#ifndef INCLUDED_CYFITTERIAR_INC
#define INCLUDED_CYFITTERIAR_INC
    INCLUDE cydeviceiar.inc
    INCLUDE cydeviceiar_trm.inc

/* SW */
SW__0__MASK EQU 0x02
SW__0__PC EQU CYREG_PRT6_PC1
SW__0__PORT EQU 6
SW__0__SHIFT EQU 1
SW__AG EQU CYREG_PRT6_AG
SW__AMUX EQU CYREG_PRT6_AMUX
SW__BIE EQU CYREG_PRT6_BIE
SW__BIT_MASK EQU CYREG_PRT6_BIT_MASK
SW__BYP EQU CYREG_PRT6_BYP
SW__CTL EQU CYREG_PRT6_CTL
SW__DM0 EQU CYREG_PRT6_DM0
SW__DM1 EQU CYREG_PRT6_DM1
SW__DM2 EQU CYREG_PRT6_DM2
SW__DR EQU CYREG_PRT6_DR
SW__INP_DIS EQU CYREG_PRT6_INP_DIS
SW__LCD_COM_SEG EQU CYREG_PRT6_LCD_COM_SEG
SW__LCD_EN EQU CYREG_PRT6_LCD_EN
SW__MASK EQU 0x02
SW__PORT EQU 6
SW__PRT EQU CYREG_PRT6_PRT
SW__PRTDSI__CAPS_SEL EQU CYREG_PRT6_CAPS_SEL
SW__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT6_DBL_SYNC_IN
SW__PRTDSI__OE_SEL0 EQU CYREG_PRT6_OE_SEL0
SW__PRTDSI__OE_SEL1 EQU CYREG_PRT6_OE_SEL1
SW__PRTDSI__OUT_SEL0 EQU CYREG_PRT6_OUT_SEL0
SW__PRTDSI__OUT_SEL1 EQU CYREG_PRT6_OUT_SEL1
SW__PRTDSI__SYNC_OUT EQU CYREG_PRT6_SYNC_OUT
SW__PS EQU CYREG_PRT6_PS
SW__SHIFT EQU 1
SW__SLW EQU CYREG_PRT6_SLW

/* ADC_DEC */
ADC_DEC__COHER EQU CYREG_DEC_COHER
ADC_DEC__CR EQU CYREG_DEC_CR
ADC_DEC__DR1 EQU CYREG_DEC_DR1
ADC_DEC__DR2 EQU CYREG_DEC_DR2
ADC_DEC__DR2H EQU CYREG_DEC_DR2H
ADC_DEC__GCOR EQU CYREG_DEC_GCOR
ADC_DEC__GCORH EQU CYREG_DEC_GCORH
ADC_DEC__GVAL EQU CYREG_DEC_GVAL
ADC_DEC__OCOR EQU CYREG_DEC_OCOR
ADC_DEC__OCORH EQU CYREG_DEC_OCORH
ADC_DEC__OCORM EQU CYREG_DEC_OCORM
ADC_DEC__OUTSAMP EQU CYREG_DEC_OUTSAMP
ADC_DEC__OUTSAMPH EQU CYREG_DEC_OUTSAMPH
ADC_DEC__OUTSAMPM EQU CYREG_DEC_OUTSAMPM
ADC_DEC__OUTSAMPS EQU CYREG_DEC_OUTSAMPS
ADC_DEC__PM_ACT_CFG EQU CYREG_PM_ACT_CFG10
ADC_DEC__PM_ACT_MSK EQU 0x01
ADC_DEC__PM_STBY_CFG EQU CYREG_PM_STBY_CFG10
ADC_DEC__PM_STBY_MSK EQU 0x01
ADC_DEC__SHIFT1 EQU CYREG_DEC_SHIFT1
ADC_DEC__SHIFT2 EQU CYREG_DEC_SHIFT2
ADC_DEC__SR EQU CYREG_DEC_SR
ADC_DEC__TRIM__M1 EQU CYREG_FLSHID_CUST_TABLES_DEC_M1
ADC_DEC__TRIM__M2 EQU CYREG_FLSHID_CUST_TABLES_DEC_M2
ADC_DEC__TRIM__M3 EQU CYREG_FLSHID_CUST_TABLES_DEC_M3
ADC_DEC__TRIM__M4 EQU CYREG_FLSHID_CUST_TABLES_DEC_M4
ADC_DEC__TRIM__M5 EQU CYREG_FLSHID_CUST_TABLES_DEC_M5
ADC_DEC__TRIM__M6 EQU CYREG_FLSHID_CUST_TABLES_DEC_M6
ADC_DEC__TRIM__M7 EQU CYREG_FLSHID_CUST_TABLES_DEC_M7
ADC_DEC__TRIM__M8 EQU CYREG_FLSHID_CUST_TABLES_DEC_M8

/* ADC_DSM */
ADC_DSM__BUF0 EQU CYREG_DSM0_BUF0
ADC_DSM__BUF1 EQU CYREG_DSM0_BUF1
ADC_DSM__BUF2 EQU CYREG_DSM0_BUF2
ADC_DSM__BUF3 EQU CYREG_DSM0_BUF3
ADC_DSM__CLK EQU CYREG_DSM0_CLK
ADC_DSM__CR0 EQU CYREG_DSM0_CR0
ADC_DSM__CR1 EQU CYREG_DSM0_CR1
ADC_DSM__CR10 EQU CYREG_DSM0_CR10
ADC_DSM__CR11 EQU CYREG_DSM0_CR11
ADC_DSM__CR12 EQU CYREG_DSM0_CR12
ADC_DSM__CR13 EQU CYREG_DSM0_CR13
ADC_DSM__CR14 EQU CYREG_DSM0_CR14
ADC_DSM__CR15 EQU CYREG_DSM0_CR15
ADC_DSM__CR16 EQU CYREG_DSM0_CR16
ADC_DSM__CR17 EQU CYREG_DSM0_CR17
ADC_DSM__CR2 EQU CYREG_DSM0_CR2
ADC_DSM__CR3 EQU CYREG_DSM0_CR3
ADC_DSM__CR4 EQU CYREG_DSM0_CR4
ADC_DSM__CR5 EQU CYREG_DSM0_CR5
ADC_DSM__CR6 EQU CYREG_DSM0_CR6
ADC_DSM__CR7 EQU CYREG_DSM0_CR7
ADC_DSM__CR8 EQU CYREG_DSM0_CR8
ADC_DSM__CR9 EQU CYREG_DSM0_CR9
ADC_DSM__DEM0 EQU CYREG_DSM0_DEM0
ADC_DSM__DEM1 EQU CYREG_DSM0_DEM1
ADC_DSM__MISC EQU CYREG_DSM0_MISC
ADC_DSM__OUT0 EQU CYREG_DSM0_OUT0
ADC_DSM__OUT1 EQU CYREG_DSM0_OUT1
ADC_DSM__REF0 EQU CYREG_DSM0_REF0
ADC_DSM__REF1 EQU CYREG_DSM0_REF1
ADC_DSM__REF2 EQU CYREG_DSM0_REF2
ADC_DSM__REF3 EQU CYREG_DSM0_REF3
ADC_DSM__RSVD1 EQU CYREG_DSM0_RSVD1
ADC_DSM__SW0 EQU CYREG_DSM0_SW0
ADC_DSM__SW2 EQU CYREG_DSM0_SW2
ADC_DSM__SW3 EQU CYREG_DSM0_SW3
ADC_DSM__SW4 EQU CYREG_DSM0_SW4
ADC_DSM__SW6 EQU CYREG_DSM0_SW6
ADC_DSM__TR0 EQU CYREG_NPUMP_DSM_TR0
ADC_DSM__TST0 EQU CYREG_DSM0_TST0
ADC_DSM__TST1 EQU CYREG_DSM0_TST1

/* ADC_Ext_CP_Clk */
ADC_Ext_CP_Clk__CFG0 EQU CYREG_CLKDIST_DCFG0_CFG0
ADC_Ext_CP_Clk__CFG1 EQU CYREG_CLKDIST_DCFG0_CFG1
ADC_Ext_CP_Clk__CFG2 EQU CYREG_CLKDIST_DCFG0_CFG2
ADC_Ext_CP_Clk__CFG2_SRC_SEL_MASK EQU 0x07
ADC_Ext_CP_Clk__INDEX EQU 0x00
ADC_Ext_CP_Clk__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
ADC_Ext_CP_Clk__PM_ACT_MSK EQU 0x01
ADC_Ext_CP_Clk__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
ADC_Ext_CP_Clk__PM_STBY_MSK EQU 0x01

/* ADC_IRQ */
ADC_IRQ__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
ADC_IRQ__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
ADC_IRQ__INTC_MASK EQU 0x20000000
ADC_IRQ__INTC_NUMBER EQU 29
ADC_IRQ__INTC_PRIOR_NUM EQU 7
ADC_IRQ__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_29
ADC_IRQ__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
ADC_IRQ__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

/* ADC_theACLK */
ADC_theACLK__CFG0 EQU CYREG_CLKDIST_ACFG0_CFG0
ADC_theACLK__CFG1 EQU CYREG_CLKDIST_ACFG0_CFG1
ADC_theACLK__CFG2 EQU CYREG_CLKDIST_ACFG0_CFG2
ADC_theACLK__CFG2_SRC_SEL_MASK EQU 0x07
ADC_theACLK__CFG3 EQU CYREG_CLKDIST_ACFG0_CFG3
ADC_theACLK__CFG3_PHASE_DLY_MASK EQU 0x0F
ADC_theACLK__INDEX EQU 0x00
ADC_theACLK__PM_ACT_CFG EQU CYREG_PM_ACT_CFG1
ADC_theACLK__PM_ACT_MSK EQU 0x01
ADC_theACLK__PM_STBY_CFG EQU CYREG_PM_STBY_CFG1
ADC_theACLK__PM_STBY_MSK EQU 0x01

/* LCD_LCDPort */
LCD_LCDPort__0__MASK EQU 0x01
LCD_LCDPort__0__PC EQU CYREG_PRT2_PC0
LCD_LCDPort__0__PORT EQU 2
LCD_LCDPort__0__SHIFT EQU 0
LCD_LCDPort__1__MASK EQU 0x02
LCD_LCDPort__1__PC EQU CYREG_PRT2_PC1
LCD_LCDPort__1__PORT EQU 2
LCD_LCDPort__1__SHIFT EQU 1
LCD_LCDPort__2__MASK EQU 0x04
LCD_LCDPort__2__PC EQU CYREG_PRT2_PC2
LCD_LCDPort__2__PORT EQU 2
LCD_LCDPort__2__SHIFT EQU 2
LCD_LCDPort__3__MASK EQU 0x08
LCD_LCDPort__3__PC EQU CYREG_PRT2_PC3
LCD_LCDPort__3__PORT EQU 2
LCD_LCDPort__3__SHIFT EQU 3
LCD_LCDPort__4__MASK EQU 0x10
LCD_LCDPort__4__PC EQU CYREG_PRT2_PC4
LCD_LCDPort__4__PORT EQU 2
LCD_LCDPort__4__SHIFT EQU 4
LCD_LCDPort__5__MASK EQU 0x20
LCD_LCDPort__5__PC EQU CYREG_PRT2_PC5
LCD_LCDPort__5__PORT EQU 2
LCD_LCDPort__5__SHIFT EQU 5
LCD_LCDPort__6__MASK EQU 0x40
LCD_LCDPort__6__PC EQU CYREG_PRT2_PC6
LCD_LCDPort__6__PORT EQU 2
LCD_LCDPort__6__SHIFT EQU 6
LCD_LCDPort__AG EQU CYREG_PRT2_AG
LCD_LCDPort__AMUX EQU CYREG_PRT2_AMUX
LCD_LCDPort__BIE EQU CYREG_PRT2_BIE
LCD_LCDPort__BIT_MASK EQU CYREG_PRT2_BIT_MASK
LCD_LCDPort__BYP EQU CYREG_PRT2_BYP
LCD_LCDPort__CTL EQU CYREG_PRT2_CTL
LCD_LCDPort__DM0 EQU CYREG_PRT2_DM0
LCD_LCDPort__DM1 EQU CYREG_PRT2_DM1
LCD_LCDPort__DM2 EQU CYREG_PRT2_DM2
LCD_LCDPort__DR EQU CYREG_PRT2_DR
LCD_LCDPort__INP_DIS EQU CYREG_PRT2_INP_DIS
LCD_LCDPort__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
LCD_LCDPort__LCD_EN EQU CYREG_PRT2_LCD_EN
LCD_LCDPort__MASK EQU 0x7F
LCD_LCDPort__PORT EQU 2
LCD_LCDPort__PRT EQU CYREG_PRT2_PRT
LCD_LCDPort__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
LCD_LCDPort__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
LCD_LCDPort__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
LCD_LCDPort__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
LCD_LCDPort__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
LCD_LCDPort__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
LCD_LCDPort__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
LCD_LCDPort__PS EQU CYREG_PRT2_PS
LCD_LCDPort__SHIFT EQU 0
LCD_LCDPort__SLW EQU CYREG_PRT2_SLW

/* LED */
LED__0__MASK EQU 0x20
LED__0__PC EQU CYREG_PRT0_PC5
LED__0__PORT EQU 0
LED__0__SHIFT EQU 5
LED__AG EQU CYREG_PRT0_AG
LED__AMUX EQU CYREG_PRT0_AMUX
LED__BIE EQU CYREG_PRT0_BIE
LED__BIT_MASK EQU CYREG_PRT0_BIT_MASK
LED__BYP EQU CYREG_PRT0_BYP
LED__CTL EQU CYREG_PRT0_CTL
LED__DM0 EQU CYREG_PRT0_DM0
LED__DM1 EQU CYREG_PRT0_DM1
LED__DM2 EQU CYREG_PRT0_DM2
LED__DR EQU CYREG_PRT0_DR
LED__INP_DIS EQU CYREG_PRT0_INP_DIS
LED__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
LED__LCD_EN EQU CYREG_PRT0_LCD_EN
LED__MASK EQU 0x20
LED__PORT EQU 0
LED__PRT EQU CYREG_PRT0_PRT
LED__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
LED__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
LED__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
LED__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
LED__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
LED__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
LED__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
LED__PS EQU CYREG_PRT0_PS
LED__SHIFT EQU 5
LED__SLW EQU CYREG_PRT0_SLW

/* USBUART_1_arb_int */
USBUART_1_arb_int__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
USBUART_1_arb_int__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
USBUART_1_arb_int__INTC_MASK EQU 0x400000
USBUART_1_arb_int__INTC_NUMBER EQU 22
USBUART_1_arb_int__INTC_PRIOR_NUM EQU 7
USBUART_1_arb_int__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_22
USBUART_1_arb_int__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
USBUART_1_arb_int__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

/* USBUART_1_bus_reset */
USBUART_1_bus_reset__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
USBUART_1_bus_reset__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
USBUART_1_bus_reset__INTC_MASK EQU 0x800000
USBUART_1_bus_reset__INTC_NUMBER EQU 23
USBUART_1_bus_reset__INTC_PRIOR_NUM EQU 7
USBUART_1_bus_reset__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_23
USBUART_1_bus_reset__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
USBUART_1_bus_reset__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

/* USBUART_1_Dm */
USBUART_1_Dm__0__MASK EQU 0x80
USBUART_1_Dm__0__PC EQU CYREG_IO_PC_PRT15_7_6_PC1
USBUART_1_Dm__0__PORT EQU 15
USBUART_1_Dm__0__SHIFT EQU 7
USBUART_1_Dm__AG EQU CYREG_PRT15_AG
USBUART_1_Dm__AMUX EQU CYREG_PRT15_AMUX
USBUART_1_Dm__BIE EQU CYREG_PRT15_BIE
USBUART_1_Dm__BIT_MASK EQU CYREG_PRT15_BIT_MASK
USBUART_1_Dm__BYP EQU CYREG_PRT15_BYP
USBUART_1_Dm__CTL EQU CYREG_PRT15_CTL
USBUART_1_Dm__DM0 EQU CYREG_PRT15_DM0
USBUART_1_Dm__DM1 EQU CYREG_PRT15_DM1
USBUART_1_Dm__DM2 EQU CYREG_PRT15_DM2
USBUART_1_Dm__DR EQU CYREG_PRT15_DR
USBUART_1_Dm__INP_DIS EQU CYREG_PRT15_INP_DIS
USBUART_1_Dm__LCD_COM_SEG EQU CYREG_PRT15_LCD_COM_SEG
USBUART_1_Dm__LCD_EN EQU CYREG_PRT15_LCD_EN
USBUART_1_Dm__MASK EQU 0x80
USBUART_1_Dm__PORT EQU 15
USBUART_1_Dm__PRT EQU CYREG_PRT15_PRT
USBUART_1_Dm__PRTDSI__CAPS_SEL EQU CYREG_PRT15_CAPS_SEL
USBUART_1_Dm__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT15_DBL_SYNC_IN
USBUART_1_Dm__PRTDSI__OE_SEL0 EQU CYREG_PRT15_OE_SEL0
USBUART_1_Dm__PRTDSI__OE_SEL1 EQU CYREG_PRT15_OE_SEL1
USBUART_1_Dm__PRTDSI__OUT_SEL0 EQU CYREG_PRT15_OUT_SEL0
USBUART_1_Dm__PRTDSI__OUT_SEL1 EQU CYREG_PRT15_OUT_SEL1
USBUART_1_Dm__PRTDSI__SYNC_OUT EQU CYREG_PRT15_SYNC_OUT
USBUART_1_Dm__PS EQU CYREG_PRT15_PS
USBUART_1_Dm__SHIFT EQU 7
USBUART_1_Dm__SLW EQU CYREG_PRT15_SLW

/* USBUART_1_Dp */
USBUART_1_Dp__0__MASK EQU 0x40
USBUART_1_Dp__0__PC EQU CYREG_IO_PC_PRT15_7_6_PC0
USBUART_1_Dp__0__PORT EQU 15
USBUART_1_Dp__0__SHIFT EQU 6
USBUART_1_Dp__AG EQU CYREG_PRT15_AG
USBUART_1_Dp__AMUX EQU CYREG_PRT15_AMUX
USBUART_1_Dp__BIE EQU CYREG_PRT15_BIE
USBUART_1_Dp__BIT_MASK EQU CYREG_PRT15_BIT_MASK
USBUART_1_Dp__BYP EQU CYREG_PRT15_BYP
USBUART_1_Dp__CTL EQU CYREG_PRT15_CTL
USBUART_1_Dp__DM0 EQU CYREG_PRT15_DM0
USBUART_1_Dp__DM1 EQU CYREG_PRT15_DM1
USBUART_1_Dp__DM2 EQU CYREG_PRT15_DM2
USBUART_1_Dp__DR EQU CYREG_PRT15_DR
USBUART_1_Dp__INP_DIS EQU CYREG_PRT15_INP_DIS
USBUART_1_Dp__INTSTAT EQU CYREG_PICU15_INTSTAT
USBUART_1_Dp__LCD_COM_SEG EQU CYREG_PRT15_LCD_COM_SEG
USBUART_1_Dp__LCD_EN EQU CYREG_PRT15_LCD_EN
USBUART_1_Dp__MASK EQU 0x40
USBUART_1_Dp__PORT EQU 15
USBUART_1_Dp__PRT EQU CYREG_PRT15_PRT
USBUART_1_Dp__PRTDSI__CAPS_SEL EQU CYREG_PRT15_CAPS_SEL
USBUART_1_Dp__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT15_DBL_SYNC_IN
USBUART_1_Dp__PRTDSI__OE_SEL0 EQU CYREG_PRT15_OE_SEL0
USBUART_1_Dp__PRTDSI__OE_SEL1 EQU CYREG_PRT15_OE_SEL1
USBUART_1_Dp__PRTDSI__OUT_SEL0 EQU CYREG_PRT15_OUT_SEL0
USBUART_1_Dp__PRTDSI__OUT_SEL1 EQU CYREG_PRT15_OUT_SEL1
USBUART_1_Dp__PRTDSI__SYNC_OUT EQU CYREG_PRT15_SYNC_OUT
USBUART_1_Dp__PS EQU CYREG_PRT15_PS
USBUART_1_Dp__SHIFT EQU 6
USBUART_1_Dp__SLW EQU CYREG_PRT15_SLW
USBUART_1_Dp__SNAP EQU CYREG_PICU_15_SNAP_15

/* USBUART_1_dp_int */
USBUART_1_dp_int__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
USBUART_1_dp_int__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
USBUART_1_dp_int__INTC_MASK EQU 0x1000
USBUART_1_dp_int__INTC_NUMBER EQU 12
USBUART_1_dp_int__INTC_PRIOR_NUM EQU 7
USBUART_1_dp_int__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_12
USBUART_1_dp_int__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
USBUART_1_dp_int__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

/* USBUART_1_ep_0 */
USBUART_1_ep_0__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
USBUART_1_ep_0__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
USBUART_1_ep_0__INTC_MASK EQU 0x1000000
USBUART_1_ep_0__INTC_NUMBER EQU 24
USBUART_1_ep_0__INTC_PRIOR_NUM EQU 7
USBUART_1_ep_0__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_24
USBUART_1_ep_0__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
USBUART_1_ep_0__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

/* USBUART_1_ep_1 */
USBUART_1_ep_1__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
USBUART_1_ep_1__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
USBUART_1_ep_1__INTC_MASK EQU 0x01
USBUART_1_ep_1__INTC_NUMBER EQU 0
USBUART_1_ep_1__INTC_PRIOR_NUM EQU 7
USBUART_1_ep_1__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_0
USBUART_1_ep_1__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
USBUART_1_ep_1__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

/* USBUART_1_ep_2 */
USBUART_1_ep_2__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
USBUART_1_ep_2__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
USBUART_1_ep_2__INTC_MASK EQU 0x02
USBUART_1_ep_2__INTC_NUMBER EQU 1
USBUART_1_ep_2__INTC_PRIOR_NUM EQU 7
USBUART_1_ep_2__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_1
USBUART_1_ep_2__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
USBUART_1_ep_2__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

/* USBUART_1_ep_3 */
USBUART_1_ep_3__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
USBUART_1_ep_3__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
USBUART_1_ep_3__INTC_MASK EQU 0x04
USBUART_1_ep_3__INTC_NUMBER EQU 2
USBUART_1_ep_3__INTC_PRIOR_NUM EQU 7
USBUART_1_ep_3__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_2
USBUART_1_ep_3__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
USBUART_1_ep_3__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

/* USBUART_1_sof_int */
USBUART_1_sof_int__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
USBUART_1_sof_int__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
USBUART_1_sof_int__INTC_MASK EQU 0x200000
USBUART_1_sof_int__INTC_NUMBER EQU 21
USBUART_1_sof_int__INTC_PRIOR_NUM EQU 7
USBUART_1_sof_int__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_21
USBUART_1_sof_int__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
USBUART_1_sof_int__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

/* USBUART_1_USB */
USBUART_1_USB__ARB_CFG EQU CYREG_USB_ARB_CFG
USBUART_1_USB__ARB_EP1_CFG EQU CYREG_USB_ARB_EP1_CFG
USBUART_1_USB__ARB_EP1_INT_EN EQU CYREG_USB_ARB_EP1_INT_EN
USBUART_1_USB__ARB_EP1_SR EQU CYREG_USB_ARB_EP1_SR
USBUART_1_USB__ARB_EP2_CFG EQU CYREG_USB_ARB_EP2_CFG
USBUART_1_USB__ARB_EP2_INT_EN EQU CYREG_USB_ARB_EP2_INT_EN
USBUART_1_USB__ARB_EP2_SR EQU CYREG_USB_ARB_EP2_SR
USBUART_1_USB__ARB_EP3_CFG EQU CYREG_USB_ARB_EP3_CFG
USBUART_1_USB__ARB_EP3_INT_EN EQU CYREG_USB_ARB_EP3_INT_EN
USBUART_1_USB__ARB_EP3_SR EQU CYREG_USB_ARB_EP3_SR
USBUART_1_USB__ARB_EP4_CFG EQU CYREG_USB_ARB_EP4_CFG
USBUART_1_USB__ARB_EP4_INT_EN EQU CYREG_USB_ARB_EP4_INT_EN
USBUART_1_USB__ARB_EP4_SR EQU CYREG_USB_ARB_EP4_SR
USBUART_1_USB__ARB_EP5_CFG EQU CYREG_USB_ARB_EP5_CFG
USBUART_1_USB__ARB_EP5_INT_EN EQU CYREG_USB_ARB_EP5_INT_EN
USBUART_1_USB__ARB_EP5_SR EQU CYREG_USB_ARB_EP5_SR
USBUART_1_USB__ARB_EP6_CFG EQU CYREG_USB_ARB_EP6_CFG
USBUART_1_USB__ARB_EP6_INT_EN EQU CYREG_USB_ARB_EP6_INT_EN
USBUART_1_USB__ARB_EP6_SR EQU CYREG_USB_ARB_EP6_SR
USBUART_1_USB__ARB_EP7_CFG EQU CYREG_USB_ARB_EP7_CFG
USBUART_1_USB__ARB_EP7_INT_EN EQU CYREG_USB_ARB_EP7_INT_EN
USBUART_1_USB__ARB_EP7_SR EQU CYREG_USB_ARB_EP7_SR
USBUART_1_USB__ARB_EP8_CFG EQU CYREG_USB_ARB_EP8_CFG
USBUART_1_USB__ARB_EP8_INT_EN EQU CYREG_USB_ARB_EP8_INT_EN
USBUART_1_USB__ARB_EP8_SR EQU CYREG_USB_ARB_EP8_SR
USBUART_1_USB__ARB_INT_EN EQU CYREG_USB_ARB_INT_EN
USBUART_1_USB__ARB_INT_SR EQU CYREG_USB_ARB_INT_SR
USBUART_1_USB__ARB_RW1_DR EQU CYREG_USB_ARB_RW1_DR
USBUART_1_USB__ARB_RW1_RA EQU CYREG_USB_ARB_RW1_RA
USBUART_1_USB__ARB_RW1_RA_MSB EQU CYREG_USB_ARB_RW1_RA_MSB
USBUART_1_USB__ARB_RW1_WA EQU CYREG_USB_ARB_RW1_WA
USBUART_1_USB__ARB_RW1_WA_MSB EQU CYREG_USB_ARB_RW1_WA_MSB
USBUART_1_USB__ARB_RW2_DR EQU CYREG_USB_ARB_RW2_DR
USBUART_1_USB__ARB_RW2_RA EQU CYREG_USB_ARB_RW2_RA
USBUART_1_USB__ARB_RW2_RA_MSB EQU CYREG_USB_ARB_RW2_RA_MSB
USBUART_1_USB__ARB_RW2_WA EQU CYREG_USB_ARB_RW2_WA
USBUART_1_USB__ARB_RW2_WA_MSB EQU CYREG_USB_ARB_RW2_WA_MSB
USBUART_1_USB__ARB_RW3_DR EQU CYREG_USB_ARB_RW3_DR
USBUART_1_USB__ARB_RW3_RA EQU CYREG_USB_ARB_RW3_RA
USBUART_1_USB__ARB_RW3_RA_MSB EQU CYREG_USB_ARB_RW3_RA_MSB
USBUART_1_USB__ARB_RW3_WA EQU CYREG_USB_ARB_RW3_WA
USBUART_1_USB__ARB_RW3_WA_MSB EQU CYREG_USB_ARB_RW3_WA_MSB
USBUART_1_USB__ARB_RW4_DR EQU CYREG_USB_ARB_RW4_DR
USBUART_1_USB__ARB_RW4_RA EQU CYREG_USB_ARB_RW4_RA
USBUART_1_USB__ARB_RW4_RA_MSB EQU CYREG_USB_ARB_RW4_RA_MSB
USBUART_1_USB__ARB_RW4_WA EQU CYREG_USB_ARB_RW4_WA
USBUART_1_USB__ARB_RW4_WA_MSB EQU CYREG_USB_ARB_RW4_WA_MSB
USBUART_1_USB__ARB_RW5_DR EQU CYREG_USB_ARB_RW5_DR
USBUART_1_USB__ARB_RW5_RA EQU CYREG_USB_ARB_RW5_RA
USBUART_1_USB__ARB_RW5_RA_MSB EQU CYREG_USB_ARB_RW5_RA_MSB
USBUART_1_USB__ARB_RW5_WA EQU CYREG_USB_ARB_RW5_WA
USBUART_1_USB__ARB_RW5_WA_MSB EQU CYREG_USB_ARB_RW5_WA_MSB
USBUART_1_USB__ARB_RW6_DR EQU CYREG_USB_ARB_RW6_DR
USBUART_1_USB__ARB_RW6_RA EQU CYREG_USB_ARB_RW6_RA
USBUART_1_USB__ARB_RW6_RA_MSB EQU CYREG_USB_ARB_RW6_RA_MSB
USBUART_1_USB__ARB_RW6_WA EQU CYREG_USB_ARB_RW6_WA
USBUART_1_USB__ARB_RW6_WA_MSB EQU CYREG_USB_ARB_RW6_WA_MSB
USBUART_1_USB__ARB_RW7_DR EQU CYREG_USB_ARB_RW7_DR
USBUART_1_USB__ARB_RW7_RA EQU CYREG_USB_ARB_RW7_RA
USBUART_1_USB__ARB_RW7_RA_MSB EQU CYREG_USB_ARB_RW7_RA_MSB
USBUART_1_USB__ARB_RW7_WA EQU CYREG_USB_ARB_RW7_WA
USBUART_1_USB__ARB_RW7_WA_MSB EQU CYREG_USB_ARB_RW7_WA_MSB
USBUART_1_USB__ARB_RW8_DR EQU CYREG_USB_ARB_RW8_DR
USBUART_1_USB__ARB_RW8_RA EQU CYREG_USB_ARB_RW8_RA
USBUART_1_USB__ARB_RW8_RA_MSB EQU CYREG_USB_ARB_RW8_RA_MSB
USBUART_1_USB__ARB_RW8_WA EQU CYREG_USB_ARB_RW8_WA
USBUART_1_USB__ARB_RW8_WA_MSB EQU CYREG_USB_ARB_RW8_WA_MSB
USBUART_1_USB__BUF_SIZE EQU CYREG_USB_BUF_SIZE
USBUART_1_USB__BUS_RST_CNT EQU CYREG_USB_BUS_RST_CNT
USBUART_1_USB__CR0 EQU CYREG_USB_CR0
USBUART_1_USB__CR1 EQU CYREG_USB_CR1
USBUART_1_USB__CWA EQU CYREG_USB_CWA
USBUART_1_USB__CWA_MSB EQU CYREG_USB_CWA_MSB
USBUART_1_USB__DMA_THRES EQU CYREG_USB_DMA_THRES
USBUART_1_USB__DMA_THRES_MSB EQU CYREG_USB_DMA_THRES_MSB
USBUART_1_USB__DYN_RECONFIG EQU CYREG_USB_DYN_RECONFIG
USBUART_1_USB__EP_ACTIVE EQU CYREG_USB_EP_ACTIVE
USBUART_1_USB__EP_TYPE EQU CYREG_USB_EP_TYPE
USBUART_1_USB__EP0_CNT EQU CYREG_USB_EP0_CNT
USBUART_1_USB__EP0_CR EQU CYREG_USB_EP0_CR
USBUART_1_USB__EP0_DR0 EQU CYREG_USB_EP0_DR0
USBUART_1_USB__EP0_DR1 EQU CYREG_USB_EP0_DR1
USBUART_1_USB__EP0_DR2 EQU CYREG_USB_EP0_DR2
USBUART_1_USB__EP0_DR3 EQU CYREG_USB_EP0_DR3
USBUART_1_USB__EP0_DR4 EQU CYREG_USB_EP0_DR4
USBUART_1_USB__EP0_DR5 EQU CYREG_USB_EP0_DR5
USBUART_1_USB__EP0_DR6 EQU CYREG_USB_EP0_DR6
USBUART_1_USB__EP0_DR7 EQU CYREG_USB_EP0_DR7
USBUART_1_USB__MEM_DATA EQU CYREG_USB_MEM_DATA_MBASE
USBUART_1_USB__PM_ACT_CFG EQU CYREG_PM_ACT_CFG5
USBUART_1_USB__PM_ACT_MSK EQU 0x01
USBUART_1_USB__PM_STBY_CFG EQU CYREG_PM_STBY_CFG5
USBUART_1_USB__PM_STBY_MSK EQU 0x01
USBUART_1_USB__SIE_EP_INT_EN EQU CYREG_USB_SIE_EP_INT_EN
USBUART_1_USB__SIE_EP_INT_SR EQU CYREG_USB_SIE_EP_INT_SR
USBUART_1_USB__SIE_EP1_CNT0 EQU CYREG_USB_SIE_EP1_CNT0
USBUART_1_USB__SIE_EP1_CNT1 EQU CYREG_USB_SIE_EP1_CNT1
USBUART_1_USB__SIE_EP1_CR0 EQU CYREG_USB_SIE_EP1_CR0
USBUART_1_USB__SIE_EP2_CNT0 EQU CYREG_USB_SIE_EP2_CNT0
USBUART_1_USB__SIE_EP2_CNT1 EQU CYREG_USB_SIE_EP2_CNT1
USBUART_1_USB__SIE_EP2_CR0 EQU CYREG_USB_SIE_EP2_CR0
USBUART_1_USB__SIE_EP3_CNT0 EQU CYREG_USB_SIE_EP3_CNT0
USBUART_1_USB__SIE_EP3_CNT1 EQU CYREG_USB_SIE_EP3_CNT1
USBUART_1_USB__SIE_EP3_CR0 EQU CYREG_USB_SIE_EP3_CR0
USBUART_1_USB__SIE_EP4_CNT0 EQU CYREG_USB_SIE_EP4_CNT0
USBUART_1_USB__SIE_EP4_CNT1 EQU CYREG_USB_SIE_EP4_CNT1
USBUART_1_USB__SIE_EP4_CR0 EQU CYREG_USB_SIE_EP4_CR0
USBUART_1_USB__SIE_EP5_CNT0 EQU CYREG_USB_SIE_EP5_CNT0
USBUART_1_USB__SIE_EP5_CNT1 EQU CYREG_USB_SIE_EP5_CNT1
USBUART_1_USB__SIE_EP5_CR0 EQU CYREG_USB_SIE_EP5_CR0
USBUART_1_USB__SIE_EP6_CNT0 EQU CYREG_USB_SIE_EP6_CNT0
USBUART_1_USB__SIE_EP6_CNT1 EQU CYREG_USB_SIE_EP6_CNT1
USBUART_1_USB__SIE_EP6_CR0 EQU CYREG_USB_SIE_EP6_CR0
USBUART_1_USB__SIE_EP7_CNT0 EQU CYREG_USB_SIE_EP7_CNT0
USBUART_1_USB__SIE_EP7_CNT1 EQU CYREG_USB_SIE_EP7_CNT1
USBUART_1_USB__SIE_EP7_CR0 EQU CYREG_USB_SIE_EP7_CR0
USBUART_1_USB__SIE_EP8_CNT0 EQU CYREG_USB_SIE_EP8_CNT0
USBUART_1_USB__SIE_EP8_CNT1 EQU CYREG_USB_SIE_EP8_CNT1
USBUART_1_USB__SIE_EP8_CR0 EQU CYREG_USB_SIE_EP8_CR0
USBUART_1_USB__SOF0 EQU CYREG_USB_SOF0
USBUART_1_USB__SOF1 EQU CYREG_USB_SOF1
USBUART_1_USB__USB_CLK_EN EQU CYREG_USB_USB_CLK_EN
USBUART_1_USB__USBIO_CR0 EQU CYREG_USB_USBIO_CR0
USBUART_1_USB__USBIO_CR1 EQU CYREG_USB_USBIO_CR1

/* VoltInput */
VoltInput__0__MASK EQU 0x20
VoltInput__0__PC EQU CYREG_PRT6_PC5
VoltInput__0__PORT EQU 6
VoltInput__0__SHIFT EQU 5
VoltInput__AG EQU CYREG_PRT6_AG
VoltInput__AMUX EQU CYREG_PRT6_AMUX
VoltInput__BIE EQU CYREG_PRT6_BIE
VoltInput__BIT_MASK EQU CYREG_PRT6_BIT_MASK
VoltInput__BYP EQU CYREG_PRT6_BYP
VoltInput__CTL EQU CYREG_PRT6_CTL
VoltInput__DM0 EQU CYREG_PRT6_DM0
VoltInput__DM1 EQU CYREG_PRT6_DM1
VoltInput__DM2 EQU CYREG_PRT6_DM2
VoltInput__DR EQU CYREG_PRT6_DR
VoltInput__INP_DIS EQU CYREG_PRT6_INP_DIS
VoltInput__LCD_COM_SEG EQU CYREG_PRT6_LCD_COM_SEG
VoltInput__LCD_EN EQU CYREG_PRT6_LCD_EN
VoltInput__MASK EQU 0x20
VoltInput__PORT EQU 6
VoltInput__PRT EQU CYREG_PRT6_PRT
VoltInput__PRTDSI__CAPS_SEL EQU CYREG_PRT6_CAPS_SEL
VoltInput__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT6_DBL_SYNC_IN
VoltInput__PRTDSI__OE_SEL0 EQU CYREG_PRT6_OE_SEL0
VoltInput__PRTDSI__OE_SEL1 EQU CYREG_PRT6_OE_SEL1
VoltInput__PRTDSI__OUT_SEL0 EQU CYREG_PRT6_OUT_SEL0
VoltInput__PRTDSI__OUT_SEL1 EQU CYREG_PRT6_OUT_SEL1
VoltInput__PRTDSI__SYNC_OUT EQU CYREG_PRT6_SYNC_OUT
VoltInput__PS EQU CYREG_PRT6_PS
VoltInput__SHIFT EQU 5
VoltInput__SLW EQU CYREG_PRT6_SLW

/* Miscellaneous */
BCLK__BUS_CLK__HZ EQU 64000000
BCLK__BUS_CLK__KHZ EQU 64000
BCLK__BUS_CLK__MHZ EQU 64
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PANTHER EQU 4
CYDEV_CHIP_DIE_PSOC4A EQU 2
CYDEV_CHIP_DIE_PSOC5LP EQU 5
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC5
CYDEV_CHIP_JTAG_ID EQU 0x2E123069
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 2
CYDEV_CHIP_MEMBER_4D EQU 3
CYDEV_CHIP_MEMBER_5A EQU 4
CYDEV_CHIP_MEMBER_5B EQU 5
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_5B
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PANTHER_ES0 EQU 0
CYDEV_CHIP_REV_PANTHER_ES1 EQU 1
CYDEV_CHIP_REV_PANTHER_PRODUCTION EQU 1
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4D_ES0 EQU 0
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_5B_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_FASTBOOT_ENABLED EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_DMA EQU 0
CYDEV_CONFIGURATION_ECC EQU 1
CYDEV_CONFIGURATION_IMOENABLED EQU CYDEV_CONFIG_FASTBOOT_ENABLED
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_ENABLE_MASK EQU 0x20
CYDEV_DEBUG_ENABLE_REGISTER EQU CYREG_MLOGIC_DEBUG
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_JTAG_4 EQU 1
CYDEV_DEBUGGING_DPS_JTAG_5 EQU 0
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS_SWD_SWV EQU 6
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD_SWV
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DEBUGGING_XRES EQU 1
CYDEV_DMA_CHANNELS_AVAILABLE EQU 24
CYDEV_ECC_ENABLE EQU 0
CYDEV_HEAP_SIZE EQU 4096
CYDEV_INSTRUCT_CACHE_ENABLED EQU 1
CYDEV_INTR_RISING EQU 0x00000000
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_PROTECTION_ENABLE EQU 0
CYDEV_STACK_SIZE EQU 16384
CYDEV_USB_CLK_OSC_LOCKING_ENABLED_AT_PWR_UP EQU 1
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 0
CYDEV_VDDA_MV EQU 5000
CYDEV_VDDD_MV EQU 5000
CYDEV_VDDIO0_MV EQU 5000
CYDEV_VDDIO1_MV EQU 5000
CYDEV_VDDIO2_MV EQU 5000
CYDEV_VDDIO3_MV EQU 5000
CYDEV_VIO0 EQU 5
CYDEV_VIO0_MV EQU 5000
CYDEV_VIO1 EQU 5
CYDEV_VIO1_MV EQU 5000
CYDEV_VIO2 EQU 5
CYDEV_VIO2_MV EQU 5000
CYDEV_VIO3 EQU 5
CYDEV_VIO3_MV EQU 5000
CYIPBLOCK_ARM_CM3_VERSION EQU 0
CYIPBLOCK_P3_ANAIF_VERSION EQU 0
CYIPBLOCK_P3_CAN_VERSION EQU 0
CYIPBLOCK_P3_CAPSENSE_VERSION EQU 0
CYIPBLOCK_P3_COMP_VERSION EQU 0
CYIPBLOCK_P3_DECIMATOR_VERSION EQU 0
CYIPBLOCK_P3_DFB_VERSION EQU 0
CYIPBLOCK_P3_DMA_VERSION EQU 0
CYIPBLOCK_P3_DRQ_VERSION EQU 0
CYIPBLOCK_P3_DSM_VERSION EQU 0
CYIPBLOCK_P3_EMIF_VERSION EQU 0
CYIPBLOCK_P3_I2C_VERSION EQU 0
CYIPBLOCK_P3_LCD_VERSION EQU 0
CYIPBLOCK_P3_LPF_VERSION EQU 0
CYIPBLOCK_P3_OPAMP_VERSION EQU 0
CYIPBLOCK_P3_PM_VERSION EQU 0
CYIPBLOCK_P3_SCCT_VERSION EQU 0
CYIPBLOCK_P3_TIMER_VERSION EQU 0
CYIPBLOCK_P3_USB_VERSION EQU 0
CYIPBLOCK_P3_VIDAC_VERSION EQU 0
CYIPBLOCK_P3_VREF_VERSION EQU 0
CYIPBLOCK_S8_GPIO_VERSION EQU 0
CYIPBLOCK_S8_IRQ_VERSION EQU 0
CYIPBLOCK_S8_SAR_VERSION EQU 0
CYIPBLOCK_S8_SIO_VERSION EQU 0
CYIPBLOCK_S8_UDB_VERSION EQU 0
DMA_CHANNELS_USED__MASK0 EQU 0x00000000
CYDEV_BOOTLOADER_ENABLE EQU 0

#endif /* INCLUDED_CYFITTERIAR_INC */
