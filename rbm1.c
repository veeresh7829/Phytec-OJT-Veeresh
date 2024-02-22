#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mraa/gpio.h>

#define GPIO_LED 61
#define GPIO_SWITCH 35

int main() {
    mraa_gpio_context gpio_led, gpio_switch;
    mraa_result_t result;
    mraa_init();

    // Initialize GPIOs
    gpio_led = mraa_gpio_init(GPIO_LED);
    if (gpio_led == NULL) {
        fprintf(stderr, "Failed to initialize LED GPIO %d\n", GPIO_LED);
        mraa_deinit();
        return EXIT_FAILURE;
    }

    gpio_switch = mraa_gpio_init(GPIO_SWITCH);
    if (gpio_switch == NULL) {
        fprintf(stderr, "Failed to initialize SWITCH GPIO %d\n", GPIO_SWITCH);
        mraa_gpio_close(gpio_led);
        mraa_deinit();
        return EXIT_FAILURE;
    }

    // Set direction
    result = mraa_gpio_dir(gpio_led, MRAA_GPIO_OUT);
    if (result != MRAA_SUCCESS) {
        fprintf(stderr, "Failed to set direction for LED GPIO\n");
        mraa_gpio_close(gpio_led);
        mraa_gpio_close(gpio_switch);
        mraa_deinit();
        return EXIT_FAILURE;
    }

    result = mraa_gpio_dir(gpio_switch, MRAA_GPIO_IN);
    if (result != MRAA_SUCCESS) {
        fprintf(stderr, "Failed to set direction for SWITCH GPIO\n");
        mraa_gpio_close(gpio_led);
        mraa_gpio_close(gpio_switch);
        mraa_deinit();
        return EXIT_FAILURE;
    }

    while (1) {
        // Read switch state
        int switch_state = mraa_gpio_read(gpio_switch);
        if (switch_state == -1) {
            fprintf(stderr, "Failed to read from SWITCH GPIO\n");
            mraa_gpio_close(gpio_led);
            mraa_gpio_close(gpio_switch);
            mraa_deinit();
            return EXIT_FAILURE;
        }

        // Turn on/off LED based on switch state
        result = mraa_gpio_write(gpio_led, switch_state);
        if (result != MRAA_SUCCESS) {
            fprintf(stderr, "Failed to write to LED GPIO\n");
            mraa_gpio_close(gpio_led);
            mraa_gpio_close(gpio_switch);
            mraa_deinit();
            return EXIT_FAILURE;
        }

        usleep(100000); // Delay to prevent busy loop
    }

    // Cleanup
    mraa_gpio_close(gpio_led);
    mraa_gpio_close(gpio_switch);
    mraa_deinit();
    return EXIT_SUCCESS;
}

