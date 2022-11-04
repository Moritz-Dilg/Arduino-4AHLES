#include <Arduino.h>

#include <adc_16.hpp>
#include <oled_ssd1306.hpp>

uint16_t getADC() {
	DDRC &= ~(1 << PC0);	// PC0-ADC0 als Eingang
	ADMUX |= (1 << REFS0);	// AVcc als Referenz, ADC0 als Eingang
	ADCSRA |= ((1 << ADEN) | (1 << ADSC) | (1 << ADPS0) | (1 << ADPS1) |
			   (1 << ADPS2));  // ADC enable + start, Prescaker 128 für 125kHz
	while ((ADCSRA & (1 << ADSC)))	// ADSC maskieren, warten bis ADSC=0
		;
	return ADC;
}

void ADC_16::main() {
	OLED_SSD1306::init();
	OLED_SSD1306::print("ADC16", 0, 0);
	while (true) {
		OLED_SSD1306::printNumber(getADC(), 6, 2);
	}
}