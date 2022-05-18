#ifndef _LIGHT_CONTROL_H_
#define _LIGHT_CONTROL_H_

#include "common.h"
#include "driver/ledc.h"

#define LEDC_HS_TIMER          LEDC_TIMER_0
#define LEDC_HS_MODE           LEDC_HIGH_SPEED_MODE
#define LEDC_HS_CH0_GPIO       GPIO_NUM_2
#define LEDC_HS_CH0_CHANNEL    LEDC_CHANNEL_0

#define LEDC_CH_NUM            (1)
#define LEDC_FADE_TIME         (1000)

#define LEDC_TAG               "LEDC"     

void ledc_init(void);
void ledc_control(uint32_t light_duty);

#endif