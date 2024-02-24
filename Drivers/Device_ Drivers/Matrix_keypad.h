/*
 * Matrix_keypad.h
 *
 *  Created on: Feb 17, 2024
 *      Author: Mina
 */

#ifndef DEVICE__DRIVERS_MATRIX_KEYPAD_H_
#define DEVICE__DRIVERS_MATRIX_KEYPAD_H_

#include "stm32f1xx_hal.h"   /*all hal drivers*/
#include "stdint.h"
/// @struct keypad
/// @brief
///
typedef struct keypad {
	///
	///attribute:Keypad_rows&columns
	uint8_t Rows;
	uint8_t Columns;

	///
	/// holds the status of the buttons
	uint32_t Button_Status;

	///
	/// peripheral configuration
	GPIO_typedef *Rows_Port;
	uint8_t Row_Start_Pin;
	GPIO_typedef *Column_Port;
	uint8_t Column_Start_Pin;
	uint32_t input_Mask;
	uint32_t output_Mask;

} Keypad_Matrix_t;

/// @fn void Keypad_Matrix_init(Keypad_Matrix_t*)
/// @brief
/// user functions
/// @param kp
void Keypad_Matrix_init(Keypad_Matrix_t *kp);
void Keypad_matrix_refresh(Keypad_Matrix_t kp);
uint8_t Keypad_Matrix_Readkey(Keypad_Matrix_t *kp, uint8_t key);//anhy keyapad ba2ra meno w teraga3 rakam el key

#endif /* DEVICE__DRIVERS_MATRIX_KEYPAD_H_ */
