#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "RawUartChannel.h"

void sendData(const char* data, const char length) {
    printf("Sending data: %.*s\n", length, data);
}

void receiveData(char* buffer, const char length) {
    snprintf(buffer, length, "Received data");
    printf("Receiving data: %s\n", buffer);
}

// Function to create a RawUartChannel instance
RawUartChannel* createRawUartChannel() {
    RawUartChannel* channel = (RawUartChannel*)malloc(sizeof(RawUartChannel));
    channel->send = sendData;
    channel->receive = receiveData;
    return channel;
}

// Function to free memory allocated for RawUartChannelS
void freeRawUartChannel(RawUartChannel* channel) {
    if (channel) {
        free(channel);
    }
}