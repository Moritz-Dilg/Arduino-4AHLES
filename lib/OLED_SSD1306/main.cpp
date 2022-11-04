#include <oled_ssd1306.hpp>

void OLED_SSD1306::init() {
	DDRB |= (1 << PB5);
	oled_init();
	oled_gotoxy(0, 0);
}

void OLED_SSD1306::main() {
	init();

	while (1) {
		for (uint32_t tmp = 1; tmp < 99999999; tmp++) {
			oled_gotoxy(0, 0);
			oled_write("****************");
			oled_gotoxy(0, 1);
			oled_write("*    Dalek     *");
			oled_gotoxy(0, 2);
			oled_write("****************");
			oled_font_size(1);
			oled_gotoxy(0, 4);
			oled_write("%8i", tmp);
			oled_font_size(0);
			_delay_ms(100);
			PORTB ^= (1 << PB5);
		}
	}
}

void OLED_SSD1306::print(char* text, uint8_t x, uint8_t y) {
	oled_gotoxy(x, y);
	oled_write_str(text);
}

void OLED_SSD1306::printNumber(int number, uint8_t x, uint8_t y) {
	oled_gotoxy(x, y);
	oled_write("%4i", number);
}