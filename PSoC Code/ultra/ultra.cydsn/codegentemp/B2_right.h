/*******************************************************************************
* File Name: B2_right.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_B2_right_H) /* Pins B2_right_H */
#define CY_PINS_B2_right_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "B2_right_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 B2_right__PORT == 15 && ((B2_right__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    B2_right_Write(uint8 value);
void    B2_right_SetDriveMode(uint8 mode);
uint8   B2_right_ReadDataReg(void);
uint8   B2_right_Read(void);
void    B2_right_SetInterruptMode(uint16 position, uint16 mode);
uint8   B2_right_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the B2_right_SetDriveMode() function.
     *  @{
     */
        #define B2_right_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define B2_right_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define B2_right_DM_RES_UP          PIN_DM_RES_UP
        #define B2_right_DM_RES_DWN         PIN_DM_RES_DWN
        #define B2_right_DM_OD_LO           PIN_DM_OD_LO
        #define B2_right_DM_OD_HI           PIN_DM_OD_HI
        #define B2_right_DM_STRONG          PIN_DM_STRONG
        #define B2_right_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define B2_right_MASK               B2_right__MASK
#define B2_right_SHIFT              B2_right__SHIFT
#define B2_right_WIDTH              1u

/* Interrupt constants */
#if defined(B2_right__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in B2_right_SetInterruptMode() function.
     *  @{
     */
        #define B2_right_INTR_NONE      (uint16)(0x0000u)
        #define B2_right_INTR_RISING    (uint16)(0x0001u)
        #define B2_right_INTR_FALLING   (uint16)(0x0002u)
        #define B2_right_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define B2_right_INTR_MASK      (0x01u) 
#endif /* (B2_right__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define B2_right_PS                     (* (reg8 *) B2_right__PS)
/* Data Register */
#define B2_right_DR                     (* (reg8 *) B2_right__DR)
/* Port Number */
#define B2_right_PRT_NUM                (* (reg8 *) B2_right__PRT) 
/* Connect to Analog Globals */                                                  
#define B2_right_AG                     (* (reg8 *) B2_right__AG)                       
/* Analog MUX bux enable */
#define B2_right_AMUX                   (* (reg8 *) B2_right__AMUX) 
/* Bidirectional Enable */                                                        
#define B2_right_BIE                    (* (reg8 *) B2_right__BIE)
/* Bit-mask for Aliased Register Access */
#define B2_right_BIT_MASK               (* (reg8 *) B2_right__BIT_MASK)
/* Bypass Enable */
#define B2_right_BYP                    (* (reg8 *) B2_right__BYP)
/* Port wide control signals */                                                   
#define B2_right_CTL                    (* (reg8 *) B2_right__CTL)
/* Drive Modes */
#define B2_right_DM0                    (* (reg8 *) B2_right__DM0) 
#define B2_right_DM1                    (* (reg8 *) B2_right__DM1)
#define B2_right_DM2                    (* (reg8 *) B2_right__DM2) 
/* Input Buffer Disable Override */
#define B2_right_INP_DIS                (* (reg8 *) B2_right__INP_DIS)
/* LCD Common or Segment Drive */
#define B2_right_LCD_COM_SEG            (* (reg8 *) B2_right__LCD_COM_SEG)
/* Enable Segment LCD */
#define B2_right_LCD_EN                 (* (reg8 *) B2_right__LCD_EN)
/* Slew Rate Control */
#define B2_right_SLW                    (* (reg8 *) B2_right__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define B2_right_PRTDSI__CAPS_SEL       (* (reg8 *) B2_right__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define B2_right_PRTDSI__DBL_SYNC_IN    (* (reg8 *) B2_right__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define B2_right_PRTDSI__OE_SEL0        (* (reg8 *) B2_right__PRTDSI__OE_SEL0) 
#define B2_right_PRTDSI__OE_SEL1        (* (reg8 *) B2_right__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define B2_right_PRTDSI__OUT_SEL0       (* (reg8 *) B2_right__PRTDSI__OUT_SEL0) 
#define B2_right_PRTDSI__OUT_SEL1       (* (reg8 *) B2_right__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define B2_right_PRTDSI__SYNC_OUT       (* (reg8 *) B2_right__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(B2_right__SIO_CFG)
    #define B2_right_SIO_HYST_EN        (* (reg8 *) B2_right__SIO_HYST_EN)
    #define B2_right_SIO_REG_HIFREQ     (* (reg8 *) B2_right__SIO_REG_HIFREQ)
    #define B2_right_SIO_CFG            (* (reg8 *) B2_right__SIO_CFG)
    #define B2_right_SIO_DIFF           (* (reg8 *) B2_right__SIO_DIFF)
#endif /* (B2_right__SIO_CFG) */

/* Interrupt Registers */
#if defined(B2_right__INTSTAT)
    #define B2_right_INTSTAT            (* (reg8 *) B2_right__INTSTAT)
    #define B2_right_SNAP               (* (reg8 *) B2_right__SNAP)
    
	#define B2_right_0_INTTYPE_REG 		(* (reg8 *) B2_right__0__INTTYPE)
#endif /* (B2_right__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_B2_right_H */


/* [] END OF FILE */
