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
 * @file    ml_multi_saw.h
 * @author  Marcel Licence
 * @date    24.03.2023
 *
 * @brief   You will find all current available functions to control the multi saw module below
 *
 * @see     https://youtu.be/kcf597op8o4
 */


#ifndef SYNTH_MULTI_SAW_H_
#define SYNTH_MULTI_SAW_H_


#include <stdint.h>
#include <ml_types.h>


void MultiSawSynth_Init(float sample_rate);
void MultiSawSynth_SetDetune(uint8_t value);
void MultiSawSynth_SetCount(uint8_t value);
void MultiSawSynth_Process(Q1_14 *ch_m, int sampleLen);
void MultiSawSynth_Process(Q1_14 *ch_l, Q1_14 *ch_r, int sampleLen);
void MultiSawSynth_NoteOn(uint8_t ch, uint8_t note, uint8_t vel);
void MultiSawSynth_NoteOff(uint8_t ch, uint8_t note);
void MultiSawSynth_NoteSetPitch(uint8_t ch, uint8_t note, uint32_t pitch);
void MultiSawSynth_NoteSetVolume(uint8_t ch, uint8_t note, uint16_t volume);
void MultiSawSynth_PitchBend(uint8_t ch, uint16_t bend);
void MultiSawSynth_SetProfile(uint8_t value);
void MultiSawSynth_SetCurrentCh(uint8_t value);
void MultiSawSynth_SetShift(uint16_t value);


#endif /* SYNTH_MULTI_SAW_H_ */

