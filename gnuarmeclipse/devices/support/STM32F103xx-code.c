// DO NOT EDIT! Automatically generated!
// Support code for STM32F103xx.

// FSMC (Flexible static memory controller) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F1 FSMC (Flexible static memory controller) registers.
		struct {
			Object *bcr1; // 0x0 SRAM/NOR-Flash chip-select control register 1
			Object *btr1; // 0x4 SRAM/NOR-Flash chip-select timing register 1
			Object *bcr2; // 0x8 SRAM/NOR-Flash chip-select control register 2
			Object *btr2; // 0xC SRAM/NOR-Flash chip-select timing register 2
			Object *bcr3; // 0x10 SRAM/NOR-Flash chip-select control register 3
			Object *btr3; // 0x14 SRAM/NOR-Flash chip-select timing register 3
			Object *bcr4; // 0x18 SRAM/NOR-Flash chip-select control register 4
			Object *btr4; // 0x1C SRAM/NOR-Flash chip-select timing register 4
			Object *pcr2; // 0x60 PC Card/NAND Flash control register 2
			Object *sr2; // 0x64 FIFO status and interrupt register 2
			Object *pmem2; // 0x68 Common memory space timing register 2
			Object *patt2; // 0x6C Attribute memory space timing register 2
			Object *eccr2; // 0x74 ECC result register 2
			Object *pcr3; // 0x80 PC Card/NAND Flash control register 3
			Object *sr3; // 0x84 FIFO status and interrupt register 3
			Object *pmem3; // 0x88 Common memory space timing register 3
			Object *patt3; // 0x8C Attribute memory space timing register 3
			Object *eccr3; // 0x94 ECC result register 3
			Object *pcr4; // 0xA0 PC Card/NAND Flash control register 4
			Object *sr4; // 0xA4 FIFO status and interrupt register 4
			Object *pmem4; // 0xA8 Common memory space timing register 4
			Object *patt4; // 0xAC Attribute memory space timing register 4
			Object *pio4; // 0xB0 I/O space timing register 4
			Object *bwtr1; // 0x104 SRAM/NOR-Flash write timing registers 1
			Object *bwtr2; // 0x10C SRAM/NOR-Flash write timing registers 2
			Object *bwtr3; // 0x114 SRAM/NOR-Flash write timing registers 3
			Object *bwtr4; // 0x11C SRAM/NOR-Flash write timing registers 4
		} reg;

		struct {

			// BCR1 (SRAM/NOR-Flash chip-select control register 1) bitfields.
			struct {
				Object *mbken; // [0:0] MBKEN
				Object *muxen; // [1:1] MUXEN
				Object *mtyp; // [2:3] MTYP
				Object *mwid; // [4:5] MWID
				Object *faccen; // [6:6] FACCEN
				Object *bursten; // [8:8] BURSTEN
				Object *waitpol; // [9:9] WAITPOL
				Object *waitcfg; // [11:11] WAITCFG
				Object *wren; // [12:12] WREN
				Object *waiten; // [13:13] WAITEN
				Object *extmod; // [14:14] EXTMOD
				Object *asyncwait; // [15:15] ASYNCWAIT
				Object *cburstrw; // [19:19] CBURSTRW
			} bcr1;

			// BTR1 (SRAM/NOR-Flash chip-select timing register 1) bitfields.
			struct {
				Object *addset; // [0:3] ADDSET
				Object *addhld; // [4:7] ADDHLD
				Object *datast; // [8:15] DATAST
				Object *busturn; // [16:19] BUSTURN
				Object *clkdiv; // [20:23] CLKDIV
				Object *datlat; // [24:27] DATLAT
				Object *accmod; // [28:29] ACCMOD
			} btr1;

			// BCR2 (SRAM/NOR-Flash chip-select control register 2) bitfields.
			struct {
				Object *mbken; // [0:0] MBKEN
				Object *muxen; // [1:1] MUXEN
				Object *mtyp; // [2:3] MTYP
				Object *mwid; // [4:5] MWID
				Object *faccen; // [6:6] FACCEN
				Object *bursten; // [8:8] BURSTEN
				Object *waitpol; // [9:9] WAITPOL
				Object *wrapmod; // [10:10] WRAPMOD
				Object *waitcfg; // [11:11] WAITCFG
				Object *wren; // [12:12] WREN
				Object *waiten; // [13:13] WAITEN
				Object *extmod; // [14:14] EXTMOD
				Object *asyncwait; // [15:15] ASYNCWAIT
				Object *cburstrw; // [19:19] CBURSTRW
			} bcr2;

			// BTR2 (SRAM/NOR-Flash chip-select timing register 2) bitfields.
			struct {
				Object *addset; // [0:3] ADDSET
				Object *addhld; // [4:7] ADDHLD
				Object *datast; // [8:15] DATAST
				Object *busturn; // [16:19] BUSTURN
				Object *clkdiv; // [20:23] CLKDIV
				Object *datlat; // [24:27] DATLAT
				Object *accmod; // [28:29] ACCMOD
			} btr2;

			// BCR3 (SRAM/NOR-Flash chip-select control register 3) bitfields.
			struct {
				Object *mbken; // [0:0] MBKEN
				Object *muxen; // [1:1] MUXEN
				Object *mtyp; // [2:3] MTYP
				Object *mwid; // [4:5] MWID
				Object *faccen; // [6:6] FACCEN
				Object *bursten; // [8:8] BURSTEN
				Object *waitpol; // [9:9] WAITPOL
				Object *wrapmod; // [10:10] WRAPMOD
				Object *waitcfg; // [11:11] WAITCFG
				Object *wren; // [12:12] WREN
				Object *waiten; // [13:13] WAITEN
				Object *extmod; // [14:14] EXTMOD
				Object *asyncwait; // [15:15] ASYNCWAIT
				Object *cburstrw; // [19:19] CBURSTRW
			} bcr3;

			// BTR3 (SRAM/NOR-Flash chip-select timing register 3) bitfields.
			struct {
				Object *addset; // [0:3] ADDSET
				Object *addhld; // [4:7] ADDHLD
				Object *datast; // [8:15] DATAST
				Object *busturn; // [16:19] BUSTURN
				Object *clkdiv; // [20:23] CLKDIV
				Object *datlat; // [24:27] DATLAT
				Object *accmod; // [28:29] ACCMOD
			} btr3;

			// BCR4 (SRAM/NOR-Flash chip-select control register 4) bitfields.
			struct {
				Object *mbken; // [0:0] MBKEN
				Object *muxen; // [1:1] MUXEN
				Object *mtyp; // [2:3] MTYP
				Object *mwid; // [4:5] MWID
				Object *faccen; // [6:6] FACCEN
				Object *bursten; // [8:8] BURSTEN
				Object *waitpol; // [9:9] WAITPOL
				Object *wrapmod; // [10:10] WRAPMOD
				Object *waitcfg; // [11:11] WAITCFG
				Object *wren; // [12:12] WREN
				Object *waiten; // [13:13] WAITEN
				Object *extmod; // [14:14] EXTMOD
				Object *asyncwait; // [15:15] ASYNCWAIT
				Object *cburstrw; // [19:19] CBURSTRW
			} bcr4;

			// BTR4 (SRAM/NOR-Flash chip-select timing register 4) bitfields.
			struct {
				Object *addset; // [0:3] ADDSET
				Object *addhld; // [4:7] ADDHLD
				Object *datast; // [8:15] DATAST
				Object *busturn; // [16:19] BUSTURN
				Object *clkdiv; // [20:23] CLKDIV
				Object *datlat; // [24:27] DATLAT
				Object *accmod; // [28:29] ACCMOD
			} btr4;

			// PCR2 (PC Card/NAND Flash control register 2) bitfields.
			struct {
				Object *pwaiten; // [1:1] PWAITEN
				Object *pbken; // [2:2] PBKEN
				Object *ptyp; // [3:3] PTYP
				Object *pwid; // [4:5] PWID
				Object *eccen; // [6:6] ECCEN
				Object *tclr; // [9:12] TCLR
				Object *tar; // [13:16] TAR
				Object *eccps; // [17:19] ECCPS
			} pcr2;

			// SR2 (FIFO status and interrupt register 2) bitfields.
			struct {
				Object *irs; // [0:0] IRS
				Object *ils; // [1:1] ILS
				Object *ifs; // [2:2] IFS
				Object *iren; // [3:3] IREN
				Object *ilen; // [4:4] ILEN
				Object *ifen; // [5:5] IFEN
				Object *fempt; // [6:6] FEMPT
			} sr2;

			// PMEM2 (Common memory space timing register 2) bitfields.
			struct {
				Object *memsetx; // [0:7] MEMSETx
				Object *memwaitx; // [8:15] MEMWAITx
				Object *memholdx; // [16:23] MEMHOLDx
				Object *memhizx; // [24:31] MEMHIZx
			} pmem2;

			// PATT2 (Attribute memory space timing register 2) bitfields.
			struct {
				Object *attsetx; // [0:7] Attribute memory x setup time
				Object *attwaitx; // [8:15] Attribute memory x wait time
				Object *attholdx; // [16:23] Attribute memory x hold time
				Object *atthizx; // [24:31] Attribute memory x databus HiZ time
			} patt2;

			// ECCR2 (ECC result register 2) bitfields.
			struct {
				Object *eccx; // [0:31] ECC result
			} eccr2;

			// PCR3 (PC Card/NAND Flash control register 3) bitfields.
			struct {
				Object *pwaiten; // [1:1] PWAITEN
				Object *pbken; // [2:2] PBKEN
				Object *ptyp; // [3:3] PTYP
				Object *pwid; // [4:5] PWID
				Object *eccen; // [6:6] ECCEN
				Object *tclr; // [9:12] TCLR
				Object *tar; // [13:16] TAR
				Object *eccps; // [17:19] ECCPS
			} pcr3;

			// SR3 (FIFO status and interrupt register 3) bitfields.
			struct {
				Object *irs; // [0:0] IRS
				Object *ils; // [1:1] ILS
				Object *ifs; // [2:2] IFS
				Object *iren; // [3:3] IREN
				Object *ilen; // [4:4] ILEN
				Object *ifen; // [5:5] IFEN
				Object *fempt; // [6:6] FEMPT
			} sr3;

			// PMEM3 (Common memory space timing register 3) bitfields.
			struct {
				Object *memsetx; // [0:7] MEMSETx
				Object *memwaitx; // [8:15] MEMWAITx
				Object *memholdx; // [16:23] MEMHOLDx
				Object *memhizx; // [24:31] MEMHIZx
			} pmem3;

			// PATT3 (Attribute memory space timing register 3) bitfields.
			struct {
				Object *attsetx; // [0:7] ATTSETx
				Object *attwaitx; // [8:15] ATTWAITx
				Object *attholdx; // [16:23] ATTHOLDx
				Object *atthizx; // [24:31] ATTHIZx
			} patt3;

			// ECCR3 (ECC result register 3) bitfields.
			struct {
				Object *eccx; // [0:31] ECCx
			} eccr3;

			// PCR4 (PC Card/NAND Flash control register 4) bitfields.
			struct {
				Object *pwaiten; // [1:1] PWAITEN
				Object *pbken; // [2:2] PBKEN
				Object *ptyp; // [3:3] PTYP
				Object *pwid; // [4:5] PWID
				Object *eccen; // [6:6] ECCEN
				Object *tclr; // [9:12] TCLR
				Object *tar; // [13:16] TAR
				Object *eccps; // [17:19] ECCPS
			} pcr4;

			// SR4 (FIFO status and interrupt register 4) bitfields.
			struct {
				Object *irs; // [0:0] IRS
				Object *ils; // [1:1] ILS
				Object *ifs; // [2:2] IFS
				Object *iren; // [3:3] IREN
				Object *ilen; // [4:4] ILEN
				Object *ifen; // [5:5] IFEN
				Object *fempt; // [6:6] FEMPT
			} sr4;

			// PMEM4 (Common memory space timing register 4) bitfields.
			struct {
				Object *memsetx; // [0:7] MEMSETx
				Object *memwaitx; // [8:15] MEMWAITx
				Object *memholdx; // [16:23] MEMHOLDx
				Object *memhizx; // [24:31] MEMHIZx
			} pmem4;

			// PATT4 (Attribute memory space timing register 4) bitfields.
			struct {
				Object *attsetx; // [0:7] ATTSETx
				Object *attwaitx; // [8:15] ATTWAITx
				Object *attholdx; // [16:23] ATTHOLDx
				Object *atthizx; // [24:31] ATTHIZx
			} patt4;

			// PIO4 (I/O space timing register 4) bitfields.
			struct {
				Object *iosetx; // [0:7] IOSETx
				Object *iowaitx; // [8:15] IOWAITx
				Object *ioholdx; // [16:23] IOHOLDx
				Object *iohizx; // [24:31] IOHIZx
			} pio4;

			// BWTR1 (SRAM/NOR-Flash write timing registers 1) bitfields.
			struct {
				Object *addset; // [0:3] ADDSET
				Object *addhld; // [4:7] ADDHLD
				Object *datast; // [8:15] DATAST
				Object *clkdiv; // [20:23] CLKDIV
				Object *datlat; // [24:27] DATLAT
				Object *accmod; // [28:29] ACCMOD
			} bwtr1;

			// BWTR2 (SRAM/NOR-Flash write timing registers 2) bitfields.
			struct {
				Object *addset; // [0:3] ADDSET
				Object *addhld; // [4:7] ADDHLD
				Object *datast; // [8:15] DATAST
				Object *clkdiv; // [20:23] CLKDIV
				Object *datlat; // [24:27] DATLAT
				Object *accmod; // [28:29] ACCMOD
			} bwtr2;

			// BWTR3 (SRAM/NOR-Flash write timing registers 3) bitfields.
			struct {
				Object *addset; // [0:3] ADDSET
				Object *addhld; // [4:7] ADDHLD
				Object *datast; // [8:15] DATAST
				Object *clkdiv; // [20:23] CLKDIV
				Object *datlat; // [24:27] DATLAT
				Object *accmod; // [28:29] ACCMOD
			} bwtr3;

			// BWTR4 (SRAM/NOR-Flash write timing registers 4) bitfields.
			struct {
				Object *addset; // [0:3] ADDSET
				Object *addhld; // [4:7] ADDHLD
				Object *datast; // [8:15] DATAST
				Object *clkdiv; // [20:23] CLKDIV
				Object *datlat; // [24:27] DATLAT
				Object *accmod; // [28:29] ACCMOD
			} bwtr4;
		} fld;
	} f1;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32FSMCState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_fsmc_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32FSMCState *state = STM32_FSMC_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f1.reg.bcr1 = cm_object_get_child_by_name(obj, "BCR1");
	state->f1.reg.btr1 = cm_object_get_child_by_name(obj, "BTR1");
	state->f1.reg.bcr2 = cm_object_get_child_by_name(obj, "BCR2");
	state->f1.reg.btr2 = cm_object_get_child_by_name(obj, "BTR2");
	state->f1.reg.bcr3 = cm_object_get_child_by_name(obj, "BCR3");
	state->f1.reg.btr3 = cm_object_get_child_by_name(obj, "BTR3");
	state->f1.reg.bcr4 = cm_object_get_child_by_name(obj, "BCR4");
	state->f1.reg.btr4 = cm_object_get_child_by_name(obj, "BTR4");
	state->f1.reg.pcr2 = cm_object_get_child_by_name(obj, "PCR2");
	state->f1.reg.sr2 = cm_object_get_child_by_name(obj, "SR2");
	state->f1.reg.pmem2 = cm_object_get_child_by_name(obj, "PMEM2");
	state->f1.reg.patt2 = cm_object_get_child_by_name(obj, "PATT2");
	state->f1.reg.eccr2 = cm_object_get_child_by_name(obj, "ECCR2");
	state->f1.reg.pcr3 = cm_object_get_child_by_name(obj, "PCR3");
	state->f1.reg.sr3 = cm_object_get_child_by_name(obj, "SR3");
	state->f1.reg.pmem3 = cm_object_get_child_by_name(obj, "PMEM3");
	state->f1.reg.patt3 = cm_object_get_child_by_name(obj, "PATT3");
	state->f1.reg.eccr3 = cm_object_get_child_by_name(obj, "ECCR3");
	state->f1.reg.pcr4 = cm_object_get_child_by_name(obj, "PCR4");
	state->f1.reg.sr4 = cm_object_get_child_by_name(obj, "SR4");
	state->f1.reg.pmem4 = cm_object_get_child_by_name(obj, "PMEM4");
	state->f1.reg.patt4 = cm_object_get_child_by_name(obj, "PATT4");
	state->f1.reg.pio4 = cm_object_get_child_by_name(obj, "PIO4");
	state->f1.reg.bwtr1 = cm_object_get_child_by_name(obj, "BWTR1");
	state->f1.reg.bwtr2 = cm_object_get_child_by_name(obj, "BWTR2");
	state->f1.reg.bwtr3 = cm_object_get_child_by_name(obj, "BWTR3");
	state->f1.reg.bwtr4 = cm_object_get_child_by_name(obj, "BWTR4");

	// BCR1 bitfields.
	state->f1.fld.bcr1.mbken = cm_object_get_child_by_name(state->f1.reg.bcr1, "MBKEN");
	state->f1.fld.bcr1.muxen = cm_object_get_child_by_name(state->f1.reg.bcr1, "MUXEN");
	state->f1.fld.bcr1.mtyp = cm_object_get_child_by_name(state->f1.reg.bcr1, "MTYP");
	state->f1.fld.bcr1.mwid = cm_object_get_child_by_name(state->f1.reg.bcr1, "MWID");
	state->f1.fld.bcr1.faccen = cm_object_get_child_by_name(state->f1.reg.bcr1, "FACCEN");
	state->f1.fld.bcr1.bursten = cm_object_get_child_by_name(state->f1.reg.bcr1, "BURSTEN");
	state->f1.fld.bcr1.waitpol = cm_object_get_child_by_name(state->f1.reg.bcr1, "WAITPOL");
	state->f1.fld.bcr1.waitcfg = cm_object_get_child_by_name(state->f1.reg.bcr1, "WAITCFG");
	state->f1.fld.bcr1.wren = cm_object_get_child_by_name(state->f1.reg.bcr1, "WREN");
	state->f1.fld.bcr1.waiten = cm_object_get_child_by_name(state->f1.reg.bcr1, "WAITEN");
	state->f1.fld.bcr1.extmod = cm_object_get_child_by_name(state->f1.reg.bcr1, "EXTMOD");
	state->f1.fld.bcr1.asyncwait = cm_object_get_child_by_name(state->f1.reg.bcr1, "ASYNCWAIT");
	state->f1.fld.bcr1.cburstrw = cm_object_get_child_by_name(state->f1.reg.bcr1, "CBURSTRW");

	// BTR1 bitfields.
	state->f1.fld.btr1.addset = cm_object_get_child_by_name(state->f1.reg.btr1, "ADDSET");
	state->f1.fld.btr1.addhld = cm_object_get_child_by_name(state->f1.reg.btr1, "ADDHLD");
	state->f1.fld.btr1.datast = cm_object_get_child_by_name(state->f1.reg.btr1, "DATAST");
	state->f1.fld.btr1.busturn = cm_object_get_child_by_name(state->f1.reg.btr1, "BUSTURN");
	state->f1.fld.btr1.clkdiv = cm_object_get_child_by_name(state->f1.reg.btr1, "CLKDIV");
	state->f1.fld.btr1.datlat = cm_object_get_child_by_name(state->f1.reg.btr1, "DATLAT");
	state->f1.fld.btr1.accmod = cm_object_get_child_by_name(state->f1.reg.btr1, "ACCMOD");

	// BCR2 bitfields.
	state->f1.fld.bcr2.mbken = cm_object_get_child_by_name(state->f1.reg.bcr2, "MBKEN");
	state->f1.fld.bcr2.muxen = cm_object_get_child_by_name(state->f1.reg.bcr2, "MUXEN");
	state->f1.fld.bcr2.mtyp = cm_object_get_child_by_name(state->f1.reg.bcr2, "MTYP");
	state->f1.fld.bcr2.mwid = cm_object_get_child_by_name(state->f1.reg.bcr2, "MWID");
	state->f1.fld.bcr2.faccen = cm_object_get_child_by_name(state->f1.reg.bcr2, "FACCEN");
	state->f1.fld.bcr2.bursten = cm_object_get_child_by_name(state->f1.reg.bcr2, "BURSTEN");
	state->f1.fld.bcr2.waitpol = cm_object_get_child_by_name(state->f1.reg.bcr2, "WAITPOL");
	state->f1.fld.bcr2.wrapmod = cm_object_get_child_by_name(state->f1.reg.bcr2, "WRAPMOD");
	state->f1.fld.bcr2.waitcfg = cm_object_get_child_by_name(state->f1.reg.bcr2, "WAITCFG");
	state->f1.fld.bcr2.wren = cm_object_get_child_by_name(state->f1.reg.bcr2, "WREN");
	state->f1.fld.bcr2.waiten = cm_object_get_child_by_name(state->f1.reg.bcr2, "WAITEN");
	state->f1.fld.bcr2.extmod = cm_object_get_child_by_name(state->f1.reg.bcr2, "EXTMOD");
	state->f1.fld.bcr2.asyncwait = cm_object_get_child_by_name(state->f1.reg.bcr2, "ASYNCWAIT");
	state->f1.fld.bcr2.cburstrw = cm_object_get_child_by_name(state->f1.reg.bcr2, "CBURSTRW");

	// BTR2 bitfields.
	state->f1.fld.btr2.addset = cm_object_get_child_by_name(state->f1.reg.btr2, "ADDSET");
	state->f1.fld.btr2.addhld = cm_object_get_child_by_name(state->f1.reg.btr2, "ADDHLD");
	state->f1.fld.btr2.datast = cm_object_get_child_by_name(state->f1.reg.btr2, "DATAST");
	state->f1.fld.btr2.busturn = cm_object_get_child_by_name(state->f1.reg.btr2, "BUSTURN");
	state->f1.fld.btr2.clkdiv = cm_object_get_child_by_name(state->f1.reg.btr2, "CLKDIV");
	state->f1.fld.btr2.datlat = cm_object_get_child_by_name(state->f1.reg.btr2, "DATLAT");
	state->f1.fld.btr2.accmod = cm_object_get_child_by_name(state->f1.reg.btr2, "ACCMOD");

	// BCR3 bitfields.
	state->f1.fld.bcr3.mbken = cm_object_get_child_by_name(state->f1.reg.bcr3, "MBKEN");
	state->f1.fld.bcr3.muxen = cm_object_get_child_by_name(state->f1.reg.bcr3, "MUXEN");
	state->f1.fld.bcr3.mtyp = cm_object_get_child_by_name(state->f1.reg.bcr3, "MTYP");
	state->f1.fld.bcr3.mwid = cm_object_get_child_by_name(state->f1.reg.bcr3, "MWID");
	state->f1.fld.bcr3.faccen = cm_object_get_child_by_name(state->f1.reg.bcr3, "FACCEN");
	state->f1.fld.bcr3.bursten = cm_object_get_child_by_name(state->f1.reg.bcr3, "BURSTEN");
	state->f1.fld.bcr3.waitpol = cm_object_get_child_by_name(state->f1.reg.bcr3, "WAITPOL");
	state->f1.fld.bcr3.wrapmod = cm_object_get_child_by_name(state->f1.reg.bcr3, "WRAPMOD");
	state->f1.fld.bcr3.waitcfg = cm_object_get_child_by_name(state->f1.reg.bcr3, "WAITCFG");
	state->f1.fld.bcr3.wren = cm_object_get_child_by_name(state->f1.reg.bcr3, "WREN");
	state->f1.fld.bcr3.waiten = cm_object_get_child_by_name(state->f1.reg.bcr3, "WAITEN");
	state->f1.fld.bcr3.extmod = cm_object_get_child_by_name(state->f1.reg.bcr3, "EXTMOD");
	state->f1.fld.bcr3.asyncwait = cm_object_get_child_by_name(state->f1.reg.bcr3, "ASYNCWAIT");
	state->f1.fld.bcr3.cburstrw = cm_object_get_child_by_name(state->f1.reg.bcr3, "CBURSTRW");

	// BTR3 bitfields.
	state->f1.fld.btr3.addset = cm_object_get_child_by_name(state->f1.reg.btr3, "ADDSET");
	state->f1.fld.btr3.addhld = cm_object_get_child_by_name(state->f1.reg.btr3, "ADDHLD");
	state->f1.fld.btr3.datast = cm_object_get_child_by_name(state->f1.reg.btr3, "DATAST");
	state->f1.fld.btr3.busturn = cm_object_get_child_by_name(state->f1.reg.btr3, "BUSTURN");
	state->f1.fld.btr3.clkdiv = cm_object_get_child_by_name(state->f1.reg.btr3, "CLKDIV");
	state->f1.fld.btr3.datlat = cm_object_get_child_by_name(state->f1.reg.btr3, "DATLAT");
	state->f1.fld.btr3.accmod = cm_object_get_child_by_name(state->f1.reg.btr3, "ACCMOD");

	// BCR4 bitfields.
	state->f1.fld.bcr4.mbken = cm_object_get_child_by_name(state->f1.reg.bcr4, "MBKEN");
	state->f1.fld.bcr4.muxen = cm_object_get_child_by_name(state->f1.reg.bcr4, "MUXEN");
	state->f1.fld.bcr4.mtyp = cm_object_get_child_by_name(state->f1.reg.bcr4, "MTYP");
	state->f1.fld.bcr4.mwid = cm_object_get_child_by_name(state->f1.reg.bcr4, "MWID");
	state->f1.fld.bcr4.faccen = cm_object_get_child_by_name(state->f1.reg.bcr4, "FACCEN");
	state->f1.fld.bcr4.bursten = cm_object_get_child_by_name(state->f1.reg.bcr4, "BURSTEN");
	state->f1.fld.bcr4.waitpol = cm_object_get_child_by_name(state->f1.reg.bcr4, "WAITPOL");
	state->f1.fld.bcr4.wrapmod = cm_object_get_child_by_name(state->f1.reg.bcr4, "WRAPMOD");
	state->f1.fld.bcr4.waitcfg = cm_object_get_child_by_name(state->f1.reg.bcr4, "WAITCFG");
	state->f1.fld.bcr4.wren = cm_object_get_child_by_name(state->f1.reg.bcr4, "WREN");
	state->f1.fld.bcr4.waiten = cm_object_get_child_by_name(state->f1.reg.bcr4, "WAITEN");
	state->f1.fld.bcr4.extmod = cm_object_get_child_by_name(state->f1.reg.bcr4, "EXTMOD");
	state->f1.fld.bcr4.asyncwait = cm_object_get_child_by_name(state->f1.reg.bcr4, "ASYNCWAIT");
	state->f1.fld.bcr4.cburstrw = cm_object_get_child_by_name(state->f1.reg.bcr4, "CBURSTRW");

	// BTR4 bitfields.
	state->f1.fld.btr4.addset = cm_object_get_child_by_name(state->f1.reg.btr4, "ADDSET");
	state->f1.fld.btr4.addhld = cm_object_get_child_by_name(state->f1.reg.btr4, "ADDHLD");
	state->f1.fld.btr4.datast = cm_object_get_child_by_name(state->f1.reg.btr4, "DATAST");
	state->f1.fld.btr4.busturn = cm_object_get_child_by_name(state->f1.reg.btr4, "BUSTURN");
	state->f1.fld.btr4.clkdiv = cm_object_get_child_by_name(state->f1.reg.btr4, "CLKDIV");
	state->f1.fld.btr4.datlat = cm_object_get_child_by_name(state->f1.reg.btr4, "DATLAT");
	state->f1.fld.btr4.accmod = cm_object_get_child_by_name(state->f1.reg.btr4, "ACCMOD");

	// PCR2 bitfields.
	state->f1.fld.pcr2.pwaiten = cm_object_get_child_by_name(state->f1.reg.pcr2, "PWAITEN");
	state->f1.fld.pcr2.pbken = cm_object_get_child_by_name(state->f1.reg.pcr2, "PBKEN");
	state->f1.fld.pcr2.ptyp = cm_object_get_child_by_name(state->f1.reg.pcr2, "PTYP");
	state->f1.fld.pcr2.pwid = cm_object_get_child_by_name(state->f1.reg.pcr2, "PWID");
	state->f1.fld.pcr2.eccen = cm_object_get_child_by_name(state->f1.reg.pcr2, "ECCEN");
	state->f1.fld.pcr2.tclr = cm_object_get_child_by_name(state->f1.reg.pcr2, "TCLR");
	state->f1.fld.pcr2.tar = cm_object_get_child_by_name(state->f1.reg.pcr2, "TAR");
	state->f1.fld.pcr2.eccps = cm_object_get_child_by_name(state->f1.reg.pcr2, "ECCPS");

	// SR2 bitfields.
	state->f1.fld.sr2.irs = cm_object_get_child_by_name(state->f1.reg.sr2, "IRS");
	state->f1.fld.sr2.ils = cm_object_get_child_by_name(state->f1.reg.sr2, "ILS");
	state->f1.fld.sr2.ifs = cm_object_get_child_by_name(state->f1.reg.sr2, "IFS");
	state->f1.fld.sr2.iren = cm_object_get_child_by_name(state->f1.reg.sr2, "IREN");
	state->f1.fld.sr2.ilen = cm_object_get_child_by_name(state->f1.reg.sr2, "ILEN");
	state->f1.fld.sr2.ifen = cm_object_get_child_by_name(state->f1.reg.sr2, "IFEN");
	state->f1.fld.sr2.fempt = cm_object_get_child_by_name(state->f1.reg.sr2, "FEMPT");

	// PMEM2 bitfields.
	state->f1.fld.pmem2.memsetx = cm_object_get_child_by_name(state->f1.reg.pmem2, "MEMSETx");
	state->f1.fld.pmem2.memwaitx = cm_object_get_child_by_name(state->f1.reg.pmem2, "MEMWAITx");
	state->f1.fld.pmem2.memholdx = cm_object_get_child_by_name(state->f1.reg.pmem2, "MEMHOLDx");
	state->f1.fld.pmem2.memhizx = cm_object_get_child_by_name(state->f1.reg.pmem2, "MEMHIZx");

	// PATT2 bitfields.
	state->f1.fld.patt2.attsetx = cm_object_get_child_by_name(state->f1.reg.patt2, "ATTSETx");
	state->f1.fld.patt2.attwaitx = cm_object_get_child_by_name(state->f1.reg.patt2, "ATTWAITx");
	state->f1.fld.patt2.attholdx = cm_object_get_child_by_name(state->f1.reg.patt2, "ATTHOLDx");
	state->f1.fld.patt2.atthizx = cm_object_get_child_by_name(state->f1.reg.patt2, "ATTHIZx");

	// ECCR2 bitfields.
	state->f1.fld.eccr2.eccx = cm_object_get_child_by_name(state->f1.reg.eccr2, "ECCx");

	// PCR3 bitfields.
	state->f1.fld.pcr3.pwaiten = cm_object_get_child_by_name(state->f1.reg.pcr3, "PWAITEN");
	state->f1.fld.pcr3.pbken = cm_object_get_child_by_name(state->f1.reg.pcr3, "PBKEN");
	state->f1.fld.pcr3.ptyp = cm_object_get_child_by_name(state->f1.reg.pcr3, "PTYP");
	state->f1.fld.pcr3.pwid = cm_object_get_child_by_name(state->f1.reg.pcr3, "PWID");
	state->f1.fld.pcr3.eccen = cm_object_get_child_by_name(state->f1.reg.pcr3, "ECCEN");
	state->f1.fld.pcr3.tclr = cm_object_get_child_by_name(state->f1.reg.pcr3, "TCLR");
	state->f1.fld.pcr3.tar = cm_object_get_child_by_name(state->f1.reg.pcr3, "TAR");
	state->f1.fld.pcr3.eccps = cm_object_get_child_by_name(state->f1.reg.pcr3, "ECCPS");

	// SR3 bitfields.
	state->f1.fld.sr3.irs = cm_object_get_child_by_name(state->f1.reg.sr3, "IRS");
	state->f1.fld.sr3.ils = cm_object_get_child_by_name(state->f1.reg.sr3, "ILS");
	state->f1.fld.sr3.ifs = cm_object_get_child_by_name(state->f1.reg.sr3, "IFS");
	state->f1.fld.sr3.iren = cm_object_get_child_by_name(state->f1.reg.sr3, "IREN");
	state->f1.fld.sr3.ilen = cm_object_get_child_by_name(state->f1.reg.sr3, "ILEN");
	state->f1.fld.sr3.ifen = cm_object_get_child_by_name(state->f1.reg.sr3, "IFEN");
	state->f1.fld.sr3.fempt = cm_object_get_child_by_name(state->f1.reg.sr3, "FEMPT");

	// PMEM3 bitfields.
	state->f1.fld.pmem3.memsetx = cm_object_get_child_by_name(state->f1.reg.pmem3, "MEMSETx");
	state->f1.fld.pmem3.memwaitx = cm_object_get_child_by_name(state->f1.reg.pmem3, "MEMWAITx");
	state->f1.fld.pmem3.memholdx = cm_object_get_child_by_name(state->f1.reg.pmem3, "MEMHOLDx");
	state->f1.fld.pmem3.memhizx = cm_object_get_child_by_name(state->f1.reg.pmem3, "MEMHIZx");

	// PATT3 bitfields.
	state->f1.fld.patt3.attsetx = cm_object_get_child_by_name(state->f1.reg.patt3, "ATTSETx");
	state->f1.fld.patt3.attwaitx = cm_object_get_child_by_name(state->f1.reg.patt3, "ATTWAITx");
	state->f1.fld.patt3.attholdx = cm_object_get_child_by_name(state->f1.reg.patt3, "ATTHOLDx");
	state->f1.fld.patt3.atthizx = cm_object_get_child_by_name(state->f1.reg.patt3, "ATTHIZx");

	// ECCR3 bitfields.
	state->f1.fld.eccr3.eccx = cm_object_get_child_by_name(state->f1.reg.eccr3, "ECCx");

	// PCR4 bitfields.
	state->f1.fld.pcr4.pwaiten = cm_object_get_child_by_name(state->f1.reg.pcr4, "PWAITEN");
	state->f1.fld.pcr4.pbken = cm_object_get_child_by_name(state->f1.reg.pcr4, "PBKEN");
	state->f1.fld.pcr4.ptyp = cm_object_get_child_by_name(state->f1.reg.pcr4, "PTYP");
	state->f1.fld.pcr4.pwid = cm_object_get_child_by_name(state->f1.reg.pcr4, "PWID");
	state->f1.fld.pcr4.eccen = cm_object_get_child_by_name(state->f1.reg.pcr4, "ECCEN");
	state->f1.fld.pcr4.tclr = cm_object_get_child_by_name(state->f1.reg.pcr4, "TCLR");
	state->f1.fld.pcr4.tar = cm_object_get_child_by_name(state->f1.reg.pcr4, "TAR");
	state->f1.fld.pcr4.eccps = cm_object_get_child_by_name(state->f1.reg.pcr4, "ECCPS");

	// SR4 bitfields.
	state->f1.fld.sr4.irs = cm_object_get_child_by_name(state->f1.reg.sr4, "IRS");
	state->f1.fld.sr4.ils = cm_object_get_child_by_name(state->f1.reg.sr4, "ILS");
	state->f1.fld.sr4.ifs = cm_object_get_child_by_name(state->f1.reg.sr4, "IFS");
	state->f1.fld.sr4.iren = cm_object_get_child_by_name(state->f1.reg.sr4, "IREN");
	state->f1.fld.sr4.ilen = cm_object_get_child_by_name(state->f1.reg.sr4, "ILEN");
	state->f1.fld.sr4.ifen = cm_object_get_child_by_name(state->f1.reg.sr4, "IFEN");
	state->f1.fld.sr4.fempt = cm_object_get_child_by_name(state->f1.reg.sr4, "FEMPT");

	// PMEM4 bitfields.
	state->f1.fld.pmem4.memsetx = cm_object_get_child_by_name(state->f1.reg.pmem4, "MEMSETx");
	state->f1.fld.pmem4.memwaitx = cm_object_get_child_by_name(state->f1.reg.pmem4, "MEMWAITx");
	state->f1.fld.pmem4.memholdx = cm_object_get_child_by_name(state->f1.reg.pmem4, "MEMHOLDx");
	state->f1.fld.pmem4.memhizx = cm_object_get_child_by_name(state->f1.reg.pmem4, "MEMHIZx");

	// PATT4 bitfields.
	state->f1.fld.patt4.attsetx = cm_object_get_child_by_name(state->f1.reg.patt4, "ATTSETx");
	state->f1.fld.patt4.attwaitx = cm_object_get_child_by_name(state->f1.reg.patt4, "ATTWAITx");
	state->f1.fld.patt4.attholdx = cm_object_get_child_by_name(state->f1.reg.patt4, "ATTHOLDx");
	state->f1.fld.patt4.atthizx = cm_object_get_child_by_name(state->f1.reg.patt4, "ATTHIZx");

	// PIO4 bitfields.
	state->f1.fld.pio4.iosetx = cm_object_get_child_by_name(state->f1.reg.pio4, "IOSETx");
	state->f1.fld.pio4.iowaitx = cm_object_get_child_by_name(state->f1.reg.pio4, "IOWAITx");
	state->f1.fld.pio4.ioholdx = cm_object_get_child_by_name(state->f1.reg.pio4, "IOHOLDx");
	state->f1.fld.pio4.iohizx = cm_object_get_child_by_name(state->f1.reg.pio4, "IOHIZx");

	// BWTR1 bitfields.
	state->f1.fld.bwtr1.addset = cm_object_get_child_by_name(state->f1.reg.bwtr1, "ADDSET");
	state->f1.fld.bwtr1.addhld = cm_object_get_child_by_name(state->f1.reg.bwtr1, "ADDHLD");
	state->f1.fld.bwtr1.datast = cm_object_get_child_by_name(state->f1.reg.bwtr1, "DATAST");
	state->f1.fld.bwtr1.clkdiv = cm_object_get_child_by_name(state->f1.reg.bwtr1, "CLKDIV");
	state->f1.fld.bwtr1.datlat = cm_object_get_child_by_name(state->f1.reg.bwtr1, "DATLAT");
	state->f1.fld.bwtr1.accmod = cm_object_get_child_by_name(state->f1.reg.bwtr1, "ACCMOD");

	// BWTR2 bitfields.
	state->f1.fld.bwtr2.addset = cm_object_get_child_by_name(state->f1.reg.bwtr2, "ADDSET");
	state->f1.fld.bwtr2.addhld = cm_object_get_child_by_name(state->f1.reg.bwtr2, "ADDHLD");
	state->f1.fld.bwtr2.datast = cm_object_get_child_by_name(state->f1.reg.bwtr2, "DATAST");
	state->f1.fld.bwtr2.clkdiv = cm_object_get_child_by_name(state->f1.reg.bwtr2, "CLKDIV");
	state->f1.fld.bwtr2.datlat = cm_object_get_child_by_name(state->f1.reg.bwtr2, "DATLAT");
	state->f1.fld.bwtr2.accmod = cm_object_get_child_by_name(state->f1.reg.bwtr2, "ACCMOD");

	// BWTR3 bitfields.
	state->f1.fld.bwtr3.addset = cm_object_get_child_by_name(state->f1.reg.bwtr3, "ADDSET");
	state->f1.fld.bwtr3.addhld = cm_object_get_child_by_name(state->f1.reg.bwtr3, "ADDHLD");
	state->f1.fld.bwtr3.datast = cm_object_get_child_by_name(state->f1.reg.bwtr3, "DATAST");
	state->f1.fld.bwtr3.clkdiv = cm_object_get_child_by_name(state->f1.reg.bwtr3, "CLKDIV");
	state->f1.fld.bwtr3.datlat = cm_object_get_child_by_name(state->f1.reg.bwtr3, "DATLAT");
	state->f1.fld.bwtr3.accmod = cm_object_get_child_by_name(state->f1.reg.bwtr3, "ACCMOD");

	// BWTR4 bitfields.
	state->f1.fld.bwtr4.addset = cm_object_get_child_by_name(state->f1.reg.bwtr4, "ADDSET");
	state->f1.fld.bwtr4.addhld = cm_object_get_child_by_name(state->f1.reg.bwtr4, "ADDHLD");
	state->f1.fld.bwtr4.datast = cm_object_get_child_by_name(state->f1.reg.bwtr4, "DATAST");
	state->f1.fld.bwtr4.clkdiv = cm_object_get_child_by_name(state->f1.reg.bwtr4, "CLKDIV");
	state->f1.fld.bwtr4.datlat = cm_object_get_child_by_name(state->f1.reg.bwtr4, "DATLAT");
	state->f1.fld.bwtr4.accmod = cm_object_get_child_by_name(state->f1.reg.bwtr4, "ACCMOD");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// PWR (Power control) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F1 PWR (Power control) registers.
		struct {
			Object *cr; // 0x0 Power control register (PWR_CR)
			Object *csr; // 0x4 Power control register (PWR_CR)
		} reg;

		struct {

			// CR (Power control register (PWR_CR)) bitfields.
			struct {
				Object *lpds; // [0:0] Low Power Deep Sleep
				Object *pdds; // [1:1] Power Down Deep Sleep
				Object *cwuf; // [2:2] Clear Wake-up Flag
				Object *csbf; // [3:3] Clear STANDBY Flag
				Object *pvde; // [4:4] Power Voltage Detector Enable
				Object *pls; // [5:7] PVD Level Selection
				Object *dbp; // [8:8] Disable Backup Domain write protection
			} cr;

			// CSR (Power control register (PWR_CR)) bitfields.
			struct {
				Object *wuf; // [0:0] Wake-Up Flag
				Object *sbf; // [1:1] STANDBY Flag
				Object *pvdo; // [2:2] PVD Output
				Object *ewup; // [8:8] Enable WKUP pin
			} csr;
		} fld;
	} f1;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32PWRState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_pwr_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32PWRState *state = STM32_PWR_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f1.reg.cr = cm_object_get_child_by_name(obj, "CR");
	state->f1.reg.csr = cm_object_get_child_by_name(obj, "CSR");

	// CR bitfields.
	state->f1.fld.cr.lpds = cm_object_get_child_by_name(state->f1.reg.cr, "LPDS");
	state->f1.fld.cr.pdds = cm_object_get_child_by_name(state->f1.reg.cr, "PDDS");
	state->f1.fld.cr.cwuf = cm_object_get_child_by_name(state->f1.reg.cr, "CWUF");
	state->f1.fld.cr.csbf = cm_object_get_child_by_name(state->f1.reg.cr, "CSBF");
	state->f1.fld.cr.pvde = cm_object_get_child_by_name(state->f1.reg.cr, "PVDE");
	state->f1.fld.cr.pls = cm_object_get_child_by_name(state->f1.reg.cr, "PLS");
	state->f1.fld.cr.dbp = cm_object_get_child_by_name(state->f1.reg.cr, "DBP");

	// CSR bitfields.
	state->f1.fld.csr.wuf = cm_object_get_child_by_name(state->f1.reg.csr, "WUF");
	state->f1.fld.csr.sbf = cm_object_get_child_by_name(state->f1.reg.csr, "SBF");
	state->f1.fld.csr.pvdo = cm_object_get_child_by_name(state->f1.reg.csr, "PVDO");
	state->f1.fld.csr.ewup = cm_object_get_child_by_name(state->f1.reg.csr, "EWUP");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// RCC (Reset and clock control) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F1 RCC (Reset and clock control) registers.
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
				Object *ppre1; // [8:10] APB Low speed prescaler (APB1)
				Object *ppre2; // [11:13] APB High speed prescaler (APB2)
				Object *adcpre; // [14:15] ADC prescaler
				Object *pllsrc; // [16:16] PLL entry clock source
				Object *pllxtpre; // [17:17] HSE divider for PLL entry
				Object *pllmul; // [18:21] PLL Multiplication Factor
				Object *otgfspre; // [22:22] USB OTG FS prescaler
				Object *mco; // [24:26] Microcontroller clock output
			} cfgr;

			// CIR (Clock interrupt register (RCC_CIR)) bitfields.
			struct {
				Object *lsirdyf; // [0:0] LSI Ready Interrupt flag
				Object *lserdyf; // [1:1] LSE Ready Interrupt flag
				Object *hsirdyf; // [2:2] HSI Ready Interrupt flag
				Object *hserdyf; // [3:3] HSE Ready Interrupt flag
				Object *pllrdyf; // [4:4] PLL Ready Interrupt flag
				Object *cssf; // [7:7] Clock Security System Interrupt flag
				Object *lsirdyie; // [8:8] LSI Ready Interrupt Enable
				Object *lserdyie; // [9:9] LSE Ready Interrupt Enable
				Object *hsirdyie; // [10:10] HSI Ready Interrupt Enable
				Object *hserdyie; // [11:11] HSE Ready Interrupt Enable
				Object *pllrdyie; // [12:12] PLL Ready Interrupt Enable
				Object *lsirdyc; // [16:16] LSI Ready Interrupt Clear
				Object *lserdyc; // [17:17] LSE Ready Interrupt Clear
				Object *hsirdyc; // [18:18] HSI Ready Interrupt Clear
				Object *hserdyc; // [19:19] HSE Ready Interrupt Clear
				Object *pllrdyc; // [20:20] PLL Ready Interrupt Clear
				Object *cssc; // [23:23] Clock security system interrupt clear
			} cir;

			// APB2RSTR (APB2 peripheral reset register (RCC_APB2RSTR)) bitfields.
			struct {
				Object *afiorst; // [0:0] Alternate function I/O reset
				Object *ioparst; // [2:2] IO port A reset
				Object *iopbrst; // [3:3] IO port B reset
				Object *iopcrst; // [4:4] IO port C reset
				Object *iopdrst; // [5:5] IO port D reset
				Object *ioperst; // [6:6] IO port E reset
				Object *iopfrst; // [7:7] IO port F reset
				Object *iopgrst; // [8:8] IO port G reset
				Object *adc1rst; // [9:9] ADC 1 interface reset
				Object *adc2rst; // [10:10] ADC 2 interface reset
				Object *tim1rst; // [11:11] TIM1 timer reset
				Object *spi1rst; // [12:12] SPI 1 reset
				Object *tim8rst; // [13:13] TIM8 timer reset
				Object *usart1rst; // [14:14] USART1 reset
				Object *adc3rst; // [15:15] ADC 3 interface reset
				Object *tim9rst; // [19:19] TIM9 timer reset
				Object *tim10rst; // [20:20] TIM10 timer reset
				Object *tim11rst; // [21:21] TIM11 timer reset
			} apb2rstr;

			// APB1RSTR (APB1 peripheral reset register (RCC_APB1RSTR)) bitfields.
			struct {
				Object *tim2rst; // [0:0] Timer 2 reset
				Object *tim3rst; // [1:1] Timer 3 reset
				Object *tim4rst; // [2:2] Timer 4 reset
				Object *tim5rst; // [3:3] Timer 5 reset
				Object *tim6rst; // [4:4] Timer 6 reset
				Object *tim7rst; // [5:5] Timer 7 reset
				Object *tim12rst; // [6:6] Timer 12 reset
				Object *tim13rst; // [7:7] Timer 13 reset
				Object *tim14rst; // [8:8] Timer 14 reset
				Object *wwdgrst; // [11:11] Window watchdog reset
				Object *spi2rst; // [14:14] SPI2 reset
				Object *spi3rst; // [15:15] SPI3 reset
				Object *usart2rst; // [17:17] USART 2 reset
				Object *usart3rst; // [18:18] USART 3 reset
				Object *uart4rst; // [19:19] UART 4 reset
				Object *uart5rst; // [20:20] UART 5 reset
				Object *i2c1rst; // [21:21] I2C1 reset
				Object *i2c2rst; // [22:22] I2C2 reset
				Object *usbrst; // [23:23] USB reset
				Object *canrst; // [25:25] CAN reset
				Object *bkprst; // [27:27] Backup interface reset
				Object *pwrrst; // [28:28] Power interface reset
				Object *dacrst; // [29:29] DAC interface reset
			} apb1rstr;

			// AHBENR (AHB Peripheral Clock enable register (RCC_AHBENR)) bitfields.
			struct {
				Object *dma1en; // [0:0] DMA1 clock enable
				Object *dma2en; // [1:1] DMA2 clock enable
				Object *sramen; // [2:2] SRAM interface clock enable
				Object *flitfen; // [4:4] FLITF clock enable
				Object *crcen; // [6:6] CRC clock enable
				Object *fsmcen; // [8:8] FSMC clock enable
				Object *sdioen; // [10:10] SDIO clock enable
			} ahbenr;

			// APB2ENR (APB2 peripheral clock enable register (RCC_APB2ENR)) bitfields.
			struct {
				Object *afioen; // [0:0] Alternate function I/O clock enable
				Object *iopaen; // [2:2] I/O port A clock enable
				Object *iopben; // [3:3] I/O port B clock enable
				Object *iopcen; // [4:4] I/O port C clock enable
				Object *iopden; // [5:5] I/O port D clock enable
				Object *iopeen; // [6:6] I/O port E clock enable
				Object *iopfen; // [7:7] I/O port F clock enable
				Object *iopgen; // [8:8] I/O port G clock enable
				Object *adc1en; // [9:9] ADC 1 interface clock enable
				Object *adc2en; // [10:10] ADC 2 interface clock enable
				Object *tim1en; // [11:11] TIM1 Timer clock enable
				Object *spi1en; // [12:12] SPI 1 clock enable
				Object *tim8en; // [13:13] TIM8 Timer clock enable
				Object *usart1en; // [14:14] USART1 clock enable
				Object *adc3en; // [15:15] ADC3 interface clock enable
				Object *tim9en; // [19:19] TIM9 Timer clock enable
				Object *tim10en; // [20:20] TIM10 Timer clock enable
				Object *tim11en; // [21:21] TIM11 Timer clock enable
			} apb2enr;

			// APB1ENR (APB1 peripheral clock enable register (RCC_APB1ENR)) bitfields.
			struct {
				Object *tim2en; // [0:0] Timer 2 clock enable
				Object *tim3en; // [1:1] Timer 3 clock enable
				Object *tim4en; // [2:2] Timer 4 clock enable
				Object *tim5en; // [3:3] Timer 5 clock enable
				Object *tim6en; // [4:4] Timer 6 clock enable
				Object *tim7en; // [5:5] Timer 7 clock enable
				Object *tim12en; // [6:6] Timer 12 clock enable
				Object *tim13en; // [7:7] Timer 13 clock enable
				Object *tim14en; // [8:8] Timer 14 clock enable
				Object *wwdgen; // [11:11] Window watchdog clock enable
				Object *spi2en; // [14:14] SPI 2 clock enable
				Object *spi3en; // [15:15] SPI 3 clock enable
				Object *usart2en; // [17:17] USART 2 clock enable
				Object *usart3en; // [18:18] USART 3 clock enable
				Object *uart4en; // [19:19] UART 4 clock enable
				Object *uart5en; // [20:20] UART 5 clock enable
				Object *i2c1en; // [21:21] I2C 1 clock enable
				Object *i2c2en; // [22:22] I2C 2 clock enable
				Object *usben; // [23:23] USB clock enable
				Object *canen; // [25:25] CAN clock enable
				Object *bkpen; // [27:27] Backup interface clock enable
				Object *pwren; // [28:28] Power interface clock enable
				Object *dacen; // [29:29] DAC interface clock enable
			} apb1enr;

			// BDCR (Backup domain control register (RCC_BDCR)) bitfields.
			struct {
				Object *lseon; // [0:0] External Low Speed oscillator enable
				Object *lserdy; // [1:1] External Low Speed oscillator ready
				Object *lsebyp; // [2:2] External Low Speed oscillator bypass
				Object *rtcsel; // [8:9] RTC clock source selection
				Object *rtcen; // [15:15] RTC clock enable
				Object *bdrst; // [16:16] Backup domain software reset
			} bdcr;

			// CSR (Control/status register (RCC_CSR)) bitfields.
			struct {
				Object *lsion; // [0:0] Internal low speed oscillator enable
				Object *lsirdy; // [1:1] Internal low speed oscillator ready
				Object *rmvf; // [24:24] Remove reset flag
				Object *pinrstf; // [26:26] PIN reset flag
				Object *porrstf; // [27:27] POR/PDR reset flag
				Object *sftrstf; // [28:28] Software reset flag
				Object *iwdgrstf; // [29:29] Independent watchdog reset flag
				Object *wwdgrstf; // [30:30] Window watchdog reset flag
				Object *lpwrrstf; // [31:31] Low-power reset flag
			} csr;
		} fld;
	} f1;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32RCCState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_rcc_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32RCCState *state = STM32_RCC_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f1.reg.cr = cm_object_get_child_by_name(obj, "CR");
	state->f1.reg.cfgr = cm_object_get_child_by_name(obj, "CFGR");
	state->f1.reg.cir = cm_object_get_child_by_name(obj, "CIR");
	state->f1.reg.apb2rstr = cm_object_get_child_by_name(obj, "APB2RSTR");
	state->f1.reg.apb1rstr = cm_object_get_child_by_name(obj, "APB1RSTR");
	state->f1.reg.ahbenr = cm_object_get_child_by_name(obj, "AHBENR");
	state->f1.reg.apb2enr = cm_object_get_child_by_name(obj, "APB2ENR");
	state->f1.reg.apb1enr = cm_object_get_child_by_name(obj, "APB1ENR");
	state->f1.reg.bdcr = cm_object_get_child_by_name(obj, "BDCR");
	state->f1.reg.csr = cm_object_get_child_by_name(obj, "CSR");

	// CR bitfields.
	state->f1.fld.cr.hsion = cm_object_get_child_by_name(state->f1.reg.cr, "HSION");
	state->f1.fld.cr.hsirdy = cm_object_get_child_by_name(state->f1.reg.cr, "HSIRDY");
	state->f1.fld.cr.hsitrim = cm_object_get_child_by_name(state->f1.reg.cr, "HSITRIM");
	state->f1.fld.cr.hsical = cm_object_get_child_by_name(state->f1.reg.cr, "HSICAL");
	state->f1.fld.cr.hseon = cm_object_get_child_by_name(state->f1.reg.cr, "HSEON");
	state->f1.fld.cr.hserdy = cm_object_get_child_by_name(state->f1.reg.cr, "HSERDY");
	state->f1.fld.cr.hsebyp = cm_object_get_child_by_name(state->f1.reg.cr, "HSEBYP");
	state->f1.fld.cr.csson = cm_object_get_child_by_name(state->f1.reg.cr, "CSSON");
	state->f1.fld.cr.pllon = cm_object_get_child_by_name(state->f1.reg.cr, "PLLON");
	state->f1.fld.cr.pllrdy = cm_object_get_child_by_name(state->f1.reg.cr, "PLLRDY");

	// CFGR bitfields.
	state->f1.fld.cfgr.sw = cm_object_get_child_by_name(state->f1.reg.cfgr, "SW");
	state->f1.fld.cfgr.sws = cm_object_get_child_by_name(state->f1.reg.cfgr, "SWS");
	state->f1.fld.cfgr.hpre = cm_object_get_child_by_name(state->f1.reg.cfgr, "HPRE");
	state->f1.fld.cfgr.ppre1 = cm_object_get_child_by_name(state->f1.reg.cfgr, "PPRE1");
	state->f1.fld.cfgr.ppre2 = cm_object_get_child_by_name(state->f1.reg.cfgr, "PPRE2");
	state->f1.fld.cfgr.adcpre = cm_object_get_child_by_name(state->f1.reg.cfgr, "ADCPRE");
	state->f1.fld.cfgr.pllsrc = cm_object_get_child_by_name(state->f1.reg.cfgr, "PLLSRC");
	state->f1.fld.cfgr.pllxtpre = cm_object_get_child_by_name(state->f1.reg.cfgr, "PLLXTPRE");
	state->f1.fld.cfgr.pllmul = cm_object_get_child_by_name(state->f1.reg.cfgr, "PLLMUL");
	state->f1.fld.cfgr.otgfspre = cm_object_get_child_by_name(state->f1.reg.cfgr, "OTGFSPRE");
	state->f1.fld.cfgr.mco = cm_object_get_child_by_name(state->f1.reg.cfgr, "MCO");

	// CIR bitfields.
	state->f1.fld.cir.lsirdyf = cm_object_get_child_by_name(state->f1.reg.cir, "LSIRDYF");
	state->f1.fld.cir.lserdyf = cm_object_get_child_by_name(state->f1.reg.cir, "LSERDYF");
	state->f1.fld.cir.hsirdyf = cm_object_get_child_by_name(state->f1.reg.cir, "HSIRDYF");
	state->f1.fld.cir.hserdyf = cm_object_get_child_by_name(state->f1.reg.cir, "HSERDYF");
	state->f1.fld.cir.pllrdyf = cm_object_get_child_by_name(state->f1.reg.cir, "PLLRDYF");
	state->f1.fld.cir.cssf = cm_object_get_child_by_name(state->f1.reg.cir, "CSSF");
	state->f1.fld.cir.lsirdyie = cm_object_get_child_by_name(state->f1.reg.cir, "LSIRDYIE");
	state->f1.fld.cir.lserdyie = cm_object_get_child_by_name(state->f1.reg.cir, "LSERDYIE");
	state->f1.fld.cir.hsirdyie = cm_object_get_child_by_name(state->f1.reg.cir, "HSIRDYIE");
	state->f1.fld.cir.hserdyie = cm_object_get_child_by_name(state->f1.reg.cir, "HSERDYIE");
	state->f1.fld.cir.pllrdyie = cm_object_get_child_by_name(state->f1.reg.cir, "PLLRDYIE");
	state->f1.fld.cir.lsirdyc = cm_object_get_child_by_name(state->f1.reg.cir, "LSIRDYC");
	state->f1.fld.cir.lserdyc = cm_object_get_child_by_name(state->f1.reg.cir, "LSERDYC");
	state->f1.fld.cir.hsirdyc = cm_object_get_child_by_name(state->f1.reg.cir, "HSIRDYC");
	state->f1.fld.cir.hserdyc = cm_object_get_child_by_name(state->f1.reg.cir, "HSERDYC");
	state->f1.fld.cir.pllrdyc = cm_object_get_child_by_name(state->f1.reg.cir, "PLLRDYC");
	state->f1.fld.cir.cssc = cm_object_get_child_by_name(state->f1.reg.cir, "CSSC");

	// APB2RSTR bitfields.
	state->f1.fld.apb2rstr.afiorst = cm_object_get_child_by_name(state->f1.reg.apb2rstr, "AFIORST");
	state->f1.fld.apb2rstr.ioparst = cm_object_get_child_by_name(state->f1.reg.apb2rstr, "IOPARST");
	state->f1.fld.apb2rstr.iopbrst = cm_object_get_child_by_name(state->f1.reg.apb2rstr, "IOPBRST");
	state->f1.fld.apb2rstr.iopcrst = cm_object_get_child_by_name(state->f1.reg.apb2rstr, "IOPCRST");
	state->f1.fld.apb2rstr.iopdrst = cm_object_get_child_by_name(state->f1.reg.apb2rstr, "IOPDRST");
	state->f1.fld.apb2rstr.ioperst = cm_object_get_child_by_name(state->f1.reg.apb2rstr, "IOPERST");
	state->f1.fld.apb2rstr.iopfrst = cm_object_get_child_by_name(state->f1.reg.apb2rstr, "IOPFRST");
	state->f1.fld.apb2rstr.iopgrst = cm_object_get_child_by_name(state->f1.reg.apb2rstr, "IOPGRST");
	state->f1.fld.apb2rstr.adc1rst = cm_object_get_child_by_name(state->f1.reg.apb2rstr, "ADC1RST");
	state->f1.fld.apb2rstr.adc2rst = cm_object_get_child_by_name(state->f1.reg.apb2rstr, "ADC2RST");
	state->f1.fld.apb2rstr.tim1rst = cm_object_get_child_by_name(state->f1.reg.apb2rstr, "TIM1RST");
	state->f1.fld.apb2rstr.spi1rst = cm_object_get_child_by_name(state->f1.reg.apb2rstr, "SPI1RST");
	state->f1.fld.apb2rstr.tim8rst = cm_object_get_child_by_name(state->f1.reg.apb2rstr, "TIM8RST");
	state->f1.fld.apb2rstr.usart1rst = cm_object_get_child_by_name(state->f1.reg.apb2rstr, "USART1RST");
	state->f1.fld.apb2rstr.adc3rst = cm_object_get_child_by_name(state->f1.reg.apb2rstr, "ADC3RST");
	state->f1.fld.apb2rstr.tim9rst = cm_object_get_child_by_name(state->f1.reg.apb2rstr, "TIM9RST");
	state->f1.fld.apb2rstr.tim10rst = cm_object_get_child_by_name(state->f1.reg.apb2rstr, "TIM10RST");
	state->f1.fld.apb2rstr.tim11rst = cm_object_get_child_by_name(state->f1.reg.apb2rstr, "TIM11RST");

	// APB1RSTR bitfields.
	state->f1.fld.apb1rstr.tim2rst = cm_object_get_child_by_name(state->f1.reg.apb1rstr, "TIM2RST");
	state->f1.fld.apb1rstr.tim3rst = cm_object_get_child_by_name(state->f1.reg.apb1rstr, "TIM3RST");
	state->f1.fld.apb1rstr.tim4rst = cm_object_get_child_by_name(state->f1.reg.apb1rstr, "TIM4RST");
	state->f1.fld.apb1rstr.tim5rst = cm_object_get_child_by_name(state->f1.reg.apb1rstr, "TIM5RST");
	state->f1.fld.apb1rstr.tim6rst = cm_object_get_child_by_name(state->f1.reg.apb1rstr, "TIM6RST");
	state->f1.fld.apb1rstr.tim7rst = cm_object_get_child_by_name(state->f1.reg.apb1rstr, "TIM7RST");
	state->f1.fld.apb1rstr.tim12rst = cm_object_get_child_by_name(state->f1.reg.apb1rstr, "TIM12RST");
	state->f1.fld.apb1rstr.tim13rst = cm_object_get_child_by_name(state->f1.reg.apb1rstr, "TIM13RST");
	state->f1.fld.apb1rstr.tim14rst = cm_object_get_child_by_name(state->f1.reg.apb1rstr, "TIM14RST");
	state->f1.fld.apb1rstr.wwdgrst = cm_object_get_child_by_name(state->f1.reg.apb1rstr, "WWDGRST");
	state->f1.fld.apb1rstr.spi2rst = cm_object_get_child_by_name(state->f1.reg.apb1rstr, "SPI2RST");
	state->f1.fld.apb1rstr.spi3rst = cm_object_get_child_by_name(state->f1.reg.apb1rstr, "SPI3RST");
	state->f1.fld.apb1rstr.usart2rst = cm_object_get_child_by_name(state->f1.reg.apb1rstr, "USART2RST");
	state->f1.fld.apb1rstr.usart3rst = cm_object_get_child_by_name(state->f1.reg.apb1rstr, "USART3RST");
	state->f1.fld.apb1rstr.uart4rst = cm_object_get_child_by_name(state->f1.reg.apb1rstr, "UART4RST");
	state->f1.fld.apb1rstr.uart5rst = cm_object_get_child_by_name(state->f1.reg.apb1rstr, "UART5RST");
	state->f1.fld.apb1rstr.i2c1rst = cm_object_get_child_by_name(state->f1.reg.apb1rstr, "I2C1RST");
	state->f1.fld.apb1rstr.i2c2rst = cm_object_get_child_by_name(state->f1.reg.apb1rstr, "I2C2RST");
	state->f1.fld.apb1rstr.usbrst = cm_object_get_child_by_name(state->f1.reg.apb1rstr, "USBRST");
	state->f1.fld.apb1rstr.canrst = cm_object_get_child_by_name(state->f1.reg.apb1rstr, "CANRST");
	state->f1.fld.apb1rstr.bkprst = cm_object_get_child_by_name(state->f1.reg.apb1rstr, "BKPRST");
	state->f1.fld.apb1rstr.pwrrst = cm_object_get_child_by_name(state->f1.reg.apb1rstr, "PWRRST");
	state->f1.fld.apb1rstr.dacrst = cm_object_get_child_by_name(state->f1.reg.apb1rstr, "DACRST");

	// AHBENR bitfields.
	state->f1.fld.ahbenr.dma1en = cm_object_get_child_by_name(state->f1.reg.ahbenr, "DMA1EN");
	state->f1.fld.ahbenr.dma2en = cm_object_get_child_by_name(state->f1.reg.ahbenr, "DMA2EN");
	state->f1.fld.ahbenr.sramen = cm_object_get_child_by_name(state->f1.reg.ahbenr, "SRAMEN");
	state->f1.fld.ahbenr.flitfen = cm_object_get_child_by_name(state->f1.reg.ahbenr, "FLITFEN");
	state->f1.fld.ahbenr.crcen = cm_object_get_child_by_name(state->f1.reg.ahbenr, "CRCEN");
	state->f1.fld.ahbenr.fsmcen = cm_object_get_child_by_name(state->f1.reg.ahbenr, "FSMCEN");
	state->f1.fld.ahbenr.sdioen = cm_object_get_child_by_name(state->f1.reg.ahbenr, "SDIOEN");

	// APB2ENR bitfields.
	state->f1.fld.apb2enr.afioen = cm_object_get_child_by_name(state->f1.reg.apb2enr, "AFIOEN");
	state->f1.fld.apb2enr.iopaen = cm_object_get_child_by_name(state->f1.reg.apb2enr, "IOPAEN");
	state->f1.fld.apb2enr.iopben = cm_object_get_child_by_name(state->f1.reg.apb2enr, "IOPBEN");
	state->f1.fld.apb2enr.iopcen = cm_object_get_child_by_name(state->f1.reg.apb2enr, "IOPCEN");
	state->f1.fld.apb2enr.iopden = cm_object_get_child_by_name(state->f1.reg.apb2enr, "IOPDEN");
	state->f1.fld.apb2enr.iopeen = cm_object_get_child_by_name(state->f1.reg.apb2enr, "IOPEEN");
	state->f1.fld.apb2enr.iopfen = cm_object_get_child_by_name(state->f1.reg.apb2enr, "IOPFEN");
	state->f1.fld.apb2enr.iopgen = cm_object_get_child_by_name(state->f1.reg.apb2enr, "IOPGEN");
	state->f1.fld.apb2enr.adc1en = cm_object_get_child_by_name(state->f1.reg.apb2enr, "ADC1EN");
	state->f1.fld.apb2enr.adc2en = cm_object_get_child_by_name(state->f1.reg.apb2enr, "ADC2EN");
	state->f1.fld.apb2enr.tim1en = cm_object_get_child_by_name(state->f1.reg.apb2enr, "TIM1EN");
	state->f1.fld.apb2enr.spi1en = cm_object_get_child_by_name(state->f1.reg.apb2enr, "SPI1EN");
	state->f1.fld.apb2enr.tim8en = cm_object_get_child_by_name(state->f1.reg.apb2enr, "TIM8EN");
	state->f1.fld.apb2enr.usart1en = cm_object_get_child_by_name(state->f1.reg.apb2enr, "USART1EN");
	state->f1.fld.apb2enr.adc3en = cm_object_get_child_by_name(state->f1.reg.apb2enr, "ADC3EN");
	state->f1.fld.apb2enr.tim9en = cm_object_get_child_by_name(state->f1.reg.apb2enr, "TIM9EN");
	state->f1.fld.apb2enr.tim10en = cm_object_get_child_by_name(state->f1.reg.apb2enr, "TIM10EN");
	state->f1.fld.apb2enr.tim11en = cm_object_get_child_by_name(state->f1.reg.apb2enr, "TIM11EN");

	// APB1ENR bitfields.
	state->f1.fld.apb1enr.tim2en = cm_object_get_child_by_name(state->f1.reg.apb1enr, "TIM2EN");
	state->f1.fld.apb1enr.tim3en = cm_object_get_child_by_name(state->f1.reg.apb1enr, "TIM3EN");
	state->f1.fld.apb1enr.tim4en = cm_object_get_child_by_name(state->f1.reg.apb1enr, "TIM4EN");
	state->f1.fld.apb1enr.tim5en = cm_object_get_child_by_name(state->f1.reg.apb1enr, "TIM5EN");
	state->f1.fld.apb1enr.tim6en = cm_object_get_child_by_name(state->f1.reg.apb1enr, "TIM6EN");
	state->f1.fld.apb1enr.tim7en = cm_object_get_child_by_name(state->f1.reg.apb1enr, "TIM7EN");
	state->f1.fld.apb1enr.tim12en = cm_object_get_child_by_name(state->f1.reg.apb1enr, "TIM12EN");
	state->f1.fld.apb1enr.tim13en = cm_object_get_child_by_name(state->f1.reg.apb1enr, "TIM13EN");
	state->f1.fld.apb1enr.tim14en = cm_object_get_child_by_name(state->f1.reg.apb1enr, "TIM14EN");
	state->f1.fld.apb1enr.wwdgen = cm_object_get_child_by_name(state->f1.reg.apb1enr, "WWDGEN");
	state->f1.fld.apb1enr.spi2en = cm_object_get_child_by_name(state->f1.reg.apb1enr, "SPI2EN");
	state->f1.fld.apb1enr.spi3en = cm_object_get_child_by_name(state->f1.reg.apb1enr, "SPI3EN");
	state->f1.fld.apb1enr.usart2en = cm_object_get_child_by_name(state->f1.reg.apb1enr, "USART2EN");
	state->f1.fld.apb1enr.usart3en = cm_object_get_child_by_name(state->f1.reg.apb1enr, "USART3EN");
	state->f1.fld.apb1enr.uart4en = cm_object_get_child_by_name(state->f1.reg.apb1enr, "UART4EN");
	state->f1.fld.apb1enr.uart5en = cm_object_get_child_by_name(state->f1.reg.apb1enr, "UART5EN");
	state->f1.fld.apb1enr.i2c1en = cm_object_get_child_by_name(state->f1.reg.apb1enr, "I2C1EN");
	state->f1.fld.apb1enr.i2c2en = cm_object_get_child_by_name(state->f1.reg.apb1enr, "I2C2EN");
	state->f1.fld.apb1enr.usben = cm_object_get_child_by_name(state->f1.reg.apb1enr, "USBEN");
	state->f1.fld.apb1enr.canen = cm_object_get_child_by_name(state->f1.reg.apb1enr, "CANEN");
	state->f1.fld.apb1enr.bkpen = cm_object_get_child_by_name(state->f1.reg.apb1enr, "BKPEN");
	state->f1.fld.apb1enr.pwren = cm_object_get_child_by_name(state->f1.reg.apb1enr, "PWREN");
	state->f1.fld.apb1enr.dacen = cm_object_get_child_by_name(state->f1.reg.apb1enr, "DACEN");

	// BDCR bitfields.
	state->f1.fld.bdcr.lseon = cm_object_get_child_by_name(state->f1.reg.bdcr, "LSEON");
	state->f1.fld.bdcr.lserdy = cm_object_get_child_by_name(state->f1.reg.bdcr, "LSERDY");
	state->f1.fld.bdcr.lsebyp = cm_object_get_child_by_name(state->f1.reg.bdcr, "LSEBYP");
	state->f1.fld.bdcr.rtcsel = cm_object_get_child_by_name(state->f1.reg.bdcr, "RTCSEL");
	state->f1.fld.bdcr.rtcen = cm_object_get_child_by_name(state->f1.reg.bdcr, "RTCEN");
	state->f1.fld.bdcr.bdrst = cm_object_get_child_by_name(state->f1.reg.bdcr, "BDRST");

	// CSR bitfields.
	state->f1.fld.csr.lsion = cm_object_get_child_by_name(state->f1.reg.csr, "LSION");
	state->f1.fld.csr.lsirdy = cm_object_get_child_by_name(state->f1.reg.csr, "LSIRDY");
	state->f1.fld.csr.rmvf = cm_object_get_child_by_name(state->f1.reg.csr, "RMVF");
	state->f1.fld.csr.pinrstf = cm_object_get_child_by_name(state->f1.reg.csr, "PINRSTF");
	state->f1.fld.csr.porrstf = cm_object_get_child_by_name(state->f1.reg.csr, "PORRSTF");
	state->f1.fld.csr.sftrstf = cm_object_get_child_by_name(state->f1.reg.csr, "SFTRSTF");
	state->f1.fld.csr.iwdgrstf = cm_object_get_child_by_name(state->f1.reg.csr, "IWDGRSTF");
	state->f1.fld.csr.wwdgrstf = cm_object_get_child_by_name(state->f1.reg.csr, "WWDGRSTF");
	state->f1.fld.csr.lpwrrstf = cm_object_get_child_by_name(state->f1.reg.csr, "LPWRRSTF");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// GPIOA (General purpose I/O) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F1 GPIOA (General purpose I/O) registers.
		struct {
			Object *crl; // 0x0 Port configuration register low (GPIOn_CRL)
			Object *crh; // 0x4 Port configuration register high (GPIOn_CRL)
			Object *idr; // 0x8 Port input data register (GPIOn_IDR)
			Object *odr; // 0xC Port output data register (GPIOn_ODR)
			Object *bsrr; // 0x10 Port bit set/reset register (GPIOn_BSRR)
			Object *brr; // 0x14 Port bit reset register (GPIOn_BRR)
			Object *lckr; // 0x18 Port configuration lock register
		} reg;

		struct {

			// CRL (Port configuration register low (GPIOn_CRL)) bitfields.
			struct {
				Object *mode0; // [0:1] Port n.0 mode bits
				Object *cnf0; // [2:3] Port n.0 configuration bits
				Object *mode1; // [4:5] Port n.1 mode bits
				Object *cnf1; // [6:7] Port n.1 configuration bits
				Object *mode2; // [8:9] Port n.2 mode bits
				Object *cnf2; // [10:11] Port n.2 configuration bits
				Object *mode3; // [12:13] Port n.3 mode bits
				Object *cnf3; // [14:15] Port n.3 configuration bits
				Object *mode4; // [16:17] Port n.4 mode bits
				Object *cnf4; // [18:19] Port n.4 configuration bits
				Object *mode5; // [20:21] Port n.5 mode bits
				Object *cnf5; // [22:23] Port n.5 configuration bits
				Object *mode6; // [24:25] Port n.6 mode bits
				Object *cnf6; // [26:27] Port n.6 configuration bits
				Object *mode7; // [28:29] Port n.7 mode bits
				Object *cnf7; // [30:31] Port n.7 configuration bits
			} crl;

			// CRH (Port configuration register high (GPIOn_CRL)) bitfields.
			struct {
				Object *mode8; // [0:1] Port n.8 mode bits
				Object *cnf8; // [2:3] Port n.8 configuration bits
				Object *mode9; // [4:5] Port n.9 mode bits
				Object *cnf9; // [6:7] Port n.9 configuration bits
				Object *mode10; // [8:9] Port n.10 mode bits
				Object *cnf10; // [10:11] Port n.10 configuration bits
				Object *mode11; // [12:13] Port n.11 mode bits
				Object *cnf11; // [14:15] Port n.11 configuration bits
				Object *mode12; // [16:17] Port n.12 mode bits
				Object *cnf12; // [18:19] Port n.12 configuration bits
				Object *mode13; // [20:21] Port n.13 mode bits
				Object *cnf13; // [22:23] Port n.13 configuration bits
				Object *mode14; // [24:25] Port n.14 mode bits
				Object *cnf14; // [26:27] Port n.14 configuration bits
				Object *mode15; // [28:29] Port n.15 mode bits
				Object *cnf15; // [30:31] Port n.15 configuration bits
			} crh;

			// IDR (Port input data register (GPIOn_IDR)) bitfields.
			struct {
				Object *idr0; // [0:0] Port input data
				Object *idr1; // [1:1] Port input data
				Object *idr2; // [2:2] Port input data
				Object *idr3; // [3:3] Port input data
				Object *idr4; // [4:4] Port input data
				Object *idr5; // [5:5] Port input data
				Object *idr6; // [6:6] Port input data
				Object *idr7; // [7:7] Port input data
				Object *idr8; // [8:8] Port input data
				Object *idr9; // [9:9] Port input data
				Object *idr10; // [10:10] Port input data
				Object *idr11; // [11:11] Port input data
				Object *idr12; // [12:12] Port input data
				Object *idr13; // [13:13] Port input data
				Object *idr14; // [14:14] Port input data
				Object *idr15; // [15:15] Port input data
			} idr;

			// ODR (Port output data register (GPIOn_ODR)) bitfields.
			struct {
				Object *odr0; // [0:0] Port output data
				Object *odr1; // [1:1] Port output data
				Object *odr2; // [2:2] Port output data
				Object *odr3; // [3:3] Port output data
				Object *odr4; // [4:4] Port output data
				Object *odr5; // [5:5] Port output data
				Object *odr6; // [6:6] Port output data
				Object *odr7; // [7:7] Port output data
				Object *odr8; // [8:8] Port output data
				Object *odr9; // [9:9] Port output data
				Object *odr10; // [10:10] Port output data
				Object *odr11; // [11:11] Port output data
				Object *odr12; // [12:12] Port output data
				Object *odr13; // [13:13] Port output data
				Object *odr14; // [14:14] Port output data
				Object *odr15; // [15:15] Port output data
			} odr;

			// BSRR (Port bit set/reset register (GPIOn_BSRR)) bitfields.
			struct {
				Object *bs0; // [0:0] Set bit 0
				Object *bs1; // [1:1] Set bit 1
				Object *bs2; // [2:2] Set bit 1
				Object *bs3; // [3:3] Set bit 3
				Object *bs4; // [4:4] Set bit 4
				Object *bs5; // [5:5] Set bit 5
				Object *bs6; // [6:6] Set bit 6
				Object *bs7; // [7:7] Set bit 7
				Object *bs8; // [8:8] Set bit 8
				Object *bs9; // [9:9] Set bit 9
				Object *bs10; // [10:10] Set bit 10
				Object *bs11; // [11:11] Set bit 11
				Object *bs12; // [12:12] Set bit 12
				Object *bs13; // [13:13] Set bit 13
				Object *bs14; // [14:14] Set bit 14
				Object *bs15; // [15:15] Set bit 15
				Object *br0; // [16:16] Reset bit 0
				Object *br1; // [17:17] Reset bit 1
				Object *br2; // [18:18] Reset bit 2
				Object *br3; // [19:19] Reset bit 3
				Object *br4; // [20:20] Reset bit 4
				Object *br5; // [21:21] Reset bit 5
				Object *br6; // [22:22] Reset bit 6
				Object *br7; // [23:23] Reset bit 7
				Object *br8; // [24:24] Reset bit 8
				Object *br9; // [25:25] Reset bit 9
				Object *br10; // [26:26] Reset bit 10
				Object *br11; // [27:27] Reset bit 11
				Object *br12; // [28:28] Reset bit 12
				Object *br13; // [29:29] Reset bit 13
				Object *br14; // [30:30] Reset bit 14
				Object *br15; // [31:31] Reset bit 15
			} bsrr;

			// BRR (Port bit reset register (GPIOn_BRR)) bitfields.
			struct {
				Object *br0; // [0:0] Reset bit 0
				Object *br1; // [1:1] Reset bit 1
				Object *br2; // [2:2] Reset bit 1
				Object *br3; // [3:3] Reset bit 3
				Object *br4; // [4:4] Reset bit 4
				Object *br5; // [5:5] Reset bit 5
				Object *br6; // [6:6] Reset bit 6
				Object *br7; // [7:7] Reset bit 7
				Object *br8; // [8:8] Reset bit 8
				Object *br9; // [9:9] Reset bit 9
				Object *br10; // [10:10] Reset bit 10
				Object *br11; // [11:11] Reset bit 11
				Object *br12; // [12:12] Reset bit 12
				Object *br13; // [13:13] Reset bit 13
				Object *br14; // [14:14] Reset bit 14
				Object *br15; // [15:15] Reset bit 15
			} brr;

			// LCKR (Port configuration lock register) bitfields.
			struct {
				Object *lck0; // [0:0] Port A Lock bit 0
				Object *lck1; // [1:1] Port A Lock bit 1
				Object *lck2; // [2:2] Port A Lock bit 2
				Object *lck3; // [3:3] Port A Lock bit 3
				Object *lck4; // [4:4] Port A Lock bit 4
				Object *lck5; // [5:5] Port A Lock bit 5
				Object *lck6; // [6:6] Port A Lock bit 6
				Object *lck7; // [7:7] Port A Lock bit 7
				Object *lck8; // [8:8] Port A Lock bit 8
				Object *lck9; // [9:9] Port A Lock bit 9
				Object *lck10; // [10:10] Port A Lock bit 10
				Object *lck11; // [11:11] Port A Lock bit 11
				Object *lck12; // [12:12] Port A Lock bit 12
				Object *lck13; // [13:13] Port A Lock bit 13
				Object *lck14; // [14:14] Port A Lock bit 14
				Object *lck15; // [15:15] Port A Lock bit 15
				Object *lckk; // [16:16] Lock key
			} lckr;
		} fld;
	} f1;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32GPIOAState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_gpioa_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32GPIOAState *state = STM32_GPIOA_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f1.reg.crl = cm_object_get_child_by_name(obj, "CRL");
	state->f1.reg.crh = cm_object_get_child_by_name(obj, "CRH");
	state->f1.reg.idr = cm_object_get_child_by_name(obj, "IDR");
	state->f1.reg.odr = cm_object_get_child_by_name(obj, "ODR");
	state->f1.reg.bsrr = cm_object_get_child_by_name(obj, "BSRR");
	state->f1.reg.brr = cm_object_get_child_by_name(obj, "BRR");
	state->f1.reg.lckr = cm_object_get_child_by_name(obj, "LCKR");

	// CRL bitfields.
	state->f1.fld.crl.mode0 = cm_object_get_child_by_name(state->f1.reg.crl, "MODE0");
	state->f1.fld.crl.cnf0 = cm_object_get_child_by_name(state->f1.reg.crl, "CNF0");
	state->f1.fld.crl.mode1 = cm_object_get_child_by_name(state->f1.reg.crl, "MODE1");
	state->f1.fld.crl.cnf1 = cm_object_get_child_by_name(state->f1.reg.crl, "CNF1");
	state->f1.fld.crl.mode2 = cm_object_get_child_by_name(state->f1.reg.crl, "MODE2");
	state->f1.fld.crl.cnf2 = cm_object_get_child_by_name(state->f1.reg.crl, "CNF2");
	state->f1.fld.crl.mode3 = cm_object_get_child_by_name(state->f1.reg.crl, "MODE3");
	state->f1.fld.crl.cnf3 = cm_object_get_child_by_name(state->f1.reg.crl, "CNF3");
	state->f1.fld.crl.mode4 = cm_object_get_child_by_name(state->f1.reg.crl, "MODE4");
	state->f1.fld.crl.cnf4 = cm_object_get_child_by_name(state->f1.reg.crl, "CNF4");
	state->f1.fld.crl.mode5 = cm_object_get_child_by_name(state->f1.reg.crl, "MODE5");
	state->f1.fld.crl.cnf5 = cm_object_get_child_by_name(state->f1.reg.crl, "CNF5");
	state->f1.fld.crl.mode6 = cm_object_get_child_by_name(state->f1.reg.crl, "MODE6");
	state->f1.fld.crl.cnf6 = cm_object_get_child_by_name(state->f1.reg.crl, "CNF6");
	state->f1.fld.crl.mode7 = cm_object_get_child_by_name(state->f1.reg.crl, "MODE7");
	state->f1.fld.crl.cnf7 = cm_object_get_child_by_name(state->f1.reg.crl, "CNF7");

	// CRH bitfields.
	state->f1.fld.crh.mode8 = cm_object_get_child_by_name(state->f1.reg.crh, "MODE8");
	state->f1.fld.crh.cnf8 = cm_object_get_child_by_name(state->f1.reg.crh, "CNF8");
	state->f1.fld.crh.mode9 = cm_object_get_child_by_name(state->f1.reg.crh, "MODE9");
	state->f1.fld.crh.cnf9 = cm_object_get_child_by_name(state->f1.reg.crh, "CNF9");
	state->f1.fld.crh.mode10 = cm_object_get_child_by_name(state->f1.reg.crh, "MODE10");
	state->f1.fld.crh.cnf10 = cm_object_get_child_by_name(state->f1.reg.crh, "CNF10");
	state->f1.fld.crh.mode11 = cm_object_get_child_by_name(state->f1.reg.crh, "MODE11");
	state->f1.fld.crh.cnf11 = cm_object_get_child_by_name(state->f1.reg.crh, "CNF11");
	state->f1.fld.crh.mode12 = cm_object_get_child_by_name(state->f1.reg.crh, "MODE12");
	state->f1.fld.crh.cnf12 = cm_object_get_child_by_name(state->f1.reg.crh, "CNF12");
	state->f1.fld.crh.mode13 = cm_object_get_child_by_name(state->f1.reg.crh, "MODE13");
	state->f1.fld.crh.cnf13 = cm_object_get_child_by_name(state->f1.reg.crh, "CNF13");
	state->f1.fld.crh.mode14 = cm_object_get_child_by_name(state->f1.reg.crh, "MODE14");
	state->f1.fld.crh.cnf14 = cm_object_get_child_by_name(state->f1.reg.crh, "CNF14");
	state->f1.fld.crh.mode15 = cm_object_get_child_by_name(state->f1.reg.crh, "MODE15");
	state->f1.fld.crh.cnf15 = cm_object_get_child_by_name(state->f1.reg.crh, "CNF15");

	// IDR bitfields.
	state->f1.fld.idr.idr0 = cm_object_get_child_by_name(state->f1.reg.idr, "IDR0");
	state->f1.fld.idr.idr1 = cm_object_get_child_by_name(state->f1.reg.idr, "IDR1");
	state->f1.fld.idr.idr2 = cm_object_get_child_by_name(state->f1.reg.idr, "IDR2");
	state->f1.fld.idr.idr3 = cm_object_get_child_by_name(state->f1.reg.idr, "IDR3");
	state->f1.fld.idr.idr4 = cm_object_get_child_by_name(state->f1.reg.idr, "IDR4");
	state->f1.fld.idr.idr5 = cm_object_get_child_by_name(state->f1.reg.idr, "IDR5");
	state->f1.fld.idr.idr6 = cm_object_get_child_by_name(state->f1.reg.idr, "IDR6");
	state->f1.fld.idr.idr7 = cm_object_get_child_by_name(state->f1.reg.idr, "IDR7");
	state->f1.fld.idr.idr8 = cm_object_get_child_by_name(state->f1.reg.idr, "IDR8");
	state->f1.fld.idr.idr9 = cm_object_get_child_by_name(state->f1.reg.idr, "IDR9");
	state->f1.fld.idr.idr10 = cm_object_get_child_by_name(state->f1.reg.idr, "IDR10");
	state->f1.fld.idr.idr11 = cm_object_get_child_by_name(state->f1.reg.idr, "IDR11");
	state->f1.fld.idr.idr12 = cm_object_get_child_by_name(state->f1.reg.idr, "IDR12");
	state->f1.fld.idr.idr13 = cm_object_get_child_by_name(state->f1.reg.idr, "IDR13");
	state->f1.fld.idr.idr14 = cm_object_get_child_by_name(state->f1.reg.idr, "IDR14");
	state->f1.fld.idr.idr15 = cm_object_get_child_by_name(state->f1.reg.idr, "IDR15");

	// ODR bitfields.
	state->f1.fld.odr.odr0 = cm_object_get_child_by_name(state->f1.reg.odr, "ODR0");
	state->f1.fld.odr.odr1 = cm_object_get_child_by_name(state->f1.reg.odr, "ODR1");
	state->f1.fld.odr.odr2 = cm_object_get_child_by_name(state->f1.reg.odr, "ODR2");
	state->f1.fld.odr.odr3 = cm_object_get_child_by_name(state->f1.reg.odr, "ODR3");
	state->f1.fld.odr.odr4 = cm_object_get_child_by_name(state->f1.reg.odr, "ODR4");
	state->f1.fld.odr.odr5 = cm_object_get_child_by_name(state->f1.reg.odr, "ODR5");
	state->f1.fld.odr.odr6 = cm_object_get_child_by_name(state->f1.reg.odr, "ODR6");
	state->f1.fld.odr.odr7 = cm_object_get_child_by_name(state->f1.reg.odr, "ODR7");
	state->f1.fld.odr.odr8 = cm_object_get_child_by_name(state->f1.reg.odr, "ODR8");
	state->f1.fld.odr.odr9 = cm_object_get_child_by_name(state->f1.reg.odr, "ODR9");
	state->f1.fld.odr.odr10 = cm_object_get_child_by_name(state->f1.reg.odr, "ODR10");
	state->f1.fld.odr.odr11 = cm_object_get_child_by_name(state->f1.reg.odr, "ODR11");
	state->f1.fld.odr.odr12 = cm_object_get_child_by_name(state->f1.reg.odr, "ODR12");
	state->f1.fld.odr.odr13 = cm_object_get_child_by_name(state->f1.reg.odr, "ODR13");
	state->f1.fld.odr.odr14 = cm_object_get_child_by_name(state->f1.reg.odr, "ODR14");
	state->f1.fld.odr.odr15 = cm_object_get_child_by_name(state->f1.reg.odr, "ODR15");

	// BSRR bitfields.
	state->f1.fld.bsrr.bs0 = cm_object_get_child_by_name(state->f1.reg.bsrr, "BS0");
	state->f1.fld.bsrr.bs1 = cm_object_get_child_by_name(state->f1.reg.bsrr, "BS1");
	state->f1.fld.bsrr.bs2 = cm_object_get_child_by_name(state->f1.reg.bsrr, "BS2");
	state->f1.fld.bsrr.bs3 = cm_object_get_child_by_name(state->f1.reg.bsrr, "BS3");
	state->f1.fld.bsrr.bs4 = cm_object_get_child_by_name(state->f1.reg.bsrr, "BS4");
	state->f1.fld.bsrr.bs5 = cm_object_get_child_by_name(state->f1.reg.bsrr, "BS5");
	state->f1.fld.bsrr.bs6 = cm_object_get_child_by_name(state->f1.reg.bsrr, "BS6");
	state->f1.fld.bsrr.bs7 = cm_object_get_child_by_name(state->f1.reg.bsrr, "BS7");
	state->f1.fld.bsrr.bs8 = cm_object_get_child_by_name(state->f1.reg.bsrr, "BS8");
	state->f1.fld.bsrr.bs9 = cm_object_get_child_by_name(state->f1.reg.bsrr, "BS9");
	state->f1.fld.bsrr.bs10 = cm_object_get_child_by_name(state->f1.reg.bsrr, "BS10");
	state->f1.fld.bsrr.bs11 = cm_object_get_child_by_name(state->f1.reg.bsrr, "BS11");
	state->f1.fld.bsrr.bs12 = cm_object_get_child_by_name(state->f1.reg.bsrr, "BS12");
	state->f1.fld.bsrr.bs13 = cm_object_get_child_by_name(state->f1.reg.bsrr, "BS13");
	state->f1.fld.bsrr.bs14 = cm_object_get_child_by_name(state->f1.reg.bsrr, "BS14");
	state->f1.fld.bsrr.bs15 = cm_object_get_child_by_name(state->f1.reg.bsrr, "BS15");
	state->f1.fld.bsrr.br0 = cm_object_get_child_by_name(state->f1.reg.bsrr, "BR0");
	state->f1.fld.bsrr.br1 = cm_object_get_child_by_name(state->f1.reg.bsrr, "BR1");
	state->f1.fld.bsrr.br2 = cm_object_get_child_by_name(state->f1.reg.bsrr, "BR2");
	state->f1.fld.bsrr.br3 = cm_object_get_child_by_name(state->f1.reg.bsrr, "BR3");
	state->f1.fld.bsrr.br4 = cm_object_get_child_by_name(state->f1.reg.bsrr, "BR4");
	state->f1.fld.bsrr.br5 = cm_object_get_child_by_name(state->f1.reg.bsrr, "BR5");
	state->f1.fld.bsrr.br6 = cm_object_get_child_by_name(state->f1.reg.bsrr, "BR6");
	state->f1.fld.bsrr.br7 = cm_object_get_child_by_name(state->f1.reg.bsrr, "BR7");
	state->f1.fld.bsrr.br8 = cm_object_get_child_by_name(state->f1.reg.bsrr, "BR8");
	state->f1.fld.bsrr.br9 = cm_object_get_child_by_name(state->f1.reg.bsrr, "BR9");
	state->f1.fld.bsrr.br10 = cm_object_get_child_by_name(state->f1.reg.bsrr, "BR10");
	state->f1.fld.bsrr.br11 = cm_object_get_child_by_name(state->f1.reg.bsrr, "BR11");
	state->f1.fld.bsrr.br12 = cm_object_get_child_by_name(state->f1.reg.bsrr, "BR12");
	state->f1.fld.bsrr.br13 = cm_object_get_child_by_name(state->f1.reg.bsrr, "BR13");
	state->f1.fld.bsrr.br14 = cm_object_get_child_by_name(state->f1.reg.bsrr, "BR14");
	state->f1.fld.bsrr.br15 = cm_object_get_child_by_name(state->f1.reg.bsrr, "BR15");

	// BRR bitfields.
	state->f1.fld.brr.br0 = cm_object_get_child_by_name(state->f1.reg.brr, "BR0");
	state->f1.fld.brr.br1 = cm_object_get_child_by_name(state->f1.reg.brr, "BR1");
	state->f1.fld.brr.br2 = cm_object_get_child_by_name(state->f1.reg.brr, "BR2");
	state->f1.fld.brr.br3 = cm_object_get_child_by_name(state->f1.reg.brr, "BR3");
	state->f1.fld.brr.br4 = cm_object_get_child_by_name(state->f1.reg.brr, "BR4");
	state->f1.fld.brr.br5 = cm_object_get_child_by_name(state->f1.reg.brr, "BR5");
	state->f1.fld.brr.br6 = cm_object_get_child_by_name(state->f1.reg.brr, "BR6");
	state->f1.fld.brr.br7 = cm_object_get_child_by_name(state->f1.reg.brr, "BR7");
	state->f1.fld.brr.br8 = cm_object_get_child_by_name(state->f1.reg.brr, "BR8");
	state->f1.fld.brr.br9 = cm_object_get_child_by_name(state->f1.reg.brr, "BR9");
	state->f1.fld.brr.br10 = cm_object_get_child_by_name(state->f1.reg.brr, "BR10");
	state->f1.fld.brr.br11 = cm_object_get_child_by_name(state->f1.reg.brr, "BR11");
	state->f1.fld.brr.br12 = cm_object_get_child_by_name(state->f1.reg.brr, "BR12");
	state->f1.fld.brr.br13 = cm_object_get_child_by_name(state->f1.reg.brr, "BR13");
	state->f1.fld.brr.br14 = cm_object_get_child_by_name(state->f1.reg.brr, "BR14");
	state->f1.fld.brr.br15 = cm_object_get_child_by_name(state->f1.reg.brr, "BR15");

	// LCKR bitfields.
	state->f1.fld.lckr.lck0 = cm_object_get_child_by_name(state->f1.reg.lckr, "LCK0");
	state->f1.fld.lckr.lck1 = cm_object_get_child_by_name(state->f1.reg.lckr, "LCK1");
	state->f1.fld.lckr.lck2 = cm_object_get_child_by_name(state->f1.reg.lckr, "LCK2");
	state->f1.fld.lckr.lck3 = cm_object_get_child_by_name(state->f1.reg.lckr, "LCK3");
	state->f1.fld.lckr.lck4 = cm_object_get_child_by_name(state->f1.reg.lckr, "LCK4");
	state->f1.fld.lckr.lck5 = cm_object_get_child_by_name(state->f1.reg.lckr, "LCK5");
	state->f1.fld.lckr.lck6 = cm_object_get_child_by_name(state->f1.reg.lckr, "LCK6");
	state->f1.fld.lckr.lck7 = cm_object_get_child_by_name(state->f1.reg.lckr, "LCK7");
	state->f1.fld.lckr.lck8 = cm_object_get_child_by_name(state->f1.reg.lckr, "LCK8");
	state->f1.fld.lckr.lck9 = cm_object_get_child_by_name(state->f1.reg.lckr, "LCK9");
	state->f1.fld.lckr.lck10 = cm_object_get_child_by_name(state->f1.reg.lckr, "LCK10");
	state->f1.fld.lckr.lck11 = cm_object_get_child_by_name(state->f1.reg.lckr, "LCK11");
	state->f1.fld.lckr.lck12 = cm_object_get_child_by_name(state->f1.reg.lckr, "LCK12");
	state->f1.fld.lckr.lck13 = cm_object_get_child_by_name(state->f1.reg.lckr, "LCK13");
	state->f1.fld.lckr.lck14 = cm_object_get_child_by_name(state->f1.reg.lckr, "LCK14");
	state->f1.fld.lckr.lck15 = cm_object_get_child_by_name(state->f1.reg.lckr, "LCK15");
	state->f1.fld.lckr.lckk = cm_object_get_child_by_name(state->f1.reg.lckr, "LCKK");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// AFIO (Alternate function I/O) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F1 AFIO (Alternate function I/O) registers.
		struct {
			Object *evcr; // 0x0 Event Control Register (AFIO_EVCR)
			Object *mapr; // 0x4 AF remap and debug I/O configuration register (AFIO_MAPR)
			Object *exticr1; // 0x8 External interrupt configuration register 1 (AFIO_EXTICR1)
			Object *exticr2; // 0xC External interrupt configuration register 2 (AFIO_EXTICR2)
			Object *exticr3; // 0x10 External interrupt configuration register 3 (AFIO_EXTICR3)
			Object *exticr4; // 0x14 External interrupt configuration register 4 (AFIO_EXTICR4)
			Object *mapr2; // 0x1C AF remap and debug I/O configuration register
		} reg;

		struct {

			// EVCR (Event Control Register (AFIO_EVCR)) bitfields.
			struct {
				Object *pin; // [0:3] Pin selection
				Object *port; // [4:6] Port selection
				Object *evoe; // [7:7] Event Output Enable
			} evcr;

			// MAPR (AF remap and debug I/O configuration register (AFIO_MAPR)) bitfields.
			struct {
				Object *spi1_remap; // [0:0] SPI1 remapping
				Object *i2c1_remap; // [1:1] I2C1 remapping
				Object *usart1_remap; // [2:2] USART1 remapping
				Object *usart2_remap; // [3:3] USART2 remapping
				Object *usart3_remap; // [4:5] USART3 remapping
				Object *tim1_remap; // [6:7] TIM1 remapping
				Object *tim2_remap; // [8:9] TIM2 remapping
				Object *tim3_remap; // [10:11] TIM3 remapping
				Object *tim4_remap; // [12:12] TIM4 remapping
				Object *can_remap; // [13:14] CAN1 remapping
				Object *pd01_remap; // [15:15] Port D0/Port D1 mapping on OSCIN/OSCOUT
				Object *tim5ch4_iremap; // [16:16] Set and cleared by software
				Object *adc1_etrginj_remap; // [17:17] ADC 1 External trigger injected conversion remapping
				Object *adc1_etrgreg_remap; // [18:18] ADC 1 external trigger regular conversion remapping
				Object *adc2_etrginj_remap; // [19:19] ADC 2 external trigger injected conversion remapping
				Object *adc2_etrgreg_remap; // [20:20] ADC 2 external trigger regular conversion remapping
				Object *swj_cfg; // [24:26] Serial wire JTAG configuration
			} mapr;

			// EXTICR1 (External interrupt configuration register 1 (AFIO_EXTICR1)) bitfields.
			struct {
				Object *exti0; // [0:3] EXTI0 configuration
				Object *exti1; // [4:7] EXTI1 configuration
				Object *exti2; // [8:11] EXTI2 configuration
				Object *exti3; // [12:15] EXTI3 configuration
			} exticr1;

			// EXTICR2 (External interrupt configuration register 2 (AFIO_EXTICR2)) bitfields.
			struct {
				Object *exti4; // [0:3] EXTI4 configuration
				Object *exti5; // [4:7] EXTI5 configuration
				Object *exti6; // [8:11] EXTI6 configuration
				Object *exti7; // [12:15] EXTI7 configuration
			} exticr2;

			// EXTICR3 (External interrupt configuration register 3 (AFIO_EXTICR3)) bitfields.
			struct {
				Object *exti8; // [0:3] EXTI8 configuration
				Object *exti9; // [4:7] EXTI9 configuration
				Object *exti10; // [8:11] EXTI10 configuration
				Object *exti11; // [12:15] EXTI11 configuration
			} exticr3;

			// EXTICR4 (External interrupt configuration register 4 (AFIO_EXTICR4)) bitfields.
			struct {
				Object *exti12; // [0:3] EXTI12 configuration
				Object *exti13; // [4:7] EXTI13 configuration
				Object *exti14; // [8:11] EXTI14 configuration
				Object *exti15; // [12:15] EXTI15 configuration
			} exticr4;

			// MAPR2 (AF remap and debug I/O configuration register) bitfields.
			struct {
				Object *tim9_remap; // [5:5] TIM9 remapping
				Object *tim10_remap; // [6:6] TIM10 remapping
				Object *tim11_remap; // [7:7] TIM11 remapping
				Object *tim13_remap; // [8:8] TIM13 remapping
				Object *tim14_remap; // [9:9] TIM14 remapping
				Object *fsmc_nadv; // [10:10] NADV connect/disconnect
			} mapr2;
		} fld;
	} f1;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32AFIOState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_afio_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32AFIOState *state = STM32_AFIO_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f1.reg.evcr = cm_object_get_child_by_name(obj, "EVCR");
	state->f1.reg.mapr = cm_object_get_child_by_name(obj, "MAPR");
	state->f1.reg.exticr1 = cm_object_get_child_by_name(obj, "EXTICR1");
	state->f1.reg.exticr2 = cm_object_get_child_by_name(obj, "EXTICR2");
	state->f1.reg.exticr3 = cm_object_get_child_by_name(obj, "EXTICR3");
	state->f1.reg.exticr4 = cm_object_get_child_by_name(obj, "EXTICR4");
	state->f1.reg.mapr2 = cm_object_get_child_by_name(obj, "MAPR2");

	// EVCR bitfields.
	state->f1.fld.evcr.pin = cm_object_get_child_by_name(state->f1.reg.evcr, "PIN");
	state->f1.fld.evcr.port = cm_object_get_child_by_name(state->f1.reg.evcr, "PORT");
	state->f1.fld.evcr.evoe = cm_object_get_child_by_name(state->f1.reg.evcr, "EVOE");

	// MAPR bitfields.
	state->f1.fld.mapr.spi1_remap = cm_object_get_child_by_name(state->f1.reg.mapr, "SPI1_REMAP");
	state->f1.fld.mapr.i2c1_remap = cm_object_get_child_by_name(state->f1.reg.mapr, "I2C1_REMAP");
	state->f1.fld.mapr.usart1_remap = cm_object_get_child_by_name(state->f1.reg.mapr, "USART1_REMAP");
	state->f1.fld.mapr.usart2_remap = cm_object_get_child_by_name(state->f1.reg.mapr, "USART2_REMAP");
	state->f1.fld.mapr.usart3_remap = cm_object_get_child_by_name(state->f1.reg.mapr, "USART3_REMAP");
	state->f1.fld.mapr.tim1_remap = cm_object_get_child_by_name(state->f1.reg.mapr, "TIM1_REMAP");
	state->f1.fld.mapr.tim2_remap = cm_object_get_child_by_name(state->f1.reg.mapr, "TIM2_REMAP");
	state->f1.fld.mapr.tim3_remap = cm_object_get_child_by_name(state->f1.reg.mapr, "TIM3_REMAP");
	state->f1.fld.mapr.tim4_remap = cm_object_get_child_by_name(state->f1.reg.mapr, "TIM4_REMAP");
	state->f1.fld.mapr.can_remap = cm_object_get_child_by_name(state->f1.reg.mapr, "CAN_REMAP");
	state->f1.fld.mapr.pd01_remap = cm_object_get_child_by_name(state->f1.reg.mapr, "PD01_REMAP");
	state->f1.fld.mapr.tim5ch4_iremap = cm_object_get_child_by_name(state->f1.reg.mapr, "TIM5CH4_IREMAP");
	state->f1.fld.mapr.adc1_etrginj_remap = cm_object_get_child_by_name(state->f1.reg.mapr, "ADC1_ETRGINJ_REMAP");
	state->f1.fld.mapr.adc1_etrgreg_remap = cm_object_get_child_by_name(state->f1.reg.mapr, "ADC1_ETRGREG_REMAP");
	state->f1.fld.mapr.adc2_etrginj_remap = cm_object_get_child_by_name(state->f1.reg.mapr, "ADC2_ETRGINJ_REMAP");
	state->f1.fld.mapr.adc2_etrgreg_remap = cm_object_get_child_by_name(state->f1.reg.mapr, "ADC2_ETRGREG_REMAP");
	state->f1.fld.mapr.swj_cfg = cm_object_get_child_by_name(state->f1.reg.mapr, "SWJ_CFG");

	// EXTICR1 bitfields.
	state->f1.fld.exticr1.exti0 = cm_object_get_child_by_name(state->f1.reg.exticr1, "EXTI0");
	state->f1.fld.exticr1.exti1 = cm_object_get_child_by_name(state->f1.reg.exticr1, "EXTI1");
	state->f1.fld.exticr1.exti2 = cm_object_get_child_by_name(state->f1.reg.exticr1, "EXTI2");
	state->f1.fld.exticr1.exti3 = cm_object_get_child_by_name(state->f1.reg.exticr1, "EXTI3");

	// EXTICR2 bitfields.
	state->f1.fld.exticr2.exti4 = cm_object_get_child_by_name(state->f1.reg.exticr2, "EXTI4");
	state->f1.fld.exticr2.exti5 = cm_object_get_child_by_name(state->f1.reg.exticr2, "EXTI5");
	state->f1.fld.exticr2.exti6 = cm_object_get_child_by_name(state->f1.reg.exticr2, "EXTI6");
	state->f1.fld.exticr2.exti7 = cm_object_get_child_by_name(state->f1.reg.exticr2, "EXTI7");

	// EXTICR3 bitfields.
	state->f1.fld.exticr3.exti8 = cm_object_get_child_by_name(state->f1.reg.exticr3, "EXTI8");
	state->f1.fld.exticr3.exti9 = cm_object_get_child_by_name(state->f1.reg.exticr3, "EXTI9");
	state->f1.fld.exticr3.exti10 = cm_object_get_child_by_name(state->f1.reg.exticr3, "EXTI10");
	state->f1.fld.exticr3.exti11 = cm_object_get_child_by_name(state->f1.reg.exticr3, "EXTI11");

	// EXTICR4 bitfields.
	state->f1.fld.exticr4.exti12 = cm_object_get_child_by_name(state->f1.reg.exticr4, "EXTI12");
	state->f1.fld.exticr4.exti13 = cm_object_get_child_by_name(state->f1.reg.exticr4, "EXTI13");
	state->f1.fld.exticr4.exti14 = cm_object_get_child_by_name(state->f1.reg.exticr4, "EXTI14");
	state->f1.fld.exticr4.exti15 = cm_object_get_child_by_name(state->f1.reg.exticr4, "EXTI15");

	// MAPR2 bitfields.
	state->f1.fld.mapr2.tim9_remap = cm_object_get_child_by_name(state->f1.reg.mapr2, "TIM9_REMAP");
	state->f1.fld.mapr2.tim10_remap = cm_object_get_child_by_name(state->f1.reg.mapr2, "TIM10_REMAP");
	state->f1.fld.mapr2.tim11_remap = cm_object_get_child_by_name(state->f1.reg.mapr2, "TIM11_REMAP");
	state->f1.fld.mapr2.tim13_remap = cm_object_get_child_by_name(state->f1.reg.mapr2, "TIM13_REMAP");
	state->f1.fld.mapr2.tim14_remap = cm_object_get_child_by_name(state->f1.reg.mapr2, "TIM14_REMAP");
	state->f1.fld.mapr2.fsmc_nadv = cm_object_get_child_by_name(state->f1.reg.mapr2, "FSMC_NADV");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// EXTI (EXTI) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F1 EXTI (EXTI) registers.
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
				Object *tr18; // [18:18] Rising trigger event configuration of line 18
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
				Object *tr18; // [18:18] Falling trigger event configuration of line 18
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
				Object *swier18; // [18:18] Software Interrupt on line 18
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
				Object *pr18; // [18:18] Pending bit 18
			} pr;
		} fld;
	} f1;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32EXTIState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_exti_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32EXTIState *state = STM32_EXTI_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f1.reg.imr = cm_object_get_child_by_name(obj, "IMR");
	state->f1.reg.emr = cm_object_get_child_by_name(obj, "EMR");
	state->f1.reg.rtsr = cm_object_get_child_by_name(obj, "RTSR");
	state->f1.reg.ftsr = cm_object_get_child_by_name(obj, "FTSR");
	state->f1.reg.swier = cm_object_get_child_by_name(obj, "SWIER");
	state->f1.reg.pr = cm_object_get_child_by_name(obj, "PR");

	// IMR bitfields.
	state->f1.fld.imr.mr0 = cm_object_get_child_by_name(state->f1.reg.imr, "MR0");
	state->f1.fld.imr.mr1 = cm_object_get_child_by_name(state->f1.reg.imr, "MR1");
	state->f1.fld.imr.mr2 = cm_object_get_child_by_name(state->f1.reg.imr, "MR2");
	state->f1.fld.imr.mr3 = cm_object_get_child_by_name(state->f1.reg.imr, "MR3");
	state->f1.fld.imr.mr4 = cm_object_get_child_by_name(state->f1.reg.imr, "MR4");
	state->f1.fld.imr.mr5 = cm_object_get_child_by_name(state->f1.reg.imr, "MR5");
	state->f1.fld.imr.mr6 = cm_object_get_child_by_name(state->f1.reg.imr, "MR6");
	state->f1.fld.imr.mr7 = cm_object_get_child_by_name(state->f1.reg.imr, "MR7");
	state->f1.fld.imr.mr8 = cm_object_get_child_by_name(state->f1.reg.imr, "MR8");
	state->f1.fld.imr.mr9 = cm_object_get_child_by_name(state->f1.reg.imr, "MR9");
	state->f1.fld.imr.mr10 = cm_object_get_child_by_name(state->f1.reg.imr, "MR10");
	state->f1.fld.imr.mr11 = cm_object_get_child_by_name(state->f1.reg.imr, "MR11");
	state->f1.fld.imr.mr12 = cm_object_get_child_by_name(state->f1.reg.imr, "MR12");
	state->f1.fld.imr.mr13 = cm_object_get_child_by_name(state->f1.reg.imr, "MR13");
	state->f1.fld.imr.mr14 = cm_object_get_child_by_name(state->f1.reg.imr, "MR14");
	state->f1.fld.imr.mr15 = cm_object_get_child_by_name(state->f1.reg.imr, "MR15");
	state->f1.fld.imr.mr16 = cm_object_get_child_by_name(state->f1.reg.imr, "MR16");
	state->f1.fld.imr.mr17 = cm_object_get_child_by_name(state->f1.reg.imr, "MR17");
	state->f1.fld.imr.mr18 = cm_object_get_child_by_name(state->f1.reg.imr, "MR18");

	// EMR bitfields.
	state->f1.fld.emr.mr0 = cm_object_get_child_by_name(state->f1.reg.emr, "MR0");
	state->f1.fld.emr.mr1 = cm_object_get_child_by_name(state->f1.reg.emr, "MR1");
	state->f1.fld.emr.mr2 = cm_object_get_child_by_name(state->f1.reg.emr, "MR2");
	state->f1.fld.emr.mr3 = cm_object_get_child_by_name(state->f1.reg.emr, "MR3");
	state->f1.fld.emr.mr4 = cm_object_get_child_by_name(state->f1.reg.emr, "MR4");
	state->f1.fld.emr.mr5 = cm_object_get_child_by_name(state->f1.reg.emr, "MR5");
	state->f1.fld.emr.mr6 = cm_object_get_child_by_name(state->f1.reg.emr, "MR6");
	state->f1.fld.emr.mr7 = cm_object_get_child_by_name(state->f1.reg.emr, "MR7");
	state->f1.fld.emr.mr8 = cm_object_get_child_by_name(state->f1.reg.emr, "MR8");
	state->f1.fld.emr.mr9 = cm_object_get_child_by_name(state->f1.reg.emr, "MR9");
	state->f1.fld.emr.mr10 = cm_object_get_child_by_name(state->f1.reg.emr, "MR10");
	state->f1.fld.emr.mr11 = cm_object_get_child_by_name(state->f1.reg.emr, "MR11");
	state->f1.fld.emr.mr12 = cm_object_get_child_by_name(state->f1.reg.emr, "MR12");
	state->f1.fld.emr.mr13 = cm_object_get_child_by_name(state->f1.reg.emr, "MR13");
	state->f1.fld.emr.mr14 = cm_object_get_child_by_name(state->f1.reg.emr, "MR14");
	state->f1.fld.emr.mr15 = cm_object_get_child_by_name(state->f1.reg.emr, "MR15");
	state->f1.fld.emr.mr16 = cm_object_get_child_by_name(state->f1.reg.emr, "MR16");
	state->f1.fld.emr.mr17 = cm_object_get_child_by_name(state->f1.reg.emr, "MR17");
	state->f1.fld.emr.mr18 = cm_object_get_child_by_name(state->f1.reg.emr, "MR18");

	// RTSR bitfields.
	state->f1.fld.rtsr.tr0 = cm_object_get_child_by_name(state->f1.reg.rtsr, "TR0");
	state->f1.fld.rtsr.tr1 = cm_object_get_child_by_name(state->f1.reg.rtsr, "TR1");
	state->f1.fld.rtsr.tr2 = cm_object_get_child_by_name(state->f1.reg.rtsr, "TR2");
	state->f1.fld.rtsr.tr3 = cm_object_get_child_by_name(state->f1.reg.rtsr, "TR3");
	state->f1.fld.rtsr.tr4 = cm_object_get_child_by_name(state->f1.reg.rtsr, "TR4");
	state->f1.fld.rtsr.tr5 = cm_object_get_child_by_name(state->f1.reg.rtsr, "TR5");
	state->f1.fld.rtsr.tr6 = cm_object_get_child_by_name(state->f1.reg.rtsr, "TR6");
	state->f1.fld.rtsr.tr7 = cm_object_get_child_by_name(state->f1.reg.rtsr, "TR7");
	state->f1.fld.rtsr.tr8 = cm_object_get_child_by_name(state->f1.reg.rtsr, "TR8");
	state->f1.fld.rtsr.tr9 = cm_object_get_child_by_name(state->f1.reg.rtsr, "TR9");
	state->f1.fld.rtsr.tr10 = cm_object_get_child_by_name(state->f1.reg.rtsr, "TR10");
	state->f1.fld.rtsr.tr11 = cm_object_get_child_by_name(state->f1.reg.rtsr, "TR11");
	state->f1.fld.rtsr.tr12 = cm_object_get_child_by_name(state->f1.reg.rtsr, "TR12");
	state->f1.fld.rtsr.tr13 = cm_object_get_child_by_name(state->f1.reg.rtsr, "TR13");
	state->f1.fld.rtsr.tr14 = cm_object_get_child_by_name(state->f1.reg.rtsr, "TR14");
	state->f1.fld.rtsr.tr15 = cm_object_get_child_by_name(state->f1.reg.rtsr, "TR15");
	state->f1.fld.rtsr.tr16 = cm_object_get_child_by_name(state->f1.reg.rtsr, "TR16");
	state->f1.fld.rtsr.tr17 = cm_object_get_child_by_name(state->f1.reg.rtsr, "TR17");
	state->f1.fld.rtsr.tr18 = cm_object_get_child_by_name(state->f1.reg.rtsr, "TR18");

	// FTSR bitfields.
	state->f1.fld.ftsr.tr0 = cm_object_get_child_by_name(state->f1.reg.ftsr, "TR0");
	state->f1.fld.ftsr.tr1 = cm_object_get_child_by_name(state->f1.reg.ftsr, "TR1");
	state->f1.fld.ftsr.tr2 = cm_object_get_child_by_name(state->f1.reg.ftsr, "TR2");
	state->f1.fld.ftsr.tr3 = cm_object_get_child_by_name(state->f1.reg.ftsr, "TR3");
	state->f1.fld.ftsr.tr4 = cm_object_get_child_by_name(state->f1.reg.ftsr, "TR4");
	state->f1.fld.ftsr.tr5 = cm_object_get_child_by_name(state->f1.reg.ftsr, "TR5");
	state->f1.fld.ftsr.tr6 = cm_object_get_child_by_name(state->f1.reg.ftsr, "TR6");
	state->f1.fld.ftsr.tr7 = cm_object_get_child_by_name(state->f1.reg.ftsr, "TR7");
	state->f1.fld.ftsr.tr8 = cm_object_get_child_by_name(state->f1.reg.ftsr, "TR8");
	state->f1.fld.ftsr.tr9 = cm_object_get_child_by_name(state->f1.reg.ftsr, "TR9");
	state->f1.fld.ftsr.tr10 = cm_object_get_child_by_name(state->f1.reg.ftsr, "TR10");
	state->f1.fld.ftsr.tr11 = cm_object_get_child_by_name(state->f1.reg.ftsr, "TR11");
	state->f1.fld.ftsr.tr12 = cm_object_get_child_by_name(state->f1.reg.ftsr, "TR12");
	state->f1.fld.ftsr.tr13 = cm_object_get_child_by_name(state->f1.reg.ftsr, "TR13");
	state->f1.fld.ftsr.tr14 = cm_object_get_child_by_name(state->f1.reg.ftsr, "TR14");
	state->f1.fld.ftsr.tr15 = cm_object_get_child_by_name(state->f1.reg.ftsr, "TR15");
	state->f1.fld.ftsr.tr16 = cm_object_get_child_by_name(state->f1.reg.ftsr, "TR16");
	state->f1.fld.ftsr.tr17 = cm_object_get_child_by_name(state->f1.reg.ftsr, "TR17");
	state->f1.fld.ftsr.tr18 = cm_object_get_child_by_name(state->f1.reg.ftsr, "TR18");

	// SWIER bitfields.
	state->f1.fld.swier.swier0 = cm_object_get_child_by_name(state->f1.reg.swier, "SWIER0");
	state->f1.fld.swier.swier1 = cm_object_get_child_by_name(state->f1.reg.swier, "SWIER1");
	state->f1.fld.swier.swier2 = cm_object_get_child_by_name(state->f1.reg.swier, "SWIER2");
	state->f1.fld.swier.swier3 = cm_object_get_child_by_name(state->f1.reg.swier, "SWIER3");
	state->f1.fld.swier.swier4 = cm_object_get_child_by_name(state->f1.reg.swier, "SWIER4");
	state->f1.fld.swier.swier5 = cm_object_get_child_by_name(state->f1.reg.swier, "SWIER5");
	state->f1.fld.swier.swier6 = cm_object_get_child_by_name(state->f1.reg.swier, "SWIER6");
	state->f1.fld.swier.swier7 = cm_object_get_child_by_name(state->f1.reg.swier, "SWIER7");
	state->f1.fld.swier.swier8 = cm_object_get_child_by_name(state->f1.reg.swier, "SWIER8");
	state->f1.fld.swier.swier9 = cm_object_get_child_by_name(state->f1.reg.swier, "SWIER9");
	state->f1.fld.swier.swier10 = cm_object_get_child_by_name(state->f1.reg.swier, "SWIER10");
	state->f1.fld.swier.swier11 = cm_object_get_child_by_name(state->f1.reg.swier, "SWIER11");
	state->f1.fld.swier.swier12 = cm_object_get_child_by_name(state->f1.reg.swier, "SWIER12");
	state->f1.fld.swier.swier13 = cm_object_get_child_by_name(state->f1.reg.swier, "SWIER13");
	state->f1.fld.swier.swier14 = cm_object_get_child_by_name(state->f1.reg.swier, "SWIER14");
	state->f1.fld.swier.swier15 = cm_object_get_child_by_name(state->f1.reg.swier, "SWIER15");
	state->f1.fld.swier.swier16 = cm_object_get_child_by_name(state->f1.reg.swier, "SWIER16");
	state->f1.fld.swier.swier17 = cm_object_get_child_by_name(state->f1.reg.swier, "SWIER17");
	state->f1.fld.swier.swier18 = cm_object_get_child_by_name(state->f1.reg.swier, "SWIER18");

	// PR bitfields.
	state->f1.fld.pr.pr0 = cm_object_get_child_by_name(state->f1.reg.pr, "PR0");
	state->f1.fld.pr.pr1 = cm_object_get_child_by_name(state->f1.reg.pr, "PR1");
	state->f1.fld.pr.pr2 = cm_object_get_child_by_name(state->f1.reg.pr, "PR2");
	state->f1.fld.pr.pr3 = cm_object_get_child_by_name(state->f1.reg.pr, "PR3");
	state->f1.fld.pr.pr4 = cm_object_get_child_by_name(state->f1.reg.pr, "PR4");
	state->f1.fld.pr.pr5 = cm_object_get_child_by_name(state->f1.reg.pr, "PR5");
	state->f1.fld.pr.pr6 = cm_object_get_child_by_name(state->f1.reg.pr, "PR6");
	state->f1.fld.pr.pr7 = cm_object_get_child_by_name(state->f1.reg.pr, "PR7");
	state->f1.fld.pr.pr8 = cm_object_get_child_by_name(state->f1.reg.pr, "PR8");
	state->f1.fld.pr.pr9 = cm_object_get_child_by_name(state->f1.reg.pr, "PR9");
	state->f1.fld.pr.pr10 = cm_object_get_child_by_name(state->f1.reg.pr, "PR10");
	state->f1.fld.pr.pr11 = cm_object_get_child_by_name(state->f1.reg.pr, "PR11");
	state->f1.fld.pr.pr12 = cm_object_get_child_by_name(state->f1.reg.pr, "PR12");
	state->f1.fld.pr.pr13 = cm_object_get_child_by_name(state->f1.reg.pr, "PR13");
	state->f1.fld.pr.pr14 = cm_object_get_child_by_name(state->f1.reg.pr, "PR14");
	state->f1.fld.pr.pr15 = cm_object_get_child_by_name(state->f1.reg.pr, "PR15");
	state->f1.fld.pr.pr16 = cm_object_get_child_by_name(state->f1.reg.pr, "PR16");
	state->f1.fld.pr.pr17 = cm_object_get_child_by_name(state->f1.reg.pr, "PR17");
	state->f1.fld.pr.pr18 = cm_object_get_child_by_name(state->f1.reg.pr, "PR18");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DMA1 (DMA controller) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F1 DMA1 (DMA controller) registers.
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
	} f1;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32DMA1State;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_dma1_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32DMA1State *state = STM32_DMA1_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f1.reg.isr = cm_object_get_child_by_name(obj, "ISR");
	state->f1.reg.ifcr = cm_object_get_child_by_name(obj, "IFCR");
	state->f1.reg.ccr1 = cm_object_get_child_by_name(obj, "CCR1");
	state->f1.reg.cndtr1 = cm_object_get_child_by_name(obj, "CNDTR1");
	state->f1.reg.cpar1 = cm_object_get_child_by_name(obj, "CPAR1");
	state->f1.reg.cmar1 = cm_object_get_child_by_name(obj, "CMAR1");
	state->f1.reg.ccr2 = cm_object_get_child_by_name(obj, "CCR2");
	state->f1.reg.cndtr2 = cm_object_get_child_by_name(obj, "CNDTR2");
	state->f1.reg.cpar2 = cm_object_get_child_by_name(obj, "CPAR2");
	state->f1.reg.cmar2 = cm_object_get_child_by_name(obj, "CMAR2");
	state->f1.reg.ccr3 = cm_object_get_child_by_name(obj, "CCR3");
	state->f1.reg.cndtr3 = cm_object_get_child_by_name(obj, "CNDTR3");
	state->f1.reg.cpar3 = cm_object_get_child_by_name(obj, "CPAR3");
	state->f1.reg.cmar3 = cm_object_get_child_by_name(obj, "CMAR3");
	state->f1.reg.ccr4 = cm_object_get_child_by_name(obj, "CCR4");
	state->f1.reg.cndtr4 = cm_object_get_child_by_name(obj, "CNDTR4");
	state->f1.reg.cpar4 = cm_object_get_child_by_name(obj, "CPAR4");
	state->f1.reg.cmar4 = cm_object_get_child_by_name(obj, "CMAR4");
	state->f1.reg.ccr5 = cm_object_get_child_by_name(obj, "CCR5");
	state->f1.reg.cndtr5 = cm_object_get_child_by_name(obj, "CNDTR5");
	state->f1.reg.cpar5 = cm_object_get_child_by_name(obj, "CPAR5");
	state->f1.reg.cmar5 = cm_object_get_child_by_name(obj, "CMAR5");
	state->f1.reg.ccr6 = cm_object_get_child_by_name(obj, "CCR6");
	state->f1.reg.cndtr6 = cm_object_get_child_by_name(obj, "CNDTR6");
	state->f1.reg.cpar6 = cm_object_get_child_by_name(obj, "CPAR6");
	state->f1.reg.cmar6 = cm_object_get_child_by_name(obj, "CMAR6");
	state->f1.reg.ccr7 = cm_object_get_child_by_name(obj, "CCR7");
	state->f1.reg.cndtr7 = cm_object_get_child_by_name(obj, "CNDTR7");
	state->f1.reg.cpar7 = cm_object_get_child_by_name(obj, "CPAR7");
	state->f1.reg.cmar7 = cm_object_get_child_by_name(obj, "CMAR7");

	// ISR bitfields.
	state->f1.fld.isr.gif1 = cm_object_get_child_by_name(state->f1.reg.isr, "GIF1");
	state->f1.fld.isr.tcif1 = cm_object_get_child_by_name(state->f1.reg.isr, "TCIF1");
	state->f1.fld.isr.htif1 = cm_object_get_child_by_name(state->f1.reg.isr, "HTIF1");
	state->f1.fld.isr.teif1 = cm_object_get_child_by_name(state->f1.reg.isr, "TEIF1");
	state->f1.fld.isr.gif2 = cm_object_get_child_by_name(state->f1.reg.isr, "GIF2");
	state->f1.fld.isr.tcif2 = cm_object_get_child_by_name(state->f1.reg.isr, "TCIF2");
	state->f1.fld.isr.htif2 = cm_object_get_child_by_name(state->f1.reg.isr, "HTIF2");
	state->f1.fld.isr.teif2 = cm_object_get_child_by_name(state->f1.reg.isr, "TEIF2");
	state->f1.fld.isr.gif3 = cm_object_get_child_by_name(state->f1.reg.isr, "GIF3");
	state->f1.fld.isr.tcif3 = cm_object_get_child_by_name(state->f1.reg.isr, "TCIF3");
	state->f1.fld.isr.htif3 = cm_object_get_child_by_name(state->f1.reg.isr, "HTIF3");
	state->f1.fld.isr.teif3 = cm_object_get_child_by_name(state->f1.reg.isr, "TEIF3");
	state->f1.fld.isr.gif4 = cm_object_get_child_by_name(state->f1.reg.isr, "GIF4");
	state->f1.fld.isr.tcif4 = cm_object_get_child_by_name(state->f1.reg.isr, "TCIF4");
	state->f1.fld.isr.htif4 = cm_object_get_child_by_name(state->f1.reg.isr, "HTIF4");
	state->f1.fld.isr.teif4 = cm_object_get_child_by_name(state->f1.reg.isr, "TEIF4");
	state->f1.fld.isr.gif5 = cm_object_get_child_by_name(state->f1.reg.isr, "GIF5");
	state->f1.fld.isr.tcif5 = cm_object_get_child_by_name(state->f1.reg.isr, "TCIF5");
	state->f1.fld.isr.htif5 = cm_object_get_child_by_name(state->f1.reg.isr, "HTIF5");
	state->f1.fld.isr.teif5 = cm_object_get_child_by_name(state->f1.reg.isr, "TEIF5");
	state->f1.fld.isr.gif6 = cm_object_get_child_by_name(state->f1.reg.isr, "GIF6");
	state->f1.fld.isr.tcif6 = cm_object_get_child_by_name(state->f1.reg.isr, "TCIF6");
	state->f1.fld.isr.htif6 = cm_object_get_child_by_name(state->f1.reg.isr, "HTIF6");
	state->f1.fld.isr.teif6 = cm_object_get_child_by_name(state->f1.reg.isr, "TEIF6");
	state->f1.fld.isr.gif7 = cm_object_get_child_by_name(state->f1.reg.isr, "GIF7");
	state->f1.fld.isr.tcif7 = cm_object_get_child_by_name(state->f1.reg.isr, "TCIF7");
	state->f1.fld.isr.htif7 = cm_object_get_child_by_name(state->f1.reg.isr, "HTIF7");
	state->f1.fld.isr.teif7 = cm_object_get_child_by_name(state->f1.reg.isr, "TEIF7");

	// IFCR bitfields.
	state->f1.fld.ifcr.cgif1 = cm_object_get_child_by_name(state->f1.reg.ifcr, "CGIF1");
	state->f1.fld.ifcr.ctcif1 = cm_object_get_child_by_name(state->f1.reg.ifcr, "CTCIF1");
	state->f1.fld.ifcr.chtif1 = cm_object_get_child_by_name(state->f1.reg.ifcr, "CHTIF1");
	state->f1.fld.ifcr.cteif1 = cm_object_get_child_by_name(state->f1.reg.ifcr, "CTEIF1");
	state->f1.fld.ifcr.cgif2 = cm_object_get_child_by_name(state->f1.reg.ifcr, "CGIF2");
	state->f1.fld.ifcr.ctcif2 = cm_object_get_child_by_name(state->f1.reg.ifcr, "CTCIF2");
	state->f1.fld.ifcr.chtif2 = cm_object_get_child_by_name(state->f1.reg.ifcr, "CHTIF2");
	state->f1.fld.ifcr.cteif2 = cm_object_get_child_by_name(state->f1.reg.ifcr, "CTEIF2");
	state->f1.fld.ifcr.cgif3 = cm_object_get_child_by_name(state->f1.reg.ifcr, "CGIF3");
	state->f1.fld.ifcr.ctcif3 = cm_object_get_child_by_name(state->f1.reg.ifcr, "CTCIF3");
	state->f1.fld.ifcr.chtif3 = cm_object_get_child_by_name(state->f1.reg.ifcr, "CHTIF3");
	state->f1.fld.ifcr.cteif3 = cm_object_get_child_by_name(state->f1.reg.ifcr, "CTEIF3");
	state->f1.fld.ifcr.cgif4 = cm_object_get_child_by_name(state->f1.reg.ifcr, "CGIF4");
	state->f1.fld.ifcr.ctcif4 = cm_object_get_child_by_name(state->f1.reg.ifcr, "CTCIF4");
	state->f1.fld.ifcr.chtif4 = cm_object_get_child_by_name(state->f1.reg.ifcr, "CHTIF4");
	state->f1.fld.ifcr.cteif4 = cm_object_get_child_by_name(state->f1.reg.ifcr, "CTEIF4");
	state->f1.fld.ifcr.cgif5 = cm_object_get_child_by_name(state->f1.reg.ifcr, "CGIF5");
	state->f1.fld.ifcr.ctcif5 = cm_object_get_child_by_name(state->f1.reg.ifcr, "CTCIF5");
	state->f1.fld.ifcr.chtif5 = cm_object_get_child_by_name(state->f1.reg.ifcr, "CHTIF5");
	state->f1.fld.ifcr.cteif5 = cm_object_get_child_by_name(state->f1.reg.ifcr, "CTEIF5");
	state->f1.fld.ifcr.cgif6 = cm_object_get_child_by_name(state->f1.reg.ifcr, "CGIF6");
	state->f1.fld.ifcr.ctcif6 = cm_object_get_child_by_name(state->f1.reg.ifcr, "CTCIF6");
	state->f1.fld.ifcr.chtif6 = cm_object_get_child_by_name(state->f1.reg.ifcr, "CHTIF6");
	state->f1.fld.ifcr.cteif6 = cm_object_get_child_by_name(state->f1.reg.ifcr, "CTEIF6");
	state->f1.fld.ifcr.cgif7 = cm_object_get_child_by_name(state->f1.reg.ifcr, "CGIF7");
	state->f1.fld.ifcr.ctcif7 = cm_object_get_child_by_name(state->f1.reg.ifcr, "CTCIF7");
	state->f1.fld.ifcr.chtif7 = cm_object_get_child_by_name(state->f1.reg.ifcr, "CHTIF7");
	state->f1.fld.ifcr.cteif7 = cm_object_get_child_by_name(state->f1.reg.ifcr, "CTEIF7");

	// CCR1 bitfields.
	state->f1.fld.ccr1.en = cm_object_get_child_by_name(state->f1.reg.ccr1, "EN");
	state->f1.fld.ccr1.tcie = cm_object_get_child_by_name(state->f1.reg.ccr1, "TCIE");
	state->f1.fld.ccr1.htie = cm_object_get_child_by_name(state->f1.reg.ccr1, "HTIE");
	state->f1.fld.ccr1.teie = cm_object_get_child_by_name(state->f1.reg.ccr1, "TEIE");
	state->f1.fld.ccr1.dir = cm_object_get_child_by_name(state->f1.reg.ccr1, "DIR");
	state->f1.fld.ccr1.circ = cm_object_get_child_by_name(state->f1.reg.ccr1, "CIRC");
	state->f1.fld.ccr1.pinc = cm_object_get_child_by_name(state->f1.reg.ccr1, "PINC");
	state->f1.fld.ccr1.minc = cm_object_get_child_by_name(state->f1.reg.ccr1, "MINC");
	state->f1.fld.ccr1.psize = cm_object_get_child_by_name(state->f1.reg.ccr1, "PSIZE");
	state->f1.fld.ccr1.msize = cm_object_get_child_by_name(state->f1.reg.ccr1, "MSIZE");
	state->f1.fld.ccr1.pl = cm_object_get_child_by_name(state->f1.reg.ccr1, "PL");
	state->f1.fld.ccr1.mem2mem = cm_object_get_child_by_name(state->f1.reg.ccr1, "MEM2MEM");

	// CNDTR1 bitfields.
	state->f1.fld.cndtr1.ndt = cm_object_get_child_by_name(state->f1.reg.cndtr1, "NDT");

	// CPAR1 bitfields.
	state->f1.fld.cpar1.pa = cm_object_get_child_by_name(state->f1.reg.cpar1, "PA");

	// CMAR1 bitfields.
	state->f1.fld.cmar1.ma = cm_object_get_child_by_name(state->f1.reg.cmar1, "MA");

	// CCR2 bitfields.
	state->f1.fld.ccr2.en = cm_object_get_child_by_name(state->f1.reg.ccr2, "EN");
	state->f1.fld.ccr2.tcie = cm_object_get_child_by_name(state->f1.reg.ccr2, "TCIE");
	state->f1.fld.ccr2.htie = cm_object_get_child_by_name(state->f1.reg.ccr2, "HTIE");
	state->f1.fld.ccr2.teie = cm_object_get_child_by_name(state->f1.reg.ccr2, "TEIE");
	state->f1.fld.ccr2.dir = cm_object_get_child_by_name(state->f1.reg.ccr2, "DIR");
	state->f1.fld.ccr2.circ = cm_object_get_child_by_name(state->f1.reg.ccr2, "CIRC");
	state->f1.fld.ccr2.pinc = cm_object_get_child_by_name(state->f1.reg.ccr2, "PINC");
	state->f1.fld.ccr2.minc = cm_object_get_child_by_name(state->f1.reg.ccr2, "MINC");
	state->f1.fld.ccr2.psize = cm_object_get_child_by_name(state->f1.reg.ccr2, "PSIZE");
	state->f1.fld.ccr2.msize = cm_object_get_child_by_name(state->f1.reg.ccr2, "MSIZE");
	state->f1.fld.ccr2.pl = cm_object_get_child_by_name(state->f1.reg.ccr2, "PL");
	state->f1.fld.ccr2.mem2mem = cm_object_get_child_by_name(state->f1.reg.ccr2, "MEM2MEM");

	// CNDTR2 bitfields.
	state->f1.fld.cndtr2.ndt = cm_object_get_child_by_name(state->f1.reg.cndtr2, "NDT");

	// CPAR2 bitfields.
	state->f1.fld.cpar2.pa = cm_object_get_child_by_name(state->f1.reg.cpar2, "PA");

	// CMAR2 bitfields.
	state->f1.fld.cmar2.ma = cm_object_get_child_by_name(state->f1.reg.cmar2, "MA");

	// CCR3 bitfields.
	state->f1.fld.ccr3.en = cm_object_get_child_by_name(state->f1.reg.ccr3, "EN");
	state->f1.fld.ccr3.tcie = cm_object_get_child_by_name(state->f1.reg.ccr3, "TCIE");
	state->f1.fld.ccr3.htie = cm_object_get_child_by_name(state->f1.reg.ccr3, "HTIE");
	state->f1.fld.ccr3.teie = cm_object_get_child_by_name(state->f1.reg.ccr3, "TEIE");
	state->f1.fld.ccr3.dir = cm_object_get_child_by_name(state->f1.reg.ccr3, "DIR");
	state->f1.fld.ccr3.circ = cm_object_get_child_by_name(state->f1.reg.ccr3, "CIRC");
	state->f1.fld.ccr3.pinc = cm_object_get_child_by_name(state->f1.reg.ccr3, "PINC");
	state->f1.fld.ccr3.minc = cm_object_get_child_by_name(state->f1.reg.ccr3, "MINC");
	state->f1.fld.ccr3.psize = cm_object_get_child_by_name(state->f1.reg.ccr3, "PSIZE");
	state->f1.fld.ccr3.msize = cm_object_get_child_by_name(state->f1.reg.ccr3, "MSIZE");
	state->f1.fld.ccr3.pl = cm_object_get_child_by_name(state->f1.reg.ccr3, "PL");
	state->f1.fld.ccr3.mem2mem = cm_object_get_child_by_name(state->f1.reg.ccr3, "MEM2MEM");

	// CNDTR3 bitfields.
	state->f1.fld.cndtr3.ndt = cm_object_get_child_by_name(state->f1.reg.cndtr3, "NDT");

	// CPAR3 bitfields.
	state->f1.fld.cpar3.pa = cm_object_get_child_by_name(state->f1.reg.cpar3, "PA");

	// CMAR3 bitfields.
	state->f1.fld.cmar3.ma = cm_object_get_child_by_name(state->f1.reg.cmar3, "MA");

	// CCR4 bitfields.
	state->f1.fld.ccr4.en = cm_object_get_child_by_name(state->f1.reg.ccr4, "EN");
	state->f1.fld.ccr4.tcie = cm_object_get_child_by_name(state->f1.reg.ccr4, "TCIE");
	state->f1.fld.ccr4.htie = cm_object_get_child_by_name(state->f1.reg.ccr4, "HTIE");
	state->f1.fld.ccr4.teie = cm_object_get_child_by_name(state->f1.reg.ccr4, "TEIE");
	state->f1.fld.ccr4.dir = cm_object_get_child_by_name(state->f1.reg.ccr4, "DIR");
	state->f1.fld.ccr4.circ = cm_object_get_child_by_name(state->f1.reg.ccr4, "CIRC");
	state->f1.fld.ccr4.pinc = cm_object_get_child_by_name(state->f1.reg.ccr4, "PINC");
	state->f1.fld.ccr4.minc = cm_object_get_child_by_name(state->f1.reg.ccr4, "MINC");
	state->f1.fld.ccr4.psize = cm_object_get_child_by_name(state->f1.reg.ccr4, "PSIZE");
	state->f1.fld.ccr4.msize = cm_object_get_child_by_name(state->f1.reg.ccr4, "MSIZE");
	state->f1.fld.ccr4.pl = cm_object_get_child_by_name(state->f1.reg.ccr4, "PL");
	state->f1.fld.ccr4.mem2mem = cm_object_get_child_by_name(state->f1.reg.ccr4, "MEM2MEM");

	// CNDTR4 bitfields.
	state->f1.fld.cndtr4.ndt = cm_object_get_child_by_name(state->f1.reg.cndtr4, "NDT");

	// CPAR4 bitfields.
	state->f1.fld.cpar4.pa = cm_object_get_child_by_name(state->f1.reg.cpar4, "PA");

	// CMAR4 bitfields.
	state->f1.fld.cmar4.ma = cm_object_get_child_by_name(state->f1.reg.cmar4, "MA");

	// CCR5 bitfields.
	state->f1.fld.ccr5.en = cm_object_get_child_by_name(state->f1.reg.ccr5, "EN");
	state->f1.fld.ccr5.tcie = cm_object_get_child_by_name(state->f1.reg.ccr5, "TCIE");
	state->f1.fld.ccr5.htie = cm_object_get_child_by_name(state->f1.reg.ccr5, "HTIE");
	state->f1.fld.ccr5.teie = cm_object_get_child_by_name(state->f1.reg.ccr5, "TEIE");
	state->f1.fld.ccr5.dir = cm_object_get_child_by_name(state->f1.reg.ccr5, "DIR");
	state->f1.fld.ccr5.circ = cm_object_get_child_by_name(state->f1.reg.ccr5, "CIRC");
	state->f1.fld.ccr5.pinc = cm_object_get_child_by_name(state->f1.reg.ccr5, "PINC");
	state->f1.fld.ccr5.minc = cm_object_get_child_by_name(state->f1.reg.ccr5, "MINC");
	state->f1.fld.ccr5.psize = cm_object_get_child_by_name(state->f1.reg.ccr5, "PSIZE");
	state->f1.fld.ccr5.msize = cm_object_get_child_by_name(state->f1.reg.ccr5, "MSIZE");
	state->f1.fld.ccr5.pl = cm_object_get_child_by_name(state->f1.reg.ccr5, "PL");
	state->f1.fld.ccr5.mem2mem = cm_object_get_child_by_name(state->f1.reg.ccr5, "MEM2MEM");

	// CNDTR5 bitfields.
	state->f1.fld.cndtr5.ndt = cm_object_get_child_by_name(state->f1.reg.cndtr5, "NDT");

	// CPAR5 bitfields.
	state->f1.fld.cpar5.pa = cm_object_get_child_by_name(state->f1.reg.cpar5, "PA");

	// CMAR5 bitfields.
	state->f1.fld.cmar5.ma = cm_object_get_child_by_name(state->f1.reg.cmar5, "MA");

	// CCR6 bitfields.
	state->f1.fld.ccr6.en = cm_object_get_child_by_name(state->f1.reg.ccr6, "EN");
	state->f1.fld.ccr6.tcie = cm_object_get_child_by_name(state->f1.reg.ccr6, "TCIE");
	state->f1.fld.ccr6.htie = cm_object_get_child_by_name(state->f1.reg.ccr6, "HTIE");
	state->f1.fld.ccr6.teie = cm_object_get_child_by_name(state->f1.reg.ccr6, "TEIE");
	state->f1.fld.ccr6.dir = cm_object_get_child_by_name(state->f1.reg.ccr6, "DIR");
	state->f1.fld.ccr6.circ = cm_object_get_child_by_name(state->f1.reg.ccr6, "CIRC");
	state->f1.fld.ccr6.pinc = cm_object_get_child_by_name(state->f1.reg.ccr6, "PINC");
	state->f1.fld.ccr6.minc = cm_object_get_child_by_name(state->f1.reg.ccr6, "MINC");
	state->f1.fld.ccr6.psize = cm_object_get_child_by_name(state->f1.reg.ccr6, "PSIZE");
	state->f1.fld.ccr6.msize = cm_object_get_child_by_name(state->f1.reg.ccr6, "MSIZE");
	state->f1.fld.ccr6.pl = cm_object_get_child_by_name(state->f1.reg.ccr6, "PL");
	state->f1.fld.ccr6.mem2mem = cm_object_get_child_by_name(state->f1.reg.ccr6, "MEM2MEM");

	// CNDTR6 bitfields.
	state->f1.fld.cndtr6.ndt = cm_object_get_child_by_name(state->f1.reg.cndtr6, "NDT");

	// CPAR6 bitfields.
	state->f1.fld.cpar6.pa = cm_object_get_child_by_name(state->f1.reg.cpar6, "PA");

	// CMAR6 bitfields.
	state->f1.fld.cmar6.ma = cm_object_get_child_by_name(state->f1.reg.cmar6, "MA");

	// CCR7 bitfields.
	state->f1.fld.ccr7.en = cm_object_get_child_by_name(state->f1.reg.ccr7, "EN");
	state->f1.fld.ccr7.tcie = cm_object_get_child_by_name(state->f1.reg.ccr7, "TCIE");
	state->f1.fld.ccr7.htie = cm_object_get_child_by_name(state->f1.reg.ccr7, "HTIE");
	state->f1.fld.ccr7.teie = cm_object_get_child_by_name(state->f1.reg.ccr7, "TEIE");
	state->f1.fld.ccr7.dir = cm_object_get_child_by_name(state->f1.reg.ccr7, "DIR");
	state->f1.fld.ccr7.circ = cm_object_get_child_by_name(state->f1.reg.ccr7, "CIRC");
	state->f1.fld.ccr7.pinc = cm_object_get_child_by_name(state->f1.reg.ccr7, "PINC");
	state->f1.fld.ccr7.minc = cm_object_get_child_by_name(state->f1.reg.ccr7, "MINC");
	state->f1.fld.ccr7.psize = cm_object_get_child_by_name(state->f1.reg.ccr7, "PSIZE");
	state->f1.fld.ccr7.msize = cm_object_get_child_by_name(state->f1.reg.ccr7, "MSIZE");
	state->f1.fld.ccr7.pl = cm_object_get_child_by_name(state->f1.reg.ccr7, "PL");
	state->f1.fld.ccr7.mem2mem = cm_object_get_child_by_name(state->f1.reg.ccr7, "MEM2MEM");

	// CNDTR7 bitfields.
	state->f1.fld.cndtr7.ndt = cm_object_get_child_by_name(state->f1.reg.cndtr7, "NDT");

	// CPAR7 bitfields.
	state->f1.fld.cpar7.pa = cm_object_get_child_by_name(state->f1.reg.cpar7, "PA");

	// CMAR7 bitfields.
	state->f1.fld.cmar7.ma = cm_object_get_child_by_name(state->f1.reg.cmar7, "MA");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// SDIO (Secure digital input/output interface) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F1 SDIO (Secure digital input/output interface) registers.
		struct {
			Object *power; // 0x0 Bits 1:0 = PWRCTRL: Power supply control bits
			Object *clkcr; // 0x4 SDI clock control register (SDIO_CLKCR)
			Object *arg; // 0x8 Bits 31:0 = : Command argument
			Object *cmd; // 0xC SDIO command register (SDIO_CMD)
			Object *respcmd; // 0x10 SDIO command register
			Object *respi1; // 0x14 Bits 31:0 = CARDSTATUS1
			Object *resp2; // 0x18 Bits 31:0 = CARDSTATUS2
			Object *resp3; // 0x1C Bits 31:0 = CARDSTATUS3
			Object *resp4; // 0x20 Bits 31:0 = CARDSTATUS4
			Object *dtimer; // 0x24 Bits 31:0 = DATATIME: Data timeout period
			Object *dlen; // 0x28 Bits 24:0 = DATALENGTH: Data length value
			Object *dctrl; // 0x2C SDIO data control register (SDIO_DCTRL)
			Object *dcount; // 0x30 Bits 24:0 = DATACOUNT: Data count value
			Object *sta; // 0x34 SDIO status register (SDIO_STA)
			Object *icr; // 0x38 SDIO interrupt clear register (SDIO_ICR)
			Object *mask; // 0x3C SDIO mask register (SDIO_MASK)
			Object *fifocnt; // 0x48 Bits 23:0 = FIFOCOUNT: Remaining number of words to be written to or read from the FIFO
			Object *fifo; // 0x80 Bits 31:0 = FIFOData: Receive and transmit FIFO data
		} reg;

		struct {

			// POWER (Bits 1:0 = PWRCTRL: Power supply control bits) bitfields.
			struct {
				Object *pwrctrl; // [0:1] PWRCTRL
			} power;

			// CLKCR (SDI clock control register (SDIO_CLKCR)) bitfields.
			struct {
				Object *clkdiv; // [0:7] Clock divide factor
				Object *clken; // [8:8] Clock enable bit
				Object *pwrsav; // [9:9] Power saving configuration bit
				Object *bypass; // [10:10] Clock divider bypass enable bit
				Object *widbus; // [11:12] Wide bus mode enable bit
				Object *negedge; // [13:13] SDIO_CK dephasing selection bit
				Object *hwfc_en; // [14:14] HW Flow Control enable
			} clkcr;

			// ARG (Bits 31:0 = : Command argument) bitfields.
			struct {
				Object *cmdarg; // [0:31] Command argument
			} arg;

			// CMD (SDIO command register (SDIO_CMD)) bitfields.
			struct {
				Object *cmdindex; // [0:5] CMDINDEX
				Object *waitresp; // [6:7] WAITRESP
				Object *waitint; // [8:8] WAITINT
				Object *waitpend; // [9:9] WAITPEND
				Object *cpsmen; // [10:10] CPSMEN
				Object *sdiosuspend; // [11:11] SDIOSuspend
				Object *encmdcompl; // [12:12] ENCMDcompl
				Object *nien; // [13:13] NIEN
				Object *ce_atacmd; // [14:14] CE_ATACMD
			} cmd;

			// RESPCMD (SDIO command register) bitfields.
			struct {
				Object *respcmd; // [0:5] RESPCMD
			} respcmd;

			// RESPI1 (Bits 31:0 = CARDSTATUS1) bitfields.
			struct {
				Object *cardstatus1; // [0:31] CARDSTATUS1
			} respi1;

			// RESP2 (Bits 31:0 = CARDSTATUS2) bitfields.
			struct {
				Object *cardstatus2; // [0:31] CARDSTATUS2
			} resp2;

			// RESP3 (Bits 31:0 = CARDSTATUS3) bitfields.
			struct {
				Object *cardstatus3; // [0:31] CARDSTATUS3
			} resp3;

			// RESP4 (Bits 31:0 = CARDSTATUS4) bitfields.
			struct {
				Object *cardstatus4; // [0:31] CARDSTATUS4
			} resp4;

			// DTIMER (Bits 31:0 = DATATIME: Data timeout period) bitfields.
			struct {
				Object *datatime; // [0:31] Data timeout period
			} dtimer;

			// DLEN (Bits 24:0 = DATALENGTH: Data length value) bitfields.
			struct {
				Object *datalength; // [0:24] Data length value
			} dlen;

			// DCTRL (SDIO data control register (SDIO_DCTRL)) bitfields.
			struct {
				Object *dten; // [0:0] DTEN
				Object *dtdir; // [1:1] DTDIR
				Object *dtmode; // [2:2] DTMODE
				Object *dmaen; // [3:3] DMAEN
				Object *dblocksize; // [4:7] DBLOCKSIZE
				Object *pwstart; // [8:8] PWSTART
				Object *pwstop; // [9:9] PWSTOP
				Object *rwmod; // [10:10] RWMOD
				Object *sdioen; // [11:11] SDIOEN
			} dctrl;

			// DCOUNT (Bits 24:0 = DATACOUNT: Data count value) bitfields.
			struct {
				Object *datacount; // [0:24] Data count value
			} dcount;

			// STA (SDIO status register (SDIO_STA)) bitfields.
			struct {
				Object *ccrcfail; // [0:0] CCRCFAIL
				Object *dcrcfail; // [1:1] DCRCFAIL
				Object *ctimeout; // [2:2] CTIMEOUT
				Object *dtimeout; // [3:3] DTIMEOUT
				Object *txunderr; // [4:4] TXUNDERR
				Object *rxoverr; // [5:5] RXOVERR
				Object *cmdrend; // [6:6] CMDREND
				Object *cmdsent; // [7:7] CMDSENT
				Object *dataend; // [8:8] DATAEND
				Object *stbiterr; // [9:9] STBITERR
				Object *dbckend; // [10:10] DBCKEND
				Object *cmdact; // [11:11] CMDACT
				Object *txact; // [12:12] TXACT
				Object *rxact; // [13:13] RXACT
				Object *txfifohe; // [14:14] TXFIFOHE
				Object *rxfifohf; // [15:15] RXFIFOHF
				Object *txfifof; // [16:16] TXFIFOF
				Object *rxfifof; // [17:17] RXFIFOF
				Object *txfifoe; // [18:18] TXFIFOE
				Object *rxfifoe; // [19:19] RXFIFOE
				Object *txdavl; // [20:20] TXDAVL
				Object *rxdavl; // [21:21] RXDAVL
				Object *sdioit; // [22:22] SDIOIT
				Object *ceataend; // [23:23] CEATAEND
			} sta;

			// ICR (SDIO interrupt clear register (SDIO_ICR)) bitfields.
			struct {
				Object *ccrcfailc; // [0:0] CCRCFAILC
				Object *dcrcfailc; // [1:1] DCRCFAILC
				Object *ctimeoutc; // [2:2] CTIMEOUTC
				Object *dtimeoutc; // [3:3] DTIMEOUTC
				Object *txunderrc; // [4:4] TXUNDERRC
				Object *rxoverrc; // [5:5] RXOVERRC
				Object *cmdrendc; // [6:6] CMDRENDC
				Object *cmdsentc; // [7:7] CMDSENTC
				Object *dataendc; // [8:8] DATAENDC
				Object *stbiterrc; // [9:9] STBITERRC
				Object *dbckendc; // [10:10] DBCKENDC
				Object *sdioitc; // [22:22] SDIOITC
				Object *ceataendc; // [23:23] CEATAENDC
			} icr;

			// MASK (SDIO mask register (SDIO_MASK)) bitfields.
			struct {
				Object *ccrcfailie; // [0:0] CCRCFAILIE
				Object *dcrcfailie; // [1:1] DCRCFAILIE
				Object *ctimeoutie; // [2:2] CTIMEOUTIE
				Object *dtimeoutie; // [3:3] DTIMEOUTIE
				Object *txunderrie; // [4:4] TXUNDERRIE
				Object *rxoverrie; // [5:5] RXOVERRIE
				Object *cmdrendie; // [6:6] CMDRENDIE
				Object *cmdsentie; // [7:7] CMDSENTIE
				Object *dataendie; // [8:8] DATAENDIE
				Object *stbiterrie; // [9:9] STBITERRIE
				Object *dbackendie; // [10:10] DBACKENDIE
				Object *cmdactie; // [11:11] CMDACTIE
				Object *txactie; // [12:12] TXACTIE
				Object *rxactie; // [13:13] RXACTIE
				Object *txfifoheie; // [14:14] TXFIFOHEIE
				Object *rxfifohfie; // [15:15] RXFIFOHFIE
				Object *txfifofie; // [16:16] TXFIFOFIE
				Object *rxfifofie; // [17:17] RXFIFOFIE
				Object *txfifoeie; // [18:18] TXFIFOEIE
				Object *rxfifoeie; // [19:19] RXFIFOEIE
				Object *txdavlie; // [20:20] TXDAVLIE
				Object *rxdavlie; // [21:21] RXDAVLIE
				Object *sdioitie; // [22:22] SDIOITIE
				Object *ceatendie; // [23:23] CEATENDIE
			} mask;

			// FIFOCNT (Bits 23:0 = FIFOCOUNT: Remaining number of words to be written to or read from the FIFO) bitfields.
			struct {
				Object *fif0count; // [0:23] FIF0COUNT
			} fifocnt;

			// FIFO (Bits 31:0 = FIFOData: Receive and transmit FIFO data) bitfields.
			struct {
				Object *fifodata; // [0:31] FIFOData
			} fifo;
		} fld;
	} f1;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32SDIOState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_sdio_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32SDIOState *state = STM32_SDIO_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f1.reg.power = cm_object_get_child_by_name(obj, "POWER");
	state->f1.reg.clkcr = cm_object_get_child_by_name(obj, "CLKCR");
	state->f1.reg.arg = cm_object_get_child_by_name(obj, "ARG");
	state->f1.reg.cmd = cm_object_get_child_by_name(obj, "CMD");
	state->f1.reg.respcmd = cm_object_get_child_by_name(obj, "RESPCMD");
	state->f1.reg.respi1 = cm_object_get_child_by_name(obj, "RESPI1");
	state->f1.reg.resp2 = cm_object_get_child_by_name(obj, "RESP2");
	state->f1.reg.resp3 = cm_object_get_child_by_name(obj, "RESP3");
	state->f1.reg.resp4 = cm_object_get_child_by_name(obj, "RESP4");
	state->f1.reg.dtimer = cm_object_get_child_by_name(obj, "DTIMER");
	state->f1.reg.dlen = cm_object_get_child_by_name(obj, "DLEN");
	state->f1.reg.dctrl = cm_object_get_child_by_name(obj, "DCTRL");
	state->f1.reg.dcount = cm_object_get_child_by_name(obj, "DCOUNT");
	state->f1.reg.sta = cm_object_get_child_by_name(obj, "STA");
	state->f1.reg.icr = cm_object_get_child_by_name(obj, "ICR");
	state->f1.reg.mask = cm_object_get_child_by_name(obj, "MASK");
	state->f1.reg.fifocnt = cm_object_get_child_by_name(obj, "FIFOCNT");
	state->f1.reg.fifo = cm_object_get_child_by_name(obj, "FIFO");

	// POWER bitfields.
	state->f1.fld.power.pwrctrl = cm_object_get_child_by_name(state->f1.reg.power, "PWRCTRL");

	// CLKCR bitfields.
	state->f1.fld.clkcr.clkdiv = cm_object_get_child_by_name(state->f1.reg.clkcr, "CLKDIV");
	state->f1.fld.clkcr.clken = cm_object_get_child_by_name(state->f1.reg.clkcr, "CLKEN");
	state->f1.fld.clkcr.pwrsav = cm_object_get_child_by_name(state->f1.reg.clkcr, "PWRSAV");
	state->f1.fld.clkcr.bypass = cm_object_get_child_by_name(state->f1.reg.clkcr, "BYPASS");
	state->f1.fld.clkcr.widbus = cm_object_get_child_by_name(state->f1.reg.clkcr, "WIDBUS");
	state->f1.fld.clkcr.negedge = cm_object_get_child_by_name(state->f1.reg.clkcr, "NEGEDGE");
	state->f1.fld.clkcr.hwfc_en = cm_object_get_child_by_name(state->f1.reg.clkcr, "HWFC_EN");

	// ARG bitfields.
	state->f1.fld.arg.cmdarg = cm_object_get_child_by_name(state->f1.reg.arg, "CMDARG");

	// CMD bitfields.
	state->f1.fld.cmd.cmdindex = cm_object_get_child_by_name(state->f1.reg.cmd, "CMDINDEX");
	state->f1.fld.cmd.waitresp = cm_object_get_child_by_name(state->f1.reg.cmd, "WAITRESP");
	state->f1.fld.cmd.waitint = cm_object_get_child_by_name(state->f1.reg.cmd, "WAITINT");
	state->f1.fld.cmd.waitpend = cm_object_get_child_by_name(state->f1.reg.cmd, "WAITPEND");
	state->f1.fld.cmd.cpsmen = cm_object_get_child_by_name(state->f1.reg.cmd, "CPSMEN");
	state->f1.fld.cmd.sdiosuspend = cm_object_get_child_by_name(state->f1.reg.cmd, "SDIOSuspend");
	state->f1.fld.cmd.encmdcompl = cm_object_get_child_by_name(state->f1.reg.cmd, "ENCMDcompl");
	state->f1.fld.cmd.nien = cm_object_get_child_by_name(state->f1.reg.cmd, "nIEN");
	state->f1.fld.cmd.ce_atacmd = cm_object_get_child_by_name(state->f1.reg.cmd, "CE_ATACMD");

	// RESPCMD bitfields.
	state->f1.fld.respcmd.respcmd = cm_object_get_child_by_name(state->f1.reg.respcmd, "RESPCMD");

	// RESPI1 bitfields.
	state->f1.fld.respi1.cardstatus1 = cm_object_get_child_by_name(state->f1.reg.respi1, "CARDSTATUS1");

	// RESP2 bitfields.
	state->f1.fld.resp2.cardstatus2 = cm_object_get_child_by_name(state->f1.reg.resp2, "CARDSTATUS2");

	// RESP3 bitfields.
	state->f1.fld.resp3.cardstatus3 = cm_object_get_child_by_name(state->f1.reg.resp3, "CARDSTATUS3");

	// RESP4 bitfields.
	state->f1.fld.resp4.cardstatus4 = cm_object_get_child_by_name(state->f1.reg.resp4, "CARDSTATUS4");

	// DTIMER bitfields.
	state->f1.fld.dtimer.datatime = cm_object_get_child_by_name(state->f1.reg.dtimer, "DATATIME");

	// DLEN bitfields.
	state->f1.fld.dlen.datalength = cm_object_get_child_by_name(state->f1.reg.dlen, "DATALENGTH");

	// DCTRL bitfields.
	state->f1.fld.dctrl.dten = cm_object_get_child_by_name(state->f1.reg.dctrl, "DTEN");
	state->f1.fld.dctrl.dtdir = cm_object_get_child_by_name(state->f1.reg.dctrl, "DTDIR");
	state->f1.fld.dctrl.dtmode = cm_object_get_child_by_name(state->f1.reg.dctrl, "DTMODE");
	state->f1.fld.dctrl.dmaen = cm_object_get_child_by_name(state->f1.reg.dctrl, "DMAEN");
	state->f1.fld.dctrl.dblocksize = cm_object_get_child_by_name(state->f1.reg.dctrl, "DBLOCKSIZE");
	state->f1.fld.dctrl.pwstart = cm_object_get_child_by_name(state->f1.reg.dctrl, "PWSTART");
	state->f1.fld.dctrl.pwstop = cm_object_get_child_by_name(state->f1.reg.dctrl, "PWSTOP");
	state->f1.fld.dctrl.rwmod = cm_object_get_child_by_name(state->f1.reg.dctrl, "RWMOD");
	state->f1.fld.dctrl.sdioen = cm_object_get_child_by_name(state->f1.reg.dctrl, "SDIOEN");

	// DCOUNT bitfields.
	state->f1.fld.dcount.datacount = cm_object_get_child_by_name(state->f1.reg.dcount, "DATACOUNT");

	// STA bitfields.
	state->f1.fld.sta.ccrcfail = cm_object_get_child_by_name(state->f1.reg.sta, "CCRCFAIL");
	state->f1.fld.sta.dcrcfail = cm_object_get_child_by_name(state->f1.reg.sta, "DCRCFAIL");
	state->f1.fld.sta.ctimeout = cm_object_get_child_by_name(state->f1.reg.sta, "CTIMEOUT");
	state->f1.fld.sta.dtimeout = cm_object_get_child_by_name(state->f1.reg.sta, "DTIMEOUT");
	state->f1.fld.sta.txunderr = cm_object_get_child_by_name(state->f1.reg.sta, "TXUNDERR");
	state->f1.fld.sta.rxoverr = cm_object_get_child_by_name(state->f1.reg.sta, "RXOVERR");
	state->f1.fld.sta.cmdrend = cm_object_get_child_by_name(state->f1.reg.sta, "CMDREND");
	state->f1.fld.sta.cmdsent = cm_object_get_child_by_name(state->f1.reg.sta, "CMDSENT");
	state->f1.fld.sta.dataend = cm_object_get_child_by_name(state->f1.reg.sta, "DATAEND");
	state->f1.fld.sta.stbiterr = cm_object_get_child_by_name(state->f1.reg.sta, "STBITERR");
	state->f1.fld.sta.dbckend = cm_object_get_child_by_name(state->f1.reg.sta, "DBCKEND");
	state->f1.fld.sta.cmdact = cm_object_get_child_by_name(state->f1.reg.sta, "CMDACT");
	state->f1.fld.sta.txact = cm_object_get_child_by_name(state->f1.reg.sta, "TXACT");
	state->f1.fld.sta.rxact = cm_object_get_child_by_name(state->f1.reg.sta, "RXACT");
	state->f1.fld.sta.txfifohe = cm_object_get_child_by_name(state->f1.reg.sta, "TXFIFOHE");
	state->f1.fld.sta.rxfifohf = cm_object_get_child_by_name(state->f1.reg.sta, "RXFIFOHF");
	state->f1.fld.sta.txfifof = cm_object_get_child_by_name(state->f1.reg.sta, "TXFIFOF");
	state->f1.fld.sta.rxfifof = cm_object_get_child_by_name(state->f1.reg.sta, "RXFIFOF");
	state->f1.fld.sta.txfifoe = cm_object_get_child_by_name(state->f1.reg.sta, "TXFIFOE");
	state->f1.fld.sta.rxfifoe = cm_object_get_child_by_name(state->f1.reg.sta, "RXFIFOE");
	state->f1.fld.sta.txdavl = cm_object_get_child_by_name(state->f1.reg.sta, "TXDAVL");
	state->f1.fld.sta.rxdavl = cm_object_get_child_by_name(state->f1.reg.sta, "RXDAVL");
	state->f1.fld.sta.sdioit = cm_object_get_child_by_name(state->f1.reg.sta, "SDIOIT");
	state->f1.fld.sta.ceataend = cm_object_get_child_by_name(state->f1.reg.sta, "CEATAEND");

	// ICR bitfields.
	state->f1.fld.icr.ccrcfailc = cm_object_get_child_by_name(state->f1.reg.icr, "CCRCFAILC");
	state->f1.fld.icr.dcrcfailc = cm_object_get_child_by_name(state->f1.reg.icr, "DCRCFAILC");
	state->f1.fld.icr.ctimeoutc = cm_object_get_child_by_name(state->f1.reg.icr, "CTIMEOUTC");
	state->f1.fld.icr.dtimeoutc = cm_object_get_child_by_name(state->f1.reg.icr, "DTIMEOUTC");
	state->f1.fld.icr.txunderrc = cm_object_get_child_by_name(state->f1.reg.icr, "TXUNDERRC");
	state->f1.fld.icr.rxoverrc = cm_object_get_child_by_name(state->f1.reg.icr, "RXOVERRC");
	state->f1.fld.icr.cmdrendc = cm_object_get_child_by_name(state->f1.reg.icr, "CMDRENDC");
	state->f1.fld.icr.cmdsentc = cm_object_get_child_by_name(state->f1.reg.icr, "CMDSENTC");
	state->f1.fld.icr.dataendc = cm_object_get_child_by_name(state->f1.reg.icr, "DATAENDC");
	state->f1.fld.icr.stbiterrc = cm_object_get_child_by_name(state->f1.reg.icr, "STBITERRC");
	state->f1.fld.icr.dbckendc = cm_object_get_child_by_name(state->f1.reg.icr, "DBCKENDC");
	state->f1.fld.icr.sdioitc = cm_object_get_child_by_name(state->f1.reg.icr, "SDIOITC");
	state->f1.fld.icr.ceataendc = cm_object_get_child_by_name(state->f1.reg.icr, "CEATAENDC");

	// MASK bitfields.
	state->f1.fld.mask.ccrcfailie = cm_object_get_child_by_name(state->f1.reg.mask, "CCRCFAILIE");
	state->f1.fld.mask.dcrcfailie = cm_object_get_child_by_name(state->f1.reg.mask, "DCRCFAILIE");
	state->f1.fld.mask.ctimeoutie = cm_object_get_child_by_name(state->f1.reg.mask, "CTIMEOUTIE");
	state->f1.fld.mask.dtimeoutie = cm_object_get_child_by_name(state->f1.reg.mask, "DTIMEOUTIE");
	state->f1.fld.mask.txunderrie = cm_object_get_child_by_name(state->f1.reg.mask, "TXUNDERRIE");
	state->f1.fld.mask.rxoverrie = cm_object_get_child_by_name(state->f1.reg.mask, "RXOVERRIE");
	state->f1.fld.mask.cmdrendie = cm_object_get_child_by_name(state->f1.reg.mask, "CMDRENDIE");
	state->f1.fld.mask.cmdsentie = cm_object_get_child_by_name(state->f1.reg.mask, "CMDSENTIE");
	state->f1.fld.mask.dataendie = cm_object_get_child_by_name(state->f1.reg.mask, "DATAENDIE");
	state->f1.fld.mask.stbiterrie = cm_object_get_child_by_name(state->f1.reg.mask, "STBITERRIE");
	state->f1.fld.mask.dbackendie = cm_object_get_child_by_name(state->f1.reg.mask, "DBACKENDIE");
	state->f1.fld.mask.cmdactie = cm_object_get_child_by_name(state->f1.reg.mask, "CMDACTIE");
	state->f1.fld.mask.txactie = cm_object_get_child_by_name(state->f1.reg.mask, "TXACTIE");
	state->f1.fld.mask.rxactie = cm_object_get_child_by_name(state->f1.reg.mask, "RXACTIE");
	state->f1.fld.mask.txfifoheie = cm_object_get_child_by_name(state->f1.reg.mask, "TXFIFOHEIE");
	state->f1.fld.mask.rxfifohfie = cm_object_get_child_by_name(state->f1.reg.mask, "RXFIFOHFIE");
	state->f1.fld.mask.txfifofie = cm_object_get_child_by_name(state->f1.reg.mask, "TXFIFOFIE");
	state->f1.fld.mask.rxfifofie = cm_object_get_child_by_name(state->f1.reg.mask, "RXFIFOFIE");
	state->f1.fld.mask.txfifoeie = cm_object_get_child_by_name(state->f1.reg.mask, "TXFIFOEIE");
	state->f1.fld.mask.rxfifoeie = cm_object_get_child_by_name(state->f1.reg.mask, "RXFIFOEIE");
	state->f1.fld.mask.txdavlie = cm_object_get_child_by_name(state->f1.reg.mask, "TXDAVLIE");
	state->f1.fld.mask.rxdavlie = cm_object_get_child_by_name(state->f1.reg.mask, "RXDAVLIE");
	state->f1.fld.mask.sdioitie = cm_object_get_child_by_name(state->f1.reg.mask, "SDIOITIE");
	state->f1.fld.mask.ceatendie = cm_object_get_child_by_name(state->f1.reg.mask, "CEATENDIE");

	// FIFOCNT bitfields.
	state->f1.fld.fifocnt.fif0count = cm_object_get_child_by_name(state->f1.reg.fifocnt, "FIF0COUNT");

	// FIFO bitfields.
	state->f1.fld.fifo.fifodata = cm_object_get_child_by_name(state->f1.reg.fifo, "FIFOData");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// RTC (Real time clock) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F1 RTC (Real time clock) registers.
		struct {
			Object *crh; // 0x0 RTC Control Register High
			Object *crl; // 0x4 RTC Control Register Low
			Object *prlh; // 0x8 RTC Prescaler Load Register High
			Object *prll; // 0xC RTC Prescaler Load Register Low
			Object *divh; // 0x10 RTC Prescaler Divider Register High
			Object *divl; // 0x14 RTC Prescaler Divider Register Low
			Object *cnth; // 0x18 RTC Counter Register High
			Object *cntl; // 0x1C RTC Counter Register Low
			Object *alrh; // 0x20 RTC Alarm Register High
			Object *alrl; // 0x24 RTC Alarm Register Low
		} reg;

		struct {

			// CRH (RTC Control Register High) bitfields.
			struct {
				Object *secie; // [0:0] Second interrupt Enable
				Object *alrie; // [1:1] Alarm interrupt Enable
				Object *owie; // [2:2] Overflow interrupt Enable
			} crh;

			// CRL (RTC Control Register Low) bitfields.
			struct {
				Object *secf; // [0:0] Second Flag
				Object *alrf; // [1:1] Alarm Flag
				Object *owf; // [2:2] Overflow Flag
				Object *rsf; // [3:3] Registers Synchronized Flag
				Object *cnf; // [4:4] Configuration Flag
				Object *rtoff; // [5:5] RTC operation OFF
			} crl;

			// PRLH (RTC Prescaler Load Register High) bitfields.
			struct {
				Object *prlh; // [0:3] RTC Prescaler Load Register High
			} prlh;

			// PRLL (RTC Prescaler Load Register Low) bitfields.
			struct {
				Object *prll; // [0:15] RTC Prescaler Divider Register Low
			} prll;

			// DIVH (RTC Prescaler Divider Register High) bitfields.
			struct {
				Object *divh; // [0:3] RTC prescaler divider register high
			} divh;

			// DIVL (RTC Prescaler Divider Register Low) bitfields.
			struct {
				Object *divl; // [0:15] RTC prescaler divider register Low
			} divl;

			// CNTH (RTC Counter Register High) bitfields.
			struct {
				Object *cnth; // [0:15] RTC counter register high
			} cnth;

			// CNTL (RTC Counter Register Low) bitfields.
			struct {
				Object *cntl; // [0:15] RTC counter register Low
			} cntl;

			// ALRH (RTC Alarm Register High) bitfields.
			struct {
				Object *alrh; // [0:15] RTC alarm register high
			} alrh;

			// ALRL (RTC Alarm Register Low) bitfields.
			struct {
				Object *alrl; // [0:15] RTC alarm register low
			} alrl;
		} fld;
	} f1;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32RTCState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_rtc_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32RTCState *state = STM32_RTC_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f1.reg.crh = cm_object_get_child_by_name(obj, "CRH");
	state->f1.reg.crl = cm_object_get_child_by_name(obj, "CRL");
	state->f1.reg.prlh = cm_object_get_child_by_name(obj, "PRLH");
	state->f1.reg.prll = cm_object_get_child_by_name(obj, "PRLL");
	state->f1.reg.divh = cm_object_get_child_by_name(obj, "DIVH");
	state->f1.reg.divl = cm_object_get_child_by_name(obj, "DIVL");
	state->f1.reg.cnth = cm_object_get_child_by_name(obj, "CNTH");
	state->f1.reg.cntl = cm_object_get_child_by_name(obj, "CNTL");
	state->f1.reg.alrh = cm_object_get_child_by_name(obj, "ALRH");
	state->f1.reg.alrl = cm_object_get_child_by_name(obj, "ALRL");

	// CRH bitfields.
	state->f1.fld.crh.secie = cm_object_get_child_by_name(state->f1.reg.crh, "SECIE");
	state->f1.fld.crh.alrie = cm_object_get_child_by_name(state->f1.reg.crh, "ALRIE");
	state->f1.fld.crh.owie = cm_object_get_child_by_name(state->f1.reg.crh, "OWIE");

	// CRL bitfields.
	state->f1.fld.crl.secf = cm_object_get_child_by_name(state->f1.reg.crl, "SECF");
	state->f1.fld.crl.alrf = cm_object_get_child_by_name(state->f1.reg.crl, "ALRF");
	state->f1.fld.crl.owf = cm_object_get_child_by_name(state->f1.reg.crl, "OWF");
	state->f1.fld.crl.rsf = cm_object_get_child_by_name(state->f1.reg.crl, "RSF");
	state->f1.fld.crl.cnf = cm_object_get_child_by_name(state->f1.reg.crl, "CNF");
	state->f1.fld.crl.rtoff = cm_object_get_child_by_name(state->f1.reg.crl, "RTOFF");

	// PRLH bitfields.
	state->f1.fld.prlh.prlh = cm_object_get_child_by_name(state->f1.reg.prlh, "PRLH");

	// PRLL bitfields.
	state->f1.fld.prll.prll = cm_object_get_child_by_name(state->f1.reg.prll, "PRLL");

	// DIVH bitfields.
	state->f1.fld.divh.divh = cm_object_get_child_by_name(state->f1.reg.divh, "DIVH");

	// DIVL bitfields.
	state->f1.fld.divl.divl = cm_object_get_child_by_name(state->f1.reg.divl, "DIVL");

	// CNTH bitfields.
	state->f1.fld.cnth.cnth = cm_object_get_child_by_name(state->f1.reg.cnth, "CNTH");

	// CNTL bitfields.
	state->f1.fld.cntl.cntl = cm_object_get_child_by_name(state->f1.reg.cntl, "CNTL");

	// ALRH bitfields.
	state->f1.fld.alrh.alrh = cm_object_get_child_by_name(state->f1.reg.alrh, "ALRH");

	// ALRL bitfields.
	state->f1.fld.alrl.alrl = cm_object_get_child_by_name(state->f1.reg.alrl, "ALRL");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// BKP (Backup registers) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F1 BKP (Backup registers) registers.
		struct {
			Object *dr1; // 0x0 Backup data register (BKP_DR)
			Object *dr2; // 0x4 Backup data register (BKP_DR)
			Object *dr3; // 0x8 Backup data register (BKP_DR)
			Object *dr4; // 0xC Backup data register (BKP_DR)
			Object *dr5; // 0x10 Backup data register (BKP_DR)
			Object *dr6; // 0x14 Backup data register (BKP_DR)
			Object *dr7; // 0x18 Backup data register (BKP_DR)
			Object *dr8; // 0x1C Backup data register (BKP_DR)
			Object *dr9; // 0x20 Backup data register (BKP_DR)
			Object *dr10; // 0x24 Backup data register (BKP_DR)
			Object *dr11; // 0x3C Backup data register (BKP_DR)
			Object *dr12; // 0x40 Backup data register (BKP_DR)
			Object *dr13; // 0x44 Backup data register (BKP_DR)
			Object *dr14; // 0x48 Backup data register (BKP_DR)
			Object *dr15; // 0x4C Backup data register (BKP_DR)
			Object *dr16; // 0x50 Backup data register (BKP_DR)
			Object *dr17; // 0x54 Backup data register (BKP_DR)
			Object *dr18; // 0x58 Backup data register (BKP_DR)
			Object *dr19; // 0x5C Backup data register (BKP_DR)
			Object *dr20; // 0x60 Backup data register (BKP_DR)
			Object *dr21; // 0x64 Backup data register (BKP_DR)
			Object *dr22; // 0x68 Backup data register (BKP_DR)
			Object *dr23; // 0x6C Backup data register (BKP_DR)
			Object *dr24; // 0x70 Backup data register (BKP_DR)
			Object *dr25; // 0x74 Backup data register (BKP_DR)
			Object *dr26; // 0x78 Backup data register (BKP_DR)
			Object *dr27; // 0x7C Backup data register (BKP_DR)
			Object *dr28; // 0x80 Backup data register (BKP_DR)
			Object *dr29; // 0x84 Backup data register (BKP_DR)
			Object *dr30; // 0x88 Backup data register (BKP_DR)
			Object *dr31; // 0x8C Backup data register (BKP_DR)
			Object *dr32; // 0x90 Backup data register (BKP_DR)
			Object *dr33; // 0x94 Backup data register (BKP_DR)
			Object *dr34; // 0x98 Backup data register (BKP_DR)
			Object *dr35; // 0x9C Backup data register (BKP_DR)
			Object *dr36; // 0xA0 Backup data register (BKP_DR)
			Object *dr37; // 0xA4 Backup data register (BKP_DR)
			Object *dr38; // 0xA8 Backup data register (BKP_DR)
			Object *dr39; // 0xAC Backup data register (BKP_DR)
			Object *dr40; // 0xB0 Backup data register (BKP_DR)
			Object *dr41; // 0xB4 Backup data register (BKP_DR)
			Object *dr42; // 0xB8 Backup data register (BKP_DR)
			Object *rtccr; // 0x28 RTC clock calibration register (BKP_RTCCR)
			Object *cr; // 0x2C Backup control register (BKP_CR)
			Object *csr; // 0x30 BKP_CSR control/status register (BKP_CSR)
		} reg;

		struct {

			// DR1 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d1; // [0:15] Backup data
			} dr1;

			// DR2 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d2; // [0:15] Backup data
			} dr2;

			// DR3 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d3; // [0:15] Backup data
			} dr3;

			// DR4 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d4; // [0:15] Backup data
			} dr4;

			// DR5 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d5; // [0:15] Backup data
			} dr5;

			// DR6 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d6; // [0:15] Backup data
			} dr6;

			// DR7 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d7; // [0:15] Backup data
			} dr7;

			// DR8 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d8; // [0:15] Backup data
			} dr8;

			// DR9 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d9; // [0:15] Backup data
			} dr9;

			// DR10 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d10; // [0:15] Backup data
			} dr10;

			// DR11 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *dr11; // [0:15] Backup data
			} dr11;

			// DR12 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *dr12; // [0:15] Backup data
			} dr12;

			// DR13 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *dr13; // [0:15] Backup data
			} dr13;

			// DR14 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d14; // [0:15] Backup data
			} dr14;

			// DR15 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d15; // [0:15] Backup data
			} dr15;

			// DR16 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d16; // [0:15] Backup data
			} dr16;

			// DR17 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d17; // [0:15] Backup data
			} dr17;

			// DR18 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d18; // [0:15] Backup data
			} dr18;

			// DR19 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d19; // [0:15] Backup data
			} dr19;

			// DR20 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d20; // [0:15] Backup data
			} dr20;

			// DR21 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d21; // [0:15] Backup data
			} dr21;

			// DR22 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d22; // [0:15] Backup data
			} dr22;

			// DR23 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d23; // [0:15] Backup data
			} dr23;

			// DR24 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d24; // [0:15] Backup data
			} dr24;

			// DR25 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d25; // [0:15] Backup data
			} dr25;

			// DR26 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d26; // [0:15] Backup data
			} dr26;

			// DR27 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d27; // [0:15] Backup data
			} dr27;

			// DR28 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d28; // [0:15] Backup data
			} dr28;

			// DR29 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d29; // [0:15] Backup data
			} dr29;

			// DR30 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d30; // [0:15] Backup data
			} dr30;

			// DR31 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d31; // [0:15] Backup data
			} dr31;

			// DR32 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d32; // [0:15] Backup data
			} dr32;

			// DR33 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d33; // [0:15] Backup data
			} dr33;

			// DR34 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d34; // [0:15] Backup data
			} dr34;

			// DR35 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d35; // [0:15] Backup data
			} dr35;

			// DR36 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d36; // [0:15] Backup data
			} dr36;

			// DR37 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d37; // [0:15] Backup data
			} dr37;

			// DR38 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d38; // [0:15] Backup data
			} dr38;

			// DR39 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d39; // [0:15] Backup data
			} dr39;

			// DR40 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d40; // [0:15] Backup data
			} dr40;

			// DR41 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d41; // [0:15] Backup data
			} dr41;

			// DR42 (Backup data register (BKP_DR)) bitfields.
			struct {
				Object *d42; // [0:15] Backup data
			} dr42;

			// RTCCR (RTC clock calibration register (BKP_RTCCR)) bitfields.
			struct {
				Object *cal; // [0:6] Calibration value
				Object *cco; // [7:7] Calibration Clock Output
				Object *asoe; // [8:8] Alarm or second output enable
				Object *asos; // [9:9] Alarm or second output selection
			} rtccr;

			// CR (Backup control register (BKP_CR)) bitfields.
			struct {
				Object *tpe; // [0:0] Tamper pin enable
				Object *tpal; // [1:1] Tamper pin active level
			} cr;

			// CSR (BKP_CSR control/status register (BKP_CSR)) bitfields.
			struct {
				Object *cte; // [0:0] Clear Tamper event
				Object *cti; // [1:1] Clear Tamper Interrupt
				Object *tpie; // [2:2] Tamper Pin interrupt enable
				Object *tef; // [8:8] Tamper Event Flag
				Object *tif; // [9:9] Tamper Interrupt Flag
			} csr;
		} fld;
	} f1;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32BKPState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_bkp_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32BKPState *state = STM32_BKP_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f1.reg.dr1 = cm_object_get_child_by_name(obj, "DR1");
	state->f1.reg.dr2 = cm_object_get_child_by_name(obj, "DR2");
	state->f1.reg.dr3 = cm_object_get_child_by_name(obj, "DR3");
	state->f1.reg.dr4 = cm_object_get_child_by_name(obj, "DR4");
	state->f1.reg.dr5 = cm_object_get_child_by_name(obj, "DR5");
	state->f1.reg.dr6 = cm_object_get_child_by_name(obj, "DR6");
	state->f1.reg.dr7 = cm_object_get_child_by_name(obj, "DR7");
	state->f1.reg.dr8 = cm_object_get_child_by_name(obj, "DR8");
	state->f1.reg.dr9 = cm_object_get_child_by_name(obj, "DR9");
	state->f1.reg.dr10 = cm_object_get_child_by_name(obj, "DR10");
	state->f1.reg.dr11 = cm_object_get_child_by_name(obj, "DR11");
	state->f1.reg.dr12 = cm_object_get_child_by_name(obj, "DR12");
	state->f1.reg.dr13 = cm_object_get_child_by_name(obj, "DR13");
	state->f1.reg.dr14 = cm_object_get_child_by_name(obj, "DR14");
	state->f1.reg.dr15 = cm_object_get_child_by_name(obj, "DR15");
	state->f1.reg.dr16 = cm_object_get_child_by_name(obj, "DR16");
	state->f1.reg.dr17 = cm_object_get_child_by_name(obj, "DR17");
	state->f1.reg.dr18 = cm_object_get_child_by_name(obj, "DR18");
	state->f1.reg.dr19 = cm_object_get_child_by_name(obj, "DR19");
	state->f1.reg.dr20 = cm_object_get_child_by_name(obj, "DR20");
	state->f1.reg.dr21 = cm_object_get_child_by_name(obj, "DR21");
	state->f1.reg.dr22 = cm_object_get_child_by_name(obj, "DR22");
	state->f1.reg.dr23 = cm_object_get_child_by_name(obj, "DR23");
	state->f1.reg.dr24 = cm_object_get_child_by_name(obj, "DR24");
	state->f1.reg.dr25 = cm_object_get_child_by_name(obj, "DR25");
	state->f1.reg.dr26 = cm_object_get_child_by_name(obj, "DR26");
	state->f1.reg.dr27 = cm_object_get_child_by_name(obj, "DR27");
	state->f1.reg.dr28 = cm_object_get_child_by_name(obj, "DR28");
	state->f1.reg.dr29 = cm_object_get_child_by_name(obj, "DR29");
	state->f1.reg.dr30 = cm_object_get_child_by_name(obj, "DR30");
	state->f1.reg.dr31 = cm_object_get_child_by_name(obj, "DR31");
	state->f1.reg.dr32 = cm_object_get_child_by_name(obj, "DR32");
	state->f1.reg.dr33 = cm_object_get_child_by_name(obj, "DR33");
	state->f1.reg.dr34 = cm_object_get_child_by_name(obj, "DR34");
	state->f1.reg.dr35 = cm_object_get_child_by_name(obj, "DR35");
	state->f1.reg.dr36 = cm_object_get_child_by_name(obj, "DR36");
	state->f1.reg.dr37 = cm_object_get_child_by_name(obj, "DR37");
	state->f1.reg.dr38 = cm_object_get_child_by_name(obj, "DR38");
	state->f1.reg.dr39 = cm_object_get_child_by_name(obj, "DR39");
	state->f1.reg.dr40 = cm_object_get_child_by_name(obj, "DR40");
	state->f1.reg.dr41 = cm_object_get_child_by_name(obj, "DR41");
	state->f1.reg.dr42 = cm_object_get_child_by_name(obj, "DR42");
	state->f1.reg.rtccr = cm_object_get_child_by_name(obj, "RTCCR");
	state->f1.reg.cr = cm_object_get_child_by_name(obj, "CR");
	state->f1.reg.csr = cm_object_get_child_by_name(obj, "CSR");

	// DR1 bitfields.
	state->f1.fld.dr1.d1 = cm_object_get_child_by_name(state->f1.reg.dr1, "D1");

	// DR2 bitfields.
	state->f1.fld.dr2.d2 = cm_object_get_child_by_name(state->f1.reg.dr2, "D2");

	// DR3 bitfields.
	state->f1.fld.dr3.d3 = cm_object_get_child_by_name(state->f1.reg.dr3, "D3");

	// DR4 bitfields.
	state->f1.fld.dr4.d4 = cm_object_get_child_by_name(state->f1.reg.dr4, "D4");

	// DR5 bitfields.
	state->f1.fld.dr5.d5 = cm_object_get_child_by_name(state->f1.reg.dr5, "D5");

	// DR6 bitfields.
	state->f1.fld.dr6.d6 = cm_object_get_child_by_name(state->f1.reg.dr6, "D6");

	// DR7 bitfields.
	state->f1.fld.dr7.d7 = cm_object_get_child_by_name(state->f1.reg.dr7, "D7");

	// DR8 bitfields.
	state->f1.fld.dr8.d8 = cm_object_get_child_by_name(state->f1.reg.dr8, "D8");

	// DR9 bitfields.
	state->f1.fld.dr9.d9 = cm_object_get_child_by_name(state->f1.reg.dr9, "D9");

	// DR10 bitfields.
	state->f1.fld.dr10.d10 = cm_object_get_child_by_name(state->f1.reg.dr10, "D10");

	// DR11 bitfields.
	state->f1.fld.dr11.dr11 = cm_object_get_child_by_name(state->f1.reg.dr11, "DR11");

	// DR12 bitfields.
	state->f1.fld.dr12.dr12 = cm_object_get_child_by_name(state->f1.reg.dr12, "DR12");

	// DR13 bitfields.
	state->f1.fld.dr13.dr13 = cm_object_get_child_by_name(state->f1.reg.dr13, "DR13");

	// DR14 bitfields.
	state->f1.fld.dr14.d14 = cm_object_get_child_by_name(state->f1.reg.dr14, "D14");

	// DR15 bitfields.
	state->f1.fld.dr15.d15 = cm_object_get_child_by_name(state->f1.reg.dr15, "D15");

	// DR16 bitfields.
	state->f1.fld.dr16.d16 = cm_object_get_child_by_name(state->f1.reg.dr16, "D16");

	// DR17 bitfields.
	state->f1.fld.dr17.d17 = cm_object_get_child_by_name(state->f1.reg.dr17, "D17");

	// DR18 bitfields.
	state->f1.fld.dr18.d18 = cm_object_get_child_by_name(state->f1.reg.dr18, "D18");

	// DR19 bitfields.
	state->f1.fld.dr19.d19 = cm_object_get_child_by_name(state->f1.reg.dr19, "D19");

	// DR20 bitfields.
	state->f1.fld.dr20.d20 = cm_object_get_child_by_name(state->f1.reg.dr20, "D20");

	// DR21 bitfields.
	state->f1.fld.dr21.d21 = cm_object_get_child_by_name(state->f1.reg.dr21, "D21");

	// DR22 bitfields.
	state->f1.fld.dr22.d22 = cm_object_get_child_by_name(state->f1.reg.dr22, "D22");

	// DR23 bitfields.
	state->f1.fld.dr23.d23 = cm_object_get_child_by_name(state->f1.reg.dr23, "D23");

	// DR24 bitfields.
	state->f1.fld.dr24.d24 = cm_object_get_child_by_name(state->f1.reg.dr24, "D24");

	// DR25 bitfields.
	state->f1.fld.dr25.d25 = cm_object_get_child_by_name(state->f1.reg.dr25, "D25");

	// DR26 bitfields.
	state->f1.fld.dr26.d26 = cm_object_get_child_by_name(state->f1.reg.dr26, "D26");

	// DR27 bitfields.
	state->f1.fld.dr27.d27 = cm_object_get_child_by_name(state->f1.reg.dr27, "D27");

	// DR28 bitfields.
	state->f1.fld.dr28.d28 = cm_object_get_child_by_name(state->f1.reg.dr28, "D28");

	// DR29 bitfields.
	state->f1.fld.dr29.d29 = cm_object_get_child_by_name(state->f1.reg.dr29, "D29");

	// DR30 bitfields.
	state->f1.fld.dr30.d30 = cm_object_get_child_by_name(state->f1.reg.dr30, "D30");

	// DR31 bitfields.
	state->f1.fld.dr31.d31 = cm_object_get_child_by_name(state->f1.reg.dr31, "D31");

	// DR32 bitfields.
	state->f1.fld.dr32.d32 = cm_object_get_child_by_name(state->f1.reg.dr32, "D32");

	// DR33 bitfields.
	state->f1.fld.dr33.d33 = cm_object_get_child_by_name(state->f1.reg.dr33, "D33");

	// DR34 bitfields.
	state->f1.fld.dr34.d34 = cm_object_get_child_by_name(state->f1.reg.dr34, "D34");

	// DR35 bitfields.
	state->f1.fld.dr35.d35 = cm_object_get_child_by_name(state->f1.reg.dr35, "D35");

	// DR36 bitfields.
	state->f1.fld.dr36.d36 = cm_object_get_child_by_name(state->f1.reg.dr36, "D36");

	// DR37 bitfields.
	state->f1.fld.dr37.d37 = cm_object_get_child_by_name(state->f1.reg.dr37, "D37");

	// DR38 bitfields.
	state->f1.fld.dr38.d38 = cm_object_get_child_by_name(state->f1.reg.dr38, "D38");

	// DR39 bitfields.
	state->f1.fld.dr39.d39 = cm_object_get_child_by_name(state->f1.reg.dr39, "D39");

	// DR40 bitfields.
	state->f1.fld.dr40.d40 = cm_object_get_child_by_name(state->f1.reg.dr40, "D40");

	// DR41 bitfields.
	state->f1.fld.dr41.d41 = cm_object_get_child_by_name(state->f1.reg.dr41, "D41");

	// DR42 bitfields.
	state->f1.fld.dr42.d42 = cm_object_get_child_by_name(state->f1.reg.dr42, "D42");

	// RTCCR bitfields.
	state->f1.fld.rtccr.cal = cm_object_get_child_by_name(state->f1.reg.rtccr, "CAL");
	state->f1.fld.rtccr.cco = cm_object_get_child_by_name(state->f1.reg.rtccr, "CCO");
	state->f1.fld.rtccr.asoe = cm_object_get_child_by_name(state->f1.reg.rtccr, "ASOE");
	state->f1.fld.rtccr.asos = cm_object_get_child_by_name(state->f1.reg.rtccr, "ASOS");

	// CR bitfields.
	state->f1.fld.cr.tpe = cm_object_get_child_by_name(state->f1.reg.cr, "TPE");
	state->f1.fld.cr.tpal = cm_object_get_child_by_name(state->f1.reg.cr, "TPAL");

	// CSR bitfields.
	state->f1.fld.csr.cte = cm_object_get_child_by_name(state->f1.reg.csr, "CTE");
	state->f1.fld.csr.cti = cm_object_get_child_by_name(state->f1.reg.csr, "CTI");
	state->f1.fld.csr.tpie = cm_object_get_child_by_name(state->f1.reg.csr, "TPIE");
	state->f1.fld.csr.tef = cm_object_get_child_by_name(state->f1.reg.csr, "TEF");
	state->f1.fld.csr.tif = cm_object_get_child_by_name(state->f1.reg.csr, "TIF");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// IWDG (Independent watchdog) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F1 IWDG (Independent watchdog) registers.
		struct {
			Object *kr; // 0x0 Key register (IWDG_KR)
			Object *pr; // 0x4 Prescaler register (IWDG_PR)
			Object *rlr; // 0x8 Reload register (IWDG_RLR)
			Object *sr; // 0xC Status register (IWDG_SR)
		} reg;

		struct {

			// KR (Key register (IWDG_KR)) bitfields.
			struct {
				Object *key; // [0:15] Key value
			} kr;

			// PR (Prescaler register (IWDG_PR)) bitfields.
			struct {
				Object *pr; // [0:2] Prescaler divider
			} pr;

			// RLR (Reload register (IWDG_RLR)) bitfields.
			struct {
				Object *rl; // [0:11] Watchdog counter reload value
			} rlr;

			// SR (Status register (IWDG_SR)) bitfields.
			struct {
				Object *pvu; // [0:0] Watchdog prescaler value update
				Object *rvu; // [1:1] Watchdog counter reload value update
			} sr;
		} fld;
	} f1;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32IWDGState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_iwdg_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32IWDGState *state = STM32_IWDG_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f1.reg.kr = cm_object_get_child_by_name(obj, "KR");
	state->f1.reg.pr = cm_object_get_child_by_name(obj, "PR");
	state->f1.reg.rlr = cm_object_get_child_by_name(obj, "RLR");
	state->f1.reg.sr = cm_object_get_child_by_name(obj, "SR");

	// KR bitfields.
	state->f1.fld.kr.key = cm_object_get_child_by_name(state->f1.reg.kr, "KEY");

	// PR bitfields.
	state->f1.fld.pr.pr = cm_object_get_child_by_name(state->f1.reg.pr, "PR");

	// RLR bitfields.
	state->f1.fld.rlr.rl = cm_object_get_child_by_name(state->f1.reg.rlr, "RL");

	// SR bitfields.
	state->f1.fld.sr.pvu = cm_object_get_child_by_name(state->f1.reg.sr, "PVU");
	state->f1.fld.sr.rvu = cm_object_get_child_by_name(state->f1.reg.sr, "RVU");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// WWDG (Window watchdog) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F1 WWDG (Window watchdog) registers.
		struct {
			Object *cr; // 0x0 Control register (WWDG_CR)
			Object *cfr; // 0x4 Configuration register (WWDG_CFR)
			Object *sr; // 0x8 Status register (WWDG_SR)
		} reg;

		struct {

			// CR (Control register (WWDG_CR)) bitfields.
			struct {
				Object *t; // [0:6] 7-bit counter (MSB to LSB)
				Object *wdga; // [7:7] Activation bit
			} cr;

			// CFR (Configuration register (WWDG_CFR)) bitfields.
			struct {
				Object *w; // [0:6] 7-bit window value
				Object *wdgtb; // [7:8] Timer Base
				Object *ewi; // [9:9] Early Wakeup Interrupt
			} cfr;

			// SR (Status register (WWDG_SR)) bitfields.
			struct {
				Object *ewi; // [0:0] Early Wakeup Interrupt
			} sr;
		} fld;
	} f1;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32WWDGState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_wwdg_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32WWDGState *state = STM32_WWDG_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f1.reg.cr = cm_object_get_child_by_name(obj, "CR");
	state->f1.reg.cfr = cm_object_get_child_by_name(obj, "CFR");
	state->f1.reg.sr = cm_object_get_child_by_name(obj, "SR");

	// CR bitfields.
	state->f1.fld.cr.t = cm_object_get_child_by_name(state->f1.reg.cr, "T");
	state->f1.fld.cr.wdga = cm_object_get_child_by_name(state->f1.reg.cr, "WDGA");

	// CFR bitfields.
	state->f1.fld.cfr.w = cm_object_get_child_by_name(state->f1.reg.cfr, "W");
	state->f1.fld.cfr.wdgtb = cm_object_get_child_by_name(state->f1.reg.cfr, "WDGTB");
	state->f1.fld.cfr.ewi = cm_object_get_child_by_name(state->f1.reg.cfr, "EWI");

	// SR bitfields.
	state->f1.fld.sr.ewi = cm_object_get_child_by_name(state->f1.reg.sr, "EWI");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// TIM1 (Advanced timer) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F1 TIM1 (Advanced timer) registers.
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
			Object *ccr1; // 0x34 Capture/compare register 1
			Object *ccr2; // 0x38 Capture/compare register 2
			Object *ccr3; // 0x3C Capture/compare register 3
			Object *ccr4; // 0x40 Capture/compare register 4
			Object *dcr; // 0x48 DMA control register
			Object *dmar; // 0x4C DMA address for full transfer
			Object *rcr; // 0x30 Repetition counter register
			Object *bdtr; // 0x44 Break and dead-time register
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
				Object *comde; // [13:13] COM DMA request enable
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
				Object *icpcs; // [2:3] Input capture 1 prescaler
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
				Object *ccr3; // [0:15] Capture/Compare value
			} ccr3;

			// CCR4 (Capture/compare register 4) bitfields.
			struct {
				Object *ccr4; // [0:15] Capture/Compare value
			} ccr4;

			// DCR (DMA control register) bitfields.
			struct {
				Object *dba; // [0:4] DMA base address
				Object *dbl; // [8:12] DMA burst length
			} dcr;

			// DMAR (DMA address for full transfer) bitfields.
			struct {
				Object *dmab; // [0:15] DMA register for burst accesses
			} dmar;

			// RCR (Repetition counter register) bitfields.
			struct {
				Object *rep; // [0:7] Repetition counter value
			} rcr;

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
		} fld;
	} f1;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32TIM1State;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_tim1_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32TIM1State *state = STM32_TIM1_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f1.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
	state->f1.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
	state->f1.reg.smcr = cm_object_get_child_by_name(obj, "SMCR");
	state->f1.reg.dier = cm_object_get_child_by_name(obj, "DIER");
	state->f1.reg.sr = cm_object_get_child_by_name(obj, "SR");
	state->f1.reg.egr = cm_object_get_child_by_name(obj, "EGR");
	state->f1.reg.ccmr1_output = cm_object_get_child_by_name(obj, "CCMR1_Output");
	state->f1.reg.ccmr1_input = cm_object_get_child_by_name(obj, "CCMR1_Input");
	state->f1.reg.ccmr2_output = cm_object_get_child_by_name(obj, "CCMR2_Output");
	state->f1.reg.ccmr2_input = cm_object_get_child_by_name(obj, "CCMR2_Input");
	state->f1.reg.ccer = cm_object_get_child_by_name(obj, "CCER");
	state->f1.reg.cnt = cm_object_get_child_by_name(obj, "CNT");
	state->f1.reg.psc = cm_object_get_child_by_name(obj, "PSC");
	state->f1.reg.arr = cm_object_get_child_by_name(obj, "ARR");
	state->f1.reg.ccr1 = cm_object_get_child_by_name(obj, "CCR1");
	state->f1.reg.ccr2 = cm_object_get_child_by_name(obj, "CCR2");
	state->f1.reg.ccr3 = cm_object_get_child_by_name(obj, "CCR3");
	state->f1.reg.ccr4 = cm_object_get_child_by_name(obj, "CCR4");
	state->f1.reg.dcr = cm_object_get_child_by_name(obj, "DCR");
	state->f1.reg.dmar = cm_object_get_child_by_name(obj, "DMAR");
	state->f1.reg.rcr = cm_object_get_child_by_name(obj, "RCR");
	state->f1.reg.bdtr = cm_object_get_child_by_name(obj, "BDTR");

	// CR1 bitfields.
	state->f1.fld.cr1.cen = cm_object_get_child_by_name(state->f1.reg.cr1, "CEN");
	state->f1.fld.cr1.udis = cm_object_get_child_by_name(state->f1.reg.cr1, "UDIS");
	state->f1.fld.cr1.urs = cm_object_get_child_by_name(state->f1.reg.cr1, "URS");
	state->f1.fld.cr1.opm = cm_object_get_child_by_name(state->f1.reg.cr1, "OPM");
	state->f1.fld.cr1.dir = cm_object_get_child_by_name(state->f1.reg.cr1, "DIR");
	state->f1.fld.cr1.cms = cm_object_get_child_by_name(state->f1.reg.cr1, "CMS");
	state->f1.fld.cr1.arpe = cm_object_get_child_by_name(state->f1.reg.cr1, "ARPE");
	state->f1.fld.cr1.ckd = cm_object_get_child_by_name(state->f1.reg.cr1, "CKD");

	// CR2 bitfields.
	state->f1.fld.cr2.ccpc = cm_object_get_child_by_name(state->f1.reg.cr2, "CCPC");
	state->f1.fld.cr2.ccus = cm_object_get_child_by_name(state->f1.reg.cr2, "CCUS");
	state->f1.fld.cr2.ccds = cm_object_get_child_by_name(state->f1.reg.cr2, "CCDS");
	state->f1.fld.cr2.mms = cm_object_get_child_by_name(state->f1.reg.cr2, "MMS");
	state->f1.fld.cr2.ti1s = cm_object_get_child_by_name(state->f1.reg.cr2, "TI1S");
	state->f1.fld.cr2.ois1 = cm_object_get_child_by_name(state->f1.reg.cr2, "OIS1");
	state->f1.fld.cr2.ois1n = cm_object_get_child_by_name(state->f1.reg.cr2, "OIS1N");
	state->f1.fld.cr2.ois2 = cm_object_get_child_by_name(state->f1.reg.cr2, "OIS2");
	state->f1.fld.cr2.ois2n = cm_object_get_child_by_name(state->f1.reg.cr2, "OIS2N");
	state->f1.fld.cr2.ois3 = cm_object_get_child_by_name(state->f1.reg.cr2, "OIS3");
	state->f1.fld.cr2.ois3n = cm_object_get_child_by_name(state->f1.reg.cr2, "OIS3N");
	state->f1.fld.cr2.ois4 = cm_object_get_child_by_name(state->f1.reg.cr2, "OIS4");

	// SMCR bitfields.
	state->f1.fld.smcr.sms = cm_object_get_child_by_name(state->f1.reg.smcr, "SMS");
	state->f1.fld.smcr.ts = cm_object_get_child_by_name(state->f1.reg.smcr, "TS");
	state->f1.fld.smcr.msm = cm_object_get_child_by_name(state->f1.reg.smcr, "MSM");
	state->f1.fld.smcr.etf = cm_object_get_child_by_name(state->f1.reg.smcr, "ETF");
	state->f1.fld.smcr.etps = cm_object_get_child_by_name(state->f1.reg.smcr, "ETPS");
	state->f1.fld.smcr.ece = cm_object_get_child_by_name(state->f1.reg.smcr, "ECE");
	state->f1.fld.smcr.etp = cm_object_get_child_by_name(state->f1.reg.smcr, "ETP");

	// DIER bitfields.
	state->f1.fld.dier.uie = cm_object_get_child_by_name(state->f1.reg.dier, "UIE");
	state->f1.fld.dier.cc1ie = cm_object_get_child_by_name(state->f1.reg.dier, "CC1IE");
	state->f1.fld.dier.cc2ie = cm_object_get_child_by_name(state->f1.reg.dier, "CC2IE");
	state->f1.fld.dier.cc3ie = cm_object_get_child_by_name(state->f1.reg.dier, "CC3IE");
	state->f1.fld.dier.cc4ie = cm_object_get_child_by_name(state->f1.reg.dier, "CC4IE");
	state->f1.fld.dier.comie = cm_object_get_child_by_name(state->f1.reg.dier, "COMIE");
	state->f1.fld.dier.tie = cm_object_get_child_by_name(state->f1.reg.dier, "TIE");
	state->f1.fld.dier.bie = cm_object_get_child_by_name(state->f1.reg.dier, "BIE");
	state->f1.fld.dier.ude = cm_object_get_child_by_name(state->f1.reg.dier, "UDE");
	state->f1.fld.dier.cc1de = cm_object_get_child_by_name(state->f1.reg.dier, "CC1DE");
	state->f1.fld.dier.cc2de = cm_object_get_child_by_name(state->f1.reg.dier, "CC2DE");
	state->f1.fld.dier.cc3de = cm_object_get_child_by_name(state->f1.reg.dier, "CC3DE");
	state->f1.fld.dier.cc4de = cm_object_get_child_by_name(state->f1.reg.dier, "CC4DE");
	state->f1.fld.dier.comde = cm_object_get_child_by_name(state->f1.reg.dier, "COMDE");
	state->f1.fld.dier.tde = cm_object_get_child_by_name(state->f1.reg.dier, "TDE");

	// SR bitfields.
	state->f1.fld.sr.uif = cm_object_get_child_by_name(state->f1.reg.sr, "UIF");
	state->f1.fld.sr.cc1if = cm_object_get_child_by_name(state->f1.reg.sr, "CC1IF");
	state->f1.fld.sr.cc2if = cm_object_get_child_by_name(state->f1.reg.sr, "CC2IF");
	state->f1.fld.sr.cc3if = cm_object_get_child_by_name(state->f1.reg.sr, "CC3IF");
	state->f1.fld.sr.cc4if = cm_object_get_child_by_name(state->f1.reg.sr, "CC4IF");
	state->f1.fld.sr.comif = cm_object_get_child_by_name(state->f1.reg.sr, "COMIF");
	state->f1.fld.sr.tif = cm_object_get_child_by_name(state->f1.reg.sr, "TIF");
	state->f1.fld.sr.bif = cm_object_get_child_by_name(state->f1.reg.sr, "BIF");
	state->f1.fld.sr.cc1of = cm_object_get_child_by_name(state->f1.reg.sr, "CC1OF");
	state->f1.fld.sr.cc2of = cm_object_get_child_by_name(state->f1.reg.sr, "CC2OF");
	state->f1.fld.sr.cc3of = cm_object_get_child_by_name(state->f1.reg.sr, "CC3OF");
	state->f1.fld.sr.cc4of = cm_object_get_child_by_name(state->f1.reg.sr, "CC4OF");

	// EGR bitfields.
	state->f1.fld.egr.ug = cm_object_get_child_by_name(state->f1.reg.egr, "UG");
	state->f1.fld.egr.cc1g = cm_object_get_child_by_name(state->f1.reg.egr, "CC1G");
	state->f1.fld.egr.cc2g = cm_object_get_child_by_name(state->f1.reg.egr, "CC2G");
	state->f1.fld.egr.cc3g = cm_object_get_child_by_name(state->f1.reg.egr, "CC3G");
	state->f1.fld.egr.cc4g = cm_object_get_child_by_name(state->f1.reg.egr, "CC4G");
	state->f1.fld.egr.comg = cm_object_get_child_by_name(state->f1.reg.egr, "COMG");
	state->f1.fld.egr.tg = cm_object_get_child_by_name(state->f1.reg.egr, "TG");
	state->f1.fld.egr.bg = cm_object_get_child_by_name(state->f1.reg.egr, "BG");

	// CCMR1_Output bitfields.
	state->f1.fld.ccmr1_output.cc1s = cm_object_get_child_by_name(state->f1.reg.ccmr1_output, "CC1S");
	state->f1.fld.ccmr1_output.oc1fe = cm_object_get_child_by_name(state->f1.reg.ccmr1_output, "OC1FE");
	state->f1.fld.ccmr1_output.oc1pe = cm_object_get_child_by_name(state->f1.reg.ccmr1_output, "OC1PE");
	state->f1.fld.ccmr1_output.oc1m = cm_object_get_child_by_name(state->f1.reg.ccmr1_output, "OC1M");
	state->f1.fld.ccmr1_output.oc1ce = cm_object_get_child_by_name(state->f1.reg.ccmr1_output, "OC1CE");
	state->f1.fld.ccmr1_output.cc2s = cm_object_get_child_by_name(state->f1.reg.ccmr1_output, "CC2S");
	state->f1.fld.ccmr1_output.oc2fe = cm_object_get_child_by_name(state->f1.reg.ccmr1_output, "OC2FE");
	state->f1.fld.ccmr1_output.oc2pe = cm_object_get_child_by_name(state->f1.reg.ccmr1_output, "OC2PE");
	state->f1.fld.ccmr1_output.oc2m = cm_object_get_child_by_name(state->f1.reg.ccmr1_output, "OC2M");
	state->f1.fld.ccmr1_output.oc2ce = cm_object_get_child_by_name(state->f1.reg.ccmr1_output, "OC2CE");

	// CCMR1_Input bitfields.
	state->f1.fld.ccmr1_input.cc1s = cm_object_get_child_by_name(state->f1.reg.ccmr1_input, "CC1S");
	state->f1.fld.ccmr1_input.icpcs = cm_object_get_child_by_name(state->f1.reg.ccmr1_input, "ICPCS");
	state->f1.fld.ccmr1_input.ic1f = cm_object_get_child_by_name(state->f1.reg.ccmr1_input, "IC1F");
	state->f1.fld.ccmr1_input.cc2s = cm_object_get_child_by_name(state->f1.reg.ccmr1_input, "CC2S");
	state->f1.fld.ccmr1_input.ic2pcs = cm_object_get_child_by_name(state->f1.reg.ccmr1_input, "IC2PCS");
	state->f1.fld.ccmr1_input.ic2f = cm_object_get_child_by_name(state->f1.reg.ccmr1_input, "IC2F");

	// CCMR2_Output bitfields.
	state->f1.fld.ccmr2_output.cc3s = cm_object_get_child_by_name(state->f1.reg.ccmr2_output, "CC3S");
	state->f1.fld.ccmr2_output.oc3fe = cm_object_get_child_by_name(state->f1.reg.ccmr2_output, "OC3FE");
	state->f1.fld.ccmr2_output.oc3pe = cm_object_get_child_by_name(state->f1.reg.ccmr2_output, "OC3PE");
	state->f1.fld.ccmr2_output.oc3m = cm_object_get_child_by_name(state->f1.reg.ccmr2_output, "OC3M");
	state->f1.fld.ccmr2_output.oc3ce = cm_object_get_child_by_name(state->f1.reg.ccmr2_output, "OC3CE");
	state->f1.fld.ccmr2_output.cc4s = cm_object_get_child_by_name(state->f1.reg.ccmr2_output, "CC4S");
	state->f1.fld.ccmr2_output.oc4fe = cm_object_get_child_by_name(state->f1.reg.ccmr2_output, "OC4FE");
	state->f1.fld.ccmr2_output.oc4pe = cm_object_get_child_by_name(state->f1.reg.ccmr2_output, "OC4PE");
	state->f1.fld.ccmr2_output.oc4m = cm_object_get_child_by_name(state->f1.reg.ccmr2_output, "OC4M");
	state->f1.fld.ccmr2_output.oc4ce = cm_object_get_child_by_name(state->f1.reg.ccmr2_output, "OC4CE");

	// CCMR2_Input bitfields.
	state->f1.fld.ccmr2_input.cc3s = cm_object_get_child_by_name(state->f1.reg.ccmr2_input, "CC3S");
	state->f1.fld.ccmr2_input.ic3psc = cm_object_get_child_by_name(state->f1.reg.ccmr2_input, "IC3PSC");
	state->f1.fld.ccmr2_input.ic3f = cm_object_get_child_by_name(state->f1.reg.ccmr2_input, "IC3F");
	state->f1.fld.ccmr2_input.cc4s = cm_object_get_child_by_name(state->f1.reg.ccmr2_input, "CC4S");
	state->f1.fld.ccmr2_input.ic4psc = cm_object_get_child_by_name(state->f1.reg.ccmr2_input, "IC4PSC");
	state->f1.fld.ccmr2_input.ic4f = cm_object_get_child_by_name(state->f1.reg.ccmr2_input, "IC4F");

	// CCER bitfields.
	state->f1.fld.ccer.cc1e = cm_object_get_child_by_name(state->f1.reg.ccer, "CC1E");
	state->f1.fld.ccer.cc1p = cm_object_get_child_by_name(state->f1.reg.ccer, "CC1P");
	state->f1.fld.ccer.cc1ne = cm_object_get_child_by_name(state->f1.reg.ccer, "CC1NE");
	state->f1.fld.ccer.cc1np = cm_object_get_child_by_name(state->f1.reg.ccer, "CC1NP");
	state->f1.fld.ccer.cc2e = cm_object_get_child_by_name(state->f1.reg.ccer, "CC2E");
	state->f1.fld.ccer.cc2p = cm_object_get_child_by_name(state->f1.reg.ccer, "CC2P");
	state->f1.fld.ccer.cc2ne = cm_object_get_child_by_name(state->f1.reg.ccer, "CC2NE");
	state->f1.fld.ccer.cc2np = cm_object_get_child_by_name(state->f1.reg.ccer, "CC2NP");
	state->f1.fld.ccer.cc3e = cm_object_get_child_by_name(state->f1.reg.ccer, "CC3E");
	state->f1.fld.ccer.cc3p = cm_object_get_child_by_name(state->f1.reg.ccer, "CC3P");
	state->f1.fld.ccer.cc3ne = cm_object_get_child_by_name(state->f1.reg.ccer, "CC3NE");
	state->f1.fld.ccer.cc3np = cm_object_get_child_by_name(state->f1.reg.ccer, "CC3NP");
	state->f1.fld.ccer.cc4e = cm_object_get_child_by_name(state->f1.reg.ccer, "CC4E");
	state->f1.fld.ccer.cc4p = cm_object_get_child_by_name(state->f1.reg.ccer, "CC4P");

	// CNT bitfields.
	state->f1.fld.cnt.cnt = cm_object_get_child_by_name(state->f1.reg.cnt, "CNT");

	// PSC bitfields.
	state->f1.fld.psc.psc = cm_object_get_child_by_name(state->f1.reg.psc, "PSC");

	// ARR bitfields.
	state->f1.fld.arr.arr = cm_object_get_child_by_name(state->f1.reg.arr, "ARR");

	// CCR1 bitfields.
	state->f1.fld.ccr1.ccr1 = cm_object_get_child_by_name(state->f1.reg.ccr1, "CCR1");

	// CCR2 bitfields.
	state->f1.fld.ccr2.ccr2 = cm_object_get_child_by_name(state->f1.reg.ccr2, "CCR2");

	// CCR3 bitfields.
	state->f1.fld.ccr3.ccr3 = cm_object_get_child_by_name(state->f1.reg.ccr3, "CCR3");

	// CCR4 bitfields.
	state->f1.fld.ccr4.ccr4 = cm_object_get_child_by_name(state->f1.reg.ccr4, "CCR4");

	// DCR bitfields.
	state->f1.fld.dcr.dba = cm_object_get_child_by_name(state->f1.reg.dcr, "DBA");
	state->f1.fld.dcr.dbl = cm_object_get_child_by_name(state->f1.reg.dcr, "DBL");

	// DMAR bitfields.
	state->f1.fld.dmar.dmab = cm_object_get_child_by_name(state->f1.reg.dmar, "DMAB");

	// RCR bitfields.
	state->f1.fld.rcr.rep = cm_object_get_child_by_name(state->f1.reg.rcr, "REP");

	// BDTR bitfields.
	state->f1.fld.bdtr.dtg = cm_object_get_child_by_name(state->f1.reg.bdtr, "DTG");
	state->f1.fld.bdtr.lock = cm_object_get_child_by_name(state->f1.reg.bdtr, "LOCK");
	state->f1.fld.bdtr.ossi = cm_object_get_child_by_name(state->f1.reg.bdtr, "OSSI");
	state->f1.fld.bdtr.ossr = cm_object_get_child_by_name(state->f1.reg.bdtr, "OSSR");
	state->f1.fld.bdtr.bke = cm_object_get_child_by_name(state->f1.reg.bdtr, "BKE");
	state->f1.fld.bdtr.bkp = cm_object_get_child_by_name(state->f1.reg.bdtr, "BKP");
	state->f1.fld.bdtr.aoe = cm_object_get_child_by_name(state->f1.reg.bdtr, "AOE");
	state->f1.fld.bdtr.moe = cm_object_get_child_by_name(state->f1.reg.bdtr, "MOE");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// TIM2 (General purpose timer) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F1 TIM2 (General purpose timer) registers.
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
				Object *o24ce; // [15:15] Output compare 4 clear enable
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
				Object *cc2e; // [4:4] Capture/Compare 2 output enable
				Object *cc2p; // [5:5] Capture/Compare 2 output Polarity
				Object *cc3e; // [8:8] Capture/Compare 3 output enable
				Object *cc3p; // [9:9] Capture/Compare 3 output Polarity
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
				Object *ccr3; // [0:15] Capture/Compare value
			} ccr3;

			// CCR4 (Capture/compare register 4) bitfields.
			struct {
				Object *ccr4; // [0:15] Capture/Compare value
			} ccr4;

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
	} f1;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32TIM2State;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_tim2_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32TIM2State *state = STM32_TIM2_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f1.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
	state->f1.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
	state->f1.reg.smcr = cm_object_get_child_by_name(obj, "SMCR");
	state->f1.reg.dier = cm_object_get_child_by_name(obj, "DIER");
	state->f1.reg.sr = cm_object_get_child_by_name(obj, "SR");
	state->f1.reg.egr = cm_object_get_child_by_name(obj, "EGR");
	state->f1.reg.ccmr1_output = cm_object_get_child_by_name(obj, "CCMR1_Output");
	state->f1.reg.ccmr1_input = cm_object_get_child_by_name(obj, "CCMR1_Input");
	state->f1.reg.ccmr2_output = cm_object_get_child_by_name(obj, "CCMR2_Output");
	state->f1.reg.ccmr2_input = cm_object_get_child_by_name(obj, "CCMR2_Input");
	state->f1.reg.ccer = cm_object_get_child_by_name(obj, "CCER");
	state->f1.reg.cnt = cm_object_get_child_by_name(obj, "CNT");
	state->f1.reg.psc = cm_object_get_child_by_name(obj, "PSC");
	state->f1.reg.arr = cm_object_get_child_by_name(obj, "ARR");
	state->f1.reg.ccr1 = cm_object_get_child_by_name(obj, "CCR1");
	state->f1.reg.ccr2 = cm_object_get_child_by_name(obj, "CCR2");
	state->f1.reg.ccr3 = cm_object_get_child_by_name(obj, "CCR3");
	state->f1.reg.ccr4 = cm_object_get_child_by_name(obj, "CCR4");
	state->f1.reg.dcr = cm_object_get_child_by_name(obj, "DCR");
	state->f1.reg.dmar = cm_object_get_child_by_name(obj, "DMAR");

	// CR1 bitfields.
	state->f1.fld.cr1.cen = cm_object_get_child_by_name(state->f1.reg.cr1, "CEN");
	state->f1.fld.cr1.udis = cm_object_get_child_by_name(state->f1.reg.cr1, "UDIS");
	state->f1.fld.cr1.urs = cm_object_get_child_by_name(state->f1.reg.cr1, "URS");
	state->f1.fld.cr1.opm = cm_object_get_child_by_name(state->f1.reg.cr1, "OPM");
	state->f1.fld.cr1.dir = cm_object_get_child_by_name(state->f1.reg.cr1, "DIR");
	state->f1.fld.cr1.cms = cm_object_get_child_by_name(state->f1.reg.cr1, "CMS");
	state->f1.fld.cr1.arpe = cm_object_get_child_by_name(state->f1.reg.cr1, "ARPE");
	state->f1.fld.cr1.ckd = cm_object_get_child_by_name(state->f1.reg.cr1, "CKD");

	// CR2 bitfields.
	state->f1.fld.cr2.ccds = cm_object_get_child_by_name(state->f1.reg.cr2, "CCDS");
	state->f1.fld.cr2.mms = cm_object_get_child_by_name(state->f1.reg.cr2, "MMS");
	state->f1.fld.cr2.ti1s = cm_object_get_child_by_name(state->f1.reg.cr2, "TI1S");

	// SMCR bitfields.
	state->f1.fld.smcr.sms = cm_object_get_child_by_name(state->f1.reg.smcr, "SMS");
	state->f1.fld.smcr.ts = cm_object_get_child_by_name(state->f1.reg.smcr, "TS");
	state->f1.fld.smcr.msm = cm_object_get_child_by_name(state->f1.reg.smcr, "MSM");
	state->f1.fld.smcr.etf = cm_object_get_child_by_name(state->f1.reg.smcr, "ETF");
	state->f1.fld.smcr.etps = cm_object_get_child_by_name(state->f1.reg.smcr, "ETPS");
	state->f1.fld.smcr.ece = cm_object_get_child_by_name(state->f1.reg.smcr, "ECE");
	state->f1.fld.smcr.etp = cm_object_get_child_by_name(state->f1.reg.smcr, "ETP");

	// DIER bitfields.
	state->f1.fld.dier.uie = cm_object_get_child_by_name(state->f1.reg.dier, "UIE");
	state->f1.fld.dier.cc1ie = cm_object_get_child_by_name(state->f1.reg.dier, "CC1IE");
	state->f1.fld.dier.cc2ie = cm_object_get_child_by_name(state->f1.reg.dier, "CC2IE");
	state->f1.fld.dier.cc3ie = cm_object_get_child_by_name(state->f1.reg.dier, "CC3IE");
	state->f1.fld.dier.cc4ie = cm_object_get_child_by_name(state->f1.reg.dier, "CC4IE");
	state->f1.fld.dier.tie = cm_object_get_child_by_name(state->f1.reg.dier, "TIE");
	state->f1.fld.dier.ude = cm_object_get_child_by_name(state->f1.reg.dier, "UDE");
	state->f1.fld.dier.cc1de = cm_object_get_child_by_name(state->f1.reg.dier, "CC1DE");
	state->f1.fld.dier.cc2de = cm_object_get_child_by_name(state->f1.reg.dier, "CC2DE");
	state->f1.fld.dier.cc3de = cm_object_get_child_by_name(state->f1.reg.dier, "CC3DE");
	state->f1.fld.dier.cc4de = cm_object_get_child_by_name(state->f1.reg.dier, "CC4DE");
	state->f1.fld.dier.tde = cm_object_get_child_by_name(state->f1.reg.dier, "TDE");

	// SR bitfields.
	state->f1.fld.sr.uif = cm_object_get_child_by_name(state->f1.reg.sr, "UIF");
	state->f1.fld.sr.cc1if = cm_object_get_child_by_name(state->f1.reg.sr, "CC1IF");
	state->f1.fld.sr.cc2if = cm_object_get_child_by_name(state->f1.reg.sr, "CC2IF");
	state->f1.fld.sr.cc3if = cm_object_get_child_by_name(state->f1.reg.sr, "CC3IF");
	state->f1.fld.sr.cc4if = cm_object_get_child_by_name(state->f1.reg.sr, "CC4IF");
	state->f1.fld.sr.tif = cm_object_get_child_by_name(state->f1.reg.sr, "TIF");
	state->f1.fld.sr.cc1of = cm_object_get_child_by_name(state->f1.reg.sr, "CC1OF");
	state->f1.fld.sr.cc2of = cm_object_get_child_by_name(state->f1.reg.sr, "CC2OF");
	state->f1.fld.sr.cc3of = cm_object_get_child_by_name(state->f1.reg.sr, "CC3OF");
	state->f1.fld.sr.cc4of = cm_object_get_child_by_name(state->f1.reg.sr, "CC4OF");

	// EGR bitfields.
	state->f1.fld.egr.ug = cm_object_get_child_by_name(state->f1.reg.egr, "UG");
	state->f1.fld.egr.cc1g = cm_object_get_child_by_name(state->f1.reg.egr, "CC1G");
	state->f1.fld.egr.cc2g = cm_object_get_child_by_name(state->f1.reg.egr, "CC2G");
	state->f1.fld.egr.cc3g = cm_object_get_child_by_name(state->f1.reg.egr, "CC3G");
	state->f1.fld.egr.cc4g = cm_object_get_child_by_name(state->f1.reg.egr, "CC4G");
	state->f1.fld.egr.tg = cm_object_get_child_by_name(state->f1.reg.egr, "TG");

	// CCMR1_Output bitfields.
	state->f1.fld.ccmr1_output.cc1s = cm_object_get_child_by_name(state->f1.reg.ccmr1_output, "CC1S");
	state->f1.fld.ccmr1_output.oc1fe = cm_object_get_child_by_name(state->f1.reg.ccmr1_output, "OC1FE");
	state->f1.fld.ccmr1_output.oc1pe = cm_object_get_child_by_name(state->f1.reg.ccmr1_output, "OC1PE");
	state->f1.fld.ccmr1_output.oc1m = cm_object_get_child_by_name(state->f1.reg.ccmr1_output, "OC1M");
	state->f1.fld.ccmr1_output.oc1ce = cm_object_get_child_by_name(state->f1.reg.ccmr1_output, "OC1CE");
	state->f1.fld.ccmr1_output.cc2s = cm_object_get_child_by_name(state->f1.reg.ccmr1_output, "CC2S");
	state->f1.fld.ccmr1_output.oc2fe = cm_object_get_child_by_name(state->f1.reg.ccmr1_output, "OC2FE");
	state->f1.fld.ccmr1_output.oc2pe = cm_object_get_child_by_name(state->f1.reg.ccmr1_output, "OC2PE");
	state->f1.fld.ccmr1_output.oc2m = cm_object_get_child_by_name(state->f1.reg.ccmr1_output, "OC2M");
	state->f1.fld.ccmr1_output.oc2ce = cm_object_get_child_by_name(state->f1.reg.ccmr1_output, "OC2CE");

	// CCMR1_Input bitfields.
	state->f1.fld.ccmr1_input.cc1s = cm_object_get_child_by_name(state->f1.reg.ccmr1_input, "CC1S");
	state->f1.fld.ccmr1_input.ic1psc = cm_object_get_child_by_name(state->f1.reg.ccmr1_input, "IC1PSC");
	state->f1.fld.ccmr1_input.ic1f = cm_object_get_child_by_name(state->f1.reg.ccmr1_input, "IC1F");
	state->f1.fld.ccmr1_input.cc2s = cm_object_get_child_by_name(state->f1.reg.ccmr1_input, "CC2S");
	state->f1.fld.ccmr1_input.ic2psc = cm_object_get_child_by_name(state->f1.reg.ccmr1_input, "IC2PSC");
	state->f1.fld.ccmr1_input.ic2f = cm_object_get_child_by_name(state->f1.reg.ccmr1_input, "IC2F");

	// CCMR2_Output bitfields.
	state->f1.fld.ccmr2_output.cc3s = cm_object_get_child_by_name(state->f1.reg.ccmr2_output, "CC3S");
	state->f1.fld.ccmr2_output.oc3fe = cm_object_get_child_by_name(state->f1.reg.ccmr2_output, "OC3FE");
	state->f1.fld.ccmr2_output.oc3pe = cm_object_get_child_by_name(state->f1.reg.ccmr2_output, "OC3PE");
	state->f1.fld.ccmr2_output.oc3m = cm_object_get_child_by_name(state->f1.reg.ccmr2_output, "OC3M");
	state->f1.fld.ccmr2_output.oc3ce = cm_object_get_child_by_name(state->f1.reg.ccmr2_output, "OC3CE");
	state->f1.fld.ccmr2_output.cc4s = cm_object_get_child_by_name(state->f1.reg.ccmr2_output, "CC4S");
	state->f1.fld.ccmr2_output.oc4fe = cm_object_get_child_by_name(state->f1.reg.ccmr2_output, "OC4FE");
	state->f1.fld.ccmr2_output.oc4pe = cm_object_get_child_by_name(state->f1.reg.ccmr2_output, "OC4PE");
	state->f1.fld.ccmr2_output.oc4m = cm_object_get_child_by_name(state->f1.reg.ccmr2_output, "OC4M");
	state->f1.fld.ccmr2_output.o24ce = cm_object_get_child_by_name(state->f1.reg.ccmr2_output, "O24CE");

	// CCMR2_Input bitfields.
	state->f1.fld.ccmr2_input.cc3s = cm_object_get_child_by_name(state->f1.reg.ccmr2_input, "CC3S");
	state->f1.fld.ccmr2_input.ic3psc = cm_object_get_child_by_name(state->f1.reg.ccmr2_input, "IC3PSC");
	state->f1.fld.ccmr2_input.ic3f = cm_object_get_child_by_name(state->f1.reg.ccmr2_input, "IC3F");
	state->f1.fld.ccmr2_input.cc4s = cm_object_get_child_by_name(state->f1.reg.ccmr2_input, "CC4S");
	state->f1.fld.ccmr2_input.ic4psc = cm_object_get_child_by_name(state->f1.reg.ccmr2_input, "IC4PSC");
	state->f1.fld.ccmr2_input.ic4f = cm_object_get_child_by_name(state->f1.reg.ccmr2_input, "IC4F");

	// CCER bitfields.
	state->f1.fld.ccer.cc1e = cm_object_get_child_by_name(state->f1.reg.ccer, "CC1E");
	state->f1.fld.ccer.cc1p = cm_object_get_child_by_name(state->f1.reg.ccer, "CC1P");
	state->f1.fld.ccer.cc2e = cm_object_get_child_by_name(state->f1.reg.ccer, "CC2E");
	state->f1.fld.ccer.cc2p = cm_object_get_child_by_name(state->f1.reg.ccer, "CC2P");
	state->f1.fld.ccer.cc3e = cm_object_get_child_by_name(state->f1.reg.ccer, "CC3E");
	state->f1.fld.ccer.cc3p = cm_object_get_child_by_name(state->f1.reg.ccer, "CC3P");
	state->f1.fld.ccer.cc4e = cm_object_get_child_by_name(state->f1.reg.ccer, "CC4E");
	state->f1.fld.ccer.cc4p = cm_object_get_child_by_name(state->f1.reg.ccer, "CC4P");

	// CNT bitfields.
	state->f1.fld.cnt.cnt = cm_object_get_child_by_name(state->f1.reg.cnt, "CNT");

	// PSC bitfields.
	state->f1.fld.psc.psc = cm_object_get_child_by_name(state->f1.reg.psc, "PSC");

	// ARR bitfields.
	state->f1.fld.arr.arr = cm_object_get_child_by_name(state->f1.reg.arr, "ARR");

	// CCR1 bitfields.
	state->f1.fld.ccr1.ccr1 = cm_object_get_child_by_name(state->f1.reg.ccr1, "CCR1");

	// CCR2 bitfields.
	state->f1.fld.ccr2.ccr2 = cm_object_get_child_by_name(state->f1.reg.ccr2, "CCR2");

	// CCR3 bitfields.
	state->f1.fld.ccr3.ccr3 = cm_object_get_child_by_name(state->f1.reg.ccr3, "CCR3");

	// CCR4 bitfields.
	state->f1.fld.ccr4.ccr4 = cm_object_get_child_by_name(state->f1.reg.ccr4, "CCR4");

	// DCR bitfields.
	state->f1.fld.dcr.dba = cm_object_get_child_by_name(state->f1.reg.dcr, "DBA");
	state->f1.fld.dcr.dbl = cm_object_get_child_by_name(state->f1.reg.dcr, "DBL");

	// DMAR bitfields.
	state->f1.fld.dmar.dmab = cm_object_get_child_by_name(state->f1.reg.dmar, "DMAB");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// TIM9 (General purpose timer) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F1 TIM9 (General purpose timer) registers.
		struct {
			Object *cr1; // 0x0 Control register 1
			Object *cr2; // 0x4 Control register 2
			Object *smcr; // 0x8 Slave mode control register
			Object *dier; // 0xC DMA/Interrupt enable register
			Object *sr; // 0x10 Status register
			Object *egr; // 0x14 Event generation register
			Object *ccmr1_output; // 0x18 Capture/compare mode register 1 (output mode)
			Object *ccmr1_input; // 0x18 Capture/compare mode register 1 (input mode)
			Object *ccer; // 0x20 Capture/compare enable register
			Object *cnt; // 0x24 Counter
			Object *psc; // 0x28 Prescaler
			Object *arr; // 0x2C Auto-reload register
			Object *ccr1; // 0x34 Capture/compare register 1
			Object *ccr2; // 0x38 Capture/compare register 2
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
				Object *mms; // [4:6] Master mode selection
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
				Object *tie; // [6:6] Trigger interrupt enable
			} dier;

			// SR (Status register) bitfields.
			struct {
				Object *uif; // [0:0] Update interrupt flag
				Object *cc1if; // [1:1] Capture/compare 1 interrupt flag
				Object *cc2if; // [2:2] Capture/Compare 2 interrupt flag
				Object *tif; // [6:6] Trigger interrupt flag
				Object *cc1of; // [9:9] Capture/Compare 1 overcapture flag
				Object *cc2of; // [10:10] Capture/compare 2 overcapture flag
			} sr;

			// EGR (Event generation register) bitfields.
			struct {
				Object *ug; // [0:0] Update generation
				Object *cc1g; // [1:1] Capture/compare 1 generation
				Object *cc2g; // [2:2] Capture/compare 2 generation
				Object *tg; // [6:6] Trigger generation
			} egr;

			// CCMR1_Output (Capture/compare mode register 1 (output mode)) bitfields.
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

			// CCR1 (Capture/compare register 1) bitfields.
			struct {
				Object *ccr1; // [0:15] Capture/Compare 1 value
			} ccr1;

			// CCR2 (Capture/compare register 2) bitfields.
			struct {
				Object *ccr2; // [0:15] Capture/Compare 2 value
			} ccr2;
		} fld;
	} f1;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32TIM9State;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_tim9_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32TIM9State *state = STM32_TIM9_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f1.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
	state->f1.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
	state->f1.reg.smcr = cm_object_get_child_by_name(obj, "SMCR");
	state->f1.reg.dier = cm_object_get_child_by_name(obj, "DIER");
	state->f1.reg.sr = cm_object_get_child_by_name(obj, "SR");
	state->f1.reg.egr = cm_object_get_child_by_name(obj, "EGR");
	state->f1.reg.ccmr1_output = cm_object_get_child_by_name(obj, "CCMR1_Output");
	state->f1.reg.ccmr1_input = cm_object_get_child_by_name(obj, "CCMR1_Input");
	state->f1.reg.ccer = cm_object_get_child_by_name(obj, "CCER");
	state->f1.reg.cnt = cm_object_get_child_by_name(obj, "CNT");
	state->f1.reg.psc = cm_object_get_child_by_name(obj, "PSC");
	state->f1.reg.arr = cm_object_get_child_by_name(obj, "ARR");
	state->f1.reg.ccr1 = cm_object_get_child_by_name(obj, "CCR1");
	state->f1.reg.ccr2 = cm_object_get_child_by_name(obj, "CCR2");

	// CR1 bitfields.
	state->f1.fld.cr1.cen = cm_object_get_child_by_name(state->f1.reg.cr1, "CEN");
	state->f1.fld.cr1.udis = cm_object_get_child_by_name(state->f1.reg.cr1, "UDIS");
	state->f1.fld.cr1.urs = cm_object_get_child_by_name(state->f1.reg.cr1, "URS");
	state->f1.fld.cr1.opm = cm_object_get_child_by_name(state->f1.reg.cr1, "OPM");
	state->f1.fld.cr1.arpe = cm_object_get_child_by_name(state->f1.reg.cr1, "ARPE");
	state->f1.fld.cr1.ckd = cm_object_get_child_by_name(state->f1.reg.cr1, "CKD");

	// CR2 bitfields.
	state->f1.fld.cr2.mms = cm_object_get_child_by_name(state->f1.reg.cr2, "MMS");

	// SMCR bitfields.
	state->f1.fld.smcr.sms = cm_object_get_child_by_name(state->f1.reg.smcr, "SMS");
	state->f1.fld.smcr.ts = cm_object_get_child_by_name(state->f1.reg.smcr, "TS");
	state->f1.fld.smcr.msm = cm_object_get_child_by_name(state->f1.reg.smcr, "MSM");

	// DIER bitfields.
	state->f1.fld.dier.uie = cm_object_get_child_by_name(state->f1.reg.dier, "UIE");
	state->f1.fld.dier.cc1ie = cm_object_get_child_by_name(state->f1.reg.dier, "CC1IE");
	state->f1.fld.dier.cc2ie = cm_object_get_child_by_name(state->f1.reg.dier, "CC2IE");
	state->f1.fld.dier.tie = cm_object_get_child_by_name(state->f1.reg.dier, "TIE");

	// SR bitfields.
	state->f1.fld.sr.uif = cm_object_get_child_by_name(state->f1.reg.sr, "UIF");
	state->f1.fld.sr.cc1if = cm_object_get_child_by_name(state->f1.reg.sr, "CC1IF");
	state->f1.fld.sr.cc2if = cm_object_get_child_by_name(state->f1.reg.sr, "CC2IF");
	state->f1.fld.sr.tif = cm_object_get_child_by_name(state->f1.reg.sr, "TIF");
	state->f1.fld.sr.cc1of = cm_object_get_child_by_name(state->f1.reg.sr, "CC1OF");
	state->f1.fld.sr.cc2of = cm_object_get_child_by_name(state->f1.reg.sr, "CC2OF");

	// EGR bitfields.
	state->f1.fld.egr.ug = cm_object_get_child_by_name(state->f1.reg.egr, "UG");
	state->f1.fld.egr.cc1g = cm_object_get_child_by_name(state->f1.reg.egr, "CC1G");
	state->f1.fld.egr.cc2g = cm_object_get_child_by_name(state->f1.reg.egr, "CC2G");
	state->f1.fld.egr.tg = cm_object_get_child_by_name(state->f1.reg.egr, "TG");

	// CCMR1_Output bitfields.
	state->f1.fld.ccmr1_output.cc1s = cm_object_get_child_by_name(state->f1.reg.ccmr1_output, "CC1S");
	state->f1.fld.ccmr1_output.oc1fe = cm_object_get_child_by_name(state->f1.reg.ccmr1_output, "OC1FE");
	state->f1.fld.ccmr1_output.oc1pe = cm_object_get_child_by_name(state->f1.reg.ccmr1_output, "OC1PE");
	state->f1.fld.ccmr1_output.oc1m = cm_object_get_child_by_name(state->f1.reg.ccmr1_output, "OC1M");
	state->f1.fld.ccmr1_output.cc2s = cm_object_get_child_by_name(state->f1.reg.ccmr1_output, "CC2S");
	state->f1.fld.ccmr1_output.oc2fe = cm_object_get_child_by_name(state->f1.reg.ccmr1_output, "OC2FE");
	state->f1.fld.ccmr1_output.oc2pe = cm_object_get_child_by_name(state->f1.reg.ccmr1_output, "OC2PE");
	state->f1.fld.ccmr1_output.oc2m = cm_object_get_child_by_name(state->f1.reg.ccmr1_output, "OC2M");

	// CCMR1_Input bitfields.
	state->f1.fld.ccmr1_input.cc1s = cm_object_get_child_by_name(state->f1.reg.ccmr1_input, "CC1S");
	state->f1.fld.ccmr1_input.ic1psc = cm_object_get_child_by_name(state->f1.reg.ccmr1_input, "IC1PSC");
	state->f1.fld.ccmr1_input.ic1f = cm_object_get_child_by_name(state->f1.reg.ccmr1_input, "IC1F");
	state->f1.fld.ccmr1_input.cc2s = cm_object_get_child_by_name(state->f1.reg.ccmr1_input, "CC2S");
	state->f1.fld.ccmr1_input.ic2psc = cm_object_get_child_by_name(state->f1.reg.ccmr1_input, "IC2PSC");
	state->f1.fld.ccmr1_input.ic2f = cm_object_get_child_by_name(state->f1.reg.ccmr1_input, "IC2F");

	// CCER bitfields.
	state->f1.fld.ccer.cc1e = cm_object_get_child_by_name(state->f1.reg.ccer, "CC1E");
	state->f1.fld.ccer.cc1p = cm_object_get_child_by_name(state->f1.reg.ccer, "CC1P");
	state->f1.fld.ccer.cc1np = cm_object_get_child_by_name(state->f1.reg.ccer, "CC1NP");
	state->f1.fld.ccer.cc2e = cm_object_get_child_by_name(state->f1.reg.ccer, "CC2E");
	state->f1.fld.ccer.cc2p = cm_object_get_child_by_name(state->f1.reg.ccer, "CC2P");
	state->f1.fld.ccer.cc2np = cm_object_get_child_by_name(state->f1.reg.ccer, "CC2NP");

	// CNT bitfields.
	state->f1.fld.cnt.cnt = cm_object_get_child_by_name(state->f1.reg.cnt, "CNT");

	// PSC bitfields.
	state->f1.fld.psc.psc = cm_object_get_child_by_name(state->f1.reg.psc, "PSC");

	// ARR bitfields.
	state->f1.fld.arr.arr = cm_object_get_child_by_name(state->f1.reg.arr, "ARR");

	// CCR1 bitfields.
	state->f1.fld.ccr1.ccr1 = cm_object_get_child_by_name(state->f1.reg.ccr1, "CCR1");

	// CCR2 bitfields.
	state->f1.fld.ccr2.ccr2 = cm_object_get_child_by_name(state->f1.reg.ccr2, "CCR2");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// TIM10 (General purpose timer) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F1 TIM10 (General purpose timer) registers.
		struct {
			Object *cr1; // 0x0 Control register 1
			Object *cr2; // 0x4 Control register 2
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

			// CR2 (Control register 2) bitfields.
			struct {
				Object *mms; // [4:6] Master mode selection
			} cr2;

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
		} fld;
	} f1;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32TIM10State;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_tim10_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32TIM10State *state = STM32_TIM10_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f1.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
	state->f1.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
	state->f1.reg.dier = cm_object_get_child_by_name(obj, "DIER");
	state->f1.reg.sr = cm_object_get_child_by_name(obj, "SR");
	state->f1.reg.egr = cm_object_get_child_by_name(obj, "EGR");
	state->f1.reg.ccmr1_output = cm_object_get_child_by_name(obj, "CCMR1_Output");
	state->f1.reg.ccmr1_input = cm_object_get_child_by_name(obj, "CCMR1_Input");
	state->f1.reg.ccer = cm_object_get_child_by_name(obj, "CCER");
	state->f1.reg.cnt = cm_object_get_child_by_name(obj, "CNT");
	state->f1.reg.psc = cm_object_get_child_by_name(obj, "PSC");
	state->f1.reg.arr = cm_object_get_child_by_name(obj, "ARR");
	state->f1.reg.ccr1 = cm_object_get_child_by_name(obj, "CCR1");

	// CR1 bitfields.
	state->f1.fld.cr1.cen = cm_object_get_child_by_name(state->f1.reg.cr1, "CEN");
	state->f1.fld.cr1.udis = cm_object_get_child_by_name(state->f1.reg.cr1, "UDIS");
	state->f1.fld.cr1.urs = cm_object_get_child_by_name(state->f1.reg.cr1, "URS");
	state->f1.fld.cr1.arpe = cm_object_get_child_by_name(state->f1.reg.cr1, "ARPE");
	state->f1.fld.cr1.ckd = cm_object_get_child_by_name(state->f1.reg.cr1, "CKD");

	// CR2 bitfields.
	state->f1.fld.cr2.mms = cm_object_get_child_by_name(state->f1.reg.cr2, "MMS");

	// DIER bitfields.
	state->f1.fld.dier.uie = cm_object_get_child_by_name(state->f1.reg.dier, "UIE");
	state->f1.fld.dier.cc1ie = cm_object_get_child_by_name(state->f1.reg.dier, "CC1IE");

	// SR bitfields.
	state->f1.fld.sr.uif = cm_object_get_child_by_name(state->f1.reg.sr, "UIF");
	state->f1.fld.sr.cc1if = cm_object_get_child_by_name(state->f1.reg.sr, "CC1IF");
	state->f1.fld.sr.cc1of = cm_object_get_child_by_name(state->f1.reg.sr, "CC1OF");

	// EGR bitfields.
	state->f1.fld.egr.ug = cm_object_get_child_by_name(state->f1.reg.egr, "UG");
	state->f1.fld.egr.cc1g = cm_object_get_child_by_name(state->f1.reg.egr, "CC1G");

	// CCMR1_Output bitfields.
	state->f1.fld.ccmr1_output.cc1s = cm_object_get_child_by_name(state->f1.reg.ccmr1_output, "CC1S");
	state->f1.fld.ccmr1_output.oc1pe = cm_object_get_child_by_name(state->f1.reg.ccmr1_output, "OC1PE");
	state->f1.fld.ccmr1_output.oc1m = cm_object_get_child_by_name(state->f1.reg.ccmr1_output, "OC1M");

	// CCMR1_Input bitfields.
	state->f1.fld.ccmr1_input.cc1s = cm_object_get_child_by_name(state->f1.reg.ccmr1_input, "CC1S");
	state->f1.fld.ccmr1_input.ic1psc = cm_object_get_child_by_name(state->f1.reg.ccmr1_input, "IC1PSC");
	state->f1.fld.ccmr1_input.ic1f = cm_object_get_child_by_name(state->f1.reg.ccmr1_input, "IC1F");

	// CCER bitfields.
	state->f1.fld.ccer.cc1e = cm_object_get_child_by_name(state->f1.reg.ccer, "CC1E");
	state->f1.fld.ccer.cc1p = cm_object_get_child_by_name(state->f1.reg.ccer, "CC1P");
	state->f1.fld.ccer.cc1np = cm_object_get_child_by_name(state->f1.reg.ccer, "CC1NP");

	// CNT bitfields.
	state->f1.fld.cnt.cnt = cm_object_get_child_by_name(state->f1.reg.cnt, "CNT");

	// PSC bitfields.
	state->f1.fld.psc.psc = cm_object_get_child_by_name(state->f1.reg.psc, "PSC");

	// ARR bitfields.
	state->f1.fld.arr.arr = cm_object_get_child_by_name(state->f1.reg.arr, "ARR");

	// CCR1 bitfields.
	state->f1.fld.ccr1.ccr1 = cm_object_get_child_by_name(state->f1.reg.ccr1, "CCR1");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// TIM6 (Basic timer) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F1 TIM6 (Basic timer) registers.
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
	} f1;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32TIM6State;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_tim6_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32TIM6State *state = STM32_TIM6_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f1.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
	state->f1.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
	state->f1.reg.dier = cm_object_get_child_by_name(obj, "DIER");
	state->f1.reg.sr = cm_object_get_child_by_name(obj, "SR");
	state->f1.reg.egr = cm_object_get_child_by_name(obj, "EGR");
	state->f1.reg.cnt = cm_object_get_child_by_name(obj, "CNT");
	state->f1.reg.psc = cm_object_get_child_by_name(obj, "PSC");
	state->f1.reg.arr = cm_object_get_child_by_name(obj, "ARR");

	// CR1 bitfields.
	state->f1.fld.cr1.cen = cm_object_get_child_by_name(state->f1.reg.cr1, "CEN");
	state->f1.fld.cr1.udis = cm_object_get_child_by_name(state->f1.reg.cr1, "UDIS");
	state->f1.fld.cr1.urs = cm_object_get_child_by_name(state->f1.reg.cr1, "URS");
	state->f1.fld.cr1.opm = cm_object_get_child_by_name(state->f1.reg.cr1, "OPM");
	state->f1.fld.cr1.arpe = cm_object_get_child_by_name(state->f1.reg.cr1, "ARPE");

	// CR2 bitfields.
	state->f1.fld.cr2.mms = cm_object_get_child_by_name(state->f1.reg.cr2, "MMS");

	// DIER bitfields.
	state->f1.fld.dier.uie = cm_object_get_child_by_name(state->f1.reg.dier, "UIE");
	state->f1.fld.dier.ude = cm_object_get_child_by_name(state->f1.reg.dier, "UDE");

	// SR bitfields.
	state->f1.fld.sr.uif = cm_object_get_child_by_name(state->f1.reg.sr, "UIF");

	// EGR bitfields.
	state->f1.fld.egr.ug = cm_object_get_child_by_name(state->f1.reg.egr, "UG");

	// CNT bitfields.
	state->f1.fld.cnt.cnt = cm_object_get_child_by_name(state->f1.reg.cnt, "CNT");

	// PSC bitfields.
	state->f1.fld.psc.psc = cm_object_get_child_by_name(state->f1.reg.psc, "PSC");

	// ARR bitfields.
	state->f1.fld.arr.arr = cm_object_get_child_by_name(state->f1.reg.arr, "ARR");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// I2C1 (Inter integrated circuit) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F1 I2C1 (Inter integrated circuit) registers.
		struct {
			Object *cr1; // 0x0 Control register 1
			Object *cr2; // 0x4 Control register 2
			Object *oar1; // 0x8 Own address register 1
			Object *oar2; // 0xC Own address register 2
			Object *dr; // 0x10 Data register
			Object *sr1; // 0x14 Status register 1
			Object *sr2; // 0x18 Status register 2
			Object *ccr; // 0x1C Clock control register
			Object *trise; // 0x20 TRISE register
		} reg;

		struct {

			// CR1 (Control register 1) bitfields.
			struct {
				Object *pe; // [0:0] Peripheral enable
				Object *smbus; // [1:1] SMBus mode
				Object *smbtype; // [3:3] SMBus type
				Object *enarp; // [4:4] ARP enable
				Object *enpec; // [5:5] PEC enable
				Object *engc; // [6:6] General call enable
				Object *nostretch; // [7:7] Clock stretching disable (Slave mode)
				Object *start; // [8:8] Start generation
				Object *stop; // [9:9] Stop generation
				Object *ack; // [10:10] Acknowledge enable
				Object *pos; // [11:11] Acknowledge/PEC Position (for data reception)
				Object *pec; // [12:12] Packet error checking
				Object *alert; // [13:13] SMBus alert
				Object *swrst; // [15:15] Software reset
			} cr1;

			// CR2 (Control register 2) bitfields.
			struct {
				Object *freq; // [0:5] Peripheral clock frequency
				Object *iterren; // [8:8] Error interrupt enable
				Object *itevten; // [9:9] Event interrupt enable
				Object *itbufen; // [10:10] Buffer interrupt enable
				Object *dmaen; // [11:11] DMA requests enable
				Object *last; // [12:12] DMA last transfer
			} cr2;

			// OAR1 (Own address register 1) bitfields.
			struct {
				Object *add0; // [0:0] Interface address
				Object *add7; // [1:7] Interface address
				Object *add10; // [8:9] Interface address
				Object *addmode; // [15:15] Addressing mode (slave mode)
			} oar1;

			// OAR2 (Own address register 2) bitfields.
			struct {
				Object *endual; // [0:0] Dual addressing mode enable
				Object *add2; // [1:7] Interface address
			} oar2;

			// DR (Data register) bitfields.
			struct {
				Object *dr; // [0:7] 8-bit data register
			} dr;

			// SR1 (Status register 1) bitfields.
			struct {
				Object *sb; // [0:0] Start bit (Master mode)
				Object *addr; // [1:1] Address sent (master mode)/matched (slave mode)
				Object *btf; // [2:2] Byte transfer finished
				Object *add10; // [3:3] 10-bit header sent (Master mode)
				Object *stopf; // [4:4] Stop detection (slave mode)
				Object *rxne; // [6:6] Data register not empty (receivers)
				Object *txe; // [7:7] Data register empty (transmitters)
				Object *berr; // [8:8] Bus error
				Object *arlo; // [9:9] Arbitration lost (master mode)
				Object *af; // [10:10] Acknowledge failure
				Object *ovr; // [11:11] Overrun/Underrun
				Object *pecerr; // [12:12] PEC Error in reception
				Object *timeout; // [14:14] Timeout or Tlow error
				Object *smbalert; // [15:15] SMBus alert
			} sr1;

			// SR2 (Status register 2) bitfields.
			struct {
				Object *msl; // [0:0] Master/slave
				Object *busy; // [1:1] Bus busy
				Object *tra; // [2:2] Transmitter/receiver
				Object *gencall; // [4:4] General call address (Slave mode)
				Object *smbdefault; // [5:5] SMBus device default address (Slave mode)
				Object *smbhost; // [6:6] SMBus host header (Slave mode)
				Object *dualf; // [7:7] Dual flag (Slave mode)
				Object *pec; // [8:15] Acket error checking register
			} sr2;

			// CCR (Clock control register) bitfields.
			struct {
				Object *ccr; // [0:11] Clock control register in Fast/Standard mode (Master mode)
				Object *duty; // [14:14] Fast mode duty cycle
				Object *f_s; // [15:15] I2C master mode selection
			} ccr;

			// TRISE (TRISE register) bitfields.
			struct {
				Object *trise; // [0:5] Maximum rise time in Fast/Standard mode (Master mode)
			} trise;
		} fld;
	} f1;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32I2C1State;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_i2c1_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32I2C1State *state = STM32_I2C1_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f1.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
	state->f1.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
	state->f1.reg.oar1 = cm_object_get_child_by_name(obj, "OAR1");
	state->f1.reg.oar2 = cm_object_get_child_by_name(obj, "OAR2");
	state->f1.reg.dr = cm_object_get_child_by_name(obj, "DR");
	state->f1.reg.sr1 = cm_object_get_child_by_name(obj, "SR1");
	state->f1.reg.sr2 = cm_object_get_child_by_name(obj, "SR2");
	state->f1.reg.ccr = cm_object_get_child_by_name(obj, "CCR");
	state->f1.reg.trise = cm_object_get_child_by_name(obj, "TRISE");

	// CR1 bitfields.
	state->f1.fld.cr1.pe = cm_object_get_child_by_name(state->f1.reg.cr1, "PE");
	state->f1.fld.cr1.smbus = cm_object_get_child_by_name(state->f1.reg.cr1, "SMBUS");
	state->f1.fld.cr1.smbtype = cm_object_get_child_by_name(state->f1.reg.cr1, "SMBTYPE");
	state->f1.fld.cr1.enarp = cm_object_get_child_by_name(state->f1.reg.cr1, "ENARP");
	state->f1.fld.cr1.enpec = cm_object_get_child_by_name(state->f1.reg.cr1, "ENPEC");
	state->f1.fld.cr1.engc = cm_object_get_child_by_name(state->f1.reg.cr1, "ENGC");
	state->f1.fld.cr1.nostretch = cm_object_get_child_by_name(state->f1.reg.cr1, "NOSTRETCH");
	state->f1.fld.cr1.start = cm_object_get_child_by_name(state->f1.reg.cr1, "START");
	state->f1.fld.cr1.stop = cm_object_get_child_by_name(state->f1.reg.cr1, "STOP");
	state->f1.fld.cr1.ack = cm_object_get_child_by_name(state->f1.reg.cr1, "ACK");
	state->f1.fld.cr1.pos = cm_object_get_child_by_name(state->f1.reg.cr1, "POS");
	state->f1.fld.cr1.pec = cm_object_get_child_by_name(state->f1.reg.cr1, "PEC");
	state->f1.fld.cr1.alert = cm_object_get_child_by_name(state->f1.reg.cr1, "ALERT");
	state->f1.fld.cr1.swrst = cm_object_get_child_by_name(state->f1.reg.cr1, "SWRST");

	// CR2 bitfields.
	state->f1.fld.cr2.freq = cm_object_get_child_by_name(state->f1.reg.cr2, "FREQ");
	state->f1.fld.cr2.iterren = cm_object_get_child_by_name(state->f1.reg.cr2, "ITERREN");
	state->f1.fld.cr2.itevten = cm_object_get_child_by_name(state->f1.reg.cr2, "ITEVTEN");
	state->f1.fld.cr2.itbufen = cm_object_get_child_by_name(state->f1.reg.cr2, "ITBUFEN");
	state->f1.fld.cr2.dmaen = cm_object_get_child_by_name(state->f1.reg.cr2, "DMAEN");
	state->f1.fld.cr2.last = cm_object_get_child_by_name(state->f1.reg.cr2, "LAST");

	// OAR1 bitfields.
	state->f1.fld.oar1.add0 = cm_object_get_child_by_name(state->f1.reg.oar1, "ADD0");
	state->f1.fld.oar1.add7 = cm_object_get_child_by_name(state->f1.reg.oar1, "ADD7");
	state->f1.fld.oar1.add10 = cm_object_get_child_by_name(state->f1.reg.oar1, "ADD10");
	state->f1.fld.oar1.addmode = cm_object_get_child_by_name(state->f1.reg.oar1, "ADDMODE");

	// OAR2 bitfields.
	state->f1.fld.oar2.endual = cm_object_get_child_by_name(state->f1.reg.oar2, "ENDUAL");
	state->f1.fld.oar2.add2 = cm_object_get_child_by_name(state->f1.reg.oar2, "ADD2");

	// DR bitfields.
	state->f1.fld.dr.dr = cm_object_get_child_by_name(state->f1.reg.dr, "DR");

	// SR1 bitfields.
	state->f1.fld.sr1.sb = cm_object_get_child_by_name(state->f1.reg.sr1, "SB");
	state->f1.fld.sr1.addr = cm_object_get_child_by_name(state->f1.reg.sr1, "ADDR");
	state->f1.fld.sr1.btf = cm_object_get_child_by_name(state->f1.reg.sr1, "BTF");
	state->f1.fld.sr1.add10 = cm_object_get_child_by_name(state->f1.reg.sr1, "ADD10");
	state->f1.fld.sr1.stopf = cm_object_get_child_by_name(state->f1.reg.sr1, "STOPF");
	state->f1.fld.sr1.rxne = cm_object_get_child_by_name(state->f1.reg.sr1, "RxNE");
	state->f1.fld.sr1.txe = cm_object_get_child_by_name(state->f1.reg.sr1, "TxE");
	state->f1.fld.sr1.berr = cm_object_get_child_by_name(state->f1.reg.sr1, "BERR");
	state->f1.fld.sr1.arlo = cm_object_get_child_by_name(state->f1.reg.sr1, "ARLO");
	state->f1.fld.sr1.af = cm_object_get_child_by_name(state->f1.reg.sr1, "AF");
	state->f1.fld.sr1.ovr = cm_object_get_child_by_name(state->f1.reg.sr1, "OVR");
	state->f1.fld.sr1.pecerr = cm_object_get_child_by_name(state->f1.reg.sr1, "PECERR");
	state->f1.fld.sr1.timeout = cm_object_get_child_by_name(state->f1.reg.sr1, "TIMEOUT");
	state->f1.fld.sr1.smbalert = cm_object_get_child_by_name(state->f1.reg.sr1, "SMBALERT");

	// SR2 bitfields.
	state->f1.fld.sr2.msl = cm_object_get_child_by_name(state->f1.reg.sr2, "MSL");
	state->f1.fld.sr2.busy = cm_object_get_child_by_name(state->f1.reg.sr2, "BUSY");
	state->f1.fld.sr2.tra = cm_object_get_child_by_name(state->f1.reg.sr2, "TRA");
	state->f1.fld.sr2.gencall = cm_object_get_child_by_name(state->f1.reg.sr2, "GENCALL");
	state->f1.fld.sr2.smbdefault = cm_object_get_child_by_name(state->f1.reg.sr2, "SMBDEFAULT");
	state->f1.fld.sr2.smbhost = cm_object_get_child_by_name(state->f1.reg.sr2, "SMBHOST");
	state->f1.fld.sr2.dualf = cm_object_get_child_by_name(state->f1.reg.sr2, "DUALF");
	state->f1.fld.sr2.pec = cm_object_get_child_by_name(state->f1.reg.sr2, "PEC");

	// CCR bitfields.
	state->f1.fld.ccr.ccr = cm_object_get_child_by_name(state->f1.reg.ccr, "CCR");
	state->f1.fld.ccr.duty = cm_object_get_child_by_name(state->f1.reg.ccr, "DUTY");
	state->f1.fld.ccr.f_s = cm_object_get_child_by_name(state->f1.reg.ccr, "F_S");

	// TRISE bitfields.
	state->f1.fld.trise.trise = cm_object_get_child_by_name(state->f1.reg.trise, "TRISE");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// SPI1 (Serial peripheral interface) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F1 SPI1 (Serial peripheral interface) registers.
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
				Object *errie; // [5:5] Error interrupt enable
				Object *rxneie; // [6:6] RX buffer not empty interrupt enable
				Object *txeie; // [7:7] Tx buffer empty interrupt enable
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
	} f1;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32SPI1State;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_spi1_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32SPI1State *state = STM32_SPI1_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f1.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
	state->f1.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
	state->f1.reg.sr = cm_object_get_child_by_name(obj, "SR");
	state->f1.reg.dr = cm_object_get_child_by_name(obj, "DR");
	state->f1.reg.crcpr = cm_object_get_child_by_name(obj, "CRCPR");
	state->f1.reg.rxcrcr = cm_object_get_child_by_name(obj, "RXCRCR");
	state->f1.reg.txcrcr = cm_object_get_child_by_name(obj, "TXCRCR");
	state->f1.reg.i2scfgr = cm_object_get_child_by_name(obj, "I2SCFGR");
	state->f1.reg.i2spr = cm_object_get_child_by_name(obj, "I2SPR");

	// CR1 bitfields.
	state->f1.fld.cr1.cpha = cm_object_get_child_by_name(state->f1.reg.cr1, "CPHA");
	state->f1.fld.cr1.cpol = cm_object_get_child_by_name(state->f1.reg.cr1, "CPOL");
	state->f1.fld.cr1.mstr = cm_object_get_child_by_name(state->f1.reg.cr1, "MSTR");
	state->f1.fld.cr1.br = cm_object_get_child_by_name(state->f1.reg.cr1, "BR");
	state->f1.fld.cr1.spe = cm_object_get_child_by_name(state->f1.reg.cr1, "SPE");
	state->f1.fld.cr1.lsbfirst = cm_object_get_child_by_name(state->f1.reg.cr1, "LSBFIRST");
	state->f1.fld.cr1.ssi = cm_object_get_child_by_name(state->f1.reg.cr1, "SSI");
	state->f1.fld.cr1.ssm = cm_object_get_child_by_name(state->f1.reg.cr1, "SSM");
	state->f1.fld.cr1.rxonly = cm_object_get_child_by_name(state->f1.reg.cr1, "RXONLY");
	state->f1.fld.cr1.dff = cm_object_get_child_by_name(state->f1.reg.cr1, "DFF");
	state->f1.fld.cr1.crcnext = cm_object_get_child_by_name(state->f1.reg.cr1, "CRCNEXT");
	state->f1.fld.cr1.crcen = cm_object_get_child_by_name(state->f1.reg.cr1, "CRCEN");
	state->f1.fld.cr1.bidioe = cm_object_get_child_by_name(state->f1.reg.cr1, "BIDIOE");
	state->f1.fld.cr1.bidimode = cm_object_get_child_by_name(state->f1.reg.cr1, "BIDIMODE");

	// CR2 bitfields.
	state->f1.fld.cr2.rxdmaen = cm_object_get_child_by_name(state->f1.reg.cr2, "RXDMAEN");
	state->f1.fld.cr2.txdmaen = cm_object_get_child_by_name(state->f1.reg.cr2, "TXDMAEN");
	state->f1.fld.cr2.ssoe = cm_object_get_child_by_name(state->f1.reg.cr2, "SSOE");
	state->f1.fld.cr2.errie = cm_object_get_child_by_name(state->f1.reg.cr2, "ERRIE");
	state->f1.fld.cr2.rxneie = cm_object_get_child_by_name(state->f1.reg.cr2, "RXNEIE");
	state->f1.fld.cr2.txeie = cm_object_get_child_by_name(state->f1.reg.cr2, "TXEIE");

	// SR bitfields.
	state->f1.fld.sr.rxne = cm_object_get_child_by_name(state->f1.reg.sr, "RXNE");
	state->f1.fld.sr.txe = cm_object_get_child_by_name(state->f1.reg.sr, "TXE");
	state->f1.fld.sr.chside = cm_object_get_child_by_name(state->f1.reg.sr, "CHSIDE");
	state->f1.fld.sr.udr = cm_object_get_child_by_name(state->f1.reg.sr, "UDR");
	state->f1.fld.sr.crcerr = cm_object_get_child_by_name(state->f1.reg.sr, "CRCERR");
	state->f1.fld.sr.modf = cm_object_get_child_by_name(state->f1.reg.sr, "MODF");
	state->f1.fld.sr.ovr = cm_object_get_child_by_name(state->f1.reg.sr, "OVR");
	state->f1.fld.sr.bsy = cm_object_get_child_by_name(state->f1.reg.sr, "BSY");

	// DR bitfields.
	state->f1.fld.dr.dr = cm_object_get_child_by_name(state->f1.reg.dr, "DR");

	// CRCPR bitfields.
	state->f1.fld.crcpr.crcpoly = cm_object_get_child_by_name(state->f1.reg.crcpr, "CRCPOLY");

	// RXCRCR bitfields.
	state->f1.fld.rxcrcr.rxcrc = cm_object_get_child_by_name(state->f1.reg.rxcrcr, "RxCRC");

	// TXCRCR bitfields.
	state->f1.fld.txcrcr.txcrc = cm_object_get_child_by_name(state->f1.reg.txcrcr, "TxCRC");

	// I2SCFGR bitfields.
	state->f1.fld.i2scfgr.chlen = cm_object_get_child_by_name(state->f1.reg.i2scfgr, "CHLEN");
	state->f1.fld.i2scfgr.datlen = cm_object_get_child_by_name(state->f1.reg.i2scfgr, "DATLEN");
	state->f1.fld.i2scfgr.ckpol = cm_object_get_child_by_name(state->f1.reg.i2scfgr, "CKPOL");
	state->f1.fld.i2scfgr.i2sstd = cm_object_get_child_by_name(state->f1.reg.i2scfgr, "I2SSTD");
	state->f1.fld.i2scfgr.pcmsync = cm_object_get_child_by_name(state->f1.reg.i2scfgr, "PCMSYNC");
	state->f1.fld.i2scfgr.i2scfg = cm_object_get_child_by_name(state->f1.reg.i2scfgr, "I2SCFG");
	state->f1.fld.i2scfgr.i2se = cm_object_get_child_by_name(state->f1.reg.i2scfgr, "I2SE");
	state->f1.fld.i2scfgr.i2smod = cm_object_get_child_by_name(state->f1.reg.i2scfgr, "I2SMOD");

	// I2SPR bitfields.
	state->f1.fld.i2spr.i2sdiv = cm_object_get_child_by_name(state->f1.reg.i2spr, "I2SDIV");
	state->f1.fld.i2spr.odd = cm_object_get_child_by_name(state->f1.reg.i2spr, "ODD");
	state->f1.fld.i2spr.mckoe = cm_object_get_child_by_name(state->f1.reg.i2spr, "MCKOE");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// USART1 (Universal synchronous asynchronous receiver transmitter) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F1 USART1 (Universal synchronous asynchronous receiver transmitter) registers.
		struct {
			Object *sr; // 0x0 Status register
			Object *dr; // 0x4 Data register
			Object *brr; // 0x8 Baud rate register
			Object *cr1; // 0xC Control register 1
			Object *cr2; // 0x10 Control register 2
			Object *cr3; // 0x14 Control register 3
			Object *gtpr; // 0x18 Guard time and prescaler register
		} reg;

		struct {

			// SR (Status register) bitfields.
			struct {
				Object *pe; // [0:0] Parity error
				Object *fe; // [1:1] Framing error
				Object *ne; // [2:2] Noise error flag
				Object *ore; // [3:3] Overrun error
				Object *idle; // [4:4] IDLE line detected
				Object *rxne; // [5:5] Read data register not empty
				Object *tc; // [6:6] Transmission complete
				Object *txe; // [7:7] Transmit data register empty
				Object *lbd; // [8:8] LIN break detection flag
				Object *cts; // [9:9] CTS flag
			} sr;

			// DR (Data register) bitfields.
			struct {
				Object *dr; // [0:8] Data value
			} dr;

			// BRR (Baud rate register) bitfields.
			struct {
				Object *div_fraction; // [0:3] Fraction of USARTDIV
				Object *div_mantissa; // [4:15] Mantissa of USARTDIV
			} brr;

			// CR1 (Control register 1) bitfields.
			struct {
				Object *sbk; // [0:0] Send break
				Object *rwu; // [1:1] Receiver wakeup
				Object *re; // [2:2] Receiver enable
				Object *te; // [3:3] Transmitter enable
				Object *idleie; // [4:4] IDLE interrupt enable
				Object *rxneie; // [5:5] RXNE interrupt enable
				Object *tcie; // [6:6] Transmission complete interrupt enable
				Object *txeie; // [7:7] TXE interrupt enable
				Object *peie; // [8:8] PE interrupt enable
				Object *ps; // [9:9] Parity selection
				Object *pce; // [10:10] Parity control enable
				Object *wake; // [11:11] Wakeup method
				Object *m; // [12:12] Word length
				Object *ue; // [13:13] USART enable
			} cr1;

			// CR2 (Control register 2) bitfields.
			struct {
				Object *add; // [0:3] Address of the USART node
				Object *lbdl; // [5:5] Lin break detection length
				Object *lbdie; // [6:6] LIN break detection interrupt enable
				Object *lbcl; // [8:8] Last bit clock pulse
				Object *cpha; // [9:9] Clock phase
				Object *cpol; // [10:10] Clock polarity
				Object *clken; // [11:11] Clock enable
				Object *stop; // [12:13] STOP bits
				Object *linen; // [14:14] LIN mode enable
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
			} cr3;

			// GTPR (Guard time and prescaler register) bitfields.
			struct {
				Object *psc; // [0:7] Prescaler value
				Object *gt; // [8:15] Guard time value
			} gtpr;
		} fld;
	} f1;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32USART1State;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_usart1_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32USART1State *state = STM32_USART1_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f1.reg.sr = cm_object_get_child_by_name(obj, "SR");
	state->f1.reg.dr = cm_object_get_child_by_name(obj, "DR");
	state->f1.reg.brr = cm_object_get_child_by_name(obj, "BRR");
	state->f1.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
	state->f1.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
	state->f1.reg.cr3 = cm_object_get_child_by_name(obj, "CR3");
	state->f1.reg.gtpr = cm_object_get_child_by_name(obj, "GTPR");

	// SR bitfields.
	state->f1.fld.sr.pe = cm_object_get_child_by_name(state->f1.reg.sr, "PE");
	state->f1.fld.sr.fe = cm_object_get_child_by_name(state->f1.reg.sr, "FE");
	state->f1.fld.sr.ne = cm_object_get_child_by_name(state->f1.reg.sr, "NE");
	state->f1.fld.sr.ore = cm_object_get_child_by_name(state->f1.reg.sr, "ORE");
	state->f1.fld.sr.idle = cm_object_get_child_by_name(state->f1.reg.sr, "IDLE");
	state->f1.fld.sr.rxne = cm_object_get_child_by_name(state->f1.reg.sr, "RXNE");
	state->f1.fld.sr.tc = cm_object_get_child_by_name(state->f1.reg.sr, "TC");
	state->f1.fld.sr.txe = cm_object_get_child_by_name(state->f1.reg.sr, "TXE");
	state->f1.fld.sr.lbd = cm_object_get_child_by_name(state->f1.reg.sr, "LBD");
	state->f1.fld.sr.cts = cm_object_get_child_by_name(state->f1.reg.sr, "CTS");

	// DR bitfields.
	state->f1.fld.dr.dr = cm_object_get_child_by_name(state->f1.reg.dr, "DR");

	// BRR bitfields.
	state->f1.fld.brr.div_fraction = cm_object_get_child_by_name(state->f1.reg.brr, "DIV_Fraction");
	state->f1.fld.brr.div_mantissa = cm_object_get_child_by_name(state->f1.reg.brr, "DIV_Mantissa");

	// CR1 bitfields.
	state->f1.fld.cr1.sbk = cm_object_get_child_by_name(state->f1.reg.cr1, "SBK");
	state->f1.fld.cr1.rwu = cm_object_get_child_by_name(state->f1.reg.cr1, "RWU");
	state->f1.fld.cr1.re = cm_object_get_child_by_name(state->f1.reg.cr1, "RE");
	state->f1.fld.cr1.te = cm_object_get_child_by_name(state->f1.reg.cr1, "TE");
	state->f1.fld.cr1.idleie = cm_object_get_child_by_name(state->f1.reg.cr1, "IDLEIE");
	state->f1.fld.cr1.rxneie = cm_object_get_child_by_name(state->f1.reg.cr1, "RXNEIE");
	state->f1.fld.cr1.tcie = cm_object_get_child_by_name(state->f1.reg.cr1, "TCIE");
	state->f1.fld.cr1.txeie = cm_object_get_child_by_name(state->f1.reg.cr1, "TXEIE");
	state->f1.fld.cr1.peie = cm_object_get_child_by_name(state->f1.reg.cr1, "PEIE");
	state->f1.fld.cr1.ps = cm_object_get_child_by_name(state->f1.reg.cr1, "PS");
	state->f1.fld.cr1.pce = cm_object_get_child_by_name(state->f1.reg.cr1, "PCE");
	state->f1.fld.cr1.wake = cm_object_get_child_by_name(state->f1.reg.cr1, "WAKE");
	state->f1.fld.cr1.m = cm_object_get_child_by_name(state->f1.reg.cr1, "M");
	state->f1.fld.cr1.ue = cm_object_get_child_by_name(state->f1.reg.cr1, "UE");

	// CR2 bitfields.
	state->f1.fld.cr2.add = cm_object_get_child_by_name(state->f1.reg.cr2, "ADD");
	state->f1.fld.cr2.lbdl = cm_object_get_child_by_name(state->f1.reg.cr2, "LBDL");
	state->f1.fld.cr2.lbdie = cm_object_get_child_by_name(state->f1.reg.cr2, "LBDIE");
	state->f1.fld.cr2.lbcl = cm_object_get_child_by_name(state->f1.reg.cr2, "LBCL");
	state->f1.fld.cr2.cpha = cm_object_get_child_by_name(state->f1.reg.cr2, "CPHA");
	state->f1.fld.cr2.cpol = cm_object_get_child_by_name(state->f1.reg.cr2, "CPOL");
	state->f1.fld.cr2.clken = cm_object_get_child_by_name(state->f1.reg.cr2, "CLKEN");
	state->f1.fld.cr2.stop = cm_object_get_child_by_name(state->f1.reg.cr2, "STOP");
	state->f1.fld.cr2.linen = cm_object_get_child_by_name(state->f1.reg.cr2, "LINEN");

	// CR3 bitfields.
	state->f1.fld.cr3.eie = cm_object_get_child_by_name(state->f1.reg.cr3, "EIE");
	state->f1.fld.cr3.iren = cm_object_get_child_by_name(state->f1.reg.cr3, "IREN");
	state->f1.fld.cr3.irlp = cm_object_get_child_by_name(state->f1.reg.cr3, "IRLP");
	state->f1.fld.cr3.hdsel = cm_object_get_child_by_name(state->f1.reg.cr3, "HDSEL");
	state->f1.fld.cr3.nack = cm_object_get_child_by_name(state->f1.reg.cr3, "NACK");
	state->f1.fld.cr3.scen = cm_object_get_child_by_name(state->f1.reg.cr3, "SCEN");
	state->f1.fld.cr3.dmar = cm_object_get_child_by_name(state->f1.reg.cr3, "DMAR");
	state->f1.fld.cr3.dmat = cm_object_get_child_by_name(state->f1.reg.cr3, "DMAT");
	state->f1.fld.cr3.rtse = cm_object_get_child_by_name(state->f1.reg.cr3, "RTSE");
	state->f1.fld.cr3.ctse = cm_object_get_child_by_name(state->f1.reg.cr3, "CTSE");
	state->f1.fld.cr3.ctsie = cm_object_get_child_by_name(state->f1.reg.cr3, "CTSIE");

	// GTPR bitfields.
	state->f1.fld.gtpr.psc = cm_object_get_child_by_name(state->f1.reg.gtpr, "PSC");
	state->f1.fld.gtpr.gt = cm_object_get_child_by_name(state->f1.reg.gtpr, "GT");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ADC1 (Analog to digital converter) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F1 ADC1 (Analog to digital converter) registers.
		struct {
			Object *sr; // 0x0 Status register
			Object *cr1; // 0x4 Control register 1
			Object *cr2; // 0x8 Control register 2
			Object *smpr1; // 0xC Sample time register 1
			Object *smpr2; // 0x10 Sample time register 2
			Object *jofr1; // 0x14 Injected channel data offset register x
			Object *jofr2; // 0x18 Injected channel data offset register x
			Object *jofr3; // 0x1C Injected channel data offset register x
			Object *jofr4; // 0x20 Injected channel data offset register x
			Object *htr; // 0x24 Watchdog higher threshold register
			Object *ltr; // 0x28 Watchdog lower threshold register
			Object *sqr1; // 0x2C Regular sequence register 1
			Object *sqr2; // 0x30 Regular sequence register 2
			Object *sqr3; // 0x34 Regular sequence register 3
			Object *jsqr; // 0x38 Injected sequence register
			Object *jdr1; // 0x3C Injected data register x
			Object *jdr2; // 0x40 Injected data register x
			Object *jdr3; // 0x44 Injected data register x
			Object *jdr4; // 0x48 Injected data register x
			Object *dr; // 0x4C Regular data register
		} reg;

		struct {

			// SR (Status register) bitfields.
			struct {
				Object *awd; // [0:0] Analog watchdog flag
				Object *eoc; // [1:1] Regular channel end of conversion
				Object *jeoc; // [2:2] Injected channel end of conversion
				Object *jstrt; // [3:3] Injected channel start flag
				Object *strt; // [4:4] Regular channel start flag
			} sr;

			// CR1 (Control register 1) bitfields.
			struct {
				Object *awdch; // [0:4] Analog watchdog channel select bits
				Object *eocie; // [5:5] Interrupt enable for EOC
				Object *awdie; // [6:6] Analog watchdog interrupt enable
				Object *jeocie; // [7:7] Interrupt enable for injected channels
				Object *scan; // [8:8] Scan mode
				Object *awdsgl; // [9:9] Enable the watchdog on a single channel in scan mode
				Object *jauto; // [10:10] Automatic injected group conversion
				Object *discen; // [11:11] Discontinuous mode on regular channels
				Object *jdiscen; // [12:12] Discontinuous mode on injected channels
				Object *discnum; // [13:15] Discontinuous mode channel count
				Object *dualmod; // [16:19] Dual mode selection
				Object *jawden; // [22:22] Analog watchdog enable on injected channels
				Object *awden; // [23:23] Analog watchdog enable on regular channels
			} cr1;

			// CR2 (Control register 2) bitfields.
			struct {
				Object *adon; // [0:0] A/D converter ON / OFF
				Object *cont; // [1:1] Continuous conversion
				Object *cal; // [2:2] A/D calibration
				Object *rstcal; // [3:3] Reset calibration
				Object *dma; // [8:8] Direct memory access mode
				Object *align; // [11:11] Data alignment
				Object *jextsel; // [12:14] External event select for injected group
				Object *jexttrig; // [15:15] External trigger conversion mode for injected channels
				Object *extsel; // [17:19] External event select for regular group
				Object *exttrig; // [20:20] External trigger conversion mode for regular channels
				Object *jswstart; // [21:21] Start conversion of injected channels
				Object *swstart; // [22:22] Start conversion of regular channels
				Object *tsvrefe; // [23:23] Temperature sensor and VREFINT enable
			} cr2;

			// SMPR1 (Sample time register 1) bitfields.
			struct {
				Object *smp10; // [0:2] Channel 10 sample time selection
				Object *smp11; // [3:5] Channel 11 sample time selection
				Object *smp12; // [6:8] Channel 12 sample time selection
				Object *smp13; // [9:11] Channel 13 sample time selection
				Object *smp14; // [12:14] Channel 14 sample time selection
				Object *smp15; // [15:17] Channel 15 sample time selection
				Object *smp16; // [18:20] Channel 16 sample time selection
				Object *smp17; // [21:23] Channel 17 sample time selection
			} smpr1;

			// SMPR2 (Sample time register 2) bitfields.
			struct {
				Object *smp0; // [0:2] Channel 0 sample time selection
				Object *smp1; // [3:5] Channel 1 sample time selection
				Object *smp2; // [6:8] Channel 2 sample time selection
				Object *smp3; // [9:11] Channel 3 sample time selection
				Object *smp4; // [12:14] Channel 4 sample time selection
				Object *smp5; // [15:17] Channel 5 sample time selection
				Object *smp6; // [18:20] Channel 6 sample time selection
				Object *smp7; // [21:23] Channel 7 sample time selection
				Object *smp8; // [24:26] Channel 8 sample time selection
				Object *smp9; // [27:29] Channel 9 sample time selection
			} smpr2;

			// JOFR1 (Injected channel data offset register x) bitfields.
			struct {
				Object *joffset1; // [0:11] Data offset for injected channel x
			} jofr1;

			// JOFR2 (Injected channel data offset register x) bitfields.
			struct {
				Object *joffset2; // [0:11] Data offset for injected channel x
			} jofr2;

			// JOFR3 (Injected channel data offset register x) bitfields.
			struct {
				Object *joffset3; // [0:11] Data offset for injected channel x
			} jofr3;

			// JOFR4 (Injected channel data offset register x) bitfields.
			struct {
				Object *joffset4; // [0:11] Data offset for injected channel x
			} jofr4;

			// HTR (Watchdog higher threshold register) bitfields.
			struct {
				Object *ht; // [0:11] Analog watchdog higher threshold
			} htr;

			// LTR (Watchdog lower threshold register) bitfields.
			struct {
				Object *lt; // [0:11] Analog watchdog lower threshold
			} ltr;

			// SQR1 (Regular sequence register 1) bitfields.
			struct {
				Object *sq13; // [0:4] 13th conversion in regular sequence
				Object *sq14; // [5:9] 14th conversion in regular sequence
				Object *sq15; // [10:14] 15th conversion in regular sequence
				Object *sq16; // [15:19] 16th conversion in regular sequence
				Object *l; // [20:23] Regular channel sequence length
			} sqr1;

			// SQR2 (Regular sequence register 2) bitfields.
			struct {
				Object *sq7; // [0:4] 7th conversion in regular sequence
				Object *sq8; // [5:9] 8th conversion in regular sequence
				Object *sq9; // [10:14] 9th conversion in regular sequence
				Object *sq10; // [15:19] 10th conversion in regular sequence
				Object *sq11; // [20:24] 11th conversion in regular sequence
				Object *sq12; // [25:29] 12th conversion in regular sequence
			} sqr2;

			// SQR3 (Regular sequence register 3) bitfields.
			struct {
				Object *sq1; // [0:4] 1st conversion in regular sequence
				Object *sq2; // [5:9] 2nd conversion in regular sequence
				Object *sq3; // [10:14] 3rd conversion in regular sequence
				Object *sq4; // [15:19] 4th conversion in regular sequence
				Object *sq5; // [20:24] 5th conversion in regular sequence
				Object *sq6; // [25:29] 6th conversion in regular sequence
			} sqr3;

			// JSQR (Injected sequence register) bitfields.
			struct {
				Object *jsq1; // [0:4] 1st conversion in injected sequence
				Object *jsq2; // [5:9] 2nd conversion in injected sequence
				Object *jsq3; // [10:14] 3rd conversion in injected sequence
				Object *jsq4; // [15:19] 4th conversion in injected sequence
				Object *jl; // [20:21] Injected sequence length
			} jsqr;

			// JDR1 (Injected data register x) bitfields.
			struct {
				Object *jdata; // [0:15] Injected data
			} jdr1;

			// JDR2 (Injected data register x) bitfields.
			struct {
				Object *jdata; // [0:15] Injected data
			} jdr2;

			// JDR3 (Injected data register x) bitfields.
			struct {
				Object *jdata; // [0:15] Injected data
			} jdr3;

			// JDR4 (Injected data register x) bitfields.
			struct {
				Object *jdata; // [0:15] Injected data
			} jdr4;

			// DR (Regular data register) bitfields.
			struct {
				Object *data; // [0:15] Regular data
				Object *adc2data; // [16:31] ADC2 data
			} dr;
		} fld;
	} f1;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32ADC1State;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_adc1_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32ADC1State *state = STM32_ADC1_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f1.reg.sr = cm_object_get_child_by_name(obj, "SR");
	state->f1.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
	state->f1.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
	state->f1.reg.smpr1 = cm_object_get_child_by_name(obj, "SMPR1");
	state->f1.reg.smpr2 = cm_object_get_child_by_name(obj, "SMPR2");
	state->f1.reg.jofr1 = cm_object_get_child_by_name(obj, "JOFR1");
	state->f1.reg.jofr2 = cm_object_get_child_by_name(obj, "JOFR2");
	state->f1.reg.jofr3 = cm_object_get_child_by_name(obj, "JOFR3");
	state->f1.reg.jofr4 = cm_object_get_child_by_name(obj, "JOFR4");
	state->f1.reg.htr = cm_object_get_child_by_name(obj, "HTR");
	state->f1.reg.ltr = cm_object_get_child_by_name(obj, "LTR");
	state->f1.reg.sqr1 = cm_object_get_child_by_name(obj, "SQR1");
	state->f1.reg.sqr2 = cm_object_get_child_by_name(obj, "SQR2");
	state->f1.reg.sqr3 = cm_object_get_child_by_name(obj, "SQR3");
	state->f1.reg.jsqr = cm_object_get_child_by_name(obj, "JSQR");
	state->f1.reg.jdr1 = cm_object_get_child_by_name(obj, "JDR1");
	state->f1.reg.jdr2 = cm_object_get_child_by_name(obj, "JDR2");
	state->f1.reg.jdr3 = cm_object_get_child_by_name(obj, "JDR3");
	state->f1.reg.jdr4 = cm_object_get_child_by_name(obj, "JDR4");
	state->f1.reg.dr = cm_object_get_child_by_name(obj, "DR");

	// SR bitfields.
	state->f1.fld.sr.awd = cm_object_get_child_by_name(state->f1.reg.sr, "AWD");
	state->f1.fld.sr.eoc = cm_object_get_child_by_name(state->f1.reg.sr, "EOC");
	state->f1.fld.sr.jeoc = cm_object_get_child_by_name(state->f1.reg.sr, "JEOC");
	state->f1.fld.sr.jstrt = cm_object_get_child_by_name(state->f1.reg.sr, "JSTRT");
	state->f1.fld.sr.strt = cm_object_get_child_by_name(state->f1.reg.sr, "STRT");

	// CR1 bitfields.
	state->f1.fld.cr1.awdch = cm_object_get_child_by_name(state->f1.reg.cr1, "AWDCH");
	state->f1.fld.cr1.eocie = cm_object_get_child_by_name(state->f1.reg.cr1, "EOCIE");
	state->f1.fld.cr1.awdie = cm_object_get_child_by_name(state->f1.reg.cr1, "AWDIE");
	state->f1.fld.cr1.jeocie = cm_object_get_child_by_name(state->f1.reg.cr1, "JEOCIE");
	state->f1.fld.cr1.scan = cm_object_get_child_by_name(state->f1.reg.cr1, "SCAN");
	state->f1.fld.cr1.awdsgl = cm_object_get_child_by_name(state->f1.reg.cr1, "AWDSGL");
	state->f1.fld.cr1.jauto = cm_object_get_child_by_name(state->f1.reg.cr1, "JAUTO");
	state->f1.fld.cr1.discen = cm_object_get_child_by_name(state->f1.reg.cr1, "DISCEN");
	state->f1.fld.cr1.jdiscen = cm_object_get_child_by_name(state->f1.reg.cr1, "JDISCEN");
	state->f1.fld.cr1.discnum = cm_object_get_child_by_name(state->f1.reg.cr1, "DISCNUM");
	state->f1.fld.cr1.dualmod = cm_object_get_child_by_name(state->f1.reg.cr1, "DUALMOD");
	state->f1.fld.cr1.jawden = cm_object_get_child_by_name(state->f1.reg.cr1, "JAWDEN");
	state->f1.fld.cr1.awden = cm_object_get_child_by_name(state->f1.reg.cr1, "AWDEN");

	// CR2 bitfields.
	state->f1.fld.cr2.adon = cm_object_get_child_by_name(state->f1.reg.cr2, "ADON");
	state->f1.fld.cr2.cont = cm_object_get_child_by_name(state->f1.reg.cr2, "CONT");
	state->f1.fld.cr2.cal = cm_object_get_child_by_name(state->f1.reg.cr2, "CAL");
	state->f1.fld.cr2.rstcal = cm_object_get_child_by_name(state->f1.reg.cr2, "RSTCAL");
	state->f1.fld.cr2.dma = cm_object_get_child_by_name(state->f1.reg.cr2, "DMA");
	state->f1.fld.cr2.align = cm_object_get_child_by_name(state->f1.reg.cr2, "ALIGN");
	state->f1.fld.cr2.jextsel = cm_object_get_child_by_name(state->f1.reg.cr2, "JEXTSEL");
	state->f1.fld.cr2.jexttrig = cm_object_get_child_by_name(state->f1.reg.cr2, "JEXTTRIG");
	state->f1.fld.cr2.extsel = cm_object_get_child_by_name(state->f1.reg.cr2, "EXTSEL");
	state->f1.fld.cr2.exttrig = cm_object_get_child_by_name(state->f1.reg.cr2, "EXTTRIG");
	state->f1.fld.cr2.jswstart = cm_object_get_child_by_name(state->f1.reg.cr2, "JSWSTART");
	state->f1.fld.cr2.swstart = cm_object_get_child_by_name(state->f1.reg.cr2, "SWSTART");
	state->f1.fld.cr2.tsvrefe = cm_object_get_child_by_name(state->f1.reg.cr2, "TSVREFE");

	// SMPR1 bitfields.
	state->f1.fld.smpr1.smp10 = cm_object_get_child_by_name(state->f1.reg.smpr1, "SMP10");
	state->f1.fld.smpr1.smp11 = cm_object_get_child_by_name(state->f1.reg.smpr1, "SMP11");
	state->f1.fld.smpr1.smp12 = cm_object_get_child_by_name(state->f1.reg.smpr1, "SMP12");
	state->f1.fld.smpr1.smp13 = cm_object_get_child_by_name(state->f1.reg.smpr1, "SMP13");
	state->f1.fld.smpr1.smp14 = cm_object_get_child_by_name(state->f1.reg.smpr1, "SMP14");
	state->f1.fld.smpr1.smp15 = cm_object_get_child_by_name(state->f1.reg.smpr1, "SMP15");
	state->f1.fld.smpr1.smp16 = cm_object_get_child_by_name(state->f1.reg.smpr1, "SMP16");
	state->f1.fld.smpr1.smp17 = cm_object_get_child_by_name(state->f1.reg.smpr1, "SMP17");

	// SMPR2 bitfields.
	state->f1.fld.smpr2.smp0 = cm_object_get_child_by_name(state->f1.reg.smpr2, "SMP0");
	state->f1.fld.smpr2.smp1 = cm_object_get_child_by_name(state->f1.reg.smpr2, "SMP1");
	state->f1.fld.smpr2.smp2 = cm_object_get_child_by_name(state->f1.reg.smpr2, "SMP2");
	state->f1.fld.smpr2.smp3 = cm_object_get_child_by_name(state->f1.reg.smpr2, "SMP3");
	state->f1.fld.smpr2.smp4 = cm_object_get_child_by_name(state->f1.reg.smpr2, "SMP4");
	state->f1.fld.smpr2.smp5 = cm_object_get_child_by_name(state->f1.reg.smpr2, "SMP5");
	state->f1.fld.smpr2.smp6 = cm_object_get_child_by_name(state->f1.reg.smpr2, "SMP6");
	state->f1.fld.smpr2.smp7 = cm_object_get_child_by_name(state->f1.reg.smpr2, "SMP7");
	state->f1.fld.smpr2.smp8 = cm_object_get_child_by_name(state->f1.reg.smpr2, "SMP8");
	state->f1.fld.smpr2.smp9 = cm_object_get_child_by_name(state->f1.reg.smpr2, "SMP9");

	// JOFR1 bitfields.
	state->f1.fld.jofr1.joffset1 = cm_object_get_child_by_name(state->f1.reg.jofr1, "JOFFSET1");

	// JOFR2 bitfields.
	state->f1.fld.jofr2.joffset2 = cm_object_get_child_by_name(state->f1.reg.jofr2, "JOFFSET2");

	// JOFR3 bitfields.
	state->f1.fld.jofr3.joffset3 = cm_object_get_child_by_name(state->f1.reg.jofr3, "JOFFSET3");

	// JOFR4 bitfields.
	state->f1.fld.jofr4.joffset4 = cm_object_get_child_by_name(state->f1.reg.jofr4, "JOFFSET4");

	// HTR bitfields.
	state->f1.fld.htr.ht = cm_object_get_child_by_name(state->f1.reg.htr, "HT");

	// LTR bitfields.
	state->f1.fld.ltr.lt = cm_object_get_child_by_name(state->f1.reg.ltr, "LT");

	// SQR1 bitfields.
	state->f1.fld.sqr1.sq13 = cm_object_get_child_by_name(state->f1.reg.sqr1, "SQ13");
	state->f1.fld.sqr1.sq14 = cm_object_get_child_by_name(state->f1.reg.sqr1, "SQ14");
	state->f1.fld.sqr1.sq15 = cm_object_get_child_by_name(state->f1.reg.sqr1, "SQ15");
	state->f1.fld.sqr1.sq16 = cm_object_get_child_by_name(state->f1.reg.sqr1, "SQ16");
	state->f1.fld.sqr1.l = cm_object_get_child_by_name(state->f1.reg.sqr1, "L");

	// SQR2 bitfields.
	state->f1.fld.sqr2.sq7 = cm_object_get_child_by_name(state->f1.reg.sqr2, "SQ7");
	state->f1.fld.sqr2.sq8 = cm_object_get_child_by_name(state->f1.reg.sqr2, "SQ8");
	state->f1.fld.sqr2.sq9 = cm_object_get_child_by_name(state->f1.reg.sqr2, "SQ9");
	state->f1.fld.sqr2.sq10 = cm_object_get_child_by_name(state->f1.reg.sqr2, "SQ10");
	state->f1.fld.sqr2.sq11 = cm_object_get_child_by_name(state->f1.reg.sqr2, "SQ11");
	state->f1.fld.sqr2.sq12 = cm_object_get_child_by_name(state->f1.reg.sqr2, "SQ12");

	// SQR3 bitfields.
	state->f1.fld.sqr3.sq1 = cm_object_get_child_by_name(state->f1.reg.sqr3, "SQ1");
	state->f1.fld.sqr3.sq2 = cm_object_get_child_by_name(state->f1.reg.sqr3, "SQ2");
	state->f1.fld.sqr3.sq3 = cm_object_get_child_by_name(state->f1.reg.sqr3, "SQ3");
	state->f1.fld.sqr3.sq4 = cm_object_get_child_by_name(state->f1.reg.sqr3, "SQ4");
	state->f1.fld.sqr3.sq5 = cm_object_get_child_by_name(state->f1.reg.sqr3, "SQ5");
	state->f1.fld.sqr3.sq6 = cm_object_get_child_by_name(state->f1.reg.sqr3, "SQ6");

	// JSQR bitfields.
	state->f1.fld.jsqr.jsq1 = cm_object_get_child_by_name(state->f1.reg.jsqr, "JSQ1");
	state->f1.fld.jsqr.jsq2 = cm_object_get_child_by_name(state->f1.reg.jsqr, "JSQ2");
	state->f1.fld.jsqr.jsq3 = cm_object_get_child_by_name(state->f1.reg.jsqr, "JSQ3");
	state->f1.fld.jsqr.jsq4 = cm_object_get_child_by_name(state->f1.reg.jsqr, "JSQ4");
	state->f1.fld.jsqr.jl = cm_object_get_child_by_name(state->f1.reg.jsqr, "JL");

	// JDR1 bitfields.
	state->f1.fld.jdr1.jdata = cm_object_get_child_by_name(state->f1.reg.jdr1, "JDATA");

	// JDR2 bitfields.
	state->f1.fld.jdr2.jdata = cm_object_get_child_by_name(state->f1.reg.jdr2, "JDATA");

	// JDR3 bitfields.
	state->f1.fld.jdr3.jdata = cm_object_get_child_by_name(state->f1.reg.jdr3, "JDATA");

	// JDR4 bitfields.
	state->f1.fld.jdr4.jdata = cm_object_get_child_by_name(state->f1.reg.jdr4, "JDATA");

	// DR bitfields.
	state->f1.fld.dr.data = cm_object_get_child_by_name(state->f1.reg.dr, "DATA");
	state->f1.fld.dr.adc2data = cm_object_get_child_by_name(state->f1.reg.dr, "ADC2DATA");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ADC2 (Analog to digital converter) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F1 ADC2 (Analog to digital converter) registers.
		struct {
			Object *sr; // 0x0 Status register
			Object *cr1; // 0x4 Control register 1
			Object *cr2; // 0x8 Control register 2
			Object *smpr1; // 0xC Sample time register 1
			Object *smpr2; // 0x10 Sample time register 2
			Object *jofr1; // 0x14 Injected channel data offset register x
			Object *jofr2; // 0x18 Injected channel data offset register x
			Object *jofr3; // 0x1C Injected channel data offset register x
			Object *jofr4; // 0x20 Injected channel data offset register x
			Object *htr; // 0x24 Watchdog higher threshold register
			Object *ltr; // 0x28 Watchdog lower threshold register
			Object *sqr1; // 0x2C Regular sequence register 1
			Object *sqr2; // 0x30 Regular sequence register 2
			Object *sqr3; // 0x34 Regular sequence register 3
			Object *jsqr; // 0x38 Injected sequence register
			Object *jdr1; // 0x3C Injected data register x
			Object *jdr2; // 0x40 Injected data register x
			Object *jdr3; // 0x44 Injected data register x
			Object *jdr4; // 0x48 Injected data register x
			Object *dr; // 0x4C Regular data register
		} reg;

		struct {

			// SR (Status register) bitfields.
			struct {
				Object *awd; // [0:0] Analog watchdog flag
				Object *eoc; // [1:1] Regular channel end of conversion
				Object *jeoc; // [2:2] Injected channel end of conversion
				Object *jstrt; // [3:3] Injected channel start flag
				Object *strt; // [4:4] Regular channel start flag
			} sr;

			// CR1 (Control register 1) bitfields.
			struct {
				Object *awdch; // [0:4] Analog watchdog channel select bits
				Object *eocie; // [5:5] Interrupt enable for EOC
				Object *awdie; // [6:6] Analog watchdog interrupt enable
				Object *jeocie; // [7:7] Interrupt enable for injected channels
				Object *scan; // [8:8] Scan mode
				Object *awdsgl; // [9:9] Enable the watchdog on a single channel in scan mode
				Object *jauto; // [10:10] Automatic injected group conversion
				Object *discen; // [11:11] Discontinuous mode on regular channels
				Object *jdiscen; // [12:12] Discontinuous mode on injected channels
				Object *discnum; // [13:15] Discontinuous mode channel count
				Object *jawden; // [22:22] Analog watchdog enable on injected channels
				Object *awden; // [23:23] Analog watchdog enable on regular channels
			} cr1;

			// CR2 (Control register 2) bitfields.
			struct {
				Object *adon; // [0:0] A/D converter ON / OFF
				Object *cont; // [1:1] Continuous conversion
				Object *cal; // [2:2] A/D calibration
				Object *rstcal; // [3:3] Reset calibration
				Object *dma; // [8:8] Direct memory access mode
				Object *align; // [11:11] Data alignment
				Object *jextsel; // [12:14] External event select for injected group
				Object *jexttrig; // [15:15] External trigger conversion mode for injected channels
				Object *extsel; // [17:19] External event select for regular group
				Object *exttrig; // [20:20] External trigger conversion mode for regular channels
				Object *jswstart; // [21:21] Start conversion of injected channels
				Object *swstart; // [22:22] Start conversion of regular channels
				Object *tsvrefe; // [23:23] Temperature sensor and VREFINT enable
			} cr2;

			// SMPR1 (Sample time register 1) bitfields.
			struct {
				Object *smp10; // [0:2] Channel 10 sample time selection
				Object *smp11; // [3:5] Channel 11 sample time selection
				Object *smp12; // [6:8] Channel 12 sample time selection
				Object *smp13; // [9:11] Channel 13 sample time selection
				Object *smp14; // [12:14] Channel 14 sample time selection
				Object *smp15; // [15:17] Channel 15 sample time selection
				Object *smp16; // [18:20] Channel 16 sample time selection
				Object *smp17; // [21:23] Channel 17 sample time selection
			} smpr1;

			// SMPR2 (Sample time register 2) bitfields.
			struct {
				Object *smp0; // [0:2] Channel 0 sample time selection
				Object *smp1; // [3:5] Channel 1 sample time selection
				Object *smp2; // [6:8] Channel 2 sample time selection
				Object *smp3; // [9:11] Channel 3 sample time selection
				Object *smp4; // [12:14] Channel 4 sample time selection
				Object *smp5; // [15:17] Channel 5 sample time selection
				Object *smp6; // [18:20] Channel 6 sample time selection
				Object *smp7; // [21:23] Channel 7 sample time selection
				Object *smp8; // [24:26] Channel 8 sample time selection
				Object *smp9; // [27:29] Channel 9 sample time selection
			} smpr2;

			// JOFR1 (Injected channel data offset register x) bitfields.
			struct {
				Object *joffset1; // [0:11] Data offset for injected channel x
			} jofr1;

			// JOFR2 (Injected channel data offset register x) bitfields.
			struct {
				Object *joffset2; // [0:11] Data offset for injected channel x
			} jofr2;

			// JOFR3 (Injected channel data offset register x) bitfields.
			struct {
				Object *joffset3; // [0:11] Data offset for injected channel x
			} jofr3;

			// JOFR4 (Injected channel data offset register x) bitfields.
			struct {
				Object *joffset4; // [0:11] Data offset for injected channel x
			} jofr4;

			// HTR (Watchdog higher threshold register) bitfields.
			struct {
				Object *ht; // [0:11] Analog watchdog higher threshold
			} htr;

			// LTR (Watchdog lower threshold register) bitfields.
			struct {
				Object *lt; // [0:11] Analog watchdog lower threshold
			} ltr;

			// SQR1 (Regular sequence register 1) bitfields.
			struct {
				Object *sq13; // [0:4] 13th conversion in regular sequence
				Object *sq14; // [5:9] 14th conversion in regular sequence
				Object *sq15; // [10:14] 15th conversion in regular sequence
				Object *sq16; // [15:19] 16th conversion in regular sequence
				Object *l; // [20:23] Regular channel sequence length
			} sqr1;

			// SQR2 (Regular sequence register 2) bitfields.
			struct {
				Object *sq7; // [0:4] 7th conversion in regular sequence
				Object *sq8; // [5:9] 8th conversion in regular sequence
				Object *sq9; // [10:14] 9th conversion in regular sequence
				Object *sq10; // [15:19] 10th conversion in regular sequence
				Object *sq11; // [20:24] 11th conversion in regular sequence
				Object *sq12; // [25:29] 12th conversion in regular sequence
			} sqr2;

			// SQR3 (Regular sequence register 3) bitfields.
			struct {
				Object *sq1; // [0:4] 1st conversion in regular sequence
				Object *sq2; // [5:9] 2nd conversion in regular sequence
				Object *sq3; // [10:14] 3rd conversion in regular sequence
				Object *sq4; // [15:19] 4th conversion in regular sequence
				Object *sq5; // [20:24] 5th conversion in regular sequence
				Object *sq6; // [25:29] 6th conversion in regular sequence
			} sqr3;

			// JSQR (Injected sequence register) bitfields.
			struct {
				Object *jsq1; // [0:4] 1st conversion in injected sequence
				Object *jsq2; // [5:9] 2nd conversion in injected sequence
				Object *jsq3; // [10:14] 3rd conversion in injected sequence
				Object *jsq4; // [15:19] 4th conversion in injected sequence
				Object *jl; // [20:21] Injected sequence length
			} jsqr;

			// JDR1 (Injected data register x) bitfields.
			struct {
				Object *jdata; // [0:15] Injected data
			} jdr1;

			// JDR2 (Injected data register x) bitfields.
			struct {
				Object *jdata; // [0:15] Injected data
			} jdr2;

			// JDR3 (Injected data register x) bitfields.
			struct {
				Object *jdata; // [0:15] Injected data
			} jdr3;

			// JDR4 (Injected data register x) bitfields.
			struct {
				Object *jdata; // [0:15] Injected data
			} jdr4;

			// DR (Regular data register) bitfields.
			struct {
				Object *data; // [0:15] Regular data
			} dr;
		} fld;
	} f1;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32ADC2State;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_adc2_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32ADC2State *state = STM32_ADC2_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f1.reg.sr = cm_object_get_child_by_name(obj, "SR");
	state->f1.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
	state->f1.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
	state->f1.reg.smpr1 = cm_object_get_child_by_name(obj, "SMPR1");
	state->f1.reg.smpr2 = cm_object_get_child_by_name(obj, "SMPR2");
	state->f1.reg.jofr1 = cm_object_get_child_by_name(obj, "JOFR1");
	state->f1.reg.jofr2 = cm_object_get_child_by_name(obj, "JOFR2");
	state->f1.reg.jofr3 = cm_object_get_child_by_name(obj, "JOFR3");
	state->f1.reg.jofr4 = cm_object_get_child_by_name(obj, "JOFR4");
	state->f1.reg.htr = cm_object_get_child_by_name(obj, "HTR");
	state->f1.reg.ltr = cm_object_get_child_by_name(obj, "LTR");
	state->f1.reg.sqr1 = cm_object_get_child_by_name(obj, "SQR1");
	state->f1.reg.sqr2 = cm_object_get_child_by_name(obj, "SQR2");
	state->f1.reg.sqr3 = cm_object_get_child_by_name(obj, "SQR3");
	state->f1.reg.jsqr = cm_object_get_child_by_name(obj, "JSQR");
	state->f1.reg.jdr1 = cm_object_get_child_by_name(obj, "JDR1");
	state->f1.reg.jdr2 = cm_object_get_child_by_name(obj, "JDR2");
	state->f1.reg.jdr3 = cm_object_get_child_by_name(obj, "JDR3");
	state->f1.reg.jdr4 = cm_object_get_child_by_name(obj, "JDR4");
	state->f1.reg.dr = cm_object_get_child_by_name(obj, "DR");

	// SR bitfields.
	state->f1.fld.sr.awd = cm_object_get_child_by_name(state->f1.reg.sr, "AWD");
	state->f1.fld.sr.eoc = cm_object_get_child_by_name(state->f1.reg.sr, "EOC");
	state->f1.fld.sr.jeoc = cm_object_get_child_by_name(state->f1.reg.sr, "JEOC");
	state->f1.fld.sr.jstrt = cm_object_get_child_by_name(state->f1.reg.sr, "JSTRT");
	state->f1.fld.sr.strt = cm_object_get_child_by_name(state->f1.reg.sr, "STRT");

	// CR1 bitfields.
	state->f1.fld.cr1.awdch = cm_object_get_child_by_name(state->f1.reg.cr1, "AWDCH");
	state->f1.fld.cr1.eocie = cm_object_get_child_by_name(state->f1.reg.cr1, "EOCIE");
	state->f1.fld.cr1.awdie = cm_object_get_child_by_name(state->f1.reg.cr1, "AWDIE");
	state->f1.fld.cr1.jeocie = cm_object_get_child_by_name(state->f1.reg.cr1, "JEOCIE");
	state->f1.fld.cr1.scan = cm_object_get_child_by_name(state->f1.reg.cr1, "SCAN");
	state->f1.fld.cr1.awdsgl = cm_object_get_child_by_name(state->f1.reg.cr1, "AWDSGL");
	state->f1.fld.cr1.jauto = cm_object_get_child_by_name(state->f1.reg.cr1, "JAUTO");
	state->f1.fld.cr1.discen = cm_object_get_child_by_name(state->f1.reg.cr1, "DISCEN");
	state->f1.fld.cr1.jdiscen = cm_object_get_child_by_name(state->f1.reg.cr1, "JDISCEN");
	state->f1.fld.cr1.discnum = cm_object_get_child_by_name(state->f1.reg.cr1, "DISCNUM");
	state->f1.fld.cr1.jawden = cm_object_get_child_by_name(state->f1.reg.cr1, "JAWDEN");
	state->f1.fld.cr1.awden = cm_object_get_child_by_name(state->f1.reg.cr1, "AWDEN");

	// CR2 bitfields.
	state->f1.fld.cr2.adon = cm_object_get_child_by_name(state->f1.reg.cr2, "ADON");
	state->f1.fld.cr2.cont = cm_object_get_child_by_name(state->f1.reg.cr2, "CONT");
	state->f1.fld.cr2.cal = cm_object_get_child_by_name(state->f1.reg.cr2, "CAL");
	state->f1.fld.cr2.rstcal = cm_object_get_child_by_name(state->f1.reg.cr2, "RSTCAL");
	state->f1.fld.cr2.dma = cm_object_get_child_by_name(state->f1.reg.cr2, "DMA");
	state->f1.fld.cr2.align = cm_object_get_child_by_name(state->f1.reg.cr2, "ALIGN");
	state->f1.fld.cr2.jextsel = cm_object_get_child_by_name(state->f1.reg.cr2, "JEXTSEL");
	state->f1.fld.cr2.jexttrig = cm_object_get_child_by_name(state->f1.reg.cr2, "JEXTTRIG");
	state->f1.fld.cr2.extsel = cm_object_get_child_by_name(state->f1.reg.cr2, "EXTSEL");
	state->f1.fld.cr2.exttrig = cm_object_get_child_by_name(state->f1.reg.cr2, "EXTTRIG");
	state->f1.fld.cr2.jswstart = cm_object_get_child_by_name(state->f1.reg.cr2, "JSWSTART");
	state->f1.fld.cr2.swstart = cm_object_get_child_by_name(state->f1.reg.cr2, "SWSTART");
	state->f1.fld.cr2.tsvrefe = cm_object_get_child_by_name(state->f1.reg.cr2, "TSVREFE");

	// SMPR1 bitfields.
	state->f1.fld.smpr1.smp10 = cm_object_get_child_by_name(state->f1.reg.smpr1, "SMP10");
	state->f1.fld.smpr1.smp11 = cm_object_get_child_by_name(state->f1.reg.smpr1, "SMP11");
	state->f1.fld.smpr1.smp12 = cm_object_get_child_by_name(state->f1.reg.smpr1, "SMP12");
	state->f1.fld.smpr1.smp13 = cm_object_get_child_by_name(state->f1.reg.smpr1, "SMP13");
	state->f1.fld.smpr1.smp14 = cm_object_get_child_by_name(state->f1.reg.smpr1, "SMP14");
	state->f1.fld.smpr1.smp15 = cm_object_get_child_by_name(state->f1.reg.smpr1, "SMP15");
	state->f1.fld.smpr1.smp16 = cm_object_get_child_by_name(state->f1.reg.smpr1, "SMP16");
	state->f1.fld.smpr1.smp17 = cm_object_get_child_by_name(state->f1.reg.smpr1, "SMP17");

	// SMPR2 bitfields.
	state->f1.fld.smpr2.smp0 = cm_object_get_child_by_name(state->f1.reg.smpr2, "SMP0");
	state->f1.fld.smpr2.smp1 = cm_object_get_child_by_name(state->f1.reg.smpr2, "SMP1");
	state->f1.fld.smpr2.smp2 = cm_object_get_child_by_name(state->f1.reg.smpr2, "SMP2");
	state->f1.fld.smpr2.smp3 = cm_object_get_child_by_name(state->f1.reg.smpr2, "SMP3");
	state->f1.fld.smpr2.smp4 = cm_object_get_child_by_name(state->f1.reg.smpr2, "SMP4");
	state->f1.fld.smpr2.smp5 = cm_object_get_child_by_name(state->f1.reg.smpr2, "SMP5");
	state->f1.fld.smpr2.smp6 = cm_object_get_child_by_name(state->f1.reg.smpr2, "SMP6");
	state->f1.fld.smpr2.smp7 = cm_object_get_child_by_name(state->f1.reg.smpr2, "SMP7");
	state->f1.fld.smpr2.smp8 = cm_object_get_child_by_name(state->f1.reg.smpr2, "SMP8");
	state->f1.fld.smpr2.smp9 = cm_object_get_child_by_name(state->f1.reg.smpr2, "SMP9");

	// JOFR1 bitfields.
	state->f1.fld.jofr1.joffset1 = cm_object_get_child_by_name(state->f1.reg.jofr1, "JOFFSET1");

	// JOFR2 bitfields.
	state->f1.fld.jofr2.joffset2 = cm_object_get_child_by_name(state->f1.reg.jofr2, "JOFFSET2");

	// JOFR3 bitfields.
	state->f1.fld.jofr3.joffset3 = cm_object_get_child_by_name(state->f1.reg.jofr3, "JOFFSET3");

	// JOFR4 bitfields.
	state->f1.fld.jofr4.joffset4 = cm_object_get_child_by_name(state->f1.reg.jofr4, "JOFFSET4");

	// HTR bitfields.
	state->f1.fld.htr.ht = cm_object_get_child_by_name(state->f1.reg.htr, "HT");

	// LTR bitfields.
	state->f1.fld.ltr.lt = cm_object_get_child_by_name(state->f1.reg.ltr, "LT");

	// SQR1 bitfields.
	state->f1.fld.sqr1.sq13 = cm_object_get_child_by_name(state->f1.reg.sqr1, "SQ13");
	state->f1.fld.sqr1.sq14 = cm_object_get_child_by_name(state->f1.reg.sqr1, "SQ14");
	state->f1.fld.sqr1.sq15 = cm_object_get_child_by_name(state->f1.reg.sqr1, "SQ15");
	state->f1.fld.sqr1.sq16 = cm_object_get_child_by_name(state->f1.reg.sqr1, "SQ16");
	state->f1.fld.sqr1.l = cm_object_get_child_by_name(state->f1.reg.sqr1, "L");

	// SQR2 bitfields.
	state->f1.fld.sqr2.sq7 = cm_object_get_child_by_name(state->f1.reg.sqr2, "SQ7");
	state->f1.fld.sqr2.sq8 = cm_object_get_child_by_name(state->f1.reg.sqr2, "SQ8");
	state->f1.fld.sqr2.sq9 = cm_object_get_child_by_name(state->f1.reg.sqr2, "SQ9");
	state->f1.fld.sqr2.sq10 = cm_object_get_child_by_name(state->f1.reg.sqr2, "SQ10");
	state->f1.fld.sqr2.sq11 = cm_object_get_child_by_name(state->f1.reg.sqr2, "SQ11");
	state->f1.fld.sqr2.sq12 = cm_object_get_child_by_name(state->f1.reg.sqr2, "SQ12");

	// SQR3 bitfields.
	state->f1.fld.sqr3.sq1 = cm_object_get_child_by_name(state->f1.reg.sqr3, "SQ1");
	state->f1.fld.sqr3.sq2 = cm_object_get_child_by_name(state->f1.reg.sqr3, "SQ2");
	state->f1.fld.sqr3.sq3 = cm_object_get_child_by_name(state->f1.reg.sqr3, "SQ3");
	state->f1.fld.sqr3.sq4 = cm_object_get_child_by_name(state->f1.reg.sqr3, "SQ4");
	state->f1.fld.sqr3.sq5 = cm_object_get_child_by_name(state->f1.reg.sqr3, "SQ5");
	state->f1.fld.sqr3.sq6 = cm_object_get_child_by_name(state->f1.reg.sqr3, "SQ6");

	// JSQR bitfields.
	state->f1.fld.jsqr.jsq1 = cm_object_get_child_by_name(state->f1.reg.jsqr, "JSQ1");
	state->f1.fld.jsqr.jsq2 = cm_object_get_child_by_name(state->f1.reg.jsqr, "JSQ2");
	state->f1.fld.jsqr.jsq3 = cm_object_get_child_by_name(state->f1.reg.jsqr, "JSQ3");
	state->f1.fld.jsqr.jsq4 = cm_object_get_child_by_name(state->f1.reg.jsqr, "JSQ4");
	state->f1.fld.jsqr.jl = cm_object_get_child_by_name(state->f1.reg.jsqr, "JL");

	// JDR1 bitfields.
	state->f1.fld.jdr1.jdata = cm_object_get_child_by_name(state->f1.reg.jdr1, "JDATA");

	// JDR2 bitfields.
	state->f1.fld.jdr2.jdata = cm_object_get_child_by_name(state->f1.reg.jdr2, "JDATA");

	// JDR3 bitfields.
	state->f1.fld.jdr3.jdata = cm_object_get_child_by_name(state->f1.reg.jdr3, "JDATA");

	// JDR4 bitfields.
	state->f1.fld.jdr4.jdata = cm_object_get_child_by_name(state->f1.reg.jdr4, "JDATA");

	// DR bitfields.
	state->f1.fld.dr.data = cm_object_get_child_by_name(state->f1.reg.dr, "DATA");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// CAN (Controller area network) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F1 CAN (Controller area network) registers.
		struct {
			Object *can_mcr; // 0x0 CAN_MCR
			Object *can_msr; // 0x4 CAN_MSR
			Object *can_tsr; // 0x8 CAN_TSR
			Object *can_rf0r; // 0xC CAN_RF0R
			Object *can_rf1r; // 0x10 CAN_RF1R
			Object *can_ier; // 0x14 CAN_IER
			Object *can_esr; // 0x18 CAN_ESR
			Object *can_btr; // 0x1C CAN_BTR
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

			// CAN_BTR (CAN_BTR) bitfields.
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
		} fld;
	} f1;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32CANState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_can_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32CANState *state = STM32_CAN_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f1.reg.can_mcr = cm_object_get_child_by_name(obj, "CAN_MCR");
	state->f1.reg.can_msr = cm_object_get_child_by_name(obj, "CAN_MSR");
	state->f1.reg.can_tsr = cm_object_get_child_by_name(obj, "CAN_TSR");
	state->f1.reg.can_rf0r = cm_object_get_child_by_name(obj, "CAN_RF0R");
	state->f1.reg.can_rf1r = cm_object_get_child_by_name(obj, "CAN_RF1R");
	state->f1.reg.can_ier = cm_object_get_child_by_name(obj, "CAN_IER");
	state->f1.reg.can_esr = cm_object_get_child_by_name(obj, "CAN_ESR");
	state->f1.reg.can_btr = cm_object_get_child_by_name(obj, "CAN_BTR");
	state->f1.reg.can_ti0r = cm_object_get_child_by_name(obj, "CAN_TI0R");
	state->f1.reg.can_tdt0r = cm_object_get_child_by_name(obj, "CAN_TDT0R");
	state->f1.reg.can_tdl0r = cm_object_get_child_by_name(obj, "CAN_TDL0R");
	state->f1.reg.can_tdh0r = cm_object_get_child_by_name(obj, "CAN_TDH0R");
	state->f1.reg.can_ti1r = cm_object_get_child_by_name(obj, "CAN_TI1R");
	state->f1.reg.can_tdt1r = cm_object_get_child_by_name(obj, "CAN_TDT1R");
	state->f1.reg.can_tdl1r = cm_object_get_child_by_name(obj, "CAN_TDL1R");
	state->f1.reg.can_tdh1r = cm_object_get_child_by_name(obj, "CAN_TDH1R");
	state->f1.reg.can_ti2r = cm_object_get_child_by_name(obj, "CAN_TI2R");
	state->f1.reg.can_tdt2r = cm_object_get_child_by_name(obj, "CAN_TDT2R");
	state->f1.reg.can_tdl2r = cm_object_get_child_by_name(obj, "CAN_TDL2R");
	state->f1.reg.can_tdh2r = cm_object_get_child_by_name(obj, "CAN_TDH2R");
	state->f1.reg.can_ri0r = cm_object_get_child_by_name(obj, "CAN_RI0R");
	state->f1.reg.can_rdt0r = cm_object_get_child_by_name(obj, "CAN_RDT0R");
	state->f1.reg.can_rdl0r = cm_object_get_child_by_name(obj, "CAN_RDL0R");
	state->f1.reg.can_rdh0r = cm_object_get_child_by_name(obj, "CAN_RDH0R");
	state->f1.reg.can_ri1r = cm_object_get_child_by_name(obj, "CAN_RI1R");
	state->f1.reg.can_rdt1r = cm_object_get_child_by_name(obj, "CAN_RDT1R");
	state->f1.reg.can_rdl1r = cm_object_get_child_by_name(obj, "CAN_RDL1R");
	state->f1.reg.can_rdh1r = cm_object_get_child_by_name(obj, "CAN_RDH1R");
	state->f1.reg.can_fmr = cm_object_get_child_by_name(obj, "CAN_FMR");
	state->f1.reg.can_fm1r = cm_object_get_child_by_name(obj, "CAN_FM1R");
	state->f1.reg.can_fs1r = cm_object_get_child_by_name(obj, "CAN_FS1R");
	state->f1.reg.can_ffa1r = cm_object_get_child_by_name(obj, "CAN_FFA1R");
	state->f1.reg.can_fa1r = cm_object_get_child_by_name(obj, "CAN_FA1R");
	state->f1.reg.f0r1 = cm_object_get_child_by_name(obj, "F0R1");
	state->f1.reg.f0r2 = cm_object_get_child_by_name(obj, "F0R2");
	state->f1.reg.f1r1 = cm_object_get_child_by_name(obj, "F1R1");
	state->f1.reg.f1r2 = cm_object_get_child_by_name(obj, "F1R2");
	state->f1.reg.f2r1 = cm_object_get_child_by_name(obj, "F2R1");
	state->f1.reg.f2r2 = cm_object_get_child_by_name(obj, "F2R2");
	state->f1.reg.f3r1 = cm_object_get_child_by_name(obj, "F3R1");
	state->f1.reg.f3r2 = cm_object_get_child_by_name(obj, "F3R2");
	state->f1.reg.f4r1 = cm_object_get_child_by_name(obj, "F4R1");
	state->f1.reg.f4r2 = cm_object_get_child_by_name(obj, "F4R2");
	state->f1.reg.f5r1 = cm_object_get_child_by_name(obj, "F5R1");
	state->f1.reg.f5r2 = cm_object_get_child_by_name(obj, "F5R2");
	state->f1.reg.f6r1 = cm_object_get_child_by_name(obj, "F6R1");
	state->f1.reg.f6r2 = cm_object_get_child_by_name(obj, "F6R2");
	state->f1.reg.f7r1 = cm_object_get_child_by_name(obj, "F7R1");
	state->f1.reg.f7r2 = cm_object_get_child_by_name(obj, "F7R2");
	state->f1.reg.f8r1 = cm_object_get_child_by_name(obj, "F8R1");
	state->f1.reg.f8r2 = cm_object_get_child_by_name(obj, "F8R2");
	state->f1.reg.f9r1 = cm_object_get_child_by_name(obj, "F9R1");
	state->f1.reg.f9r2 = cm_object_get_child_by_name(obj, "F9R2");
	state->f1.reg.f10r1 = cm_object_get_child_by_name(obj, "F10R1");
	state->f1.reg.f10r2 = cm_object_get_child_by_name(obj, "F10R2");
	state->f1.reg.f11r1 = cm_object_get_child_by_name(obj, "F11R1");
	state->f1.reg.f11r2 = cm_object_get_child_by_name(obj, "F11R2");
	state->f1.reg.f12r1 = cm_object_get_child_by_name(obj, "F12R1");
	state->f1.reg.f12r2 = cm_object_get_child_by_name(obj, "F12R2");
	state->f1.reg.f13r1 = cm_object_get_child_by_name(obj, "F13R1");
	state->f1.reg.f13r2 = cm_object_get_child_by_name(obj, "F13R2");

	// CAN_MCR bitfields.
	state->f1.fld.can_mcr.inrq = cm_object_get_child_by_name(state->f1.reg.can_mcr, "INRQ");
	state->f1.fld.can_mcr.sleep = cm_object_get_child_by_name(state->f1.reg.can_mcr, "SLEEP");
	state->f1.fld.can_mcr.txfp = cm_object_get_child_by_name(state->f1.reg.can_mcr, "TXFP");
	state->f1.fld.can_mcr.rflm = cm_object_get_child_by_name(state->f1.reg.can_mcr, "RFLM");
	state->f1.fld.can_mcr.nart = cm_object_get_child_by_name(state->f1.reg.can_mcr, "NART");
	state->f1.fld.can_mcr.awum = cm_object_get_child_by_name(state->f1.reg.can_mcr, "AWUM");
	state->f1.fld.can_mcr.abom = cm_object_get_child_by_name(state->f1.reg.can_mcr, "ABOM");
	state->f1.fld.can_mcr.ttcm = cm_object_get_child_by_name(state->f1.reg.can_mcr, "TTCM");
	state->f1.fld.can_mcr.reset = cm_object_get_child_by_name(state->f1.reg.can_mcr, "RESET");
	state->f1.fld.can_mcr.dbf = cm_object_get_child_by_name(state->f1.reg.can_mcr, "DBF");

	// CAN_MSR bitfields.
	state->f1.fld.can_msr.inak = cm_object_get_child_by_name(state->f1.reg.can_msr, "INAK");
	state->f1.fld.can_msr.slak = cm_object_get_child_by_name(state->f1.reg.can_msr, "SLAK");
	state->f1.fld.can_msr.erri = cm_object_get_child_by_name(state->f1.reg.can_msr, "ERRI");
	state->f1.fld.can_msr.wkui = cm_object_get_child_by_name(state->f1.reg.can_msr, "WKUI");
	state->f1.fld.can_msr.slaki = cm_object_get_child_by_name(state->f1.reg.can_msr, "SLAKI");
	state->f1.fld.can_msr.txm = cm_object_get_child_by_name(state->f1.reg.can_msr, "TXM");
	state->f1.fld.can_msr.rxm = cm_object_get_child_by_name(state->f1.reg.can_msr, "RXM");
	state->f1.fld.can_msr.samp = cm_object_get_child_by_name(state->f1.reg.can_msr, "SAMP");
	state->f1.fld.can_msr.rx = cm_object_get_child_by_name(state->f1.reg.can_msr, "RX");

	// CAN_TSR bitfields.
	state->f1.fld.can_tsr.rqcp0 = cm_object_get_child_by_name(state->f1.reg.can_tsr, "RQCP0");
	state->f1.fld.can_tsr.txok0 = cm_object_get_child_by_name(state->f1.reg.can_tsr, "TXOK0");
	state->f1.fld.can_tsr.alst0 = cm_object_get_child_by_name(state->f1.reg.can_tsr, "ALST0");
	state->f1.fld.can_tsr.terr0 = cm_object_get_child_by_name(state->f1.reg.can_tsr, "TERR0");
	state->f1.fld.can_tsr.abrq0 = cm_object_get_child_by_name(state->f1.reg.can_tsr, "ABRQ0");
	state->f1.fld.can_tsr.rqcp1 = cm_object_get_child_by_name(state->f1.reg.can_tsr, "RQCP1");
	state->f1.fld.can_tsr.txok1 = cm_object_get_child_by_name(state->f1.reg.can_tsr, "TXOK1");
	state->f1.fld.can_tsr.alst1 = cm_object_get_child_by_name(state->f1.reg.can_tsr, "ALST1");
	state->f1.fld.can_tsr.terr1 = cm_object_get_child_by_name(state->f1.reg.can_tsr, "TERR1");
	state->f1.fld.can_tsr.abrq1 = cm_object_get_child_by_name(state->f1.reg.can_tsr, "ABRQ1");
	state->f1.fld.can_tsr.rqcp2 = cm_object_get_child_by_name(state->f1.reg.can_tsr, "RQCP2");
	state->f1.fld.can_tsr.txok2 = cm_object_get_child_by_name(state->f1.reg.can_tsr, "TXOK2");
	state->f1.fld.can_tsr.alst2 = cm_object_get_child_by_name(state->f1.reg.can_tsr, "ALST2");
	state->f1.fld.can_tsr.terr2 = cm_object_get_child_by_name(state->f1.reg.can_tsr, "TERR2");
	state->f1.fld.can_tsr.abrq2 = cm_object_get_child_by_name(state->f1.reg.can_tsr, "ABRQ2");
	state->f1.fld.can_tsr.code = cm_object_get_child_by_name(state->f1.reg.can_tsr, "CODE");
	state->f1.fld.can_tsr.tme0 = cm_object_get_child_by_name(state->f1.reg.can_tsr, "TME0");
	state->f1.fld.can_tsr.tme1 = cm_object_get_child_by_name(state->f1.reg.can_tsr, "TME1");
	state->f1.fld.can_tsr.tme2 = cm_object_get_child_by_name(state->f1.reg.can_tsr, "TME2");
	state->f1.fld.can_tsr.low0 = cm_object_get_child_by_name(state->f1.reg.can_tsr, "LOW0");
	state->f1.fld.can_tsr.low1 = cm_object_get_child_by_name(state->f1.reg.can_tsr, "LOW1");
	state->f1.fld.can_tsr.low2 = cm_object_get_child_by_name(state->f1.reg.can_tsr, "LOW2");

	// CAN_RF0R bitfields.
	state->f1.fld.can_rf0r.fmp0 = cm_object_get_child_by_name(state->f1.reg.can_rf0r, "FMP0");
	state->f1.fld.can_rf0r.full0 = cm_object_get_child_by_name(state->f1.reg.can_rf0r, "FULL0");
	state->f1.fld.can_rf0r.fovr0 = cm_object_get_child_by_name(state->f1.reg.can_rf0r, "FOVR0");
	state->f1.fld.can_rf0r.rfom0 = cm_object_get_child_by_name(state->f1.reg.can_rf0r, "RFOM0");

	// CAN_RF1R bitfields.
	state->f1.fld.can_rf1r.fmp1 = cm_object_get_child_by_name(state->f1.reg.can_rf1r, "FMP1");
	state->f1.fld.can_rf1r.full1 = cm_object_get_child_by_name(state->f1.reg.can_rf1r, "FULL1");
	state->f1.fld.can_rf1r.fovr1 = cm_object_get_child_by_name(state->f1.reg.can_rf1r, "FOVR1");
	state->f1.fld.can_rf1r.rfom1 = cm_object_get_child_by_name(state->f1.reg.can_rf1r, "RFOM1");

	// CAN_IER bitfields.
	state->f1.fld.can_ier.tmeie = cm_object_get_child_by_name(state->f1.reg.can_ier, "TMEIE");
	state->f1.fld.can_ier.fmpie0 = cm_object_get_child_by_name(state->f1.reg.can_ier, "FMPIE0");
	state->f1.fld.can_ier.ffie0 = cm_object_get_child_by_name(state->f1.reg.can_ier, "FFIE0");
	state->f1.fld.can_ier.fovie0 = cm_object_get_child_by_name(state->f1.reg.can_ier, "FOVIE0");
	state->f1.fld.can_ier.fmpie1 = cm_object_get_child_by_name(state->f1.reg.can_ier, "FMPIE1");
	state->f1.fld.can_ier.ffie1 = cm_object_get_child_by_name(state->f1.reg.can_ier, "FFIE1");
	state->f1.fld.can_ier.fovie1 = cm_object_get_child_by_name(state->f1.reg.can_ier, "FOVIE1");
	state->f1.fld.can_ier.ewgie = cm_object_get_child_by_name(state->f1.reg.can_ier, "EWGIE");
	state->f1.fld.can_ier.epvie = cm_object_get_child_by_name(state->f1.reg.can_ier, "EPVIE");
	state->f1.fld.can_ier.bofie = cm_object_get_child_by_name(state->f1.reg.can_ier, "BOFIE");
	state->f1.fld.can_ier.lecie = cm_object_get_child_by_name(state->f1.reg.can_ier, "LECIE");
	state->f1.fld.can_ier.errie = cm_object_get_child_by_name(state->f1.reg.can_ier, "ERRIE");
	state->f1.fld.can_ier.wkuie = cm_object_get_child_by_name(state->f1.reg.can_ier, "WKUIE");
	state->f1.fld.can_ier.slkie = cm_object_get_child_by_name(state->f1.reg.can_ier, "SLKIE");

	// CAN_ESR bitfields.
	state->f1.fld.can_esr.ewgf = cm_object_get_child_by_name(state->f1.reg.can_esr, "EWGF");
	state->f1.fld.can_esr.epvf = cm_object_get_child_by_name(state->f1.reg.can_esr, "EPVF");
	state->f1.fld.can_esr.boff = cm_object_get_child_by_name(state->f1.reg.can_esr, "BOFF");
	state->f1.fld.can_esr.lec = cm_object_get_child_by_name(state->f1.reg.can_esr, "LEC");
	state->f1.fld.can_esr.tec = cm_object_get_child_by_name(state->f1.reg.can_esr, "TEC");
	state->f1.fld.can_esr.rec = cm_object_get_child_by_name(state->f1.reg.can_esr, "REC");

	// CAN_BTR bitfields.
	state->f1.fld.can_btr.brp = cm_object_get_child_by_name(state->f1.reg.can_btr, "BRP");
	state->f1.fld.can_btr.ts1 = cm_object_get_child_by_name(state->f1.reg.can_btr, "TS1");
	state->f1.fld.can_btr.ts2 = cm_object_get_child_by_name(state->f1.reg.can_btr, "TS2");
	state->f1.fld.can_btr.sjw = cm_object_get_child_by_name(state->f1.reg.can_btr, "SJW");
	state->f1.fld.can_btr.lbkm = cm_object_get_child_by_name(state->f1.reg.can_btr, "LBKM");
	state->f1.fld.can_btr.silm = cm_object_get_child_by_name(state->f1.reg.can_btr, "SILM");

	// CAN_TI0R bitfields.
	state->f1.fld.can_ti0r.txrq = cm_object_get_child_by_name(state->f1.reg.can_ti0r, "TXRQ");
	state->f1.fld.can_ti0r.rtr = cm_object_get_child_by_name(state->f1.reg.can_ti0r, "RTR");
	state->f1.fld.can_ti0r.ide = cm_object_get_child_by_name(state->f1.reg.can_ti0r, "IDE");
	state->f1.fld.can_ti0r.exid = cm_object_get_child_by_name(state->f1.reg.can_ti0r, "EXID");
	state->f1.fld.can_ti0r.stid = cm_object_get_child_by_name(state->f1.reg.can_ti0r, "STID");

	// CAN_TDT0R bitfields.
	state->f1.fld.can_tdt0r.dlc = cm_object_get_child_by_name(state->f1.reg.can_tdt0r, "DLC");
	state->f1.fld.can_tdt0r.tgt = cm_object_get_child_by_name(state->f1.reg.can_tdt0r, "TGT");
	state->f1.fld.can_tdt0r.time = cm_object_get_child_by_name(state->f1.reg.can_tdt0r, "TIME");

	// CAN_TDL0R bitfields.
	state->f1.fld.can_tdl0r.data0 = cm_object_get_child_by_name(state->f1.reg.can_tdl0r, "DATA0");
	state->f1.fld.can_tdl0r.data1 = cm_object_get_child_by_name(state->f1.reg.can_tdl0r, "DATA1");
	state->f1.fld.can_tdl0r.data2 = cm_object_get_child_by_name(state->f1.reg.can_tdl0r, "DATA2");
	state->f1.fld.can_tdl0r.data3 = cm_object_get_child_by_name(state->f1.reg.can_tdl0r, "DATA3");

	// CAN_TDH0R bitfields.
	state->f1.fld.can_tdh0r.data4 = cm_object_get_child_by_name(state->f1.reg.can_tdh0r, "DATA4");
	state->f1.fld.can_tdh0r.data5 = cm_object_get_child_by_name(state->f1.reg.can_tdh0r, "DATA5");
	state->f1.fld.can_tdh0r.data6 = cm_object_get_child_by_name(state->f1.reg.can_tdh0r, "DATA6");
	state->f1.fld.can_tdh0r.data7 = cm_object_get_child_by_name(state->f1.reg.can_tdh0r, "DATA7");

	// CAN_TI1R bitfields.
	state->f1.fld.can_ti1r.txrq = cm_object_get_child_by_name(state->f1.reg.can_ti1r, "TXRQ");
	state->f1.fld.can_ti1r.rtr = cm_object_get_child_by_name(state->f1.reg.can_ti1r, "RTR");
	state->f1.fld.can_ti1r.ide = cm_object_get_child_by_name(state->f1.reg.can_ti1r, "IDE");
	state->f1.fld.can_ti1r.exid = cm_object_get_child_by_name(state->f1.reg.can_ti1r, "EXID");
	state->f1.fld.can_ti1r.stid = cm_object_get_child_by_name(state->f1.reg.can_ti1r, "STID");

	// CAN_TDT1R bitfields.
	state->f1.fld.can_tdt1r.dlc = cm_object_get_child_by_name(state->f1.reg.can_tdt1r, "DLC");
	state->f1.fld.can_tdt1r.tgt = cm_object_get_child_by_name(state->f1.reg.can_tdt1r, "TGT");
	state->f1.fld.can_tdt1r.time = cm_object_get_child_by_name(state->f1.reg.can_tdt1r, "TIME");

	// CAN_TDL1R bitfields.
	state->f1.fld.can_tdl1r.data0 = cm_object_get_child_by_name(state->f1.reg.can_tdl1r, "DATA0");
	state->f1.fld.can_tdl1r.data1 = cm_object_get_child_by_name(state->f1.reg.can_tdl1r, "DATA1");
	state->f1.fld.can_tdl1r.data2 = cm_object_get_child_by_name(state->f1.reg.can_tdl1r, "DATA2");
	state->f1.fld.can_tdl1r.data3 = cm_object_get_child_by_name(state->f1.reg.can_tdl1r, "DATA3");

	// CAN_TDH1R bitfields.
	state->f1.fld.can_tdh1r.data4 = cm_object_get_child_by_name(state->f1.reg.can_tdh1r, "DATA4");
	state->f1.fld.can_tdh1r.data5 = cm_object_get_child_by_name(state->f1.reg.can_tdh1r, "DATA5");
	state->f1.fld.can_tdh1r.data6 = cm_object_get_child_by_name(state->f1.reg.can_tdh1r, "DATA6");
	state->f1.fld.can_tdh1r.data7 = cm_object_get_child_by_name(state->f1.reg.can_tdh1r, "DATA7");

	// CAN_TI2R bitfields.
	state->f1.fld.can_ti2r.txrq = cm_object_get_child_by_name(state->f1.reg.can_ti2r, "TXRQ");
	state->f1.fld.can_ti2r.rtr = cm_object_get_child_by_name(state->f1.reg.can_ti2r, "RTR");
	state->f1.fld.can_ti2r.ide = cm_object_get_child_by_name(state->f1.reg.can_ti2r, "IDE");
	state->f1.fld.can_ti2r.exid = cm_object_get_child_by_name(state->f1.reg.can_ti2r, "EXID");
	state->f1.fld.can_ti2r.stid = cm_object_get_child_by_name(state->f1.reg.can_ti2r, "STID");

	// CAN_TDT2R bitfields.
	state->f1.fld.can_tdt2r.dlc = cm_object_get_child_by_name(state->f1.reg.can_tdt2r, "DLC");
	state->f1.fld.can_tdt2r.tgt = cm_object_get_child_by_name(state->f1.reg.can_tdt2r, "TGT");
	state->f1.fld.can_tdt2r.time = cm_object_get_child_by_name(state->f1.reg.can_tdt2r, "TIME");

	// CAN_TDL2R bitfields.
	state->f1.fld.can_tdl2r.data0 = cm_object_get_child_by_name(state->f1.reg.can_tdl2r, "DATA0");
	state->f1.fld.can_tdl2r.data1 = cm_object_get_child_by_name(state->f1.reg.can_tdl2r, "DATA1");
	state->f1.fld.can_tdl2r.data2 = cm_object_get_child_by_name(state->f1.reg.can_tdl2r, "DATA2");
	state->f1.fld.can_tdl2r.data3 = cm_object_get_child_by_name(state->f1.reg.can_tdl2r, "DATA3");

	// CAN_TDH2R bitfields.
	state->f1.fld.can_tdh2r.data4 = cm_object_get_child_by_name(state->f1.reg.can_tdh2r, "DATA4");
	state->f1.fld.can_tdh2r.data5 = cm_object_get_child_by_name(state->f1.reg.can_tdh2r, "DATA5");
	state->f1.fld.can_tdh2r.data6 = cm_object_get_child_by_name(state->f1.reg.can_tdh2r, "DATA6");
	state->f1.fld.can_tdh2r.data7 = cm_object_get_child_by_name(state->f1.reg.can_tdh2r, "DATA7");

	// CAN_RI0R bitfields.
	state->f1.fld.can_ri0r.rtr = cm_object_get_child_by_name(state->f1.reg.can_ri0r, "RTR");
	state->f1.fld.can_ri0r.ide = cm_object_get_child_by_name(state->f1.reg.can_ri0r, "IDE");
	state->f1.fld.can_ri0r.exid = cm_object_get_child_by_name(state->f1.reg.can_ri0r, "EXID");
	state->f1.fld.can_ri0r.stid = cm_object_get_child_by_name(state->f1.reg.can_ri0r, "STID");

	// CAN_RDT0R bitfields.
	state->f1.fld.can_rdt0r.dlc = cm_object_get_child_by_name(state->f1.reg.can_rdt0r, "DLC");
	state->f1.fld.can_rdt0r.fmi = cm_object_get_child_by_name(state->f1.reg.can_rdt0r, "FMI");
	state->f1.fld.can_rdt0r.time = cm_object_get_child_by_name(state->f1.reg.can_rdt0r, "TIME");

	// CAN_RDL0R bitfields.
	state->f1.fld.can_rdl0r.data0 = cm_object_get_child_by_name(state->f1.reg.can_rdl0r, "DATA0");
	state->f1.fld.can_rdl0r.data1 = cm_object_get_child_by_name(state->f1.reg.can_rdl0r, "DATA1");
	state->f1.fld.can_rdl0r.data2 = cm_object_get_child_by_name(state->f1.reg.can_rdl0r, "DATA2");
	state->f1.fld.can_rdl0r.data3 = cm_object_get_child_by_name(state->f1.reg.can_rdl0r, "DATA3");

	// CAN_RDH0R bitfields.
	state->f1.fld.can_rdh0r.data4 = cm_object_get_child_by_name(state->f1.reg.can_rdh0r, "DATA4");
	state->f1.fld.can_rdh0r.data5 = cm_object_get_child_by_name(state->f1.reg.can_rdh0r, "DATA5");
	state->f1.fld.can_rdh0r.data6 = cm_object_get_child_by_name(state->f1.reg.can_rdh0r, "DATA6");
	state->f1.fld.can_rdh0r.data7 = cm_object_get_child_by_name(state->f1.reg.can_rdh0r, "DATA7");

	// CAN_RI1R bitfields.
	state->f1.fld.can_ri1r.rtr = cm_object_get_child_by_name(state->f1.reg.can_ri1r, "RTR");
	state->f1.fld.can_ri1r.ide = cm_object_get_child_by_name(state->f1.reg.can_ri1r, "IDE");
	state->f1.fld.can_ri1r.exid = cm_object_get_child_by_name(state->f1.reg.can_ri1r, "EXID");
	state->f1.fld.can_ri1r.stid = cm_object_get_child_by_name(state->f1.reg.can_ri1r, "STID");

	// CAN_RDT1R bitfields.
	state->f1.fld.can_rdt1r.dlc = cm_object_get_child_by_name(state->f1.reg.can_rdt1r, "DLC");
	state->f1.fld.can_rdt1r.fmi = cm_object_get_child_by_name(state->f1.reg.can_rdt1r, "FMI");
	state->f1.fld.can_rdt1r.time = cm_object_get_child_by_name(state->f1.reg.can_rdt1r, "TIME");

	// CAN_RDL1R bitfields.
	state->f1.fld.can_rdl1r.data0 = cm_object_get_child_by_name(state->f1.reg.can_rdl1r, "DATA0");
	state->f1.fld.can_rdl1r.data1 = cm_object_get_child_by_name(state->f1.reg.can_rdl1r, "DATA1");
	state->f1.fld.can_rdl1r.data2 = cm_object_get_child_by_name(state->f1.reg.can_rdl1r, "DATA2");
	state->f1.fld.can_rdl1r.data3 = cm_object_get_child_by_name(state->f1.reg.can_rdl1r, "DATA3");

	// CAN_RDH1R bitfields.
	state->f1.fld.can_rdh1r.data4 = cm_object_get_child_by_name(state->f1.reg.can_rdh1r, "DATA4");
	state->f1.fld.can_rdh1r.data5 = cm_object_get_child_by_name(state->f1.reg.can_rdh1r, "DATA5");
	state->f1.fld.can_rdh1r.data6 = cm_object_get_child_by_name(state->f1.reg.can_rdh1r, "DATA6");
	state->f1.fld.can_rdh1r.data7 = cm_object_get_child_by_name(state->f1.reg.can_rdh1r, "DATA7");

	// CAN_FMR bitfields.
	state->f1.fld.can_fmr.finit = cm_object_get_child_by_name(state->f1.reg.can_fmr, "FINIT");

	// CAN_FM1R bitfields.
	state->f1.fld.can_fm1r.fbm0 = cm_object_get_child_by_name(state->f1.reg.can_fm1r, "FBM0");
	state->f1.fld.can_fm1r.fbm1 = cm_object_get_child_by_name(state->f1.reg.can_fm1r, "FBM1");
	state->f1.fld.can_fm1r.fbm2 = cm_object_get_child_by_name(state->f1.reg.can_fm1r, "FBM2");
	state->f1.fld.can_fm1r.fbm3 = cm_object_get_child_by_name(state->f1.reg.can_fm1r, "FBM3");
	state->f1.fld.can_fm1r.fbm4 = cm_object_get_child_by_name(state->f1.reg.can_fm1r, "FBM4");
	state->f1.fld.can_fm1r.fbm5 = cm_object_get_child_by_name(state->f1.reg.can_fm1r, "FBM5");
	state->f1.fld.can_fm1r.fbm6 = cm_object_get_child_by_name(state->f1.reg.can_fm1r, "FBM6");
	state->f1.fld.can_fm1r.fbm7 = cm_object_get_child_by_name(state->f1.reg.can_fm1r, "FBM7");
	state->f1.fld.can_fm1r.fbm8 = cm_object_get_child_by_name(state->f1.reg.can_fm1r, "FBM8");
	state->f1.fld.can_fm1r.fbm9 = cm_object_get_child_by_name(state->f1.reg.can_fm1r, "FBM9");
	state->f1.fld.can_fm1r.fbm10 = cm_object_get_child_by_name(state->f1.reg.can_fm1r, "FBM10");
	state->f1.fld.can_fm1r.fbm11 = cm_object_get_child_by_name(state->f1.reg.can_fm1r, "FBM11");
	state->f1.fld.can_fm1r.fbm12 = cm_object_get_child_by_name(state->f1.reg.can_fm1r, "FBM12");
	state->f1.fld.can_fm1r.fbm13 = cm_object_get_child_by_name(state->f1.reg.can_fm1r, "FBM13");

	// CAN_FS1R bitfields.
	state->f1.fld.can_fs1r.fsc0 = cm_object_get_child_by_name(state->f1.reg.can_fs1r, "FSC0");
	state->f1.fld.can_fs1r.fsc1 = cm_object_get_child_by_name(state->f1.reg.can_fs1r, "FSC1");
	state->f1.fld.can_fs1r.fsc2 = cm_object_get_child_by_name(state->f1.reg.can_fs1r, "FSC2");
	state->f1.fld.can_fs1r.fsc3 = cm_object_get_child_by_name(state->f1.reg.can_fs1r, "FSC3");
	state->f1.fld.can_fs1r.fsc4 = cm_object_get_child_by_name(state->f1.reg.can_fs1r, "FSC4");
	state->f1.fld.can_fs1r.fsc5 = cm_object_get_child_by_name(state->f1.reg.can_fs1r, "FSC5");
	state->f1.fld.can_fs1r.fsc6 = cm_object_get_child_by_name(state->f1.reg.can_fs1r, "FSC6");
	state->f1.fld.can_fs1r.fsc7 = cm_object_get_child_by_name(state->f1.reg.can_fs1r, "FSC7");
	state->f1.fld.can_fs1r.fsc8 = cm_object_get_child_by_name(state->f1.reg.can_fs1r, "FSC8");
	state->f1.fld.can_fs1r.fsc9 = cm_object_get_child_by_name(state->f1.reg.can_fs1r, "FSC9");
	state->f1.fld.can_fs1r.fsc10 = cm_object_get_child_by_name(state->f1.reg.can_fs1r, "FSC10");
	state->f1.fld.can_fs1r.fsc11 = cm_object_get_child_by_name(state->f1.reg.can_fs1r, "FSC11");
	state->f1.fld.can_fs1r.fsc12 = cm_object_get_child_by_name(state->f1.reg.can_fs1r, "FSC12");
	state->f1.fld.can_fs1r.fsc13 = cm_object_get_child_by_name(state->f1.reg.can_fs1r, "FSC13");

	// CAN_FFA1R bitfields.
	state->f1.fld.can_ffa1r.ffa0 = cm_object_get_child_by_name(state->f1.reg.can_ffa1r, "FFA0");
	state->f1.fld.can_ffa1r.ffa1 = cm_object_get_child_by_name(state->f1.reg.can_ffa1r, "FFA1");
	state->f1.fld.can_ffa1r.ffa2 = cm_object_get_child_by_name(state->f1.reg.can_ffa1r, "FFA2");
	state->f1.fld.can_ffa1r.ffa3 = cm_object_get_child_by_name(state->f1.reg.can_ffa1r, "FFA3");
	state->f1.fld.can_ffa1r.ffa4 = cm_object_get_child_by_name(state->f1.reg.can_ffa1r, "FFA4");
	state->f1.fld.can_ffa1r.ffa5 = cm_object_get_child_by_name(state->f1.reg.can_ffa1r, "FFA5");
	state->f1.fld.can_ffa1r.ffa6 = cm_object_get_child_by_name(state->f1.reg.can_ffa1r, "FFA6");
	state->f1.fld.can_ffa1r.ffa7 = cm_object_get_child_by_name(state->f1.reg.can_ffa1r, "FFA7");
	state->f1.fld.can_ffa1r.ffa8 = cm_object_get_child_by_name(state->f1.reg.can_ffa1r, "FFA8");
	state->f1.fld.can_ffa1r.ffa9 = cm_object_get_child_by_name(state->f1.reg.can_ffa1r, "FFA9");
	state->f1.fld.can_ffa1r.ffa10 = cm_object_get_child_by_name(state->f1.reg.can_ffa1r, "FFA10");
	state->f1.fld.can_ffa1r.ffa11 = cm_object_get_child_by_name(state->f1.reg.can_ffa1r, "FFA11");
	state->f1.fld.can_ffa1r.ffa12 = cm_object_get_child_by_name(state->f1.reg.can_ffa1r, "FFA12");
	state->f1.fld.can_ffa1r.ffa13 = cm_object_get_child_by_name(state->f1.reg.can_ffa1r, "FFA13");

	// CAN_FA1R bitfields.
	state->f1.fld.can_fa1r.fact0 = cm_object_get_child_by_name(state->f1.reg.can_fa1r, "FACT0");
	state->f1.fld.can_fa1r.fact1 = cm_object_get_child_by_name(state->f1.reg.can_fa1r, "FACT1");
	state->f1.fld.can_fa1r.fact2 = cm_object_get_child_by_name(state->f1.reg.can_fa1r, "FACT2");
	state->f1.fld.can_fa1r.fact3 = cm_object_get_child_by_name(state->f1.reg.can_fa1r, "FACT3");
	state->f1.fld.can_fa1r.fact4 = cm_object_get_child_by_name(state->f1.reg.can_fa1r, "FACT4");
	state->f1.fld.can_fa1r.fact5 = cm_object_get_child_by_name(state->f1.reg.can_fa1r, "FACT5");
	state->f1.fld.can_fa1r.fact6 = cm_object_get_child_by_name(state->f1.reg.can_fa1r, "FACT6");
	state->f1.fld.can_fa1r.fact7 = cm_object_get_child_by_name(state->f1.reg.can_fa1r, "FACT7");
	state->f1.fld.can_fa1r.fact8 = cm_object_get_child_by_name(state->f1.reg.can_fa1r, "FACT8");
	state->f1.fld.can_fa1r.fact9 = cm_object_get_child_by_name(state->f1.reg.can_fa1r, "FACT9");
	state->f1.fld.can_fa1r.fact10 = cm_object_get_child_by_name(state->f1.reg.can_fa1r, "FACT10");
	state->f1.fld.can_fa1r.fact11 = cm_object_get_child_by_name(state->f1.reg.can_fa1r, "FACT11");
	state->f1.fld.can_fa1r.fact12 = cm_object_get_child_by_name(state->f1.reg.can_fa1r, "FACT12");
	state->f1.fld.can_fa1r.fact13 = cm_object_get_child_by_name(state->f1.reg.can_fa1r, "FACT13");

	// F0R1 bitfields.
	state->f1.fld.f0r1.fb0 = cm_object_get_child_by_name(state->f1.reg.f0r1, "FB0");
	state->f1.fld.f0r1.fb1 = cm_object_get_child_by_name(state->f1.reg.f0r1, "FB1");
	state->f1.fld.f0r1.fb2 = cm_object_get_child_by_name(state->f1.reg.f0r1, "FB2");
	state->f1.fld.f0r1.fb3 = cm_object_get_child_by_name(state->f1.reg.f0r1, "FB3");
	state->f1.fld.f0r1.fb4 = cm_object_get_child_by_name(state->f1.reg.f0r1, "FB4");
	state->f1.fld.f0r1.fb5 = cm_object_get_child_by_name(state->f1.reg.f0r1, "FB5");
	state->f1.fld.f0r1.fb6 = cm_object_get_child_by_name(state->f1.reg.f0r1, "FB6");
	state->f1.fld.f0r1.fb7 = cm_object_get_child_by_name(state->f1.reg.f0r1, "FB7");
	state->f1.fld.f0r1.fb8 = cm_object_get_child_by_name(state->f1.reg.f0r1, "FB8");
	state->f1.fld.f0r1.fb9 = cm_object_get_child_by_name(state->f1.reg.f0r1, "FB9");
	state->f1.fld.f0r1.fb10 = cm_object_get_child_by_name(state->f1.reg.f0r1, "FB10");
	state->f1.fld.f0r1.fb11 = cm_object_get_child_by_name(state->f1.reg.f0r1, "FB11");
	state->f1.fld.f0r1.fb12 = cm_object_get_child_by_name(state->f1.reg.f0r1, "FB12");
	state->f1.fld.f0r1.fb13 = cm_object_get_child_by_name(state->f1.reg.f0r1, "FB13");
	state->f1.fld.f0r1.fb14 = cm_object_get_child_by_name(state->f1.reg.f0r1, "FB14");
	state->f1.fld.f0r1.fb15 = cm_object_get_child_by_name(state->f1.reg.f0r1, "FB15");
	state->f1.fld.f0r1.fb16 = cm_object_get_child_by_name(state->f1.reg.f0r1, "FB16");
	state->f1.fld.f0r1.fb17 = cm_object_get_child_by_name(state->f1.reg.f0r1, "FB17");
	state->f1.fld.f0r1.fb18 = cm_object_get_child_by_name(state->f1.reg.f0r1, "FB18");
	state->f1.fld.f0r1.fb19 = cm_object_get_child_by_name(state->f1.reg.f0r1, "FB19");
	state->f1.fld.f0r1.fb20 = cm_object_get_child_by_name(state->f1.reg.f0r1, "FB20");
	state->f1.fld.f0r1.fb21 = cm_object_get_child_by_name(state->f1.reg.f0r1, "FB21");
	state->f1.fld.f0r1.fb22 = cm_object_get_child_by_name(state->f1.reg.f0r1, "FB22");
	state->f1.fld.f0r1.fb23 = cm_object_get_child_by_name(state->f1.reg.f0r1, "FB23");
	state->f1.fld.f0r1.fb24 = cm_object_get_child_by_name(state->f1.reg.f0r1, "FB24");
	state->f1.fld.f0r1.fb25 = cm_object_get_child_by_name(state->f1.reg.f0r1, "FB25");
	state->f1.fld.f0r1.fb26 = cm_object_get_child_by_name(state->f1.reg.f0r1, "FB26");
	state->f1.fld.f0r1.fb27 = cm_object_get_child_by_name(state->f1.reg.f0r1, "FB27");
	state->f1.fld.f0r1.fb28 = cm_object_get_child_by_name(state->f1.reg.f0r1, "FB28");
	state->f1.fld.f0r1.fb29 = cm_object_get_child_by_name(state->f1.reg.f0r1, "FB29");
	state->f1.fld.f0r1.fb30 = cm_object_get_child_by_name(state->f1.reg.f0r1, "FB30");
	state->f1.fld.f0r1.fb31 = cm_object_get_child_by_name(state->f1.reg.f0r1, "FB31");

	// F0R2 bitfields.
	state->f1.fld.f0r2.fb0 = cm_object_get_child_by_name(state->f1.reg.f0r2, "FB0");
	state->f1.fld.f0r2.fb1 = cm_object_get_child_by_name(state->f1.reg.f0r2, "FB1");
	state->f1.fld.f0r2.fb2 = cm_object_get_child_by_name(state->f1.reg.f0r2, "FB2");
	state->f1.fld.f0r2.fb3 = cm_object_get_child_by_name(state->f1.reg.f0r2, "FB3");
	state->f1.fld.f0r2.fb4 = cm_object_get_child_by_name(state->f1.reg.f0r2, "FB4");
	state->f1.fld.f0r2.fb5 = cm_object_get_child_by_name(state->f1.reg.f0r2, "FB5");
	state->f1.fld.f0r2.fb6 = cm_object_get_child_by_name(state->f1.reg.f0r2, "FB6");
	state->f1.fld.f0r2.fb7 = cm_object_get_child_by_name(state->f1.reg.f0r2, "FB7");
	state->f1.fld.f0r2.fb8 = cm_object_get_child_by_name(state->f1.reg.f0r2, "FB8");
	state->f1.fld.f0r2.fb9 = cm_object_get_child_by_name(state->f1.reg.f0r2, "FB9");
	state->f1.fld.f0r2.fb10 = cm_object_get_child_by_name(state->f1.reg.f0r2, "FB10");
	state->f1.fld.f0r2.fb11 = cm_object_get_child_by_name(state->f1.reg.f0r2, "FB11");
	state->f1.fld.f0r2.fb12 = cm_object_get_child_by_name(state->f1.reg.f0r2, "FB12");
	state->f1.fld.f0r2.fb13 = cm_object_get_child_by_name(state->f1.reg.f0r2, "FB13");
	state->f1.fld.f0r2.fb14 = cm_object_get_child_by_name(state->f1.reg.f0r2, "FB14");
	state->f1.fld.f0r2.fb15 = cm_object_get_child_by_name(state->f1.reg.f0r2, "FB15");
	state->f1.fld.f0r2.fb16 = cm_object_get_child_by_name(state->f1.reg.f0r2, "FB16");
	state->f1.fld.f0r2.fb17 = cm_object_get_child_by_name(state->f1.reg.f0r2, "FB17");
	state->f1.fld.f0r2.fb18 = cm_object_get_child_by_name(state->f1.reg.f0r2, "FB18");
	state->f1.fld.f0r2.fb19 = cm_object_get_child_by_name(state->f1.reg.f0r2, "FB19");
	state->f1.fld.f0r2.fb20 = cm_object_get_child_by_name(state->f1.reg.f0r2, "FB20");
	state->f1.fld.f0r2.fb21 = cm_object_get_child_by_name(state->f1.reg.f0r2, "FB21");
	state->f1.fld.f0r2.fb22 = cm_object_get_child_by_name(state->f1.reg.f0r2, "FB22");
	state->f1.fld.f0r2.fb23 = cm_object_get_child_by_name(state->f1.reg.f0r2, "FB23");
	state->f1.fld.f0r2.fb24 = cm_object_get_child_by_name(state->f1.reg.f0r2, "FB24");
	state->f1.fld.f0r2.fb25 = cm_object_get_child_by_name(state->f1.reg.f0r2, "FB25");
	state->f1.fld.f0r2.fb26 = cm_object_get_child_by_name(state->f1.reg.f0r2, "FB26");
	state->f1.fld.f0r2.fb27 = cm_object_get_child_by_name(state->f1.reg.f0r2, "FB27");
	state->f1.fld.f0r2.fb28 = cm_object_get_child_by_name(state->f1.reg.f0r2, "FB28");
	state->f1.fld.f0r2.fb29 = cm_object_get_child_by_name(state->f1.reg.f0r2, "FB29");
	state->f1.fld.f0r2.fb30 = cm_object_get_child_by_name(state->f1.reg.f0r2, "FB30");
	state->f1.fld.f0r2.fb31 = cm_object_get_child_by_name(state->f1.reg.f0r2, "FB31");

	// F1R1 bitfields.
	state->f1.fld.f1r1.fb0 = cm_object_get_child_by_name(state->f1.reg.f1r1, "FB0");
	state->f1.fld.f1r1.fb1 = cm_object_get_child_by_name(state->f1.reg.f1r1, "FB1");
	state->f1.fld.f1r1.fb2 = cm_object_get_child_by_name(state->f1.reg.f1r1, "FB2");
	state->f1.fld.f1r1.fb3 = cm_object_get_child_by_name(state->f1.reg.f1r1, "FB3");
	state->f1.fld.f1r1.fb4 = cm_object_get_child_by_name(state->f1.reg.f1r1, "FB4");
	state->f1.fld.f1r1.fb5 = cm_object_get_child_by_name(state->f1.reg.f1r1, "FB5");
	state->f1.fld.f1r1.fb6 = cm_object_get_child_by_name(state->f1.reg.f1r1, "FB6");
	state->f1.fld.f1r1.fb7 = cm_object_get_child_by_name(state->f1.reg.f1r1, "FB7");
	state->f1.fld.f1r1.fb8 = cm_object_get_child_by_name(state->f1.reg.f1r1, "FB8");
	state->f1.fld.f1r1.fb9 = cm_object_get_child_by_name(state->f1.reg.f1r1, "FB9");
	state->f1.fld.f1r1.fb10 = cm_object_get_child_by_name(state->f1.reg.f1r1, "FB10");
	state->f1.fld.f1r1.fb11 = cm_object_get_child_by_name(state->f1.reg.f1r1, "FB11");
	state->f1.fld.f1r1.fb12 = cm_object_get_child_by_name(state->f1.reg.f1r1, "FB12");
	state->f1.fld.f1r1.fb13 = cm_object_get_child_by_name(state->f1.reg.f1r1, "FB13");
	state->f1.fld.f1r1.fb14 = cm_object_get_child_by_name(state->f1.reg.f1r1, "FB14");
	state->f1.fld.f1r1.fb15 = cm_object_get_child_by_name(state->f1.reg.f1r1, "FB15");
	state->f1.fld.f1r1.fb16 = cm_object_get_child_by_name(state->f1.reg.f1r1, "FB16");
	state->f1.fld.f1r1.fb17 = cm_object_get_child_by_name(state->f1.reg.f1r1, "FB17");
	state->f1.fld.f1r1.fb18 = cm_object_get_child_by_name(state->f1.reg.f1r1, "FB18");
	state->f1.fld.f1r1.fb19 = cm_object_get_child_by_name(state->f1.reg.f1r1, "FB19");
	state->f1.fld.f1r1.fb20 = cm_object_get_child_by_name(state->f1.reg.f1r1, "FB20");
	state->f1.fld.f1r1.fb21 = cm_object_get_child_by_name(state->f1.reg.f1r1, "FB21");
	state->f1.fld.f1r1.fb22 = cm_object_get_child_by_name(state->f1.reg.f1r1, "FB22");
	state->f1.fld.f1r1.fb23 = cm_object_get_child_by_name(state->f1.reg.f1r1, "FB23");
	state->f1.fld.f1r1.fb24 = cm_object_get_child_by_name(state->f1.reg.f1r1, "FB24");
	state->f1.fld.f1r1.fb25 = cm_object_get_child_by_name(state->f1.reg.f1r1, "FB25");
	state->f1.fld.f1r1.fb26 = cm_object_get_child_by_name(state->f1.reg.f1r1, "FB26");
	state->f1.fld.f1r1.fb27 = cm_object_get_child_by_name(state->f1.reg.f1r1, "FB27");
	state->f1.fld.f1r1.fb28 = cm_object_get_child_by_name(state->f1.reg.f1r1, "FB28");
	state->f1.fld.f1r1.fb29 = cm_object_get_child_by_name(state->f1.reg.f1r1, "FB29");
	state->f1.fld.f1r1.fb30 = cm_object_get_child_by_name(state->f1.reg.f1r1, "FB30");
	state->f1.fld.f1r1.fb31 = cm_object_get_child_by_name(state->f1.reg.f1r1, "FB31");

	// F1R2 bitfields.
	state->f1.fld.f1r2.fb0 = cm_object_get_child_by_name(state->f1.reg.f1r2, "FB0");
	state->f1.fld.f1r2.fb1 = cm_object_get_child_by_name(state->f1.reg.f1r2, "FB1");
	state->f1.fld.f1r2.fb2 = cm_object_get_child_by_name(state->f1.reg.f1r2, "FB2");
	state->f1.fld.f1r2.fb3 = cm_object_get_child_by_name(state->f1.reg.f1r2, "FB3");
	state->f1.fld.f1r2.fb4 = cm_object_get_child_by_name(state->f1.reg.f1r2, "FB4");
	state->f1.fld.f1r2.fb5 = cm_object_get_child_by_name(state->f1.reg.f1r2, "FB5");
	state->f1.fld.f1r2.fb6 = cm_object_get_child_by_name(state->f1.reg.f1r2, "FB6");
	state->f1.fld.f1r2.fb7 = cm_object_get_child_by_name(state->f1.reg.f1r2, "FB7");
	state->f1.fld.f1r2.fb8 = cm_object_get_child_by_name(state->f1.reg.f1r2, "FB8");
	state->f1.fld.f1r2.fb9 = cm_object_get_child_by_name(state->f1.reg.f1r2, "FB9");
	state->f1.fld.f1r2.fb10 = cm_object_get_child_by_name(state->f1.reg.f1r2, "FB10");
	state->f1.fld.f1r2.fb11 = cm_object_get_child_by_name(state->f1.reg.f1r2, "FB11");
	state->f1.fld.f1r2.fb12 = cm_object_get_child_by_name(state->f1.reg.f1r2, "FB12");
	state->f1.fld.f1r2.fb13 = cm_object_get_child_by_name(state->f1.reg.f1r2, "FB13");
	state->f1.fld.f1r2.fb14 = cm_object_get_child_by_name(state->f1.reg.f1r2, "FB14");
	state->f1.fld.f1r2.fb15 = cm_object_get_child_by_name(state->f1.reg.f1r2, "FB15");
	state->f1.fld.f1r2.fb16 = cm_object_get_child_by_name(state->f1.reg.f1r2, "FB16");
	state->f1.fld.f1r2.fb17 = cm_object_get_child_by_name(state->f1.reg.f1r2, "FB17");
	state->f1.fld.f1r2.fb18 = cm_object_get_child_by_name(state->f1.reg.f1r2, "FB18");
	state->f1.fld.f1r2.fb19 = cm_object_get_child_by_name(state->f1.reg.f1r2, "FB19");
	state->f1.fld.f1r2.fb20 = cm_object_get_child_by_name(state->f1.reg.f1r2, "FB20");
	state->f1.fld.f1r2.fb21 = cm_object_get_child_by_name(state->f1.reg.f1r2, "FB21");
	state->f1.fld.f1r2.fb22 = cm_object_get_child_by_name(state->f1.reg.f1r2, "FB22");
	state->f1.fld.f1r2.fb23 = cm_object_get_child_by_name(state->f1.reg.f1r2, "FB23");
	state->f1.fld.f1r2.fb24 = cm_object_get_child_by_name(state->f1.reg.f1r2, "FB24");
	state->f1.fld.f1r2.fb25 = cm_object_get_child_by_name(state->f1.reg.f1r2, "FB25");
	state->f1.fld.f1r2.fb26 = cm_object_get_child_by_name(state->f1.reg.f1r2, "FB26");
	state->f1.fld.f1r2.fb27 = cm_object_get_child_by_name(state->f1.reg.f1r2, "FB27");
	state->f1.fld.f1r2.fb28 = cm_object_get_child_by_name(state->f1.reg.f1r2, "FB28");
	state->f1.fld.f1r2.fb29 = cm_object_get_child_by_name(state->f1.reg.f1r2, "FB29");
	state->f1.fld.f1r2.fb30 = cm_object_get_child_by_name(state->f1.reg.f1r2, "FB30");
	state->f1.fld.f1r2.fb31 = cm_object_get_child_by_name(state->f1.reg.f1r2, "FB31");

	// F2R1 bitfields.
	state->f1.fld.f2r1.fb0 = cm_object_get_child_by_name(state->f1.reg.f2r1, "FB0");
	state->f1.fld.f2r1.fb1 = cm_object_get_child_by_name(state->f1.reg.f2r1, "FB1");
	state->f1.fld.f2r1.fb2 = cm_object_get_child_by_name(state->f1.reg.f2r1, "FB2");
	state->f1.fld.f2r1.fb3 = cm_object_get_child_by_name(state->f1.reg.f2r1, "FB3");
	state->f1.fld.f2r1.fb4 = cm_object_get_child_by_name(state->f1.reg.f2r1, "FB4");
	state->f1.fld.f2r1.fb5 = cm_object_get_child_by_name(state->f1.reg.f2r1, "FB5");
	state->f1.fld.f2r1.fb6 = cm_object_get_child_by_name(state->f1.reg.f2r1, "FB6");
	state->f1.fld.f2r1.fb7 = cm_object_get_child_by_name(state->f1.reg.f2r1, "FB7");
	state->f1.fld.f2r1.fb8 = cm_object_get_child_by_name(state->f1.reg.f2r1, "FB8");
	state->f1.fld.f2r1.fb9 = cm_object_get_child_by_name(state->f1.reg.f2r1, "FB9");
	state->f1.fld.f2r1.fb10 = cm_object_get_child_by_name(state->f1.reg.f2r1, "FB10");
	state->f1.fld.f2r1.fb11 = cm_object_get_child_by_name(state->f1.reg.f2r1, "FB11");
	state->f1.fld.f2r1.fb12 = cm_object_get_child_by_name(state->f1.reg.f2r1, "FB12");
	state->f1.fld.f2r1.fb13 = cm_object_get_child_by_name(state->f1.reg.f2r1, "FB13");
	state->f1.fld.f2r1.fb14 = cm_object_get_child_by_name(state->f1.reg.f2r1, "FB14");
	state->f1.fld.f2r1.fb15 = cm_object_get_child_by_name(state->f1.reg.f2r1, "FB15");
	state->f1.fld.f2r1.fb16 = cm_object_get_child_by_name(state->f1.reg.f2r1, "FB16");
	state->f1.fld.f2r1.fb17 = cm_object_get_child_by_name(state->f1.reg.f2r1, "FB17");
	state->f1.fld.f2r1.fb18 = cm_object_get_child_by_name(state->f1.reg.f2r1, "FB18");
	state->f1.fld.f2r1.fb19 = cm_object_get_child_by_name(state->f1.reg.f2r1, "FB19");
	state->f1.fld.f2r1.fb20 = cm_object_get_child_by_name(state->f1.reg.f2r1, "FB20");
	state->f1.fld.f2r1.fb21 = cm_object_get_child_by_name(state->f1.reg.f2r1, "FB21");
	state->f1.fld.f2r1.fb22 = cm_object_get_child_by_name(state->f1.reg.f2r1, "FB22");
	state->f1.fld.f2r1.fb23 = cm_object_get_child_by_name(state->f1.reg.f2r1, "FB23");
	state->f1.fld.f2r1.fb24 = cm_object_get_child_by_name(state->f1.reg.f2r1, "FB24");
	state->f1.fld.f2r1.fb25 = cm_object_get_child_by_name(state->f1.reg.f2r1, "FB25");
	state->f1.fld.f2r1.fb26 = cm_object_get_child_by_name(state->f1.reg.f2r1, "FB26");
	state->f1.fld.f2r1.fb27 = cm_object_get_child_by_name(state->f1.reg.f2r1, "FB27");
	state->f1.fld.f2r1.fb28 = cm_object_get_child_by_name(state->f1.reg.f2r1, "FB28");
	state->f1.fld.f2r1.fb29 = cm_object_get_child_by_name(state->f1.reg.f2r1, "FB29");
	state->f1.fld.f2r1.fb30 = cm_object_get_child_by_name(state->f1.reg.f2r1, "FB30");
	state->f1.fld.f2r1.fb31 = cm_object_get_child_by_name(state->f1.reg.f2r1, "FB31");

	// F2R2 bitfields.
	state->f1.fld.f2r2.fb0 = cm_object_get_child_by_name(state->f1.reg.f2r2, "FB0");
	state->f1.fld.f2r2.fb1 = cm_object_get_child_by_name(state->f1.reg.f2r2, "FB1");
	state->f1.fld.f2r2.fb2 = cm_object_get_child_by_name(state->f1.reg.f2r2, "FB2");
	state->f1.fld.f2r2.fb3 = cm_object_get_child_by_name(state->f1.reg.f2r2, "FB3");
	state->f1.fld.f2r2.fb4 = cm_object_get_child_by_name(state->f1.reg.f2r2, "FB4");
	state->f1.fld.f2r2.fb5 = cm_object_get_child_by_name(state->f1.reg.f2r2, "FB5");
	state->f1.fld.f2r2.fb6 = cm_object_get_child_by_name(state->f1.reg.f2r2, "FB6");
	state->f1.fld.f2r2.fb7 = cm_object_get_child_by_name(state->f1.reg.f2r2, "FB7");
	state->f1.fld.f2r2.fb8 = cm_object_get_child_by_name(state->f1.reg.f2r2, "FB8");
	state->f1.fld.f2r2.fb9 = cm_object_get_child_by_name(state->f1.reg.f2r2, "FB9");
	state->f1.fld.f2r2.fb10 = cm_object_get_child_by_name(state->f1.reg.f2r2, "FB10");
	state->f1.fld.f2r2.fb11 = cm_object_get_child_by_name(state->f1.reg.f2r2, "FB11");
	state->f1.fld.f2r2.fb12 = cm_object_get_child_by_name(state->f1.reg.f2r2, "FB12");
	state->f1.fld.f2r2.fb13 = cm_object_get_child_by_name(state->f1.reg.f2r2, "FB13");
	state->f1.fld.f2r2.fb14 = cm_object_get_child_by_name(state->f1.reg.f2r2, "FB14");
	state->f1.fld.f2r2.fb15 = cm_object_get_child_by_name(state->f1.reg.f2r2, "FB15");
	state->f1.fld.f2r2.fb16 = cm_object_get_child_by_name(state->f1.reg.f2r2, "FB16");
	state->f1.fld.f2r2.fb17 = cm_object_get_child_by_name(state->f1.reg.f2r2, "FB17");
	state->f1.fld.f2r2.fb18 = cm_object_get_child_by_name(state->f1.reg.f2r2, "FB18");
	state->f1.fld.f2r2.fb19 = cm_object_get_child_by_name(state->f1.reg.f2r2, "FB19");
	state->f1.fld.f2r2.fb20 = cm_object_get_child_by_name(state->f1.reg.f2r2, "FB20");
	state->f1.fld.f2r2.fb21 = cm_object_get_child_by_name(state->f1.reg.f2r2, "FB21");
	state->f1.fld.f2r2.fb22 = cm_object_get_child_by_name(state->f1.reg.f2r2, "FB22");
	state->f1.fld.f2r2.fb23 = cm_object_get_child_by_name(state->f1.reg.f2r2, "FB23");
	state->f1.fld.f2r2.fb24 = cm_object_get_child_by_name(state->f1.reg.f2r2, "FB24");
	state->f1.fld.f2r2.fb25 = cm_object_get_child_by_name(state->f1.reg.f2r2, "FB25");
	state->f1.fld.f2r2.fb26 = cm_object_get_child_by_name(state->f1.reg.f2r2, "FB26");
	state->f1.fld.f2r2.fb27 = cm_object_get_child_by_name(state->f1.reg.f2r2, "FB27");
	state->f1.fld.f2r2.fb28 = cm_object_get_child_by_name(state->f1.reg.f2r2, "FB28");
	state->f1.fld.f2r2.fb29 = cm_object_get_child_by_name(state->f1.reg.f2r2, "FB29");
	state->f1.fld.f2r2.fb30 = cm_object_get_child_by_name(state->f1.reg.f2r2, "FB30");
	state->f1.fld.f2r2.fb31 = cm_object_get_child_by_name(state->f1.reg.f2r2, "FB31");

	// F3R1 bitfields.
	state->f1.fld.f3r1.fb0 = cm_object_get_child_by_name(state->f1.reg.f3r1, "FB0");
	state->f1.fld.f3r1.fb1 = cm_object_get_child_by_name(state->f1.reg.f3r1, "FB1");
	state->f1.fld.f3r1.fb2 = cm_object_get_child_by_name(state->f1.reg.f3r1, "FB2");
	state->f1.fld.f3r1.fb3 = cm_object_get_child_by_name(state->f1.reg.f3r1, "FB3");
	state->f1.fld.f3r1.fb4 = cm_object_get_child_by_name(state->f1.reg.f3r1, "FB4");
	state->f1.fld.f3r1.fb5 = cm_object_get_child_by_name(state->f1.reg.f3r1, "FB5");
	state->f1.fld.f3r1.fb6 = cm_object_get_child_by_name(state->f1.reg.f3r1, "FB6");
	state->f1.fld.f3r1.fb7 = cm_object_get_child_by_name(state->f1.reg.f3r1, "FB7");
	state->f1.fld.f3r1.fb8 = cm_object_get_child_by_name(state->f1.reg.f3r1, "FB8");
	state->f1.fld.f3r1.fb9 = cm_object_get_child_by_name(state->f1.reg.f3r1, "FB9");
	state->f1.fld.f3r1.fb10 = cm_object_get_child_by_name(state->f1.reg.f3r1, "FB10");
	state->f1.fld.f3r1.fb11 = cm_object_get_child_by_name(state->f1.reg.f3r1, "FB11");
	state->f1.fld.f3r1.fb12 = cm_object_get_child_by_name(state->f1.reg.f3r1, "FB12");
	state->f1.fld.f3r1.fb13 = cm_object_get_child_by_name(state->f1.reg.f3r1, "FB13");
	state->f1.fld.f3r1.fb14 = cm_object_get_child_by_name(state->f1.reg.f3r1, "FB14");
	state->f1.fld.f3r1.fb15 = cm_object_get_child_by_name(state->f1.reg.f3r1, "FB15");
	state->f1.fld.f3r1.fb16 = cm_object_get_child_by_name(state->f1.reg.f3r1, "FB16");
	state->f1.fld.f3r1.fb17 = cm_object_get_child_by_name(state->f1.reg.f3r1, "FB17");
	state->f1.fld.f3r1.fb18 = cm_object_get_child_by_name(state->f1.reg.f3r1, "FB18");
	state->f1.fld.f3r1.fb19 = cm_object_get_child_by_name(state->f1.reg.f3r1, "FB19");
	state->f1.fld.f3r1.fb20 = cm_object_get_child_by_name(state->f1.reg.f3r1, "FB20");
	state->f1.fld.f3r1.fb21 = cm_object_get_child_by_name(state->f1.reg.f3r1, "FB21");
	state->f1.fld.f3r1.fb22 = cm_object_get_child_by_name(state->f1.reg.f3r1, "FB22");
	state->f1.fld.f3r1.fb23 = cm_object_get_child_by_name(state->f1.reg.f3r1, "FB23");
	state->f1.fld.f3r1.fb24 = cm_object_get_child_by_name(state->f1.reg.f3r1, "FB24");
	state->f1.fld.f3r1.fb25 = cm_object_get_child_by_name(state->f1.reg.f3r1, "FB25");
	state->f1.fld.f3r1.fb26 = cm_object_get_child_by_name(state->f1.reg.f3r1, "FB26");
	state->f1.fld.f3r1.fb27 = cm_object_get_child_by_name(state->f1.reg.f3r1, "FB27");
	state->f1.fld.f3r1.fb28 = cm_object_get_child_by_name(state->f1.reg.f3r1, "FB28");
	state->f1.fld.f3r1.fb29 = cm_object_get_child_by_name(state->f1.reg.f3r1, "FB29");
	state->f1.fld.f3r1.fb30 = cm_object_get_child_by_name(state->f1.reg.f3r1, "FB30");
	state->f1.fld.f3r1.fb31 = cm_object_get_child_by_name(state->f1.reg.f3r1, "FB31");

	// F3R2 bitfields.
	state->f1.fld.f3r2.fb0 = cm_object_get_child_by_name(state->f1.reg.f3r2, "FB0");
	state->f1.fld.f3r2.fb1 = cm_object_get_child_by_name(state->f1.reg.f3r2, "FB1");
	state->f1.fld.f3r2.fb2 = cm_object_get_child_by_name(state->f1.reg.f3r2, "FB2");
	state->f1.fld.f3r2.fb3 = cm_object_get_child_by_name(state->f1.reg.f3r2, "FB3");
	state->f1.fld.f3r2.fb4 = cm_object_get_child_by_name(state->f1.reg.f3r2, "FB4");
	state->f1.fld.f3r2.fb5 = cm_object_get_child_by_name(state->f1.reg.f3r2, "FB5");
	state->f1.fld.f3r2.fb6 = cm_object_get_child_by_name(state->f1.reg.f3r2, "FB6");
	state->f1.fld.f3r2.fb7 = cm_object_get_child_by_name(state->f1.reg.f3r2, "FB7");
	state->f1.fld.f3r2.fb8 = cm_object_get_child_by_name(state->f1.reg.f3r2, "FB8");
	state->f1.fld.f3r2.fb9 = cm_object_get_child_by_name(state->f1.reg.f3r2, "FB9");
	state->f1.fld.f3r2.fb10 = cm_object_get_child_by_name(state->f1.reg.f3r2, "FB10");
	state->f1.fld.f3r2.fb11 = cm_object_get_child_by_name(state->f1.reg.f3r2, "FB11");
	state->f1.fld.f3r2.fb12 = cm_object_get_child_by_name(state->f1.reg.f3r2, "FB12");
	state->f1.fld.f3r2.fb13 = cm_object_get_child_by_name(state->f1.reg.f3r2, "FB13");
	state->f1.fld.f3r2.fb14 = cm_object_get_child_by_name(state->f1.reg.f3r2, "FB14");
	state->f1.fld.f3r2.fb15 = cm_object_get_child_by_name(state->f1.reg.f3r2, "FB15");
	state->f1.fld.f3r2.fb16 = cm_object_get_child_by_name(state->f1.reg.f3r2, "FB16");
	state->f1.fld.f3r2.fb17 = cm_object_get_child_by_name(state->f1.reg.f3r2, "FB17");
	state->f1.fld.f3r2.fb18 = cm_object_get_child_by_name(state->f1.reg.f3r2, "FB18");
	state->f1.fld.f3r2.fb19 = cm_object_get_child_by_name(state->f1.reg.f3r2, "FB19");
	state->f1.fld.f3r2.fb20 = cm_object_get_child_by_name(state->f1.reg.f3r2, "FB20");
	state->f1.fld.f3r2.fb21 = cm_object_get_child_by_name(state->f1.reg.f3r2, "FB21");
	state->f1.fld.f3r2.fb22 = cm_object_get_child_by_name(state->f1.reg.f3r2, "FB22");
	state->f1.fld.f3r2.fb23 = cm_object_get_child_by_name(state->f1.reg.f3r2, "FB23");
	state->f1.fld.f3r2.fb24 = cm_object_get_child_by_name(state->f1.reg.f3r2, "FB24");
	state->f1.fld.f3r2.fb25 = cm_object_get_child_by_name(state->f1.reg.f3r2, "FB25");
	state->f1.fld.f3r2.fb26 = cm_object_get_child_by_name(state->f1.reg.f3r2, "FB26");
	state->f1.fld.f3r2.fb27 = cm_object_get_child_by_name(state->f1.reg.f3r2, "FB27");
	state->f1.fld.f3r2.fb28 = cm_object_get_child_by_name(state->f1.reg.f3r2, "FB28");
	state->f1.fld.f3r2.fb29 = cm_object_get_child_by_name(state->f1.reg.f3r2, "FB29");
	state->f1.fld.f3r2.fb30 = cm_object_get_child_by_name(state->f1.reg.f3r2, "FB30");
	state->f1.fld.f3r2.fb31 = cm_object_get_child_by_name(state->f1.reg.f3r2, "FB31");

	// F4R1 bitfields.
	state->f1.fld.f4r1.fb0 = cm_object_get_child_by_name(state->f1.reg.f4r1, "FB0");
	state->f1.fld.f4r1.fb1 = cm_object_get_child_by_name(state->f1.reg.f4r1, "FB1");
	state->f1.fld.f4r1.fb2 = cm_object_get_child_by_name(state->f1.reg.f4r1, "FB2");
	state->f1.fld.f4r1.fb3 = cm_object_get_child_by_name(state->f1.reg.f4r1, "FB3");
	state->f1.fld.f4r1.fb4 = cm_object_get_child_by_name(state->f1.reg.f4r1, "FB4");
	state->f1.fld.f4r1.fb5 = cm_object_get_child_by_name(state->f1.reg.f4r1, "FB5");
	state->f1.fld.f4r1.fb6 = cm_object_get_child_by_name(state->f1.reg.f4r1, "FB6");
	state->f1.fld.f4r1.fb7 = cm_object_get_child_by_name(state->f1.reg.f4r1, "FB7");
	state->f1.fld.f4r1.fb8 = cm_object_get_child_by_name(state->f1.reg.f4r1, "FB8");
	state->f1.fld.f4r1.fb9 = cm_object_get_child_by_name(state->f1.reg.f4r1, "FB9");
	state->f1.fld.f4r1.fb10 = cm_object_get_child_by_name(state->f1.reg.f4r1, "FB10");
	state->f1.fld.f4r1.fb11 = cm_object_get_child_by_name(state->f1.reg.f4r1, "FB11");
	state->f1.fld.f4r1.fb12 = cm_object_get_child_by_name(state->f1.reg.f4r1, "FB12");
	state->f1.fld.f4r1.fb13 = cm_object_get_child_by_name(state->f1.reg.f4r1, "FB13");
	state->f1.fld.f4r1.fb14 = cm_object_get_child_by_name(state->f1.reg.f4r1, "FB14");
	state->f1.fld.f4r1.fb15 = cm_object_get_child_by_name(state->f1.reg.f4r1, "FB15");
	state->f1.fld.f4r1.fb16 = cm_object_get_child_by_name(state->f1.reg.f4r1, "FB16");
	state->f1.fld.f4r1.fb17 = cm_object_get_child_by_name(state->f1.reg.f4r1, "FB17");
	state->f1.fld.f4r1.fb18 = cm_object_get_child_by_name(state->f1.reg.f4r1, "FB18");
	state->f1.fld.f4r1.fb19 = cm_object_get_child_by_name(state->f1.reg.f4r1, "FB19");
	state->f1.fld.f4r1.fb20 = cm_object_get_child_by_name(state->f1.reg.f4r1, "FB20");
	state->f1.fld.f4r1.fb21 = cm_object_get_child_by_name(state->f1.reg.f4r1, "FB21");
	state->f1.fld.f4r1.fb22 = cm_object_get_child_by_name(state->f1.reg.f4r1, "FB22");
	state->f1.fld.f4r1.fb23 = cm_object_get_child_by_name(state->f1.reg.f4r1, "FB23");
	state->f1.fld.f4r1.fb24 = cm_object_get_child_by_name(state->f1.reg.f4r1, "FB24");
	state->f1.fld.f4r1.fb25 = cm_object_get_child_by_name(state->f1.reg.f4r1, "FB25");
	state->f1.fld.f4r1.fb26 = cm_object_get_child_by_name(state->f1.reg.f4r1, "FB26");
	state->f1.fld.f4r1.fb27 = cm_object_get_child_by_name(state->f1.reg.f4r1, "FB27");
	state->f1.fld.f4r1.fb28 = cm_object_get_child_by_name(state->f1.reg.f4r1, "FB28");
	state->f1.fld.f4r1.fb29 = cm_object_get_child_by_name(state->f1.reg.f4r1, "FB29");
	state->f1.fld.f4r1.fb30 = cm_object_get_child_by_name(state->f1.reg.f4r1, "FB30");
	state->f1.fld.f4r1.fb31 = cm_object_get_child_by_name(state->f1.reg.f4r1, "FB31");

	// F4R2 bitfields.
	state->f1.fld.f4r2.fb0 = cm_object_get_child_by_name(state->f1.reg.f4r2, "FB0");
	state->f1.fld.f4r2.fb1 = cm_object_get_child_by_name(state->f1.reg.f4r2, "FB1");
	state->f1.fld.f4r2.fb2 = cm_object_get_child_by_name(state->f1.reg.f4r2, "FB2");
	state->f1.fld.f4r2.fb3 = cm_object_get_child_by_name(state->f1.reg.f4r2, "FB3");
	state->f1.fld.f4r2.fb4 = cm_object_get_child_by_name(state->f1.reg.f4r2, "FB4");
	state->f1.fld.f4r2.fb5 = cm_object_get_child_by_name(state->f1.reg.f4r2, "FB5");
	state->f1.fld.f4r2.fb6 = cm_object_get_child_by_name(state->f1.reg.f4r2, "FB6");
	state->f1.fld.f4r2.fb7 = cm_object_get_child_by_name(state->f1.reg.f4r2, "FB7");
	state->f1.fld.f4r2.fb8 = cm_object_get_child_by_name(state->f1.reg.f4r2, "FB8");
	state->f1.fld.f4r2.fb9 = cm_object_get_child_by_name(state->f1.reg.f4r2, "FB9");
	state->f1.fld.f4r2.fb10 = cm_object_get_child_by_name(state->f1.reg.f4r2, "FB10");
	state->f1.fld.f4r2.fb11 = cm_object_get_child_by_name(state->f1.reg.f4r2, "FB11");
	state->f1.fld.f4r2.fb12 = cm_object_get_child_by_name(state->f1.reg.f4r2, "FB12");
	state->f1.fld.f4r2.fb13 = cm_object_get_child_by_name(state->f1.reg.f4r2, "FB13");
	state->f1.fld.f4r2.fb14 = cm_object_get_child_by_name(state->f1.reg.f4r2, "FB14");
	state->f1.fld.f4r2.fb15 = cm_object_get_child_by_name(state->f1.reg.f4r2, "FB15");
	state->f1.fld.f4r2.fb16 = cm_object_get_child_by_name(state->f1.reg.f4r2, "FB16");
	state->f1.fld.f4r2.fb17 = cm_object_get_child_by_name(state->f1.reg.f4r2, "FB17");
	state->f1.fld.f4r2.fb18 = cm_object_get_child_by_name(state->f1.reg.f4r2, "FB18");
	state->f1.fld.f4r2.fb19 = cm_object_get_child_by_name(state->f1.reg.f4r2, "FB19");
	state->f1.fld.f4r2.fb20 = cm_object_get_child_by_name(state->f1.reg.f4r2, "FB20");
	state->f1.fld.f4r2.fb21 = cm_object_get_child_by_name(state->f1.reg.f4r2, "FB21");
	state->f1.fld.f4r2.fb22 = cm_object_get_child_by_name(state->f1.reg.f4r2, "FB22");
	state->f1.fld.f4r2.fb23 = cm_object_get_child_by_name(state->f1.reg.f4r2, "FB23");
	state->f1.fld.f4r2.fb24 = cm_object_get_child_by_name(state->f1.reg.f4r2, "FB24");
	state->f1.fld.f4r2.fb25 = cm_object_get_child_by_name(state->f1.reg.f4r2, "FB25");
	state->f1.fld.f4r2.fb26 = cm_object_get_child_by_name(state->f1.reg.f4r2, "FB26");
	state->f1.fld.f4r2.fb27 = cm_object_get_child_by_name(state->f1.reg.f4r2, "FB27");
	state->f1.fld.f4r2.fb28 = cm_object_get_child_by_name(state->f1.reg.f4r2, "FB28");
	state->f1.fld.f4r2.fb29 = cm_object_get_child_by_name(state->f1.reg.f4r2, "FB29");
	state->f1.fld.f4r2.fb30 = cm_object_get_child_by_name(state->f1.reg.f4r2, "FB30");
	state->f1.fld.f4r2.fb31 = cm_object_get_child_by_name(state->f1.reg.f4r2, "FB31");

	// F5R1 bitfields.
	state->f1.fld.f5r1.fb0 = cm_object_get_child_by_name(state->f1.reg.f5r1, "FB0");
	state->f1.fld.f5r1.fb1 = cm_object_get_child_by_name(state->f1.reg.f5r1, "FB1");
	state->f1.fld.f5r1.fb2 = cm_object_get_child_by_name(state->f1.reg.f5r1, "FB2");
	state->f1.fld.f5r1.fb3 = cm_object_get_child_by_name(state->f1.reg.f5r1, "FB3");
	state->f1.fld.f5r1.fb4 = cm_object_get_child_by_name(state->f1.reg.f5r1, "FB4");
	state->f1.fld.f5r1.fb5 = cm_object_get_child_by_name(state->f1.reg.f5r1, "FB5");
	state->f1.fld.f5r1.fb6 = cm_object_get_child_by_name(state->f1.reg.f5r1, "FB6");
	state->f1.fld.f5r1.fb7 = cm_object_get_child_by_name(state->f1.reg.f5r1, "FB7");
	state->f1.fld.f5r1.fb8 = cm_object_get_child_by_name(state->f1.reg.f5r1, "FB8");
	state->f1.fld.f5r1.fb9 = cm_object_get_child_by_name(state->f1.reg.f5r1, "FB9");
	state->f1.fld.f5r1.fb10 = cm_object_get_child_by_name(state->f1.reg.f5r1, "FB10");
	state->f1.fld.f5r1.fb11 = cm_object_get_child_by_name(state->f1.reg.f5r1, "FB11");
	state->f1.fld.f5r1.fb12 = cm_object_get_child_by_name(state->f1.reg.f5r1, "FB12");
	state->f1.fld.f5r1.fb13 = cm_object_get_child_by_name(state->f1.reg.f5r1, "FB13");
	state->f1.fld.f5r1.fb14 = cm_object_get_child_by_name(state->f1.reg.f5r1, "FB14");
	state->f1.fld.f5r1.fb15 = cm_object_get_child_by_name(state->f1.reg.f5r1, "FB15");
	state->f1.fld.f5r1.fb16 = cm_object_get_child_by_name(state->f1.reg.f5r1, "FB16");
	state->f1.fld.f5r1.fb17 = cm_object_get_child_by_name(state->f1.reg.f5r1, "FB17");
	state->f1.fld.f5r1.fb18 = cm_object_get_child_by_name(state->f1.reg.f5r1, "FB18");
	state->f1.fld.f5r1.fb19 = cm_object_get_child_by_name(state->f1.reg.f5r1, "FB19");
	state->f1.fld.f5r1.fb20 = cm_object_get_child_by_name(state->f1.reg.f5r1, "FB20");
	state->f1.fld.f5r1.fb21 = cm_object_get_child_by_name(state->f1.reg.f5r1, "FB21");
	state->f1.fld.f5r1.fb22 = cm_object_get_child_by_name(state->f1.reg.f5r1, "FB22");
	state->f1.fld.f5r1.fb23 = cm_object_get_child_by_name(state->f1.reg.f5r1, "FB23");
	state->f1.fld.f5r1.fb24 = cm_object_get_child_by_name(state->f1.reg.f5r1, "FB24");
	state->f1.fld.f5r1.fb25 = cm_object_get_child_by_name(state->f1.reg.f5r1, "FB25");
	state->f1.fld.f5r1.fb26 = cm_object_get_child_by_name(state->f1.reg.f5r1, "FB26");
	state->f1.fld.f5r1.fb27 = cm_object_get_child_by_name(state->f1.reg.f5r1, "FB27");
	state->f1.fld.f5r1.fb28 = cm_object_get_child_by_name(state->f1.reg.f5r1, "FB28");
	state->f1.fld.f5r1.fb29 = cm_object_get_child_by_name(state->f1.reg.f5r1, "FB29");
	state->f1.fld.f5r1.fb30 = cm_object_get_child_by_name(state->f1.reg.f5r1, "FB30");
	state->f1.fld.f5r1.fb31 = cm_object_get_child_by_name(state->f1.reg.f5r1, "FB31");

	// F5R2 bitfields.
	state->f1.fld.f5r2.fb0 = cm_object_get_child_by_name(state->f1.reg.f5r2, "FB0");
	state->f1.fld.f5r2.fb1 = cm_object_get_child_by_name(state->f1.reg.f5r2, "FB1");
	state->f1.fld.f5r2.fb2 = cm_object_get_child_by_name(state->f1.reg.f5r2, "FB2");
	state->f1.fld.f5r2.fb3 = cm_object_get_child_by_name(state->f1.reg.f5r2, "FB3");
	state->f1.fld.f5r2.fb4 = cm_object_get_child_by_name(state->f1.reg.f5r2, "FB4");
	state->f1.fld.f5r2.fb5 = cm_object_get_child_by_name(state->f1.reg.f5r2, "FB5");
	state->f1.fld.f5r2.fb6 = cm_object_get_child_by_name(state->f1.reg.f5r2, "FB6");
	state->f1.fld.f5r2.fb7 = cm_object_get_child_by_name(state->f1.reg.f5r2, "FB7");
	state->f1.fld.f5r2.fb8 = cm_object_get_child_by_name(state->f1.reg.f5r2, "FB8");
	state->f1.fld.f5r2.fb9 = cm_object_get_child_by_name(state->f1.reg.f5r2, "FB9");
	state->f1.fld.f5r2.fb10 = cm_object_get_child_by_name(state->f1.reg.f5r2, "FB10");
	state->f1.fld.f5r2.fb11 = cm_object_get_child_by_name(state->f1.reg.f5r2, "FB11");
	state->f1.fld.f5r2.fb12 = cm_object_get_child_by_name(state->f1.reg.f5r2, "FB12");
	state->f1.fld.f5r2.fb13 = cm_object_get_child_by_name(state->f1.reg.f5r2, "FB13");
	state->f1.fld.f5r2.fb14 = cm_object_get_child_by_name(state->f1.reg.f5r2, "FB14");
	state->f1.fld.f5r2.fb15 = cm_object_get_child_by_name(state->f1.reg.f5r2, "FB15");
	state->f1.fld.f5r2.fb16 = cm_object_get_child_by_name(state->f1.reg.f5r2, "FB16");
	state->f1.fld.f5r2.fb17 = cm_object_get_child_by_name(state->f1.reg.f5r2, "FB17");
	state->f1.fld.f5r2.fb18 = cm_object_get_child_by_name(state->f1.reg.f5r2, "FB18");
	state->f1.fld.f5r2.fb19 = cm_object_get_child_by_name(state->f1.reg.f5r2, "FB19");
	state->f1.fld.f5r2.fb20 = cm_object_get_child_by_name(state->f1.reg.f5r2, "FB20");
	state->f1.fld.f5r2.fb21 = cm_object_get_child_by_name(state->f1.reg.f5r2, "FB21");
	state->f1.fld.f5r2.fb22 = cm_object_get_child_by_name(state->f1.reg.f5r2, "FB22");
	state->f1.fld.f5r2.fb23 = cm_object_get_child_by_name(state->f1.reg.f5r2, "FB23");
	state->f1.fld.f5r2.fb24 = cm_object_get_child_by_name(state->f1.reg.f5r2, "FB24");
	state->f1.fld.f5r2.fb25 = cm_object_get_child_by_name(state->f1.reg.f5r2, "FB25");
	state->f1.fld.f5r2.fb26 = cm_object_get_child_by_name(state->f1.reg.f5r2, "FB26");
	state->f1.fld.f5r2.fb27 = cm_object_get_child_by_name(state->f1.reg.f5r2, "FB27");
	state->f1.fld.f5r2.fb28 = cm_object_get_child_by_name(state->f1.reg.f5r2, "FB28");
	state->f1.fld.f5r2.fb29 = cm_object_get_child_by_name(state->f1.reg.f5r2, "FB29");
	state->f1.fld.f5r2.fb30 = cm_object_get_child_by_name(state->f1.reg.f5r2, "FB30");
	state->f1.fld.f5r2.fb31 = cm_object_get_child_by_name(state->f1.reg.f5r2, "FB31");

	// F6R1 bitfields.
	state->f1.fld.f6r1.fb0 = cm_object_get_child_by_name(state->f1.reg.f6r1, "FB0");
	state->f1.fld.f6r1.fb1 = cm_object_get_child_by_name(state->f1.reg.f6r1, "FB1");
	state->f1.fld.f6r1.fb2 = cm_object_get_child_by_name(state->f1.reg.f6r1, "FB2");
	state->f1.fld.f6r1.fb3 = cm_object_get_child_by_name(state->f1.reg.f6r1, "FB3");
	state->f1.fld.f6r1.fb4 = cm_object_get_child_by_name(state->f1.reg.f6r1, "FB4");
	state->f1.fld.f6r1.fb5 = cm_object_get_child_by_name(state->f1.reg.f6r1, "FB5");
	state->f1.fld.f6r1.fb6 = cm_object_get_child_by_name(state->f1.reg.f6r1, "FB6");
	state->f1.fld.f6r1.fb7 = cm_object_get_child_by_name(state->f1.reg.f6r1, "FB7");
	state->f1.fld.f6r1.fb8 = cm_object_get_child_by_name(state->f1.reg.f6r1, "FB8");
	state->f1.fld.f6r1.fb9 = cm_object_get_child_by_name(state->f1.reg.f6r1, "FB9");
	state->f1.fld.f6r1.fb10 = cm_object_get_child_by_name(state->f1.reg.f6r1, "FB10");
	state->f1.fld.f6r1.fb11 = cm_object_get_child_by_name(state->f1.reg.f6r1, "FB11");
	state->f1.fld.f6r1.fb12 = cm_object_get_child_by_name(state->f1.reg.f6r1, "FB12");
	state->f1.fld.f6r1.fb13 = cm_object_get_child_by_name(state->f1.reg.f6r1, "FB13");
	state->f1.fld.f6r1.fb14 = cm_object_get_child_by_name(state->f1.reg.f6r1, "FB14");
	state->f1.fld.f6r1.fb15 = cm_object_get_child_by_name(state->f1.reg.f6r1, "FB15");
	state->f1.fld.f6r1.fb16 = cm_object_get_child_by_name(state->f1.reg.f6r1, "FB16");
	state->f1.fld.f6r1.fb17 = cm_object_get_child_by_name(state->f1.reg.f6r1, "FB17");
	state->f1.fld.f6r1.fb18 = cm_object_get_child_by_name(state->f1.reg.f6r1, "FB18");
	state->f1.fld.f6r1.fb19 = cm_object_get_child_by_name(state->f1.reg.f6r1, "FB19");
	state->f1.fld.f6r1.fb20 = cm_object_get_child_by_name(state->f1.reg.f6r1, "FB20");
	state->f1.fld.f6r1.fb21 = cm_object_get_child_by_name(state->f1.reg.f6r1, "FB21");
	state->f1.fld.f6r1.fb22 = cm_object_get_child_by_name(state->f1.reg.f6r1, "FB22");
	state->f1.fld.f6r1.fb23 = cm_object_get_child_by_name(state->f1.reg.f6r1, "FB23");
	state->f1.fld.f6r1.fb24 = cm_object_get_child_by_name(state->f1.reg.f6r1, "FB24");
	state->f1.fld.f6r1.fb25 = cm_object_get_child_by_name(state->f1.reg.f6r1, "FB25");
	state->f1.fld.f6r1.fb26 = cm_object_get_child_by_name(state->f1.reg.f6r1, "FB26");
	state->f1.fld.f6r1.fb27 = cm_object_get_child_by_name(state->f1.reg.f6r1, "FB27");
	state->f1.fld.f6r1.fb28 = cm_object_get_child_by_name(state->f1.reg.f6r1, "FB28");
	state->f1.fld.f6r1.fb29 = cm_object_get_child_by_name(state->f1.reg.f6r1, "FB29");
	state->f1.fld.f6r1.fb30 = cm_object_get_child_by_name(state->f1.reg.f6r1, "FB30");
	state->f1.fld.f6r1.fb31 = cm_object_get_child_by_name(state->f1.reg.f6r1, "FB31");

	// F6R2 bitfields.
	state->f1.fld.f6r2.fb0 = cm_object_get_child_by_name(state->f1.reg.f6r2, "FB0");
	state->f1.fld.f6r2.fb1 = cm_object_get_child_by_name(state->f1.reg.f6r2, "FB1");
	state->f1.fld.f6r2.fb2 = cm_object_get_child_by_name(state->f1.reg.f6r2, "FB2");
	state->f1.fld.f6r2.fb3 = cm_object_get_child_by_name(state->f1.reg.f6r2, "FB3");
	state->f1.fld.f6r2.fb4 = cm_object_get_child_by_name(state->f1.reg.f6r2, "FB4");
	state->f1.fld.f6r2.fb5 = cm_object_get_child_by_name(state->f1.reg.f6r2, "FB5");
	state->f1.fld.f6r2.fb6 = cm_object_get_child_by_name(state->f1.reg.f6r2, "FB6");
	state->f1.fld.f6r2.fb7 = cm_object_get_child_by_name(state->f1.reg.f6r2, "FB7");
	state->f1.fld.f6r2.fb8 = cm_object_get_child_by_name(state->f1.reg.f6r2, "FB8");
	state->f1.fld.f6r2.fb9 = cm_object_get_child_by_name(state->f1.reg.f6r2, "FB9");
	state->f1.fld.f6r2.fb10 = cm_object_get_child_by_name(state->f1.reg.f6r2, "FB10");
	state->f1.fld.f6r2.fb11 = cm_object_get_child_by_name(state->f1.reg.f6r2, "FB11");
	state->f1.fld.f6r2.fb12 = cm_object_get_child_by_name(state->f1.reg.f6r2, "FB12");
	state->f1.fld.f6r2.fb13 = cm_object_get_child_by_name(state->f1.reg.f6r2, "FB13");
	state->f1.fld.f6r2.fb14 = cm_object_get_child_by_name(state->f1.reg.f6r2, "FB14");
	state->f1.fld.f6r2.fb15 = cm_object_get_child_by_name(state->f1.reg.f6r2, "FB15");
	state->f1.fld.f6r2.fb16 = cm_object_get_child_by_name(state->f1.reg.f6r2, "FB16");
	state->f1.fld.f6r2.fb17 = cm_object_get_child_by_name(state->f1.reg.f6r2, "FB17");
	state->f1.fld.f6r2.fb18 = cm_object_get_child_by_name(state->f1.reg.f6r2, "FB18");
	state->f1.fld.f6r2.fb19 = cm_object_get_child_by_name(state->f1.reg.f6r2, "FB19");
	state->f1.fld.f6r2.fb20 = cm_object_get_child_by_name(state->f1.reg.f6r2, "FB20");
	state->f1.fld.f6r2.fb21 = cm_object_get_child_by_name(state->f1.reg.f6r2, "FB21");
	state->f1.fld.f6r2.fb22 = cm_object_get_child_by_name(state->f1.reg.f6r2, "FB22");
	state->f1.fld.f6r2.fb23 = cm_object_get_child_by_name(state->f1.reg.f6r2, "FB23");
	state->f1.fld.f6r2.fb24 = cm_object_get_child_by_name(state->f1.reg.f6r2, "FB24");
	state->f1.fld.f6r2.fb25 = cm_object_get_child_by_name(state->f1.reg.f6r2, "FB25");
	state->f1.fld.f6r2.fb26 = cm_object_get_child_by_name(state->f1.reg.f6r2, "FB26");
	state->f1.fld.f6r2.fb27 = cm_object_get_child_by_name(state->f1.reg.f6r2, "FB27");
	state->f1.fld.f6r2.fb28 = cm_object_get_child_by_name(state->f1.reg.f6r2, "FB28");
	state->f1.fld.f6r2.fb29 = cm_object_get_child_by_name(state->f1.reg.f6r2, "FB29");
	state->f1.fld.f6r2.fb30 = cm_object_get_child_by_name(state->f1.reg.f6r2, "FB30");
	state->f1.fld.f6r2.fb31 = cm_object_get_child_by_name(state->f1.reg.f6r2, "FB31");

	// F7R1 bitfields.
	state->f1.fld.f7r1.fb0 = cm_object_get_child_by_name(state->f1.reg.f7r1, "FB0");
	state->f1.fld.f7r1.fb1 = cm_object_get_child_by_name(state->f1.reg.f7r1, "FB1");
	state->f1.fld.f7r1.fb2 = cm_object_get_child_by_name(state->f1.reg.f7r1, "FB2");
	state->f1.fld.f7r1.fb3 = cm_object_get_child_by_name(state->f1.reg.f7r1, "FB3");
	state->f1.fld.f7r1.fb4 = cm_object_get_child_by_name(state->f1.reg.f7r1, "FB4");
	state->f1.fld.f7r1.fb5 = cm_object_get_child_by_name(state->f1.reg.f7r1, "FB5");
	state->f1.fld.f7r1.fb6 = cm_object_get_child_by_name(state->f1.reg.f7r1, "FB6");
	state->f1.fld.f7r1.fb7 = cm_object_get_child_by_name(state->f1.reg.f7r1, "FB7");
	state->f1.fld.f7r1.fb8 = cm_object_get_child_by_name(state->f1.reg.f7r1, "FB8");
	state->f1.fld.f7r1.fb9 = cm_object_get_child_by_name(state->f1.reg.f7r1, "FB9");
	state->f1.fld.f7r1.fb10 = cm_object_get_child_by_name(state->f1.reg.f7r1, "FB10");
	state->f1.fld.f7r1.fb11 = cm_object_get_child_by_name(state->f1.reg.f7r1, "FB11");
	state->f1.fld.f7r1.fb12 = cm_object_get_child_by_name(state->f1.reg.f7r1, "FB12");
	state->f1.fld.f7r1.fb13 = cm_object_get_child_by_name(state->f1.reg.f7r1, "FB13");
	state->f1.fld.f7r1.fb14 = cm_object_get_child_by_name(state->f1.reg.f7r1, "FB14");
	state->f1.fld.f7r1.fb15 = cm_object_get_child_by_name(state->f1.reg.f7r1, "FB15");
	state->f1.fld.f7r1.fb16 = cm_object_get_child_by_name(state->f1.reg.f7r1, "FB16");
	state->f1.fld.f7r1.fb17 = cm_object_get_child_by_name(state->f1.reg.f7r1, "FB17");
	state->f1.fld.f7r1.fb18 = cm_object_get_child_by_name(state->f1.reg.f7r1, "FB18");
	state->f1.fld.f7r1.fb19 = cm_object_get_child_by_name(state->f1.reg.f7r1, "FB19");
	state->f1.fld.f7r1.fb20 = cm_object_get_child_by_name(state->f1.reg.f7r1, "FB20");
	state->f1.fld.f7r1.fb21 = cm_object_get_child_by_name(state->f1.reg.f7r1, "FB21");
	state->f1.fld.f7r1.fb22 = cm_object_get_child_by_name(state->f1.reg.f7r1, "FB22");
	state->f1.fld.f7r1.fb23 = cm_object_get_child_by_name(state->f1.reg.f7r1, "FB23");
	state->f1.fld.f7r1.fb24 = cm_object_get_child_by_name(state->f1.reg.f7r1, "FB24");
	state->f1.fld.f7r1.fb25 = cm_object_get_child_by_name(state->f1.reg.f7r1, "FB25");
	state->f1.fld.f7r1.fb26 = cm_object_get_child_by_name(state->f1.reg.f7r1, "FB26");
	state->f1.fld.f7r1.fb27 = cm_object_get_child_by_name(state->f1.reg.f7r1, "FB27");
	state->f1.fld.f7r1.fb28 = cm_object_get_child_by_name(state->f1.reg.f7r1, "FB28");
	state->f1.fld.f7r1.fb29 = cm_object_get_child_by_name(state->f1.reg.f7r1, "FB29");
	state->f1.fld.f7r1.fb30 = cm_object_get_child_by_name(state->f1.reg.f7r1, "FB30");
	state->f1.fld.f7r1.fb31 = cm_object_get_child_by_name(state->f1.reg.f7r1, "FB31");

	// F7R2 bitfields.
	state->f1.fld.f7r2.fb0 = cm_object_get_child_by_name(state->f1.reg.f7r2, "FB0");
	state->f1.fld.f7r2.fb1 = cm_object_get_child_by_name(state->f1.reg.f7r2, "FB1");
	state->f1.fld.f7r2.fb2 = cm_object_get_child_by_name(state->f1.reg.f7r2, "FB2");
	state->f1.fld.f7r2.fb3 = cm_object_get_child_by_name(state->f1.reg.f7r2, "FB3");
	state->f1.fld.f7r2.fb4 = cm_object_get_child_by_name(state->f1.reg.f7r2, "FB4");
	state->f1.fld.f7r2.fb5 = cm_object_get_child_by_name(state->f1.reg.f7r2, "FB5");
	state->f1.fld.f7r2.fb6 = cm_object_get_child_by_name(state->f1.reg.f7r2, "FB6");
	state->f1.fld.f7r2.fb7 = cm_object_get_child_by_name(state->f1.reg.f7r2, "FB7");
	state->f1.fld.f7r2.fb8 = cm_object_get_child_by_name(state->f1.reg.f7r2, "FB8");
	state->f1.fld.f7r2.fb9 = cm_object_get_child_by_name(state->f1.reg.f7r2, "FB9");
	state->f1.fld.f7r2.fb10 = cm_object_get_child_by_name(state->f1.reg.f7r2, "FB10");
	state->f1.fld.f7r2.fb11 = cm_object_get_child_by_name(state->f1.reg.f7r2, "FB11");
	state->f1.fld.f7r2.fb12 = cm_object_get_child_by_name(state->f1.reg.f7r2, "FB12");
	state->f1.fld.f7r2.fb13 = cm_object_get_child_by_name(state->f1.reg.f7r2, "FB13");
	state->f1.fld.f7r2.fb14 = cm_object_get_child_by_name(state->f1.reg.f7r2, "FB14");
	state->f1.fld.f7r2.fb15 = cm_object_get_child_by_name(state->f1.reg.f7r2, "FB15");
	state->f1.fld.f7r2.fb16 = cm_object_get_child_by_name(state->f1.reg.f7r2, "FB16");
	state->f1.fld.f7r2.fb17 = cm_object_get_child_by_name(state->f1.reg.f7r2, "FB17");
	state->f1.fld.f7r2.fb18 = cm_object_get_child_by_name(state->f1.reg.f7r2, "FB18");
	state->f1.fld.f7r2.fb19 = cm_object_get_child_by_name(state->f1.reg.f7r2, "FB19");
	state->f1.fld.f7r2.fb20 = cm_object_get_child_by_name(state->f1.reg.f7r2, "FB20");
	state->f1.fld.f7r2.fb21 = cm_object_get_child_by_name(state->f1.reg.f7r2, "FB21");
	state->f1.fld.f7r2.fb22 = cm_object_get_child_by_name(state->f1.reg.f7r2, "FB22");
	state->f1.fld.f7r2.fb23 = cm_object_get_child_by_name(state->f1.reg.f7r2, "FB23");
	state->f1.fld.f7r2.fb24 = cm_object_get_child_by_name(state->f1.reg.f7r2, "FB24");
	state->f1.fld.f7r2.fb25 = cm_object_get_child_by_name(state->f1.reg.f7r2, "FB25");
	state->f1.fld.f7r2.fb26 = cm_object_get_child_by_name(state->f1.reg.f7r2, "FB26");
	state->f1.fld.f7r2.fb27 = cm_object_get_child_by_name(state->f1.reg.f7r2, "FB27");
	state->f1.fld.f7r2.fb28 = cm_object_get_child_by_name(state->f1.reg.f7r2, "FB28");
	state->f1.fld.f7r2.fb29 = cm_object_get_child_by_name(state->f1.reg.f7r2, "FB29");
	state->f1.fld.f7r2.fb30 = cm_object_get_child_by_name(state->f1.reg.f7r2, "FB30");
	state->f1.fld.f7r2.fb31 = cm_object_get_child_by_name(state->f1.reg.f7r2, "FB31");

	// F8R1 bitfields.
	state->f1.fld.f8r1.fb0 = cm_object_get_child_by_name(state->f1.reg.f8r1, "FB0");
	state->f1.fld.f8r1.fb1 = cm_object_get_child_by_name(state->f1.reg.f8r1, "FB1");
	state->f1.fld.f8r1.fb2 = cm_object_get_child_by_name(state->f1.reg.f8r1, "FB2");
	state->f1.fld.f8r1.fb3 = cm_object_get_child_by_name(state->f1.reg.f8r1, "FB3");
	state->f1.fld.f8r1.fb4 = cm_object_get_child_by_name(state->f1.reg.f8r1, "FB4");
	state->f1.fld.f8r1.fb5 = cm_object_get_child_by_name(state->f1.reg.f8r1, "FB5");
	state->f1.fld.f8r1.fb6 = cm_object_get_child_by_name(state->f1.reg.f8r1, "FB6");
	state->f1.fld.f8r1.fb7 = cm_object_get_child_by_name(state->f1.reg.f8r1, "FB7");
	state->f1.fld.f8r1.fb8 = cm_object_get_child_by_name(state->f1.reg.f8r1, "FB8");
	state->f1.fld.f8r1.fb9 = cm_object_get_child_by_name(state->f1.reg.f8r1, "FB9");
	state->f1.fld.f8r1.fb10 = cm_object_get_child_by_name(state->f1.reg.f8r1, "FB10");
	state->f1.fld.f8r1.fb11 = cm_object_get_child_by_name(state->f1.reg.f8r1, "FB11");
	state->f1.fld.f8r1.fb12 = cm_object_get_child_by_name(state->f1.reg.f8r1, "FB12");
	state->f1.fld.f8r1.fb13 = cm_object_get_child_by_name(state->f1.reg.f8r1, "FB13");
	state->f1.fld.f8r1.fb14 = cm_object_get_child_by_name(state->f1.reg.f8r1, "FB14");
	state->f1.fld.f8r1.fb15 = cm_object_get_child_by_name(state->f1.reg.f8r1, "FB15");
	state->f1.fld.f8r1.fb16 = cm_object_get_child_by_name(state->f1.reg.f8r1, "FB16");
	state->f1.fld.f8r1.fb17 = cm_object_get_child_by_name(state->f1.reg.f8r1, "FB17");
	state->f1.fld.f8r1.fb18 = cm_object_get_child_by_name(state->f1.reg.f8r1, "FB18");
	state->f1.fld.f8r1.fb19 = cm_object_get_child_by_name(state->f1.reg.f8r1, "FB19");
	state->f1.fld.f8r1.fb20 = cm_object_get_child_by_name(state->f1.reg.f8r1, "FB20");
	state->f1.fld.f8r1.fb21 = cm_object_get_child_by_name(state->f1.reg.f8r1, "FB21");
	state->f1.fld.f8r1.fb22 = cm_object_get_child_by_name(state->f1.reg.f8r1, "FB22");
	state->f1.fld.f8r1.fb23 = cm_object_get_child_by_name(state->f1.reg.f8r1, "FB23");
	state->f1.fld.f8r1.fb24 = cm_object_get_child_by_name(state->f1.reg.f8r1, "FB24");
	state->f1.fld.f8r1.fb25 = cm_object_get_child_by_name(state->f1.reg.f8r1, "FB25");
	state->f1.fld.f8r1.fb26 = cm_object_get_child_by_name(state->f1.reg.f8r1, "FB26");
	state->f1.fld.f8r1.fb27 = cm_object_get_child_by_name(state->f1.reg.f8r1, "FB27");
	state->f1.fld.f8r1.fb28 = cm_object_get_child_by_name(state->f1.reg.f8r1, "FB28");
	state->f1.fld.f8r1.fb29 = cm_object_get_child_by_name(state->f1.reg.f8r1, "FB29");
	state->f1.fld.f8r1.fb30 = cm_object_get_child_by_name(state->f1.reg.f8r1, "FB30");
	state->f1.fld.f8r1.fb31 = cm_object_get_child_by_name(state->f1.reg.f8r1, "FB31");

	// F8R2 bitfields.
	state->f1.fld.f8r2.fb0 = cm_object_get_child_by_name(state->f1.reg.f8r2, "FB0");
	state->f1.fld.f8r2.fb1 = cm_object_get_child_by_name(state->f1.reg.f8r2, "FB1");
	state->f1.fld.f8r2.fb2 = cm_object_get_child_by_name(state->f1.reg.f8r2, "FB2");
	state->f1.fld.f8r2.fb3 = cm_object_get_child_by_name(state->f1.reg.f8r2, "FB3");
	state->f1.fld.f8r2.fb4 = cm_object_get_child_by_name(state->f1.reg.f8r2, "FB4");
	state->f1.fld.f8r2.fb5 = cm_object_get_child_by_name(state->f1.reg.f8r2, "FB5");
	state->f1.fld.f8r2.fb6 = cm_object_get_child_by_name(state->f1.reg.f8r2, "FB6");
	state->f1.fld.f8r2.fb7 = cm_object_get_child_by_name(state->f1.reg.f8r2, "FB7");
	state->f1.fld.f8r2.fb8 = cm_object_get_child_by_name(state->f1.reg.f8r2, "FB8");
	state->f1.fld.f8r2.fb9 = cm_object_get_child_by_name(state->f1.reg.f8r2, "FB9");
	state->f1.fld.f8r2.fb10 = cm_object_get_child_by_name(state->f1.reg.f8r2, "FB10");
	state->f1.fld.f8r2.fb11 = cm_object_get_child_by_name(state->f1.reg.f8r2, "FB11");
	state->f1.fld.f8r2.fb12 = cm_object_get_child_by_name(state->f1.reg.f8r2, "FB12");
	state->f1.fld.f8r2.fb13 = cm_object_get_child_by_name(state->f1.reg.f8r2, "FB13");
	state->f1.fld.f8r2.fb14 = cm_object_get_child_by_name(state->f1.reg.f8r2, "FB14");
	state->f1.fld.f8r2.fb15 = cm_object_get_child_by_name(state->f1.reg.f8r2, "FB15");
	state->f1.fld.f8r2.fb16 = cm_object_get_child_by_name(state->f1.reg.f8r2, "FB16");
	state->f1.fld.f8r2.fb17 = cm_object_get_child_by_name(state->f1.reg.f8r2, "FB17");
	state->f1.fld.f8r2.fb18 = cm_object_get_child_by_name(state->f1.reg.f8r2, "FB18");
	state->f1.fld.f8r2.fb19 = cm_object_get_child_by_name(state->f1.reg.f8r2, "FB19");
	state->f1.fld.f8r2.fb20 = cm_object_get_child_by_name(state->f1.reg.f8r2, "FB20");
	state->f1.fld.f8r2.fb21 = cm_object_get_child_by_name(state->f1.reg.f8r2, "FB21");
	state->f1.fld.f8r2.fb22 = cm_object_get_child_by_name(state->f1.reg.f8r2, "FB22");
	state->f1.fld.f8r2.fb23 = cm_object_get_child_by_name(state->f1.reg.f8r2, "FB23");
	state->f1.fld.f8r2.fb24 = cm_object_get_child_by_name(state->f1.reg.f8r2, "FB24");
	state->f1.fld.f8r2.fb25 = cm_object_get_child_by_name(state->f1.reg.f8r2, "FB25");
	state->f1.fld.f8r2.fb26 = cm_object_get_child_by_name(state->f1.reg.f8r2, "FB26");
	state->f1.fld.f8r2.fb27 = cm_object_get_child_by_name(state->f1.reg.f8r2, "FB27");
	state->f1.fld.f8r2.fb28 = cm_object_get_child_by_name(state->f1.reg.f8r2, "FB28");
	state->f1.fld.f8r2.fb29 = cm_object_get_child_by_name(state->f1.reg.f8r2, "FB29");
	state->f1.fld.f8r2.fb30 = cm_object_get_child_by_name(state->f1.reg.f8r2, "FB30");
	state->f1.fld.f8r2.fb31 = cm_object_get_child_by_name(state->f1.reg.f8r2, "FB31");

	// F9R1 bitfields.
	state->f1.fld.f9r1.fb0 = cm_object_get_child_by_name(state->f1.reg.f9r1, "FB0");
	state->f1.fld.f9r1.fb1 = cm_object_get_child_by_name(state->f1.reg.f9r1, "FB1");
	state->f1.fld.f9r1.fb2 = cm_object_get_child_by_name(state->f1.reg.f9r1, "FB2");
	state->f1.fld.f9r1.fb3 = cm_object_get_child_by_name(state->f1.reg.f9r1, "FB3");
	state->f1.fld.f9r1.fb4 = cm_object_get_child_by_name(state->f1.reg.f9r1, "FB4");
	state->f1.fld.f9r1.fb5 = cm_object_get_child_by_name(state->f1.reg.f9r1, "FB5");
	state->f1.fld.f9r1.fb6 = cm_object_get_child_by_name(state->f1.reg.f9r1, "FB6");
	state->f1.fld.f9r1.fb7 = cm_object_get_child_by_name(state->f1.reg.f9r1, "FB7");
	state->f1.fld.f9r1.fb8 = cm_object_get_child_by_name(state->f1.reg.f9r1, "FB8");
	state->f1.fld.f9r1.fb9 = cm_object_get_child_by_name(state->f1.reg.f9r1, "FB9");
	state->f1.fld.f9r1.fb10 = cm_object_get_child_by_name(state->f1.reg.f9r1, "FB10");
	state->f1.fld.f9r1.fb11 = cm_object_get_child_by_name(state->f1.reg.f9r1, "FB11");
	state->f1.fld.f9r1.fb12 = cm_object_get_child_by_name(state->f1.reg.f9r1, "FB12");
	state->f1.fld.f9r1.fb13 = cm_object_get_child_by_name(state->f1.reg.f9r1, "FB13");
	state->f1.fld.f9r1.fb14 = cm_object_get_child_by_name(state->f1.reg.f9r1, "FB14");
	state->f1.fld.f9r1.fb15 = cm_object_get_child_by_name(state->f1.reg.f9r1, "FB15");
	state->f1.fld.f9r1.fb16 = cm_object_get_child_by_name(state->f1.reg.f9r1, "FB16");
	state->f1.fld.f9r1.fb17 = cm_object_get_child_by_name(state->f1.reg.f9r1, "FB17");
	state->f1.fld.f9r1.fb18 = cm_object_get_child_by_name(state->f1.reg.f9r1, "FB18");
	state->f1.fld.f9r1.fb19 = cm_object_get_child_by_name(state->f1.reg.f9r1, "FB19");
	state->f1.fld.f9r1.fb20 = cm_object_get_child_by_name(state->f1.reg.f9r1, "FB20");
	state->f1.fld.f9r1.fb21 = cm_object_get_child_by_name(state->f1.reg.f9r1, "FB21");
	state->f1.fld.f9r1.fb22 = cm_object_get_child_by_name(state->f1.reg.f9r1, "FB22");
	state->f1.fld.f9r1.fb23 = cm_object_get_child_by_name(state->f1.reg.f9r1, "FB23");
	state->f1.fld.f9r1.fb24 = cm_object_get_child_by_name(state->f1.reg.f9r1, "FB24");
	state->f1.fld.f9r1.fb25 = cm_object_get_child_by_name(state->f1.reg.f9r1, "FB25");
	state->f1.fld.f9r1.fb26 = cm_object_get_child_by_name(state->f1.reg.f9r1, "FB26");
	state->f1.fld.f9r1.fb27 = cm_object_get_child_by_name(state->f1.reg.f9r1, "FB27");
	state->f1.fld.f9r1.fb28 = cm_object_get_child_by_name(state->f1.reg.f9r1, "FB28");
	state->f1.fld.f9r1.fb29 = cm_object_get_child_by_name(state->f1.reg.f9r1, "FB29");
	state->f1.fld.f9r1.fb30 = cm_object_get_child_by_name(state->f1.reg.f9r1, "FB30");
	state->f1.fld.f9r1.fb31 = cm_object_get_child_by_name(state->f1.reg.f9r1, "FB31");

	// F9R2 bitfields.
	state->f1.fld.f9r2.fb0 = cm_object_get_child_by_name(state->f1.reg.f9r2, "FB0");
	state->f1.fld.f9r2.fb1 = cm_object_get_child_by_name(state->f1.reg.f9r2, "FB1");
	state->f1.fld.f9r2.fb2 = cm_object_get_child_by_name(state->f1.reg.f9r2, "FB2");
	state->f1.fld.f9r2.fb3 = cm_object_get_child_by_name(state->f1.reg.f9r2, "FB3");
	state->f1.fld.f9r2.fb4 = cm_object_get_child_by_name(state->f1.reg.f9r2, "FB4");
	state->f1.fld.f9r2.fb5 = cm_object_get_child_by_name(state->f1.reg.f9r2, "FB5");
	state->f1.fld.f9r2.fb6 = cm_object_get_child_by_name(state->f1.reg.f9r2, "FB6");
	state->f1.fld.f9r2.fb7 = cm_object_get_child_by_name(state->f1.reg.f9r2, "FB7");
	state->f1.fld.f9r2.fb8 = cm_object_get_child_by_name(state->f1.reg.f9r2, "FB8");
	state->f1.fld.f9r2.fb9 = cm_object_get_child_by_name(state->f1.reg.f9r2, "FB9");
	state->f1.fld.f9r2.fb10 = cm_object_get_child_by_name(state->f1.reg.f9r2, "FB10");
	state->f1.fld.f9r2.fb11 = cm_object_get_child_by_name(state->f1.reg.f9r2, "FB11");
	state->f1.fld.f9r2.fb12 = cm_object_get_child_by_name(state->f1.reg.f9r2, "FB12");
	state->f1.fld.f9r2.fb13 = cm_object_get_child_by_name(state->f1.reg.f9r2, "FB13");
	state->f1.fld.f9r2.fb14 = cm_object_get_child_by_name(state->f1.reg.f9r2, "FB14");
	state->f1.fld.f9r2.fb15 = cm_object_get_child_by_name(state->f1.reg.f9r2, "FB15");
	state->f1.fld.f9r2.fb16 = cm_object_get_child_by_name(state->f1.reg.f9r2, "FB16");
	state->f1.fld.f9r2.fb17 = cm_object_get_child_by_name(state->f1.reg.f9r2, "FB17");
	state->f1.fld.f9r2.fb18 = cm_object_get_child_by_name(state->f1.reg.f9r2, "FB18");
	state->f1.fld.f9r2.fb19 = cm_object_get_child_by_name(state->f1.reg.f9r2, "FB19");
	state->f1.fld.f9r2.fb20 = cm_object_get_child_by_name(state->f1.reg.f9r2, "FB20");
	state->f1.fld.f9r2.fb21 = cm_object_get_child_by_name(state->f1.reg.f9r2, "FB21");
	state->f1.fld.f9r2.fb22 = cm_object_get_child_by_name(state->f1.reg.f9r2, "FB22");
	state->f1.fld.f9r2.fb23 = cm_object_get_child_by_name(state->f1.reg.f9r2, "FB23");
	state->f1.fld.f9r2.fb24 = cm_object_get_child_by_name(state->f1.reg.f9r2, "FB24");
	state->f1.fld.f9r2.fb25 = cm_object_get_child_by_name(state->f1.reg.f9r2, "FB25");
	state->f1.fld.f9r2.fb26 = cm_object_get_child_by_name(state->f1.reg.f9r2, "FB26");
	state->f1.fld.f9r2.fb27 = cm_object_get_child_by_name(state->f1.reg.f9r2, "FB27");
	state->f1.fld.f9r2.fb28 = cm_object_get_child_by_name(state->f1.reg.f9r2, "FB28");
	state->f1.fld.f9r2.fb29 = cm_object_get_child_by_name(state->f1.reg.f9r2, "FB29");
	state->f1.fld.f9r2.fb30 = cm_object_get_child_by_name(state->f1.reg.f9r2, "FB30");
	state->f1.fld.f9r2.fb31 = cm_object_get_child_by_name(state->f1.reg.f9r2, "FB31");

	// F10R1 bitfields.
	state->f1.fld.f10r1.fb0 = cm_object_get_child_by_name(state->f1.reg.f10r1, "FB0");
	state->f1.fld.f10r1.fb1 = cm_object_get_child_by_name(state->f1.reg.f10r1, "FB1");
	state->f1.fld.f10r1.fb2 = cm_object_get_child_by_name(state->f1.reg.f10r1, "FB2");
	state->f1.fld.f10r1.fb3 = cm_object_get_child_by_name(state->f1.reg.f10r1, "FB3");
	state->f1.fld.f10r1.fb4 = cm_object_get_child_by_name(state->f1.reg.f10r1, "FB4");
	state->f1.fld.f10r1.fb5 = cm_object_get_child_by_name(state->f1.reg.f10r1, "FB5");
	state->f1.fld.f10r1.fb6 = cm_object_get_child_by_name(state->f1.reg.f10r1, "FB6");
	state->f1.fld.f10r1.fb7 = cm_object_get_child_by_name(state->f1.reg.f10r1, "FB7");
	state->f1.fld.f10r1.fb8 = cm_object_get_child_by_name(state->f1.reg.f10r1, "FB8");
	state->f1.fld.f10r1.fb9 = cm_object_get_child_by_name(state->f1.reg.f10r1, "FB9");
	state->f1.fld.f10r1.fb10 = cm_object_get_child_by_name(state->f1.reg.f10r1, "FB10");
	state->f1.fld.f10r1.fb11 = cm_object_get_child_by_name(state->f1.reg.f10r1, "FB11");
	state->f1.fld.f10r1.fb12 = cm_object_get_child_by_name(state->f1.reg.f10r1, "FB12");
	state->f1.fld.f10r1.fb13 = cm_object_get_child_by_name(state->f1.reg.f10r1, "FB13");
	state->f1.fld.f10r1.fb14 = cm_object_get_child_by_name(state->f1.reg.f10r1, "FB14");
	state->f1.fld.f10r1.fb15 = cm_object_get_child_by_name(state->f1.reg.f10r1, "FB15");
	state->f1.fld.f10r1.fb16 = cm_object_get_child_by_name(state->f1.reg.f10r1, "FB16");
	state->f1.fld.f10r1.fb17 = cm_object_get_child_by_name(state->f1.reg.f10r1, "FB17");
	state->f1.fld.f10r1.fb18 = cm_object_get_child_by_name(state->f1.reg.f10r1, "FB18");
	state->f1.fld.f10r1.fb19 = cm_object_get_child_by_name(state->f1.reg.f10r1, "FB19");
	state->f1.fld.f10r1.fb20 = cm_object_get_child_by_name(state->f1.reg.f10r1, "FB20");
	state->f1.fld.f10r1.fb21 = cm_object_get_child_by_name(state->f1.reg.f10r1, "FB21");
	state->f1.fld.f10r1.fb22 = cm_object_get_child_by_name(state->f1.reg.f10r1, "FB22");
	state->f1.fld.f10r1.fb23 = cm_object_get_child_by_name(state->f1.reg.f10r1, "FB23");
	state->f1.fld.f10r1.fb24 = cm_object_get_child_by_name(state->f1.reg.f10r1, "FB24");
	state->f1.fld.f10r1.fb25 = cm_object_get_child_by_name(state->f1.reg.f10r1, "FB25");
	state->f1.fld.f10r1.fb26 = cm_object_get_child_by_name(state->f1.reg.f10r1, "FB26");
	state->f1.fld.f10r1.fb27 = cm_object_get_child_by_name(state->f1.reg.f10r1, "FB27");
	state->f1.fld.f10r1.fb28 = cm_object_get_child_by_name(state->f1.reg.f10r1, "FB28");
	state->f1.fld.f10r1.fb29 = cm_object_get_child_by_name(state->f1.reg.f10r1, "FB29");
	state->f1.fld.f10r1.fb30 = cm_object_get_child_by_name(state->f1.reg.f10r1, "FB30");
	state->f1.fld.f10r1.fb31 = cm_object_get_child_by_name(state->f1.reg.f10r1, "FB31");

	// F10R2 bitfields.
	state->f1.fld.f10r2.fb0 = cm_object_get_child_by_name(state->f1.reg.f10r2, "FB0");
	state->f1.fld.f10r2.fb1 = cm_object_get_child_by_name(state->f1.reg.f10r2, "FB1");
	state->f1.fld.f10r2.fb2 = cm_object_get_child_by_name(state->f1.reg.f10r2, "FB2");
	state->f1.fld.f10r2.fb3 = cm_object_get_child_by_name(state->f1.reg.f10r2, "FB3");
	state->f1.fld.f10r2.fb4 = cm_object_get_child_by_name(state->f1.reg.f10r2, "FB4");
	state->f1.fld.f10r2.fb5 = cm_object_get_child_by_name(state->f1.reg.f10r2, "FB5");
	state->f1.fld.f10r2.fb6 = cm_object_get_child_by_name(state->f1.reg.f10r2, "FB6");
	state->f1.fld.f10r2.fb7 = cm_object_get_child_by_name(state->f1.reg.f10r2, "FB7");
	state->f1.fld.f10r2.fb8 = cm_object_get_child_by_name(state->f1.reg.f10r2, "FB8");
	state->f1.fld.f10r2.fb9 = cm_object_get_child_by_name(state->f1.reg.f10r2, "FB9");
	state->f1.fld.f10r2.fb10 = cm_object_get_child_by_name(state->f1.reg.f10r2, "FB10");
	state->f1.fld.f10r2.fb11 = cm_object_get_child_by_name(state->f1.reg.f10r2, "FB11");
	state->f1.fld.f10r2.fb12 = cm_object_get_child_by_name(state->f1.reg.f10r2, "FB12");
	state->f1.fld.f10r2.fb13 = cm_object_get_child_by_name(state->f1.reg.f10r2, "FB13");
	state->f1.fld.f10r2.fb14 = cm_object_get_child_by_name(state->f1.reg.f10r2, "FB14");
	state->f1.fld.f10r2.fb15 = cm_object_get_child_by_name(state->f1.reg.f10r2, "FB15");
	state->f1.fld.f10r2.fb16 = cm_object_get_child_by_name(state->f1.reg.f10r2, "FB16");
	state->f1.fld.f10r2.fb17 = cm_object_get_child_by_name(state->f1.reg.f10r2, "FB17");
	state->f1.fld.f10r2.fb18 = cm_object_get_child_by_name(state->f1.reg.f10r2, "FB18");
	state->f1.fld.f10r2.fb19 = cm_object_get_child_by_name(state->f1.reg.f10r2, "FB19");
	state->f1.fld.f10r2.fb20 = cm_object_get_child_by_name(state->f1.reg.f10r2, "FB20");
	state->f1.fld.f10r2.fb21 = cm_object_get_child_by_name(state->f1.reg.f10r2, "FB21");
	state->f1.fld.f10r2.fb22 = cm_object_get_child_by_name(state->f1.reg.f10r2, "FB22");
	state->f1.fld.f10r2.fb23 = cm_object_get_child_by_name(state->f1.reg.f10r2, "FB23");
	state->f1.fld.f10r2.fb24 = cm_object_get_child_by_name(state->f1.reg.f10r2, "FB24");
	state->f1.fld.f10r2.fb25 = cm_object_get_child_by_name(state->f1.reg.f10r2, "FB25");
	state->f1.fld.f10r2.fb26 = cm_object_get_child_by_name(state->f1.reg.f10r2, "FB26");
	state->f1.fld.f10r2.fb27 = cm_object_get_child_by_name(state->f1.reg.f10r2, "FB27");
	state->f1.fld.f10r2.fb28 = cm_object_get_child_by_name(state->f1.reg.f10r2, "FB28");
	state->f1.fld.f10r2.fb29 = cm_object_get_child_by_name(state->f1.reg.f10r2, "FB29");
	state->f1.fld.f10r2.fb30 = cm_object_get_child_by_name(state->f1.reg.f10r2, "FB30");
	state->f1.fld.f10r2.fb31 = cm_object_get_child_by_name(state->f1.reg.f10r2, "FB31");

	// F11R1 bitfields.
	state->f1.fld.f11r1.fb0 = cm_object_get_child_by_name(state->f1.reg.f11r1, "FB0");
	state->f1.fld.f11r1.fb1 = cm_object_get_child_by_name(state->f1.reg.f11r1, "FB1");
	state->f1.fld.f11r1.fb2 = cm_object_get_child_by_name(state->f1.reg.f11r1, "FB2");
	state->f1.fld.f11r1.fb3 = cm_object_get_child_by_name(state->f1.reg.f11r1, "FB3");
	state->f1.fld.f11r1.fb4 = cm_object_get_child_by_name(state->f1.reg.f11r1, "FB4");
	state->f1.fld.f11r1.fb5 = cm_object_get_child_by_name(state->f1.reg.f11r1, "FB5");
	state->f1.fld.f11r1.fb6 = cm_object_get_child_by_name(state->f1.reg.f11r1, "FB6");
	state->f1.fld.f11r1.fb7 = cm_object_get_child_by_name(state->f1.reg.f11r1, "FB7");
	state->f1.fld.f11r1.fb8 = cm_object_get_child_by_name(state->f1.reg.f11r1, "FB8");
	state->f1.fld.f11r1.fb9 = cm_object_get_child_by_name(state->f1.reg.f11r1, "FB9");
	state->f1.fld.f11r1.fb10 = cm_object_get_child_by_name(state->f1.reg.f11r1, "FB10");
	state->f1.fld.f11r1.fb11 = cm_object_get_child_by_name(state->f1.reg.f11r1, "FB11");
	state->f1.fld.f11r1.fb12 = cm_object_get_child_by_name(state->f1.reg.f11r1, "FB12");
	state->f1.fld.f11r1.fb13 = cm_object_get_child_by_name(state->f1.reg.f11r1, "FB13");
	state->f1.fld.f11r1.fb14 = cm_object_get_child_by_name(state->f1.reg.f11r1, "FB14");
	state->f1.fld.f11r1.fb15 = cm_object_get_child_by_name(state->f1.reg.f11r1, "FB15");
	state->f1.fld.f11r1.fb16 = cm_object_get_child_by_name(state->f1.reg.f11r1, "FB16");
	state->f1.fld.f11r1.fb17 = cm_object_get_child_by_name(state->f1.reg.f11r1, "FB17");
	state->f1.fld.f11r1.fb18 = cm_object_get_child_by_name(state->f1.reg.f11r1, "FB18");
	state->f1.fld.f11r1.fb19 = cm_object_get_child_by_name(state->f1.reg.f11r1, "FB19");
	state->f1.fld.f11r1.fb20 = cm_object_get_child_by_name(state->f1.reg.f11r1, "FB20");
	state->f1.fld.f11r1.fb21 = cm_object_get_child_by_name(state->f1.reg.f11r1, "FB21");
	state->f1.fld.f11r1.fb22 = cm_object_get_child_by_name(state->f1.reg.f11r1, "FB22");
	state->f1.fld.f11r1.fb23 = cm_object_get_child_by_name(state->f1.reg.f11r1, "FB23");
	state->f1.fld.f11r1.fb24 = cm_object_get_child_by_name(state->f1.reg.f11r1, "FB24");
	state->f1.fld.f11r1.fb25 = cm_object_get_child_by_name(state->f1.reg.f11r1, "FB25");
	state->f1.fld.f11r1.fb26 = cm_object_get_child_by_name(state->f1.reg.f11r1, "FB26");
	state->f1.fld.f11r1.fb27 = cm_object_get_child_by_name(state->f1.reg.f11r1, "FB27");
	state->f1.fld.f11r1.fb28 = cm_object_get_child_by_name(state->f1.reg.f11r1, "FB28");
	state->f1.fld.f11r1.fb29 = cm_object_get_child_by_name(state->f1.reg.f11r1, "FB29");
	state->f1.fld.f11r1.fb30 = cm_object_get_child_by_name(state->f1.reg.f11r1, "FB30");
	state->f1.fld.f11r1.fb31 = cm_object_get_child_by_name(state->f1.reg.f11r1, "FB31");

	// F11R2 bitfields.
	state->f1.fld.f11r2.fb0 = cm_object_get_child_by_name(state->f1.reg.f11r2, "FB0");
	state->f1.fld.f11r2.fb1 = cm_object_get_child_by_name(state->f1.reg.f11r2, "FB1");
	state->f1.fld.f11r2.fb2 = cm_object_get_child_by_name(state->f1.reg.f11r2, "FB2");
	state->f1.fld.f11r2.fb3 = cm_object_get_child_by_name(state->f1.reg.f11r2, "FB3");
	state->f1.fld.f11r2.fb4 = cm_object_get_child_by_name(state->f1.reg.f11r2, "FB4");
	state->f1.fld.f11r2.fb5 = cm_object_get_child_by_name(state->f1.reg.f11r2, "FB5");
	state->f1.fld.f11r2.fb6 = cm_object_get_child_by_name(state->f1.reg.f11r2, "FB6");
	state->f1.fld.f11r2.fb7 = cm_object_get_child_by_name(state->f1.reg.f11r2, "FB7");
	state->f1.fld.f11r2.fb8 = cm_object_get_child_by_name(state->f1.reg.f11r2, "FB8");
	state->f1.fld.f11r2.fb9 = cm_object_get_child_by_name(state->f1.reg.f11r2, "FB9");
	state->f1.fld.f11r2.fb10 = cm_object_get_child_by_name(state->f1.reg.f11r2, "FB10");
	state->f1.fld.f11r2.fb11 = cm_object_get_child_by_name(state->f1.reg.f11r2, "FB11");
	state->f1.fld.f11r2.fb12 = cm_object_get_child_by_name(state->f1.reg.f11r2, "FB12");
	state->f1.fld.f11r2.fb13 = cm_object_get_child_by_name(state->f1.reg.f11r2, "FB13");
	state->f1.fld.f11r2.fb14 = cm_object_get_child_by_name(state->f1.reg.f11r2, "FB14");
	state->f1.fld.f11r2.fb15 = cm_object_get_child_by_name(state->f1.reg.f11r2, "FB15");
	state->f1.fld.f11r2.fb16 = cm_object_get_child_by_name(state->f1.reg.f11r2, "FB16");
	state->f1.fld.f11r2.fb17 = cm_object_get_child_by_name(state->f1.reg.f11r2, "FB17");
	state->f1.fld.f11r2.fb18 = cm_object_get_child_by_name(state->f1.reg.f11r2, "FB18");
	state->f1.fld.f11r2.fb19 = cm_object_get_child_by_name(state->f1.reg.f11r2, "FB19");
	state->f1.fld.f11r2.fb20 = cm_object_get_child_by_name(state->f1.reg.f11r2, "FB20");
	state->f1.fld.f11r2.fb21 = cm_object_get_child_by_name(state->f1.reg.f11r2, "FB21");
	state->f1.fld.f11r2.fb22 = cm_object_get_child_by_name(state->f1.reg.f11r2, "FB22");
	state->f1.fld.f11r2.fb23 = cm_object_get_child_by_name(state->f1.reg.f11r2, "FB23");
	state->f1.fld.f11r2.fb24 = cm_object_get_child_by_name(state->f1.reg.f11r2, "FB24");
	state->f1.fld.f11r2.fb25 = cm_object_get_child_by_name(state->f1.reg.f11r2, "FB25");
	state->f1.fld.f11r2.fb26 = cm_object_get_child_by_name(state->f1.reg.f11r2, "FB26");
	state->f1.fld.f11r2.fb27 = cm_object_get_child_by_name(state->f1.reg.f11r2, "FB27");
	state->f1.fld.f11r2.fb28 = cm_object_get_child_by_name(state->f1.reg.f11r2, "FB28");
	state->f1.fld.f11r2.fb29 = cm_object_get_child_by_name(state->f1.reg.f11r2, "FB29");
	state->f1.fld.f11r2.fb30 = cm_object_get_child_by_name(state->f1.reg.f11r2, "FB30");
	state->f1.fld.f11r2.fb31 = cm_object_get_child_by_name(state->f1.reg.f11r2, "FB31");

	// F12R1 bitfields.
	state->f1.fld.f12r1.fb0 = cm_object_get_child_by_name(state->f1.reg.f12r1, "FB0");
	state->f1.fld.f12r1.fb1 = cm_object_get_child_by_name(state->f1.reg.f12r1, "FB1");
	state->f1.fld.f12r1.fb2 = cm_object_get_child_by_name(state->f1.reg.f12r1, "FB2");
	state->f1.fld.f12r1.fb3 = cm_object_get_child_by_name(state->f1.reg.f12r1, "FB3");
	state->f1.fld.f12r1.fb4 = cm_object_get_child_by_name(state->f1.reg.f12r1, "FB4");
	state->f1.fld.f12r1.fb5 = cm_object_get_child_by_name(state->f1.reg.f12r1, "FB5");
	state->f1.fld.f12r1.fb6 = cm_object_get_child_by_name(state->f1.reg.f12r1, "FB6");
	state->f1.fld.f12r1.fb7 = cm_object_get_child_by_name(state->f1.reg.f12r1, "FB7");
	state->f1.fld.f12r1.fb8 = cm_object_get_child_by_name(state->f1.reg.f12r1, "FB8");
	state->f1.fld.f12r1.fb9 = cm_object_get_child_by_name(state->f1.reg.f12r1, "FB9");
	state->f1.fld.f12r1.fb10 = cm_object_get_child_by_name(state->f1.reg.f12r1, "FB10");
	state->f1.fld.f12r1.fb11 = cm_object_get_child_by_name(state->f1.reg.f12r1, "FB11");
	state->f1.fld.f12r1.fb12 = cm_object_get_child_by_name(state->f1.reg.f12r1, "FB12");
	state->f1.fld.f12r1.fb13 = cm_object_get_child_by_name(state->f1.reg.f12r1, "FB13");
	state->f1.fld.f12r1.fb14 = cm_object_get_child_by_name(state->f1.reg.f12r1, "FB14");
	state->f1.fld.f12r1.fb15 = cm_object_get_child_by_name(state->f1.reg.f12r1, "FB15");
	state->f1.fld.f12r1.fb16 = cm_object_get_child_by_name(state->f1.reg.f12r1, "FB16");
	state->f1.fld.f12r1.fb17 = cm_object_get_child_by_name(state->f1.reg.f12r1, "FB17");
	state->f1.fld.f12r1.fb18 = cm_object_get_child_by_name(state->f1.reg.f12r1, "FB18");
	state->f1.fld.f12r1.fb19 = cm_object_get_child_by_name(state->f1.reg.f12r1, "FB19");
	state->f1.fld.f12r1.fb20 = cm_object_get_child_by_name(state->f1.reg.f12r1, "FB20");
	state->f1.fld.f12r1.fb21 = cm_object_get_child_by_name(state->f1.reg.f12r1, "FB21");
	state->f1.fld.f12r1.fb22 = cm_object_get_child_by_name(state->f1.reg.f12r1, "FB22");
	state->f1.fld.f12r1.fb23 = cm_object_get_child_by_name(state->f1.reg.f12r1, "FB23");
	state->f1.fld.f12r1.fb24 = cm_object_get_child_by_name(state->f1.reg.f12r1, "FB24");
	state->f1.fld.f12r1.fb25 = cm_object_get_child_by_name(state->f1.reg.f12r1, "FB25");
	state->f1.fld.f12r1.fb26 = cm_object_get_child_by_name(state->f1.reg.f12r1, "FB26");
	state->f1.fld.f12r1.fb27 = cm_object_get_child_by_name(state->f1.reg.f12r1, "FB27");
	state->f1.fld.f12r1.fb28 = cm_object_get_child_by_name(state->f1.reg.f12r1, "FB28");
	state->f1.fld.f12r1.fb29 = cm_object_get_child_by_name(state->f1.reg.f12r1, "FB29");
	state->f1.fld.f12r1.fb30 = cm_object_get_child_by_name(state->f1.reg.f12r1, "FB30");
	state->f1.fld.f12r1.fb31 = cm_object_get_child_by_name(state->f1.reg.f12r1, "FB31");

	// F12R2 bitfields.
	state->f1.fld.f12r2.fb0 = cm_object_get_child_by_name(state->f1.reg.f12r2, "FB0");
	state->f1.fld.f12r2.fb1 = cm_object_get_child_by_name(state->f1.reg.f12r2, "FB1");
	state->f1.fld.f12r2.fb2 = cm_object_get_child_by_name(state->f1.reg.f12r2, "FB2");
	state->f1.fld.f12r2.fb3 = cm_object_get_child_by_name(state->f1.reg.f12r2, "FB3");
	state->f1.fld.f12r2.fb4 = cm_object_get_child_by_name(state->f1.reg.f12r2, "FB4");
	state->f1.fld.f12r2.fb5 = cm_object_get_child_by_name(state->f1.reg.f12r2, "FB5");
	state->f1.fld.f12r2.fb6 = cm_object_get_child_by_name(state->f1.reg.f12r2, "FB6");
	state->f1.fld.f12r2.fb7 = cm_object_get_child_by_name(state->f1.reg.f12r2, "FB7");
	state->f1.fld.f12r2.fb8 = cm_object_get_child_by_name(state->f1.reg.f12r2, "FB8");
	state->f1.fld.f12r2.fb9 = cm_object_get_child_by_name(state->f1.reg.f12r2, "FB9");
	state->f1.fld.f12r2.fb10 = cm_object_get_child_by_name(state->f1.reg.f12r2, "FB10");
	state->f1.fld.f12r2.fb11 = cm_object_get_child_by_name(state->f1.reg.f12r2, "FB11");
	state->f1.fld.f12r2.fb12 = cm_object_get_child_by_name(state->f1.reg.f12r2, "FB12");
	state->f1.fld.f12r2.fb13 = cm_object_get_child_by_name(state->f1.reg.f12r2, "FB13");
	state->f1.fld.f12r2.fb14 = cm_object_get_child_by_name(state->f1.reg.f12r2, "FB14");
	state->f1.fld.f12r2.fb15 = cm_object_get_child_by_name(state->f1.reg.f12r2, "FB15");
	state->f1.fld.f12r2.fb16 = cm_object_get_child_by_name(state->f1.reg.f12r2, "FB16");
	state->f1.fld.f12r2.fb17 = cm_object_get_child_by_name(state->f1.reg.f12r2, "FB17");
	state->f1.fld.f12r2.fb18 = cm_object_get_child_by_name(state->f1.reg.f12r2, "FB18");
	state->f1.fld.f12r2.fb19 = cm_object_get_child_by_name(state->f1.reg.f12r2, "FB19");
	state->f1.fld.f12r2.fb20 = cm_object_get_child_by_name(state->f1.reg.f12r2, "FB20");
	state->f1.fld.f12r2.fb21 = cm_object_get_child_by_name(state->f1.reg.f12r2, "FB21");
	state->f1.fld.f12r2.fb22 = cm_object_get_child_by_name(state->f1.reg.f12r2, "FB22");
	state->f1.fld.f12r2.fb23 = cm_object_get_child_by_name(state->f1.reg.f12r2, "FB23");
	state->f1.fld.f12r2.fb24 = cm_object_get_child_by_name(state->f1.reg.f12r2, "FB24");
	state->f1.fld.f12r2.fb25 = cm_object_get_child_by_name(state->f1.reg.f12r2, "FB25");
	state->f1.fld.f12r2.fb26 = cm_object_get_child_by_name(state->f1.reg.f12r2, "FB26");
	state->f1.fld.f12r2.fb27 = cm_object_get_child_by_name(state->f1.reg.f12r2, "FB27");
	state->f1.fld.f12r2.fb28 = cm_object_get_child_by_name(state->f1.reg.f12r2, "FB28");
	state->f1.fld.f12r2.fb29 = cm_object_get_child_by_name(state->f1.reg.f12r2, "FB29");
	state->f1.fld.f12r2.fb30 = cm_object_get_child_by_name(state->f1.reg.f12r2, "FB30");
	state->f1.fld.f12r2.fb31 = cm_object_get_child_by_name(state->f1.reg.f12r2, "FB31");

	// F13R1 bitfields.
	state->f1.fld.f13r1.fb0 = cm_object_get_child_by_name(state->f1.reg.f13r1, "FB0");
	state->f1.fld.f13r1.fb1 = cm_object_get_child_by_name(state->f1.reg.f13r1, "FB1");
	state->f1.fld.f13r1.fb2 = cm_object_get_child_by_name(state->f1.reg.f13r1, "FB2");
	state->f1.fld.f13r1.fb3 = cm_object_get_child_by_name(state->f1.reg.f13r1, "FB3");
	state->f1.fld.f13r1.fb4 = cm_object_get_child_by_name(state->f1.reg.f13r1, "FB4");
	state->f1.fld.f13r1.fb5 = cm_object_get_child_by_name(state->f1.reg.f13r1, "FB5");
	state->f1.fld.f13r1.fb6 = cm_object_get_child_by_name(state->f1.reg.f13r1, "FB6");
	state->f1.fld.f13r1.fb7 = cm_object_get_child_by_name(state->f1.reg.f13r1, "FB7");
	state->f1.fld.f13r1.fb8 = cm_object_get_child_by_name(state->f1.reg.f13r1, "FB8");
	state->f1.fld.f13r1.fb9 = cm_object_get_child_by_name(state->f1.reg.f13r1, "FB9");
	state->f1.fld.f13r1.fb10 = cm_object_get_child_by_name(state->f1.reg.f13r1, "FB10");
	state->f1.fld.f13r1.fb11 = cm_object_get_child_by_name(state->f1.reg.f13r1, "FB11");
	state->f1.fld.f13r1.fb12 = cm_object_get_child_by_name(state->f1.reg.f13r1, "FB12");
	state->f1.fld.f13r1.fb13 = cm_object_get_child_by_name(state->f1.reg.f13r1, "FB13");
	state->f1.fld.f13r1.fb14 = cm_object_get_child_by_name(state->f1.reg.f13r1, "FB14");
	state->f1.fld.f13r1.fb15 = cm_object_get_child_by_name(state->f1.reg.f13r1, "FB15");
	state->f1.fld.f13r1.fb16 = cm_object_get_child_by_name(state->f1.reg.f13r1, "FB16");
	state->f1.fld.f13r1.fb17 = cm_object_get_child_by_name(state->f1.reg.f13r1, "FB17");
	state->f1.fld.f13r1.fb18 = cm_object_get_child_by_name(state->f1.reg.f13r1, "FB18");
	state->f1.fld.f13r1.fb19 = cm_object_get_child_by_name(state->f1.reg.f13r1, "FB19");
	state->f1.fld.f13r1.fb20 = cm_object_get_child_by_name(state->f1.reg.f13r1, "FB20");
	state->f1.fld.f13r1.fb21 = cm_object_get_child_by_name(state->f1.reg.f13r1, "FB21");
	state->f1.fld.f13r1.fb22 = cm_object_get_child_by_name(state->f1.reg.f13r1, "FB22");
	state->f1.fld.f13r1.fb23 = cm_object_get_child_by_name(state->f1.reg.f13r1, "FB23");
	state->f1.fld.f13r1.fb24 = cm_object_get_child_by_name(state->f1.reg.f13r1, "FB24");
	state->f1.fld.f13r1.fb25 = cm_object_get_child_by_name(state->f1.reg.f13r1, "FB25");
	state->f1.fld.f13r1.fb26 = cm_object_get_child_by_name(state->f1.reg.f13r1, "FB26");
	state->f1.fld.f13r1.fb27 = cm_object_get_child_by_name(state->f1.reg.f13r1, "FB27");
	state->f1.fld.f13r1.fb28 = cm_object_get_child_by_name(state->f1.reg.f13r1, "FB28");
	state->f1.fld.f13r1.fb29 = cm_object_get_child_by_name(state->f1.reg.f13r1, "FB29");
	state->f1.fld.f13r1.fb30 = cm_object_get_child_by_name(state->f1.reg.f13r1, "FB30");
	state->f1.fld.f13r1.fb31 = cm_object_get_child_by_name(state->f1.reg.f13r1, "FB31");

	// F13R2 bitfields.
	state->f1.fld.f13r2.fb0 = cm_object_get_child_by_name(state->f1.reg.f13r2, "FB0");
	state->f1.fld.f13r2.fb1 = cm_object_get_child_by_name(state->f1.reg.f13r2, "FB1");
	state->f1.fld.f13r2.fb2 = cm_object_get_child_by_name(state->f1.reg.f13r2, "FB2");
	state->f1.fld.f13r2.fb3 = cm_object_get_child_by_name(state->f1.reg.f13r2, "FB3");
	state->f1.fld.f13r2.fb4 = cm_object_get_child_by_name(state->f1.reg.f13r2, "FB4");
	state->f1.fld.f13r2.fb5 = cm_object_get_child_by_name(state->f1.reg.f13r2, "FB5");
	state->f1.fld.f13r2.fb6 = cm_object_get_child_by_name(state->f1.reg.f13r2, "FB6");
	state->f1.fld.f13r2.fb7 = cm_object_get_child_by_name(state->f1.reg.f13r2, "FB7");
	state->f1.fld.f13r2.fb8 = cm_object_get_child_by_name(state->f1.reg.f13r2, "FB8");
	state->f1.fld.f13r2.fb9 = cm_object_get_child_by_name(state->f1.reg.f13r2, "FB9");
	state->f1.fld.f13r2.fb10 = cm_object_get_child_by_name(state->f1.reg.f13r2, "FB10");
	state->f1.fld.f13r2.fb11 = cm_object_get_child_by_name(state->f1.reg.f13r2, "FB11");
	state->f1.fld.f13r2.fb12 = cm_object_get_child_by_name(state->f1.reg.f13r2, "FB12");
	state->f1.fld.f13r2.fb13 = cm_object_get_child_by_name(state->f1.reg.f13r2, "FB13");
	state->f1.fld.f13r2.fb14 = cm_object_get_child_by_name(state->f1.reg.f13r2, "FB14");
	state->f1.fld.f13r2.fb15 = cm_object_get_child_by_name(state->f1.reg.f13r2, "FB15");
	state->f1.fld.f13r2.fb16 = cm_object_get_child_by_name(state->f1.reg.f13r2, "FB16");
	state->f1.fld.f13r2.fb17 = cm_object_get_child_by_name(state->f1.reg.f13r2, "FB17");
	state->f1.fld.f13r2.fb18 = cm_object_get_child_by_name(state->f1.reg.f13r2, "FB18");
	state->f1.fld.f13r2.fb19 = cm_object_get_child_by_name(state->f1.reg.f13r2, "FB19");
	state->f1.fld.f13r2.fb20 = cm_object_get_child_by_name(state->f1.reg.f13r2, "FB20");
	state->f1.fld.f13r2.fb21 = cm_object_get_child_by_name(state->f1.reg.f13r2, "FB21");
	state->f1.fld.f13r2.fb22 = cm_object_get_child_by_name(state->f1.reg.f13r2, "FB22");
	state->f1.fld.f13r2.fb23 = cm_object_get_child_by_name(state->f1.reg.f13r2, "FB23");
	state->f1.fld.f13r2.fb24 = cm_object_get_child_by_name(state->f1.reg.f13r2, "FB24");
	state->f1.fld.f13r2.fb25 = cm_object_get_child_by_name(state->f1.reg.f13r2, "FB25");
	state->f1.fld.f13r2.fb26 = cm_object_get_child_by_name(state->f1.reg.f13r2, "FB26");
	state->f1.fld.f13r2.fb27 = cm_object_get_child_by_name(state->f1.reg.f13r2, "FB27");
	state->f1.fld.f13r2.fb28 = cm_object_get_child_by_name(state->f1.reg.f13r2, "FB28");
	state->f1.fld.f13r2.fb29 = cm_object_get_child_by_name(state->f1.reg.f13r2, "FB29");
	state->f1.fld.f13r2.fb30 = cm_object_get_child_by_name(state->f1.reg.f13r2, "FB30");
	state->f1.fld.f13r2.fb31 = cm_object_get_child_by_name(state->f1.reg.f13r2, "FB31");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DAC (Digital to analog converter) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F1 DAC (Digital to analog converter) registers.
		struct {
			Object *cr; // 0x0 Control register (DAC_CR)
			Object *swtrigr; // 0x4 DAC software trigger register (DAC_SWTRIGR)
			Object *dhr12r1; // 0x8 DAC channel1 12-bit right-aligned data holding register(DAC_DHR12R1)
			Object *dhr12l1; // 0xC DAC channel1 12-bit left aligned data holding register (DAC_DHR12L1)
			Object *dhr8r1; // 0x10 DAC channel1 8-bit right aligned data holding register (DAC_DHR8R1)
			Object *dhr12r2; // 0x14 DAC channel2 12-bit right aligned data holding register (DAC_DHR12R2)
			Object *dhr12l2; // 0x18 DAC channel2 12-bit left aligned data holding register (DAC_DHR12L2)
			Object *dhr8r2; // 0x1C DAC channel2 8-bit right-aligned data holding register (DAC_DHR8R2)
			Object *dhr12rd; // 0x20 Dual DAC 12-bit right-aligned data holding register (DAC_DHR12RD), Bits 31:28 Reserved, Bits 15:12 Reserved
			Object *dhr12ld; // 0x24 DUAL DAC 12-bit left aligned data holding register (DAC_DHR12LD), Bits 19:16 Reserved, Bits 3:0 Reserved
			Object *dhr8rd; // 0x28 DUAL DAC 8-bit right aligned data holding register (DAC_DHR8RD), Bits 31:16 Reserved
			Object *dor1; // 0x2C DAC channel1 data output register (DAC_DOR1)
			Object *dor2; // 0x30 DAC channel2 data output register (DAC_DOR2)
		} reg;

		struct {

			// CR (Control register (DAC_CR)) bitfields.
			struct {
				Object *en1; // [0:0] DAC channel1 enable
				Object *boff1; // [1:1] DAC channel1 output buffer disable
				Object *ten1; // [2:2] DAC channel1 trigger enable
				Object *tsel1; // [3:5] DAC channel1 trigger selection
				Object *wave1; // [6:7] DAC channel1 noise/triangle wave generation enable
				Object *mamp1; // [8:11] DAC channel1 mask/amplitude selector
				Object *dmaen1; // [12:12] DAC channel1 DMA enable
				Object *en2; // [16:16] DAC channel2 enable
				Object *boff2; // [17:17] DAC channel2 output buffer disable
				Object *ten2; // [18:18] DAC channel2 trigger enable
				Object *tsel2; // [19:21] DAC channel2 trigger selection
				Object *wave2; // [22:23] DAC channel2 noise/triangle wave generation enable
				Object *mamp2; // [24:27] DAC channel2 mask/amplitude selector
				Object *dmaen2; // [28:28] DAC channel2 DMA enable
			} cr;

			// SWTRIGR (DAC software trigger register (DAC_SWTRIGR)) bitfields.
			struct {
				Object *swtrig1; // [0:0] DAC channel1 software trigger
				Object *swtrig2; // [1:1] DAC channel2 software trigger
			} swtrigr;

			// DHR12R1 (DAC channel1 12-bit right-aligned data holding register(DAC_DHR12R1)) bitfields.
			struct {
				Object *dacc1dhr; // [0:11] DAC channel1 12-bit right-aligned data
			} dhr12r1;

			// DHR12L1 (DAC channel1 12-bit left aligned data holding register (DAC_DHR12L1)) bitfields.
			struct {
				Object *dacc1dhr; // [4:15] DAC channel1 12-bit left-aligned data
			} dhr12l1;

			// DHR8R1 (DAC channel1 8-bit right aligned data holding register (DAC_DHR8R1)) bitfields.
			struct {
				Object *dacc1dhr; // [0:7] DAC channel1 8-bit right-aligned data
			} dhr8r1;

			// DHR12R2 (DAC channel2 12-bit right aligned data holding register (DAC_DHR12R2)) bitfields.
			struct {
				Object *dacc2dhr; // [0:11] DAC channel2 12-bit right-aligned data
			} dhr12r2;

			// DHR12L2 (DAC channel2 12-bit left aligned data holding register (DAC_DHR12L2)) bitfields.
			struct {
				Object *dacc2dhr; // [4:15] DAC channel2 12-bit left-aligned data
			} dhr12l2;

			// DHR8R2 (DAC channel2 8-bit right-aligned data holding register (DAC_DHR8R2)) bitfields.
			struct {
				Object *dacc2dhr; // [0:7] DAC channel2 8-bit right-aligned data
			} dhr8r2;

			// DHR12RD (Dual DAC 12-bit right-aligned data holding register (DAC_DHR12RD), Bits 31:28 Reserved, Bits 15:12 Reserved) bitfields.
			struct {
				Object *dacc1dhr; // [0:11] DAC channel1 12-bit right-aligned data
				Object *dacc2dhr; // [16:27] DAC channel2 12-bit right-aligned data
			} dhr12rd;

			// DHR12LD (DUAL DAC 12-bit left aligned data holding register (DAC_DHR12LD), Bits 19:16 Reserved, Bits 3:0 Reserved) bitfields.
			struct {
				Object *dacc1dhr; // [4:15] DAC channel1 12-bit left-aligned data
				Object *dacc2dhr; // [20:31] DAC channel2 12-bit right-aligned data
			} dhr12ld;

			// DHR8RD (DUAL DAC 8-bit right aligned data holding register (DAC_DHR8RD), Bits 31:16 Reserved) bitfields.
			struct {
				Object *dacc1dhr; // [0:7] DAC channel1 8-bit right-aligned data
				Object *dacc2dhr; // [8:15] DAC channel2 8-bit right-aligned data
			} dhr8rd;

			// DOR1 (DAC channel1 data output register (DAC_DOR1)) bitfields.
			struct {
				Object *dacc1dor; // [0:11] DAC channel1 data output
			} dor1;

			// DOR2 (DAC channel2 data output register (DAC_DOR2)) bitfields.
			struct {
				Object *dacc2dor; // [0:11] DAC channel2 data output
			} dor2;
		} fld;
	} f1;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32DACState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_dac_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32DACState *state = STM32_DAC_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f1.reg.cr = cm_object_get_child_by_name(obj, "CR");
	state->f1.reg.swtrigr = cm_object_get_child_by_name(obj, "SWTRIGR");
	state->f1.reg.dhr12r1 = cm_object_get_child_by_name(obj, "DHR12R1");
	state->f1.reg.dhr12l1 = cm_object_get_child_by_name(obj, "DHR12L1");
	state->f1.reg.dhr8r1 = cm_object_get_child_by_name(obj, "DHR8R1");
	state->f1.reg.dhr12r2 = cm_object_get_child_by_name(obj, "DHR12R2");
	state->f1.reg.dhr12l2 = cm_object_get_child_by_name(obj, "DHR12L2");
	state->f1.reg.dhr8r2 = cm_object_get_child_by_name(obj, "DHR8R2");
	state->f1.reg.dhr12rd = cm_object_get_child_by_name(obj, "DHR12RD");
	state->f1.reg.dhr12ld = cm_object_get_child_by_name(obj, "DHR12LD");
	state->f1.reg.dhr8rd = cm_object_get_child_by_name(obj, "DHR8RD");
	state->f1.reg.dor1 = cm_object_get_child_by_name(obj, "DOR1");
	state->f1.reg.dor2 = cm_object_get_child_by_name(obj, "DOR2");

	// CR bitfields.
	state->f1.fld.cr.en1 = cm_object_get_child_by_name(state->f1.reg.cr, "EN1");
	state->f1.fld.cr.boff1 = cm_object_get_child_by_name(state->f1.reg.cr, "BOFF1");
	state->f1.fld.cr.ten1 = cm_object_get_child_by_name(state->f1.reg.cr, "TEN1");
	state->f1.fld.cr.tsel1 = cm_object_get_child_by_name(state->f1.reg.cr, "TSEL1");
	state->f1.fld.cr.wave1 = cm_object_get_child_by_name(state->f1.reg.cr, "WAVE1");
	state->f1.fld.cr.mamp1 = cm_object_get_child_by_name(state->f1.reg.cr, "MAMP1");
	state->f1.fld.cr.dmaen1 = cm_object_get_child_by_name(state->f1.reg.cr, "DMAEN1");
	state->f1.fld.cr.en2 = cm_object_get_child_by_name(state->f1.reg.cr, "EN2");
	state->f1.fld.cr.boff2 = cm_object_get_child_by_name(state->f1.reg.cr, "BOFF2");
	state->f1.fld.cr.ten2 = cm_object_get_child_by_name(state->f1.reg.cr, "TEN2");
	state->f1.fld.cr.tsel2 = cm_object_get_child_by_name(state->f1.reg.cr, "TSEL2");
	state->f1.fld.cr.wave2 = cm_object_get_child_by_name(state->f1.reg.cr, "WAVE2");
	state->f1.fld.cr.mamp2 = cm_object_get_child_by_name(state->f1.reg.cr, "MAMP2");
	state->f1.fld.cr.dmaen2 = cm_object_get_child_by_name(state->f1.reg.cr, "DMAEN2");

	// SWTRIGR bitfields.
	state->f1.fld.swtrigr.swtrig1 = cm_object_get_child_by_name(state->f1.reg.swtrigr, "SWTRIG1");
	state->f1.fld.swtrigr.swtrig2 = cm_object_get_child_by_name(state->f1.reg.swtrigr, "SWTRIG2");

	// DHR12R1 bitfields.
	state->f1.fld.dhr12r1.dacc1dhr = cm_object_get_child_by_name(state->f1.reg.dhr12r1, "DACC1DHR");

	// DHR12L1 bitfields.
	state->f1.fld.dhr12l1.dacc1dhr = cm_object_get_child_by_name(state->f1.reg.dhr12l1, "DACC1DHR");

	// DHR8R1 bitfields.
	state->f1.fld.dhr8r1.dacc1dhr = cm_object_get_child_by_name(state->f1.reg.dhr8r1, "DACC1DHR");

	// DHR12R2 bitfields.
	state->f1.fld.dhr12r2.dacc2dhr = cm_object_get_child_by_name(state->f1.reg.dhr12r2, "DACC2DHR");

	// DHR12L2 bitfields.
	state->f1.fld.dhr12l2.dacc2dhr = cm_object_get_child_by_name(state->f1.reg.dhr12l2, "DACC2DHR");

	// DHR8R2 bitfields.
	state->f1.fld.dhr8r2.dacc2dhr = cm_object_get_child_by_name(state->f1.reg.dhr8r2, "DACC2DHR");

	// DHR12RD bitfields.
	state->f1.fld.dhr12rd.dacc1dhr = cm_object_get_child_by_name(state->f1.reg.dhr12rd, "DACC1DHR");
	state->f1.fld.dhr12rd.dacc2dhr = cm_object_get_child_by_name(state->f1.reg.dhr12rd, "DACC2DHR");

	// DHR12LD bitfields.
	state->f1.fld.dhr12ld.dacc1dhr = cm_object_get_child_by_name(state->f1.reg.dhr12ld, "DACC1DHR");
	state->f1.fld.dhr12ld.dacc2dhr = cm_object_get_child_by_name(state->f1.reg.dhr12ld, "DACC2DHR");

	// DHR8RD bitfields.
	state->f1.fld.dhr8rd.dacc1dhr = cm_object_get_child_by_name(state->f1.reg.dhr8rd, "DACC1DHR");
	state->f1.fld.dhr8rd.dacc2dhr = cm_object_get_child_by_name(state->f1.reg.dhr8rd, "DACC2DHR");

	// DOR1 bitfields.
	state->f1.fld.dor1.dacc1dor = cm_object_get_child_by_name(state->f1.reg.dor1, "DACC1DOR");

	// DOR2 bitfields.
	state->f1.fld.dor2.dacc2dor = cm_object_get_child_by_name(state->f1.reg.dor2, "DACC2DOR");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DBG (Debug support) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F1 DBG (Debug support) registers.
		struct {
			Object *idcode; // 0x0 DBGMCU_IDCODE
			Object *cr; // 0x4 DBGMCU_CR
		} reg;

		struct {

			// IDCODE (DBGMCU_IDCODE) bitfields.
			struct {
				Object *dev_id; // [0:11] DEV_ID
				Object *rev_id; // [16:31] REV_ID
			} idcode;

			// CR (DBGMCU_CR) bitfields.
			struct {
				Object *dbg_sleep; // [0:0] DBG_SLEEP
				Object *dbg_stop; // [1:1] DBG_STOP
				Object *dbg_standby; // [2:2] DBG_STANDBY
				Object *trace_ioen; // [5:5] TRACE_IOEN
				Object *trace_mode; // [6:7] TRACE_MODE
				Object *dbg_iwdg_stop; // [8:8] DBG_IWDG_STOP
				Object *dbg_wwdg_stop; // [9:9] DBG_WWDG_STOP
				Object *dbg_tim1_stop; // [10:10] DBG_TIM1_STOP
				Object *dbg_tim2_stop; // [11:11] DBG_TIM2_STOP
				Object *dbg_tim3_stop; // [12:12] DBG_TIM3_STOP
				Object *dbg_tim4_stop; // [13:13] DBG_TIM4_STOP
				Object *dbg_can1_stop; // [14:14] DBG_CAN1_STOP
				Object *dbg_i2c1_smbus_timeout; // [15:15] DBG_I2C1_SMBUS_TIMEOUT
				Object *dbg_i2c2_smbus_timeout; // [16:16] DBG_I2C2_SMBUS_TIMEOUT
				Object *dbg_tim8_stop; // [17:17] DBG_TIM8_STOP
				Object *dbg_tim5_stop; // [18:18] DBG_TIM5_STOP
				Object *dbg_tim6_stop; // [19:19] DBG_TIM6_STOP
				Object *dbg_tim7_stop; // [20:20] DBG_TIM7_STOP
				Object *dbg_can2_stop; // [21:21] DBG_CAN2_STOP
			} cr;
		} fld;
	} f1;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32DBGState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_dbg_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32DBGState *state = STM32_DBG_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f1.reg.idcode = cm_object_get_child_by_name(obj, "IDCODE");
	state->f1.reg.cr = cm_object_get_child_by_name(obj, "CR");

	// IDCODE bitfields.
	state->f1.fld.idcode.dev_id = cm_object_get_child_by_name(state->f1.reg.idcode, "DEV_ID");
	state->f1.fld.idcode.rev_id = cm_object_get_child_by_name(state->f1.reg.idcode, "REV_ID");

	// CR bitfields.
	state->f1.fld.cr.dbg_sleep = cm_object_get_child_by_name(state->f1.reg.cr, "DBG_SLEEP");
	state->f1.fld.cr.dbg_stop = cm_object_get_child_by_name(state->f1.reg.cr, "DBG_STOP");
	state->f1.fld.cr.dbg_standby = cm_object_get_child_by_name(state->f1.reg.cr, "DBG_STANDBY");
	state->f1.fld.cr.trace_ioen = cm_object_get_child_by_name(state->f1.reg.cr, "TRACE_IOEN");
	state->f1.fld.cr.trace_mode = cm_object_get_child_by_name(state->f1.reg.cr, "TRACE_MODE");
	state->f1.fld.cr.dbg_iwdg_stop = cm_object_get_child_by_name(state->f1.reg.cr, "DBG_IWDG_STOP");
	state->f1.fld.cr.dbg_wwdg_stop = cm_object_get_child_by_name(state->f1.reg.cr, "DBG_WWDG_STOP");
	state->f1.fld.cr.dbg_tim1_stop = cm_object_get_child_by_name(state->f1.reg.cr, "DBG_TIM1_STOP");
	state->f1.fld.cr.dbg_tim2_stop = cm_object_get_child_by_name(state->f1.reg.cr, "DBG_TIM2_STOP");
	state->f1.fld.cr.dbg_tim3_stop = cm_object_get_child_by_name(state->f1.reg.cr, "DBG_TIM3_STOP");
	state->f1.fld.cr.dbg_tim4_stop = cm_object_get_child_by_name(state->f1.reg.cr, "DBG_TIM4_STOP");
	state->f1.fld.cr.dbg_can1_stop = cm_object_get_child_by_name(state->f1.reg.cr, "DBG_CAN1_STOP");
	state->f1.fld.cr.dbg_i2c1_smbus_timeout = cm_object_get_child_by_name(state->f1.reg.cr, "DBG_I2C1_SMBUS_TIMEOUT");
	state->f1.fld.cr.dbg_i2c2_smbus_timeout = cm_object_get_child_by_name(state->f1.reg.cr, "DBG_I2C2_SMBUS_TIMEOUT");
	state->f1.fld.cr.dbg_tim8_stop = cm_object_get_child_by_name(state->f1.reg.cr, "DBG_TIM8_STOP");
	state->f1.fld.cr.dbg_tim5_stop = cm_object_get_child_by_name(state->f1.reg.cr, "DBG_TIM5_STOP");
	state->f1.fld.cr.dbg_tim6_stop = cm_object_get_child_by_name(state->f1.reg.cr, "DBG_TIM6_STOP");
	state->f1.fld.cr.dbg_tim7_stop = cm_object_get_child_by_name(state->f1.reg.cr, "DBG_TIM7_STOP");
	state->f1.fld.cr.dbg_can2_stop = cm_object_get_child_by_name(state->f1.reg.cr, "DBG_CAN2_STOP");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// UART4 (Universal asynchronous receiver transmitter) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F1 UART4 (Universal asynchronous receiver transmitter) registers.
		struct {
			Object *sr; // 0x0 UART4_SR
			Object *dr; // 0x4 UART4_DR
			Object *brr; // 0x8 UART4_BRR
			Object *cr1; // 0xC UART4_CR1
			Object *cr2; // 0x10 UART4_CR2
			Object *cr3; // 0x14 UART4_CR3
		} reg;

		struct {

			// SR (UART4_SR) bitfields.
			struct {
				Object *pe; // [0:0] Parity error
				Object *fe; // [1:1] Framing error
				Object *ne; // [2:2] Noise error flag
				Object *ore; // [3:3] Overrun error
				Object *idle; // [4:4] IDLE line detected
				Object *rxne; // [5:5] Read data register not empty
				Object *tc; // [6:6] Transmission complete
				Object *txe; // [7:7] Transmit data register empty
				Object *lbd; // [8:8] LIN break detection flag
			} sr;

			// DR (UART4_DR) bitfields.
			struct {
				Object *dr; // [0:8] DR
			} dr;

			// BRR (UART4_BRR) bitfields.
			struct {
				Object *div_fraction; // [0:3] DIV_Fraction
				Object *div_mantissa; // [4:15] DIV_Mantissa
			} brr;

			// CR1 (UART4_CR1) bitfields.
			struct {
				Object *sbk; // [0:0] Send break
				Object *rwu; // [1:1] Receiver wakeup
				Object *re; // [2:2] Receiver enable
				Object *te; // [3:3] Transmitter enable
				Object *idleie; // [4:4] IDLE interrupt enable
				Object *rxneie; // [5:5] RXNE interrupt enable
				Object *tcie; // [6:6] Transmission complete interrupt enable
				Object *txeie; // [7:7] TXE interrupt enable
				Object *peie; // [8:8] PE interrupt enable
				Object *ps; // [9:9] Parity selection
				Object *pce; // [10:10] Parity control enable
				Object *wake; // [11:11] Wakeup method
				Object *m; // [12:12] Word length
				Object *ue; // [13:13] USART enable
			} cr1;

			// CR2 (UART4_CR2) bitfields.
			struct {
				Object *add; // [0:3] Address of the USART node
				Object *lbdl; // [5:5] Lin break detection length
				Object *lbdie; // [6:6] LIN break detection interrupt enable
				Object *stop; // [12:13] STOP bits
				Object *linen; // [14:14] LIN mode enable
			} cr2;

			// CR3 (UART4_CR3) bitfields.
			struct {
				Object *eie; // [0:0] Error interrupt enable
				Object *iren; // [1:1] IrDA mode enable
				Object *irlp; // [2:2] IrDA low-power
				Object *hdsel; // [3:3] Half-duplex selection
				Object *dmar; // [6:6] DMA enable receiver
				Object *dmat; // [7:7] DMA enable transmitter
			} cr3;
		} fld;
	} f1;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32UART4State;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_uart4_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32UART4State *state = STM32_UART4_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f1.reg.sr = cm_object_get_child_by_name(obj, "SR");
	state->f1.reg.dr = cm_object_get_child_by_name(obj, "DR");
	state->f1.reg.brr = cm_object_get_child_by_name(obj, "BRR");
	state->f1.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
	state->f1.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
	state->f1.reg.cr3 = cm_object_get_child_by_name(obj, "CR3");

	// SR bitfields.
	state->f1.fld.sr.pe = cm_object_get_child_by_name(state->f1.reg.sr, "PE");
	state->f1.fld.sr.fe = cm_object_get_child_by_name(state->f1.reg.sr, "FE");
	state->f1.fld.sr.ne = cm_object_get_child_by_name(state->f1.reg.sr, "NE");
	state->f1.fld.sr.ore = cm_object_get_child_by_name(state->f1.reg.sr, "ORE");
	state->f1.fld.sr.idle = cm_object_get_child_by_name(state->f1.reg.sr, "IDLE");
	state->f1.fld.sr.rxne = cm_object_get_child_by_name(state->f1.reg.sr, "RXNE");
	state->f1.fld.sr.tc = cm_object_get_child_by_name(state->f1.reg.sr, "TC");
	state->f1.fld.sr.txe = cm_object_get_child_by_name(state->f1.reg.sr, "TXE");
	state->f1.fld.sr.lbd = cm_object_get_child_by_name(state->f1.reg.sr, "LBD");

	// DR bitfields.
	state->f1.fld.dr.dr = cm_object_get_child_by_name(state->f1.reg.dr, "DR");

	// BRR bitfields.
	state->f1.fld.brr.div_fraction = cm_object_get_child_by_name(state->f1.reg.brr, "DIV_Fraction");
	state->f1.fld.brr.div_mantissa = cm_object_get_child_by_name(state->f1.reg.brr, "DIV_Mantissa");

	// CR1 bitfields.
	state->f1.fld.cr1.sbk = cm_object_get_child_by_name(state->f1.reg.cr1, "SBK");
	state->f1.fld.cr1.rwu = cm_object_get_child_by_name(state->f1.reg.cr1, "RWU");
	state->f1.fld.cr1.re = cm_object_get_child_by_name(state->f1.reg.cr1, "RE");
	state->f1.fld.cr1.te = cm_object_get_child_by_name(state->f1.reg.cr1, "TE");
	state->f1.fld.cr1.idleie = cm_object_get_child_by_name(state->f1.reg.cr1, "IDLEIE");
	state->f1.fld.cr1.rxneie = cm_object_get_child_by_name(state->f1.reg.cr1, "RXNEIE");
	state->f1.fld.cr1.tcie = cm_object_get_child_by_name(state->f1.reg.cr1, "TCIE");
	state->f1.fld.cr1.txeie = cm_object_get_child_by_name(state->f1.reg.cr1, "TXEIE");
	state->f1.fld.cr1.peie = cm_object_get_child_by_name(state->f1.reg.cr1, "PEIE");
	state->f1.fld.cr1.ps = cm_object_get_child_by_name(state->f1.reg.cr1, "PS");
	state->f1.fld.cr1.pce = cm_object_get_child_by_name(state->f1.reg.cr1, "PCE");
	state->f1.fld.cr1.wake = cm_object_get_child_by_name(state->f1.reg.cr1, "WAKE");
	state->f1.fld.cr1.m = cm_object_get_child_by_name(state->f1.reg.cr1, "M");
	state->f1.fld.cr1.ue = cm_object_get_child_by_name(state->f1.reg.cr1, "UE");

	// CR2 bitfields.
	state->f1.fld.cr2.add = cm_object_get_child_by_name(state->f1.reg.cr2, "ADD");
	state->f1.fld.cr2.lbdl = cm_object_get_child_by_name(state->f1.reg.cr2, "LBDL");
	state->f1.fld.cr2.lbdie = cm_object_get_child_by_name(state->f1.reg.cr2, "LBDIE");
	state->f1.fld.cr2.stop = cm_object_get_child_by_name(state->f1.reg.cr2, "STOP");
	state->f1.fld.cr2.linen = cm_object_get_child_by_name(state->f1.reg.cr2, "LINEN");

	// CR3 bitfields.
	state->f1.fld.cr3.eie = cm_object_get_child_by_name(state->f1.reg.cr3, "EIE");
	state->f1.fld.cr3.iren = cm_object_get_child_by_name(state->f1.reg.cr3, "IREN");
	state->f1.fld.cr3.irlp = cm_object_get_child_by_name(state->f1.reg.cr3, "IRLP");
	state->f1.fld.cr3.hdsel = cm_object_get_child_by_name(state->f1.reg.cr3, "HDSEL");
	state->f1.fld.cr3.dmar = cm_object_get_child_by_name(state->f1.reg.cr3, "DMAR");
	state->f1.fld.cr3.dmat = cm_object_get_child_by_name(state->f1.reg.cr3, "DMAT");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// UART5 (Universal asynchronous receiver transmitter) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F1 UART5 (Universal asynchronous receiver transmitter) registers.
		struct {
			Object *sr; // 0x0 UART4_SR
			Object *dr; // 0x4 UART4_DR
			Object *brr; // 0x8 UART4_BRR
			Object *cr1; // 0xC UART4_CR1
			Object *cr2; // 0x10 UART4_CR2
			Object *cr3; // 0x14 UART4_CR3
		} reg;

		struct {

			// SR (UART4_SR) bitfields.
			struct {
				Object *pe; // [0:0] PE
				Object *fe; // [1:1] FE
				Object *ne; // [2:2] NE
				Object *ore; // [3:3] ORE
				Object *idle; // [4:4] IDLE
				Object *rxne; // [5:5] RXNE
				Object *tc; // [6:6] TC
				Object *txe; // [7:7] TXE
				Object *lbd; // [8:8] LBD
			} sr;

			// DR (UART4_DR) bitfields.
			struct {
				Object *dr; // [0:8] DR
			} dr;

			// BRR (UART4_BRR) bitfields.
			struct {
				Object *div_fraction; // [0:3] DIV_Fraction
				Object *div_mantissa; // [4:15] DIV_Mantissa
			} brr;

			// CR1 (UART4_CR1) bitfields.
			struct {
				Object *sbk; // [0:0] SBK
				Object *rwu; // [1:1] RWU
				Object *re; // [2:2] RE
				Object *te; // [3:3] TE
				Object *idleie; // [4:4] IDLEIE
				Object *rxneie; // [5:5] RXNEIE
				Object *tcie; // [6:6] TCIE
				Object *txeie; // [7:7] TXEIE
				Object *peie; // [8:8] PEIE
				Object *ps; // [9:9] PS
				Object *pce; // [10:10] PCE
				Object *wake; // [11:11] WAKE
				Object *m; // [12:12] M
				Object *ue; // [13:13] UE
			} cr1;

			// CR2 (UART4_CR2) bitfields.
			struct {
				Object *add; // [0:3] ADD
				Object *lbdl; // [5:5] LBDL
				Object *lbdie; // [6:6] LBDIE
				Object *stop; // [12:13] STOP
				Object *linen; // [14:14] LINEN
			} cr2;

			// CR3 (UART4_CR3) bitfields.
			struct {
				Object *eie; // [0:0] Error interrupt enable
				Object *iren; // [1:1] IrDA mode enable
				Object *irlp; // [2:2] IrDA low-power
				Object *hdsel; // [3:3] Half-duplex selection
				Object *dmat; // [7:7] DMA enable transmitter
			} cr3;
		} fld;
	} f1;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32UART5State;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_uart5_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32UART5State *state = STM32_UART5_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f1.reg.sr = cm_object_get_child_by_name(obj, "SR");
	state->f1.reg.dr = cm_object_get_child_by_name(obj, "DR");
	state->f1.reg.brr = cm_object_get_child_by_name(obj, "BRR");
	state->f1.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
	state->f1.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
	state->f1.reg.cr3 = cm_object_get_child_by_name(obj, "CR3");

	// SR bitfields.
	state->f1.fld.sr.pe = cm_object_get_child_by_name(state->f1.reg.sr, "PE");
	state->f1.fld.sr.fe = cm_object_get_child_by_name(state->f1.reg.sr, "FE");
	state->f1.fld.sr.ne = cm_object_get_child_by_name(state->f1.reg.sr, "NE");
	state->f1.fld.sr.ore = cm_object_get_child_by_name(state->f1.reg.sr, "ORE");
	state->f1.fld.sr.idle = cm_object_get_child_by_name(state->f1.reg.sr, "IDLE");
	state->f1.fld.sr.rxne = cm_object_get_child_by_name(state->f1.reg.sr, "RXNE");
	state->f1.fld.sr.tc = cm_object_get_child_by_name(state->f1.reg.sr, "TC");
	state->f1.fld.sr.txe = cm_object_get_child_by_name(state->f1.reg.sr, "TXE");
	state->f1.fld.sr.lbd = cm_object_get_child_by_name(state->f1.reg.sr, "LBD");

	// DR bitfields.
	state->f1.fld.dr.dr = cm_object_get_child_by_name(state->f1.reg.dr, "DR");

	// BRR bitfields.
	state->f1.fld.brr.div_fraction = cm_object_get_child_by_name(state->f1.reg.brr, "DIV_Fraction");
	state->f1.fld.brr.div_mantissa = cm_object_get_child_by_name(state->f1.reg.brr, "DIV_Mantissa");

	// CR1 bitfields.
	state->f1.fld.cr1.sbk = cm_object_get_child_by_name(state->f1.reg.cr1, "SBK");
	state->f1.fld.cr1.rwu = cm_object_get_child_by_name(state->f1.reg.cr1, "RWU");
	state->f1.fld.cr1.re = cm_object_get_child_by_name(state->f1.reg.cr1, "RE");
	state->f1.fld.cr1.te = cm_object_get_child_by_name(state->f1.reg.cr1, "TE");
	state->f1.fld.cr1.idleie = cm_object_get_child_by_name(state->f1.reg.cr1, "IDLEIE");
	state->f1.fld.cr1.rxneie = cm_object_get_child_by_name(state->f1.reg.cr1, "RXNEIE");
	state->f1.fld.cr1.tcie = cm_object_get_child_by_name(state->f1.reg.cr1, "TCIE");
	state->f1.fld.cr1.txeie = cm_object_get_child_by_name(state->f1.reg.cr1, "TXEIE");
	state->f1.fld.cr1.peie = cm_object_get_child_by_name(state->f1.reg.cr1, "PEIE");
	state->f1.fld.cr1.ps = cm_object_get_child_by_name(state->f1.reg.cr1, "PS");
	state->f1.fld.cr1.pce = cm_object_get_child_by_name(state->f1.reg.cr1, "PCE");
	state->f1.fld.cr1.wake = cm_object_get_child_by_name(state->f1.reg.cr1, "WAKE");
	state->f1.fld.cr1.m = cm_object_get_child_by_name(state->f1.reg.cr1, "M");
	state->f1.fld.cr1.ue = cm_object_get_child_by_name(state->f1.reg.cr1, "UE");

	// CR2 bitfields.
	state->f1.fld.cr2.add = cm_object_get_child_by_name(state->f1.reg.cr2, "ADD");
	state->f1.fld.cr2.lbdl = cm_object_get_child_by_name(state->f1.reg.cr2, "LBDL");
	state->f1.fld.cr2.lbdie = cm_object_get_child_by_name(state->f1.reg.cr2, "LBDIE");
	state->f1.fld.cr2.stop = cm_object_get_child_by_name(state->f1.reg.cr2, "STOP");
	state->f1.fld.cr2.linen = cm_object_get_child_by_name(state->f1.reg.cr2, "LINEN");

	// CR3 bitfields.
	state->f1.fld.cr3.eie = cm_object_get_child_by_name(state->f1.reg.cr3, "EIE");
	state->f1.fld.cr3.iren = cm_object_get_child_by_name(state->f1.reg.cr3, "IREN");
	state->f1.fld.cr3.irlp = cm_object_get_child_by_name(state->f1.reg.cr3, "IRLP");
	state->f1.fld.cr3.hdsel = cm_object_get_child_by_name(state->f1.reg.cr3, "HDSEL");
	state->f1.fld.cr3.dmat = cm_object_get_child_by_name(state->f1.reg.cr3, "DMAT");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// CRC (CRC calculation unit) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F1 CRC (CRC calculation unit) registers.
		struct {
			Object *dr; // 0x0 Data register
			Object *idr; // 0x4 Independent Data register
			Object *cr; // 0x8 Control register
		} reg;

		struct {

			// DR (Data register) bitfields.
			struct {
				Object *dr; // [0:31] Data Register
			} dr;

			// IDR (Independent Data register) bitfields.
			struct {
				Object *idr; // [0:7] Independent Data register
			} idr;

			// CR (Control register) bitfields.
			struct {
				Object *reset; // [0:0] Reset bit
			} cr;
		} fld;
	} f1;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32CRCState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_crc_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32CRCState *state = STM32_CRC_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f1.reg.dr = cm_object_get_child_by_name(obj, "DR");
	state->f1.reg.idr = cm_object_get_child_by_name(obj, "IDR");
	state->f1.reg.cr = cm_object_get_child_by_name(obj, "CR");

	// DR bitfields.
	state->f1.fld.dr.dr = cm_object_get_child_by_name(state->f1.reg.dr, "DR");

	// IDR bitfields.
	state->f1.fld.idr.idr = cm_object_get_child_by_name(state->f1.reg.idr, "IDR");

	// CR bitfields.
	state->f1.fld.cr.reset = cm_object_get_child_by_name(state->f1.reg.cr, "RESET");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// FLASH (FLASH) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F1 FLASH (FLASH) registers.
		struct {
			Object *acr; // 0x0 Flash access control register
			Object *keyr; // 0x4 Flash key register
			Object *optkeyr; // 0x8 Flash option key register
			Object *sr; // 0xC Status register
			Object *cr; // 0x10 Control register
			Object *ar; // 0x14 Flash address register
			Object *obr; // 0x1C Option byte register
			Object *wrpr; // 0x20 Write protection register
		} reg;

		struct {

			// ACR (Flash access control register) bitfields.
			struct {
				Object *latency; // [0:2] Latency
				Object *hlfcya; // [3:3] Flash half cycle access enable
				Object *prftbe; // [4:4] Prefetch buffer enable
				Object *prftbs; // [5:5] Prefetch buffer status
			} acr;

			// KEYR (Flash key register) bitfields.
			struct {
				Object *key; // [0:31] FPEC key
			} keyr;

			// OPTKEYR (Flash option key register) bitfields.
			struct {
				Object *optkey; // [0:31] Option byte key
			} optkeyr;

			// SR (Status register) bitfields.
			struct {
				Object *bsy; // [0:0] Busy
				Object *pgerr; // [2:2] Programming error
				Object *wrprterr; // [4:4] Write protection error
				Object *eop; // [5:5] End of operation
			} sr;

			// CR (Control register) bitfields.
			struct {
				Object *pg; // [0:0] Programming
				Object *per; // [1:1] Page Erase
				Object *mer; // [2:2] Mass Erase
				Object *optpg; // [4:4] Option byte programming
				Object *opter; // [5:5] Option byte erase
				Object *strt; // [6:6] Start
				Object *lock; // [7:7] Lock
				Object *optwre; // [9:9] Option bytes write enable
				Object *errie; // [10:10] Error interrupt enable
				Object *eopie; // [12:12] End of operation interrupt enable
			} cr;

			// AR (Flash address register) bitfields.
			struct {
				Object *far; // [0:31] Flash Address
			} ar;

			// OBR (Option byte register) bitfields.
			struct {
				Object *opterr; // [0:0] Option byte error
				Object *rdprt; // [1:1] Read protection
				Object *wdg_sw; // [2:2] WDG_SW
				Object *nrst_stop; // [3:3] NRST_STOP
				Object *nrst_stdby; // [4:4] NRST_STDBY
				Object *data0; // [10:17] Data0
				Object *data1; // [18:25] Data1
			} obr;

			// WRPR (Write protection register) bitfields.
			struct {
				Object *wrp; // [0:31] Write protect
			} wrpr;
		} fld;
	} f1;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32FLASHState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_flash_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32FLASHState *state = STM32_FLASH_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f1.reg.acr = cm_object_get_child_by_name(obj, "ACR");
	state->f1.reg.keyr = cm_object_get_child_by_name(obj, "KEYR");
	state->f1.reg.optkeyr = cm_object_get_child_by_name(obj, "OPTKEYR");
	state->f1.reg.sr = cm_object_get_child_by_name(obj, "SR");
	state->f1.reg.cr = cm_object_get_child_by_name(obj, "CR");
	state->f1.reg.ar = cm_object_get_child_by_name(obj, "AR");
	state->f1.reg.obr = cm_object_get_child_by_name(obj, "OBR");
	state->f1.reg.wrpr = cm_object_get_child_by_name(obj, "WRPR");

	// ACR bitfields.
	state->f1.fld.acr.latency = cm_object_get_child_by_name(state->f1.reg.acr, "LATENCY");
	state->f1.fld.acr.hlfcya = cm_object_get_child_by_name(state->f1.reg.acr, "HLFCYA");
	state->f1.fld.acr.prftbe = cm_object_get_child_by_name(state->f1.reg.acr, "PRFTBE");
	state->f1.fld.acr.prftbs = cm_object_get_child_by_name(state->f1.reg.acr, "PRFTBS");

	// KEYR bitfields.
	state->f1.fld.keyr.key = cm_object_get_child_by_name(state->f1.reg.keyr, "KEY");

	// OPTKEYR bitfields.
	state->f1.fld.optkeyr.optkey = cm_object_get_child_by_name(state->f1.reg.optkeyr, "OPTKEY");

	// SR bitfields.
	state->f1.fld.sr.bsy = cm_object_get_child_by_name(state->f1.reg.sr, "BSY");
	state->f1.fld.sr.pgerr = cm_object_get_child_by_name(state->f1.reg.sr, "PGERR");
	state->f1.fld.sr.wrprterr = cm_object_get_child_by_name(state->f1.reg.sr, "WRPRTERR");
	state->f1.fld.sr.eop = cm_object_get_child_by_name(state->f1.reg.sr, "EOP");

	// CR bitfields.
	state->f1.fld.cr.pg = cm_object_get_child_by_name(state->f1.reg.cr, "PG");
	state->f1.fld.cr.per = cm_object_get_child_by_name(state->f1.reg.cr, "PER");
	state->f1.fld.cr.mer = cm_object_get_child_by_name(state->f1.reg.cr, "MER");
	state->f1.fld.cr.optpg = cm_object_get_child_by_name(state->f1.reg.cr, "OPTPG");
	state->f1.fld.cr.opter = cm_object_get_child_by_name(state->f1.reg.cr, "OPTER");
	state->f1.fld.cr.strt = cm_object_get_child_by_name(state->f1.reg.cr, "STRT");
	state->f1.fld.cr.lock = cm_object_get_child_by_name(state->f1.reg.cr, "LOCK");
	state->f1.fld.cr.optwre = cm_object_get_child_by_name(state->f1.reg.cr, "OPTWRE");
	state->f1.fld.cr.errie = cm_object_get_child_by_name(state->f1.reg.cr, "ERRIE");
	state->f1.fld.cr.eopie = cm_object_get_child_by_name(state->f1.reg.cr, "EOPIE");

	// AR bitfields.
	state->f1.fld.ar.far = cm_object_get_child_by_name(state->f1.reg.ar, "FAR");

	// OBR bitfields.
	state->f1.fld.obr.opterr = cm_object_get_child_by_name(state->f1.reg.obr, "OPTERR");
	state->f1.fld.obr.rdprt = cm_object_get_child_by_name(state->f1.reg.obr, "RDPRT");
	state->f1.fld.obr.wdg_sw = cm_object_get_child_by_name(state->f1.reg.obr, "WDG_SW");
	state->f1.fld.obr.nrst_stop = cm_object_get_child_by_name(state->f1.reg.obr, "nRST_STOP");
	state->f1.fld.obr.nrst_stdby = cm_object_get_child_by_name(state->f1.reg.obr, "nRST_STDBY");
	state->f1.fld.obr.data0 = cm_object_get_child_by_name(state->f1.reg.obr, "Data0");
	state->f1.fld.obr.data1 = cm_object_get_child_by_name(state->f1.reg.obr, "Data1");

	// WRPR bitfields.
	state->f1.fld.wrpr.wrp = cm_object_get_child_by_name(state->f1.reg.wrpr, "WRP");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// USB (Universal serial bus full-speed device interface) peripheral.
struct {
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

	// DO NOT EDIT! Automatically generated!
	struct {
		// F1 USB (Universal serial bus full-speed device interface) registers.
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
		} fld;
	} f1;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
} STM32USBState;

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_usb_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
	STM32USBState *state = STM32_USB_STATE(obj);

	JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
	svd_add_peripheral_properties_and_children(obj, periph, svd);

	// Registers.
	state->f1.reg.ep0r = cm_object_get_child_by_name(obj, "EP0R");
	state->f1.reg.ep1r = cm_object_get_child_by_name(obj, "EP1R");
	state->f1.reg.ep2r = cm_object_get_child_by_name(obj, "EP2R");
	state->f1.reg.ep3r = cm_object_get_child_by_name(obj, "EP3R");
	state->f1.reg.ep4r = cm_object_get_child_by_name(obj, "EP4R");
	state->f1.reg.ep5r = cm_object_get_child_by_name(obj, "EP5R");
	state->f1.reg.ep6r = cm_object_get_child_by_name(obj, "EP6R");
	state->f1.reg.ep7r = cm_object_get_child_by_name(obj, "EP7R");
	state->f1.reg.cntr = cm_object_get_child_by_name(obj, "CNTR");
	state->f1.reg.istr = cm_object_get_child_by_name(obj, "ISTR");
	state->f1.reg.fnr = cm_object_get_child_by_name(obj, "FNR");
	state->f1.reg.daddr = cm_object_get_child_by_name(obj, "DADDR");
	state->f1.reg.btable = cm_object_get_child_by_name(obj, "BTABLE");

	// EP0R bitfields.
	state->f1.fld.ep0r.ea = cm_object_get_child_by_name(state->f1.reg.ep0r, "EA");
	state->f1.fld.ep0r.stat_tx = cm_object_get_child_by_name(state->f1.reg.ep0r, "STAT_TX");
	state->f1.fld.ep0r.dtog_tx = cm_object_get_child_by_name(state->f1.reg.ep0r, "DTOG_TX");
	state->f1.fld.ep0r.ctr_tx = cm_object_get_child_by_name(state->f1.reg.ep0r, "CTR_TX");
	state->f1.fld.ep0r.ep_kind = cm_object_get_child_by_name(state->f1.reg.ep0r, "EP_KIND");
	state->f1.fld.ep0r.ep_type = cm_object_get_child_by_name(state->f1.reg.ep0r, "EP_TYPE");
	state->f1.fld.ep0r.setup = cm_object_get_child_by_name(state->f1.reg.ep0r, "SETUP");
	state->f1.fld.ep0r.stat_rx = cm_object_get_child_by_name(state->f1.reg.ep0r, "STAT_RX");
	state->f1.fld.ep0r.dtog_rx = cm_object_get_child_by_name(state->f1.reg.ep0r, "DTOG_RX");
	state->f1.fld.ep0r.ctr_rx = cm_object_get_child_by_name(state->f1.reg.ep0r, "CTR_RX");

	// EP1R bitfields.
	state->f1.fld.ep1r.ea = cm_object_get_child_by_name(state->f1.reg.ep1r, "EA");
	state->f1.fld.ep1r.stat_tx = cm_object_get_child_by_name(state->f1.reg.ep1r, "STAT_TX");
	state->f1.fld.ep1r.dtog_tx = cm_object_get_child_by_name(state->f1.reg.ep1r, "DTOG_TX");
	state->f1.fld.ep1r.ctr_tx = cm_object_get_child_by_name(state->f1.reg.ep1r, "CTR_TX");
	state->f1.fld.ep1r.ep_kind = cm_object_get_child_by_name(state->f1.reg.ep1r, "EP_KIND");
	state->f1.fld.ep1r.ep_type = cm_object_get_child_by_name(state->f1.reg.ep1r, "EP_TYPE");
	state->f1.fld.ep1r.setup = cm_object_get_child_by_name(state->f1.reg.ep1r, "SETUP");
	state->f1.fld.ep1r.stat_rx = cm_object_get_child_by_name(state->f1.reg.ep1r, "STAT_RX");
	state->f1.fld.ep1r.dtog_rx = cm_object_get_child_by_name(state->f1.reg.ep1r, "DTOG_RX");
	state->f1.fld.ep1r.ctr_rx = cm_object_get_child_by_name(state->f1.reg.ep1r, "CTR_RX");

	// EP2R bitfields.
	state->f1.fld.ep2r.ea = cm_object_get_child_by_name(state->f1.reg.ep2r, "EA");
	state->f1.fld.ep2r.stat_tx = cm_object_get_child_by_name(state->f1.reg.ep2r, "STAT_TX");
	state->f1.fld.ep2r.dtog_tx = cm_object_get_child_by_name(state->f1.reg.ep2r, "DTOG_TX");
	state->f1.fld.ep2r.ctr_tx = cm_object_get_child_by_name(state->f1.reg.ep2r, "CTR_TX");
	state->f1.fld.ep2r.ep_kind = cm_object_get_child_by_name(state->f1.reg.ep2r, "EP_KIND");
	state->f1.fld.ep2r.ep_type = cm_object_get_child_by_name(state->f1.reg.ep2r, "EP_TYPE");
	state->f1.fld.ep2r.setup = cm_object_get_child_by_name(state->f1.reg.ep2r, "SETUP");
	state->f1.fld.ep2r.stat_rx = cm_object_get_child_by_name(state->f1.reg.ep2r, "STAT_RX");
	state->f1.fld.ep2r.dtog_rx = cm_object_get_child_by_name(state->f1.reg.ep2r, "DTOG_RX");
	state->f1.fld.ep2r.ctr_rx = cm_object_get_child_by_name(state->f1.reg.ep2r, "CTR_RX");

	// EP3R bitfields.
	state->f1.fld.ep3r.ea = cm_object_get_child_by_name(state->f1.reg.ep3r, "EA");
	state->f1.fld.ep3r.stat_tx = cm_object_get_child_by_name(state->f1.reg.ep3r, "STAT_TX");
	state->f1.fld.ep3r.dtog_tx = cm_object_get_child_by_name(state->f1.reg.ep3r, "DTOG_TX");
	state->f1.fld.ep3r.ctr_tx = cm_object_get_child_by_name(state->f1.reg.ep3r, "CTR_TX");
	state->f1.fld.ep3r.ep_kind = cm_object_get_child_by_name(state->f1.reg.ep3r, "EP_KIND");
	state->f1.fld.ep3r.ep_type = cm_object_get_child_by_name(state->f1.reg.ep3r, "EP_TYPE");
	state->f1.fld.ep3r.setup = cm_object_get_child_by_name(state->f1.reg.ep3r, "SETUP");
	state->f1.fld.ep3r.stat_rx = cm_object_get_child_by_name(state->f1.reg.ep3r, "STAT_RX");
	state->f1.fld.ep3r.dtog_rx = cm_object_get_child_by_name(state->f1.reg.ep3r, "DTOG_RX");
	state->f1.fld.ep3r.ctr_rx = cm_object_get_child_by_name(state->f1.reg.ep3r, "CTR_RX");

	// EP4R bitfields.
	state->f1.fld.ep4r.ea = cm_object_get_child_by_name(state->f1.reg.ep4r, "EA");
	state->f1.fld.ep4r.stat_tx = cm_object_get_child_by_name(state->f1.reg.ep4r, "STAT_TX");
	state->f1.fld.ep4r.dtog_tx = cm_object_get_child_by_name(state->f1.reg.ep4r, "DTOG_TX");
	state->f1.fld.ep4r.ctr_tx = cm_object_get_child_by_name(state->f1.reg.ep4r, "CTR_TX");
	state->f1.fld.ep4r.ep_kind = cm_object_get_child_by_name(state->f1.reg.ep4r, "EP_KIND");
	state->f1.fld.ep4r.ep_type = cm_object_get_child_by_name(state->f1.reg.ep4r, "EP_TYPE");
	state->f1.fld.ep4r.setup = cm_object_get_child_by_name(state->f1.reg.ep4r, "SETUP");
	state->f1.fld.ep4r.stat_rx = cm_object_get_child_by_name(state->f1.reg.ep4r, "STAT_RX");
	state->f1.fld.ep4r.dtog_rx = cm_object_get_child_by_name(state->f1.reg.ep4r, "DTOG_RX");
	state->f1.fld.ep4r.ctr_rx = cm_object_get_child_by_name(state->f1.reg.ep4r, "CTR_RX");

	// EP5R bitfields.
	state->f1.fld.ep5r.ea = cm_object_get_child_by_name(state->f1.reg.ep5r, "EA");
	state->f1.fld.ep5r.stat_tx = cm_object_get_child_by_name(state->f1.reg.ep5r, "STAT_TX");
	state->f1.fld.ep5r.dtog_tx = cm_object_get_child_by_name(state->f1.reg.ep5r, "DTOG_TX");
	state->f1.fld.ep5r.ctr_tx = cm_object_get_child_by_name(state->f1.reg.ep5r, "CTR_TX");
	state->f1.fld.ep5r.ep_kind = cm_object_get_child_by_name(state->f1.reg.ep5r, "EP_KIND");
	state->f1.fld.ep5r.ep_type = cm_object_get_child_by_name(state->f1.reg.ep5r, "EP_TYPE");
	state->f1.fld.ep5r.setup = cm_object_get_child_by_name(state->f1.reg.ep5r, "SETUP");
	state->f1.fld.ep5r.stat_rx = cm_object_get_child_by_name(state->f1.reg.ep5r, "STAT_RX");
	state->f1.fld.ep5r.dtog_rx = cm_object_get_child_by_name(state->f1.reg.ep5r, "DTOG_RX");
	state->f1.fld.ep5r.ctr_rx = cm_object_get_child_by_name(state->f1.reg.ep5r, "CTR_RX");

	// EP6R bitfields.
	state->f1.fld.ep6r.ea = cm_object_get_child_by_name(state->f1.reg.ep6r, "EA");
	state->f1.fld.ep6r.stat_tx = cm_object_get_child_by_name(state->f1.reg.ep6r, "STAT_TX");
	state->f1.fld.ep6r.dtog_tx = cm_object_get_child_by_name(state->f1.reg.ep6r, "DTOG_TX");
	state->f1.fld.ep6r.ctr_tx = cm_object_get_child_by_name(state->f1.reg.ep6r, "CTR_TX");
	state->f1.fld.ep6r.ep_kind = cm_object_get_child_by_name(state->f1.reg.ep6r, "EP_KIND");
	state->f1.fld.ep6r.ep_type = cm_object_get_child_by_name(state->f1.reg.ep6r, "EP_TYPE");
	state->f1.fld.ep6r.setup = cm_object_get_child_by_name(state->f1.reg.ep6r, "SETUP");
	state->f1.fld.ep6r.stat_rx = cm_object_get_child_by_name(state->f1.reg.ep6r, "STAT_RX");
	state->f1.fld.ep6r.dtog_rx = cm_object_get_child_by_name(state->f1.reg.ep6r, "DTOG_RX");
	state->f1.fld.ep6r.ctr_rx = cm_object_get_child_by_name(state->f1.reg.ep6r, "CTR_RX");

	// EP7R bitfields.
	state->f1.fld.ep7r.ea = cm_object_get_child_by_name(state->f1.reg.ep7r, "EA");
	state->f1.fld.ep7r.stat_tx = cm_object_get_child_by_name(state->f1.reg.ep7r, "STAT_TX");
	state->f1.fld.ep7r.dtog_tx = cm_object_get_child_by_name(state->f1.reg.ep7r, "DTOG_TX");
	state->f1.fld.ep7r.ctr_tx = cm_object_get_child_by_name(state->f1.reg.ep7r, "CTR_TX");
	state->f1.fld.ep7r.ep_kind = cm_object_get_child_by_name(state->f1.reg.ep7r, "EP_KIND");
	state->f1.fld.ep7r.ep_type = cm_object_get_child_by_name(state->f1.reg.ep7r, "EP_TYPE");
	state->f1.fld.ep7r.setup = cm_object_get_child_by_name(state->f1.reg.ep7r, "SETUP");
	state->f1.fld.ep7r.stat_rx = cm_object_get_child_by_name(state->f1.reg.ep7r, "STAT_RX");
	state->f1.fld.ep7r.dtog_rx = cm_object_get_child_by_name(state->f1.reg.ep7r, "DTOG_RX");
	state->f1.fld.ep7r.ctr_rx = cm_object_get_child_by_name(state->f1.reg.ep7r, "CTR_RX");

	// CNTR bitfields.
	state->f1.fld.cntr.fres = cm_object_get_child_by_name(state->f1.reg.cntr, "FRES");
	state->f1.fld.cntr.pdwn = cm_object_get_child_by_name(state->f1.reg.cntr, "PDWN");
	state->f1.fld.cntr.lpmode = cm_object_get_child_by_name(state->f1.reg.cntr, "LPMODE");
	state->f1.fld.cntr.fsusp = cm_object_get_child_by_name(state->f1.reg.cntr, "FSUSP");
	state->f1.fld.cntr.resume = cm_object_get_child_by_name(state->f1.reg.cntr, "RESUME");
	state->f1.fld.cntr.esofm = cm_object_get_child_by_name(state->f1.reg.cntr, "ESOFM");
	state->f1.fld.cntr.sofm = cm_object_get_child_by_name(state->f1.reg.cntr, "SOFM");
	state->f1.fld.cntr.resetm = cm_object_get_child_by_name(state->f1.reg.cntr, "RESETM");
	state->f1.fld.cntr.suspm = cm_object_get_child_by_name(state->f1.reg.cntr, "SUSPM");
	state->f1.fld.cntr.wkupm = cm_object_get_child_by_name(state->f1.reg.cntr, "WKUPM");
	state->f1.fld.cntr.errm = cm_object_get_child_by_name(state->f1.reg.cntr, "ERRM");
	state->f1.fld.cntr.pmaovrm = cm_object_get_child_by_name(state->f1.reg.cntr, "PMAOVRM");
	state->f1.fld.cntr.ctrm = cm_object_get_child_by_name(state->f1.reg.cntr, "CTRM");

	// ISTR bitfields.
	state->f1.fld.istr.ep_id = cm_object_get_child_by_name(state->f1.reg.istr, "EP_ID");
	state->f1.fld.istr.dir = cm_object_get_child_by_name(state->f1.reg.istr, "DIR");
	state->f1.fld.istr.esof = cm_object_get_child_by_name(state->f1.reg.istr, "ESOF");
	state->f1.fld.istr.sof = cm_object_get_child_by_name(state->f1.reg.istr, "SOF");
	state->f1.fld.istr.reset = cm_object_get_child_by_name(state->f1.reg.istr, "RESET");
	state->f1.fld.istr.susp = cm_object_get_child_by_name(state->f1.reg.istr, "SUSP");
	state->f1.fld.istr.wkup = cm_object_get_child_by_name(state->f1.reg.istr, "WKUP");
	state->f1.fld.istr.err = cm_object_get_child_by_name(state->f1.reg.istr, "ERR");
	state->f1.fld.istr.pmaovr = cm_object_get_child_by_name(state->f1.reg.istr, "PMAOVR");
	state->f1.fld.istr.ctr = cm_object_get_child_by_name(state->f1.reg.istr, "CTR");

	// FNR bitfields.
	state->f1.fld.fnr.fn = cm_object_get_child_by_name(state->f1.reg.fnr, "FN");
	state->f1.fld.fnr.lsof = cm_object_get_child_by_name(state->f1.reg.fnr, "LSOF");
	state->f1.fld.fnr.lck = cm_object_get_child_by_name(state->f1.reg.fnr, "LCK");
	state->f1.fld.fnr.rxdm = cm_object_get_child_by_name(state->f1.reg.fnr, "RXDM");
	state->f1.fld.fnr.rxdp = cm_object_get_child_by_name(state->f1.reg.fnr, "RXDP");

	// DADDR bitfields.
	state->f1.fld.daddr.add = cm_object_get_child_by_name(state->f1.reg.daddr, "ADD");
	state->f1.fld.daddr.ef = cm_object_get_child_by_name(state->f1.reg.daddr, "EF");

	// BTABLE bitfields.
	state->f1.fld.btable.btable = cm_object_get_child_by_name(state->f1.reg.btable, "BTABLE");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

