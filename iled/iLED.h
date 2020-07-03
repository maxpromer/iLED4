#ifndef __iLED_H__
#define __iLED_H__

#include "driver.h"
#include "device.h"
#include "i2c-dev.h"
#include "kidbright32.h"

#define LED_ON 1  ///< GFX color of lit LED segments (single-color displays)
#define LED_OFF 0 ///< GFX color of unlit LED segments (single-color displays)

#define LED_RED 1	 ///< GFX color for red LED segments (bi-color displays)
#define LED_YELLOW 2 ///< GFX color for yellow LED segments (bi-color displays)
#define LED_GREEN 3	 ///< GFX color for green LED segments (bi-color displays)

#define iLED_BLINK_CMD 0x80		 ///< I2C register for BLINK setting
#define iLED_BLINK_DISPLAYON 0x01 ///< I2C value for steady on
#define iLED_BLINK_OFF 0			 ///< I2C value for steady off
#define iLED_BLINK_2HZ 1			 ///< I2C value for 2 Hz blink
#define iLED_BLINK_1HZ 2			 ///< I2C value for 1 Hz blink
#define iLED_BLINK_HALFHZ 3		 ///< I2C value for 0.5 Hz blink

#define iLED_CMD_BRIGHTNESS 0xE0 ///< I2C register for BRIGHTNESS setting

#define SEVENSEG_DIGITS 5 ///< # Digits in 7-seg displays, plus NUL end

#define DEC 10 ///< Print value in decimal format (base 10)
#define HEX 16 ///< Print value in hexadecimal format (base 16)
#define OCT 8  ///< Print value in octal format (base 8)
#define BIN 2  ///< Print value in binary format (base 2)
#define BYTE 0 ///< Issue 7-segment data as raw bits

class iLED : public Device
{
private:
	enum
	{
		s_detect,
		s_pulling,
		s_wait,
		s_error
	} state;
	TickType_t tickcnt, polling_tickcnt;

	I2CDev *i2c;
	
	uint8_t position; ///< Current print position, 0-3

public:
	// constructor
	iLED(int bus_ch, int dev_addr);

	// override
	void init(void);
	void process(Driver *drv);
	int prop_count(void);
	bool prop_name(int index, char *name);
	bool prop_unit(int index, char *unit);
	bool prop_attr(int index, char *attr);
	bool prop_read(int index, char *value);
	bool prop_write(int index, char *value);

	// method
	void begin();
	void setBrightness(uint8_t b);
	void blinkRate(uint8_t b);
	void writeDisplay(void);
	void clear(void);

	uint16_t displaybuffer[8]; ///< Raw display data

	size_t write(uint8_t c);

	void print(char c, int base = BYTE);
	void print(unsigned char b, int base = BYTE);
	void print(int n, int base = DEC);
	void print(unsigned int n, int base = DEC);
	void print(long n, int base = DEC);
	void print(unsigned long n, int base = DEC);
	void print(double n, int digits = 2);

	void writeDigitRaw(uint8_t x, uint8_t bitmask);
	void writeDigitNum(uint8_t x, uint8_t num, bool dot = false);
	void drawColon(bool state);
	void printNumber(long n, uint8_t base = 2);
	void printFloat(double n, uint8_t fracDigits = 2, uint8_t base = DEC);
	void printError(void);
	void writeColon(void);

	void showDotPoint(uint8_t x, bool show);

	void turn_on() ;
	void turn_off() ;
};

#endif