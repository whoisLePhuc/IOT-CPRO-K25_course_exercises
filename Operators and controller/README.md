## I. Project Description
## II. Source Code Structure
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
2. Struct
3. Components
## IV. How to Build & Run
## V. Flow Chart
## VI. Testing
## VII. Known Issues or Bugs

int led_init(size_t num_pixels)