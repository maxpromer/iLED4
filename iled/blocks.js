Blockly.Blocks['iled_show_number'] = {
	init: function () {
		this.jsonInit({
			"type": "iled_show_number",
			"message0": Blockly.Msg.ILED_SHOW_NUMBER_MESSAGE,
			"args0": [
				{
					"type": "input_value",
					"name": "number",
					"check": "Number"
				},
				{
					"type": "field_number",
					"name": "decimal",
					"value": 2,
					"min": 0,
					"max": 3
				}
			],
			"inputsInline": true,
			"previousStatement": null,
			"nextStatement": null,
			"colour": 105,
			"tooltip": Blockly.Msg.ILED_SHOW_NUMBER_TOOLTIP,
			"helpUrl": ""
		});
	},
	xmlToolbox: function() {
		return `
		<block type="iled_show_number">
		  	<value name="number">
				<shadow type="math_number">
					<field name="VALUE">0</field>
				</shadow>
			</value>
		</block>
		`;
	}
};

Blockly.Blocks['iled_show_digit_at'] = {
	init: function () {
		this.jsonInit({
			"type": "iled_show_digit_at",
			"message0": Blockly.Msg.ILED_SHOW_DIGIT_AT_MESSAGE,
			"args0": [
				{
					"type": "input_value",
					"name": "number",
					"check": "Number"
				},
				{
					"type": "input_value",
					"name": "pos",
					"check": "Number"
				}
			],
			"inputsInline": true,
			"previousStatement": null,
			"nextStatement": null,
			"colour": 105,
			"tooltip": Blockly.Msg.ILED_SHOW_DIGIT_AT_TOOLTIP,
			"helpUrl": ""
		});
	},
	xmlToolbox: function() {
		return `
		<block type="iled_show_digit_at">
		  	<value name="number">
				<shadow type="math_number">
					<field name="VALUE">0</field>
				</shadow>
			</value>
			<value name="pos">
				<shadow type="math_number">
					<field name="VALUE">0</field>
				</shadow>
			</value>
		</block>
		`;
	}
};

Blockly.Blocks['iled_show_char_at'] = {
	init: function () {
		this.jsonInit({
			"type": "iled_show_char_at",
			"message0": Blockly.Msg.ILED_SHOW_CHAR_AT_MESSAGE,
			"args0": [
				{
					"type": "field_dropdown",
					"name": "char",
					"options": [
						[
							"0",
							"0"
						],
						[
							"1",
							"1"
						],
						[
							"2",
							"2"
						],
						[
							"3",
							"3"
						],
						[
							"4",
							"4"
						],
						[
							"5",
							"5"
						],
						[
							"6",
							"6"
						],
						[
							"7",
							"7"
						],
						[
							"8",
							"9"
						],
						[
							"9",
							"9"
						],
						[
							"a",
							"10"
						],
						[
							"b",
							"11"
						],
						[
							"C",
							"12"
						],
						[
							"d",
							"13"
						],
						[
							"E",
							"14"
						],
						[
							"F",
							"15"
						]
					]
				},
				{
					"type": "input_value",
					"name": "pos",
					"check": "Number"
				}
			],
			"inputsInline": true,
			"previousStatement": null,
			"nextStatement": null,
			"colour": 105,
			"tooltip": Blockly.Msg.ILED_SHOW_CHAR_AT_TOOLTIP,
			"helpUrl": ""
		});
	},
	xmlToolbox: function() {
		return `
		<block type="iled_show_char_at">
		  	<value name="pos">
				<shadow type="math_number">
					<field name="VALUE">0</field>
				</shadow>
			</value>
		</block>
		`;
	}
};

Blockly.Blocks['iled_show_hex_number'] = {
	init: function () {
		this.jsonInit({
			"type": "iled_show_hex_number",
			"message0": Blockly.Msg.ILED_SHOW_HEX_NUMBER_MESSAGE,
			"args0": [
				{
					"type": "input_value",
					"name": "number",
					"check": "Number"
				}
			],
			"inputsInline": true,
			"previousStatement": null,
			"nextStatement": null,
			"colour": 105,
			"tooltip": Blockly.Msg.ILED_SHOW_HEX_NUMBER_TOOLTIP,
			"helpUrl": ""
		});
	},
	xmlToolbox: function() {
		return `
		<block type="iled_show_hex_number">
		  	<value name="number">
				<shadow type="math_number">
					<field name="VALUE">255</field>
				</shadow>
			</value>
		</block>
		`;
	}
};

Blockly.Blocks['iled_turn_on'] = {
	init: function () {
		this.jsonInit({
			"type": "iled_turn_on",
			"message0": Blockly.Msg.ILED_TURN_ON_MESSAGE,
			"previousStatement": null,
			"nextStatement": null,
			"colour": 105,
			"tooltip": Blockly.Msg.ILED_TURN_ON_TOOLTIP,
			"helpUrl": ""
		});
	}
};

Blockly.Blocks['iled_turn_off'] = {
	init: function () {
		this.jsonInit({
			"type": "iled_turn_off",
			"message0": Blockly.Msg.ILED_TURN_OFF_MESSAGE,
			"previousStatement": null,
			"nextStatement": null,
			"colour": 105,
			"tooltip": Blockly.Msg.ILED_TURN_OFF_TOOLTIP,
			"helpUrl": ""
		});
	}
};

Blockly.Blocks['iled_clear'] = {
	init: function () {
		this.jsonInit({
			"type": "iled_clear",
			"message0": Blockly.Msg.ILED_CLEAR_MESSAGE,
			"previousStatement": null,
			"nextStatement": null,
			"colour": 105,
			"tooltip": Blockly.Msg.ILED_CLEAR_TOOLTIP,
			"helpUrl": ""
		});
	}
};

Blockly.Blocks['iled_set_dotpoint'] = {
	init: function () {
		this.jsonInit({
			"type": "iled_set_dotpoint",
			"message0": Blockly.Msg.ILED_SET_DOTPOINT_MESSAGE,
			"args0": [
				{
					"type": "input_value",
					"name": "pos",
					"check": "Number"
				},
				{
					"type": "field_dropdown",
					"name": "show",
					"options": [
						[
							Blockly.Msg.ILED_SET_DOTPOINT_TRUE_MESSAGE,
							"true"
						],
						[
							Blockly.Msg.ILED_SET_DOTPOINT_FALSE_MESSAGE,
							"false"
						]
					]
				}
			],
			"previousStatement": null,
			"nextStatement": null,
			"colour": 105,
			"tooltip": Blockly.Msg.ILED_SET_DOTPOINT_TOOLTIP,
			"helpUrl": ""
		});
	},
	xmlToolbox: function() {
		return `
		<block type="iled_set_dotpoint">
		  	<value name="pos">
				<shadow type="math_number">
					<field name="VALUE">0</field>
				</shadow>
			</value>
		</block>
		`;
	}
};

Blockly.Blocks['iled_set_colon'] = {
	init: function () {
		this.jsonInit({
			"type": "iled_set_colon",
			"message0": Blockly.Msg.ILED_SET_COLON_MESSAGE,
			"args0": [
				{
					"type": "field_dropdown",
					"name": "show",
					"options": [
						[
							Blockly.Msg.ILED_SET_DOTPOINT_TRUE_MESSAGE,
							"true"
						],
						[
							Blockly.Msg.ILED_SET_DOTPOINT_FALSE_MESSAGE,
							"false"
						]
					]
				}
			],
			"previousStatement": null,
			"nextStatement": null,
			"colour": 105,
			"tooltip": Blockly.Msg.ILED_SET_COLON_TOOLTIP,
			"helpUrl": ""
		});
	}
};

Blockly.Blocks['iled_set_intensity'] = {
	init: function () {
		this.jsonInit({
			"type": "iled_set_intensity",
			"message0": Blockly.Msg.ILED_SET_INTENSITY_MESSAGE,
			"args0": [
				{
					"type": "input_value",
					"name": "intensity",
					"check": "Number"
				}
			],
			"inputsInline": true,
			"previousStatement": null,
			"nextStatement": null,
			"colour": 105,
			"tooltip": Blockly.Msg.ILED_SET_INTENSITY_TOOLTIP,
			"helpUrl": ""
		});
	},
	xmlToolbox: function() {
		return `
		<block type="iled_set_intensity">
		  	<value name="intensity">
				<shadow type="math_number">
					<field name="VALUE">15</field>
				</shadow>
			</value>
		</block>
		`;
	}
};
