/*
 * dartt_map.h
 *
 *  Created on: Sep 27, 2026
 *      Author: redux
 */

#ifndef DARTT_MAP_H_
#define DARTT_MAP_H_
#include <stdint.h>
#include "dartt.h"

typedef struct ctl_fds_t
{
	uint32_t config_addr;	//primary configuration address of the doomba controller

	uint32_t uart1_lo;
	uint32_t uart1_hi;

	uint32_t uart3_lo;
	uint32_t uart3_hi;

}ctl_fds_t;

typedef struct controller_regmap_t
{
	ctl_fds_t fds;
	uint32_t action_register;
	uint32_t load_action;	//single bit, when set the action queued in action_register is executed
	uint32_t led_state;
	uint32_t wifi_passthrough_en;
}controller_regmap_t;

extern ctl_fds_t default_fds;
extern dartt_mem_t gl_dp_alias;

#endif /* DARTT_MAP_H_ */
