const iLED_BEGIN_WORD = 'DEV_I2C1.iLED(0, 0x70)';

Blockly.JavaScript['iled_show_number'] = function (block) {
	var value_number = Blockly.JavaScript.valueToCode(block, 'number', Blockly.JavaScript.ORDER_ATOMIC) || '0';
	var number_decimal = block.getFieldValue('decimal');
	var code = `${iLED_BEGIN_WORD}.printFloat(${value_number}, ${number_decimal}, DEC); ${iLED_BEGIN_WORD}.writeDisplay();\n`;
	return code;
};

Blockly.JavaScript['iled_show_digit_at'] = function (block) {
	var value_number = Blockly.JavaScript.valueToCode(block, 'number', Blockly.JavaScript.ORDER_ATOMIC) || '0';
	var value_pos = Blockly.JavaScript.valueToCode(block, 'pos', Blockly.JavaScript.ORDER_ATOMIC) || '0';
	var code = `${iLED_BEGIN_WORD}.writeDigitNum(${value_pos}, ${value_number}, false); ${iLED_BEGIN_WORD}.writeDisplay();\n`;
	return code;
};

Blockly.JavaScript['iled_show_char_at'] = function (block) {
	var dropdown_char = block.getFieldValue('char');
	var value_pos = Blockly.JavaScript.valueToCode(block, 'pos', Blockly.JavaScript.ORDER_ATOMIC) || '0';
	var code = `${iLED_BEGIN_WORD}.writeDigitNum(${value_pos}, ${dropdown_char}, false); ${iLED_BEGIN_WORD}.writeDisplay();\n`;
	return code;
};

Blockly.JavaScript['iled_show_hex_number'] = function (block) {
	var value_number = Blockly.JavaScript.valueToCode(block, 'number', Blockly.JavaScript.ORDER_ATOMIC) || '0';
	var code = `${iLED_BEGIN_WORD}.print((int)(${value_number}), HEX); ${iLED_BEGIN_WORD}.writeDisplay();\n`;
	return code;
};

Blockly.JavaScript['iled_turn_on'] = function (block) {
	var code = `${iLED_BEGIN_WORD}.turn_on();\n`;
	return code;
};

Blockly.JavaScript['iled_turn_off'] = function (block) {
	var code = `${iLED_BEGIN_WORD}.turn_off();\n`;
	return code;
};

Blockly.JavaScript['iled_clear'] = function (block) {
	var code = `${iLED_BEGIN_WORD}.clear(); ${iLED_BEGIN_WORD}.writeDisplay();\n`;
	return code;
};

Blockly.JavaScript['iled_set_dotpoint'] = function (block) {
	var value_pos = Blockly.JavaScript.valueToCode(block, 'pos', Blockly.JavaScript.ORDER_ATOMIC) || '0';
	var dropdown_show = block.getFieldValue('show');
	var code = `${iLED_BEGIN_WORD}.showDotPoint(${value_pos}, ${dropdown_show}); ${iLED_BEGIN_WORD}.writeDisplay();\n`;
	return code;
};

Blockly.JavaScript['iled_set_colon'] = function (block) {
	var dropdown_show = block.getFieldValue('show');
	var code = `${iLED_BEGIN_WORD}.drawColon(${dropdown_show}); ${iLED_BEGIN_WORD}.writeDisplay();\n`;
	return code;
};

Blockly.JavaScript['iled_set_intensity'] = function (block) {
	var value_intensity = Blockly.JavaScript.valueToCode(block, 'intensity', Blockly.JavaScript.ORDER_ATOMIC) || '15';
	var code = `${iLED_BEGIN_WORD}.setBrightness(${value_intensity});\n`;
	return code;
};
