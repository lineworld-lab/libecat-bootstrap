
#ifndef _ECAT_V2_OD_H_
#define _ECAT_V2_OD_H_

// 0x1601: RxPDO Mapping (Profile Position Mode)
#define OD_RXPDO_ASSIGN 0x1C12
#define OD_RXPDO_MAP_1 0x1601
#define OD_CONTROL_WORD 0x6040
// index(0x6040) + subindex(0x00) + data_size(0x10)
#define OD_CONTROL_WORD_MAPPING_CONTENT 0x60400010
#define OD_TARGET_POSITION 0x607A
#define OD_TARGET_POSITION_MAPPING_CONTENT 0x607A0020
#define OD_PROFILE_VELOCITY 0x6081
#define OD_PROFILE_VELOCITY_MAPPING_CONTENT 0x60810020
#define OD_PHYSICAL_OUTPUTS_1 0x60FE
#define OD_PHYSICAL_OUTPUTS_1_MAPPING_CONTENT 0x60FE0120
// 1: Profile Position Mode
// 6: Homing Mode
// 8: Cyclic Synchronous Position Mode
#define OD_MODE_OF_OPERATION 0x6060
#define OD_MODE_OF_OPERATION_MAPPING_CONTENT 0x60600008

// 0x1A01: TxPDO Mapping (Profile Position Mode)
#define OD_TXPDO_ASSIGN 0x1C13
#define OD_TXPDO_MAP_1 0x1A01
#define OD_STATUS_WORD 0x6041
#define OD_STATUS_WORD_MAPPING_CONTENT 0x60410010
#define OD_POSITION_ACTUAL_VALUE 0x6064
#define OD_POSITION_ACTUAL_VALUE_MAPPING_CONTENT 0x60640020
#define OD_VELOCITY_ACTUAL_VALUE 0x606C
#define OD_VELOCITY_ACTUAL_VALUE_MAPPING_CONTENT 0x606C0020
#define OD_DIGITAL_INPUTS 0x60FD
#define OD_DIGITAL_INPUTS_MAPPING_CONTENT 0x60FD0020
#define OD_ERROR_CODE 0x603F
#define OD_ERROR_CODE_MAPPING_CONTENT 0x603F0010
#define OD_MODE_OF_OPERATION_DISPLAY 0x6061
#define OD_MODE_OF_OPERATION_DISPLAY_MAPPING_CONTENT 0x60610008

// set 0b10000000 (80) to reverse motor direction
#define OD_POLARITY 0x607E
#define OD_MAX_PROFILE_VELOCITY 0x607F
#define OD_PROFILE_ACCERATION 0x6083
#define OD_PROFILE_DECELERATION 0x6084
#define OD_POSITION_DEMAND_VALUE 0x6062
#define OD_VELOCITY_DEMAND_VALUE 0x606B
#define OD_HOME_OFFSET 0x607C
#define OD_HOMING_METHOD 0X6098
// sub 01: Min Position Range Limit (I32)
// sub 02: Max Position Range Limit (I32)
#define OD_SOFTWARE_LIMIT 0x607D
// sub 0x01: speed during search for switch
// sub 0x02: speed during search for zero
#define OD_HOMING_SPEEDS 0x6099
#define OD_HOMING_ACCELERATION 0x609A

#define OD_DEVICE_NAME 0x1008
#define OD_HARDWARE_VERSION 0x1009
#define OD_SOFTWARE_VERSION 0x100A


// control word bits
#define BIT_CONTROL_WORD_SWITCH_ON 0
#define BIT_CONTROL_WORD_ENABLE_VOLTAGE 1
#define BIT_CONTROL_WORD_QUICK_STOP 2
#define BIT_CONTROL_WORD_ENABLE_OPERATION 3

#define BIT_CONTROL_WORD_PP_NEW_SET_POINT 4
#define BIT_CONTROL_WORD_PP_CHANGE_SET_IMMEDIATELY 5
#define BIT_CONTROL_WORD_PP_RELATIVE 6
#define BIT_CONTROL_WORD_FAULTRESET 7

#define BIT_STATUS_WORD_READY_TO_SWITCH_ON 0
#define BIT_STATUS_WORD_SWITCHED_ON 1
#define BIT_STATUS_WORD_OPERATION_ENABLED 2
#define BIT_STATUS_WORD_FAULT 3
#define BIT_STATUS_WORD_VOLTAGE_ENABLED 4
#define BIT_STATUS_WORD_QUICK_STOP 5
#define BIT_STATUS_WORD_SWITCH_ON_DISABLED 6
#define BIT_STATUS_WORD_PP_TARGET_REACHED 10
#define BIT_STATUS_WORD_PP_SETPOINT_ACKNOWLEDGE 12


#define MODE_PP 0x01

#define MODE_HM 0x06


/*xxxx xxxx xx10 1111*/

#define CONTROL_WORD_PP_NEW_SET 0x002F

/*xxxx xxxx xx11 1111*/

#define CONTROL_WORD_PP_CHANGE_SET 0x003F


/*xxxx xxxx xxx1 1111*/

#define CONTROL_WORD_HM_OP_START 0x001F


/*xxxx xxxx x0xx 0000*/
#define STATUS_WORD_NOT_READY_TO_SWITCH_ON 0x0
/*xxxx xxxx x1xx 0000*/
#define STATUS_WORD_SWITCH_ON_DISABLED (1 << 6)
/*xxxx xxxx x01x 0001*/
#define STATUS_WORD_READY_TO_SWITCH_ON ((1 << 5) | 1)
/*xxxx xxxx x01x 0011*/
#define STATUS_WORD_SWITCHED_ON ((1 << 5) | (1 << 4) | 3)
/*xxxx xxxx x01x 0111*/
#define STATUS_WORD_OPERATION_ENABLED ((1 << 5) | (1 << 4) | 7)
/*xxxx xxxx x00x 0111*/
#define STATUS_WORD_QUICK_STOP_ACTIVE 0x7
/*xxxx xxxx x0xx 1111*/
#define STATUS_WORD_FAULT_REACTION_ACTIVE 0xf
/*xxxx xxxx x0xx 1000*/
#define STATUS_WORD_FAULT 0x8

// Bit13 Bit12 Bit10
//   x     x     0   -> Homing is ongoing
//   0     0     1   -> Homing is canceled or not started
//   0     1     1   -> Homing is finished successfully
//   1     0     1   -> Homing failed
#define BIT_STATUS_WORD_HM_HOMING_ERROR 13
#define BIT_STATUS_WORD_HM_HOMING_ATTAINED 12
#define BIT_STATUS_WORD_HM_TARGET_REACHED 10







#endif