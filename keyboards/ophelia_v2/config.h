/* Copyright 2017 Mattia Dal Ben
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */

#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6068
#define DEVICE_VER      0x0004
#define MANUFACTURER    F14eagle
#define PRODUCT         Ophelia V2
//#define DESCRIPTION     q.m.k. keyboard firmware for OpheliaV2

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 18
#define PAD_START_COL 14

#define MATRIX_ROW_PINS { D4, C6, D7, E6, B4 }
#define MATRIX_COL_PINS { B6, B6, B6, B6, B6, B6, B6, B6, B6, B6, B6, B6, B6, B6, F6, F7, B1, B3 }

#define RGB_DI_PIN B5
#define RGBLED_NUM 16

//#define RGBLIGHT_ANIMATIONS
/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
//#define BACKLIGHT_LEVELS 3

#define ONESHOT_TIMEOUT 500

#define VIAL_KEYBOARD_UID {0xD3, 0xEC, 0xC6, 0x37, 0xB1, 0x38, 0x59, 0x87}
#define VIAL_UNLOCK_COMBO_ROWS { 0, 0, 2 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 3, 12 }
/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

//UART settings for communication with the RF microcontroller
#define SERIAL_UART_BAUD 38400
#define SERIAL_UART_DATA UDR1
#define SERIAL_UART_UBRR (F_CPU / (16UL * SERIAL_UART_BAUD) - 1)
#define SERIAL_UART_TXD_READY (UCSR1A & _BV(UDRE1))
#define SERIAL_UART_RXD_PRESENT (UCSR1A & _BV(RXC1))
#define SERIAL_UART_INIT() do { \
    	/* baud rate */ \
    	UBRR1L = SERIAL_UART_UBRR; \
    	/* baud rate */ \
    	UBRR1H = SERIAL_UART_UBRR >> 8; \
    	/* enable TX and RX */ \
    	UCSR1B = _BV(TXEN1) | _BV(RXEN1); \
    	/* 8-bit data */ \
    	UCSR1C = _BV(UCSZ11) | _BV(UCSZ10); \
  	} while(0)
