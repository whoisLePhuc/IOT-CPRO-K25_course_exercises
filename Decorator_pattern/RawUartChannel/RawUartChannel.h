#ifndef RAW_UART_CHANNEL_H
#define RAW_UART_CHANNEL_H

// Function prototypes for RawUartChannel
typedef struct{
    void (*send)(const char* data, const char length);
    void (*receive)(char* buffer, const char length); 
}RawUartChannel;

// function prototypes for creating RawUartChannelS
RawUartChannel* createRawUartChannel();

// Function to free memory allocated for RawUartChannel
void freeRawUartChannel(RawUartChannel* channel); 

#endif // RAW_UART_CHANNEL_HS