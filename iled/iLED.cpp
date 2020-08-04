#ifndef __iLED_CPP__
#define __iLED_CPP__

#include "iLED.h"

static const uint8_t numbertable[] = {
	0x3F, /* 0 */
	0x06, /* 1 */
	0x5B, /* 2 */
	0x4F, /* 3 */
	0x66, /* 4 */
	0x6D, /* 5 */
	0x7D, /* 6 */
	0x07, /* 7 */
	0x7F, /* 8 */
	0x6F, /* 9 */
	0x77, /* a */
	0x7C, /* b */
	0x39, /* C */
	0x5E, /* d */
	0x79, /* E */
	0x71, /* F */
};

iLED::iLED(int bus_ch, int dev_addr)
{
	channel = bus_ch;
	address = dev_addr;
	polling_ms = 500;
}

void iLED::init(void)
{
	// clear error flag
	error = false;
	// set initialized flag
	initialized = true;

	// Reset speed of I2C
	i2c_config_t conf;

	conf.mode = I2C_MODE_MASTER;
	conf.sda_io_num = CHAIN_SDA_GPIO;
	conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
	conf.scl_io_num = CHAIN_SCL_GPIO;
	conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
	conf.master.clk_speed = 100E3;

	i2c_param_config(I2C_NUM_1, &conf);
}

int iLED::prop_count(void)
{
	// not supported
	return 0;
}

bool iLED::prop_name(int index, char *name)
{
	// not supported
	return false;
}

bool iLED::prop_unit(int index, char *unit)
{
	// not supported
	return false;
}

bool iLED::prop_attr(int index, char *attr)
{
	// not supported
	return false;
}

bool iLED::prop_read(int index, char *value)
{
	// not supported
	return false;
}

bool iLED::prop_write(int index, char *value)
{
	// not supported
	return false;
}
// --------------------------------------

void iLED::process(Driver *drv)
{
	i2c = (I2CDev *)drv;
	switch (state)
	{
	case s_detect:
		// detect i2c device
		if (i2c->detect(channel, address) == ESP_OK)
		{
			begin();

			// clear error flag
			error = false;
			// set initialized flag
			initialized = true;

			// Go to main state
			state = s_pulling;
		}
		else
		{
			state = s_error;
		}
		break;

	case s_pulling:
	{
		if (is_tickcnt_elapsed(tickcnt, polling_ms))
		{
			tickcnt = get_tickcnt();

			if (i2c->detect(channel, address) != ESP_OK)
			{
				state = s_error;
			}
		}
		break;
	}

	case s_wait:
		if (error)
		{
			// wait polling_ms timeout
			if (is_tickcnt_elapsed(tickcnt, polling_ms))
			{
				state = s_detect;
			}
		}
		break;

	case s_error:
		// set error flag
		error = true;
		// clear initialized flag
		initialized = false;
		// get current tickcnt
		tickcnt = get_tickcnt();
		// goto wait and retry with detect state
		state = s_wait;
		break;
	}
}

// Method
void iLED::setBrightness(uint8_t b)
{
	if (b > 15)
		b = 15;
	
	uint8_t cmd = iLED_CMD_BRIGHTNESS | b;
	i2c->write(channel, address, &cmd, 1);
}

void iLED::blinkRate(uint8_t b)
{
	if (b > 3)
		b = 0; // turn off if not sure

	uint8_t cmd = iLED_BLINK_CMD | iLED_BLINK_DISPLAYON | (b << 1);
	i2c->write(channel, address, &cmd, 1);
}

void iLED::begin()
{
	uint8_t cmd = 0x21;
	i2c->write(channel, address, &cmd, 1);

	blinkRate(iLED_BLINK_OFF);

	setBrightness(15); // max brightness
}

void iLED::writeDisplay(void)
{
	uint8_t data[1 + 16];
	data[0] = 0x00;
	uint8_t inx = 1;
	for (uint8_t i = 0; i < 8; i++)
	{
		data[inx++] = displaybuffer[i] & 0xFF;
		data[inx++] = displaybuffer[i] >> 8;
	}

	i2c->write(channel, address, data, 1 + 16);
}

void iLED::clear(void)
{
	for (uint8_t i = 0; i < 8; i++)
	{
		displaybuffer[i] = 0;
	}
}

void iLED::print(unsigned long n, int base)
{
	if (base == 0)
		write(n);
	else
		printNumber(n, base);
}

void iLED::print(char c, int base) { print((long)c, base); }

void iLED::print(unsigned char b, int base)
{
	print((unsigned long)b, base);
}

void iLED::print(int n, int base) { print((long)n, base); }

void iLED::print(unsigned int n, int base)
{
	print((unsigned long)n, base);
}

void iLED::print(double n, int digits) { printFloat(n, digits); }

size_t iLED::write(uint8_t c)
{

	uint8_t r = 0;

	if (c == '\n')
		position = 0;
	if (c == '\r')
		position = 0;

	if ((c >= '0') && (c <= '9'))
	{
		writeDigitNum(position, c - '0');
		r = 1;
	}

	position++;
	if (position == 2)
		position++;

	return r;
}

void iLED::writeDigitRaw(uint8_t d, uint8_t bitmask)
{
	if (d > 4)
		return;
	displaybuffer[d] = bitmask;
}

void iLED::drawColon(bool state)
{
	if (state)
		displaybuffer[4] = 0x1;
	else
		displaybuffer[4] = 0;
}

void iLED::writeColon(void)
{
	uint8_t buff[3] = { 0x08, (uint8_t)(displaybuffer[4] & 0xFF), (uint8_t)(displaybuffer[4] >> 8) };
	i2c->write(channel, address, buff, 3);
}

void iLED::writeDigitNum(uint8_t d, uint8_t num, bool dot)
{
	if (d > 4)
		return;

	writeDigitRaw(d, numbertable[num] | (dot << 7));
}

void iLED::print(long n, int base) { printNumber(n, base); }

void iLED::printNumber(long n, uint8_t base)
{
	printFloat(n, 0, base);
}

void iLED::printFloat(double n, uint8_t fracDigits, uint8_t base)
{
	uint8_t numericDigits = 4; // available digits on display
	bool isNegative = false;   // true if the number is negative

	// is the number negative?
	if (n < 0)
	{
		isNegative = true; // need to draw sign later
		--numericDigits;   // the sign will take up one digit
		n *= -1;		   // pretend the number is positive
	}

	// calculate the factor required to shift all fractional digits
	// into the integer part of the number
	double toIntFactor = 1.0;
	for (int i = 0; i < fracDigits; ++i)
		toIntFactor *= base;

	// create integer containing digits to display by applying
	// shifting factor and rounding adjustment
	uint32_t displayNumber = n * toIntFactor + 0.5;

	// calculate upper bound on displayNumber given
	// available digits on display
	uint32_t tooBig = 1;
	for (int i = 0; i < numericDigits; ++i)
		tooBig *= base;

	// if displayNumber is too large, try fewer fractional digits
	while (displayNumber >= tooBig)
	{
		--fracDigits;
		toIntFactor /= base;
		displayNumber = n * toIntFactor + 0.5;
	}

	// did toIntFactor shift the decimal off the display?
	if (toIntFactor < 1)
	{
		printError();
	}
	else
	{
		// otherwise, display the number
		int8_t displayPos = 3;

		if (displayNumber) // if displayNumber is not 0
		{
			for (uint8_t i = 0; displayNumber || i <= fracDigits; ++i)
			{
				bool displayDecimal = (fracDigits != 0 && i == fracDigits);
				writeDigitNum(displayPos--, displayNumber % base, displayDecimal);
				/*if (displayPos == 2)
					writeDigitRaw(displayPos--, 0x00);*/
				displayNumber /= base;
			}
		}
		else
		{
			writeDigitNum(displayPos--, 0, false);
		}

		// display negative sign if negative
		if (isNegative)
			writeDigitRaw(displayPos--, 0x40);

		// clear remaining display positions
		while (displayPos >= 0)
			writeDigitRaw(displayPos--, 0x00);
	}
}

void iLED::printError(void)
{
	for (uint8_t i = 0; i < SEVENSEG_DIGITS; ++i)
	{
		writeDigitRaw(i, (i == 2 ? 0x00 : 0x40));
	}
}

void iLED::showDotPoint(uint8_t x, bool show) {
	if (x > 4) return;
	if (x == 4) {
		drawColon(show);
		return;
	}

	if (show) {
		displaybuffer[x] |= (1 << 7);
	} else {
		displaybuffer[x] &= ~(1 << 7);
	}
}

void iLED::turn_on() {
	uint8_t cmd = 0x81;
	i2c->write(channel, address, &cmd, 1);
}

void iLED::turn_off() {
	uint8_t cmd = 0x80;
	i2c->write(channel, address, &cmd, 1);
}

#endif