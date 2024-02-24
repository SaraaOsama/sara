/*
 * Matrix_keypad.c
 *
 *  Created on: Feb 17, 2024
 *      Author: Mina
 *      static visible only in this file
 */
#include "Matrix_keypad.h"

static void hardware_initialize(Keypad_Matrix_t *kp) {
	GPIO_InitTypeDef gp =
			{ .Mode = GPIO_MODE_OUTPUT_PP, .Speed = GPIO_SPEED_LOW };
	uint32_t Pins = 0;
	for (int x = 0; x < kp->Rows; x++) {
		Pins |= (1 << (kp->Row_Start_Pin) + x);
	}
	gp.Pin = Pins;
	HAL_GPIO_Init(kp->Rows_Port, &gp);

	kp->output_Mask = Pins;
	gp.Mode = GPIO_MODE_INPUT;
	gp.Pull = GPIO_PULLDOWN;
	Pins = 0;
	for (int x = 0; x < kp->Columns; x++) {
		Pins |= (1 << (kp->Column_Start_Pin) + x);
	}
	gp.Pin = Pins;
	HAL_GPIO_Init(kp->Column_Port, &gp);
	kp->input_Mask = Pins;
}
static void Hardware_Generate_Delay(uint16_t delay) {
	HAL_Delay(delay);
}
static uint8_t Hardware_Get_Inputs(Keypad_Matrix_t *kp) {
	uint32_t m = kp->Column_Port->IDR & kp->input_Mask;
	m >>= kp->Column_Start_Pin;
	return (uint8_t) m;

}
static void Hardware_Set_Outputs(Keypad_Matrix_t *kp, uint8_t status) {
	kp->Rows_Port->ODR &=~(kp->output_Mask);
	kp->Rows_Port->ODR |=((uint32_t) status)<<kp->Row_Start_Pin;
}

void Keypad_Matrix_init(Keypad_Matrix_t *kp) {

}
void Keypad_matrix_refresh(Keypad_Matrix_t kp) {

}
uint8_t Keypad_Matrix_Readkey(Keypad_Matrix_t *kp, uint8_t key) {

}
