#include "std_fsm.h"
#include <memory.h>
#include <assert.h>
#include <stddef.h>

fsm_bool_t
match_any_0_9_match_fn(char *data1,         /*Transition entry key, which will be empty buffer*/
                         unsigned int size, /*size shall be zero*/
                         char *data2,       /*Data from User Input*/
                         unsigned int user_data_len,
                         unsigned int *length_read){

    /*We are bothered only about user data 'data2'*/

    if(user_data_len == 0){
        *length_read = 0;
        return FSM_FALSE;
    }o0p
    if(*data2 >= 48 &&
            *data2 <= 57){

        *length_read = 1;
        return FSM_TRUE;
    }

    return FSM_FALSE;
}

fsm_bool_t
match_any_a_z_match_fn(char *data1,       /*Transition entry key, which will be empty buffer*/
                       unsigned int size, /*size shall be zero*/
                       char *data2,       /*Data from User Input*/
                       unsigned int user_data_len,
                       unsigned int *length_read){

    /*We are bothered only about user data 'data2'*/

    if(user_data_len == 0){
        *length_read = 0;
        return FSM_FALSE;
    }

    if(*data2 >= 97 &&
            *data2 <= 122){

        *length_read = 1;
        return FSM_TRUE;
    }

    return FSM_FALSE;
}

fsm_bool_t
match_any_A_Z_match_fn(char *data1,       /*Transition entry key, which will be empty buffer*/
                       unsigned int size, /*size shall be zero*/
                       char *data2,       /*Data from User Input*/
                       unsigned int user_data_len,
                       unsigned int *length_read){

    /*We are bothered only about user data 'data2'*/
    if(user_data_len == 0){
        *length_read = 0;
        return FSM_FALSE;
    }

    if(*data2 >= 65 &&
            *data2 <= 90){

        *length_read = 1;
        return FSM_TRUE;
    }

    return FSM_FALSE;
}


fsm_bool_t
match_any_0_9_or_a_z_or_A_Z_match_fn(char *data1, unsigned int size,
                                     char *data2, unsigned int user_data_len,
                                     unsigned int *length_read){

    return (match_any_0_9_match_fn(data1, size, data2, user_data_len, length_read) ||
            match_any_a_z_match_fn(data1, size, data2, user_data_len, length_read) ||
            match_any_A_Z_match_fn(data1, size, data2, user_data_len, length_read));

    /**length_read shall be set to 1 by callees*/
}

fsm_bool_t
match_any_character_match_fn(char *data1, unsigned int size,
                             char *data2,
                             unsigned int user_data_len,
                             unsigned int *length_read){

    if(user_data_len == 0){
        *length_read = 0;
        return FSM_FALSE;
    }
    *length_read = 1;
    return FSM_TRUE;
}

fsm_t *email_validator_fsm(){

    tt_entry_t *tt_entry = NULL;
    char transition_key[MAX_TRANSITION_KEY_SIZE];
    unsigned int transition_keysize = 0;

    fsm_t *fsm = create_new_fsm("Email Validator");

/*DEAD_STATE*/
    state_t *DEAD_STATE = create_new_state("D", FSM_FALSE);
    create_and_insert_new_tt_entry_wild_card(DEAD_STATE, DEAD_STATE, 0);

/*state_F*/
    state_t *state_F = create_new_state("F", FSM_TRUE);
    create_and_insert_new_tt_entry_wild_card(state_F, DEAD_STATE, 0);

/*q6*/
    state_t *state_q6 = create_new_state("q6", FSM_FALSE);

    transition_keysize = strlen("gmail.com");
    strncpy(transition_key, "gmail.com", transition_keysize);
    create_and_insert_new_tt_entry(&state_q6->state_trans_table,
                                   transition_key, transition_keysize, 0,
                                   state_F);

    transition_keysize = strlen("hotmail.com");
    strncpy(transition_key, "hotmail.com", transition_keysize);
    create_and_insert_new_tt_entry(&state_q6->state_trans_table,
                                   transition_key, transition_keysize, 0,
                                   state_F);

    create_and_insert_new_tt_entry_wild_card(state_q6, DEAD_STATE, 0);

/*q5*/
    state_t *state_q5 = create_new_state("q5", FSM_FALSE);
    tt_entry = create_and_insert_new_tt_entry(&state_q5->state_trans_table,
                                   0, 0, 0,
                                   state_q5);

    register_input_matching_tt_entry_cb(tt_entry, match_any_0_9_match_fn);
    register_input_matching_tt_entry_cb(tt_entry, match_any_a_z_match_fn);
    register_input_matching_tt_entry_cb(tt_entry, match_any_A_Z_match_fn);

    transition_keysize = 1;
    transition_key[0] = '@';
    create_and_insert_new_tt_entry(&state_q5->state_trans_table,
                                    transition_key, transition_keysize , 0,
                                    state_q6);
    create_and_insert_new_tt_entry_wild_card(state_q5, DEAD_STATE, 0);

/*q4*/
    state_t *state_q4 = create_new_state("q4", FSM_FALSE);
    tt_entry = create_and_insert_new_tt_entry(&state_q4->state_trans_table,
                                   0, 0, 0,
                                   state_q5);

    register_input_matching_tt_entry_cb(tt_entry, match_any_0_9_match_fn);
    register_input_matching_tt_entry_cb(tt_entry, match_any_a_z_match_fn);
    register_input_matching_tt_entry_cb(tt_entry, match_any_A_Z_match_fn);
    create_and_insert_new_tt_entry_wild_card(state_q4, DEAD_STATE, 0);

/*q3*/
    state_t *state_q3 = create_new_state("q3", FSM_FALSE);
    tt_entry = create_and_insert_new_tt_entry(&state_q3->state_trans_table,
                                   0, 0, 0,
                                   state_q4);

    register_input_matching_tt_entry_cb(tt_entry, match_any_0_9_match_fn);
    register_input_matching_tt_entry_cb(tt_entry, match_any_a_z_match_fn);
    register_input_matching_tt_entry_cb(tt_entry, match_any_A_Z_match_fn);
    create_and_insert_new_tt_entry_wild_card(state_q3, DEAD_STATE, 0);

/*q2*/
    state_t *state_q2 = create_new_state("q2", FSM_FALSE);
    tt_entry = create_and_insert_new_tt_entry(&state_q2->state_trans_table,
                                   0, 0, 0,
                                   state_q3);

    register_input_matching_tt_entry_cb(tt_entry, match_any_0_9_match_fn);
    register_input_matching_tt_entry_cb(tt_entry, match_any_a_z_match_fn);
    register_input_matching_tt_entry_cb(tt_entry, match_any_A_Z_match_fn);
    create_and_insert_new_tt_entry_wild_card(state_q2, DEAD_STATE, 0);

/*q1*/
    state_t *state_q1 = create_new_state("q1", FSM_FALSE);
    tt_entry = create_and_insert_new_tt_entry(&state_q1->state_trans_table,
                                   0, 0, 0,
                                   state_q2);

    register_input_matching_tt_entry_cb(tt_entry, match_any_0_9_match_fn);
    register_input_matching_tt_entry_cb(tt_entry, match_any_a_z_match_fn);
    register_input_matching_tt_entry_cb(tt_entry, match_any_A_Z_match_fn);
    create_and_insert_new_tt_entry_wild_card(state_q1, DEAD_STATE, 0);

/*q0*/
    state_t *state_q0 = create_new_state("q0", FSM_FALSE);
    set_fsm_initial_state(fsm, state_q0);

    tt_entry = create_and_insert_new_tt_entry(&state_q0->state_trans_table,
                                   0, 0, 0,
                                   state_q1);

    register_input_matching_tt_entry_cb(tt_entry, match_any_0_9_match_fn);
    register_input_matching_tt_entry_cb(tt_entry, match_any_a_z_match_fn);
    register_input_matching_tt_entry_cb(tt_entry, match_any_A_Z_match_fn);
    create_and_insert_new_tt_entry_wild_card(state_q0, DEAD_STATE, 0);

    return fsm;
}

void
substring_occurrence_counter(state_t *from, state_t *to,
                             char *input_buff,
                             unsigned int input_buff_size,
                             fsm_output_buff_t *fsm_output_buff){


    unsigned int *counter_array = (unsigned int *)(fsm_output_buff->output_buffer);
    unsigned int index = fsm_output_buff->curr_pos;

    if((index * sizeof(unsigned int)) < MAX_FSM_OUTPUT_BUFFER){

        counter_array[index] = (unsigned int)(input_buff);
        fsm_output_buff->curr_pos++;
    }
}


fsm_t *
fsm_substring_counter(char *common_trans_key,
                      unsigned int trans_key_size){

    fsm_t *fsm = create_new_fsm("FSM Substring Counter");
    state_t *state_S0 = create_new_state("S0", FSM_FALSE);
    set_fsm_initial_state(fsm, state_S0);

    create_and_insert_new_tt_entry(&state_S0->state_trans_table,
                                    common_trans_key,
                                    trans_key_size,
                                    substring_occurrence_counter,
                                    state_S0);
    create_and_insert_new_tt_entry_wild_card(state_S0, state_S0, 0);
    return fsm;
}

void
convert_binary_to_hex(state_t *from, state_t *to,
            char *input_buff,
            unsigned int input_buff_size,
            fsm_output_buff_t *fsm_output_buff){


    char hex;
    char *last_4_bits = input_buff - 3;

    if     (last_4_bits[0] == '0' && last_4_bits[1] == '0' && last_4_bits[2] == '0' && last_4_bits[3] == '0')
        hex = '0';
    else if(last_4_bits[0] == '0' && last_4_bits[1] == '0' && last_4_bits[2] == '0' && last_4_bits[3] == '1')
        hex = '1';
    else if(last_4_bits[0] == '0' && last_4_bits[1] == '0' && last_4_bits[2] == '1' && last_4_bits[3] == '0')
        hex = '2';
    else if(last_4_bits[0] == '0' && last_4_bits[1] == '0' && last_4_bits[2] == '1' && last_4_bits[3] == '1')
        hex = '3';
    else if(last_4_bits[0] == '0' && last_4_bits[1] == '1' && last_4_bits[2] == '0' && last_4_bits[3] == '0')
        hex = '4';
    else if(last_4_bits[0] == '0' && last_4_bits[1] == '1' && last_4_bits[2] == '0' && last_4_bits[3] == '1')
        hex = '5';
    else if(last_4_bits[0] == '0' && last_4_bits[1] == '1' && last_4_bits[2] == '1' && last_4_bits[3] == '0')
        hex = '6';
    else if(last_4_bits[0] == '0' && last_4_bits[1] == '1' && last_4_bits[2] == '1' && last_4_bits[3] == '1')
        hex = '7';
    else if(last_4_bits[0] == '1' && last_4_bits[1] == '0' && last_4_bits[2] == '0' && last_4_bits[3] == '0')
        hex = '8';
    else if(last_4_bits[0] == '1' && last_4_bits[1] == '0' && last_4_bits[2] == '0' && last_4_bits[3] == '1')
        hex = '9';
    else if(last_4_bits[0] == '1' && last_4_bits[1] == '0' && last_4_bits[2] == '1' && last_4_bits[3] == '0')
        hex = 'A';
    else if(last_4_bits[0] == '1' && last_4_bits[1] == '0' && last_4_bits[2] == '1' && last_4_bits[3] == '1')
        hex = 'B';
    else if(last_4_bits[0] == '1' && last_4_bits[1] == '1' && last_4_bits[2] == '0' && last_4_bits[3] == '0')
        hex = 'C';
    else if(last_4_bits[0] == '1' && last_4_bits[1] == '1' && last_4_bits[2] == '0' && last_4_bits[3] == '1')
        hex = 'D';
    else if(last_4_bits[0] == '1' && last_4_bits[1] == '1' && last_4_bits[2] == '1' && last_4_bits[3] == '0')
        hex = 'E';
    else if(last_4_bits[0] == '1' && last_4_bits[1] == '1' && last_4_bits[2] == '1' && last_4_bits[3] == '1')
        hex = 'F';
    else
        assert(0);

    fsm_output_buff->output_buffer[fsm_output_buff->curr_pos] = hex;
    fsm_output_buff->curr_pos++;
}

/*This Violate the principles of FSM, You are not supposed to look backwards in the past
 * of input buffer !! Redo it.*/
fsm_t *
fsm_binary_to_hex(){

    fsm_t *fsm = create_new_fsm("FSM Bin->Hex Converter");

    state_t *q1 = create_new_state("q1", FSM_FALSE);

    /*q4*/
    state_t *q4 = create_new_state("q4", FSM_TRUE);
    create_and_insert_new_tt_entry(&q4->state_trans_table,
                                   "0", 1, 0,
                                    q1);
    create_and_insert_new_tt_entry(&q4->state_trans_table,
                                   "1", 1, 0,
                                    q1);
    /*q3*/
    state_t *q3 = create_new_state("q3", FSM_FALSE);
    create_and_insert_new_tt_entry(&q3->state_trans_table,
                                   "0", 1, convert_binary_to_hex,
                                    q4);
    create_and_insert_new_tt_entry(&q3->state_trans_table,
                                   "1", 1, convert_binary_to_hex,
                                    q4);

    /*q2*/
    state_t *q2 = create_new_state("q2", FSM_FALSE);
    create_and_insert_new_tt_entry(&q2->state_trans_table,
                                   "0", 1, 0,
                                    q3);
    create_and_insert_new_tt_entry(&q2->state_trans_table,
                                   "1", 1, 0,
                                    q3);
    /*q1*/
    create_and_insert_new_tt_entry(&q1->state_trans_table,
                                   "0", 1, 0,
                                    q2);
    create_and_insert_new_tt_entry(&q1->state_trans_table,
                                   "1", 1, 0,
                                    q2);
    /*q0*/
    state_t *q0 = create_new_state("q0", FSM_FALSE);
    set_fsm_initial_state(fsm, q0);
    create_and_insert_new_tt_entry(&q0->state_trans_table,
                                   "0", 1, 0,
                                    q1);
    create_and_insert_new_tt_entry(&q0->state_trans_table,
                                   "1", 1, 0,
                                    q1);
    return fsm;
}

