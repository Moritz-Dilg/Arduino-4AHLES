#include <Arduino.h>

#define SDA_PIN PC4
#define SCL_PIN PC5
#define I2C_PORT PORTC
#define SCL_CLOCK 400000UL

void i2c_init(void);
uint8_t i2c_start(uint8_t byte);
uint8_t i2c_byte(uint8_t byte);
void i2c_stop();
unsigned char i2c_readAck(void);
unsigned char i2c_readNak(void);
void i2c_write(unsigned char);