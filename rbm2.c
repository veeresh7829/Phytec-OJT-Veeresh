#include <stdio.h>
#include <stdlib.h>
#include <mraa.h>

#define GPIO_IN_PIN     35  // Assuming PC12
#define GPIO_OUT_PIN    61  // Assuming PC17

int main() {
    mraa_gpio_context switch_pin, led_pin;
    switch_pin = mraa_gpio_init(GPIO_IN_PIN);
    led_pin = mraa_gpio_init(GPIO_OUT_PIN);

    if (switch_pin == NULL || led_pin == NULL) {
        fprintf(stderr, "Failed to initialize GPIO pins\n");
        return 1;
    }

    mraa_result_t status;
    status = mraa_gpio_dir(switch_pin, MRAA_GPIO_IN);
    if (status != MRAA_SUCCESS) {
        fprintf(stderr, "Failed to set direction for switch pin\n");
        mraa_gpio_close(switch_pin);
        mraa_gpio_close(led_pin);
        return 1;
    }

    status = mraa_gpio_dir(led_pin, MRAA_GPIO_OUT);
    if (status != MRAA_SUCCESS) {
        fprintf(stderr, "Failed to set direction for LED pin\n");
        mraa_gpio_close(switch_pin);
        mraa_gpio_close(led_pin);
        return 1;
    }

    int switch_state = 0; // 0: Switch off, 1: Switch on
    int led_state = 0;    // 0: LED off, 1: LED on

    // Continuously read the state of the switch and toggle the LED accordingly
    while (1) {
        int switch_val = mraa_gpio_read(switch_pin);

        // Toggle LED if the switch is pressed
        if (switch_val == 1 && switch_state == 0) {
            switch_state = 1;
            led_state = !led_state; // Toggle LED state
            status = mraa_gpio_write(led_pin, led_state); // Turn on/off LED
            if (status != MRAA_SUCCESS) {
                fprintf(stderr, "Failed to write to LED pin\n");
                break;
            }
        } else if (switch_val == 0 && switch_state == 1) {
            switch_state = 0;
        }

        usleep(10000); // Small delay to avoid high CPU usage
    }

    // Close GPIO pins
    mraa_gpio_close(switch_pin);
    mraa_gpio_close(led_pin);

    return 0;
}

