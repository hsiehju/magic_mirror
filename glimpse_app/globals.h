/*
 * globals.h
 *
 *  Created on: Apr 12, 2016
 *      Author: hsiehju
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_

#include <inttypes.h>
#include "drivers/CoreUARTapb/core_uart_apb.h"

#define RX_BUFF_SIZE    64
#define TX_BUFF_SIZE    64

// FRAME BUFFER
extern unsigned frame_buffer[40][15];

// MAIN PAGE
extern char time[9];
extern char date[10];
extern char temp[4];
extern char icon[6][6];
extern uint8_t icon_selected;
extern const char quote_title[17];
extern char quotes_lib[5][93];
extern uint8_t quote_selected;

// TODO LIST
extern const char todo_title[10];
extern char todo_list[5][35];
extern char todo_check[5];
extern uint8_t num_of_tasks;
extern uint8_t tasks_full;

// SONG
extern char song_name[40];
extern char artist[40];

// INT
extern uint8_t gesture_available;
extern int gesture;

extern UART_instance_t uart2;

// PAGE SELECTION
// 0 blank page
// 1 main page
// 2 todo list
// 3 song page
extern uint8_t page_selected;


void GPIO0_IRQHandler();

char ascii_to_value(char ascii);

char large_number_to_fb(char ascii, uint8_t x, uint8_t y);

char icon_to_fb(uint8_t icon);

#endif /* GLOBALS_H_ */
