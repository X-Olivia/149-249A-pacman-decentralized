#ifndef _bluetoothdrive_main_H
#define _bluetoothdrive_main_H
#ifndef _BLUETOOTHDRIVE_MAIN_H // necessary for arduino-cli, which automatically includes headers that are not used
#ifndef TOP_LEVEL_PREAMBLE_358422965_H
#define TOP_LEVEL_PREAMBLE_358422965_H
/*Correspondence: Range: [(19, 2), (20, 17)) -> Range: [(0, 0), (1, 17)) (verbatim=true; src=/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src/lib/Motors.lf)*/#include <motors.h>
#include <math.h>
#endif // TOP_LEVEL_PREAMBLE_358422965_H
#ifndef TOP_LEVEL_PREAMBLE_1804537094_H
#define TOP_LEVEL_PREAMBLE_1804537094_H
/*Correspondence: Range: [(11, 2), (12, 26)) -> Range: [(0, 0), (1, 26)) (verbatim=true; src=/Users/sareenarobinson/Desktop/EECS149Repo/149-249A-pacman-decentralized/firmware/src/BluetoothDrive.lf)*/#include "hardware/uart.h"
#include "hardware/gpio.h"
#endif // TOP_LEVEL_PREAMBLE_1804537094_H


#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/schedule.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct bluetoothdrive_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    int end[0]; // placeholder; MSVC does not compile empty structs
} bluetoothdrive_self_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    char value;

} bluetooth_cmd_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    char value;

} robot_cmd_t;
#endif
#endif
