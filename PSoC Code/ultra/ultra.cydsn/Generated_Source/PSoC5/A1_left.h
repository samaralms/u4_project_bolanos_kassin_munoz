/*******************************************************************************
* File Name: A1_left.h  
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

#if !defined(CY_PINS_A1_left_H) /* Pins A1_left_H */
#define CY_PINS_A1_left_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "A1_left_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 A1_left__PORT == 15 && ((A1_left__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    A1_left_Write(uint8 value);
void    A1_left_SetDriveMode(uint8 mode);
uint8   A1_left_ReadDataReg(void);
uint8   A1_left_Read(void);
void    A1_left_SetInterruptMode(uint16 position, uint16 mode);
uint8   A1_left_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the A1_left_SetDriveMode() function.
     *  @{
     */
        #define A1_left_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define A1_left_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define A1_left_DM_RES_UP          PIN_DM_RES_UP
        #define A1_left_DM_RES_DWN         PIN_DM_RES_DWN
        #define A1_left_DM_OD_LO           PIN_DM_OD_LO
        #define A1_left_DM_OD_HI           PIN_DM_OD_HI
        #define A1_left_DM_STRONG          PIN_DM_STRONG
        #define A1_left_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define A1_left_MASK               A1_left__MASK
#define A1_left_SHIFT              A1_left__SHIFT
#define A1_left_WIDTH              1u

/* Interrupt constants */
#if defined(A1_left__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in A1_left_SetInterruptMode() function.
     *  @{
     */
        #define A1_left_INTR_NONE      (uint16)(0x0000u)
        #define A1_left_INTR_RISING    (uint16)(0x0001u)
        #define A1_left_INTR_FALLING   (uint16)(0x0002u)
        #define A1_left_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define A1_left_INTR_MASK      (0x01u) 
#endif /* (A1_left__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define A1_left_PS                     (* (reg8 *) A1_left__PS)
/* Data Register */
#define A1_left_DR                     (* (reg8 *) A1_left__DR)
/* Port Number */
#define A1_left_PRT_NUM                (* (reg8 *) A1_left__PRT) 
/* Connect to Analog Globals */                                                  
#define A1_left_AG                     (* (reg8 *) A1_left__AG)                       
/* Analog MUX bux enable */
#define A1_left_AMUX                   (* (reg8 *) A1_left__AMUX) 
/* Bidirectional Enable */                                                        
#define A1_left_BIE                    (* (reg8 *) A1_left__BIE)
/* Bit-mask for Aliased Register Access */
#define A1_left_BIT_MASK               (* (reg8 *) A1_left__BIT_MASK)
/* Bypass Enable */
#define A1_left_BYP                    (* (reg8 *) A1_left__BYP)
/* Port wide control signals */                                                   
#define A1_left_CTL                    (* (reg8 *) A1_left__CTL)
/* Drive Modes */
#define A1_left_DM0                    (* (reg8 *) A1_left__DM0) 
#define A1_left_DM1                    (* (reg8 *) A1_left__DM1)
#define A1_left_DM2                    (* (reg8 *) A1_left__DM2) 
/* Input Buffer Disable Override */
#define A1_left_INP_DIS                (* (reg8 *) A1_left__INP_DIS)
/* LCD Common or Segment Drive */
#define A1_left_LCD_COM_SEG            (* (reg8 *) A1_left__LCD_COM_SEG)
/* Enable Segment LCD */
#define A1_left_LCD_EN                 (* (reg8 *) A1_left__LCD_EN)
/* Slew Rate Control */
#define A1_left_SLW                    (* (reg8 *) A1_left__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define A1_left_PRTDSI__CAPS_SEL       (* (reg8 *) A1_left__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define A1_left_PRTDSI__DBL_SYNC_IN    (* (reg8 *) A1_left__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define A1_left_PRTDSI__OE_SEL0        (* (reg8 *) A1_left__PRTDSI__OE_SEL0) 
#define A1_left_PRTDSI__OE_SEL1        (* (reg8 *) A1_left__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define A1_left_PRTDSI__OUT_SEL0       (* (reg8 *) A1_left__PRTDSI__OUT_SEL0) 
#define A1_left_PRTDSI__OUT_SEL1       (* (reg8 *) A1_left__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define A1_left_PRTDSI__SYNC_OUT       (* (reg8 *) A1_left__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(A1_left__SIO_CFG)
    #define A1_left_SIO_HYST_EN        (* (reg8 *) A1_left__SIO_HYST_EN)
    #define A1_left_SIO_REG_HIFREQ     (* (reg8 *) A1_left__SIO_REG_HIFREQ)
    #define A1_left_SIO_CFG            (* (reg8 *) A1_left__SIO_CFG)
    #define A1_left_SIO_DIFF           (* (reg8 *) A1_left__SIO_DIFF)
#endif /* (A1_left__SIO_CFG) */

/* Interrupt Registers */
#if defined(A1_left__INTSTAT)
    #define A1_left_INTSTAT            (* (reg8 *) A1_left__INTSTAT)
    #define A1_left_SNAP               (* (reg8 *) A1_left__SNAP)
    
	#define A1_left_0_INTTYPE_REG 		(* (reg8 *) A1_left__0__INTTYPE)
#endif /* (A1_left__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_A1_left_H */


/* [] END OF FILE */
