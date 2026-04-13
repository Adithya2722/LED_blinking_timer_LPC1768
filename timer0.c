#include "timer0.h"

void timer0_init(void)
{
    // Enable power to Timer0
    set_bit(LPC_SC->PCONP, 1);

    // Set PCLK = CCLK (important)
    LPC_SC->PCLKSEL0 &= ~(3 << 2);
    LPC_SC->PCLKSEL0 |=  (1 << 2);

    // Reset Timer
    set_bit(LPC_TIM0->TCR, 1);
    reset_bit(LPC_TIM0->TCR, 1);
}

void start_timer0(void)
{
    set_bit(LPC_TIM0->TCR, 0);
}

void stop_timer0(void)
{
    reset_bit(LPC_TIM0->TCR, 0);
}

void enable_timer0_interrupt(void)
{
    set_bit(LPC_TIM0->MCR, 0);   // Interrupt on MR0
    NVIC_EnableIRQ(TIMER0_IRQn);
}

void enable_timer0_mr_reset(void)
{
    set_bit(LPC_TIM0->MCR, 1);   // Reset on MR0
}

void set_timer0_pre_scale_value(uint32_t value)
{
    LPC_TIM0->PR = value;
}

void set_timer0_match_value(uint32_t value)
{
    LPC_TIM0->MR0 = value;
}