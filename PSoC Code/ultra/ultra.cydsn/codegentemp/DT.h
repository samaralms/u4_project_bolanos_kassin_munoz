/*******************************************************************************
* File Name: DT.h  
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

#if !defined(CY_PINS_DT_H) /* Pins DT_H */
#define CY_PINS_DT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DT_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DT__PORT == 15 && ((DT__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DT_Write(uint8 value);
void    DT_SetDriveMode(uint8 mode);
uint8   DT_ReadDataReg(void);
uint8   DT_Read(void);
void    DT_SetInterruptMode(uint16 position, uint16 mode);
uint8   DT_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DT_SetDriveMode() function.
     *  @{
     */
        #define DT_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DT_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DT_DM_RES_UP          PIN_DM_RES_UP
        #define DT_DM_RES_DWN         PIN_DM_RES_DWN
        #define DT_DM_OD_LO           PIN_DM_OD_LO
        #define DT_DM_OD_HI           PIN_DM_OD_HI
        #define DT_DM_STRONG          PIN_DM_STRONG
        #define DT_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DT_MASK               DT__MASK
#define DT_SHIFT              DT__SHIFT
#define DT_WIDTH              1u

/* Interrupt constants */
#if defined(DT__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DT_SetInterruptMode() function.
     *  @{
     */
        #define DT_INTR_NONE      (uint16)(0x0000u)
        #define DT_INTR_RISING    (uint16)(0x0001u)
        #define DT_INTR_FALLING   (uint16)(0x0002u)
        #define DT_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DT_INTR_MASK      (0x01u) 
#endif /* (DT__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DT_PS                     (* (reg8 *) DT__PS)
/* Data Register */
#define DT_DR                     (* (reg8 *) DT__DR)
/* Port Number */
#define DT_PRT_NUM                (* (reg8 *) DT__PRT) 
/* Connect to Analog Globals */                                                  
#define DT_AG                     (* (reg8 *) DT__AG)                       
/* Analog MUX bux enable */
#define DT_AMUX                   (* (reg8 *) DT__AMUX) 
/* Bidirectional Enable */                                                        
#define DT_BIE                    (* (reg8 *) DT__BIE)
/* Bit-mask for Aliased Register Access */
#define DT_BIT_MASK               (* (reg8 *) DT__BIT_MASK)
/* Bypass Enable */
#define DT_BYP                    (* (reg8 *) DT__BYP)
/* Port wide control signals */                                                   
#define DT_CTL                    (* (reg8 *) DT__CTL)
/* Drive Modes */
#define DT_DM0                    (* (reg8 *) DT__DM0) 
#define DT_DM1                    (* (reg8 *) DT__DM1)
#define DT_DM2                    (* (reg8 *) DT__DM2) 
/* Input Buffer Disable Override */
#define DT_INP_DIS                (* (reg8 *) DT__INP_DIS)
/* LCD Common or Segment Drive */
#define DT_LCD_COM_SEG            (* (reg8 *) DT__LCD_COM_SEG)
/* Enable Segment LCD */
#define DT_LCD_EN                 (* (reg8 *) DT__LCD_EN)
/* Slew Rate Control */
#define DT_SLW                    (* (reg8 *) DT__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DT_PRTDSI__CAPS_SEL       (* (reg8 *) DT__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DT_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DT__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DT_PRTDSI__OE_SEL0        (* (reg8 *) DT__PRTDSI__OE_SEL0) 
#define DT_PRTDSI__OE_SEL1        (* (reg8 *) DT__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DT_PRTDSI__OUT_SEL0       (* (reg8 *) DT__PRTDSI__OUT_SEL0) 
#define DT_PRTDSI__OUT_SEL1       (* (reg8 *) DT__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DT_PRTDSI__SYNC_OUT       (* (reg8 *) DT__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DT__SIO_CFG)
    #define DT_SIO_HYST_EN        (* (reg8 *) DT__SIO_HYST_EN)
    #define DT_SIO_REG_HIFREQ     (* (reg8 *) DT__SIO_REG_HIFREQ)
    #define DT_SIO_CFG            (* (reg8 *) DT__SIO_CFG)
    #define DT_SIO_DIFF           (* (reg8 *) DT__SIO_DIFF)
#endif /* (DT__SIO_CFG) */

/* Interrupt Registers */
#if defined(DT__INTSTAT)
    #define DT_INTSTAT            (* (reg8 *) DT__INTSTAT)
    #define DT_SNAP               (* (reg8 *) DT__SNAP)
    
	#define DT_0_INTTYPE_REG 		(* (reg8 *) DT__0__INTTYPE)
#endif /* (DT__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DT_H */


/* [] END OF FILE */
