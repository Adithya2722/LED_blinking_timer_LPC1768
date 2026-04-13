#include <LPC17xx.h>
#include "timer0.h"

// Global variable
BOOL led_on = TRUE;

// Interrupt Handler
void TIMER0_IRQHandler(void)
{
    if (LPC_TIM0->IR & (1 << 0))   // MR0 interrupt
    {
        LPC_TIM0->IR = (1 << 0);   // Clear interrupt flag

        if (led_on == TRUE)
        {
            LPC_GPIO0->FIOSET = (0XFF << 17);  // LED ON
            led_on = FALSE;
        }
        else
        {
            LPC_GPIO0->FIOCLR = (0XFF << 17);  // LED OFF
            led_on = TRUE;
        }
    }
}

int main(void)
{
    // Configure P0.20 as output
    (LPC_GPIO0->FIODIR = (0xFF << 17));

    // Timer setup
    timer0_init();
    stop_timer0();

    set_timer0_pre_scale_value(0);      // No prescaler
    set_timer0_match_value(30000000);   // 0.5 sec delay (for 100 MHz)

    enable_timer0_interrupt();
    enable_timer0_mr_reset();

    start_timer0();   // ?? Start timer

    while (1)
    {
        
    }
}