#include <Arduino.h>

#include <adc_16_interrupt.hpp>
#include <oled_ssd1306.hpp>

volatile uint16_t adcValue = 0;

ISR(ADC_vect) { adcValue = ADC; }

void initADC() {
	DDRC &= ~(1 << PC0);	// PC0-ADC0 als Eingang
	ADMUX |= (1 << REFS0);	// AVcc als Referenz, ADC0 als Eingang
	ADCSRA |= ((1 << ADEN) | (1 << ADSC) | (1 << ADATE) | (1 << ADPS0) |
			   (1 << ADIE) | (1 << ADPS1) |
			   (1 << ADPS2));  // ADC enable + start, Prescaker 128 für 125kHz
}

void ADC_16_Interrupt::main() {
	sei();
	OLED_SSD1306::init();
	OLED_SSD1306::print("ADC16 Interrupt", 0, 0);
	initADC();
	while (true) {
		OLED_SSD1306::printNumber(adcValue, 6, 2);
	}
}