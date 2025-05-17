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
 * @file ml_organ.h
 * @author Marcel Licence
 * @date 26.11.2021
 *
 * @brief   This shows you all available functions to use the organ library
 *          The library is still in progress and will be updated in future
 *          You can integrate this lib at the moment in your ESP32 and ESP8266 projects
 */


#ifndef SRC_ML_ORGAN_H_
#define SRC_ML_ORGAN_H_


#include <stdint.h>


#define CTRL_PERC_SWITCH    0
#define CTRL_PERC_SPEED     1
#define CTRL_PERC_NOTE      2
#define CTRL_PERC_LOUD      3
#define CTRL_PERC_POLY      4
#define CTRL_INTR_FEEDBACK  5
#define CTRL_ROTARY_ACTIVE  6


#ifdef ARDUINO_ARCH_SAMD
#define Organ_Setup(...)    OrganSAMD21_Setup(__VA_ARGS__)
#define Organ_Process(...)    OrganSAMD21_Process(__VA_ARGS__)
#define Organ_Process_Buf(...)    OrganSAMD21_Process_Buf(__VA_ARGS__)
#define Organ_NoteOn    OrganSAMD21_NoteOn
#define Organ_NoteOff    OrganSAMD21_NoteOff
#define Organ_PercussionSet(...)    OrganSAMD21_PercussionSet(__VA_ARGS__)
#define Organ_SetLeslCtrl(...)    OrganSAMD21_SetLeslCtrl(__VA_ARGS__)
#define Organ_SetDrawbar(...)    OrganSAMD21_SetDrawbar(__VA_ARGS__)
#endif

#ifdef ARDUINO_ARCH_RP2040
#ifndef __ARM_FEATURE_DSP
#define Organ_Setup(...)    OrganRP2040_Setup(__VA_ARGS__)
#define Organ_Process(...)    OrganRP2040_Process(__VA_ARGS__)
#define Organ_Process_Buf(...)    OrganRP2040_Process_Buf(__VA_ARGS__)
#define Organ_NoteOn    OrganRP2040_NoteOn
#define Organ_NoteOff    OrganRP2040_NoteOff
#define Organ_PercussionSet(...)    OrganRP2040_PercussionSet(__VA_ARGS__)
#define Organ_SetLeslCtrl(...)    OrganRP2040_SetLeslCtrl(__VA_ARGS__)
#define Organ_SetDrawbar(...)    OrganRP2040_SetDrawbar(__VA_ARGS__)
#else
#define Organ_Setup(...)    OrganRP2350_Setup(__VA_ARGS__)
#define Organ_Process(...)    OrganRP2350_Process(__VA_ARGS__)
#define Organ_Process_Buf(...)    OrganRP2350_Process_Buf(__VA_ARGS__)
#define Organ_NoteOn    OrganRP2350_NoteOn
#define Organ_NoteOff    OrganRP2350_NoteOff
#define Organ_PercussionSet(...)    OrganRP2350_PercussionSet(__VA_ARGS__)
#define Organ_SetLeslCtrl(...)    OrganRP2350_SetLeslCtrl(__VA_ARGS__)
#define Organ_SetDrawbar(...)    OrganRP2350_SetDrawbar(__VA_ARGS__)
#endif
#endif

/**
 * call this first before using the module to initialize it
 */
void Organ_Setup(float sample_rate);

/**
 * when initialized you will get your audio samples from this function
 */
int16_t Organ_Process(void);
void Organ_Process_Buf(int32_t *buf, uint8_t len); /* not supported by ESP32, ESP8266 */

/**
 * this functions are used to feed in the note on/off events
 */
void Organ_NoteOn(uint8_t ch __attribute__((unused)), uint8_t note, uint8_t vel __attribute__((unused)));
void Organ_NoteOff(uint8_t ch __attribute__((unused)), uint8_t note);

/**
 * finally you can control some settings with the following functions
 */
void Organ_PercussionSet(uint8_t setting);
void Organ_SetLeslCtrl(uint8_t val); /* not supported by SAMD21 */
void Organ_SetDrawbar(uint8_t idx, uint8_t value);


#endif /* SRC_ML_ORGAN_H_ */

