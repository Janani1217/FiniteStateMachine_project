#ifndef __STD_FSM__
#define __STD_FSM__

#include "fsm.h"

/* Standard utility callbacks for transition table
 * entry matching*/

fsm_bool_t
match_any_0_9_match_fn(char *data1,         /*Transition entry key, which will be empty buffer*/
        unsigned int size,                  /*size shall be zero*/
        char *data2,                        /*Data from User Input*/
        unsigned int user_data_len,
        unsigned int *length_read);

fsm_bool_t
match_any_a_z_match_fn(char *data1,       /*Transition entry key, which will be empty buffer*/
        unsigned int size,                /*size shall be zero*/
        char *data2,                      /*Data from User Input*/
        unsigned int user_data_len,
        unsigned int *length_read);

fsm_bool_t
match_any_A_Z_match_fn(char *data1,       /*Transition entry key, which will be empty buffer*/
        unsigned int size,                /*size shall be zero*/
        char *data2,                      /*Data from User Input*/
        unsigned int user_data_len,
        unsigned int *length_read);

fsm_bool_t
match_any_0_9_or_a_z_or_A_Z_match_fn(char *data1,
                                     unsigned int size,
                                     char *data2,
                                     unsigned int user_data_len,
                                     unsigned int *length_read);

fsm_bool_t
match_any_character_match_fn(char *data1, unsigned int size,
                             char *data2, unsigned int user_data_len,
                             unsigned int *length_read);


/*Standard output functions*/
void
convert_binary_to_hex(state_t *from, state_t *to,
                       char *input_buff,
                       unsigned int input_buff_size,
                       fsm_output_buff_t *fsm_output_buff);



/*Standard Example FSMs*/
fsm_t *email_validator_fsm();
fsm_t *phone_number_validator_fsm();

/*https://www.geeksforgeeks.org/mealy-and-moore-machines*/
fsm_t *mealy_machine_fsm();
fsm_t *moore_machine_fsm();

fsm_t *fsm_substring_counter(char *common_trans_key,
                              unsigned int trans_key_size);

fsm_t *
fsm_binary_to_hex();

#endif /* __STD_FSM__ */
