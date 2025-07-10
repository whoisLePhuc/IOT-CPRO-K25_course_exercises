## I. Project Description
This project simulates the control of an addressable RGB LED strip (WS2812B / NeoPixel) using the C programming language. Each LED requires a 24-bit color value (8 bits each for Green, Red, and Blue), and the driver is responsible for managing a buffer containing color data for the entire strip.

The driver provides a high-level API to:
- Initialize and free memory for the LED strip,
- Set individual pixel colors,
- Fill the entire strip with a single color,
- Clear the strip (turn all LEDs off),
- And retrieve the raw buffer for inspection or transmission.

This simulation focuses purely on logic and memory handling, and does **not** include actual signal generation for GPIO or hardware output.

## II. Source Code Structure
    project/
    ├── include/
    │   └── led_driver.h         
    ├── src/
    │   └── led_driver.c         
    ├── main.c                   
    ├── Makefile     
    ├── README.md  

## III. Key APIs, Structs, and Components
1. Function
- 'int led_init(size_t num_pixels)': 
    - Initializes abudder for the LED strip with the given number of pixels.
    - Return 0 on success, -1 on failure
- 'void led_shutdown()':
    - Frees the memory allocated for the LED strip
- 'void led_set_pixel_color(size_t index, uint8_t r, uint8_t g, uint8_t b)'
    - Sets the color of a specifix pixel at the given index
    - Uses 3 seperate 8-bits values for Red, Green and Blue
- 'void led_fill(uint8_t r, uint8_t g, uint8_t b)'
    - Fills the entire strip with a single color
- 'void led_clear()'
    - Turns off all pixels (by setting their color to black)
- 'const uint32_t* led_get_buffer()'
    - Gets a constant (read-only) pointer to the data buffer, ready to be sent out
- 'size_t led_get_pixel_count()'
    - Gets the number of pixels on the LED strip

## IV. How to Build & Run
Using makefile

## V. Flow Chart
    main.c
    │
    ├── led_init(10)
    ├── led_set_pixel_color(...)
    ├── led_fill(...)
    ├── led_get_buffer()
    └── led_shutdown()
## VI. Testing
- ✅ Initialize a 10-pixel LED strip and verify that the buffer is initialized to all zeros.
- ✅ Set specific colors for the first, middle, and last pixels:
    - Pixel 0 → Red (255, 0, 0)
    - Pixel 4 → White (255, 255, 255)
    - Pixel 9 → Blue (0, 0, 255)
- ✅ Use `led_get_buffer()` to retrieve the internal buffer and verify that:
    - Pixel 0 has value `0x00FF0000` (Red)
    - Pixel 4 has value `0x00FFFFFF` (White)
    - Pixel 9 has value `0x000000FF` (Blue)
- ✅ Call `led_fill()` to set all pixels to Green (0, 255, 0), and verify all buffer values are `0x00FF0000`.
- ✅ Call `led_shutdown()` to safely release the allocated memory.

## VII. Known Issues or Bugs
- Nothing