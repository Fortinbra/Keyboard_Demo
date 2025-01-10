#include <stdio.h>
#include "pico/stdlib.h"
#include "btstack.h"
#include "pico/cyw43_arch.h"
#includ "pico/btstack_cyw43.h"


int main()
{
    stdio_init_all();

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
