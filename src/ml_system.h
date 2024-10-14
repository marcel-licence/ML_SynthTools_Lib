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
 * @file    ml_system.h
 * @author  Marcel Licence
 * @date    06.02.2022
 *
 * @brief   This is only required some specific system tasks
 */

#ifndef SRC_ML_SYSTEM_H_
#define SRC_ML_SYSTEM_H_


void System_PrintInfo(const char *user);
char *System_GetInfo(void);

/* no pub start */
bool CheckLc(void);
/* no pub end */


#endif /* SRC_ML_SYSTEM_H_ */

