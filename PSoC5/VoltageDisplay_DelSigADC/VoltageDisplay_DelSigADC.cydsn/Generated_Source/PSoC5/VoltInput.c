/*******************************************************************************
* File Name: VoltInput.c  
* Version 2.5
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "VoltInput.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 VoltInput__PORT == 15 && ((VoltInput__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: VoltInput_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void VoltInput_Write(uint8 value) 
{
    uint8 staticBits = (VoltInput_DR & (uint8)(~VoltInput_MASK));
    VoltInput_DR = staticBits | ((uint8)(value << VoltInput_SHIFT) & VoltInput_MASK);
}


/*******************************************************************************
* Function Name: VoltInput_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  VoltInput_DM_STRONG     Strong Drive 
*  VoltInput_DM_OD_HI      Open Drain, Drives High 
*  VoltInput_DM_OD_LO      Open Drain, Drives Low 
*  VoltInput_DM_RES_UP     Resistive Pull Up 
*  VoltInput_DM_RES_DWN    Resistive Pull Down 
*  VoltInput_DM_RES_UPDWN  Resistive Pull Up/Down 
*  VoltInput_DM_DIG_HIZ    High Impedance Digital 
*  VoltInput_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void VoltInput_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(VoltInput_0, mode);
}


/*******************************************************************************
* Function Name: VoltInput_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro VoltInput_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 VoltInput_Read(void) 
{
    return (VoltInput_PS & VoltInput_MASK) >> VoltInput_SHIFT;
}


/*******************************************************************************
* Function Name: VoltInput_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 VoltInput_ReadDataReg(void) 
{
    return (VoltInput_DR & VoltInput_MASK) >> VoltInput_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(VoltInput_INTSTAT) 

    /*******************************************************************************
    * Function Name: VoltInput_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 VoltInput_ClearInterrupt(void) 
    {
        return (VoltInput_INTSTAT & VoltInput_MASK) >> VoltInput_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
