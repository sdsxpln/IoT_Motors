#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include "user_interface.h"

#define RESOLUTION_US 5

#define CLOCKWISE_PINOUT 1
#define COUNTERCLOCKWISE_PINOUT -1

void step_driver ( void );
void opcode_move(signed int step_num, unsigned short step_rate);
void opcode_goto(signed int step_num, unsigned short step_rate);
void opcode_stop(signed int wait_time, unsigned short precision);
float calculate_step_incrementor(unsigned short input_step_rate);
int is_motor_running();

void driver_logic_task(os_event_t *events);

enum stepper_state
{
    IDLE,
    DIRECTION_ASSERT,
    STEPPING,
	DWELL
};

enum motor_direction
{
    FORWARDS = 1,
    PAUSED = 0,
    BACKWARDS = -1
};


#endif