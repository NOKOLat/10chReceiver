/*
 * user.h
 *
 *  Created on: Aug 16, 2024
 *      Author: ohya
 */

#ifndef INC_USER_H_
#define INC_USER_H_

#include "gpio.h"
#include <array>

#include "SBUS/sbus.h"

#define PB7 GPIOB, GPIO_PIN_7
#define PC14 GPIOC, GPIO_PIN_14

extern uint16_t adcValue;

inline std::array<uint16_t,10> mixer(nokolat::SBUS_DATA &input){
	const uint8_t ADC_THRESHOLD = 100;
	const uint16_t AUTO_PERMISSION_THRESHOLD = 1500;
	static std::array<uint16_t,10> res;
	auto it_res = res.begin();

	*it_res++ = input.at(0);
	*it_res++ = input.at(1);
	*it_res++ = input.at(2);
	*it_res++ = input.at(3);
	*it_res++ = input.at(4);
	*it_res++ = input.at(5);
	if(adcValue < ADC_THRESHOLD && input.at(5) > AUTO_PERMISSION_THRESHOLD){
		*it_res++ = input.at(6);
	}else{
		it_res++;
	}
	*it_res++ = input.at(7);
	*it_res++ = input.at(8);
	*it_res++ = input.at(9);

	return res;
}

void failsafe();

#endif /* INC_USER_H_ */
