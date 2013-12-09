#include <msp430g2553.h>
#include "IRsensor.h"

/*
 * main.c
 */
int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE;
	ADC10CTL1 = ADC10DIV_7;
	ADC10AE0 |= BIT3|BIT4|BIT5;
	ADC10CTL1 |= ADC10SSEL1 | ADC10SSEL0;

	P1DIR |= BIT0;
	P1DIR |= BIT6;

	for (;;) {
		getLeft();
		if (ADC10MEM < 0x250)
			P1OUT &= ~BIT0;
		else
			P1OUT |= BIT0;
		__delay_cycles(500);
		getRight();
		if (ADC10MEM < 0x250)
			P1OUT &= ~BIT6;
		else
			P1OUT |= BIT6;
	}

	return 0;
}
