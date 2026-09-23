if(CONFIG_MY_LED_DRIVER)
    add_subdirectory(drivers/my-led-driver)
    zephyr_include_directories(include)
endif()
