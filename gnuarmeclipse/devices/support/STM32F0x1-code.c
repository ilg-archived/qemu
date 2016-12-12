// DO NOT EDIT! Automatically generated!
// Support code for STM32F0x1.

// CRC (Cyclic redundancy check calculation unit) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F0 CRC (Cyclic redundancy check calculation unit) registers.
		struct {
			Object *dr; // 0x0 Data register
			Object *idr; // 0x4 Independent data register
			Object *cr; // 0x8 Control register
			Object *init; // 0xC Initial CRC value
		} reg;

		struct {

			// DR (Data register) bitfields.
			struct {
				Object *dr; // [0:31] Data register bits
			} dr;

			// IDR (Independent data register) bitfields.
			struct {
				Object *idr; // [0:7] General-purpose 8-bit data register bits
			} idr;

			// CR (Control register) bitfields.
			struct {
				Object *reset; // [0:0] Reset bit
				Object *polysize; // [3:4] Polynomial size
				Object *rev_in; // [5:6] Reverse input data
				Object *rev_out; // [7:7] Reverse output data
			} cr;

			// INIT (Initial CRC value) bitfields.
			struct {
				Object *init; // [0:31] Programmable initial CRC value
			} init;
		} fld;
	} f0;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32CRCState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_crc_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32CRCState *state = STM32_CRC_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f0.reg.dr = cm_object_get_child_by_name(obj, "DR");
	state->f0.reg.idr = cm_object_get_child_by_name(obj, "IDR");
	state->f0.reg.cr = cm_object_get_child_by_name(obj, "CR");
	state->f0.reg.init = cm_object_get_child_by_name(obj, "INIT");

	// DR bitfields.
	state->f0.fld.dr.dr = cm_object_get_child_by_name(state->f0.reg.dr, "DR");

	// IDR bitfields.
	state->f0.fld.idr.idr = cm_object_get_child_by_name(state->f0.reg.idr, "IDR");

	// CR bitfields.
	state->f0.fld.cr.reset = cm_object_get_child_by_name(state->f0.reg.cr, "RESET");
	state->f0.fld.cr.polysize = cm_object_get_child_by_name(state->f0.reg.cr, "POLYSIZE");
	state->f0.fld.cr.rev_in = cm_object_get_child_by_name(state->f0.reg.cr, "REV_IN");
	state->f0.fld.cr.rev_out = cm_object_get_child_by_name(state->f0.reg.cr, "REV_OUT");

	// INIT bitfields.
	state->f0.fld.init.init = cm_object_get_child_by_name(state->f0.reg.init, "INIT");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// GPIOF (General-purpose I/Os) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F0 GPIOF (General-purpose I/Os) registers.
		struct {
			Object *moder; // 0x0 GPIO port mode register
			Object *otyper; // 0x4 GPIO port output type register
			Object *ospeedr; // 0x8 GPIO port output speed register
			Object *pupdr; // 0xC GPIO port pull-up/pull-down register
			Object *idr; // 0x10 GPIO port input data register
			Object *odr; // 0x14 GPIO port output data register
			Object *bsrr; // 0x18 GPIO port bit set/reset register
			Object *lckr; // 0x1C GPIO port configuration lock register
			Object *afrl; // 0x20 GPIO alternate function low register
			Object *afrh; // 0x24 GPIO alternate function high register
			Object *brr; // 0x28 Port bit reset register
		} reg;

		struct {

			// MODER (GPIO port mode register) bitfields.
			struct {
				Object *moder0; // [0:1] Port x configuration bits (y = 0..15)
				Object *moder1; // [2:3] Port x configuration bits (y = 0..15)
				Object *moder2; // [4:5] Port x configuration bits (y = 0..15)
				Object *moder3; // [6:7] Port x configuration bits (y = 0..15)
				Object *moder4; // [8:9] Port x configuration bits (y = 0..15)
				Object *moder5; // [10:11] Port x configuration bits (y = 0..15)
				Object *moder6; // [12:13] Port x configuration bits (y = 0..15)
				Object *moder7; // [14:15] Port x configuration bits (y = 0..15)
				Object *moder8; // [16:17] Port x configuration bits (y = 0..15)
				Object *moder9; // [18:19] Port x configuration bits (y = 0..15)
				Object *moder10; // [20:21] Port x configuration bits (y = 0..15)
				Object *moder11; // [22:23] Port x configuration bits (y = 0..15)
				Object *moder12; // [24:25] Port x configuration bits (y = 0..15)
				Object *moder13; // [26:27] Port x configuration bits (y = 0..15)
				Object *moder14; // [28:29] Port x configuration bits (y = 0..15)
				Object *moder15; // [30:31] Port x configuration bits (y = 0..15)
			} moder;

			// OTYPER (GPIO port output type register) bitfields.
			struct {
				Object *ot0; // [0:0] Port x configuration bit 0
				Object *ot1; // [1:1] Port x configuration bit 1
				Object *ot2; // [2:2] Port x configuration bit 2
				Object *ot3; // [3:3] Port x configuration bit 3
				Object *ot4; // [4:4] Port x configuration bit 4
				Object *ot5; // [5:5] Port x configuration bit 5
				Object *ot6; // [6:6] Port x configuration bit 6
				Object *ot7; // [7:7] Port x configuration bit 7
				Object *ot8; // [8:8] Port x configuration bit 8
				Object *ot9; // [9:9] Port x configuration bit 9
				Object *ot10; // [10:10] Port x configuration bit 10
				Object *ot11; // [11:11] Port x configuration bit 11
				Object *ot12; // [12:12] Port x configuration bit 12
				Object *ot13; // [13:13] Port x configuration bit 13
				Object *ot14; // [14:14] Port x configuration bit 14
				Object *ot15; // [15:15] Port x configuration bit 15
			} otyper;

			// OSPEEDR (GPIO port output speed register) bitfields.
			struct {
				Object *ospeedr0; // [0:1] Port x configuration bits (y = 0..15)
				Object *ospeedr1; // [2:3] Port x configuration bits (y = 0..15)
				Object *ospeedr2; // [4:5] Port x configuration bits (y = 0..15)
				Object *ospeedr3; // [6:7] Port x configuration bits (y = 0..15)
				Object *ospeedr4; // [8:9] Port x configuration bits (y = 0..15)
				Object *ospeedr5; // [10:11] Port x configuration bits (y = 0..15)
				Object *ospeedr6; // [12:13] Port x configuration bits (y = 0..15)
				Object *ospeedr7; // [14:15] Port x configuration bits (y = 0..15)
				Object *ospeedr8; // [16:17] Port x configuration bits (y = 0..15)
				Object *ospeedr9; // [18:19] Port x configuration bits (y = 0..15)
				Object *ospeedr10; // [20:21] Port x configuration bits (y = 0..15)
				Object *ospeedr11; // [22:23] Port x configuration bits (y = 0..15)
				Object *ospeedr12; // [24:25] Port x configuration bits (y = 0..15)
				Object *ospeedr13; // [26:27] Port x configuration bits (y = 0..15)
				Object *ospeedr14; // [28:29] Port x configuration bits (y = 0..15)
				Object *ospeedr15; // [30:31] Port x configuration bits (y = 0..15)
			} ospeedr;

			// PUPDR (GPIO port pull-up/pull-down register) bitfields.
			struct {
				Object *pupdr0; // [0:1] Port x configuration bits (y = 0..15)
				Object *pupdr1; // [2:3] Port x configuration bits (y = 0..15)
				Object *pupdr2; // [4:5] Port x configuration bits (y = 0..15)
				Object *pupdr3; // [6:7] Port x configuration bits (y = 0..15)
				Object *pupdr4; // [8:9] Port x configuration bits (y = 0..15)
				Object *pupdr5; // [10:11] Port x configuration bits (y = 0..15)
				Object *pupdr6; // [12:13] Port x configuration bits (y = 0..15)
				Object *pupdr7; // [14:15] Port x configuration bits (y = 0..15)
				Object *pupdr8; // [16:17] Port x configuration bits (y = 0..15)
				Object *pupdr9; // [18:19] Port x configuration bits (y = 0..15)
				Object *pupdr10; // [20:21] Port x configuration bits (y = 0..15)
				Object *pupdr11; // [22:23] Port x configuration bits (y = 0..15)
				Object *pupdr12; // [24:25] Port x configuration bits (y = 0..15)
				Object *pupdr13; // [26:27] Port x configuration bits (y = 0..15)
				Object *pupdr14; // [28:29] Port x configuration bits (y = 0..15)
				Object *pupdr15; // [30:31] Port x configuration bits (y = 0..15)
			} pupdr;

			// IDR (GPIO port input data register) bitfields.
			struct {
				Object *idr0; // [0:0] Port input data (y = 0..15)
				Object *idr1; // [1:1] Port input data (y = 0..15)
				Object *idr2; // [2:2] Port input data (y = 0..15)
				Object *idr3; // [3:3] Port input data (y = 0..15)
				Object *idr4; // [4:4] Port input data (y = 0..15)
				Object *idr5; // [5:5] Port input data (y = 0..15)
				Object *idr6; // [6:6] Port input data (y = 0..15)
				Object *idr7; // [7:7] Port input data (y = 0..15)
				Object *idr8; // [8:8] Port input data (y = 0..15)
				Object *idr9; // [9:9] Port input data (y = 0..15)
				Object *idr10; // [10:10] Port input data (y = 0..15)
				Object *idr11; // [11:11] Port input data (y = 0..15)
				Object *idr12; // [12:12] Port input data (y = 0..15)
				Object *idr13; // [13:13] Port input data (y = 0..15)
				Object *idr14; // [14:14] Port input data (y = 0..15)
				Object *idr15; // [15:15] Port input data (y = 0..15)
			} idr;

			// ODR (GPIO port output data register) bitfields.
			struct {
				Object *odr0; // [0:0] Port output data (y = 0..15)
				Object *odr1; // [1:1] Port output data (y = 0..15)
				Object *odr2; // [2:2] Port output data (y = 0..15)
				Object *odr3; // [3:3] Port output data (y = 0..15)
				Object *odr4; // [4:4] Port output data (y = 0..15)
				Object *odr5; // [5:5] Port output data (y = 0..15)
				Object *odr6; // [6:6] Port output data (y = 0..15)
				Object *odr7; // [7:7] Port output data (y = 0..15)
				Object *odr8; // [8:8] Port output data (y = 0..15)
				Object *odr9; // [9:9] Port output data (y = 0..15)
				Object *odr10; // [10:10] Port output data (y = 0..15)
				Object *odr11; // [11:11] Port output data (y = 0..15)
				Object *odr12; // [12:12] Port output data (y = 0..15)
				Object *odr13; // [13:13] Port output data (y = 0..15)
				Object *odr14; // [14:14] Port output data (y = 0..15)
				Object *odr15; // [15:15] Port output data (y = 0..15)
			} odr;

			// BSRR (GPIO port bit set/reset register) bitfields.
			struct {
				Object *bs0; // [0:0] Port x set bit y (y= 0..15)
				Object *bs1; // [1:1] Port x set bit y (y= 0..15)
				Object *bs2; // [2:2] Port x set bit y (y= 0..15)
				Object *bs3; // [3:3] Port x set bit y (y= 0..15)
				Object *bs4; // [4:4] Port x set bit y (y= 0..15)
				Object *bs5; // [5:5] Port x set bit y (y= 0..15)
				Object *bs6; // [6:6] Port x set bit y (y= 0..15)
				Object *bs7; // [7:7] Port x set bit y (y= 0..15)
				Object *bs8; // [8:8] Port x set bit y (y= 0..15)
				Object *bs9; // [9:9] Port x set bit y (y= 0..15)
				Object *bs10; // [10:10] Port x set bit y (y= 0..15)
				Object *bs11; // [11:11] Port x set bit y (y= 0..15)
				Object *bs12; // [12:12] Port x set bit y (y= 0..15)
				Object *bs13; // [13:13] Port x set bit y (y= 0..15)
				Object *bs14; // [14:14] Port x set bit y (y= 0..15)
				Object *bs15; // [15:15] Port x set bit y (y= 0..15)
				Object *br0; // [16:16] Port x set bit y (y= 0..15)
				Object *br1; // [17:17] Port x reset bit y (y = 0..15)
				Object *br2; // [18:18] Port x reset bit y (y = 0..15)
				Object *br3; // [19:19] Port x reset bit y (y = 0..15)
				Object *br4; // [20:20] Port x reset bit y (y = 0..15)
				Object *br5; // [21:21] Port x reset bit y (y = 0..15)
				Object *br6; // [22:22] Port x reset bit y (y = 0..15)
				Object *br7; // [23:23] Port x reset bit y (y = 0..15)
				Object *br8; // [24:24] Port x reset bit y (y = 0..15)
				Object *br9; // [25:25] Port x reset bit y (y = 0..15)
				Object *br10; // [26:26] Port x reset bit y (y = 0..15)
				Object *br11; // [27:27] Port x reset bit y (y = 0..15)
				Object *br12; // [28:28] Port x reset bit y (y = 0..15)
				Object *br13; // [29:29] Port x reset bit y (y = 0..15)
				Object *br14; // [30:30] Port x reset bit y (y = 0..15)
				Object *br15; // [31:31] Port x reset bit y (y = 0..15)
			} bsrr;

			// LCKR (GPIO port configuration lock register) bitfields.
			struct {
				Object *lck0; // [0:0] Port x lock bit y (y= 0..15)
				Object *lck1; // [1:1] Port x lock bit y (y= 0..15)
				Object *lck2; // [2:2] Port x lock bit y (y= 0..15)
				Object *lck3; // [3:3] Port x lock bit y (y= 0..15)
				Object *lck4; // [4:4] Port x lock bit y (y= 0..15)
				Object *lck5; // [5:5] Port x lock bit y (y= 0..15)
				Object *lck6; // [6:6] Port x lock bit y (y= 0..15)
				Object *lck7; // [7:7] Port x lock bit y (y= 0..15)
				Object *lck8; // [8:8] Port x lock bit y (y= 0..15)
				Object *lck9; // [9:9] Port x lock bit y (y= 0..15)
				Object *lck10; // [10:10] Port x lock bit y (y= 0..15)
				Object *lck11; // [11:11] Port x lock bit y (y= 0..15)
				Object *lck12; // [12:12] Port x lock bit y (y= 0..15)
				Object *lck13; // [13:13] Port x lock bit y (y= 0..15)
				Object *lck14; // [14:14] Port x lock bit y (y= 0..15)
				Object *lck15; // [15:15] Port x lock bit y (y= 0..15)
				Object *lckk; // [16:16] Port x lock bit y
			} lckr;

			// AFRL (GPIO alternate function low register) bitfields.
			struct {
				Object *afrl0; // [0:3] Alternate function selection for port x bit y (y = 0..7)
				Object *afrl1; // [4:7] Alternate function selection for port x bit y (y = 0..7)
				Object *afrl2; // [8:11] Alternate function selection for port x bit y (y = 0..7)
				Object *afrl3; // [12:15] Alternate function selection for port x bit y (y = 0..7)
				Object *afrl4; // [16:19] Alternate function selection for port x bit y (y = 0..7)
				Object *afrl5; // [20:23] Alternate function selection for port x bit y (y = 0..7)
				Object *afrl6; // [24:27] Alternate function selection for port x bit y (y = 0..7)
				Object *afrl7; // [28:31] Alternate function selection for port x bit y (y = 0..7)
			} afrl;

			// AFRH (GPIO alternate function high register) bitfields.
			struct {
				Object *afrh8; // [0:3] Alternate function selection for port x bit y (y = 8..15)
				Object *afrh9; // [4:7] Alternate function selection for port x bit y (y = 8..15)
				Object *afrh10; // [8:11] Alternate function selection for port x bit y (y = 8..15)
				Object *afrh11; // [12:15] Alternate function selection for port x bit y (y = 8..15)
				Object *afrh12; // [16:19] Alternate function selection for port x bit y (y = 8..15)
				Object *afrh13; // [20:23] Alternate function selection for port x bit y (y = 8..15)
				Object *afrh14; // [24:27] Alternate function selection for port x bit y (y = 8..15)
				Object *afrh15; // [28:31] Alternate function selection for port x bit y (y = 8..15)
			} afrh;

			// BRR (Port bit reset register) bitfields.
			struct {
				Object *br0; // [0:0] Port x Reset bit y
				Object *br1; // [1:1] Port x Reset bit y
				Object *br2; // [2:2] Port x Reset bit y
				Object *br3; // [3:3] Port x Reset bit y
				Object *br4; // [4:4] Port x Reset bit y
				Object *br5; // [5:5] Port x Reset bit y
				Object *br6; // [6:6] Port x Reset bit y
				Object *br7; // [7:7] Port x Reset bit y
				Object *br8; // [8:8] Port x Reset bit y
				Object *br9; // [9:9] Port x Reset bit y
				Object *br10; // [10:10] Port x Reset bit y
				Object *br11; // [11:11] Port x Reset bit y
				Object *br12; // [12:12] Port x Reset bit y
				Object *br13; // [13:13] Port x Reset bit y
				Object *br14; // [14:14] Port x Reset bit y
				Object *br15; // [15:15] Port x Reset bit y
			} brr;
		} fld;
	} f0;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32GPIOFState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_gpiof_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32GPIOFState *state = STM32_GPIOF_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f0.reg.moder = cm_object_get_child_by_name(obj, "MODER");
	state->f0.reg.otyper = cm_object_get_child_by_name(obj, "OTYPER");
	state->f0.reg.ospeedr = cm_object_get_child_by_name(obj, "OSPEEDR");
	state->f0.reg.pupdr = cm_object_get_child_by_name(obj, "PUPDR");
	state->f0.reg.idr = cm_object_get_child_by_name(obj, "IDR");
	state->f0.reg.odr = cm_object_get_child_by_name(obj, "ODR");
	state->f0.reg.bsrr = cm_object_get_child_by_name(obj, "BSRR");
	state->f0.reg.lckr = cm_object_get_child_by_name(obj, "LCKR");
	state->f0.reg.afrl = cm_object_get_child_by_name(obj, "AFRL");
	state->f0.reg.afrh = cm_object_get_child_by_name(obj, "AFRH");
	state->f0.reg.brr = cm_object_get_child_by_name(obj, "BRR");

	// MODER bitfields.
	state->f0.fld.moder.moder0 = cm_object_get_child_by_name(state->f0.reg.moder, "MODER0");
	state->f0.fld.moder.moder1 = cm_object_get_child_by_name(state->f0.reg.moder, "MODER1");
	state->f0.fld.moder.moder2 = cm_object_get_child_by_name(state->f0.reg.moder, "MODER2");
	state->f0.fld.moder.moder3 = cm_object_get_child_by_name(state->f0.reg.moder, "MODER3");
	state->f0.fld.moder.moder4 = cm_object_get_child_by_name(state->f0.reg.moder, "MODER4");
	state->f0.fld.moder.moder5 = cm_object_get_child_by_name(state->f0.reg.moder, "MODER5");
	state->f0.fld.moder.moder6 = cm_object_get_child_by_name(state->f0.reg.moder, "MODER6");
	state->f0.fld.moder.moder7 = cm_object_get_child_by_name(state->f0.reg.moder, "MODER7");
	state->f0.fld.moder.moder8 = cm_object_get_child_by_name(state->f0.reg.moder, "MODER8");
	state->f0.fld.moder.moder9 = cm_object_get_child_by_name(state->f0.reg.moder, "MODER9");
	state->f0.fld.moder.moder10 = cm_object_get_child_by_name(state->f0.reg.moder, "MODER10");
	state->f0.fld.moder.moder11 = cm_object_get_child_by_name(state->f0.reg.moder, "MODER11");
	state->f0.fld.moder.moder12 = cm_object_get_child_by_name(state->f0.reg.moder, "MODER12");
	state->f0.fld.moder.moder13 = cm_object_get_child_by_name(state->f0.reg.moder, "MODER13");
	state->f0.fld.moder.moder14 = cm_object_get_child_by_name(state->f0.reg.moder, "MODER14");
	state->f0.fld.moder.moder15 = cm_object_get_child_by_name(state->f0.reg.moder, "MODER15");

	// OTYPER bitfields.
	state->f0.fld.otyper.ot0 = cm_object_get_child_by_name(state->f0.reg.otyper, "OT0");
	state->f0.fld.otyper.ot1 = cm_object_get_child_by_name(state->f0.reg.otyper, "OT1");
	state->f0.fld.otyper.ot2 = cm_object_get_child_by_name(state->f0.reg.otyper, "OT2");
	state->f0.fld.otyper.ot3 = cm_object_get_child_by_name(state->f0.reg.otyper, "OT3");
	state->f0.fld.otyper.ot4 = cm_object_get_child_by_name(state->f0.reg.otyper, "OT4");
	state->f0.fld.otyper.ot5 = cm_object_get_child_by_name(state->f0.reg.otyper, "OT5");
	state->f0.fld.otyper.ot6 = cm_object_get_child_by_name(state->f0.reg.otyper, "OT6");
	state->f0.fld.otyper.ot7 = cm_object_get_child_by_name(state->f0.reg.otyper, "OT7");
	state->f0.fld.otyper.ot8 = cm_object_get_child_by_name(state->f0.reg.otyper, "OT8");
	state->f0.fld.otyper.ot9 = cm_object_get_child_by_name(state->f0.reg.otyper, "OT9");
	state->f0.fld.otyper.ot10 = cm_object_get_child_by_name(state->f0.reg.otyper, "OT10");
	state->f0.fld.otyper.ot11 = cm_object_get_child_by_name(state->f0.reg.otyper, "OT11");
	state->f0.fld.otyper.ot12 = cm_object_get_child_by_name(state->f0.reg.otyper, "OT12");
	state->f0.fld.otyper.ot13 = cm_object_get_child_by_name(state->f0.reg.otyper, "OT13");
	state->f0.fld.otyper.ot14 = cm_object_get_child_by_name(state->f0.reg.otyper, "OT14");
	state->f0.fld.otyper.ot15 = cm_object_get_child_by_name(state->f0.reg.otyper, "OT15");

	// OSPEEDR bitfields.
	state->f0.fld.ospeedr.ospeedr0 = cm_object_get_child_by_name(state->f0.reg.ospeedr, "OSPEEDR0");
	state->f0.fld.ospeedr.ospeedr1 = cm_object_get_child_by_name(state->f0.reg.ospeedr, "OSPEEDR1");
	state->f0.fld.ospeedr.ospeedr2 = cm_object_get_child_by_name(state->f0.reg.ospeedr, "OSPEEDR2");
	state->f0.fld.ospeedr.ospeedr3 = cm_object_get_child_by_name(state->f0.reg.ospeedr, "OSPEEDR3");
	state->f0.fld.ospeedr.ospeedr4 = cm_object_get_child_by_name(state->f0.reg.ospeedr, "OSPEEDR4");
	state->f0.fld.ospeedr.ospeedr5 = cm_object_get_child_by_name(state->f0.reg.ospeedr, "OSPEEDR5");
	state->f0.fld.ospeedr.ospeedr6 = cm_object_get_child_by_name(state->f0.reg.ospeedr, "OSPEEDR6");
	state->f0.fld.ospeedr.ospeedr7 = cm_object_get_child_by_name(state->f0.reg.ospeedr, "OSPEEDR7");
	state->f0.fld.ospeedr.ospeedr8 = cm_object_get_child_by_name(state->f0.reg.ospeedr, "OSPEEDR8");
	state->f0.fld.ospeedr.ospeedr9 = cm_object_get_child_by_name(state->f0.reg.ospeedr, "OSPEEDR9");
	state->f0.fld.ospeedr.ospeedr10 = cm_object_get_child_by_name(state->f0.reg.ospeedr, "OSPEEDR10");
	state->f0.fld.ospeedr.ospeedr11 = cm_object_get_child_by_name(state->f0.reg.ospeedr, "OSPEEDR11");
	state->f0.fld.ospeedr.ospeedr12 = cm_object_get_child_by_name(state->f0.reg.ospeedr, "OSPEEDR12");
	state->f0.fld.ospeedr.ospeedr13 = cm_object_get_child_by_name(state->f0.reg.ospeedr, "OSPEEDR13");
	state->f0.fld.ospeedr.ospeedr14 = cm_object_get_child_by_name(state->f0.reg.ospeedr, "OSPEEDR14");
	state->f0.fld.ospeedr.ospeedr15 = cm_object_get_child_by_name(state->f0.reg.ospeedr, "OSPEEDR15");

	// PUPDR bitfields.
	state->f0.fld.pupdr.pupdr0 = cm_object_get_child_by_name(state->f0.reg.pupdr, "PUPDR0");
	state->f0.fld.pupdr.pupdr1 = cm_object_get_child_by_name(state->f0.reg.pupdr, "PUPDR1");
	state->f0.fld.pupdr.pupdr2 = cm_object_get_child_by_name(state->f0.reg.pupdr, "PUPDR2");
	state->f0.fld.pupdr.pupdr3 = cm_object_get_child_by_name(state->f0.reg.pupdr, "PUPDR3");
	state->f0.fld.pupdr.pupdr4 = cm_object_get_child_by_name(state->f0.reg.pupdr, "PUPDR4");
	state->f0.fld.pupdr.pupdr5 = cm_object_get_child_by_name(state->f0.reg.pupdr, "PUPDR5");
	state->f0.fld.pupdr.pupdr6 = cm_object_get_child_by_name(state->f0.reg.pupdr, "PUPDR6");
	state->f0.fld.pupdr.pupdr7 = cm_object_get_child_by_name(state->f0.reg.pupdr, "PUPDR7");
	state->f0.fld.pupdr.pupdr8 = cm_object_get_child_by_name(state->f0.reg.pupdr, "PUPDR8");
	state->f0.fld.pupdr.pupdr9 = cm_object_get_child_by_name(state->f0.reg.pupdr, "PUPDR9");
	state->f0.fld.pupdr.pupdr10 = cm_object_get_child_by_name(state->f0.reg.pupdr, "PUPDR10");
	state->f0.fld.pupdr.pupdr11 = cm_object_get_child_by_name(state->f0.reg.pupdr, "PUPDR11");
	state->f0.fld.pupdr.pupdr12 = cm_object_get_child_by_name(state->f0.reg.pupdr, "PUPDR12");
	state->f0.fld.pupdr.pupdr13 = cm_object_get_child_by_name(state->f0.reg.pupdr, "PUPDR13");
	state->f0.fld.pupdr.pupdr14 = cm_object_get_child_by_name(state->f0.reg.pupdr, "PUPDR14");
	state->f0.fld.pupdr.pupdr15 = cm_object_get_child_by_name(state->f0.reg.pupdr, "PUPDR15");

	// IDR bitfields.
	state->f0.fld.idr.idr0 = cm_object_get_child_by_name(state->f0.reg.idr, "IDR0");
	state->f0.fld.idr.idr1 = cm_object_get_child_by_name(state->f0.reg.idr, "IDR1");
	state->f0.fld.idr.idr2 = cm_object_get_child_by_name(state->f0.reg.idr, "IDR2");
	state->f0.fld.idr.idr3 = cm_object_get_child_by_name(state->f0.reg.idr, "IDR3");
	state->f0.fld.idr.idr4 = cm_object_get_child_by_name(state->f0.reg.idr, "IDR4");
	state->f0.fld.idr.idr5 = cm_object_get_child_by_name(state->f0.reg.idr, "IDR5");
	state->f0.fld.idr.idr6 = cm_object_get_child_by_name(state->f0.reg.idr, "IDR6");
	state->f0.fld.idr.idr7 = cm_object_get_child_by_name(state->f0.reg.idr, "IDR7");
	state->f0.fld.idr.idr8 = cm_object_get_child_by_name(state->f0.reg.idr, "IDR8");
	state->f0.fld.idr.idr9 = cm_object_get_child_by_name(state->f0.reg.idr, "IDR9");
	state->f0.fld.idr.idr10 = cm_object_get_child_by_name(state->f0.reg.idr, "IDR10");
	state->f0.fld.idr.idr11 = cm_object_get_child_by_name(state->f0.reg.idr, "IDR11");
	state->f0.fld.idr.idr12 = cm_object_get_child_by_name(state->f0.reg.idr, "IDR12");
	state->f0.fld.idr.idr13 = cm_object_get_child_by_name(state->f0.reg.idr, "IDR13");
	state->f0.fld.idr.idr14 = cm_object_get_child_by_name(state->f0.reg.idr, "IDR14");
	state->f0.fld.idr.idr15 = cm_object_get_child_by_name(state->f0.reg.idr, "IDR15");

	// ODR bitfields.
	state->f0.fld.odr.odr0 = cm_object_get_child_by_name(state->f0.reg.odr, "ODR0");
	state->f0.fld.odr.odr1 = cm_object_get_child_by_name(state->f0.reg.odr, "ODR1");
	state->f0.fld.odr.odr2 = cm_object_get_child_by_name(state->f0.reg.odr, "ODR2");
	state->f0.fld.odr.odr3 = cm_object_get_child_by_name(state->f0.reg.odr, "ODR3");
	state->f0.fld.odr.odr4 = cm_object_get_child_by_name(state->f0.reg.odr, "ODR4");
	state->f0.fld.odr.odr5 = cm_object_get_child_by_name(state->f0.reg.odr, "ODR5");
	state->f0.fld.odr.odr6 = cm_object_get_child_by_name(state->f0.reg.odr, "ODR6");
	state->f0.fld.odr.odr7 = cm_object_get_child_by_name(state->f0.reg.odr, "ODR7");
	state->f0.fld.odr.odr8 = cm_object_get_child_by_name(state->f0.reg.odr, "ODR8");
	state->f0.fld.odr.odr9 = cm_object_get_child_by_name(state->f0.reg.odr, "ODR9");
	state->f0.fld.odr.odr10 = cm_object_get_child_by_name(state->f0.reg.odr, "ODR10");
	state->f0.fld.odr.odr11 = cm_object_get_child_by_name(state->f0.reg.odr, "ODR11");
	state->f0.fld.odr.odr12 = cm_object_get_child_by_name(state->f0.reg.odr, "ODR12");
	state->f0.fld.odr.odr13 = cm_object_get_child_by_name(state->f0.reg.odr, "ODR13");
	state->f0.fld.odr.odr14 = cm_object_get_child_by_name(state->f0.reg.odr, "ODR14");
	state->f0.fld.odr.odr15 = cm_object_get_child_by_name(state->f0.reg.odr, "ODR15");

	// BSRR bitfields.
	state->f0.fld.bsrr.bs0 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BS0");
	state->f0.fld.bsrr.bs1 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BS1");
	state->f0.fld.bsrr.bs2 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BS2");
	state->f0.fld.bsrr.bs3 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BS3");
	state->f0.fld.bsrr.bs4 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BS4");
	state->f0.fld.bsrr.bs5 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BS5");
	state->f0.fld.bsrr.bs6 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BS6");
	state->f0.fld.bsrr.bs7 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BS7");
	state->f0.fld.bsrr.bs8 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BS8");
	state->f0.fld.bsrr.bs9 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BS9");
	state->f0.fld.bsrr.bs10 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BS10");
	state->f0.fld.bsrr.bs11 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BS11");
	state->f0.fld.bsrr.bs12 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BS12");
	state->f0.fld.bsrr.bs13 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BS13");
	state->f0.fld.bsrr.bs14 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BS14");
	state->f0.fld.bsrr.bs15 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BS15");
	state->f0.fld.bsrr.br0 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BR0");
	state->f0.fld.bsrr.br1 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BR1");
	state->f0.fld.bsrr.br2 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BR2");
	state->f0.fld.bsrr.br3 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BR3");
	state->f0.fld.bsrr.br4 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BR4");
	state->f0.fld.bsrr.br5 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BR5");
	state->f0.fld.bsrr.br6 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BR6");
	state->f0.fld.bsrr.br7 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BR7");
	state->f0.fld.bsrr.br8 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BR8");
	state->f0.fld.bsrr.br9 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BR9");
	state->f0.fld.bsrr.br10 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BR10");
	state->f0.fld.bsrr.br11 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BR11");
	state->f0.fld.bsrr.br12 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BR12");
	state->f0.fld.bsrr.br13 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BR13");
	state->f0.fld.bsrr.br14 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BR14");
	state->f0.fld.bsrr.br15 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BR15");

	// LCKR bitfields.
	state->f0.fld.lckr.lck0 = cm_object_get_child_by_name(state->f0.reg.lckr, "LCK0");
	state->f0.fld.lckr.lck1 = cm_object_get_child_by_name(state->f0.reg.lckr, "LCK1");
	state->f0.fld.lckr.lck2 = cm_object_get_child_by_name(state->f0.reg.lckr, "LCK2");
	state->f0.fld.lckr.lck3 = cm_object_get_child_by_name(state->f0.reg.lckr, "LCK3");
	state->f0.fld.lckr.lck4 = cm_object_get_child_by_name(state->f0.reg.lckr, "LCK4");
	state->f0.fld.lckr.lck5 = cm_object_get_child_by_name(state->f0.reg.lckr, "LCK5");
	state->f0.fld.lckr.lck6 = cm_object_get_child_by_name(state->f0.reg.lckr, "LCK6");
	state->f0.fld.lckr.lck7 = cm_object_get_child_by_name(state->f0.reg.lckr, "LCK7");
	state->f0.fld.lckr.lck8 = cm_object_get_child_by_name(state->f0.reg.lckr, "LCK8");
	state->f0.fld.lckr.lck9 = cm_object_get_child_by_name(state->f0.reg.lckr, "LCK9");
	state->f0.fld.lckr.lck10 = cm_object_get_child_by_name(state->f0.reg.lckr, "LCK10");
	state->f0.fld.lckr.lck11 = cm_object_get_child_by_name(state->f0.reg.lckr, "LCK11");
	state->f0.fld.lckr.lck12 = cm_object_get_child_by_name(state->f0.reg.lckr, "LCK12");
	state->f0.fld.lckr.lck13 = cm_object_get_child_by_name(state->f0.reg.lckr, "LCK13");
	state->f0.fld.lckr.lck14 = cm_object_get_child_by_name(state->f0.reg.lckr, "LCK14");
	state->f0.fld.lckr.lck15 = cm_object_get_child_by_name(state->f0.reg.lckr, "LCK15");
	state->f0.fld.lckr.lckk = cm_object_get_child_by_name(state->f0.reg.lckr, "LCKK");

	// AFRL bitfields.
	state->f0.fld.afrl.afrl0 = cm_object_get_child_by_name(state->f0.reg.afrl, "AFRL0");
	state->f0.fld.afrl.afrl1 = cm_object_get_child_by_name(state->f0.reg.afrl, "AFRL1");
	state->f0.fld.afrl.afrl2 = cm_object_get_child_by_name(state->f0.reg.afrl, "AFRL2");
	state->f0.fld.afrl.afrl3 = cm_object_get_child_by_name(state->f0.reg.afrl, "AFRL3");
	state->f0.fld.afrl.afrl4 = cm_object_get_child_by_name(state->f0.reg.afrl, "AFRL4");
	state->f0.fld.afrl.afrl5 = cm_object_get_child_by_name(state->f0.reg.afrl, "AFRL5");
	state->f0.fld.afrl.afrl6 = cm_object_get_child_by_name(state->f0.reg.afrl, "AFRL6");
	state->f0.fld.afrl.afrl7 = cm_object_get_child_by_name(state->f0.reg.afrl, "AFRL7");

	// AFRH bitfields.
	state->f0.fld.afrh.afrh8 = cm_object_get_child_by_name(state->f0.reg.afrh, "AFRH8");
	state->f0.fld.afrh.afrh9 = cm_object_get_child_by_name(state->f0.reg.afrh, "AFRH9");
	state->f0.fld.afrh.afrh10 = cm_object_get_child_by_name(state->f0.reg.afrh, "AFRH10");
	state->f0.fld.afrh.afrh11 = cm_object_get_child_by_name(state->f0.reg.afrh, "AFRH11");
	state->f0.fld.afrh.afrh12 = cm_object_get_child_by_name(state->f0.reg.afrh, "AFRH12");
	state->f0.fld.afrh.afrh13 = cm_object_get_child_by_name(state->f0.reg.afrh, "AFRH13");
	state->f0.fld.afrh.afrh14 = cm_object_get_child_by_name(state->f0.reg.afrh, "AFRH14");
	state->f0.fld.afrh.afrh15 = cm_object_get_child_by_name(state->f0.reg.afrh, "AFRH15");

	// BRR bitfields.
	state->f0.fld.brr.br0 = cm_object_get_child_by_name(state->f0.reg.brr, "BR0");
	state->f0.fld.brr.br1 = cm_object_get_child_by_name(state->f0.reg.brr, "BR1");
	state->f0.fld.brr.br2 = cm_object_get_child_by_name(state->f0.reg.brr, "BR2");
	state->f0.fld.brr.br3 = cm_object_get_child_by_name(state->f0.reg.brr, "BR3");
	state->f0.fld.brr.br4 = cm_object_get_child_by_name(state->f0.reg.brr, "BR4");
	state->f0.fld.brr.br5 = cm_object_get_child_by_name(state->f0.reg.brr, "BR5");
	state->f0.fld.brr.br6 = cm_object_get_child_by_name(state->f0.reg.brr, "BR6");
	state->f0.fld.brr.br7 = cm_object_get_child_by_name(state->f0.reg.brr, "BR7");
	state->f0.fld.brr.br8 = cm_object_get_child_by_name(state->f0.reg.brr, "BR8");
	state->f0.fld.brr.br9 = cm_object_get_child_by_name(state->f0.reg.brr, "BR9");
	state->f0.fld.brr.br10 = cm_object_get_child_by_name(state->f0.reg.brr, "BR10");
	state->f0.fld.brr.br11 = cm_object_get_child_by_name(state->f0.reg.brr, "BR11");
	state->f0.fld.brr.br12 = cm_object_get_child_by_name(state->f0.reg.brr, "BR12");
	state->f0.fld.brr.br13 = cm_object_get_child_by_name(state->f0.reg.brr, "BR13");
	state->f0.fld.brr.br14 = cm_object_get_child_by_name(state->f0.reg.brr, "BR14");
	state->f0.fld.brr.br15 = cm_object_get_child_by_name(state->f0.reg.brr, "BR15");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// GPIOA (General-purpose I/Os) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F0 GPIOA (General-purpose I/Os) registers.
		struct {
			Object *moder; // 0x0 GPIO port mode register
			Object *otyper; // 0x4 GPIO port output type register
			Object *ospeedr; // 0x8 GPIO port output speed register
			Object *pupdr; // 0xC GPIO port pull-up/pull-down register
			Object *idr; // 0x10 GPIO port input data register
			Object *odr; // 0x14 GPIO port output data register
			Object *bsrr; // 0x18 GPIO port bit set/reset register
			Object *lckr; // 0x1C GPIO port configuration lock register
			Object *afrl; // 0x20 GPIO alternate function low register
			Object *afrh; // 0x24 GPIO alternate function high register
			Object *brr; // 0x28 Port bit reset register
		} reg;

		struct {

			// MODER (GPIO port mode register) bitfields.
			struct {
				Object *moder0; // [0:1] Port x configuration bits (y = 0..15)
				Object *moder1; // [2:3] Port x configuration bits (y = 0..15)
				Object *moder2; // [4:5] Port x configuration bits (y = 0..15)
				Object *moder3; // [6:7] Port x configuration bits (y = 0..15)
				Object *moder4; // [8:9] Port x configuration bits (y = 0..15)
				Object *moder5; // [10:11] Port x configuration bits (y = 0..15)
				Object *moder6; // [12:13] Port x configuration bits (y = 0..15)
				Object *moder7; // [14:15] Port x configuration bits (y = 0..15)
				Object *moder8; // [16:17] Port x configuration bits (y = 0..15)
				Object *moder9; // [18:19] Port x configuration bits (y = 0..15)
				Object *moder10; // [20:21] Port x configuration bits (y = 0..15)
				Object *moder11; // [22:23] Port x configuration bits (y = 0..15)
				Object *moder12; // [24:25] Port x configuration bits (y = 0..15)
				Object *moder13; // [26:27] Port x configuration bits (y = 0..15)
				Object *moder14; // [28:29] Port x configuration bits (y = 0..15)
				Object *moder15; // [30:31] Port x configuration bits (y = 0..15)
			} moder;

			// OTYPER (GPIO port output type register) bitfields.
			struct {
				Object *ot0; // [0:0] Port x configuration bits (y = 0..15)
				Object *ot1; // [1:1] Port x configuration bits (y = 0..15)
				Object *ot2; // [2:2] Port x configuration bits (y = 0..15)
				Object *ot3; // [3:3] Port x configuration bits (y = 0..15)
				Object *ot4; // [4:4] Port x configuration bits (y = 0..15)
				Object *ot5; // [5:5] Port x configuration bits (y = 0..15)
				Object *ot6; // [6:6] Port x configuration bits (y = 0..15)
				Object *ot7; // [7:7] Port x configuration bits (y = 0..15)
				Object *ot8; // [8:8] Port x configuration bits (y = 0..15)
				Object *ot9; // [9:9] Port x configuration bits (y = 0..15)
				Object *ot10; // [10:10] Port x configuration bits (y = 0..15)
				Object *ot11; // [11:11] Port x configuration bits (y = 0..15)
				Object *ot12; // [12:12] Port x configuration bits (y = 0..15)
				Object *ot13; // [13:13] Port x configuration bits (y = 0..15)
				Object *ot14; // [14:14] Port x configuration bits (y = 0..15)
				Object *ot15; // [15:15] Port x configuration bits (y = 0..15)
			} otyper;

			// OSPEEDR (GPIO port output speed register) bitfields.
			struct {
				Object *ospeedr0; // [0:1] Port x configuration bits (y = 0..15)
				Object *ospeedr1; // [2:3] Port x configuration bits (y = 0..15)
				Object *ospeedr2; // [4:5] Port x configuration bits (y = 0..15)
				Object *ospeedr3; // [6:7] Port x configuration bits (y = 0..15)
				Object *ospeedr4; // [8:9] Port x configuration bits (y = 0..15)
				Object *ospeedr5; // [10:11] Port x configuration bits (y = 0..15)
				Object *ospeedr6; // [12:13] Port x configuration bits (y = 0..15)
				Object *ospeedr7; // [14:15] Port x configuration bits (y = 0..15)
				Object *ospeedr8; // [16:17] Port x configuration bits (y = 0..15)
				Object *ospeedr9; // [18:19] Port x configuration bits (y = 0..15)
				Object *ospeedr10; // [20:21] Port x configuration bits (y = 0..15)
				Object *ospeedr11; // [22:23] Port x configuration bits (y = 0..15)
				Object *ospeedr12; // [24:25] Port x configuration bits (y = 0..15)
				Object *ospeedr13; // [26:27] Port x configuration bits (y = 0..15)
				Object *ospeedr14; // [28:29] Port x configuration bits (y = 0..15)
				Object *ospeedr15; // [30:31] Port x configuration bits (y = 0..15)
			} ospeedr;

			// PUPDR (GPIO port pull-up/pull-down register) bitfields.
			struct {
				Object *pupdr0; // [0:1] Port x configuration bits (y = 0..15)
				Object *pupdr1; // [2:3] Port x configuration bits (y = 0..15)
				Object *pupdr2; // [4:5] Port x configuration bits (y = 0..15)
				Object *pupdr3; // [6:7] Port x configuration bits (y = 0..15)
				Object *pupdr4; // [8:9] Port x configuration bits (y = 0..15)
				Object *pupdr5; // [10:11] Port x configuration bits (y = 0..15)
				Object *pupdr6; // [12:13] Port x configuration bits (y = 0..15)
				Object *pupdr7; // [14:15] Port x configuration bits (y = 0..15)
				Object *pupdr8; // [16:17] Port x configuration bits (y = 0..15)
				Object *pupdr9; // [18:19] Port x configuration bits (y = 0..15)
				Object *pupdr10; // [20:21] Port x configuration bits (y = 0..15)
				Object *pupdr11; // [22:23] Port x configuration bits (y = 0..15)
				Object *pupdr12; // [24:25] Port x configuration bits (y = 0..15)
				Object *pupdr13; // [26:27] Port x configuration bits (y = 0..15)
				Object *pupdr14; // [28:29] Port x configuration bits (y = 0..15)
				Object *pupdr15; // [30:31] Port x configuration bits (y = 0..15)
			} pupdr;

			// IDR (GPIO port input data register) bitfields.
			struct {
				Object *idr0; // [0:0] Port input data (y = 0..15)
				Object *idr1; // [1:1] Port input data (y = 0..15)
				Object *idr2; // [2:2] Port input data (y = 0..15)
				Object *idr3; // [3:3] Port input data (y = 0..15)
				Object *idr4; // [4:4] Port input data (y = 0..15)
				Object *idr5; // [5:5] Port input data (y = 0..15)
				Object *idr6; // [6:6] Port input data (y = 0..15)
				Object *idr7; // [7:7] Port input data (y = 0..15)
				Object *idr8; // [8:8] Port input data (y = 0..15)
				Object *idr9; // [9:9] Port input data (y = 0..15)
				Object *idr10; // [10:10] Port input data (y = 0..15)
				Object *idr11; // [11:11] Port input data (y = 0..15)
				Object *idr12; // [12:12] Port input data (y = 0..15)
				Object *idr13; // [13:13] Port input data (y = 0..15)
				Object *idr14; // [14:14] Port input data (y = 0..15)
				Object *idr15; // [15:15] Port input data (y = 0..15)
			} idr;

			// ODR (GPIO port output data register) bitfields.
			struct {
				Object *odr0; // [0:0] Port output data (y = 0..15)
				Object *odr1; // [1:1] Port output data (y = 0..15)
				Object *odr2; // [2:2] Port output data (y = 0..15)
				Object *odr3; // [3:3] Port output data (y = 0..15)
				Object *odr4; // [4:4] Port output data (y = 0..15)
				Object *odr5; // [5:5] Port output data (y = 0..15)
				Object *odr6; // [6:6] Port output data (y = 0..15)
				Object *odr7; // [7:7] Port output data (y = 0..15)
				Object *odr8; // [8:8] Port output data (y = 0..15)
				Object *odr9; // [9:9] Port output data (y = 0..15)
				Object *odr10; // [10:10] Port output data (y = 0..15)
				Object *odr11; // [11:11] Port output data (y = 0..15)
				Object *odr12; // [12:12] Port output data (y = 0..15)
				Object *odr13; // [13:13] Port output data (y = 0..15)
				Object *odr14; // [14:14] Port output data (y = 0..15)
				Object *odr15; // [15:15] Port output data (y = 0..15)
			} odr;

			// BSRR (GPIO port bit set/reset register) bitfields.
			struct {
				Object *bs0; // [0:0] Port x set bit y (y= 0..15)
				Object *bs1; // [1:1] Port x set bit y (y= 0..15)
				Object *bs2; // [2:2] Port x set bit y (y= 0..15)
				Object *bs3; // [3:3] Port x set bit y (y= 0..15)
				Object *bs4; // [4:4] Port x set bit y (y= 0..15)
				Object *bs5; // [5:5] Port x set bit y (y= 0..15)
				Object *bs6; // [6:6] Port x set bit y (y= 0..15)
				Object *bs7; // [7:7] Port x set bit y (y= 0..15)
				Object *bs8; // [8:8] Port x set bit y (y= 0..15)
				Object *bs9; // [9:9] Port x set bit y (y= 0..15)
				Object *bs10; // [10:10] Port x set bit y (y= 0..15)
				Object *bs11; // [11:11] Port x set bit y (y= 0..15)
				Object *bs12; // [12:12] Port x set bit y (y= 0..15)
				Object *bs13; // [13:13] Port x set bit y (y= 0..15)
				Object *bs14; // [14:14] Port x set bit y (y= 0..15)
				Object *bs15; // [15:15] Port x set bit y (y= 0..15)
				Object *br0; // [16:16] Port x set bit y (y= 0..15)
				Object *br1; // [17:17] Port x reset bit y (y = 0..15)
				Object *br2; // [18:18] Port x reset bit y (y = 0..15)
				Object *br3; // [19:19] Port x reset bit y (y = 0..15)
				Object *br4; // [20:20] Port x reset bit y (y = 0..15)
				Object *br5; // [21:21] Port x reset bit y (y = 0..15)
				Object *br6; // [22:22] Port x reset bit y (y = 0..15)
				Object *br7; // [23:23] Port x reset bit y (y = 0..15)
				Object *br8; // [24:24] Port x reset bit y (y = 0..15)
				Object *br9; // [25:25] Port x reset bit y (y = 0..15)
				Object *br10; // [26:26] Port x reset bit y (y = 0..15)
				Object *br11; // [27:27] Port x reset bit y (y = 0..15)
				Object *br12; // [28:28] Port x reset bit y (y = 0..15)
				Object *br13; // [29:29] Port x reset bit y (y = 0..15)
				Object *br14; // [30:30] Port x reset bit y (y = 0..15)
				Object *br15; // [31:31] Port x reset bit y (y = 0..15)
			} bsrr;

			// LCKR (GPIO port configuration lock register) bitfields.
			struct {
				Object *lck0; // [0:0] Port x lock bit y (y= 0..15)
				Object *lck1; // [1:1] Port x lock bit y (y= 0..15)
				Object *lck2; // [2:2] Port x lock bit y (y= 0..15)
				Object *lck3; // [3:3] Port x lock bit y (y= 0..15)
				Object *lck4; // [4:4] Port x lock bit y (y= 0..15)
				Object *lck5; // [5:5] Port x lock bit y (y= 0..15)
				Object *lck6; // [6:6] Port x lock bit y (y= 0..15)
				Object *lck7; // [7:7] Port x lock bit y (y= 0..15)
				Object *lck8; // [8:8] Port x lock bit y (y= 0..15)
				Object *lck9; // [9:9] Port x lock bit y (y= 0..15)
				Object *lck10; // [10:10] Port x lock bit y (y= 0..15)
				Object *lck11; // [11:11] Port x lock bit y (y= 0..15)
				Object *lck12; // [12:12] Port x lock bit y (y= 0..15)
				Object *lck13; // [13:13] Port x lock bit y (y= 0..15)
				Object *lck14; // [14:14] Port x lock bit y (y= 0..15)
				Object *lck15; // [15:15] Port x lock bit y (y= 0..15)
				Object *lckk; // [16:16] Port x lock bit y (y= 0..15)
			} lckr;

			// AFRL (GPIO alternate function low register) bitfields.
			struct {
				Object *afrl0; // [0:3] Alternate function selection for port x bit y (y = 0..7)
				Object *afrl1; // [4:7] Alternate function selection for port x bit y (y = 0..7)
				Object *afrl2; // [8:11] Alternate function selection for port x bit y (y = 0..7)
				Object *afrl3; // [12:15] Alternate function selection for port x bit y (y = 0..7)
				Object *afrl4; // [16:19] Alternate function selection for port x bit y (y = 0..7)
				Object *afrl5; // [20:23] Alternate function selection for port x bit y (y = 0..7)
				Object *afrl6; // [24:27] Alternate function selection for port x bit y (y = 0..7)
				Object *afrl7; // [28:31] Alternate function selection for port x bit y (y = 0..7)
			} afrl;

			// AFRH (GPIO alternate function high register) bitfields.
			struct {
				Object *afrh8; // [0:3] Alternate function selection for port x bit y (y = 8..15)
				Object *afrh9; // [4:7] Alternate function selection for port x bit y (y = 8..15)
				Object *afrh10; // [8:11] Alternate function selection for port x bit y (y = 8..15)
				Object *afrh11; // [12:15] Alternate function selection for port x bit y (y = 8..15)
				Object *afrh12; // [16:19] Alternate function selection for port x bit y (y = 8..15)
				Object *afrh13; // [20:23] Alternate function selection for port x bit y (y = 8..15)
				Object *afrh14; // [24:27] Alternate function selection for port x bit y (y = 8..15)
				Object *afrh15; // [28:31] Alternate function selection for port x bit y (y = 8..15)
			} afrh;

			// BRR (Port bit reset register) bitfields.
			struct {
				Object *br0; // [0:0] Port x Reset bit y
				Object *br1; // [1:1] Port x Reset bit y
				Object *br2; // [2:2] Port x Reset bit y
				Object *br3; // [3:3] Port x Reset bit y
				Object *br4; // [4:4] Port x Reset bit y
				Object *br5; // [5:5] Port x Reset bit y
				Object *br6; // [6:6] Port x Reset bit y
				Object *br7; // [7:7] Port x Reset bit y
				Object *br8; // [8:8] Port x Reset bit y
				Object *br9; // [9:9] Port x Reset bit y
				Object *br10; // [10:10] Port x Reset bit y
				Object *br11; // [11:11] Port x Reset bit y
				Object *br12; // [12:12] Port x Reset bit y
				Object *br13; // [13:13] Port x Reset bit y
				Object *br14; // [14:14] Port x Reset bit y
				Object *br15; // [15:15] Port x Reset bit y
			} brr;
		} fld;
	} f0;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32GPIOAState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_gpioa_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32GPIOAState *state = STM32_GPIOA_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f0.reg.moder = cm_object_get_child_by_name(obj, "MODER");
	state->f0.reg.otyper = cm_object_get_child_by_name(obj, "OTYPER");
	state->f0.reg.ospeedr = cm_object_get_child_by_name(obj, "OSPEEDR");
	state->f0.reg.pupdr = cm_object_get_child_by_name(obj, "PUPDR");
	state->f0.reg.idr = cm_object_get_child_by_name(obj, "IDR");
	state->f0.reg.odr = cm_object_get_child_by_name(obj, "ODR");
	state->f0.reg.bsrr = cm_object_get_child_by_name(obj, "BSRR");
	state->f0.reg.lckr = cm_object_get_child_by_name(obj, "LCKR");
	state->f0.reg.afrl = cm_object_get_child_by_name(obj, "AFRL");
	state->f0.reg.afrh = cm_object_get_child_by_name(obj, "AFRH");
	state->f0.reg.brr = cm_object_get_child_by_name(obj, "BRR");

	// MODER bitfields.
	state->f0.fld.moder.moder0 = cm_object_get_child_by_name(state->f0.reg.moder, "MODER0");
	state->f0.fld.moder.moder1 = cm_object_get_child_by_name(state->f0.reg.moder, "MODER1");
	state->f0.fld.moder.moder2 = cm_object_get_child_by_name(state->f0.reg.moder, "MODER2");
	state->f0.fld.moder.moder3 = cm_object_get_child_by_name(state->f0.reg.moder, "MODER3");
	state->f0.fld.moder.moder4 = cm_object_get_child_by_name(state->f0.reg.moder, "MODER4");
	state->f0.fld.moder.moder5 = cm_object_get_child_by_name(state->f0.reg.moder, "MODER5");
	state->f0.fld.moder.moder6 = cm_object_get_child_by_name(state->f0.reg.moder, "MODER6");
	state->f0.fld.moder.moder7 = cm_object_get_child_by_name(state->f0.reg.moder, "MODER7");
	state->f0.fld.moder.moder8 = cm_object_get_child_by_name(state->f0.reg.moder, "MODER8");
	state->f0.fld.moder.moder9 = cm_object_get_child_by_name(state->f0.reg.moder, "MODER9");
	state->f0.fld.moder.moder10 = cm_object_get_child_by_name(state->f0.reg.moder, "MODER10");
	state->f0.fld.moder.moder11 = cm_object_get_child_by_name(state->f0.reg.moder, "MODER11");
	state->f0.fld.moder.moder12 = cm_object_get_child_by_name(state->f0.reg.moder, "MODER12");
	state->f0.fld.moder.moder13 = cm_object_get_child_by_name(state->f0.reg.moder, "MODER13");
	state->f0.fld.moder.moder14 = cm_object_get_child_by_name(state->f0.reg.moder, "MODER14");
	state->f0.fld.moder.moder15 = cm_object_get_child_by_name(state->f0.reg.moder, "MODER15");

	// OTYPER bitfields.
	state->f0.fld.otyper.ot0 = cm_object_get_child_by_name(state->f0.reg.otyper, "OT0");
	state->f0.fld.otyper.ot1 = cm_object_get_child_by_name(state->f0.reg.otyper, "OT1");
	state->f0.fld.otyper.ot2 = cm_object_get_child_by_name(state->f0.reg.otyper, "OT2");
	state->f0.fld.otyper.ot3 = cm_object_get_child_by_name(state->f0.reg.otyper, "OT3");
	state->f0.fld.otyper.ot4 = cm_object_get_child_by_name(state->f0.reg.otyper, "OT4");
	state->f0.fld.otyper.ot5 = cm_object_get_child_by_name(state->f0.reg.otyper, "OT5");
	state->f0.fld.otyper.ot6 = cm_object_get_child_by_name(state->f0.reg.otyper, "OT6");
	state->f0.fld.otyper.ot7 = cm_object_get_child_by_name(state->f0.reg.otyper, "OT7");
	state->f0.fld.otyper.ot8 = cm_object_get_child_by_name(state->f0.reg.otyper, "OT8");
	state->f0.fld.otyper.ot9 = cm_object_get_child_by_name(state->f0.reg.otyper, "OT9");
	state->f0.fld.otyper.ot10 = cm_object_get_child_by_name(state->f0.reg.otyper, "OT10");
	state->f0.fld.otyper.ot11 = cm_object_get_child_by_name(state->f0.reg.otyper, "OT11");
	state->f0.fld.otyper.ot12 = cm_object_get_child_by_name(state->f0.reg.otyper, "OT12");
	state->f0.fld.otyper.ot13 = cm_object_get_child_by_name(state->f0.reg.otyper, "OT13");
	state->f0.fld.otyper.ot14 = cm_object_get_child_by_name(state->f0.reg.otyper, "OT14");
	state->f0.fld.otyper.ot15 = cm_object_get_child_by_name(state->f0.reg.otyper, "OT15");

	// OSPEEDR bitfields.
	state->f0.fld.ospeedr.ospeedr0 = cm_object_get_child_by_name(state->f0.reg.ospeedr, "OSPEEDR0");
	state->f0.fld.ospeedr.ospeedr1 = cm_object_get_child_by_name(state->f0.reg.ospeedr, "OSPEEDR1");
	state->f0.fld.ospeedr.ospeedr2 = cm_object_get_child_by_name(state->f0.reg.ospeedr, "OSPEEDR2");
	state->f0.fld.ospeedr.ospeedr3 = cm_object_get_child_by_name(state->f0.reg.ospeedr, "OSPEEDR3");
	state->f0.fld.ospeedr.ospeedr4 = cm_object_get_child_by_name(state->f0.reg.ospeedr, "OSPEEDR4");
	state->f0.fld.ospeedr.ospeedr5 = cm_object_get_child_by_name(state->f0.reg.ospeedr, "OSPEEDR5");
	state->f0.fld.ospeedr.ospeedr6 = cm_object_get_child_by_name(state->f0.reg.ospeedr, "OSPEEDR6");
	state->f0.fld.ospeedr.ospeedr7 = cm_object_get_child_by_name(state->f0.reg.ospeedr, "OSPEEDR7");
	state->f0.fld.ospeedr.ospeedr8 = cm_object_get_child_by_name(state->f0.reg.ospeedr, "OSPEEDR8");
	state->f0.fld.ospeedr.ospeedr9 = cm_object_get_child_by_name(state->f0.reg.ospeedr, "OSPEEDR9");
	state->f0.fld.ospeedr.ospeedr10 = cm_object_get_child_by_name(state->f0.reg.ospeedr, "OSPEEDR10");
	state->f0.fld.ospeedr.ospeedr11 = cm_object_get_child_by_name(state->f0.reg.ospeedr, "OSPEEDR11");
	state->f0.fld.ospeedr.ospeedr12 = cm_object_get_child_by_name(state->f0.reg.ospeedr, "OSPEEDR12");
	state->f0.fld.ospeedr.ospeedr13 = cm_object_get_child_by_name(state->f0.reg.ospeedr, "OSPEEDR13");
	state->f0.fld.ospeedr.ospeedr14 = cm_object_get_child_by_name(state->f0.reg.ospeedr, "OSPEEDR14");
	state->f0.fld.ospeedr.ospeedr15 = cm_object_get_child_by_name(state->f0.reg.ospeedr, "OSPEEDR15");

	// PUPDR bitfields.
	state->f0.fld.pupdr.pupdr0 = cm_object_get_child_by_name(state->f0.reg.pupdr, "PUPDR0");
	state->f0.fld.pupdr.pupdr1 = cm_object_get_child_by_name(state->f0.reg.pupdr, "PUPDR1");
	state->f0.fld.pupdr.pupdr2 = cm_object_get_child_by_name(state->f0.reg.pupdr, "PUPDR2");
	state->f0.fld.pupdr.pupdr3 = cm_object_get_child_by_name(state->f0.reg.pupdr, "PUPDR3");
	state->f0.fld.pupdr.pupdr4 = cm_object_get_child_by_name(state->f0.reg.pupdr, "PUPDR4");
	state->f0.fld.pupdr.pupdr5 = cm_object_get_child_by_name(state->f0.reg.pupdr, "PUPDR5");
	state->f0.fld.pupdr.pupdr6 = cm_object_get_child_by_name(state->f0.reg.pupdr, "PUPDR6");
	state->f0.fld.pupdr.pupdr7 = cm_object_get_child_by_name(state->f0.reg.pupdr, "PUPDR7");
	state->f0.fld.pupdr.pupdr8 = cm_object_get_child_by_name(state->f0.reg.pupdr, "PUPDR8");
	state->f0.fld.pupdr.pupdr9 = cm_object_get_child_by_name(state->f0.reg.pupdr, "PUPDR9");
	state->f0.fld.pupdr.pupdr10 = cm_object_get_child_by_name(state->f0.reg.pupdr, "PUPDR10");
	state->f0.fld.pupdr.pupdr11 = cm_object_get_child_by_name(state->f0.reg.pupdr, "PUPDR11");
	state->f0.fld.pupdr.pupdr12 = cm_object_get_child_by_name(state->f0.reg.pupdr, "PUPDR12");
	state->f0.fld.pupdr.pupdr13 = cm_object_get_child_by_name(state->f0.reg.pupdr, "PUPDR13");
	state->f0.fld.pupdr.pupdr14 = cm_object_get_child_by_name(state->f0.reg.pupdr, "PUPDR14");
	state->f0.fld.pupdr.pupdr15 = cm_object_get_child_by_name(state->f0.reg.pupdr, "PUPDR15");

	// IDR bitfields.
	state->f0.fld.idr.idr0 = cm_object_get_child_by_name(state->f0.reg.idr, "IDR0");
	state->f0.fld.idr.idr1 = cm_object_get_child_by_name(state->f0.reg.idr, "IDR1");
	state->f0.fld.idr.idr2 = cm_object_get_child_by_name(state->f0.reg.idr, "IDR2");
	state->f0.fld.idr.idr3 = cm_object_get_child_by_name(state->f0.reg.idr, "IDR3");
	state->f0.fld.idr.idr4 = cm_object_get_child_by_name(state->f0.reg.idr, "IDR4");
	state->f0.fld.idr.idr5 = cm_object_get_child_by_name(state->f0.reg.idr, "IDR5");
	state->f0.fld.idr.idr6 = cm_object_get_child_by_name(state->f0.reg.idr, "IDR6");
	state->f0.fld.idr.idr7 = cm_object_get_child_by_name(state->f0.reg.idr, "IDR7");
	state->f0.fld.idr.idr8 = cm_object_get_child_by_name(state->f0.reg.idr, "IDR8");
	state->f0.fld.idr.idr9 = cm_object_get_child_by_name(state->f0.reg.idr, "IDR9");
	state->f0.fld.idr.idr10 = cm_object_get_child_by_name(state->f0.reg.idr, "IDR10");
	state->f0.fld.idr.idr11 = cm_object_get_child_by_name(state->f0.reg.idr, "IDR11");
	state->f0.fld.idr.idr12 = cm_object_get_child_by_name(state->f0.reg.idr, "IDR12");
	state->f0.fld.idr.idr13 = cm_object_get_child_by_name(state->f0.reg.idr, "IDR13");
	state->f0.fld.idr.idr14 = cm_object_get_child_by_name(state->f0.reg.idr, "IDR14");
	state->f0.fld.idr.idr15 = cm_object_get_child_by_name(state->f0.reg.idr, "IDR15");

	// ODR bitfields.
	state->f0.fld.odr.odr0 = cm_object_get_child_by_name(state->f0.reg.odr, "ODR0");
	state->f0.fld.odr.odr1 = cm_object_get_child_by_name(state->f0.reg.odr, "ODR1");
	state->f0.fld.odr.odr2 = cm_object_get_child_by_name(state->f0.reg.odr, "ODR2");
	state->f0.fld.odr.odr3 = cm_object_get_child_by_name(state->f0.reg.odr, "ODR3");
	state->f0.fld.odr.odr4 = cm_object_get_child_by_name(state->f0.reg.odr, "ODR4");
	state->f0.fld.odr.odr5 = cm_object_get_child_by_name(state->f0.reg.odr, "ODR5");
	state->f0.fld.odr.odr6 = cm_object_get_child_by_name(state->f0.reg.odr, "ODR6");
	state->f0.fld.odr.odr7 = cm_object_get_child_by_name(state->f0.reg.odr, "ODR7");
	state->f0.fld.odr.odr8 = cm_object_get_child_by_name(state->f0.reg.odr, "ODR8");
	state->f0.fld.odr.odr9 = cm_object_get_child_by_name(state->f0.reg.odr, "ODR9");
	state->f0.fld.odr.odr10 = cm_object_get_child_by_name(state->f0.reg.odr, "ODR10");
	state->f0.fld.odr.odr11 = cm_object_get_child_by_name(state->f0.reg.odr, "ODR11");
	state->f0.fld.odr.odr12 = cm_object_get_child_by_name(state->f0.reg.odr, "ODR12");
	state->f0.fld.odr.odr13 = cm_object_get_child_by_name(state->f0.reg.odr, "ODR13");
	state->f0.fld.odr.odr14 = cm_object_get_child_by_name(state->f0.reg.odr, "ODR14");
	state->f0.fld.odr.odr15 = cm_object_get_child_by_name(state->f0.reg.odr, "ODR15");

	// BSRR bitfields.
	state->f0.fld.bsrr.bs0 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BS0");
	state->f0.fld.bsrr.bs1 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BS1");
	state->f0.fld.bsrr.bs2 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BS2");
	state->f0.fld.bsrr.bs3 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BS3");
	state->f0.fld.bsrr.bs4 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BS4");
	state->f0.fld.bsrr.bs5 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BS5");
	state->f0.fld.bsrr.bs6 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BS6");
	state->f0.fld.bsrr.bs7 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BS7");
	state->f0.fld.bsrr.bs8 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BS8");
	state->f0.fld.bsrr.bs9 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BS9");
	state->f0.fld.bsrr.bs10 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BS10");
	state->f0.fld.bsrr.bs11 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BS11");
	state->f0.fld.bsrr.bs12 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BS12");
	state->f0.fld.bsrr.bs13 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BS13");
	state->f0.fld.bsrr.bs14 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BS14");
	state->f0.fld.bsrr.bs15 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BS15");
	state->f0.fld.bsrr.br0 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BR0");
	state->f0.fld.bsrr.br1 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BR1");
	state->f0.fld.bsrr.br2 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BR2");
	state->f0.fld.bsrr.br3 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BR3");
	state->f0.fld.bsrr.br4 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BR4");
	state->f0.fld.bsrr.br5 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BR5");
	state->f0.fld.bsrr.br6 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BR6");
	state->f0.fld.bsrr.br7 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BR7");
	state->f0.fld.bsrr.br8 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BR8");
	state->f0.fld.bsrr.br9 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BR9");
	state->f0.fld.bsrr.br10 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BR10");
	state->f0.fld.bsrr.br11 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BR11");
	state->f0.fld.bsrr.br12 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BR12");
	state->f0.fld.bsrr.br13 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BR13");
	state->f0.fld.bsrr.br14 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BR14");
	state->f0.fld.bsrr.br15 = cm_object_get_child_by_name(state->f0.reg.bsrr, "BR15");

	// LCKR bitfields.
	state->f0.fld.lckr.lck0 = cm_object_get_child_by_name(state->f0.reg.lckr, "LCK0");
	state->f0.fld.lckr.lck1 = cm_object_get_child_by_name(state->f0.reg.lckr, "LCK1");
	state->f0.fld.lckr.lck2 = cm_object_get_child_by_name(state->f0.reg.lckr, "LCK2");
	state->f0.fld.lckr.lck3 = cm_object_get_child_by_name(state->f0.reg.lckr, "LCK3");
	state->f0.fld.lckr.lck4 = cm_object_get_child_by_name(state->f0.reg.lckr, "LCK4");
	state->f0.fld.lckr.lck5 = cm_object_get_child_by_name(state->f0.reg.lckr, "LCK5");
	state->f0.fld.lckr.lck6 = cm_object_get_child_by_name(state->f0.reg.lckr, "LCK6");
	state->f0.fld.lckr.lck7 = cm_object_get_child_by_name(state->f0.reg.lckr, "LCK7");
	state->f0.fld.lckr.lck8 = cm_object_get_child_by_name(state->f0.reg.lckr, "LCK8");
	state->f0.fld.lckr.lck9 = cm_object_get_child_by_name(state->f0.reg.lckr, "LCK9");
	state->f0.fld.lckr.lck10 = cm_object_get_child_by_name(state->f0.reg.lckr, "LCK10");
	state->f0.fld.lckr.lck11 = cm_object_get_child_by_name(state->f0.reg.lckr, "LCK11");
	state->f0.fld.lckr.lck12 = cm_object_get_child_by_name(state->f0.reg.lckr, "LCK12");
	state->f0.fld.lckr.lck13 = cm_object_get_child_by_name(state->f0.reg.lckr, "LCK13");
	state->f0.fld.lckr.lck14 = cm_object_get_child_by_name(state->f0.reg.lckr, "LCK14");
	state->f0.fld.lckr.lck15 = cm_object_get_child_by_name(state->f0.reg.lckr, "LCK15");
	state->f0.fld.lckr.lckk = cm_object_get_child_by_name(state->f0.reg.lckr, "LCKK");

	// AFRL bitfields.
	state->f0.fld.afrl.afrl0 = cm_object_get_child_by_name(state->f0.reg.afrl, "AFRL0");
	state->f0.fld.afrl.afrl1 = cm_object_get_child_by_name(state->f0.reg.afrl, "AFRL1");
	state->f0.fld.afrl.afrl2 = cm_object_get_child_by_name(state->f0.reg.afrl, "AFRL2");
	state->f0.fld.afrl.afrl3 = cm_object_get_child_by_name(state->f0.reg.afrl, "AFRL3");
	state->f0.fld.afrl.afrl4 = cm_object_get_child_by_name(state->f0.reg.afrl, "AFRL4");
	state->f0.fld.afrl.afrl5 = cm_object_get_child_by_name(state->f0.reg.afrl, "AFRL5");
	state->f0.fld.afrl.afrl6 = cm_object_get_child_by_name(state->f0.reg.afrl, "AFRL6");
	state->f0.fld.afrl.afrl7 = cm_object_get_child_by_name(state->f0.reg.afrl, "AFRL7");

	// AFRH bitfields.
	state->f0.fld.afrh.afrh8 = cm_object_get_child_by_name(state->f0.reg.afrh, "AFRH8");
	state->f0.fld.afrh.afrh9 = cm_object_get_child_by_name(state->f0.reg.afrh, "AFRH9");
	state->f0.fld.afrh.afrh10 = cm_object_get_child_by_name(state->f0.reg.afrh, "AFRH10");
	state->f0.fld.afrh.afrh11 = cm_object_get_child_by_name(state->f0.reg.afrh, "AFRH11");
	state->f0.fld.afrh.afrh12 = cm_object_get_child_by_name(state->f0.reg.afrh, "AFRH12");
	state->f0.fld.afrh.afrh13 = cm_object_get_child_by_name(state->f0.reg.afrh, "AFRH13");
	state->f0.fld.afrh.afrh14 = cm_object_get_child_by_name(state->f0.reg.afrh, "AFRH14");
	state->f0.fld.afrh.afrh15 = cm_object_get_child_by_name(state->f0.reg.afrh, "AFRH15");

	// BRR bitfields.
	state->f0.fld.brr.br0 = cm_object_get_child_by_name(state->f0.reg.brr, "BR0");
	state->f0.fld.brr.br1 = cm_object_get_child_by_name(state->f0.reg.brr, "BR1");
	state->f0.fld.brr.br2 = cm_object_get_child_by_name(state->f0.reg.brr, "BR2");
	state->f0.fld.brr.br3 = cm_object_get_child_by_name(state->f0.reg.brr, "BR3");
	state->f0.fld.brr.br4 = cm_object_get_child_by_name(state->f0.reg.brr, "BR4");
	state->f0.fld.brr.br5 = cm_object_get_child_by_name(state->f0.reg.brr, "BR5");
	state->f0.fld.brr.br6 = cm_object_get_child_by_name(state->f0.reg.brr, "BR6");
	state->f0.fld.brr.br7 = cm_object_get_child_by_name(state->f0.reg.brr, "BR7");
	state->f0.fld.brr.br8 = cm_object_get_child_by_name(state->f0.reg.brr, "BR8");
	state->f0.fld.brr.br9 = cm_object_get_child_by_name(state->f0.reg.brr, "BR9");
	state->f0.fld.brr.br10 = cm_object_get_child_by_name(state->f0.reg.brr, "BR10");
	state->f0.fld.brr.br11 = cm_object_get_child_by_name(state->f0.reg.brr, "BR11");
	state->f0.fld.brr.br12 = cm_object_get_child_by_name(state->f0.reg.brr, "BR12");
	state->f0.fld.brr.br13 = cm_object_get_child_by_name(state->f0.reg.brr, "BR13");
	state->f0.fld.brr.br14 = cm_object_get_child_by_name(state->f0.reg.brr, "BR14");
	state->f0.fld.brr.br15 = cm_object_get_child_by_name(state->f0.reg.brr, "BR15");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// SPI1 (Serial peripheral interface) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F0 SPI1 (Serial peripheral interface) registers.
		struct {
			Object *cr1; // 0x0 Control register 1
			Object *cr2; // 0x4 Control register 2
			Object *sr; // 0x8 Status register
			Object *dr; // 0xC Data register
			Object *crcpr; // 0x10 CRC polynomial register
			Object *rxcrcr; // 0x14 RX CRC register
			Object *txcrcr; // 0x18 TX CRC register
			Object *i2scfgr; // 0x1C I2S configuration register
			Object *i2spr; // 0x20 I2S prescaler register
		} reg;

		struct {

			// CR1 (Control register 1) bitfields.
			struct {
				Object *cpha; // [0:0] Clock phase
				Object *cpol; // [1:1] Clock polarity
				Object *mstr; // [2:2] Master selection
				Object *br; // [3:5] Baud rate control
				Object *spe; // [6:6] SPI enable
				Object *lsbfirst; // [7:7] Frame format
				Object *ssi; // [8:8] Internal slave select
				Object *ssm; // [9:9] Software slave management
				Object *rxonly; // [10:10] Receive only
				Object *dff; // [11:11] Data frame format
				Object *crcnext; // [12:12] CRC transfer next
				Object *crcen; // [13:13] Hardware CRC calculation enable
				Object *bidioe; // [14:14] Output enable in bidirectional mode
				Object *bidimode; // [15:15] Bidirectional data mode enable
			} cr1;

			// CR2 (Control register 2) bitfields.
			struct {
				Object *rxdmaen; // [0:0] Rx buffer DMA enable
				Object *txdmaen; // [1:1] Tx buffer DMA enable
				Object *ssoe; // [2:2] SS output enable
				Object *nssp; // [3:3] NSS pulse management
				Object *frf; // [4:4] Frame format
				Object *errie; // [5:5] Error interrupt enable
				Object *rxneie; // [6:6] RX buffer not empty interrupt enable
				Object *txeie; // [7:7] Tx buffer empty interrupt enable
				Object *ds; // [8:11] Data size
				Object *frxth; // [12:12] FIFO reception threshold
				Object *ldma_rx; // [13:13] Last DMA transfer for reception
				Object *ldma_tx; // [14:14] Last DMA transfer for transmission
			} cr2;

			// SR (Status register) bitfields.
			struct {
				Object *rxne; // [0:0] Receive buffer not empty
				Object *txe; // [1:1] Transmit buffer empty
				Object *chside; // [2:2] Channel side
				Object *udr; // [3:3] Underrun flag
				Object *crcerr; // [4:4] CRC error flag
				Object *modf; // [5:5] Mode fault
				Object *ovr; // [6:6] Overrun flag
				Object *bsy; // [7:7] Busy flag
				Object *tifrfe; // [8:8] TI frame format error
				Object *frlvl; // [9:10] FIFO reception level
				Object *ftlvl; // [11:12] FIFO transmission level
			} sr;

			// DR (Data register) bitfields.
			struct {
				Object *dr; // [0:15] Data register
			} dr;

			// CRCPR (CRC polynomial register) bitfields.
			struct {
				Object *crcpoly; // [0:15] CRC polynomial register
			} crcpr;

			// RXCRCR (RX CRC register) bitfields.
			struct {
				Object *rxcrc; // [0:15] Rx CRC register
			} rxcrcr;

			// TXCRCR (TX CRC register) bitfields.
			struct {
				Object *txcrc; // [0:15] Tx CRC register
			} txcrcr;

			// I2SCFGR (I2S configuration register) bitfields.
			struct {
				Object *chlen; // [0:0] Channel length (number of bits per audio channel)
				Object *datlen; // [1:2] Data length to be transferred
				Object *ckpol; // [3:3] Steady state clock polarity
				Object *i2sstd; // [4:5] I2S standard selection
				Object *pcmsync; // [7:7] PCM frame synchronization
				Object *i2scfg; // [8:9] I2S configuration mode
				Object *i2se; // [10:10] I2S Enable
				Object *i2smod; // [11:11] I2S mode selection
			} i2scfgr;

			// I2SPR (I2S prescaler register) bitfields.
			struct {
				Object *i2sdiv; // [0:7] I2S Linear prescaler
				Object *odd; // [8:8] Odd factor for the prescaler
				Object *mckoe; // [9:9] Master clock output enable
			} i2spr;
		} fld;
	} f0;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32SPI1State;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_spi1_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32SPI1State *state = STM32_SPI1_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f0.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
	state->f0.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
	state->f0.reg.sr = cm_object_get_child_by_name(obj, "SR");
	state->f0.reg.dr = cm_object_get_child_by_name(obj, "DR");
	state->f0.reg.crcpr = cm_object_get_child_by_name(obj, "CRCPR");
	state->f0.reg.rxcrcr = cm_object_get_child_by_name(obj, "RXCRCR");
	state->f0.reg.txcrcr = cm_object_get_child_by_name(obj, "TXCRCR");
	state->f0.reg.i2scfgr = cm_object_get_child_by_name(obj, "I2SCFGR");
	state->f0.reg.i2spr = cm_object_get_child_by_name(obj, "I2SPR");

	// CR1 bitfields.
	state->f0.fld.cr1.cpha = cm_object_get_child_by_name(state->f0.reg.cr1, "CPHA");
	state->f0.fld.cr1.cpol = cm_object_get_child_by_name(state->f0.reg.cr1, "CPOL");
	state->f0.fld.cr1.mstr = cm_object_get_child_by_name(state->f0.reg.cr1, "MSTR");
	state->f0.fld.cr1.br = cm_object_get_child_by_name(state->f0.reg.cr1, "BR");
	state->f0.fld.cr1.spe = cm_object_get_child_by_name(state->f0.reg.cr1, "SPE");
	state->f0.fld.cr1.lsbfirst = cm_object_get_child_by_name(state->f0.reg.cr1, "LSBFIRST");
	state->f0.fld.cr1.ssi = cm_object_get_child_by_name(state->f0.reg.cr1, "SSI");
	state->f0.fld.cr1.ssm = cm_object_get_child_by_name(state->f0.reg.cr1, "SSM");
	state->f0.fld.cr1.rxonly = cm_object_get_child_by_name(state->f0.reg.cr1, "RXONLY");
	state->f0.fld.cr1.dff = cm_object_get_child_by_name(state->f0.reg.cr1, "DFF");
	state->f0.fld.cr1.crcnext = cm_object_get_child_by_name(state->f0.reg.cr1, "CRCNEXT");
	state->f0.fld.cr1.crcen = cm_object_get_child_by_name(state->f0.reg.cr1, "CRCEN");
	state->f0.fld.cr1.bidioe = cm_object_get_child_by_name(state->f0.reg.cr1, "BIDIOE");
	state->f0.fld.cr1.bidimode = cm_object_get_child_by_name(state->f0.reg.cr1, "BIDIMODE");

	// CR2 bitfields.
	state->f0.fld.cr2.rxdmaen = cm_object_get_child_by_name(state->f0.reg.cr2, "RXDMAEN");
	state->f0.fld.cr2.txdmaen = cm_object_get_child_by_name(state->f0.reg.cr2, "TXDMAEN");
	state->f0.fld.cr2.ssoe = cm_object_get_child_by_name(state->f0.reg.cr2, "SSOE");
	state->f0.fld.cr2.nssp = cm_object_get_child_by_name(state->f0.reg.cr2, "NSSP");
	state->f0.fld.cr2.frf = cm_object_get_child_by_name(state->f0.reg.cr2, "FRF");
	state->f0.fld.cr2.errie = cm_object_get_child_by_name(state->f0.reg.cr2, "ERRIE");
	state->f0.fld.cr2.rxneie = cm_object_get_child_by_name(state->f0.reg.cr2, "RXNEIE");
	state->f0.fld.cr2.txeie = cm_object_get_child_by_name(state->f0.reg.cr2, "TXEIE");
	state->f0.fld.cr2.ds = cm_object_get_child_by_name(state->f0.reg.cr2, "DS");
	state->f0.fld.cr2.frxth = cm_object_get_child_by_name(state->f0.reg.cr2, "FRXTH");
	state->f0.fld.cr2.ldma_rx = cm_object_get_child_by_name(state->f0.reg.cr2, "LDMA_RX");
	state->f0.fld.cr2.ldma_tx = cm_object_get_child_by_name(state->f0.reg.cr2, "LDMA_TX");

	// SR bitfields.
	state->f0.fld.sr.rxne = cm_object_get_child_by_name(state->f0.reg.sr, "RXNE");
	state->f0.fld.sr.txe = cm_object_get_child_by_name(state->f0.reg.sr, "TXE");
	state->f0.fld.sr.chside = cm_object_get_child_by_name(state->f0.reg.sr, "CHSIDE");
	state->f0.fld.sr.udr = cm_object_get_child_by_name(state->f0.reg.sr, "UDR");
	state->f0.fld.sr.crcerr = cm_object_get_child_by_name(state->f0.reg.sr, "CRCERR");
	state->f0.fld.sr.modf = cm_object_get_child_by_name(state->f0.reg.sr, "MODF");
	state->f0.fld.sr.ovr = cm_object_get_child_by_name(state->f0.reg.sr, "OVR");
	state->f0.fld.sr.bsy = cm_object_get_child_by_name(state->f0.reg.sr, "BSY");
	state->f0.fld.sr.tifrfe = cm_object_get_child_by_name(state->f0.reg.sr, "TIFRFE");
	state->f0.fld.sr.frlvl = cm_object_get_child_by_name(state->f0.reg.sr, "FRLVL");
	state->f0.fld.sr.ftlvl = cm_object_get_child_by_name(state->f0.reg.sr, "FTLVL");

	// DR bitfields.
	state->f0.fld.dr.dr = cm_object_get_child_by_name(state->f0.reg.dr, "DR");

	// CRCPR bitfields.
	state->f0.fld.crcpr.crcpoly = cm_object_get_child_by_name(state->f0.reg.crcpr, "CRCPOLY");

	// RXCRCR bitfields.
	state->f0.fld.rxcrcr.rxcrc = cm_object_get_child_by_name(state->f0.reg.rxcrcr, "RxCRC");

	// TXCRCR bitfields.
	state->f0.fld.txcrcr.txcrc = cm_object_get_child_by_name(state->f0.reg.txcrcr, "TxCRC");

	// I2SCFGR bitfields.
	state->f0.fld.i2scfgr.chlen = cm_object_get_child_by_name(state->f0.reg.i2scfgr, "CHLEN");
	state->f0.fld.i2scfgr.datlen = cm_object_get_child_by_name(state->f0.reg.i2scfgr, "DATLEN");
	state->f0.fld.i2scfgr.ckpol = cm_object_get_child_by_name(state->f0.reg.i2scfgr, "CKPOL");
	state->f0.fld.i2scfgr.i2sstd = cm_object_get_child_by_name(state->f0.reg.i2scfgr, "I2SSTD");
	state->f0.fld.i2scfgr.pcmsync = cm_object_get_child_by_name(state->f0.reg.i2scfgr, "PCMSYNC");
	state->f0.fld.i2scfgr.i2scfg = cm_object_get_child_by_name(state->f0.reg.i2scfgr, "I2SCFG");
	state->f0.fld.i2scfgr.i2se = cm_object_get_child_by_name(state->f0.reg.i2scfgr, "I2SE");
	state->f0.fld.i2scfgr.i2smod = cm_object_get_child_by_name(state->f0.reg.i2scfgr, "I2SMOD");

	// I2SPR bitfields.
	state->f0.fld.i2spr.i2sdiv = cm_object_get_child_by_name(state->f0.reg.i2spr, "I2SDIV");
	state->f0.fld.i2spr.odd = cm_object_get_child_by_name(state->f0.reg.i2spr, "ODD");
	state->f0.fld.i2spr.mckoe = cm_object_get_child_by_name(state->f0.reg.i2spr, "MCKOE");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DAC (Digital-to-analog converter) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F0 DAC (Digital-to-analog converter) registers.
		struct {
			Object *cr; // 0x0 Control register
			Object *swtrigr; // 0x4 Software trigger register
			Object *dhr12r1; // 0x8 Channel1 12-bit right-aligned data holding register
			Object *dhr12l1; // 0xC Channel1 12-bit left aligned data holding register
			Object *dhr8r1; // 0x10 Channel1 8-bit right aligned data holding register
			Object *dor1; // 0x2C Channel1 data output register
			Object *sr; // 0x34 Status register
		} reg;

		struct {

			// CR (Control register) bitfields.
			struct {
				Object *lpds; // [0:0] Low-power deep sleep
				Object *pdds; // [1:1] Power down deepsleep
				Object *cwuf; // [2:2] Clear wakeup flag
				Object *csbf; // [3:3] Clear standby flag
				Object *pvde; // [4:4] Power voltage detector enable
				Object *pls; // [5:7] PVD level selection
				Object *dbp; // [8:8] Disable backup domain write protection
			} cr;

			// SWTRIGR (Software trigger register) bitfields.
			struct {
				Object *swtrig1; // [0:0] DAC channel1 software trigger
			} swtrigr;

			// DHR12R1 (Channel1 12-bit right-aligned data holding register) bitfields.
			struct {
				Object *dacc1dhr; // [0:11] DAC channel1 12-bit right-aligned data
			} dhr12r1;

			// DHR12L1 (Channel1 12-bit left aligned data holding register) bitfields.
			struct {
				Object *dacc1dhr; // [4:15] DAC channel1 12-bit left-aligned data
			} dhr12l1;

			// DHR8R1 (Channel1 8-bit right aligned data holding register) bitfields.
			struct {
				Object *dacc1dhr; // [0:7] DAC channel1 8-bit right-aligned data
			} dhr8r1;

			// DOR1 (Channel1 data output register) bitfields.
			struct {
				Object *dacc1dor; // [0:11] DAC channel1 data output
			} dor1;

			// SR (Status register) bitfields.
			struct {
				Object *dmaudr1; // [13:13] DAC channel1 DMA underrun flag
				Object *dmaudr2; // [29:29] DAC channel2 DMA underrun flag
			} sr;
		} fld;
	} f0;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32DACState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_dac_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32DACState *state = STM32_DAC_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f0.reg.cr = cm_object_get_child_by_name(obj, "CR");
	state->f0.reg.swtrigr = cm_object_get_child_by_name(obj, "SWTRIGR");
	state->f0.reg.dhr12r1 = cm_object_get_child_by_name(obj, "DHR12R1");
	state->f0.reg.dhr12l1 = cm_object_get_child_by_name(obj, "DHR12L1");
	state->f0.reg.dhr8r1 = cm_object_get_child_by_name(obj, "DHR8R1");
	state->f0.reg.dor1 = cm_object_get_child_by_name(obj, "DOR1");
	state->f0.reg.sr = cm_object_get_child_by_name(obj, "SR");

	// CR bitfields.
	state->f0.fld.cr.lpds = cm_object_get_child_by_name(state->f0.reg.cr, "LPDS");
	state->f0.fld.cr.pdds = cm_object_get_child_by_name(state->f0.reg.cr, "PDDS");
	state->f0.fld.cr.cwuf = cm_object_get_child_by_name(state->f0.reg.cr, "CWUF");
	state->f0.fld.cr.csbf = cm_object_get_child_by_name(state->f0.reg.cr, "CSBF");
	state->f0.fld.cr.pvde = cm_object_get_child_by_name(state->f0.reg.cr, "PVDE");
	state->f0.fld.cr.pls = cm_object_get_child_by_name(state->f0.reg.cr, "PLS");
	state->f0.fld.cr.dbp = cm_object_get_child_by_name(state->f0.reg.cr, "DBP");

	// SWTRIGR bitfields.
	state->f0.fld.swtrigr.swtrig1 = cm_object_get_child_by_name(state->f0.reg.swtrigr, "SWTRIG1");

	// DHR12R1 bitfields.
	state->f0.fld.dhr12r1.dacc1dhr = cm_object_get_child_by_name(state->f0.reg.dhr12r1, "DACC1DHR");

	// DHR12L1 bitfields.
	state->f0.fld.dhr12l1.dacc1dhr = cm_object_get_child_by_name(state->f0.reg.dhr12l1, "DACC1DHR");

	// DHR8R1 bitfields.
	state->f0.fld.dhr8r1.dacc1dhr = cm_object_get_child_by_name(state->f0.reg.dhr8r1, "DACC1DHR");

	// DOR1 bitfields.
	state->f0.fld.dor1.dacc1dor = cm_object_get_child_by_name(state->f0.reg.dor1, "DACC1DOR");

	// SR bitfields.
	state->f0.fld.sr.dmaudr1 = cm_object_get_child_by_name(state->f0.reg.sr, "DMAUDR1");
	state->f0.fld.sr.dmaudr2 = cm_object_get_child_by_name(state->f0.reg.sr, "DMAUDR2");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// PWR (Power control) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F0 PWR (Power control) registers.
		struct {
			Object *cr; // 0x0 Power control register
			Object *csr; // 0x4 Power control/status register
		} reg;

		struct {

			// CR (Power control register) bitfields.
			struct {
				Object *lpds; // [0:0] Low-power deep sleep
				Object *pdds; // [1:1] Power down deepsleep
				Object *cwuf; // [2:2] Clear wakeup flag
				Object *csbf; // [3:3] Clear standby flag
				Object *pvde; // [4:4] Power voltage detector enable
				Object *pls; // [5:7] PVD level selection
				Object *dbp; // [8:8] Disable backup domain write protection
			} cr;

			// CSR (Power control/status register) bitfields.
			struct {
				Object *wuf; // [0:0] Wakeup flag
				Object *sbf; // [1:1] Standby flag
				Object *pvdo; // [2:2] PVD output
				Object *vrefintrdy; // [3:3] VREFINT reference voltage ready
				Object *ewup1; // [8:8] Enable WKUP pin 1
				Object *ewup2; // [9:9] Enable WKUP pin 2
				Object *ewup3; // [10:10] Enable WKUP pin 3
				Object *ewup4; // [11:11] Enable WKUP pin 4
				Object *ewup5; // [12:12] Enable WKUP pin 5
				Object *ewup6; // [13:13] Enable WKUP pin 6
				Object *ewup7; // [14:14] Enable WKUP pin 7
				Object *ewup8; // [15:15] Enable WKUP pin 8
			} csr;
		} fld;
	} f0;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32PWRState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_pwr_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32PWRState *state = STM32_PWR_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f0.reg.cr = cm_object_get_child_by_name(obj, "CR");
	state->f0.reg.csr = cm_object_get_child_by_name(obj, "CSR");

	// CR bitfields.
	state->f0.fld.cr.lpds = cm_object_get_child_by_name(state->f0.reg.cr, "LPDS");
	state->f0.fld.cr.pdds = cm_object_get_child_by_name(state->f0.reg.cr, "PDDS");
	state->f0.fld.cr.cwuf = cm_object_get_child_by_name(state->f0.reg.cr, "CWUF");
	state->f0.fld.cr.csbf = cm_object_get_child_by_name(state->f0.reg.cr, "CSBF");
	state->f0.fld.cr.pvde = cm_object_get_child_by_name(state->f0.reg.cr, "PVDE");
	state->f0.fld.cr.pls = cm_object_get_child_by_name(state->f0.reg.cr, "PLS");
	state->f0.fld.cr.dbp = cm_object_get_child_by_name(state->f0.reg.cr, "DBP");

	// CSR bitfields.
	state->f0.fld.csr.wuf = cm_object_get_child_by_name(state->f0.reg.csr, "WUF");
	state->f0.fld.csr.sbf = cm_object_get_child_by_name(state->f0.reg.csr, "SBF");
	state->f0.fld.csr.pvdo = cm_object_get_child_by_name(state->f0.reg.csr, "PVDO");
	state->f0.fld.csr.vrefintrdy = cm_object_get_child_by_name(state->f0.reg.csr, "VREFINTRDY");
	state->f0.fld.csr.ewup1 = cm_object_get_child_by_name(state->f0.reg.csr, "EWUP1");
	state->f0.fld.csr.ewup2 = cm_object_get_child_by_name(state->f0.reg.csr, "EWUP2");
	state->f0.fld.csr.ewup3 = cm_object_get_child_by_name(state->f0.reg.csr, "EWUP3");
	state->f0.fld.csr.ewup4 = cm_object_get_child_by_name(state->f0.reg.csr, "EWUP4");
	state->f0.fld.csr.ewup5 = cm_object_get_child_by_name(state->f0.reg.csr, "EWUP5");
	state->f0.fld.csr.ewup6 = cm_object_get_child_by_name(state->f0.reg.csr, "EWUP6");
	state->f0.fld.csr.ewup7 = cm_object_get_child_by_name(state->f0.reg.csr, "EWUP7");
	state->f0.fld.csr.ewup8 = cm_object_get_child_by_name(state->f0.reg.csr, "EWUP8");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// I2C1 (Inter-integrated circuit) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F0 I2C1 (Inter-integrated circuit) registers.
		struct {
			Object *cr1; // 0x0 Control register 1
			Object *cr2; // 0x4 Control register 2
			Object *oar1; // 0x8 Own address register 1
			Object *oar2; // 0xC Own address register 2
			Object *timingr; // 0x10 Timing register
			Object *timeoutr; // 0x14 Status register 1
			Object *isr; // 0x18 Interrupt and Status register
			Object *icr; // 0x1C Interrupt clear register
			Object *pecr; // 0x20 PEC register
			Object *rxdr; // 0x24 Receive data register
			Object *txdr; // 0x28 Transmit data register
		} reg;

		struct {

			// CR1 (Control register 1) bitfields.
			struct {
				Object *pe; // [0:0] Peripheral enable
				Object *txie; // [1:1] TX Interrupt enable
				Object *rxie; // [2:2] RX Interrupt enable
				Object *addrie; // [3:3] Address match interrupt enable (slave only)
				Object *nackie; // [4:4] Not acknowledge received interrupt enable
				Object *stopie; // [5:5] STOP detection Interrupt enable
				Object *tcie; // [6:6] Transfer Complete interrupt enable
				Object *errie; // [7:7] Error interrupts enable
				Object *dnf; // [8:11] Digital noise filter
				Object *anfoff; // [12:12] Analog noise filter OFF
				Object *swrst; // [13:13] Software reset
				Object *txdmaen; // [14:14] DMA transmission requests enable
				Object *rxdmaen; // [15:15] DMA reception requests enable
				Object *sbc; // [16:16] Slave byte control
				Object *nostretch; // [17:17] Clock stretching disable
				Object *wupen; // [18:18] Wakeup from STOP enable
				Object *gcen; // [19:19] General call enable
				Object *smbhen; // [20:20] SMBus Host address enable
				Object *smbden; // [21:21] SMBus Device Default address enable
				Object *alerten; // [22:22] SMBUS alert enable
				Object *pecen; // [23:23] PEC enable
			} cr1;

			// CR2 (Control register 2) bitfields.
			struct {
				Object *sadd0; // [0:0] Slave address bit 0 (master mode)
				Object *sadd1; // [1:7] Slave address bit 7:1 (master mode)
				Object *sadd8; // [8:9] Slave address bit 9:8 (master mode)
				Object *rd_wrn; // [10:10] Transfer direction (master mode)
				Object *add10; // [11:11] 10-bit addressing mode (master mode)
				Object *head10r; // [12:12] 10-bit address header only read direction (master receiver mode)
				Object *start; // [13:13] Start generation
				Object *stop; // [14:14] Stop generation (master mode)
				Object *nack; // [15:15] NACK generation (slave mode)
				Object *nbytes; // [16:23] Number of bytes
				Object *reload; // [24:24] NBYTES reload mode
				Object *autoend; // [25:25] Automatic end mode (master mode)
				Object *pecbyte; // [26:26] Packet error checking byte
			} cr2;

			// OAR1 (Own address register 1) bitfields.
			struct {
				Object *oa1_0; // [0:0] Interface address
				Object *oa1_1; // [1:7] Interface address
				Object *oa1_8; // [8:9] Interface address
				Object *oa1mode; // [10:10] Own Address 1 10-bit mode
				Object *oa1en; // [15:15] Own Address 1 enable
			} oar1;

			// OAR2 (Own address register 2) bitfields.
			struct {
				Object *oa2; // [1:7] Interface address
				Object *oa2msk; // [8:10] Own Address 2 masks
				Object *oa2en; // [15:15] Own Address 2 enable
			} oar2;

			// TIMINGR (Timing register) bitfields.
			struct {
				Object *scll; // [0:7] SCL low period (master mode)
				Object *sclh; // [8:15] SCL high period (master mode)
				Object *sdadel; // [16:19] Data hold time
				Object *scldel; // [20:23] Data setup time
				Object *presc; // [28:31] Timing prescaler
			} timingr;

			// TIMEOUTR (Status register 1) bitfields.
			struct {
				Object *timeouta; // [0:11] Bus timeout A
				Object *tidle; // [12:12] Idle clock timeout detection
				Object *timouten; // [15:15] Clock timeout enable
				Object *timeoutb; // [16:27] Bus timeout B
				Object *texten; // [31:31] Extended clock timeout enable
			} timeoutr;

			// ISR (Interrupt and Status register) bitfields.
			struct {
				Object *txe; // [0:0] Transmit data register empty (transmitters)
				Object *txis; // [1:1] Transmit interrupt status (transmitters)
				Object *rxne; // [2:2] Receive data register not empty (receivers)
				Object *addr; // [3:3] Address matched (slave mode)
				Object *nackf; // [4:4] Not acknowledge received flag
				Object *stopf; // [5:5] Stop detection flag
				Object *tc; // [6:6] Transfer Complete (master mode)
				Object *tcr; // [7:7] Transfer Complete Reload
				Object *berr; // [8:8] Bus error
				Object *arlo; // [9:9] Arbitration lost
				Object *ovr; // [10:10] Overrun/Underrun (slave mode)
				Object *pecerr; // [11:11] PEC Error in reception
				Object *timeout; // [12:12] Timeout or t_low detection flag
				Object *alert; // [13:13] SMBus alert
				Object *busy; // [15:15] Bus busy
				Object *dir; // [16:16] Transfer direction (Slave mode)
				Object *addcode; // [17:23] Address match code (Slave mode)
			} isr;

			// ICR (Interrupt clear register) bitfields.
			struct {
				Object *addrcf; // [3:3] Address Matched flag clear
				Object *nackcf; // [4:4] Not Acknowledge flag clear
				Object *stopcf; // [5:5] Stop detection flag clear
				Object *berrcf; // [8:8] Bus error flag clear
				Object *arlocf; // [9:9] Arbitration lost flag clear
				Object *ovrcf; // [10:10] Overrun/Underrun flag clear
				Object *peccf; // [11:11] PEC Error flag clear
				Object *timoutcf; // [12:12] Timeout detection flag clear
				Object *alertcf; // [13:13] Alert flag clear
			} icr;

			// PECR (PEC register) bitfields.
			struct {
				Object *pec; // [0:7] Packet error checking register
			} pecr;

			// RXDR (Receive data register) bitfields.
			struct {
				Object *rxdata; // [0:7] 8-bit receive data
			} rxdr;

			// TXDR (Transmit data register) bitfields.
			struct {
				Object *txdata; // [0:7] 8-bit transmit data
			} txdr;
		} fld;
	} f0;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32I2C1State;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_i2c1_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32I2C1State *state = STM32_I2C1_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f0.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
	state->f0.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
	state->f0.reg.oar1 = cm_object_get_child_by_name(obj, "OAR1");
	state->f0.reg.oar2 = cm_object_get_child_by_name(obj, "OAR2");
	state->f0.reg.timingr = cm_object_get_child_by_name(obj, "TIMINGR");
	state->f0.reg.timeoutr = cm_object_get_child_by_name(obj, "TIMEOUTR");
	state->f0.reg.isr = cm_object_get_child_by_name(obj, "ISR");
	state->f0.reg.icr = cm_object_get_child_by_name(obj, "ICR");
	state->f0.reg.pecr = cm_object_get_child_by_name(obj, "PECR");
	state->f0.reg.rxdr = cm_object_get_child_by_name(obj, "RXDR");
	state->f0.reg.txdr = cm_object_get_child_by_name(obj, "TXDR");

	// CR1 bitfields.
	state->f0.fld.cr1.pe = cm_object_get_child_by_name(state->f0.reg.cr1, "PE");
	state->f0.fld.cr1.txie = cm_object_get_child_by_name(state->f0.reg.cr1, "TXIE");
	state->f0.fld.cr1.rxie = cm_object_get_child_by_name(state->f0.reg.cr1, "RXIE");
	state->f0.fld.cr1.addrie = cm_object_get_child_by_name(state->f0.reg.cr1, "ADDRIE");
	state->f0.fld.cr1.nackie = cm_object_get_child_by_name(state->f0.reg.cr1, "NACKIE");
	state->f0.fld.cr1.stopie = cm_object_get_child_by_name(state->f0.reg.cr1, "STOPIE");
	state->f0.fld.cr1.tcie = cm_object_get_child_by_name(state->f0.reg.cr1, "TCIE");
	state->f0.fld.cr1.errie = cm_object_get_child_by_name(state->f0.reg.cr1, "ERRIE");
	state->f0.fld.cr1.dnf = cm_object_get_child_by_name(state->f0.reg.cr1, "DNF");
	state->f0.fld.cr1.anfoff = cm_object_get_child_by_name(state->f0.reg.cr1, "ANFOFF");
	state->f0.fld.cr1.swrst = cm_object_get_child_by_name(state->f0.reg.cr1, "SWRST");
	state->f0.fld.cr1.txdmaen = cm_object_get_child_by_name(state->f0.reg.cr1, "TXDMAEN");
	state->f0.fld.cr1.rxdmaen = cm_object_get_child_by_name(state->f0.reg.cr1, "RXDMAEN");
	state->f0.fld.cr1.sbc = cm_object_get_child_by_name(state->f0.reg.cr1, "SBC");
	state->f0.fld.cr1.nostretch = cm_object_get_child_by_name(state->f0.reg.cr1, "NOSTRETCH");
	state->f0.fld.cr1.wupen = cm_object_get_child_by_name(state->f0.reg.cr1, "WUPEN");
	state->f0.fld.cr1.gcen = cm_object_get_child_by_name(state->f0.reg.cr1, "GCEN");
	state->f0.fld.cr1.smbhen = cm_object_get_child_by_name(state->f0.reg.cr1, "SMBHEN");
	state->f0.fld.cr1.smbden = cm_object_get_child_by_name(state->f0.reg.cr1, "SMBDEN");
	state->f0.fld.cr1.alerten = cm_object_get_child_by_name(state->f0.reg.cr1, "ALERTEN");
	state->f0.fld.cr1.pecen = cm_object_get_child_by_name(state->f0.reg.cr1, "PECEN");

	// CR2 bitfields.
	state->f0.fld.cr2.sadd0 = cm_object_get_child_by_name(state->f0.reg.cr2, "SADD0");
	state->f0.fld.cr2.sadd1 = cm_object_get_child_by_name(state->f0.reg.cr2, "SADD1");
	state->f0.fld.cr2.sadd8 = cm_object_get_child_by_name(state->f0.reg.cr2, "SADD8");
	state->f0.fld.cr2.rd_wrn = cm_object_get_child_by_name(state->f0.reg.cr2, "RD_WRN");
	state->f0.fld.cr2.add10 = cm_object_get_child_by_name(state->f0.reg.cr2, "ADD10");
	state->f0.fld.cr2.head10r = cm_object_get_child_by_name(state->f0.reg.cr2, "HEAD10R");
	state->f0.fld.cr2.start = cm_object_get_child_by_name(state->f0.reg.cr2, "START");
	state->f0.fld.cr2.stop = cm_object_get_child_by_name(state->f0.reg.cr2, "STOP");
	state->f0.fld.cr2.nack = cm_object_get_child_by_name(state->f0.reg.cr2, "NACK");
	state->f0.fld.cr2.nbytes = cm_object_get_child_by_name(state->f0.reg.cr2, "NBYTES");
	state->f0.fld.cr2.reload = cm_object_get_child_by_name(state->f0.reg.cr2, "RELOAD");
	state->f0.fld.cr2.autoend = cm_object_get_child_by_name(state->f0.reg.cr2, "AUTOEND");
	state->f0.fld.cr2.pecbyte = cm_object_get_child_by_name(state->f0.reg.cr2, "PECBYTE");

	// OAR1 bitfields.
	state->f0.fld.oar1.oa1_0 = cm_object_get_child_by_name(state->f0.reg.oar1, "OA1_0");
	state->f0.fld.oar1.oa1_1 = cm_object_get_child_by_name(state->f0.reg.oar1, "OA1_1");
	state->f0.fld.oar1.oa1_8 = cm_object_get_child_by_name(state->f0.reg.oar1, "OA1_8");
	state->f0.fld.oar1.oa1mode = cm_object_get_child_by_name(state->f0.reg.oar1, "OA1MODE");
	state->f0.fld.oar1.oa1en = cm_object_get_child_by_name(state->f0.reg.oar1, "OA1EN");

	// OAR2 bitfields.
	state->f0.fld.oar2.oa2 = cm_object_get_child_by_name(state->f0.reg.oar2, "OA2");
	state->f0.fld.oar2.oa2msk = cm_object_get_child_by_name(state->f0.reg.oar2, "OA2MSK");
	state->f0.fld.oar2.oa2en = cm_object_get_child_by_name(state->f0.reg.oar2, "OA2EN");

	// TIMINGR bitfields.
	state->f0.fld.timingr.scll = cm_object_get_child_by_name(state->f0.reg.timingr, "SCLL");
	state->f0.fld.timingr.sclh = cm_object_get_child_by_name(state->f0.reg.timingr, "SCLH");
	state->f0.fld.timingr.sdadel = cm_object_get_child_by_name(state->f0.reg.timingr, "SDADEL");
	state->f0.fld.timingr.scldel = cm_object_get_child_by_name(state->f0.reg.timingr, "SCLDEL");
	state->f0.fld.timingr.presc = cm_object_get_child_by_name(state->f0.reg.timingr, "PRESC");

	// TIMEOUTR bitfields.
	state->f0.fld.timeoutr.timeouta = cm_object_get_child_by_name(state->f0.reg.timeoutr, "TIMEOUTA");
	state->f0.fld.timeoutr.tidle = cm_object_get_child_by_name(state->f0.reg.timeoutr, "TIDLE");
	state->f0.fld.timeoutr.timouten = cm_object_get_child_by_name(state->f0.reg.timeoutr, "TIMOUTEN");
	state->f0.fld.timeoutr.timeoutb = cm_object_get_child_by_name(state->f0.reg.timeoutr, "TIMEOUTB");
	state->f0.fld.timeoutr.texten = cm_object_get_child_by_name(state->f0.reg.timeoutr, "TEXTEN");

	// ISR bitfields.
	state->f0.fld.isr.txe = cm_object_get_child_by_name(state->f0.reg.isr, "TXE");
	state->f0.fld.isr.txis = cm_object_get_child_by_name(state->f0.reg.isr, "TXIS");
	state->f0.fld.isr.rxne = cm_object_get_child_by_name(state->f0.reg.isr, "RXNE");
	state->f0.fld.isr.addr = cm_object_get_child_by_name(state->f0.reg.isr, "ADDR");
	state->f0.fld.isr.nackf = cm_object_get_child_by_name(state->f0.reg.isr, "NACKF");
	state->f0.fld.isr.stopf = cm_object_get_child_by_name(state->f0.reg.isr, "STOPF");
	state->f0.fld.isr.tc = cm_object_get_child_by_name(state->f0.reg.isr, "TC");
	state->f0.fld.isr.tcr = cm_object_get_child_by_name(state->f0.reg.isr, "TCR");
	state->f0.fld.isr.berr = cm_object_get_child_by_name(state->f0.reg.isr, "BERR");
	state->f0.fld.isr.arlo = cm_object_get_child_by_name(state->f0.reg.isr, "ARLO");
	state->f0.fld.isr.ovr = cm_object_get_child_by_name(state->f0.reg.isr, "OVR");
	state->f0.fld.isr.pecerr = cm_object_get_child_by_name(state->f0.reg.isr, "PECERR");
	state->f0.fld.isr.timeout = cm_object_get_child_by_name(state->f0.reg.isr, "TIMEOUT");
	state->f0.fld.isr.alert = cm_object_get_child_by_name(state->f0.reg.isr, "ALERT");
	state->f0.fld.isr.busy = cm_object_get_child_by_name(state->f0.reg.isr, "BUSY");
	state->f0.fld.isr.dir = cm_object_get_child_by_name(state->f0.reg.isr, "DIR");
	state->f0.fld.isr.addcode = cm_object_get_child_by_name(state->f0.reg.isr, "ADDCODE");

	// ICR bitfields.
	state->f0.fld.icr.addrcf = cm_object_get_child_by_name(state->f0.reg.icr, "ADDRCF");
	state->f0.fld.icr.nackcf = cm_object_get_child_by_name(state->f0.reg.icr, "NACKCF");
	state->f0.fld.icr.stopcf = cm_object_get_child_by_name(state->f0.reg.icr, "STOPCF");
	state->f0.fld.icr.berrcf = cm_object_get_child_by_name(state->f0.reg.icr, "BERRCF");
	state->f0.fld.icr.arlocf = cm_object_get_child_by_name(state->f0.reg.icr, "ARLOCF");
	state->f0.fld.icr.ovrcf = cm_object_get_child_by_name(state->f0.reg.icr, "OVRCF");
	state->f0.fld.icr.peccf = cm_object_get_child_by_name(state->f0.reg.icr, "PECCF");
	state->f0.fld.icr.timoutcf = cm_object_get_child_by_name(state->f0.reg.icr, "TIMOUTCF");
	state->f0.fld.icr.alertcf = cm_object_get_child_by_name(state->f0.reg.icr, "ALERTCF");

	// PECR bitfields.
	state->f0.fld.pecr.pec = cm_object_get_child_by_name(state->f0.reg.pecr, "PEC");

	// RXDR bitfields.
	state->f0.fld.rxdr.rxdata = cm_object_get_child_by_name(state->f0.reg.rxdr, "RXDATA");

	// TXDR bitfields.
	state->f0.fld.txdr.txdata = cm_object_get_child_by_name(state->f0.reg.txdr, "TXDATA");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// IWDG (Independent watchdog) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F0 IWDG (Independent watchdog) registers.
		struct {
			Object *kr; // 0x0 Key register
			Object *pr; // 0x4 Prescaler register
			Object *rlr; // 0x8 Reload register
			Object *sr; // 0xC Status register
			Object *winr; // 0x10 Window register
		} reg;

		struct {

			// KR (Key register) bitfields.
			struct {
				Object *key; // [0:15] Key value
			} kr;

			// PR (Prescaler register) bitfields.
			struct {
				Object *pr; // [0:2] Prescaler divider
			} pr;

			// RLR (Reload register) bitfields.
			struct {
				Object *rl; // [0:11] Watchdog counter reload value
			} rlr;

			// SR (Status register) bitfields.
			struct {
				Object *pvu; // [0:0] Watchdog prescaler value update
				Object *rvu; // [1:1] Watchdog counter reload value update
				Object *wvu; // [2:2] Watchdog counter window value update
			} sr;

			// WINR (Window register) bitfields.
			struct {
				Object *win; // [0:11] Watchdog counter window value
			} winr;
		} fld;
	} f0;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32IWDGState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_iwdg_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32IWDGState *state = STM32_IWDG_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f0.reg.kr = cm_object_get_child_by_name(obj, "KR");
	state->f0.reg.pr = cm_object_get_child_by_name(obj, "PR");
	state->f0.reg.rlr = cm_object_get_child_by_name(obj, "RLR");
	state->f0.reg.sr = cm_object_get_child_by_name(obj, "SR");
	state->f0.reg.winr = cm_object_get_child_by_name(obj, "WINR");

	// KR bitfields.
	state->f0.fld.kr.key = cm_object_get_child_by_name(state->f0.reg.kr, "KEY");

	// PR bitfields.
	state->f0.fld.pr.pr = cm_object_get_child_by_name(state->f0.reg.pr, "PR");

	// RLR bitfields.
	state->f0.fld.rlr.rl = cm_object_get_child_by_name(state->f0.reg.rlr, "RL");

	// SR bitfields.
	state->f0.fld.sr.pvu = cm_object_get_child_by_name(state->f0.reg.sr, "PVU");
	state->f0.fld.sr.rvu = cm_object_get_child_by_name(state->f0.reg.sr, "RVU");
	state->f0.fld.sr.wvu = cm_object_get_child_by_name(state->f0.reg.sr, "WVU");

	// WINR bitfields.
	state->f0.fld.winr.win = cm_object_get_child_by_name(state->f0.reg.winr, "WIN");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// WWDG (Window watchdog) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F0 WWDG (Window watchdog) registers.
		struct {
			Object *cr; // 0x0 Control register
			Object *cfr; // 0x4 Configuration register
			Object *sr; // 0x8 Status register
		} reg;

		struct {

			// CR (Control register) bitfields.
			struct {
				Object *t; // [0:6] 7-bit counter
				Object *wdga; // [7:7] Activation bit
			} cr;

			// CFR (Configuration register) bitfields.
			struct {
				Object *w; // [0:6] 7-bit window value
				Object *wdgtb; // [7:8] Timer base
				Object *ewi; // [9:9] Early wakeup interrupt
			} cfr;

			// SR (Status register) bitfields.
			struct {
				Object *ewif; // [0:0] Early wakeup interrupt flag
			} sr;
		} fld;
	} f0;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32WWDGState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_wwdg_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32WWDGState *state = STM32_WWDG_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f0.reg.cr = cm_object_get_child_by_name(obj, "CR");
	state->f0.reg.cfr = cm_object_get_child_by_name(obj, "CFR");
	state->f0.reg.sr = cm_object_get_child_by_name(obj, "SR");

	// CR bitfields.
	state->f0.fld.cr.t = cm_object_get_child_by_name(state->f0.reg.cr, "T");
	state->f0.fld.cr.wdga = cm_object_get_child_by_name(state->f0.reg.cr, "WDGA");

	// CFR bitfields.
	state->f0.fld.cfr.w = cm_object_get_child_by_name(state->f0.reg.cfr, "W");
	state->f0.fld.cfr.wdgtb = cm_object_get_child_by_name(state->f0.reg.cfr, "WDGTB");
	state->f0.fld.cfr.ewi = cm_object_get_child_by_name(state->f0.reg.cfr, "EWI");

	// SR bitfields.
	state->f0.fld.sr.ewif = cm_object_get_child_by_name(state->f0.reg.sr, "EWIF");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// TIM1 (Advanced-timers) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F0 TIM1 (Advanced-timers) registers.
		struct {
			Object *cr1; // 0x0 Control register 1
			Object *cr2; // 0x4 Control register 2
			Object *smcr; // 0x8 Slave mode control register
			Object *dier; // 0xC DMA/Interrupt enable register
			Object *sr; // 0x10 Status register
			Object *egr; // 0x14 Event generation register
			Object *ccmr1_output; // 0x18 Capture/compare mode register (output mode)
			Object *ccmr1_input; // 0x18 Capture/compare mode register 1 (input mode)
			Object *ccmr2_output; // 0x1C Capture/compare mode register (output mode)
			Object *ccmr2_input; // 0x1C Capture/compare mode register 2 (input mode)
			Object *ccer; // 0x20 Capture/compare enable register
			Object *cnt; // 0x24 Counter
			Object *psc; // 0x28 Prescaler
			Object *arr; // 0x2C Auto-reload register
			Object *rcr; // 0x30 Repetition counter register
			Object *ccr1; // 0x34 Capture/compare register 1
			Object *ccr2; // 0x38 Capture/compare register 2
			Object *ccr3; // 0x3C Capture/compare register 3
			Object *ccr4; // 0x40 Capture/compare register 4
			Object *bdtr; // 0x44 Break and dead-time register
			Object *dcr; // 0x48 DMA control register
			Object *dmar; // 0x4C DMA address for full transfer
		} reg;

		struct {

			// CR1 (Control register 1) bitfields.
			struct {
				Object *cen; // [0:0] Counter enable
				Object *udis; // [1:1] Update disable
				Object *urs; // [2:2] Update request source
				Object *opm; // [3:3] One-pulse mode
				Object *dir; // [4:4] Direction
				Object *cms; // [5:6] Center-aligned mode selection
				Object *arpe; // [7:7] Auto-reload preload enable
				Object *ckd; // [8:9] Clock division
			} cr1;

			// CR2 (Control register 2) bitfields.
			struct {
				Object *ccpc; // [0:0] Capture/compare preloaded control
				Object *ccus; // [2:2] Capture/compare control update selection
				Object *ccds; // [3:3] Capture/compare DMA selection
				Object *mms; // [4:6] Master mode selection
				Object *ti1s; // [7:7] TI1 selection
				Object *ois1; // [8:8] Output Idle state 1
				Object *ois1n; // [9:9] Output Idle state 1
				Object *ois2; // [10:10] Output Idle state 2
				Object *ois2n; // [11:11] Output Idle state 2
				Object *ois3; // [12:12] Output Idle state 3
				Object *ois3n; // [13:13] Output Idle state 3
				Object *ois4; // [14:14] Output Idle state 4
			} cr2;

			// SMCR (Slave mode control register) bitfields.
			struct {
				Object *sms; // [0:2] Slave mode selection
				Object *ts; // [4:6] Trigger selection
				Object *msm; // [7:7] Master/Slave mode
				Object *etf; // [8:11] External trigger filter
				Object *etps; // [12:13] External trigger prescaler
				Object *ece; // [14:14] External clock enable
				Object *etp; // [15:15] External trigger polarity
			} smcr;

			// DIER (DMA/Interrupt enable register) bitfields.
			struct {
				Object *uie; // [0:0] Update interrupt enable
				Object *cc1ie; // [1:1] Capture/Compare 1 interrupt enable
				Object *cc2ie; // [2:2] Capture/Compare 2 interrupt enable
				Object *cc3ie; // [3:3] Capture/Compare 3 interrupt enable
				Object *cc4ie; // [4:4] Capture/Compare 4 interrupt enable
				Object *comie; // [5:5] COM interrupt enable
				Object *tie; // [6:6] Trigger interrupt enable
				Object *bie; // [7:7] Break interrupt enable
				Object *ude; // [8:8] Update DMA request enable
				Object *cc1de; // [9:9] Capture/Compare 1 DMA request enable
				Object *cc2de; // [10:10] Capture/Compare 2 DMA request enable
				Object *cc3de; // [11:11] Capture/Compare 3 DMA request enable
				Object *cc4de; // [12:12] Capture/Compare 4 DMA request enable
				Object *comde; // [13:13] Reserved
				Object *tde; // [14:14] Trigger DMA request enable
			} dier;

			// SR (Status register) bitfields.
			struct {
				Object *uif; // [0:0] Update interrupt flag
				Object *cc1if; // [1:1] Capture/compare 1 interrupt flag
				Object *cc2if; // [2:2] Capture/Compare 2 interrupt flag
				Object *cc3if; // [3:3] Capture/Compare 3 interrupt flag
				Object *cc4if; // [4:4] Capture/Compare 4 interrupt flag
				Object *comif; // [5:5] COM interrupt flag
				Object *tif; // [6:6] Trigger interrupt flag
				Object *bif; // [7:7] Break interrupt flag
				Object *cc1of; // [9:9] Capture/Compare 1 overcapture flag
				Object *cc2of; // [10:10] Capture/compare 2 overcapture flag
				Object *cc3of; // [11:11] Capture/Compare 3 overcapture flag
				Object *cc4of; // [12:12] Capture/Compare 4 overcapture flag
			} sr;

			// EGR (Event generation register) bitfields.
			struct {
				Object *ug; // [0:0] Update generation
				Object *cc1g; // [1:1] Capture/compare 1 generation
				Object *cc2g; // [2:2] Capture/compare 2 generation
				Object *cc3g; // [3:3] Capture/compare 3 generation
				Object *cc4g; // [4:4] Capture/compare 4 generation
				Object *comg; // [5:5] Capture/Compare control update generation
				Object *tg; // [6:6] Trigger generation
				Object *bg; // [7:7] Break generation
			} egr;

			// CCMR1_Output (Capture/compare mode register (output mode)) bitfields.
			struct {
				Object *cc1s; // [0:1] Capture/Compare 1 selection
				Object *oc1fe; // [2:2] Output Compare 1 fast enable
				Object *oc1pe; // [3:3] Output Compare 1 preload enable
				Object *oc1m; // [4:6] Output Compare 1 mode
				Object *oc1ce; // [7:7] Output Compare 1 clear enable
				Object *cc2s; // [8:9] Capture/Compare 2 selection
				Object *oc2fe; // [10:10] Output Compare 2 fast enable
				Object *oc2pe; // [11:11] Output Compare 2 preload enable
				Object *oc2m; // [12:14] Output Compare 2 mode
				Object *oc2ce; // [15:15] Output Compare 2 clear enable
			} ccmr1_output;

			// CCMR1_Input (Capture/compare mode register 1 (input mode)) bitfields.
			struct {
				Object *cc1s; // [0:1] Capture/Compare 1 selection
				Object *ic1pcs; // [2:3] Input capture 1 prescaler
				Object *ic1f; // [4:7] Input capture 1 filter
				Object *cc2s; // [8:9] Capture/Compare 2 selection
				Object *ic2pcs; // [10:11] Input capture 2 prescaler
				Object *ic2f; // [12:15] Input capture 2 filter
			} ccmr1_input;

			// CCMR2_Output (Capture/compare mode register (output mode)) bitfields.
			struct {
				Object *cc3s; // [0:1] Capture/Compare 3 selection
				Object *oc3fe; // [2:2] Output compare 3 fast enable
				Object *oc3pe; // [3:3] Output compare 3 preload enable
				Object *oc3m; // [4:6] Output compare 3 mode
				Object *oc3ce; // [7:7] Output compare 3 clear enable
				Object *cc4s; // [8:9] Capture/Compare 4 selection
				Object *oc4fe; // [10:10] Output compare 4 fast enable
				Object *oc4pe; // [11:11] Output compare 4 preload enable
				Object *oc4m; // [12:14] Output compare 4 mode
				Object *oc4ce; // [15:15] Output compare 4 clear enable
			} ccmr2_output;

			// CCMR2_Input (Capture/compare mode register 2 (input mode)) bitfields.
			struct {
				Object *cc3s; // [0:1] Capture/compare 3 selection
				Object *ic3psc; // [2:3] Input capture 3 prescaler
				Object *ic3f; // [4:7] Input capture 3 filter
				Object *cc4s; // [8:9] Capture/Compare 4 selection
				Object *ic4psc; // [10:11] Input capture 4 prescaler
				Object *ic4f; // [12:15] Input capture 4 filter
			} ccmr2_input;

			// CCER (Capture/compare enable register) bitfields.
			struct {
				Object *cc1e; // [0:0] Capture/Compare 1 output enable
				Object *cc1p; // [1:1] Capture/Compare 1 output Polarity
				Object *cc1ne; // [2:2] Capture/Compare 1 complementary output enable
				Object *cc1np; // [3:3] Capture/Compare 1 output Polarity
				Object *cc2e; // [4:4] Capture/Compare 2 output enable
				Object *cc2p; // [5:5] Capture/Compare 2 output Polarity
				Object *cc2ne; // [6:6] Capture/Compare 2 complementary output enable
				Object *cc2np; // [7:7] Capture/Compare 2 output Polarity
				Object *cc3e; // [8:8] Capture/Compare 3 output enable
				Object *cc3p; // [9:9] Capture/Compare 3 output Polarity
				Object *cc3ne; // [10:10] Capture/Compare 3 complementary output enable
				Object *cc3np; // [11:11] Capture/Compare 3 output Polarity
				Object *cc4e; // [12:12] Capture/Compare 4 output enable
				Object *cc4p; // [13:13] Capture/Compare 3 output Polarity
			} ccer;

			// CNT (Counter) bitfields.
			struct {
				Object *cnt; // [0:15] Counter value
			} cnt;

			// PSC (Prescaler) bitfields.
			struct {
				Object *psc; // [0:15] Prescaler value
			} psc;

			// ARR (Auto-reload register) bitfields.
			struct {
				Object *arr; // [0:15] Auto-reload value
			} arr;

			// RCR (Repetition counter register) bitfields.
			struct {
				Object *rep; // [0:7] Repetition counter value
			} rcr;

			// CCR1 (Capture/compare register 1) bitfields.
			struct {
				Object *ccr1; // [0:15] Capture/Compare 1 value
			} ccr1;

			// CCR2 (Capture/compare register 2) bitfields.
			struct {
				Object *ccr2; // [0:15] Capture/Compare 2 value
			} ccr2;

			// CCR3 (Capture/compare register 3) bitfields.
			struct {
				Object *ccr3; // [0:15] Capture/Compare 3 value
			} ccr3;

			// CCR4 (Capture/compare register 4) bitfields.
			struct {
				Object *ccr4; // [0:15] Capture/Compare 3 value
			} ccr4;

			// BDTR (Break and dead-time register) bitfields.
			struct {
				Object *dtg; // [0:7] Dead-time generator setup
				Object *lock; // [8:9] Lock configuration
				Object *ossi; // [10:10] Off-state selection for Idle mode
				Object *ossr; // [11:11] Off-state selection for Run mode
				Object *bke; // [12:12] Break enable
				Object *bkp; // [13:13] Break polarity
				Object *aoe; // [14:14] Automatic output enable
				Object *moe; // [15:15] Main output enable
			} bdtr;

			// DCR (DMA control register) bitfields.
			struct {
				Object *dba; // [0:4] DMA base address
				Object *dbl; // [8:12] DMA burst length
			} dcr;

			// DMAR (DMA address for full transfer) bitfields.
			struct {
				Object *dmab; // [0:15] DMA register for burst accesses
			} dmar;
		} fld;
	} f0;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32TIM1State;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_tim1_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32TIM1State *state = STM32_TIM1_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f0.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
	state->f0.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
	state->f0.reg.smcr = cm_object_get_child_by_name(obj, "SMCR");
	state->f0.reg.dier = cm_object_get_child_by_name(obj, "DIER");
	state->f0.reg.sr = cm_object_get_child_by_name(obj, "SR");
	state->f0.reg.egr = cm_object_get_child_by_name(obj, "EGR");
	state->f0.reg.ccmr1_output = cm_object_get_child_by_name(obj, "CCMR1_Output");
	state->f0.reg.ccmr1_input = cm_object_get_child_by_name(obj, "CCMR1_Input");
	state->f0.reg.ccmr2_output = cm_object_get_child_by_name(obj, "CCMR2_Output");
	state->f0.reg.ccmr2_input = cm_object_get_child_by_name(obj, "CCMR2_Input");
	state->f0.reg.ccer = cm_object_get_child_by_name(obj, "CCER");
	state->f0.reg.cnt = cm_object_get_child_by_name(obj, "CNT");
	state->f0.reg.psc = cm_object_get_child_by_name(obj, "PSC");
	state->f0.reg.arr = cm_object_get_child_by_name(obj, "ARR");
	state->f0.reg.rcr = cm_object_get_child_by_name(obj, "RCR");
	state->f0.reg.ccr1 = cm_object_get_child_by_name(obj, "CCR1");
	state->f0.reg.ccr2 = cm_object_get_child_by_name(obj, "CCR2");
	state->f0.reg.ccr3 = cm_object_get_child_by_name(obj, "CCR3");
	state->f0.reg.ccr4 = cm_object_get_child_by_name(obj, "CCR4");
	state->f0.reg.bdtr = cm_object_get_child_by_name(obj, "BDTR");
	state->f0.reg.dcr = cm_object_get_child_by_name(obj, "DCR");
	state->f0.reg.dmar = cm_object_get_child_by_name(obj, "DMAR");

	// CR1 bitfields.
	state->f0.fld.cr1.cen = cm_object_get_child_by_name(state->f0.reg.cr1, "CEN");
	state->f0.fld.cr1.udis = cm_object_get_child_by_name(state->f0.reg.cr1, "UDIS");
	state->f0.fld.cr1.urs = cm_object_get_child_by_name(state->f0.reg.cr1, "URS");
	state->f0.fld.cr1.opm = cm_object_get_child_by_name(state->f0.reg.cr1, "OPM");
	state->f0.fld.cr1.dir = cm_object_get_child_by_name(state->f0.reg.cr1, "DIR");
	state->f0.fld.cr1.cms = cm_object_get_child_by_name(state->f0.reg.cr1, "CMS");
	state->f0.fld.cr1.arpe = cm_object_get_child_by_name(state->f0.reg.cr1, "ARPE");
	state->f0.fld.cr1.ckd = cm_object_get_child_by_name(state->f0.reg.cr1, "CKD");

	// CR2 bitfields.
	state->f0.fld.cr2.ccpc = cm_object_get_child_by_name(state->f0.reg.cr2, "CCPC");
	state->f0.fld.cr2.ccus = cm_object_get_child_by_name(state->f0.reg.cr2, "CCUS");
	state->f0.fld.cr2.ccds = cm_object_get_child_by_name(state->f0.reg.cr2, "CCDS");
	state->f0.fld.cr2.mms = cm_object_get_child_by_name(state->f0.reg.cr2, "MMS");
	state->f0.fld.cr2.ti1s = cm_object_get_child_by_name(state->f0.reg.cr2, "TI1S");
	state->f0.fld.cr2.ois1 = cm_object_get_child_by_name(state->f0.reg.cr2, "OIS1");
	state->f0.fld.cr2.ois1n = cm_object_get_child_by_name(state->f0.reg.cr2, "OIS1N");
	state->f0.fld.cr2.ois2 = cm_object_get_child_by_name(state->f0.reg.cr2, "OIS2");
	state->f0.fld.cr2.ois2n = cm_object_get_child_by_name(state->f0.reg.cr2, "OIS2N");
	state->f0.fld.cr2.ois3 = cm_object_get_child_by_name(state->f0.reg.cr2, "OIS3");
	state->f0.fld.cr2.ois3n = cm_object_get_child_by_name(state->f0.reg.cr2, "OIS3N");
	state->f0.fld.cr2.ois4 = cm_object_get_child_by_name(state->f0.reg.cr2, "OIS4");

	// SMCR bitfields.
	state->f0.fld.smcr.sms = cm_object_get_child_by_name(state->f0.reg.smcr, "SMS");
	state->f0.fld.smcr.ts = cm_object_get_child_by_name(state->f0.reg.smcr, "TS");
	state->f0.fld.smcr.msm = cm_object_get_child_by_name(state->f0.reg.smcr, "MSM");
	state->f0.fld.smcr.etf = cm_object_get_child_by_name(state->f0.reg.smcr, "ETF");
	state->f0.fld.smcr.etps = cm_object_get_child_by_name(state->f0.reg.smcr, "ETPS");
	state->f0.fld.smcr.ece = cm_object_get_child_by_name(state->f0.reg.smcr, "ECE");
	state->f0.fld.smcr.etp = cm_object_get_child_by_name(state->f0.reg.smcr, "ETP");

	// DIER bitfields.
	state->f0.fld.dier.uie = cm_object_get_child_by_name(state->f0.reg.dier, "UIE");
	state->f0.fld.dier.cc1ie = cm_object_get_child_by_name(state->f0.reg.dier, "CC1IE");
	state->f0.fld.dier.cc2ie = cm_object_get_child_by_name(state->f0.reg.dier, "CC2IE");
	state->f0.fld.dier.cc3ie = cm_object_get_child_by_name(state->f0.reg.dier, "CC3IE");
	state->f0.fld.dier.cc4ie = cm_object_get_child_by_name(state->f0.reg.dier, "CC4IE");
	state->f0.fld.dier.comie = cm_object_get_child_by_name(state->f0.reg.dier, "COMIE");
	state->f0.fld.dier.tie = cm_object_get_child_by_name(state->f0.reg.dier, "TIE");
	state->f0.fld.dier.bie = cm_object_get_child_by_name(state->f0.reg.dier, "BIE");
	state->f0.fld.dier.ude = cm_object_get_child_by_name(state->f0.reg.dier, "UDE");
	state->f0.fld.dier.cc1de = cm_object_get_child_by_name(state->f0.reg.dier, "CC1DE");
	state->f0.fld.dier.cc2de = cm_object_get_child_by_name(state->f0.reg.dier, "CC2DE");
	state->f0.fld.dier.cc3de = cm_object_get_child_by_name(state->f0.reg.dier, "CC3DE");
	state->f0.fld.dier.cc4de = cm_object_get_child_by_name(state->f0.reg.dier, "CC4DE");
	state->f0.fld.dier.comde = cm_object_get_child_by_name(state->f0.reg.dier, "COMDE");
	state->f0.fld.dier.tde = cm_object_get_child_by_name(state->f0.reg.dier, "TDE");

	// SR bitfields.
	state->f0.fld.sr.uif = cm_object_get_child_by_name(state->f0.reg.sr, "UIF");
	state->f0.fld.sr.cc1if = cm_object_get_child_by_name(state->f0.reg.sr, "CC1IF");
	state->f0.fld.sr.cc2if = cm_object_get_child_by_name(state->f0.reg.sr, "CC2IF");
	state->f0.fld.sr.cc3if = cm_object_get_child_by_name(state->f0.reg.sr, "CC3IF");
	state->f0.fld.sr.cc4if = cm_object_get_child_by_name(state->f0.reg.sr, "CC4IF");
	state->f0.fld.sr.comif = cm_object_get_child_by_name(state->f0.reg.sr, "COMIF");
	state->f0.fld.sr.tif = cm_object_get_child_by_name(state->f0.reg.sr, "TIF");
	state->f0.fld.sr.bif = cm_object_get_child_by_name(state->f0.reg.sr, "BIF");
	state->f0.fld.sr.cc1of = cm_object_get_child_by_name(state->f0.reg.sr, "CC1OF");
	state->f0.fld.sr.cc2of = cm_object_get_child_by_name(state->f0.reg.sr, "CC2OF");
	state->f0.fld.sr.cc3of = cm_object_get_child_by_name(state->f0.reg.sr, "CC3OF");
	state->f0.fld.sr.cc4of = cm_object_get_child_by_name(state->f0.reg.sr, "CC4OF");

	// EGR bitfields.
	state->f0.fld.egr.ug = cm_object_get_child_by_name(state->f0.reg.egr, "UG");
	state->f0.fld.egr.cc1g = cm_object_get_child_by_name(state->f0.reg.egr, "CC1G");
	state->f0.fld.egr.cc2g = cm_object_get_child_by_name(state->f0.reg.egr, "CC2G");
	state->f0.fld.egr.cc3g = cm_object_get_child_by_name(state->f0.reg.egr, "CC3G");
	state->f0.fld.egr.cc4g = cm_object_get_child_by_name(state->f0.reg.egr, "CC4G");
	state->f0.fld.egr.comg = cm_object_get_child_by_name(state->f0.reg.egr, "COMG");
	state->f0.fld.egr.tg = cm_object_get_child_by_name(state->f0.reg.egr, "TG");
	state->f0.fld.egr.bg = cm_object_get_child_by_name(state->f0.reg.egr, "BG");

	// CCMR1_Output bitfields.
	state->f0.fld.ccmr1_output.cc1s = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "CC1S");
	state->f0.fld.ccmr1_output.oc1fe = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "OC1FE");
	state->f0.fld.ccmr1_output.oc1pe = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "OC1PE");
	state->f0.fld.ccmr1_output.oc1m = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "OC1M");
	state->f0.fld.ccmr1_output.oc1ce = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "OC1CE");
	state->f0.fld.ccmr1_output.cc2s = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "CC2S");
	state->f0.fld.ccmr1_output.oc2fe = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "OC2FE");
	state->f0.fld.ccmr1_output.oc2pe = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "OC2PE");
	state->f0.fld.ccmr1_output.oc2m = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "OC2M");
	state->f0.fld.ccmr1_output.oc2ce = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "OC2CE");

	// CCMR1_Input bitfields.
	state->f0.fld.ccmr1_input.cc1s = cm_object_get_child_by_name(state->f0.reg.ccmr1_input, "CC1S");
	state->f0.fld.ccmr1_input.ic1pcs = cm_object_get_child_by_name(state->f0.reg.ccmr1_input, "IC1PCS");
	state->f0.fld.ccmr1_input.ic1f = cm_object_get_child_by_name(state->f0.reg.ccmr1_input, "IC1F");
	state->f0.fld.ccmr1_input.cc2s = cm_object_get_child_by_name(state->f0.reg.ccmr1_input, "CC2S");
	state->f0.fld.ccmr1_input.ic2pcs = cm_object_get_child_by_name(state->f0.reg.ccmr1_input, "IC2PCS");
	state->f0.fld.ccmr1_input.ic2f = cm_object_get_child_by_name(state->f0.reg.ccmr1_input, "IC2F");

	// CCMR2_Output bitfields.
	state->f0.fld.ccmr2_output.cc3s = cm_object_get_child_by_name(state->f0.reg.ccmr2_output, "CC3S");
	state->f0.fld.ccmr2_output.oc3fe = cm_object_get_child_by_name(state->f0.reg.ccmr2_output, "OC3FE");
	state->f0.fld.ccmr2_output.oc3pe = cm_object_get_child_by_name(state->f0.reg.ccmr2_output, "OC3PE");
	state->f0.fld.ccmr2_output.oc3m = cm_object_get_child_by_name(state->f0.reg.ccmr2_output, "OC3M");
	state->f0.fld.ccmr2_output.oc3ce = cm_object_get_child_by_name(state->f0.reg.ccmr2_output, "OC3CE");
	state->f0.fld.ccmr2_output.cc4s = cm_object_get_child_by_name(state->f0.reg.ccmr2_output, "CC4S");
	state->f0.fld.ccmr2_output.oc4fe = cm_object_get_child_by_name(state->f0.reg.ccmr2_output, "OC4FE");
	state->f0.fld.ccmr2_output.oc4pe = cm_object_get_child_by_name(state->f0.reg.ccmr2_output, "OC4PE");
	state->f0.fld.ccmr2_output.oc4m = cm_object_get_child_by_name(state->f0.reg.ccmr2_output, "OC4M");
	state->f0.fld.ccmr2_output.oc4ce = cm_object_get_child_by_name(state->f0.reg.ccmr2_output, "OC4CE");

	// CCMR2_Input bitfields.
	state->f0.fld.ccmr2_input.cc3s = cm_object_get_child_by_name(state->f0.reg.ccmr2_input, "CC3S");
	state->f0.fld.ccmr2_input.ic3psc = cm_object_get_child_by_name(state->f0.reg.ccmr2_input, "IC3PSC");
	state->f0.fld.ccmr2_input.ic3f = cm_object_get_child_by_name(state->f0.reg.ccmr2_input, "IC3F");
	state->f0.fld.ccmr2_input.cc4s = cm_object_get_child_by_name(state->f0.reg.ccmr2_input, "CC4S");
	state->f0.fld.ccmr2_input.ic4psc = cm_object_get_child_by_name(state->f0.reg.ccmr2_input, "IC4PSC");
	state->f0.fld.ccmr2_input.ic4f = cm_object_get_child_by_name(state->f0.reg.ccmr2_input, "IC4F");

	// CCER bitfields.
	state->f0.fld.ccer.cc1e = cm_object_get_child_by_name(state->f0.reg.ccer, "CC1E");
	state->f0.fld.ccer.cc1p = cm_object_get_child_by_name(state->f0.reg.ccer, "CC1P");
	state->f0.fld.ccer.cc1ne = cm_object_get_child_by_name(state->f0.reg.ccer, "CC1NE");
	state->f0.fld.ccer.cc1np = cm_object_get_child_by_name(state->f0.reg.ccer, "CC1NP");
	state->f0.fld.ccer.cc2e = cm_object_get_child_by_name(state->f0.reg.ccer, "CC2E");
	state->f0.fld.ccer.cc2p = cm_object_get_child_by_name(state->f0.reg.ccer, "CC2P");
	state->f0.fld.ccer.cc2ne = cm_object_get_child_by_name(state->f0.reg.ccer, "CC2NE");
	state->f0.fld.ccer.cc2np = cm_object_get_child_by_name(state->f0.reg.ccer, "CC2NP");
	state->f0.fld.ccer.cc3e = cm_object_get_child_by_name(state->f0.reg.ccer, "CC3E");
	state->f0.fld.ccer.cc3p = cm_object_get_child_by_name(state->f0.reg.ccer, "CC3P");
	state->f0.fld.ccer.cc3ne = cm_object_get_child_by_name(state->f0.reg.ccer, "CC3NE");
	state->f0.fld.ccer.cc3np = cm_object_get_child_by_name(state->f0.reg.ccer, "CC3NP");
	state->f0.fld.ccer.cc4e = cm_object_get_child_by_name(state->f0.reg.ccer, "CC4E");
	state->f0.fld.ccer.cc4p = cm_object_get_child_by_name(state->f0.reg.ccer, "CC4P");

	// CNT bitfields.
	state->f0.fld.cnt.cnt = cm_object_get_child_by_name(state->f0.reg.cnt, "CNT");

	// PSC bitfields.
	state->f0.fld.psc.psc = cm_object_get_child_by_name(state->f0.reg.psc, "PSC");

	// ARR bitfields.
	state->f0.fld.arr.arr = cm_object_get_child_by_name(state->f0.reg.arr, "ARR");

	// RCR bitfields.
	state->f0.fld.rcr.rep = cm_object_get_child_by_name(state->f0.reg.rcr, "REP");

	// CCR1 bitfields.
	state->f0.fld.ccr1.ccr1 = cm_object_get_child_by_name(state->f0.reg.ccr1, "CCR1");

	// CCR2 bitfields.
	state->f0.fld.ccr2.ccr2 = cm_object_get_child_by_name(state->f0.reg.ccr2, "CCR2");

	// CCR3 bitfields.
	state->f0.fld.ccr3.ccr3 = cm_object_get_child_by_name(state->f0.reg.ccr3, "CCR3");

	// CCR4 bitfields.
	state->f0.fld.ccr4.ccr4 = cm_object_get_child_by_name(state->f0.reg.ccr4, "CCR4");

	// BDTR bitfields.
	state->f0.fld.bdtr.dtg = cm_object_get_child_by_name(state->f0.reg.bdtr, "DTG");
	state->f0.fld.bdtr.lock = cm_object_get_child_by_name(state->f0.reg.bdtr, "LOCK");
	state->f0.fld.bdtr.ossi = cm_object_get_child_by_name(state->f0.reg.bdtr, "OSSI");
	state->f0.fld.bdtr.ossr = cm_object_get_child_by_name(state->f0.reg.bdtr, "OSSR");
	state->f0.fld.bdtr.bke = cm_object_get_child_by_name(state->f0.reg.bdtr, "BKE");
	state->f0.fld.bdtr.bkp = cm_object_get_child_by_name(state->f0.reg.bdtr, "BKP");
	state->f0.fld.bdtr.aoe = cm_object_get_child_by_name(state->f0.reg.bdtr, "AOE");
	state->f0.fld.bdtr.moe = cm_object_get_child_by_name(state->f0.reg.bdtr, "MOE");

	// DCR bitfields.
	state->f0.fld.dcr.dba = cm_object_get_child_by_name(state->f0.reg.dcr, "DBA");
	state->f0.fld.dcr.dbl = cm_object_get_child_by_name(state->f0.reg.dcr, "DBL");

	// DMAR bitfields.
	state->f0.fld.dmar.dmab = cm_object_get_child_by_name(state->f0.reg.dmar, "DMAB");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// TIM2 (General-purpose-timers) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F0 TIM2 (General-purpose-timers) registers.
		struct {
			Object *cr1; // 0x0 Control register 1
			Object *cr2; // 0x4 Control register 2
			Object *smcr; // 0x8 Slave mode control register
			Object *dier; // 0xC DMA/Interrupt enable register
			Object *sr; // 0x10 Status register
			Object *egr; // 0x14 Event generation register
			Object *ccmr1_output; // 0x18 Capture/compare mode register 1 (output mode)
			Object *ccmr1_input; // 0x18 Capture/compare mode register 1 (input mode)
			Object *ccmr2_output; // 0x1C Capture/compare mode register 2 (output mode)
			Object *ccmr2_input; // 0x1C Capture/compare mode register 2 (input mode)
			Object *ccer; // 0x20 Capture/compare enable register
			Object *cnt; // 0x24 Counter
			Object *psc; // 0x28 Prescaler
			Object *arr; // 0x2C Auto-reload register
			Object *ccr1; // 0x34 Capture/compare register 1
			Object *ccr2; // 0x38 Capture/compare register 2
			Object *ccr3; // 0x3C Capture/compare register 3
			Object *ccr4; // 0x40 Capture/compare register 4
			Object *dcr; // 0x48 DMA control register
			Object *dmar; // 0x4C DMA address for full transfer
		} reg;

		struct {

			// CR1 (Control register 1) bitfields.
			struct {
				Object *cen; // [0:0] Counter enable
				Object *udis; // [1:1] Update disable
				Object *urs; // [2:2] Update request source
				Object *opm; // [3:3] One-pulse mode
				Object *dir; // [4:4] Direction
				Object *cms; // [5:6] Center-aligned mode selection
				Object *arpe; // [7:7] Auto-reload preload enable
				Object *ckd; // [8:9] Clock division
			} cr1;

			// CR2 (Control register 2) bitfields.
			struct {
				Object *ccds; // [3:3] Capture/compare DMA selection
				Object *mms; // [4:6] Master mode selection
				Object *ti1s; // [7:7] TI1 selection
			} cr2;

			// SMCR (Slave mode control register) bitfields.
			struct {
				Object *sms; // [0:2] Slave mode selection
				Object *ts; // [4:6] Trigger selection
				Object *msm; // [7:7] Master/Slave mode
				Object *etf; // [8:11] External trigger filter
				Object *etps; // [12:13] External trigger prescaler
				Object *ece; // [14:14] External clock enable
				Object *etp; // [15:15] External trigger polarity
			} smcr;

			// DIER (DMA/Interrupt enable register) bitfields.
			struct {
				Object *uie; // [0:0] Update interrupt enable
				Object *cc1ie; // [1:1] Capture/Compare 1 interrupt enable
				Object *cc2ie; // [2:2] Capture/Compare 2 interrupt enable
				Object *cc3ie; // [3:3] Capture/Compare 3 interrupt enable
				Object *cc4ie; // [4:4] Capture/Compare 4 interrupt enable
				Object *tie; // [6:6] Trigger interrupt enable
				Object *ude; // [8:8] Update DMA request enable
				Object *cc1de; // [9:9] Capture/Compare 1 DMA request enable
				Object *cc2de; // [10:10] Capture/Compare 2 DMA request enable
				Object *cc3de; // [11:11] Capture/Compare 3 DMA request enable
				Object *cc4de; // [12:12] Capture/Compare 4 DMA request enable
				Object *comde; // [13:13] Reserved
				Object *tde; // [14:14] Trigger DMA request enable
			} dier;

			// SR (Status register) bitfields.
			struct {
				Object *uif; // [0:0] Update interrupt flag
				Object *cc1if; // [1:1] Capture/compare 1 interrupt flag
				Object *cc2if; // [2:2] Capture/Compare 2 interrupt flag
				Object *cc3if; // [3:3] Capture/Compare 3 interrupt flag
				Object *cc4if; // [4:4] Capture/Compare 4 interrupt flag
				Object *tif; // [6:6] Trigger interrupt flag
				Object *cc1of; // [9:9] Capture/Compare 1 overcapture flag
				Object *cc2of; // [10:10] Capture/compare 2 overcapture flag
				Object *cc3of; // [11:11] Capture/Compare 3 overcapture flag
				Object *cc4of; // [12:12] Capture/Compare 4 overcapture flag
			} sr;

			// EGR (Event generation register) bitfields.
			struct {
				Object *ug; // [0:0] Update generation
				Object *cc1g; // [1:1] Capture/compare 1 generation
				Object *cc2g; // [2:2] Capture/compare 2 generation
				Object *cc3g; // [3:3] Capture/compare 3 generation
				Object *cc4g; // [4:4] Capture/compare 4 generation
				Object *tg; // [6:6] Trigger generation
			} egr;

			// CCMR1_Output (Capture/compare mode register 1 (output mode)) bitfields.
			struct {
				Object *cc1s; // [0:1] Capture/Compare 1 selection
				Object *oc1fe; // [2:2] Output compare 1 fast enable
				Object *oc1pe; // [3:3] Output compare 1 preload enable
				Object *oc1m; // [4:6] Output compare 1 mode
				Object *oc1ce; // [7:7] Output compare 1 clear enable
				Object *cc2s; // [8:9] Capture/Compare 2 selection
				Object *oc2fe; // [10:10] Output compare 2 fast enable
				Object *oc2pe; // [11:11] Output compare 2 preload enable
				Object *oc2m; // [12:14] Output compare 2 mode
				Object *oc2ce; // [15:15] Output compare 2 clear enable
			} ccmr1_output;

			// CCMR1_Input (Capture/compare mode register 1 (input mode)) bitfields.
			struct {
				Object *cc1s; // [0:1] Capture/Compare 1 selection
				Object *ic1psc; // [2:3] Input capture 1 prescaler
				Object *ic1f; // [4:7] Input capture 1 filter
				Object *cc2s; // [8:9] Capture/compare 2 selection
				Object *ic2psc; // [10:11] Input capture 2 prescaler
				Object *ic2f; // [12:15] Input capture 2 filter
			} ccmr1_input;

			// CCMR2_Output (Capture/compare mode register 2 (output mode)) bitfields.
			struct {
				Object *cc3s; // [0:1] Capture/Compare 3 selection
				Object *oc3fe; // [2:2] Output compare 3 fast enable
				Object *oc3pe; // [3:3] Output compare 3 preload enable
				Object *oc3m; // [4:6] Output compare 3 mode
				Object *oc3ce; // [7:7] Output compare 3 clear enable
				Object *cc4s; // [8:9] Capture/Compare 4 selection
				Object *oc4fe; // [10:10] Output compare 4 fast enable
				Object *oc4pe; // [11:11] Output compare 4 preload enable
				Object *oc4m; // [12:14] Output compare 4 mode
				Object *oc4ce; // [15:15] Output compare 4 clear enable
			} ccmr2_output;

			// CCMR2_Input (Capture/compare mode register 2 (input mode)) bitfields.
			struct {
				Object *cc3s; // [0:1] Capture/Compare 3 selection
				Object *ic3psc; // [2:3] Input capture 3 prescaler
				Object *ic3f; // [4:7] Input capture 3 filter
				Object *cc4s; // [8:9] Capture/Compare 4 selection
				Object *ic4psc; // [10:11] Input capture 4 prescaler
				Object *ic4f; // [12:15] Input capture 4 filter
			} ccmr2_input;

			// CCER (Capture/compare enable register) bitfields.
			struct {
				Object *cc1e; // [0:0] Capture/Compare 1 output enable
				Object *cc1p; // [1:1] Capture/Compare 1 output Polarity
				Object *cc1np; // [3:3] Capture/Compare 1 output Polarity
				Object *cc2e; // [4:4] Capture/Compare 2 output enable
				Object *cc2p; // [5:5] Capture/Compare 2 output Polarity
				Object *cc2np; // [7:7] Capture/Compare 2 output Polarity
				Object *cc3e; // [8:8] Capture/Compare 3 output enable
				Object *cc3p; // [9:9] Capture/Compare 3 output Polarity
				Object *cc3np; // [11:11] Capture/Compare 3 output Polarity
				Object *cc4e; // [12:12] Capture/Compare 4 output enable
				Object *cc4p; // [13:13] Capture/Compare 3 output Polarity
				Object *cc4np; // [15:15] Capture/Compare 4 output Polarity
			} ccer;

			// CNT (Counter) bitfields.
			struct {
				Object *cnt_l; // [0:15] Low counter value
				Object *cnt_h; // [16:31] High counter value (TIM2 only)
			} cnt;

			// PSC (Prescaler) bitfields.
			struct {
				Object *psc; // [0:15] Prescaler value
			} psc;

			// ARR (Auto-reload register) bitfields.
			struct {
				Object *arr_l; // [0:15] Low Auto-reload value
				Object *arr_h; // [16:31] High Auto-reload value (TIM2 only)
			} arr;

			// CCR1 (Capture/compare register 1) bitfields.
			struct {
				Object *ccr1_l; // [0:15] Low Capture/Compare 1 value
				Object *ccr1_h; // [16:31] High Capture/Compare 1 value (TIM2 only)
			} ccr1;

			// CCR2 (Capture/compare register 2) bitfields.
			struct {
				Object *ccr2_l; // [0:15] Low Capture/Compare 2 value
				Object *ccr2_h; // [16:31] High Capture/Compare 2 value (TIM2 only)
			} ccr2;

			// CCR3 (Capture/compare register 3) bitfields.
			struct {
				Object *ccr3_l; // [0:15] Low Capture/Compare value
				Object *ccr3_h; // [16:31] High Capture/Compare value (TIM2 only)
			} ccr3;

			// CCR4 (Capture/compare register 4) bitfields.
			struct {
				Object *ccr4_l; // [0:15] Low Capture/Compare value
				Object *ccr4_h; // [16:31] High Capture/Compare value (TIM2 only)
			} ccr4;

			// DCR (DMA control register) bitfields.
			struct {
				Object *dba; // [0:4] DMA base address
				Object *dbl; // [8:12] DMA burst length
			} dcr;

			// DMAR (DMA address for full transfer) bitfields.
			struct {
				Object *dmar; // [0:15] DMA register for burst accesses
			} dmar;
		} fld;
	} f0;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32TIM2State;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_tim2_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32TIM2State *state = STM32_TIM2_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f0.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
	state->f0.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
	state->f0.reg.smcr = cm_object_get_child_by_name(obj, "SMCR");
	state->f0.reg.dier = cm_object_get_child_by_name(obj, "DIER");
	state->f0.reg.sr = cm_object_get_child_by_name(obj, "SR");
	state->f0.reg.egr = cm_object_get_child_by_name(obj, "EGR");
	state->f0.reg.ccmr1_output = cm_object_get_child_by_name(obj, "CCMR1_Output");
	state->f0.reg.ccmr1_input = cm_object_get_child_by_name(obj, "CCMR1_Input");
	state->f0.reg.ccmr2_output = cm_object_get_child_by_name(obj, "CCMR2_Output");
	state->f0.reg.ccmr2_input = cm_object_get_child_by_name(obj, "CCMR2_Input");
	state->f0.reg.ccer = cm_object_get_child_by_name(obj, "CCER");
	state->f0.reg.cnt = cm_object_get_child_by_name(obj, "CNT");
	state->f0.reg.psc = cm_object_get_child_by_name(obj, "PSC");
	state->f0.reg.arr = cm_object_get_child_by_name(obj, "ARR");
	state->f0.reg.ccr1 = cm_object_get_child_by_name(obj, "CCR1");
	state->f0.reg.ccr2 = cm_object_get_child_by_name(obj, "CCR2");
	state->f0.reg.ccr3 = cm_object_get_child_by_name(obj, "CCR3");
	state->f0.reg.ccr4 = cm_object_get_child_by_name(obj, "CCR4");
	state->f0.reg.dcr = cm_object_get_child_by_name(obj, "DCR");
	state->f0.reg.dmar = cm_object_get_child_by_name(obj, "DMAR");

	// CR1 bitfields.
	state->f0.fld.cr1.cen = cm_object_get_child_by_name(state->f0.reg.cr1, "CEN");
	state->f0.fld.cr1.udis = cm_object_get_child_by_name(state->f0.reg.cr1, "UDIS");
	state->f0.fld.cr1.urs = cm_object_get_child_by_name(state->f0.reg.cr1, "URS");
	state->f0.fld.cr1.opm = cm_object_get_child_by_name(state->f0.reg.cr1, "OPM");
	state->f0.fld.cr1.dir = cm_object_get_child_by_name(state->f0.reg.cr1, "DIR");
	state->f0.fld.cr1.cms = cm_object_get_child_by_name(state->f0.reg.cr1, "CMS");
	state->f0.fld.cr1.arpe = cm_object_get_child_by_name(state->f0.reg.cr1, "ARPE");
	state->f0.fld.cr1.ckd = cm_object_get_child_by_name(state->f0.reg.cr1, "CKD");

	// CR2 bitfields.
	state->f0.fld.cr2.ccds = cm_object_get_child_by_name(state->f0.reg.cr2, "CCDS");
	state->f0.fld.cr2.mms = cm_object_get_child_by_name(state->f0.reg.cr2, "MMS");
	state->f0.fld.cr2.ti1s = cm_object_get_child_by_name(state->f0.reg.cr2, "TI1S");

	// SMCR bitfields.
	state->f0.fld.smcr.sms = cm_object_get_child_by_name(state->f0.reg.smcr, "SMS");
	state->f0.fld.smcr.ts = cm_object_get_child_by_name(state->f0.reg.smcr, "TS");
	state->f0.fld.smcr.msm = cm_object_get_child_by_name(state->f0.reg.smcr, "MSM");
	state->f0.fld.smcr.etf = cm_object_get_child_by_name(state->f0.reg.smcr, "ETF");
	state->f0.fld.smcr.etps = cm_object_get_child_by_name(state->f0.reg.smcr, "ETPS");
	state->f0.fld.smcr.ece = cm_object_get_child_by_name(state->f0.reg.smcr, "ECE");
	state->f0.fld.smcr.etp = cm_object_get_child_by_name(state->f0.reg.smcr, "ETP");

	// DIER bitfields.
	state->f0.fld.dier.uie = cm_object_get_child_by_name(state->f0.reg.dier, "UIE");
	state->f0.fld.dier.cc1ie = cm_object_get_child_by_name(state->f0.reg.dier, "CC1IE");
	state->f0.fld.dier.cc2ie = cm_object_get_child_by_name(state->f0.reg.dier, "CC2IE");
	state->f0.fld.dier.cc3ie = cm_object_get_child_by_name(state->f0.reg.dier, "CC3IE");
	state->f0.fld.dier.cc4ie = cm_object_get_child_by_name(state->f0.reg.dier, "CC4IE");
	state->f0.fld.dier.tie = cm_object_get_child_by_name(state->f0.reg.dier, "TIE");
	state->f0.fld.dier.ude = cm_object_get_child_by_name(state->f0.reg.dier, "UDE");
	state->f0.fld.dier.cc1de = cm_object_get_child_by_name(state->f0.reg.dier, "CC1DE");
	state->f0.fld.dier.cc2de = cm_object_get_child_by_name(state->f0.reg.dier, "CC2DE");
	state->f0.fld.dier.cc3de = cm_object_get_child_by_name(state->f0.reg.dier, "CC3DE");
	state->f0.fld.dier.cc4de = cm_object_get_child_by_name(state->f0.reg.dier, "CC4DE");
	state->f0.fld.dier.comde = cm_object_get_child_by_name(state->f0.reg.dier, "COMDE");
	state->f0.fld.dier.tde = cm_object_get_child_by_name(state->f0.reg.dier, "TDE");

	// SR bitfields.
	state->f0.fld.sr.uif = cm_object_get_child_by_name(state->f0.reg.sr, "UIF");
	state->f0.fld.sr.cc1if = cm_object_get_child_by_name(state->f0.reg.sr, "CC1IF");
	state->f0.fld.sr.cc2if = cm_object_get_child_by_name(state->f0.reg.sr, "CC2IF");
	state->f0.fld.sr.cc3if = cm_object_get_child_by_name(state->f0.reg.sr, "CC3IF");
	state->f0.fld.sr.cc4if = cm_object_get_child_by_name(state->f0.reg.sr, "CC4IF");
	state->f0.fld.sr.tif = cm_object_get_child_by_name(state->f0.reg.sr, "TIF");
	state->f0.fld.sr.cc1of = cm_object_get_child_by_name(state->f0.reg.sr, "CC1OF");
	state->f0.fld.sr.cc2of = cm_object_get_child_by_name(state->f0.reg.sr, "CC2OF");
	state->f0.fld.sr.cc3of = cm_object_get_child_by_name(state->f0.reg.sr, "CC3OF");
	state->f0.fld.sr.cc4of = cm_object_get_child_by_name(state->f0.reg.sr, "CC4OF");

	// EGR bitfields.
	state->f0.fld.egr.ug = cm_object_get_child_by_name(state->f0.reg.egr, "UG");
	state->f0.fld.egr.cc1g = cm_object_get_child_by_name(state->f0.reg.egr, "CC1G");
	state->f0.fld.egr.cc2g = cm_object_get_child_by_name(state->f0.reg.egr, "CC2G");
	state->f0.fld.egr.cc3g = cm_object_get_child_by_name(state->f0.reg.egr, "CC3G");
	state->f0.fld.egr.cc4g = cm_object_get_child_by_name(state->f0.reg.egr, "CC4G");
	state->f0.fld.egr.tg = cm_object_get_child_by_name(state->f0.reg.egr, "TG");

	// CCMR1_Output bitfields.
	state->f0.fld.ccmr1_output.cc1s = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "CC1S");
	state->f0.fld.ccmr1_output.oc1fe = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "OC1FE");
	state->f0.fld.ccmr1_output.oc1pe = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "OC1PE");
	state->f0.fld.ccmr1_output.oc1m = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "OC1M");
	state->f0.fld.ccmr1_output.oc1ce = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "OC1CE");
	state->f0.fld.ccmr1_output.cc2s = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "CC2S");
	state->f0.fld.ccmr1_output.oc2fe = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "OC2FE");
	state->f0.fld.ccmr1_output.oc2pe = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "OC2PE");
	state->f0.fld.ccmr1_output.oc2m = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "OC2M");
	state->f0.fld.ccmr1_output.oc2ce = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "OC2CE");

	// CCMR1_Input bitfields.
	state->f0.fld.ccmr1_input.cc1s = cm_object_get_child_by_name(state->f0.reg.ccmr1_input, "CC1S");
	state->f0.fld.ccmr1_input.ic1psc = cm_object_get_child_by_name(state->f0.reg.ccmr1_input, "IC1PSC");
	state->f0.fld.ccmr1_input.ic1f = cm_object_get_child_by_name(state->f0.reg.ccmr1_input, "IC1F");
	state->f0.fld.ccmr1_input.cc2s = cm_object_get_child_by_name(state->f0.reg.ccmr1_input, "CC2S");
	state->f0.fld.ccmr1_input.ic2psc = cm_object_get_child_by_name(state->f0.reg.ccmr1_input, "IC2PSC");
	state->f0.fld.ccmr1_input.ic2f = cm_object_get_child_by_name(state->f0.reg.ccmr1_input, "IC2F");

	// CCMR2_Output bitfields.
	state->f0.fld.ccmr2_output.cc3s = cm_object_get_child_by_name(state->f0.reg.ccmr2_output, "CC3S");
	state->f0.fld.ccmr2_output.oc3fe = cm_object_get_child_by_name(state->f0.reg.ccmr2_output, "OC3FE");
	state->f0.fld.ccmr2_output.oc3pe = cm_object_get_child_by_name(state->f0.reg.ccmr2_output, "OC3PE");
	state->f0.fld.ccmr2_output.oc3m = cm_object_get_child_by_name(state->f0.reg.ccmr2_output, "OC3M");
	state->f0.fld.ccmr2_output.oc3ce = cm_object_get_child_by_name(state->f0.reg.ccmr2_output, "OC3CE");
	state->f0.fld.ccmr2_output.cc4s = cm_object_get_child_by_name(state->f0.reg.ccmr2_output, "CC4S");
	state->f0.fld.ccmr2_output.oc4fe = cm_object_get_child_by_name(state->f0.reg.ccmr2_output, "OC4FE");
	state->f0.fld.ccmr2_output.oc4pe = cm_object_get_child_by_name(state->f0.reg.ccmr2_output, "OC4PE");
	state->f0.fld.ccmr2_output.oc4m = cm_object_get_child_by_name(state->f0.reg.ccmr2_output, "OC4M");
	state->f0.fld.ccmr2_output.oc4ce = cm_object_get_child_by_name(state->f0.reg.ccmr2_output, "OC4CE");

	// CCMR2_Input bitfields.
	state->f0.fld.ccmr2_input.cc3s = cm_object_get_child_by_name(state->f0.reg.ccmr2_input, "CC3S");
	state->f0.fld.ccmr2_input.ic3psc = cm_object_get_child_by_name(state->f0.reg.ccmr2_input, "IC3PSC");
	state->f0.fld.ccmr2_input.ic3f = cm_object_get_child_by_name(state->f0.reg.ccmr2_input, "IC3F");
	state->f0.fld.ccmr2_input.cc4s = cm_object_get_child_by_name(state->f0.reg.ccmr2_input, "CC4S");
	state->f0.fld.ccmr2_input.ic4psc = cm_object_get_child_by_name(state->f0.reg.ccmr2_input, "IC4PSC");
	state->f0.fld.ccmr2_input.ic4f = cm_object_get_child_by_name(state->f0.reg.ccmr2_input, "IC4F");

	// CCER bitfields.
	state->f0.fld.ccer.cc1e = cm_object_get_child_by_name(state->f0.reg.ccer, "CC1E");
	state->f0.fld.ccer.cc1p = cm_object_get_child_by_name(state->f0.reg.ccer, "CC1P");
	state->f0.fld.ccer.cc1np = cm_object_get_child_by_name(state->f0.reg.ccer, "CC1NP");
	state->f0.fld.ccer.cc2e = cm_object_get_child_by_name(state->f0.reg.ccer, "CC2E");
	state->f0.fld.ccer.cc2p = cm_object_get_child_by_name(state->f0.reg.ccer, "CC2P");
	state->f0.fld.ccer.cc2np = cm_object_get_child_by_name(state->f0.reg.ccer, "CC2NP");
	state->f0.fld.ccer.cc3e = cm_object_get_child_by_name(state->f0.reg.ccer, "CC3E");
	state->f0.fld.ccer.cc3p = cm_object_get_child_by_name(state->f0.reg.ccer, "CC3P");
	state->f0.fld.ccer.cc3np = cm_object_get_child_by_name(state->f0.reg.ccer, "CC3NP");
	state->f0.fld.ccer.cc4e = cm_object_get_child_by_name(state->f0.reg.ccer, "CC4E");
	state->f0.fld.ccer.cc4p = cm_object_get_child_by_name(state->f0.reg.ccer, "CC4P");
	state->f0.fld.ccer.cc4np = cm_object_get_child_by_name(state->f0.reg.ccer, "CC4NP");

	// CNT bitfields.
	state->f0.fld.cnt.cnt_l = cm_object_get_child_by_name(state->f0.reg.cnt, "CNT_L");
	state->f0.fld.cnt.cnt_h = cm_object_get_child_by_name(state->f0.reg.cnt, "CNT_H");

	// PSC bitfields.
	state->f0.fld.psc.psc = cm_object_get_child_by_name(state->f0.reg.psc, "PSC");

	// ARR bitfields.
	state->f0.fld.arr.arr_l = cm_object_get_child_by_name(state->f0.reg.arr, "ARR_L");
	state->f0.fld.arr.arr_h = cm_object_get_child_by_name(state->f0.reg.arr, "ARR_H");

	// CCR1 bitfields.
	state->f0.fld.ccr1.ccr1_l = cm_object_get_child_by_name(state->f0.reg.ccr1, "CCR1_L");
	state->f0.fld.ccr1.ccr1_h = cm_object_get_child_by_name(state->f0.reg.ccr1, "CCR1_H");

	// CCR2 bitfields.
	state->f0.fld.ccr2.ccr2_l = cm_object_get_child_by_name(state->f0.reg.ccr2, "CCR2_L");
	state->f0.fld.ccr2.ccr2_h = cm_object_get_child_by_name(state->f0.reg.ccr2, "CCR2_H");

	// CCR3 bitfields.
	state->f0.fld.ccr3.ccr3_l = cm_object_get_child_by_name(state->f0.reg.ccr3, "CCR3_L");
	state->f0.fld.ccr3.ccr3_h = cm_object_get_child_by_name(state->f0.reg.ccr3, "CCR3_H");

	// CCR4 bitfields.
	state->f0.fld.ccr4.ccr4_l = cm_object_get_child_by_name(state->f0.reg.ccr4, "CCR4_L");
	state->f0.fld.ccr4.ccr4_h = cm_object_get_child_by_name(state->f0.reg.ccr4, "CCR4_H");

	// DCR bitfields.
	state->f0.fld.dcr.dba = cm_object_get_child_by_name(state->f0.reg.dcr, "DBA");
	state->f0.fld.dcr.dbl = cm_object_get_child_by_name(state->f0.reg.dcr, "DBL");

	// DMAR bitfields.
	state->f0.fld.dmar.dmar = cm_object_get_child_by_name(state->f0.reg.dmar, "DMAR");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// TIM14 (General-purpose-timers) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F0 TIM14 (General-purpose-timers) registers.
		struct {
			Object *cr1; // 0x0 Control register 1
			Object *dier; // 0xC DMA/Interrupt enable register
			Object *sr; // 0x10 Status register
			Object *egr; // 0x14 Event generation register
			Object *ccmr1_output; // 0x18 Capture/compare mode register (output mode)
			Object *ccmr1_input; // 0x18 Capture/compare mode register (input mode)
			Object *ccer; // 0x20 Capture/compare enable register
			Object *cnt; // 0x24 Counter
			Object *psc; // 0x28 Prescaler
			Object *arr; // 0x2C Auto-reload register
			Object *ccr1; // 0x34 Capture/compare register 1
			Object *or; // 0x50 Option register
		} reg;

		struct {

			// CR1 (Control register 1) bitfields.
			struct {
				Object *cen; // [0:0] Counter enable
				Object *udis; // [1:1] Update disable
				Object *urs; // [2:2] Update request source
				Object *arpe; // [7:7] Auto-reload preload enable
				Object *ckd; // [8:9] Clock division
			} cr1;

			// DIER (DMA/Interrupt enable register) bitfields.
			struct {
				Object *uie; // [0:0] Update interrupt enable
				Object *cc1ie; // [1:1] Capture/Compare 1 interrupt enable
			} dier;

			// SR (Status register) bitfields.
			struct {
				Object *uif; // [0:0] Update interrupt flag
				Object *cc1if; // [1:1] Capture/compare 1 interrupt flag
				Object *cc1of; // [9:9] Capture/Compare 1 overcapture flag
			} sr;

			// EGR (Event generation register) bitfields.
			struct {
				Object *ug; // [0:0] Update generation
				Object *cc1g; // [1:1] Capture/compare 1 generation
			} egr;

			// CCMR1_Output (Capture/compare mode register (output mode)) bitfields.
			struct {
				Object *cc1s; // [0:1] Capture/Compare 1 selection
				Object *oc1fe; // [2:2] Output compare 1 fast enable
				Object *oc1pe; // [3:3] Output Compare 1 preload enable
				Object *oc1m; // [4:6] Output Compare 1 mode
			} ccmr1_output;

			// CCMR1_Input (Capture/compare mode register (input mode)) bitfields.
			struct {
				Object *cc1s; // [0:1] Capture/Compare 1 selection
				Object *ic1psc; // [2:3] Input capture 1 prescaler
				Object *ic1f; // [4:7] Input capture 1 filter
			} ccmr1_input;

			// CCER (Capture/compare enable register) bitfields.
			struct {
				Object *cc1e; // [0:0] Capture/Compare 1 output enable
				Object *cc1p; // [1:1] Capture/Compare 1 output Polarity
				Object *cc1np; // [3:3] Capture/Compare 1 output Polarity
			} ccer;

			// CNT (Counter) bitfields.
			struct {
				Object *cnt; // [0:15] Counter value
			} cnt;

			// PSC (Prescaler) bitfields.
			struct {
				Object *psc; // [0:15] Prescaler value
			} psc;

			// ARR (Auto-reload register) bitfields.
			struct {
				Object *arr; // [0:15] Auto-reload value
			} arr;

			// CCR1 (Capture/compare register 1) bitfields.
			struct {
				Object *ccr1; // [0:15] Capture/Compare 1 value
			} ccr1;

			// OR (Option register) bitfields.
			struct {
				Object *rmp; // [0:1] Timer input 1 remap
			} or;
		} fld;
	} f0;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32TIM14State;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_tim14_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32TIM14State *state = STM32_TIM14_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f0.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
	state->f0.reg.dier = cm_object_get_child_by_name(obj, "DIER");
	state->f0.reg.sr = cm_object_get_child_by_name(obj, "SR");
	state->f0.reg.egr = cm_object_get_child_by_name(obj, "EGR");
	state->f0.reg.ccmr1_output = cm_object_get_child_by_name(obj, "CCMR1_Output");
	state->f0.reg.ccmr1_input = cm_object_get_child_by_name(obj, "CCMR1_Input");
	state->f0.reg.ccer = cm_object_get_child_by_name(obj, "CCER");
	state->f0.reg.cnt = cm_object_get_child_by_name(obj, "CNT");
	state->f0.reg.psc = cm_object_get_child_by_name(obj, "PSC");
	state->f0.reg.arr = cm_object_get_child_by_name(obj, "ARR");
	state->f0.reg.ccr1 = cm_object_get_child_by_name(obj, "CCR1");
	state->f0.reg.or = cm_object_get_child_by_name(obj, "OR");

	// CR1 bitfields.
	state->f0.fld.cr1.cen = cm_object_get_child_by_name(state->f0.reg.cr1, "CEN");
	state->f0.fld.cr1.udis = cm_object_get_child_by_name(state->f0.reg.cr1, "UDIS");
	state->f0.fld.cr1.urs = cm_object_get_child_by_name(state->f0.reg.cr1, "URS");
	state->f0.fld.cr1.arpe = cm_object_get_child_by_name(state->f0.reg.cr1, "ARPE");
	state->f0.fld.cr1.ckd = cm_object_get_child_by_name(state->f0.reg.cr1, "CKD");

	// DIER bitfields.
	state->f0.fld.dier.uie = cm_object_get_child_by_name(state->f0.reg.dier, "UIE");
	state->f0.fld.dier.cc1ie = cm_object_get_child_by_name(state->f0.reg.dier, "CC1IE");

	// SR bitfields.
	state->f0.fld.sr.uif = cm_object_get_child_by_name(state->f0.reg.sr, "UIF");
	state->f0.fld.sr.cc1if = cm_object_get_child_by_name(state->f0.reg.sr, "CC1IF");
	state->f0.fld.sr.cc1of = cm_object_get_child_by_name(state->f0.reg.sr, "CC1OF");

	// EGR bitfields.
	state->f0.fld.egr.ug = cm_object_get_child_by_name(state->f0.reg.egr, "UG");
	state->f0.fld.egr.cc1g = cm_object_get_child_by_name(state->f0.reg.egr, "CC1G");

	// CCMR1_Output bitfields.
	state->f0.fld.ccmr1_output.cc1s = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "CC1S");
	state->f0.fld.ccmr1_output.oc1fe = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "OC1FE");
	state->f0.fld.ccmr1_output.oc1pe = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "OC1PE");
	state->f0.fld.ccmr1_output.oc1m = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "OC1M");

	// CCMR1_Input bitfields.
	state->f0.fld.ccmr1_input.cc1s = cm_object_get_child_by_name(state->f0.reg.ccmr1_input, "CC1S");
	state->f0.fld.ccmr1_input.ic1psc = cm_object_get_child_by_name(state->f0.reg.ccmr1_input, "IC1PSC");
	state->f0.fld.ccmr1_input.ic1f = cm_object_get_child_by_name(state->f0.reg.ccmr1_input, "IC1F");

	// CCER bitfields.
	state->f0.fld.ccer.cc1e = cm_object_get_child_by_name(state->f0.reg.ccer, "CC1E");
	state->f0.fld.ccer.cc1p = cm_object_get_child_by_name(state->f0.reg.ccer, "CC1P");
	state->f0.fld.ccer.cc1np = cm_object_get_child_by_name(state->f0.reg.ccer, "CC1NP");

	// CNT bitfields.
	state->f0.fld.cnt.cnt = cm_object_get_child_by_name(state->f0.reg.cnt, "CNT");

	// PSC bitfields.
	state->f0.fld.psc.psc = cm_object_get_child_by_name(state->f0.reg.psc, "PSC");

	// ARR bitfields.
	state->f0.fld.arr.arr = cm_object_get_child_by_name(state->f0.reg.arr, "ARR");

	// CCR1 bitfields.
	state->f0.fld.ccr1.ccr1 = cm_object_get_child_by_name(state->f0.reg.ccr1, "CCR1");

	// OR bitfields.
	state->f0.fld.or.rmp = cm_object_get_child_by_name(state->f0.reg.or, "RMP");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// TIM6 (Basic-timers) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F0 TIM6 (Basic-timers) registers.
		struct {
			Object *cr1; // 0x0 Control register 1
			Object *cr2; // 0x4 Control register 2
			Object *dier; // 0xC DMA/Interrupt enable register
			Object *sr; // 0x10 Status register
			Object *egr; // 0x14 Event generation register
			Object *cnt; // 0x24 Counter
			Object *psc; // 0x28 Prescaler
			Object *arr; // 0x2C Auto-reload register
		} reg;

		struct {

			// CR1 (Control register 1) bitfields.
			struct {
				Object *cen; // [0:0] Counter enable
				Object *udis; // [1:1] Update disable
				Object *urs; // [2:2] Update request source
				Object *opm; // [3:3] One-pulse mode
				Object *arpe; // [7:7] Auto-reload preload enable
			} cr1;

			// CR2 (Control register 2) bitfields.
			struct {
				Object *mms; // [4:6] Master mode selection
			} cr2;

			// DIER (DMA/Interrupt enable register) bitfields.
			struct {
				Object *uie; // [0:0] Update interrupt enable
				Object *ude; // [8:8] Update DMA request enable
			} dier;

			// SR (Status register) bitfields.
			struct {
				Object *uif; // [0:0] Update interrupt flag
			} sr;

			// EGR (Event generation register) bitfields.
			struct {
				Object *ug; // [0:0] Update generation
			} egr;

			// CNT (Counter) bitfields.
			struct {
				Object *cnt; // [0:15] Low counter value
			} cnt;

			// PSC (Prescaler) bitfields.
			struct {
				Object *psc; // [0:15] Prescaler value
			} psc;

			// ARR (Auto-reload register) bitfields.
			struct {
				Object *arr; // [0:15] Low Auto-reload value
			} arr;
		} fld;
	} f0;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32TIM6State;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_tim6_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32TIM6State *state = STM32_TIM6_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f0.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
	state->f0.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
	state->f0.reg.dier = cm_object_get_child_by_name(obj, "DIER");
	state->f0.reg.sr = cm_object_get_child_by_name(obj, "SR");
	state->f0.reg.egr = cm_object_get_child_by_name(obj, "EGR");
	state->f0.reg.cnt = cm_object_get_child_by_name(obj, "CNT");
	state->f0.reg.psc = cm_object_get_child_by_name(obj, "PSC");
	state->f0.reg.arr = cm_object_get_child_by_name(obj, "ARR");

	// CR1 bitfields.
	state->f0.fld.cr1.cen = cm_object_get_child_by_name(state->f0.reg.cr1, "CEN");
	state->f0.fld.cr1.udis = cm_object_get_child_by_name(state->f0.reg.cr1, "UDIS");
	state->f0.fld.cr1.urs = cm_object_get_child_by_name(state->f0.reg.cr1, "URS");
	state->f0.fld.cr1.opm = cm_object_get_child_by_name(state->f0.reg.cr1, "OPM");
	state->f0.fld.cr1.arpe = cm_object_get_child_by_name(state->f0.reg.cr1, "ARPE");

	// CR2 bitfields.
	state->f0.fld.cr2.mms = cm_object_get_child_by_name(state->f0.reg.cr2, "MMS");

	// DIER bitfields.
	state->f0.fld.dier.uie = cm_object_get_child_by_name(state->f0.reg.dier, "UIE");
	state->f0.fld.dier.ude = cm_object_get_child_by_name(state->f0.reg.dier, "UDE");

	// SR bitfields.
	state->f0.fld.sr.uif = cm_object_get_child_by_name(state->f0.reg.sr, "UIF");

	// EGR bitfields.
	state->f0.fld.egr.ug = cm_object_get_child_by_name(state->f0.reg.egr, "UG");

	// CNT bitfields.
	state->f0.fld.cnt.cnt = cm_object_get_child_by_name(state->f0.reg.cnt, "CNT");

	// PSC bitfields.
	state->f0.fld.psc.psc = cm_object_get_child_by_name(state->f0.reg.psc, "PSC");

	// ARR bitfields.
	state->f0.fld.arr.arr = cm_object_get_child_by_name(state->f0.reg.arr, "ARR");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// EXTI (External interrupt/event controller) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F0 EXTI (External interrupt/event controller) registers.
		struct {
			Object *imr; // 0x0 Interrupt mask register (EXTI_IMR)
			Object *emr; // 0x4 Event mask register (EXTI_EMR)
			Object *rtsr; // 0x8 Rising Trigger selection register (EXTI_RTSR)
			Object *ftsr; // 0xC Falling Trigger selection register (EXTI_FTSR)
			Object *swier; // 0x10 Software interrupt event register (EXTI_SWIER)
			Object *pr; // 0x14 Pending register (EXTI_PR)
		} reg;

		struct {

			// IMR (Interrupt mask register (EXTI_IMR)) bitfields.
			struct {
				Object *mr0; // [0:0] Interrupt Mask on line 0
				Object *mr1; // [1:1] Interrupt Mask on line 1
				Object *mr2; // [2:2] Interrupt Mask on line 2
				Object *mr3; // [3:3] Interrupt Mask on line 3
				Object *mr4; // [4:4] Interrupt Mask on line 4
				Object *mr5; // [5:5] Interrupt Mask on line 5
				Object *mr6; // [6:6] Interrupt Mask on line 6
				Object *mr7; // [7:7] Interrupt Mask on line 7
				Object *mr8; // [8:8] Interrupt Mask on line 8
				Object *mr9; // [9:9] Interrupt Mask on line 9
				Object *mr10; // [10:10] Interrupt Mask on line 10
				Object *mr11; // [11:11] Interrupt Mask on line 11
				Object *mr12; // [12:12] Interrupt Mask on line 12
				Object *mr13; // [13:13] Interrupt Mask on line 13
				Object *mr14; // [14:14] Interrupt Mask on line 14
				Object *mr15; // [15:15] Interrupt Mask on line 15
				Object *mr16; // [16:16] Interrupt Mask on line 16
				Object *mr17; // [17:17] Interrupt Mask on line 17
				Object *mr18; // [18:18] Interrupt Mask on line 18
				Object *mr19; // [19:19] Interrupt Mask on line 19
				Object *mr20; // [20:20] Interrupt Mask on line 20
				Object *mr21; // [21:21] Interrupt Mask on line 21
				Object *mr22; // [22:22] Interrupt Mask on line 22
				Object *mr23; // [23:23] Interrupt Mask on line 23
				Object *mr24; // [24:24] Interrupt Mask on line 24
				Object *mr25; // [25:25] Interrupt Mask on line 25
				Object *mr26; // [26:26] Interrupt Mask on line 26
				Object *mr27; // [27:27] Interrupt Mask on line 27
			} imr;

			// EMR (Event mask register (EXTI_EMR)) bitfields.
			struct {
				Object *mr0; // [0:0] Event Mask on line 0
				Object *mr1; // [1:1] Event Mask on line 1
				Object *mr2; // [2:2] Event Mask on line 2
				Object *mr3; // [3:3] Event Mask on line 3
				Object *mr4; // [4:4] Event Mask on line 4
				Object *mr5; // [5:5] Event Mask on line 5
				Object *mr6; // [6:6] Event Mask on line 6
				Object *mr7; // [7:7] Event Mask on line 7
				Object *mr8; // [8:8] Event Mask on line 8
				Object *mr9; // [9:9] Event Mask on line 9
				Object *mr10; // [10:10] Event Mask on line 10
				Object *mr11; // [11:11] Event Mask on line 11
				Object *mr12; // [12:12] Event Mask on line 12
				Object *mr13; // [13:13] Event Mask on line 13
				Object *mr14; // [14:14] Event Mask on line 14
				Object *mr15; // [15:15] Event Mask on line 15
				Object *mr16; // [16:16] Event Mask on line 16
				Object *mr17; // [17:17] Event Mask on line 17
				Object *mr18; // [18:18] Event Mask on line 18
				Object *mr19; // [19:19] Event Mask on line 19
				Object *mr20; // [20:20] Event Mask on line 20
				Object *mr21; // [21:21] Event Mask on line 21
				Object *mr22; // [22:22] Event Mask on line 22
				Object *mr23; // [23:23] Event Mask on line 23
				Object *mr24; // [24:24] Event Mask on line 24
				Object *mr25; // [25:25] Event Mask on line 25
				Object *mr26; // [26:26] Event Mask on line 26
				Object *mr27; // [27:27] Event Mask on line 27
			} emr;

			// RTSR (Rising Trigger selection register (EXTI_RTSR)) bitfields.
			struct {
				Object *tr0; // [0:0] Rising trigger event configuration of line 0
				Object *tr1; // [1:1] Rising trigger event configuration of line 1
				Object *tr2; // [2:2] Rising trigger event configuration of line 2
				Object *tr3; // [3:3] Rising trigger event configuration of line 3
				Object *tr4; // [4:4] Rising trigger event configuration of line 4
				Object *tr5; // [5:5] Rising trigger event configuration of line 5
				Object *tr6; // [6:6] Rising trigger event configuration of line 6
				Object *tr7; // [7:7] Rising trigger event configuration of line 7
				Object *tr8; // [8:8] Rising trigger event configuration of line 8
				Object *tr9; // [9:9] Rising trigger event configuration of line 9
				Object *tr10; // [10:10] Rising trigger event configuration of line 10
				Object *tr11; // [11:11] Rising trigger event configuration of line 11
				Object *tr12; // [12:12] Rising trigger event configuration of line 12
				Object *tr13; // [13:13] Rising trigger event configuration of line 13
				Object *tr14; // [14:14] Rising trigger event configuration of line 14
				Object *tr15; // [15:15] Rising trigger event configuration of line 15
				Object *tr16; // [16:16] Rising trigger event configuration of line 16
				Object *tr17; // [17:17] Rising trigger event configuration of line 17
				Object *tr19; // [19:19] Rising trigger event configuration of line 19
			} rtsr;

			// FTSR (Falling Trigger selection register (EXTI_FTSR)) bitfields.
			struct {
				Object *tr0; // [0:0] Falling trigger event configuration of line 0
				Object *tr1; // [1:1] Falling trigger event configuration of line 1
				Object *tr2; // [2:2] Falling trigger event configuration of line 2
				Object *tr3; // [3:3] Falling trigger event configuration of line 3
				Object *tr4; // [4:4] Falling trigger event configuration of line 4
				Object *tr5; // [5:5] Falling trigger event configuration of line 5
				Object *tr6; // [6:6] Falling trigger event configuration of line 6
				Object *tr7; // [7:7] Falling trigger event configuration of line 7
				Object *tr8; // [8:8] Falling trigger event configuration of line 8
				Object *tr9; // [9:9] Falling trigger event configuration of line 9
				Object *tr10; // [10:10] Falling trigger event configuration of line 10
				Object *tr11; // [11:11] Falling trigger event configuration of line 11
				Object *tr12; // [12:12] Falling trigger event configuration of line 12
				Object *tr13; // [13:13] Falling trigger event configuration of line 13
				Object *tr14; // [14:14] Falling trigger event configuration of line 14
				Object *tr15; // [15:15] Falling trigger event configuration of line 15
				Object *tr16; // [16:16] Falling trigger event configuration of line 16
				Object *tr17; // [17:17] Falling trigger event configuration of line 17
				Object *tr19; // [19:19] Falling trigger event configuration of line 19
			} ftsr;

			// SWIER (Software interrupt event register (EXTI_SWIER)) bitfields.
			struct {
				Object *swier0; // [0:0] Software Interrupt on line 0
				Object *swier1; // [1:1] Software Interrupt on line 1
				Object *swier2; // [2:2] Software Interrupt on line 2
				Object *swier3; // [3:3] Software Interrupt on line 3
				Object *swier4; // [4:4] Software Interrupt on line 4
				Object *swier5; // [5:5] Software Interrupt on line 5
				Object *swier6; // [6:6] Software Interrupt on line 6
				Object *swier7; // [7:7] Software Interrupt on line 7
				Object *swier8; // [8:8] Software Interrupt on line 8
				Object *swier9; // [9:9] Software Interrupt on line 9
				Object *swier10; // [10:10] Software Interrupt on line 10
				Object *swier11; // [11:11] Software Interrupt on line 11
				Object *swier12; // [12:12] Software Interrupt on line 12
				Object *swier13; // [13:13] Software Interrupt on line 13
				Object *swier14; // [14:14] Software Interrupt on line 14
				Object *swier15; // [15:15] Software Interrupt on line 15
				Object *swier16; // [16:16] Software Interrupt on line 16
				Object *swier17; // [17:17] Software Interrupt on line 17
				Object *swier19; // [19:19] Software Interrupt on line 19
			} swier;

			// PR (Pending register (EXTI_PR)) bitfields.
			struct {
				Object *pr0; // [0:0] Pending bit 0
				Object *pr1; // [1:1] Pending bit 1
				Object *pr2; // [2:2] Pending bit 2
				Object *pr3; // [3:3] Pending bit 3
				Object *pr4; // [4:4] Pending bit 4
				Object *pr5; // [5:5] Pending bit 5
				Object *pr6; // [6:6] Pending bit 6
				Object *pr7; // [7:7] Pending bit 7
				Object *pr8; // [8:8] Pending bit 8
				Object *pr9; // [9:9] Pending bit 9
				Object *pr10; // [10:10] Pending bit 10
				Object *pr11; // [11:11] Pending bit 11
				Object *pr12; // [12:12] Pending bit 12
				Object *pr13; // [13:13] Pending bit 13
				Object *pr14; // [14:14] Pending bit 14
				Object *pr15; // [15:15] Pending bit 15
				Object *pr16; // [16:16] Pending bit 16
				Object *pr17; // [17:17] Pending bit 17
				Object *pr19; // [19:19] Pending bit 19
			} pr;
		} fld;
	} f0;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32EXTIState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_exti_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32EXTIState *state = STM32_EXTI_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f0.reg.imr = cm_object_get_child_by_name(obj, "IMR");
	state->f0.reg.emr = cm_object_get_child_by_name(obj, "EMR");
	state->f0.reg.rtsr = cm_object_get_child_by_name(obj, "RTSR");
	state->f0.reg.ftsr = cm_object_get_child_by_name(obj, "FTSR");
	state->f0.reg.swier = cm_object_get_child_by_name(obj, "SWIER");
	state->f0.reg.pr = cm_object_get_child_by_name(obj, "PR");

	// IMR bitfields.
	state->f0.fld.imr.mr0 = cm_object_get_child_by_name(state->f0.reg.imr, "MR0");
	state->f0.fld.imr.mr1 = cm_object_get_child_by_name(state->f0.reg.imr, "MR1");
	state->f0.fld.imr.mr2 = cm_object_get_child_by_name(state->f0.reg.imr, "MR2");
	state->f0.fld.imr.mr3 = cm_object_get_child_by_name(state->f0.reg.imr, "MR3");
	state->f0.fld.imr.mr4 = cm_object_get_child_by_name(state->f0.reg.imr, "MR4");
	state->f0.fld.imr.mr5 = cm_object_get_child_by_name(state->f0.reg.imr, "MR5");
	state->f0.fld.imr.mr6 = cm_object_get_child_by_name(state->f0.reg.imr, "MR6");
	state->f0.fld.imr.mr7 = cm_object_get_child_by_name(state->f0.reg.imr, "MR7");
	state->f0.fld.imr.mr8 = cm_object_get_child_by_name(state->f0.reg.imr, "MR8");
	state->f0.fld.imr.mr9 = cm_object_get_child_by_name(state->f0.reg.imr, "MR9");
	state->f0.fld.imr.mr10 = cm_object_get_child_by_name(state->f0.reg.imr, "MR10");
	state->f0.fld.imr.mr11 = cm_object_get_child_by_name(state->f0.reg.imr, "MR11");
	state->f0.fld.imr.mr12 = cm_object_get_child_by_name(state->f0.reg.imr, "MR12");
	state->f0.fld.imr.mr13 = cm_object_get_child_by_name(state->f0.reg.imr, "MR13");
	state->f0.fld.imr.mr14 = cm_object_get_child_by_name(state->f0.reg.imr, "MR14");
	state->f0.fld.imr.mr15 = cm_object_get_child_by_name(state->f0.reg.imr, "MR15");
	state->f0.fld.imr.mr16 = cm_object_get_child_by_name(state->f0.reg.imr, "MR16");
	state->f0.fld.imr.mr17 = cm_object_get_child_by_name(state->f0.reg.imr, "MR17");
	state->f0.fld.imr.mr18 = cm_object_get_child_by_name(state->f0.reg.imr, "MR18");
	state->f0.fld.imr.mr19 = cm_object_get_child_by_name(state->f0.reg.imr, "MR19");
	state->f0.fld.imr.mr20 = cm_object_get_child_by_name(state->f0.reg.imr, "MR20");
	state->f0.fld.imr.mr21 = cm_object_get_child_by_name(state->f0.reg.imr, "MR21");
	state->f0.fld.imr.mr22 = cm_object_get_child_by_name(state->f0.reg.imr, "MR22");
	state->f0.fld.imr.mr23 = cm_object_get_child_by_name(state->f0.reg.imr, "MR23");
	state->f0.fld.imr.mr24 = cm_object_get_child_by_name(state->f0.reg.imr, "MR24");
	state->f0.fld.imr.mr25 = cm_object_get_child_by_name(state->f0.reg.imr, "MR25");
	state->f0.fld.imr.mr26 = cm_object_get_child_by_name(state->f0.reg.imr, "MR26");
	state->f0.fld.imr.mr27 = cm_object_get_child_by_name(state->f0.reg.imr, "MR27");

	// EMR bitfields.
	state->f0.fld.emr.mr0 = cm_object_get_child_by_name(state->f0.reg.emr, "MR0");
	state->f0.fld.emr.mr1 = cm_object_get_child_by_name(state->f0.reg.emr, "MR1");
	state->f0.fld.emr.mr2 = cm_object_get_child_by_name(state->f0.reg.emr, "MR2");
	state->f0.fld.emr.mr3 = cm_object_get_child_by_name(state->f0.reg.emr, "MR3");
	state->f0.fld.emr.mr4 = cm_object_get_child_by_name(state->f0.reg.emr, "MR4");
	state->f0.fld.emr.mr5 = cm_object_get_child_by_name(state->f0.reg.emr, "MR5");
	state->f0.fld.emr.mr6 = cm_object_get_child_by_name(state->f0.reg.emr, "MR6");
	state->f0.fld.emr.mr7 = cm_object_get_child_by_name(state->f0.reg.emr, "MR7");
	state->f0.fld.emr.mr8 = cm_object_get_child_by_name(state->f0.reg.emr, "MR8");
	state->f0.fld.emr.mr9 = cm_object_get_child_by_name(state->f0.reg.emr, "MR9");
	state->f0.fld.emr.mr10 = cm_object_get_child_by_name(state->f0.reg.emr, "MR10");
	state->f0.fld.emr.mr11 = cm_object_get_child_by_name(state->f0.reg.emr, "MR11");
	state->f0.fld.emr.mr12 = cm_object_get_child_by_name(state->f0.reg.emr, "MR12");
	state->f0.fld.emr.mr13 = cm_object_get_child_by_name(state->f0.reg.emr, "MR13");
	state->f0.fld.emr.mr14 = cm_object_get_child_by_name(state->f0.reg.emr, "MR14");
	state->f0.fld.emr.mr15 = cm_object_get_child_by_name(state->f0.reg.emr, "MR15");
	state->f0.fld.emr.mr16 = cm_object_get_child_by_name(state->f0.reg.emr, "MR16");
	state->f0.fld.emr.mr17 = cm_object_get_child_by_name(state->f0.reg.emr, "MR17");
	state->f0.fld.emr.mr18 = cm_object_get_child_by_name(state->f0.reg.emr, "MR18");
	state->f0.fld.emr.mr19 = cm_object_get_child_by_name(state->f0.reg.emr, "MR19");
	state->f0.fld.emr.mr20 = cm_object_get_child_by_name(state->f0.reg.emr, "MR20");
	state->f0.fld.emr.mr21 = cm_object_get_child_by_name(state->f0.reg.emr, "MR21");
	state->f0.fld.emr.mr22 = cm_object_get_child_by_name(state->f0.reg.emr, "MR22");
	state->f0.fld.emr.mr23 = cm_object_get_child_by_name(state->f0.reg.emr, "MR23");
	state->f0.fld.emr.mr24 = cm_object_get_child_by_name(state->f0.reg.emr, "MR24");
	state->f0.fld.emr.mr25 = cm_object_get_child_by_name(state->f0.reg.emr, "MR25");
	state->f0.fld.emr.mr26 = cm_object_get_child_by_name(state->f0.reg.emr, "MR26");
	state->f0.fld.emr.mr27 = cm_object_get_child_by_name(state->f0.reg.emr, "MR27");

	// RTSR bitfields.
	state->f0.fld.rtsr.tr0 = cm_object_get_child_by_name(state->f0.reg.rtsr, "TR0");
	state->f0.fld.rtsr.tr1 = cm_object_get_child_by_name(state->f0.reg.rtsr, "TR1");
	state->f0.fld.rtsr.tr2 = cm_object_get_child_by_name(state->f0.reg.rtsr, "TR2");
	state->f0.fld.rtsr.tr3 = cm_object_get_child_by_name(state->f0.reg.rtsr, "TR3");
	state->f0.fld.rtsr.tr4 = cm_object_get_child_by_name(state->f0.reg.rtsr, "TR4");
	state->f0.fld.rtsr.tr5 = cm_object_get_child_by_name(state->f0.reg.rtsr, "TR5");
	state->f0.fld.rtsr.tr6 = cm_object_get_child_by_name(state->f0.reg.rtsr, "TR6");
	state->f0.fld.rtsr.tr7 = cm_object_get_child_by_name(state->f0.reg.rtsr, "TR7");
	state->f0.fld.rtsr.tr8 = cm_object_get_child_by_name(state->f0.reg.rtsr, "TR8");
	state->f0.fld.rtsr.tr9 = cm_object_get_child_by_name(state->f0.reg.rtsr, "TR9");
	state->f0.fld.rtsr.tr10 = cm_object_get_child_by_name(state->f0.reg.rtsr, "TR10");
	state->f0.fld.rtsr.tr11 = cm_object_get_child_by_name(state->f0.reg.rtsr, "TR11");
	state->f0.fld.rtsr.tr12 = cm_object_get_child_by_name(state->f0.reg.rtsr, "TR12");
	state->f0.fld.rtsr.tr13 = cm_object_get_child_by_name(state->f0.reg.rtsr, "TR13");
	state->f0.fld.rtsr.tr14 = cm_object_get_child_by_name(state->f0.reg.rtsr, "TR14");
	state->f0.fld.rtsr.tr15 = cm_object_get_child_by_name(state->f0.reg.rtsr, "TR15");
	state->f0.fld.rtsr.tr16 = cm_object_get_child_by_name(state->f0.reg.rtsr, "TR16");
	state->f0.fld.rtsr.tr17 = cm_object_get_child_by_name(state->f0.reg.rtsr, "TR17");
	state->f0.fld.rtsr.tr19 = cm_object_get_child_by_name(state->f0.reg.rtsr, "TR19");

	// FTSR bitfields.
	state->f0.fld.ftsr.tr0 = cm_object_get_child_by_name(state->f0.reg.ftsr, "TR0");
	state->f0.fld.ftsr.tr1 = cm_object_get_child_by_name(state->f0.reg.ftsr, "TR1");
	state->f0.fld.ftsr.tr2 = cm_object_get_child_by_name(state->f0.reg.ftsr, "TR2");
	state->f0.fld.ftsr.tr3 = cm_object_get_child_by_name(state->f0.reg.ftsr, "TR3");
	state->f0.fld.ftsr.tr4 = cm_object_get_child_by_name(state->f0.reg.ftsr, "TR4");
	state->f0.fld.ftsr.tr5 = cm_object_get_child_by_name(state->f0.reg.ftsr, "TR5");
	state->f0.fld.ftsr.tr6 = cm_object_get_child_by_name(state->f0.reg.ftsr, "TR6");
	state->f0.fld.ftsr.tr7 = cm_object_get_child_by_name(state->f0.reg.ftsr, "TR7");
	state->f0.fld.ftsr.tr8 = cm_object_get_child_by_name(state->f0.reg.ftsr, "TR8");
	state->f0.fld.ftsr.tr9 = cm_object_get_child_by_name(state->f0.reg.ftsr, "TR9");
	state->f0.fld.ftsr.tr10 = cm_object_get_child_by_name(state->f0.reg.ftsr, "TR10");
	state->f0.fld.ftsr.tr11 = cm_object_get_child_by_name(state->f0.reg.ftsr, "TR11");
	state->f0.fld.ftsr.tr12 = cm_object_get_child_by_name(state->f0.reg.ftsr, "TR12");
	state->f0.fld.ftsr.tr13 = cm_object_get_child_by_name(state->f0.reg.ftsr, "TR13");
	state->f0.fld.ftsr.tr14 = cm_object_get_child_by_name(state->f0.reg.ftsr, "TR14");
	state->f0.fld.ftsr.tr15 = cm_object_get_child_by_name(state->f0.reg.ftsr, "TR15");
	state->f0.fld.ftsr.tr16 = cm_object_get_child_by_name(state->f0.reg.ftsr, "TR16");
	state->f0.fld.ftsr.tr17 = cm_object_get_child_by_name(state->f0.reg.ftsr, "TR17");
	state->f0.fld.ftsr.tr19 = cm_object_get_child_by_name(state->f0.reg.ftsr, "TR19");

	// SWIER bitfields.
	state->f0.fld.swier.swier0 = cm_object_get_child_by_name(state->f0.reg.swier, "SWIER0");
	state->f0.fld.swier.swier1 = cm_object_get_child_by_name(state->f0.reg.swier, "SWIER1");
	state->f0.fld.swier.swier2 = cm_object_get_child_by_name(state->f0.reg.swier, "SWIER2");
	state->f0.fld.swier.swier3 = cm_object_get_child_by_name(state->f0.reg.swier, "SWIER3");
	state->f0.fld.swier.swier4 = cm_object_get_child_by_name(state->f0.reg.swier, "SWIER4");
	state->f0.fld.swier.swier5 = cm_object_get_child_by_name(state->f0.reg.swier, "SWIER5");
	state->f0.fld.swier.swier6 = cm_object_get_child_by_name(state->f0.reg.swier, "SWIER6");
	state->f0.fld.swier.swier7 = cm_object_get_child_by_name(state->f0.reg.swier, "SWIER7");
	state->f0.fld.swier.swier8 = cm_object_get_child_by_name(state->f0.reg.swier, "SWIER8");
	state->f0.fld.swier.swier9 = cm_object_get_child_by_name(state->f0.reg.swier, "SWIER9");
	state->f0.fld.swier.swier10 = cm_object_get_child_by_name(state->f0.reg.swier, "SWIER10");
	state->f0.fld.swier.swier11 = cm_object_get_child_by_name(state->f0.reg.swier, "SWIER11");
	state->f0.fld.swier.swier12 = cm_object_get_child_by_name(state->f0.reg.swier, "SWIER12");
	state->f0.fld.swier.swier13 = cm_object_get_child_by_name(state->f0.reg.swier, "SWIER13");
	state->f0.fld.swier.swier14 = cm_object_get_child_by_name(state->f0.reg.swier, "SWIER14");
	state->f0.fld.swier.swier15 = cm_object_get_child_by_name(state->f0.reg.swier, "SWIER15");
	state->f0.fld.swier.swier16 = cm_object_get_child_by_name(state->f0.reg.swier, "SWIER16");
	state->f0.fld.swier.swier17 = cm_object_get_child_by_name(state->f0.reg.swier, "SWIER17");
	state->f0.fld.swier.swier19 = cm_object_get_child_by_name(state->f0.reg.swier, "SWIER19");

	// PR bitfields.
	state->f0.fld.pr.pr0 = cm_object_get_child_by_name(state->f0.reg.pr, "PR0");
	state->f0.fld.pr.pr1 = cm_object_get_child_by_name(state->f0.reg.pr, "PR1");
	state->f0.fld.pr.pr2 = cm_object_get_child_by_name(state->f0.reg.pr, "PR2");
	state->f0.fld.pr.pr3 = cm_object_get_child_by_name(state->f0.reg.pr, "PR3");
	state->f0.fld.pr.pr4 = cm_object_get_child_by_name(state->f0.reg.pr, "PR4");
	state->f0.fld.pr.pr5 = cm_object_get_child_by_name(state->f0.reg.pr, "PR5");
	state->f0.fld.pr.pr6 = cm_object_get_child_by_name(state->f0.reg.pr, "PR6");
	state->f0.fld.pr.pr7 = cm_object_get_child_by_name(state->f0.reg.pr, "PR7");
	state->f0.fld.pr.pr8 = cm_object_get_child_by_name(state->f0.reg.pr, "PR8");
	state->f0.fld.pr.pr9 = cm_object_get_child_by_name(state->f0.reg.pr, "PR9");
	state->f0.fld.pr.pr10 = cm_object_get_child_by_name(state->f0.reg.pr, "PR10");
	state->f0.fld.pr.pr11 = cm_object_get_child_by_name(state->f0.reg.pr, "PR11");
	state->f0.fld.pr.pr12 = cm_object_get_child_by_name(state->f0.reg.pr, "PR12");
	state->f0.fld.pr.pr13 = cm_object_get_child_by_name(state->f0.reg.pr, "PR13");
	state->f0.fld.pr.pr14 = cm_object_get_child_by_name(state->f0.reg.pr, "PR14");
	state->f0.fld.pr.pr15 = cm_object_get_child_by_name(state->f0.reg.pr, "PR15");
	state->f0.fld.pr.pr16 = cm_object_get_child_by_name(state->f0.reg.pr, "PR16");
	state->f0.fld.pr.pr17 = cm_object_get_child_by_name(state->f0.reg.pr, "PR17");
	state->f0.fld.pr.pr19 = cm_object_get_child_by_name(state->f0.reg.pr, "PR19");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DMA1 (DMA controller) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F0 DMA1 (DMA controller) registers.
		struct {
			Object *isr; // 0x0 DMA interrupt status register (DMA_ISR)
			Object *ifcr; // 0x4 DMA interrupt flag clear register (DMA_IFCR)
			Object *ccr1; // 0x8 DMA channel configuration register (DMA_CCR)
			Object *cndtr1; // 0xC DMA channel 1 number of data register
			Object *cpar1; // 0x10 DMA channel 1 peripheral address register
			Object *cmar1; // 0x14 DMA channel 1 memory address register
			Object *ccr2; // 0x1C DMA channel configuration register (DMA_CCR)
			Object *cndtr2; // 0x20 DMA channel 2 number of data register
			Object *cpar2; // 0x24 DMA channel 2 peripheral address register
			Object *cmar2; // 0x28 DMA channel 2 memory address register
			Object *ccr3; // 0x30 DMA channel configuration register (DMA_CCR)
			Object *cndtr3; // 0x34 DMA channel 3 number of data register
			Object *cpar3; // 0x38 DMA channel 3 peripheral address register
			Object *cmar3; // 0x3C DMA channel 3 memory address register
			Object *ccr4; // 0x44 DMA channel configuration register (DMA_CCR)
			Object *cndtr4; // 0x48 DMA channel 4 number of data register
			Object *cpar4; // 0x4C DMA channel 4 peripheral address register
			Object *cmar4; // 0x50 DMA channel 4 memory address register
			Object *ccr5; // 0x58 DMA channel configuration register (DMA_CCR)
			Object *cndtr5; // 0x5C DMA channel 5 number of data register
			Object *cpar5; // 0x60 DMA channel 5 peripheral address register
			Object *cmar5; // 0x64 DMA channel 5 memory address register
			Object *ccr6; // 0x6C DMA channel configuration register (DMA_CCR)
			Object *cndtr6; // 0x70 DMA channel 6 number of data register
			Object *cpar6; // 0x74 DMA channel 6 peripheral address register
			Object *cmar6; // 0x78 DMA channel 6 memory address register
			Object *ccr7; // 0x80 DMA channel configuration register (DMA_CCR)
			Object *cndtr7; // 0x84 DMA channel 7 number of data register
			Object *cpar7; // 0x88 DMA channel 7 peripheral address register
			Object *cmar7; // 0x8C DMA channel 7 memory address register
		} reg;

		struct {

			// ISR (DMA interrupt status register (DMA_ISR)) bitfields.
			struct {
				Object *gif1; // [0:0] Channel 1 Global interrupt flag
				Object *tcif1; // [1:1] Channel 1 Transfer Complete flag
				Object *htif1; // [2:2] Channel 1 Half Transfer Complete flag
				Object *teif1; // [3:3] Channel 1 Transfer Error flag
				Object *gif2; // [4:4] Channel 2 Global interrupt flag
				Object *tcif2; // [5:5] Channel 2 Transfer Complete flag
				Object *htif2; // [6:6] Channel 2 Half Transfer Complete flag
				Object *teif2; // [7:7] Channel 2 Transfer Error flag
				Object *gif3; // [8:8] Channel 3 Global interrupt flag
				Object *tcif3; // [9:9] Channel 3 Transfer Complete flag
				Object *htif3; // [10:10] Channel 3 Half Transfer Complete flag
				Object *teif3; // [11:11] Channel 3 Transfer Error flag
				Object *gif4; // [12:12] Channel 4 Global interrupt flag
				Object *tcif4; // [13:13] Channel 4 Transfer Complete flag
				Object *htif4; // [14:14] Channel 4 Half Transfer Complete flag
				Object *teif4; // [15:15] Channel 4 Transfer Error flag
				Object *gif5; // [16:16] Channel 5 Global interrupt flag
				Object *tcif5; // [17:17] Channel 5 Transfer Complete flag
				Object *htif5; // [18:18] Channel 5 Half Transfer Complete flag
				Object *teif5; // [19:19] Channel 5 Transfer Error flag
				Object *gif6; // [20:20] Channel 6 Global interrupt flag
				Object *tcif6; // [21:21] Channel 6 Transfer Complete flag
				Object *htif6; // [22:22] Channel 6 Half Transfer Complete flag
				Object *teif6; // [23:23] Channel 6 Transfer Error flag
				Object *gif7; // [24:24] Channel 7 Global interrupt flag
				Object *tcif7; // [25:25] Channel 7 Transfer Complete flag
				Object *htif7; // [26:26] Channel 7 Half Transfer Complete flag
				Object *teif7; // [27:27] Channel 7 Transfer Error flag
			} isr;

			// IFCR (DMA interrupt flag clear register (DMA_IFCR)) bitfields.
			struct {
				Object *cgif1; // [0:0] Channel 1 Global interrupt clear
				Object *ctcif1; // [1:1] Channel 1 Transfer Complete clear
				Object *chtif1; // [2:2] Channel 1 Half Transfer clear
				Object *cteif1; // [3:3] Channel 1 Transfer Error clear
				Object *cgif2; // [4:4] Channel 2 Global interrupt clear
				Object *ctcif2; // [5:5] Channel 2 Transfer Complete clear
				Object *chtif2; // [6:6] Channel 2 Half Transfer clear
				Object *cteif2; // [7:7] Channel 2 Transfer Error clear
				Object *cgif3; // [8:8] Channel 3 Global interrupt clear
				Object *ctcif3; // [9:9] Channel 3 Transfer Complete clear
				Object *chtif3; // [10:10] Channel 3 Half Transfer clear
				Object *cteif3; // [11:11] Channel 3 Transfer Error clear
				Object *cgif4; // [12:12] Channel 4 Global interrupt clear
				Object *ctcif4; // [13:13] Channel 4 Transfer Complete clear
				Object *chtif4; // [14:14] Channel 4 Half Transfer clear
				Object *cteif4; // [15:15] Channel 4 Transfer Error clear
				Object *cgif5; // [16:16] Channel 5 Global interrupt clear
				Object *ctcif5; // [17:17] Channel 5 Transfer Complete clear
				Object *chtif5; // [18:18] Channel 5 Half Transfer clear
				Object *cteif5; // [19:19] Channel 5 Transfer Error clear
				Object *cgif6; // [20:20] Channel 6 Global interrupt clear
				Object *ctcif6; // [21:21] Channel 6 Transfer Complete clear
				Object *chtif6; // [22:22] Channel 6 Half Transfer clear
				Object *cteif6; // [23:23] Channel 6 Transfer Error clear
				Object *cgif7; // [24:24] Channel 7 Global interrupt clear
				Object *ctcif7; // [25:25] Channel 7 Transfer Complete clear
				Object *chtif7; // [26:26] Channel 7 Half Transfer clear
				Object *cteif7; // [27:27] Channel 7 Transfer Error clear
			} ifcr;

			// CCR1 (DMA channel configuration register (DMA_CCR)) bitfields.
			struct {
				Object *en; // [0:0] Channel enable
				Object *tcie; // [1:1] Transfer complete interrupt enable
				Object *htie; // [2:2] Half Transfer interrupt enable
				Object *teie; // [3:3] Transfer error interrupt enable
				Object *dir; // [4:4] Data transfer direction
				Object *circ; // [5:5] Circular mode
				Object *pinc; // [6:6] Peripheral increment mode
				Object *minc; // [7:7] Memory increment mode
				Object *psize; // [8:9] Peripheral size
				Object *msize; // [10:11] Memory size
				Object *pl; // [12:13] Channel Priority level
				Object *mem2mem; // [14:14] Memory to memory mode
			} ccr1;

			// CNDTR1 (DMA channel 1 number of data register) bitfields.
			struct {
				Object *ndt; // [0:15] Number of data to transfer
			} cndtr1;

			// CPAR1 (DMA channel 1 peripheral address register) bitfields.
			struct {
				Object *pa; // [0:31] Peripheral address
			} cpar1;

			// CMAR1 (DMA channel 1 memory address register) bitfields.
			struct {
				Object *ma; // [0:31] Memory address
			} cmar1;

			// CCR2 (DMA channel configuration register (DMA_CCR)) bitfields.
			struct {
				Object *en; // [0:0] Channel enable
				Object *tcie; // [1:1] Transfer complete interrupt enable
				Object *htie; // [2:2] Half Transfer interrupt enable
				Object *teie; // [3:3] Transfer error interrupt enable
				Object *dir; // [4:4] Data transfer direction
				Object *circ; // [5:5] Circular mode
				Object *pinc; // [6:6] Peripheral increment mode
				Object *minc; // [7:7] Memory increment mode
				Object *psize; // [8:9] Peripheral size
				Object *msize; // [10:11] Memory size
				Object *pl; // [12:13] Channel Priority level
				Object *mem2mem; // [14:14] Memory to memory mode
			} ccr2;

			// CNDTR2 (DMA channel 2 number of data register) bitfields.
			struct {
				Object *ndt; // [0:15] Number of data to transfer
			} cndtr2;

			// CPAR2 (DMA channel 2 peripheral address register) bitfields.
			struct {
				Object *pa; // [0:31] Peripheral address
			} cpar2;

			// CMAR2 (DMA channel 2 memory address register) bitfields.
			struct {
				Object *ma; // [0:31] Memory address
			} cmar2;

			// CCR3 (DMA channel configuration register (DMA_CCR)) bitfields.
			struct {
				Object *en; // [0:0] Channel enable
				Object *tcie; // [1:1] Transfer complete interrupt enable
				Object *htie; // [2:2] Half Transfer interrupt enable
				Object *teie; // [3:3] Transfer error interrupt enable
				Object *dir; // [4:4] Data transfer direction
				Object *circ; // [5:5] Circular mode
				Object *pinc; // [6:6] Peripheral increment mode
				Object *minc; // [7:7] Memory increment mode
				Object *psize; // [8:9] Peripheral size
				Object *msize; // [10:11] Memory size
				Object *pl; // [12:13] Channel Priority level
				Object *mem2mem; // [14:14] Memory to memory mode
			} ccr3;

			// CNDTR3 (DMA channel 3 number of data register) bitfields.
			struct {
				Object *ndt; // [0:15] Number of data to transfer
			} cndtr3;

			// CPAR3 (DMA channel 3 peripheral address register) bitfields.
			struct {
				Object *pa; // [0:31] Peripheral address
			} cpar3;

			// CMAR3 (DMA channel 3 memory address register) bitfields.
			struct {
				Object *ma; // [0:31] Memory address
			} cmar3;

			// CCR4 (DMA channel configuration register (DMA_CCR)) bitfields.
			struct {
				Object *en; // [0:0] Channel enable
				Object *tcie; // [1:1] Transfer complete interrupt enable
				Object *htie; // [2:2] Half Transfer interrupt enable
				Object *teie; // [3:3] Transfer error interrupt enable
				Object *dir; // [4:4] Data transfer direction
				Object *circ; // [5:5] Circular mode
				Object *pinc; // [6:6] Peripheral increment mode
				Object *minc; // [7:7] Memory increment mode
				Object *psize; // [8:9] Peripheral size
				Object *msize; // [10:11] Memory size
				Object *pl; // [12:13] Channel Priority level
				Object *mem2mem; // [14:14] Memory to memory mode
			} ccr4;

			// CNDTR4 (DMA channel 4 number of data register) bitfields.
			struct {
				Object *ndt; // [0:15] Number of data to transfer
			} cndtr4;

			// CPAR4 (DMA channel 4 peripheral address register) bitfields.
			struct {
				Object *pa; // [0:31] Peripheral address
			} cpar4;

			// CMAR4 (DMA channel 4 memory address register) bitfields.
			struct {
				Object *ma; // [0:31] Memory address
			} cmar4;

			// CCR5 (DMA channel configuration register (DMA_CCR)) bitfields.
			struct {
				Object *en; // [0:0] Channel enable
				Object *tcie; // [1:1] Transfer complete interrupt enable
				Object *htie; // [2:2] Half Transfer interrupt enable
				Object *teie; // [3:3] Transfer error interrupt enable
				Object *dir; // [4:4] Data transfer direction
				Object *circ; // [5:5] Circular mode
				Object *pinc; // [6:6] Peripheral increment mode
				Object *minc; // [7:7] Memory increment mode
				Object *psize; // [8:9] Peripheral size
				Object *msize; // [10:11] Memory size
				Object *pl; // [12:13] Channel Priority level
				Object *mem2mem; // [14:14] Memory to memory mode
			} ccr5;

			// CNDTR5 (DMA channel 5 number of data register) bitfields.
			struct {
				Object *ndt; // [0:15] Number of data to transfer
			} cndtr5;

			// CPAR5 (DMA channel 5 peripheral address register) bitfields.
			struct {
				Object *pa; // [0:31] Peripheral address
			} cpar5;

			// CMAR5 (DMA channel 5 memory address register) bitfields.
			struct {
				Object *ma; // [0:31] Memory address
			} cmar5;

			// CCR6 (DMA channel configuration register (DMA_CCR)) bitfields.
			struct {
				Object *en; // [0:0] Channel enable
				Object *tcie; // [1:1] Transfer complete interrupt enable
				Object *htie; // [2:2] Half Transfer interrupt enable
				Object *teie; // [3:3] Transfer error interrupt enable
				Object *dir; // [4:4] Data transfer direction
				Object *circ; // [5:5] Circular mode
				Object *pinc; // [6:6] Peripheral increment mode
				Object *minc; // [7:7] Memory increment mode
				Object *psize; // [8:9] Peripheral size
				Object *msize; // [10:11] Memory size
				Object *pl; // [12:13] Channel Priority level
				Object *mem2mem; // [14:14] Memory to memory mode
			} ccr6;

			// CNDTR6 (DMA channel 6 number of data register) bitfields.
			struct {
				Object *ndt; // [0:15] Number of data to transfer
			} cndtr6;

			// CPAR6 (DMA channel 6 peripheral address register) bitfields.
			struct {
				Object *pa; // [0:31] Peripheral address
			} cpar6;

			// CMAR6 (DMA channel 6 memory address register) bitfields.
			struct {
				Object *ma; // [0:31] Memory address
			} cmar6;

			// CCR7 (DMA channel configuration register (DMA_CCR)) bitfields.
			struct {
				Object *en; // [0:0] Channel enable
				Object *tcie; // [1:1] Transfer complete interrupt enable
				Object *htie; // [2:2] Half Transfer interrupt enable
				Object *teie; // [3:3] Transfer error interrupt enable
				Object *dir; // [4:4] Data transfer direction
				Object *circ; // [5:5] Circular mode
				Object *pinc; // [6:6] Peripheral increment mode
				Object *minc; // [7:7] Memory increment mode
				Object *psize; // [8:9] Peripheral size
				Object *msize; // [10:11] Memory size
				Object *pl; // [12:13] Channel Priority level
				Object *mem2mem; // [14:14] Memory to memory mode
			} ccr7;

			// CNDTR7 (DMA channel 7 number of data register) bitfields.
			struct {
				Object *ndt; // [0:15] Number of data to transfer
			} cndtr7;

			// CPAR7 (DMA channel 7 peripheral address register) bitfields.
			struct {
				Object *pa; // [0:31] Peripheral address
			} cpar7;

			// CMAR7 (DMA channel 7 memory address register) bitfields.
			struct {
				Object *ma; // [0:31] Memory address
			} cmar7;
		} fld;
	} f0;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32DMA1State;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_dma1_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32DMA1State *state = STM32_DMA1_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f0.reg.isr = cm_object_get_child_by_name(obj, "ISR");
	state->f0.reg.ifcr = cm_object_get_child_by_name(obj, "IFCR");
	state->f0.reg.ccr1 = cm_object_get_child_by_name(obj, "CCR1");
	state->f0.reg.cndtr1 = cm_object_get_child_by_name(obj, "CNDTR1");
	state->f0.reg.cpar1 = cm_object_get_child_by_name(obj, "CPAR1");
	state->f0.reg.cmar1 = cm_object_get_child_by_name(obj, "CMAR1");
	state->f0.reg.ccr2 = cm_object_get_child_by_name(obj, "CCR2");
	state->f0.reg.cndtr2 = cm_object_get_child_by_name(obj, "CNDTR2");
	state->f0.reg.cpar2 = cm_object_get_child_by_name(obj, "CPAR2");
	state->f0.reg.cmar2 = cm_object_get_child_by_name(obj, "CMAR2");
	state->f0.reg.ccr3 = cm_object_get_child_by_name(obj, "CCR3");
	state->f0.reg.cndtr3 = cm_object_get_child_by_name(obj, "CNDTR3");
	state->f0.reg.cpar3 = cm_object_get_child_by_name(obj, "CPAR3");
	state->f0.reg.cmar3 = cm_object_get_child_by_name(obj, "CMAR3");
	state->f0.reg.ccr4 = cm_object_get_child_by_name(obj, "CCR4");
	state->f0.reg.cndtr4 = cm_object_get_child_by_name(obj, "CNDTR4");
	state->f0.reg.cpar4 = cm_object_get_child_by_name(obj, "CPAR4");
	state->f0.reg.cmar4 = cm_object_get_child_by_name(obj, "CMAR4");
	state->f0.reg.ccr5 = cm_object_get_child_by_name(obj, "CCR5");
	state->f0.reg.cndtr5 = cm_object_get_child_by_name(obj, "CNDTR5");
	state->f0.reg.cpar5 = cm_object_get_child_by_name(obj, "CPAR5");
	state->f0.reg.cmar5 = cm_object_get_child_by_name(obj, "CMAR5");
	state->f0.reg.ccr6 = cm_object_get_child_by_name(obj, "CCR6");
	state->f0.reg.cndtr6 = cm_object_get_child_by_name(obj, "CNDTR6");
	state->f0.reg.cpar6 = cm_object_get_child_by_name(obj, "CPAR6");
	state->f0.reg.cmar6 = cm_object_get_child_by_name(obj, "CMAR6");
	state->f0.reg.ccr7 = cm_object_get_child_by_name(obj, "CCR7");
	state->f0.reg.cndtr7 = cm_object_get_child_by_name(obj, "CNDTR7");
	state->f0.reg.cpar7 = cm_object_get_child_by_name(obj, "CPAR7");
	state->f0.reg.cmar7 = cm_object_get_child_by_name(obj, "CMAR7");

	// ISR bitfields.
	state->f0.fld.isr.gif1 = cm_object_get_child_by_name(state->f0.reg.isr, "GIF1");
	state->f0.fld.isr.tcif1 = cm_object_get_child_by_name(state->f0.reg.isr, "TCIF1");
	state->f0.fld.isr.htif1 = cm_object_get_child_by_name(state->f0.reg.isr, "HTIF1");
	state->f0.fld.isr.teif1 = cm_object_get_child_by_name(state->f0.reg.isr, "TEIF1");
	state->f0.fld.isr.gif2 = cm_object_get_child_by_name(state->f0.reg.isr, "GIF2");
	state->f0.fld.isr.tcif2 = cm_object_get_child_by_name(state->f0.reg.isr, "TCIF2");
	state->f0.fld.isr.htif2 = cm_object_get_child_by_name(state->f0.reg.isr, "HTIF2");
	state->f0.fld.isr.teif2 = cm_object_get_child_by_name(state->f0.reg.isr, "TEIF2");
	state->f0.fld.isr.gif3 = cm_object_get_child_by_name(state->f0.reg.isr, "GIF3");
	state->f0.fld.isr.tcif3 = cm_object_get_child_by_name(state->f0.reg.isr, "TCIF3");
	state->f0.fld.isr.htif3 = cm_object_get_child_by_name(state->f0.reg.isr, "HTIF3");
	state->f0.fld.isr.teif3 = cm_object_get_child_by_name(state->f0.reg.isr, "TEIF3");
	state->f0.fld.isr.gif4 = cm_object_get_child_by_name(state->f0.reg.isr, "GIF4");
	state->f0.fld.isr.tcif4 = cm_object_get_child_by_name(state->f0.reg.isr, "TCIF4");
	state->f0.fld.isr.htif4 = cm_object_get_child_by_name(state->f0.reg.isr, "HTIF4");
	state->f0.fld.isr.teif4 = cm_object_get_child_by_name(state->f0.reg.isr, "TEIF4");
	state->f0.fld.isr.gif5 = cm_object_get_child_by_name(state->f0.reg.isr, "GIF5");
	state->f0.fld.isr.tcif5 = cm_object_get_child_by_name(state->f0.reg.isr, "TCIF5");
	state->f0.fld.isr.htif5 = cm_object_get_child_by_name(state->f0.reg.isr, "HTIF5");
	state->f0.fld.isr.teif5 = cm_object_get_child_by_name(state->f0.reg.isr, "TEIF5");
	state->f0.fld.isr.gif6 = cm_object_get_child_by_name(state->f0.reg.isr, "GIF6");
	state->f0.fld.isr.tcif6 = cm_object_get_child_by_name(state->f0.reg.isr, "TCIF6");
	state->f0.fld.isr.htif6 = cm_object_get_child_by_name(state->f0.reg.isr, "HTIF6");
	state->f0.fld.isr.teif6 = cm_object_get_child_by_name(state->f0.reg.isr, "TEIF6");
	state->f0.fld.isr.gif7 = cm_object_get_child_by_name(state->f0.reg.isr, "GIF7");
	state->f0.fld.isr.tcif7 = cm_object_get_child_by_name(state->f0.reg.isr, "TCIF7");
	state->f0.fld.isr.htif7 = cm_object_get_child_by_name(state->f0.reg.isr, "HTIF7");
	state->f0.fld.isr.teif7 = cm_object_get_child_by_name(state->f0.reg.isr, "TEIF7");

	// IFCR bitfields.
	state->f0.fld.ifcr.cgif1 = cm_object_get_child_by_name(state->f0.reg.ifcr, "CGIF1");
	state->f0.fld.ifcr.ctcif1 = cm_object_get_child_by_name(state->f0.reg.ifcr, "CTCIF1");
	state->f0.fld.ifcr.chtif1 = cm_object_get_child_by_name(state->f0.reg.ifcr, "CHTIF1");
	state->f0.fld.ifcr.cteif1 = cm_object_get_child_by_name(state->f0.reg.ifcr, "CTEIF1");
	state->f0.fld.ifcr.cgif2 = cm_object_get_child_by_name(state->f0.reg.ifcr, "CGIF2");
	state->f0.fld.ifcr.ctcif2 = cm_object_get_child_by_name(state->f0.reg.ifcr, "CTCIF2");
	state->f0.fld.ifcr.chtif2 = cm_object_get_child_by_name(state->f0.reg.ifcr, "CHTIF2");
	state->f0.fld.ifcr.cteif2 = cm_object_get_child_by_name(state->f0.reg.ifcr, "CTEIF2");
	state->f0.fld.ifcr.cgif3 = cm_object_get_child_by_name(state->f0.reg.ifcr, "CGIF3");
	state->f0.fld.ifcr.ctcif3 = cm_object_get_child_by_name(state->f0.reg.ifcr, "CTCIF3");
	state->f0.fld.ifcr.chtif3 = cm_object_get_child_by_name(state->f0.reg.ifcr, "CHTIF3");
	state->f0.fld.ifcr.cteif3 = cm_object_get_child_by_name(state->f0.reg.ifcr, "CTEIF3");
	state->f0.fld.ifcr.cgif4 = cm_object_get_child_by_name(state->f0.reg.ifcr, "CGIF4");
	state->f0.fld.ifcr.ctcif4 = cm_object_get_child_by_name(state->f0.reg.ifcr, "CTCIF4");
	state->f0.fld.ifcr.chtif4 = cm_object_get_child_by_name(state->f0.reg.ifcr, "CHTIF4");
	state->f0.fld.ifcr.cteif4 = cm_object_get_child_by_name(state->f0.reg.ifcr, "CTEIF4");
	state->f0.fld.ifcr.cgif5 = cm_object_get_child_by_name(state->f0.reg.ifcr, "CGIF5");
	state->f0.fld.ifcr.ctcif5 = cm_object_get_child_by_name(state->f0.reg.ifcr, "CTCIF5");
	state->f0.fld.ifcr.chtif5 = cm_object_get_child_by_name(state->f0.reg.ifcr, "CHTIF5");
	state->f0.fld.ifcr.cteif5 = cm_object_get_child_by_name(state->f0.reg.ifcr, "CTEIF5");
	state->f0.fld.ifcr.cgif6 = cm_object_get_child_by_name(state->f0.reg.ifcr, "CGIF6");
	state->f0.fld.ifcr.ctcif6 = cm_object_get_child_by_name(state->f0.reg.ifcr, "CTCIF6");
	state->f0.fld.ifcr.chtif6 = cm_object_get_child_by_name(state->f0.reg.ifcr, "CHTIF6");
	state->f0.fld.ifcr.cteif6 = cm_object_get_child_by_name(state->f0.reg.ifcr, "CTEIF6");
	state->f0.fld.ifcr.cgif7 = cm_object_get_child_by_name(state->f0.reg.ifcr, "CGIF7");
	state->f0.fld.ifcr.ctcif7 = cm_object_get_child_by_name(state->f0.reg.ifcr, "CTCIF7");
	state->f0.fld.ifcr.chtif7 = cm_object_get_child_by_name(state->f0.reg.ifcr, "CHTIF7");
	state->f0.fld.ifcr.cteif7 = cm_object_get_child_by_name(state->f0.reg.ifcr, "CTEIF7");

	// CCR1 bitfields.
	state->f0.fld.ccr1.en = cm_object_get_child_by_name(state->f0.reg.ccr1, "EN");
	state->f0.fld.ccr1.tcie = cm_object_get_child_by_name(state->f0.reg.ccr1, "TCIE");
	state->f0.fld.ccr1.htie = cm_object_get_child_by_name(state->f0.reg.ccr1, "HTIE");
	state->f0.fld.ccr1.teie = cm_object_get_child_by_name(state->f0.reg.ccr1, "TEIE");
	state->f0.fld.ccr1.dir = cm_object_get_child_by_name(state->f0.reg.ccr1, "DIR");
	state->f0.fld.ccr1.circ = cm_object_get_child_by_name(state->f0.reg.ccr1, "CIRC");
	state->f0.fld.ccr1.pinc = cm_object_get_child_by_name(state->f0.reg.ccr1, "PINC");
	state->f0.fld.ccr1.minc = cm_object_get_child_by_name(state->f0.reg.ccr1, "MINC");
	state->f0.fld.ccr1.psize = cm_object_get_child_by_name(state->f0.reg.ccr1, "PSIZE");
	state->f0.fld.ccr1.msize = cm_object_get_child_by_name(state->f0.reg.ccr1, "MSIZE");
	state->f0.fld.ccr1.pl = cm_object_get_child_by_name(state->f0.reg.ccr1, "PL");
	state->f0.fld.ccr1.mem2mem = cm_object_get_child_by_name(state->f0.reg.ccr1, "MEM2MEM");

	// CNDTR1 bitfields.
	state->f0.fld.cndtr1.ndt = cm_object_get_child_by_name(state->f0.reg.cndtr1, "NDT");

	// CPAR1 bitfields.
	state->f0.fld.cpar1.pa = cm_object_get_child_by_name(state->f0.reg.cpar1, "PA");

	// CMAR1 bitfields.
	state->f0.fld.cmar1.ma = cm_object_get_child_by_name(state->f0.reg.cmar1, "MA");

	// CCR2 bitfields.
	state->f0.fld.ccr2.en = cm_object_get_child_by_name(state->f0.reg.ccr2, "EN");
	state->f0.fld.ccr2.tcie = cm_object_get_child_by_name(state->f0.reg.ccr2, "TCIE");
	state->f0.fld.ccr2.htie = cm_object_get_child_by_name(state->f0.reg.ccr2, "HTIE");
	state->f0.fld.ccr2.teie = cm_object_get_child_by_name(state->f0.reg.ccr2, "TEIE");
	state->f0.fld.ccr2.dir = cm_object_get_child_by_name(state->f0.reg.ccr2, "DIR");
	state->f0.fld.ccr2.circ = cm_object_get_child_by_name(state->f0.reg.ccr2, "CIRC");
	state->f0.fld.ccr2.pinc = cm_object_get_child_by_name(state->f0.reg.ccr2, "PINC");
	state->f0.fld.ccr2.minc = cm_object_get_child_by_name(state->f0.reg.ccr2, "MINC");
	state->f0.fld.ccr2.psize = cm_object_get_child_by_name(state->f0.reg.ccr2, "PSIZE");
	state->f0.fld.ccr2.msize = cm_object_get_child_by_name(state->f0.reg.ccr2, "MSIZE");
	state->f0.fld.ccr2.pl = cm_object_get_child_by_name(state->f0.reg.ccr2, "PL");
	state->f0.fld.ccr2.mem2mem = cm_object_get_child_by_name(state->f0.reg.ccr2, "MEM2MEM");

	// CNDTR2 bitfields.
	state->f0.fld.cndtr2.ndt = cm_object_get_child_by_name(state->f0.reg.cndtr2, "NDT");

	// CPAR2 bitfields.
	state->f0.fld.cpar2.pa = cm_object_get_child_by_name(state->f0.reg.cpar2, "PA");

	// CMAR2 bitfields.
	state->f0.fld.cmar2.ma = cm_object_get_child_by_name(state->f0.reg.cmar2, "MA");

	// CCR3 bitfields.
	state->f0.fld.ccr3.en = cm_object_get_child_by_name(state->f0.reg.ccr3, "EN");
	state->f0.fld.ccr3.tcie = cm_object_get_child_by_name(state->f0.reg.ccr3, "TCIE");
	state->f0.fld.ccr3.htie = cm_object_get_child_by_name(state->f0.reg.ccr3, "HTIE");
	state->f0.fld.ccr3.teie = cm_object_get_child_by_name(state->f0.reg.ccr3, "TEIE");
	state->f0.fld.ccr3.dir = cm_object_get_child_by_name(state->f0.reg.ccr3, "DIR");
	state->f0.fld.ccr3.circ = cm_object_get_child_by_name(state->f0.reg.ccr3, "CIRC");
	state->f0.fld.ccr3.pinc = cm_object_get_child_by_name(state->f0.reg.ccr3, "PINC");
	state->f0.fld.ccr3.minc = cm_object_get_child_by_name(state->f0.reg.ccr3, "MINC");
	state->f0.fld.ccr3.psize = cm_object_get_child_by_name(state->f0.reg.ccr3, "PSIZE");
	state->f0.fld.ccr3.msize = cm_object_get_child_by_name(state->f0.reg.ccr3, "MSIZE");
	state->f0.fld.ccr3.pl = cm_object_get_child_by_name(state->f0.reg.ccr3, "PL");
	state->f0.fld.ccr3.mem2mem = cm_object_get_child_by_name(state->f0.reg.ccr3, "MEM2MEM");

	// CNDTR3 bitfields.
	state->f0.fld.cndtr3.ndt = cm_object_get_child_by_name(state->f0.reg.cndtr3, "NDT");

	// CPAR3 bitfields.
	state->f0.fld.cpar3.pa = cm_object_get_child_by_name(state->f0.reg.cpar3, "PA");

	// CMAR3 bitfields.
	state->f0.fld.cmar3.ma = cm_object_get_child_by_name(state->f0.reg.cmar3, "MA");

	// CCR4 bitfields.
	state->f0.fld.ccr4.en = cm_object_get_child_by_name(state->f0.reg.ccr4, "EN");
	state->f0.fld.ccr4.tcie = cm_object_get_child_by_name(state->f0.reg.ccr4, "TCIE");
	state->f0.fld.ccr4.htie = cm_object_get_child_by_name(state->f0.reg.ccr4, "HTIE");
	state->f0.fld.ccr4.teie = cm_object_get_child_by_name(state->f0.reg.ccr4, "TEIE");
	state->f0.fld.ccr4.dir = cm_object_get_child_by_name(state->f0.reg.ccr4, "DIR");
	state->f0.fld.ccr4.circ = cm_object_get_child_by_name(state->f0.reg.ccr4, "CIRC");
	state->f0.fld.ccr4.pinc = cm_object_get_child_by_name(state->f0.reg.ccr4, "PINC");
	state->f0.fld.ccr4.minc = cm_object_get_child_by_name(state->f0.reg.ccr4, "MINC");
	state->f0.fld.ccr4.psize = cm_object_get_child_by_name(state->f0.reg.ccr4, "PSIZE");
	state->f0.fld.ccr4.msize = cm_object_get_child_by_name(state->f0.reg.ccr4, "MSIZE");
	state->f0.fld.ccr4.pl = cm_object_get_child_by_name(state->f0.reg.ccr4, "PL");
	state->f0.fld.ccr4.mem2mem = cm_object_get_child_by_name(state->f0.reg.ccr4, "MEM2MEM");

	// CNDTR4 bitfields.
	state->f0.fld.cndtr4.ndt = cm_object_get_child_by_name(state->f0.reg.cndtr4, "NDT");

	// CPAR4 bitfields.
	state->f0.fld.cpar4.pa = cm_object_get_child_by_name(state->f0.reg.cpar4, "PA");

	// CMAR4 bitfields.
	state->f0.fld.cmar4.ma = cm_object_get_child_by_name(state->f0.reg.cmar4, "MA");

	// CCR5 bitfields.
	state->f0.fld.ccr5.en = cm_object_get_child_by_name(state->f0.reg.ccr5, "EN");
	state->f0.fld.ccr5.tcie = cm_object_get_child_by_name(state->f0.reg.ccr5, "TCIE");
	state->f0.fld.ccr5.htie = cm_object_get_child_by_name(state->f0.reg.ccr5, "HTIE");
	state->f0.fld.ccr5.teie = cm_object_get_child_by_name(state->f0.reg.ccr5, "TEIE");
	state->f0.fld.ccr5.dir = cm_object_get_child_by_name(state->f0.reg.ccr5, "DIR");
	state->f0.fld.ccr5.circ = cm_object_get_child_by_name(state->f0.reg.ccr5, "CIRC");
	state->f0.fld.ccr5.pinc = cm_object_get_child_by_name(state->f0.reg.ccr5, "PINC");
	state->f0.fld.ccr5.minc = cm_object_get_child_by_name(state->f0.reg.ccr5, "MINC");
	state->f0.fld.ccr5.psize = cm_object_get_child_by_name(state->f0.reg.ccr5, "PSIZE");
	state->f0.fld.ccr5.msize = cm_object_get_child_by_name(state->f0.reg.ccr5, "MSIZE");
	state->f0.fld.ccr5.pl = cm_object_get_child_by_name(state->f0.reg.ccr5, "PL");
	state->f0.fld.ccr5.mem2mem = cm_object_get_child_by_name(state->f0.reg.ccr5, "MEM2MEM");

	// CNDTR5 bitfields.
	state->f0.fld.cndtr5.ndt = cm_object_get_child_by_name(state->f0.reg.cndtr5, "NDT");

	// CPAR5 bitfields.
	state->f0.fld.cpar5.pa = cm_object_get_child_by_name(state->f0.reg.cpar5, "PA");

	// CMAR5 bitfields.
	state->f0.fld.cmar5.ma = cm_object_get_child_by_name(state->f0.reg.cmar5, "MA");

	// CCR6 bitfields.
	state->f0.fld.ccr6.en = cm_object_get_child_by_name(state->f0.reg.ccr6, "EN");
	state->f0.fld.ccr6.tcie = cm_object_get_child_by_name(state->f0.reg.ccr6, "TCIE");
	state->f0.fld.ccr6.htie = cm_object_get_child_by_name(state->f0.reg.ccr6, "HTIE");
	state->f0.fld.ccr6.teie = cm_object_get_child_by_name(state->f0.reg.ccr6, "TEIE");
	state->f0.fld.ccr6.dir = cm_object_get_child_by_name(state->f0.reg.ccr6, "DIR");
	state->f0.fld.ccr6.circ = cm_object_get_child_by_name(state->f0.reg.ccr6, "CIRC");
	state->f0.fld.ccr6.pinc = cm_object_get_child_by_name(state->f0.reg.ccr6, "PINC");
	state->f0.fld.ccr6.minc = cm_object_get_child_by_name(state->f0.reg.ccr6, "MINC");
	state->f0.fld.ccr6.psize = cm_object_get_child_by_name(state->f0.reg.ccr6, "PSIZE");
	state->f0.fld.ccr6.msize = cm_object_get_child_by_name(state->f0.reg.ccr6, "MSIZE");
	state->f0.fld.ccr6.pl = cm_object_get_child_by_name(state->f0.reg.ccr6, "PL");
	state->f0.fld.ccr6.mem2mem = cm_object_get_child_by_name(state->f0.reg.ccr6, "MEM2MEM");

	// CNDTR6 bitfields.
	state->f0.fld.cndtr6.ndt = cm_object_get_child_by_name(state->f0.reg.cndtr6, "NDT");

	// CPAR6 bitfields.
	state->f0.fld.cpar6.pa = cm_object_get_child_by_name(state->f0.reg.cpar6, "PA");

	// CMAR6 bitfields.
	state->f0.fld.cmar6.ma = cm_object_get_child_by_name(state->f0.reg.cmar6, "MA");

	// CCR7 bitfields.
	state->f0.fld.ccr7.en = cm_object_get_child_by_name(state->f0.reg.ccr7, "EN");
	state->f0.fld.ccr7.tcie = cm_object_get_child_by_name(state->f0.reg.ccr7, "TCIE");
	state->f0.fld.ccr7.htie = cm_object_get_child_by_name(state->f0.reg.ccr7, "HTIE");
	state->f0.fld.ccr7.teie = cm_object_get_child_by_name(state->f0.reg.ccr7, "TEIE");
	state->f0.fld.ccr7.dir = cm_object_get_child_by_name(state->f0.reg.ccr7, "DIR");
	state->f0.fld.ccr7.circ = cm_object_get_child_by_name(state->f0.reg.ccr7, "CIRC");
	state->f0.fld.ccr7.pinc = cm_object_get_child_by_name(state->f0.reg.ccr7, "PINC");
	state->f0.fld.ccr7.minc = cm_object_get_child_by_name(state->f0.reg.ccr7, "MINC");
	state->f0.fld.ccr7.psize = cm_object_get_child_by_name(state->f0.reg.ccr7, "PSIZE");
	state->f0.fld.ccr7.msize = cm_object_get_child_by_name(state->f0.reg.ccr7, "MSIZE");
	state->f0.fld.ccr7.pl = cm_object_get_child_by_name(state->f0.reg.ccr7, "PL");
	state->f0.fld.ccr7.mem2mem = cm_object_get_child_by_name(state->f0.reg.ccr7, "MEM2MEM");

	// CNDTR7 bitfields.
	state->f0.fld.cndtr7.ndt = cm_object_get_child_by_name(state->f0.reg.cndtr7, "NDT");

	// CPAR7 bitfields.
	state->f0.fld.cpar7.pa = cm_object_get_child_by_name(state->f0.reg.cpar7, "PA");

	// CMAR7 bitfields.
	state->f0.fld.cmar7.ma = cm_object_get_child_by_name(state->f0.reg.cmar7, "MA");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// RCC (Reset and clock control) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F0 RCC (Reset and clock control) registers.
		struct {
			Object *cr; // 0x0 Clock control register
			Object *cfgr; // 0x4 Clock configuration register (RCC_CFGR)
			Object *cir; // 0x8 Clock interrupt register (RCC_CIR)
			Object *apb2rstr; // 0xC APB2 peripheral reset register (RCC_APB2RSTR)
			Object *apb1rstr; // 0x10 APB1 peripheral reset register (RCC_APB1RSTR)
			Object *ahbenr; // 0x14 AHB Peripheral Clock enable register (RCC_AHBENR)
			Object *apb2enr; // 0x18 APB2 peripheral clock enable register (RCC_APB2ENR)
			Object *apb1enr; // 0x1C APB1 peripheral clock enable register (RCC_APB1ENR)
			Object *bdcr; // 0x20 Backup domain control register (RCC_BDCR)
			Object *csr; // 0x24 Control/status register (RCC_CSR)
			Object *ahbrstr; // 0x28 AHB peripheral reset register
			Object *cfgr2; // 0x2C Clock configuration register 2
			Object *cfgr3; // 0x30 Clock configuration register 3
			Object *cr2; // 0x34 Clock control register 2
		} reg;

		struct {

			// CR (Clock control register) bitfields.
			struct {
				Object *hsion; // [0:0] Internal High Speed clock enable
				Object *hsirdy; // [1:1] Internal High Speed clock ready flag
				Object *hsitrim; // [3:7] Internal High Speed clock trimming
				Object *hsical; // [8:15] Internal High Speed clock Calibration
				Object *hseon; // [16:16] External High Speed clock enable
				Object *hserdy; // [17:17] External High Speed clock ready flag
				Object *hsebyp; // [18:18] External High Speed clock Bypass
				Object *csson; // [19:19] Clock Security System enable
				Object *pllon; // [24:24] PLL enable
				Object *pllrdy; // [25:25] PLL clock ready flag
			} cr;

			// CFGR (Clock configuration register (RCC_CFGR)) bitfields.
			struct {
				Object *sw; // [0:1] System clock Switch
				Object *sws; // [2:3] System Clock Switch Status
				Object *hpre; // [4:7] AHB prescaler
				Object *ppre; // [8:10] APB Low speed prescaler (APB1)
				Object *adcpre; // [14:14] ADC prescaler
				Object *pllsrc; // [15:16] PLL input clock source
				Object *pllxtpre; // [17:17] HSE divider for PLL entry
				Object *pllmul; // [18:21] PLL Multiplication Factor
				Object *mco; // [24:26] Microcontroller clock output
				Object *mcopre; // [28:30] Microcontroller Clock Output Prescaler
				Object *pllnodiv; // [31:31] PLL clock not divided for MCO
			} cfgr;

			// CIR (Clock interrupt register (RCC_CIR)) bitfields.
			struct {
				Object *lsirdyf; // [0:0] LSI Ready Interrupt flag
				Object *lserdyf; // [1:1] LSE Ready Interrupt flag
				Object *hsirdyf; // [2:2] HSI Ready Interrupt flag
				Object *hserdyf; // [3:3] HSE Ready Interrupt flag
				Object *pllrdyf; // [4:4] PLL Ready Interrupt flag
				Object *hsi14rdyf; // [5:5] HSI14 ready interrupt flag
				Object *hsi48rdyf; // [6:6] HSI48 ready interrupt flag
				Object *cssf; // [7:7] Clock Security System Interrupt flag
				Object *lsirdyie; // [8:8] LSI Ready Interrupt Enable
				Object *lserdyie; // [9:9] LSE Ready Interrupt Enable
				Object *hsirdyie; // [10:10] HSI Ready Interrupt Enable
				Object *hserdyie; // [11:11] HSE Ready Interrupt Enable
				Object *pllrdyie; // [12:12] PLL Ready Interrupt Enable
				Object *hsi14rdye; // [13:13] HSI14 ready interrupt enable
				Object *hsi48rdyie; // [14:14] HSI48 ready interrupt enable
				Object *lsirdyc; // [16:16] LSI Ready Interrupt Clear
				Object *lserdyc; // [17:17] LSE Ready Interrupt Clear
				Object *hsirdyc; // [18:18] HSI Ready Interrupt Clear
				Object *hserdyc; // [19:19] HSE Ready Interrupt Clear
				Object *pllrdyc; // [20:20] PLL Ready Interrupt Clear
				Object *hsi14rdyc; // [21:21] HSI 14 MHz Ready Interrupt Clear
				Object *hsi48rdyc; // [22:22] HSI48 Ready Interrupt Clear
				Object *cssc; // [23:23] Clock security system interrupt clear
			} cir;

			// APB2RSTR (APB2 peripheral reset register (RCC_APB2RSTR)) bitfields.
			struct {
				Object *syscfgrst; // [0:0] SYSCFG and COMP reset
				Object *adcrst; // [9:9] ADC interface reset
				Object *tim1rst; // [11:11] TIM1 timer reset
				Object *spi1rst; // [12:12] SPI 1 reset
				Object *usart1rst; // [14:14] USART1 reset
				Object *tim15rst; // [16:16] TIM15 timer reset
				Object *tim16rst; // [17:17] TIM16 timer reset
				Object *tim17rst; // [18:18] TIM17 timer reset
				Object *dbgmcurst; // [22:22] Debug MCU reset
			} apb2rstr;

			// APB1RSTR (APB1 peripheral reset register (RCC_APB1RSTR)) bitfields.
			struct {
				Object *tim2rst; // [0:0] Timer 2 reset
				Object *tim3rst; // [1:1] Timer 3 reset
				Object *tim6rst; // [4:4] Timer 6 reset
				Object *tim7rst; // [5:5] TIM7 timer reset
				Object *tim14rst; // [8:8] Timer 14 reset
				Object *wwdgrst; // [11:11] Window watchdog reset
				Object *spi2rst; // [14:14] SPI2 reset
				Object *usart2rst; // [17:17] USART 2 reset
				Object *usart3rst; // [18:18] USART3 reset
				Object *usart4rst; // [19:19] USART4 reset
				Object *usart5rst; // [20:20] USART5 reset
				Object *i2c1rst; // [21:21] I2C1 reset
				Object *i2c2rst; // [22:22] I2C2 reset
				Object *usbrst; // [23:23] USB interface reset
				Object *canrst; // [25:25] CAN interface reset
				Object *crsrst; // [27:27] Clock Recovery System interface reset
				Object *pwrrst; // [28:28] Power interface reset
				Object *dacrst; // [29:29] DAC interface reset
				Object *cecrst; // [30:30] HDMI CEC reset
			} apb1rstr;

			// AHBENR (AHB Peripheral Clock enable register (RCC_AHBENR)) bitfields.
			struct {
				Object *dma1en; // [0:0] DMA1 clock enable
				Object *dma2en; // [1:1] DMA2 clock enable
				Object *sramen; // [2:2] SRAM interface clock enable
				Object *flitfen; // [4:4] FLITF clock enable
				Object *crcen; // [6:6] CRC clock enable
				Object *iopaen; // [17:17] I/O port A clock enable
				Object *iopben; // [18:18] I/O port B clock enable
				Object *iopcen; // [19:19] I/O port C clock enable
				Object *iopden; // [20:20] I/O port D clock enable
				Object *iopfen; // [22:22] I/O port F clock enable
				Object *tscen; // [24:24] Touch sensing controller clock enable
			} ahbenr;

			// APB2ENR (APB2 peripheral clock enable register (RCC_APB2ENR)) bitfields.
			struct {
				Object *syscfgen; // [0:0] SYSCFG clock enable
				Object *adcen; // [9:9] ADC 1 interface clock enable
				Object *tim1en; // [11:11] TIM1 Timer clock enable
				Object *spi1en; // [12:12] SPI 1 clock enable
				Object *usart1en; // [14:14] USART1 clock enable
				Object *tim15en; // [16:16] TIM15 timer clock enable
				Object *tim16en; // [17:17] TIM16 timer clock enable
				Object *tim17en; // [18:18] TIM17 timer clock enable
				Object *dbgmcuen; // [22:22] MCU debug module clock enable
			} apb2enr;

			// APB1ENR (APB1 peripheral clock enable register (RCC_APB1ENR)) bitfields.
			struct {
				Object *tim2en; // [0:0] Timer 2 clock enable
				Object *tim3en; // [1:1] Timer 3 clock enable
				Object *tim6en; // [4:4] Timer 6 clock enable
				Object *tim7en; // [5:5] TIM7 timer clock enable
				Object *tim14en; // [8:8] Timer 14 clock enable
				Object *wwdgen; // [11:11] Window watchdog clock enable
				Object *spi2en; // [14:14] SPI 2 clock enable
				Object *usart2en; // [17:17] USART 2 clock enable
				Object *usart3en; // [18:18] USART3 clock enable
				Object *usart4en; // [19:19] USART4 clock enable
				Object *usart5en; // [20:20] USART5 clock enable
				Object *i2c1en; // [21:21] I2C 1 clock enable
				Object *i2c2en; // [22:22] I2C 2 clock enable
				Object *usbrst; // [23:23] USB interface clock enable
				Object *canen; // [25:25] CAN interface clock enable
				Object *crsen; // [27:27] Clock Recovery System interface clock enable
				Object *pwren; // [28:28] Power interface clock enable
				Object *dacen; // [29:29] DAC interface clock enable
				Object *cecen; // [30:30] HDMI CEC interface clock enable
			} apb1enr;

			// BDCR (Backup domain control register (RCC_BDCR)) bitfields.
			struct {
				Object *lseon; // [0:0] External Low Speed oscillator enable
				Object *lserdy; // [1:1] External Low Speed oscillator ready
				Object *lsebyp; // [2:2] External Low Speed oscillator bypass
				Object *lsedrv; // [3:4] LSE oscillator drive capability
				Object *rtcsel; // [8:9] RTC clock source selection
				Object *rtcen; // [15:15] RTC clock enable
				Object *bdrst; // [16:16] Backup domain software reset
			} bdcr;

			// CSR (Control/status register (RCC_CSR)) bitfields.
			struct {
				Object *lsion; // [0:0] Internal low speed oscillator enable
				Object *lsirdy; // [1:1] Internal low speed oscillator ready
				Object *rmvf; // [24:24] Remove reset flag
				Object *oblrstf; // [25:25] Option byte loader reset flag
				Object *pinrstf; // [26:26] PIN reset flag
				Object *porrstf; // [27:27] POR/PDR reset flag
				Object *sftrstf; // [28:28] Software reset flag
				Object *iwdgrstf; // [29:29] Independent watchdog reset flag
				Object *wwdgrstf; // [30:30] Window watchdog reset flag
				Object *lpwrrstf; // [31:31] Low-power reset flag
			} csr;

			// AHBRSTR (AHB peripheral reset register) bitfields.
			struct {
				Object *ioparst; // [17:17] I/O port A reset
				Object *iopbrst; // [18:18] I/O port B reset
				Object *iopcrst; // [19:19] I/O port C reset
				Object *iopdrst; // [20:20] I/O port D reset
				Object *iopfrst; // [22:22] I/O port F reset
				Object *tscrst; // [24:24] Touch sensing controller reset
			} ahbrstr;

			// CFGR2 (Clock configuration register 2) bitfields.
			struct {
				Object *prediv; // [0:3] PREDIV division factor
			} cfgr2;

			// CFGR3 (Clock configuration register 3) bitfields.
			struct {
				Object *usart1sw; // [0:1] USART1 clock source selection
				Object *i2c1sw; // [4:4] I2C1 clock source selection
				Object *cecsw; // [6:6] HDMI CEC clock source selection
				Object *usbsw; // [7:7] USB clock source selection
				Object *adcsw; // [8:8] ADC clock source selection
				Object *usart2sw; // [16:17] USART2 clock source selection
			} cfgr3;

			// CR2 (Clock control register 2) bitfields.
			struct {
				Object *hsi14on; // [0:0] HSI14 clock enable
				Object *hsi14rdy; // [1:1] HR14 clock ready flag
				Object *hsi14dis; // [2:2] HSI14 clock request from ADC disable
				Object *hsi14trim; // [3:7] HSI14 clock trimming
				Object *hsi14cal; // [8:15] HSI14 clock calibration
				Object *hsi48on; // [16:16] HSI48 clock enable
				Object *hsi48rdy; // [17:17] HSI48 clock ready flag
				Object *hsi48cal; // [24:24] HSI48 factory clock calibration
			} cr2;
		} fld;
	} f0;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32RCCState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_rcc_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32RCCState *state = STM32_RCC_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f0.reg.cr = cm_object_get_child_by_name(obj, "CR");
	state->f0.reg.cfgr = cm_object_get_child_by_name(obj, "CFGR");
	state->f0.reg.cir = cm_object_get_child_by_name(obj, "CIR");
	state->f0.reg.apb2rstr = cm_object_get_child_by_name(obj, "APB2RSTR");
	state->f0.reg.apb1rstr = cm_object_get_child_by_name(obj, "APB1RSTR");
	state->f0.reg.ahbenr = cm_object_get_child_by_name(obj, "AHBENR");
	state->f0.reg.apb2enr = cm_object_get_child_by_name(obj, "APB2ENR");
	state->f0.reg.apb1enr = cm_object_get_child_by_name(obj, "APB1ENR");
	state->f0.reg.bdcr = cm_object_get_child_by_name(obj, "BDCR");
	state->f0.reg.csr = cm_object_get_child_by_name(obj, "CSR");
	state->f0.reg.ahbrstr = cm_object_get_child_by_name(obj, "AHBRSTR");
	state->f0.reg.cfgr2 = cm_object_get_child_by_name(obj, "CFGR2");
	state->f0.reg.cfgr3 = cm_object_get_child_by_name(obj, "CFGR3");
	state->f0.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");

	// CR bitfields.
	state->f0.fld.cr.hsion = cm_object_get_child_by_name(state->f0.reg.cr, "HSION");
	state->f0.fld.cr.hsirdy = cm_object_get_child_by_name(state->f0.reg.cr, "HSIRDY");
	state->f0.fld.cr.hsitrim = cm_object_get_child_by_name(state->f0.reg.cr, "HSITRIM");
	state->f0.fld.cr.hsical = cm_object_get_child_by_name(state->f0.reg.cr, "HSICAL");
	state->f0.fld.cr.hseon = cm_object_get_child_by_name(state->f0.reg.cr, "HSEON");
	state->f0.fld.cr.hserdy = cm_object_get_child_by_name(state->f0.reg.cr, "HSERDY");
	state->f0.fld.cr.hsebyp = cm_object_get_child_by_name(state->f0.reg.cr, "HSEBYP");
	state->f0.fld.cr.csson = cm_object_get_child_by_name(state->f0.reg.cr, "CSSON");
	state->f0.fld.cr.pllon = cm_object_get_child_by_name(state->f0.reg.cr, "PLLON");
	state->f0.fld.cr.pllrdy = cm_object_get_child_by_name(state->f0.reg.cr, "PLLRDY");

	// CFGR bitfields.
	state->f0.fld.cfgr.sw = cm_object_get_child_by_name(state->f0.reg.cfgr, "SW");
	state->f0.fld.cfgr.sws = cm_object_get_child_by_name(state->f0.reg.cfgr, "SWS");
	state->f0.fld.cfgr.hpre = cm_object_get_child_by_name(state->f0.reg.cfgr, "HPRE");
	state->f0.fld.cfgr.ppre = cm_object_get_child_by_name(state->f0.reg.cfgr, "PPRE");
	state->f0.fld.cfgr.adcpre = cm_object_get_child_by_name(state->f0.reg.cfgr, "ADCPRE");
	state->f0.fld.cfgr.pllsrc = cm_object_get_child_by_name(state->f0.reg.cfgr, "PLLSRC");
	state->f0.fld.cfgr.pllxtpre = cm_object_get_child_by_name(state->f0.reg.cfgr, "PLLXTPRE");
	state->f0.fld.cfgr.pllmul = cm_object_get_child_by_name(state->f0.reg.cfgr, "PLLMUL");
	state->f0.fld.cfgr.mco = cm_object_get_child_by_name(state->f0.reg.cfgr, "MCO");
	state->f0.fld.cfgr.mcopre = cm_object_get_child_by_name(state->f0.reg.cfgr, "MCOPRE");
	state->f0.fld.cfgr.pllnodiv = cm_object_get_child_by_name(state->f0.reg.cfgr, "PLLNODIV");

	// CIR bitfields.
	state->f0.fld.cir.lsirdyf = cm_object_get_child_by_name(state->f0.reg.cir, "LSIRDYF");
	state->f0.fld.cir.lserdyf = cm_object_get_child_by_name(state->f0.reg.cir, "LSERDYF");
	state->f0.fld.cir.hsirdyf = cm_object_get_child_by_name(state->f0.reg.cir, "HSIRDYF");
	state->f0.fld.cir.hserdyf = cm_object_get_child_by_name(state->f0.reg.cir, "HSERDYF");
	state->f0.fld.cir.pllrdyf = cm_object_get_child_by_name(state->f0.reg.cir, "PLLRDYF");
	state->f0.fld.cir.hsi14rdyf = cm_object_get_child_by_name(state->f0.reg.cir, "HSI14RDYF");
	state->f0.fld.cir.hsi48rdyf = cm_object_get_child_by_name(state->f0.reg.cir, "HSI48RDYF");
	state->f0.fld.cir.cssf = cm_object_get_child_by_name(state->f0.reg.cir, "CSSF");
	state->f0.fld.cir.lsirdyie = cm_object_get_child_by_name(state->f0.reg.cir, "LSIRDYIE");
	state->f0.fld.cir.lserdyie = cm_object_get_child_by_name(state->f0.reg.cir, "LSERDYIE");
	state->f0.fld.cir.hsirdyie = cm_object_get_child_by_name(state->f0.reg.cir, "HSIRDYIE");
	state->f0.fld.cir.hserdyie = cm_object_get_child_by_name(state->f0.reg.cir, "HSERDYIE");
	state->f0.fld.cir.pllrdyie = cm_object_get_child_by_name(state->f0.reg.cir, "PLLRDYIE");
	state->f0.fld.cir.hsi14rdye = cm_object_get_child_by_name(state->f0.reg.cir, "HSI14RDYE");
	state->f0.fld.cir.hsi48rdyie = cm_object_get_child_by_name(state->f0.reg.cir, "HSI48RDYIE");
	state->f0.fld.cir.lsirdyc = cm_object_get_child_by_name(state->f0.reg.cir, "LSIRDYC");
	state->f0.fld.cir.lserdyc = cm_object_get_child_by_name(state->f0.reg.cir, "LSERDYC");
	state->f0.fld.cir.hsirdyc = cm_object_get_child_by_name(state->f0.reg.cir, "HSIRDYC");
	state->f0.fld.cir.hserdyc = cm_object_get_child_by_name(state->f0.reg.cir, "HSERDYC");
	state->f0.fld.cir.pllrdyc = cm_object_get_child_by_name(state->f0.reg.cir, "PLLRDYC");
	state->f0.fld.cir.hsi14rdyc = cm_object_get_child_by_name(state->f0.reg.cir, "HSI14RDYC");
	state->f0.fld.cir.hsi48rdyc = cm_object_get_child_by_name(state->f0.reg.cir, "HSI48RDYC");
	state->f0.fld.cir.cssc = cm_object_get_child_by_name(state->f0.reg.cir, "CSSC");

	// APB2RSTR bitfields.
	state->f0.fld.apb2rstr.syscfgrst = cm_object_get_child_by_name(state->f0.reg.apb2rstr, "SYSCFGRST");
	state->f0.fld.apb2rstr.adcrst = cm_object_get_child_by_name(state->f0.reg.apb2rstr, "ADCRST");
	state->f0.fld.apb2rstr.tim1rst = cm_object_get_child_by_name(state->f0.reg.apb2rstr, "TIM1RST");
	state->f0.fld.apb2rstr.spi1rst = cm_object_get_child_by_name(state->f0.reg.apb2rstr, "SPI1RST");
	state->f0.fld.apb2rstr.usart1rst = cm_object_get_child_by_name(state->f0.reg.apb2rstr, "USART1RST");
	state->f0.fld.apb2rstr.tim15rst = cm_object_get_child_by_name(state->f0.reg.apb2rstr, "TIM15RST");
	state->f0.fld.apb2rstr.tim16rst = cm_object_get_child_by_name(state->f0.reg.apb2rstr, "TIM16RST");
	state->f0.fld.apb2rstr.tim17rst = cm_object_get_child_by_name(state->f0.reg.apb2rstr, "TIM17RST");
	state->f0.fld.apb2rstr.dbgmcurst = cm_object_get_child_by_name(state->f0.reg.apb2rstr, "DBGMCURST");

	// APB1RSTR bitfields.
	state->f0.fld.apb1rstr.tim2rst = cm_object_get_child_by_name(state->f0.reg.apb1rstr, "TIM2RST");
	state->f0.fld.apb1rstr.tim3rst = cm_object_get_child_by_name(state->f0.reg.apb1rstr, "TIM3RST");
	state->f0.fld.apb1rstr.tim6rst = cm_object_get_child_by_name(state->f0.reg.apb1rstr, "TIM6RST");
	state->f0.fld.apb1rstr.tim7rst = cm_object_get_child_by_name(state->f0.reg.apb1rstr, "TIM7RST");
	state->f0.fld.apb1rstr.tim14rst = cm_object_get_child_by_name(state->f0.reg.apb1rstr, "TIM14RST");
	state->f0.fld.apb1rstr.wwdgrst = cm_object_get_child_by_name(state->f0.reg.apb1rstr, "WWDGRST");
	state->f0.fld.apb1rstr.spi2rst = cm_object_get_child_by_name(state->f0.reg.apb1rstr, "SPI2RST");
	state->f0.fld.apb1rstr.usart2rst = cm_object_get_child_by_name(state->f0.reg.apb1rstr, "USART2RST");
	state->f0.fld.apb1rstr.usart3rst = cm_object_get_child_by_name(state->f0.reg.apb1rstr, "USART3RST");
	state->f0.fld.apb1rstr.usart4rst = cm_object_get_child_by_name(state->f0.reg.apb1rstr, "USART4RST");
	state->f0.fld.apb1rstr.usart5rst = cm_object_get_child_by_name(state->f0.reg.apb1rstr, "USART5RST");
	state->f0.fld.apb1rstr.i2c1rst = cm_object_get_child_by_name(state->f0.reg.apb1rstr, "I2C1RST");
	state->f0.fld.apb1rstr.i2c2rst = cm_object_get_child_by_name(state->f0.reg.apb1rstr, "I2C2RST");
	state->f0.fld.apb1rstr.usbrst = cm_object_get_child_by_name(state->f0.reg.apb1rstr, "USBRST");
	state->f0.fld.apb1rstr.canrst = cm_object_get_child_by_name(state->f0.reg.apb1rstr, "CANRST");
	state->f0.fld.apb1rstr.crsrst = cm_object_get_child_by_name(state->f0.reg.apb1rstr, "CRSRST");
	state->f0.fld.apb1rstr.pwrrst = cm_object_get_child_by_name(state->f0.reg.apb1rstr, "PWRRST");
	state->f0.fld.apb1rstr.dacrst = cm_object_get_child_by_name(state->f0.reg.apb1rstr, "DACRST");
	state->f0.fld.apb1rstr.cecrst = cm_object_get_child_by_name(state->f0.reg.apb1rstr, "CECRST");

	// AHBENR bitfields.
	state->f0.fld.ahbenr.dma1en = cm_object_get_child_by_name(state->f0.reg.ahbenr, "DMA1EN");
	state->f0.fld.ahbenr.dma2en = cm_object_get_child_by_name(state->f0.reg.ahbenr, "DMA2EN");
	state->f0.fld.ahbenr.sramen = cm_object_get_child_by_name(state->f0.reg.ahbenr, "SRAMEN");
	state->f0.fld.ahbenr.flitfen = cm_object_get_child_by_name(state->f0.reg.ahbenr, "FLITFEN");
	state->f0.fld.ahbenr.crcen = cm_object_get_child_by_name(state->f0.reg.ahbenr, "CRCEN");
	state->f0.fld.ahbenr.iopaen = cm_object_get_child_by_name(state->f0.reg.ahbenr, "IOPAEN");
	state->f0.fld.ahbenr.iopben = cm_object_get_child_by_name(state->f0.reg.ahbenr, "IOPBEN");
	state->f0.fld.ahbenr.iopcen = cm_object_get_child_by_name(state->f0.reg.ahbenr, "IOPCEN");
	state->f0.fld.ahbenr.iopden = cm_object_get_child_by_name(state->f0.reg.ahbenr, "IOPDEN");
	state->f0.fld.ahbenr.iopfen = cm_object_get_child_by_name(state->f0.reg.ahbenr, "IOPFEN");
	state->f0.fld.ahbenr.tscen = cm_object_get_child_by_name(state->f0.reg.ahbenr, "TSCEN");

	// APB2ENR bitfields.
	state->f0.fld.apb2enr.syscfgen = cm_object_get_child_by_name(state->f0.reg.apb2enr, "SYSCFGEN");
	state->f0.fld.apb2enr.adcen = cm_object_get_child_by_name(state->f0.reg.apb2enr, "ADCEN");
	state->f0.fld.apb2enr.tim1en = cm_object_get_child_by_name(state->f0.reg.apb2enr, "TIM1EN");
	state->f0.fld.apb2enr.spi1en = cm_object_get_child_by_name(state->f0.reg.apb2enr, "SPI1EN");
	state->f0.fld.apb2enr.usart1en = cm_object_get_child_by_name(state->f0.reg.apb2enr, "USART1EN");
	state->f0.fld.apb2enr.tim15en = cm_object_get_child_by_name(state->f0.reg.apb2enr, "TIM15EN");
	state->f0.fld.apb2enr.tim16en = cm_object_get_child_by_name(state->f0.reg.apb2enr, "TIM16EN");
	state->f0.fld.apb2enr.tim17en = cm_object_get_child_by_name(state->f0.reg.apb2enr, "TIM17EN");
	state->f0.fld.apb2enr.dbgmcuen = cm_object_get_child_by_name(state->f0.reg.apb2enr, "DBGMCUEN");

	// APB1ENR bitfields.
	state->f0.fld.apb1enr.tim2en = cm_object_get_child_by_name(state->f0.reg.apb1enr, "TIM2EN");
	state->f0.fld.apb1enr.tim3en = cm_object_get_child_by_name(state->f0.reg.apb1enr, "TIM3EN");
	state->f0.fld.apb1enr.tim6en = cm_object_get_child_by_name(state->f0.reg.apb1enr, "TIM6EN");
	state->f0.fld.apb1enr.tim7en = cm_object_get_child_by_name(state->f0.reg.apb1enr, "TIM7EN");
	state->f0.fld.apb1enr.tim14en = cm_object_get_child_by_name(state->f0.reg.apb1enr, "TIM14EN");
	state->f0.fld.apb1enr.wwdgen = cm_object_get_child_by_name(state->f0.reg.apb1enr, "WWDGEN");
	state->f0.fld.apb1enr.spi2en = cm_object_get_child_by_name(state->f0.reg.apb1enr, "SPI2EN");
	state->f0.fld.apb1enr.usart2en = cm_object_get_child_by_name(state->f0.reg.apb1enr, "USART2EN");
	state->f0.fld.apb1enr.usart3en = cm_object_get_child_by_name(state->f0.reg.apb1enr, "USART3EN");
	state->f0.fld.apb1enr.usart4en = cm_object_get_child_by_name(state->f0.reg.apb1enr, "USART4EN");
	state->f0.fld.apb1enr.usart5en = cm_object_get_child_by_name(state->f0.reg.apb1enr, "USART5EN");
	state->f0.fld.apb1enr.i2c1en = cm_object_get_child_by_name(state->f0.reg.apb1enr, "I2C1EN");
	state->f0.fld.apb1enr.i2c2en = cm_object_get_child_by_name(state->f0.reg.apb1enr, "I2C2EN");
	state->f0.fld.apb1enr.usbrst = cm_object_get_child_by_name(state->f0.reg.apb1enr, "USBRST");
	state->f0.fld.apb1enr.canen = cm_object_get_child_by_name(state->f0.reg.apb1enr, "CANEN");
	state->f0.fld.apb1enr.crsen = cm_object_get_child_by_name(state->f0.reg.apb1enr, "CRSEN");
	state->f0.fld.apb1enr.pwren = cm_object_get_child_by_name(state->f0.reg.apb1enr, "PWREN");
	state->f0.fld.apb1enr.dacen = cm_object_get_child_by_name(state->f0.reg.apb1enr, "DACEN");
	state->f0.fld.apb1enr.cecen = cm_object_get_child_by_name(state->f0.reg.apb1enr, "CECEN");

	// BDCR bitfields.
	state->f0.fld.bdcr.lseon = cm_object_get_child_by_name(state->f0.reg.bdcr, "LSEON");
	state->f0.fld.bdcr.lserdy = cm_object_get_child_by_name(state->f0.reg.bdcr, "LSERDY");
	state->f0.fld.bdcr.lsebyp = cm_object_get_child_by_name(state->f0.reg.bdcr, "LSEBYP");
	state->f0.fld.bdcr.lsedrv = cm_object_get_child_by_name(state->f0.reg.bdcr, "LSEDRV");
	state->f0.fld.bdcr.rtcsel = cm_object_get_child_by_name(state->f0.reg.bdcr, "RTCSEL");
	state->f0.fld.bdcr.rtcen = cm_object_get_child_by_name(state->f0.reg.bdcr, "RTCEN");
	state->f0.fld.bdcr.bdrst = cm_object_get_child_by_name(state->f0.reg.bdcr, "BDRST");

	// CSR bitfields.
	state->f0.fld.csr.lsion = cm_object_get_child_by_name(state->f0.reg.csr, "LSION");
	state->f0.fld.csr.lsirdy = cm_object_get_child_by_name(state->f0.reg.csr, "LSIRDY");
	state->f0.fld.csr.rmvf = cm_object_get_child_by_name(state->f0.reg.csr, "RMVF");
	state->f0.fld.csr.oblrstf = cm_object_get_child_by_name(state->f0.reg.csr, "OBLRSTF");
	state->f0.fld.csr.pinrstf = cm_object_get_child_by_name(state->f0.reg.csr, "PINRSTF");
	state->f0.fld.csr.porrstf = cm_object_get_child_by_name(state->f0.reg.csr, "PORRSTF");
	state->f0.fld.csr.sftrstf = cm_object_get_child_by_name(state->f0.reg.csr, "SFTRSTF");
	state->f0.fld.csr.iwdgrstf = cm_object_get_child_by_name(state->f0.reg.csr, "IWDGRSTF");
	state->f0.fld.csr.wwdgrstf = cm_object_get_child_by_name(state->f0.reg.csr, "WWDGRSTF");
	state->f0.fld.csr.lpwrrstf = cm_object_get_child_by_name(state->f0.reg.csr, "LPWRRSTF");

	// AHBRSTR bitfields.
	state->f0.fld.ahbrstr.ioparst = cm_object_get_child_by_name(state->f0.reg.ahbrstr, "IOPARST");
	state->f0.fld.ahbrstr.iopbrst = cm_object_get_child_by_name(state->f0.reg.ahbrstr, "IOPBRST");
	state->f0.fld.ahbrstr.iopcrst = cm_object_get_child_by_name(state->f0.reg.ahbrstr, "IOPCRST");
	state->f0.fld.ahbrstr.iopdrst = cm_object_get_child_by_name(state->f0.reg.ahbrstr, "IOPDRST");
	state->f0.fld.ahbrstr.iopfrst = cm_object_get_child_by_name(state->f0.reg.ahbrstr, "IOPFRST");
	state->f0.fld.ahbrstr.tscrst = cm_object_get_child_by_name(state->f0.reg.ahbrstr, "TSCRST");

	// CFGR2 bitfields.
	state->f0.fld.cfgr2.prediv = cm_object_get_child_by_name(state->f0.reg.cfgr2, "PREDIV");

	// CFGR3 bitfields.
	state->f0.fld.cfgr3.usart1sw = cm_object_get_child_by_name(state->f0.reg.cfgr3, "USART1SW");
	state->f0.fld.cfgr3.i2c1sw = cm_object_get_child_by_name(state->f0.reg.cfgr3, "I2C1SW");
	state->f0.fld.cfgr3.cecsw = cm_object_get_child_by_name(state->f0.reg.cfgr3, "CECSW");
	state->f0.fld.cfgr3.usbsw = cm_object_get_child_by_name(state->f0.reg.cfgr3, "USBSW");
	state->f0.fld.cfgr3.adcsw = cm_object_get_child_by_name(state->f0.reg.cfgr3, "ADCSW");
	state->f0.fld.cfgr3.usart2sw = cm_object_get_child_by_name(state->f0.reg.cfgr3, "USART2SW");

	// CR2 bitfields.
	state->f0.fld.cr2.hsi14on = cm_object_get_child_by_name(state->f0.reg.cr2, "HSI14ON");
	state->f0.fld.cr2.hsi14rdy = cm_object_get_child_by_name(state->f0.reg.cr2, "HSI14RDY");
	state->f0.fld.cr2.hsi14dis = cm_object_get_child_by_name(state->f0.reg.cr2, "HSI14DIS");
	state->f0.fld.cr2.hsi14trim = cm_object_get_child_by_name(state->f0.reg.cr2, "HSI14TRIM");
	state->f0.fld.cr2.hsi14cal = cm_object_get_child_by_name(state->f0.reg.cr2, "HSI14CAL");
	state->f0.fld.cr2.hsi48on = cm_object_get_child_by_name(state->f0.reg.cr2, "HSI48ON");
	state->f0.fld.cr2.hsi48rdy = cm_object_get_child_by_name(state->f0.reg.cr2, "HSI48RDY");
	state->f0.fld.cr2.hsi48cal = cm_object_get_child_by_name(state->f0.reg.cr2, "HSI48CAL");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// SYSCFG (System configuration controller) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F0 SYSCFG (System configuration controller) registers.
		struct {
			Object *cfgr1; // 0x0 Configuration register 1
			Object *exticr1; // 0x8 External interrupt configuration register 1
			Object *exticr2; // 0xC External interrupt configuration register 2
			Object *exticr3; // 0x10 External interrupt configuration register 3
			Object *exticr4; // 0x14 External interrupt configuration register 4
			Object *cfgr2; // 0x18 Configuration register 2
		} reg;

		struct {

			// CFGR1 (Configuration register 1) bitfields.
			struct {
				Object *mem_mode; // [0:1] Memory mapping selection bits
				Object *adc_dma_rmp; // [8:8] ADC DMA remapping bit
				Object *usart1_tx_dma_rmp; // [9:9] USART1_TX DMA remapping bit
				Object *usart1_rx_dma_rmp; // [10:10] USART1_RX DMA request remapping bit
				Object *tim16_dma_rmp; // [11:11] TIM16 DMA request remapping bit
				Object *tim17_dma_rmp; // [12:12] TIM17 DMA request remapping bit
				Object *i2c_pb6_fm; // [16:16] Fast Mode Plus (FM plus) driving capability activation bits.
				Object *i2c_pb7_fm; // [17:17] Fast Mode Plus (FM+) driving capability activation bits.
				Object *i2c_pb8_fm; // [18:18] Fast Mode Plus (FM+) driving capability activation bits.
				Object *i2c_pb9_fm; // [19:19] Fast Mode Plus (FM+) driving capability activation bits.
				Object *i2c1_fm_plus; // [20:20] FM+ driving capability activation for I2C1
				Object *i2c2_fm_plus; // [21:21] FM+ driving capability activation for I2C2
				Object *spi2_dma_rmp; // [24:24] SPI2 DMA request remapping bit
				Object *usart2_dma_rmp; // [25:25] USART2 DMA request remapping bit
				Object *usart3_dma_rmp; // [26:26] USART3 DMA request remapping bit
				Object *i2c1_dma_rmp; // [27:27] I2C1 DMA request remapping bit
				Object *tim1_dma_rmp; // [28:28] TIM1 DMA request remapping bit
				Object *tim2_dma_rmp; // [29:29] TIM2 DMA request remapping bit
				Object *tim3_dma_rmp; // [30:30] TIM3 DMA request remapping bit
			} cfgr1;

			// EXTICR1 (External interrupt configuration register 1) bitfields.
			struct {
				Object *exti0; // [0:3] EXTI 0 configuration bits
				Object *exti1; // [4:7] EXTI 1 configuration bits
				Object *exti2; // [8:11] EXTI 2 configuration bits
				Object *exti3; // [12:15] EXTI 3 configuration bits
			} exticr1;

			// EXTICR2 (External interrupt configuration register 2) bitfields.
			struct {
				Object *exti4; // [0:3] EXTI 4 configuration bits
				Object *exti5; // [4:7] EXTI 5 configuration bits
				Object *exti6; // [8:11] EXTI 6 configuration bits
				Object *exti7; // [12:15] EXTI 7 configuration bits
			} exticr2;

			// EXTICR3 (External interrupt configuration register 3) bitfields.
			struct {
				Object *exti8; // [0:3] EXTI 8 configuration bits
				Object *exti9; // [4:7] EXTI 9 configuration bits
				Object *exti10; // [8:11] EXTI 10 configuration bits
				Object *exti11; // [12:15] EXTI 11 configuration bits
			} exticr3;

			// EXTICR4 (External interrupt configuration register 4) bitfields.
			struct {
				Object *exti12; // [0:3] EXTI 12 configuration bits
				Object *exti13; // [4:7] EXTI 13 configuration bits
				Object *exti14; // [8:11] EXTI 14 configuration bits
				Object *exti15; // [12:15] EXTI 15 configuration bits
			} exticr4;

			// CFGR2 (Configuration register 2) bitfields.
			struct {
				Object *locup_lock; // [0:0] Cortex-M0 LOCKUP bit enable bit
				Object *sram_parity_lock; // [1:1] SRAM parity lock bit
				Object *pvd_lock; // [2:2] PVD lock enable bit
				Object *sram_pef; // [8:8] SRAM parity flag
			} cfgr2;
		} fld;
	} f0;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32SYSCFGState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_syscfg_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32SYSCFGState *state = STM32_SYSCFG_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f0.reg.cfgr1 = cm_object_get_child_by_name(obj, "CFGR1");
	state->f0.reg.exticr1 = cm_object_get_child_by_name(obj, "EXTICR1");
	state->f0.reg.exticr2 = cm_object_get_child_by_name(obj, "EXTICR2");
	state->f0.reg.exticr3 = cm_object_get_child_by_name(obj, "EXTICR3");
	state->f0.reg.exticr4 = cm_object_get_child_by_name(obj, "EXTICR4");
	state->f0.reg.cfgr2 = cm_object_get_child_by_name(obj, "CFGR2");

	// CFGR1 bitfields.
	state->f0.fld.cfgr1.mem_mode = cm_object_get_child_by_name(state->f0.reg.cfgr1, "MEM_MODE");
	state->f0.fld.cfgr1.adc_dma_rmp = cm_object_get_child_by_name(state->f0.reg.cfgr1, "ADC_DMA_RMP");
	state->f0.fld.cfgr1.usart1_tx_dma_rmp = cm_object_get_child_by_name(state->f0.reg.cfgr1, "USART1_TX_DMA_RMP");
	state->f0.fld.cfgr1.usart1_rx_dma_rmp = cm_object_get_child_by_name(state->f0.reg.cfgr1, "USART1_RX_DMA_RMP");
	state->f0.fld.cfgr1.tim16_dma_rmp = cm_object_get_child_by_name(state->f0.reg.cfgr1, "TIM16_DMA_RMP");
	state->f0.fld.cfgr1.tim17_dma_rmp = cm_object_get_child_by_name(state->f0.reg.cfgr1, "TIM17_DMA_RMP");
	state->f0.fld.cfgr1.i2c_pb6_fm = cm_object_get_child_by_name(state->f0.reg.cfgr1, "I2C_PB6_FM");
	state->f0.fld.cfgr1.i2c_pb7_fm = cm_object_get_child_by_name(state->f0.reg.cfgr1, "I2C_PB7_FM");
	state->f0.fld.cfgr1.i2c_pb8_fm = cm_object_get_child_by_name(state->f0.reg.cfgr1, "I2C_PB8_FM");
	state->f0.fld.cfgr1.i2c_pb9_fm = cm_object_get_child_by_name(state->f0.reg.cfgr1, "I2C_PB9_FM");
	state->f0.fld.cfgr1.i2c1_fm_plus = cm_object_get_child_by_name(state->f0.reg.cfgr1, "I2C1_FM_plus");
	state->f0.fld.cfgr1.i2c2_fm_plus = cm_object_get_child_by_name(state->f0.reg.cfgr1, "I2C2_FM_plus");
	state->f0.fld.cfgr1.spi2_dma_rmp = cm_object_get_child_by_name(state->f0.reg.cfgr1, "SPI2_DMA_RMP");
	state->f0.fld.cfgr1.usart2_dma_rmp = cm_object_get_child_by_name(state->f0.reg.cfgr1, "USART2_DMA_RMP");
	state->f0.fld.cfgr1.usart3_dma_rmp = cm_object_get_child_by_name(state->f0.reg.cfgr1, "USART3_DMA_RMP");
	state->f0.fld.cfgr1.i2c1_dma_rmp = cm_object_get_child_by_name(state->f0.reg.cfgr1, "I2C1_DMA_RMP");
	state->f0.fld.cfgr1.tim1_dma_rmp = cm_object_get_child_by_name(state->f0.reg.cfgr1, "TIM1_DMA_RMP");
	state->f0.fld.cfgr1.tim2_dma_rmp = cm_object_get_child_by_name(state->f0.reg.cfgr1, "TIM2_DMA_RMP");
	state->f0.fld.cfgr1.tim3_dma_rmp = cm_object_get_child_by_name(state->f0.reg.cfgr1, "TIM3_DMA_RMP");

	// EXTICR1 bitfields.
	state->f0.fld.exticr1.exti0 = cm_object_get_child_by_name(state->f0.reg.exticr1, "EXTI0");
	state->f0.fld.exticr1.exti1 = cm_object_get_child_by_name(state->f0.reg.exticr1, "EXTI1");
	state->f0.fld.exticr1.exti2 = cm_object_get_child_by_name(state->f0.reg.exticr1, "EXTI2");
	state->f0.fld.exticr1.exti3 = cm_object_get_child_by_name(state->f0.reg.exticr1, "EXTI3");

	// EXTICR2 bitfields.
	state->f0.fld.exticr2.exti4 = cm_object_get_child_by_name(state->f0.reg.exticr2, "EXTI4");
	state->f0.fld.exticr2.exti5 = cm_object_get_child_by_name(state->f0.reg.exticr2, "EXTI5");
	state->f0.fld.exticr2.exti6 = cm_object_get_child_by_name(state->f0.reg.exticr2, "EXTI6");
	state->f0.fld.exticr2.exti7 = cm_object_get_child_by_name(state->f0.reg.exticr2, "EXTI7");

	// EXTICR3 bitfields.
	state->f0.fld.exticr3.exti8 = cm_object_get_child_by_name(state->f0.reg.exticr3, "EXTI8");
	state->f0.fld.exticr3.exti9 = cm_object_get_child_by_name(state->f0.reg.exticr3, "EXTI9");
	state->f0.fld.exticr3.exti10 = cm_object_get_child_by_name(state->f0.reg.exticr3, "EXTI10");
	state->f0.fld.exticr3.exti11 = cm_object_get_child_by_name(state->f0.reg.exticr3, "EXTI11");

	// EXTICR4 bitfields.
	state->f0.fld.exticr4.exti12 = cm_object_get_child_by_name(state->f0.reg.exticr4, "EXTI12");
	state->f0.fld.exticr4.exti13 = cm_object_get_child_by_name(state->f0.reg.exticr4, "EXTI13");
	state->f0.fld.exticr4.exti14 = cm_object_get_child_by_name(state->f0.reg.exticr4, "EXTI14");
	state->f0.fld.exticr4.exti15 = cm_object_get_child_by_name(state->f0.reg.exticr4, "EXTI15");

	// CFGR2 bitfields.
	state->f0.fld.cfgr2.locup_lock = cm_object_get_child_by_name(state->f0.reg.cfgr2, "LOCUP_LOCK");
	state->f0.fld.cfgr2.sram_parity_lock = cm_object_get_child_by_name(state->f0.reg.cfgr2, "SRAM_PARITY_LOCK");
	state->f0.fld.cfgr2.pvd_lock = cm_object_get_child_by_name(state->f0.reg.cfgr2, "PVD_LOCK");
	state->f0.fld.cfgr2.sram_pef = cm_object_get_child_by_name(state->f0.reg.cfgr2, "SRAM_PEF");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ADC (Analog-to-digital converter) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F0 ADC (Analog-to-digital converter) registers.
		struct {
			Object *isr; // 0x0 Interrupt and status register
			Object *ier; // 0x4 Interrupt enable register
			Object *cr; // 0x8 Control register
			Object *cfgr1; // 0xC Configuration register 1
			Object *cfgr2; // 0x10 Configuration register 2
			Object *smpr; // 0x14 Sampling time register
			Object *tr; // 0x20 Watchdog threshold register
			Object *chselr; // 0x28 Channel selection register
			Object *dr; // 0x40 Data register
			Object *ccr; // 0x308 Common configuration register
		} reg;

		struct {

			// ISR (Interrupt and status register) bitfields.
			struct {
				Object *adrdy; // [0:0] ADC ready
				Object *eosmp; // [1:1] End of sampling flag
				Object *eoc; // [2:2] End of conversion flag
				Object *eos; // [3:3] End of sequence flag
				Object *ovr; // [4:4] ADC overrun
				Object *awd; // [7:7] Analog watchdog flag
			} isr;

			// IER (Interrupt enable register) bitfields.
			struct {
				Object *adrdyie; // [0:0] ADC ready interrupt enable
				Object *eosmpie; // [1:1] End of sampling flag interrupt enable
				Object *eocie; // [2:2] End of conversion interrupt enable
				Object *eosie; // [3:3] End of conversion sequence interrupt enable
				Object *ovrie; // [4:4] Overrun interrupt enable
				Object *awdie; // [7:7] Analog watchdog interrupt enable
			} ier;

			// CR (Control register) bitfields.
			struct {
				Object *aden; // [0:0] ADC enable command
				Object *addis; // [1:1] ADC disable command
				Object *adstart; // [2:2] ADC start conversion command
				Object *adstp; // [4:4] ADC stop conversion command
				Object *adcal; // [31:31] ADC calibration
			} cr;

			// CFGR1 (Configuration register 1) bitfields.
			struct {
				Object *dmaen; // [0:0] Direct memory access enable
				Object *dmacfg; // [1:1] Direct memery access configuration
				Object *scandir; // [2:2] Scan sequence direction
				Object *res; // [3:4] Data resolution
				Object *align; // [5:5] Data alignment
				Object *extsel; // [6:8] External trigger selection
				Object *exten; // [10:11] External trigger enable and polarity selection
				Object *ovrmod; // [12:12] Overrun management mode
				Object *cont; // [13:13] Single / continuous conversion mode
				Object *autdly; // [14:14] Auto-delayed conversion mode
				Object *autoff; // [15:15] Auto-off mode
				Object *discen; // [16:16] Discontinuous mode
				Object *awdsgl; // [22:22] Enable the watchdog on a single channel or on all channels
				Object *awden; // [23:23] Analog watchdog enable
				Object *awdch; // [26:30] Analog watchdog channel selection
			} cfgr1;

			// CFGR2 (Configuration register 2) bitfields.
			struct {
				Object *jitoff_d2; // [30:30] JITOFF_D2
				Object *jitoff_d4; // [31:31] JITOFF_D4
			} cfgr2;

			// SMPR (Sampling time register) bitfields.
			struct {
				Object *smpr; // [0:2] Sampling time selection
			} smpr;

			// TR (Watchdog threshold register) bitfields.
			struct {
				Object *lt; // [0:11] Analog watchdog lower threshold
				Object *ht; // [16:27] Analog watchdog higher threshold
			} tr;

			// CHSELR (Channel selection register) bitfields.
			struct {
				Object *chsel0; // [0:0] Channel-x selection
				Object *chsel1; // [1:1] Channel-x selection
				Object *chsel2; // [2:2] Channel-x selection
				Object *chsel3; // [3:3] Channel-x selection
				Object *chsel4; // [4:4] Channel-x selection
				Object *chsel5; // [5:5] Channel-x selection
				Object *chsel6; // [6:6] Channel-x selection
				Object *chsel7; // [7:7] Channel-x selection
				Object *chsel8; // [8:8] Channel-x selection
				Object *chsel9; // [9:9] Channel-x selection
				Object *chsel10; // [10:10] Channel-x selection
				Object *chsel11; // [11:11] Channel-x selection
				Object *chsel12; // [12:12] Channel-x selection
				Object *chsel13; // [13:13] Channel-x selection
				Object *chsel14; // [14:14] Channel-x selection
				Object *chsel15; // [15:15] Channel-x selection
				Object *chsel16; // [16:16] Channel-x selection
				Object *chsel17; // [17:17] Channel-x selection
				Object *chsel18; // [18:18] Channel-x selection
			} chselr;

			// DR (Data register) bitfields.
			struct {
				Object *data; // [0:15] Converted data
			} dr;

			// CCR (Common configuration register) bitfields.
			struct {
				Object *vrefen; // [22:22] Temperature sensor and VREFINT enable
				Object *tsen; // [23:23] Temperature sensor enable
				Object *vbaten; // [24:24] VBAT enable
			} ccr;
		} fld;
	} f0;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32ADCState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_adc_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32ADCState *state = STM32_ADC_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f0.reg.isr = cm_object_get_child_by_name(obj, "ISR");
	state->f0.reg.ier = cm_object_get_child_by_name(obj, "IER");
	state->f0.reg.cr = cm_object_get_child_by_name(obj, "CR");
	state->f0.reg.cfgr1 = cm_object_get_child_by_name(obj, "CFGR1");
	state->f0.reg.cfgr2 = cm_object_get_child_by_name(obj, "CFGR2");
	state->f0.reg.smpr = cm_object_get_child_by_name(obj, "SMPR");
	state->f0.reg.tr = cm_object_get_child_by_name(obj, "TR");
	state->f0.reg.chselr = cm_object_get_child_by_name(obj, "CHSELR");
	state->f0.reg.dr = cm_object_get_child_by_name(obj, "DR");
	state->f0.reg.ccr = cm_object_get_child_by_name(obj, "CCR");

	// ISR bitfields.
	state->f0.fld.isr.adrdy = cm_object_get_child_by_name(state->f0.reg.isr, "ADRDY");
	state->f0.fld.isr.eosmp = cm_object_get_child_by_name(state->f0.reg.isr, "EOSMP");
	state->f0.fld.isr.eoc = cm_object_get_child_by_name(state->f0.reg.isr, "EOC");
	state->f0.fld.isr.eos = cm_object_get_child_by_name(state->f0.reg.isr, "EOS");
	state->f0.fld.isr.ovr = cm_object_get_child_by_name(state->f0.reg.isr, "OVR");
	state->f0.fld.isr.awd = cm_object_get_child_by_name(state->f0.reg.isr, "AWD");

	// IER bitfields.
	state->f0.fld.ier.adrdyie = cm_object_get_child_by_name(state->f0.reg.ier, "ADRDYIE");
	state->f0.fld.ier.eosmpie = cm_object_get_child_by_name(state->f0.reg.ier, "EOSMPIE");
	state->f0.fld.ier.eocie = cm_object_get_child_by_name(state->f0.reg.ier, "EOCIE");
	state->f0.fld.ier.eosie = cm_object_get_child_by_name(state->f0.reg.ier, "EOSIE");
	state->f0.fld.ier.ovrie = cm_object_get_child_by_name(state->f0.reg.ier, "OVRIE");
	state->f0.fld.ier.awdie = cm_object_get_child_by_name(state->f0.reg.ier, "AWDIE");

	// CR bitfields.
	state->f0.fld.cr.aden = cm_object_get_child_by_name(state->f0.reg.cr, "ADEN");
	state->f0.fld.cr.addis = cm_object_get_child_by_name(state->f0.reg.cr, "ADDIS");
	state->f0.fld.cr.adstart = cm_object_get_child_by_name(state->f0.reg.cr, "ADSTART");
	state->f0.fld.cr.adstp = cm_object_get_child_by_name(state->f0.reg.cr, "ADSTP");
	state->f0.fld.cr.adcal = cm_object_get_child_by_name(state->f0.reg.cr, "ADCAL");

	// CFGR1 bitfields.
	state->f0.fld.cfgr1.dmaen = cm_object_get_child_by_name(state->f0.reg.cfgr1, "DMAEN");
	state->f0.fld.cfgr1.dmacfg = cm_object_get_child_by_name(state->f0.reg.cfgr1, "DMACFG");
	state->f0.fld.cfgr1.scandir = cm_object_get_child_by_name(state->f0.reg.cfgr1, "SCANDIR");
	state->f0.fld.cfgr1.res = cm_object_get_child_by_name(state->f0.reg.cfgr1, "RES");
	state->f0.fld.cfgr1.align = cm_object_get_child_by_name(state->f0.reg.cfgr1, "ALIGN");
	state->f0.fld.cfgr1.extsel = cm_object_get_child_by_name(state->f0.reg.cfgr1, "EXTSEL");
	state->f0.fld.cfgr1.exten = cm_object_get_child_by_name(state->f0.reg.cfgr1, "EXTEN");
	state->f0.fld.cfgr1.ovrmod = cm_object_get_child_by_name(state->f0.reg.cfgr1, "OVRMOD");
	state->f0.fld.cfgr1.cont = cm_object_get_child_by_name(state->f0.reg.cfgr1, "CONT");
	state->f0.fld.cfgr1.autdly = cm_object_get_child_by_name(state->f0.reg.cfgr1, "AUTDLY");
	state->f0.fld.cfgr1.autoff = cm_object_get_child_by_name(state->f0.reg.cfgr1, "AUTOFF");
	state->f0.fld.cfgr1.discen = cm_object_get_child_by_name(state->f0.reg.cfgr1, "DISCEN");
	state->f0.fld.cfgr1.awdsgl = cm_object_get_child_by_name(state->f0.reg.cfgr1, "AWDSGL");
	state->f0.fld.cfgr1.awden = cm_object_get_child_by_name(state->f0.reg.cfgr1, "AWDEN");
	state->f0.fld.cfgr1.awdch = cm_object_get_child_by_name(state->f0.reg.cfgr1, "AWDCH");

	// CFGR2 bitfields.
	state->f0.fld.cfgr2.jitoff_d2 = cm_object_get_child_by_name(state->f0.reg.cfgr2, "JITOFF_D2");
	state->f0.fld.cfgr2.jitoff_d4 = cm_object_get_child_by_name(state->f0.reg.cfgr2, "JITOFF_D4");

	// SMPR bitfields.
	state->f0.fld.smpr.smpr = cm_object_get_child_by_name(state->f0.reg.smpr, "SMPR");

	// TR bitfields.
	state->f0.fld.tr.lt = cm_object_get_child_by_name(state->f0.reg.tr, "LT");
	state->f0.fld.tr.ht = cm_object_get_child_by_name(state->f0.reg.tr, "HT");

	// CHSELR bitfields.
	state->f0.fld.chselr.chsel0 = cm_object_get_child_by_name(state->f0.reg.chselr, "CHSEL0");
	state->f0.fld.chselr.chsel1 = cm_object_get_child_by_name(state->f0.reg.chselr, "CHSEL1");
	state->f0.fld.chselr.chsel2 = cm_object_get_child_by_name(state->f0.reg.chselr, "CHSEL2");
	state->f0.fld.chselr.chsel3 = cm_object_get_child_by_name(state->f0.reg.chselr, "CHSEL3");
	state->f0.fld.chselr.chsel4 = cm_object_get_child_by_name(state->f0.reg.chselr, "CHSEL4");
	state->f0.fld.chselr.chsel5 = cm_object_get_child_by_name(state->f0.reg.chselr, "CHSEL5");
	state->f0.fld.chselr.chsel6 = cm_object_get_child_by_name(state->f0.reg.chselr, "CHSEL6");
	state->f0.fld.chselr.chsel7 = cm_object_get_child_by_name(state->f0.reg.chselr, "CHSEL7");
	state->f0.fld.chselr.chsel8 = cm_object_get_child_by_name(state->f0.reg.chselr, "CHSEL8");
	state->f0.fld.chselr.chsel9 = cm_object_get_child_by_name(state->f0.reg.chselr, "CHSEL9");
	state->f0.fld.chselr.chsel10 = cm_object_get_child_by_name(state->f0.reg.chselr, "CHSEL10");
	state->f0.fld.chselr.chsel11 = cm_object_get_child_by_name(state->f0.reg.chselr, "CHSEL11");
	state->f0.fld.chselr.chsel12 = cm_object_get_child_by_name(state->f0.reg.chselr, "CHSEL12");
	state->f0.fld.chselr.chsel13 = cm_object_get_child_by_name(state->f0.reg.chselr, "CHSEL13");
	state->f0.fld.chselr.chsel14 = cm_object_get_child_by_name(state->f0.reg.chselr, "CHSEL14");
	state->f0.fld.chselr.chsel15 = cm_object_get_child_by_name(state->f0.reg.chselr, "CHSEL15");
	state->f0.fld.chselr.chsel16 = cm_object_get_child_by_name(state->f0.reg.chselr, "CHSEL16");
	state->f0.fld.chselr.chsel17 = cm_object_get_child_by_name(state->f0.reg.chselr, "CHSEL17");
	state->f0.fld.chselr.chsel18 = cm_object_get_child_by_name(state->f0.reg.chselr, "CHSEL18");

	// DR bitfields.
	state->f0.fld.dr.data = cm_object_get_child_by_name(state->f0.reg.dr, "DATA");

	// CCR bitfields.
	state->f0.fld.ccr.vrefen = cm_object_get_child_by_name(state->f0.reg.ccr, "VREFEN");
	state->f0.fld.ccr.tsen = cm_object_get_child_by_name(state->f0.reg.ccr, "TSEN");
	state->f0.fld.ccr.vbaten = cm_object_get_child_by_name(state->f0.reg.ccr, "VBATEN");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// USART1 (Universal synchronous asynchronous receiver transmitter) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F0 USART1 (Universal synchronous asynchronous receiver transmitter) registers.
		struct {
			Object *cr1; // 0x0 Control register 1
			Object *cr2; // 0x4 Control register 2
			Object *cr3; // 0x8 Control register 3
			Object *brr; // 0xC Baud rate register
			Object *gtpr; // 0x10 Guard time and prescaler register
			Object *rtor; // 0x14 Receiver timeout register
			Object *rqr; // 0x18 Request register
			Object *isr; // 0x1C Interrupt & status register
			Object *icr; // 0x20 Interrupt flag clear register
			Object *rdr; // 0x24 Receive data register
			Object *tdr; // 0x28 Transmit data register
		} reg;

		struct {

			// CR1 (Control register 1) bitfields.
			struct {
				Object *ue; // [0:0] USART enable
				Object *uesm; // [1:1] USART enable in Stop mode
				Object *re; // [2:2] Receiver enable
				Object *te; // [3:3] Transmitter enable
				Object *idleie; // [4:4] IDLE interrupt enable
				Object *rxneie; // [5:5] RXNE interrupt enable
				Object *tcie; // [6:6] Transmission complete interrupt enable
				Object *txeie; // [7:7] Interrupt enable
				Object *peie; // [8:8] PE interrupt enable
				Object *ps; // [9:9] Parity selection
				Object *pce; // [10:10] Parity control enable
				Object *wake; // [11:11] Receiver wakeup method
				Object *m; // [12:12] Word length
				Object *mme; // [13:13] Mute mode enable
				Object *cmie; // [14:14] Character match interrupt enable
				Object *over8; // [15:15] Oversampling mode
				Object *dedt; // [16:20] Driver Enable deassertion time
				Object *deat; // [21:25] Driver Enable assertion time
				Object *rtoie; // [26:26] Receiver timeout interrupt enable
				Object *eobie; // [27:27] End of Block interrupt enable
				Object *m1; // [28:28] Word length
			} cr1;

			// CR2 (Control register 2) bitfields.
			struct {
				Object *addm7; // [4:4] 7-bit Address Detection/4-bit Address Detection
				Object *lbdl; // [5:5] LIN break detection length
				Object *lbdie; // [6:6] LIN break detection interrupt enable
				Object *lbcl; // [8:8] Last bit clock pulse
				Object *cpha; // [9:9] Clock phase
				Object *cpol; // [10:10] Clock polarity
				Object *clken; // [11:11] Clock enable
				Object *stop; // [12:13] STOP bits
				Object *linen; // [14:14] LIN mode enable
				Object *swap; // [15:15] Swap TX/RX pins
				Object *rxinv; // [16:16] RX pin active level inversion
				Object *txinv; // [17:17] TX pin active level inversion
				Object *datainv; // [18:18] Binary data inversion
				Object *msbfirst; // [19:19] Most significant bit first
				Object *abren; // [20:20] Auto baud rate enable
				Object *abrmod; // [21:22] Auto baud rate mode
				Object *rtoen; // [23:23] Receiver timeout enable
				Object *add0; // [24:27] Address of the USART node
				Object *add4; // [28:31] Address of the USART node
			} cr2;

			// CR3 (Control register 3) bitfields.
			struct {
				Object *eie; // [0:0] Error interrupt enable
				Object *iren; // [1:1] IrDA mode enable
				Object *irlp; // [2:2] IrDA low-power
				Object *hdsel; // [3:3] Half-duplex selection
				Object *nack; // [4:4] Smartcard NACK enable
				Object *scen; // [5:5] Smartcard mode enable
				Object *dmar; // [6:6] DMA enable receiver
				Object *dmat; // [7:7] DMA enable transmitter
				Object *rtse; // [8:8] RTS enable
				Object *ctse; // [9:9] CTS enable
				Object *ctsie; // [10:10] CTS interrupt enable
				Object *onebit; // [11:11] One sample bit method enable
				Object *ovrdis; // [12:12] Overrun Disable
				Object *ddre; // [13:13] DMA Disable on Reception Error
				Object *dem; // [14:14] Driver enable mode
				Object *dep; // [15:15] Driver enable polarity selection
				Object *scarcnt; // [17:19] Smartcard auto-retry count
				Object *wus; // [20:21] Wakeup from Stop mode interrupt flag selection
				Object *wufie; // [22:22] Wakeup from Stop mode interrupt enable
			} cr3;

			// BRR (Baud rate register) bitfields.
			struct {
				Object *div_fraction; // [0:3] Fraction of USARTDIV
				Object *div_mantissa; // [4:15] Mantissa of USARTDIV
			} brr;

			// GTPR (Guard time and prescaler register) bitfields.
			struct {
				Object *psc; // [0:7] Prescaler value
				Object *gt; // [8:15] Guard time value
			} gtpr;

			// RTOR (Receiver timeout register) bitfields.
			struct {
				Object *rto; // [0:23] Receiver timeout value
				Object *blen; // [24:31] Block Length
			} rtor;

			// RQR (Request register) bitfields.
			struct {
				Object *abrrq; // [0:0] Auto baud rate request
				Object *sbkrq; // [1:1] Send break request
				Object *mmrq; // [2:2] Mute mode request
				Object *rxfrq; // [3:3] Receive data flush request
				Object *txfrq; // [4:4] Transmit data flush request
			} rqr;

			// ISR (Interrupt & status register) bitfields.
			struct {
				Object *pe; // [0:0] Parity error
				Object *fe; // [1:1] Framing error
				Object *nf; // [2:2] Noise detected flag
				Object *ore; // [3:3] Overrun error
				Object *idle; // [4:4] Idle line detected
				Object *rxne; // [5:5] Read data register not empty
				Object *tc; // [6:6] Transmission complete
				Object *txe; // [7:7] Transmit data register empty
				Object *lbdf; // [8:8] LIN break detection flag
				Object *ctsif; // [9:9] CTS interrupt flag
				Object *cts; // [10:10] CTS flag
				Object *rtof; // [11:11] Receiver timeout
				Object *eobf; // [12:12] End of block flag
				Object *abre; // [14:14] Auto baud rate error
				Object *abrf; // [15:15] Auto baud rate flag
				Object *busy; // [16:16] Busy flag
				Object *cmf; // [17:17] Character match flag
				Object *sbkf; // [18:18] Send break flag
				Object *rwu; // [19:19] Receiver wakeup from Mute mode
				Object *wuf; // [20:20] Wakeup from Stop mode flag
				Object *teack; // [21:21] Transmit enable acknowledge flag
				Object *reack; // [22:22] Receive enable acknowledge flag
			} isr;

			// ICR (Interrupt flag clear register) bitfields.
			struct {
				Object *pecf; // [0:0] Parity error clear flag
				Object *fecf; // [1:1] Framing error clear flag
				Object *ncf; // [2:2] Noise detected clear flag
				Object *orecf; // [3:3] Overrun error clear flag
				Object *idlecf; // [4:4] Idle line detected clear flag
				Object *tccf; // [6:6] Transmission complete clear flag
				Object *lbdcf; // [8:8] LIN break detection clear flag
				Object *ctscf; // [9:9] CTS clear flag
				Object *rtocf; // [11:11] Receiver timeout clear flag
				Object *eobcf; // [12:12] End of timeout clear flag
				Object *cmcf; // [17:17] Character match clear flag
				Object *wucf; // [20:20] Wakeup from Stop mode clear flag
			} icr;

			// RDR (Receive data register) bitfields.
			struct {
				Object *rdr; // [0:8] Receive data value
			} rdr;

			// TDR (Transmit data register) bitfields.
			struct {
				Object *tdr; // [0:8] Transmit data value
			} tdr;
		} fld;
	} f0;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32USART1State;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_usart1_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32USART1State *state = STM32_USART1_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f0.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
	state->f0.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
	state->f0.reg.cr3 = cm_object_get_child_by_name(obj, "CR3");
	state->f0.reg.brr = cm_object_get_child_by_name(obj, "BRR");
	state->f0.reg.gtpr = cm_object_get_child_by_name(obj, "GTPR");
	state->f0.reg.rtor = cm_object_get_child_by_name(obj, "RTOR");
	state->f0.reg.rqr = cm_object_get_child_by_name(obj, "RQR");
	state->f0.reg.isr = cm_object_get_child_by_name(obj, "ISR");
	state->f0.reg.icr = cm_object_get_child_by_name(obj, "ICR");
	state->f0.reg.rdr = cm_object_get_child_by_name(obj, "RDR");
	state->f0.reg.tdr = cm_object_get_child_by_name(obj, "TDR");

	// CR1 bitfields.
	state->f0.fld.cr1.ue = cm_object_get_child_by_name(state->f0.reg.cr1, "UE");
	state->f0.fld.cr1.uesm = cm_object_get_child_by_name(state->f0.reg.cr1, "UESM");
	state->f0.fld.cr1.re = cm_object_get_child_by_name(state->f0.reg.cr1, "RE");
	state->f0.fld.cr1.te = cm_object_get_child_by_name(state->f0.reg.cr1, "TE");
	state->f0.fld.cr1.idleie = cm_object_get_child_by_name(state->f0.reg.cr1, "IDLEIE");
	state->f0.fld.cr1.rxneie = cm_object_get_child_by_name(state->f0.reg.cr1, "RXNEIE");
	state->f0.fld.cr1.tcie = cm_object_get_child_by_name(state->f0.reg.cr1, "TCIE");
	state->f0.fld.cr1.txeie = cm_object_get_child_by_name(state->f0.reg.cr1, "TXEIE");
	state->f0.fld.cr1.peie = cm_object_get_child_by_name(state->f0.reg.cr1, "PEIE");
	state->f0.fld.cr1.ps = cm_object_get_child_by_name(state->f0.reg.cr1, "PS");
	state->f0.fld.cr1.pce = cm_object_get_child_by_name(state->f0.reg.cr1, "PCE");
	state->f0.fld.cr1.wake = cm_object_get_child_by_name(state->f0.reg.cr1, "WAKE");
	state->f0.fld.cr1.m = cm_object_get_child_by_name(state->f0.reg.cr1, "M");
	state->f0.fld.cr1.mme = cm_object_get_child_by_name(state->f0.reg.cr1, "MME");
	state->f0.fld.cr1.cmie = cm_object_get_child_by_name(state->f0.reg.cr1, "CMIE");
	state->f0.fld.cr1.over8 = cm_object_get_child_by_name(state->f0.reg.cr1, "OVER8");
	state->f0.fld.cr1.dedt = cm_object_get_child_by_name(state->f0.reg.cr1, "DEDT");
	state->f0.fld.cr1.deat = cm_object_get_child_by_name(state->f0.reg.cr1, "DEAT");
	state->f0.fld.cr1.rtoie = cm_object_get_child_by_name(state->f0.reg.cr1, "RTOIE");
	state->f0.fld.cr1.eobie = cm_object_get_child_by_name(state->f0.reg.cr1, "EOBIE");
	state->f0.fld.cr1.m1 = cm_object_get_child_by_name(state->f0.reg.cr1, "M1");

	// CR2 bitfields.
	state->f0.fld.cr2.addm7 = cm_object_get_child_by_name(state->f0.reg.cr2, "ADDM7");
	state->f0.fld.cr2.lbdl = cm_object_get_child_by_name(state->f0.reg.cr2, "LBDL");
	state->f0.fld.cr2.lbdie = cm_object_get_child_by_name(state->f0.reg.cr2, "LBDIE");
	state->f0.fld.cr2.lbcl = cm_object_get_child_by_name(state->f0.reg.cr2, "LBCL");
	state->f0.fld.cr2.cpha = cm_object_get_child_by_name(state->f0.reg.cr2, "CPHA");
	state->f0.fld.cr2.cpol = cm_object_get_child_by_name(state->f0.reg.cr2, "CPOL");
	state->f0.fld.cr2.clken = cm_object_get_child_by_name(state->f0.reg.cr2, "CLKEN");
	state->f0.fld.cr2.stop = cm_object_get_child_by_name(state->f0.reg.cr2, "STOP");
	state->f0.fld.cr2.linen = cm_object_get_child_by_name(state->f0.reg.cr2, "LINEN");
	state->f0.fld.cr2.swap = cm_object_get_child_by_name(state->f0.reg.cr2, "SWAP");
	state->f0.fld.cr2.rxinv = cm_object_get_child_by_name(state->f0.reg.cr2, "RXINV");
	state->f0.fld.cr2.txinv = cm_object_get_child_by_name(state->f0.reg.cr2, "TXINV");
	state->f0.fld.cr2.datainv = cm_object_get_child_by_name(state->f0.reg.cr2, "DATAINV");
	state->f0.fld.cr2.msbfirst = cm_object_get_child_by_name(state->f0.reg.cr2, "MSBFIRST");
	state->f0.fld.cr2.abren = cm_object_get_child_by_name(state->f0.reg.cr2, "ABREN");
	state->f0.fld.cr2.abrmod = cm_object_get_child_by_name(state->f0.reg.cr2, "ABRMOD");
	state->f0.fld.cr2.rtoen = cm_object_get_child_by_name(state->f0.reg.cr2, "RTOEN");
	state->f0.fld.cr2.add0 = cm_object_get_child_by_name(state->f0.reg.cr2, "ADD0");
	state->f0.fld.cr2.add4 = cm_object_get_child_by_name(state->f0.reg.cr2, "ADD4");

	// CR3 bitfields.
	state->f0.fld.cr3.eie = cm_object_get_child_by_name(state->f0.reg.cr3, "EIE");
	state->f0.fld.cr3.iren = cm_object_get_child_by_name(state->f0.reg.cr3, "IREN");
	state->f0.fld.cr3.irlp = cm_object_get_child_by_name(state->f0.reg.cr3, "IRLP");
	state->f0.fld.cr3.hdsel = cm_object_get_child_by_name(state->f0.reg.cr3, "HDSEL");
	state->f0.fld.cr3.nack = cm_object_get_child_by_name(state->f0.reg.cr3, "NACK");
	state->f0.fld.cr3.scen = cm_object_get_child_by_name(state->f0.reg.cr3, "SCEN");
	state->f0.fld.cr3.dmar = cm_object_get_child_by_name(state->f0.reg.cr3, "DMAR");
	state->f0.fld.cr3.dmat = cm_object_get_child_by_name(state->f0.reg.cr3, "DMAT");
	state->f0.fld.cr3.rtse = cm_object_get_child_by_name(state->f0.reg.cr3, "RTSE");
	state->f0.fld.cr3.ctse = cm_object_get_child_by_name(state->f0.reg.cr3, "CTSE");
	state->f0.fld.cr3.ctsie = cm_object_get_child_by_name(state->f0.reg.cr3, "CTSIE");
	state->f0.fld.cr3.onebit = cm_object_get_child_by_name(state->f0.reg.cr3, "ONEBIT");
	state->f0.fld.cr3.ovrdis = cm_object_get_child_by_name(state->f0.reg.cr3, "OVRDIS");
	state->f0.fld.cr3.ddre = cm_object_get_child_by_name(state->f0.reg.cr3, "DDRE");
	state->f0.fld.cr3.dem = cm_object_get_child_by_name(state->f0.reg.cr3, "DEM");
	state->f0.fld.cr3.dep = cm_object_get_child_by_name(state->f0.reg.cr3, "DEP");
	state->f0.fld.cr3.scarcnt = cm_object_get_child_by_name(state->f0.reg.cr3, "SCARCNT");
	state->f0.fld.cr3.wus = cm_object_get_child_by_name(state->f0.reg.cr3, "WUS");
	state->f0.fld.cr3.wufie = cm_object_get_child_by_name(state->f0.reg.cr3, "WUFIE");

	// BRR bitfields.
	state->f0.fld.brr.div_fraction = cm_object_get_child_by_name(state->f0.reg.brr, "DIV_Fraction");
	state->f0.fld.brr.div_mantissa = cm_object_get_child_by_name(state->f0.reg.brr, "DIV_Mantissa");

	// GTPR bitfields.
	state->f0.fld.gtpr.psc = cm_object_get_child_by_name(state->f0.reg.gtpr, "PSC");
	state->f0.fld.gtpr.gt = cm_object_get_child_by_name(state->f0.reg.gtpr, "GT");

	// RTOR bitfields.
	state->f0.fld.rtor.rto = cm_object_get_child_by_name(state->f0.reg.rtor, "RTO");
	state->f0.fld.rtor.blen = cm_object_get_child_by_name(state->f0.reg.rtor, "BLEN");

	// RQR bitfields.
	state->f0.fld.rqr.abrrq = cm_object_get_child_by_name(state->f0.reg.rqr, "ABRRQ");
	state->f0.fld.rqr.sbkrq = cm_object_get_child_by_name(state->f0.reg.rqr, "SBKRQ");
	state->f0.fld.rqr.mmrq = cm_object_get_child_by_name(state->f0.reg.rqr, "MMRQ");
	state->f0.fld.rqr.rxfrq = cm_object_get_child_by_name(state->f0.reg.rqr, "RXFRQ");
	state->f0.fld.rqr.txfrq = cm_object_get_child_by_name(state->f0.reg.rqr, "TXFRQ");

	// ISR bitfields.
	state->f0.fld.isr.pe = cm_object_get_child_by_name(state->f0.reg.isr, "PE");
	state->f0.fld.isr.fe = cm_object_get_child_by_name(state->f0.reg.isr, "FE");
	state->f0.fld.isr.nf = cm_object_get_child_by_name(state->f0.reg.isr, "NF");
	state->f0.fld.isr.ore = cm_object_get_child_by_name(state->f0.reg.isr, "ORE");
	state->f0.fld.isr.idle = cm_object_get_child_by_name(state->f0.reg.isr, "IDLE");
	state->f0.fld.isr.rxne = cm_object_get_child_by_name(state->f0.reg.isr, "RXNE");
	state->f0.fld.isr.tc = cm_object_get_child_by_name(state->f0.reg.isr, "TC");
	state->f0.fld.isr.txe = cm_object_get_child_by_name(state->f0.reg.isr, "TXE");
	state->f0.fld.isr.lbdf = cm_object_get_child_by_name(state->f0.reg.isr, "LBDF");
	state->f0.fld.isr.ctsif = cm_object_get_child_by_name(state->f0.reg.isr, "CTSIF");
	state->f0.fld.isr.cts = cm_object_get_child_by_name(state->f0.reg.isr, "CTS");
	state->f0.fld.isr.rtof = cm_object_get_child_by_name(state->f0.reg.isr, "RTOF");
	state->f0.fld.isr.eobf = cm_object_get_child_by_name(state->f0.reg.isr, "EOBF");
	state->f0.fld.isr.abre = cm_object_get_child_by_name(state->f0.reg.isr, "ABRE");
	state->f0.fld.isr.abrf = cm_object_get_child_by_name(state->f0.reg.isr, "ABRF");
	state->f0.fld.isr.busy = cm_object_get_child_by_name(state->f0.reg.isr, "BUSY");
	state->f0.fld.isr.cmf = cm_object_get_child_by_name(state->f0.reg.isr, "CMF");
	state->f0.fld.isr.sbkf = cm_object_get_child_by_name(state->f0.reg.isr, "SBKF");
	state->f0.fld.isr.rwu = cm_object_get_child_by_name(state->f0.reg.isr, "RWU");
	state->f0.fld.isr.wuf = cm_object_get_child_by_name(state->f0.reg.isr, "WUF");
	state->f0.fld.isr.teack = cm_object_get_child_by_name(state->f0.reg.isr, "TEACK");
	state->f0.fld.isr.reack = cm_object_get_child_by_name(state->f0.reg.isr, "REACK");

	// ICR bitfields.
	state->f0.fld.icr.pecf = cm_object_get_child_by_name(state->f0.reg.icr, "PECF");
	state->f0.fld.icr.fecf = cm_object_get_child_by_name(state->f0.reg.icr, "FECF");
	state->f0.fld.icr.ncf = cm_object_get_child_by_name(state->f0.reg.icr, "NCF");
	state->f0.fld.icr.orecf = cm_object_get_child_by_name(state->f0.reg.icr, "ORECF");
	state->f0.fld.icr.idlecf = cm_object_get_child_by_name(state->f0.reg.icr, "IDLECF");
	state->f0.fld.icr.tccf = cm_object_get_child_by_name(state->f0.reg.icr, "TCCF");
	state->f0.fld.icr.lbdcf = cm_object_get_child_by_name(state->f0.reg.icr, "LBDCF");
	state->f0.fld.icr.ctscf = cm_object_get_child_by_name(state->f0.reg.icr, "CTSCF");
	state->f0.fld.icr.rtocf = cm_object_get_child_by_name(state->f0.reg.icr, "RTOCF");
	state->f0.fld.icr.eobcf = cm_object_get_child_by_name(state->f0.reg.icr, "EOBCF");
	state->f0.fld.icr.cmcf = cm_object_get_child_by_name(state->f0.reg.icr, "CMCF");
	state->f0.fld.icr.wucf = cm_object_get_child_by_name(state->f0.reg.icr, "WUCF");

	// RDR bitfields.
	state->f0.fld.rdr.rdr = cm_object_get_child_by_name(state->f0.reg.rdr, "RDR");

	// TDR bitfields.
	state->f0.fld.tdr.tdr = cm_object_get_child_by_name(state->f0.reg.tdr, "TDR");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// COMP (Comparator) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F0 COMP (Comparator) registers.
		struct {
			Object *csr; // 0x0 Control and status register
		} reg;

		struct {

			// CSR (Control and status register) bitfields.
			struct {
				Object *comp1en; // [0:0] Comparator 1 enable
				Object *comp1_inp_dac; // [1:1] COMP1_INP_DAC
				Object *comp1mode; // [2:3] Comparator 1 mode
				Object *comp1insel; // [4:6] Comparator 1 inverting input selection
				Object *comp1outsel; // [8:10] Comparator 1 output selection
				Object *comp1pol; // [11:11] Comparator 1 output polarity
				Object *comp1hyst; // [12:13] Comparator 1 hysteresis
				Object *comp1out; // [14:14] Comparator 1 output
				Object *comp1lock; // [15:15] Comparator 1 lock
				Object *comp2en; // [16:16] Comparator 2 enable
				Object *comp2mode; // [18:19] Comparator 2 mode
				Object *comp2insel; // [20:22] Comparator 2 inverting input selection
				Object *wndwen; // [23:23] Window mode enable
				Object *comp2outsel; // [24:26] Comparator 2 output selection
				Object *comp2pol; // [27:27] Comparator 2 output polarity
				Object *comp2hyst; // [28:29] Comparator 2 hysteresis
				Object *comp2out; // [30:30] Comparator 2 output
				Object *comp2lock; // [31:31] Comparator 2 lock
			} csr;
		} fld;
	} f0;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32COMPState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_comp_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32COMPState *state = STM32_COMP_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f0.reg.csr = cm_object_get_child_by_name(obj, "CSR");

	// CSR bitfields.
	state->f0.fld.csr.comp1en = cm_object_get_child_by_name(state->f0.reg.csr, "COMP1EN");
	state->f0.fld.csr.comp1_inp_dac = cm_object_get_child_by_name(state->f0.reg.csr, "COMP1_INP_DAC");
	state->f0.fld.csr.comp1mode = cm_object_get_child_by_name(state->f0.reg.csr, "COMP1MODE");
	state->f0.fld.csr.comp1insel = cm_object_get_child_by_name(state->f0.reg.csr, "COMP1INSEL");
	state->f0.fld.csr.comp1outsel = cm_object_get_child_by_name(state->f0.reg.csr, "COMP1OUTSEL");
	state->f0.fld.csr.comp1pol = cm_object_get_child_by_name(state->f0.reg.csr, "COMP1POL");
	state->f0.fld.csr.comp1hyst = cm_object_get_child_by_name(state->f0.reg.csr, "COMP1HYST");
	state->f0.fld.csr.comp1out = cm_object_get_child_by_name(state->f0.reg.csr, "COMP1OUT");
	state->f0.fld.csr.comp1lock = cm_object_get_child_by_name(state->f0.reg.csr, "COMP1LOCK");
	state->f0.fld.csr.comp2en = cm_object_get_child_by_name(state->f0.reg.csr, "COMP2EN");
	state->f0.fld.csr.comp2mode = cm_object_get_child_by_name(state->f0.reg.csr, "COMP2MODE");
	state->f0.fld.csr.comp2insel = cm_object_get_child_by_name(state->f0.reg.csr, "COMP2INSEL");
	state->f0.fld.csr.wndwen = cm_object_get_child_by_name(state->f0.reg.csr, "WNDWEN");
	state->f0.fld.csr.comp2outsel = cm_object_get_child_by_name(state->f0.reg.csr, "COMP2OUTSEL");
	state->f0.fld.csr.comp2pol = cm_object_get_child_by_name(state->f0.reg.csr, "COMP2POL");
	state->f0.fld.csr.comp2hyst = cm_object_get_child_by_name(state->f0.reg.csr, "COMP2HYST");
	state->f0.fld.csr.comp2out = cm_object_get_child_by_name(state->f0.reg.csr, "COMP2OUT");
	state->f0.fld.csr.comp2lock = cm_object_get_child_by_name(state->f0.reg.csr, "COMP2LOCK");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// RTC (Real-time clock) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F0 RTC (Real-time clock) registers.
		struct {
			Object *tr; // 0x0 Time register
			Object *dr; // 0x4 Date register
			Object *cr; // 0x8 Control register
			Object *isr; // 0xC Initialization and status register
			Object *prer; // 0x10 Prescaler register
			Object *alrmar; // 0x1C Alarm A register
			Object *wpr; // 0x24 Write protection register
			Object *ssr; // 0x28 Sub second register
			Object *shiftr; // 0x2C Shift control register
			Object *tstr; // 0x30 Timestamp time register
			Object *tsdr; // 0x34 Timestamp date register
			Object *tsssr; // 0x38 Time-stamp sub second register
			Object *calr; // 0x3C Calibration register
			Object *tafcr; // 0x40 Tamper and alternate function configuration register
			Object *alrmassr; // 0x44 Alarm A sub second register
			Object *bkp0r; // 0x50 Backup register
			Object *bkp1r; // 0x54 Backup register
			Object *bkp2r; // 0x58 Backup register
			Object *bkp3r; // 0x5C Backup register
			Object *bkp4r; // 0x60 Backup register
		} reg;

		struct {

			// TR (Time register) bitfields.
			struct {
				Object *su; // [0:3] Second units in BCD format
				Object *st; // [4:6] Second tens in BCD format
				Object *mnu; // [8:11] Minute units in BCD format
				Object *mnt; // [12:14] Minute tens in BCD format
				Object *hu; // [16:19] Hour units in BCD format
				Object *ht; // [20:21] Hour tens in BCD format
				Object *pm; // [22:22] AM/PM notation
			} tr;

			// DR (Date register) bitfields.
			struct {
				Object *du; // [0:3] Date units in BCD format
				Object *dt; // [4:5] Date tens in BCD format
				Object *mu; // [8:11] Month units in BCD format
				Object *mt; // [12:12] Month tens in BCD format
				Object *wdu; // [13:15] Week day units
				Object *yu; // [16:19] Year units in BCD format
				Object *yt; // [20:23] Year tens in BCD format
			} dr;

			// CR (Control register) bitfields.
			struct {
				Object *tsedge; // [3:3] Time-stamp event active edge
				Object *refckon; // [4:4] RTC_REFIN reference clock detection enable (50 or 60 Hz)
				Object *bypshad; // [5:5] Bypass the shadow registers
				Object *fmt; // [6:6] Hour format
				Object *alrae; // [8:8] Alarm A enable
				Object *tse; // [11:11] Timestamp enable
				Object *alraie; // [12:12] Alarm A interrupt enable
				Object *tsie; // [15:15] Time-stamp interrupt enable
				Object *add1h; // [16:16] Add 1 hour (summer time change)
				Object *sub1h; // [17:17] Subtract 1 hour (winter time change)
				Object *bkp; // [18:18] Backup
				Object *cosel; // [19:19] Calibration output selection
				Object *pol; // [20:20] Output polarity
				Object *osel; // [21:22] Output selection
				Object *coe; // [23:23] Calibration output enable
			} cr;

			// ISR (Initialization and status register) bitfields.
			struct {
				Object *alrawf; // [0:0] Alarm A write flag
				Object *shpf; // [3:3] Shift operation pending
				Object *inits; // [4:4] Initialization status flag
				Object *rsf; // [5:5] Registers synchronization flag
				Object *initf; // [6:6] Initialization flag
				Object *init; // [7:7] Initialization mode
				Object *alraf; // [8:8] Alarm A flag
				Object *tsf; // [11:11] Time-stamp flag
				Object *tsovf; // [12:12] Time-stamp overflow flag
				Object *tamp1f; // [13:13] RTC_TAMP1 detection flag
				Object *tamp2f; // [14:14] RTC_TAMP2 detection flag
				Object *recalpf; // [16:16] Recalibration pending Flag
			} isr;

			// PRER (Prescaler register) bitfields.
			struct {
				Object *prediv_s; // [0:14] Synchronous prescaler factor
				Object *prediv_a; // [16:22] Asynchronous prescaler factor
			} prer;

			// ALRMAR (Alarm A register) bitfields.
			struct {
				Object *su; // [0:3] Second units in BCD format.
				Object *st; // [4:6] Second tens in BCD format.
				Object *msk1; // [7:7] Alarm A seconds mask
				Object *mnu; // [8:11] Minute units in BCD format.
				Object *mnt; // [12:14] Minute tens in BCD format.
				Object *msk2; // [15:15] Alarm A minutes mask
				Object *hu; // [16:19] Hour units in BCD format.
				Object *ht; // [20:21] Hour tens in BCD format.
				Object *pm; // [22:22] AM/PM notation
				Object *msk3; // [23:23] Alarm A hours mask
				Object *du; // [24:27] Date units or day in BCD format.
				Object *dt; // [28:29] Date tens in BCD format.
				Object *wdsel; // [30:30] Week day selection
				Object *msk4; // [31:31] Alarm A date mask
			} alrmar;

			// WPR (Write protection register) bitfields.
			struct {
				Object *key; // [0:7] Write protection key
			} wpr;

			// SSR (Sub second register) bitfields.
			struct {
				Object *ss; // [0:15] Sub second value
			} ssr;

			// SHIFTR (Shift control register) bitfields.
			struct {
				Object *subfs; // [0:14] Subtract a fraction of a second
				Object *add1s; // [31:31] Reserved
			} shiftr;

			// TSTR (Timestamp time register) bitfields.
			struct {
				Object *su; // [0:3] Second units in BCD format.
				Object *st; // [4:6] Second tens in BCD format.
				Object *mnu; // [8:11] Minute units in BCD format.
				Object *mnt; // [12:14] Minute tens in BCD format.
				Object *hu; // [16:19] Hour units in BCD format.
				Object *ht; // [20:21] Hour tens in BCD format.
				Object *pm; // [22:22] AM/PM notation
			} tstr;

			// TSDR (Timestamp date register) bitfields.
			struct {
				Object *du; // [0:3] Date units in BCD format
				Object *dt; // [4:5] Date tens in BCD format
				Object *mu; // [8:11] Month units in BCD format
				Object *mt; // [12:12] Month tens in BCD format
				Object *wdu; // [13:15] Week day units
			} tsdr;

			// TSSSR (Time-stamp sub second register) bitfields.
			struct {
				Object *ss; // [0:15] Sub second value
			} tsssr;

			// CALR (Calibration register) bitfields.
			struct {
				Object *calm; // [0:8] Calibration minus
				Object *calw16; // [13:13] Reserved
				Object *calw8; // [14:14] Use a 16-second calibration cycle period
				Object *calp; // [15:15] Use an 8-second calibration cycle period
			} calr;

			// TAFCR (Tamper and alternate function configuration register) bitfields.
			struct {
				Object *tamp1e; // [0:0] RTC_TAMP1 input detection enable
				Object *tamp1trg; // [1:1] Active level for RTC_TAMP1 input
				Object *tampie; // [2:2] Tamper interrupt enable
				Object *tamp2e; // [3:3] RTC_TAMP2 input detection enable
				Object *tamp2_trg; // [4:4] Active level for RTC_TAMP2 input
				Object *tampts; // [7:7] Activate timestamp on tamper detection event
				Object *tampfreq; // [8:10] Tamper sampling frequency
				Object *tampflt; // [11:12] RTC_TAMPx filter count
				Object *tamp_prch; // [13:14] RTC_TAMPx precharge duration
				Object *tamp_pudis; // [15:15] RTC_TAMPx pull-up disable
				Object *pc13value; // [18:18] RTC_ALARM output type/PC13 value
				Object *pc13mode; // [19:19] PC13 mode
				Object *pc14value; // [20:20] PC14 value
				Object *pc14mode; // [21:21] PC14 mode
				Object *pc15value; // [22:22] PC15 value
				Object *pc15mode; // [23:23] PC15 mode
			} tafcr;

			// ALRMASSR (Alarm A sub second register) bitfields.
			struct {
				Object *ss; // [0:14] Sub seconds value
				Object *maskss; // [24:27] Mask the most-significant bits starting at this bit
			} alrmassr;

			// BKP0R (Backup register) bitfields.
			struct {
				Object *bkp; // [0:31] BKP
			} bkp0r;

			// BKP1R (Backup register) bitfields.
			struct {
				Object *bkp; // [0:31] BKP
			} bkp1r;

			// BKP2R (Backup register) bitfields.
			struct {
				Object *bkp; // [0:31] BKP
			} bkp2r;

			// BKP3R (Backup register) bitfields.
			struct {
				Object *bkp; // [0:31] BKP
			} bkp3r;

			// BKP4R (Backup register) bitfields.
			struct {
				Object *bkp; // [0:31] BKP
			} bkp4r;
		} fld;
	} f0;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32RTCState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_rtc_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32RTCState *state = STM32_RTC_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f0.reg.tr = cm_object_get_child_by_name(obj, "TR");
	state->f0.reg.dr = cm_object_get_child_by_name(obj, "DR");
	state->f0.reg.cr = cm_object_get_child_by_name(obj, "CR");
	state->f0.reg.isr = cm_object_get_child_by_name(obj, "ISR");
	state->f0.reg.prer = cm_object_get_child_by_name(obj, "PRER");
	state->f0.reg.alrmar = cm_object_get_child_by_name(obj, "ALRMAR");
	state->f0.reg.wpr = cm_object_get_child_by_name(obj, "WPR");
	state->f0.reg.ssr = cm_object_get_child_by_name(obj, "SSR");
	state->f0.reg.shiftr = cm_object_get_child_by_name(obj, "SHIFTR");
	state->f0.reg.tstr = cm_object_get_child_by_name(obj, "TSTR");
	state->f0.reg.tsdr = cm_object_get_child_by_name(obj, "TSDR");
	state->f0.reg.tsssr = cm_object_get_child_by_name(obj, "TSSSR");
	state->f0.reg.calr = cm_object_get_child_by_name(obj, "CALR");
	state->f0.reg.tafcr = cm_object_get_child_by_name(obj, "TAFCR");
	state->f0.reg.alrmassr = cm_object_get_child_by_name(obj, "ALRMASSR");
	state->f0.reg.bkp0r = cm_object_get_child_by_name(obj, "BKP0R");
	state->f0.reg.bkp1r = cm_object_get_child_by_name(obj, "BKP1R");
	state->f0.reg.bkp2r = cm_object_get_child_by_name(obj, "BKP2R");
	state->f0.reg.bkp3r = cm_object_get_child_by_name(obj, "BKP3R");
	state->f0.reg.bkp4r = cm_object_get_child_by_name(obj, "BKP4R");

	// TR bitfields.
	state->f0.fld.tr.su = cm_object_get_child_by_name(state->f0.reg.tr, "SU");
	state->f0.fld.tr.st = cm_object_get_child_by_name(state->f0.reg.tr, "ST");
	state->f0.fld.tr.mnu = cm_object_get_child_by_name(state->f0.reg.tr, "MNU");
	state->f0.fld.tr.mnt = cm_object_get_child_by_name(state->f0.reg.tr, "MNT");
	state->f0.fld.tr.hu = cm_object_get_child_by_name(state->f0.reg.tr, "HU");
	state->f0.fld.tr.ht = cm_object_get_child_by_name(state->f0.reg.tr, "HT");
	state->f0.fld.tr.pm = cm_object_get_child_by_name(state->f0.reg.tr, "PM");

	// DR bitfields.
	state->f0.fld.dr.du = cm_object_get_child_by_name(state->f0.reg.dr, "DU");
	state->f0.fld.dr.dt = cm_object_get_child_by_name(state->f0.reg.dr, "DT");
	state->f0.fld.dr.mu = cm_object_get_child_by_name(state->f0.reg.dr, "MU");
	state->f0.fld.dr.mt = cm_object_get_child_by_name(state->f0.reg.dr, "MT");
	state->f0.fld.dr.wdu = cm_object_get_child_by_name(state->f0.reg.dr, "WDU");
	state->f0.fld.dr.yu = cm_object_get_child_by_name(state->f0.reg.dr, "YU");
	state->f0.fld.dr.yt = cm_object_get_child_by_name(state->f0.reg.dr, "YT");

	// CR bitfields.
	state->f0.fld.cr.tsedge = cm_object_get_child_by_name(state->f0.reg.cr, "TSEDGE");
	state->f0.fld.cr.refckon = cm_object_get_child_by_name(state->f0.reg.cr, "REFCKON");
	state->f0.fld.cr.bypshad = cm_object_get_child_by_name(state->f0.reg.cr, "BYPSHAD");
	state->f0.fld.cr.fmt = cm_object_get_child_by_name(state->f0.reg.cr, "FMT");
	state->f0.fld.cr.alrae = cm_object_get_child_by_name(state->f0.reg.cr, "ALRAE");
	state->f0.fld.cr.tse = cm_object_get_child_by_name(state->f0.reg.cr, "TSE");
	state->f0.fld.cr.alraie = cm_object_get_child_by_name(state->f0.reg.cr, "ALRAIE");
	state->f0.fld.cr.tsie = cm_object_get_child_by_name(state->f0.reg.cr, "TSIE");
	state->f0.fld.cr.add1h = cm_object_get_child_by_name(state->f0.reg.cr, "ADD1H");
	state->f0.fld.cr.sub1h = cm_object_get_child_by_name(state->f0.reg.cr, "SUB1H");
	state->f0.fld.cr.bkp = cm_object_get_child_by_name(state->f0.reg.cr, "BKP");
	state->f0.fld.cr.cosel = cm_object_get_child_by_name(state->f0.reg.cr, "COSEL");
	state->f0.fld.cr.pol = cm_object_get_child_by_name(state->f0.reg.cr, "POL");
	state->f0.fld.cr.osel = cm_object_get_child_by_name(state->f0.reg.cr, "OSEL");
	state->f0.fld.cr.coe = cm_object_get_child_by_name(state->f0.reg.cr, "COE");

	// ISR bitfields.
	state->f0.fld.isr.alrawf = cm_object_get_child_by_name(state->f0.reg.isr, "ALRAWF");
	state->f0.fld.isr.shpf = cm_object_get_child_by_name(state->f0.reg.isr, "SHPF");
	state->f0.fld.isr.inits = cm_object_get_child_by_name(state->f0.reg.isr, "INITS");
	state->f0.fld.isr.rsf = cm_object_get_child_by_name(state->f0.reg.isr, "RSF");
	state->f0.fld.isr.initf = cm_object_get_child_by_name(state->f0.reg.isr, "INITF");
	state->f0.fld.isr.init = cm_object_get_child_by_name(state->f0.reg.isr, "INIT");
	state->f0.fld.isr.alraf = cm_object_get_child_by_name(state->f0.reg.isr, "ALRAF");
	state->f0.fld.isr.tsf = cm_object_get_child_by_name(state->f0.reg.isr, "TSF");
	state->f0.fld.isr.tsovf = cm_object_get_child_by_name(state->f0.reg.isr, "TSOVF");
	state->f0.fld.isr.tamp1f = cm_object_get_child_by_name(state->f0.reg.isr, "TAMP1F");
	state->f0.fld.isr.tamp2f = cm_object_get_child_by_name(state->f0.reg.isr, "TAMP2F");
	state->f0.fld.isr.recalpf = cm_object_get_child_by_name(state->f0.reg.isr, "RECALPF");

	// PRER bitfields.
	state->f0.fld.prer.prediv_s = cm_object_get_child_by_name(state->f0.reg.prer, "PREDIV_S");
	state->f0.fld.prer.prediv_a = cm_object_get_child_by_name(state->f0.reg.prer, "PREDIV_A");

	// ALRMAR bitfields.
	state->f0.fld.alrmar.su = cm_object_get_child_by_name(state->f0.reg.alrmar, "SU");
	state->f0.fld.alrmar.st = cm_object_get_child_by_name(state->f0.reg.alrmar, "ST");
	state->f0.fld.alrmar.msk1 = cm_object_get_child_by_name(state->f0.reg.alrmar, "MSK1");
	state->f0.fld.alrmar.mnu = cm_object_get_child_by_name(state->f0.reg.alrmar, "MNU");
	state->f0.fld.alrmar.mnt = cm_object_get_child_by_name(state->f0.reg.alrmar, "MNT");
	state->f0.fld.alrmar.msk2 = cm_object_get_child_by_name(state->f0.reg.alrmar, "MSK2");
	state->f0.fld.alrmar.hu = cm_object_get_child_by_name(state->f0.reg.alrmar, "HU");
	state->f0.fld.alrmar.ht = cm_object_get_child_by_name(state->f0.reg.alrmar, "HT");
	state->f0.fld.alrmar.pm = cm_object_get_child_by_name(state->f0.reg.alrmar, "PM");
	state->f0.fld.alrmar.msk3 = cm_object_get_child_by_name(state->f0.reg.alrmar, "MSK3");
	state->f0.fld.alrmar.du = cm_object_get_child_by_name(state->f0.reg.alrmar, "DU");
	state->f0.fld.alrmar.dt = cm_object_get_child_by_name(state->f0.reg.alrmar, "DT");
	state->f0.fld.alrmar.wdsel = cm_object_get_child_by_name(state->f0.reg.alrmar, "WDSEL");
	state->f0.fld.alrmar.msk4 = cm_object_get_child_by_name(state->f0.reg.alrmar, "MSK4");

	// WPR bitfields.
	state->f0.fld.wpr.key = cm_object_get_child_by_name(state->f0.reg.wpr, "KEY");

	// SSR bitfields.
	state->f0.fld.ssr.ss = cm_object_get_child_by_name(state->f0.reg.ssr, "SS");

	// SHIFTR bitfields.
	state->f0.fld.shiftr.subfs = cm_object_get_child_by_name(state->f0.reg.shiftr, "SUBFS");
	state->f0.fld.shiftr.add1s = cm_object_get_child_by_name(state->f0.reg.shiftr, "ADD1S");

	// TSTR bitfields.
	state->f0.fld.tstr.su = cm_object_get_child_by_name(state->f0.reg.tstr, "SU");
	state->f0.fld.tstr.st = cm_object_get_child_by_name(state->f0.reg.tstr, "ST");
	state->f0.fld.tstr.mnu = cm_object_get_child_by_name(state->f0.reg.tstr, "MNU");
	state->f0.fld.tstr.mnt = cm_object_get_child_by_name(state->f0.reg.tstr, "MNT");
	state->f0.fld.tstr.hu = cm_object_get_child_by_name(state->f0.reg.tstr, "HU");
	state->f0.fld.tstr.ht = cm_object_get_child_by_name(state->f0.reg.tstr, "HT");
	state->f0.fld.tstr.pm = cm_object_get_child_by_name(state->f0.reg.tstr, "PM");

	// TSDR bitfields.
	state->f0.fld.tsdr.du = cm_object_get_child_by_name(state->f0.reg.tsdr, "DU");
	state->f0.fld.tsdr.dt = cm_object_get_child_by_name(state->f0.reg.tsdr, "DT");
	state->f0.fld.tsdr.mu = cm_object_get_child_by_name(state->f0.reg.tsdr, "MU");
	state->f0.fld.tsdr.mt = cm_object_get_child_by_name(state->f0.reg.tsdr, "MT");
	state->f0.fld.tsdr.wdu = cm_object_get_child_by_name(state->f0.reg.tsdr, "WDU");

	// TSSSR bitfields.
	state->f0.fld.tsssr.ss = cm_object_get_child_by_name(state->f0.reg.tsssr, "SS");

	// CALR bitfields.
	state->f0.fld.calr.calm = cm_object_get_child_by_name(state->f0.reg.calr, "CALM");
	state->f0.fld.calr.calw16 = cm_object_get_child_by_name(state->f0.reg.calr, "CALW16");
	state->f0.fld.calr.calw8 = cm_object_get_child_by_name(state->f0.reg.calr, "CALW8");
	state->f0.fld.calr.calp = cm_object_get_child_by_name(state->f0.reg.calr, "CALP");

	// TAFCR bitfields.
	state->f0.fld.tafcr.tamp1e = cm_object_get_child_by_name(state->f0.reg.tafcr, "TAMP1E");
	state->f0.fld.tafcr.tamp1trg = cm_object_get_child_by_name(state->f0.reg.tafcr, "TAMP1TRG");
	state->f0.fld.tafcr.tampie = cm_object_get_child_by_name(state->f0.reg.tafcr, "TAMPIE");
	state->f0.fld.tafcr.tamp2e = cm_object_get_child_by_name(state->f0.reg.tafcr, "TAMP2E");
	state->f0.fld.tafcr.tamp2_trg = cm_object_get_child_by_name(state->f0.reg.tafcr, "TAMP2_TRG");
	state->f0.fld.tafcr.tampts = cm_object_get_child_by_name(state->f0.reg.tafcr, "TAMPTS");
	state->f0.fld.tafcr.tampfreq = cm_object_get_child_by_name(state->f0.reg.tafcr, "TAMPFREQ");
	state->f0.fld.tafcr.tampflt = cm_object_get_child_by_name(state->f0.reg.tafcr, "TAMPFLT");
	state->f0.fld.tafcr.tamp_prch = cm_object_get_child_by_name(state->f0.reg.tafcr, "TAMP_PRCH");
	state->f0.fld.tafcr.tamp_pudis = cm_object_get_child_by_name(state->f0.reg.tafcr, "TAMP_PUDIS");
	state->f0.fld.tafcr.pc13value = cm_object_get_child_by_name(state->f0.reg.tafcr, "PC13VALUE");
	state->f0.fld.tafcr.pc13mode = cm_object_get_child_by_name(state->f0.reg.tafcr, "PC13MODE");
	state->f0.fld.tafcr.pc14value = cm_object_get_child_by_name(state->f0.reg.tafcr, "PC14VALUE");
	state->f0.fld.tafcr.pc14mode = cm_object_get_child_by_name(state->f0.reg.tafcr, "PC14MODE");
	state->f0.fld.tafcr.pc15value = cm_object_get_child_by_name(state->f0.reg.tafcr, "PC15VALUE");
	state->f0.fld.tafcr.pc15mode = cm_object_get_child_by_name(state->f0.reg.tafcr, "PC15MODE");

	// ALRMASSR bitfields.
	state->f0.fld.alrmassr.ss = cm_object_get_child_by_name(state->f0.reg.alrmassr, "SS");
	state->f0.fld.alrmassr.maskss = cm_object_get_child_by_name(state->f0.reg.alrmassr, "MASKSS");

	// BKP0R bitfields.
	state->f0.fld.bkp0r.bkp = cm_object_get_child_by_name(state->f0.reg.bkp0r, "BKP");

	// BKP1R bitfields.
	state->f0.fld.bkp1r.bkp = cm_object_get_child_by_name(state->f0.reg.bkp1r, "BKP");

	// BKP2R bitfields.
	state->f0.fld.bkp2r.bkp = cm_object_get_child_by_name(state->f0.reg.bkp2r, "BKP");

	// BKP3R bitfields.
	state->f0.fld.bkp3r.bkp = cm_object_get_child_by_name(state->f0.reg.bkp3r, "BKP");

	// BKP4R bitfields.
	state->f0.fld.bkp4r.bkp = cm_object_get_child_by_name(state->f0.reg.bkp4r, "BKP");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// TIM15 (General-purpose-timers) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F0 TIM15 (General-purpose-timers) registers.
		struct {
			Object *cr1; // 0x0 Control register 1
			Object *cr2; // 0x4 Control register 2
			Object *smcr; // 0x8 Slave mode control register
			Object *dier; // 0xC DMA/Interrupt enable register
			Object *sr; // 0x10 Status register
			Object *egr; // 0x14 Event generation register
			Object *ccmr1_output; // 0x18 Capture/compare mode register (output mode)
			Object *ccmr1_input; // 0x18 Capture/compare mode register 1 (input mode)
			Object *ccer; // 0x20 Capture/compare enable register
			Object *cnt; // 0x24 Counter
			Object *psc; // 0x28 Prescaler
			Object *arr; // 0x2C Auto-reload register
			Object *rcr; // 0x30 Repetition counter register
			Object *ccr1; // 0x34 Capture/compare register 1
			Object *ccr2; // 0x38 Capture/compare register 2
			Object *bdtr; // 0x44 Break and dead-time register
			Object *dcr; // 0x48 DMA control register
			Object *dmar; // 0x4C DMA address for full transfer
		} reg;

		struct {

			// CR1 (Control register 1) bitfields.
			struct {
				Object *cen; // [0:0] Counter enable
				Object *udis; // [1:1] Update disable
				Object *urs; // [2:2] Update request source
				Object *opm; // [3:3] One-pulse mode
				Object *arpe; // [7:7] Auto-reload preload enable
				Object *ckd; // [8:9] Clock division
			} cr1;

			// CR2 (Control register 2) bitfields.
			struct {
				Object *ccpc; // [0:0] Capture/compare preloaded control
				Object *ccus; // [2:2] Capture/compare control update selection
				Object *ccds; // [3:3] Capture/compare DMA selection
				Object *mms; // [4:6] Master mode selection
				Object *ois1; // [8:8] Output Idle state 1
				Object *ois1n; // [9:9] Output Idle state 1
				Object *ois2; // [10:10] Output Idle state 2
			} cr2;

			// SMCR (Slave mode control register) bitfields.
			struct {
				Object *sms; // [0:2] Slave mode selection
				Object *ts; // [4:6] Trigger selection
				Object *msm; // [7:7] Master/Slave mode
			} smcr;

			// DIER (DMA/Interrupt enable register) bitfields.
			struct {
				Object *uie; // [0:0] Update interrupt enable
				Object *cc1ie; // [1:1] Capture/Compare 1 interrupt enable
				Object *cc2ie; // [2:2] Capture/Compare 2 interrupt enable
				Object *comie; // [5:5] COM interrupt enable
				Object *tie; // [6:6] Trigger interrupt enable
				Object *bie; // [7:7] Break interrupt enable
				Object *ude; // [8:8] Update DMA request enable
				Object *cc1de; // [9:9] Capture/Compare 1 DMA request enable
				Object *cc2de; // [10:10] Capture/Compare 2 DMA request enable
				Object *tde; // [14:14] Trigger DMA request enable
			} dier;

			// SR (Status register) bitfields.
			struct {
				Object *uif; // [0:0] Update interrupt flag
				Object *cc1if; // [1:1] Capture/compare 1 interrupt flag
				Object *cc2if; // [2:2] Capture/Compare 2 interrupt flag
				Object *comif; // [5:5] COM interrupt flag
				Object *tif; // [6:6] Trigger interrupt flag
				Object *bif; // [7:7] Break interrupt flag
				Object *cc1of; // [9:9] Capture/Compare 1 overcapture flag
				Object *cc2of; // [10:10] Capture/compare 2 overcapture flag
			} sr;

			// EGR (Event generation register) bitfields.
			struct {
				Object *ug; // [0:0] Update generation
				Object *cc1g; // [1:1] Capture/compare 1 generation
				Object *cc2g; // [2:2] Capture/compare 2 generation
				Object *comg; // [5:5] Capture/Compare control update generation
				Object *tg; // [6:6] Trigger generation
				Object *bg; // [7:7] Break generation
			} egr;

			// CCMR1_Output (Capture/compare mode register (output mode)) bitfields.
			struct {
				Object *cc1s; // [0:1] Capture/Compare 1 selection
				Object *oc1fe; // [2:2] Output Compare 1 fast enable
				Object *oc1pe; // [3:3] Output Compare 1 preload enable
				Object *oc1m; // [4:6] Output Compare 1 mode
				Object *cc2s; // [8:9] Capture/Compare 2 selection
				Object *oc2fe; // [10:10] Output Compare 2 fast enable
				Object *oc2pe; // [11:11] Output Compare 2 preload enable
				Object *oc2m; // [12:14] Output Compare 2 mode
			} ccmr1_output;

			// CCMR1_Input (Capture/compare mode register 1 (input mode)) bitfields.
			struct {
				Object *cc1s; // [0:1] Capture/Compare 1 selection
				Object *ic1psc; // [2:3] Input capture 1 prescaler
				Object *ic1f; // [4:7] Input capture 1 filter
				Object *cc2s; // [8:9] Capture/Compare 2 selection
				Object *ic2psc; // [10:11] Input capture 2 prescaler
				Object *ic2f; // [12:15] Input capture 2 filter
			} ccmr1_input;

			// CCER (Capture/compare enable register) bitfields.
			struct {
				Object *cc1e; // [0:0] Capture/Compare 1 output enable
				Object *cc1p; // [1:1] Capture/Compare 1 output Polarity
				Object *cc1ne; // [2:2] Capture/Compare 1 complementary output enable
				Object *cc1np; // [3:3] Capture/Compare 1 output Polarity
				Object *cc2e; // [4:4] Capture/Compare 2 output enable
				Object *cc2p; // [5:5] Capture/Compare 2 output Polarity
				Object *cc2np; // [7:7] Capture/Compare 2 output Polarity
			} ccer;

			// CNT (Counter) bitfields.
			struct {
				Object *cnt; // [0:15] Counter value
			} cnt;

			// PSC (Prescaler) bitfields.
			struct {
				Object *psc; // [0:15] Prescaler value
			} psc;

			// ARR (Auto-reload register) bitfields.
			struct {
				Object *arr; // [0:15] Auto-reload value
			} arr;

			// RCR (Repetition counter register) bitfields.
			struct {
				Object *rep; // [0:7] Repetition counter value
			} rcr;

			// CCR1 (Capture/compare register 1) bitfields.
			struct {
				Object *ccr1; // [0:15] Capture/Compare 1 value
			} ccr1;

			// CCR2 (Capture/compare register 2) bitfields.
			struct {
				Object *ccr2; // [0:15] Capture/Compare 2 value
			} ccr2;

			// BDTR (Break and dead-time register) bitfields.
			struct {
				Object *dtg; // [0:7] Dead-time generator setup
				Object *lock; // [8:9] Lock configuration
				Object *ossi; // [10:10] Off-state selection for Idle mode
				Object *ossr; // [11:11] Off-state selection for Run mode
				Object *bke; // [12:12] Break enable
				Object *bkp; // [13:13] Break polarity
				Object *aoe; // [14:14] Automatic output enable
				Object *moe; // [15:15] Main output enable
			} bdtr;

			// DCR (DMA control register) bitfields.
			struct {
				Object *dba; // [0:4] DMA base address
				Object *dbl; // [8:12] DMA burst length
			} dcr;

			// DMAR (DMA address for full transfer) bitfields.
			struct {
				Object *dmab; // [0:15] DMA register for burst accesses
			} dmar;
		} fld;
	} f0;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32TIM15State;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_tim15_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32TIM15State *state = STM32_TIM15_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f0.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
	state->f0.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
	state->f0.reg.smcr = cm_object_get_child_by_name(obj, "SMCR");
	state->f0.reg.dier = cm_object_get_child_by_name(obj, "DIER");
	state->f0.reg.sr = cm_object_get_child_by_name(obj, "SR");
	state->f0.reg.egr = cm_object_get_child_by_name(obj, "EGR");
	state->f0.reg.ccmr1_output = cm_object_get_child_by_name(obj, "CCMR1_Output");
	state->f0.reg.ccmr1_input = cm_object_get_child_by_name(obj, "CCMR1_Input");
	state->f0.reg.ccer = cm_object_get_child_by_name(obj, "CCER");
	state->f0.reg.cnt = cm_object_get_child_by_name(obj, "CNT");
	state->f0.reg.psc = cm_object_get_child_by_name(obj, "PSC");
	state->f0.reg.arr = cm_object_get_child_by_name(obj, "ARR");
	state->f0.reg.rcr = cm_object_get_child_by_name(obj, "RCR");
	state->f0.reg.ccr1 = cm_object_get_child_by_name(obj, "CCR1");
	state->f0.reg.ccr2 = cm_object_get_child_by_name(obj, "CCR2");
	state->f0.reg.bdtr = cm_object_get_child_by_name(obj, "BDTR");
	state->f0.reg.dcr = cm_object_get_child_by_name(obj, "DCR");
	state->f0.reg.dmar = cm_object_get_child_by_name(obj, "DMAR");

	// CR1 bitfields.
	state->f0.fld.cr1.cen = cm_object_get_child_by_name(state->f0.reg.cr1, "CEN");
	state->f0.fld.cr1.udis = cm_object_get_child_by_name(state->f0.reg.cr1, "UDIS");
	state->f0.fld.cr1.urs = cm_object_get_child_by_name(state->f0.reg.cr1, "URS");
	state->f0.fld.cr1.opm = cm_object_get_child_by_name(state->f0.reg.cr1, "OPM");
	state->f0.fld.cr1.arpe = cm_object_get_child_by_name(state->f0.reg.cr1, "ARPE");
	state->f0.fld.cr1.ckd = cm_object_get_child_by_name(state->f0.reg.cr1, "CKD");

	// CR2 bitfields.
	state->f0.fld.cr2.ccpc = cm_object_get_child_by_name(state->f0.reg.cr2, "CCPC");
	state->f0.fld.cr2.ccus = cm_object_get_child_by_name(state->f0.reg.cr2, "CCUS");
	state->f0.fld.cr2.ccds = cm_object_get_child_by_name(state->f0.reg.cr2, "CCDS");
	state->f0.fld.cr2.mms = cm_object_get_child_by_name(state->f0.reg.cr2, "MMS");
	state->f0.fld.cr2.ois1 = cm_object_get_child_by_name(state->f0.reg.cr2, "OIS1");
	state->f0.fld.cr2.ois1n = cm_object_get_child_by_name(state->f0.reg.cr2, "OIS1N");
	state->f0.fld.cr2.ois2 = cm_object_get_child_by_name(state->f0.reg.cr2, "OIS2");

	// SMCR bitfields.
	state->f0.fld.smcr.sms = cm_object_get_child_by_name(state->f0.reg.smcr, "SMS");
	state->f0.fld.smcr.ts = cm_object_get_child_by_name(state->f0.reg.smcr, "TS");
	state->f0.fld.smcr.msm = cm_object_get_child_by_name(state->f0.reg.smcr, "MSM");

	// DIER bitfields.
	state->f0.fld.dier.uie = cm_object_get_child_by_name(state->f0.reg.dier, "UIE");
	state->f0.fld.dier.cc1ie = cm_object_get_child_by_name(state->f0.reg.dier, "CC1IE");
	state->f0.fld.dier.cc2ie = cm_object_get_child_by_name(state->f0.reg.dier, "CC2IE");
	state->f0.fld.dier.comie = cm_object_get_child_by_name(state->f0.reg.dier, "COMIE");
	state->f0.fld.dier.tie = cm_object_get_child_by_name(state->f0.reg.dier, "TIE");
	state->f0.fld.dier.bie = cm_object_get_child_by_name(state->f0.reg.dier, "BIE");
	state->f0.fld.dier.ude = cm_object_get_child_by_name(state->f0.reg.dier, "UDE");
	state->f0.fld.dier.cc1de = cm_object_get_child_by_name(state->f0.reg.dier, "CC1DE");
	state->f0.fld.dier.cc2de = cm_object_get_child_by_name(state->f0.reg.dier, "CC2DE");
	state->f0.fld.dier.tde = cm_object_get_child_by_name(state->f0.reg.dier, "TDE");

	// SR bitfields.
	state->f0.fld.sr.uif = cm_object_get_child_by_name(state->f0.reg.sr, "UIF");
	state->f0.fld.sr.cc1if = cm_object_get_child_by_name(state->f0.reg.sr, "CC1IF");
	state->f0.fld.sr.cc2if = cm_object_get_child_by_name(state->f0.reg.sr, "CC2IF");
	state->f0.fld.sr.comif = cm_object_get_child_by_name(state->f0.reg.sr, "COMIF");
	state->f0.fld.sr.tif = cm_object_get_child_by_name(state->f0.reg.sr, "TIF");
	state->f0.fld.sr.bif = cm_object_get_child_by_name(state->f0.reg.sr, "BIF");
	state->f0.fld.sr.cc1of = cm_object_get_child_by_name(state->f0.reg.sr, "CC1OF");
	state->f0.fld.sr.cc2of = cm_object_get_child_by_name(state->f0.reg.sr, "CC2OF");

	// EGR bitfields.
	state->f0.fld.egr.ug = cm_object_get_child_by_name(state->f0.reg.egr, "UG");
	state->f0.fld.egr.cc1g = cm_object_get_child_by_name(state->f0.reg.egr, "CC1G");
	state->f0.fld.egr.cc2g = cm_object_get_child_by_name(state->f0.reg.egr, "CC2G");
	state->f0.fld.egr.comg = cm_object_get_child_by_name(state->f0.reg.egr, "COMG");
	state->f0.fld.egr.tg = cm_object_get_child_by_name(state->f0.reg.egr, "TG");
	state->f0.fld.egr.bg = cm_object_get_child_by_name(state->f0.reg.egr, "BG");

	// CCMR1_Output bitfields.
	state->f0.fld.ccmr1_output.cc1s = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "CC1S");
	state->f0.fld.ccmr1_output.oc1fe = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "OC1FE");
	state->f0.fld.ccmr1_output.oc1pe = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "OC1PE");
	state->f0.fld.ccmr1_output.oc1m = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "OC1M");
	state->f0.fld.ccmr1_output.cc2s = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "CC2S");
	state->f0.fld.ccmr1_output.oc2fe = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "OC2FE");
	state->f0.fld.ccmr1_output.oc2pe = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "OC2PE");
	state->f0.fld.ccmr1_output.oc2m = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "OC2M");

	// CCMR1_Input bitfields.
	state->f0.fld.ccmr1_input.cc1s = cm_object_get_child_by_name(state->f0.reg.ccmr1_input, "CC1S");
	state->f0.fld.ccmr1_input.ic1psc = cm_object_get_child_by_name(state->f0.reg.ccmr1_input, "IC1PSC");
	state->f0.fld.ccmr1_input.ic1f = cm_object_get_child_by_name(state->f0.reg.ccmr1_input, "IC1F");
	state->f0.fld.ccmr1_input.cc2s = cm_object_get_child_by_name(state->f0.reg.ccmr1_input, "CC2S");
	state->f0.fld.ccmr1_input.ic2psc = cm_object_get_child_by_name(state->f0.reg.ccmr1_input, "IC2PSC");
	state->f0.fld.ccmr1_input.ic2f = cm_object_get_child_by_name(state->f0.reg.ccmr1_input, "IC2F");

	// CCER bitfields.
	state->f0.fld.ccer.cc1e = cm_object_get_child_by_name(state->f0.reg.ccer, "CC1E");
	state->f0.fld.ccer.cc1p = cm_object_get_child_by_name(state->f0.reg.ccer, "CC1P");
	state->f0.fld.ccer.cc1ne = cm_object_get_child_by_name(state->f0.reg.ccer, "CC1NE");
	state->f0.fld.ccer.cc1np = cm_object_get_child_by_name(state->f0.reg.ccer, "CC1NP");
	state->f0.fld.ccer.cc2e = cm_object_get_child_by_name(state->f0.reg.ccer, "CC2E");
	state->f0.fld.ccer.cc2p = cm_object_get_child_by_name(state->f0.reg.ccer, "CC2P");
	state->f0.fld.ccer.cc2np = cm_object_get_child_by_name(state->f0.reg.ccer, "CC2NP");

	// CNT bitfields.
	state->f0.fld.cnt.cnt = cm_object_get_child_by_name(state->f0.reg.cnt, "CNT");

	// PSC bitfields.
	state->f0.fld.psc.psc = cm_object_get_child_by_name(state->f0.reg.psc, "PSC");

	// ARR bitfields.
	state->f0.fld.arr.arr = cm_object_get_child_by_name(state->f0.reg.arr, "ARR");

	// RCR bitfields.
	state->f0.fld.rcr.rep = cm_object_get_child_by_name(state->f0.reg.rcr, "REP");

	// CCR1 bitfields.
	state->f0.fld.ccr1.ccr1 = cm_object_get_child_by_name(state->f0.reg.ccr1, "CCR1");

	// CCR2 bitfields.
	state->f0.fld.ccr2.ccr2 = cm_object_get_child_by_name(state->f0.reg.ccr2, "CCR2");

	// BDTR bitfields.
	state->f0.fld.bdtr.dtg = cm_object_get_child_by_name(state->f0.reg.bdtr, "DTG");
	state->f0.fld.bdtr.lock = cm_object_get_child_by_name(state->f0.reg.bdtr, "LOCK");
	state->f0.fld.bdtr.ossi = cm_object_get_child_by_name(state->f0.reg.bdtr, "OSSI");
	state->f0.fld.bdtr.ossr = cm_object_get_child_by_name(state->f0.reg.bdtr, "OSSR");
	state->f0.fld.bdtr.bke = cm_object_get_child_by_name(state->f0.reg.bdtr, "BKE");
	state->f0.fld.bdtr.bkp = cm_object_get_child_by_name(state->f0.reg.bdtr, "BKP");
	state->f0.fld.bdtr.aoe = cm_object_get_child_by_name(state->f0.reg.bdtr, "AOE");
	state->f0.fld.bdtr.moe = cm_object_get_child_by_name(state->f0.reg.bdtr, "MOE");

	// DCR bitfields.
	state->f0.fld.dcr.dba = cm_object_get_child_by_name(state->f0.reg.dcr, "DBA");
	state->f0.fld.dcr.dbl = cm_object_get_child_by_name(state->f0.reg.dcr, "DBL");

	// DMAR bitfields.
	state->f0.fld.dmar.dmab = cm_object_get_child_by_name(state->f0.reg.dmar, "DMAB");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// TIM16 (General-purpose-timers) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F0 TIM16 (General-purpose-timers) registers.
		struct {
			Object *cr1; // 0x0 Control register 1
			Object *cr2; // 0x4 Control register 2
			Object *dier; // 0xC DMA/Interrupt enable register
			Object *sr; // 0x10 Status register
			Object *egr; // 0x14 Event generation register
			Object *ccmr1_output; // 0x18 Capture/compare mode register (output mode)
			Object *ccmr1_input; // 0x18 Capture/compare mode register 1 (input mode)
			Object *ccer; // 0x20 Capture/compare enable register
			Object *cnt; // 0x24 Counter
			Object *psc; // 0x28 Prescaler
			Object *arr; // 0x2C Auto-reload register
			Object *rcr; // 0x30 Repetition counter register
			Object *ccr1; // 0x34 Capture/compare register 1
			Object *bdtr; // 0x44 Break and dead-time register
			Object *dcr; // 0x48 DMA control register
			Object *dmar; // 0x4C DMA address for full transfer
		} reg;

		struct {

			// CR1 (Control register 1) bitfields.
			struct {
				Object *cen; // [0:0] Counter enable
				Object *udis; // [1:1] Update disable
				Object *urs; // [2:2] Update request source
				Object *opm; // [3:3] One-pulse mode
				Object *arpe; // [7:7] Auto-reload preload enable
				Object *ckd; // [8:9] Clock division
			} cr1;

			// CR2 (Control register 2) bitfields.
			struct {
				Object *ccpc; // [0:0] Capture/compare preloaded control
				Object *ccus; // [2:2] Capture/compare control update selection
				Object *ccds; // [3:3] Capture/compare DMA selection
				Object *ois1; // [8:8] Output Idle state 1
				Object *ois1n; // [9:9] Output Idle state 1
			} cr2;

			// DIER (DMA/Interrupt enable register) bitfields.
			struct {
				Object *uie; // [0:0] Update interrupt enable
				Object *cc1ie; // [1:1] Capture/Compare 1 interrupt enable
				Object *comie; // [5:5] COM interrupt enable
				Object *tie; // [6:6] Trigger interrupt enable
				Object *bie; // [7:7] Break interrupt enable
				Object *ude; // [8:8] Update DMA request enable
				Object *cc1de; // [9:9] Capture/Compare 1 DMA request enable
				Object *tde; // [14:14] Trigger DMA request enable
			} dier;

			// SR (Status register) bitfields.
			struct {
				Object *uif; // [0:0] Update interrupt flag
				Object *cc1if; // [1:1] Capture/compare 1 interrupt flag
				Object *comif; // [5:5] COM interrupt flag
				Object *tif; // [6:6] Trigger interrupt flag
				Object *bif; // [7:7] Break interrupt flag
				Object *cc1of; // [9:9] Capture/Compare 1 overcapture flag
			} sr;

			// EGR (Event generation register) bitfields.
			struct {
				Object *ug; // [0:0] Update generation
				Object *cc1g; // [1:1] Capture/compare 1 generation
				Object *comg; // [5:5] Capture/Compare control update generation
				Object *tg; // [6:6] Trigger generation
				Object *bg; // [7:7] Break generation
			} egr;

			// CCMR1_Output (Capture/compare mode register (output mode)) bitfields.
			struct {
				Object *cc1s; // [0:1] Capture/Compare 1 selection
				Object *oc1fe; // [2:2] Output Compare 1 fast enable
				Object *oc1pe; // [3:3] Output Compare 1 preload enable
				Object *oc1m; // [4:6] Output Compare 1 mode
			} ccmr1_output;

			// CCMR1_Input (Capture/compare mode register 1 (input mode)) bitfields.
			struct {
				Object *cc1s; // [0:1] Capture/Compare 1 selection
				Object *ic1psc; // [2:3] Input capture 1 prescaler
				Object *ic1f; // [4:7] Input capture 1 filter
			} ccmr1_input;

			// CCER (Capture/compare enable register) bitfields.
			struct {
				Object *cc1e; // [0:0] Capture/Compare 1 output enable
				Object *cc1p; // [1:1] Capture/Compare 1 output Polarity
				Object *cc1ne; // [2:2] Capture/Compare 1 complementary output enable
				Object *cc1np; // [3:3] Capture/Compare 1 output Polarity
			} ccer;

			// CNT (Counter) bitfields.
			struct {
				Object *cnt; // [0:15] Counter value
			} cnt;

			// PSC (Prescaler) bitfields.
			struct {
				Object *psc; // [0:15] Prescaler value
			} psc;

			// ARR (Auto-reload register) bitfields.
			struct {
				Object *arr; // [0:15] Auto-reload value
			} arr;

			// RCR (Repetition counter register) bitfields.
			struct {
				Object *rep; // [0:7] Repetition counter value
			} rcr;

			// CCR1 (Capture/compare register 1) bitfields.
			struct {
				Object *ccr1; // [0:15] Capture/Compare 1 value
			} ccr1;

			// BDTR (Break and dead-time register) bitfields.
			struct {
				Object *dtg; // [0:7] Dead-time generator setup
				Object *lock; // [8:9] Lock configuration
				Object *ossi; // [10:10] Off-state selection for Idle mode
				Object *ossr; // [11:11] Off-state selection for Run mode
				Object *bke; // [12:12] Break enable
				Object *bkp; // [13:13] Break polarity
				Object *aoe; // [14:14] Automatic output enable
				Object *moe; // [15:15] Main output enable
			} bdtr;

			// DCR (DMA control register) bitfields.
			struct {
				Object *dba; // [0:4] DMA base address
				Object *dbl; // [8:12] DMA burst length
			} dcr;

			// DMAR (DMA address for full transfer) bitfields.
			struct {
				Object *dmab; // [0:15] DMA register for burst accesses
			} dmar;
		} fld;
	} f0;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32TIM16State;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_tim16_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32TIM16State *state = STM32_TIM16_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f0.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
	state->f0.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
	state->f0.reg.dier = cm_object_get_child_by_name(obj, "DIER");
	state->f0.reg.sr = cm_object_get_child_by_name(obj, "SR");
	state->f0.reg.egr = cm_object_get_child_by_name(obj, "EGR");
	state->f0.reg.ccmr1_output = cm_object_get_child_by_name(obj, "CCMR1_Output");
	state->f0.reg.ccmr1_input = cm_object_get_child_by_name(obj, "CCMR1_Input");
	state->f0.reg.ccer = cm_object_get_child_by_name(obj, "CCER");
	state->f0.reg.cnt = cm_object_get_child_by_name(obj, "CNT");
	state->f0.reg.psc = cm_object_get_child_by_name(obj, "PSC");
	state->f0.reg.arr = cm_object_get_child_by_name(obj, "ARR");
	state->f0.reg.rcr = cm_object_get_child_by_name(obj, "RCR");
	state->f0.reg.ccr1 = cm_object_get_child_by_name(obj, "CCR1");
	state->f0.reg.bdtr = cm_object_get_child_by_name(obj, "BDTR");
	state->f0.reg.dcr = cm_object_get_child_by_name(obj, "DCR");
	state->f0.reg.dmar = cm_object_get_child_by_name(obj, "DMAR");

	// CR1 bitfields.
	state->f0.fld.cr1.cen = cm_object_get_child_by_name(state->f0.reg.cr1, "CEN");
	state->f0.fld.cr1.udis = cm_object_get_child_by_name(state->f0.reg.cr1, "UDIS");
	state->f0.fld.cr1.urs = cm_object_get_child_by_name(state->f0.reg.cr1, "URS");
	state->f0.fld.cr1.opm = cm_object_get_child_by_name(state->f0.reg.cr1, "OPM");
	state->f0.fld.cr1.arpe = cm_object_get_child_by_name(state->f0.reg.cr1, "ARPE");
	state->f0.fld.cr1.ckd = cm_object_get_child_by_name(state->f0.reg.cr1, "CKD");

	// CR2 bitfields.
	state->f0.fld.cr2.ccpc = cm_object_get_child_by_name(state->f0.reg.cr2, "CCPC");
	state->f0.fld.cr2.ccus = cm_object_get_child_by_name(state->f0.reg.cr2, "CCUS");
	state->f0.fld.cr2.ccds = cm_object_get_child_by_name(state->f0.reg.cr2, "CCDS");
	state->f0.fld.cr2.ois1 = cm_object_get_child_by_name(state->f0.reg.cr2, "OIS1");
	state->f0.fld.cr2.ois1n = cm_object_get_child_by_name(state->f0.reg.cr2, "OIS1N");

	// DIER bitfields.
	state->f0.fld.dier.uie = cm_object_get_child_by_name(state->f0.reg.dier, "UIE");
	state->f0.fld.dier.cc1ie = cm_object_get_child_by_name(state->f0.reg.dier, "CC1IE");
	state->f0.fld.dier.comie = cm_object_get_child_by_name(state->f0.reg.dier, "COMIE");
	state->f0.fld.dier.tie = cm_object_get_child_by_name(state->f0.reg.dier, "TIE");
	state->f0.fld.dier.bie = cm_object_get_child_by_name(state->f0.reg.dier, "BIE");
	state->f0.fld.dier.ude = cm_object_get_child_by_name(state->f0.reg.dier, "UDE");
	state->f0.fld.dier.cc1de = cm_object_get_child_by_name(state->f0.reg.dier, "CC1DE");
	state->f0.fld.dier.tde = cm_object_get_child_by_name(state->f0.reg.dier, "TDE");

	// SR bitfields.
	state->f0.fld.sr.uif = cm_object_get_child_by_name(state->f0.reg.sr, "UIF");
	state->f0.fld.sr.cc1if = cm_object_get_child_by_name(state->f0.reg.sr, "CC1IF");
	state->f0.fld.sr.comif = cm_object_get_child_by_name(state->f0.reg.sr, "COMIF");
	state->f0.fld.sr.tif = cm_object_get_child_by_name(state->f0.reg.sr, "TIF");
	state->f0.fld.sr.bif = cm_object_get_child_by_name(state->f0.reg.sr, "BIF");
	state->f0.fld.sr.cc1of = cm_object_get_child_by_name(state->f0.reg.sr, "CC1OF");

	// EGR bitfields.
	state->f0.fld.egr.ug = cm_object_get_child_by_name(state->f0.reg.egr, "UG");
	state->f0.fld.egr.cc1g = cm_object_get_child_by_name(state->f0.reg.egr, "CC1G");
	state->f0.fld.egr.comg = cm_object_get_child_by_name(state->f0.reg.egr, "COMG");
	state->f0.fld.egr.tg = cm_object_get_child_by_name(state->f0.reg.egr, "TG");
	state->f0.fld.egr.bg = cm_object_get_child_by_name(state->f0.reg.egr, "BG");

	// CCMR1_Output bitfields.
	state->f0.fld.ccmr1_output.cc1s = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "CC1S");
	state->f0.fld.ccmr1_output.oc1fe = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "OC1FE");
	state->f0.fld.ccmr1_output.oc1pe = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "OC1PE");
	state->f0.fld.ccmr1_output.oc1m = cm_object_get_child_by_name(state->f0.reg.ccmr1_output, "OC1M");

	// CCMR1_Input bitfields.
	state->f0.fld.ccmr1_input.cc1s = cm_object_get_child_by_name(state->f0.reg.ccmr1_input, "CC1S");
	state->f0.fld.ccmr1_input.ic1psc = cm_object_get_child_by_name(state->f0.reg.ccmr1_input, "IC1PSC");
	state->f0.fld.ccmr1_input.ic1f = cm_object_get_child_by_name(state->f0.reg.ccmr1_input, "IC1F");

	// CCER bitfields.
	state->f0.fld.ccer.cc1e = cm_object_get_child_by_name(state->f0.reg.ccer, "CC1E");
	state->f0.fld.ccer.cc1p = cm_object_get_child_by_name(state->f0.reg.ccer, "CC1P");
	state->f0.fld.ccer.cc1ne = cm_object_get_child_by_name(state->f0.reg.ccer, "CC1NE");
	state->f0.fld.ccer.cc1np = cm_object_get_child_by_name(state->f0.reg.ccer, "CC1NP");

	// CNT bitfields.
	state->f0.fld.cnt.cnt = cm_object_get_child_by_name(state->f0.reg.cnt, "CNT");

	// PSC bitfields.
	state->f0.fld.psc.psc = cm_object_get_child_by_name(state->f0.reg.psc, "PSC");

	// ARR bitfields.
	state->f0.fld.arr.arr = cm_object_get_child_by_name(state->f0.reg.arr, "ARR");

	// RCR bitfields.
	state->f0.fld.rcr.rep = cm_object_get_child_by_name(state->f0.reg.rcr, "REP");

	// CCR1 bitfields.
	state->f0.fld.ccr1.ccr1 = cm_object_get_child_by_name(state->f0.reg.ccr1, "CCR1");

	// BDTR bitfields.
	state->f0.fld.bdtr.dtg = cm_object_get_child_by_name(state->f0.reg.bdtr, "DTG");
	state->f0.fld.bdtr.lock = cm_object_get_child_by_name(state->f0.reg.bdtr, "LOCK");
	state->f0.fld.bdtr.ossi = cm_object_get_child_by_name(state->f0.reg.bdtr, "OSSI");
	state->f0.fld.bdtr.ossr = cm_object_get_child_by_name(state->f0.reg.bdtr, "OSSR");
	state->f0.fld.bdtr.bke = cm_object_get_child_by_name(state->f0.reg.bdtr, "BKE");
	state->f0.fld.bdtr.bkp = cm_object_get_child_by_name(state->f0.reg.bdtr, "BKP");
	state->f0.fld.bdtr.aoe = cm_object_get_child_by_name(state->f0.reg.bdtr, "AOE");
	state->f0.fld.bdtr.moe = cm_object_get_child_by_name(state->f0.reg.bdtr, "MOE");

	// DCR bitfields.
	state->f0.fld.dcr.dba = cm_object_get_child_by_name(state->f0.reg.dcr, "DBA");
	state->f0.fld.dcr.dbl = cm_object_get_child_by_name(state->f0.reg.dcr, "DBL");

	// DMAR bitfields.
	state->f0.fld.dmar.dmab = cm_object_get_child_by_name(state->f0.reg.dmar, "DMAB");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// TSC (Touch sensing controller) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F0 TSC (Touch sensing controller) registers.
		struct {
			Object *cr; // 0x0 Control register
			Object *ier; // 0x4 Interrupt enable register
			Object *icr; // 0x8 Interrupt clear register
			Object *isr; // 0xC Interrupt status register
			Object *iohcr; // 0x10 I/O hysteresis control register
			Object *ioascr; // 0x18 I/O analog switch control register
			Object *ioscr; // 0x20 I/O sampling control register
			Object *ioccr; // 0x28 I/O channel control register
			Object *iogcsr; // 0x30 I/O group control status register
			Object *iog1cr; // 0x34 I/O group x counter register
			Object *iog2cr; // 0x38 I/O group x counter register
			Object *iog3cr; // 0x3C I/O group x counter register
			Object *iog4cr; // 0x40 I/O group x counter register
			Object *iog5cr; // 0x44 I/O group x counter register
			Object *iog6cr; // 0x48 I/O group x counter register
		} reg;

		struct {

			// CR (Control register) bitfields.
			struct {
				Object *tsce; // [0:0] Touch sensing controller enable
				Object *start; // [1:1] Start a new acquisition
				Object *am; // [2:2] Acquisition mode
				Object *syncpol; // [3:3] Synchronization pin polarity
				Object *iodef; // [4:4] I/O Default mode
				Object *mcv; // [5:7] Max count value
				Object *pgpsc; // [12:14] Pulse generator prescaler
				Object *sspsc; // [15:15] Spread spectrum prescaler
				Object *sse; // [16:16] Spread spectrum enable
				Object *ssd; // [17:23] Spread spectrum deviation
				Object *ctpl; // [24:27] Charge transfer pulse low
				Object *ctph; // [28:31] Charge transfer pulse high
			} cr;

			// IER (Interrupt enable register) bitfields.
			struct {
				Object *eoaie; // [0:0] End of acquisition interrupt enable
				Object *mceie; // [1:1] Max count error interrupt enable
			} ier;

			// ICR (Interrupt clear register) bitfields.
			struct {
				Object *eoaic; // [0:0] End of acquisition interrupt clear
				Object *mceic; // [1:1] Max count error interrupt clear
			} icr;

			// ISR (Interrupt status register) bitfields.
			struct {
				Object *eoaf; // [0:0] End of acquisition flag
				Object *mcef; // [1:1] Max count error flag
			} isr;

			// IOHCR (I/O hysteresis control register) bitfields.
			struct {
				Object *g1_io1; // [0:0] G1_IO1 Schmitt trigger hysteresis mode
				Object *g1_io2; // [1:1] G1_IO2 Schmitt trigger hysteresis mode
				Object *g1_io3; // [2:2] G1_IO3 Schmitt trigger hysteresis mode
				Object *g1_io4; // [3:3] G1_IO4 Schmitt trigger hysteresis mode
				Object *g2_io1; // [4:4] G2_IO1 Schmitt trigger hysteresis mode
				Object *g2_io2; // [5:5] G2_IO2 Schmitt trigger hysteresis mode
				Object *g2_io3; // [6:6] G2_IO3 Schmitt trigger hysteresis mode
				Object *g2_io4; // [7:7] G2_IO4 Schmitt trigger hysteresis mode
				Object *g3_io1; // [8:8] G3_IO1 Schmitt trigger hysteresis mode
				Object *g3_io2; // [9:9] G3_IO2 Schmitt trigger hysteresis mode
				Object *g3_io3; // [10:10] G3_IO3 Schmitt trigger hysteresis mode
				Object *g3_io4; // [11:11] G3_IO4 Schmitt trigger hysteresis mode
				Object *g4_io1; // [12:12] G4_IO1 Schmitt trigger hysteresis mode
				Object *g4_io2; // [13:13] G4_IO2 Schmitt trigger hysteresis mode
				Object *g4_io3; // [14:14] G4_IO3 Schmitt trigger hysteresis mode
				Object *g4_io4; // [15:15] G4_IO4 Schmitt trigger hysteresis mode
				Object *g5_io1; // [16:16] G5_IO1 Schmitt trigger hysteresis mode
				Object *g5_io2; // [17:17] G5_IO2 Schmitt trigger hysteresis mode
				Object *g5_io3; // [18:18] G5_IO3 Schmitt trigger hysteresis mode
				Object *g5_io4; // [19:19] G5_IO4 Schmitt trigger hysteresis mode
				Object *g6_io1; // [20:20] G6_IO1 Schmitt trigger hysteresis mode
				Object *g6_io2; // [21:21] G6_IO2 Schmitt trigger hysteresis mode
				Object *g6_io3; // [22:22] G6_IO3 Schmitt trigger hysteresis mode
				Object *g6_io4; // [23:23] G6_IO4 Schmitt trigger hysteresis mode
			} iohcr;

			// IOASCR (I/O analog switch control register) bitfields.
			struct {
				Object *g1_io1; // [0:0] G1_IO1 analog switch enable
				Object *g1_io2; // [1:1] G1_IO2 analog switch enable
				Object *g1_io3; // [2:2] G1_IO3 analog switch enable
				Object *g1_io4; // [3:3] G1_IO4 analog switch enable
				Object *g2_io1; // [4:4] G2_IO1 analog switch enable
				Object *g2_io2; // [5:5] G2_IO2 analog switch enable
				Object *g2_io3; // [6:6] G2_IO3 analog switch enable
				Object *g2_io4; // [7:7] G2_IO4 analog switch enable
				Object *g3_io1; // [8:8] G3_IO1 analog switch enable
				Object *g3_io2; // [9:9] G3_IO2 analog switch enable
				Object *g3_io3; // [10:10] G3_IO3 analog switch enable
				Object *g3_io4; // [11:11] G3_IO4 analog switch enable
				Object *g4_io1; // [12:12] G4_IO1 analog switch enable
				Object *g4_io2; // [13:13] G4_IO2 analog switch enable
				Object *g4_io3; // [14:14] G4_IO3 analog switch enable
				Object *g4_io4; // [15:15] G4_IO4 analog switch enable
				Object *g5_io1; // [16:16] G5_IO1 analog switch enable
				Object *g5_io2; // [17:17] G5_IO2 analog switch enable
				Object *g5_io3; // [18:18] G5_IO3 analog switch enable
				Object *g5_io4; // [19:19] G5_IO4 analog switch enable
				Object *g6_io1; // [20:20] G6_IO1 analog switch enable
				Object *g6_io2; // [21:21] G6_IO2 analog switch enable
				Object *g6_io3; // [22:22] G6_IO3 analog switch enable
				Object *g6_io4; // [23:23] G6_IO4 analog switch enable
			} ioascr;

			// IOSCR (I/O sampling control register) bitfields.
			struct {
				Object *g1_io1; // [0:0] G1_IO1 sampling mode
				Object *g1_io2; // [1:1] G1_IO2 sampling mode
				Object *g1_io3; // [2:2] G1_IO3 sampling mode
				Object *g1_io4; // [3:3] G1_IO4 sampling mode
				Object *g2_io1; // [4:4] G2_IO1 sampling mode
				Object *g2_io2; // [5:5] G2_IO2 sampling mode
				Object *g2_io3; // [6:6] G2_IO3 sampling mode
				Object *g2_io4; // [7:7] G2_IO4 sampling mode
				Object *g3_io1; // [8:8] G3_IO1 sampling mode
				Object *g3_io2; // [9:9] G3_IO2 sampling mode
				Object *g3_io3; // [10:10] G3_IO3 sampling mode
				Object *g3_io4; // [11:11] G3_IO4 sampling mode
				Object *g4_io1; // [12:12] G4_IO1 sampling mode
				Object *g4_io2; // [13:13] G4_IO2 sampling mode
				Object *g4_io3; // [14:14] G4_IO3 sampling mode
				Object *g4_io4; // [15:15] G4_IO4 sampling mode
				Object *g5_io1; // [16:16] G5_IO1 sampling mode
				Object *g5_io2; // [17:17] G5_IO2 sampling mode
				Object *g5_io3; // [18:18] G5_IO3 sampling mode
				Object *g5_io4; // [19:19] G5_IO4 sampling mode
				Object *g6_io1; // [20:20] G6_IO1 sampling mode
				Object *g6_io2; // [21:21] G6_IO2 sampling mode
				Object *g6_io3; // [22:22] G6_IO3 sampling mode
				Object *g6_io4; // [23:23] G6_IO4 sampling mode
			} ioscr;

			// IOCCR (I/O channel control register) bitfields.
			struct {
				Object *g1_io1; // [0:0] G1_IO1 channel mode
				Object *g1_io2; // [1:1] G1_IO2 channel mode
				Object *g1_io3; // [2:2] G1_IO3 channel mode
				Object *g1_io4; // [3:3] G1_IO4 channel mode
				Object *g2_io1; // [4:4] G2_IO1 channel mode
				Object *g2_io2; // [5:5] G2_IO2 channel mode
				Object *g2_io3; // [6:6] G2_IO3 channel mode
				Object *g2_io4; // [7:7] G2_IO4 channel mode
				Object *g3_io1; // [8:8] G3_IO1 channel mode
				Object *g3_io2; // [9:9] G3_IO2 channel mode
				Object *g3_io3; // [10:10] G3_IO3 channel mode
				Object *g3_io4; // [11:11] G3_IO4 channel mode
				Object *g4_io1; // [12:12] G4_IO1 channel mode
				Object *g4_io2; // [13:13] G4_IO2 channel mode
				Object *g4_io3; // [14:14] G4_IO3 channel mode
				Object *g4_io4; // [15:15] G4_IO4 channel mode
				Object *g5_io1; // [16:16] G5_IO1 channel mode
				Object *g5_io2; // [17:17] G5_IO2 channel mode
				Object *g5_io3; // [18:18] G5_IO3 channel mode
				Object *g5_io4; // [19:19] G5_IO4 channel mode
				Object *g6_io1; // [20:20] G6_IO1 channel mode
				Object *g6_io2; // [21:21] G6_IO2 channel mode
				Object *g6_io3; // [22:22] G6_IO3 channel mode
				Object *g6_io4; // [23:23] G6_IO4 channel mode
			} ioccr;

			// IOGCSR (I/O group control status register) bitfields.
			struct {
				Object *g1e; // [0:0] Analog I/O group x enable
				Object *g2e; // [1:1] Analog I/O group x enable
				Object *g3e; // [2:2] Analog I/O group x enable
				Object *g4e; // [3:3] Analog I/O group x enable
				Object *g5e; // [4:4] Analog I/O group x enable
				Object *g6e; // [5:5] Analog I/O group x enable
				Object *g7e; // [6:6] Analog I/O group x enable
				Object *g8e; // [7:7] Analog I/O group x enable
				Object *g1s; // [16:16] Analog I/O group x status
				Object *g2s; // [17:17] Analog I/O group x status
				Object *g3s; // [18:18] Analog I/O group x status
				Object *g4s; // [19:19] Analog I/O group x status
				Object *g5s; // [20:20] Analog I/O group x status
				Object *g6s; // [21:21] Analog I/O group x status
				Object *g7s; // [22:22] Analog I/O group x status
				Object *g8s; // [23:23] Analog I/O group x status
			} iogcsr;

			// IOG1CR (I/O group x counter register) bitfields.
			struct {
				Object *cnt; // [0:13] Counter value
			} iog1cr;

			// IOG2CR (I/O group x counter register) bitfields.
			struct {
				Object *cnt; // [0:13] Counter value
			} iog2cr;

			// IOG3CR (I/O group x counter register) bitfields.
			struct {
				Object *cnt; // [0:13] Counter value
			} iog3cr;

			// IOG4CR (I/O group x counter register) bitfields.
			struct {
				Object *cnt; // [0:13] Counter value
			} iog4cr;

			// IOG5CR (I/O group x counter register) bitfields.
			struct {
				Object *cnt; // [0:13] Counter value
			} iog5cr;

			// IOG6CR (I/O group x counter register) bitfields.
			struct {
				Object *cnt; // [0:13] Counter value
			} iog6cr;
		} fld;
	} f0;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32TSCState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_tsc_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32TSCState *state = STM32_TSC_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f0.reg.cr = cm_object_get_child_by_name(obj, "CR");
	state->f0.reg.ier = cm_object_get_child_by_name(obj, "IER");
	state->f0.reg.icr = cm_object_get_child_by_name(obj, "ICR");
	state->f0.reg.isr = cm_object_get_child_by_name(obj, "ISR");
	state->f0.reg.iohcr = cm_object_get_child_by_name(obj, "IOHCR");
	state->f0.reg.ioascr = cm_object_get_child_by_name(obj, "IOASCR");
	state->f0.reg.ioscr = cm_object_get_child_by_name(obj, "IOSCR");
	state->f0.reg.ioccr = cm_object_get_child_by_name(obj, "IOCCR");
	state->f0.reg.iogcsr = cm_object_get_child_by_name(obj, "IOGCSR");
	state->f0.reg.iog1cr = cm_object_get_child_by_name(obj, "IOG1CR");
	state->f0.reg.iog2cr = cm_object_get_child_by_name(obj, "IOG2CR");
	state->f0.reg.iog3cr = cm_object_get_child_by_name(obj, "IOG3CR");
	state->f0.reg.iog4cr = cm_object_get_child_by_name(obj, "IOG4CR");
	state->f0.reg.iog5cr = cm_object_get_child_by_name(obj, "IOG5CR");
	state->f0.reg.iog6cr = cm_object_get_child_by_name(obj, "IOG6CR");

	// CR bitfields.
	state->f0.fld.cr.tsce = cm_object_get_child_by_name(state->f0.reg.cr, "TSCE");
	state->f0.fld.cr.start = cm_object_get_child_by_name(state->f0.reg.cr, "START");
	state->f0.fld.cr.am = cm_object_get_child_by_name(state->f0.reg.cr, "AM");
	state->f0.fld.cr.syncpol = cm_object_get_child_by_name(state->f0.reg.cr, "SYNCPOL");
	state->f0.fld.cr.iodef = cm_object_get_child_by_name(state->f0.reg.cr, "IODEF");
	state->f0.fld.cr.mcv = cm_object_get_child_by_name(state->f0.reg.cr, "MCV");
	state->f0.fld.cr.pgpsc = cm_object_get_child_by_name(state->f0.reg.cr, "PGPSC");
	state->f0.fld.cr.sspsc = cm_object_get_child_by_name(state->f0.reg.cr, "SSPSC");
	state->f0.fld.cr.sse = cm_object_get_child_by_name(state->f0.reg.cr, "SSE");
	state->f0.fld.cr.ssd = cm_object_get_child_by_name(state->f0.reg.cr, "SSD");
	state->f0.fld.cr.ctpl = cm_object_get_child_by_name(state->f0.reg.cr, "CTPL");
	state->f0.fld.cr.ctph = cm_object_get_child_by_name(state->f0.reg.cr, "CTPH");

	// IER bitfields.
	state->f0.fld.ier.eoaie = cm_object_get_child_by_name(state->f0.reg.ier, "EOAIE");
	state->f0.fld.ier.mceie = cm_object_get_child_by_name(state->f0.reg.ier, "MCEIE");

	// ICR bitfields.
	state->f0.fld.icr.eoaic = cm_object_get_child_by_name(state->f0.reg.icr, "EOAIC");
	state->f0.fld.icr.mceic = cm_object_get_child_by_name(state->f0.reg.icr, "MCEIC");

	// ISR bitfields.
	state->f0.fld.isr.eoaf = cm_object_get_child_by_name(state->f0.reg.isr, "EOAF");
	state->f0.fld.isr.mcef = cm_object_get_child_by_name(state->f0.reg.isr, "MCEF");

	// IOHCR bitfields.
	state->f0.fld.iohcr.g1_io1 = cm_object_get_child_by_name(state->f0.reg.iohcr, "G1_IO1");
	state->f0.fld.iohcr.g1_io2 = cm_object_get_child_by_name(state->f0.reg.iohcr, "G1_IO2");
	state->f0.fld.iohcr.g1_io3 = cm_object_get_child_by_name(state->f0.reg.iohcr, "G1_IO3");
	state->f0.fld.iohcr.g1_io4 = cm_object_get_child_by_name(state->f0.reg.iohcr, "G1_IO4");
	state->f0.fld.iohcr.g2_io1 = cm_object_get_child_by_name(state->f0.reg.iohcr, "G2_IO1");
	state->f0.fld.iohcr.g2_io2 = cm_object_get_child_by_name(state->f0.reg.iohcr, "G2_IO2");
	state->f0.fld.iohcr.g2_io3 = cm_object_get_child_by_name(state->f0.reg.iohcr, "G2_IO3");
	state->f0.fld.iohcr.g2_io4 = cm_object_get_child_by_name(state->f0.reg.iohcr, "G2_IO4");
	state->f0.fld.iohcr.g3_io1 = cm_object_get_child_by_name(state->f0.reg.iohcr, "G3_IO1");
	state->f0.fld.iohcr.g3_io2 = cm_object_get_child_by_name(state->f0.reg.iohcr, "G3_IO2");
	state->f0.fld.iohcr.g3_io3 = cm_object_get_child_by_name(state->f0.reg.iohcr, "G3_IO3");
	state->f0.fld.iohcr.g3_io4 = cm_object_get_child_by_name(state->f0.reg.iohcr, "G3_IO4");
	state->f0.fld.iohcr.g4_io1 = cm_object_get_child_by_name(state->f0.reg.iohcr, "G4_IO1");
	state->f0.fld.iohcr.g4_io2 = cm_object_get_child_by_name(state->f0.reg.iohcr, "G4_IO2");
	state->f0.fld.iohcr.g4_io3 = cm_object_get_child_by_name(state->f0.reg.iohcr, "G4_IO3");
	state->f0.fld.iohcr.g4_io4 = cm_object_get_child_by_name(state->f0.reg.iohcr, "G4_IO4");
	state->f0.fld.iohcr.g5_io1 = cm_object_get_child_by_name(state->f0.reg.iohcr, "G5_IO1");
	state->f0.fld.iohcr.g5_io2 = cm_object_get_child_by_name(state->f0.reg.iohcr, "G5_IO2");
	state->f0.fld.iohcr.g5_io3 = cm_object_get_child_by_name(state->f0.reg.iohcr, "G5_IO3");
	state->f0.fld.iohcr.g5_io4 = cm_object_get_child_by_name(state->f0.reg.iohcr, "G5_IO4");
	state->f0.fld.iohcr.g6_io1 = cm_object_get_child_by_name(state->f0.reg.iohcr, "G6_IO1");
	state->f0.fld.iohcr.g6_io2 = cm_object_get_child_by_name(state->f0.reg.iohcr, "G6_IO2");
	state->f0.fld.iohcr.g6_io3 = cm_object_get_child_by_name(state->f0.reg.iohcr, "G6_IO3");
	state->f0.fld.iohcr.g6_io4 = cm_object_get_child_by_name(state->f0.reg.iohcr, "G6_IO4");

	// IOASCR bitfields.
	state->f0.fld.ioascr.g1_io1 = cm_object_get_child_by_name(state->f0.reg.ioascr, "G1_IO1");
	state->f0.fld.ioascr.g1_io2 = cm_object_get_child_by_name(state->f0.reg.ioascr, "G1_IO2");
	state->f0.fld.ioascr.g1_io3 = cm_object_get_child_by_name(state->f0.reg.ioascr, "G1_IO3");
	state->f0.fld.ioascr.g1_io4 = cm_object_get_child_by_name(state->f0.reg.ioascr, "G1_IO4");
	state->f0.fld.ioascr.g2_io1 = cm_object_get_child_by_name(state->f0.reg.ioascr, "G2_IO1");
	state->f0.fld.ioascr.g2_io2 = cm_object_get_child_by_name(state->f0.reg.ioascr, "G2_IO2");
	state->f0.fld.ioascr.g2_io3 = cm_object_get_child_by_name(state->f0.reg.ioascr, "G2_IO3");
	state->f0.fld.ioascr.g2_io4 = cm_object_get_child_by_name(state->f0.reg.ioascr, "G2_IO4");
	state->f0.fld.ioascr.g3_io1 = cm_object_get_child_by_name(state->f0.reg.ioascr, "G3_IO1");
	state->f0.fld.ioascr.g3_io2 = cm_object_get_child_by_name(state->f0.reg.ioascr, "G3_IO2");
	state->f0.fld.ioascr.g3_io3 = cm_object_get_child_by_name(state->f0.reg.ioascr, "G3_IO3");
	state->f0.fld.ioascr.g3_io4 = cm_object_get_child_by_name(state->f0.reg.ioascr, "G3_IO4");
	state->f0.fld.ioascr.g4_io1 = cm_object_get_child_by_name(state->f0.reg.ioascr, "G4_IO1");
	state->f0.fld.ioascr.g4_io2 = cm_object_get_child_by_name(state->f0.reg.ioascr, "G4_IO2");
	state->f0.fld.ioascr.g4_io3 = cm_object_get_child_by_name(state->f0.reg.ioascr, "G4_IO3");
	state->f0.fld.ioascr.g4_io4 = cm_object_get_child_by_name(state->f0.reg.ioascr, "G4_IO4");
	state->f0.fld.ioascr.g5_io1 = cm_object_get_child_by_name(state->f0.reg.ioascr, "G5_IO1");
	state->f0.fld.ioascr.g5_io2 = cm_object_get_child_by_name(state->f0.reg.ioascr, "G5_IO2");
	state->f0.fld.ioascr.g5_io3 = cm_object_get_child_by_name(state->f0.reg.ioascr, "G5_IO3");
	state->f0.fld.ioascr.g5_io4 = cm_object_get_child_by_name(state->f0.reg.ioascr, "G5_IO4");
	state->f0.fld.ioascr.g6_io1 = cm_object_get_child_by_name(state->f0.reg.ioascr, "G6_IO1");
	state->f0.fld.ioascr.g6_io2 = cm_object_get_child_by_name(state->f0.reg.ioascr, "G6_IO2");
	state->f0.fld.ioascr.g6_io3 = cm_object_get_child_by_name(state->f0.reg.ioascr, "G6_IO3");
	state->f0.fld.ioascr.g6_io4 = cm_object_get_child_by_name(state->f0.reg.ioascr, "G6_IO4");

	// IOSCR bitfields.
	state->f0.fld.ioscr.g1_io1 = cm_object_get_child_by_name(state->f0.reg.ioscr, "G1_IO1");
	state->f0.fld.ioscr.g1_io2 = cm_object_get_child_by_name(state->f0.reg.ioscr, "G1_IO2");
	state->f0.fld.ioscr.g1_io3 = cm_object_get_child_by_name(state->f0.reg.ioscr, "G1_IO3");
	state->f0.fld.ioscr.g1_io4 = cm_object_get_child_by_name(state->f0.reg.ioscr, "G1_IO4");
	state->f0.fld.ioscr.g2_io1 = cm_object_get_child_by_name(state->f0.reg.ioscr, "G2_IO1");
	state->f0.fld.ioscr.g2_io2 = cm_object_get_child_by_name(state->f0.reg.ioscr, "G2_IO2");
	state->f0.fld.ioscr.g2_io3 = cm_object_get_child_by_name(state->f0.reg.ioscr, "G2_IO3");
	state->f0.fld.ioscr.g2_io4 = cm_object_get_child_by_name(state->f0.reg.ioscr, "G2_IO4");
	state->f0.fld.ioscr.g3_io1 = cm_object_get_child_by_name(state->f0.reg.ioscr, "G3_IO1");
	state->f0.fld.ioscr.g3_io2 = cm_object_get_child_by_name(state->f0.reg.ioscr, "G3_IO2");
	state->f0.fld.ioscr.g3_io3 = cm_object_get_child_by_name(state->f0.reg.ioscr, "G3_IO3");
	state->f0.fld.ioscr.g3_io4 = cm_object_get_child_by_name(state->f0.reg.ioscr, "G3_IO4");
	state->f0.fld.ioscr.g4_io1 = cm_object_get_child_by_name(state->f0.reg.ioscr, "G4_IO1");
	state->f0.fld.ioscr.g4_io2 = cm_object_get_child_by_name(state->f0.reg.ioscr, "G4_IO2");
	state->f0.fld.ioscr.g4_io3 = cm_object_get_child_by_name(state->f0.reg.ioscr, "G4_IO3");
	state->f0.fld.ioscr.g4_io4 = cm_object_get_child_by_name(state->f0.reg.ioscr, "G4_IO4");
	state->f0.fld.ioscr.g5_io1 = cm_object_get_child_by_name(state->f0.reg.ioscr, "G5_IO1");
	state->f0.fld.ioscr.g5_io2 = cm_object_get_child_by_name(state->f0.reg.ioscr, "G5_IO2");
	state->f0.fld.ioscr.g5_io3 = cm_object_get_child_by_name(state->f0.reg.ioscr, "G5_IO3");
	state->f0.fld.ioscr.g5_io4 = cm_object_get_child_by_name(state->f0.reg.ioscr, "G5_IO4");
	state->f0.fld.ioscr.g6_io1 = cm_object_get_child_by_name(state->f0.reg.ioscr, "G6_IO1");
	state->f0.fld.ioscr.g6_io2 = cm_object_get_child_by_name(state->f0.reg.ioscr, "G6_IO2");
	state->f0.fld.ioscr.g6_io3 = cm_object_get_child_by_name(state->f0.reg.ioscr, "G6_IO3");
	state->f0.fld.ioscr.g6_io4 = cm_object_get_child_by_name(state->f0.reg.ioscr, "G6_IO4");

	// IOCCR bitfields.
	state->f0.fld.ioccr.g1_io1 = cm_object_get_child_by_name(state->f0.reg.ioccr, "G1_IO1");
	state->f0.fld.ioccr.g1_io2 = cm_object_get_child_by_name(state->f0.reg.ioccr, "G1_IO2");
	state->f0.fld.ioccr.g1_io3 = cm_object_get_child_by_name(state->f0.reg.ioccr, "G1_IO3");
	state->f0.fld.ioccr.g1_io4 = cm_object_get_child_by_name(state->f0.reg.ioccr, "G1_IO4");
	state->f0.fld.ioccr.g2_io1 = cm_object_get_child_by_name(state->f0.reg.ioccr, "G2_IO1");
	state->f0.fld.ioccr.g2_io2 = cm_object_get_child_by_name(state->f0.reg.ioccr, "G2_IO2");
	state->f0.fld.ioccr.g2_io3 = cm_object_get_child_by_name(state->f0.reg.ioccr, "G2_IO3");
	state->f0.fld.ioccr.g2_io4 = cm_object_get_child_by_name(state->f0.reg.ioccr, "G2_IO4");
	state->f0.fld.ioccr.g3_io1 = cm_object_get_child_by_name(state->f0.reg.ioccr, "G3_IO1");
	state->f0.fld.ioccr.g3_io2 = cm_object_get_child_by_name(state->f0.reg.ioccr, "G3_IO2");
	state->f0.fld.ioccr.g3_io3 = cm_object_get_child_by_name(state->f0.reg.ioccr, "G3_IO3");
	state->f0.fld.ioccr.g3_io4 = cm_object_get_child_by_name(state->f0.reg.ioccr, "G3_IO4");
	state->f0.fld.ioccr.g4_io1 = cm_object_get_child_by_name(state->f0.reg.ioccr, "G4_IO1");
	state->f0.fld.ioccr.g4_io2 = cm_object_get_child_by_name(state->f0.reg.ioccr, "G4_IO2");
	state->f0.fld.ioccr.g4_io3 = cm_object_get_child_by_name(state->f0.reg.ioccr, "G4_IO3");
	state->f0.fld.ioccr.g4_io4 = cm_object_get_child_by_name(state->f0.reg.ioccr, "G4_IO4");
	state->f0.fld.ioccr.g5_io1 = cm_object_get_child_by_name(state->f0.reg.ioccr, "G5_IO1");
	state->f0.fld.ioccr.g5_io2 = cm_object_get_child_by_name(state->f0.reg.ioccr, "G5_IO2");
	state->f0.fld.ioccr.g5_io3 = cm_object_get_child_by_name(state->f0.reg.ioccr, "G5_IO3");
	state->f0.fld.ioccr.g5_io4 = cm_object_get_child_by_name(state->f0.reg.ioccr, "G5_IO4");
	state->f0.fld.ioccr.g6_io1 = cm_object_get_child_by_name(state->f0.reg.ioccr, "G6_IO1");
	state->f0.fld.ioccr.g6_io2 = cm_object_get_child_by_name(state->f0.reg.ioccr, "G6_IO2");
	state->f0.fld.ioccr.g6_io3 = cm_object_get_child_by_name(state->f0.reg.ioccr, "G6_IO3");
	state->f0.fld.ioccr.g6_io4 = cm_object_get_child_by_name(state->f0.reg.ioccr, "G6_IO4");

	// IOGCSR bitfields.
	state->f0.fld.iogcsr.g1e = cm_object_get_child_by_name(state->f0.reg.iogcsr, "G1E");
	state->f0.fld.iogcsr.g2e = cm_object_get_child_by_name(state->f0.reg.iogcsr, "G2E");
	state->f0.fld.iogcsr.g3e = cm_object_get_child_by_name(state->f0.reg.iogcsr, "G3E");
	state->f0.fld.iogcsr.g4e = cm_object_get_child_by_name(state->f0.reg.iogcsr, "G4E");
	state->f0.fld.iogcsr.g5e = cm_object_get_child_by_name(state->f0.reg.iogcsr, "G5E");
	state->f0.fld.iogcsr.g6e = cm_object_get_child_by_name(state->f0.reg.iogcsr, "G6E");
	state->f0.fld.iogcsr.g7e = cm_object_get_child_by_name(state->f0.reg.iogcsr, "G7E");
	state->f0.fld.iogcsr.g8e = cm_object_get_child_by_name(state->f0.reg.iogcsr, "G8E");
	state->f0.fld.iogcsr.g1s = cm_object_get_child_by_name(state->f0.reg.iogcsr, "G1S");
	state->f0.fld.iogcsr.g2s = cm_object_get_child_by_name(state->f0.reg.iogcsr, "G2S");
	state->f0.fld.iogcsr.g3s = cm_object_get_child_by_name(state->f0.reg.iogcsr, "G3S");
	state->f0.fld.iogcsr.g4s = cm_object_get_child_by_name(state->f0.reg.iogcsr, "G4S");
	state->f0.fld.iogcsr.g5s = cm_object_get_child_by_name(state->f0.reg.iogcsr, "G5S");
	state->f0.fld.iogcsr.g6s = cm_object_get_child_by_name(state->f0.reg.iogcsr, "G6S");
	state->f0.fld.iogcsr.g7s = cm_object_get_child_by_name(state->f0.reg.iogcsr, "G7S");
	state->f0.fld.iogcsr.g8s = cm_object_get_child_by_name(state->f0.reg.iogcsr, "G8S");

	// IOG1CR bitfields.
	state->f0.fld.iog1cr.cnt = cm_object_get_child_by_name(state->f0.reg.iog1cr, "CNT");

	// IOG2CR bitfields.
	state->f0.fld.iog2cr.cnt = cm_object_get_child_by_name(state->f0.reg.iog2cr, "CNT");

	// IOG3CR bitfields.
	state->f0.fld.iog3cr.cnt = cm_object_get_child_by_name(state->f0.reg.iog3cr, "CNT");

	// IOG4CR bitfields.
	state->f0.fld.iog4cr.cnt = cm_object_get_child_by_name(state->f0.reg.iog4cr, "CNT");

	// IOG5CR bitfields.
	state->f0.fld.iog5cr.cnt = cm_object_get_child_by_name(state->f0.reg.iog5cr, "CNT");

	// IOG6CR bitfields.
	state->f0.fld.iog6cr.cnt = cm_object_get_child_by_name(state->f0.reg.iog6cr, "CNT");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// CEC (HDMI-CEC controller) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F0 CEC (HDMI-CEC controller) registers.
		struct {
			Object *cr; // 0x0 Control register
			Object *cfgr; // 0x4 Configuration register
			Object *txdr; // 0x8 Tx data register
			Object *rxdr; // 0xC Rx Data Register
			Object *isr; // 0x10 Interrupt and Status Register
			Object *ier; // 0x14 Interrupt enable register
		} reg;

		struct {

			// CR (Control register) bitfields.
			struct {
				Object *cecen; // [0:0] CEC Enable
				Object *txsom; // [1:1] Tx start of message
				Object *txeom; // [2:2] Tx End Of Message
			} cr;

			// CFGR (Configuration register) bitfields.
			struct {
				Object *oar; // [0:3] Own Address
				Object *lstn; // [4:4] Listen mode
				Object *sft; // [5:7] Signal Free Time
				Object *rxtol; // [8:8] Rx-Tolerance
				Object *brestp; // [9:9] Rx-stop on bit rising error
				Object *bregen; // [10:10] Generate error-bit on bit rising error
				Object *lbpegen; // [11:11] Generate Error-Bit on Long Bit Period Error
			} cfgr;

			// TXDR (Tx data register) bitfields.
			struct {
				Object *txd; // [0:7] Tx Data register
			} txdr;

			// RXDR (Rx Data Register) bitfields.
			struct {
				Object *rxdr; // [0:7] CEC Rx Data Register
			} rxdr;

			// ISR (Interrupt and Status Register) bitfields.
			struct {
				Object *rxbr; // [0:0] Rx-Byte Received
				Object *rxend; // [1:1] End Of Reception
				Object *rxovr; // [2:2] Rx-Overrun
				Object *bre; // [3:3] Rx-Bit rising error
				Object *sbpe; // [4:4] Rx-Short Bit period error
				Object *lbpe; // [5:5] Rx-Long Bit Period Error
				Object *rxacke; // [6:6] Rx-Missing Acknowledge
				Object *arblst; // [7:7] Arbitration Lost
				Object *txbr; // [8:8] Tx-Byte Request
				Object *txend; // [9:9] End of Transmission
				Object *txudr; // [10:10] Tx-Buffer Underrun
				Object *txerr; // [11:11] Tx-Error
				Object *txacke; // [12:12] Tx-Missing acknowledge error
			} isr;

			// IER (Interrupt enable register) bitfields.
			struct {
				Object *rxbrie; // [0:0] Rx-Byte Received Interrupt Enable
				Object *rxendie; // [1:1] End Of Reception Interrupt Enable
				Object *rxovrie; // [2:2] Rx-Buffer Overrun Interrupt Enable
				Object *breie; // [3:3] Bit Rising Error Interrupt Enable
				Object *sbpeie; // [4:4] Short Bit Period Error Interrupt Enable
				Object *lbpeie; // [5:5] Long Bit Period Error Interrupt Enable
				Object *rxackie; // [6:6] Rx-Missing Acknowledge Error Interrupt Enable
				Object *arblstie; // [7:7] Arbitration Lost Interrupt Enable
				Object *txbrie; // [8:8] Tx-Byte Request Interrupt Enable
				Object *txendie; // [9:9] Tx-End of message interrupt enable
				Object *txudrie; // [10:10] Tx-Underrun interrupt enable
				Object *txerrie; // [11:11] Tx-Error Interrupt Enable
				Object *txackie; // [12:12] Tx-Missing Acknowledge Error Interrupt Enable
			} ier;
		} fld;
	} f0;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32CECState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_cec_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32CECState *state = STM32_CEC_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f0.reg.cr = cm_object_get_child_by_name(obj, "CR");
	state->f0.reg.cfgr = cm_object_get_child_by_name(obj, "CFGR");
	state->f0.reg.txdr = cm_object_get_child_by_name(obj, "TXDR");
	state->f0.reg.rxdr = cm_object_get_child_by_name(obj, "RXDR");
	state->f0.reg.isr = cm_object_get_child_by_name(obj, "ISR");
	state->f0.reg.ier = cm_object_get_child_by_name(obj, "IER");

	// CR bitfields.
	state->f0.fld.cr.cecen = cm_object_get_child_by_name(state->f0.reg.cr, "CECEN");
	state->f0.fld.cr.txsom = cm_object_get_child_by_name(state->f0.reg.cr, "TXSOM");
	state->f0.fld.cr.txeom = cm_object_get_child_by_name(state->f0.reg.cr, "TXEOM");

	// CFGR bitfields.
	state->f0.fld.cfgr.oar = cm_object_get_child_by_name(state->f0.reg.cfgr, "OAR");
	state->f0.fld.cfgr.lstn = cm_object_get_child_by_name(state->f0.reg.cfgr, "LSTN");
	state->f0.fld.cfgr.sft = cm_object_get_child_by_name(state->f0.reg.cfgr, "SFT");
	state->f0.fld.cfgr.rxtol = cm_object_get_child_by_name(state->f0.reg.cfgr, "RXTOL");
	state->f0.fld.cfgr.brestp = cm_object_get_child_by_name(state->f0.reg.cfgr, "BRESTP");
	state->f0.fld.cfgr.bregen = cm_object_get_child_by_name(state->f0.reg.cfgr, "BREGEN");
	state->f0.fld.cfgr.lbpegen = cm_object_get_child_by_name(state->f0.reg.cfgr, "LBPEGEN");

	// TXDR bitfields.
	state->f0.fld.txdr.txd = cm_object_get_child_by_name(state->f0.reg.txdr, "TXD");

	// RXDR bitfields.
	state->f0.fld.rxdr.rxdr = cm_object_get_child_by_name(state->f0.reg.rxdr, "RXDR");

	// ISR bitfields.
	state->f0.fld.isr.rxbr = cm_object_get_child_by_name(state->f0.reg.isr, "RXBR");
	state->f0.fld.isr.rxend = cm_object_get_child_by_name(state->f0.reg.isr, "RXEND");
	state->f0.fld.isr.rxovr = cm_object_get_child_by_name(state->f0.reg.isr, "RXOVR");
	state->f0.fld.isr.bre = cm_object_get_child_by_name(state->f0.reg.isr, "BRE");
	state->f0.fld.isr.sbpe = cm_object_get_child_by_name(state->f0.reg.isr, "SBPE");
	state->f0.fld.isr.lbpe = cm_object_get_child_by_name(state->f0.reg.isr, "LBPE");
	state->f0.fld.isr.rxacke = cm_object_get_child_by_name(state->f0.reg.isr, "RXACKE");
	state->f0.fld.isr.arblst = cm_object_get_child_by_name(state->f0.reg.isr, "ARBLST");
	state->f0.fld.isr.txbr = cm_object_get_child_by_name(state->f0.reg.isr, "TXBR");
	state->f0.fld.isr.txend = cm_object_get_child_by_name(state->f0.reg.isr, "TXEND");
	state->f0.fld.isr.txudr = cm_object_get_child_by_name(state->f0.reg.isr, "TXUDR");
	state->f0.fld.isr.txerr = cm_object_get_child_by_name(state->f0.reg.isr, "TXERR");
	state->f0.fld.isr.txacke = cm_object_get_child_by_name(state->f0.reg.isr, "TXACKE");

	// IER bitfields.
	state->f0.fld.ier.rxbrie = cm_object_get_child_by_name(state->f0.reg.ier, "RXBRIE");
	state->f0.fld.ier.rxendie = cm_object_get_child_by_name(state->f0.reg.ier, "RXENDIE");
	state->f0.fld.ier.rxovrie = cm_object_get_child_by_name(state->f0.reg.ier, "RXOVRIE");
	state->f0.fld.ier.breie = cm_object_get_child_by_name(state->f0.reg.ier, "BREIE");
	state->f0.fld.ier.sbpeie = cm_object_get_child_by_name(state->f0.reg.ier, "SBPEIE");
	state->f0.fld.ier.lbpeie = cm_object_get_child_by_name(state->f0.reg.ier, "LBPEIE");
	state->f0.fld.ier.rxackie = cm_object_get_child_by_name(state->f0.reg.ier, "RXACKIE");
	state->f0.fld.ier.arblstie = cm_object_get_child_by_name(state->f0.reg.ier, "ARBLSTIE");
	state->f0.fld.ier.txbrie = cm_object_get_child_by_name(state->f0.reg.ier, "TXBRIE");
	state->f0.fld.ier.txendie = cm_object_get_child_by_name(state->f0.reg.ier, "TXENDIE");
	state->f0.fld.ier.txudrie = cm_object_get_child_by_name(state->f0.reg.ier, "TXUDRIE");
	state->f0.fld.ier.txerrie = cm_object_get_child_by_name(state->f0.reg.ier, "TXERRIE");
	state->f0.fld.ier.txackie = cm_object_get_child_by_name(state->f0.reg.ier, "TXACKIE");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// FLASH (Flash) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F0 FLASH (Flash) registers.
		struct {
			Object *acr; // 0x0 Flash access control register
			Object *keyr; // 0x4 Flash key register
			Object *optkeyr; // 0x8 Flash option key register
			Object *sr; // 0xC Flash status register
			Object *cr; // 0x10 Flash control register
			Object *ar; // 0x14 Flash address register
			Object *obr; // 0x1C Option byte register
			Object *wrpr; // 0x20 Write protection register
		} reg;

		struct {

			// ACR (Flash access control register) bitfields.
			struct {
				Object *latency; // [0:2] LATENCY
				Object *prftbe; // [4:4] PRFTBE
				Object *prftbs; // [5:5] PRFTBS
			} acr;

			// KEYR (Flash key register) bitfields.
			struct {
				Object *fkeyr; // [0:31] Flash Key
			} keyr;

			// OPTKEYR (Flash option key register) bitfields.
			struct {
				Object *optkeyr; // [0:31] Option byte key
			} optkeyr;

			// SR (Flash status register) bitfields.
			struct {
				Object *bsy; // [0:0] Busy
				Object *pgerr; // [2:2] Programming error
				Object *wrprt; // [4:4] Write protection error
				Object *eop; // [5:5] End of operation
			} sr;

			// CR (Flash control register) bitfields.
			struct {
				Object *pg; // [0:0] Programming
				Object *per; // [1:1] Page erase
				Object *mer; // [2:2] Mass erase
				Object *optpg; // [4:4] Option byte programming
				Object *opter; // [5:5] Option byte erase
				Object *strt; // [6:6] Start
				Object *lock; // [7:7] Lock
				Object *optwre; // [9:9] Option bytes write enable
				Object *errie; // [10:10] Error interrupt enable
				Object *eopie; // [12:12] End of operation interrupt enable
				Object *force_optload; // [13:13] Force option byte loading
			} cr;

			// AR (Flash address register) bitfields.
			struct {
				Object *far; // [0:31] Flash address
			} ar;

			// OBR (Option byte register) bitfields.
			struct {
				Object *opterr; // [0:0] Option byte error
				Object *level1_prot; // [1:1] Level 1 protection status
				Object *level2_prot; // [2:2] Level 2 protection status
				Object *wdg_sw; // [8:8] WDG_SW
				Object *nrst_stop; // [9:9] NRST_STOP
				Object *nrst_stdby; // [10:10] NRST_STDBY
				Object *boot1; // [12:12] BOOT1
				Object *vdda_monitor; // [13:13] VDDA_MONITOR
				Object *data0; // [16:23] Data0
				Object *data1; // [24:31] Data1
			} obr;

			// WRPR (Write protection register) bitfields.
			struct {
				Object *wrp; // [0:31] Write protect
			} wrpr;
		} fld;
	} f0;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32FLASHState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_flash_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32FLASHState *state = STM32_FLASH_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f0.reg.acr = cm_object_get_child_by_name(obj, "ACR");
	state->f0.reg.keyr = cm_object_get_child_by_name(obj, "KEYR");
	state->f0.reg.optkeyr = cm_object_get_child_by_name(obj, "OPTKEYR");
	state->f0.reg.sr = cm_object_get_child_by_name(obj, "SR");
	state->f0.reg.cr = cm_object_get_child_by_name(obj, "CR");
	state->f0.reg.ar = cm_object_get_child_by_name(obj, "AR");
	state->f0.reg.obr = cm_object_get_child_by_name(obj, "OBR");
	state->f0.reg.wrpr = cm_object_get_child_by_name(obj, "WRPR");

	// ACR bitfields.
	state->f0.fld.acr.latency = cm_object_get_child_by_name(state->f0.reg.acr, "LATENCY");
	state->f0.fld.acr.prftbe = cm_object_get_child_by_name(state->f0.reg.acr, "PRFTBE");
	state->f0.fld.acr.prftbs = cm_object_get_child_by_name(state->f0.reg.acr, "PRFTBS");

	// KEYR bitfields.
	state->f0.fld.keyr.fkeyr = cm_object_get_child_by_name(state->f0.reg.keyr, "FKEYR");

	// OPTKEYR bitfields.
	state->f0.fld.optkeyr.optkeyr = cm_object_get_child_by_name(state->f0.reg.optkeyr, "OPTKEYR");

	// SR bitfields.
	state->f0.fld.sr.bsy = cm_object_get_child_by_name(state->f0.reg.sr, "BSY");
	state->f0.fld.sr.pgerr = cm_object_get_child_by_name(state->f0.reg.sr, "PGERR");
	state->f0.fld.sr.wrprt = cm_object_get_child_by_name(state->f0.reg.sr, "WRPRT");
	state->f0.fld.sr.eop = cm_object_get_child_by_name(state->f0.reg.sr, "EOP");

	// CR bitfields.
	state->f0.fld.cr.pg = cm_object_get_child_by_name(state->f0.reg.cr, "PG");
	state->f0.fld.cr.per = cm_object_get_child_by_name(state->f0.reg.cr, "PER");
	state->f0.fld.cr.mer = cm_object_get_child_by_name(state->f0.reg.cr, "MER");
	state->f0.fld.cr.optpg = cm_object_get_child_by_name(state->f0.reg.cr, "OPTPG");
	state->f0.fld.cr.opter = cm_object_get_child_by_name(state->f0.reg.cr, "OPTER");
	state->f0.fld.cr.strt = cm_object_get_child_by_name(state->f0.reg.cr, "STRT");
	state->f0.fld.cr.lock = cm_object_get_child_by_name(state->f0.reg.cr, "LOCK");
	state->f0.fld.cr.optwre = cm_object_get_child_by_name(state->f0.reg.cr, "OPTWRE");
	state->f0.fld.cr.errie = cm_object_get_child_by_name(state->f0.reg.cr, "ERRIE");
	state->f0.fld.cr.eopie = cm_object_get_child_by_name(state->f0.reg.cr, "EOPIE");
	state->f0.fld.cr.force_optload = cm_object_get_child_by_name(state->f0.reg.cr, "FORCE_OPTLOAD");

	// AR bitfields.
	state->f0.fld.ar.far = cm_object_get_child_by_name(state->f0.reg.ar, "FAR");

	// OBR bitfields.
	state->f0.fld.obr.opterr = cm_object_get_child_by_name(state->f0.reg.obr, "OPTERR");
	state->f0.fld.obr.level1_prot = cm_object_get_child_by_name(state->f0.reg.obr, "LEVEL1_PROT");
	state->f0.fld.obr.level2_prot = cm_object_get_child_by_name(state->f0.reg.obr, "LEVEL2_PROT");
	state->f0.fld.obr.wdg_sw = cm_object_get_child_by_name(state->f0.reg.obr, "WDG_SW");
	state->f0.fld.obr.nrst_stop = cm_object_get_child_by_name(state->f0.reg.obr, "nRST_STOP");
	state->f0.fld.obr.nrst_stdby = cm_object_get_child_by_name(state->f0.reg.obr, "nRST_STDBY");
	state->f0.fld.obr.boot1 = cm_object_get_child_by_name(state->f0.reg.obr, "BOOT1");
	state->f0.fld.obr.vdda_monitor = cm_object_get_child_by_name(state->f0.reg.obr, "VDDA_MONITOR");
	state->f0.fld.obr.data0 = cm_object_get_child_by_name(state->f0.reg.obr, "Data0");
	state->f0.fld.obr.data1 = cm_object_get_child_by_name(state->f0.reg.obr, "Data1");

	// WRPR bitfields.
	state->f0.fld.wrpr.wrp = cm_object_get_child_by_name(state->f0.reg.wrpr, "WRP");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DBGMCU (Debug support) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F0 DBGMCU (Debug support) registers.
		struct {
			Object *idcode; // 0x0 MCU Device ID Code Register
			Object *cr; // 0x4 Debug MCU Configuration Register
			Object *apblfz; // 0x8 APB Low Freeze Register
			Object *apbhfz; // 0xC APB High Freeze Register
		} reg;

		struct {

			// IDCODE (MCU Device ID Code Register) bitfields.
			struct {
				Object *dev_id; // [0:11] Device Identifier
				Object *div_id; // [12:15] Division Identifier
				Object *rev_id; // [16:31] Revision Identifier
			} idcode;

			// CR (Debug MCU Configuration Register) bitfields.
			struct {
				Object *dbg_stop; // [1:1] Debug Stop Mode
				Object *dbg_standby; // [2:2] Debug Standby Mode
			} cr;

			// APBLFZ (APB Low Freeze Register) bitfields.
			struct {
				Object *dbg_timer2_stop; // [0:0] Debug Timer 2 stopped when Core is halted
				Object *dbg_timer3_stop; // [1:1] Debug Timer 3 stopped when Core is halted
				Object *dbg_timer6_stop; // [4:4] Debug Timer 6 stopped when Core is halted
				Object *dbg_timer14_stop; // [8:8] Debug Timer 14 stopped when Core is halted
				Object *dbg_rtc_stop; // [10:10] Debug RTC stopped when Core is halted
				Object *dbg_wwdg_stop; // [11:11] Debug Window Wachdog stopped when Core is halted
				Object *dbg_iwdg_stop; // [12:12] Debug Independent Wachdog stopped when Core is halted
				Object *i2c1_smbus_timeout; // [21:21] SMBUS timeout mode stopped when Core is halted
			} apblfz;

			// APBHFZ (APB High Freeze Register) bitfields.
			struct {
				Object *dbg_timer1_stop; // [11:11] Debug Timer 1 stopped when Core is halted
				Object *dbg_timer15_sto; // [16:16] Debug Timer 15 stopped when Core is halted
				Object *dbg_timer16_sto; // [17:17] Debug Timer 16 stopped when Core is halted
				Object *dbg_timer17_sto; // [18:18] Debug Timer 17 stopped when Core is halted
			} apbhfz;
		} fld;
	} f0;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32DBGMCUState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_dbgmcu_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32DBGMCUState *state = STM32_DBGMCU_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f0.reg.idcode = cm_object_get_child_by_name(obj, "IDCODE");
	state->f0.reg.cr = cm_object_get_child_by_name(obj, "CR");
	state->f0.reg.apblfz = cm_object_get_child_by_name(obj, "APBLFZ");
	state->f0.reg.apbhfz = cm_object_get_child_by_name(obj, "APBHFZ");

	// IDCODE bitfields.
	state->f0.fld.idcode.dev_id = cm_object_get_child_by_name(state->f0.reg.idcode, "DEV_ID");
	state->f0.fld.idcode.div_id = cm_object_get_child_by_name(state->f0.reg.idcode, "DIV_ID");
	state->f0.fld.idcode.rev_id = cm_object_get_child_by_name(state->f0.reg.idcode, "REV_ID");

	// CR bitfields.
	state->f0.fld.cr.dbg_stop = cm_object_get_child_by_name(state->f0.reg.cr, "DBG_STOP");
	state->f0.fld.cr.dbg_standby = cm_object_get_child_by_name(state->f0.reg.cr, "DBG_STANDBY");

	// APBLFZ bitfields.
	state->f0.fld.apblfz.dbg_timer2_stop = cm_object_get_child_by_name(state->f0.reg.apblfz, "DBG_TIMER2_STOP");
	state->f0.fld.apblfz.dbg_timer3_stop = cm_object_get_child_by_name(state->f0.reg.apblfz, "DBG_TIMER3_STOP");
	state->f0.fld.apblfz.dbg_timer6_stop = cm_object_get_child_by_name(state->f0.reg.apblfz, "DBG_TIMER6_STOP");
	state->f0.fld.apblfz.dbg_timer14_stop = cm_object_get_child_by_name(state->f0.reg.apblfz, "DBG_TIMER14_STOP");
	state->f0.fld.apblfz.dbg_rtc_stop = cm_object_get_child_by_name(state->f0.reg.apblfz, "DBG_RTC_STOP");
	state->f0.fld.apblfz.dbg_wwdg_stop = cm_object_get_child_by_name(state->f0.reg.apblfz, "DBG_WWDG_STOP");
	state->f0.fld.apblfz.dbg_iwdg_stop = cm_object_get_child_by_name(state->f0.reg.apblfz, "DBG_IWDG_STOP");
	state->f0.fld.apblfz.i2c1_smbus_timeout = cm_object_get_child_by_name(state->f0.reg.apblfz, "I2C1_SMBUS_TIMEOUT");

	// APBHFZ bitfields.
	state->f0.fld.apbhfz.dbg_timer1_stop = cm_object_get_child_by_name(state->f0.reg.apbhfz, "DBG_TIMER1_STOP");
	state->f0.fld.apbhfz.dbg_timer15_sto = cm_object_get_child_by_name(state->f0.reg.apbhfz, "DBG_TIMER15_STO");
	state->f0.fld.apbhfz.dbg_timer16_sto = cm_object_get_child_by_name(state->f0.reg.apbhfz, "DBG_TIMER16_STO");
	state->f0.fld.apbhfz.dbg_timer17_sto = cm_object_get_child_by_name(state->f0.reg.apbhfz, "DBG_TIMER17_STO");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// USB (Universal serial bus full-speed device interface) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F0 USB (Universal serial bus full-speed device interface) registers.
		struct {
			Object *ep0r; // 0x0 Endpoint 0 register
			Object *ep1r; // 0x4 Endpoint 1 register
			Object *ep2r; // 0x8 Endpoint 2 register
			Object *ep3r; // 0xC Endpoint 3 register
			Object *ep4r; // 0x10 Endpoint 4 register
			Object *ep5r; // 0x14 Endpoint 5 register
			Object *ep6r; // 0x18 Endpoint 6 register
			Object *ep7r; // 0x1C Endpoint 7 register
			Object *cntr; // 0x40 Control register
			Object *istr; // 0x44 Interrupt status register
			Object *fnr; // 0x48 Frame number register
			Object *daddr; // 0x4C Device address
			Object *btable; // 0x50 Buffer table address
			Object *lpmcsr; // 0x54 LPM control and status register
			Object *bcdr; // 0x58 Battery charging detector
		} reg;

		struct {

			// EP0R (Endpoint 0 register) bitfields.
			struct {
				Object *ea; // [0:3] Endpoint address
				Object *stat_tx; // [4:5] Status bits, for transmission transfers
				Object *dtog_tx; // [6:6] Data Toggle, for transmission transfers
				Object *ctr_tx; // [7:7] Correct Transfer for transmission
				Object *ep_kind; // [8:8] Endpoint kind
				Object *ep_type; // [9:10] Endpoint type
				Object *setup; // [11:11] Setup transaction completed
				Object *stat_rx; // [12:13] Status bits, for reception transfers
				Object *dtog_rx; // [14:14] Data Toggle, for reception transfers
				Object *ctr_rx; // [15:15] Correct transfer for reception
			} ep0r;

			// EP1R (Endpoint 1 register) bitfields.
			struct {
				Object *ea; // [0:3] Endpoint address
				Object *stat_tx; // [4:5] Status bits, for transmission transfers
				Object *dtog_tx; // [6:6] Data Toggle, for transmission transfers
				Object *ctr_tx; // [7:7] Correct Transfer for transmission
				Object *ep_kind; // [8:8] Endpoint kind
				Object *ep_type; // [9:10] Endpoint type
				Object *setup; // [11:11] Setup transaction completed
				Object *stat_rx; // [12:13] Status bits, for reception transfers
				Object *dtog_rx; // [14:14] Data Toggle, for reception transfers
				Object *ctr_rx; // [15:15] Correct transfer for reception
			} ep1r;

			// EP2R (Endpoint 2 register) bitfields.
			struct {
				Object *ea; // [0:3] Endpoint address
				Object *stat_tx; // [4:5] Status bits, for transmission transfers
				Object *dtog_tx; // [6:6] Data Toggle, for transmission transfers
				Object *ctr_tx; // [7:7] Correct Transfer for transmission
				Object *ep_kind; // [8:8] Endpoint kind
				Object *ep_type; // [9:10] Endpoint type
				Object *setup; // [11:11] Setup transaction completed
				Object *stat_rx; // [12:13] Status bits, for reception transfers
				Object *dtog_rx; // [14:14] Data Toggle, for reception transfers
				Object *ctr_rx; // [15:15] Correct transfer for reception
			} ep2r;

			// EP3R (Endpoint 3 register) bitfields.
			struct {
				Object *ea; // [0:3] Endpoint address
				Object *stat_tx; // [4:5] Status bits, for transmission transfers
				Object *dtog_tx; // [6:6] Data Toggle, for transmission transfers
				Object *ctr_tx; // [7:7] Correct Transfer for transmission
				Object *ep_kind; // [8:8] Endpoint kind
				Object *ep_type; // [9:10] Endpoint type
				Object *setup; // [11:11] Setup transaction completed
				Object *stat_rx; // [12:13] Status bits, for reception transfers
				Object *dtog_rx; // [14:14] Data Toggle, for reception transfers
				Object *ctr_rx; // [15:15] Correct transfer for reception
			} ep3r;

			// EP4R (Endpoint 4 register) bitfields.
			struct {
				Object *ea; // [0:3] Endpoint address
				Object *stat_tx; // [4:5] Status bits, for transmission transfers
				Object *dtog_tx; // [6:6] Data Toggle, for transmission transfers
				Object *ctr_tx; // [7:7] Correct Transfer for transmission
				Object *ep_kind; // [8:8] Endpoint kind
				Object *ep_type; // [9:10] Endpoint type
				Object *setup; // [11:11] Setup transaction completed
				Object *stat_rx; // [12:13] Status bits, for reception transfers
				Object *dtog_rx; // [14:14] Data Toggle, for reception transfers
				Object *ctr_rx; // [15:15] Correct transfer for reception
			} ep4r;

			// EP5R (Endpoint 5 register) bitfields.
			struct {
				Object *ea; // [0:3] Endpoint address
				Object *stat_tx; // [4:5] Status bits, for transmission transfers
				Object *dtog_tx; // [6:6] Data Toggle, for transmission transfers
				Object *ctr_tx; // [7:7] Correct Transfer for transmission
				Object *ep_kind; // [8:8] Endpoint kind
				Object *ep_type; // [9:10] Endpoint type
				Object *setup; // [11:11] Setup transaction completed
				Object *stat_rx; // [12:13] Status bits, for reception transfers
				Object *dtog_rx; // [14:14] Data Toggle, for reception transfers
				Object *ctr_rx; // [15:15] Correct transfer for reception
			} ep5r;

			// EP6R (Endpoint 6 register) bitfields.
			struct {
				Object *ea; // [0:3] Endpoint address
				Object *stat_tx; // [4:5] Status bits, for transmission transfers
				Object *dtog_tx; // [6:6] Data Toggle, for transmission transfers
				Object *ctr_tx; // [7:7] Correct Transfer for transmission
				Object *ep_kind; // [8:8] Endpoint kind
				Object *ep_type; // [9:10] Endpoint type
				Object *setup; // [11:11] Setup transaction completed
				Object *stat_rx; // [12:13] Status bits, for reception transfers
				Object *dtog_rx; // [14:14] Data Toggle, for reception transfers
				Object *ctr_rx; // [15:15] Correct transfer for reception
			} ep6r;

			// EP7R (Endpoint 7 register) bitfields.
			struct {
				Object *ea; // [0:3] Endpoint address
				Object *stat_tx; // [4:5] Status bits, for transmission transfers
				Object *dtog_tx; // [6:6] Data Toggle, for transmission transfers
				Object *ctr_tx; // [7:7] Correct Transfer for transmission
				Object *ep_kind; // [8:8] Endpoint kind
				Object *ep_type; // [9:10] Endpoint type
				Object *setup; // [11:11] Setup transaction completed
				Object *stat_rx; // [12:13] Status bits, for reception transfers
				Object *dtog_rx; // [14:14] Data Toggle, for reception transfers
				Object *ctr_rx; // [15:15] Correct transfer for reception
			} ep7r;

			// CNTR (Control register) bitfields.
			struct {
				Object *fres; // [0:0] Force USB Reset
				Object *pdwn; // [1:1] Power down
				Object *lpmode; // [2:2] Low-power mode
				Object *fsusp; // [3:3] Force suspend
				Object *resume; // [4:4] Resume request
				Object *l1resume; // [5:5] LPM L1 Resume request
				Object *l1reqm; // [7:7] LPM L1 state request interrupt mask
				Object *esofm; // [8:8] Expected start of frame interrupt mask
				Object *sofm; // [9:9] Start of frame interrupt mask
				Object *resetm; // [10:10] USB reset interrupt mask
				Object *suspm; // [11:11] Suspend mode interrupt mask
				Object *wkupm; // [12:12] Wakeup interrupt mask
				Object *errm; // [13:13] Error interrupt mask
				Object *pmaovrm; // [14:14] Packet memory area over / underrun interrupt mask
				Object *ctrm; // [15:15] Correct transfer interrupt mask
			} cntr;

			// ISTR (Interrupt status register) bitfields.
			struct {
				Object *ep_id; // [0:3] Endpoint Identifier
				Object *dir; // [4:4] Direction of transaction
				Object *l1req; // [7:7] LPM L1 state request
				Object *esof; // [8:8] Expected start frame
				Object *sof; // [9:9] Start of frame
				Object *reset; // [10:10] Reset request
				Object *susp; // [11:11] Suspend mode request
				Object *wkup; // [12:12] Wakeup
				Object *err; // [13:13] Error
				Object *pmaovr; // [14:14] Packet memory area over / underrun
				Object *ctr; // [15:15] Correct transfer
			} istr;

			// FNR (Frame number register) bitfields.
			struct {
				Object *fn; // [0:10] Frame number
				Object *lsof; // [11:12] Lost SOF
				Object *lck; // [13:13] Locked
				Object *rxdm; // [14:14] Receive data - line status
				Object *rxdp; // [15:15] Receive data + line status
			} fnr;

			// DADDR (Device address) bitfields.
			struct {
				Object *add; // [0:6] Device address
				Object *ef; // [7:7] Enable function
			} daddr;

			// BTABLE (Buffer table address) bitfields.
			struct {
				Object *btable; // [3:15] Buffer table
			} btable;

			// LPMCSR (LPM control and status register) bitfields.
			struct {
				Object *lpmen; // [0:0] LPM support enable
				Object *lpmack; // [1:1] LPM Token acknowledge enable
				Object *remwake; // [3:3] BRemoteWake value
				Object *besl; // [4:7] BESL value
			} lpmcsr;

			// BCDR (Battery charging detector) bitfields.
			struct {
				Object *bcden; // [0:0] Battery charging detector (BCD) enable
				Object *dcden; // [1:1] Data contact detection (DCD) mode enable
				Object *pden; // [2:2] Primary detection (PD) mode enable
				Object *sden; // [3:3] Secondary detection (SD) mode enable
				Object *dcdet; // [4:4] Data contact detection (DCD) status
				Object *pdet; // [5:5] Primary detection (PD) status
				Object *sdet; // [6:6] Secondary detection (SD) status
				Object *ps2det; // [7:7] DM pull-up detection status
				Object *dppu; // [15:15] DP pull-up control
			} bcdr;
		} fld;
	} f0;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32USBState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_usb_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32USBState *state = STM32_USB_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f0.reg.ep0r = cm_object_get_child_by_name(obj, "EP0R");
	state->f0.reg.ep1r = cm_object_get_child_by_name(obj, "EP1R");
	state->f0.reg.ep2r = cm_object_get_child_by_name(obj, "EP2R");
	state->f0.reg.ep3r = cm_object_get_child_by_name(obj, "EP3R");
	state->f0.reg.ep4r = cm_object_get_child_by_name(obj, "EP4R");
	state->f0.reg.ep5r = cm_object_get_child_by_name(obj, "EP5R");
	state->f0.reg.ep6r = cm_object_get_child_by_name(obj, "EP6R");
	state->f0.reg.ep7r = cm_object_get_child_by_name(obj, "EP7R");
	state->f0.reg.cntr = cm_object_get_child_by_name(obj, "CNTR");
	state->f0.reg.istr = cm_object_get_child_by_name(obj, "ISTR");
	state->f0.reg.fnr = cm_object_get_child_by_name(obj, "FNR");
	state->f0.reg.daddr = cm_object_get_child_by_name(obj, "DADDR");
	state->f0.reg.btable = cm_object_get_child_by_name(obj, "BTABLE");
	state->f0.reg.lpmcsr = cm_object_get_child_by_name(obj, "LPMCSR");
	state->f0.reg.bcdr = cm_object_get_child_by_name(obj, "BCDR");

	// EP0R bitfields.
	state->f0.fld.ep0r.ea = cm_object_get_child_by_name(state->f0.reg.ep0r, "EA");
	state->f0.fld.ep0r.stat_tx = cm_object_get_child_by_name(state->f0.reg.ep0r, "STAT_TX");
	state->f0.fld.ep0r.dtog_tx = cm_object_get_child_by_name(state->f0.reg.ep0r, "DTOG_TX");
	state->f0.fld.ep0r.ctr_tx = cm_object_get_child_by_name(state->f0.reg.ep0r, "CTR_TX");
	state->f0.fld.ep0r.ep_kind = cm_object_get_child_by_name(state->f0.reg.ep0r, "EP_KIND");
	state->f0.fld.ep0r.ep_type = cm_object_get_child_by_name(state->f0.reg.ep0r, "EP_TYPE");
	state->f0.fld.ep0r.setup = cm_object_get_child_by_name(state->f0.reg.ep0r, "SETUP");
	state->f0.fld.ep0r.stat_rx = cm_object_get_child_by_name(state->f0.reg.ep0r, "STAT_RX");
	state->f0.fld.ep0r.dtog_rx = cm_object_get_child_by_name(state->f0.reg.ep0r, "DTOG_RX");
	state->f0.fld.ep0r.ctr_rx = cm_object_get_child_by_name(state->f0.reg.ep0r, "CTR_RX");

	// EP1R bitfields.
	state->f0.fld.ep1r.ea = cm_object_get_child_by_name(state->f0.reg.ep1r, "EA");
	state->f0.fld.ep1r.stat_tx = cm_object_get_child_by_name(state->f0.reg.ep1r, "STAT_TX");
	state->f0.fld.ep1r.dtog_tx = cm_object_get_child_by_name(state->f0.reg.ep1r, "DTOG_TX");
	state->f0.fld.ep1r.ctr_tx = cm_object_get_child_by_name(state->f0.reg.ep1r, "CTR_TX");
	state->f0.fld.ep1r.ep_kind = cm_object_get_child_by_name(state->f0.reg.ep1r, "EP_KIND");
	state->f0.fld.ep1r.ep_type = cm_object_get_child_by_name(state->f0.reg.ep1r, "EP_TYPE");
	state->f0.fld.ep1r.setup = cm_object_get_child_by_name(state->f0.reg.ep1r, "SETUP");
	state->f0.fld.ep1r.stat_rx = cm_object_get_child_by_name(state->f0.reg.ep1r, "STAT_RX");
	state->f0.fld.ep1r.dtog_rx = cm_object_get_child_by_name(state->f0.reg.ep1r, "DTOG_RX");
	state->f0.fld.ep1r.ctr_rx = cm_object_get_child_by_name(state->f0.reg.ep1r, "CTR_RX");

	// EP2R bitfields.
	state->f0.fld.ep2r.ea = cm_object_get_child_by_name(state->f0.reg.ep2r, "EA");
	state->f0.fld.ep2r.stat_tx = cm_object_get_child_by_name(state->f0.reg.ep2r, "STAT_TX");
	state->f0.fld.ep2r.dtog_tx = cm_object_get_child_by_name(state->f0.reg.ep2r, "DTOG_TX");
	state->f0.fld.ep2r.ctr_tx = cm_object_get_child_by_name(state->f0.reg.ep2r, "CTR_TX");
	state->f0.fld.ep2r.ep_kind = cm_object_get_child_by_name(state->f0.reg.ep2r, "EP_KIND");
	state->f0.fld.ep2r.ep_type = cm_object_get_child_by_name(state->f0.reg.ep2r, "EP_TYPE");
	state->f0.fld.ep2r.setup = cm_object_get_child_by_name(state->f0.reg.ep2r, "SETUP");
	state->f0.fld.ep2r.stat_rx = cm_object_get_child_by_name(state->f0.reg.ep2r, "STAT_RX");
	state->f0.fld.ep2r.dtog_rx = cm_object_get_child_by_name(state->f0.reg.ep2r, "DTOG_RX");
	state->f0.fld.ep2r.ctr_rx = cm_object_get_child_by_name(state->f0.reg.ep2r, "CTR_RX");

	// EP3R bitfields.
	state->f0.fld.ep3r.ea = cm_object_get_child_by_name(state->f0.reg.ep3r, "EA");
	state->f0.fld.ep3r.stat_tx = cm_object_get_child_by_name(state->f0.reg.ep3r, "STAT_TX");
	state->f0.fld.ep3r.dtog_tx = cm_object_get_child_by_name(state->f0.reg.ep3r, "DTOG_TX");
	state->f0.fld.ep3r.ctr_tx = cm_object_get_child_by_name(state->f0.reg.ep3r, "CTR_TX");
	state->f0.fld.ep3r.ep_kind = cm_object_get_child_by_name(state->f0.reg.ep3r, "EP_KIND");
	state->f0.fld.ep3r.ep_type = cm_object_get_child_by_name(state->f0.reg.ep3r, "EP_TYPE");
	state->f0.fld.ep3r.setup = cm_object_get_child_by_name(state->f0.reg.ep3r, "SETUP");
	state->f0.fld.ep3r.stat_rx = cm_object_get_child_by_name(state->f0.reg.ep3r, "STAT_RX");
	state->f0.fld.ep3r.dtog_rx = cm_object_get_child_by_name(state->f0.reg.ep3r, "DTOG_RX");
	state->f0.fld.ep3r.ctr_rx = cm_object_get_child_by_name(state->f0.reg.ep3r, "CTR_RX");

	// EP4R bitfields.
	state->f0.fld.ep4r.ea = cm_object_get_child_by_name(state->f0.reg.ep4r, "EA");
	state->f0.fld.ep4r.stat_tx = cm_object_get_child_by_name(state->f0.reg.ep4r, "STAT_TX");
	state->f0.fld.ep4r.dtog_tx = cm_object_get_child_by_name(state->f0.reg.ep4r, "DTOG_TX");
	state->f0.fld.ep4r.ctr_tx = cm_object_get_child_by_name(state->f0.reg.ep4r, "CTR_TX");
	state->f0.fld.ep4r.ep_kind = cm_object_get_child_by_name(state->f0.reg.ep4r, "EP_KIND");
	state->f0.fld.ep4r.ep_type = cm_object_get_child_by_name(state->f0.reg.ep4r, "EP_TYPE");
	state->f0.fld.ep4r.setup = cm_object_get_child_by_name(state->f0.reg.ep4r, "SETUP");
	state->f0.fld.ep4r.stat_rx = cm_object_get_child_by_name(state->f0.reg.ep4r, "STAT_RX");
	state->f0.fld.ep4r.dtog_rx = cm_object_get_child_by_name(state->f0.reg.ep4r, "DTOG_RX");
	state->f0.fld.ep4r.ctr_rx = cm_object_get_child_by_name(state->f0.reg.ep4r, "CTR_RX");

	// EP5R bitfields.
	state->f0.fld.ep5r.ea = cm_object_get_child_by_name(state->f0.reg.ep5r, "EA");
	state->f0.fld.ep5r.stat_tx = cm_object_get_child_by_name(state->f0.reg.ep5r, "STAT_TX");
	state->f0.fld.ep5r.dtog_tx = cm_object_get_child_by_name(state->f0.reg.ep5r, "DTOG_TX");
	state->f0.fld.ep5r.ctr_tx = cm_object_get_child_by_name(state->f0.reg.ep5r, "CTR_TX");
	state->f0.fld.ep5r.ep_kind = cm_object_get_child_by_name(state->f0.reg.ep5r, "EP_KIND");
	state->f0.fld.ep5r.ep_type = cm_object_get_child_by_name(state->f0.reg.ep5r, "EP_TYPE");
	state->f0.fld.ep5r.setup = cm_object_get_child_by_name(state->f0.reg.ep5r, "SETUP");
	state->f0.fld.ep5r.stat_rx = cm_object_get_child_by_name(state->f0.reg.ep5r, "STAT_RX");
	state->f0.fld.ep5r.dtog_rx = cm_object_get_child_by_name(state->f0.reg.ep5r, "DTOG_RX");
	state->f0.fld.ep5r.ctr_rx = cm_object_get_child_by_name(state->f0.reg.ep5r, "CTR_RX");

	// EP6R bitfields.
	state->f0.fld.ep6r.ea = cm_object_get_child_by_name(state->f0.reg.ep6r, "EA");
	state->f0.fld.ep6r.stat_tx = cm_object_get_child_by_name(state->f0.reg.ep6r, "STAT_TX");
	state->f0.fld.ep6r.dtog_tx = cm_object_get_child_by_name(state->f0.reg.ep6r, "DTOG_TX");
	state->f0.fld.ep6r.ctr_tx = cm_object_get_child_by_name(state->f0.reg.ep6r, "CTR_TX");
	state->f0.fld.ep6r.ep_kind = cm_object_get_child_by_name(state->f0.reg.ep6r, "EP_KIND");
	state->f0.fld.ep6r.ep_type = cm_object_get_child_by_name(state->f0.reg.ep6r, "EP_TYPE");
	state->f0.fld.ep6r.setup = cm_object_get_child_by_name(state->f0.reg.ep6r, "SETUP");
	state->f0.fld.ep6r.stat_rx = cm_object_get_child_by_name(state->f0.reg.ep6r, "STAT_RX");
	state->f0.fld.ep6r.dtog_rx = cm_object_get_child_by_name(state->f0.reg.ep6r, "DTOG_RX");
	state->f0.fld.ep6r.ctr_rx = cm_object_get_child_by_name(state->f0.reg.ep6r, "CTR_RX");

	// EP7R bitfields.
	state->f0.fld.ep7r.ea = cm_object_get_child_by_name(state->f0.reg.ep7r, "EA");
	state->f0.fld.ep7r.stat_tx = cm_object_get_child_by_name(state->f0.reg.ep7r, "STAT_TX");
	state->f0.fld.ep7r.dtog_tx = cm_object_get_child_by_name(state->f0.reg.ep7r, "DTOG_TX");
	state->f0.fld.ep7r.ctr_tx = cm_object_get_child_by_name(state->f0.reg.ep7r, "CTR_TX");
	state->f0.fld.ep7r.ep_kind = cm_object_get_child_by_name(state->f0.reg.ep7r, "EP_KIND");
	state->f0.fld.ep7r.ep_type = cm_object_get_child_by_name(state->f0.reg.ep7r, "EP_TYPE");
	state->f0.fld.ep7r.setup = cm_object_get_child_by_name(state->f0.reg.ep7r, "SETUP");
	state->f0.fld.ep7r.stat_rx = cm_object_get_child_by_name(state->f0.reg.ep7r, "STAT_RX");
	state->f0.fld.ep7r.dtog_rx = cm_object_get_child_by_name(state->f0.reg.ep7r, "DTOG_RX");
	state->f0.fld.ep7r.ctr_rx = cm_object_get_child_by_name(state->f0.reg.ep7r, "CTR_RX");

	// CNTR bitfields.
	state->f0.fld.cntr.fres = cm_object_get_child_by_name(state->f0.reg.cntr, "FRES");
	state->f0.fld.cntr.pdwn = cm_object_get_child_by_name(state->f0.reg.cntr, "PDWN");
	state->f0.fld.cntr.lpmode = cm_object_get_child_by_name(state->f0.reg.cntr, "LPMODE");
	state->f0.fld.cntr.fsusp = cm_object_get_child_by_name(state->f0.reg.cntr, "FSUSP");
	state->f0.fld.cntr.resume = cm_object_get_child_by_name(state->f0.reg.cntr, "RESUME");
	state->f0.fld.cntr.l1resume = cm_object_get_child_by_name(state->f0.reg.cntr, "L1RESUME");
	state->f0.fld.cntr.l1reqm = cm_object_get_child_by_name(state->f0.reg.cntr, "L1REQM");
	state->f0.fld.cntr.esofm = cm_object_get_child_by_name(state->f0.reg.cntr, "ESOFM");
	state->f0.fld.cntr.sofm = cm_object_get_child_by_name(state->f0.reg.cntr, "SOFM");
	state->f0.fld.cntr.resetm = cm_object_get_child_by_name(state->f0.reg.cntr, "RESETM");
	state->f0.fld.cntr.suspm = cm_object_get_child_by_name(state->f0.reg.cntr, "SUSPM");
	state->f0.fld.cntr.wkupm = cm_object_get_child_by_name(state->f0.reg.cntr, "WKUPM");
	state->f0.fld.cntr.errm = cm_object_get_child_by_name(state->f0.reg.cntr, "ERRM");
	state->f0.fld.cntr.pmaovrm = cm_object_get_child_by_name(state->f0.reg.cntr, "PMAOVRM");
	state->f0.fld.cntr.ctrm = cm_object_get_child_by_name(state->f0.reg.cntr, "CTRM");

	// ISTR bitfields.
	state->f0.fld.istr.ep_id = cm_object_get_child_by_name(state->f0.reg.istr, "EP_ID");
	state->f0.fld.istr.dir = cm_object_get_child_by_name(state->f0.reg.istr, "DIR");
	state->f0.fld.istr.l1req = cm_object_get_child_by_name(state->f0.reg.istr, "L1REQ");
	state->f0.fld.istr.esof = cm_object_get_child_by_name(state->f0.reg.istr, "ESOF");
	state->f0.fld.istr.sof = cm_object_get_child_by_name(state->f0.reg.istr, "SOF");
	state->f0.fld.istr.reset = cm_object_get_child_by_name(state->f0.reg.istr, "RESET");
	state->f0.fld.istr.susp = cm_object_get_child_by_name(state->f0.reg.istr, "SUSP");
	state->f0.fld.istr.wkup = cm_object_get_child_by_name(state->f0.reg.istr, "WKUP");
	state->f0.fld.istr.err = cm_object_get_child_by_name(state->f0.reg.istr, "ERR");
	state->f0.fld.istr.pmaovr = cm_object_get_child_by_name(state->f0.reg.istr, "PMAOVR");
	state->f0.fld.istr.ctr = cm_object_get_child_by_name(state->f0.reg.istr, "CTR");

	// FNR bitfields.
	state->f0.fld.fnr.fn = cm_object_get_child_by_name(state->f0.reg.fnr, "FN");
	state->f0.fld.fnr.lsof = cm_object_get_child_by_name(state->f0.reg.fnr, "LSOF");
	state->f0.fld.fnr.lck = cm_object_get_child_by_name(state->f0.reg.fnr, "LCK");
	state->f0.fld.fnr.rxdm = cm_object_get_child_by_name(state->f0.reg.fnr, "RXDM");
	state->f0.fld.fnr.rxdp = cm_object_get_child_by_name(state->f0.reg.fnr, "RXDP");

	// DADDR bitfields.
	state->f0.fld.daddr.add = cm_object_get_child_by_name(state->f0.reg.daddr, "ADD");
	state->f0.fld.daddr.ef = cm_object_get_child_by_name(state->f0.reg.daddr, "EF");

	// BTABLE bitfields.
	state->f0.fld.btable.btable = cm_object_get_child_by_name(state->f0.reg.btable, "BTABLE");

	// LPMCSR bitfields.
	state->f0.fld.lpmcsr.lpmen = cm_object_get_child_by_name(state->f0.reg.lpmcsr, "LPMEN");
	state->f0.fld.lpmcsr.lpmack = cm_object_get_child_by_name(state->f0.reg.lpmcsr, "LPMACK");
	state->f0.fld.lpmcsr.remwake = cm_object_get_child_by_name(state->f0.reg.lpmcsr, "REMWAKE");
	state->f0.fld.lpmcsr.besl = cm_object_get_child_by_name(state->f0.reg.lpmcsr, "BESL");

	// BCDR bitfields.
	state->f0.fld.bcdr.bcden = cm_object_get_child_by_name(state->f0.reg.bcdr, "BCDEN");
	state->f0.fld.bcdr.dcden = cm_object_get_child_by_name(state->f0.reg.bcdr, "DCDEN");
	state->f0.fld.bcdr.pden = cm_object_get_child_by_name(state->f0.reg.bcdr, "PDEN");
	state->f0.fld.bcdr.sden = cm_object_get_child_by_name(state->f0.reg.bcdr, "SDEN");
	state->f0.fld.bcdr.dcdet = cm_object_get_child_by_name(state->f0.reg.bcdr, "DCDET");
	state->f0.fld.bcdr.pdet = cm_object_get_child_by_name(state->f0.reg.bcdr, "PDET");
	state->f0.fld.bcdr.sdet = cm_object_get_child_by_name(state->f0.reg.bcdr, "SDET");
	state->f0.fld.bcdr.ps2det = cm_object_get_child_by_name(state->f0.reg.bcdr, "PS2DET");
	state->f0.fld.bcdr.dppu = cm_object_get_child_by_name(state->f0.reg.bcdr, "DPPU");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// CRS (Clock recovery system) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F0 CRS (Clock recovery system) registers.
		struct {
			Object *cr; // 0x0 Control register
			Object *cfgr; // 0x4 Configuration register
			Object *isr; // 0x8 Interrupt and status register
			Object *icr; // 0xC Interrupt flag clear register
		} reg;

		struct {

			// CR (Control register) bitfields.
			struct {
				Object *syncokie; // [0:0] SYNC event OK interrupt enable
				Object *syncwarnie; // [1:1] SYNC warning interrupt enable
				Object *errie; // [2:2] Synchronization or trimming error interrupt enable
				Object *esyncie; // [3:3] Expected SYNC interrupt enable
				Object *cen; // [5:5] Frequency error counter enable
				Object *autotrimen; // [6:6] Automatic trimming enable
				Object *swsync; // [7:7] Generate software SYNC event
				Object *trim; // [8:13] HSI48 oscillator smooth trimming
			} cr;

			// CFGR (Configuration register) bitfields.
			struct {
				Object *reload; // [0:15] Counter reload value
				Object *felim; // [16:23] Frequency error limit
				Object *syncdiv; // [24:26] SYNC divider
				Object *syncsrc; // [28:29] SYNC signal source selection
				Object *syncpol; // [31:31] SYNC polarity selection
			} cfgr;

			// ISR (Interrupt and status register) bitfields.
			struct {
				Object *syncokf; // [0:0] SYNC event OK flag
				Object *syncwarnf; // [1:1] SYNC warning flag
				Object *errf; // [2:2] Error flag
				Object *esyncf; // [3:3] Expected SYNC flag
				Object *syncerr; // [8:8] SYNC error
				Object *syncmiss; // [9:9] SYNC missed
				Object *trimovf; // [10:10] Trimming overflow or underflow
				Object *fedir; // [15:15] Frequency error direction
				Object *fecap; // [16:31] Frequency error capture
			} isr;

			// ICR (Interrupt flag clear register) bitfields.
			struct {
				Object *syncokc; // [0:0] SYNC event OK clear flag
				Object *syncwarnc; // [1:1] SYNC warning clear flag
				Object *errc; // [2:2] Error clear flag
				Object *esyncc; // [3:3] Expected SYNC clear flag
			} icr;
		} fld;
	} f0;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32CRSState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_crs_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32CRSState *state = STM32_CRS_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f0.reg.cr = cm_object_get_child_by_name(obj, "CR");
	state->f0.reg.cfgr = cm_object_get_child_by_name(obj, "CFGR");
	state->f0.reg.isr = cm_object_get_child_by_name(obj, "ISR");
	state->f0.reg.icr = cm_object_get_child_by_name(obj, "ICR");

	// CR bitfields.
	state->f0.fld.cr.syncokie = cm_object_get_child_by_name(state->f0.reg.cr, "SYNCOKIE");
	state->f0.fld.cr.syncwarnie = cm_object_get_child_by_name(state->f0.reg.cr, "SYNCWARNIE");
	state->f0.fld.cr.errie = cm_object_get_child_by_name(state->f0.reg.cr, "ERRIE");
	state->f0.fld.cr.esyncie = cm_object_get_child_by_name(state->f0.reg.cr, "ESYNCIE");
	state->f0.fld.cr.cen = cm_object_get_child_by_name(state->f0.reg.cr, "CEN");
	state->f0.fld.cr.autotrimen = cm_object_get_child_by_name(state->f0.reg.cr, "AUTOTRIMEN");
	state->f0.fld.cr.swsync = cm_object_get_child_by_name(state->f0.reg.cr, "SWSYNC");
	state->f0.fld.cr.trim = cm_object_get_child_by_name(state->f0.reg.cr, "TRIM");

	// CFGR bitfields.
	state->f0.fld.cfgr.reload = cm_object_get_child_by_name(state->f0.reg.cfgr, "RELOAD");
	state->f0.fld.cfgr.felim = cm_object_get_child_by_name(state->f0.reg.cfgr, "FELIM");
	state->f0.fld.cfgr.syncdiv = cm_object_get_child_by_name(state->f0.reg.cfgr, "SYNCDIV");
	state->f0.fld.cfgr.syncsrc = cm_object_get_child_by_name(state->f0.reg.cfgr, "SYNCSRC");
	state->f0.fld.cfgr.syncpol = cm_object_get_child_by_name(state->f0.reg.cfgr, "SYNCPOL");

	// ISR bitfields.
	state->f0.fld.isr.syncokf = cm_object_get_child_by_name(state->f0.reg.isr, "SYNCOKF");
	state->f0.fld.isr.syncwarnf = cm_object_get_child_by_name(state->f0.reg.isr, "SYNCWARNF");
	state->f0.fld.isr.errf = cm_object_get_child_by_name(state->f0.reg.isr, "ERRF");
	state->f0.fld.isr.esyncf = cm_object_get_child_by_name(state->f0.reg.isr, "ESYNCF");
	state->f0.fld.isr.syncerr = cm_object_get_child_by_name(state->f0.reg.isr, "SYNCERR");
	state->f0.fld.isr.syncmiss = cm_object_get_child_by_name(state->f0.reg.isr, "SYNCMISS");
	state->f0.fld.isr.trimovf = cm_object_get_child_by_name(state->f0.reg.isr, "TRIMOVF");
	state->f0.fld.isr.fedir = cm_object_get_child_by_name(state->f0.reg.isr, "FEDIR");
	state->f0.fld.isr.fecap = cm_object_get_child_by_name(state->f0.reg.isr, "FECAP");

	// ICR bitfields.
	state->f0.fld.icr.syncokc = cm_object_get_child_by_name(state->f0.reg.icr, "SYNCOKC");
	state->f0.fld.icr.syncwarnc = cm_object_get_child_by_name(state->f0.reg.icr, "SYNCWARNC");
	state->f0.fld.icr.errc = cm_object_get_child_by_name(state->f0.reg.icr, "ERRC");
	state->f0.fld.icr.esyncc = cm_object_get_child_by_name(state->f0.reg.icr, "ESYNCC");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// CAN (Controller area network) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F0 CAN (Controller area network) registers.
		struct {
			Object *can_mcr; // 0x0 CAN_MCR
			Object *can_msr; // 0x4 CAN_MSR
			Object *can_tsr; // 0x8 CAN_TSR
			Object *can_rf0r; // 0xC CAN_RF0R
			Object *can_rf1r; // 0x10 CAN_RF1R
			Object *can_ier; // 0x14 CAN_IER
			Object *can_esr; // 0x18 CAN_ESR
			Object *can_btr; // 0x1C CAN BTR
			Object *can_ti0r; // 0x180 CAN_TI0R
			Object *can_tdt0r; // 0x184 CAN_TDT0R
			Object *can_tdl0r; // 0x188 CAN_TDL0R
			Object *can_tdh0r; // 0x18C CAN_TDH0R
			Object *can_ti1r; // 0x190 CAN_TI1R
			Object *can_tdt1r; // 0x194 CAN_TDT1R
			Object *can_tdl1r; // 0x198 CAN_TDL1R
			Object *can_tdh1r; // 0x19C CAN_TDH1R
			Object *can_ti2r; // 0x1A0 CAN_TI2R
			Object *can_tdt2r; // 0x1A4 CAN_TDT2R
			Object *can_tdl2r; // 0x1A8 CAN_TDL2R
			Object *can_tdh2r; // 0x1AC CAN_TDH2R
			Object *can_ri0r; // 0x1B0 CAN_RI0R
			Object *can_rdt0r; // 0x1B4 CAN_RDT0R
			Object *can_rdl0r; // 0x1B8 CAN_RDL0R
			Object *can_rdh0r; // 0x1BC CAN_RDH0R
			Object *can_ri1r; // 0x1C0 CAN_RI1R
			Object *can_rdt1r; // 0x1C4 CAN_RDT1R
			Object *can_rdl1r; // 0x1C8 CAN_RDL1R
			Object *can_rdh1r; // 0x1CC CAN_RDH1R
			Object *can_fmr; // 0x200 CAN_FMR
			Object *can_fm1r; // 0x204 CAN_FM1R
			Object *can_fs1r; // 0x20C CAN_FS1R
			Object *can_ffa1r; // 0x214 CAN_FFA1R
			Object *can_fa1r; // 0x21C CAN_FA1R
			Object *f0r1; // 0x240 Filter bank 0 register 1
			Object *f0r2; // 0x244 Filter bank 0 register 2
			Object *f1r1; // 0x248 Filter bank 1 register 1
			Object *f1r2; // 0x24C Filter bank 1 register 2
			Object *f2r1; // 0x250 Filter bank 2 register 1
			Object *f2r2; // 0x254 Filter bank 2 register 2
			Object *f3r1; // 0x258 Filter bank 3 register 1
			Object *f3r2; // 0x25C Filter bank 3 register 2
			Object *f4r1; // 0x260 Filter bank 4 register 1
			Object *f4r2; // 0x264 Filter bank 4 register 2
			Object *f5r1; // 0x268 Filter bank 5 register 1
			Object *f5r2; // 0x26C Filter bank 5 register 2
			Object *f6r1; // 0x270 Filter bank 6 register 1
			Object *f6r2; // 0x274 Filter bank 6 register 2
			Object *f7r1; // 0x278 Filter bank 7 register 1
			Object *f7r2; // 0x27C Filter bank 7 register 2
			Object *f8r1; // 0x280 Filter bank 8 register 1
			Object *f8r2; // 0x284 Filter bank 8 register 2
			Object *f9r1; // 0x288 Filter bank 9 register 1
			Object *f9r2; // 0x28C Filter bank 9 register 2
			Object *f10r1; // 0x290 Filter bank 10 register 1
			Object *f10r2; // 0x294 Filter bank 10 register 2
			Object *f11r1; // 0x298 Filter bank 11 register 1
			Object *f11r2; // 0x29C Filter bank 11 register 2
			Object *f12r1; // 0x2A0 Filter bank 4 register 1
			Object *f12r2; // 0x2A4 Filter bank 12 register 2
			Object *f13r1; // 0x2A8 Filter bank 13 register 1
			Object *f13r2; // 0x2AC Filter bank 13 register 2
			Object *f14r1; // 0x2B0 Filter bank 14 register 1
			Object *f14r2; // 0x2B4 Filter bank 14 register 2
			Object *f15r1; // 0x2B8 Filter bank 15 register 1
			Object *f15r2; // 0x2BC Filter bank 15 register 2
			Object *f16r1; // 0x2C0 Filter bank 16 register 1
			Object *f16r2; // 0x2C4 Filter bank 16 register 2
			Object *f17r1; // 0x2C8 Filter bank 17 register 1
			Object *f17r2; // 0x2CC Filter bank 17 register 2
			Object *f18r1; // 0x2D0 Filter bank 18 register 1
			Object *f18r2; // 0x2D4 Filter bank 18 register 2
			Object *f19r1; // 0x2D8 Filter bank 19 register 1
			Object *f19r2; // 0x2DC Filter bank 19 register 2
			Object *f20r1; // 0x2E0 Filter bank 20 register 1
			Object *f20r2; // 0x2E4 Filter bank 20 register 2
			Object *f21r1; // 0x2E8 Filter bank 21 register 1
			Object *f21r2; // 0x2EC Filter bank 21 register 2
			Object *f22r1; // 0x2F0 Filter bank 22 register 1
			Object *f22r2; // 0x2F4 Filter bank 22 register 2
			Object *f23r1; // 0x2F8 Filter bank 23 register 1
			Object *f23r2; // 0x2FC Filter bank 23 register 2
			Object *f24r1; // 0x300 Filter bank 24 register 1
			Object *f24r2; // 0x304 Filter bank 24 register 2
			Object *f25r1; // 0x308 Filter bank 25 register 1
			Object *f25r2; // 0x30C Filter bank 25 register 2
			Object *f26r1; // 0x310 Filter bank 26 register 1
			Object *f26r2; // 0x314 Filter bank 26 register 2
			Object *f27r1; // 0x318 Filter bank 27 register 1
			Object *f27r2; // 0x31C Filter bank 27 register 2
		} reg;

		struct {

			// CAN_MCR (CAN_MCR) bitfields.
			struct {
				Object *inrq; // [0:0] INRQ
				Object *sleep; // [1:1] SLEEP
				Object *txfp; // [2:2] TXFP
				Object *rflm; // [3:3] RFLM
				Object *nart; // [4:4] NART
				Object *awum; // [5:5] AWUM
				Object *abom; // [6:6] ABOM
				Object *ttcm; // [7:7] TTCM
				Object *reset; // [15:15] RESET
				Object *dbf; // [16:16] DBF
			} can_mcr;

			// CAN_MSR (CAN_MSR) bitfields.
			struct {
				Object *inak; // [0:0] INAK
				Object *slak; // [1:1] SLAK
				Object *erri; // [2:2] ERRI
				Object *wkui; // [3:3] WKUI
				Object *slaki; // [4:4] SLAKI
				Object *txm; // [8:8] TXM
				Object *rxm; // [9:9] RXM
				Object *samp; // [10:10] SAMP
				Object *rx; // [11:11] RX
			} can_msr;

			// CAN_TSR (CAN_TSR) bitfields.
			struct {
				Object *rqcp0; // [0:0] RQCP0
				Object *txok0; // [1:1] TXOK0
				Object *alst0; // [2:2] ALST0
				Object *terr0; // [3:3] TERR0
				Object *abrq0; // [7:7] ABRQ0
				Object *rqcp1; // [8:8] RQCP1
				Object *txok1; // [9:9] TXOK1
				Object *alst1; // [10:10] ALST1
				Object *terr1; // [11:11] TERR1
				Object *abrq1; // [15:15] ABRQ1
				Object *rqcp2; // [16:16] RQCP2
				Object *txok2; // [17:17] TXOK2
				Object *alst2; // [18:18] ALST2
				Object *terr2; // [19:19] TERR2
				Object *abrq2; // [23:23] ABRQ2
				Object *code; // [24:25] CODE
				Object *tme0; // [26:26] Lowest priority flag for mailbox 0
				Object *tme1; // [27:27] Lowest priority flag for mailbox 1
				Object *tme2; // [28:28] Lowest priority flag for mailbox 2
				Object *low0; // [29:29] Lowest priority flag for mailbox 0
				Object *low1; // [30:30] Lowest priority flag for mailbox 1
				Object *low2; // [31:31] Lowest priority flag for mailbox 2
			} can_tsr;

			// CAN_RF0R (CAN_RF0R) bitfields.
			struct {
				Object *fmp0; // [0:1] FMP0
				Object *full0; // [3:3] FULL0
				Object *fovr0; // [4:4] FOVR0
				Object *rfom0; // [5:5] RFOM0
			} can_rf0r;

			// CAN_RF1R (CAN_RF1R) bitfields.
			struct {
				Object *fmp1; // [0:1] FMP1
				Object *full1; // [3:3] FULL1
				Object *fovr1; // [4:4] FOVR1
				Object *rfom1; // [5:5] RFOM1
			} can_rf1r;

			// CAN_IER (CAN_IER) bitfields.
			struct {
				Object *tmeie; // [0:0] TMEIE
				Object *fmpie0; // [1:1] FMPIE0
				Object *ffie0; // [2:2] FFIE0
				Object *fovie0; // [3:3] FOVIE0
				Object *fmpie1; // [4:4] FMPIE1
				Object *ffie1; // [5:5] FFIE1
				Object *fovie1; // [6:6] FOVIE1
				Object *ewgie; // [8:8] EWGIE
				Object *epvie; // [9:9] EPVIE
				Object *bofie; // [10:10] BOFIE
				Object *lecie; // [11:11] LECIE
				Object *errie; // [15:15] ERRIE
				Object *wkuie; // [16:16] WKUIE
				Object *slkie; // [17:17] SLKIE
			} can_ier;

			// CAN_ESR (CAN_ESR) bitfields.
			struct {
				Object *ewgf; // [0:0] EWGF
				Object *epvf; // [1:1] EPVF
				Object *boff; // [2:2] BOFF
				Object *lec; // [4:6] LEC
				Object *tec; // [16:23] TEC
				Object *rec; // [24:31] REC
			} can_esr;

			// CAN_BTR (CAN BTR) bitfields.
			struct {
				Object *brp; // [0:9] BRP
				Object *ts1; // [16:19] TS1
				Object *ts2; // [20:22] TS2
				Object *sjw; // [24:25] SJW
				Object *lbkm; // [30:30] LBKM
				Object *silm; // [31:31] SILM
			} can_btr;

			// CAN_TI0R (CAN_TI0R) bitfields.
			struct {
				Object *txrq; // [0:0] TXRQ
				Object *rtr; // [1:1] RTR
				Object *ide; // [2:2] IDE
				Object *exid; // [3:20] EXID
				Object *stid; // [21:31] STID
			} can_ti0r;

			// CAN_TDT0R (CAN_TDT0R) bitfields.
			struct {
				Object *dlc; // [0:3] DLC
				Object *tgt; // [8:8] TGT
				Object *time; // [16:31] TIME
			} can_tdt0r;

			// CAN_TDL0R (CAN_TDL0R) bitfields.
			struct {
				Object *data0; // [0:7] DATA0
				Object *data1; // [8:15] DATA1
				Object *data2; // [16:23] DATA2
				Object *data3; // [24:31] DATA3
			} can_tdl0r;

			// CAN_TDH0R (CAN_TDH0R) bitfields.
			struct {
				Object *data4; // [0:7] DATA4
				Object *data5; // [8:15] DATA5
				Object *data6; // [16:23] DATA6
				Object *data7; // [24:31] DATA7
			} can_tdh0r;

			// CAN_TI1R (CAN_TI1R) bitfields.
			struct {
				Object *txrq; // [0:0] TXRQ
				Object *rtr; // [1:1] RTR
				Object *ide; // [2:2] IDE
				Object *exid; // [3:20] EXID
				Object *stid; // [21:31] STID
			} can_ti1r;

			// CAN_TDT1R (CAN_TDT1R) bitfields.
			struct {
				Object *dlc; // [0:3] DLC
				Object *tgt; // [8:8] TGT
				Object *time; // [16:31] TIME
			} can_tdt1r;

			// CAN_TDL1R (CAN_TDL1R) bitfields.
			struct {
				Object *data0; // [0:7] DATA0
				Object *data1; // [8:15] DATA1
				Object *data2; // [16:23] DATA2
				Object *data3; // [24:31] DATA3
			} can_tdl1r;

			// CAN_TDH1R (CAN_TDH1R) bitfields.
			struct {
				Object *data4; // [0:7] DATA4
				Object *data5; // [8:15] DATA5
				Object *data6; // [16:23] DATA6
				Object *data7; // [24:31] DATA7
			} can_tdh1r;

			// CAN_TI2R (CAN_TI2R) bitfields.
			struct {
				Object *txrq; // [0:0] TXRQ
				Object *rtr; // [1:1] RTR
				Object *ide; // [2:2] IDE
				Object *exid; // [3:20] EXID
				Object *stid; // [21:31] STID
			} can_ti2r;

			// CAN_TDT2R (CAN_TDT2R) bitfields.
			struct {
				Object *dlc; // [0:3] DLC
				Object *tgt; // [8:8] TGT
				Object *time; // [16:31] TIME
			} can_tdt2r;

			// CAN_TDL2R (CAN_TDL2R) bitfields.
			struct {
				Object *data0; // [0:7] DATA0
				Object *data1; // [8:15] DATA1
				Object *data2; // [16:23] DATA2
				Object *data3; // [24:31] DATA3
			} can_tdl2r;

			// CAN_TDH2R (CAN_TDH2R) bitfields.
			struct {
				Object *data4; // [0:7] DATA4
				Object *data5; // [8:15] DATA5
				Object *data6; // [16:23] DATA6
				Object *data7; // [24:31] DATA7
			} can_tdh2r;

			// CAN_RI0R (CAN_RI0R) bitfields.
			struct {
				Object *rtr; // [1:1] RTR
				Object *ide; // [2:2] IDE
				Object *exid; // [3:20] EXID
				Object *stid; // [21:31] STID
			} can_ri0r;

			// CAN_RDT0R (CAN_RDT0R) bitfields.
			struct {
				Object *dlc; // [0:3] DLC
				Object *fmi; // [8:15] FMI
				Object *time; // [16:31] TIME
			} can_rdt0r;

			// CAN_RDL0R (CAN_RDL0R) bitfields.
			struct {
				Object *data0; // [0:7] DATA0
				Object *data1; // [8:15] DATA1
				Object *data2; // [16:23] DATA2
				Object *data3; // [24:31] DATA3
			} can_rdl0r;

			// CAN_RDH0R (CAN_RDH0R) bitfields.
			struct {
				Object *data4; // [0:7] DATA4
				Object *data5; // [8:15] DATA5
				Object *data6; // [16:23] DATA6
				Object *data7; // [24:31] DATA7
			} can_rdh0r;

			// CAN_RI1R (CAN_RI1R) bitfields.
			struct {
				Object *rtr; // [1:1] RTR
				Object *ide; // [2:2] IDE
				Object *exid; // [3:20] EXID
				Object *stid; // [21:31] STID
			} can_ri1r;

			// CAN_RDT1R (CAN_RDT1R) bitfields.
			struct {
				Object *dlc; // [0:3] DLC
				Object *fmi; // [8:15] FMI
				Object *time; // [16:31] TIME
			} can_rdt1r;

			// CAN_RDL1R (CAN_RDL1R) bitfields.
			struct {
				Object *data0; // [0:7] DATA0
				Object *data1; // [8:15] DATA1
				Object *data2; // [16:23] DATA2
				Object *data3; // [24:31] DATA3
			} can_rdl1r;

			// CAN_RDH1R (CAN_RDH1R) bitfields.
			struct {
				Object *data4; // [0:7] DATA4
				Object *data5; // [8:15] DATA5
				Object *data6; // [16:23] DATA6
				Object *data7; // [24:31] DATA7
			} can_rdh1r;

			// CAN_FMR (CAN_FMR) bitfields.
			struct {
				Object *finit; // [0:0] FINIT
				Object *can2sb; // [8:13] CAN2SB
			} can_fmr;

			// CAN_FM1R (CAN_FM1R) bitfields.
			struct {
				Object *fbm0; // [0:0] Filter mode
				Object *fbm1; // [1:1] Filter mode
				Object *fbm2; // [2:2] Filter mode
				Object *fbm3; // [3:3] Filter mode
				Object *fbm4; // [4:4] Filter mode
				Object *fbm5; // [5:5] Filter mode
				Object *fbm6; // [6:6] Filter mode
				Object *fbm7; // [7:7] Filter mode
				Object *fbm8; // [8:8] Filter mode
				Object *fbm9; // [9:9] Filter mode
				Object *fbm10; // [10:10] Filter mode
				Object *fbm11; // [11:11] Filter mode
				Object *fbm12; // [12:12] Filter mode
				Object *fbm13; // [13:13] Filter mode
				Object *fbm14; // [14:14] Filter mode
				Object *fbm15; // [15:15] Filter mode
				Object *fbm16; // [16:16] Filter mode
				Object *fbm17; // [17:17] Filter mode
				Object *fbm18; // [18:18] Filter mode
				Object *fbm19; // [19:19] Filter mode
				Object *fbm20; // [20:20] Filter mode
				Object *fbm21; // [21:21] Filter mode
				Object *fbm22; // [22:22] Filter mode
				Object *fbm23; // [23:23] Filter mode
				Object *fbm24; // [24:24] Filter mode
				Object *fbm25; // [25:25] Filter mode
				Object *fbm26; // [26:26] Filter mode
				Object *fbm27; // [27:27] Filter mode
			} can_fm1r;

			// CAN_FS1R (CAN_FS1R) bitfields.
			struct {
				Object *fsc0; // [0:0] Filter scale configuration
				Object *fsc1; // [1:1] Filter scale configuration
				Object *fsc2; // [2:2] Filter scale configuration
				Object *fsc3; // [3:3] Filter scale configuration
				Object *fsc4; // [4:4] Filter scale configuration
				Object *fsc5; // [5:5] Filter scale configuration
				Object *fsc6; // [6:6] Filter scale configuration
				Object *fsc7; // [7:7] Filter scale configuration
				Object *fsc8; // [8:8] Filter scale configuration
				Object *fsc9; // [9:9] Filter scale configuration
				Object *fsc10; // [10:10] Filter scale configuration
				Object *fsc11; // [11:11] Filter scale configuration
				Object *fsc12; // [12:12] Filter scale configuration
				Object *fsc13; // [13:13] Filter scale configuration
				Object *fsc14; // [14:14] Filter scale configuration
				Object *fsc15; // [15:15] Filter scale configuration
				Object *fsc16; // [16:16] Filter scale configuration
				Object *fsc17; // [17:17] Filter scale configuration
				Object *fsc18; // [18:18] Filter scale configuration
				Object *fsc19; // [19:19] Filter scale configuration
				Object *fsc20; // [20:20] Filter scale configuration
				Object *fsc21; // [21:21] Filter scale configuration
				Object *fsc22; // [22:22] Filter scale configuration
				Object *fsc23; // [23:23] Filter scale configuration
				Object *fsc24; // [24:24] Filter scale configuration
				Object *fsc25; // [25:25] Filter scale configuration
				Object *fsc26; // [26:26] Filter scale configuration
				Object *fsc27; // [27:27] Filter scale configuration
			} can_fs1r;

			// CAN_FFA1R (CAN_FFA1R) bitfields.
			struct {
				Object *ffa0; // [0:0] Filter FIFO assignment for filter 0
				Object *ffa1; // [1:1] Filter FIFO assignment for filter 1
				Object *ffa2; // [2:2] Filter FIFO assignment for filter 2
				Object *ffa3; // [3:3] Filter FIFO assignment for filter 3
				Object *ffa4; // [4:4] Filter FIFO assignment for filter 4
				Object *ffa5; // [5:5] Filter FIFO assignment for filter 5
				Object *ffa6; // [6:6] Filter FIFO assignment for filter 6
				Object *ffa7; // [7:7] Filter FIFO assignment for filter 7
				Object *ffa8; // [8:8] Filter FIFO assignment for filter 8
				Object *ffa9; // [9:9] Filter FIFO assignment for filter 9
				Object *ffa10; // [10:10] Filter FIFO assignment for filter 10
				Object *ffa11; // [11:11] Filter FIFO assignment for filter 11
				Object *ffa12; // [12:12] Filter FIFO assignment for filter 12
				Object *ffa13; // [13:13] Filter FIFO assignment for filter 13
				Object *ffa14; // [14:14] Filter FIFO assignment for filter 14
				Object *ffa15; // [15:15] Filter FIFO assignment for filter 15
				Object *ffa16; // [16:16] Filter FIFO assignment for filter 16
				Object *ffa17; // [17:17] Filter FIFO assignment for filter 17
				Object *ffa18; // [18:18] Filter FIFO assignment for filter 18
				Object *ffa19; // [19:19] Filter FIFO assignment for filter 19
				Object *ffa20; // [20:20] Filter FIFO assignment for filter 20
				Object *ffa21; // [21:21] Filter FIFO assignment for filter 21
				Object *ffa22; // [22:22] Filter FIFO assignment for filter 22
				Object *ffa23; // [23:23] Filter FIFO assignment for filter 23
				Object *ffa24; // [24:24] Filter FIFO assignment for filter 24
				Object *ffa25; // [25:25] Filter FIFO assignment for filter 25
				Object *ffa26; // [26:26] Filter FIFO assignment for filter 26
				Object *ffa27; // [27:27] Filter FIFO assignment for filter 27
			} can_ffa1r;

			// CAN_FA1R (CAN_FA1R) bitfields.
			struct {
				Object *fact0; // [0:0] Filter active
				Object *fact1; // [1:1] Filter active
				Object *fact2; // [2:2] Filter active
				Object *fact3; // [3:3] Filter active
				Object *fact4; // [4:4] Filter active
				Object *fact5; // [5:5] Filter active
				Object *fact6; // [6:6] Filter active
				Object *fact7; // [7:7] Filter active
				Object *fact8; // [8:8] Filter active
				Object *fact9; // [9:9] Filter active
				Object *fact10; // [10:10] Filter active
				Object *fact11; // [11:11] Filter active
				Object *fact12; // [12:12] Filter active
				Object *fact13; // [13:13] Filter active
				Object *fact14; // [14:14] Filter active
				Object *fact15; // [15:15] Filter active
				Object *fact16; // [16:16] Filter active
				Object *fact17; // [17:17] Filter active
				Object *fact18; // [18:18] Filter active
				Object *fact19; // [19:19] Filter active
				Object *fact20; // [20:20] Filter active
				Object *fact21; // [21:21] Filter active
				Object *fact22; // [22:22] Filter active
				Object *fact23; // [23:23] Filter active
				Object *fact24; // [24:24] Filter active
				Object *fact25; // [25:25] Filter active
				Object *fact26; // [26:26] Filter active
				Object *fact27; // [27:27] Filter active
			} can_fa1r;

			// F0R1 (Filter bank 0 register 1) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f0r1;

			// F0R2 (Filter bank 0 register 2) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f0r2;

			// F1R1 (Filter bank 1 register 1) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f1r1;

			// F1R2 (Filter bank 1 register 2) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f1r2;

			// F2R1 (Filter bank 2 register 1) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f2r1;

			// F2R2 (Filter bank 2 register 2) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f2r2;

			// F3R1 (Filter bank 3 register 1) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f3r1;

			// F3R2 (Filter bank 3 register 2) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f3r2;

			// F4R1 (Filter bank 4 register 1) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f4r1;

			// F4R2 (Filter bank 4 register 2) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f4r2;

			// F5R1 (Filter bank 5 register 1) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f5r1;

			// F5R2 (Filter bank 5 register 2) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f5r2;

			// F6R1 (Filter bank 6 register 1) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f6r1;

			// F6R2 (Filter bank 6 register 2) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f6r2;

			// F7R1 (Filter bank 7 register 1) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f7r1;

			// F7R2 (Filter bank 7 register 2) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f7r2;

			// F8R1 (Filter bank 8 register 1) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f8r1;

			// F8R2 (Filter bank 8 register 2) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f8r2;

			// F9R1 (Filter bank 9 register 1) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f9r1;

			// F9R2 (Filter bank 9 register 2) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f9r2;

			// F10R1 (Filter bank 10 register 1) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f10r1;

			// F10R2 (Filter bank 10 register 2) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f10r2;

			// F11R1 (Filter bank 11 register 1) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f11r1;

			// F11R2 (Filter bank 11 register 2) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f11r2;

			// F12R1 (Filter bank 4 register 1) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f12r1;

			// F12R2 (Filter bank 12 register 2) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f12r2;

			// F13R1 (Filter bank 13 register 1) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f13r1;

			// F13R2 (Filter bank 13 register 2) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f13r2;

			// F14R1 (Filter bank 14 register 1) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f14r1;

			// F14R2 (Filter bank 14 register 2) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f14r2;

			// F15R1 (Filter bank 15 register 1) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f15r1;

			// F15R2 (Filter bank 15 register 2) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f15r2;

			// F16R1 (Filter bank 16 register 1) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f16r1;

			// F16R2 (Filter bank 16 register 2) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f16r2;

			// F17R1 (Filter bank 17 register 1) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f17r1;

			// F17R2 (Filter bank 17 register 2) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f17r2;

			// F18R1 (Filter bank 18 register 1) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f18r1;

			// F18R2 (Filter bank 18 register 2) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f18r2;

			// F19R1 (Filter bank 19 register 1) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f19r1;

			// F19R2 (Filter bank 19 register 2) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f19r2;

			// F20R1 (Filter bank 20 register 1) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f20r1;

			// F20R2 (Filter bank 20 register 2) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f20r2;

			// F21R1 (Filter bank 21 register 1) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f21r1;

			// F21R2 (Filter bank 21 register 2) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f21r2;

			// F22R1 (Filter bank 22 register 1) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f22r1;

			// F22R2 (Filter bank 22 register 2) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f22r2;

			// F23R1 (Filter bank 23 register 1) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f23r1;

			// F23R2 (Filter bank 23 register 2) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f23r2;

			// F24R1 (Filter bank 24 register 1) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f24r1;

			// F24R2 (Filter bank 24 register 2) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f24r2;

			// F25R1 (Filter bank 25 register 1) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f25r1;

			// F25R2 (Filter bank 25 register 2) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f25r2;

			// F26R1 (Filter bank 26 register 1) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f26r1;

			// F26R2 (Filter bank 26 register 2) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f26r2;

			// F27R1 (Filter bank 27 register 1) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f27r1;

			// F27R2 (Filter bank 27 register 2) bitfields.
			struct {
				Object *fb0; // [0:0] Filter bits
				Object *fb1; // [1:1] Filter bits
				Object *fb2; // [2:2] Filter bits
				Object *fb3; // [3:3] Filter bits
				Object *fb4; // [4:4] Filter bits
				Object *fb5; // [5:5] Filter bits
				Object *fb6; // [6:6] Filter bits
				Object *fb7; // [7:7] Filter bits
				Object *fb8; // [8:8] Filter bits
				Object *fb9; // [9:9] Filter bits
				Object *fb10; // [10:10] Filter bits
				Object *fb11; // [11:11] Filter bits
				Object *fb12; // [12:12] Filter bits
				Object *fb13; // [13:13] Filter bits
				Object *fb14; // [14:14] Filter bits
				Object *fb15; // [15:15] Filter bits
				Object *fb16; // [16:16] Filter bits
				Object *fb17; // [17:17] Filter bits
				Object *fb18; // [18:18] Filter bits
				Object *fb19; // [19:19] Filter bits
				Object *fb20; // [20:20] Filter bits
				Object *fb21; // [21:21] Filter bits
				Object *fb22; // [22:22] Filter bits
				Object *fb23; // [23:23] Filter bits
				Object *fb24; // [24:24] Filter bits
				Object *fb25; // [25:25] Filter bits
				Object *fb26; // [26:26] Filter bits
				Object *fb27; // [27:27] Filter bits
				Object *fb28; // [28:28] Filter bits
				Object *fb29; // [29:29] Filter bits
				Object *fb30; // [30:30] Filter bits
				Object *fb31; // [31:31] Filter bits
			} f27r2;
		} fld;
	} f0;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32CANState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_can_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32CANState *state = STM32_CAN_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f0.reg.can_mcr = cm_object_get_child_by_name(obj, "CAN_MCR");
	state->f0.reg.can_msr = cm_object_get_child_by_name(obj, "CAN_MSR");
	state->f0.reg.can_tsr = cm_object_get_child_by_name(obj, "CAN_TSR");
	state->f0.reg.can_rf0r = cm_object_get_child_by_name(obj, "CAN_RF0R");
	state->f0.reg.can_rf1r = cm_object_get_child_by_name(obj, "CAN_RF1R");
	state->f0.reg.can_ier = cm_object_get_child_by_name(obj, "CAN_IER");
	state->f0.reg.can_esr = cm_object_get_child_by_name(obj, "CAN_ESR");
	state->f0.reg.can_btr = cm_object_get_child_by_name(obj, "CAN_BTR");
	state->f0.reg.can_ti0r = cm_object_get_child_by_name(obj, "CAN_TI0R");
	state->f0.reg.can_tdt0r = cm_object_get_child_by_name(obj, "CAN_TDT0R");
	state->f0.reg.can_tdl0r = cm_object_get_child_by_name(obj, "CAN_TDL0R");
	state->f0.reg.can_tdh0r = cm_object_get_child_by_name(obj, "CAN_TDH0R");
	state->f0.reg.can_ti1r = cm_object_get_child_by_name(obj, "CAN_TI1R");
	state->f0.reg.can_tdt1r = cm_object_get_child_by_name(obj, "CAN_TDT1R");
	state->f0.reg.can_tdl1r = cm_object_get_child_by_name(obj, "CAN_TDL1R");
	state->f0.reg.can_tdh1r = cm_object_get_child_by_name(obj, "CAN_TDH1R");
	state->f0.reg.can_ti2r = cm_object_get_child_by_name(obj, "CAN_TI2R");
	state->f0.reg.can_tdt2r = cm_object_get_child_by_name(obj, "CAN_TDT2R");
	state->f0.reg.can_tdl2r = cm_object_get_child_by_name(obj, "CAN_TDL2R");
	state->f0.reg.can_tdh2r = cm_object_get_child_by_name(obj, "CAN_TDH2R");
	state->f0.reg.can_ri0r = cm_object_get_child_by_name(obj, "CAN_RI0R");
	state->f0.reg.can_rdt0r = cm_object_get_child_by_name(obj, "CAN_RDT0R");
	state->f0.reg.can_rdl0r = cm_object_get_child_by_name(obj, "CAN_RDL0R");
	state->f0.reg.can_rdh0r = cm_object_get_child_by_name(obj, "CAN_RDH0R");
	state->f0.reg.can_ri1r = cm_object_get_child_by_name(obj, "CAN_RI1R");
	state->f0.reg.can_rdt1r = cm_object_get_child_by_name(obj, "CAN_RDT1R");
	state->f0.reg.can_rdl1r = cm_object_get_child_by_name(obj, "CAN_RDL1R");
	state->f0.reg.can_rdh1r = cm_object_get_child_by_name(obj, "CAN_RDH1R");
	state->f0.reg.can_fmr = cm_object_get_child_by_name(obj, "CAN_FMR");
	state->f0.reg.can_fm1r = cm_object_get_child_by_name(obj, "CAN_FM1R");
	state->f0.reg.can_fs1r = cm_object_get_child_by_name(obj, "CAN_FS1R");
	state->f0.reg.can_ffa1r = cm_object_get_child_by_name(obj, "CAN_FFA1R");
	state->f0.reg.can_fa1r = cm_object_get_child_by_name(obj, "CAN_FA1R");
	state->f0.reg.f0r1 = cm_object_get_child_by_name(obj, "F0R1");
	state->f0.reg.f0r2 = cm_object_get_child_by_name(obj, "F0R2");
	state->f0.reg.f1r1 = cm_object_get_child_by_name(obj, "F1R1");
	state->f0.reg.f1r2 = cm_object_get_child_by_name(obj, "F1R2");
	state->f0.reg.f2r1 = cm_object_get_child_by_name(obj, "F2R1");
	state->f0.reg.f2r2 = cm_object_get_child_by_name(obj, "F2R2");
	state->f0.reg.f3r1 = cm_object_get_child_by_name(obj, "F3R1");
	state->f0.reg.f3r2 = cm_object_get_child_by_name(obj, "F3R2");
	state->f0.reg.f4r1 = cm_object_get_child_by_name(obj, "F4R1");
	state->f0.reg.f4r2 = cm_object_get_child_by_name(obj, "F4R2");
	state->f0.reg.f5r1 = cm_object_get_child_by_name(obj, "F5R1");
	state->f0.reg.f5r2 = cm_object_get_child_by_name(obj, "F5R2");
	state->f0.reg.f6r1 = cm_object_get_child_by_name(obj, "F6R1");
	state->f0.reg.f6r2 = cm_object_get_child_by_name(obj, "F6R2");
	state->f0.reg.f7r1 = cm_object_get_child_by_name(obj, "F7R1");
	state->f0.reg.f7r2 = cm_object_get_child_by_name(obj, "F7R2");
	state->f0.reg.f8r1 = cm_object_get_child_by_name(obj, "F8R1");
	state->f0.reg.f8r2 = cm_object_get_child_by_name(obj, "F8R2");
	state->f0.reg.f9r1 = cm_object_get_child_by_name(obj, "F9R1");
	state->f0.reg.f9r2 = cm_object_get_child_by_name(obj, "F9R2");
	state->f0.reg.f10r1 = cm_object_get_child_by_name(obj, "F10R1");
	state->f0.reg.f10r2 = cm_object_get_child_by_name(obj, "F10R2");
	state->f0.reg.f11r1 = cm_object_get_child_by_name(obj, "F11R1");
	state->f0.reg.f11r2 = cm_object_get_child_by_name(obj, "F11R2");
	state->f0.reg.f12r1 = cm_object_get_child_by_name(obj, "F12R1");
	state->f0.reg.f12r2 = cm_object_get_child_by_name(obj, "F12R2");
	state->f0.reg.f13r1 = cm_object_get_child_by_name(obj, "F13R1");
	state->f0.reg.f13r2 = cm_object_get_child_by_name(obj, "F13R2");
	state->f0.reg.f14r1 = cm_object_get_child_by_name(obj, "F14R1");
	state->f0.reg.f14r2 = cm_object_get_child_by_name(obj, "F14R2");
	state->f0.reg.f15r1 = cm_object_get_child_by_name(obj, "F15R1");
	state->f0.reg.f15r2 = cm_object_get_child_by_name(obj, "F15R2");
	state->f0.reg.f16r1 = cm_object_get_child_by_name(obj, "F16R1");
	state->f0.reg.f16r2 = cm_object_get_child_by_name(obj, "F16R2");
	state->f0.reg.f17r1 = cm_object_get_child_by_name(obj, "F17R1");
	state->f0.reg.f17r2 = cm_object_get_child_by_name(obj, "F17R2");
	state->f0.reg.f18r1 = cm_object_get_child_by_name(obj, "F18R1");
	state->f0.reg.f18r2 = cm_object_get_child_by_name(obj, "F18R2");
	state->f0.reg.f19r1 = cm_object_get_child_by_name(obj, "F19R1");
	state->f0.reg.f19r2 = cm_object_get_child_by_name(obj, "F19R2");
	state->f0.reg.f20r1 = cm_object_get_child_by_name(obj, "F20R1");
	state->f0.reg.f20r2 = cm_object_get_child_by_name(obj, "F20R2");
	state->f0.reg.f21r1 = cm_object_get_child_by_name(obj, "F21R1");
	state->f0.reg.f21r2 = cm_object_get_child_by_name(obj, "F21R2");
	state->f0.reg.f22r1 = cm_object_get_child_by_name(obj, "F22R1");
	state->f0.reg.f22r2 = cm_object_get_child_by_name(obj, "F22R2");
	state->f0.reg.f23r1 = cm_object_get_child_by_name(obj, "F23R1");
	state->f0.reg.f23r2 = cm_object_get_child_by_name(obj, "F23R2");
	state->f0.reg.f24r1 = cm_object_get_child_by_name(obj, "F24R1");
	state->f0.reg.f24r2 = cm_object_get_child_by_name(obj, "F24R2");
	state->f0.reg.f25r1 = cm_object_get_child_by_name(obj, "F25R1");
	state->f0.reg.f25r2 = cm_object_get_child_by_name(obj, "F25R2");
	state->f0.reg.f26r1 = cm_object_get_child_by_name(obj, "F26R1");
	state->f0.reg.f26r2 = cm_object_get_child_by_name(obj, "F26R2");
	state->f0.reg.f27r1 = cm_object_get_child_by_name(obj, "F27R1");
	state->f0.reg.f27r2 = cm_object_get_child_by_name(obj, "F27R2");

	// CAN_MCR bitfields.
	state->f0.fld.can_mcr.inrq = cm_object_get_child_by_name(state->f0.reg.can_mcr, "INRQ");
	state->f0.fld.can_mcr.sleep = cm_object_get_child_by_name(state->f0.reg.can_mcr, "SLEEP");
	state->f0.fld.can_mcr.txfp = cm_object_get_child_by_name(state->f0.reg.can_mcr, "TXFP");
	state->f0.fld.can_mcr.rflm = cm_object_get_child_by_name(state->f0.reg.can_mcr, "RFLM");
	state->f0.fld.can_mcr.nart = cm_object_get_child_by_name(state->f0.reg.can_mcr, "NART");
	state->f0.fld.can_mcr.awum = cm_object_get_child_by_name(state->f0.reg.can_mcr, "AWUM");
	state->f0.fld.can_mcr.abom = cm_object_get_child_by_name(state->f0.reg.can_mcr, "ABOM");
	state->f0.fld.can_mcr.ttcm = cm_object_get_child_by_name(state->f0.reg.can_mcr, "TTCM");
	state->f0.fld.can_mcr.reset = cm_object_get_child_by_name(state->f0.reg.can_mcr, "RESET");
	state->f0.fld.can_mcr.dbf = cm_object_get_child_by_name(state->f0.reg.can_mcr, "DBF");

	// CAN_MSR bitfields.
	state->f0.fld.can_msr.inak = cm_object_get_child_by_name(state->f0.reg.can_msr, "INAK");
	state->f0.fld.can_msr.slak = cm_object_get_child_by_name(state->f0.reg.can_msr, "SLAK");
	state->f0.fld.can_msr.erri = cm_object_get_child_by_name(state->f0.reg.can_msr, "ERRI");
	state->f0.fld.can_msr.wkui = cm_object_get_child_by_name(state->f0.reg.can_msr, "WKUI");
	state->f0.fld.can_msr.slaki = cm_object_get_child_by_name(state->f0.reg.can_msr, "SLAKI");
	state->f0.fld.can_msr.txm = cm_object_get_child_by_name(state->f0.reg.can_msr, "TXM");
	state->f0.fld.can_msr.rxm = cm_object_get_child_by_name(state->f0.reg.can_msr, "RXM");
	state->f0.fld.can_msr.samp = cm_object_get_child_by_name(state->f0.reg.can_msr, "SAMP");
	state->f0.fld.can_msr.rx = cm_object_get_child_by_name(state->f0.reg.can_msr, "RX");

	// CAN_TSR bitfields.
	state->f0.fld.can_tsr.rqcp0 = cm_object_get_child_by_name(state->f0.reg.can_tsr, "RQCP0");
	state->f0.fld.can_tsr.txok0 = cm_object_get_child_by_name(state->f0.reg.can_tsr, "TXOK0");
	state->f0.fld.can_tsr.alst0 = cm_object_get_child_by_name(state->f0.reg.can_tsr, "ALST0");
	state->f0.fld.can_tsr.terr0 = cm_object_get_child_by_name(state->f0.reg.can_tsr, "TERR0");
	state->f0.fld.can_tsr.abrq0 = cm_object_get_child_by_name(state->f0.reg.can_tsr, "ABRQ0");
	state->f0.fld.can_tsr.rqcp1 = cm_object_get_child_by_name(state->f0.reg.can_tsr, "RQCP1");
	state->f0.fld.can_tsr.txok1 = cm_object_get_child_by_name(state->f0.reg.can_tsr, "TXOK1");
	state->f0.fld.can_tsr.alst1 = cm_object_get_child_by_name(state->f0.reg.can_tsr, "ALST1");
	state->f0.fld.can_tsr.terr1 = cm_object_get_child_by_name(state->f0.reg.can_tsr, "TERR1");
	state->f0.fld.can_tsr.abrq1 = cm_object_get_child_by_name(state->f0.reg.can_tsr, "ABRQ1");
	state->f0.fld.can_tsr.rqcp2 = cm_object_get_child_by_name(state->f0.reg.can_tsr, "RQCP2");
	state->f0.fld.can_tsr.txok2 = cm_object_get_child_by_name(state->f0.reg.can_tsr, "TXOK2");
	state->f0.fld.can_tsr.alst2 = cm_object_get_child_by_name(state->f0.reg.can_tsr, "ALST2");
	state->f0.fld.can_tsr.terr2 = cm_object_get_child_by_name(state->f0.reg.can_tsr, "TERR2");
	state->f0.fld.can_tsr.abrq2 = cm_object_get_child_by_name(state->f0.reg.can_tsr, "ABRQ2");
	state->f0.fld.can_tsr.code = cm_object_get_child_by_name(state->f0.reg.can_tsr, "CODE");
	state->f0.fld.can_tsr.tme0 = cm_object_get_child_by_name(state->f0.reg.can_tsr, "TME0");
	state->f0.fld.can_tsr.tme1 = cm_object_get_child_by_name(state->f0.reg.can_tsr, "TME1");
	state->f0.fld.can_tsr.tme2 = cm_object_get_child_by_name(state->f0.reg.can_tsr, "TME2");
	state->f0.fld.can_tsr.low0 = cm_object_get_child_by_name(state->f0.reg.can_tsr, "LOW0");
	state->f0.fld.can_tsr.low1 = cm_object_get_child_by_name(state->f0.reg.can_tsr, "LOW1");
	state->f0.fld.can_tsr.low2 = cm_object_get_child_by_name(state->f0.reg.can_tsr, "LOW2");

	// CAN_RF0R bitfields.
	state->f0.fld.can_rf0r.fmp0 = cm_object_get_child_by_name(state->f0.reg.can_rf0r, "FMP0");
	state->f0.fld.can_rf0r.full0 = cm_object_get_child_by_name(state->f0.reg.can_rf0r, "FULL0");
	state->f0.fld.can_rf0r.fovr0 = cm_object_get_child_by_name(state->f0.reg.can_rf0r, "FOVR0");
	state->f0.fld.can_rf0r.rfom0 = cm_object_get_child_by_name(state->f0.reg.can_rf0r, "RFOM0");

	// CAN_RF1R bitfields.
	state->f0.fld.can_rf1r.fmp1 = cm_object_get_child_by_name(state->f0.reg.can_rf1r, "FMP1");
	state->f0.fld.can_rf1r.full1 = cm_object_get_child_by_name(state->f0.reg.can_rf1r, "FULL1");
	state->f0.fld.can_rf1r.fovr1 = cm_object_get_child_by_name(state->f0.reg.can_rf1r, "FOVR1");
	state->f0.fld.can_rf1r.rfom1 = cm_object_get_child_by_name(state->f0.reg.can_rf1r, "RFOM1");

	// CAN_IER bitfields.
	state->f0.fld.can_ier.tmeie = cm_object_get_child_by_name(state->f0.reg.can_ier, "TMEIE");
	state->f0.fld.can_ier.fmpie0 = cm_object_get_child_by_name(state->f0.reg.can_ier, "FMPIE0");
	state->f0.fld.can_ier.ffie0 = cm_object_get_child_by_name(state->f0.reg.can_ier, "FFIE0");
	state->f0.fld.can_ier.fovie0 = cm_object_get_child_by_name(state->f0.reg.can_ier, "FOVIE0");
	state->f0.fld.can_ier.fmpie1 = cm_object_get_child_by_name(state->f0.reg.can_ier, "FMPIE1");
	state->f0.fld.can_ier.ffie1 = cm_object_get_child_by_name(state->f0.reg.can_ier, "FFIE1");
	state->f0.fld.can_ier.fovie1 = cm_object_get_child_by_name(state->f0.reg.can_ier, "FOVIE1");
	state->f0.fld.can_ier.ewgie = cm_object_get_child_by_name(state->f0.reg.can_ier, "EWGIE");
	state->f0.fld.can_ier.epvie = cm_object_get_child_by_name(state->f0.reg.can_ier, "EPVIE");
	state->f0.fld.can_ier.bofie = cm_object_get_child_by_name(state->f0.reg.can_ier, "BOFIE");
	state->f0.fld.can_ier.lecie = cm_object_get_child_by_name(state->f0.reg.can_ier, "LECIE");
	state->f0.fld.can_ier.errie = cm_object_get_child_by_name(state->f0.reg.can_ier, "ERRIE");
	state->f0.fld.can_ier.wkuie = cm_object_get_child_by_name(state->f0.reg.can_ier, "WKUIE");
	state->f0.fld.can_ier.slkie = cm_object_get_child_by_name(state->f0.reg.can_ier, "SLKIE");

	// CAN_ESR bitfields.
	state->f0.fld.can_esr.ewgf = cm_object_get_child_by_name(state->f0.reg.can_esr, "EWGF");
	state->f0.fld.can_esr.epvf = cm_object_get_child_by_name(state->f0.reg.can_esr, "EPVF");
	state->f0.fld.can_esr.boff = cm_object_get_child_by_name(state->f0.reg.can_esr, "BOFF");
	state->f0.fld.can_esr.lec = cm_object_get_child_by_name(state->f0.reg.can_esr, "LEC");
	state->f0.fld.can_esr.tec = cm_object_get_child_by_name(state->f0.reg.can_esr, "TEC");
	state->f0.fld.can_esr.rec = cm_object_get_child_by_name(state->f0.reg.can_esr, "REC");

	// CAN_BTR bitfields.
	state->f0.fld.can_btr.brp = cm_object_get_child_by_name(state->f0.reg.can_btr, "BRP");
	state->f0.fld.can_btr.ts1 = cm_object_get_child_by_name(state->f0.reg.can_btr, "TS1");
	state->f0.fld.can_btr.ts2 = cm_object_get_child_by_name(state->f0.reg.can_btr, "TS2");
	state->f0.fld.can_btr.sjw = cm_object_get_child_by_name(state->f0.reg.can_btr, "SJW");
	state->f0.fld.can_btr.lbkm = cm_object_get_child_by_name(state->f0.reg.can_btr, "LBKM");
	state->f0.fld.can_btr.silm = cm_object_get_child_by_name(state->f0.reg.can_btr, "SILM");

	// CAN_TI0R bitfields.
	state->f0.fld.can_ti0r.txrq = cm_object_get_child_by_name(state->f0.reg.can_ti0r, "TXRQ");
	state->f0.fld.can_ti0r.rtr = cm_object_get_child_by_name(state->f0.reg.can_ti0r, "RTR");
	state->f0.fld.can_ti0r.ide = cm_object_get_child_by_name(state->f0.reg.can_ti0r, "IDE");
	state->f0.fld.can_ti0r.exid = cm_object_get_child_by_name(state->f0.reg.can_ti0r, "EXID");
	state->f0.fld.can_ti0r.stid = cm_object_get_child_by_name(state->f0.reg.can_ti0r, "STID");

	// CAN_TDT0R bitfields.
	state->f0.fld.can_tdt0r.dlc = cm_object_get_child_by_name(state->f0.reg.can_tdt0r, "DLC");
	state->f0.fld.can_tdt0r.tgt = cm_object_get_child_by_name(state->f0.reg.can_tdt0r, "TGT");
	state->f0.fld.can_tdt0r.time = cm_object_get_child_by_name(state->f0.reg.can_tdt0r, "TIME");

	// CAN_TDL0R bitfields.
	state->f0.fld.can_tdl0r.data0 = cm_object_get_child_by_name(state->f0.reg.can_tdl0r, "DATA0");
	state->f0.fld.can_tdl0r.data1 = cm_object_get_child_by_name(state->f0.reg.can_tdl0r, "DATA1");
	state->f0.fld.can_tdl0r.data2 = cm_object_get_child_by_name(state->f0.reg.can_tdl0r, "DATA2");
	state->f0.fld.can_tdl0r.data3 = cm_object_get_child_by_name(state->f0.reg.can_tdl0r, "DATA3");

	// CAN_TDH0R bitfields.
	state->f0.fld.can_tdh0r.data4 = cm_object_get_child_by_name(state->f0.reg.can_tdh0r, "DATA4");
	state->f0.fld.can_tdh0r.data5 = cm_object_get_child_by_name(state->f0.reg.can_tdh0r, "DATA5");
	state->f0.fld.can_tdh0r.data6 = cm_object_get_child_by_name(state->f0.reg.can_tdh0r, "DATA6");
	state->f0.fld.can_tdh0r.data7 = cm_object_get_child_by_name(state->f0.reg.can_tdh0r, "DATA7");

	// CAN_TI1R bitfields.
	state->f0.fld.can_ti1r.txrq = cm_object_get_child_by_name(state->f0.reg.can_ti1r, "TXRQ");
	state->f0.fld.can_ti1r.rtr = cm_object_get_child_by_name(state->f0.reg.can_ti1r, "RTR");
	state->f0.fld.can_ti1r.ide = cm_object_get_child_by_name(state->f0.reg.can_ti1r, "IDE");
	state->f0.fld.can_ti1r.exid = cm_object_get_child_by_name(state->f0.reg.can_ti1r, "EXID");
	state->f0.fld.can_ti1r.stid = cm_object_get_child_by_name(state->f0.reg.can_ti1r, "STID");

	// CAN_TDT1R bitfields.
	state->f0.fld.can_tdt1r.dlc = cm_object_get_child_by_name(state->f0.reg.can_tdt1r, "DLC");
	state->f0.fld.can_tdt1r.tgt = cm_object_get_child_by_name(state->f0.reg.can_tdt1r, "TGT");
	state->f0.fld.can_tdt1r.time = cm_object_get_child_by_name(state->f0.reg.can_tdt1r, "TIME");

	// CAN_TDL1R bitfields.
	state->f0.fld.can_tdl1r.data0 = cm_object_get_child_by_name(state->f0.reg.can_tdl1r, "DATA0");
	state->f0.fld.can_tdl1r.data1 = cm_object_get_child_by_name(state->f0.reg.can_tdl1r, "DATA1");
	state->f0.fld.can_tdl1r.data2 = cm_object_get_child_by_name(state->f0.reg.can_tdl1r, "DATA2");
	state->f0.fld.can_tdl1r.data3 = cm_object_get_child_by_name(state->f0.reg.can_tdl1r, "DATA3");

	// CAN_TDH1R bitfields.
	state->f0.fld.can_tdh1r.data4 = cm_object_get_child_by_name(state->f0.reg.can_tdh1r, "DATA4");
	state->f0.fld.can_tdh1r.data5 = cm_object_get_child_by_name(state->f0.reg.can_tdh1r, "DATA5");
	state->f0.fld.can_tdh1r.data6 = cm_object_get_child_by_name(state->f0.reg.can_tdh1r, "DATA6");
	state->f0.fld.can_tdh1r.data7 = cm_object_get_child_by_name(state->f0.reg.can_tdh1r, "DATA7");

	// CAN_TI2R bitfields.
	state->f0.fld.can_ti2r.txrq = cm_object_get_child_by_name(state->f0.reg.can_ti2r, "TXRQ");
	state->f0.fld.can_ti2r.rtr = cm_object_get_child_by_name(state->f0.reg.can_ti2r, "RTR");
	state->f0.fld.can_ti2r.ide = cm_object_get_child_by_name(state->f0.reg.can_ti2r, "IDE");
	state->f0.fld.can_ti2r.exid = cm_object_get_child_by_name(state->f0.reg.can_ti2r, "EXID");
	state->f0.fld.can_ti2r.stid = cm_object_get_child_by_name(state->f0.reg.can_ti2r, "STID");

	// CAN_TDT2R bitfields.
	state->f0.fld.can_tdt2r.dlc = cm_object_get_child_by_name(state->f0.reg.can_tdt2r, "DLC");
	state->f0.fld.can_tdt2r.tgt = cm_object_get_child_by_name(state->f0.reg.can_tdt2r, "TGT");
	state->f0.fld.can_tdt2r.time = cm_object_get_child_by_name(state->f0.reg.can_tdt2r, "TIME");

	// CAN_TDL2R bitfields.
	state->f0.fld.can_tdl2r.data0 = cm_object_get_child_by_name(state->f0.reg.can_tdl2r, "DATA0");
	state->f0.fld.can_tdl2r.data1 = cm_object_get_child_by_name(state->f0.reg.can_tdl2r, "DATA1");
	state->f0.fld.can_tdl2r.data2 = cm_object_get_child_by_name(state->f0.reg.can_tdl2r, "DATA2");
	state->f0.fld.can_tdl2r.data3 = cm_object_get_child_by_name(state->f0.reg.can_tdl2r, "DATA3");

	// CAN_TDH2R bitfields.
	state->f0.fld.can_tdh2r.data4 = cm_object_get_child_by_name(state->f0.reg.can_tdh2r, "DATA4");
	state->f0.fld.can_tdh2r.data5 = cm_object_get_child_by_name(state->f0.reg.can_tdh2r, "DATA5");
	state->f0.fld.can_tdh2r.data6 = cm_object_get_child_by_name(state->f0.reg.can_tdh2r, "DATA6");
	state->f0.fld.can_tdh2r.data7 = cm_object_get_child_by_name(state->f0.reg.can_tdh2r, "DATA7");

	// CAN_RI0R bitfields.
	state->f0.fld.can_ri0r.rtr = cm_object_get_child_by_name(state->f0.reg.can_ri0r, "RTR");
	state->f0.fld.can_ri0r.ide = cm_object_get_child_by_name(state->f0.reg.can_ri0r, "IDE");
	state->f0.fld.can_ri0r.exid = cm_object_get_child_by_name(state->f0.reg.can_ri0r, "EXID");
	state->f0.fld.can_ri0r.stid = cm_object_get_child_by_name(state->f0.reg.can_ri0r, "STID");

	// CAN_RDT0R bitfields.
	state->f0.fld.can_rdt0r.dlc = cm_object_get_child_by_name(state->f0.reg.can_rdt0r, "DLC");
	state->f0.fld.can_rdt0r.fmi = cm_object_get_child_by_name(state->f0.reg.can_rdt0r, "FMI");
	state->f0.fld.can_rdt0r.time = cm_object_get_child_by_name(state->f0.reg.can_rdt0r, "TIME");

	// CAN_RDL0R bitfields.
	state->f0.fld.can_rdl0r.data0 = cm_object_get_child_by_name(state->f0.reg.can_rdl0r, "DATA0");
	state->f0.fld.can_rdl0r.data1 = cm_object_get_child_by_name(state->f0.reg.can_rdl0r, "DATA1");
	state->f0.fld.can_rdl0r.data2 = cm_object_get_child_by_name(state->f0.reg.can_rdl0r, "DATA2");
	state->f0.fld.can_rdl0r.data3 = cm_object_get_child_by_name(state->f0.reg.can_rdl0r, "DATA3");

	// CAN_RDH0R bitfields.
	state->f0.fld.can_rdh0r.data4 = cm_object_get_child_by_name(state->f0.reg.can_rdh0r, "DATA4");
	state->f0.fld.can_rdh0r.data5 = cm_object_get_child_by_name(state->f0.reg.can_rdh0r, "DATA5");
	state->f0.fld.can_rdh0r.data6 = cm_object_get_child_by_name(state->f0.reg.can_rdh0r, "DATA6");
	state->f0.fld.can_rdh0r.data7 = cm_object_get_child_by_name(state->f0.reg.can_rdh0r, "DATA7");

	// CAN_RI1R bitfields.
	state->f0.fld.can_ri1r.rtr = cm_object_get_child_by_name(state->f0.reg.can_ri1r, "RTR");
	state->f0.fld.can_ri1r.ide = cm_object_get_child_by_name(state->f0.reg.can_ri1r, "IDE");
	state->f0.fld.can_ri1r.exid = cm_object_get_child_by_name(state->f0.reg.can_ri1r, "EXID");
	state->f0.fld.can_ri1r.stid = cm_object_get_child_by_name(state->f0.reg.can_ri1r, "STID");

	// CAN_RDT1R bitfields.
	state->f0.fld.can_rdt1r.dlc = cm_object_get_child_by_name(state->f0.reg.can_rdt1r, "DLC");
	state->f0.fld.can_rdt1r.fmi = cm_object_get_child_by_name(state->f0.reg.can_rdt1r, "FMI");
	state->f0.fld.can_rdt1r.time = cm_object_get_child_by_name(state->f0.reg.can_rdt1r, "TIME");

	// CAN_RDL1R bitfields.
	state->f0.fld.can_rdl1r.data0 = cm_object_get_child_by_name(state->f0.reg.can_rdl1r, "DATA0");
	state->f0.fld.can_rdl1r.data1 = cm_object_get_child_by_name(state->f0.reg.can_rdl1r, "DATA1");
	state->f0.fld.can_rdl1r.data2 = cm_object_get_child_by_name(state->f0.reg.can_rdl1r, "DATA2");
	state->f0.fld.can_rdl1r.data3 = cm_object_get_child_by_name(state->f0.reg.can_rdl1r, "DATA3");

	// CAN_RDH1R bitfields.
	state->f0.fld.can_rdh1r.data4 = cm_object_get_child_by_name(state->f0.reg.can_rdh1r, "DATA4");
	state->f0.fld.can_rdh1r.data5 = cm_object_get_child_by_name(state->f0.reg.can_rdh1r, "DATA5");
	state->f0.fld.can_rdh1r.data6 = cm_object_get_child_by_name(state->f0.reg.can_rdh1r, "DATA6");
	state->f0.fld.can_rdh1r.data7 = cm_object_get_child_by_name(state->f0.reg.can_rdh1r, "DATA7");

	// CAN_FMR bitfields.
	state->f0.fld.can_fmr.finit = cm_object_get_child_by_name(state->f0.reg.can_fmr, "FINIT");
	state->f0.fld.can_fmr.can2sb = cm_object_get_child_by_name(state->f0.reg.can_fmr, "CAN2SB");

	// CAN_FM1R bitfields.
	state->f0.fld.can_fm1r.fbm0 = cm_object_get_child_by_name(state->f0.reg.can_fm1r, "FBM0");
	state->f0.fld.can_fm1r.fbm1 = cm_object_get_child_by_name(state->f0.reg.can_fm1r, "FBM1");
	state->f0.fld.can_fm1r.fbm2 = cm_object_get_child_by_name(state->f0.reg.can_fm1r, "FBM2");
	state->f0.fld.can_fm1r.fbm3 = cm_object_get_child_by_name(state->f0.reg.can_fm1r, "FBM3");
	state->f0.fld.can_fm1r.fbm4 = cm_object_get_child_by_name(state->f0.reg.can_fm1r, "FBM4");
	state->f0.fld.can_fm1r.fbm5 = cm_object_get_child_by_name(state->f0.reg.can_fm1r, "FBM5");
	state->f0.fld.can_fm1r.fbm6 = cm_object_get_child_by_name(state->f0.reg.can_fm1r, "FBM6");
	state->f0.fld.can_fm1r.fbm7 = cm_object_get_child_by_name(state->f0.reg.can_fm1r, "FBM7");
	state->f0.fld.can_fm1r.fbm8 = cm_object_get_child_by_name(state->f0.reg.can_fm1r, "FBM8");
	state->f0.fld.can_fm1r.fbm9 = cm_object_get_child_by_name(state->f0.reg.can_fm1r, "FBM9");
	state->f0.fld.can_fm1r.fbm10 = cm_object_get_child_by_name(state->f0.reg.can_fm1r, "FBM10");
	state->f0.fld.can_fm1r.fbm11 = cm_object_get_child_by_name(state->f0.reg.can_fm1r, "FBM11");
	state->f0.fld.can_fm1r.fbm12 = cm_object_get_child_by_name(state->f0.reg.can_fm1r, "FBM12");
	state->f0.fld.can_fm1r.fbm13 = cm_object_get_child_by_name(state->f0.reg.can_fm1r, "FBM13");
	state->f0.fld.can_fm1r.fbm14 = cm_object_get_child_by_name(state->f0.reg.can_fm1r, "FBM14");
	state->f0.fld.can_fm1r.fbm15 = cm_object_get_child_by_name(state->f0.reg.can_fm1r, "FBM15");
	state->f0.fld.can_fm1r.fbm16 = cm_object_get_child_by_name(state->f0.reg.can_fm1r, "FBM16");
	state->f0.fld.can_fm1r.fbm17 = cm_object_get_child_by_name(state->f0.reg.can_fm1r, "FBM17");
	state->f0.fld.can_fm1r.fbm18 = cm_object_get_child_by_name(state->f0.reg.can_fm1r, "FBM18");
	state->f0.fld.can_fm1r.fbm19 = cm_object_get_child_by_name(state->f0.reg.can_fm1r, "FBM19");
	state->f0.fld.can_fm1r.fbm20 = cm_object_get_child_by_name(state->f0.reg.can_fm1r, "FBM20");
	state->f0.fld.can_fm1r.fbm21 = cm_object_get_child_by_name(state->f0.reg.can_fm1r, "FBM21");
	state->f0.fld.can_fm1r.fbm22 = cm_object_get_child_by_name(state->f0.reg.can_fm1r, "FBM22");
	state->f0.fld.can_fm1r.fbm23 = cm_object_get_child_by_name(state->f0.reg.can_fm1r, "FBM23");
	state->f0.fld.can_fm1r.fbm24 = cm_object_get_child_by_name(state->f0.reg.can_fm1r, "FBM24");
	state->f0.fld.can_fm1r.fbm25 = cm_object_get_child_by_name(state->f0.reg.can_fm1r, "FBM25");
	state->f0.fld.can_fm1r.fbm26 = cm_object_get_child_by_name(state->f0.reg.can_fm1r, "FBM26");
	state->f0.fld.can_fm1r.fbm27 = cm_object_get_child_by_name(state->f0.reg.can_fm1r, "FBM27");

	// CAN_FS1R bitfields.
	state->f0.fld.can_fs1r.fsc0 = cm_object_get_child_by_name(state->f0.reg.can_fs1r, "FSC0");
	state->f0.fld.can_fs1r.fsc1 = cm_object_get_child_by_name(state->f0.reg.can_fs1r, "FSC1");
	state->f0.fld.can_fs1r.fsc2 = cm_object_get_child_by_name(state->f0.reg.can_fs1r, "FSC2");
	state->f0.fld.can_fs1r.fsc3 = cm_object_get_child_by_name(state->f0.reg.can_fs1r, "FSC3");
	state->f0.fld.can_fs1r.fsc4 = cm_object_get_child_by_name(state->f0.reg.can_fs1r, "FSC4");
	state->f0.fld.can_fs1r.fsc5 = cm_object_get_child_by_name(state->f0.reg.can_fs1r, "FSC5");
	state->f0.fld.can_fs1r.fsc6 = cm_object_get_child_by_name(state->f0.reg.can_fs1r, "FSC6");
	state->f0.fld.can_fs1r.fsc7 = cm_object_get_child_by_name(state->f0.reg.can_fs1r, "FSC7");
	state->f0.fld.can_fs1r.fsc8 = cm_object_get_child_by_name(state->f0.reg.can_fs1r, "FSC8");
	state->f0.fld.can_fs1r.fsc9 = cm_object_get_child_by_name(state->f0.reg.can_fs1r, "FSC9");
	state->f0.fld.can_fs1r.fsc10 = cm_object_get_child_by_name(state->f0.reg.can_fs1r, "FSC10");
	state->f0.fld.can_fs1r.fsc11 = cm_object_get_child_by_name(state->f0.reg.can_fs1r, "FSC11");
	state->f0.fld.can_fs1r.fsc12 = cm_object_get_child_by_name(state->f0.reg.can_fs1r, "FSC12");
	state->f0.fld.can_fs1r.fsc13 = cm_object_get_child_by_name(state->f0.reg.can_fs1r, "FSC13");
	state->f0.fld.can_fs1r.fsc14 = cm_object_get_child_by_name(state->f0.reg.can_fs1r, "FSC14");
	state->f0.fld.can_fs1r.fsc15 = cm_object_get_child_by_name(state->f0.reg.can_fs1r, "FSC15");
	state->f0.fld.can_fs1r.fsc16 = cm_object_get_child_by_name(state->f0.reg.can_fs1r, "FSC16");
	state->f0.fld.can_fs1r.fsc17 = cm_object_get_child_by_name(state->f0.reg.can_fs1r, "FSC17");
	state->f0.fld.can_fs1r.fsc18 = cm_object_get_child_by_name(state->f0.reg.can_fs1r, "FSC18");
	state->f0.fld.can_fs1r.fsc19 = cm_object_get_child_by_name(state->f0.reg.can_fs1r, "FSC19");
	state->f0.fld.can_fs1r.fsc20 = cm_object_get_child_by_name(state->f0.reg.can_fs1r, "FSC20");
	state->f0.fld.can_fs1r.fsc21 = cm_object_get_child_by_name(state->f0.reg.can_fs1r, "FSC21");
	state->f0.fld.can_fs1r.fsc22 = cm_object_get_child_by_name(state->f0.reg.can_fs1r, "FSC22");
	state->f0.fld.can_fs1r.fsc23 = cm_object_get_child_by_name(state->f0.reg.can_fs1r, "FSC23");
	state->f0.fld.can_fs1r.fsc24 = cm_object_get_child_by_name(state->f0.reg.can_fs1r, "FSC24");
	state->f0.fld.can_fs1r.fsc25 = cm_object_get_child_by_name(state->f0.reg.can_fs1r, "FSC25");
	state->f0.fld.can_fs1r.fsc26 = cm_object_get_child_by_name(state->f0.reg.can_fs1r, "FSC26");
	state->f0.fld.can_fs1r.fsc27 = cm_object_get_child_by_name(state->f0.reg.can_fs1r, "FSC27");

	// CAN_FFA1R bitfields.
	state->f0.fld.can_ffa1r.ffa0 = cm_object_get_child_by_name(state->f0.reg.can_ffa1r, "FFA0");
	state->f0.fld.can_ffa1r.ffa1 = cm_object_get_child_by_name(state->f0.reg.can_ffa1r, "FFA1");
	state->f0.fld.can_ffa1r.ffa2 = cm_object_get_child_by_name(state->f0.reg.can_ffa1r, "FFA2");
	state->f0.fld.can_ffa1r.ffa3 = cm_object_get_child_by_name(state->f0.reg.can_ffa1r, "FFA3");
	state->f0.fld.can_ffa1r.ffa4 = cm_object_get_child_by_name(state->f0.reg.can_ffa1r, "FFA4");
	state->f0.fld.can_ffa1r.ffa5 = cm_object_get_child_by_name(state->f0.reg.can_ffa1r, "FFA5");
	state->f0.fld.can_ffa1r.ffa6 = cm_object_get_child_by_name(state->f0.reg.can_ffa1r, "FFA6");
	state->f0.fld.can_ffa1r.ffa7 = cm_object_get_child_by_name(state->f0.reg.can_ffa1r, "FFA7");
	state->f0.fld.can_ffa1r.ffa8 = cm_object_get_child_by_name(state->f0.reg.can_ffa1r, "FFA8");
	state->f0.fld.can_ffa1r.ffa9 = cm_object_get_child_by_name(state->f0.reg.can_ffa1r, "FFA9");
	state->f0.fld.can_ffa1r.ffa10 = cm_object_get_child_by_name(state->f0.reg.can_ffa1r, "FFA10");
	state->f0.fld.can_ffa1r.ffa11 = cm_object_get_child_by_name(state->f0.reg.can_ffa1r, "FFA11");
	state->f0.fld.can_ffa1r.ffa12 = cm_object_get_child_by_name(state->f0.reg.can_ffa1r, "FFA12");
	state->f0.fld.can_ffa1r.ffa13 = cm_object_get_child_by_name(state->f0.reg.can_ffa1r, "FFA13");
	state->f0.fld.can_ffa1r.ffa14 = cm_object_get_child_by_name(state->f0.reg.can_ffa1r, "FFA14");
	state->f0.fld.can_ffa1r.ffa15 = cm_object_get_child_by_name(state->f0.reg.can_ffa1r, "FFA15");
	state->f0.fld.can_ffa1r.ffa16 = cm_object_get_child_by_name(state->f0.reg.can_ffa1r, "FFA16");
	state->f0.fld.can_ffa1r.ffa17 = cm_object_get_child_by_name(state->f0.reg.can_ffa1r, "FFA17");
	state->f0.fld.can_ffa1r.ffa18 = cm_object_get_child_by_name(state->f0.reg.can_ffa1r, "FFA18");
	state->f0.fld.can_ffa1r.ffa19 = cm_object_get_child_by_name(state->f0.reg.can_ffa1r, "FFA19");
	state->f0.fld.can_ffa1r.ffa20 = cm_object_get_child_by_name(state->f0.reg.can_ffa1r, "FFA20");
	state->f0.fld.can_ffa1r.ffa21 = cm_object_get_child_by_name(state->f0.reg.can_ffa1r, "FFA21");
	state->f0.fld.can_ffa1r.ffa22 = cm_object_get_child_by_name(state->f0.reg.can_ffa1r, "FFA22");
	state->f0.fld.can_ffa1r.ffa23 = cm_object_get_child_by_name(state->f0.reg.can_ffa1r, "FFA23");
	state->f0.fld.can_ffa1r.ffa24 = cm_object_get_child_by_name(state->f0.reg.can_ffa1r, "FFA24");
	state->f0.fld.can_ffa1r.ffa25 = cm_object_get_child_by_name(state->f0.reg.can_ffa1r, "FFA25");
	state->f0.fld.can_ffa1r.ffa26 = cm_object_get_child_by_name(state->f0.reg.can_ffa1r, "FFA26");
	state->f0.fld.can_ffa1r.ffa27 = cm_object_get_child_by_name(state->f0.reg.can_ffa1r, "FFA27");

	// CAN_FA1R bitfields.
	state->f0.fld.can_fa1r.fact0 = cm_object_get_child_by_name(state->f0.reg.can_fa1r, "FACT0");
	state->f0.fld.can_fa1r.fact1 = cm_object_get_child_by_name(state->f0.reg.can_fa1r, "FACT1");
	state->f0.fld.can_fa1r.fact2 = cm_object_get_child_by_name(state->f0.reg.can_fa1r, "FACT2");
	state->f0.fld.can_fa1r.fact3 = cm_object_get_child_by_name(state->f0.reg.can_fa1r, "FACT3");
	state->f0.fld.can_fa1r.fact4 = cm_object_get_child_by_name(state->f0.reg.can_fa1r, "FACT4");
	state->f0.fld.can_fa1r.fact5 = cm_object_get_child_by_name(state->f0.reg.can_fa1r, "FACT5");
	state->f0.fld.can_fa1r.fact6 = cm_object_get_child_by_name(state->f0.reg.can_fa1r, "FACT6");
	state->f0.fld.can_fa1r.fact7 = cm_object_get_child_by_name(state->f0.reg.can_fa1r, "FACT7");
	state->f0.fld.can_fa1r.fact8 = cm_object_get_child_by_name(state->f0.reg.can_fa1r, "FACT8");
	state->f0.fld.can_fa1r.fact9 = cm_object_get_child_by_name(state->f0.reg.can_fa1r, "FACT9");
	state->f0.fld.can_fa1r.fact10 = cm_object_get_child_by_name(state->f0.reg.can_fa1r, "FACT10");
	state->f0.fld.can_fa1r.fact11 = cm_object_get_child_by_name(state->f0.reg.can_fa1r, "FACT11");
	state->f0.fld.can_fa1r.fact12 = cm_object_get_child_by_name(state->f0.reg.can_fa1r, "FACT12");
	state->f0.fld.can_fa1r.fact13 = cm_object_get_child_by_name(state->f0.reg.can_fa1r, "FACT13");
	state->f0.fld.can_fa1r.fact14 = cm_object_get_child_by_name(state->f0.reg.can_fa1r, "FACT14");
	state->f0.fld.can_fa1r.fact15 = cm_object_get_child_by_name(state->f0.reg.can_fa1r, "FACT15");
	state->f0.fld.can_fa1r.fact16 = cm_object_get_child_by_name(state->f0.reg.can_fa1r, "FACT16");
	state->f0.fld.can_fa1r.fact17 = cm_object_get_child_by_name(state->f0.reg.can_fa1r, "FACT17");
	state->f0.fld.can_fa1r.fact18 = cm_object_get_child_by_name(state->f0.reg.can_fa1r, "FACT18");
	state->f0.fld.can_fa1r.fact19 = cm_object_get_child_by_name(state->f0.reg.can_fa1r, "FACT19");
	state->f0.fld.can_fa1r.fact20 = cm_object_get_child_by_name(state->f0.reg.can_fa1r, "FACT20");
	state->f0.fld.can_fa1r.fact21 = cm_object_get_child_by_name(state->f0.reg.can_fa1r, "FACT21");
	state->f0.fld.can_fa1r.fact22 = cm_object_get_child_by_name(state->f0.reg.can_fa1r, "FACT22");
	state->f0.fld.can_fa1r.fact23 = cm_object_get_child_by_name(state->f0.reg.can_fa1r, "FACT23");
	state->f0.fld.can_fa1r.fact24 = cm_object_get_child_by_name(state->f0.reg.can_fa1r, "FACT24");
	state->f0.fld.can_fa1r.fact25 = cm_object_get_child_by_name(state->f0.reg.can_fa1r, "FACT25");
	state->f0.fld.can_fa1r.fact26 = cm_object_get_child_by_name(state->f0.reg.can_fa1r, "FACT26");
	state->f0.fld.can_fa1r.fact27 = cm_object_get_child_by_name(state->f0.reg.can_fa1r, "FACT27");

	// F0R1 bitfields.
	state->f0.fld.f0r1.fb0 = cm_object_get_child_by_name(state->f0.reg.f0r1, "FB0");
	state->f0.fld.f0r1.fb1 = cm_object_get_child_by_name(state->f0.reg.f0r1, "FB1");
	state->f0.fld.f0r1.fb2 = cm_object_get_child_by_name(state->f0.reg.f0r1, "FB2");
	state->f0.fld.f0r1.fb3 = cm_object_get_child_by_name(state->f0.reg.f0r1, "FB3");
	state->f0.fld.f0r1.fb4 = cm_object_get_child_by_name(state->f0.reg.f0r1, "FB4");
	state->f0.fld.f0r1.fb5 = cm_object_get_child_by_name(state->f0.reg.f0r1, "FB5");
	state->f0.fld.f0r1.fb6 = cm_object_get_child_by_name(state->f0.reg.f0r1, "FB6");
	state->f0.fld.f0r1.fb7 = cm_object_get_child_by_name(state->f0.reg.f0r1, "FB7");
	state->f0.fld.f0r1.fb8 = cm_object_get_child_by_name(state->f0.reg.f0r1, "FB8");
	state->f0.fld.f0r1.fb9 = cm_object_get_child_by_name(state->f0.reg.f0r1, "FB9");
	state->f0.fld.f0r1.fb10 = cm_object_get_child_by_name(state->f0.reg.f0r1, "FB10");
	state->f0.fld.f0r1.fb11 = cm_object_get_child_by_name(state->f0.reg.f0r1, "FB11");
	state->f0.fld.f0r1.fb12 = cm_object_get_child_by_name(state->f0.reg.f0r1, "FB12");
	state->f0.fld.f0r1.fb13 = cm_object_get_child_by_name(state->f0.reg.f0r1, "FB13");
	state->f0.fld.f0r1.fb14 = cm_object_get_child_by_name(state->f0.reg.f0r1, "FB14");
	state->f0.fld.f0r1.fb15 = cm_object_get_child_by_name(state->f0.reg.f0r1, "FB15");
	state->f0.fld.f0r1.fb16 = cm_object_get_child_by_name(state->f0.reg.f0r1, "FB16");
	state->f0.fld.f0r1.fb17 = cm_object_get_child_by_name(state->f0.reg.f0r1, "FB17");
	state->f0.fld.f0r1.fb18 = cm_object_get_child_by_name(state->f0.reg.f0r1, "FB18");
	state->f0.fld.f0r1.fb19 = cm_object_get_child_by_name(state->f0.reg.f0r1, "FB19");
	state->f0.fld.f0r1.fb20 = cm_object_get_child_by_name(state->f0.reg.f0r1, "FB20");
	state->f0.fld.f0r1.fb21 = cm_object_get_child_by_name(state->f0.reg.f0r1, "FB21");
	state->f0.fld.f0r1.fb22 = cm_object_get_child_by_name(state->f0.reg.f0r1, "FB22");
	state->f0.fld.f0r1.fb23 = cm_object_get_child_by_name(state->f0.reg.f0r1, "FB23");
	state->f0.fld.f0r1.fb24 = cm_object_get_child_by_name(state->f0.reg.f0r1, "FB24");
	state->f0.fld.f0r1.fb25 = cm_object_get_child_by_name(state->f0.reg.f0r1, "FB25");
	state->f0.fld.f0r1.fb26 = cm_object_get_child_by_name(state->f0.reg.f0r1, "FB26");
	state->f0.fld.f0r1.fb27 = cm_object_get_child_by_name(state->f0.reg.f0r1, "FB27");
	state->f0.fld.f0r1.fb28 = cm_object_get_child_by_name(state->f0.reg.f0r1, "FB28");
	state->f0.fld.f0r1.fb29 = cm_object_get_child_by_name(state->f0.reg.f0r1, "FB29");
	state->f0.fld.f0r1.fb30 = cm_object_get_child_by_name(state->f0.reg.f0r1, "FB30");
	state->f0.fld.f0r1.fb31 = cm_object_get_child_by_name(state->f0.reg.f0r1, "FB31");

	// F0R2 bitfields.
	state->f0.fld.f0r2.fb0 = cm_object_get_child_by_name(state->f0.reg.f0r2, "FB0");
	state->f0.fld.f0r2.fb1 = cm_object_get_child_by_name(state->f0.reg.f0r2, "FB1");
	state->f0.fld.f0r2.fb2 = cm_object_get_child_by_name(state->f0.reg.f0r2, "FB2");
	state->f0.fld.f0r2.fb3 = cm_object_get_child_by_name(state->f0.reg.f0r2, "FB3");
	state->f0.fld.f0r2.fb4 = cm_object_get_child_by_name(state->f0.reg.f0r2, "FB4");
	state->f0.fld.f0r2.fb5 = cm_object_get_child_by_name(state->f0.reg.f0r2, "FB5");
	state->f0.fld.f0r2.fb6 = cm_object_get_child_by_name(state->f0.reg.f0r2, "FB6");
	state->f0.fld.f0r2.fb7 = cm_object_get_child_by_name(state->f0.reg.f0r2, "FB7");
	state->f0.fld.f0r2.fb8 = cm_object_get_child_by_name(state->f0.reg.f0r2, "FB8");
	state->f0.fld.f0r2.fb9 = cm_object_get_child_by_name(state->f0.reg.f0r2, "FB9");
	state->f0.fld.f0r2.fb10 = cm_object_get_child_by_name(state->f0.reg.f0r2, "FB10");
	state->f0.fld.f0r2.fb11 = cm_object_get_child_by_name(state->f0.reg.f0r2, "FB11");
	state->f0.fld.f0r2.fb12 = cm_object_get_child_by_name(state->f0.reg.f0r2, "FB12");
	state->f0.fld.f0r2.fb13 = cm_object_get_child_by_name(state->f0.reg.f0r2, "FB13");
	state->f0.fld.f0r2.fb14 = cm_object_get_child_by_name(state->f0.reg.f0r2, "FB14");
	state->f0.fld.f0r2.fb15 = cm_object_get_child_by_name(state->f0.reg.f0r2, "FB15");
	state->f0.fld.f0r2.fb16 = cm_object_get_child_by_name(state->f0.reg.f0r2, "FB16");
	state->f0.fld.f0r2.fb17 = cm_object_get_child_by_name(state->f0.reg.f0r2, "FB17");
	state->f0.fld.f0r2.fb18 = cm_object_get_child_by_name(state->f0.reg.f0r2, "FB18");
	state->f0.fld.f0r2.fb19 = cm_object_get_child_by_name(state->f0.reg.f0r2, "FB19");
	state->f0.fld.f0r2.fb20 = cm_object_get_child_by_name(state->f0.reg.f0r2, "FB20");
	state->f0.fld.f0r2.fb21 = cm_object_get_child_by_name(state->f0.reg.f0r2, "FB21");
	state->f0.fld.f0r2.fb22 = cm_object_get_child_by_name(state->f0.reg.f0r2, "FB22");
	state->f0.fld.f0r2.fb23 = cm_object_get_child_by_name(state->f0.reg.f0r2, "FB23");
	state->f0.fld.f0r2.fb24 = cm_object_get_child_by_name(state->f0.reg.f0r2, "FB24");
	state->f0.fld.f0r2.fb25 = cm_object_get_child_by_name(state->f0.reg.f0r2, "FB25");
	state->f0.fld.f0r2.fb26 = cm_object_get_child_by_name(state->f0.reg.f0r2, "FB26");
	state->f0.fld.f0r2.fb27 = cm_object_get_child_by_name(state->f0.reg.f0r2, "FB27");
	state->f0.fld.f0r2.fb28 = cm_object_get_child_by_name(state->f0.reg.f0r2, "FB28");
	state->f0.fld.f0r2.fb29 = cm_object_get_child_by_name(state->f0.reg.f0r2, "FB29");
	state->f0.fld.f0r2.fb30 = cm_object_get_child_by_name(state->f0.reg.f0r2, "FB30");
	state->f0.fld.f0r2.fb31 = cm_object_get_child_by_name(state->f0.reg.f0r2, "FB31");

	// F1R1 bitfields.
	state->f0.fld.f1r1.fb0 = cm_object_get_child_by_name(state->f0.reg.f1r1, "FB0");
	state->f0.fld.f1r1.fb1 = cm_object_get_child_by_name(state->f0.reg.f1r1, "FB1");
	state->f0.fld.f1r1.fb2 = cm_object_get_child_by_name(state->f0.reg.f1r1, "FB2");
	state->f0.fld.f1r1.fb3 = cm_object_get_child_by_name(state->f0.reg.f1r1, "FB3");
	state->f0.fld.f1r1.fb4 = cm_object_get_child_by_name(state->f0.reg.f1r1, "FB4");
	state->f0.fld.f1r1.fb5 = cm_object_get_child_by_name(state->f0.reg.f1r1, "FB5");
	state->f0.fld.f1r1.fb6 = cm_object_get_child_by_name(state->f0.reg.f1r1, "FB6");
	state->f0.fld.f1r1.fb7 = cm_object_get_child_by_name(state->f0.reg.f1r1, "FB7");
	state->f0.fld.f1r1.fb8 = cm_object_get_child_by_name(state->f0.reg.f1r1, "FB8");
	state->f0.fld.f1r1.fb9 = cm_object_get_child_by_name(state->f0.reg.f1r1, "FB9");
	state->f0.fld.f1r1.fb10 = cm_object_get_child_by_name(state->f0.reg.f1r1, "FB10");
	state->f0.fld.f1r1.fb11 = cm_object_get_child_by_name(state->f0.reg.f1r1, "FB11");
	state->f0.fld.f1r1.fb12 = cm_object_get_child_by_name(state->f0.reg.f1r1, "FB12");
	state->f0.fld.f1r1.fb13 = cm_object_get_child_by_name(state->f0.reg.f1r1, "FB13");
	state->f0.fld.f1r1.fb14 = cm_object_get_child_by_name(state->f0.reg.f1r1, "FB14");
	state->f0.fld.f1r1.fb15 = cm_object_get_child_by_name(state->f0.reg.f1r1, "FB15");
	state->f0.fld.f1r1.fb16 = cm_object_get_child_by_name(state->f0.reg.f1r1, "FB16");
	state->f0.fld.f1r1.fb17 = cm_object_get_child_by_name(state->f0.reg.f1r1, "FB17");
	state->f0.fld.f1r1.fb18 = cm_object_get_child_by_name(state->f0.reg.f1r1, "FB18");
	state->f0.fld.f1r1.fb19 = cm_object_get_child_by_name(state->f0.reg.f1r1, "FB19");
	state->f0.fld.f1r1.fb20 = cm_object_get_child_by_name(state->f0.reg.f1r1, "FB20");
	state->f0.fld.f1r1.fb21 = cm_object_get_child_by_name(state->f0.reg.f1r1, "FB21");
	state->f0.fld.f1r1.fb22 = cm_object_get_child_by_name(state->f0.reg.f1r1, "FB22");
	state->f0.fld.f1r1.fb23 = cm_object_get_child_by_name(state->f0.reg.f1r1, "FB23");
	state->f0.fld.f1r1.fb24 = cm_object_get_child_by_name(state->f0.reg.f1r1, "FB24");
	state->f0.fld.f1r1.fb25 = cm_object_get_child_by_name(state->f0.reg.f1r1, "FB25");
	state->f0.fld.f1r1.fb26 = cm_object_get_child_by_name(state->f0.reg.f1r1, "FB26");
	state->f0.fld.f1r1.fb27 = cm_object_get_child_by_name(state->f0.reg.f1r1, "FB27");
	state->f0.fld.f1r1.fb28 = cm_object_get_child_by_name(state->f0.reg.f1r1, "FB28");
	state->f0.fld.f1r1.fb29 = cm_object_get_child_by_name(state->f0.reg.f1r1, "FB29");
	state->f0.fld.f1r1.fb30 = cm_object_get_child_by_name(state->f0.reg.f1r1, "FB30");
	state->f0.fld.f1r1.fb31 = cm_object_get_child_by_name(state->f0.reg.f1r1, "FB31");

	// F1R2 bitfields.
	state->f0.fld.f1r2.fb0 = cm_object_get_child_by_name(state->f0.reg.f1r2, "FB0");
	state->f0.fld.f1r2.fb1 = cm_object_get_child_by_name(state->f0.reg.f1r2, "FB1");
	state->f0.fld.f1r2.fb2 = cm_object_get_child_by_name(state->f0.reg.f1r2, "FB2");
	state->f0.fld.f1r2.fb3 = cm_object_get_child_by_name(state->f0.reg.f1r2, "FB3");
	state->f0.fld.f1r2.fb4 = cm_object_get_child_by_name(state->f0.reg.f1r2, "FB4");
	state->f0.fld.f1r2.fb5 = cm_object_get_child_by_name(state->f0.reg.f1r2, "FB5");
	state->f0.fld.f1r2.fb6 = cm_object_get_child_by_name(state->f0.reg.f1r2, "FB6");
	state->f0.fld.f1r2.fb7 = cm_object_get_child_by_name(state->f0.reg.f1r2, "FB7");
	state->f0.fld.f1r2.fb8 = cm_object_get_child_by_name(state->f0.reg.f1r2, "FB8");
	state->f0.fld.f1r2.fb9 = cm_object_get_child_by_name(state->f0.reg.f1r2, "FB9");
	state->f0.fld.f1r2.fb10 = cm_object_get_child_by_name(state->f0.reg.f1r2, "FB10");
	state->f0.fld.f1r2.fb11 = cm_object_get_child_by_name(state->f0.reg.f1r2, "FB11");
	state->f0.fld.f1r2.fb12 = cm_object_get_child_by_name(state->f0.reg.f1r2, "FB12");
	state->f0.fld.f1r2.fb13 = cm_object_get_child_by_name(state->f0.reg.f1r2, "FB13");
	state->f0.fld.f1r2.fb14 = cm_object_get_child_by_name(state->f0.reg.f1r2, "FB14");
	state->f0.fld.f1r2.fb15 = cm_object_get_child_by_name(state->f0.reg.f1r2, "FB15");
	state->f0.fld.f1r2.fb16 = cm_object_get_child_by_name(state->f0.reg.f1r2, "FB16");
	state->f0.fld.f1r2.fb17 = cm_object_get_child_by_name(state->f0.reg.f1r2, "FB17");
	state->f0.fld.f1r2.fb18 = cm_object_get_child_by_name(state->f0.reg.f1r2, "FB18");
	state->f0.fld.f1r2.fb19 = cm_object_get_child_by_name(state->f0.reg.f1r2, "FB19");
	state->f0.fld.f1r2.fb20 = cm_object_get_child_by_name(state->f0.reg.f1r2, "FB20");
	state->f0.fld.f1r2.fb21 = cm_object_get_child_by_name(state->f0.reg.f1r2, "FB21");
	state->f0.fld.f1r2.fb22 = cm_object_get_child_by_name(state->f0.reg.f1r2, "FB22");
	state->f0.fld.f1r2.fb23 = cm_object_get_child_by_name(state->f0.reg.f1r2, "FB23");
	state->f0.fld.f1r2.fb24 = cm_object_get_child_by_name(state->f0.reg.f1r2, "FB24");
	state->f0.fld.f1r2.fb25 = cm_object_get_child_by_name(state->f0.reg.f1r2, "FB25");
	state->f0.fld.f1r2.fb26 = cm_object_get_child_by_name(state->f0.reg.f1r2, "FB26");
	state->f0.fld.f1r2.fb27 = cm_object_get_child_by_name(state->f0.reg.f1r2, "FB27");
	state->f0.fld.f1r2.fb28 = cm_object_get_child_by_name(state->f0.reg.f1r2, "FB28");
	state->f0.fld.f1r2.fb29 = cm_object_get_child_by_name(state->f0.reg.f1r2, "FB29");
	state->f0.fld.f1r2.fb30 = cm_object_get_child_by_name(state->f0.reg.f1r2, "FB30");
	state->f0.fld.f1r2.fb31 = cm_object_get_child_by_name(state->f0.reg.f1r2, "FB31");

	// F2R1 bitfields.
	state->f0.fld.f2r1.fb0 = cm_object_get_child_by_name(state->f0.reg.f2r1, "FB0");
	state->f0.fld.f2r1.fb1 = cm_object_get_child_by_name(state->f0.reg.f2r1, "FB1");
	state->f0.fld.f2r1.fb2 = cm_object_get_child_by_name(state->f0.reg.f2r1, "FB2");
	state->f0.fld.f2r1.fb3 = cm_object_get_child_by_name(state->f0.reg.f2r1, "FB3");
	state->f0.fld.f2r1.fb4 = cm_object_get_child_by_name(state->f0.reg.f2r1, "FB4");
	state->f0.fld.f2r1.fb5 = cm_object_get_child_by_name(state->f0.reg.f2r1, "FB5");
	state->f0.fld.f2r1.fb6 = cm_object_get_child_by_name(state->f0.reg.f2r1, "FB6");
	state->f0.fld.f2r1.fb7 = cm_object_get_child_by_name(state->f0.reg.f2r1, "FB7");
	state->f0.fld.f2r1.fb8 = cm_object_get_child_by_name(state->f0.reg.f2r1, "FB8");
	state->f0.fld.f2r1.fb9 = cm_object_get_child_by_name(state->f0.reg.f2r1, "FB9");
	state->f0.fld.f2r1.fb10 = cm_object_get_child_by_name(state->f0.reg.f2r1, "FB10");
	state->f0.fld.f2r1.fb11 = cm_object_get_child_by_name(state->f0.reg.f2r1, "FB11");
	state->f0.fld.f2r1.fb12 = cm_object_get_child_by_name(state->f0.reg.f2r1, "FB12");
	state->f0.fld.f2r1.fb13 = cm_object_get_child_by_name(state->f0.reg.f2r1, "FB13");
	state->f0.fld.f2r1.fb14 = cm_object_get_child_by_name(state->f0.reg.f2r1, "FB14");
	state->f0.fld.f2r1.fb15 = cm_object_get_child_by_name(state->f0.reg.f2r1, "FB15");
	state->f0.fld.f2r1.fb16 = cm_object_get_child_by_name(state->f0.reg.f2r1, "FB16");
	state->f0.fld.f2r1.fb17 = cm_object_get_child_by_name(state->f0.reg.f2r1, "FB17");
	state->f0.fld.f2r1.fb18 = cm_object_get_child_by_name(state->f0.reg.f2r1, "FB18");
	state->f0.fld.f2r1.fb19 = cm_object_get_child_by_name(state->f0.reg.f2r1, "FB19");
	state->f0.fld.f2r1.fb20 = cm_object_get_child_by_name(state->f0.reg.f2r1, "FB20");
	state->f0.fld.f2r1.fb21 = cm_object_get_child_by_name(state->f0.reg.f2r1, "FB21");
	state->f0.fld.f2r1.fb22 = cm_object_get_child_by_name(state->f0.reg.f2r1, "FB22");
	state->f0.fld.f2r1.fb23 = cm_object_get_child_by_name(state->f0.reg.f2r1, "FB23");
	state->f0.fld.f2r1.fb24 = cm_object_get_child_by_name(state->f0.reg.f2r1, "FB24");
	state->f0.fld.f2r1.fb25 = cm_object_get_child_by_name(state->f0.reg.f2r1, "FB25");
	state->f0.fld.f2r1.fb26 = cm_object_get_child_by_name(state->f0.reg.f2r1, "FB26");
	state->f0.fld.f2r1.fb27 = cm_object_get_child_by_name(state->f0.reg.f2r1, "FB27");
	state->f0.fld.f2r1.fb28 = cm_object_get_child_by_name(state->f0.reg.f2r1, "FB28");
	state->f0.fld.f2r1.fb29 = cm_object_get_child_by_name(state->f0.reg.f2r1, "FB29");
	state->f0.fld.f2r1.fb30 = cm_object_get_child_by_name(state->f0.reg.f2r1, "FB30");
	state->f0.fld.f2r1.fb31 = cm_object_get_child_by_name(state->f0.reg.f2r1, "FB31");

	// F2R2 bitfields.
	state->f0.fld.f2r2.fb0 = cm_object_get_child_by_name(state->f0.reg.f2r2, "FB0");
	state->f0.fld.f2r2.fb1 = cm_object_get_child_by_name(state->f0.reg.f2r2, "FB1");
	state->f0.fld.f2r2.fb2 = cm_object_get_child_by_name(state->f0.reg.f2r2, "FB2");
	state->f0.fld.f2r2.fb3 = cm_object_get_child_by_name(state->f0.reg.f2r2, "FB3");
	state->f0.fld.f2r2.fb4 = cm_object_get_child_by_name(state->f0.reg.f2r2, "FB4");
	state->f0.fld.f2r2.fb5 = cm_object_get_child_by_name(state->f0.reg.f2r2, "FB5");
	state->f0.fld.f2r2.fb6 = cm_object_get_child_by_name(state->f0.reg.f2r2, "FB6");
	state->f0.fld.f2r2.fb7 = cm_object_get_child_by_name(state->f0.reg.f2r2, "FB7");
	state->f0.fld.f2r2.fb8 = cm_object_get_child_by_name(state->f0.reg.f2r2, "FB8");
	state->f0.fld.f2r2.fb9 = cm_object_get_child_by_name(state->f0.reg.f2r2, "FB9");
	state->f0.fld.f2r2.fb10 = cm_object_get_child_by_name(state->f0.reg.f2r2, "FB10");
	state->f0.fld.f2r2.fb11 = cm_object_get_child_by_name(state->f0.reg.f2r2, "FB11");
	state->f0.fld.f2r2.fb12 = cm_object_get_child_by_name(state->f0.reg.f2r2, "FB12");
	state->f0.fld.f2r2.fb13 = cm_object_get_child_by_name(state->f0.reg.f2r2, "FB13");
	state->f0.fld.f2r2.fb14 = cm_object_get_child_by_name(state->f0.reg.f2r2, "FB14");
	state->f0.fld.f2r2.fb15 = cm_object_get_child_by_name(state->f0.reg.f2r2, "FB15");
	state->f0.fld.f2r2.fb16 = cm_object_get_child_by_name(state->f0.reg.f2r2, "FB16");
	state->f0.fld.f2r2.fb17 = cm_object_get_child_by_name(state->f0.reg.f2r2, "FB17");
	state->f0.fld.f2r2.fb18 = cm_object_get_child_by_name(state->f0.reg.f2r2, "FB18");
	state->f0.fld.f2r2.fb19 = cm_object_get_child_by_name(state->f0.reg.f2r2, "FB19");
	state->f0.fld.f2r2.fb20 = cm_object_get_child_by_name(state->f0.reg.f2r2, "FB20");
	state->f0.fld.f2r2.fb21 = cm_object_get_child_by_name(state->f0.reg.f2r2, "FB21");
	state->f0.fld.f2r2.fb22 = cm_object_get_child_by_name(state->f0.reg.f2r2, "FB22");
	state->f0.fld.f2r2.fb23 = cm_object_get_child_by_name(state->f0.reg.f2r2, "FB23");
	state->f0.fld.f2r2.fb24 = cm_object_get_child_by_name(state->f0.reg.f2r2, "FB24");
	state->f0.fld.f2r2.fb25 = cm_object_get_child_by_name(state->f0.reg.f2r2, "FB25");
	state->f0.fld.f2r2.fb26 = cm_object_get_child_by_name(state->f0.reg.f2r2, "FB26");
	state->f0.fld.f2r2.fb27 = cm_object_get_child_by_name(state->f0.reg.f2r2, "FB27");
	state->f0.fld.f2r2.fb28 = cm_object_get_child_by_name(state->f0.reg.f2r2, "FB28");
	state->f0.fld.f2r2.fb29 = cm_object_get_child_by_name(state->f0.reg.f2r2, "FB29");
	state->f0.fld.f2r2.fb30 = cm_object_get_child_by_name(state->f0.reg.f2r2, "FB30");
	state->f0.fld.f2r2.fb31 = cm_object_get_child_by_name(state->f0.reg.f2r2, "FB31");

	// F3R1 bitfields.
	state->f0.fld.f3r1.fb0 = cm_object_get_child_by_name(state->f0.reg.f3r1, "FB0");
	state->f0.fld.f3r1.fb1 = cm_object_get_child_by_name(state->f0.reg.f3r1, "FB1");
	state->f0.fld.f3r1.fb2 = cm_object_get_child_by_name(state->f0.reg.f3r1, "FB2");
	state->f0.fld.f3r1.fb3 = cm_object_get_child_by_name(state->f0.reg.f3r1, "FB3");
	state->f0.fld.f3r1.fb4 = cm_object_get_child_by_name(state->f0.reg.f3r1, "FB4");
	state->f0.fld.f3r1.fb5 = cm_object_get_child_by_name(state->f0.reg.f3r1, "FB5");
	state->f0.fld.f3r1.fb6 = cm_object_get_child_by_name(state->f0.reg.f3r1, "FB6");
	state->f0.fld.f3r1.fb7 = cm_object_get_child_by_name(state->f0.reg.f3r1, "FB7");
	state->f0.fld.f3r1.fb8 = cm_object_get_child_by_name(state->f0.reg.f3r1, "FB8");
	state->f0.fld.f3r1.fb9 = cm_object_get_child_by_name(state->f0.reg.f3r1, "FB9");
	state->f0.fld.f3r1.fb10 = cm_object_get_child_by_name(state->f0.reg.f3r1, "FB10");
	state->f0.fld.f3r1.fb11 = cm_object_get_child_by_name(state->f0.reg.f3r1, "FB11");
	state->f0.fld.f3r1.fb12 = cm_object_get_child_by_name(state->f0.reg.f3r1, "FB12");
	state->f0.fld.f3r1.fb13 = cm_object_get_child_by_name(state->f0.reg.f3r1, "FB13");
	state->f0.fld.f3r1.fb14 = cm_object_get_child_by_name(state->f0.reg.f3r1, "FB14");
	state->f0.fld.f3r1.fb15 = cm_object_get_child_by_name(state->f0.reg.f3r1, "FB15");
	state->f0.fld.f3r1.fb16 = cm_object_get_child_by_name(state->f0.reg.f3r1, "FB16");
	state->f0.fld.f3r1.fb17 = cm_object_get_child_by_name(state->f0.reg.f3r1, "FB17");
	state->f0.fld.f3r1.fb18 = cm_object_get_child_by_name(state->f0.reg.f3r1, "FB18");
	state->f0.fld.f3r1.fb19 = cm_object_get_child_by_name(state->f0.reg.f3r1, "FB19");
	state->f0.fld.f3r1.fb20 = cm_object_get_child_by_name(state->f0.reg.f3r1, "FB20");
	state->f0.fld.f3r1.fb21 = cm_object_get_child_by_name(state->f0.reg.f3r1, "FB21");
	state->f0.fld.f3r1.fb22 = cm_object_get_child_by_name(state->f0.reg.f3r1, "FB22");
	state->f0.fld.f3r1.fb23 = cm_object_get_child_by_name(state->f0.reg.f3r1, "FB23");
	state->f0.fld.f3r1.fb24 = cm_object_get_child_by_name(state->f0.reg.f3r1, "FB24");
	state->f0.fld.f3r1.fb25 = cm_object_get_child_by_name(state->f0.reg.f3r1, "FB25");
	state->f0.fld.f3r1.fb26 = cm_object_get_child_by_name(state->f0.reg.f3r1, "FB26");
	state->f0.fld.f3r1.fb27 = cm_object_get_child_by_name(state->f0.reg.f3r1, "FB27");
	state->f0.fld.f3r1.fb28 = cm_object_get_child_by_name(state->f0.reg.f3r1, "FB28");
	state->f0.fld.f3r1.fb29 = cm_object_get_child_by_name(state->f0.reg.f3r1, "FB29");
	state->f0.fld.f3r1.fb30 = cm_object_get_child_by_name(state->f0.reg.f3r1, "FB30");
	state->f0.fld.f3r1.fb31 = cm_object_get_child_by_name(state->f0.reg.f3r1, "FB31");

	// F3R2 bitfields.
	state->f0.fld.f3r2.fb0 = cm_object_get_child_by_name(state->f0.reg.f3r2, "FB0");
	state->f0.fld.f3r2.fb1 = cm_object_get_child_by_name(state->f0.reg.f3r2, "FB1");
	state->f0.fld.f3r2.fb2 = cm_object_get_child_by_name(state->f0.reg.f3r2, "FB2");
	state->f0.fld.f3r2.fb3 = cm_object_get_child_by_name(state->f0.reg.f3r2, "FB3");
	state->f0.fld.f3r2.fb4 = cm_object_get_child_by_name(state->f0.reg.f3r2, "FB4");
	state->f0.fld.f3r2.fb5 = cm_object_get_child_by_name(state->f0.reg.f3r2, "FB5");
	state->f0.fld.f3r2.fb6 = cm_object_get_child_by_name(state->f0.reg.f3r2, "FB6");
	state->f0.fld.f3r2.fb7 = cm_object_get_child_by_name(state->f0.reg.f3r2, "FB7");
	state->f0.fld.f3r2.fb8 = cm_object_get_child_by_name(state->f0.reg.f3r2, "FB8");
	state->f0.fld.f3r2.fb9 = cm_object_get_child_by_name(state->f0.reg.f3r2, "FB9");
	state->f0.fld.f3r2.fb10 = cm_object_get_child_by_name(state->f0.reg.f3r2, "FB10");
	state->f0.fld.f3r2.fb11 = cm_object_get_child_by_name(state->f0.reg.f3r2, "FB11");
	state->f0.fld.f3r2.fb12 = cm_object_get_child_by_name(state->f0.reg.f3r2, "FB12");
	state->f0.fld.f3r2.fb13 = cm_object_get_child_by_name(state->f0.reg.f3r2, "FB13");
	state->f0.fld.f3r2.fb14 = cm_object_get_child_by_name(state->f0.reg.f3r2, "FB14");
	state->f0.fld.f3r2.fb15 = cm_object_get_child_by_name(state->f0.reg.f3r2, "FB15");
	state->f0.fld.f3r2.fb16 = cm_object_get_child_by_name(state->f0.reg.f3r2, "FB16");
	state->f0.fld.f3r2.fb17 = cm_object_get_child_by_name(state->f0.reg.f3r2, "FB17");
	state->f0.fld.f3r2.fb18 = cm_object_get_child_by_name(state->f0.reg.f3r2, "FB18");
	state->f0.fld.f3r2.fb19 = cm_object_get_child_by_name(state->f0.reg.f3r2, "FB19");
	state->f0.fld.f3r2.fb20 = cm_object_get_child_by_name(state->f0.reg.f3r2, "FB20");
	state->f0.fld.f3r2.fb21 = cm_object_get_child_by_name(state->f0.reg.f3r2, "FB21");
	state->f0.fld.f3r2.fb22 = cm_object_get_child_by_name(state->f0.reg.f3r2, "FB22");
	state->f0.fld.f3r2.fb23 = cm_object_get_child_by_name(state->f0.reg.f3r2, "FB23");
	state->f0.fld.f3r2.fb24 = cm_object_get_child_by_name(state->f0.reg.f3r2, "FB24");
	state->f0.fld.f3r2.fb25 = cm_object_get_child_by_name(state->f0.reg.f3r2, "FB25");
	state->f0.fld.f3r2.fb26 = cm_object_get_child_by_name(state->f0.reg.f3r2, "FB26");
	state->f0.fld.f3r2.fb27 = cm_object_get_child_by_name(state->f0.reg.f3r2, "FB27");
	state->f0.fld.f3r2.fb28 = cm_object_get_child_by_name(state->f0.reg.f3r2, "FB28");
	state->f0.fld.f3r2.fb29 = cm_object_get_child_by_name(state->f0.reg.f3r2, "FB29");
	state->f0.fld.f3r2.fb30 = cm_object_get_child_by_name(state->f0.reg.f3r2, "FB30");
	state->f0.fld.f3r2.fb31 = cm_object_get_child_by_name(state->f0.reg.f3r2, "FB31");

	// F4R1 bitfields.
	state->f0.fld.f4r1.fb0 = cm_object_get_child_by_name(state->f0.reg.f4r1, "FB0");
	state->f0.fld.f4r1.fb1 = cm_object_get_child_by_name(state->f0.reg.f4r1, "FB1");
	state->f0.fld.f4r1.fb2 = cm_object_get_child_by_name(state->f0.reg.f4r1, "FB2");
	state->f0.fld.f4r1.fb3 = cm_object_get_child_by_name(state->f0.reg.f4r1, "FB3");
	state->f0.fld.f4r1.fb4 = cm_object_get_child_by_name(state->f0.reg.f4r1, "FB4");
	state->f0.fld.f4r1.fb5 = cm_object_get_child_by_name(state->f0.reg.f4r1, "FB5");
	state->f0.fld.f4r1.fb6 = cm_object_get_child_by_name(state->f0.reg.f4r1, "FB6");
	state->f0.fld.f4r1.fb7 = cm_object_get_child_by_name(state->f0.reg.f4r1, "FB7");
	state->f0.fld.f4r1.fb8 = cm_object_get_child_by_name(state->f0.reg.f4r1, "FB8");
	state->f0.fld.f4r1.fb9 = cm_object_get_child_by_name(state->f0.reg.f4r1, "FB9");
	state->f0.fld.f4r1.fb10 = cm_object_get_child_by_name(state->f0.reg.f4r1, "FB10");
	state->f0.fld.f4r1.fb11 = cm_object_get_child_by_name(state->f0.reg.f4r1, "FB11");
	state->f0.fld.f4r1.fb12 = cm_object_get_child_by_name(state->f0.reg.f4r1, "FB12");
	state->f0.fld.f4r1.fb13 = cm_object_get_child_by_name(state->f0.reg.f4r1, "FB13");
	state->f0.fld.f4r1.fb14 = cm_object_get_child_by_name(state->f0.reg.f4r1, "FB14");
	state->f0.fld.f4r1.fb15 = cm_object_get_child_by_name(state->f0.reg.f4r1, "FB15");
	state->f0.fld.f4r1.fb16 = cm_object_get_child_by_name(state->f0.reg.f4r1, "FB16");
	state->f0.fld.f4r1.fb17 = cm_object_get_child_by_name(state->f0.reg.f4r1, "FB17");
	state->f0.fld.f4r1.fb18 = cm_object_get_child_by_name(state->f0.reg.f4r1, "FB18");
	state->f0.fld.f4r1.fb19 = cm_object_get_child_by_name(state->f0.reg.f4r1, "FB19");
	state->f0.fld.f4r1.fb20 = cm_object_get_child_by_name(state->f0.reg.f4r1, "FB20");
	state->f0.fld.f4r1.fb21 = cm_object_get_child_by_name(state->f0.reg.f4r1, "FB21");
	state->f0.fld.f4r1.fb22 = cm_object_get_child_by_name(state->f0.reg.f4r1, "FB22");
	state->f0.fld.f4r1.fb23 = cm_object_get_child_by_name(state->f0.reg.f4r1, "FB23");
	state->f0.fld.f4r1.fb24 = cm_object_get_child_by_name(state->f0.reg.f4r1, "FB24");
	state->f0.fld.f4r1.fb25 = cm_object_get_child_by_name(state->f0.reg.f4r1, "FB25");
	state->f0.fld.f4r1.fb26 = cm_object_get_child_by_name(state->f0.reg.f4r1, "FB26");
	state->f0.fld.f4r1.fb27 = cm_object_get_child_by_name(state->f0.reg.f4r1, "FB27");
	state->f0.fld.f4r1.fb28 = cm_object_get_child_by_name(state->f0.reg.f4r1, "FB28");
	state->f0.fld.f4r1.fb29 = cm_object_get_child_by_name(state->f0.reg.f4r1, "FB29");
	state->f0.fld.f4r1.fb30 = cm_object_get_child_by_name(state->f0.reg.f4r1, "FB30");
	state->f0.fld.f4r1.fb31 = cm_object_get_child_by_name(state->f0.reg.f4r1, "FB31");

	// F4R2 bitfields.
	state->f0.fld.f4r2.fb0 = cm_object_get_child_by_name(state->f0.reg.f4r2, "FB0");
	state->f0.fld.f4r2.fb1 = cm_object_get_child_by_name(state->f0.reg.f4r2, "FB1");
	state->f0.fld.f4r2.fb2 = cm_object_get_child_by_name(state->f0.reg.f4r2, "FB2");
	state->f0.fld.f4r2.fb3 = cm_object_get_child_by_name(state->f0.reg.f4r2, "FB3");
	state->f0.fld.f4r2.fb4 = cm_object_get_child_by_name(state->f0.reg.f4r2, "FB4");
	state->f0.fld.f4r2.fb5 = cm_object_get_child_by_name(state->f0.reg.f4r2, "FB5");
	state->f0.fld.f4r2.fb6 = cm_object_get_child_by_name(state->f0.reg.f4r2, "FB6");
	state->f0.fld.f4r2.fb7 = cm_object_get_child_by_name(state->f0.reg.f4r2, "FB7");
	state->f0.fld.f4r2.fb8 = cm_object_get_child_by_name(state->f0.reg.f4r2, "FB8");
	state->f0.fld.f4r2.fb9 = cm_object_get_child_by_name(state->f0.reg.f4r2, "FB9");
	state->f0.fld.f4r2.fb10 = cm_object_get_child_by_name(state->f0.reg.f4r2, "FB10");
	state->f0.fld.f4r2.fb11 = cm_object_get_child_by_name(state->f0.reg.f4r2, "FB11");
	state->f0.fld.f4r2.fb12 = cm_object_get_child_by_name(state->f0.reg.f4r2, "FB12");
	state->f0.fld.f4r2.fb13 = cm_object_get_child_by_name(state->f0.reg.f4r2, "FB13");
	state->f0.fld.f4r2.fb14 = cm_object_get_child_by_name(state->f0.reg.f4r2, "FB14");
	state->f0.fld.f4r2.fb15 = cm_object_get_child_by_name(state->f0.reg.f4r2, "FB15");
	state->f0.fld.f4r2.fb16 = cm_object_get_child_by_name(state->f0.reg.f4r2, "FB16");
	state->f0.fld.f4r2.fb17 = cm_object_get_child_by_name(state->f0.reg.f4r2, "FB17");
	state->f0.fld.f4r2.fb18 = cm_object_get_child_by_name(state->f0.reg.f4r2, "FB18");
	state->f0.fld.f4r2.fb19 = cm_object_get_child_by_name(state->f0.reg.f4r2, "FB19");
	state->f0.fld.f4r2.fb20 = cm_object_get_child_by_name(state->f0.reg.f4r2, "FB20");
	state->f0.fld.f4r2.fb21 = cm_object_get_child_by_name(state->f0.reg.f4r2, "FB21");
	state->f0.fld.f4r2.fb22 = cm_object_get_child_by_name(state->f0.reg.f4r2, "FB22");
	state->f0.fld.f4r2.fb23 = cm_object_get_child_by_name(state->f0.reg.f4r2, "FB23");
	state->f0.fld.f4r2.fb24 = cm_object_get_child_by_name(state->f0.reg.f4r2, "FB24");
	state->f0.fld.f4r2.fb25 = cm_object_get_child_by_name(state->f0.reg.f4r2, "FB25");
	state->f0.fld.f4r2.fb26 = cm_object_get_child_by_name(state->f0.reg.f4r2, "FB26");
	state->f0.fld.f4r2.fb27 = cm_object_get_child_by_name(state->f0.reg.f4r2, "FB27");
	state->f0.fld.f4r2.fb28 = cm_object_get_child_by_name(state->f0.reg.f4r2, "FB28");
	state->f0.fld.f4r2.fb29 = cm_object_get_child_by_name(state->f0.reg.f4r2, "FB29");
	state->f0.fld.f4r2.fb30 = cm_object_get_child_by_name(state->f0.reg.f4r2, "FB30");
	state->f0.fld.f4r2.fb31 = cm_object_get_child_by_name(state->f0.reg.f4r2, "FB31");

	// F5R1 bitfields.
	state->f0.fld.f5r1.fb0 = cm_object_get_child_by_name(state->f0.reg.f5r1, "FB0");
	state->f0.fld.f5r1.fb1 = cm_object_get_child_by_name(state->f0.reg.f5r1, "FB1");
	state->f0.fld.f5r1.fb2 = cm_object_get_child_by_name(state->f0.reg.f5r1, "FB2");
	state->f0.fld.f5r1.fb3 = cm_object_get_child_by_name(state->f0.reg.f5r1, "FB3");
	state->f0.fld.f5r1.fb4 = cm_object_get_child_by_name(state->f0.reg.f5r1, "FB4");
	state->f0.fld.f5r1.fb5 = cm_object_get_child_by_name(state->f0.reg.f5r1, "FB5");
	state->f0.fld.f5r1.fb6 = cm_object_get_child_by_name(state->f0.reg.f5r1, "FB6");
	state->f0.fld.f5r1.fb7 = cm_object_get_child_by_name(state->f0.reg.f5r1, "FB7");
	state->f0.fld.f5r1.fb8 = cm_object_get_child_by_name(state->f0.reg.f5r1, "FB8");
	state->f0.fld.f5r1.fb9 = cm_object_get_child_by_name(state->f0.reg.f5r1, "FB9");
	state->f0.fld.f5r1.fb10 = cm_object_get_child_by_name(state->f0.reg.f5r1, "FB10");
	state->f0.fld.f5r1.fb11 = cm_object_get_child_by_name(state->f0.reg.f5r1, "FB11");
	state->f0.fld.f5r1.fb12 = cm_object_get_child_by_name(state->f0.reg.f5r1, "FB12");
	state->f0.fld.f5r1.fb13 = cm_object_get_child_by_name(state->f0.reg.f5r1, "FB13");
	state->f0.fld.f5r1.fb14 = cm_object_get_child_by_name(state->f0.reg.f5r1, "FB14");
	state->f0.fld.f5r1.fb15 = cm_object_get_child_by_name(state->f0.reg.f5r1, "FB15");
	state->f0.fld.f5r1.fb16 = cm_object_get_child_by_name(state->f0.reg.f5r1, "FB16");
	state->f0.fld.f5r1.fb17 = cm_object_get_child_by_name(state->f0.reg.f5r1, "FB17");
	state->f0.fld.f5r1.fb18 = cm_object_get_child_by_name(state->f0.reg.f5r1, "FB18");
	state->f0.fld.f5r1.fb19 = cm_object_get_child_by_name(state->f0.reg.f5r1, "FB19");
	state->f0.fld.f5r1.fb20 = cm_object_get_child_by_name(state->f0.reg.f5r1, "FB20");
	state->f0.fld.f5r1.fb21 = cm_object_get_child_by_name(state->f0.reg.f5r1, "FB21");
	state->f0.fld.f5r1.fb22 = cm_object_get_child_by_name(state->f0.reg.f5r1, "FB22");
	state->f0.fld.f5r1.fb23 = cm_object_get_child_by_name(state->f0.reg.f5r1, "FB23");
	state->f0.fld.f5r1.fb24 = cm_object_get_child_by_name(state->f0.reg.f5r1, "FB24");
	state->f0.fld.f5r1.fb25 = cm_object_get_child_by_name(state->f0.reg.f5r1, "FB25");
	state->f0.fld.f5r1.fb26 = cm_object_get_child_by_name(state->f0.reg.f5r1, "FB26");
	state->f0.fld.f5r1.fb27 = cm_object_get_child_by_name(state->f0.reg.f5r1, "FB27");
	state->f0.fld.f5r1.fb28 = cm_object_get_child_by_name(state->f0.reg.f5r1, "FB28");
	state->f0.fld.f5r1.fb29 = cm_object_get_child_by_name(state->f0.reg.f5r1, "FB29");
	state->f0.fld.f5r1.fb30 = cm_object_get_child_by_name(state->f0.reg.f5r1, "FB30");
	state->f0.fld.f5r1.fb31 = cm_object_get_child_by_name(state->f0.reg.f5r1, "FB31");

	// F5R2 bitfields.
	state->f0.fld.f5r2.fb0 = cm_object_get_child_by_name(state->f0.reg.f5r2, "FB0");
	state->f0.fld.f5r2.fb1 = cm_object_get_child_by_name(state->f0.reg.f5r2, "FB1");
	state->f0.fld.f5r2.fb2 = cm_object_get_child_by_name(state->f0.reg.f5r2, "FB2");
	state->f0.fld.f5r2.fb3 = cm_object_get_child_by_name(state->f0.reg.f5r2, "FB3");
	state->f0.fld.f5r2.fb4 = cm_object_get_child_by_name(state->f0.reg.f5r2, "FB4");
	state->f0.fld.f5r2.fb5 = cm_object_get_child_by_name(state->f0.reg.f5r2, "FB5");
	state->f0.fld.f5r2.fb6 = cm_object_get_child_by_name(state->f0.reg.f5r2, "FB6");
	state->f0.fld.f5r2.fb7 = cm_object_get_child_by_name(state->f0.reg.f5r2, "FB7");
	state->f0.fld.f5r2.fb8 = cm_object_get_child_by_name(state->f0.reg.f5r2, "FB8");
	state->f0.fld.f5r2.fb9 = cm_object_get_child_by_name(state->f0.reg.f5r2, "FB9");
	state->f0.fld.f5r2.fb10 = cm_object_get_child_by_name(state->f0.reg.f5r2, "FB10");
	state->f0.fld.f5r2.fb11 = cm_object_get_child_by_name(state->f0.reg.f5r2, "FB11");
	state->f0.fld.f5r2.fb12 = cm_object_get_child_by_name(state->f0.reg.f5r2, "FB12");
	state->f0.fld.f5r2.fb13 = cm_object_get_child_by_name(state->f0.reg.f5r2, "FB13");
	state->f0.fld.f5r2.fb14 = cm_object_get_child_by_name(state->f0.reg.f5r2, "FB14");
	state->f0.fld.f5r2.fb15 = cm_object_get_child_by_name(state->f0.reg.f5r2, "FB15");
	state->f0.fld.f5r2.fb16 = cm_object_get_child_by_name(state->f0.reg.f5r2, "FB16");
	state->f0.fld.f5r2.fb17 = cm_object_get_child_by_name(state->f0.reg.f5r2, "FB17");
	state->f0.fld.f5r2.fb18 = cm_object_get_child_by_name(state->f0.reg.f5r2, "FB18");
	state->f0.fld.f5r2.fb19 = cm_object_get_child_by_name(state->f0.reg.f5r2, "FB19");
	state->f0.fld.f5r2.fb20 = cm_object_get_child_by_name(state->f0.reg.f5r2, "FB20");
	state->f0.fld.f5r2.fb21 = cm_object_get_child_by_name(state->f0.reg.f5r2, "FB21");
	state->f0.fld.f5r2.fb22 = cm_object_get_child_by_name(state->f0.reg.f5r2, "FB22");
	state->f0.fld.f5r2.fb23 = cm_object_get_child_by_name(state->f0.reg.f5r2, "FB23");
	state->f0.fld.f5r2.fb24 = cm_object_get_child_by_name(state->f0.reg.f5r2, "FB24");
	state->f0.fld.f5r2.fb25 = cm_object_get_child_by_name(state->f0.reg.f5r2, "FB25");
	state->f0.fld.f5r2.fb26 = cm_object_get_child_by_name(state->f0.reg.f5r2, "FB26");
	state->f0.fld.f5r2.fb27 = cm_object_get_child_by_name(state->f0.reg.f5r2, "FB27");
	state->f0.fld.f5r2.fb28 = cm_object_get_child_by_name(state->f0.reg.f5r2, "FB28");
	state->f0.fld.f5r2.fb29 = cm_object_get_child_by_name(state->f0.reg.f5r2, "FB29");
	state->f0.fld.f5r2.fb30 = cm_object_get_child_by_name(state->f0.reg.f5r2, "FB30");
	state->f0.fld.f5r2.fb31 = cm_object_get_child_by_name(state->f0.reg.f5r2, "FB31");

	// F6R1 bitfields.
	state->f0.fld.f6r1.fb0 = cm_object_get_child_by_name(state->f0.reg.f6r1, "FB0");
	state->f0.fld.f6r1.fb1 = cm_object_get_child_by_name(state->f0.reg.f6r1, "FB1");
	state->f0.fld.f6r1.fb2 = cm_object_get_child_by_name(state->f0.reg.f6r1, "FB2");
	state->f0.fld.f6r1.fb3 = cm_object_get_child_by_name(state->f0.reg.f6r1, "FB3");
	state->f0.fld.f6r1.fb4 = cm_object_get_child_by_name(state->f0.reg.f6r1, "FB4");
	state->f0.fld.f6r1.fb5 = cm_object_get_child_by_name(state->f0.reg.f6r1, "FB5");
	state->f0.fld.f6r1.fb6 = cm_object_get_child_by_name(state->f0.reg.f6r1, "FB6");
	state->f0.fld.f6r1.fb7 = cm_object_get_child_by_name(state->f0.reg.f6r1, "FB7");
	state->f0.fld.f6r1.fb8 = cm_object_get_child_by_name(state->f0.reg.f6r1, "FB8");
	state->f0.fld.f6r1.fb9 = cm_object_get_child_by_name(state->f0.reg.f6r1, "FB9");
	state->f0.fld.f6r1.fb10 = cm_object_get_child_by_name(state->f0.reg.f6r1, "FB10");
	state->f0.fld.f6r1.fb11 = cm_object_get_child_by_name(state->f0.reg.f6r1, "FB11");
	state->f0.fld.f6r1.fb12 = cm_object_get_child_by_name(state->f0.reg.f6r1, "FB12");
	state->f0.fld.f6r1.fb13 = cm_object_get_child_by_name(state->f0.reg.f6r1, "FB13");
	state->f0.fld.f6r1.fb14 = cm_object_get_child_by_name(state->f0.reg.f6r1, "FB14");
	state->f0.fld.f6r1.fb15 = cm_object_get_child_by_name(state->f0.reg.f6r1, "FB15");
	state->f0.fld.f6r1.fb16 = cm_object_get_child_by_name(state->f0.reg.f6r1, "FB16");
	state->f0.fld.f6r1.fb17 = cm_object_get_child_by_name(state->f0.reg.f6r1, "FB17");
	state->f0.fld.f6r1.fb18 = cm_object_get_child_by_name(state->f0.reg.f6r1, "FB18");
	state->f0.fld.f6r1.fb19 = cm_object_get_child_by_name(state->f0.reg.f6r1, "FB19");
	state->f0.fld.f6r1.fb20 = cm_object_get_child_by_name(state->f0.reg.f6r1, "FB20");
	state->f0.fld.f6r1.fb21 = cm_object_get_child_by_name(state->f0.reg.f6r1, "FB21");
	state->f0.fld.f6r1.fb22 = cm_object_get_child_by_name(state->f0.reg.f6r1, "FB22");
	state->f0.fld.f6r1.fb23 = cm_object_get_child_by_name(state->f0.reg.f6r1, "FB23");
	state->f0.fld.f6r1.fb24 = cm_object_get_child_by_name(state->f0.reg.f6r1, "FB24");
	state->f0.fld.f6r1.fb25 = cm_object_get_child_by_name(state->f0.reg.f6r1, "FB25");
	state->f0.fld.f6r1.fb26 = cm_object_get_child_by_name(state->f0.reg.f6r1, "FB26");
	state->f0.fld.f6r1.fb27 = cm_object_get_child_by_name(state->f0.reg.f6r1, "FB27");
	state->f0.fld.f6r1.fb28 = cm_object_get_child_by_name(state->f0.reg.f6r1, "FB28");
	state->f0.fld.f6r1.fb29 = cm_object_get_child_by_name(state->f0.reg.f6r1, "FB29");
	state->f0.fld.f6r1.fb30 = cm_object_get_child_by_name(state->f0.reg.f6r1, "FB30");
	state->f0.fld.f6r1.fb31 = cm_object_get_child_by_name(state->f0.reg.f6r1, "FB31");

	// F6R2 bitfields.
	state->f0.fld.f6r2.fb0 = cm_object_get_child_by_name(state->f0.reg.f6r2, "FB0");
	state->f0.fld.f6r2.fb1 = cm_object_get_child_by_name(state->f0.reg.f6r2, "FB1");
	state->f0.fld.f6r2.fb2 = cm_object_get_child_by_name(state->f0.reg.f6r2, "FB2");
	state->f0.fld.f6r2.fb3 = cm_object_get_child_by_name(state->f0.reg.f6r2, "FB3");
	state->f0.fld.f6r2.fb4 = cm_object_get_child_by_name(state->f0.reg.f6r2, "FB4");
	state->f0.fld.f6r2.fb5 = cm_object_get_child_by_name(state->f0.reg.f6r2, "FB5");
	state->f0.fld.f6r2.fb6 = cm_object_get_child_by_name(state->f0.reg.f6r2, "FB6");
	state->f0.fld.f6r2.fb7 = cm_object_get_child_by_name(state->f0.reg.f6r2, "FB7");
	state->f0.fld.f6r2.fb8 = cm_object_get_child_by_name(state->f0.reg.f6r2, "FB8");
	state->f0.fld.f6r2.fb9 = cm_object_get_child_by_name(state->f0.reg.f6r2, "FB9");
	state->f0.fld.f6r2.fb10 = cm_object_get_child_by_name(state->f0.reg.f6r2, "FB10");
	state->f0.fld.f6r2.fb11 = cm_object_get_child_by_name(state->f0.reg.f6r2, "FB11");
	state->f0.fld.f6r2.fb12 = cm_object_get_child_by_name(state->f0.reg.f6r2, "FB12");
	state->f0.fld.f6r2.fb13 = cm_object_get_child_by_name(state->f0.reg.f6r2, "FB13");
	state->f0.fld.f6r2.fb14 = cm_object_get_child_by_name(state->f0.reg.f6r2, "FB14");
	state->f0.fld.f6r2.fb15 = cm_object_get_child_by_name(state->f0.reg.f6r2, "FB15");
	state->f0.fld.f6r2.fb16 = cm_object_get_child_by_name(state->f0.reg.f6r2, "FB16");
	state->f0.fld.f6r2.fb17 = cm_object_get_child_by_name(state->f0.reg.f6r2, "FB17");
	state->f0.fld.f6r2.fb18 = cm_object_get_child_by_name(state->f0.reg.f6r2, "FB18");
	state->f0.fld.f6r2.fb19 = cm_object_get_child_by_name(state->f0.reg.f6r2, "FB19");
	state->f0.fld.f6r2.fb20 = cm_object_get_child_by_name(state->f0.reg.f6r2, "FB20");
	state->f0.fld.f6r2.fb21 = cm_object_get_child_by_name(state->f0.reg.f6r2, "FB21");
	state->f0.fld.f6r2.fb22 = cm_object_get_child_by_name(state->f0.reg.f6r2, "FB22");
	state->f0.fld.f6r2.fb23 = cm_object_get_child_by_name(state->f0.reg.f6r2, "FB23");
	state->f0.fld.f6r2.fb24 = cm_object_get_child_by_name(state->f0.reg.f6r2, "FB24");
	state->f0.fld.f6r2.fb25 = cm_object_get_child_by_name(state->f0.reg.f6r2, "FB25");
	state->f0.fld.f6r2.fb26 = cm_object_get_child_by_name(state->f0.reg.f6r2, "FB26");
	state->f0.fld.f6r2.fb27 = cm_object_get_child_by_name(state->f0.reg.f6r2, "FB27");
	state->f0.fld.f6r2.fb28 = cm_object_get_child_by_name(state->f0.reg.f6r2, "FB28");
	state->f0.fld.f6r2.fb29 = cm_object_get_child_by_name(state->f0.reg.f6r2, "FB29");
	state->f0.fld.f6r2.fb30 = cm_object_get_child_by_name(state->f0.reg.f6r2, "FB30");
	state->f0.fld.f6r2.fb31 = cm_object_get_child_by_name(state->f0.reg.f6r2, "FB31");

	// F7R1 bitfields.
	state->f0.fld.f7r1.fb0 = cm_object_get_child_by_name(state->f0.reg.f7r1, "FB0");
	state->f0.fld.f7r1.fb1 = cm_object_get_child_by_name(state->f0.reg.f7r1, "FB1");
	state->f0.fld.f7r1.fb2 = cm_object_get_child_by_name(state->f0.reg.f7r1, "FB2");
	state->f0.fld.f7r1.fb3 = cm_object_get_child_by_name(state->f0.reg.f7r1, "FB3");
	state->f0.fld.f7r1.fb4 = cm_object_get_child_by_name(state->f0.reg.f7r1, "FB4");
	state->f0.fld.f7r1.fb5 = cm_object_get_child_by_name(state->f0.reg.f7r1, "FB5");
	state->f0.fld.f7r1.fb6 = cm_object_get_child_by_name(state->f0.reg.f7r1, "FB6");
	state->f0.fld.f7r1.fb7 = cm_object_get_child_by_name(state->f0.reg.f7r1, "FB7");
	state->f0.fld.f7r1.fb8 = cm_object_get_child_by_name(state->f0.reg.f7r1, "FB8");
	state->f0.fld.f7r1.fb9 = cm_object_get_child_by_name(state->f0.reg.f7r1, "FB9");
	state->f0.fld.f7r1.fb10 = cm_object_get_child_by_name(state->f0.reg.f7r1, "FB10");
	state->f0.fld.f7r1.fb11 = cm_object_get_child_by_name(state->f0.reg.f7r1, "FB11");
	state->f0.fld.f7r1.fb12 = cm_object_get_child_by_name(state->f0.reg.f7r1, "FB12");
	state->f0.fld.f7r1.fb13 = cm_object_get_child_by_name(state->f0.reg.f7r1, "FB13");
	state->f0.fld.f7r1.fb14 = cm_object_get_child_by_name(state->f0.reg.f7r1, "FB14");
	state->f0.fld.f7r1.fb15 = cm_object_get_child_by_name(state->f0.reg.f7r1, "FB15");
	state->f0.fld.f7r1.fb16 = cm_object_get_child_by_name(state->f0.reg.f7r1, "FB16");
	state->f0.fld.f7r1.fb17 = cm_object_get_child_by_name(state->f0.reg.f7r1, "FB17");
	state->f0.fld.f7r1.fb18 = cm_object_get_child_by_name(state->f0.reg.f7r1, "FB18");
	state->f0.fld.f7r1.fb19 = cm_object_get_child_by_name(state->f0.reg.f7r1, "FB19");
	state->f0.fld.f7r1.fb20 = cm_object_get_child_by_name(state->f0.reg.f7r1, "FB20");
	state->f0.fld.f7r1.fb21 = cm_object_get_child_by_name(state->f0.reg.f7r1, "FB21");
	state->f0.fld.f7r1.fb22 = cm_object_get_child_by_name(state->f0.reg.f7r1, "FB22");
	state->f0.fld.f7r1.fb23 = cm_object_get_child_by_name(state->f0.reg.f7r1, "FB23");
	state->f0.fld.f7r1.fb24 = cm_object_get_child_by_name(state->f0.reg.f7r1, "FB24");
	state->f0.fld.f7r1.fb25 = cm_object_get_child_by_name(state->f0.reg.f7r1, "FB25");
	state->f0.fld.f7r1.fb26 = cm_object_get_child_by_name(state->f0.reg.f7r1, "FB26");
	state->f0.fld.f7r1.fb27 = cm_object_get_child_by_name(state->f0.reg.f7r1, "FB27");
	state->f0.fld.f7r1.fb28 = cm_object_get_child_by_name(state->f0.reg.f7r1, "FB28");
	state->f0.fld.f7r1.fb29 = cm_object_get_child_by_name(state->f0.reg.f7r1, "FB29");
	state->f0.fld.f7r1.fb30 = cm_object_get_child_by_name(state->f0.reg.f7r1, "FB30");
	state->f0.fld.f7r1.fb31 = cm_object_get_child_by_name(state->f0.reg.f7r1, "FB31");

	// F7R2 bitfields.
	state->f0.fld.f7r2.fb0 = cm_object_get_child_by_name(state->f0.reg.f7r2, "FB0");
	state->f0.fld.f7r2.fb1 = cm_object_get_child_by_name(state->f0.reg.f7r2, "FB1");
	state->f0.fld.f7r2.fb2 = cm_object_get_child_by_name(state->f0.reg.f7r2, "FB2");
	state->f0.fld.f7r2.fb3 = cm_object_get_child_by_name(state->f0.reg.f7r2, "FB3");
	state->f0.fld.f7r2.fb4 = cm_object_get_child_by_name(state->f0.reg.f7r2, "FB4");
	state->f0.fld.f7r2.fb5 = cm_object_get_child_by_name(state->f0.reg.f7r2, "FB5");
	state->f0.fld.f7r2.fb6 = cm_object_get_child_by_name(state->f0.reg.f7r2, "FB6");
	state->f0.fld.f7r2.fb7 = cm_object_get_child_by_name(state->f0.reg.f7r2, "FB7");
	state->f0.fld.f7r2.fb8 = cm_object_get_child_by_name(state->f0.reg.f7r2, "FB8");
	state->f0.fld.f7r2.fb9 = cm_object_get_child_by_name(state->f0.reg.f7r2, "FB9");
	state->f0.fld.f7r2.fb10 = cm_object_get_child_by_name(state->f0.reg.f7r2, "FB10");
	state->f0.fld.f7r2.fb11 = cm_object_get_child_by_name(state->f0.reg.f7r2, "FB11");
	state->f0.fld.f7r2.fb12 = cm_object_get_child_by_name(state->f0.reg.f7r2, "FB12");
	state->f0.fld.f7r2.fb13 = cm_object_get_child_by_name(state->f0.reg.f7r2, "FB13");
	state->f0.fld.f7r2.fb14 = cm_object_get_child_by_name(state->f0.reg.f7r2, "FB14");
	state->f0.fld.f7r2.fb15 = cm_object_get_child_by_name(state->f0.reg.f7r2, "FB15");
	state->f0.fld.f7r2.fb16 = cm_object_get_child_by_name(state->f0.reg.f7r2, "FB16");
	state->f0.fld.f7r2.fb17 = cm_object_get_child_by_name(state->f0.reg.f7r2, "FB17");
	state->f0.fld.f7r2.fb18 = cm_object_get_child_by_name(state->f0.reg.f7r2, "FB18");
	state->f0.fld.f7r2.fb19 = cm_object_get_child_by_name(state->f0.reg.f7r2, "FB19");
	state->f0.fld.f7r2.fb20 = cm_object_get_child_by_name(state->f0.reg.f7r2, "FB20");
	state->f0.fld.f7r2.fb21 = cm_object_get_child_by_name(state->f0.reg.f7r2, "FB21");
	state->f0.fld.f7r2.fb22 = cm_object_get_child_by_name(state->f0.reg.f7r2, "FB22");
	state->f0.fld.f7r2.fb23 = cm_object_get_child_by_name(state->f0.reg.f7r2, "FB23");
	state->f0.fld.f7r2.fb24 = cm_object_get_child_by_name(state->f0.reg.f7r2, "FB24");
	state->f0.fld.f7r2.fb25 = cm_object_get_child_by_name(state->f0.reg.f7r2, "FB25");
	state->f0.fld.f7r2.fb26 = cm_object_get_child_by_name(state->f0.reg.f7r2, "FB26");
	state->f0.fld.f7r2.fb27 = cm_object_get_child_by_name(state->f0.reg.f7r2, "FB27");
	state->f0.fld.f7r2.fb28 = cm_object_get_child_by_name(state->f0.reg.f7r2, "FB28");
	state->f0.fld.f7r2.fb29 = cm_object_get_child_by_name(state->f0.reg.f7r2, "FB29");
	state->f0.fld.f7r2.fb30 = cm_object_get_child_by_name(state->f0.reg.f7r2, "FB30");
	state->f0.fld.f7r2.fb31 = cm_object_get_child_by_name(state->f0.reg.f7r2, "FB31");

	// F8R1 bitfields.
	state->f0.fld.f8r1.fb0 = cm_object_get_child_by_name(state->f0.reg.f8r1, "FB0");
	state->f0.fld.f8r1.fb1 = cm_object_get_child_by_name(state->f0.reg.f8r1, "FB1");
	state->f0.fld.f8r1.fb2 = cm_object_get_child_by_name(state->f0.reg.f8r1, "FB2");
	state->f0.fld.f8r1.fb3 = cm_object_get_child_by_name(state->f0.reg.f8r1, "FB3");
	state->f0.fld.f8r1.fb4 = cm_object_get_child_by_name(state->f0.reg.f8r1, "FB4");
	state->f0.fld.f8r1.fb5 = cm_object_get_child_by_name(state->f0.reg.f8r1, "FB5");
	state->f0.fld.f8r1.fb6 = cm_object_get_child_by_name(state->f0.reg.f8r1, "FB6");
	state->f0.fld.f8r1.fb7 = cm_object_get_child_by_name(state->f0.reg.f8r1, "FB7");
	state->f0.fld.f8r1.fb8 = cm_object_get_child_by_name(state->f0.reg.f8r1, "FB8");
	state->f0.fld.f8r1.fb9 = cm_object_get_child_by_name(state->f0.reg.f8r1, "FB9");
	state->f0.fld.f8r1.fb10 = cm_object_get_child_by_name(state->f0.reg.f8r1, "FB10");
	state->f0.fld.f8r1.fb11 = cm_object_get_child_by_name(state->f0.reg.f8r1, "FB11");
	state->f0.fld.f8r1.fb12 = cm_object_get_child_by_name(state->f0.reg.f8r1, "FB12");
	state->f0.fld.f8r1.fb13 = cm_object_get_child_by_name(state->f0.reg.f8r1, "FB13");
	state->f0.fld.f8r1.fb14 = cm_object_get_child_by_name(state->f0.reg.f8r1, "FB14");
	state->f0.fld.f8r1.fb15 = cm_object_get_child_by_name(state->f0.reg.f8r1, "FB15");
	state->f0.fld.f8r1.fb16 = cm_object_get_child_by_name(state->f0.reg.f8r1, "FB16");
	state->f0.fld.f8r1.fb17 = cm_object_get_child_by_name(state->f0.reg.f8r1, "FB17");
	state->f0.fld.f8r1.fb18 = cm_object_get_child_by_name(state->f0.reg.f8r1, "FB18");
	state->f0.fld.f8r1.fb19 = cm_object_get_child_by_name(state->f0.reg.f8r1, "FB19");
	state->f0.fld.f8r1.fb20 = cm_object_get_child_by_name(state->f0.reg.f8r1, "FB20");
	state->f0.fld.f8r1.fb21 = cm_object_get_child_by_name(state->f0.reg.f8r1, "FB21");
	state->f0.fld.f8r1.fb22 = cm_object_get_child_by_name(state->f0.reg.f8r1, "FB22");
	state->f0.fld.f8r1.fb23 = cm_object_get_child_by_name(state->f0.reg.f8r1, "FB23");
	state->f0.fld.f8r1.fb24 = cm_object_get_child_by_name(state->f0.reg.f8r1, "FB24");
	state->f0.fld.f8r1.fb25 = cm_object_get_child_by_name(state->f0.reg.f8r1, "FB25");
	state->f0.fld.f8r1.fb26 = cm_object_get_child_by_name(state->f0.reg.f8r1, "FB26");
	state->f0.fld.f8r1.fb27 = cm_object_get_child_by_name(state->f0.reg.f8r1, "FB27");
	state->f0.fld.f8r1.fb28 = cm_object_get_child_by_name(state->f0.reg.f8r1, "FB28");
	state->f0.fld.f8r1.fb29 = cm_object_get_child_by_name(state->f0.reg.f8r1, "FB29");
	state->f0.fld.f8r1.fb30 = cm_object_get_child_by_name(state->f0.reg.f8r1, "FB30");
	state->f0.fld.f8r1.fb31 = cm_object_get_child_by_name(state->f0.reg.f8r1, "FB31");

	// F8R2 bitfields.
	state->f0.fld.f8r2.fb0 = cm_object_get_child_by_name(state->f0.reg.f8r2, "FB0");
	state->f0.fld.f8r2.fb1 = cm_object_get_child_by_name(state->f0.reg.f8r2, "FB1");
	state->f0.fld.f8r2.fb2 = cm_object_get_child_by_name(state->f0.reg.f8r2, "FB2");
	state->f0.fld.f8r2.fb3 = cm_object_get_child_by_name(state->f0.reg.f8r2, "FB3");
	state->f0.fld.f8r2.fb4 = cm_object_get_child_by_name(state->f0.reg.f8r2, "FB4");
	state->f0.fld.f8r2.fb5 = cm_object_get_child_by_name(state->f0.reg.f8r2, "FB5");
	state->f0.fld.f8r2.fb6 = cm_object_get_child_by_name(state->f0.reg.f8r2, "FB6");
	state->f0.fld.f8r2.fb7 = cm_object_get_child_by_name(state->f0.reg.f8r2, "FB7");
	state->f0.fld.f8r2.fb8 = cm_object_get_child_by_name(state->f0.reg.f8r2, "FB8");
	state->f0.fld.f8r2.fb9 = cm_object_get_child_by_name(state->f0.reg.f8r2, "FB9");
	state->f0.fld.f8r2.fb10 = cm_object_get_child_by_name(state->f0.reg.f8r2, "FB10");
	state->f0.fld.f8r2.fb11 = cm_object_get_child_by_name(state->f0.reg.f8r2, "FB11");
	state->f0.fld.f8r2.fb12 = cm_object_get_child_by_name(state->f0.reg.f8r2, "FB12");
	state->f0.fld.f8r2.fb13 = cm_object_get_child_by_name(state->f0.reg.f8r2, "FB13");
	state->f0.fld.f8r2.fb14 = cm_object_get_child_by_name(state->f0.reg.f8r2, "FB14");
	state->f0.fld.f8r2.fb15 = cm_object_get_child_by_name(state->f0.reg.f8r2, "FB15");
	state->f0.fld.f8r2.fb16 = cm_object_get_child_by_name(state->f0.reg.f8r2, "FB16");
	state->f0.fld.f8r2.fb17 = cm_object_get_child_by_name(state->f0.reg.f8r2, "FB17");
	state->f0.fld.f8r2.fb18 = cm_object_get_child_by_name(state->f0.reg.f8r2, "FB18");
	state->f0.fld.f8r2.fb19 = cm_object_get_child_by_name(state->f0.reg.f8r2, "FB19");
	state->f0.fld.f8r2.fb20 = cm_object_get_child_by_name(state->f0.reg.f8r2, "FB20");
	state->f0.fld.f8r2.fb21 = cm_object_get_child_by_name(state->f0.reg.f8r2, "FB21");
	state->f0.fld.f8r2.fb22 = cm_object_get_child_by_name(state->f0.reg.f8r2, "FB22");
	state->f0.fld.f8r2.fb23 = cm_object_get_child_by_name(state->f0.reg.f8r2, "FB23");
	state->f0.fld.f8r2.fb24 = cm_object_get_child_by_name(state->f0.reg.f8r2, "FB24");
	state->f0.fld.f8r2.fb25 = cm_object_get_child_by_name(state->f0.reg.f8r2, "FB25");
	state->f0.fld.f8r2.fb26 = cm_object_get_child_by_name(state->f0.reg.f8r2, "FB26");
	state->f0.fld.f8r2.fb27 = cm_object_get_child_by_name(state->f0.reg.f8r2, "FB27");
	state->f0.fld.f8r2.fb28 = cm_object_get_child_by_name(state->f0.reg.f8r2, "FB28");
	state->f0.fld.f8r2.fb29 = cm_object_get_child_by_name(state->f0.reg.f8r2, "FB29");
	state->f0.fld.f8r2.fb30 = cm_object_get_child_by_name(state->f0.reg.f8r2, "FB30");
	state->f0.fld.f8r2.fb31 = cm_object_get_child_by_name(state->f0.reg.f8r2, "FB31");

	// F9R1 bitfields.
	state->f0.fld.f9r1.fb0 = cm_object_get_child_by_name(state->f0.reg.f9r1, "FB0");
	state->f0.fld.f9r1.fb1 = cm_object_get_child_by_name(state->f0.reg.f9r1, "FB1");
	state->f0.fld.f9r1.fb2 = cm_object_get_child_by_name(state->f0.reg.f9r1, "FB2");
	state->f0.fld.f9r1.fb3 = cm_object_get_child_by_name(state->f0.reg.f9r1, "FB3");
	state->f0.fld.f9r1.fb4 = cm_object_get_child_by_name(state->f0.reg.f9r1, "FB4");
	state->f0.fld.f9r1.fb5 = cm_object_get_child_by_name(state->f0.reg.f9r1, "FB5");
	state->f0.fld.f9r1.fb6 = cm_object_get_child_by_name(state->f0.reg.f9r1, "FB6");
	state->f0.fld.f9r1.fb7 = cm_object_get_child_by_name(state->f0.reg.f9r1, "FB7");
	state->f0.fld.f9r1.fb8 = cm_object_get_child_by_name(state->f0.reg.f9r1, "FB8");
	state->f0.fld.f9r1.fb9 = cm_object_get_child_by_name(state->f0.reg.f9r1, "FB9");
	state->f0.fld.f9r1.fb10 = cm_object_get_child_by_name(state->f0.reg.f9r1, "FB10");
	state->f0.fld.f9r1.fb11 = cm_object_get_child_by_name(state->f0.reg.f9r1, "FB11");
	state->f0.fld.f9r1.fb12 = cm_object_get_child_by_name(state->f0.reg.f9r1, "FB12");
	state->f0.fld.f9r1.fb13 = cm_object_get_child_by_name(state->f0.reg.f9r1, "FB13");
	state->f0.fld.f9r1.fb14 = cm_object_get_child_by_name(state->f0.reg.f9r1, "FB14");
	state->f0.fld.f9r1.fb15 = cm_object_get_child_by_name(state->f0.reg.f9r1, "FB15");
	state->f0.fld.f9r1.fb16 = cm_object_get_child_by_name(state->f0.reg.f9r1, "FB16");
	state->f0.fld.f9r1.fb17 = cm_object_get_child_by_name(state->f0.reg.f9r1, "FB17");
	state->f0.fld.f9r1.fb18 = cm_object_get_child_by_name(state->f0.reg.f9r1, "FB18");
	state->f0.fld.f9r1.fb19 = cm_object_get_child_by_name(state->f0.reg.f9r1, "FB19");
	state->f0.fld.f9r1.fb20 = cm_object_get_child_by_name(state->f0.reg.f9r1, "FB20");
	state->f0.fld.f9r1.fb21 = cm_object_get_child_by_name(state->f0.reg.f9r1, "FB21");
	state->f0.fld.f9r1.fb22 = cm_object_get_child_by_name(state->f0.reg.f9r1, "FB22");
	state->f0.fld.f9r1.fb23 = cm_object_get_child_by_name(state->f0.reg.f9r1, "FB23");
	state->f0.fld.f9r1.fb24 = cm_object_get_child_by_name(state->f0.reg.f9r1, "FB24");
	state->f0.fld.f9r1.fb25 = cm_object_get_child_by_name(state->f0.reg.f9r1, "FB25");
	state->f0.fld.f9r1.fb26 = cm_object_get_child_by_name(state->f0.reg.f9r1, "FB26");
	state->f0.fld.f9r1.fb27 = cm_object_get_child_by_name(state->f0.reg.f9r1, "FB27");
	state->f0.fld.f9r1.fb28 = cm_object_get_child_by_name(state->f0.reg.f9r1, "FB28");
	state->f0.fld.f9r1.fb29 = cm_object_get_child_by_name(state->f0.reg.f9r1, "FB29");
	state->f0.fld.f9r1.fb30 = cm_object_get_child_by_name(state->f0.reg.f9r1, "FB30");
	state->f0.fld.f9r1.fb31 = cm_object_get_child_by_name(state->f0.reg.f9r1, "FB31");

	// F9R2 bitfields.
	state->f0.fld.f9r2.fb0 = cm_object_get_child_by_name(state->f0.reg.f9r2, "FB0");
	state->f0.fld.f9r2.fb1 = cm_object_get_child_by_name(state->f0.reg.f9r2, "FB1");
	state->f0.fld.f9r2.fb2 = cm_object_get_child_by_name(state->f0.reg.f9r2, "FB2");
	state->f0.fld.f9r2.fb3 = cm_object_get_child_by_name(state->f0.reg.f9r2, "FB3");
	state->f0.fld.f9r2.fb4 = cm_object_get_child_by_name(state->f0.reg.f9r2, "FB4");
	state->f0.fld.f9r2.fb5 = cm_object_get_child_by_name(state->f0.reg.f9r2, "FB5");
	state->f0.fld.f9r2.fb6 = cm_object_get_child_by_name(state->f0.reg.f9r2, "FB6");
	state->f0.fld.f9r2.fb7 = cm_object_get_child_by_name(state->f0.reg.f9r2, "FB7");
	state->f0.fld.f9r2.fb8 = cm_object_get_child_by_name(state->f0.reg.f9r2, "FB8");
	state->f0.fld.f9r2.fb9 = cm_object_get_child_by_name(state->f0.reg.f9r2, "FB9");
	state->f0.fld.f9r2.fb10 = cm_object_get_child_by_name(state->f0.reg.f9r2, "FB10");
	state->f0.fld.f9r2.fb11 = cm_object_get_child_by_name(state->f0.reg.f9r2, "FB11");
	state->f0.fld.f9r2.fb12 = cm_object_get_child_by_name(state->f0.reg.f9r2, "FB12");
	state->f0.fld.f9r2.fb13 = cm_object_get_child_by_name(state->f0.reg.f9r2, "FB13");
	state->f0.fld.f9r2.fb14 = cm_object_get_child_by_name(state->f0.reg.f9r2, "FB14");
	state->f0.fld.f9r2.fb15 = cm_object_get_child_by_name(state->f0.reg.f9r2, "FB15");
	state->f0.fld.f9r2.fb16 = cm_object_get_child_by_name(state->f0.reg.f9r2, "FB16");
	state->f0.fld.f9r2.fb17 = cm_object_get_child_by_name(state->f0.reg.f9r2, "FB17");
	state->f0.fld.f9r2.fb18 = cm_object_get_child_by_name(state->f0.reg.f9r2, "FB18");
	state->f0.fld.f9r2.fb19 = cm_object_get_child_by_name(state->f0.reg.f9r2, "FB19");
	state->f0.fld.f9r2.fb20 = cm_object_get_child_by_name(state->f0.reg.f9r2, "FB20");
	state->f0.fld.f9r2.fb21 = cm_object_get_child_by_name(state->f0.reg.f9r2, "FB21");
	state->f0.fld.f9r2.fb22 = cm_object_get_child_by_name(state->f0.reg.f9r2, "FB22");
	state->f0.fld.f9r2.fb23 = cm_object_get_child_by_name(state->f0.reg.f9r2, "FB23");
	state->f0.fld.f9r2.fb24 = cm_object_get_child_by_name(state->f0.reg.f9r2, "FB24");
	state->f0.fld.f9r2.fb25 = cm_object_get_child_by_name(state->f0.reg.f9r2, "FB25");
	state->f0.fld.f9r2.fb26 = cm_object_get_child_by_name(state->f0.reg.f9r2, "FB26");
	state->f0.fld.f9r2.fb27 = cm_object_get_child_by_name(state->f0.reg.f9r2, "FB27");
	state->f0.fld.f9r2.fb28 = cm_object_get_child_by_name(state->f0.reg.f9r2, "FB28");
	state->f0.fld.f9r2.fb29 = cm_object_get_child_by_name(state->f0.reg.f9r2, "FB29");
	state->f0.fld.f9r2.fb30 = cm_object_get_child_by_name(state->f0.reg.f9r2, "FB30");
	state->f0.fld.f9r2.fb31 = cm_object_get_child_by_name(state->f0.reg.f9r2, "FB31");

	// F10R1 bitfields.
	state->f0.fld.f10r1.fb0 = cm_object_get_child_by_name(state->f0.reg.f10r1, "FB0");
	state->f0.fld.f10r1.fb1 = cm_object_get_child_by_name(state->f0.reg.f10r1, "FB1");
	state->f0.fld.f10r1.fb2 = cm_object_get_child_by_name(state->f0.reg.f10r1, "FB2");
	state->f0.fld.f10r1.fb3 = cm_object_get_child_by_name(state->f0.reg.f10r1, "FB3");
	state->f0.fld.f10r1.fb4 = cm_object_get_child_by_name(state->f0.reg.f10r1, "FB4");
	state->f0.fld.f10r1.fb5 = cm_object_get_child_by_name(state->f0.reg.f10r1, "FB5");
	state->f0.fld.f10r1.fb6 = cm_object_get_child_by_name(state->f0.reg.f10r1, "FB6");
	state->f0.fld.f10r1.fb7 = cm_object_get_child_by_name(state->f0.reg.f10r1, "FB7");
	state->f0.fld.f10r1.fb8 = cm_object_get_child_by_name(state->f0.reg.f10r1, "FB8");
	state->f0.fld.f10r1.fb9 = cm_object_get_child_by_name(state->f0.reg.f10r1, "FB9");
	state->f0.fld.f10r1.fb10 = cm_object_get_child_by_name(state->f0.reg.f10r1, "FB10");
	state->f0.fld.f10r1.fb11 = cm_object_get_child_by_name(state->f0.reg.f10r1, "FB11");
	state->f0.fld.f10r1.fb12 = cm_object_get_child_by_name(state->f0.reg.f10r1, "FB12");
	state->f0.fld.f10r1.fb13 = cm_object_get_child_by_name(state->f0.reg.f10r1, "FB13");
	state->f0.fld.f10r1.fb14 = cm_object_get_child_by_name(state->f0.reg.f10r1, "FB14");
	state->f0.fld.f10r1.fb15 = cm_object_get_child_by_name(state->f0.reg.f10r1, "FB15");
	state->f0.fld.f10r1.fb16 = cm_object_get_child_by_name(state->f0.reg.f10r1, "FB16");
	state->f0.fld.f10r1.fb17 = cm_object_get_child_by_name(state->f0.reg.f10r1, "FB17");
	state->f0.fld.f10r1.fb18 = cm_object_get_child_by_name(state->f0.reg.f10r1, "FB18");
	state->f0.fld.f10r1.fb19 = cm_object_get_child_by_name(state->f0.reg.f10r1, "FB19");
	state->f0.fld.f10r1.fb20 = cm_object_get_child_by_name(state->f0.reg.f10r1, "FB20");
	state->f0.fld.f10r1.fb21 = cm_object_get_child_by_name(state->f0.reg.f10r1, "FB21");
	state->f0.fld.f10r1.fb22 = cm_object_get_child_by_name(state->f0.reg.f10r1, "FB22");
	state->f0.fld.f10r1.fb23 = cm_object_get_child_by_name(state->f0.reg.f10r1, "FB23");
	state->f0.fld.f10r1.fb24 = cm_object_get_child_by_name(state->f0.reg.f10r1, "FB24");
	state->f0.fld.f10r1.fb25 = cm_object_get_child_by_name(state->f0.reg.f10r1, "FB25");
	state->f0.fld.f10r1.fb26 = cm_object_get_child_by_name(state->f0.reg.f10r1, "FB26");
	state->f0.fld.f10r1.fb27 = cm_object_get_child_by_name(state->f0.reg.f10r1, "FB27");
	state->f0.fld.f10r1.fb28 = cm_object_get_child_by_name(state->f0.reg.f10r1, "FB28");
	state->f0.fld.f10r1.fb29 = cm_object_get_child_by_name(state->f0.reg.f10r1, "FB29");
	state->f0.fld.f10r1.fb30 = cm_object_get_child_by_name(state->f0.reg.f10r1, "FB30");
	state->f0.fld.f10r1.fb31 = cm_object_get_child_by_name(state->f0.reg.f10r1, "FB31");

	// F10R2 bitfields.
	state->f0.fld.f10r2.fb0 = cm_object_get_child_by_name(state->f0.reg.f10r2, "FB0");
	state->f0.fld.f10r2.fb1 = cm_object_get_child_by_name(state->f0.reg.f10r2, "FB1");
	state->f0.fld.f10r2.fb2 = cm_object_get_child_by_name(state->f0.reg.f10r2, "FB2");
	state->f0.fld.f10r2.fb3 = cm_object_get_child_by_name(state->f0.reg.f10r2, "FB3");
	state->f0.fld.f10r2.fb4 = cm_object_get_child_by_name(state->f0.reg.f10r2, "FB4");
	state->f0.fld.f10r2.fb5 = cm_object_get_child_by_name(state->f0.reg.f10r2, "FB5");
	state->f0.fld.f10r2.fb6 = cm_object_get_child_by_name(state->f0.reg.f10r2, "FB6");
	state->f0.fld.f10r2.fb7 = cm_object_get_child_by_name(state->f0.reg.f10r2, "FB7");
	state->f0.fld.f10r2.fb8 = cm_object_get_child_by_name(state->f0.reg.f10r2, "FB8");
	state->f0.fld.f10r2.fb9 = cm_object_get_child_by_name(state->f0.reg.f10r2, "FB9");
	state->f0.fld.f10r2.fb10 = cm_object_get_child_by_name(state->f0.reg.f10r2, "FB10");
	state->f0.fld.f10r2.fb11 = cm_object_get_child_by_name(state->f0.reg.f10r2, "FB11");
	state->f0.fld.f10r2.fb12 = cm_object_get_child_by_name(state->f0.reg.f10r2, "FB12");
	state->f0.fld.f10r2.fb13 = cm_object_get_child_by_name(state->f0.reg.f10r2, "FB13");
	state->f0.fld.f10r2.fb14 = cm_object_get_child_by_name(state->f0.reg.f10r2, "FB14");
	state->f0.fld.f10r2.fb15 = cm_object_get_child_by_name(state->f0.reg.f10r2, "FB15");
	state->f0.fld.f10r2.fb16 = cm_object_get_child_by_name(state->f0.reg.f10r2, "FB16");
	state->f0.fld.f10r2.fb17 = cm_object_get_child_by_name(state->f0.reg.f10r2, "FB17");
	state->f0.fld.f10r2.fb18 = cm_object_get_child_by_name(state->f0.reg.f10r2, "FB18");
	state->f0.fld.f10r2.fb19 = cm_object_get_child_by_name(state->f0.reg.f10r2, "FB19");
	state->f0.fld.f10r2.fb20 = cm_object_get_child_by_name(state->f0.reg.f10r2, "FB20");
	state->f0.fld.f10r2.fb21 = cm_object_get_child_by_name(state->f0.reg.f10r2, "FB21");
	state->f0.fld.f10r2.fb22 = cm_object_get_child_by_name(state->f0.reg.f10r2, "FB22");
	state->f0.fld.f10r2.fb23 = cm_object_get_child_by_name(state->f0.reg.f10r2, "FB23");
	state->f0.fld.f10r2.fb24 = cm_object_get_child_by_name(state->f0.reg.f10r2, "FB24");
	state->f0.fld.f10r2.fb25 = cm_object_get_child_by_name(state->f0.reg.f10r2, "FB25");
	state->f0.fld.f10r2.fb26 = cm_object_get_child_by_name(state->f0.reg.f10r2, "FB26");
	state->f0.fld.f10r2.fb27 = cm_object_get_child_by_name(state->f0.reg.f10r2, "FB27");
	state->f0.fld.f10r2.fb28 = cm_object_get_child_by_name(state->f0.reg.f10r2, "FB28");
	state->f0.fld.f10r2.fb29 = cm_object_get_child_by_name(state->f0.reg.f10r2, "FB29");
	state->f0.fld.f10r2.fb30 = cm_object_get_child_by_name(state->f0.reg.f10r2, "FB30");
	state->f0.fld.f10r2.fb31 = cm_object_get_child_by_name(state->f0.reg.f10r2, "FB31");

	// F11R1 bitfields.
	state->f0.fld.f11r1.fb0 = cm_object_get_child_by_name(state->f0.reg.f11r1, "FB0");
	state->f0.fld.f11r1.fb1 = cm_object_get_child_by_name(state->f0.reg.f11r1, "FB1");
	state->f0.fld.f11r1.fb2 = cm_object_get_child_by_name(state->f0.reg.f11r1, "FB2");
	state->f0.fld.f11r1.fb3 = cm_object_get_child_by_name(state->f0.reg.f11r1, "FB3");
	state->f0.fld.f11r1.fb4 = cm_object_get_child_by_name(state->f0.reg.f11r1, "FB4");
	state->f0.fld.f11r1.fb5 = cm_object_get_child_by_name(state->f0.reg.f11r1, "FB5");
	state->f0.fld.f11r1.fb6 = cm_object_get_child_by_name(state->f0.reg.f11r1, "FB6");
	state->f0.fld.f11r1.fb7 = cm_object_get_child_by_name(state->f0.reg.f11r1, "FB7");
	state->f0.fld.f11r1.fb8 = cm_object_get_child_by_name(state->f0.reg.f11r1, "FB8");
	state->f0.fld.f11r1.fb9 = cm_object_get_child_by_name(state->f0.reg.f11r1, "FB9");
	state->f0.fld.f11r1.fb10 = cm_object_get_child_by_name(state->f0.reg.f11r1, "FB10");
	state->f0.fld.f11r1.fb11 = cm_object_get_child_by_name(state->f0.reg.f11r1, "FB11");
	state->f0.fld.f11r1.fb12 = cm_object_get_child_by_name(state->f0.reg.f11r1, "FB12");
	state->f0.fld.f11r1.fb13 = cm_object_get_child_by_name(state->f0.reg.f11r1, "FB13");
	state->f0.fld.f11r1.fb14 = cm_object_get_child_by_name(state->f0.reg.f11r1, "FB14");
	state->f0.fld.f11r1.fb15 = cm_object_get_child_by_name(state->f0.reg.f11r1, "FB15");
	state->f0.fld.f11r1.fb16 = cm_object_get_child_by_name(state->f0.reg.f11r1, "FB16");
	state->f0.fld.f11r1.fb17 = cm_object_get_child_by_name(state->f0.reg.f11r1, "FB17");
	state->f0.fld.f11r1.fb18 = cm_object_get_child_by_name(state->f0.reg.f11r1, "FB18");
	state->f0.fld.f11r1.fb19 = cm_object_get_child_by_name(state->f0.reg.f11r1, "FB19");
	state->f0.fld.f11r1.fb20 = cm_object_get_child_by_name(state->f0.reg.f11r1, "FB20");
	state->f0.fld.f11r1.fb21 = cm_object_get_child_by_name(state->f0.reg.f11r1, "FB21");
	state->f0.fld.f11r1.fb22 = cm_object_get_child_by_name(state->f0.reg.f11r1, "FB22");
	state->f0.fld.f11r1.fb23 = cm_object_get_child_by_name(state->f0.reg.f11r1, "FB23");
	state->f0.fld.f11r1.fb24 = cm_object_get_child_by_name(state->f0.reg.f11r1, "FB24");
	state->f0.fld.f11r1.fb25 = cm_object_get_child_by_name(state->f0.reg.f11r1, "FB25");
	state->f0.fld.f11r1.fb26 = cm_object_get_child_by_name(state->f0.reg.f11r1, "FB26");
	state->f0.fld.f11r1.fb27 = cm_object_get_child_by_name(state->f0.reg.f11r1, "FB27");
	state->f0.fld.f11r1.fb28 = cm_object_get_child_by_name(state->f0.reg.f11r1, "FB28");
	state->f0.fld.f11r1.fb29 = cm_object_get_child_by_name(state->f0.reg.f11r1, "FB29");
	state->f0.fld.f11r1.fb30 = cm_object_get_child_by_name(state->f0.reg.f11r1, "FB30");
	state->f0.fld.f11r1.fb31 = cm_object_get_child_by_name(state->f0.reg.f11r1, "FB31");

	// F11R2 bitfields.
	state->f0.fld.f11r2.fb0 = cm_object_get_child_by_name(state->f0.reg.f11r2, "FB0");
	state->f0.fld.f11r2.fb1 = cm_object_get_child_by_name(state->f0.reg.f11r2, "FB1");
	state->f0.fld.f11r2.fb2 = cm_object_get_child_by_name(state->f0.reg.f11r2, "FB2");
	state->f0.fld.f11r2.fb3 = cm_object_get_child_by_name(state->f0.reg.f11r2, "FB3");
	state->f0.fld.f11r2.fb4 = cm_object_get_child_by_name(state->f0.reg.f11r2, "FB4");
	state->f0.fld.f11r2.fb5 = cm_object_get_child_by_name(state->f0.reg.f11r2, "FB5");
	state->f0.fld.f11r2.fb6 = cm_object_get_child_by_name(state->f0.reg.f11r2, "FB6");
	state->f0.fld.f11r2.fb7 = cm_object_get_child_by_name(state->f0.reg.f11r2, "FB7");
	state->f0.fld.f11r2.fb8 = cm_object_get_child_by_name(state->f0.reg.f11r2, "FB8");
	state->f0.fld.f11r2.fb9 = cm_object_get_child_by_name(state->f0.reg.f11r2, "FB9");
	state->f0.fld.f11r2.fb10 = cm_object_get_child_by_name(state->f0.reg.f11r2, "FB10");
	state->f0.fld.f11r2.fb11 = cm_object_get_child_by_name(state->f0.reg.f11r2, "FB11");
	state->f0.fld.f11r2.fb12 = cm_object_get_child_by_name(state->f0.reg.f11r2, "FB12");
	state->f0.fld.f11r2.fb13 = cm_object_get_child_by_name(state->f0.reg.f11r2, "FB13");
	state->f0.fld.f11r2.fb14 = cm_object_get_child_by_name(state->f0.reg.f11r2, "FB14");
	state->f0.fld.f11r2.fb15 = cm_object_get_child_by_name(state->f0.reg.f11r2, "FB15");
	state->f0.fld.f11r2.fb16 = cm_object_get_child_by_name(state->f0.reg.f11r2, "FB16");
	state->f0.fld.f11r2.fb17 = cm_object_get_child_by_name(state->f0.reg.f11r2, "FB17");
	state->f0.fld.f11r2.fb18 = cm_object_get_child_by_name(state->f0.reg.f11r2, "FB18");
	state->f0.fld.f11r2.fb19 = cm_object_get_child_by_name(state->f0.reg.f11r2, "FB19");
	state->f0.fld.f11r2.fb20 = cm_object_get_child_by_name(state->f0.reg.f11r2, "FB20");
	state->f0.fld.f11r2.fb21 = cm_object_get_child_by_name(state->f0.reg.f11r2, "FB21");
	state->f0.fld.f11r2.fb22 = cm_object_get_child_by_name(state->f0.reg.f11r2, "FB22");
	state->f0.fld.f11r2.fb23 = cm_object_get_child_by_name(state->f0.reg.f11r2, "FB23");
	state->f0.fld.f11r2.fb24 = cm_object_get_child_by_name(state->f0.reg.f11r2, "FB24");
	state->f0.fld.f11r2.fb25 = cm_object_get_child_by_name(state->f0.reg.f11r2, "FB25");
	state->f0.fld.f11r2.fb26 = cm_object_get_child_by_name(state->f0.reg.f11r2, "FB26");
	state->f0.fld.f11r2.fb27 = cm_object_get_child_by_name(state->f0.reg.f11r2, "FB27");
	state->f0.fld.f11r2.fb28 = cm_object_get_child_by_name(state->f0.reg.f11r2, "FB28");
	state->f0.fld.f11r2.fb29 = cm_object_get_child_by_name(state->f0.reg.f11r2, "FB29");
	state->f0.fld.f11r2.fb30 = cm_object_get_child_by_name(state->f0.reg.f11r2, "FB30");
	state->f0.fld.f11r2.fb31 = cm_object_get_child_by_name(state->f0.reg.f11r2, "FB31");

	// F12R1 bitfields.
	state->f0.fld.f12r1.fb0 = cm_object_get_child_by_name(state->f0.reg.f12r1, "FB0");
	state->f0.fld.f12r1.fb1 = cm_object_get_child_by_name(state->f0.reg.f12r1, "FB1");
	state->f0.fld.f12r1.fb2 = cm_object_get_child_by_name(state->f0.reg.f12r1, "FB2");
	state->f0.fld.f12r1.fb3 = cm_object_get_child_by_name(state->f0.reg.f12r1, "FB3");
	state->f0.fld.f12r1.fb4 = cm_object_get_child_by_name(state->f0.reg.f12r1, "FB4");
	state->f0.fld.f12r1.fb5 = cm_object_get_child_by_name(state->f0.reg.f12r1, "FB5");
	state->f0.fld.f12r1.fb6 = cm_object_get_child_by_name(state->f0.reg.f12r1, "FB6");
	state->f0.fld.f12r1.fb7 = cm_object_get_child_by_name(state->f0.reg.f12r1, "FB7");
	state->f0.fld.f12r1.fb8 = cm_object_get_child_by_name(state->f0.reg.f12r1, "FB8");
	state->f0.fld.f12r1.fb9 = cm_object_get_child_by_name(state->f0.reg.f12r1, "FB9");
	state->f0.fld.f12r1.fb10 = cm_object_get_child_by_name(state->f0.reg.f12r1, "FB10");
	state->f0.fld.f12r1.fb11 = cm_object_get_child_by_name(state->f0.reg.f12r1, "FB11");
	state->f0.fld.f12r1.fb12 = cm_object_get_child_by_name(state->f0.reg.f12r1, "FB12");
	state->f0.fld.f12r1.fb13 = cm_object_get_child_by_name(state->f0.reg.f12r1, "FB13");
	state->f0.fld.f12r1.fb14 = cm_object_get_child_by_name(state->f0.reg.f12r1, "FB14");
	state->f0.fld.f12r1.fb15 = cm_object_get_child_by_name(state->f0.reg.f12r1, "FB15");
	state->f0.fld.f12r1.fb16 = cm_object_get_child_by_name(state->f0.reg.f12r1, "FB16");
	state->f0.fld.f12r1.fb17 = cm_object_get_child_by_name(state->f0.reg.f12r1, "FB17");
	state->f0.fld.f12r1.fb18 = cm_object_get_child_by_name(state->f0.reg.f12r1, "FB18");
	state->f0.fld.f12r1.fb19 = cm_object_get_child_by_name(state->f0.reg.f12r1, "FB19");
	state->f0.fld.f12r1.fb20 = cm_object_get_child_by_name(state->f0.reg.f12r1, "FB20");
	state->f0.fld.f12r1.fb21 = cm_object_get_child_by_name(state->f0.reg.f12r1, "FB21");
	state->f0.fld.f12r1.fb22 = cm_object_get_child_by_name(state->f0.reg.f12r1, "FB22");
	state->f0.fld.f12r1.fb23 = cm_object_get_child_by_name(state->f0.reg.f12r1, "FB23");
	state->f0.fld.f12r1.fb24 = cm_object_get_child_by_name(state->f0.reg.f12r1, "FB24");
	state->f0.fld.f12r1.fb25 = cm_object_get_child_by_name(state->f0.reg.f12r1, "FB25");
	state->f0.fld.f12r1.fb26 = cm_object_get_child_by_name(state->f0.reg.f12r1, "FB26");
	state->f0.fld.f12r1.fb27 = cm_object_get_child_by_name(state->f0.reg.f12r1, "FB27");
	state->f0.fld.f12r1.fb28 = cm_object_get_child_by_name(state->f0.reg.f12r1, "FB28");
	state->f0.fld.f12r1.fb29 = cm_object_get_child_by_name(state->f0.reg.f12r1, "FB29");
	state->f0.fld.f12r1.fb30 = cm_object_get_child_by_name(state->f0.reg.f12r1, "FB30");
	state->f0.fld.f12r1.fb31 = cm_object_get_child_by_name(state->f0.reg.f12r1, "FB31");

	// F12R2 bitfields.
	state->f0.fld.f12r2.fb0 = cm_object_get_child_by_name(state->f0.reg.f12r2, "FB0");
	state->f0.fld.f12r2.fb1 = cm_object_get_child_by_name(state->f0.reg.f12r2, "FB1");
	state->f0.fld.f12r2.fb2 = cm_object_get_child_by_name(state->f0.reg.f12r2, "FB2");
	state->f0.fld.f12r2.fb3 = cm_object_get_child_by_name(state->f0.reg.f12r2, "FB3");
	state->f0.fld.f12r2.fb4 = cm_object_get_child_by_name(state->f0.reg.f12r2, "FB4");
	state->f0.fld.f12r2.fb5 = cm_object_get_child_by_name(state->f0.reg.f12r2, "FB5");
	state->f0.fld.f12r2.fb6 = cm_object_get_child_by_name(state->f0.reg.f12r2, "FB6");
	state->f0.fld.f12r2.fb7 = cm_object_get_child_by_name(state->f0.reg.f12r2, "FB7");
	state->f0.fld.f12r2.fb8 = cm_object_get_child_by_name(state->f0.reg.f12r2, "FB8");
	state->f0.fld.f12r2.fb9 = cm_object_get_child_by_name(state->f0.reg.f12r2, "FB9");
	state->f0.fld.f12r2.fb10 = cm_object_get_child_by_name(state->f0.reg.f12r2, "FB10");
	state->f0.fld.f12r2.fb11 = cm_object_get_child_by_name(state->f0.reg.f12r2, "FB11");
	state->f0.fld.f12r2.fb12 = cm_object_get_child_by_name(state->f0.reg.f12r2, "FB12");
	state->f0.fld.f12r2.fb13 = cm_object_get_child_by_name(state->f0.reg.f12r2, "FB13");
	state->f0.fld.f12r2.fb14 = cm_object_get_child_by_name(state->f0.reg.f12r2, "FB14");
	state->f0.fld.f12r2.fb15 = cm_object_get_child_by_name(state->f0.reg.f12r2, "FB15");
	state->f0.fld.f12r2.fb16 = cm_object_get_child_by_name(state->f0.reg.f12r2, "FB16");
	state->f0.fld.f12r2.fb17 = cm_object_get_child_by_name(state->f0.reg.f12r2, "FB17");
	state->f0.fld.f12r2.fb18 = cm_object_get_child_by_name(state->f0.reg.f12r2, "FB18");
	state->f0.fld.f12r2.fb19 = cm_object_get_child_by_name(state->f0.reg.f12r2, "FB19");
	state->f0.fld.f12r2.fb20 = cm_object_get_child_by_name(state->f0.reg.f12r2, "FB20");
	state->f0.fld.f12r2.fb21 = cm_object_get_child_by_name(state->f0.reg.f12r2, "FB21");
	state->f0.fld.f12r2.fb22 = cm_object_get_child_by_name(state->f0.reg.f12r2, "FB22");
	state->f0.fld.f12r2.fb23 = cm_object_get_child_by_name(state->f0.reg.f12r2, "FB23");
	state->f0.fld.f12r2.fb24 = cm_object_get_child_by_name(state->f0.reg.f12r2, "FB24");
	state->f0.fld.f12r2.fb25 = cm_object_get_child_by_name(state->f0.reg.f12r2, "FB25");
	state->f0.fld.f12r2.fb26 = cm_object_get_child_by_name(state->f0.reg.f12r2, "FB26");
	state->f0.fld.f12r2.fb27 = cm_object_get_child_by_name(state->f0.reg.f12r2, "FB27");
	state->f0.fld.f12r2.fb28 = cm_object_get_child_by_name(state->f0.reg.f12r2, "FB28");
	state->f0.fld.f12r2.fb29 = cm_object_get_child_by_name(state->f0.reg.f12r2, "FB29");
	state->f0.fld.f12r2.fb30 = cm_object_get_child_by_name(state->f0.reg.f12r2, "FB30");
	state->f0.fld.f12r2.fb31 = cm_object_get_child_by_name(state->f0.reg.f12r2, "FB31");

	// F13R1 bitfields.
	state->f0.fld.f13r1.fb0 = cm_object_get_child_by_name(state->f0.reg.f13r1, "FB0");
	state->f0.fld.f13r1.fb1 = cm_object_get_child_by_name(state->f0.reg.f13r1, "FB1");
	state->f0.fld.f13r1.fb2 = cm_object_get_child_by_name(state->f0.reg.f13r1, "FB2");
	state->f0.fld.f13r1.fb3 = cm_object_get_child_by_name(state->f0.reg.f13r1, "FB3");
	state->f0.fld.f13r1.fb4 = cm_object_get_child_by_name(state->f0.reg.f13r1, "FB4");
	state->f0.fld.f13r1.fb5 = cm_object_get_child_by_name(state->f0.reg.f13r1, "FB5");
	state->f0.fld.f13r1.fb6 = cm_object_get_child_by_name(state->f0.reg.f13r1, "FB6");
	state->f0.fld.f13r1.fb7 = cm_object_get_child_by_name(state->f0.reg.f13r1, "FB7");
	state->f0.fld.f13r1.fb8 = cm_object_get_child_by_name(state->f0.reg.f13r1, "FB8");
	state->f0.fld.f13r1.fb9 = cm_object_get_child_by_name(state->f0.reg.f13r1, "FB9");
	state->f0.fld.f13r1.fb10 = cm_object_get_child_by_name(state->f0.reg.f13r1, "FB10");
	state->f0.fld.f13r1.fb11 = cm_object_get_child_by_name(state->f0.reg.f13r1, "FB11");
	state->f0.fld.f13r1.fb12 = cm_object_get_child_by_name(state->f0.reg.f13r1, "FB12");
	state->f0.fld.f13r1.fb13 = cm_object_get_child_by_name(state->f0.reg.f13r1, "FB13");
	state->f0.fld.f13r1.fb14 = cm_object_get_child_by_name(state->f0.reg.f13r1, "FB14");
	state->f0.fld.f13r1.fb15 = cm_object_get_child_by_name(state->f0.reg.f13r1, "FB15");
	state->f0.fld.f13r1.fb16 = cm_object_get_child_by_name(state->f0.reg.f13r1, "FB16");
	state->f0.fld.f13r1.fb17 = cm_object_get_child_by_name(state->f0.reg.f13r1, "FB17");
	state->f0.fld.f13r1.fb18 = cm_object_get_child_by_name(state->f0.reg.f13r1, "FB18");
	state->f0.fld.f13r1.fb19 = cm_object_get_child_by_name(state->f0.reg.f13r1, "FB19");
	state->f0.fld.f13r1.fb20 = cm_object_get_child_by_name(state->f0.reg.f13r1, "FB20");
	state->f0.fld.f13r1.fb21 = cm_object_get_child_by_name(state->f0.reg.f13r1, "FB21");
	state->f0.fld.f13r1.fb22 = cm_object_get_child_by_name(state->f0.reg.f13r1, "FB22");
	state->f0.fld.f13r1.fb23 = cm_object_get_child_by_name(state->f0.reg.f13r1, "FB23");
	state->f0.fld.f13r1.fb24 = cm_object_get_child_by_name(state->f0.reg.f13r1, "FB24");
	state->f0.fld.f13r1.fb25 = cm_object_get_child_by_name(state->f0.reg.f13r1, "FB25");
	state->f0.fld.f13r1.fb26 = cm_object_get_child_by_name(state->f0.reg.f13r1, "FB26");
	state->f0.fld.f13r1.fb27 = cm_object_get_child_by_name(state->f0.reg.f13r1, "FB27");
	state->f0.fld.f13r1.fb28 = cm_object_get_child_by_name(state->f0.reg.f13r1, "FB28");
	state->f0.fld.f13r1.fb29 = cm_object_get_child_by_name(state->f0.reg.f13r1, "FB29");
	state->f0.fld.f13r1.fb30 = cm_object_get_child_by_name(state->f0.reg.f13r1, "FB30");
	state->f0.fld.f13r1.fb31 = cm_object_get_child_by_name(state->f0.reg.f13r1, "FB31");

	// F13R2 bitfields.
	state->f0.fld.f13r2.fb0 = cm_object_get_child_by_name(state->f0.reg.f13r2, "FB0");
	state->f0.fld.f13r2.fb1 = cm_object_get_child_by_name(state->f0.reg.f13r2, "FB1");
	state->f0.fld.f13r2.fb2 = cm_object_get_child_by_name(state->f0.reg.f13r2, "FB2");
	state->f0.fld.f13r2.fb3 = cm_object_get_child_by_name(state->f0.reg.f13r2, "FB3");
	state->f0.fld.f13r2.fb4 = cm_object_get_child_by_name(state->f0.reg.f13r2, "FB4");
	state->f0.fld.f13r2.fb5 = cm_object_get_child_by_name(state->f0.reg.f13r2, "FB5");
	state->f0.fld.f13r2.fb6 = cm_object_get_child_by_name(state->f0.reg.f13r2, "FB6");
	state->f0.fld.f13r2.fb7 = cm_object_get_child_by_name(state->f0.reg.f13r2, "FB7");
	state->f0.fld.f13r2.fb8 = cm_object_get_child_by_name(state->f0.reg.f13r2, "FB8");
	state->f0.fld.f13r2.fb9 = cm_object_get_child_by_name(state->f0.reg.f13r2, "FB9");
	state->f0.fld.f13r2.fb10 = cm_object_get_child_by_name(state->f0.reg.f13r2, "FB10");
	state->f0.fld.f13r2.fb11 = cm_object_get_child_by_name(state->f0.reg.f13r2, "FB11");
	state->f0.fld.f13r2.fb12 = cm_object_get_child_by_name(state->f0.reg.f13r2, "FB12");
	state->f0.fld.f13r2.fb13 = cm_object_get_child_by_name(state->f0.reg.f13r2, "FB13");
	state->f0.fld.f13r2.fb14 = cm_object_get_child_by_name(state->f0.reg.f13r2, "FB14");
	state->f0.fld.f13r2.fb15 = cm_object_get_child_by_name(state->f0.reg.f13r2, "FB15");
	state->f0.fld.f13r2.fb16 = cm_object_get_child_by_name(state->f0.reg.f13r2, "FB16");
	state->f0.fld.f13r2.fb17 = cm_object_get_child_by_name(state->f0.reg.f13r2, "FB17");
	state->f0.fld.f13r2.fb18 = cm_object_get_child_by_name(state->f0.reg.f13r2, "FB18");
	state->f0.fld.f13r2.fb19 = cm_object_get_child_by_name(state->f0.reg.f13r2, "FB19");
	state->f0.fld.f13r2.fb20 = cm_object_get_child_by_name(state->f0.reg.f13r2, "FB20");
	state->f0.fld.f13r2.fb21 = cm_object_get_child_by_name(state->f0.reg.f13r2, "FB21");
	state->f0.fld.f13r2.fb22 = cm_object_get_child_by_name(state->f0.reg.f13r2, "FB22");
	state->f0.fld.f13r2.fb23 = cm_object_get_child_by_name(state->f0.reg.f13r2, "FB23");
	state->f0.fld.f13r2.fb24 = cm_object_get_child_by_name(state->f0.reg.f13r2, "FB24");
	state->f0.fld.f13r2.fb25 = cm_object_get_child_by_name(state->f0.reg.f13r2, "FB25");
	state->f0.fld.f13r2.fb26 = cm_object_get_child_by_name(state->f0.reg.f13r2, "FB26");
	state->f0.fld.f13r2.fb27 = cm_object_get_child_by_name(state->f0.reg.f13r2, "FB27");
	state->f0.fld.f13r2.fb28 = cm_object_get_child_by_name(state->f0.reg.f13r2, "FB28");
	state->f0.fld.f13r2.fb29 = cm_object_get_child_by_name(state->f0.reg.f13r2, "FB29");
	state->f0.fld.f13r2.fb30 = cm_object_get_child_by_name(state->f0.reg.f13r2, "FB30");
	state->f0.fld.f13r2.fb31 = cm_object_get_child_by_name(state->f0.reg.f13r2, "FB31");

	// F14R1 bitfields.
	state->f0.fld.f14r1.fb0 = cm_object_get_child_by_name(state->f0.reg.f14r1, "FB0");
	state->f0.fld.f14r1.fb1 = cm_object_get_child_by_name(state->f0.reg.f14r1, "FB1");
	state->f0.fld.f14r1.fb2 = cm_object_get_child_by_name(state->f0.reg.f14r1, "FB2");
	state->f0.fld.f14r1.fb3 = cm_object_get_child_by_name(state->f0.reg.f14r1, "FB3");
	state->f0.fld.f14r1.fb4 = cm_object_get_child_by_name(state->f0.reg.f14r1, "FB4");
	state->f0.fld.f14r1.fb5 = cm_object_get_child_by_name(state->f0.reg.f14r1, "FB5");
	state->f0.fld.f14r1.fb6 = cm_object_get_child_by_name(state->f0.reg.f14r1, "FB6");
	state->f0.fld.f14r1.fb7 = cm_object_get_child_by_name(state->f0.reg.f14r1, "FB7");
	state->f0.fld.f14r1.fb8 = cm_object_get_child_by_name(state->f0.reg.f14r1, "FB8");
	state->f0.fld.f14r1.fb9 = cm_object_get_child_by_name(state->f0.reg.f14r1, "FB9");
	state->f0.fld.f14r1.fb10 = cm_object_get_child_by_name(state->f0.reg.f14r1, "FB10");
	state->f0.fld.f14r1.fb11 = cm_object_get_child_by_name(state->f0.reg.f14r1, "FB11");
	state->f0.fld.f14r1.fb12 = cm_object_get_child_by_name(state->f0.reg.f14r1, "FB12");
	state->f0.fld.f14r1.fb13 = cm_object_get_child_by_name(state->f0.reg.f14r1, "FB13");
	state->f0.fld.f14r1.fb14 = cm_object_get_child_by_name(state->f0.reg.f14r1, "FB14");
	state->f0.fld.f14r1.fb15 = cm_object_get_child_by_name(state->f0.reg.f14r1, "FB15");
	state->f0.fld.f14r1.fb16 = cm_object_get_child_by_name(state->f0.reg.f14r1, "FB16");
	state->f0.fld.f14r1.fb17 = cm_object_get_child_by_name(state->f0.reg.f14r1, "FB17");
	state->f0.fld.f14r1.fb18 = cm_object_get_child_by_name(state->f0.reg.f14r1, "FB18");
	state->f0.fld.f14r1.fb19 = cm_object_get_child_by_name(state->f0.reg.f14r1, "FB19");
	state->f0.fld.f14r1.fb20 = cm_object_get_child_by_name(state->f0.reg.f14r1, "FB20");
	state->f0.fld.f14r1.fb21 = cm_object_get_child_by_name(state->f0.reg.f14r1, "FB21");
	state->f0.fld.f14r1.fb22 = cm_object_get_child_by_name(state->f0.reg.f14r1, "FB22");
	state->f0.fld.f14r1.fb23 = cm_object_get_child_by_name(state->f0.reg.f14r1, "FB23");
	state->f0.fld.f14r1.fb24 = cm_object_get_child_by_name(state->f0.reg.f14r1, "FB24");
	state->f0.fld.f14r1.fb25 = cm_object_get_child_by_name(state->f0.reg.f14r1, "FB25");
	state->f0.fld.f14r1.fb26 = cm_object_get_child_by_name(state->f0.reg.f14r1, "FB26");
	state->f0.fld.f14r1.fb27 = cm_object_get_child_by_name(state->f0.reg.f14r1, "FB27");
	state->f0.fld.f14r1.fb28 = cm_object_get_child_by_name(state->f0.reg.f14r1, "FB28");
	state->f0.fld.f14r1.fb29 = cm_object_get_child_by_name(state->f0.reg.f14r1, "FB29");
	state->f0.fld.f14r1.fb30 = cm_object_get_child_by_name(state->f0.reg.f14r1, "FB30");
	state->f0.fld.f14r1.fb31 = cm_object_get_child_by_name(state->f0.reg.f14r1, "FB31");

	// F14R2 bitfields.
	state->f0.fld.f14r2.fb0 = cm_object_get_child_by_name(state->f0.reg.f14r2, "FB0");
	state->f0.fld.f14r2.fb1 = cm_object_get_child_by_name(state->f0.reg.f14r2, "FB1");
	state->f0.fld.f14r2.fb2 = cm_object_get_child_by_name(state->f0.reg.f14r2, "FB2");
	state->f0.fld.f14r2.fb3 = cm_object_get_child_by_name(state->f0.reg.f14r2, "FB3");
	state->f0.fld.f14r2.fb4 = cm_object_get_child_by_name(state->f0.reg.f14r2, "FB4");
	state->f0.fld.f14r2.fb5 = cm_object_get_child_by_name(state->f0.reg.f14r2, "FB5");
	state->f0.fld.f14r2.fb6 = cm_object_get_child_by_name(state->f0.reg.f14r2, "FB6");
	state->f0.fld.f14r2.fb7 = cm_object_get_child_by_name(state->f0.reg.f14r2, "FB7");
	state->f0.fld.f14r2.fb8 = cm_object_get_child_by_name(state->f0.reg.f14r2, "FB8");
	state->f0.fld.f14r2.fb9 = cm_object_get_child_by_name(state->f0.reg.f14r2, "FB9");
	state->f0.fld.f14r2.fb10 = cm_object_get_child_by_name(state->f0.reg.f14r2, "FB10");
	state->f0.fld.f14r2.fb11 = cm_object_get_child_by_name(state->f0.reg.f14r2, "FB11");
	state->f0.fld.f14r2.fb12 = cm_object_get_child_by_name(state->f0.reg.f14r2, "FB12");
	state->f0.fld.f14r2.fb13 = cm_object_get_child_by_name(state->f0.reg.f14r2, "FB13");
	state->f0.fld.f14r2.fb14 = cm_object_get_child_by_name(state->f0.reg.f14r2, "FB14");
	state->f0.fld.f14r2.fb15 = cm_object_get_child_by_name(state->f0.reg.f14r2, "FB15");
	state->f0.fld.f14r2.fb16 = cm_object_get_child_by_name(state->f0.reg.f14r2, "FB16");
	state->f0.fld.f14r2.fb17 = cm_object_get_child_by_name(state->f0.reg.f14r2, "FB17");
	state->f0.fld.f14r2.fb18 = cm_object_get_child_by_name(state->f0.reg.f14r2, "FB18");
	state->f0.fld.f14r2.fb19 = cm_object_get_child_by_name(state->f0.reg.f14r2, "FB19");
	state->f0.fld.f14r2.fb20 = cm_object_get_child_by_name(state->f0.reg.f14r2, "FB20");
	state->f0.fld.f14r2.fb21 = cm_object_get_child_by_name(state->f0.reg.f14r2, "FB21");
	state->f0.fld.f14r2.fb22 = cm_object_get_child_by_name(state->f0.reg.f14r2, "FB22");
	state->f0.fld.f14r2.fb23 = cm_object_get_child_by_name(state->f0.reg.f14r2, "FB23");
	state->f0.fld.f14r2.fb24 = cm_object_get_child_by_name(state->f0.reg.f14r2, "FB24");
	state->f0.fld.f14r2.fb25 = cm_object_get_child_by_name(state->f0.reg.f14r2, "FB25");
	state->f0.fld.f14r2.fb26 = cm_object_get_child_by_name(state->f0.reg.f14r2, "FB26");
	state->f0.fld.f14r2.fb27 = cm_object_get_child_by_name(state->f0.reg.f14r2, "FB27");
	state->f0.fld.f14r2.fb28 = cm_object_get_child_by_name(state->f0.reg.f14r2, "FB28");
	state->f0.fld.f14r2.fb29 = cm_object_get_child_by_name(state->f0.reg.f14r2, "FB29");
	state->f0.fld.f14r2.fb30 = cm_object_get_child_by_name(state->f0.reg.f14r2, "FB30");
	state->f0.fld.f14r2.fb31 = cm_object_get_child_by_name(state->f0.reg.f14r2, "FB31");

	// F15R1 bitfields.
	state->f0.fld.f15r1.fb0 = cm_object_get_child_by_name(state->f0.reg.f15r1, "FB0");
	state->f0.fld.f15r1.fb1 = cm_object_get_child_by_name(state->f0.reg.f15r1, "FB1");
	state->f0.fld.f15r1.fb2 = cm_object_get_child_by_name(state->f0.reg.f15r1, "FB2");
	state->f0.fld.f15r1.fb3 = cm_object_get_child_by_name(state->f0.reg.f15r1, "FB3");
	state->f0.fld.f15r1.fb4 = cm_object_get_child_by_name(state->f0.reg.f15r1, "FB4");
	state->f0.fld.f15r1.fb5 = cm_object_get_child_by_name(state->f0.reg.f15r1, "FB5");
	state->f0.fld.f15r1.fb6 = cm_object_get_child_by_name(state->f0.reg.f15r1, "FB6");
	state->f0.fld.f15r1.fb7 = cm_object_get_child_by_name(state->f0.reg.f15r1, "FB7");
	state->f0.fld.f15r1.fb8 = cm_object_get_child_by_name(state->f0.reg.f15r1, "FB8");
	state->f0.fld.f15r1.fb9 = cm_object_get_child_by_name(state->f0.reg.f15r1, "FB9");
	state->f0.fld.f15r1.fb10 = cm_object_get_child_by_name(state->f0.reg.f15r1, "FB10");
	state->f0.fld.f15r1.fb11 = cm_object_get_child_by_name(state->f0.reg.f15r1, "FB11");
	state->f0.fld.f15r1.fb12 = cm_object_get_child_by_name(state->f0.reg.f15r1, "FB12");
	state->f0.fld.f15r1.fb13 = cm_object_get_child_by_name(state->f0.reg.f15r1, "FB13");
	state->f0.fld.f15r1.fb14 = cm_object_get_child_by_name(state->f0.reg.f15r1, "FB14");
	state->f0.fld.f15r1.fb15 = cm_object_get_child_by_name(state->f0.reg.f15r1, "FB15");
	state->f0.fld.f15r1.fb16 = cm_object_get_child_by_name(state->f0.reg.f15r1, "FB16");
	state->f0.fld.f15r1.fb17 = cm_object_get_child_by_name(state->f0.reg.f15r1, "FB17");
	state->f0.fld.f15r1.fb18 = cm_object_get_child_by_name(state->f0.reg.f15r1, "FB18");
	state->f0.fld.f15r1.fb19 = cm_object_get_child_by_name(state->f0.reg.f15r1, "FB19");
	state->f0.fld.f15r1.fb20 = cm_object_get_child_by_name(state->f0.reg.f15r1, "FB20");
	state->f0.fld.f15r1.fb21 = cm_object_get_child_by_name(state->f0.reg.f15r1, "FB21");
	state->f0.fld.f15r1.fb22 = cm_object_get_child_by_name(state->f0.reg.f15r1, "FB22");
	state->f0.fld.f15r1.fb23 = cm_object_get_child_by_name(state->f0.reg.f15r1, "FB23");
	state->f0.fld.f15r1.fb24 = cm_object_get_child_by_name(state->f0.reg.f15r1, "FB24");
	state->f0.fld.f15r1.fb25 = cm_object_get_child_by_name(state->f0.reg.f15r1, "FB25");
	state->f0.fld.f15r1.fb26 = cm_object_get_child_by_name(state->f0.reg.f15r1, "FB26");
	state->f0.fld.f15r1.fb27 = cm_object_get_child_by_name(state->f0.reg.f15r1, "FB27");
	state->f0.fld.f15r1.fb28 = cm_object_get_child_by_name(state->f0.reg.f15r1, "FB28");
	state->f0.fld.f15r1.fb29 = cm_object_get_child_by_name(state->f0.reg.f15r1, "FB29");
	state->f0.fld.f15r1.fb30 = cm_object_get_child_by_name(state->f0.reg.f15r1, "FB30");
	state->f0.fld.f15r1.fb31 = cm_object_get_child_by_name(state->f0.reg.f15r1, "FB31");

	// F15R2 bitfields.
	state->f0.fld.f15r2.fb0 = cm_object_get_child_by_name(state->f0.reg.f15r2, "FB0");
	state->f0.fld.f15r2.fb1 = cm_object_get_child_by_name(state->f0.reg.f15r2, "FB1");
	state->f0.fld.f15r2.fb2 = cm_object_get_child_by_name(state->f0.reg.f15r2, "FB2");
	state->f0.fld.f15r2.fb3 = cm_object_get_child_by_name(state->f0.reg.f15r2, "FB3");
	state->f0.fld.f15r2.fb4 = cm_object_get_child_by_name(state->f0.reg.f15r2, "FB4");
	state->f0.fld.f15r2.fb5 = cm_object_get_child_by_name(state->f0.reg.f15r2, "FB5");
	state->f0.fld.f15r2.fb6 = cm_object_get_child_by_name(state->f0.reg.f15r2, "FB6");
	state->f0.fld.f15r2.fb7 = cm_object_get_child_by_name(state->f0.reg.f15r2, "FB7");
	state->f0.fld.f15r2.fb8 = cm_object_get_child_by_name(state->f0.reg.f15r2, "FB8");
	state->f0.fld.f15r2.fb9 = cm_object_get_child_by_name(state->f0.reg.f15r2, "FB9");
	state->f0.fld.f15r2.fb10 = cm_object_get_child_by_name(state->f0.reg.f15r2, "FB10");
	state->f0.fld.f15r2.fb11 = cm_object_get_child_by_name(state->f0.reg.f15r2, "FB11");
	state->f0.fld.f15r2.fb12 = cm_object_get_child_by_name(state->f0.reg.f15r2, "FB12");
	state->f0.fld.f15r2.fb13 = cm_object_get_child_by_name(state->f0.reg.f15r2, "FB13");
	state->f0.fld.f15r2.fb14 = cm_object_get_child_by_name(state->f0.reg.f15r2, "FB14");
	state->f0.fld.f15r2.fb15 = cm_object_get_child_by_name(state->f0.reg.f15r2, "FB15");
	state->f0.fld.f15r2.fb16 = cm_object_get_child_by_name(state->f0.reg.f15r2, "FB16");
	state->f0.fld.f15r2.fb17 = cm_object_get_child_by_name(state->f0.reg.f15r2, "FB17");
	state->f0.fld.f15r2.fb18 = cm_object_get_child_by_name(state->f0.reg.f15r2, "FB18");
	state->f0.fld.f15r2.fb19 = cm_object_get_child_by_name(state->f0.reg.f15r2, "FB19");
	state->f0.fld.f15r2.fb20 = cm_object_get_child_by_name(state->f0.reg.f15r2, "FB20");
	state->f0.fld.f15r2.fb21 = cm_object_get_child_by_name(state->f0.reg.f15r2, "FB21");
	state->f0.fld.f15r2.fb22 = cm_object_get_child_by_name(state->f0.reg.f15r2, "FB22");
	state->f0.fld.f15r2.fb23 = cm_object_get_child_by_name(state->f0.reg.f15r2, "FB23");
	state->f0.fld.f15r2.fb24 = cm_object_get_child_by_name(state->f0.reg.f15r2, "FB24");
	state->f0.fld.f15r2.fb25 = cm_object_get_child_by_name(state->f0.reg.f15r2, "FB25");
	state->f0.fld.f15r2.fb26 = cm_object_get_child_by_name(state->f0.reg.f15r2, "FB26");
	state->f0.fld.f15r2.fb27 = cm_object_get_child_by_name(state->f0.reg.f15r2, "FB27");
	state->f0.fld.f15r2.fb28 = cm_object_get_child_by_name(state->f0.reg.f15r2, "FB28");
	state->f0.fld.f15r2.fb29 = cm_object_get_child_by_name(state->f0.reg.f15r2, "FB29");
	state->f0.fld.f15r2.fb30 = cm_object_get_child_by_name(state->f0.reg.f15r2, "FB30");
	state->f0.fld.f15r2.fb31 = cm_object_get_child_by_name(state->f0.reg.f15r2, "FB31");

	// F16R1 bitfields.
	state->f0.fld.f16r1.fb0 = cm_object_get_child_by_name(state->f0.reg.f16r1, "FB0");
	state->f0.fld.f16r1.fb1 = cm_object_get_child_by_name(state->f0.reg.f16r1, "FB1");
	state->f0.fld.f16r1.fb2 = cm_object_get_child_by_name(state->f0.reg.f16r1, "FB2");
	state->f0.fld.f16r1.fb3 = cm_object_get_child_by_name(state->f0.reg.f16r1, "FB3");
	state->f0.fld.f16r1.fb4 = cm_object_get_child_by_name(state->f0.reg.f16r1, "FB4");
	state->f0.fld.f16r1.fb5 = cm_object_get_child_by_name(state->f0.reg.f16r1, "FB5");
	state->f0.fld.f16r1.fb6 = cm_object_get_child_by_name(state->f0.reg.f16r1, "FB6");
	state->f0.fld.f16r1.fb7 = cm_object_get_child_by_name(state->f0.reg.f16r1, "FB7");
	state->f0.fld.f16r1.fb8 = cm_object_get_child_by_name(state->f0.reg.f16r1, "FB8");
	state->f0.fld.f16r1.fb9 = cm_object_get_child_by_name(state->f0.reg.f16r1, "FB9");
	state->f0.fld.f16r1.fb10 = cm_object_get_child_by_name(state->f0.reg.f16r1, "FB10");
	state->f0.fld.f16r1.fb11 = cm_object_get_child_by_name(state->f0.reg.f16r1, "FB11");
	state->f0.fld.f16r1.fb12 = cm_object_get_child_by_name(state->f0.reg.f16r1, "FB12");
	state->f0.fld.f16r1.fb13 = cm_object_get_child_by_name(state->f0.reg.f16r1, "FB13");
	state->f0.fld.f16r1.fb14 = cm_object_get_child_by_name(state->f0.reg.f16r1, "FB14");
	state->f0.fld.f16r1.fb15 = cm_object_get_child_by_name(state->f0.reg.f16r1, "FB15");
	state->f0.fld.f16r1.fb16 = cm_object_get_child_by_name(state->f0.reg.f16r1, "FB16");
	state->f0.fld.f16r1.fb17 = cm_object_get_child_by_name(state->f0.reg.f16r1, "FB17");
	state->f0.fld.f16r1.fb18 = cm_object_get_child_by_name(state->f0.reg.f16r1, "FB18");
	state->f0.fld.f16r1.fb19 = cm_object_get_child_by_name(state->f0.reg.f16r1, "FB19");
	state->f0.fld.f16r1.fb20 = cm_object_get_child_by_name(state->f0.reg.f16r1, "FB20");
	state->f0.fld.f16r1.fb21 = cm_object_get_child_by_name(state->f0.reg.f16r1, "FB21");
	state->f0.fld.f16r1.fb22 = cm_object_get_child_by_name(state->f0.reg.f16r1, "FB22");
	state->f0.fld.f16r1.fb23 = cm_object_get_child_by_name(state->f0.reg.f16r1, "FB23");
	state->f0.fld.f16r1.fb24 = cm_object_get_child_by_name(state->f0.reg.f16r1, "FB24");
	state->f0.fld.f16r1.fb25 = cm_object_get_child_by_name(state->f0.reg.f16r1, "FB25");
	state->f0.fld.f16r1.fb26 = cm_object_get_child_by_name(state->f0.reg.f16r1, "FB26");
	state->f0.fld.f16r1.fb27 = cm_object_get_child_by_name(state->f0.reg.f16r1, "FB27");
	state->f0.fld.f16r1.fb28 = cm_object_get_child_by_name(state->f0.reg.f16r1, "FB28");
	state->f0.fld.f16r1.fb29 = cm_object_get_child_by_name(state->f0.reg.f16r1, "FB29");
	state->f0.fld.f16r1.fb30 = cm_object_get_child_by_name(state->f0.reg.f16r1, "FB30");
	state->f0.fld.f16r1.fb31 = cm_object_get_child_by_name(state->f0.reg.f16r1, "FB31");

	// F16R2 bitfields.
	state->f0.fld.f16r2.fb0 = cm_object_get_child_by_name(state->f0.reg.f16r2, "FB0");
	state->f0.fld.f16r2.fb1 = cm_object_get_child_by_name(state->f0.reg.f16r2, "FB1");
	state->f0.fld.f16r2.fb2 = cm_object_get_child_by_name(state->f0.reg.f16r2, "FB2");
	state->f0.fld.f16r2.fb3 = cm_object_get_child_by_name(state->f0.reg.f16r2, "FB3");
	state->f0.fld.f16r2.fb4 = cm_object_get_child_by_name(state->f0.reg.f16r2, "FB4");
	state->f0.fld.f16r2.fb5 = cm_object_get_child_by_name(state->f0.reg.f16r2, "FB5");
	state->f0.fld.f16r2.fb6 = cm_object_get_child_by_name(state->f0.reg.f16r2, "FB6");
	state->f0.fld.f16r2.fb7 = cm_object_get_child_by_name(state->f0.reg.f16r2, "FB7");
	state->f0.fld.f16r2.fb8 = cm_object_get_child_by_name(state->f0.reg.f16r2, "FB8");
	state->f0.fld.f16r2.fb9 = cm_object_get_child_by_name(state->f0.reg.f16r2, "FB9");
	state->f0.fld.f16r2.fb10 = cm_object_get_child_by_name(state->f0.reg.f16r2, "FB10");
	state->f0.fld.f16r2.fb11 = cm_object_get_child_by_name(state->f0.reg.f16r2, "FB11");
	state->f0.fld.f16r2.fb12 = cm_object_get_child_by_name(state->f0.reg.f16r2, "FB12");
	state->f0.fld.f16r2.fb13 = cm_object_get_child_by_name(state->f0.reg.f16r2, "FB13");
	state->f0.fld.f16r2.fb14 = cm_object_get_child_by_name(state->f0.reg.f16r2, "FB14");
	state->f0.fld.f16r2.fb15 = cm_object_get_child_by_name(state->f0.reg.f16r2, "FB15");
	state->f0.fld.f16r2.fb16 = cm_object_get_child_by_name(state->f0.reg.f16r2, "FB16");
	state->f0.fld.f16r2.fb17 = cm_object_get_child_by_name(state->f0.reg.f16r2, "FB17");
	state->f0.fld.f16r2.fb18 = cm_object_get_child_by_name(state->f0.reg.f16r2, "FB18");
	state->f0.fld.f16r2.fb19 = cm_object_get_child_by_name(state->f0.reg.f16r2, "FB19");
	state->f0.fld.f16r2.fb20 = cm_object_get_child_by_name(state->f0.reg.f16r2, "FB20");
	state->f0.fld.f16r2.fb21 = cm_object_get_child_by_name(state->f0.reg.f16r2, "FB21");
	state->f0.fld.f16r2.fb22 = cm_object_get_child_by_name(state->f0.reg.f16r2, "FB22");
	state->f0.fld.f16r2.fb23 = cm_object_get_child_by_name(state->f0.reg.f16r2, "FB23");
	state->f0.fld.f16r2.fb24 = cm_object_get_child_by_name(state->f0.reg.f16r2, "FB24");
	state->f0.fld.f16r2.fb25 = cm_object_get_child_by_name(state->f0.reg.f16r2, "FB25");
	state->f0.fld.f16r2.fb26 = cm_object_get_child_by_name(state->f0.reg.f16r2, "FB26");
	state->f0.fld.f16r2.fb27 = cm_object_get_child_by_name(state->f0.reg.f16r2, "FB27");
	state->f0.fld.f16r2.fb28 = cm_object_get_child_by_name(state->f0.reg.f16r2, "FB28");
	state->f0.fld.f16r2.fb29 = cm_object_get_child_by_name(state->f0.reg.f16r2, "FB29");
	state->f0.fld.f16r2.fb30 = cm_object_get_child_by_name(state->f0.reg.f16r2, "FB30");
	state->f0.fld.f16r2.fb31 = cm_object_get_child_by_name(state->f0.reg.f16r2, "FB31");

	// F17R1 bitfields.
	state->f0.fld.f17r1.fb0 = cm_object_get_child_by_name(state->f0.reg.f17r1, "FB0");
	state->f0.fld.f17r1.fb1 = cm_object_get_child_by_name(state->f0.reg.f17r1, "FB1");
	state->f0.fld.f17r1.fb2 = cm_object_get_child_by_name(state->f0.reg.f17r1, "FB2");
	state->f0.fld.f17r1.fb3 = cm_object_get_child_by_name(state->f0.reg.f17r1, "FB3");
	state->f0.fld.f17r1.fb4 = cm_object_get_child_by_name(state->f0.reg.f17r1, "FB4");
	state->f0.fld.f17r1.fb5 = cm_object_get_child_by_name(state->f0.reg.f17r1, "FB5");
	state->f0.fld.f17r1.fb6 = cm_object_get_child_by_name(state->f0.reg.f17r1, "FB6");
	state->f0.fld.f17r1.fb7 = cm_object_get_child_by_name(state->f0.reg.f17r1, "FB7");
	state->f0.fld.f17r1.fb8 = cm_object_get_child_by_name(state->f0.reg.f17r1, "FB8");
	state->f0.fld.f17r1.fb9 = cm_object_get_child_by_name(state->f0.reg.f17r1, "FB9");
	state->f0.fld.f17r1.fb10 = cm_object_get_child_by_name(state->f0.reg.f17r1, "FB10");
	state->f0.fld.f17r1.fb11 = cm_object_get_child_by_name(state->f0.reg.f17r1, "FB11");
	state->f0.fld.f17r1.fb12 = cm_object_get_child_by_name(state->f0.reg.f17r1, "FB12");
	state->f0.fld.f17r1.fb13 = cm_object_get_child_by_name(state->f0.reg.f17r1, "FB13");
	state->f0.fld.f17r1.fb14 = cm_object_get_child_by_name(state->f0.reg.f17r1, "FB14");
	state->f0.fld.f17r1.fb15 = cm_object_get_child_by_name(state->f0.reg.f17r1, "FB15");
	state->f0.fld.f17r1.fb16 = cm_object_get_child_by_name(state->f0.reg.f17r1, "FB16");
	state->f0.fld.f17r1.fb17 = cm_object_get_child_by_name(state->f0.reg.f17r1, "FB17");
	state->f0.fld.f17r1.fb18 = cm_object_get_child_by_name(state->f0.reg.f17r1, "FB18");
	state->f0.fld.f17r1.fb19 = cm_object_get_child_by_name(state->f0.reg.f17r1, "FB19");
	state->f0.fld.f17r1.fb20 = cm_object_get_child_by_name(state->f0.reg.f17r1, "FB20");
	state->f0.fld.f17r1.fb21 = cm_object_get_child_by_name(state->f0.reg.f17r1, "FB21");
	state->f0.fld.f17r1.fb22 = cm_object_get_child_by_name(state->f0.reg.f17r1, "FB22");
	state->f0.fld.f17r1.fb23 = cm_object_get_child_by_name(state->f0.reg.f17r1, "FB23");
	state->f0.fld.f17r1.fb24 = cm_object_get_child_by_name(state->f0.reg.f17r1, "FB24");
	state->f0.fld.f17r1.fb25 = cm_object_get_child_by_name(state->f0.reg.f17r1, "FB25");
	state->f0.fld.f17r1.fb26 = cm_object_get_child_by_name(state->f0.reg.f17r1, "FB26");
	state->f0.fld.f17r1.fb27 = cm_object_get_child_by_name(state->f0.reg.f17r1, "FB27");
	state->f0.fld.f17r1.fb28 = cm_object_get_child_by_name(state->f0.reg.f17r1, "FB28");
	state->f0.fld.f17r1.fb29 = cm_object_get_child_by_name(state->f0.reg.f17r1, "FB29");
	state->f0.fld.f17r1.fb30 = cm_object_get_child_by_name(state->f0.reg.f17r1, "FB30");
	state->f0.fld.f17r1.fb31 = cm_object_get_child_by_name(state->f0.reg.f17r1, "FB31");

	// F17R2 bitfields.
	state->f0.fld.f17r2.fb0 = cm_object_get_child_by_name(state->f0.reg.f17r2, "FB0");
	state->f0.fld.f17r2.fb1 = cm_object_get_child_by_name(state->f0.reg.f17r2, "FB1");
	state->f0.fld.f17r2.fb2 = cm_object_get_child_by_name(state->f0.reg.f17r2, "FB2");
	state->f0.fld.f17r2.fb3 = cm_object_get_child_by_name(state->f0.reg.f17r2, "FB3");
	state->f0.fld.f17r2.fb4 = cm_object_get_child_by_name(state->f0.reg.f17r2, "FB4");
	state->f0.fld.f17r2.fb5 = cm_object_get_child_by_name(state->f0.reg.f17r2, "FB5");
	state->f0.fld.f17r2.fb6 = cm_object_get_child_by_name(state->f0.reg.f17r2, "FB6");
	state->f0.fld.f17r2.fb7 = cm_object_get_child_by_name(state->f0.reg.f17r2, "FB7");
	state->f0.fld.f17r2.fb8 = cm_object_get_child_by_name(state->f0.reg.f17r2, "FB8");
	state->f0.fld.f17r2.fb9 = cm_object_get_child_by_name(state->f0.reg.f17r2, "FB9");
	state->f0.fld.f17r2.fb10 = cm_object_get_child_by_name(state->f0.reg.f17r2, "FB10");
	state->f0.fld.f17r2.fb11 = cm_object_get_child_by_name(state->f0.reg.f17r2, "FB11");
	state->f0.fld.f17r2.fb12 = cm_object_get_child_by_name(state->f0.reg.f17r2, "FB12");
	state->f0.fld.f17r2.fb13 = cm_object_get_child_by_name(state->f0.reg.f17r2, "FB13");
	state->f0.fld.f17r2.fb14 = cm_object_get_child_by_name(state->f0.reg.f17r2, "FB14");
	state->f0.fld.f17r2.fb15 = cm_object_get_child_by_name(state->f0.reg.f17r2, "FB15");
	state->f0.fld.f17r2.fb16 = cm_object_get_child_by_name(state->f0.reg.f17r2, "FB16");
	state->f0.fld.f17r2.fb17 = cm_object_get_child_by_name(state->f0.reg.f17r2, "FB17");
	state->f0.fld.f17r2.fb18 = cm_object_get_child_by_name(state->f0.reg.f17r2, "FB18");
	state->f0.fld.f17r2.fb19 = cm_object_get_child_by_name(state->f0.reg.f17r2, "FB19");
	state->f0.fld.f17r2.fb20 = cm_object_get_child_by_name(state->f0.reg.f17r2, "FB20");
	state->f0.fld.f17r2.fb21 = cm_object_get_child_by_name(state->f0.reg.f17r2, "FB21");
	state->f0.fld.f17r2.fb22 = cm_object_get_child_by_name(state->f0.reg.f17r2, "FB22");
	state->f0.fld.f17r2.fb23 = cm_object_get_child_by_name(state->f0.reg.f17r2, "FB23");
	state->f0.fld.f17r2.fb24 = cm_object_get_child_by_name(state->f0.reg.f17r2, "FB24");
	state->f0.fld.f17r2.fb25 = cm_object_get_child_by_name(state->f0.reg.f17r2, "FB25");
	state->f0.fld.f17r2.fb26 = cm_object_get_child_by_name(state->f0.reg.f17r2, "FB26");
	state->f0.fld.f17r2.fb27 = cm_object_get_child_by_name(state->f0.reg.f17r2, "FB27");
	state->f0.fld.f17r2.fb28 = cm_object_get_child_by_name(state->f0.reg.f17r2, "FB28");
	state->f0.fld.f17r2.fb29 = cm_object_get_child_by_name(state->f0.reg.f17r2, "FB29");
	state->f0.fld.f17r2.fb30 = cm_object_get_child_by_name(state->f0.reg.f17r2, "FB30");
	state->f0.fld.f17r2.fb31 = cm_object_get_child_by_name(state->f0.reg.f17r2, "FB31");

	// F18R1 bitfields.
	state->f0.fld.f18r1.fb0 = cm_object_get_child_by_name(state->f0.reg.f18r1, "FB0");
	state->f0.fld.f18r1.fb1 = cm_object_get_child_by_name(state->f0.reg.f18r1, "FB1");
	state->f0.fld.f18r1.fb2 = cm_object_get_child_by_name(state->f0.reg.f18r1, "FB2");
	state->f0.fld.f18r1.fb3 = cm_object_get_child_by_name(state->f0.reg.f18r1, "FB3");
	state->f0.fld.f18r1.fb4 = cm_object_get_child_by_name(state->f0.reg.f18r1, "FB4");
	state->f0.fld.f18r1.fb5 = cm_object_get_child_by_name(state->f0.reg.f18r1, "FB5");
	state->f0.fld.f18r1.fb6 = cm_object_get_child_by_name(state->f0.reg.f18r1, "FB6");
	state->f0.fld.f18r1.fb7 = cm_object_get_child_by_name(state->f0.reg.f18r1, "FB7");
	state->f0.fld.f18r1.fb8 = cm_object_get_child_by_name(state->f0.reg.f18r1, "FB8");
	state->f0.fld.f18r1.fb9 = cm_object_get_child_by_name(state->f0.reg.f18r1, "FB9");
	state->f0.fld.f18r1.fb10 = cm_object_get_child_by_name(state->f0.reg.f18r1, "FB10");
	state->f0.fld.f18r1.fb11 = cm_object_get_child_by_name(state->f0.reg.f18r1, "FB11");
	state->f0.fld.f18r1.fb12 = cm_object_get_child_by_name(state->f0.reg.f18r1, "FB12");
	state->f0.fld.f18r1.fb13 = cm_object_get_child_by_name(state->f0.reg.f18r1, "FB13");
	state->f0.fld.f18r1.fb14 = cm_object_get_child_by_name(state->f0.reg.f18r1, "FB14");
	state->f0.fld.f18r1.fb15 = cm_object_get_child_by_name(state->f0.reg.f18r1, "FB15");
	state->f0.fld.f18r1.fb16 = cm_object_get_child_by_name(state->f0.reg.f18r1, "FB16");
	state->f0.fld.f18r1.fb17 = cm_object_get_child_by_name(state->f0.reg.f18r1, "FB17");
	state->f0.fld.f18r1.fb18 = cm_object_get_child_by_name(state->f0.reg.f18r1, "FB18");
	state->f0.fld.f18r1.fb19 = cm_object_get_child_by_name(state->f0.reg.f18r1, "FB19");
	state->f0.fld.f18r1.fb20 = cm_object_get_child_by_name(state->f0.reg.f18r1, "FB20");
	state->f0.fld.f18r1.fb21 = cm_object_get_child_by_name(state->f0.reg.f18r1, "FB21");
	state->f0.fld.f18r1.fb22 = cm_object_get_child_by_name(state->f0.reg.f18r1, "FB22");
	state->f0.fld.f18r1.fb23 = cm_object_get_child_by_name(state->f0.reg.f18r1, "FB23");
	state->f0.fld.f18r1.fb24 = cm_object_get_child_by_name(state->f0.reg.f18r1, "FB24");
	state->f0.fld.f18r1.fb25 = cm_object_get_child_by_name(state->f0.reg.f18r1, "FB25");
	state->f0.fld.f18r1.fb26 = cm_object_get_child_by_name(state->f0.reg.f18r1, "FB26");
	state->f0.fld.f18r1.fb27 = cm_object_get_child_by_name(state->f0.reg.f18r1, "FB27");
	state->f0.fld.f18r1.fb28 = cm_object_get_child_by_name(state->f0.reg.f18r1, "FB28");
	state->f0.fld.f18r1.fb29 = cm_object_get_child_by_name(state->f0.reg.f18r1, "FB29");
	state->f0.fld.f18r1.fb30 = cm_object_get_child_by_name(state->f0.reg.f18r1, "FB30");
	state->f0.fld.f18r1.fb31 = cm_object_get_child_by_name(state->f0.reg.f18r1, "FB31");

	// F18R2 bitfields.
	state->f0.fld.f18r2.fb0 = cm_object_get_child_by_name(state->f0.reg.f18r2, "FB0");
	state->f0.fld.f18r2.fb1 = cm_object_get_child_by_name(state->f0.reg.f18r2, "FB1");
	state->f0.fld.f18r2.fb2 = cm_object_get_child_by_name(state->f0.reg.f18r2, "FB2");
	state->f0.fld.f18r2.fb3 = cm_object_get_child_by_name(state->f0.reg.f18r2, "FB3");
	state->f0.fld.f18r2.fb4 = cm_object_get_child_by_name(state->f0.reg.f18r2, "FB4");
	state->f0.fld.f18r2.fb5 = cm_object_get_child_by_name(state->f0.reg.f18r2, "FB5");
	state->f0.fld.f18r2.fb6 = cm_object_get_child_by_name(state->f0.reg.f18r2, "FB6");
	state->f0.fld.f18r2.fb7 = cm_object_get_child_by_name(state->f0.reg.f18r2, "FB7");
	state->f0.fld.f18r2.fb8 = cm_object_get_child_by_name(state->f0.reg.f18r2, "FB8");
	state->f0.fld.f18r2.fb9 = cm_object_get_child_by_name(state->f0.reg.f18r2, "FB9");
	state->f0.fld.f18r2.fb10 = cm_object_get_child_by_name(state->f0.reg.f18r2, "FB10");
	state->f0.fld.f18r2.fb11 = cm_object_get_child_by_name(state->f0.reg.f18r2, "FB11");
	state->f0.fld.f18r2.fb12 = cm_object_get_child_by_name(state->f0.reg.f18r2, "FB12");
	state->f0.fld.f18r2.fb13 = cm_object_get_child_by_name(state->f0.reg.f18r2, "FB13");
	state->f0.fld.f18r2.fb14 = cm_object_get_child_by_name(state->f0.reg.f18r2, "FB14");
	state->f0.fld.f18r2.fb15 = cm_object_get_child_by_name(state->f0.reg.f18r2, "FB15");
	state->f0.fld.f18r2.fb16 = cm_object_get_child_by_name(state->f0.reg.f18r2, "FB16");
	state->f0.fld.f18r2.fb17 = cm_object_get_child_by_name(state->f0.reg.f18r2, "FB17");
	state->f0.fld.f18r2.fb18 = cm_object_get_child_by_name(state->f0.reg.f18r2, "FB18");
	state->f0.fld.f18r2.fb19 = cm_object_get_child_by_name(state->f0.reg.f18r2, "FB19");
	state->f0.fld.f18r2.fb20 = cm_object_get_child_by_name(state->f0.reg.f18r2, "FB20");
	state->f0.fld.f18r2.fb21 = cm_object_get_child_by_name(state->f0.reg.f18r2, "FB21");
	state->f0.fld.f18r2.fb22 = cm_object_get_child_by_name(state->f0.reg.f18r2, "FB22");
	state->f0.fld.f18r2.fb23 = cm_object_get_child_by_name(state->f0.reg.f18r2, "FB23");
	state->f0.fld.f18r2.fb24 = cm_object_get_child_by_name(state->f0.reg.f18r2, "FB24");
	state->f0.fld.f18r2.fb25 = cm_object_get_child_by_name(state->f0.reg.f18r2, "FB25");
	state->f0.fld.f18r2.fb26 = cm_object_get_child_by_name(state->f0.reg.f18r2, "FB26");
	state->f0.fld.f18r2.fb27 = cm_object_get_child_by_name(state->f0.reg.f18r2, "FB27");
	state->f0.fld.f18r2.fb28 = cm_object_get_child_by_name(state->f0.reg.f18r2, "FB28");
	state->f0.fld.f18r2.fb29 = cm_object_get_child_by_name(state->f0.reg.f18r2, "FB29");
	state->f0.fld.f18r2.fb30 = cm_object_get_child_by_name(state->f0.reg.f18r2, "FB30");
	state->f0.fld.f18r2.fb31 = cm_object_get_child_by_name(state->f0.reg.f18r2, "FB31");

	// F19R1 bitfields.
	state->f0.fld.f19r1.fb0 = cm_object_get_child_by_name(state->f0.reg.f19r1, "FB0");
	state->f0.fld.f19r1.fb1 = cm_object_get_child_by_name(state->f0.reg.f19r1, "FB1");
	state->f0.fld.f19r1.fb2 = cm_object_get_child_by_name(state->f0.reg.f19r1, "FB2");
	state->f0.fld.f19r1.fb3 = cm_object_get_child_by_name(state->f0.reg.f19r1, "FB3");
	state->f0.fld.f19r1.fb4 = cm_object_get_child_by_name(state->f0.reg.f19r1, "FB4");
	state->f0.fld.f19r1.fb5 = cm_object_get_child_by_name(state->f0.reg.f19r1, "FB5");
	state->f0.fld.f19r1.fb6 = cm_object_get_child_by_name(state->f0.reg.f19r1, "FB6");
	state->f0.fld.f19r1.fb7 = cm_object_get_child_by_name(state->f0.reg.f19r1, "FB7");
	state->f0.fld.f19r1.fb8 = cm_object_get_child_by_name(state->f0.reg.f19r1, "FB8");
	state->f0.fld.f19r1.fb9 = cm_object_get_child_by_name(state->f0.reg.f19r1, "FB9");
	state->f0.fld.f19r1.fb10 = cm_object_get_child_by_name(state->f0.reg.f19r1, "FB10");
	state->f0.fld.f19r1.fb11 = cm_object_get_child_by_name(state->f0.reg.f19r1, "FB11");
	state->f0.fld.f19r1.fb12 = cm_object_get_child_by_name(state->f0.reg.f19r1, "FB12");
	state->f0.fld.f19r1.fb13 = cm_object_get_child_by_name(state->f0.reg.f19r1, "FB13");
	state->f0.fld.f19r1.fb14 = cm_object_get_child_by_name(state->f0.reg.f19r1, "FB14");
	state->f0.fld.f19r1.fb15 = cm_object_get_child_by_name(state->f0.reg.f19r1, "FB15");
	state->f0.fld.f19r1.fb16 = cm_object_get_child_by_name(state->f0.reg.f19r1, "FB16");
	state->f0.fld.f19r1.fb17 = cm_object_get_child_by_name(state->f0.reg.f19r1, "FB17");
	state->f0.fld.f19r1.fb18 = cm_object_get_child_by_name(state->f0.reg.f19r1, "FB18");
	state->f0.fld.f19r1.fb19 = cm_object_get_child_by_name(state->f0.reg.f19r1, "FB19");
	state->f0.fld.f19r1.fb20 = cm_object_get_child_by_name(state->f0.reg.f19r1, "FB20");
	state->f0.fld.f19r1.fb21 = cm_object_get_child_by_name(state->f0.reg.f19r1, "FB21");
	state->f0.fld.f19r1.fb22 = cm_object_get_child_by_name(state->f0.reg.f19r1, "FB22");
	state->f0.fld.f19r1.fb23 = cm_object_get_child_by_name(state->f0.reg.f19r1, "FB23");
	state->f0.fld.f19r1.fb24 = cm_object_get_child_by_name(state->f0.reg.f19r1, "FB24");
	state->f0.fld.f19r1.fb25 = cm_object_get_child_by_name(state->f0.reg.f19r1, "FB25");
	state->f0.fld.f19r1.fb26 = cm_object_get_child_by_name(state->f0.reg.f19r1, "FB26");
	state->f0.fld.f19r1.fb27 = cm_object_get_child_by_name(state->f0.reg.f19r1, "FB27");
	state->f0.fld.f19r1.fb28 = cm_object_get_child_by_name(state->f0.reg.f19r1, "FB28");
	state->f0.fld.f19r1.fb29 = cm_object_get_child_by_name(state->f0.reg.f19r1, "FB29");
	state->f0.fld.f19r1.fb30 = cm_object_get_child_by_name(state->f0.reg.f19r1, "FB30");
	state->f0.fld.f19r1.fb31 = cm_object_get_child_by_name(state->f0.reg.f19r1, "FB31");

	// F19R2 bitfields.
	state->f0.fld.f19r2.fb0 = cm_object_get_child_by_name(state->f0.reg.f19r2, "FB0");
	state->f0.fld.f19r2.fb1 = cm_object_get_child_by_name(state->f0.reg.f19r2, "FB1");
	state->f0.fld.f19r2.fb2 = cm_object_get_child_by_name(state->f0.reg.f19r2, "FB2");
	state->f0.fld.f19r2.fb3 = cm_object_get_child_by_name(state->f0.reg.f19r2, "FB3");
	state->f0.fld.f19r2.fb4 = cm_object_get_child_by_name(state->f0.reg.f19r2, "FB4");
	state->f0.fld.f19r2.fb5 = cm_object_get_child_by_name(state->f0.reg.f19r2, "FB5");
	state->f0.fld.f19r2.fb6 = cm_object_get_child_by_name(state->f0.reg.f19r2, "FB6");
	state->f0.fld.f19r2.fb7 = cm_object_get_child_by_name(state->f0.reg.f19r2, "FB7");
	state->f0.fld.f19r2.fb8 = cm_object_get_child_by_name(state->f0.reg.f19r2, "FB8");
	state->f0.fld.f19r2.fb9 = cm_object_get_child_by_name(state->f0.reg.f19r2, "FB9");
	state->f0.fld.f19r2.fb10 = cm_object_get_child_by_name(state->f0.reg.f19r2, "FB10");
	state->f0.fld.f19r2.fb11 = cm_object_get_child_by_name(state->f0.reg.f19r2, "FB11");
	state->f0.fld.f19r2.fb12 = cm_object_get_child_by_name(state->f0.reg.f19r2, "FB12");
	state->f0.fld.f19r2.fb13 = cm_object_get_child_by_name(state->f0.reg.f19r2, "FB13");
	state->f0.fld.f19r2.fb14 = cm_object_get_child_by_name(state->f0.reg.f19r2, "FB14");
	state->f0.fld.f19r2.fb15 = cm_object_get_child_by_name(state->f0.reg.f19r2, "FB15");
	state->f0.fld.f19r2.fb16 = cm_object_get_child_by_name(state->f0.reg.f19r2, "FB16");
	state->f0.fld.f19r2.fb17 = cm_object_get_child_by_name(state->f0.reg.f19r2, "FB17");
	state->f0.fld.f19r2.fb18 = cm_object_get_child_by_name(state->f0.reg.f19r2, "FB18");
	state->f0.fld.f19r2.fb19 = cm_object_get_child_by_name(state->f0.reg.f19r2, "FB19");
	state->f0.fld.f19r2.fb20 = cm_object_get_child_by_name(state->f0.reg.f19r2, "FB20");
	state->f0.fld.f19r2.fb21 = cm_object_get_child_by_name(state->f0.reg.f19r2, "FB21");
	state->f0.fld.f19r2.fb22 = cm_object_get_child_by_name(state->f0.reg.f19r2, "FB22");
	state->f0.fld.f19r2.fb23 = cm_object_get_child_by_name(state->f0.reg.f19r2, "FB23");
	state->f0.fld.f19r2.fb24 = cm_object_get_child_by_name(state->f0.reg.f19r2, "FB24");
	state->f0.fld.f19r2.fb25 = cm_object_get_child_by_name(state->f0.reg.f19r2, "FB25");
	state->f0.fld.f19r2.fb26 = cm_object_get_child_by_name(state->f0.reg.f19r2, "FB26");
	state->f0.fld.f19r2.fb27 = cm_object_get_child_by_name(state->f0.reg.f19r2, "FB27");
	state->f0.fld.f19r2.fb28 = cm_object_get_child_by_name(state->f0.reg.f19r2, "FB28");
	state->f0.fld.f19r2.fb29 = cm_object_get_child_by_name(state->f0.reg.f19r2, "FB29");
	state->f0.fld.f19r2.fb30 = cm_object_get_child_by_name(state->f0.reg.f19r2, "FB30");
	state->f0.fld.f19r2.fb31 = cm_object_get_child_by_name(state->f0.reg.f19r2, "FB31");

	// F20R1 bitfields.
	state->f0.fld.f20r1.fb0 = cm_object_get_child_by_name(state->f0.reg.f20r1, "FB0");
	state->f0.fld.f20r1.fb1 = cm_object_get_child_by_name(state->f0.reg.f20r1, "FB1");
	state->f0.fld.f20r1.fb2 = cm_object_get_child_by_name(state->f0.reg.f20r1, "FB2");
	state->f0.fld.f20r1.fb3 = cm_object_get_child_by_name(state->f0.reg.f20r1, "FB3");
	state->f0.fld.f20r1.fb4 = cm_object_get_child_by_name(state->f0.reg.f20r1, "FB4");
	state->f0.fld.f20r1.fb5 = cm_object_get_child_by_name(state->f0.reg.f20r1, "FB5");
	state->f0.fld.f20r1.fb6 = cm_object_get_child_by_name(state->f0.reg.f20r1, "FB6");
	state->f0.fld.f20r1.fb7 = cm_object_get_child_by_name(state->f0.reg.f20r1, "FB7");
	state->f0.fld.f20r1.fb8 = cm_object_get_child_by_name(state->f0.reg.f20r1, "FB8");
	state->f0.fld.f20r1.fb9 = cm_object_get_child_by_name(state->f0.reg.f20r1, "FB9");
	state->f0.fld.f20r1.fb10 = cm_object_get_child_by_name(state->f0.reg.f20r1, "FB10");
	state->f0.fld.f20r1.fb11 = cm_object_get_child_by_name(state->f0.reg.f20r1, "FB11");
	state->f0.fld.f20r1.fb12 = cm_object_get_child_by_name(state->f0.reg.f20r1, "FB12");
	state->f0.fld.f20r1.fb13 = cm_object_get_child_by_name(state->f0.reg.f20r1, "FB13");
	state->f0.fld.f20r1.fb14 = cm_object_get_child_by_name(state->f0.reg.f20r1, "FB14");
	state->f0.fld.f20r1.fb15 = cm_object_get_child_by_name(state->f0.reg.f20r1, "FB15");
	state->f0.fld.f20r1.fb16 = cm_object_get_child_by_name(state->f0.reg.f20r1, "FB16");
	state->f0.fld.f20r1.fb17 = cm_object_get_child_by_name(state->f0.reg.f20r1, "FB17");
	state->f0.fld.f20r1.fb18 = cm_object_get_child_by_name(state->f0.reg.f20r1, "FB18");
	state->f0.fld.f20r1.fb19 = cm_object_get_child_by_name(state->f0.reg.f20r1, "FB19");
	state->f0.fld.f20r1.fb20 = cm_object_get_child_by_name(state->f0.reg.f20r1, "FB20");
	state->f0.fld.f20r1.fb21 = cm_object_get_child_by_name(state->f0.reg.f20r1, "FB21");
	state->f0.fld.f20r1.fb22 = cm_object_get_child_by_name(state->f0.reg.f20r1, "FB22");
	state->f0.fld.f20r1.fb23 = cm_object_get_child_by_name(state->f0.reg.f20r1, "FB23");
	state->f0.fld.f20r1.fb24 = cm_object_get_child_by_name(state->f0.reg.f20r1, "FB24");
	state->f0.fld.f20r1.fb25 = cm_object_get_child_by_name(state->f0.reg.f20r1, "FB25");
	state->f0.fld.f20r1.fb26 = cm_object_get_child_by_name(state->f0.reg.f20r1, "FB26");
	state->f0.fld.f20r1.fb27 = cm_object_get_child_by_name(state->f0.reg.f20r1, "FB27");
	state->f0.fld.f20r1.fb28 = cm_object_get_child_by_name(state->f0.reg.f20r1, "FB28");
	state->f0.fld.f20r1.fb29 = cm_object_get_child_by_name(state->f0.reg.f20r1, "FB29");
	state->f0.fld.f20r1.fb30 = cm_object_get_child_by_name(state->f0.reg.f20r1, "FB30");
	state->f0.fld.f20r1.fb31 = cm_object_get_child_by_name(state->f0.reg.f20r1, "FB31");

	// F20R2 bitfields.
	state->f0.fld.f20r2.fb0 = cm_object_get_child_by_name(state->f0.reg.f20r2, "FB0");
	state->f0.fld.f20r2.fb1 = cm_object_get_child_by_name(state->f0.reg.f20r2, "FB1");
	state->f0.fld.f20r2.fb2 = cm_object_get_child_by_name(state->f0.reg.f20r2, "FB2");
	state->f0.fld.f20r2.fb3 = cm_object_get_child_by_name(state->f0.reg.f20r2, "FB3");
	state->f0.fld.f20r2.fb4 = cm_object_get_child_by_name(state->f0.reg.f20r2, "FB4");
	state->f0.fld.f20r2.fb5 = cm_object_get_child_by_name(state->f0.reg.f20r2, "FB5");
	state->f0.fld.f20r2.fb6 = cm_object_get_child_by_name(state->f0.reg.f20r2, "FB6");
	state->f0.fld.f20r2.fb7 = cm_object_get_child_by_name(state->f0.reg.f20r2, "FB7");
	state->f0.fld.f20r2.fb8 = cm_object_get_child_by_name(state->f0.reg.f20r2, "FB8");
	state->f0.fld.f20r2.fb9 = cm_object_get_child_by_name(state->f0.reg.f20r2, "FB9");
	state->f0.fld.f20r2.fb10 = cm_object_get_child_by_name(state->f0.reg.f20r2, "FB10");
	state->f0.fld.f20r2.fb11 = cm_object_get_child_by_name(state->f0.reg.f20r2, "FB11");
	state->f0.fld.f20r2.fb12 = cm_object_get_child_by_name(state->f0.reg.f20r2, "FB12");
	state->f0.fld.f20r2.fb13 = cm_object_get_child_by_name(state->f0.reg.f20r2, "FB13");
	state->f0.fld.f20r2.fb14 = cm_object_get_child_by_name(state->f0.reg.f20r2, "FB14");
	state->f0.fld.f20r2.fb15 = cm_object_get_child_by_name(state->f0.reg.f20r2, "FB15");
	state->f0.fld.f20r2.fb16 = cm_object_get_child_by_name(state->f0.reg.f20r2, "FB16");
	state->f0.fld.f20r2.fb17 = cm_object_get_child_by_name(state->f0.reg.f20r2, "FB17");
	state->f0.fld.f20r2.fb18 = cm_object_get_child_by_name(state->f0.reg.f20r2, "FB18");
	state->f0.fld.f20r2.fb19 = cm_object_get_child_by_name(state->f0.reg.f20r2, "FB19");
	state->f0.fld.f20r2.fb20 = cm_object_get_child_by_name(state->f0.reg.f20r2, "FB20");
	state->f0.fld.f20r2.fb21 = cm_object_get_child_by_name(state->f0.reg.f20r2, "FB21");
	state->f0.fld.f20r2.fb22 = cm_object_get_child_by_name(state->f0.reg.f20r2, "FB22");
	state->f0.fld.f20r2.fb23 = cm_object_get_child_by_name(state->f0.reg.f20r2, "FB23");
	state->f0.fld.f20r2.fb24 = cm_object_get_child_by_name(state->f0.reg.f20r2, "FB24");
	state->f0.fld.f20r2.fb25 = cm_object_get_child_by_name(state->f0.reg.f20r2, "FB25");
	state->f0.fld.f20r2.fb26 = cm_object_get_child_by_name(state->f0.reg.f20r2, "FB26");
	state->f0.fld.f20r2.fb27 = cm_object_get_child_by_name(state->f0.reg.f20r2, "FB27");
	state->f0.fld.f20r2.fb28 = cm_object_get_child_by_name(state->f0.reg.f20r2, "FB28");
	state->f0.fld.f20r2.fb29 = cm_object_get_child_by_name(state->f0.reg.f20r2, "FB29");
	state->f0.fld.f20r2.fb30 = cm_object_get_child_by_name(state->f0.reg.f20r2, "FB30");
	state->f0.fld.f20r2.fb31 = cm_object_get_child_by_name(state->f0.reg.f20r2, "FB31");

	// F21R1 bitfields.
	state->f0.fld.f21r1.fb0 = cm_object_get_child_by_name(state->f0.reg.f21r1, "FB0");
	state->f0.fld.f21r1.fb1 = cm_object_get_child_by_name(state->f0.reg.f21r1, "FB1");
	state->f0.fld.f21r1.fb2 = cm_object_get_child_by_name(state->f0.reg.f21r1, "FB2");
	state->f0.fld.f21r1.fb3 = cm_object_get_child_by_name(state->f0.reg.f21r1, "FB3");
	state->f0.fld.f21r1.fb4 = cm_object_get_child_by_name(state->f0.reg.f21r1, "FB4");
	state->f0.fld.f21r1.fb5 = cm_object_get_child_by_name(state->f0.reg.f21r1, "FB5");
	state->f0.fld.f21r1.fb6 = cm_object_get_child_by_name(state->f0.reg.f21r1, "FB6");
	state->f0.fld.f21r1.fb7 = cm_object_get_child_by_name(state->f0.reg.f21r1, "FB7");
	state->f0.fld.f21r1.fb8 = cm_object_get_child_by_name(state->f0.reg.f21r1, "FB8");
	state->f0.fld.f21r1.fb9 = cm_object_get_child_by_name(state->f0.reg.f21r1, "FB9");
	state->f0.fld.f21r1.fb10 = cm_object_get_child_by_name(state->f0.reg.f21r1, "FB10");
	state->f0.fld.f21r1.fb11 = cm_object_get_child_by_name(state->f0.reg.f21r1, "FB11");
	state->f0.fld.f21r1.fb12 = cm_object_get_child_by_name(state->f0.reg.f21r1, "FB12");
	state->f0.fld.f21r1.fb13 = cm_object_get_child_by_name(state->f0.reg.f21r1, "FB13");
	state->f0.fld.f21r1.fb14 = cm_object_get_child_by_name(state->f0.reg.f21r1, "FB14");
	state->f0.fld.f21r1.fb15 = cm_object_get_child_by_name(state->f0.reg.f21r1, "FB15");
	state->f0.fld.f21r1.fb16 = cm_object_get_child_by_name(state->f0.reg.f21r1, "FB16");
	state->f0.fld.f21r1.fb17 = cm_object_get_child_by_name(state->f0.reg.f21r1, "FB17");
	state->f0.fld.f21r1.fb18 = cm_object_get_child_by_name(state->f0.reg.f21r1, "FB18");
	state->f0.fld.f21r1.fb19 = cm_object_get_child_by_name(state->f0.reg.f21r1, "FB19");
	state->f0.fld.f21r1.fb20 = cm_object_get_child_by_name(state->f0.reg.f21r1, "FB20");
	state->f0.fld.f21r1.fb21 = cm_object_get_child_by_name(state->f0.reg.f21r1, "FB21");
	state->f0.fld.f21r1.fb22 = cm_object_get_child_by_name(state->f0.reg.f21r1, "FB22");
	state->f0.fld.f21r1.fb23 = cm_object_get_child_by_name(state->f0.reg.f21r1, "FB23");
	state->f0.fld.f21r1.fb24 = cm_object_get_child_by_name(state->f0.reg.f21r1, "FB24");
	state->f0.fld.f21r1.fb25 = cm_object_get_child_by_name(state->f0.reg.f21r1, "FB25");
	state->f0.fld.f21r1.fb26 = cm_object_get_child_by_name(state->f0.reg.f21r1, "FB26");
	state->f0.fld.f21r1.fb27 = cm_object_get_child_by_name(state->f0.reg.f21r1, "FB27");
	state->f0.fld.f21r1.fb28 = cm_object_get_child_by_name(state->f0.reg.f21r1, "FB28");
	state->f0.fld.f21r1.fb29 = cm_object_get_child_by_name(state->f0.reg.f21r1, "FB29");
	state->f0.fld.f21r1.fb30 = cm_object_get_child_by_name(state->f0.reg.f21r1, "FB30");
	state->f0.fld.f21r1.fb31 = cm_object_get_child_by_name(state->f0.reg.f21r1, "FB31");

	// F21R2 bitfields.
	state->f0.fld.f21r2.fb0 = cm_object_get_child_by_name(state->f0.reg.f21r2, "FB0");
	state->f0.fld.f21r2.fb1 = cm_object_get_child_by_name(state->f0.reg.f21r2, "FB1");
	state->f0.fld.f21r2.fb2 = cm_object_get_child_by_name(state->f0.reg.f21r2, "FB2");
	state->f0.fld.f21r2.fb3 = cm_object_get_child_by_name(state->f0.reg.f21r2, "FB3");
	state->f0.fld.f21r2.fb4 = cm_object_get_child_by_name(state->f0.reg.f21r2, "FB4");
	state->f0.fld.f21r2.fb5 = cm_object_get_child_by_name(state->f0.reg.f21r2, "FB5");
	state->f0.fld.f21r2.fb6 = cm_object_get_child_by_name(state->f0.reg.f21r2, "FB6");
	state->f0.fld.f21r2.fb7 = cm_object_get_child_by_name(state->f0.reg.f21r2, "FB7");
	state->f0.fld.f21r2.fb8 = cm_object_get_child_by_name(state->f0.reg.f21r2, "FB8");
	state->f0.fld.f21r2.fb9 = cm_object_get_child_by_name(state->f0.reg.f21r2, "FB9");
	state->f0.fld.f21r2.fb10 = cm_object_get_child_by_name(state->f0.reg.f21r2, "FB10");
	state->f0.fld.f21r2.fb11 = cm_object_get_child_by_name(state->f0.reg.f21r2, "FB11");
	state->f0.fld.f21r2.fb12 = cm_object_get_child_by_name(state->f0.reg.f21r2, "FB12");
	state->f0.fld.f21r2.fb13 = cm_object_get_child_by_name(state->f0.reg.f21r2, "FB13");
	state->f0.fld.f21r2.fb14 = cm_object_get_child_by_name(state->f0.reg.f21r2, "FB14");
	state->f0.fld.f21r2.fb15 = cm_object_get_child_by_name(state->f0.reg.f21r2, "FB15");
	state->f0.fld.f21r2.fb16 = cm_object_get_child_by_name(state->f0.reg.f21r2, "FB16");
	state->f0.fld.f21r2.fb17 = cm_object_get_child_by_name(state->f0.reg.f21r2, "FB17");
	state->f0.fld.f21r2.fb18 = cm_object_get_child_by_name(state->f0.reg.f21r2, "FB18");
	state->f0.fld.f21r2.fb19 = cm_object_get_child_by_name(state->f0.reg.f21r2, "FB19");
	state->f0.fld.f21r2.fb20 = cm_object_get_child_by_name(state->f0.reg.f21r2, "FB20");
	state->f0.fld.f21r2.fb21 = cm_object_get_child_by_name(state->f0.reg.f21r2, "FB21");
	state->f0.fld.f21r2.fb22 = cm_object_get_child_by_name(state->f0.reg.f21r2, "FB22");
	state->f0.fld.f21r2.fb23 = cm_object_get_child_by_name(state->f0.reg.f21r2, "FB23");
	state->f0.fld.f21r2.fb24 = cm_object_get_child_by_name(state->f0.reg.f21r2, "FB24");
	state->f0.fld.f21r2.fb25 = cm_object_get_child_by_name(state->f0.reg.f21r2, "FB25");
	state->f0.fld.f21r2.fb26 = cm_object_get_child_by_name(state->f0.reg.f21r2, "FB26");
	state->f0.fld.f21r2.fb27 = cm_object_get_child_by_name(state->f0.reg.f21r2, "FB27");
	state->f0.fld.f21r2.fb28 = cm_object_get_child_by_name(state->f0.reg.f21r2, "FB28");
	state->f0.fld.f21r2.fb29 = cm_object_get_child_by_name(state->f0.reg.f21r2, "FB29");
	state->f0.fld.f21r2.fb30 = cm_object_get_child_by_name(state->f0.reg.f21r2, "FB30");
	state->f0.fld.f21r2.fb31 = cm_object_get_child_by_name(state->f0.reg.f21r2, "FB31");

	// F22R1 bitfields.
	state->f0.fld.f22r1.fb0 = cm_object_get_child_by_name(state->f0.reg.f22r1, "FB0");
	state->f0.fld.f22r1.fb1 = cm_object_get_child_by_name(state->f0.reg.f22r1, "FB1");
	state->f0.fld.f22r1.fb2 = cm_object_get_child_by_name(state->f0.reg.f22r1, "FB2");
	state->f0.fld.f22r1.fb3 = cm_object_get_child_by_name(state->f0.reg.f22r1, "FB3");
	state->f0.fld.f22r1.fb4 = cm_object_get_child_by_name(state->f0.reg.f22r1, "FB4");
	state->f0.fld.f22r1.fb5 = cm_object_get_child_by_name(state->f0.reg.f22r1, "FB5");
	state->f0.fld.f22r1.fb6 = cm_object_get_child_by_name(state->f0.reg.f22r1, "FB6");
	state->f0.fld.f22r1.fb7 = cm_object_get_child_by_name(state->f0.reg.f22r1, "FB7");
	state->f0.fld.f22r1.fb8 = cm_object_get_child_by_name(state->f0.reg.f22r1, "FB8");
	state->f0.fld.f22r1.fb9 = cm_object_get_child_by_name(state->f0.reg.f22r1, "FB9");
	state->f0.fld.f22r1.fb10 = cm_object_get_child_by_name(state->f0.reg.f22r1, "FB10");
	state->f0.fld.f22r1.fb11 = cm_object_get_child_by_name(state->f0.reg.f22r1, "FB11");
	state->f0.fld.f22r1.fb12 = cm_object_get_child_by_name(state->f0.reg.f22r1, "FB12");
	state->f0.fld.f22r1.fb13 = cm_object_get_child_by_name(state->f0.reg.f22r1, "FB13");
	state->f0.fld.f22r1.fb14 = cm_object_get_child_by_name(state->f0.reg.f22r1, "FB14");
	state->f0.fld.f22r1.fb15 = cm_object_get_child_by_name(state->f0.reg.f22r1, "FB15");
	state->f0.fld.f22r1.fb16 = cm_object_get_child_by_name(state->f0.reg.f22r1, "FB16");
	state->f0.fld.f22r1.fb17 = cm_object_get_child_by_name(state->f0.reg.f22r1, "FB17");
	state->f0.fld.f22r1.fb18 = cm_object_get_child_by_name(state->f0.reg.f22r1, "FB18");
	state->f0.fld.f22r1.fb19 = cm_object_get_child_by_name(state->f0.reg.f22r1, "FB19");
	state->f0.fld.f22r1.fb20 = cm_object_get_child_by_name(state->f0.reg.f22r1, "FB20");
	state->f0.fld.f22r1.fb21 = cm_object_get_child_by_name(state->f0.reg.f22r1, "FB21");
	state->f0.fld.f22r1.fb22 = cm_object_get_child_by_name(state->f0.reg.f22r1, "FB22");
	state->f0.fld.f22r1.fb23 = cm_object_get_child_by_name(state->f0.reg.f22r1, "FB23");
	state->f0.fld.f22r1.fb24 = cm_object_get_child_by_name(state->f0.reg.f22r1, "FB24");
	state->f0.fld.f22r1.fb25 = cm_object_get_child_by_name(state->f0.reg.f22r1, "FB25");
	state->f0.fld.f22r1.fb26 = cm_object_get_child_by_name(state->f0.reg.f22r1, "FB26");
	state->f0.fld.f22r1.fb27 = cm_object_get_child_by_name(state->f0.reg.f22r1, "FB27");
	state->f0.fld.f22r1.fb28 = cm_object_get_child_by_name(state->f0.reg.f22r1, "FB28");
	state->f0.fld.f22r1.fb29 = cm_object_get_child_by_name(state->f0.reg.f22r1, "FB29");
	state->f0.fld.f22r1.fb30 = cm_object_get_child_by_name(state->f0.reg.f22r1, "FB30");
	state->f0.fld.f22r1.fb31 = cm_object_get_child_by_name(state->f0.reg.f22r1, "FB31");

	// F22R2 bitfields.
	state->f0.fld.f22r2.fb0 = cm_object_get_child_by_name(state->f0.reg.f22r2, "FB0");
	state->f0.fld.f22r2.fb1 = cm_object_get_child_by_name(state->f0.reg.f22r2, "FB1");
	state->f0.fld.f22r2.fb2 = cm_object_get_child_by_name(state->f0.reg.f22r2, "FB2");
	state->f0.fld.f22r2.fb3 = cm_object_get_child_by_name(state->f0.reg.f22r2, "FB3");
	state->f0.fld.f22r2.fb4 = cm_object_get_child_by_name(state->f0.reg.f22r2, "FB4");
	state->f0.fld.f22r2.fb5 = cm_object_get_child_by_name(state->f0.reg.f22r2, "FB5");
	state->f0.fld.f22r2.fb6 = cm_object_get_child_by_name(state->f0.reg.f22r2, "FB6");
	state->f0.fld.f22r2.fb7 = cm_object_get_child_by_name(state->f0.reg.f22r2, "FB7");
	state->f0.fld.f22r2.fb8 = cm_object_get_child_by_name(state->f0.reg.f22r2, "FB8");
	state->f0.fld.f22r2.fb9 = cm_object_get_child_by_name(state->f0.reg.f22r2, "FB9");
	state->f0.fld.f22r2.fb10 = cm_object_get_child_by_name(state->f0.reg.f22r2, "FB10");
	state->f0.fld.f22r2.fb11 = cm_object_get_child_by_name(state->f0.reg.f22r2, "FB11");
	state->f0.fld.f22r2.fb12 = cm_object_get_child_by_name(state->f0.reg.f22r2, "FB12");
	state->f0.fld.f22r2.fb13 = cm_object_get_child_by_name(state->f0.reg.f22r2, "FB13");
	state->f0.fld.f22r2.fb14 = cm_object_get_child_by_name(state->f0.reg.f22r2, "FB14");
	state->f0.fld.f22r2.fb15 = cm_object_get_child_by_name(state->f0.reg.f22r2, "FB15");
	state->f0.fld.f22r2.fb16 = cm_object_get_child_by_name(state->f0.reg.f22r2, "FB16");
	state->f0.fld.f22r2.fb17 = cm_object_get_child_by_name(state->f0.reg.f22r2, "FB17");
	state->f0.fld.f22r2.fb18 = cm_object_get_child_by_name(state->f0.reg.f22r2, "FB18");
	state->f0.fld.f22r2.fb19 = cm_object_get_child_by_name(state->f0.reg.f22r2, "FB19");
	state->f0.fld.f22r2.fb20 = cm_object_get_child_by_name(state->f0.reg.f22r2, "FB20");
	state->f0.fld.f22r2.fb21 = cm_object_get_child_by_name(state->f0.reg.f22r2, "FB21");
	state->f0.fld.f22r2.fb22 = cm_object_get_child_by_name(state->f0.reg.f22r2, "FB22");
	state->f0.fld.f22r2.fb23 = cm_object_get_child_by_name(state->f0.reg.f22r2, "FB23");
	state->f0.fld.f22r2.fb24 = cm_object_get_child_by_name(state->f0.reg.f22r2, "FB24");
	state->f0.fld.f22r2.fb25 = cm_object_get_child_by_name(state->f0.reg.f22r2, "FB25");
	state->f0.fld.f22r2.fb26 = cm_object_get_child_by_name(state->f0.reg.f22r2, "FB26");
	state->f0.fld.f22r2.fb27 = cm_object_get_child_by_name(state->f0.reg.f22r2, "FB27");
	state->f0.fld.f22r2.fb28 = cm_object_get_child_by_name(state->f0.reg.f22r2, "FB28");
	state->f0.fld.f22r2.fb29 = cm_object_get_child_by_name(state->f0.reg.f22r2, "FB29");
	state->f0.fld.f22r2.fb30 = cm_object_get_child_by_name(state->f0.reg.f22r2, "FB30");
	state->f0.fld.f22r2.fb31 = cm_object_get_child_by_name(state->f0.reg.f22r2, "FB31");

	// F23R1 bitfields.
	state->f0.fld.f23r1.fb0 = cm_object_get_child_by_name(state->f0.reg.f23r1, "FB0");
	state->f0.fld.f23r1.fb1 = cm_object_get_child_by_name(state->f0.reg.f23r1, "FB1");
	state->f0.fld.f23r1.fb2 = cm_object_get_child_by_name(state->f0.reg.f23r1, "FB2");
	state->f0.fld.f23r1.fb3 = cm_object_get_child_by_name(state->f0.reg.f23r1, "FB3");
	state->f0.fld.f23r1.fb4 = cm_object_get_child_by_name(state->f0.reg.f23r1, "FB4");
	state->f0.fld.f23r1.fb5 = cm_object_get_child_by_name(state->f0.reg.f23r1, "FB5");
	state->f0.fld.f23r1.fb6 = cm_object_get_child_by_name(state->f0.reg.f23r1, "FB6");
	state->f0.fld.f23r1.fb7 = cm_object_get_child_by_name(state->f0.reg.f23r1, "FB7");
	state->f0.fld.f23r1.fb8 = cm_object_get_child_by_name(state->f0.reg.f23r1, "FB8");
	state->f0.fld.f23r1.fb9 = cm_object_get_child_by_name(state->f0.reg.f23r1, "FB9");
	state->f0.fld.f23r1.fb10 = cm_object_get_child_by_name(state->f0.reg.f23r1, "FB10");
	state->f0.fld.f23r1.fb11 = cm_object_get_child_by_name(state->f0.reg.f23r1, "FB11");
	state->f0.fld.f23r1.fb12 = cm_object_get_child_by_name(state->f0.reg.f23r1, "FB12");
	state->f0.fld.f23r1.fb13 = cm_object_get_child_by_name(state->f0.reg.f23r1, "FB13");
	state->f0.fld.f23r1.fb14 = cm_object_get_child_by_name(state->f0.reg.f23r1, "FB14");
	state->f0.fld.f23r1.fb15 = cm_object_get_child_by_name(state->f0.reg.f23r1, "FB15");
	state->f0.fld.f23r1.fb16 = cm_object_get_child_by_name(state->f0.reg.f23r1, "FB16");
	state->f0.fld.f23r1.fb17 = cm_object_get_child_by_name(state->f0.reg.f23r1, "FB17");
	state->f0.fld.f23r1.fb18 = cm_object_get_child_by_name(state->f0.reg.f23r1, "FB18");
	state->f0.fld.f23r1.fb19 = cm_object_get_child_by_name(state->f0.reg.f23r1, "FB19");
	state->f0.fld.f23r1.fb20 = cm_object_get_child_by_name(state->f0.reg.f23r1, "FB20");
	state->f0.fld.f23r1.fb21 = cm_object_get_child_by_name(state->f0.reg.f23r1, "FB21");
	state->f0.fld.f23r1.fb22 = cm_object_get_child_by_name(state->f0.reg.f23r1, "FB22");
	state->f0.fld.f23r1.fb23 = cm_object_get_child_by_name(state->f0.reg.f23r1, "FB23");
	state->f0.fld.f23r1.fb24 = cm_object_get_child_by_name(state->f0.reg.f23r1, "FB24");
	state->f0.fld.f23r1.fb25 = cm_object_get_child_by_name(state->f0.reg.f23r1, "FB25");
	state->f0.fld.f23r1.fb26 = cm_object_get_child_by_name(state->f0.reg.f23r1, "FB26");
	state->f0.fld.f23r1.fb27 = cm_object_get_child_by_name(state->f0.reg.f23r1, "FB27");
	state->f0.fld.f23r1.fb28 = cm_object_get_child_by_name(state->f0.reg.f23r1, "FB28");
	state->f0.fld.f23r1.fb29 = cm_object_get_child_by_name(state->f0.reg.f23r1, "FB29");
	state->f0.fld.f23r1.fb30 = cm_object_get_child_by_name(state->f0.reg.f23r1, "FB30");
	state->f0.fld.f23r1.fb31 = cm_object_get_child_by_name(state->f0.reg.f23r1, "FB31");

	// F23R2 bitfields.
	state->f0.fld.f23r2.fb0 = cm_object_get_child_by_name(state->f0.reg.f23r2, "FB0");
	state->f0.fld.f23r2.fb1 = cm_object_get_child_by_name(state->f0.reg.f23r2, "FB1");
	state->f0.fld.f23r2.fb2 = cm_object_get_child_by_name(state->f0.reg.f23r2, "FB2");
	state->f0.fld.f23r2.fb3 = cm_object_get_child_by_name(state->f0.reg.f23r2, "FB3");
	state->f0.fld.f23r2.fb4 = cm_object_get_child_by_name(state->f0.reg.f23r2, "FB4");
	state->f0.fld.f23r2.fb5 = cm_object_get_child_by_name(state->f0.reg.f23r2, "FB5");
	state->f0.fld.f23r2.fb6 = cm_object_get_child_by_name(state->f0.reg.f23r2, "FB6");
	state->f0.fld.f23r2.fb7 = cm_object_get_child_by_name(state->f0.reg.f23r2, "FB7");
	state->f0.fld.f23r2.fb8 = cm_object_get_child_by_name(state->f0.reg.f23r2, "FB8");
	state->f0.fld.f23r2.fb9 = cm_object_get_child_by_name(state->f0.reg.f23r2, "FB9");
	state->f0.fld.f23r2.fb10 = cm_object_get_child_by_name(state->f0.reg.f23r2, "FB10");
	state->f0.fld.f23r2.fb11 = cm_object_get_child_by_name(state->f0.reg.f23r2, "FB11");
	state->f0.fld.f23r2.fb12 = cm_object_get_child_by_name(state->f0.reg.f23r2, "FB12");
	state->f0.fld.f23r2.fb13 = cm_object_get_child_by_name(state->f0.reg.f23r2, "FB13");
	state->f0.fld.f23r2.fb14 = cm_object_get_child_by_name(state->f0.reg.f23r2, "FB14");
	state->f0.fld.f23r2.fb15 = cm_object_get_child_by_name(state->f0.reg.f23r2, "FB15");
	state->f0.fld.f23r2.fb16 = cm_object_get_child_by_name(state->f0.reg.f23r2, "FB16");
	state->f0.fld.f23r2.fb17 = cm_object_get_child_by_name(state->f0.reg.f23r2, "FB17");
	state->f0.fld.f23r2.fb18 = cm_object_get_child_by_name(state->f0.reg.f23r2, "FB18");
	state->f0.fld.f23r2.fb19 = cm_object_get_child_by_name(state->f0.reg.f23r2, "FB19");
	state->f0.fld.f23r2.fb20 = cm_object_get_child_by_name(state->f0.reg.f23r2, "FB20");
	state->f0.fld.f23r2.fb21 = cm_object_get_child_by_name(state->f0.reg.f23r2, "FB21");
	state->f0.fld.f23r2.fb22 = cm_object_get_child_by_name(state->f0.reg.f23r2, "FB22");
	state->f0.fld.f23r2.fb23 = cm_object_get_child_by_name(state->f0.reg.f23r2, "FB23");
	state->f0.fld.f23r2.fb24 = cm_object_get_child_by_name(state->f0.reg.f23r2, "FB24");
	state->f0.fld.f23r2.fb25 = cm_object_get_child_by_name(state->f0.reg.f23r2, "FB25");
	state->f0.fld.f23r2.fb26 = cm_object_get_child_by_name(state->f0.reg.f23r2, "FB26");
	state->f0.fld.f23r2.fb27 = cm_object_get_child_by_name(state->f0.reg.f23r2, "FB27");
	state->f0.fld.f23r2.fb28 = cm_object_get_child_by_name(state->f0.reg.f23r2, "FB28");
	state->f0.fld.f23r2.fb29 = cm_object_get_child_by_name(state->f0.reg.f23r2, "FB29");
	state->f0.fld.f23r2.fb30 = cm_object_get_child_by_name(state->f0.reg.f23r2, "FB30");
	state->f0.fld.f23r2.fb31 = cm_object_get_child_by_name(state->f0.reg.f23r2, "FB31");

	// F24R1 bitfields.
	state->f0.fld.f24r1.fb0 = cm_object_get_child_by_name(state->f0.reg.f24r1, "FB0");
	state->f0.fld.f24r1.fb1 = cm_object_get_child_by_name(state->f0.reg.f24r1, "FB1");
	state->f0.fld.f24r1.fb2 = cm_object_get_child_by_name(state->f0.reg.f24r1, "FB2");
	state->f0.fld.f24r1.fb3 = cm_object_get_child_by_name(state->f0.reg.f24r1, "FB3");
	state->f0.fld.f24r1.fb4 = cm_object_get_child_by_name(state->f0.reg.f24r1, "FB4");
	state->f0.fld.f24r1.fb5 = cm_object_get_child_by_name(state->f0.reg.f24r1, "FB5");
	state->f0.fld.f24r1.fb6 = cm_object_get_child_by_name(state->f0.reg.f24r1, "FB6");
	state->f0.fld.f24r1.fb7 = cm_object_get_child_by_name(state->f0.reg.f24r1, "FB7");
	state->f0.fld.f24r1.fb8 = cm_object_get_child_by_name(state->f0.reg.f24r1, "FB8");
	state->f0.fld.f24r1.fb9 = cm_object_get_child_by_name(state->f0.reg.f24r1, "FB9");
	state->f0.fld.f24r1.fb10 = cm_object_get_child_by_name(state->f0.reg.f24r1, "FB10");
	state->f0.fld.f24r1.fb11 = cm_object_get_child_by_name(state->f0.reg.f24r1, "FB11");
	state->f0.fld.f24r1.fb12 = cm_object_get_child_by_name(state->f0.reg.f24r1, "FB12");
	state->f0.fld.f24r1.fb13 = cm_object_get_child_by_name(state->f0.reg.f24r1, "FB13");
	state->f0.fld.f24r1.fb14 = cm_object_get_child_by_name(state->f0.reg.f24r1, "FB14");
	state->f0.fld.f24r1.fb15 = cm_object_get_child_by_name(state->f0.reg.f24r1, "FB15");
	state->f0.fld.f24r1.fb16 = cm_object_get_child_by_name(state->f0.reg.f24r1, "FB16");
	state->f0.fld.f24r1.fb17 = cm_object_get_child_by_name(state->f0.reg.f24r1, "FB17");
	state->f0.fld.f24r1.fb18 = cm_object_get_child_by_name(state->f0.reg.f24r1, "FB18");
	state->f0.fld.f24r1.fb19 = cm_object_get_child_by_name(state->f0.reg.f24r1, "FB19");
	state->f0.fld.f24r1.fb20 = cm_object_get_child_by_name(state->f0.reg.f24r1, "FB20");
	state->f0.fld.f24r1.fb21 = cm_object_get_child_by_name(state->f0.reg.f24r1, "FB21");
	state->f0.fld.f24r1.fb22 = cm_object_get_child_by_name(state->f0.reg.f24r1, "FB22");
	state->f0.fld.f24r1.fb23 = cm_object_get_child_by_name(state->f0.reg.f24r1, "FB23");
	state->f0.fld.f24r1.fb24 = cm_object_get_child_by_name(state->f0.reg.f24r1, "FB24");
	state->f0.fld.f24r1.fb25 = cm_object_get_child_by_name(state->f0.reg.f24r1, "FB25");
	state->f0.fld.f24r1.fb26 = cm_object_get_child_by_name(state->f0.reg.f24r1, "FB26");
	state->f0.fld.f24r1.fb27 = cm_object_get_child_by_name(state->f0.reg.f24r1, "FB27");
	state->f0.fld.f24r1.fb28 = cm_object_get_child_by_name(state->f0.reg.f24r1, "FB28");
	state->f0.fld.f24r1.fb29 = cm_object_get_child_by_name(state->f0.reg.f24r1, "FB29");
	state->f0.fld.f24r1.fb30 = cm_object_get_child_by_name(state->f0.reg.f24r1, "FB30");
	state->f0.fld.f24r1.fb31 = cm_object_get_child_by_name(state->f0.reg.f24r1, "FB31");

	// F24R2 bitfields.
	state->f0.fld.f24r2.fb0 = cm_object_get_child_by_name(state->f0.reg.f24r2, "FB0");
	state->f0.fld.f24r2.fb1 = cm_object_get_child_by_name(state->f0.reg.f24r2, "FB1");
	state->f0.fld.f24r2.fb2 = cm_object_get_child_by_name(state->f0.reg.f24r2, "FB2");
	state->f0.fld.f24r2.fb3 = cm_object_get_child_by_name(state->f0.reg.f24r2, "FB3");
	state->f0.fld.f24r2.fb4 = cm_object_get_child_by_name(state->f0.reg.f24r2, "FB4");
	state->f0.fld.f24r2.fb5 = cm_object_get_child_by_name(state->f0.reg.f24r2, "FB5");
	state->f0.fld.f24r2.fb6 = cm_object_get_child_by_name(state->f0.reg.f24r2, "FB6");
	state->f0.fld.f24r2.fb7 = cm_object_get_child_by_name(state->f0.reg.f24r2, "FB7");
	state->f0.fld.f24r2.fb8 = cm_object_get_child_by_name(state->f0.reg.f24r2, "FB8");
	state->f0.fld.f24r2.fb9 = cm_object_get_child_by_name(state->f0.reg.f24r2, "FB9");
	state->f0.fld.f24r2.fb10 = cm_object_get_child_by_name(state->f0.reg.f24r2, "FB10");
	state->f0.fld.f24r2.fb11 = cm_object_get_child_by_name(state->f0.reg.f24r2, "FB11");
	state->f0.fld.f24r2.fb12 = cm_object_get_child_by_name(state->f0.reg.f24r2, "FB12");
	state->f0.fld.f24r2.fb13 = cm_object_get_child_by_name(state->f0.reg.f24r2, "FB13");
	state->f0.fld.f24r2.fb14 = cm_object_get_child_by_name(state->f0.reg.f24r2, "FB14");
	state->f0.fld.f24r2.fb15 = cm_object_get_child_by_name(state->f0.reg.f24r2, "FB15");
	state->f0.fld.f24r2.fb16 = cm_object_get_child_by_name(state->f0.reg.f24r2, "FB16");
	state->f0.fld.f24r2.fb17 = cm_object_get_child_by_name(state->f0.reg.f24r2, "FB17");
	state->f0.fld.f24r2.fb18 = cm_object_get_child_by_name(state->f0.reg.f24r2, "FB18");
	state->f0.fld.f24r2.fb19 = cm_object_get_child_by_name(state->f0.reg.f24r2, "FB19");
	state->f0.fld.f24r2.fb20 = cm_object_get_child_by_name(state->f0.reg.f24r2, "FB20");
	state->f0.fld.f24r2.fb21 = cm_object_get_child_by_name(state->f0.reg.f24r2, "FB21");
	state->f0.fld.f24r2.fb22 = cm_object_get_child_by_name(state->f0.reg.f24r2, "FB22");
	state->f0.fld.f24r2.fb23 = cm_object_get_child_by_name(state->f0.reg.f24r2, "FB23");
	state->f0.fld.f24r2.fb24 = cm_object_get_child_by_name(state->f0.reg.f24r2, "FB24");
	state->f0.fld.f24r2.fb25 = cm_object_get_child_by_name(state->f0.reg.f24r2, "FB25");
	state->f0.fld.f24r2.fb26 = cm_object_get_child_by_name(state->f0.reg.f24r2, "FB26");
	state->f0.fld.f24r2.fb27 = cm_object_get_child_by_name(state->f0.reg.f24r2, "FB27");
	state->f0.fld.f24r2.fb28 = cm_object_get_child_by_name(state->f0.reg.f24r2, "FB28");
	state->f0.fld.f24r2.fb29 = cm_object_get_child_by_name(state->f0.reg.f24r2, "FB29");
	state->f0.fld.f24r2.fb30 = cm_object_get_child_by_name(state->f0.reg.f24r2, "FB30");
	state->f0.fld.f24r2.fb31 = cm_object_get_child_by_name(state->f0.reg.f24r2, "FB31");

	// F25R1 bitfields.
	state->f0.fld.f25r1.fb0 = cm_object_get_child_by_name(state->f0.reg.f25r1, "FB0");
	state->f0.fld.f25r1.fb1 = cm_object_get_child_by_name(state->f0.reg.f25r1, "FB1");
	state->f0.fld.f25r1.fb2 = cm_object_get_child_by_name(state->f0.reg.f25r1, "FB2");
	state->f0.fld.f25r1.fb3 = cm_object_get_child_by_name(state->f0.reg.f25r1, "FB3");
	state->f0.fld.f25r1.fb4 = cm_object_get_child_by_name(state->f0.reg.f25r1, "FB4");
	state->f0.fld.f25r1.fb5 = cm_object_get_child_by_name(state->f0.reg.f25r1, "FB5");
	state->f0.fld.f25r1.fb6 = cm_object_get_child_by_name(state->f0.reg.f25r1, "FB6");
	state->f0.fld.f25r1.fb7 = cm_object_get_child_by_name(state->f0.reg.f25r1, "FB7");
	state->f0.fld.f25r1.fb8 = cm_object_get_child_by_name(state->f0.reg.f25r1, "FB8");
	state->f0.fld.f25r1.fb9 = cm_object_get_child_by_name(state->f0.reg.f25r1, "FB9");
	state->f0.fld.f25r1.fb10 = cm_object_get_child_by_name(state->f0.reg.f25r1, "FB10");
	state->f0.fld.f25r1.fb11 = cm_object_get_child_by_name(state->f0.reg.f25r1, "FB11");
	state->f0.fld.f25r1.fb12 = cm_object_get_child_by_name(state->f0.reg.f25r1, "FB12");
	state->f0.fld.f25r1.fb13 = cm_object_get_child_by_name(state->f0.reg.f25r1, "FB13");
	state->f0.fld.f25r1.fb14 = cm_object_get_child_by_name(state->f0.reg.f25r1, "FB14");
	state->f0.fld.f25r1.fb15 = cm_object_get_child_by_name(state->f0.reg.f25r1, "FB15");
	state->f0.fld.f25r1.fb16 = cm_object_get_child_by_name(state->f0.reg.f25r1, "FB16");
	state->f0.fld.f25r1.fb17 = cm_object_get_child_by_name(state->f0.reg.f25r1, "FB17");
	state->f0.fld.f25r1.fb18 = cm_object_get_child_by_name(state->f0.reg.f25r1, "FB18");
	state->f0.fld.f25r1.fb19 = cm_object_get_child_by_name(state->f0.reg.f25r1, "FB19");
	state->f0.fld.f25r1.fb20 = cm_object_get_child_by_name(state->f0.reg.f25r1, "FB20");
	state->f0.fld.f25r1.fb21 = cm_object_get_child_by_name(state->f0.reg.f25r1, "FB21");
	state->f0.fld.f25r1.fb22 = cm_object_get_child_by_name(state->f0.reg.f25r1, "FB22");
	state->f0.fld.f25r1.fb23 = cm_object_get_child_by_name(state->f0.reg.f25r1, "FB23");
	state->f0.fld.f25r1.fb24 = cm_object_get_child_by_name(state->f0.reg.f25r1, "FB24");
	state->f0.fld.f25r1.fb25 = cm_object_get_child_by_name(state->f0.reg.f25r1, "FB25");
	state->f0.fld.f25r1.fb26 = cm_object_get_child_by_name(state->f0.reg.f25r1, "FB26");
	state->f0.fld.f25r1.fb27 = cm_object_get_child_by_name(state->f0.reg.f25r1, "FB27");
	state->f0.fld.f25r1.fb28 = cm_object_get_child_by_name(state->f0.reg.f25r1, "FB28");
	state->f0.fld.f25r1.fb29 = cm_object_get_child_by_name(state->f0.reg.f25r1, "FB29");
	state->f0.fld.f25r1.fb30 = cm_object_get_child_by_name(state->f0.reg.f25r1, "FB30");
	state->f0.fld.f25r1.fb31 = cm_object_get_child_by_name(state->f0.reg.f25r1, "FB31");

	// F25R2 bitfields.
	state->f0.fld.f25r2.fb0 = cm_object_get_child_by_name(state->f0.reg.f25r2, "FB0");
	state->f0.fld.f25r2.fb1 = cm_object_get_child_by_name(state->f0.reg.f25r2, "FB1");
	state->f0.fld.f25r2.fb2 = cm_object_get_child_by_name(state->f0.reg.f25r2, "FB2");
	state->f0.fld.f25r2.fb3 = cm_object_get_child_by_name(state->f0.reg.f25r2, "FB3");
	state->f0.fld.f25r2.fb4 = cm_object_get_child_by_name(state->f0.reg.f25r2, "FB4");
	state->f0.fld.f25r2.fb5 = cm_object_get_child_by_name(state->f0.reg.f25r2, "FB5");
	state->f0.fld.f25r2.fb6 = cm_object_get_child_by_name(state->f0.reg.f25r2, "FB6");
	state->f0.fld.f25r2.fb7 = cm_object_get_child_by_name(state->f0.reg.f25r2, "FB7");
	state->f0.fld.f25r2.fb8 = cm_object_get_child_by_name(state->f0.reg.f25r2, "FB8");
	state->f0.fld.f25r2.fb9 = cm_object_get_child_by_name(state->f0.reg.f25r2, "FB9");
	state->f0.fld.f25r2.fb10 = cm_object_get_child_by_name(state->f0.reg.f25r2, "FB10");
	state->f0.fld.f25r2.fb11 = cm_object_get_child_by_name(state->f0.reg.f25r2, "FB11");
	state->f0.fld.f25r2.fb12 = cm_object_get_child_by_name(state->f0.reg.f25r2, "FB12");
	state->f0.fld.f25r2.fb13 = cm_object_get_child_by_name(state->f0.reg.f25r2, "FB13");
	state->f0.fld.f25r2.fb14 = cm_object_get_child_by_name(state->f0.reg.f25r2, "FB14");
	state->f0.fld.f25r2.fb15 = cm_object_get_child_by_name(state->f0.reg.f25r2, "FB15");
	state->f0.fld.f25r2.fb16 = cm_object_get_child_by_name(state->f0.reg.f25r2, "FB16");
	state->f0.fld.f25r2.fb17 = cm_object_get_child_by_name(state->f0.reg.f25r2, "FB17");
	state->f0.fld.f25r2.fb18 = cm_object_get_child_by_name(state->f0.reg.f25r2, "FB18");
	state->f0.fld.f25r2.fb19 = cm_object_get_child_by_name(state->f0.reg.f25r2, "FB19");
	state->f0.fld.f25r2.fb20 = cm_object_get_child_by_name(state->f0.reg.f25r2, "FB20");
	state->f0.fld.f25r2.fb21 = cm_object_get_child_by_name(state->f0.reg.f25r2, "FB21");
	state->f0.fld.f25r2.fb22 = cm_object_get_child_by_name(state->f0.reg.f25r2, "FB22");
	state->f0.fld.f25r2.fb23 = cm_object_get_child_by_name(state->f0.reg.f25r2, "FB23");
	state->f0.fld.f25r2.fb24 = cm_object_get_child_by_name(state->f0.reg.f25r2, "FB24");
	state->f0.fld.f25r2.fb25 = cm_object_get_child_by_name(state->f0.reg.f25r2, "FB25");
	state->f0.fld.f25r2.fb26 = cm_object_get_child_by_name(state->f0.reg.f25r2, "FB26");
	state->f0.fld.f25r2.fb27 = cm_object_get_child_by_name(state->f0.reg.f25r2, "FB27");
	state->f0.fld.f25r2.fb28 = cm_object_get_child_by_name(state->f0.reg.f25r2, "FB28");
	state->f0.fld.f25r2.fb29 = cm_object_get_child_by_name(state->f0.reg.f25r2, "FB29");
	state->f0.fld.f25r2.fb30 = cm_object_get_child_by_name(state->f0.reg.f25r2, "FB30");
	state->f0.fld.f25r2.fb31 = cm_object_get_child_by_name(state->f0.reg.f25r2, "FB31");

	// F26R1 bitfields.
	state->f0.fld.f26r1.fb0 = cm_object_get_child_by_name(state->f0.reg.f26r1, "FB0");
	state->f0.fld.f26r1.fb1 = cm_object_get_child_by_name(state->f0.reg.f26r1, "FB1");
	state->f0.fld.f26r1.fb2 = cm_object_get_child_by_name(state->f0.reg.f26r1, "FB2");
	state->f0.fld.f26r1.fb3 = cm_object_get_child_by_name(state->f0.reg.f26r1, "FB3");
	state->f0.fld.f26r1.fb4 = cm_object_get_child_by_name(state->f0.reg.f26r1, "FB4");
	state->f0.fld.f26r1.fb5 = cm_object_get_child_by_name(state->f0.reg.f26r1, "FB5");
	state->f0.fld.f26r1.fb6 = cm_object_get_child_by_name(state->f0.reg.f26r1, "FB6");
	state->f0.fld.f26r1.fb7 = cm_object_get_child_by_name(state->f0.reg.f26r1, "FB7");
	state->f0.fld.f26r1.fb8 = cm_object_get_child_by_name(state->f0.reg.f26r1, "FB8");
	state->f0.fld.f26r1.fb9 = cm_object_get_child_by_name(state->f0.reg.f26r1, "FB9");
	state->f0.fld.f26r1.fb10 = cm_object_get_child_by_name(state->f0.reg.f26r1, "FB10");
	state->f0.fld.f26r1.fb11 = cm_object_get_child_by_name(state->f0.reg.f26r1, "FB11");
	state->f0.fld.f26r1.fb12 = cm_object_get_child_by_name(state->f0.reg.f26r1, "FB12");
	state->f0.fld.f26r1.fb13 = cm_object_get_child_by_name(state->f0.reg.f26r1, "FB13");
	state->f0.fld.f26r1.fb14 = cm_object_get_child_by_name(state->f0.reg.f26r1, "FB14");
	state->f0.fld.f26r1.fb15 = cm_object_get_child_by_name(state->f0.reg.f26r1, "FB15");
	state->f0.fld.f26r1.fb16 = cm_object_get_child_by_name(state->f0.reg.f26r1, "FB16");
	state->f0.fld.f26r1.fb17 = cm_object_get_child_by_name(state->f0.reg.f26r1, "FB17");
	state->f0.fld.f26r1.fb18 = cm_object_get_child_by_name(state->f0.reg.f26r1, "FB18");
	state->f0.fld.f26r1.fb19 = cm_object_get_child_by_name(state->f0.reg.f26r1, "FB19");
	state->f0.fld.f26r1.fb20 = cm_object_get_child_by_name(state->f0.reg.f26r1, "FB20");
	state->f0.fld.f26r1.fb21 = cm_object_get_child_by_name(state->f0.reg.f26r1, "FB21");
	state->f0.fld.f26r1.fb22 = cm_object_get_child_by_name(state->f0.reg.f26r1, "FB22");
	state->f0.fld.f26r1.fb23 = cm_object_get_child_by_name(state->f0.reg.f26r1, "FB23");
	state->f0.fld.f26r1.fb24 = cm_object_get_child_by_name(state->f0.reg.f26r1, "FB24");
	state->f0.fld.f26r1.fb25 = cm_object_get_child_by_name(state->f0.reg.f26r1, "FB25");
	state->f0.fld.f26r1.fb26 = cm_object_get_child_by_name(state->f0.reg.f26r1, "FB26");
	state->f0.fld.f26r1.fb27 = cm_object_get_child_by_name(state->f0.reg.f26r1, "FB27");
	state->f0.fld.f26r1.fb28 = cm_object_get_child_by_name(state->f0.reg.f26r1, "FB28");
	state->f0.fld.f26r1.fb29 = cm_object_get_child_by_name(state->f0.reg.f26r1, "FB29");
	state->f0.fld.f26r1.fb30 = cm_object_get_child_by_name(state->f0.reg.f26r1, "FB30");
	state->f0.fld.f26r1.fb31 = cm_object_get_child_by_name(state->f0.reg.f26r1, "FB31");

	// F26R2 bitfields.
	state->f0.fld.f26r2.fb0 = cm_object_get_child_by_name(state->f0.reg.f26r2, "FB0");
	state->f0.fld.f26r2.fb1 = cm_object_get_child_by_name(state->f0.reg.f26r2, "FB1");
	state->f0.fld.f26r2.fb2 = cm_object_get_child_by_name(state->f0.reg.f26r2, "FB2");
	state->f0.fld.f26r2.fb3 = cm_object_get_child_by_name(state->f0.reg.f26r2, "FB3");
	state->f0.fld.f26r2.fb4 = cm_object_get_child_by_name(state->f0.reg.f26r2, "FB4");
	state->f0.fld.f26r2.fb5 = cm_object_get_child_by_name(state->f0.reg.f26r2, "FB5");
	state->f0.fld.f26r2.fb6 = cm_object_get_child_by_name(state->f0.reg.f26r2, "FB6");
	state->f0.fld.f26r2.fb7 = cm_object_get_child_by_name(state->f0.reg.f26r2, "FB7");
	state->f0.fld.f26r2.fb8 = cm_object_get_child_by_name(state->f0.reg.f26r2, "FB8");
	state->f0.fld.f26r2.fb9 = cm_object_get_child_by_name(state->f0.reg.f26r2, "FB9");
	state->f0.fld.f26r2.fb10 = cm_object_get_child_by_name(state->f0.reg.f26r2, "FB10");
	state->f0.fld.f26r2.fb11 = cm_object_get_child_by_name(state->f0.reg.f26r2, "FB11");
	state->f0.fld.f26r2.fb12 = cm_object_get_child_by_name(state->f0.reg.f26r2, "FB12");
	state->f0.fld.f26r2.fb13 = cm_object_get_child_by_name(state->f0.reg.f26r2, "FB13");
	state->f0.fld.f26r2.fb14 = cm_object_get_child_by_name(state->f0.reg.f26r2, "FB14");
	state->f0.fld.f26r2.fb15 = cm_object_get_child_by_name(state->f0.reg.f26r2, "FB15");
	state->f0.fld.f26r2.fb16 = cm_object_get_child_by_name(state->f0.reg.f26r2, "FB16");
	state->f0.fld.f26r2.fb17 = cm_object_get_child_by_name(state->f0.reg.f26r2, "FB17");
	state->f0.fld.f26r2.fb18 = cm_object_get_child_by_name(state->f0.reg.f26r2, "FB18");
	state->f0.fld.f26r2.fb19 = cm_object_get_child_by_name(state->f0.reg.f26r2, "FB19");
	state->f0.fld.f26r2.fb20 = cm_object_get_child_by_name(state->f0.reg.f26r2, "FB20");
	state->f0.fld.f26r2.fb21 = cm_object_get_child_by_name(state->f0.reg.f26r2, "FB21");
	state->f0.fld.f26r2.fb22 = cm_object_get_child_by_name(state->f0.reg.f26r2, "FB22");
	state->f0.fld.f26r2.fb23 = cm_object_get_child_by_name(state->f0.reg.f26r2, "FB23");
	state->f0.fld.f26r2.fb24 = cm_object_get_child_by_name(state->f0.reg.f26r2, "FB24");
	state->f0.fld.f26r2.fb25 = cm_object_get_child_by_name(state->f0.reg.f26r2, "FB25");
	state->f0.fld.f26r2.fb26 = cm_object_get_child_by_name(state->f0.reg.f26r2, "FB26");
	state->f0.fld.f26r2.fb27 = cm_object_get_child_by_name(state->f0.reg.f26r2, "FB27");
	state->f0.fld.f26r2.fb28 = cm_object_get_child_by_name(state->f0.reg.f26r2, "FB28");
	state->f0.fld.f26r2.fb29 = cm_object_get_child_by_name(state->f0.reg.f26r2, "FB29");
	state->f0.fld.f26r2.fb30 = cm_object_get_child_by_name(state->f0.reg.f26r2, "FB30");
	state->f0.fld.f26r2.fb31 = cm_object_get_child_by_name(state->f0.reg.f26r2, "FB31");

	// F27R1 bitfields.
	state->f0.fld.f27r1.fb0 = cm_object_get_child_by_name(state->f0.reg.f27r1, "FB0");
	state->f0.fld.f27r1.fb1 = cm_object_get_child_by_name(state->f0.reg.f27r1, "FB1");
	state->f0.fld.f27r1.fb2 = cm_object_get_child_by_name(state->f0.reg.f27r1, "FB2");
	state->f0.fld.f27r1.fb3 = cm_object_get_child_by_name(state->f0.reg.f27r1, "FB3");
	state->f0.fld.f27r1.fb4 = cm_object_get_child_by_name(state->f0.reg.f27r1, "FB4");
	state->f0.fld.f27r1.fb5 = cm_object_get_child_by_name(state->f0.reg.f27r1, "FB5");
	state->f0.fld.f27r1.fb6 = cm_object_get_child_by_name(state->f0.reg.f27r1, "FB6");
	state->f0.fld.f27r1.fb7 = cm_object_get_child_by_name(state->f0.reg.f27r1, "FB7");
	state->f0.fld.f27r1.fb8 = cm_object_get_child_by_name(state->f0.reg.f27r1, "FB8");
	state->f0.fld.f27r1.fb9 = cm_object_get_child_by_name(state->f0.reg.f27r1, "FB9");
	state->f0.fld.f27r1.fb10 = cm_object_get_child_by_name(state->f0.reg.f27r1, "FB10");
	state->f0.fld.f27r1.fb11 = cm_object_get_child_by_name(state->f0.reg.f27r1, "FB11");
	state->f0.fld.f27r1.fb12 = cm_object_get_child_by_name(state->f0.reg.f27r1, "FB12");
	state->f0.fld.f27r1.fb13 = cm_object_get_child_by_name(state->f0.reg.f27r1, "FB13");
	state->f0.fld.f27r1.fb14 = cm_object_get_child_by_name(state->f0.reg.f27r1, "FB14");
	state->f0.fld.f27r1.fb15 = cm_object_get_child_by_name(state->f0.reg.f27r1, "FB15");
	state->f0.fld.f27r1.fb16 = cm_object_get_child_by_name(state->f0.reg.f27r1, "FB16");
	state->f0.fld.f27r1.fb17 = cm_object_get_child_by_name(state->f0.reg.f27r1, "FB17");
	state->f0.fld.f27r1.fb18 = cm_object_get_child_by_name(state->f0.reg.f27r1, "FB18");
	state->f0.fld.f27r1.fb19 = cm_object_get_child_by_name(state->f0.reg.f27r1, "FB19");
	state->f0.fld.f27r1.fb20 = cm_object_get_child_by_name(state->f0.reg.f27r1, "FB20");
	state->f0.fld.f27r1.fb21 = cm_object_get_child_by_name(state->f0.reg.f27r1, "FB21");
	state->f0.fld.f27r1.fb22 = cm_object_get_child_by_name(state->f0.reg.f27r1, "FB22");
	state->f0.fld.f27r1.fb23 = cm_object_get_child_by_name(state->f0.reg.f27r1, "FB23");
	state->f0.fld.f27r1.fb24 = cm_object_get_child_by_name(state->f0.reg.f27r1, "FB24");
	state->f0.fld.f27r1.fb25 = cm_object_get_child_by_name(state->f0.reg.f27r1, "FB25");
	state->f0.fld.f27r1.fb26 = cm_object_get_child_by_name(state->f0.reg.f27r1, "FB26");
	state->f0.fld.f27r1.fb27 = cm_object_get_child_by_name(state->f0.reg.f27r1, "FB27");
	state->f0.fld.f27r1.fb28 = cm_object_get_child_by_name(state->f0.reg.f27r1, "FB28");
	state->f0.fld.f27r1.fb29 = cm_object_get_child_by_name(state->f0.reg.f27r1, "FB29");
	state->f0.fld.f27r1.fb30 = cm_object_get_child_by_name(state->f0.reg.f27r1, "FB30");
	state->f0.fld.f27r1.fb31 = cm_object_get_child_by_name(state->f0.reg.f27r1, "FB31");

	// F27R2 bitfields.
	state->f0.fld.f27r2.fb0 = cm_object_get_child_by_name(state->f0.reg.f27r2, "FB0");
	state->f0.fld.f27r2.fb1 = cm_object_get_child_by_name(state->f0.reg.f27r2, "FB1");
	state->f0.fld.f27r2.fb2 = cm_object_get_child_by_name(state->f0.reg.f27r2, "FB2");
	state->f0.fld.f27r2.fb3 = cm_object_get_child_by_name(state->f0.reg.f27r2, "FB3");
	state->f0.fld.f27r2.fb4 = cm_object_get_child_by_name(state->f0.reg.f27r2, "FB4");
	state->f0.fld.f27r2.fb5 = cm_object_get_child_by_name(state->f0.reg.f27r2, "FB5");
	state->f0.fld.f27r2.fb6 = cm_object_get_child_by_name(state->f0.reg.f27r2, "FB6");
	state->f0.fld.f27r2.fb7 = cm_object_get_child_by_name(state->f0.reg.f27r2, "FB7");
	state->f0.fld.f27r2.fb8 = cm_object_get_child_by_name(state->f0.reg.f27r2, "FB8");
	state->f0.fld.f27r2.fb9 = cm_object_get_child_by_name(state->f0.reg.f27r2, "FB9");
	state->f0.fld.f27r2.fb10 = cm_object_get_child_by_name(state->f0.reg.f27r2, "FB10");
	state->f0.fld.f27r2.fb11 = cm_object_get_child_by_name(state->f0.reg.f27r2, "FB11");
	state->f0.fld.f27r2.fb12 = cm_object_get_child_by_name(state->f0.reg.f27r2, "FB12");
	state->f0.fld.f27r2.fb13 = cm_object_get_child_by_name(state->f0.reg.f27r2, "FB13");
	state->f0.fld.f27r2.fb14 = cm_object_get_child_by_name(state->f0.reg.f27r2, "FB14");
	state->f0.fld.f27r2.fb15 = cm_object_get_child_by_name(state->f0.reg.f27r2, "FB15");
	state->f0.fld.f27r2.fb16 = cm_object_get_child_by_name(state->f0.reg.f27r2, "FB16");
	state->f0.fld.f27r2.fb17 = cm_object_get_child_by_name(state->f0.reg.f27r2, "FB17");
	state->f0.fld.f27r2.fb18 = cm_object_get_child_by_name(state->f0.reg.f27r2, "FB18");
	state->f0.fld.f27r2.fb19 = cm_object_get_child_by_name(state->f0.reg.f27r2, "FB19");
	state->f0.fld.f27r2.fb20 = cm_object_get_child_by_name(state->f0.reg.f27r2, "FB20");
	state->f0.fld.f27r2.fb21 = cm_object_get_child_by_name(state->f0.reg.f27r2, "FB21");
	state->f0.fld.f27r2.fb22 = cm_object_get_child_by_name(state->f0.reg.f27r2, "FB22");
	state->f0.fld.f27r2.fb23 = cm_object_get_child_by_name(state->f0.reg.f27r2, "FB23");
	state->f0.fld.f27r2.fb24 = cm_object_get_child_by_name(state->f0.reg.f27r2, "FB24");
	state->f0.fld.f27r2.fb25 = cm_object_get_child_by_name(state->f0.reg.f27r2, "FB25");
	state->f0.fld.f27r2.fb26 = cm_object_get_child_by_name(state->f0.reg.f27r2, "FB26");
	state->f0.fld.f27r2.fb27 = cm_object_get_child_by_name(state->f0.reg.f27r2, "FB27");
	state->f0.fld.f27r2.fb28 = cm_object_get_child_by_name(state->f0.reg.f27r2, "FB28");
	state->f0.fld.f27r2.fb29 = cm_object_get_child_by_name(state->f0.reg.f27r2, "FB29");
	state->f0.fld.f27r2.fb30 = cm_object_get_child_by_name(state->f0.reg.f27r2, "FB30");
	state->f0.fld.f27r2.fb31 = cm_object_get_child_by_name(state->f0.reg.f27r2, "FB31");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

