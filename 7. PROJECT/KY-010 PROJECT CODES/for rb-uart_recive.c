/* standard headers */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* mraa header */
#include "mraa/uart.h"

#define UART "/dev/ttyS3"
#define BAUD_RATE 9600  // Set your desired baud rate

volatile sig_atomic_t flag = 1;

void
sig_handler(int signum)
{
    if (signum == SIGINT) {
        fprintf(stdout, "Exiting...\n");
        flag = 0;
    }
}

int
main(int argc, char** argv)
{
    mraa_uart_context uart;
    char buffer[64];  // Adjust the buffer size as needed

    /* install signal handler */
    signal(SIGINT, sig_handler);

    /* initialize mraa for the platform (not needed most of the times) */
    mraa_init();

    //! [Interesting]
    /* initialize UART */
    uart = mraa_uart_init_raw(UART);
    if (uart == NULL) {
        fprintf(stderr, "Failed to initialize UART\n");
        goto err_exit;
    }

    /* set the baud rate */
    if (mraa_uart_set_baudrate(uart, BAUD_RATE) != MRAA_SUCCESS) {
        fprintf(stderr, "Failed to set baud rate\n");
        goto err_exit;
    }

    while (flag) {
        /* receive data through UART */
        int bytesRead = mraa_uart_read(uart, buffer, sizeof(buffer));
        if (bytesRead > 0) {
            buffer[bytesRead] = '\0';  // Null-terminate the received data
            printf("Received data from UART: %s\n", buffer);
        }

        sleep(1);
    }

    /* stop UART */
    mraa_uart_stop(uart);

    //! [Interesting]
    /* deinitialize mraa for the platform (not needed most of the times) */
    mraa_deinit();

    return EXIT_SUCCESS;

err_exit:
    /* deinitialize mraa for the platform (not needed most of the times) */
    mraa_deinit();

    return EXIT_FAILURE;
}

