#ifndef DECORATORS_H
#define DECORATORS_H
#include "../RawUartChannel/RawUartChannel.h"

// Structure for CRC decorator
typedef struct{
    RawUartChannel* RawUartChannel;
}CrcDecorator;

// Structure for Encryption decorator
typedef struct{
    RawUartChannel* RawUartChannel;
}EncryptionDecorator;

// Structure for Logging decorator
typedef struct{
    RawUartChannel* RawUartChannel;
}LoggingDecorator;

// Structure for Compression decorator
typedef struct{
    RawUartChannel* RawUartChannel;
}CompressionDecorator;

// Function for creating decorators
CrcDecorator* createCrcDecorator(RawUartChannel* channel);
EncryptionDecorator* createEncryptionDecorator(RawUartChannel* channel);
LoggingDecorator* createLoggingDecorator(RawUartChannel* channel);
CompressionDecorator* createCompressionDecorator(RawUartChannel* channel);

// Function for freeing memory allocated for decorators
void freeCrcDecorator(CrcDecorator* decorator);
void freeEncryptionDecorator(EncryptionDecorator* decorator);
void freeLoggingDecorator(LoggingDecorator* decorator);
void freeCompressionDecorator(CompressionDecorator* decorator);


#endif