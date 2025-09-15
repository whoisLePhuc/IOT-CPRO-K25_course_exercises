#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include "led_driver.h"

void print_pixel_hex(const char *label, size_t index, uint32_t value){
    printf("%s Pixel %zu: 0x%06X\n", label, index, value & 0xFFFFFF);
}

int main(){
    // Initialize LED with 10 pixels
    if(led_init(10) != 0){
        printf("LED initialization failed\n");
        return 1;
    } 

    // Check if the buffer is initialized to zero
    const uint32_t* buffer = led_get_buffer();
    size_t pixel_count = led_get_pizel_count();
    for(size_t i = 0; i< pixel_count; i++){
        if(buffer[i] != 0){
            printf("Pixel %zu is not initialized to zero, value: %u\n", i, buffer[i]);
        }
    }
    printf("All pixels initialized to zero.\n");

    // Set specific pixel colors 
    led_set_pixel_color(0, 255, 0, 0); // Set first pixel to red
    led_set_pixel_color(9, 0, 255, 0); // Set last pixel to blue
    led_set_pixel_color(4, 255, 255, 255); // Set fouth pixel to white

    // Check the colors of specific pixels
    print_pixel_hex("RED", 0, buffer[0]);
    print_pixel_hex("BLUE", 9, buffer[9]);
    print_pixel_hex("WHITE", 4, buffer[4]);

    // Fill all pixels with green
    led_fill(0, 255, 0); 
    int ok = 1;
    for(size_t i = 0; i < pixel_count; i++){
        if(buffer[i] != 0x00FF0000){
            printf("Pixel %zu is not filled with green, value: %u\n", i, buffer[i]);
            ok = 0;
        }
    }
    if(ok){
        printf("All pixels filled with green.\n");
    }

    // Clear all pixels
    led_shutdown();
    return 0;
}