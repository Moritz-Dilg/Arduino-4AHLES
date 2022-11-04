#include <Arduino.h>

#include <adc_16.hpp>
#include <adc_16_interrupt.hpp>
#include <oled_ssd1306.hpp>

int main() {
	// Counter on OLED display; Pin `A4` is SDA, `A5` is SCK
	// OLED_SSD1306::main();

	// ADC on Pin `A0`
	// ADC_16::main();

	// ADC on Pin `A0` with Interrupt
	ADC_16_Interrupt::main();
}