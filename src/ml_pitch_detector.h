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
 * @file ml_pitch_detector
 * @brief Header file for the pitch detector module
 *
 * This module is used for pitch detection with 24 bins per octave
 *
 * @date 17.10.2024
 * @author Marcel Licence
 */

#ifndef SRC_ML_PITCH_DETECTOR_H_
#define SRC_ML_PITCH_DETECTOR_H_


#include <stdint.h>


void Notedetector_Setup(float sample_rate);
void NoteDetector_PushSamples(float *in, uint32_t count);
void NoteDetector_GetConstants24(float *out);
uint8_t NoteDetector_GetIdx(void);
bool NoteDetector_Process(void);


#endif /* SRC_ML_PITCH_DETECTOR_H_ */
