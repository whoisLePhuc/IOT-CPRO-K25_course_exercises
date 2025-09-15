#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "led_driver.h"

static uint32_t *led_buffer = NULL;
static size_t led_pixel_count = 0;

int led_init(size_t num_pixels){
    if(led_buffer != NULL) {
        free(led_buffer);
    }
    led_buffer = (uint32_t *)malloc(num_pixels * sizeof(uint32_t));
    if(led_buffer == NULL){
        return -1; // Memory allocation failed
    }
    led_pixel_count = num_pixels;
    memset(led_buffer, 0, num_pixels * sizeof(uint32_t)); // Initialize buffer to zero
    return 0; // // Memory allocation Success
}

void led_shutdown(){
    if(led_buffer != NULL){
        free(led_buffer);
        led_buffer = NULL;
        led_pixel_count = 0;
    }
}

void led_set_pixel_color(size_t index, uint8_t r, uint8_t g, uint8_t b){
    if(index > led_pixel_count || led_buffer == NULL){
        return; // Invalid index or buffer not initialized
    }
    uint32_t color = 0;
    color |= (g << 16);
    color |= (r << 8);
    color |= b;
    led_buffer[index] = color;
}

void led_fill(uint8_t r, uint8_t g, uint8_t b){
    if(led_buffer == NULL){
        return; // Buffer not initialized
    }
    uint32_t color = 0;
    color |= (g << 16);
    color |= (r << 8);
    color |= b;
    for(size_t i = 0; i < led_pixel_count; i++){
        led_buffer[i] = color;
    }
}

void led_clear(){
    led_fill(0, 0, 0); // Fill with black color
}

const uint32_t* led_get_buffer(){
    return led_buffer;
}

size_t led_get_pizel_count(){
    return led_pixel_count;
}
