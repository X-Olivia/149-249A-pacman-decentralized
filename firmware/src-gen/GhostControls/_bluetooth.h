#ifndef _BLUETOOTH_H
#define _BLUETOOTH_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_1422415458_H
#define TOP_LEVEL_PREAMBLE_1422415458_H
#include "hardware/uart.h"
#include "hardware/gpio.h"

#define NAME_MAXLEN 12
#define PIN_UART_TX 28
#define PIN_UART_RX 29
#define BAUD_RATE 9600
#endif // TOP_LEVEL_PREAMBLE_1422415458_H
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
} _bluetooth_cmd_t;
typedef struct {
    struct self_base_t base;
    #line 21 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src/lib/Bluetooth.lf"
    string name;
#line 33 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_bluetooth.h"
#line 34 "/home/ducky/Downloads/149-249A-pacman-decentralized/firmware/src-gen/GhostControls/_bluetooth.h"
    _bluetooth_cmd_t _lf_cmd;
    int _lf_cmd_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    trigger_t _lf__poll;
    reaction_t* _lf__poll_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
} _bluetooth_self_t;
_bluetooth_self_t* new__bluetooth();
#endif // _BLUETOOTH_H
