#ifndef UTILITY_H
#define UTILITY_H

#include <cstdint>

void printMAC(const uint8_t *macAddr, uint32_t length = 6);
void printHex(const uint8_t *bytes, uint32_t bytesCount, bool printNewline = true);

#endif

/* Just an example of generating a PSK from a passphrase and SSID

    char pass[] = "password";
    char ssid[] = "IEEE";
    uint8_t psk[32] = {0};
    
    int res = PKCS5_PBKDF2_HMAC_SHA1(pass, strlen(pass), (uint8_t*) ssid, strlen(ssid), 4096, 32, psk);
    
    if(res == 0)
    {
        dbgprint("PKCS5_PBKDF2_HMAC_SHA1() failed\n");
        return -1;
    }
    
    printHex(psk, 32);
*/
