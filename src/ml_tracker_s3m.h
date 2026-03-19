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
 * @file ml_tracker_s3m.h
 * @author Marcel Licence
 * @date 02.03.2024
 *
 * @brief s3m tracker module
 *
 * @see Pi Pico: https://www.youtube.com/shorts/D_jD9efA5I0
 * @see Pi Pico 2: https://www.youtube.com/shorts/2_cdIPhUEkY
 */


#ifndef SRC_ML_TRACKER_S3M_H_
#define SRC_ML_TRACKER_S3M_H_


#include <ml_types.h>


bool TrackerS3MLoadFile(void);
bool TrackerS3MLoadData(const uint8_t *data, uint32_t len);
void TrackerS3MSetup(uint32_t sample_rate);
void TrackerS3MStartPlayback(void);
void TrackerS3MProcess(uint64_t passed);
void TrackerS3MProcessSamples(Q1_14 *chL, Q1_14 *chrR, uint64_t count);
uint32_t TrackerS3MGetMemSize(void);
void TrackerS3MUseStaticBuffer(void);
void TrackerS3MSetBuffer(void *buffer);
bool TrackerS3M_IsActive(void);

void TrackerS3M_NoteOn(uint8_t ch, uint8_t note, uint8_t vel);
void TrackerS3M_NoteOff(uint8_t ch, uint8_t note, uint8_t vel __attribute__((unused)));
void TrackerS3M_NoteOff(uint8_t ch, uint8_t note);

void TrackerS3M_Restart(uint8_t param, uint8_t value);
void TrackerS3M_Stop(uint8_t param, uint8_t value);
void TrackerS3M_End(uint8_t param __attribute__((unused)), uint8_t value);
void TrackerS3M_Start(uint8_t param, uint8_t value);

void TrackerS3M_DebugPrintf(const char *fmt, ...); /*!< weak and can be implemented by the user */
void TrackerS3M_DebugFlush(void); /*!< weak and can be implemented by the user */


#endif /* SRC_ML_TRACKER_S3M_H_ */
