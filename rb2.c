#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define GPIO_IN_PIN     "/sys/class/gpio/PC12/value"  // Assuming PC12 is GPIO 35
#define GPIO_OUT_PIN    "/sys/class/gpio/PC13/value"  // Assuming PC17 is GPIO 61

#define BUFFER_SIZE 100

int main() {
    char value;
    int switch_fd, led_fd;
    int switch_state = 0; // 0: Switch off, 1: Switch on
    int led_state = 0;    // 0: LED off, 1: LED on

    // Export GPIO pins
    int export_fd = open("/sys/class/gpio/export", O_WRONLY);
    if (export_fd < 0) {
        perror("Failed to open export GPIO");
        return 1;
    }
    write(export_fd, "35", 2); // Export GPIO 35
    write(export_fd, "61", 2); // Export GPIO 61
    close(export_fd);

    // Set direction for GPIO pins
    int direction_fd;
    direction_fd = open("/sys/class/gpio/PC12/direction", O_WRONLY);
    if (direction_fd < 0) {
        perror("Failed to open direction GPIO 35");
        return 1;
    }
    write(direction_fd, "in", 3); // Set GPIO 35 as input
    close(direction_fd);

    direction_fd = open("/sys/class/gpio/PC13/direction", O_WRONLY);
    if (direction_fd < 0) {
        perror("Failed to open direction GPIO 61");
        return 1;
    }
    write(direction_fd, "out", 4); // Set GPIO 61 as output
    close(direction_fd);

    // Open file descriptors for the GPIO pins
    switch_fd = open(GPIO_IN_PIN, O_RDONLY);
    if (switch_fd < 0) {
        perror("Failed to open switch GPIO pin");
        return 1;
    }

    led_fd = open(GPIO_OUT_PIN, O_WRONLY);
    if (led_fd < 0) {
        perror("Failed to open LED GPIO pin");
        close(switch_fd);
        return 1;
    }

    // Continuously read the state of the switch and toggle the LED accordingly
    while (1) {
        lseek(switch_fd, 0, SEEK_SET);
        read(switch_fd, &value, 1);

        // Toggle LED if the switch is pressed
        if (value == '1' && switch_state == 0) {
            switch_state = 1;
            led_state = !led_state; // Toggle LED state
            write(led_fd, led_state ? "1" : "0", 2); // Turn on/off LED
        } else if (value == '0' && switch_state == 1) {
            switch_state = 0;
        }

        usleep(10000); // Small delay to avoid high CPU usage
    }

    // Close file descriptors
    close(switch_fd);
    close(led_fd);

    // Unexport GPIO pins
    export_fd = open("/sys/class/gpio/unexport", O_WRONLY);
    if (export_fd < 0) {
        perror("Failed to open unexport GPIO");
        return 1;
    }
    write(export_fd, "35", 2); // Unexport GPIO 35
    write(export_fd, "61", 2); // Unexport GPIO 61
    close(export_fd);

    return 0;
}

