#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "bno08x.h"

// I2C defines

#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15

BNO08x IMU;

int main()
{
    stdio_init_all();

    // I2C Initialisation. Using it at 100Khz.
    i2c_init(I2C_PORT, 100*1000);
    
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);
    // For more examples of I2C use see https://github.com/raspberrypi/pico-examples/tree/master/i2c

    IMU.begin(0x4A, I2C_PORT);
    
    IMU.enableRotationVector();
    IMU.enableGravity();

    while (true) {
        float yaw = 0;
        float gravity = 0;

        if (IMU.getSensorEvent() == true) {
            if (IMU.getSensorEventID() == SENSOR_REPORTID_ROTATION_VECTOR) {
                yaw = IMU.getYaw();
            }
            if (IMU.getSensorEventID() == SENSOR_REPORTID_GRAVITY) {
                gravity = IMU.getGravityY();
            }
        }

        //printf("Yaw = %f\n", yaw);
        printf("Gravity y = %f\n", gravity);
        sleep_ms(100);
    }
}
