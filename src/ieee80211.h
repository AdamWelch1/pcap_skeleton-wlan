#ifndef IEEE80211_H
#define IEEE80211_H

#include <cstdint>

struct IEEE80211_RADIOTAP_HEADER {
    
    uint8_t it_version;     /* set to 0 */
    uint8_t it_pad;
    uint16_t it_len;        /* entire length */
    uint32_t it_present;    /* fields present */
    
} __attribute__((__packed__));

struct IEEE_80211_FRAME {

    uint8_t frameControl[2];
    uint8_t durationID[2];
    uint8_t addr1[6];
    uint8_t addr2[6];
    uint8_t addr3[6];
    uint8_t sequenceControl[2];
    
    uint8_t frameBody[];
    
} __attribute__((__packed__));

/***    Frame Control "type" field definitions ***/

#define FC_TYPE_MANAGEMENT      0
#define FC_TYPE_CONTROL         1
#define FC_TYPE_DATA            2


/***    Frame Control "subtype" field definitions ***/

// Management Frame subtypes
#define FC_SUBTYPE_ASSOC_REQUEST            0
#define FC_SUBTYPE_ASSOC_RESPONSE           1
#define FC_SUBTYPE_REASSOC_REQUEST          2
#define FC_SUBTYPE_REASSOC_RESPONSE         3
#define FC_SUBTYPE_PROBE_REQUEST            4
#define FC_SUBTYPE_PROBE_RESPONSE           5
#define FC_SUBTYPE_BEACON                   8
#define FC_SUBTYPE_ATIM                     9 // Announcement Traffic Indication Message
#define FC_SUBTYPE_DISASSOC                 10
#define FC_SUBTYPE_AUTH                     11
#define FC_SUBTYPE_DEAUTH                   12

// Control Frame subtypes
#define FC_SUBTYPE_PSPOLL                   10 // Power Save Poll
#define FC_SUBTYPE_RTS                      11 // Request To Send
#define FC_SUBTYPE_CTS                      12 // Clear To Send
#define FC_SUBTYPE_ACK                      13
#define FC_SUBTYPE_CFEND                    14 // Contention Free End
#define FC_SUBTYPE_CFENDACK                 15 // CF-End + CF-Ack

// Data Frame subtypes
#define FC_SUBTYPE_DATA                     0
#define FC_SUBTYPE_DATA_CFACK               1
#define FC_SUBTYPE_DATA_CFPOLL              2
#define FC_SUBTYPE_DATA_CFACKPOLL           3
#define FC_SUBTYPE_DATA_NULL                4
#define FC_SUBTYPE_DATA_NULL_CFACK          5
#define FC_SUBTYPE_DATA_NULL_CFPOLL         6
#define FC_SUBTYPE_DATA_NULL_CFACKPOLL      7

// FIXME: This label is inaccurate, subtype 8 is used for other packets as well.
#define FC_SUBTYPE_DATA_HANDSHAKE           8

#endif
