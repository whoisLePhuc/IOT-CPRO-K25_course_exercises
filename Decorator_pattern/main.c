#include "RawUartChannel/RawUartChannel.h"
#include <stdio.h>
#include <stdlib.h>


RawUartChannel* createRawUartChannel();
void freeRawUartChannel(RawUartChannel* channel); 

int main(){
    // Create a RawUartChannel instance
    RawUartChannel* Channel = createRawUartChannel();
    Channel->send("Hello, World!", 13);
    char buffer[50];
    Channel->receive(buffer, sizeof(buffer));

    // Create decorators

    // Free allocated memory for decorators

    // Free the raw channel
    freeRawUartChannel(Channel);

    return 0;
}

