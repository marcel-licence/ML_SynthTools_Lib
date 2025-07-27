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
 * @file ml_midi_player.h
 * @brief This file contains function declarations of the MIDI player
 *
 * This is a MIDI player with some features to manipulate the playback.
 *
 * @date 09.07.2025
 * @author Marcel Licence
 */


#ifndef ML_MIDI_PLAYER_H_
#define ML_MIDI_PLAYER_H_


/*
 * Includes
 */
#include <stdint.h>

/*
 * Function Prototypes
 */
/* system functions */
void ml_midi_player_setup(uint8_t *data, int bytesRead);
bool ml_midi_player_loop(uint64_t elapsed_millis);
void ml_midi_player_set_mt32_sound_variation(void);

/* control functions */
void ml_midi_player_set_tempo(float tempo);
void ml_midi_player_stop(void);
void ml_midi_player_rewind(void);
void ml_midi_player_play(void);
void ml_midi_player_toggle_track_mute(uint8_t track_id);
bool ml_midi_player_is_active(void);

/* callbacks */
void midi_send_cc(uint8_t ch, uint8_t data0, uint8_t data1);
void midi_player_send_data(uint8_t *msg, int len);
void midi_player_send_gm_reset_msg(void);
void ml_midi_player_song_end(void);


#endif /* ML_MIDI_PLAYER_H_ */
