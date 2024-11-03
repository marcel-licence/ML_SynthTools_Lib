/*
 * ML SynthTools Lib - A modular synthesizer library including organ, electric piano,
 * oscillators, and sound synthesis tools.
 *
 * Copyright (C) 2024 Marcel Licence
 *
 * This file is part of the ML SynthTools Lib library and is licensed under the ML SynthTools Lib License.
 *
 * You may use this file in non-commercial projects, provided that this header
 * and all authorship attributions remain intact.
 *
 * For commercial use, please contact marcel.licence.o@gmail.com for licensing terms.
 *
 * The source code of this library is not included. Reverse-engineering,
 * decompiling, or any attempt to access the source code from the compiled files
 * is strictly prohibited.
 *
 * ML SynthTools Lib is provided "as is," without warranty of any kind. See the LICENSE
 * file for the full license text.
 */

/**
 * @file ml_delay_q.h
 * @author Marcel Licence
 * @date 06.01.2022
 *
 * @brief This file contains the declarations of functions of a simple delay effect
 */


#ifndef SRC_ML_DELAY_Q_H_
#define SRC_ML_DELAY_Q_H_


#include <stdint.h>


#ifdef ARDUINO_ARCH_RP2040
#ifndef __ARM_FEATURE_DSP
#define DelayQ_Init(...)    DelayQ_RP2040_Init(__VA_ARGS__)
#define DelayQ_Init2(...)    DelayQ_RP2040_Init2(__VA_ARGS__)
#define DelayQ_Process_Buff(...)    DelayQ_RP2040_Process_Buff(__VA_ARGS__)
#define DelayQ_SetFeedback    DelayQ_RP2040_SetFeedback
#define DelayQ_SetOutputLevel    DelayQ_RP2040_SetOutputLevel
#define DelayQ_SetLength    DelayQ_RP2040_SetLength
#else
#define DelayQ_Init(...)    DelayQ_RP2350_Init(__VA_ARGS__)
#define DelayQ_Init2(...)    DelayQ_RP2350_Init2(__VA_ARGS__)
#define DelayQ_Process_Buff(...)    DelayQ_RP2350_Process_Buff(__VA_ARGS__)
#define DelayQ_SetFeedback    DelayQ_RP2350_SetFeedback
#define DelayQ_SetOutputLevel    DelayQ_RP2350_SetOutputLevel
#define DelayQ_SetLength    DelayQ_RP2350_SetLength
#endif
#endif


void DelayQ_Init(int16_t *buffer, uint32_t len);
void DelayQ_Init2(int16_t *left, int16_t *right, uint32_t len);
void DelayQ_Process_Buff(const int16_t *in_l, const int16_t *in_r, int16_t *out_l, int16_t *out_r, int buffLen);
void DelayQ_SetFeedback(uint8_t unused __attribute__((unused)), uint8_t value);
void DelayQ_SetOutputLevel(uint8_t unused __attribute__((unused)), uint8_t value);
void DelayQ_SetLength(uint8_t unused __attribute__((unused)), uint32_t value);


#endif /* SRC_ML_DELAY_Q_H_ */

