/*******************************************************************************
 *   @file   main.h
 *   @brief  Header file of main.
 *   @author hylics
********************************************************************************/

#ifndef __MAIN_H__
#define __MAIN_H__

#define PID_MAX_FLT 6000.0f
#define PID_MIN_FLT +0.0f
//calculate crc32 of options structure without crc word
#define OPT_CRC_LEN (uint32_t)(sizeof(SavedDomain_t)/sizeof(uint32_t) - 1)
#define N_FUNC_PWR 3 //number of realisations functions setting power

#define ARM_MATH_CM0
#include "float.h"
//#include "fenv.h"
#include "soft_spi.h"
#include "eeprom.h"
#include "adi.h"
#include "arm_math.h"
#include "rtd_linearization.h"
#include "ct_assert.h"


typedef struct __Temperature_t {
	float32_t rtd;
	float32_t thermocouple;
	float32_t setpoint;
}Temperature_t;

//extern HAL_StatusTypeDef out_pwm_jitter(float32_t pwr);
//extern HAL_StatusTypeDef out_pwm_simple(float32_t pwr);
//extern HAL_StatusTypeDef out_pwm_bresenham(float32_t pwr);

//HAL_StatusTypeDef (*pf_output[N_FUNC_PWR])(float32_t pwr) = {out_pwm_jitter, out_pwm_simple, out_pwm_bresenham};
extern HAL_StatusTypeDef (*pf_output[N_FUNC_PWR])(float32_t pwr);

#endif	// __MAIN_H__

