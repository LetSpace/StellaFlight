#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "hardware/i2c.h"
#include "pico/cyw43_arch.h"
#include "bmp390.h"

// SPI Defines
// Using SPI 0 on pins SCK 2, MOSI 3, MISO 4, CS 5
#define SPI_PORT spi0
#define SPI_SCK  2
#define SPI_MOSI 3
#define SPI_MISO 4
#define SPI_CS   5


/*
// I2C defines
// Using I2C1 on pins SDA 14 and SCL 15
#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
*/



int main()
{
    stdio_init_all();
    sleep_ms(5000);

    // Initialise the Wi-Fi chip
    if (cyw43_arch_init()) {
        printf("Wi-Fi init failed\n");
        return -1;
    }

    // SPI initialisation. This example will use SPI at 1MHz.
    /*
    spi_init(SPI_PORT, 1000*1000);
    gpio_set_function(PIN_MISO, GPIO_FUNC_SPI);
    gpio_set_function(PIN_CS,   GPIO_FUNC_SIO);
    gpio_set_function(PIN_SCK,  GPIO_FUNC_SPI);
    gpio_set_function(PIN_MOSI, GPIO_FUNC_SPI);
    */
    
    // Chip select is active-low, so we'll initialise it to a driven-high state
    /*
    gpio_set_dir(PIN_CS, GPIO_OUT);
    gpio_put(PIN_CS, 1);
    */
    // For more examples of SPI use see https://github.com/raspberrypi/pico-examples/tree/master/spi

    /*
    // I2C Initialisation. Using it at 100Khz.
    i2c_init(I2C_PORT, 100*1000);
    
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);
    // For more examples of I2C use see https://github.com/raspberrypi/pico-examples/tree/master/i2c
    */

    // initialize BMP
    bmp_t bmp = {
        .spi = {
            .cs = SPI_CS,
            .sck = SPI_SCK,
            .mosi = SPI_MOSI,
            .miso = SPI_MISO,
            .inst = SPI_PORT
        },
        .oss = 3
    };

    if (!bmp_init(&bmp)) {
        printf("Failed to initialize BMP390 sensor.\n");
        while (true);  // Stop the program if initialization fails
    }
    
    printf("MAIN: BMP390 Initialized Successfully.\n");


    //read data
    while (true) {
        // Read pressure, temperature, and altitude
        if (bmp_get_pressure_temperature(&bmp)) {
            printf("Temperature: %.2f °C\n", bmp.temperature);
            printf("Pressure: %.2f hPa\n", bmp.pressure);
            printf("Altitude: %.2f m\n\n", bmp.altitude);
        } else {
            printf("Failed to read data from BMP390.\n");
        }

        sleep_ms(1000);  // Delay 1 second between readings
    }


}
