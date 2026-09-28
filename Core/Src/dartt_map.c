/*
 * dartt_map.c
 *
 *  Created on: Sep 27, 2026
 *      Author: redux
 */
#include "dartt_map.h"
#include "dartt.h"

ctl_fds_t default_fds = {
		.config_addr = 0,
		.uart1_lo = 1,
		.uart1_hi = MASTER_MOTOR_ADDRESS-1,
		.uart3_lo = 0,	//disable uart3 routing by default
		.uart3_hi = 0
};

controller_regmap_t gl_dp = {
		.fds = {},	//defaults handled elsewhere
		.led_state = 1,
		.load_action = 0,
		.action_register = 0
};

dartt_mem_t gl_dp_alias = {.buf = (unsigned char *)(&gl_dp), .size = sizeof(gl_dp)};
