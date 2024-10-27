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

/**
 * @file ml_phaser.h
 * @author Marcel Licence
 * @date 20.12.2022
 *
 * @brief This file contains an implementation of a simple stereo phaser effect
 *
 * @see first peak: https://youtu.be/Kac9AB02BcQ
 * @see little demo: https://youtu.be/hqK_U22Jha8
 */


#ifndef SRC_ML_PHASER_P_H_
#define SRC_ML_PHASER_P_H_


#include <inttypes.h>
#include <ml_phaser.h>


#ifdef ARDUINO_ARCH_RP2040
#ifndef __ARM_FEATURE_DSP
#define Phaser_ProcessHQ(...)    Phaser_ProcessHQ_RP2040(__VA_ARGS__)
#else
#define Phaser_ProcessHQ(...)    Phaser_ProcessHQ_RP2350(__VA_ARGS__)
#endif
#endif


void Phaser_ProcessHQ(const float *in, const float *lfo_in, float *out, int buffLen, float phaserDepth, struct allpass_s *ap0);


#endif /* SRC_ML_PHASER_P_H_ */

