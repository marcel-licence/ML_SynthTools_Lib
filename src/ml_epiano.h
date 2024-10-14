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
 * @file ml_epiano.h
 * @author Marcel Licence
 * @date 02.11.2022
 *
 * @brief   This file contains all declarations to use the e-piano module
 *          It is pre-compiled and only linking is required (done by Arduino)
 *
 *          A short demonstration can be found here:
 * @see     https://youtu.be/m12w1Xtm5Ts
 */


#ifndef EPIANO_H_
#define EPIANO_H_


#include <stdint.h>
#include <ml_types.h>

#ifdef ARDUINO_ARCH_RP2040
#ifndef __ARM_FEATURE_DSP
#define ML_EPiano ML_EPiano_RP2040
#endif
#endif

#ifdef ARDUINO_ARCH_RP2040
#ifdef __ARM_FEATURE_DSP
#define ML_EPiano ML_EPiano_RP2350
#endif
#endif

class ML_EPiano
{
public:
    ML_EPiano();
    ~ML_EPiano() {};

    void Init(float sample_rate);

    void setSampleRate(float sample_rate);

    void Process(Q1_14 *samples, int sampleLen);
    void Process(float *samples, int sampleLen);

    void NoteOn(uint8_t ch, uint8_t note, float vel);
    void NoteOff(uint8_t ch, uint8_t note);
    void Sustain(float sustain); /*! sustain amount, you can also use 1.0 and 0.0 */

    void SetEffectSpeed(float speed); /*! speed for tremolo and modulation in Hz */
    void PitchBend(float bend); /*!< pitch bend -> -1.0 to 1.0 for -2 semitones to 2 semitones */
    void SetCurve(float value); /*!< this is one of two sound modifiers, it will take a short time to recalcute the sound-engine */
    void SetCurve2(float value); /*!< this is one of two sound modifiers, it will take a short time to recalcute the sound-engine */
    void CalcCurvePreset1(void); /*!< using a default preset */

    void SetCenterTuneA(float frequency); /*!< global tuning, use 220Hz or 880Hz to go one octave down or up */

    void SetQuickDamping(float value);
    void SetQuickDampingThr(float value);

    void SetModulationDepth(float value);
};


#endif /* EPIANO_H_ */

