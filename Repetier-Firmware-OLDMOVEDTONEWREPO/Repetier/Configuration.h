/*
    This file is part of Repetier-Firmware.

    Repetier-Firmware is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Repetier-Firmware is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Repetier-Firmware.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

/**************** READ FIRST ************************

   This configuration file was created with the configuration tool. For that
   reason, it does not contain the same informations as the original Configuration.h file.
   It misses the comments and unused parts. Open this file file in the config tool
   to see and change the data. You can also upload it to newer/older versions. The system
   will silently add new options, so compilation continues to work.

   This file is optimized for version 0.92
   generator: http://www.repetier.com/firmware/v092/

   If you are in doubt which named functions use which pins on your board, please check the
   pins.h for the used name->pin assignments and your board documentation to verify it is
   as you expect.

*/
#define ADVANCED_USER 1 // Change to 1 to unlock full menus
#define NUM_EXTRUDER 1

// 301 = RAMBO    302 = MINI_RAMBO
#define MOTHERBOARD 302

/* Define Priner being used
   Orion = 1
   Rostock Max V2 = 2
   ERIS = 3
   DROPLIT = 4
 */
#define PRINTER 3

#include "pins.h"

// ################## EDIT THESE SETTINGS MANUALLY ################
//  Microstepping mode of your RAMBO board
#define MICROSTEP_MODES {16,16,16,16,16} // [1,2,4,8,16]
// Motor Current setting (Only functional when motor driver current ref pins are connected to a digital trimpot on supported boards)
#define MOTOR_CURRENT {140,140,140,150,0} // Values 0-255 (RAMBO 135 = ~0.75A, 185 = ~1A)
//########   Mini Rambo etc... motor current settings    #########

//  Motor PWM current for mini rambo is X+Y on the same first value, Z on the next, then Extruder(s) on the last value
#define STEPPER_CURRENT_CONTROL CURRENT_CONTROL_PWM
#define MOTOR_CURRENT_PWM_RANGE 2000
//#define DEFAULT_PWM_MOTOR_CURRENT  {30, 30, 130}  // X+Y, Z, E+
#define MOTOR_CURRENT_PWM {20, 20, 175}


// ################ END MANUAL SETTINGS ##########################

#define FAN_BOARD_PIN 6  // ERIS Case Fan pin

//#define EXTERNALSERIAL  use Arduino serial library instead of build in. Requires more ram, has only 63 byte input buffer.
// Uncomment the following line if you are using arduino compatible firmware made for Arduino version earlier then 1.0
// If it is incompatible you will get compiler errors about write functions not beeing compatible!
//#define COMPAT_PRE1
#define MIXING_EXTRUDER 0
#define DRIVE_SYSTEM 3
#define BELT_PITCH 2
#define PULLEY_TEETH 20
#define PULLEY_CIRCUMFERENCE (BELT_PITCH * PULLEY_TEETH)
#define PULLEY_DIAMETER 10
//#define PULLEY_CIRCUMFERENCE (PULLEY_DIAMETER * 3.1415927)
#define STEPS_PER_ROTATION 200
#define MICRO_STEPS 16
#if PRINTER == 4
#define AXIS_STEPS_PER_MM 1600
#else
#define AXIS_STEPS_PER_MM ((float)(MICRO_STEPS * STEPS_PER_ROTATION) / PULLEY_CIRCUMFERENCE)
#endif
#define XAXIS_STEPS_PER_MM AXIS_STEPS_PER_MM
#define YAXIS_STEPS_PER_MM AXIS_STEPS_PER_MM
#define ZAXIS_STEPS_PER_MM AXIS_STEPS_PER_MM
#define EXTRUDER_FAN_COOL_TEMP 40
#define PDM_FOR_EXTRUDER 1
#define PDM_FOR_COOLER 0
#define DECOUPLING_TEST_MAX_HOLD_VARIANCE 20
#define DECOUPLING_TEST_MIN_TEMP_RISE 1
#define RETRACT_ON_PAUSE 2
#define PAUSE_START_COMMANDS "G91/nG1 Z10.0 E-5.0 F1500/nG90/n"
#define PAUSE_END_COMMANDS "G91/nG1 Z-10.0 E5.1 F1500/nG90/n"
#define EXT0_X_OFFSET 0
#define EXT0_Y_OFFSET 0
#define EXT0_STEPS_PER_MM 92.4
#define EXT0_TEMPSENSOR_TYPE 97
#define EXT0_TEMPSENSOR_PIN TEMP_0_PIN
#define EXT0_HEATER_PIN HEATER_0_PIN
#define EXT0_STEP_PIN ORIG_E0_STEP_PIN
#define EXT0_DIR_PIN ORIG_E0_DIR_PIN
#define EXT0_INVERSE 1
#define EXT0_ENABLE_PIN E0_ENABLE_PIN
#define EXT0_ENABLE_ON 0
#define EXT0_MAX_FEEDRATE 100
#define EXT0_MAX_START_FEEDRATE 45
#define EXT0_MAX_ACCELERATION 6500
#define EXT0_HEAT_MANAGER 1
#define EXT0_WATCHPERIOD 3
#define EXT0_PID_INTEGRAL_DRIVE_MAX 205
#define EXT0_PID_INTEGRAL_DRIVE_MIN 60
#define EXT0_PID_PGAIN_OR_DEAD_TIME 31.36
#define EXT0_PID_I 2.18
#define EXT0_PID_D 112.9
#define EXT0_PID_MAX 255
#define EXT0_ADVANCE_K 0
#define EXT0_ADVANCE_L 0
#define EXT0_ADVANCE_BACKLASH_STEPS 0
#define EXT0_WAIT_RETRACT_TEMP 150
#define EXT0_WAIT_RETRACT_UNITS 0
#define EXT0_SELECT_COMMANDS "M117 Extruder 1"
#define EXT0_DESELECT_COMMANDS ""

#if MOTHERBOARD == 302
#define EXT0_EXTRUDER_COOLER_PIN -1 
#else
#define EXT0_EXTRUDER_COOLER_PIN 7
#endif

#define EXT0_EXTRUDER_COOLER_SPEED 255
#define EXT0_DECOUPLE_TEST_PERIOD 45000

#define FEATURE_RETRACTION 0
#define AUTORETRACT_ENABLED 0
#define RETRACTION_LENGTH 3
#define RETRACTION_LONG_LENGTH 13
#define RETRACTION_SPEED 40
#define RETRACTION_Z_LIFT 0
#define RETRACTION_UNDO_EXTRA_LENGTH 0
#define RETRACTION_UNDO_EXTRA_LONG_LENGTH 0
#define RETRACTION_UNDO_SPEED 20
#define FILAMENTCHANGE_X_POS 0
#define FILAMENTCHANGE_Y_POS 0
#define FILAMENTCHANGE_Z_ADD  2
#define FILAMENTCHANGE_REHOME 1
#define FILAMENTCHANGE_SHORTRETRACT 5
#define FILAMENTCHANGE_LONGRETRACT 50

#define RETRACT_DURING_HEATUP true
#define PID_CONTROL_RANGE 20
#define SKIP_M109_IF_WITHIN 2
#define SCALE_PID_TO_MAX 0
#define TEMP_HYSTERESIS 0
#define EXTRUDE_MAXLENGTH 1000
#define NUM_TEMPS_USERTHERMISTOR0 0
#define USER_THERMISTORTABLE0 {}
#define NUM_TEMPS_USERTHERMISTOR1 0
#define USER_THERMISTORTABLE1 {}
#define NUM_TEMPS_USERTHERMISTOR2 0
#define USER_THERMISTORTABLE2 {}
#define USE_GENERIC_THERMISTORTABLE_1
#define GENERIC_THERM1_T0 25
#define GENERIC_THERM1_R0 100000
#define GENERIC_THERM1_BETA 4450 //4267
#define GENERIC_THERM1_MIN_TEMP -50
#define GENERIC_THERM1_MAX_TEMP 300
#define GENERIC_THERM1_R1 0
#define GENERIC_THERM1_R2 4700
#define USE_GENERIC_THERMISTORTABLE_2
#define GENERIC_THERM2_T0 25
#define GENERIC_THERM2_R0 100000
#define GENERIC_THERM2_BETA 4367
#define GENERIC_THERM2_MIN_TEMP -20
#define GENERIC_THERM2_MAX_TEMP 300
#define GENERIC_THERM2_R1 0
#define GENERIC_THERM2_R2 4700
#define GENERIC_THERM_VREF 5
#define GENERIC_THERM_NUM_ENTRIES 33
#define HEATER_PWM_SPEED 0

// ############# Heated bed configuration ########################
#if PRINTER == 1 || PRINTER == 2  // ORION and Rostock MAX
#define HAVE_HEATED_BED 1
#else
#define HAVE_HEATED_BED 0  // ERIS and DropLit have no heated beds
#endif
#define HEATED_BED_MAX_TEMP 120
#define SKIP_M190_IF_WITHIN 5
#define HEATED_BED_SENSOR_TYPE 97
#define HEATED_BED_SENSOR_PIN TEMP_BED_PIN
#define HEATED_BED_HEATER_PIN HEATER_BED_PIN
#define HEATED_BED_SET_INTERVAL 5000
#define HEATED_BED_HEAT_MANAGER 1
#define HEATED_BED_PID_INTEGRAL_DRIVE_MAX 255
#define HEATED_BED_PID_INTEGRAL_DRIVE_MIN 80
#define HEATED_BED_PID_PGAIN_OR_DEAD_TIME   87.86
#define HEATED_BED_PID_IGAIN   3.01
#define HEATED_BED_PID_DGAIN 641.82
#define HEATED_BED_PID_MAX 255
#define HEATED_BED_DECOUPLE_TEST_PERIOD 300000


// ############## Hotend safety settings ######################
/* Orion = 1
   Rostock Max V2 = 2
   ERIS = 3
   DROPLIT = 4
 */
#if PRINTER == 1 // Orion Delta w/PEEK Hotend
#define MIN_EXTRUDER_TEMP 150  //  this is the minimum temperature that will allow the extruder to drive filament, lower and it will ignore extruder commands
#define MAXTEMP 245            //  this is the max allowable temp the hotend can be set at, any higher will trigger safety's
#define MIN_DEFECT_TEMPERATURE 18  // this is the min temp that will allow the hotend to start heating.  Below this it will show as defective to help identify bad thermistors
#define MAX_DEFECT_TEMPERATURE 300 // this is the max temp that wthe printer will throw errors about defective thermistors

#elif PRINTER == 2  // Rostock MAX w/PEEK hotend
#define MIN_EXTRUDER_TEMP 150  //  this is the minimum temperature that will allow the extruder to drive filament, lower and it will ignore extruder commands
#define MAXTEMP 245            //  this is the max allowable temp the hotend can be set at, any higher will trigger safety's
#define MIN_DEFECT_TEMPERATURE 18  // this is the min temp that will allow the hotend to start heating.  Below this it will show as defective to help identify bad thermistors
#define MAX_DEFECT_TEMPERATURE 300 // this is the max temp that wthe printer will throw errors about defective thermistors

#elif PRINTER == 3  // ERIS Delta w/HE280 hotend BUT limited in temp due to cold end cooling
#define MIN_EXTRUDER_TEMP 150  //  this is the minimum temperature that will allow the extruder to drive filament, lower and it will ignore extruder commands
#define MAXTEMP 240            //  this is the max allowable temp the hotend can be set at, any higher will trigger safety's
#define MIN_DEFECT_TEMPERATURE 18  // this is the min temp that will allow the hotend to start heating.  Below this it will show as defective to help identify bad thermistors
#define MAX_DEFECT_TEMPERATURE 300 // this is the max temp that wthe printer will throw errors about defective thermistors

#elif PRINTER == 4  // DropLit so just useless numbers
#define MIN_EXTRUDER_TEMP 50   //  this is the minimum temperature that will allow the extruder to drive filament, lower and it will ignore extruder commands
#define MAXTEMP 100             //  this is the max allowable temp the hotend can be set at, any higher will trigger safety's
#define MIN_DEFECT_TEMPERATURE 18 // this is the min temp that will allow the hotend to start heating.  Below this it will show as defective to help identify bad thermistors
#define MAX_DEFECT_TEMPERATURE 300 // this is the max temp that wthe printer will throw errors about defective thermistors

#endif

// ################ Endstop configuration #####################


#if PRINTER == 4
#define ENDSTOP_PULLUP_X_MIN true
#define ENDSTOP_X_MIN_INVERTING false
#define MIN_HARDWARE_ENDSTOP_X false
#define ENDSTOP_PULLUP_Y_MIN true
#define ENDSTOP_Y_MIN_INVERTING false
#define MIN_HARDWARE_ENDSTOP_Y false
#define ENDSTOP_PULLUP_Z_MIN true
#define ENDSTOP_Z_MIN_INVERTING true
#define MIN_HARDWARE_ENDSTOP_Z true
#define ENDSTOP_PULLUP_X_MAX true
#define ENDSTOP_X_MAX_INVERTING false
#define MAX_HARDWARE_ENDSTOP_X false
#define ENDSTOP_PULLUP_Y_MAX true
#define ENDSTOP_Y_MAX_INVERTING false
#define MAX_HARDWARE_ENDSTOP_Y false
#define ENDSTOP_PULLUP_Z_MAX true
#define ENDSTOP_Z_MAX_INVERTING true
#define MAX_HARDWARE_ENDSTOP_Z true
#define max_software_endstop_r false
#else
#define ENDSTOP_PULLUP_X_MIN true
#define ENDSTOP_X_MIN_INVERTING false
#define MIN_HARDWARE_ENDSTOP_X false
#define ENDSTOP_PULLUP_Y_MIN true
#define ENDSTOP_Y_MIN_INVERTING false
#define MIN_HARDWARE_ENDSTOP_Y false
#define ENDSTOP_PULLUP_Z_MIN true
#define ENDSTOP_Z_MIN_INVERTING true
#define MIN_HARDWARE_ENDSTOP_Z false
#define ENDSTOP_PULLUP_X_MAX true
#define ENDSTOP_X_MAX_INVERTING false
#define MAX_HARDWARE_ENDSTOP_X true
#define ENDSTOP_PULLUP_Y_MAX true
#define ENDSTOP_Y_MAX_INVERTING false
#define MAX_HARDWARE_ENDSTOP_Y true
#define ENDSTOP_PULLUP_Z_MAX true
#define ENDSTOP_Z_MAX_INVERTING false
#define MAX_HARDWARE_ENDSTOP_Z true
#define max_software_endstop_r true
#endif

#define min_software_endstop_x false
#define min_software_endstop_y false
#define min_software_endstop_z false
#define max_software_endstop_x true
#define max_software_endstop_y true
#define max_software_endstop_z true
#define ENDSTOP_X_BACK_MOVE 10
#define ENDSTOP_Y_BACK_MOVE 10
#define ENDSTOP_Z_BACK_MOVE 10
#define ENDSTOP_X_RETEST_REDUCTION_FACTOR 4
#define ENDSTOP_Y_RETEST_REDUCTION_FACTOR 4
#define ENDSTOP_Z_RETEST_REDUCTION_FACTOR 4
#define ENDSTOP_X_BACK_ON_HOME 5
#define ENDSTOP_Y_BACK_ON_HOME 5
#define ENDSTOP_Z_BACK_ON_HOME 5
#define ALWAYS_CHECK_ENDSTOPS 1

// ################# XYZ movements ###################

#define X_ENABLE_ON 0
#define Y_ENABLE_ON 0
#define Z_ENABLE_ON 0
#define DISABLE_X 0
#define DISABLE_Y 0
#define DISABLE_Z 0
#define DISABLE_E 0
#if PRINTER == 1 || PRINTER == 2 || PRINTER ==4
#define INVERT_X_DIR 1
#define INVERT_Y_DIR 0
#define INVERT_Z_DIR 1
#else
#define INVERT_X_DIR 0
#define INVERT_Y_DIR 0
#define INVERT_Z_DIR 0
#endif
#define X_HOME_DIR 1
#define Y_HOME_DIR 1
#define Z_HOME_DIR 1
#define X_MAX_LENGTH 250
#define Y_MAX_LENGTH 250

#define X_MIN_POS 0
#define Y_MIN_POS 0
#define Z_MIN_POS 0
#define DISTORTION_CORRECTION 0
#define DISTORTION_CORRECTION_POINTS 5
#define DISTORTION_CORRECTION_R 100
#define DISTORTION_PERMANENT 1
#define DISTORTION_UPDATE_FREQUENCY 15
#define DISTORTION_START_DEGRADE 0.5
#define DISTORTION_END_HEIGHT 1
#define DISTORTION_EXTRAPOLATE_CORNERS 0

// ##########################################################################################
// ##                           Movement settings                                          ##
// ##########################################################################################

#define FEATURE_BABYSTEPPING 1
#define BABYSTEP_MULTIPLICATOR 1

#define DELTA_SEGMENTS_PER_SECOND_PRINT 200 // Move accurate setting for print moves
#define DELTA_SEGMENTS_PER_SECOND_MOVE 80 // Less accurate setting for other moves

// Delta settings
#if PRINTER == 1
#define DELTA_DIAGONAL_ROD 178 // mm
#define DELTA_MAX_RADIUS 145.7
#define PRINTER_RADIUS 145.7
#define Z_MAX_LENGTH 234.66
#define END_EFFECTOR_HORIZONTAL_OFFSET 33
#define CARRIAGE_HORIZONTAL_OFFSET 37.9

#elif PRINTER == 2
#define DELTA_DIAGONAL_ROD 269.0 // mm
#define DELTA_MAX_RADIUS 198.25
#define PRINTER_RADIUS 198.25
#define Z_MAX_LENGTH 234.66
#define END_EFFECTOR_HORIZONTAL_OFFSET 33
#define CARRIAGE_HORIZONTAL_OFFSET 37.9

#elif PRINTER == 3 || PRINTER == 4  //Eris and BS code for droplit
#define DELTA_DIAGONAL_ROD 134.9  // 134.58 early measurement
#define DELTA_MAX_RADIUS 65  // max printable area allowed by firmware
#define PRINTER_RADIUS 98.38  //PRINTER_RADIUS-END_EFFECTOR_HORIZONTAL_OFFSET-CARRIAGE_HORIZONTAL_OFFSET
#define Z_MAX_LENGTH 175.0
#define END_EFFECTOR_HORIZONTAL_OFFSET 23.38
#define CARRIAGE_HORIZONTAL_OFFSET 10
#endif
#define DELTA_ALPHA_A 210
#define DELTA_ALPHA_B 330
#define DELTA_ALPHA_C 90
#define DELTA_RADIUS_CORRECTION_A 0
#define DELTA_RADIUS_CORRECTION_B 0
#define DELTA_RADIUS_CORRECTION_C 0
#define DELTA_DIAGONAL_CORRECTION_A 0
#define DELTA_DIAGONAL_CORRECTION_B 0
#define DELTA_DIAGONAL_CORRECTION_C 0

#define DELTA_HOME_ON_POWER 0
#define STEP_COUNTER
#define DELTA_X_ENDSTOP_OFFSET_STEPS 0
#define DELTA_Y_ENDSTOP_OFFSET_STEPS 0
#define DELTA_Z_ENDSTOP_OFFSET_STEPS 0
#define DELTA_FLOOR_SAFETY_MARGIN_MM 15
//#define SOFTWARE_LEVELING

#define DELTASEGMENTS_PER_PRINTLINE 22
#define STEPPER_INACTIVE_TIME 600L
#define MAX_INACTIVE_TIME 900L
#define MAX_FEEDRATE_X 125
#define MAX_FEEDRATE_Y 125
#define MAX_FEEDRATE_Z 125
#define HOMING_FEEDRATE_X 80
#define HOMING_FEEDRATE_Y 80
#define HOMING_FEEDRATE_Z 80
#define HOMING_ORDER HOME_ORDER_ZXY
#define ENABLE_BACKLASH_COMPENSATION 0
#define X_BACKLASH 0
#define Y_BACKLASH 0
#define Z_BACKLASH 0
#define RAMP_ACCELERATION 1
#define STEPPER_HIGH_DELAY 0
#define DIRECTION_DELAY 0
#define STEP_DOUBLER_FREQUENCY 12000
#define ALLOW_QUADSTEPPING 1
#define DOUBLE_STEP_DELAY 1 // time in microseconds
#define MAX_HALFSTEP_INTERVAL 1999
#define MAX_ACCELERATION_UNITS_PER_SQ_SECOND_X 250
#define MAX_ACCELERATION_UNITS_PER_SQ_SECOND_Y 250
#define MAX_ACCELERATION_UNITS_PER_SQ_SECOND_Z 250
#define MAX_TRAVEL_ACCELERATION_UNITS_PER_SQ_SECOND_X 400
#define MAX_TRAVEL_ACCELERATION_UNITS_PER_SQ_SECOND_Y 400
#define MAX_TRAVEL_ACCELERATION_UNITS_PER_SQ_SECOND_Z 400
#define MAX_JERK 12
#define MAX_ZJERK 12
#define PRINTLINE_CACHE_SIZE 16
#define MOVE_CACHE_LOW 10
#define LOW_TICKS_PER_MOVE 250000
#define FEATURE_TWO_XSTEPPER 0
#define X2_STEP_PIN   ORIG_E1_STEP_PIN
#define X2_DIR_PIN    ORIG_E1_DIR_PIN
#define X2_ENABLE_PIN ORIG_E1_ENABLE_PIN
#define FEATURE_TWO_YSTEPPER 0
#define Y2_STEP_PIN   ORIG_E1_STEP_PIN
#define Y2_DIR_PIN    ORIG_E1_DIR_PIN
#define Y2_ENABLE_PIN ORIG_E1_ENABLE_PIN
#define FEATURE_TWO_ZSTEPPER 0
#define Z2_STEP_PIN   ORIG_E1_STEP_PIN
#define Z2_DIR_PIN    ORIG_E1_DIR_PIN
#define Z2_ENABLE_PIN ORIG_E1_ENABLE_PIN
#define FEATURE_DITTO_PRINTING 0
#define USE_ADVANCE 1
#define ENABLE_QUADRATIC_ADVANCE 0


// ################# Misc. settings ##################

#if PRINTER == 4
#define BAUDRATE 115200
#else
#define BAUDRATE 250000
#endif
#define ENABLE_POWER_ON_STARTUP 1
#define POWER_INVERTING 0
#define KILL_METHOD 1
#define GCODE_BUFFER_SIZE 2
#define ACK_WITH_LINENUMBER 1  // will set to 0 when done debugging
#define WAITING_IDENTIFIER "wait"
#define ECHO_ON_EXECUTE 1
#define EEPROM_MODE 1
#define PS_ON_PIN -1

/* ======== Servos =======
Control the servos with
M340 P<servoId> S<pulseInUS>   / ServoID = 0..3  pulseInUs = 500..2500
Servos are controlled by a pulse width normally between 500 and 2500 with 1500ms in center position. 0 turns servo off.
WARNING: Servos can draw a considerable amount of current. Make sure your system can handle this or you may risk your hardware!
*/
#define FEATURE_SERVO 0
#define SERVO0_PIN 11
#define SERVO1_PIN -1
#define SERVO2_PIN -1
#define SERVO3_PIN -1
#define FEATURE_WATCHDOG 1

/* #################### Z-Probe configuration and Settings #####################
   These will change machine to machine, be sure to have the correct machine selected in the top of this config file
*/

#if PRINTER == 1  //  Orion Delta w/ molded carriages and ball cup arms
#define FEATURE_Z_PROBE 1
#define Z_PROBE_SENSITIVITY  25 // 0-126 7 bit value  
#define Z_PROBE_BED_DISTANCE 20
#define Z_PROBE_PIN 16 // mini-rambo ext pins on P3 ext next to LCD header
#define Z_PROBE_PULLUP 1 //0
#define Z_PROBE_ON_HIGH 0 //1
#define Z_PROBE_X_OFFSET 0
#define Z_PROBE_Y_OFFSET 0
#define Z_PROBE_WAIT_BEFORE_TEST 0
#define Z_PROBE_SPEED 90
#define Z_PROBE_XY_SPEED 50
#define Z_PROBE_SWITCHING_DISTANCE 10
#define Z_PROBE_REPETITIONS 1
#define Z_PROBE_HEIGHT -.2
#define Z_PROBE_START_SCRIPT "G28/nG1Z25/n"
//#define Z_PROBE_START_SCRIPT "M117 Probe Started/n"
#define Z_PROBE_FINISHED_SCRIPT ""
#define FEATURE_AUTOLEVEL 1

#elif PRINTER == 2  // Rostock MAX w/ molded carriages and ball cup arms
#define FEATURE_Z_PROBE 1
#define Z_PROBE_SENSITIVITY  25 // 0-126 7 bit value  
#define Z_PROBE_BED_DISTANCE 20
#define Z_PROBE_PIN 16 // mini-rambo ext pins on P3 ext next to LCD header
#define Z_PROBE_PULLUP 1 //0
#define Z_PROBE_ON_HIGH 0 //1
#define Z_PROBE_X_OFFSET 0
#define Z_PROBE_Y_OFFSET 0
#define Z_PROBE_WAIT_BEFORE_TEST 0
#define Z_PROBE_SPEED 90
#define Z_PROBE_XY_SPEED 50
#define Z_PROBE_SWITCHING_DISTANCE 10
#define Z_PROBE_REPETITIONS 1
#define Z_PROBE_HEIGHT -.2
#define Z_PROBE_START_SCRIPT "G28/nG1Z25/n"
//#define Z_PROBE_START_SCRIPT "M117 Probe Started/n"
#define Z_PROBE_FINISHED_SCRIPT ""
#define FEATURE_AUTOLEVEL 1

#elif PRINTER == 3  // ERIS Delta
#define FEATURE_Z_PROBE 1
#define Z_PROBE_SENSITIVITY  25 // 0-126 7 bit value  
#define Z_PROBE_BED_DISTANCE 20
#define Z_PROBE_PIN 16 // mini-rambo ext pins on P3 ext next to LCD header
#define Z_PROBE_PULLUP 1 //0
#define Z_PROBE_ON_HIGH 0 //1
#define Z_PROBE_X_OFFSET 0
#define Z_PROBE_Y_OFFSET 0
#define Z_PROBE_WAIT_BEFORE_TEST 0
#define Z_PROBE_SPEED 90
#define Z_PROBE_XY_SPEED 50
#define Z_PROBE_SWITCHING_DISTANCE 10
#define Z_PROBE_REPETITIONS 1
#define Z_PROBE_HEIGHT -.2
#define Z_PROBE_START_SCRIPT "G28/nG1Z25/n"
//#define Z_PROBE_START_SCRIPT "M117 Probe Started/n"
#define Z_PROBE_FINISHED_SCRIPT ""
#define FEATURE_AUTOLEVEL 1

#endif

// ##############  Z Probe X/Y coordinates for endstop offsets and radius comp uses the Z_PROBE_Y3 coordinate ############

#if PRINTER == 1  // Orion Delta with molded carriages AND ball cup arms - needs finished
#define Z_PROBE_X1 -64.778
#define Z_PROBE_Y1 -37.400
#define Z_PROBE_X2 64.778
#define Z_PROBE_Y2 -37.400
#define Z_PROBE_X3 0
#define Z_PROBE_Y3 74.800

#elif PRINTER == 2  //  Rostock MAX with modled carriagges AND ball cup arms
#define Z_PROBE_X1 -123.565
#define Z_PROBE_Y1 -71.34
#define Z_PROBE_X2 123.565
#define Z_PROBE_Y2 -71.340
#define Z_PROBE_X3 0
#define Z_PROBE_Y3 142.68

#elif PRINTER == 3  //  ERIS Delta
#define Z_PROBE_X1 -54 
#define Z_PROBE_Y1 -31 
#define Z_PROBE_X2  54 
#define Z_PROBE_Y2 -31 
#define Z_PROBE_X3   0
#define Z_PROBE_Y3  65 

#endif


#define FEATURE_AXISCOMP 0
#define AXISCOMP_TANXY 0
#define AXISCOMP_TANYZ 0
#define AXISCOMP_TANXZ 0

// ##############  SD Card Settings  #########################


#ifndef SDSUPPORT 
#if PRINTER == 1 || PRINTER == 2
#define SDSUPPORT 1
#else
#define SDSUPPORT 0
#endif
#define SDCARDDETECT 81
#define SDCARDDETECTINVERTED 0
#endif

#define SD_EXTENDED_DIR 1 /** Show extended directory including file length. Don't use this with Pronterface! */
#define SD_RUN_ON_STOP ""
#define SD_STOP_HEATER_AND_MOTORS_ON_STOP 1
#define ARC_SUPPORT 0
#define FEATURE_MEMORY_POSITION 1
#define FEATURE_CHECKSUM_FORCED 0
#define FEATURE_FAN_CONTROL 1
#if PRINTER == 1 || PRINTER == 2
#define FEATURE_CONTROLLER 13
#else
#define FEATURE_CONTROLLER 0
#endif
#define UI_LANGUAGE 1000 // 1000 = User defined language in v92+
#if PRINTER == 1
#define UI_PRINTER_NAME "ORION Delta"
#define UI_PRINTER_COMPANY "SeeMeCNC"
#elif PRINTER == 2
#define UI_PRINTER_NAME "Rostock Max"
#define UI_PRINTER_COMPANY "SeeMeCNC"
#elif PRINTER == 3
#define UI_PRINTER_NAME "ERIS Delta"
#define UI_PRINTER_COMPANY "SeeMeCNC"
#endif
#define UI_PAGES_DURATION 4000
#define UI_ANIMATION 0
#define UI_SPEEDDEPENDENT_POSITIONING 1
#define UI_DISABLE_AUTO_PAGESWITCH 1
#define UI_AUTORETURN_TO_MENU_AFTER 600000
#define FEATURE_UI_KEYS 0
#define UI_ENCODER_SPEED 2
#define UI_KEY_BOUNCETIME 10
#define UI_KEY_FIRST_REPEAT 500
#define UI_KEY_REDUCE_REPEAT 50
#define UI_KEY_MIN_REPEAT 50
#define FEATURE_BEEPER 1
#define CASE_LIGHTS_PIN -1
#define CASE_LIGHT_DEFAULT_ON 1
#define UI_START_SCREEN_DELAY 1000
/**
Beeper sound definitions for short beeps during key actions
and longer beeps for important actions.
Parameter is delay in microseconds and the secons is the number of repetitions.
Values must be in range 1..255
*/
#define BEEPER_SHORT_SEQUENCE 1,1
#define BEEPER_LONG_SEQUENCE 32,4
#define UI_SET_PRESET_HEATED_BED_TEMP_PLA 60
#define UI_SET_PRESET_EXTRUDER_TEMP_PLA   180
#define UI_SET_PRESET_HEATED_BED_TEMP_ABS 100
#define UI_SET_PRESET_EXTRUDER_TEMP_ABS   200
#define UI_SET_MIN_HEATED_BED_TEMP  30
#define UI_SET_MAX_HEATED_BED_TEMP 120
#define UI_SET_MIN_EXTRUDER_TEMP   150
#define UI_SET_MAX_EXTRUDER_TEMP   240
#define UI_SET_EXTRUDER_FEEDRATE 2
#define UI_SET_EXTRUDER_RETRACT_DISTANCE 3

#endif
