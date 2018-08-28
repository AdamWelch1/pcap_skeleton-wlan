#include <cstdio>
#include <cstdint>
#include <cstring>

#include <thread>
#include <pcap.h>
#include <openssl/evp.h>

#include "ieee80211.h"
#include "utility.h"
#include "debug.h"

using namespace std;

void listDevices();

void receivePacket(uint8_t *userData, const struct pcap_pkthdr *packetHeader, const uint8_t *buffer)
{
	pcap_t *captureHandle = (pcap_t*) userData;
	int hdrType = pcap_datalink(captureHandle);
	
	switch(hdrType)
	{
		case DLT_IEEE802_11_RADIO:
		{
			IEEE80211_RADIOTAP_HEADER *rtHeader = (IEEE80211_RADIOTAP_HEADER*) buffer;
			IEEE_80211_FRAME *wlanFrame = (IEEE_80211_FRAME*) (buffer + rtHeader->it_len);
			
			uint8_t frameType = (wlanFrame->frameControl[0] & 0b01100) >> 2;
			uint8_t frameSubtype = (wlanFrame->frameControl[0] & 0b11110000) >> 4;
			
			switch(frameType)
			{
				case FC_TYPE_DATA:
				{
					switch(frameSubtype)
					{
						case FC_SUBTYPE_DATA_HANDSHAKE:
						{
							// TODO: Make this more readable
							if((wlanFrame->frameControl[1] & 0b01000000) == 0) // Checks the protected bit
								printf("Handshake frame!\n");
						}
						break;
					}
					
				}
				break;
			}
			
		}
		break;
		
		default:
		{
			
		}
		break;
	}
}

int main(int argc, char **argv)
{
	
	if(argc < 2)
		return -1;
	
	if(strcmp(argv[1], "-l") == 0)
	{
		listDevices();
		return 0;
	}
	
	char errbuf[PCAP_ERRBUF_SIZE];
	pcap_t *captureHandle = pcap_open_live(argv[1], 4096, 0, 1000, errbuf);
	
	if(captureHandle == NULL)
	{
		dbgprint("pcap_open_live() failed: %s\n", errbuf);
		return -1;
	}
	
	printf("Capture opened on %s\n", argv[1]);
	
	// Capture on device passed in argv[], registering receivePacket() as the callback
	pcap_loop(captureHandle, -1, receivePacket, (u_char*) captureHandle);
	pcap_close(captureHandle);	
	return 0;
}

void listDevices()
{
	char errbuf[PCAP_ERRBUF_SIZE];
	pcap_if_t *devices = 0;
	
	int res = pcap_findalldevs(&devices, errbuf);
	
	if(res == PCAP_ERROR)
	{
		dbgprint("pcap_findalldevs() failed\n");
		return;
	}
	
	printf("Listing devices:\n\n");
	for(auto i = devices; i != NULL; i = i->next)
	{
		printf("\t%s : %s\n", i->name, i->description);
	}
	
	pcap_freealldevs(devices);
}
