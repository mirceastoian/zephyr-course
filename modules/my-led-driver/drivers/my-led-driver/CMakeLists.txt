if(CONFIG_MY_LED_DRIVER)
  zephyr_library()
  zephyr_library_sources(my_led.c)
endif()
