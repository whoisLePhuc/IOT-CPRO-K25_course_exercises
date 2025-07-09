#ifndef BUTTON_H
#define BUTTON_H

// Function to enable raw terminal mode for immediate key input
void enableRawMode(struct termios *orig_termios);

// Function to restores original terminal settings
void disableRawMode(struct termios *orig_termios);

// Function to enable non-blocking input mode
void enableNonBlockingInput();

#endif // BUTTON_H