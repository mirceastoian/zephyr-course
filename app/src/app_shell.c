#include <zephyr/shell/shell.h>
#include <zephyr/drivers/sensor.h>
#include "my-led-driver/my_led.h"

const struct device *led_dev = DEVICE_DT_GET(DT_NODELABEL(my_led2));

static int cmd_sensor_fetch(const struct shell *sh, size_t argc, char **argv) {
    ARG_UNUSED(argc);
    ARG_UNUSED(argv);
    sensor_sample_fetch(led_dev);
    shell_print(sh, "LED was turned ON");
    return 0;
}

static int cmd_sensor_read(const struct shell *sh, size_t argc, char **argv) {
    ARG_UNUSED(argc);
    ARG_UNUSED(argv);
    sensor_channel_get(led_dev, SENSOR_CHAN_ALL, NULL);
    shell_print(sh, "LED was turned OFF");
    return 0;
}

static int cmd_sensor_info(const struct shell *sh, size_t argc, char **argv) {
    ARG_UNUSED(argc);
    ARG_UNUSED(argv);
    shell_print(sh, "Sensor name: %s", led_dev->name);
    shell_print(sh, "Device ready: %s", device_is_ready(led_dev) ? "yes" : "no");
    return 0;
}

static int cmd_sensor_set(const struct shell *sh, size_t argc, char **argv) {
    if (argc != 2 || (strcmp(argv[1], "on") != 0 && strcmp(argv[1], "off") != 0)) {
        shell_error(sh, "Usage: sensor set <on|off>");
        return -EINVAL;
    }

    if (strcmp(argv[1], "on") == 0) {
        my_led_driver_set_state(led_dev, true);
        shell_print(sh, "LED turned ON");
    } else if (strcmp(argv[1], "off") == 0) {
        my_led_driver_set_state(led_dev, false);
        shell_print(sh, "LED turned OFF");
    }

    return 0;
}

SHELL_STATIC_SUBCMD_SET_CREATE(
    sub_sensor,
    SHELL_CMD(fetch, NULL, "Turn LED ON", cmd_sensor_fetch),
    SHELL_CMD(read, NULL, "Turn LED OFF", cmd_sensor_read),
    SHELL_CMD(info, NULL, "Device name and ready state", cmd_sensor_info),
    SHELL_CMD_ARG(set, NULL, "Set LED state (on|off)", cmd_sensor_set, 2, 0),
    SHELL_SUBCMD_SET_END);

SHELL_CMD_REGISTER(sensor, &sub_sensor, "My LED Driver shell commands", NULL);
