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
 * @file ml_pitch_shifter.h
 * @author Marcel Licence
 * @date 01.09.2023
 *
 * @brief   PitchShifter declarations
 *
 * @see little demo: https://youtu.be/hqK_U22Jha8
 */


#ifndef SRC_ML_PITCH_SHIFTER_P_H_
#define SRC_ML_PITCH_SHIFTER_P_H_


#include <ml_pitch_shifter.h>


#ifdef ARDUINO_ARCH_RP2040
#ifndef __ARM_FEATURE_DSP
#define ML_PitchShifter_ProcessHQ(...)    ML_PitchShifter_ProcessHQ_RP2040(__VA_ARGS__)
#else
#define ML_PitchShifter_ProcessHQ(...)    ML_PitchShifter_ProcessHQ_RP2350(__VA_ARGS__)
#endif
#endif


void ML_PitchShifter_ProcessHQ(const float *in, float *buffer, float *out, uint32_t count, float speed, int32_t &inCnt, float &outCnt, float wetV, float dryV, float feedback);


#endif /* SRC_ML_PITCH_SHIFTER_P_H_ */

