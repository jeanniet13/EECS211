#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define MAX_CMD_LINE_LENGTH 256
#define MAX_TOKENS_ON_A_LINE 30

#define NUMBER_OF_COMMANDS 8

#define HALT 50
#define STATUS 51
#define TIME_CLICK 52
#define CREATE_DEVICE 61
#define CREATE_EVENT 62
#define SET_DEVICE_VALUE 71
#define PROCESS_EVENTS 53
#define MALFUNCTION 54

#define UNDEFINED_COMMAND 99

#define MAX_DEVICES 20

#define GENERIC 50
#define DIGITAL_SENSOR 51
#define ANALOG_SENSOR 52
#define DIGITAL_CONTROLLER 53
#define ANALOG_CONTROLLER 54

#define ON 200
#define OFF 250


#define NO_MALFUNCTION 20  //indicates if there's a malfunction
#define MALFUNCTION_OVER_RANGE 21  //if there's an over range malfunction
#define MALFUNCTION_UNDER_RANGE 22  //if there's an under range malfunction
#define MALFUNCTION_STOPPED_WORKING 23  //if it stopped working

#endif
