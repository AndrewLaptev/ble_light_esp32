#ifndef _LEDC_CONTROL_H_
#define _LEDC_CONTROL_H_

#include "common.h"
#include "driver/ledc.h"

/*
 * True values: from 2700 to 6500 kelvins
 * But in real this values may be incorrect.
 * Because the voltage on the lamps may not 
 * be enough for normal light. 
 * There may be flickering and fading
*/

#define LEDC_HS_TIMER            LEDC_TIMER_0
#define LEDC_HS_MODE             LEDC_HIGH_SPEED_MODE
#define LEDC_WARM_CH0_GPIO       GPIO_NUM_22
#define LEDC_COLD_CH1_GPIO       GPIO_NUM_23
#define LEDC_HS_CH0_CHANNEL      LEDC_CHANNEL_0
#define LEDC_HS_CH1_CHANNEL      LEDC_CHANNEL_1
#define LEDC_DUTY_RESOLUTION     LEDC_TIMER_13_BIT

#define LEDC_CH_NUM              (2)
#define LEDC_FADE_TIME           (1000)

#define LEDC_TAG                 "LEDC"

typedef struct {
    uint32_t light_warm_duty;
    uint32_t light_cold_duty;
    int light_brightness;       // 0 to 100
    int color_temperature;
} light_mode_t;

/**
 * Init ledc driver
 */
void ledc_init(void);

/**
 * Smooth adjustment of two light channels
 */
void ledc_fade_control(uint32_t warm_duty, uint32_t cold_duty);

/**
 * Set brightness
 */
void ledc_set_brightness(int brightness, light_mode_t *light_mode);

/**
 * Set color from temp and brightness
 */
void ledc_set_color(uint32_t color_temperature, light_mode_t *light_mode);

#endif