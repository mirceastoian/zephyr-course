#include <zephyr/init.h>
#include <zephyr/kernel.h>

static int custom_board_init(void)
{
    printk("Board Initialized\n");
    return 0;
}

SYS_INIT(custom_board_init, APPLICATION, 0);
