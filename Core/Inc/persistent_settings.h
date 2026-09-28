/*
 * persistent_settings.h
 *
 *  Created on: Sep 27, 2026
 *      Author: redux
 */

#ifndef INC_PERSISTENT_SETTINGS_H_
#define INC_PERSISTENT_SETTINGS_H_

uint32_t write_flash(void * data, size_t num_bytes);
void load_flash_params(void);

#endif /* INC_PERSISTENT_SETTINGS_H_ */
