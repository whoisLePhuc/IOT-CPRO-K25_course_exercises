#include <stdio.h>
#include <stdlib.h>
#include "uart.h"

// Function to set baud rate
static UART_Builder* setBaudRate(UART_Builder* builder, uint32_t baudRate) {
    if (baudRate < 1200 || baudRate > 115200) {
        printf("Error: Invalid baud rate.\n");
        return builder;
    }
    builder->config.baudRate = baudRate;
    return builder;
}

// Function to set parity
static UART_Builder* setParity(UART_Builder* builder, uint8_t parity) {
    if (parity > 2) {
        printf("Error: Invalid parity.\n");
        return builder;
    }
    builder->config.parity = parity;
    return builder;
}

// Function to set the stop bits
static UART_Builder* setStopBits(UART_Builder* builder, uint8_t stopBits) {
    if (stopBits != 1 && stopBits != 2) {
        printf("Error: Invalid stop bits.\n");
        return builder;
    }
    builder->config.stopBits = stopBits;
    return builder;
}

// Function to set the data bits
static UART_Builder* setDataBits(UART_Builder* builder, uint8_t dataBits) {
    if (dataBits != 8 && dataBits != 9) {
        printf("Error: Invalid bits.\n");
        return builder;
    }
    builder->config.dataBits = dataBits;
    return builder;
}

// Function to build and return the UART configuration
static UART_Config_t build(UART_Builder* builder) {
    return builder->config;
}

// Function to initialize the Builder
UART_Builder UartBuilderInit() {
    UART_Builder builder;
    builder.config.baudRate = 9600;  
    builder.config.parity = 0;      
    builder.config.stopBits = 1;    
    builder.config.dataBits = 8;   
    builder.setBaudRate = setBaudRate;
    builder.setParity = setParity;
    builder.setStopBits = setStopBits;
    builder.setDataBits = setDataBits;
    builder.build = build;
    return builder;
}
