#include <stdio.h>
#include "uart/uart.h"

int main() {
    // Initialize Builder
    UART_Builder builder = UartBuilderInit();

    // Configure UART 
    UART_Config_t uartConfig = builder
        .setBaudRate(&builder, 115200)
        ->setParity(&builder, 1)
        ->setStopBits(&builder, 2)
        ->setDataBits(&builder, 9)
        ->build(&builder);

    // Print configured UART parameters
    printf("UART Configuration:\n");
    printf("Baud Rate: %d\n", uartConfig.baudRate);
    printf("Parity: %d\n", uartConfig.parity);
    printf("Stop Bits: %d\n", uartConfig.stopBits);
    printf("Data Bits: %d\n", uartConfig.dataBits);

    return 0;
}
