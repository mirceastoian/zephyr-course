#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/drivers/sensor.h>

// LED as a sensor device
const struct device *led = DEVICE_DT_GET(DT_NODELABEL(my_led));

LOG_MODULE_REGISTER(main, LOG_LEVEL_INF);

int main(void)
{
    if (!device_is_ready(led)) {
        printk("My LED not ready!\n");
        return -1;
    }

    while (1) {
        sensor_sample_fetch(led);
        k_msleep(CONFIG_APP_HEARTBEAT_PERIOD_MS);
        sensor_channel_get(led, SENSOR_CHAN_ALL, NULL);
        k_msleep(CONFIG_APP_HEARTBEAT_PERIOD_MS);
    }

    return 0;
}
