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
 * @file librp2350_i2s_audio.h
 * @author Marcel Licence
 * @date 28.09.2024
 *
 * @brief This file includes the prototypes of the librp2350_i2s_audio.a library
 * It is precompiled because some headers are not available withing the Arduino IDE to compile
 * DIN->DOUT: 26
 * BCK->BCK: 27
 * WCK->LCK: 28
 */


#if (defined ARDUINO_RASPBERRY_PI_PICO) || (defined ARDUINO_GENERIC_RP2040)
#define rp2350_i2s_init(...)    rp2040_i2s_init(__VA_ARGS__)
#define rp2350_i2s_write_stereo_samples_buff(...)   rp2040_i2s_write_stereo_samples_buff(__VA_ARGS__)
#endif


void rp2350_i2s_init(int data_pin, int clock_base_pin);
void rp2350_i2s_write_stereo_samples_buff(const float *in_l, const float *in_r, uint32_t sample_count);
void rp2350_i2s_write_stereo_samples_buff(const int16_t *in_l, const int16_t *in_r, uint32_t sample_count);
