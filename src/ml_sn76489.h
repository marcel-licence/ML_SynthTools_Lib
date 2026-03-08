/*
 * ML SynthTools Lib - A modular synthesizer library including organ, electric piano,
 * oscillators, and sound synthesis tools.
 *
 * Copyright (C) 2026 Marcel Licence
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
 * @file ml_sn76489.h
 * @author Marcel Licence
 * @date 04.03.2024
 *
 * @brief SN76489 emulation
 *
 * @see sneak peak: https://youtu.be/bDulrbvu_M8
 * @see pi pico: https://youtu.be/ZSxM3nDhyo4
 * @see esp32: https://youtu.be/nhTBUviYfUs
 */


#ifndef SRC_ML_SN76489_H_
#define SRC_ML_SN76489_H_


#include <ml_types.h>


void SN76489Setup(uint32_t sample_rate);
void SN76489_Stop(void);
void SN76489SetClock(uint32_t clock_rate);
void SN76489Data(uint8_t data);
void SN76489_ProcessSamples(Q1_14 *chL, Q1_14 *chR, uint64_t count);
void SN76489_ProcessSamples(Q1_14 *ch1, Q1_14 *ch2, Q1_14 *ch3, Q1_14 *ch4, uint64_t count);
void SN76489_SetPitch(uint8_t unused, uint8_t value);
void SN76489_SetNoise(uint8_t unused, uint8_t value);
void SN76489_ToggleMute(uint8_t param, uint8_t value);


#endif /* SRC_ML_SN76489_H_ */
