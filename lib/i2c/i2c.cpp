#include "i2c.hpp"

void i2c_init(void) {
	I2C_PORT |= (1 << SDA_PIN | 1 << SCL_PIN);	// Port Pullup
	TWCR = 0;
	TWSR = 0;
	TWBR = ((F_CPU / SCL_CLOCK) - 16) / 2;
	_delay_ms(50);
}

uint8_t i2c_start(uint8_t byte) {
	uint8_t timeout = 0;
	TWCR = (1 << TWINT | 1 << TWSTA | 1 << TWEN);
	while (!(TWCR & (1 << TWINT))) {
		if ((timeout++) > 100) return 1;
	}
	TWDR = byte;
	TWCR = (1 << TWINT | 1 << TWEN);
	timeout = 0;
	while (!(TWCR & (1 << TWINT))) {
		if ((timeout++) > 100) return 1;
	}
	return 0;
}

void i2c_stop(void) {
	TWCR = (1 << TWINT | 1 << TWSTO | 1 << TWEN);
	TWCR = 0;
}

uint8_t i2c_byte(uint8_t byte) {
	uint8_t timeout = 0;
	TWDR = byte;
	TWCR = (1 << TWINT | 1 << TWEN);
	while (!(TWCR & (1 << TWINT))) {
		if ((timeout++) > 100) return 1;
	}
	return 0;
}
/*************************************************************************
 Read one byte from the I2C device, request more data from device

 Return:  byte read from I2C device
*************************************************************************/
unsigned char i2c_readAck(void) {
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
	while (!(TWCR & (1 << TWINT)))
		;

	return TWDR;

} /* i2c_readAck */

/*************************************************************************
 Read one byte from the I2C device, read is followed by a stop condition

 Return:  byte read from I2C device
*************************************************************************/
unsigned char i2c_readNak(void) {
	TWCR = (1 << TWINT) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)))
		;

	return TWDR;

} /* i2c_readNak */
/*************************************************************************
  Send one byte to I2C device

  Input:    byte to be transfered
  Return:   0 write successful
			1 write failed
*************************************************************************/
void i2c_write(unsigned char data) {
	// send data to the previously addressed device
	TWDR = data;
	TWCR = (1 << TWINT) | (1 << TWEN);

	// wait until transmission completed
	while (!(TWCR & (1 << TWINT)))
		;

} /* i2c_write */
