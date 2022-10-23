#include <Arduino.h>

#include <oled_ssd1306.hpp>

int main() {
	// Counter on OLED display; Pin `A4` is SDA, `A5` is SCK
	OLED_SSD1306::main();
}