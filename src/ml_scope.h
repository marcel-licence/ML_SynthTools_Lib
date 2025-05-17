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
 * @file h
 * @author Marcel Licence
 * @date 01.01.2022
 *
 * @brief This file contains an implementation of a little fast scope which
 * is optimized to create steady images
 *
 * In this version it uses the default Wire connection to talk to an OLED display
 * It is written to be used with up to two 128x64 OLED displays
 * The left channel will be output on i2c addr 0x3C and the right on i2c addr 0x3D
 */


#ifndef SRC_ML_SCOPE_H_
#define SRC_ML_SCOPE_H_


/*
 * includes
 */
#include <stdint.h>
#include <Wire.h>

#define ML_SCOPE_OLED

/*
 * function declarations
 */
void ScopeOled_Setup(void);
#ifdef ESP32
void ScopeOled_Setup(TwoWire *twi);
#endif
void ScopeOled_Process(void);
void ScopeOled_AddSamples(float *left, float *right, uint32_t len);
void ScopeOled_DrawData(const float *dispData, uint8_t idx);


#endif /* SRC_ML_SCOPE_H_ */

