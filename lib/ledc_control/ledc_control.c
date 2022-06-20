#include "ledc_control.h"


ledc_timer_config_t ledc_timer = {
    .duty_resolution = LEDC_DUTY_RESOLUTION, // resolution of PWM duty
    .freq_hz = 5000,                         // frequency of PWM signal
    .speed_mode = LEDC_HS_MODE,              // timer mode
    .timer_num = LEDC_HS_TIMER,              // timer index
    .clk_cfg = LEDC_AUTO_CLK,                // Auto select the source clock
};

ledc_channel_config_t ledc_channel[LEDC_CH_NUM] = {
    {
        .channel    = LEDC_HS_CH0_CHANNEL,
        .duty       = 0,
        .gpio_num   = LEDC_WARM_CH0_GPIO,
        .speed_mode = LEDC_HS_MODE,
        .hpoint     = 0,
        .timer_sel  = LEDC_HS_TIMER
    },
    {
        .channel    = LEDC_HS_CH1_CHANNEL,
        .duty       = 0,
        .gpio_num   = LEDC_COLD_CH1_GPIO,
        .speed_mode = LEDC_HS_MODE,
        .hpoint     = 0,
        .timer_sel  = LEDC_HS_TIMER
    }
};

esp_err_t err;

void ledc_init(void) {
    ledc_timer_config(&ledc_timer);
    // Set LED Controller with previously prepared configuration
    for (int ch = 0; ch < LEDC_CH_NUM; ch++) {
        err = ledc_channel_config(&ledc_channel[ch]);
        if (err) {
            ESP_LOGE(LEDC_TAG, "%s ledc config channel failed: %s\n", __func__, esp_err_to_name(err));
        }
    }
    // Initialize fade service.
    err = ledc_fade_func_install(0);
    if (err) {
        ESP_LOGE(LEDC_TAG, "%s ledc fade func install failed: %s\n", __func__, esp_err_to_name(err));
    }
}

void ledc_fade_control(uint32_t warm_duty, uint32_t cold_duty) {
    uint32_t arr_dutys[2] = {warm_duty, cold_duty};
    for (int ch = 0; ch < LEDC_CH_NUM; ch++) {
        err = ledc_set_fade_with_time(ledc_channel[ch].speed_mode,
                ledc_channel[ch].channel, arr_dutys[ch], LEDC_FADE_TIME);
        if (err) {
            ESP_LOGE(LEDC_TAG, "%s ledc set fade with time failed: %s\n", __func__, esp_err_to_name(err));
        }
        err = ledc_fade_start(ledc_channel[ch].speed_mode,
                ledc_channel[ch].channel, LEDC_FADE_NO_WAIT);
        if (err) {
            ESP_LOGE(LEDC_TAG, "%s ledc fade start failed: %s\n", __func__, esp_err_to_name(err));
        }
    }
    vTaskDelay(LEDC_FADE_TIME / portTICK_PERIOD_MS);
}

void ledc_set_brightness(int brightness, light_mode_t *light_mode) {
    light_mode->light_brightness = brightness;
}

void ledc_set_color(uint32_t color_temperature, light_mode_t *light_mode) {
    light_mode->color_temperature = color_temperature;
    float coeff_brightnes = (float)light_mode->light_brightness / 100;
    
    ESP_LOGI("TEST_IN", "warm: %f", coeff_brightnes);

    light_mode->light_warm_duty = (int)(coeff_brightnes * ((LEDC_COLOR_TEMP_MAX - color_temperature) * (1 << LEDC_DUTY_RESOLUTION)
                                    / (LEDC_COLOR_TEMP_MAX - LEDC_COLOR_TEMP_MIN)));
    
    light_mode->light_cold_duty = (int)(coeff_brightnes * ((color_temperature - LEDC_COLOR_TEMP_MIN) * (1 << LEDC_DUTY_RESOLUTION)
                                    / (LEDC_COLOR_TEMP_MAX - LEDC_COLOR_TEMP_MIN)));
}