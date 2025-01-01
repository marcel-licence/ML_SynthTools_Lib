/*
 * ML SynthTools Lib - A modular synthesizer library including organ, electric piano,
 * oscillators, and sound synthesis tools.
 *
 * Copyright (C) 2025 Marcel Licence
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
 * @file ml_vibrato.h
 * @author Marcel Licence
 * @date 01.09.2023
 *
 * @brief   Vibrato declarations
 *
 * @see little demo: https://youtu.be/hqK_U22Jha8
 */


#ifndef SRC_ML_VIBRATO_P_H_
#define SRC_ML_VIBRATO_P_H_


#include <ml_vibrato.h>


#ifdef ARDUINO_ARCH_RP2040
#ifndef __ARM_FEATURE_DSP
#define ML_Vibrato_ProcessHQ(...)    ML_Vibrato_ProcessHQ_RP2040(__VA_ARGS__)
#else
#define ML_Vibrato_ProcessHQ(...)    ML_Vibrato_ProcessHQ_RP2350(__VA_ARGS__)
#endif
#endif


void ML_Vibrato_ProcessHQ(const float *in, const float *mod_in, float *out, uint32_t count, float mod_multiplier, int32_t &inCnt, float *buffer, float depth, float depthInv);


#endif /* SRC_ML_VIBRATO_P_H_ */

