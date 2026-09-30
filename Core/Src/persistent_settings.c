/*
 * persistent_settings.c
 *
 *  Created on: Sep 27, 2026
 *      Author: ocanath
 */
#include "fds.h"
#include "dartt_map.h"
#include <string.h>
/*
 * Write flash helper function that pads alignment with a stack buffer
 */
#define FDS_WRITE_PAD_SIZE (sizeof(ctl_fds_t)+(sizeof(ctl_fds_t) % sizeof(uint64_t)))

unsigned char gl_misc_address = 0xFF;

uint32_t write_flash(void * data, size_t num_bytes)
{
	uint64_t scratch_buffer[FDS_WRITE_PAD_SIZE/sizeof(uint64_t)] = {0};
	if(num_bytes > sizeof(scratch_buffer))
	{
		return 0xFFFFFFFF;	//too large for the scratch buffer - refuse rather than overrun
	}
	memcpy(scratch_buffer, data, num_bytes);
	return m_write_flash((uint64_t*)scratch_buffer, sizeof(scratch_buffer)/sizeof(uint64_t));
}

void load_flash_params(void)
{
	//loading
	if(is_page_empty(sizeof(controller_regmap_t)/sizeof(uint32_t)) == 0)
	{
		m_read_flash((uint32_t*)(&gl_dp.fds), sizeof(ctl_fds_t)/sizeof(uint32_t));
	}
	else
	{
		write_flash(&default_fds, sizeof(ctl_fds_t));
		memcpy(&gl_dp.fds, &default_fds, sizeof(ctl_fds_t));
	}
	gl_misc_address = dartt_get_complementary_address((unsigned char)(gl_dp.fds.config_addr & 0xFF));
}

