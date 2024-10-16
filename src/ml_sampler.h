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

/*
 *  @file   ml_sampler.h
 *  @author Marcel Licence
 *  @date   03.06.2023
 *
 *  @brief  This file includes prototypes for a multiplatform sampler module
 */

#ifndef SRC_ML_SAMPLER_H_
#define SRC_ML_SAMPLER_H_


#include <stdint.h>
#include <ml_types.h>


#define SAMPLER_PARAM_INSTRUMENT_IDX    0
#define SAMPLER_PARAM_HOLD              1
#define SAMPLER_PARAM_RELEASE           2
#define SAMPLER_PARAM_LOOP_MODE         3


void Sampler_Init(uint32_t sample_rate);

void Sampler_SetSampleBuffer(uint8_t *buffer, uint32_t buffer_len);
void Sampler_UseStaticBuffer(Q1_14 *buffer, uint32_t count);

uint32_t Sampler_GetFreeSpace(void);
uint32_t Sampler_GetUsedSpace(void);
uint32_t Sampler_GetMaxSpace(void);

void Sampler_NoteOn(uint8_t ch, uint8_t note, uint8_t vel);
void Sampler_NoteOff(uint8_t ch, uint8_t note, uint8_t vel __attribute__((unused)));
void Sampler_NoteOff(uint8_t ch, uint8_t note);
void Sampler_AllNotesOff(void);
void Sampler_PitchBend(uint8_t ch, uint16_t bend);

void Sampler_ChangeParameter(uint8_t parameter, float value);
void Sampler_ChangeParameter(uint8_t parameter, uint8_t value);
void Sampler_ChangeParameterSample(uint8_t parameter, float value);
void Sampler_ChangeParameterSample(uint8_t parameter, uint8_t value);
void Sampler_ProgramChange(uint8_t channel, uint8_t program_number);

void Sampler_StartTransfer(void);
void Sampler_EndTransfer(void);
void Sampler_InstrumentDone(void);

bool Sampler_NewSample(void);
bool Sampler_AddSamples(Q1_14 *samples, uint32_t sample_count);
bool Sampler_AddSamplesU8(uint8_t *samples, uint32_t sample_count);
void Sampler_NewSampleSetRange(uint32_t start, uint32_t end);
void Sampler_NewSampleSetLoop(uint32_t start, uint32_t end);
void Sampler_SetLoopMode(uint8_t mode);
void Sampler_SetPitch(uint8_t originalPitch, uint32_t sampleRate, int8_t pitchCorrection);
void Sampler_SetKeyRange(uint8_t keyLowest, uint8_t keyHighest);
void Sampler_SetVelRange(uint8_t velLowest, uint8_t velHighest);
void Sampler_SetExclusiveClass(uint8_t ex_class);
void Sampler_SetRelease(uint32_t release);
void Sampler_SetHold(uint32_t hold);
void Sampler_FinishSample(void);

void Sampler_TuneCoarse(uint8_t unused, uint8_t value);
void Sampler_TuneFine(uint8_t unused, uint8_t value);
void Sampler_LoopEntireSample(uint8_t unused, uint8_t value);

void Sampler_ClearAllSamples(void);

void Sampler_DebugInt(const char *str, uint32_t num);
void Sampler_DebugFloat(const char *str, float num);

uint8_t Sampler_GetSampleCount(void);

void Sampler_DecSample(void);
void Sampler_IncSample(void);

void Sampler_Process(Q1_14 *left, Q1_14 *right, uint32_t count);

bool Sampler_NewSampleStatic(const unsigned char *data, uint32_t size);
bool Sampler_NewSampleStatic(const unsigned char *data, uint32_t size, uint8_t note);


#endif /* SRC_ML_SAMPLER_H_ */

