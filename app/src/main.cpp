#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/drivers/sensor.h>
#include "my-led-driver/my_led.h"

// LED as a sensor device
const struct device *led = DEVICE_DT_GET(DT_NODELABEL(my_led));

LOG_MODULE_REGISTER(main, LOG_LEVEL_INF);

int main(void)
{
    if (!device_is_ready(led)) {
        printk("My LED not ready!\n");
        return -ENODEV;
    }

    while (1) {
        my_led_driver_set_state(led, true);
        k_msleep(CONFIG_APP_HEARTBEAT_PERIOD_MS);
        my_led_driver_set_state(led, false);
        k_msleep(CONFIG_APP_HEARTBEAT_PERIOD_MS);
    }

    return 0;
}
