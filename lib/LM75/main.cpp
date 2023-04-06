#include <oled_ssd1306.hpp>

#include "LM75.hpp"
#include "i2c.hpp"

int8_t getTemp() {
	int8_t tmp = 0;

	i2c_start(0b10010000);
	i2c_write(0);
	i2c_write(0b10010001);
	tmp = i2c_readNak();
	i2c_stop();

	return tmp;
}

uint8_t setOTemp(int8_t OTemp, int8_t Hyst) {
	int8_t tmp = 0;

	return tmp;
}

void LM75::main() {
	DDRB |= (1 << PB5);
	OLED_SSD1306::init();
	OLED_SSD1306::print("Temperature", 0, 0);
	Serial.begin(9600);

	while (1) {
		int8_t tmp = 0;
		tmp = getTemp();
		Serial.print("Temp: ");
		Serial.println(tmp);
		// OLED_SSD1306::printNumber(tmp, 0, 4);
		// OLED_SSD1306::print("Grad C", 4, 4);
		setOTemp(28, 26);
		// delay(100);
		PORTB ^= (1 << PB5);
	}
}