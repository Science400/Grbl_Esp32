#pragma once
// clang-format off

/*
    layoutTable.h
    Part of Grbl_ESP32

    Machine definition for the Layout Table build by Isaiah Young for
    Magnum Manufacturing.

    2018    - Bart Dring
    2020    - Mitch Bradley
    2021    - Isaiah Young

    Grbl_ESP32 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Grbl is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Grbl_ESP32.  If not, see <http://www.gnu.org/licenses/>.
*/

#define MACHINE_NAME "Layout Table"


#define N_AXIS 3

// === Special Features ===

#define USE_STEPSTICK   // makes sure MS1,2,3 !reset and !sleep are set

// I2S (steppers & other output-only pins)
#define USE_I2S_OUT
#define USE_I2S_STEPS
//#define DEFAULT_STEPPER ST_I2S_STATIC

#define I2S_OUT_BCK             GPIO_NUM_22
#define I2S_OUT_WS              GPIO_NUM_17
#define I2S_OUT_DATA            GPIO_NUM_21

// === Pin Mapping ===
// Motor Socket #1
#define X_DISABLE_PIN           I2SO(0)
#define X_DIRECTION_PIN         I2SO(1)
#define X_STEP_PIN              I2SO(2)
#define X_STEPPER_MS3           I2SO(3)

// Motor Socket #2
#define Y_DIRECTION_PIN         I2SO(4)
#define Y_STEP_PIN              I2SO(5)
#define Y_DISABLE_PIN           I2SO(7)

// Motor Socket #3
#define Y2_DISABLE_PIN          I2SO(8)
#define Y2_DIRECTION_PIN        I2SO(9)
#define Y2_STEP_PIN             I2SO(10)

// Motor Socket #4
#define Z_DIRECTION_PIN         I2SO(12)
#define Z_STEP_PIN              I2SO(13)
#define Z_STEPPER_MS3           I2SO(14)
#define Z_DISABLE_PIN           I2SO(15)

// 4x Input Module in Socket #1
// https://github.com/bdring/6-Pack_CNC_Controller/wiki/4x-Switch-Input-module
// #define X_LIMIT_PIN                 GPIO_NUM_33
// #define Y_LIMIT_PIN                 GPIO_NUM_32
// #define Z_LIMIT_PIN                 GPIO_NUM_35

// === Homing ===
// This cannot use homing because there are no switches yet
#ifdef DEFAULT_HOMING_CYCLE_0
    #undef DEFAULT_HOMING_CYCLE_0
#endif

#ifdef DEFAULT_HOMING_CYCLE_1
    #undef DEFAULT_HOMING_CYCLE_1
#endif


#define SPINDLE_TYPE    SpindleType::NONE

#ifdef USE_RMT_STEPS
#undef USE_RMT_STEPS  // Suppress unused variable warning
#endif

// ================= Setting Defaults ==========================

// see wiki https://github.com/bdring/Grbl_Esp32/wiki/External-Stepper-Drivers
// #define DEFAULT_STEP_ENABLE_DELAY        5 // how long after enable do we wait for 
// #define DEFAULT_STEP_PULSE_MICROSECONDS  4 // length of step pulse. Must be greater than I2S_OUT_USEC_PER_PULSE (4) with I2S
// #define STEP_PULSE_DELAY                 6 // gap between enable and dir changes before step

// #define DEFAULT_STEPPING_INVERT_MASK     (bit(Y_AXIS))
// #define DEFAULT_DIRECTION_INVERT_MASK    (bit(Y_AXIS))
#define DEFAULT_INVERT_ST_ENABLE    (bit(Y_AXIS))

#define DEFAULT_X_STEPS_PER_MM 200.0
#define DEFAULT_Y_STEPS_PER_MM 200.0
#define DEFAULT_Z_STEPS_PER_MM 800.0

#define DEFAULT_X_MAX_RATE 8000.0 // mm/min
#define DEFAULT_Y_MAX_RATE 8000.0 // mm/min
#define DEFAULT_Z_MAX_RATE 3000.0 // mm/min

#define DEFAULT_X_ACCELERATION 200.0 // mm/sec^2
#define DEFAULT_Y_ACCELERATION 200.0 // mm/sec^2
#define DEFAULT_Z_ACCELERATION 100.0 // mm/sec^2

#define DEFAULT_X_MAX_TRAVEL 500.0 // mm NOTE: Must be a positive value.
#define DEFAULT_Y_MAX_TRAVEL 500.0 // mm NOTE: Must be a positive value.
#define DEFAULT_Z_MAX_TRAVEL 80.0 // mm NOTE: Must be a positive value.

