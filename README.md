# LED Blinking with Timer0 Interrupts - LPC1768

Professional implementation of a hardware timer-based LED toggle for the NXP LPC1768 (Cortex-M3). This project demonstrates register-level programming without relying on heavy abstraction layers.

## Technical Specifications
| Feature | Details |
| :--- | :--- |
| **Microcontroller** | NXP LPC1768 (Cortex-M3) |
| **Clock Speed** | 100 MHz |
| **Timer Used** | Timer0 |
| **Interrupt** | Match Register 0 (MR0) |
| **Delay Time** | 0.5 Seconds |
| **IDE** | Keil uVision 5 |

## Hardware Configuration
* **Port Pin:** P0.17 to P0.24 (8 LEDs)
* **Register Control:** Uses FIODIR, FIOSET, and FIOCLR for high-speed I/O.
