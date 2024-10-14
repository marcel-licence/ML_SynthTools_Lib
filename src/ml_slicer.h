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
 * @file    ml_slicer.h
 * @author  Marcel Licence
 * @date    24.03.2023
 *
 * @brief   A simple slicer effect (work still on progress)
 *
 * @see     https://youtu.be/kcf597op8o4
 */


#ifndef ML_SLICER_H_
#define ML_SLICER_H_


#include <ml_types.h>


void Slicer_Process(Q1_14 *ch_l, Q1_14 *ch_r, uint32_t sample_count);
uint32_t Slicer_GetLastMultiplier(void);
void Slicer_SetSpeed(uint8_t unused __attribute__((unused)), uint8_t value);
void Slicer_SetDepth(uint8_t unused __attribute__((unused)), uint8_t value);
void Slicer_SetType(uint8_t unused __attribute__((unused)), uint8_t value);
void Slicer_SetAttack(uint8_t unused __attribute__((unused)), uint8_t value);
void Slicer_SetDecay(uint8_t unused __attribute__((unused)), uint8_t value);


#endif /* ML_SLICER_H_ */
