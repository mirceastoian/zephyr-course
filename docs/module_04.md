# Module 04

## Build

```
west build --board nucleo_h7s3l8/stm32h7s3xx app
```

## zephyr.dts

Existing LED aliases for this board.

```
/* node '/aliases' defined in deps\zephyr\dts\common\skeleton.dtsi:15 */
aliases {
    led0 = &green_led;         /* in deps\zephyr\boards\st\nucleo_h7s3l8\nucleo_h7s3l8-common.dtsi:53 */
    led1 = &yellow_led;        /* in deps\zephyr\boards\st\nucleo_h7s3l8\nucleo_h7s3l8-common.dtsi:54 */
    led2 = &red_led;           /* in deps\zephyr\boards\st\nucleo_h7s3l8\nucleo_h7s3l8-common.dtsi:55 */
    sw0 = &user_button;        /* in deps\zephyr\boards\st\nucleo_h7s3l8\nucleo_h7s3l8-common.dtsi:56 */
    watchdog0 = &iwdg;         /* in deps\zephyr\boards\st\nucleo_h7s3l8\nucleo_h7s3l8-common.dtsi:57 */
    spi-flash0 = &mx25uw25645; /* in deps\zephyr\boards\st\nucleo_h7s3l8\nucleo_h7s3l8-common.dtsi:58 */
    rtc = &rtc;                /* in deps\zephyr\boards\st\nucleo_h7s3l8\nucleo_h7s3l8-common.dtsi:59 */
    app-led = &green_led;      /* in zephyr-course\app\app.overlay:4 */
};
```
