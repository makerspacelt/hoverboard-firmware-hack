#pragma once
#include "stm32f1xx_hal.h"

// ############################### DO-NOT-TOUCH SETTINGS ###############################

#define PWM_FREQ         16000      // PWM frequency in Hz
#define DEAD_TIME        32         // PWM deadtime

#define DELAY_IN_MAIN_LOOP 5        // in ms. default 5. it is independent of all the timing critical stuff. do not touch if you do not know what you are doing.

#define TIMEOUT          5          // number of wrong / missing input commands before emergency off

// ############################### GENERAL ###############################

// How to calibrate: connect GND and RX of a 3.3v uart-usb adapter to the right sensor board cable (be careful not to use the red wire of the cable. 15v will destroye verything.). if you are using nunchuck, disable it temporarily. enable DEBUG_SERIAL_USART3 and DEBUG_SERIAL_ASCII use asearial terminal.

// Battery voltage calibration: connect power source. see <How to calibrate>. write value nr 5 to BAT_CALIB_ADC. make and flash firmware. then you can verify voltage on value 6 (devide it by 100.0 to get calibrated voltage).
#define BAT_CALIB_REAL_VOLTAGE        44.0       // input voltage measured by multimeter  
#define BAT_CALIB_ADC                 1944       // adc-value measured by mainboard (value nr 5 on UART debug output)

#define BAT_NUMBER_OF_CELLS     4         // normal Hoverboard battery: 10s
#define BAT_LOW_LVL1_ENABLE     0         // to beep or not to beep, 1 or 0
#define BAT_LOW_LVL1            10.5      // gently beeps at this voltage level. [V/cell]
#define BAT_LOW_LVL2_ENABLE     0         // to beep or not to beep, 1 or 0
#define BAT_LOW_LVL2            10        // your battery is almost empty. Charge now! [V/cell]
#define BAT_LOW_DEAD            0         // undervoltage poweroff (while not driving). Set to 0 to disable. [V/cell]

#define DC_CUR_LIMIT           25         // DC current limit in amps per motor. so 15 means it will draw 30A out of your battery. it does not disable motors, it is a soft current limit.

// Board overheat detection: the sensor is inside the STM/GD chip. it is very inaccurate without calibration (up to 45°C). so only enable this funcion after calibration! let your board cool down. see <How to calibrate>. get the real temp of the chip by thermo cam or another temp-sensor taped on top of the chip and write it to TEMP_CAL_LOW_DEG_C. write debug value 8 to TEMP_CAL_LOW_ADC. drive around to warm up the board. it should be at least 20°C warmer. repeat it for the HIGH-values. enable warning and/or poweroff and make and flash firmware.
#define TEMP_POWEROFF_ENABLE    0         // to poweroff or not to poweroff, 1 or 0, DO NOT ACTIVITE WITHOUT CALIBRATION!
#define TEMP_WARNING_ENABLE     0         // to beep or not to beep, 1 or 0, DO NOT ACTIVITE WITHOUT CALIBRATION!
#define TEMP_CAL_LOW_ADC        1655      // temperature 1: ADC value
#define TEMP_CAL_LOW_DEG_C      35.8      // temperature 1: measured temperature [°C]
#define TEMP_CAL_HIGH_ADC       1588      // temperature 2: ADC value
#define TEMP_CAL_HIGH_DEG_C     48.9      // temperature 2: measured temperature [°C]
#define TEMP_WARNING            60        // annoying fast beeps [°C]
#define TEMP_POWEROFF           65        // overheat poweroff. (while not driving) [°C]

#define INACTIVITY_TIMEOUT 8        // minutes of not driving until poweroff. it is not very precise.

// ############################### SERIAL DEBUG ###############################

#define DEBUG_SERIAL_USART3         // right sensor board cable, disable if I2C (nunchuck or lcd) is used!
#define DEBUG_BAUD       115200     // UART baud rate
#define DEBUG_SERIAL_ASCII          // "1:345 2:1337 3:0 4:0 5:0 6:0 7:0 8:0\r\n"

// ############################### INPUT ###############################

#define ADC1_MIN 780 // adc_buffer.l_tx2 -> cmd1 -> speedR
#define ADC1_MID 1935
#define ADC1_MAX 3140
#define ADC2_MIN 780 // adc_buffer.l_rx2 -> cmd2 -> speedL
#define ADC2_MID 1935
#define ADC2_MAX 3140

#define FILTER              0.05  // lower value == softer filter. do not use values <0.01, you will get float precision issues.
#define BEEPS_BACKWARD 0    // 0 or 1

