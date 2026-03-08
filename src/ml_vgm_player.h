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
 * @file ml_vgm_player.h
 * @author Marcel Licence
 * @date 04.03.2024
 *
 * @brief VGM player module
 *
 * @see sneak peak: https://youtu.be/bDulrbvu_M8
 * @see pi pico: https://youtu.be/ZSxM3nDhyo4
 * @see esp32: https://youtu.be/nhTBUviYfUs
 */


#ifndef SRC_ML_VGM_PLAYER_H_
#define SRC_ML_VGM_PLAYER_H_


#include <ml_types.h>


bool VgmPlayerLoadFile(void);
void VgmPlayerSetup(uint32_t sample_rate);
void VgmPlayerSetBuffer(uint8_t *buffer, uint32_t buffer_size);
void VgmPlayerProcessSamples(Q1_14 *chL, Q1_14 *chR, uint64_t count);
void VgmPlayerProcessSamples(Q1_14 *ch1, Q1_14 *ch2, Q1_14 *ch3, Q1_14 *ch4, uint64_t count);
bool VgmPlayerIsPlaying(void);

void VgmPlayerRewind(uint8_t unused __attribute__((unused)), uint8_t value);
void VgmPlayerStop(uint8_t unused __attribute__((unused)), uint8_t value);
void VgmPlayerPlay(uint8_t unused __attribute__((unused)), uint8_t value);
void VgmPlayerPlayPause(uint8_t unused __attribute__((unused)), uint8_t value);
void VgmPlayerStep(uint8_t unused __attribute__((unused)), uint8_t value);

void VgmPlayer_SetTempo(uint8_t unused __attribute__((unused)), uint8_t value);

void VgmPlayerDebugPrintf(const char *fmt, ...); /*!< weak and can be implemented by the user */
void VgmPlayerDebugFlush(void); /*!< weak and can be implemented by the user */


#endif /* SRC_ML_VGM_PLAYER_H_ */
