#include "uart.h"
#include <stdint.h>

int main(void)
{
    uart_init();
    uart_puts("hello world!!\n");
    while(1)
    {
        
    }
    return 0;
}