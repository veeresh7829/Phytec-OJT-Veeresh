#include <stdio.h>
#include <unistd.h>
#include "mraa.h"

// Define LED pins
#define LED1_PIN 61
#define LED2_PIN 62
#define LED3_PIN 63
// Define Button pin
#define BUTTON_PIN 35

int main() {
    mraa_init();

    // Initialize LED pins
    mraa_gpio_context led1 = mraa_gpio_init(LED1_PIN);
    mraa_gpio_context led2 = mraa_gpio_init(LED2_PIN);
    mraa_gpio_context led3 = mraa_gpio_init(LED3_PIN);
    // Initialize Button pin
    mraa_gpio_context button = mraa_gpio_init(BUTTON_PIN);

    // Set LED pins as output
    mraa_gpio_dir(led1, MRAA_GPIO_OUT);
    mraa_gpio_dir(led2, MRAA_GPIO_OUT);
    mraa_gpio_dir(led3, MRAA_GPIO_OUT);
    // Set Button pin as input
    mraa_gpio_dir(button, MRAA_GPIO_IN);

    int count = 0; // Counter to track button presses

    while (1) {
        // Read the button state
        int button_state = mraa_gpio_read(button);
        
        // If button is pressed (active low)
        if (button_state == 0) {
            count++; // Increment the count

            // Based on the count, turn on corresponding LED
            switch (count) {
                case 1:
                    mraa_gpio_write(led1, 1); // Turn on LED 1
                    sleep(1);
                    mraa_gpio_write(led1, 0); // Turn off LED 1
                    break;
                case 2:
                    mraa_gpio_write(led2, 1); // Turn on LED 2
                    sleep(1);
                    mraa_gpio_write(led2, 0); // Turn off LED 2
                    break;
                case 3:
                    mraa_gpio_write(led3, 1); // Turn on LED 3
                    sleep(1);
                    mraa_gpio_write(led3, 0); // Turn off LED 3
                    count = 0; // Reset count
                    break;
                default:
                    break;
            }

            // Wait for button release
            while (mraa_gpio_read(button) == 0); // Wait until button is released
            usleep(100000); // Wait for 100 milliseconds for debounce
        }
    }

    // Cleanup
    mraa_gpio_close(led1);
    mraa_gpio_close(led2);
    mraa_gpio_close(led3);
    mraa_gpio_close(button);

    return MRAA_SUCCESS;
}

