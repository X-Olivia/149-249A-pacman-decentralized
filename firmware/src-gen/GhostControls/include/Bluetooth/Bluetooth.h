#ifndef _bluetooth_H
#define _bluetooth_H
#ifndef _BLUETOOTH_H // necessary for arduino-cli, which automatically includes headers that are not used
#ifndef TOP_LEVEL_PREAMBLE_1422415458_H
#define TOP_LEVEL_PREAMBLE_1422415458_H
/*Correspondence: Range: [(9, 2), (15, 22)) -> Range: [(0, 0), (6, 22)) (verbatim=true; src=/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/Bluetooth.lf)*/#include "hardware/uart.h"
#include "hardware/gpio.h"

#define NAME_MAXLEN 12
#define PIN_UART_TX 28
#define PIN_UART_RX 29
#define BAUD_RATE 9600
#endif // TOP_LEVEL_PREAMBLE_1422415458_H
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/schedule.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct bluetooth_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    string name;
    int end[0]; // placeholder; MSVC does not compile empty structs
} bluetooth_self_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    char value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} bluetooth_cmd_t;
#endif
#endif
