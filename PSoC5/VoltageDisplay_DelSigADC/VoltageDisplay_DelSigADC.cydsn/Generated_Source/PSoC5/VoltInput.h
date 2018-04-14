/*******************************************************************************
* File Name: VoltInput.h  
* Version 2.5
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_VoltInput_H) /* Pins VoltInput_H */
#define CY_PINS_VoltInput_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "VoltInput_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 VoltInput__PORT == 15 && ((VoltInput__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    VoltInput_Write(uint8 value) ;
void    VoltInput_SetDriveMode(uint8 mode) ;
uint8   VoltInput_ReadDataReg(void) ;
uint8   VoltInput_Read(void) ;
uint8   VoltInput_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define VoltInput_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define VoltInput_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define VoltInput_DM_RES_UP          PIN_DM_RES_UP
#define VoltInput_DM_RES_DWN         PIN_DM_RES_DWN
#define VoltInput_DM_OD_LO           PIN_DM_OD_LO
#define VoltInput_DM_OD_HI           PIN_DM_OD_HI
#define VoltInput_DM_STRONG          PIN_DM_STRONG
#define VoltInput_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define VoltInput_MASK               VoltInput__MASK
#define VoltInput_SHIFT              VoltInput__SHIFT
#define VoltInput_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define VoltInput_PS                     (* (reg8 *) VoltInput__PS)
/* Data Register */
#define VoltInput_DR                     (* (reg8 *) VoltInput__DR)
/* Port Number */
#define VoltInput_PRT_NUM                (* (reg8 *) VoltInput__PRT) 
/* Connect to Analog Globals */                                                  
#define VoltInput_AG                     (* (reg8 *) VoltInput__AG)                       
/* Analog MUX bux enable */
#define VoltInput_AMUX                   (* (reg8 *) VoltInput__AMUX) 
/* Bidirectional Enable */                                                        
#define VoltInput_BIE                    (* (reg8 *) VoltInput__BIE)
/* Bit-mask for Aliased Register Access */
#define VoltInput_BIT_MASK               (* (reg8 *) VoltInput__BIT_MASK)
/* Bypass Enable */
#define VoltInput_BYP                    (* (reg8 *) VoltInput__BYP)
/* Port wide control signals */                                                   
#define VoltInput_CTL                    (* (reg8 *) VoltInput__CTL)
/* Drive Modes */
#define VoltInput_DM0                    (* (reg8 *) VoltInput__DM0) 
#define VoltInput_DM1                    (* (reg8 *) VoltInput__DM1)
#define VoltInput_DM2                    (* (reg8 *) VoltInput__DM2) 
/* Input Buffer Disable Override */
#define VoltInput_INP_DIS                (* (reg8 *) VoltInput__INP_DIS)
/* LCD Common or Segment Drive */
#define VoltInput_LCD_COM_SEG            (* (reg8 *) VoltInput__LCD_COM_SEG)
/* Enable Segment LCD */
#define VoltInput_LCD_EN                 (* (reg8 *) VoltInput__LCD_EN)
/* Slew Rate Control */
#define VoltInput_SLW                    (* (reg8 *) VoltInput__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define VoltInput_PRTDSI__CAPS_SEL       (* (reg8 *) VoltInput__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define VoltInput_PRTDSI__DBL_SYNC_IN    (* (reg8 *) VoltInput__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define VoltInput_PRTDSI__OE_SEL0        (* (reg8 *) VoltInput__PRTDSI__OE_SEL0) 
#define VoltInput_PRTDSI__OE_SEL1        (* (reg8 *) VoltInput__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define VoltInput_PRTDSI__OUT_SEL0       (* (reg8 *) VoltInput__PRTDSI__OUT_SEL0) 
#define VoltInput_PRTDSI__OUT_SEL1       (* (reg8 *) VoltInput__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define VoltInput_PRTDSI__SYNC_OUT       (* (reg8 *) VoltInput__PRTDSI__SYNC_OUT) 


#if defined(VoltInput__INTSTAT)  /* Interrupt Registers */

    #define VoltInput_INTSTAT                (* (reg8 *) VoltInput__INTSTAT)
    #define VoltInput_SNAP                   (* (reg8 *) VoltInput__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_VoltInput_H */


/* [] END OF FILE */
