#include "header.h"

/*
 * You are required to implement the parser functions below.
 *
 * int validateHeader(uint32_t header); function validates the header. A header is valid if all the conditions below evaluate true.
 *  - SYNC field is equal to 0x2a
 *  - if ACK bit is set V bit is also
 *  - if ACK bit is reset TYPE is non-zero.
 *  - SOURCE ADDRESS and DESTINATION ADDRESS are non-zero and different than each other.
 *
 *  If the header is valid, the function returns 1 otherwise it returns 0.
 *
 * int getFrameId(uint32_t header); function returns FRAME ID field if the header is valid, possibly checked using validateHeader function above.
 *  - If the header is not valid, it returns -1.
 *  - Otherwise, it returns non-negative integer corresponding to FRAME ID field.
 *
 * int getFrameType(uint32_t header); function returns TYPE field if the header is valid, possibly checked using validateHeader function above, and ACK bit is reset.
 *  - If the header is not valid, it returns -1.
 *  - If ACK bit is set, it returns 0.
 *  - Otherwise, it returns non-negative integer corresponding to TYPE field.
 *
 * int getSourceAddress(uint32_t header); function returns SOURCE ADDRESS field if the header is valid, possibly checked using validateHeader function above.
 *  - If the header is not valid, it returns -1.
 *  - Otherwise, it returns non-negative integer corresponding to SOURCE ADDRESS field.
 */



int validateHeader(uint32_t header)
{   
    uint32_t mask = 42;
    for (int i = 0; i < 5; i++)
    {
        int bit = header & (mask << i);
        if (bit) {
            ;
        }
        else {
            return 0;
        }
    }

    if (header & (mask << 5) == 1) {
        if(header & (mask << 6) != 1) {
            return 0;
        }
    }
    if (header & (mask << 5) == 0) {
        if(header & (mask << 7) == 0) {
            return 0;
        }
    }
    int source = getSourceAddress(header);
    int dest = getDestinationAddress(header);
    if (source == 0 || dest == 0) {
        return 0;
    }
    if (source == dest) {
        return 0;
    }
    return 1;
}

int getFrameId(uint32_t header)
{
    if (validateHeader(header) == 0) {
        return -1;
    }
    else {
        uint32_t mask = 31;
        int frameid = header & (mask << 11);
        return frameid;
    }
    
}
int getFrameType(uint32_t header)
{
    
    return -2;
}
int getSourceAddress(uint32_t header)
{
    
    return -2;
}

uint32_t createAckHeader(int destAddress, int sourceAddress, uint8_t frameId, char valid)
{
    
    return 0;
}

uint32_t createHeader(int destAddress, int sourceAddress, uint8_t frameId, uint8_t type)
{
    
    return 0;
}
