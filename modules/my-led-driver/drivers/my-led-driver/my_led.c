#include <zephyr/device.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/logging/log.h>

#define DT_DRV_COMPAT mircea_my_led_driver

LOG_MODULE_REGISTER(my_led_driver, LOG_LEVEL_INF);

struct my_led_driver_config {
    struct gpio_dt_spec gpio;
    uint32_t id;
};

struct my_led_driver_data {
    bool led_state;
};

static int my_led_driver_init(const struct device *dev)
{
    const struct my_led_driver_config *cfg = (const struct my_led_driver_config *)dev->config;
    const struct gpio_dt_spec *led = &cfg->gpio;

    if (!gpio_is_ready_dt(led)) return -1;
    if (gpio_pin_configure_dt(led, GPIO_OUTPUT_INACTIVE) < 0) return -2;

	return 0;
}

static inline int control_led(const struct device *dev, const bool state)
{
    const struct my_led_driver_config *cfg = (const struct my_led_driver_config *)dev->config;
    const struct gpio_dt_spec *led = &cfg->gpio;
    
    if (gpio_pin_set_dt(led, state) < 0) return -1;

    struct my_led_driver_data *data = dev->data;
    data->led_state = gpio_pin_get_dt(led);

    return 0;
}

// ON
static int my_led_driver_sample_fetch(const struct device *dev,
                                      enum sensor_channel chan)
{
    (void)chan;
    return control_led(dev, 1);
}

// OFF
static int my_led_driver_channel_get(const struct device *dev,
                                     enum sensor_channel chan,
                                     struct sensor_value *val)
{
    (void)chan;
    (void)val;
    return control_led(dev, 0);
}

int my_led_driver_set_state(const struct device *dev, bool state)
{
    // control_led function also changes the led state value in the
    // dynamic driver data structure so we will not do it here
    return control_led(dev, state);
}

static const struct sensor_driver_api my_led_driver_api = {
	.sample_fetch = my_led_driver_sample_fetch,
	.channel_get = my_led_driver_channel_get
};

#define DEVICE_INSTANCE(inst) \
\
const static struct my_led_driver_config my_led_driver_##inst##_cfg = { \
		.gpio = GPIO_DT_SPEC_INST_GET(inst, gpios), \
        .id = inst \
}; \
\
static struct my_led_driver_data my_led_driver_##inst##_drvdata = { \
		.led_state = false, \
}; \
\
DEVICE_DT_INST_DEFINE(inst, \
		my_led_driver_init, \
		NULL, \
		&my_led_driver_##inst##_drvdata, \
		&my_led_driver_##inst##_cfg, \
		POST_KERNEL, \
        CONFIG_GPIO_INIT_PRIORITY, \
		&my_led_driver_api);

DT_INST_FOREACH_STATUS_OKAY(DEVICE_INSTANCE);
