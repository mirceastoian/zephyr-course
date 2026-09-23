#pragma once

#include <zephyr/device.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

int my_led_driver_set_state(const struct device *dev, bool state);

#ifdef __cplusplus
}
#endif
