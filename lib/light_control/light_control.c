#include "light_control.h"


ledc_timer_config_t ledc_timer = {
    .duty_resolution = LEDC_TIMER_13_BIT, // resolution of PWM duty
    .freq_hz = 5000,                      // frequency of PWM signal
    .speed_mode = LEDC_HS_MODE,           // timer mode
    .timer_num = LEDC_HS_TIMER,            // timer index
    .clk_cfg = LEDC_AUTO_CLK,              // Auto select the source clock
};

ledc_channel_config_t ledc_channel[LEDC_CH_NUM] = {
    {
        .channel    = LEDC_HS_CH0_CHANNEL,
        .duty       = 0,
        .gpio_num   = LEDC_HS_CH0_GPIO,
        .speed_mode = LEDC_HS_MODE,
        .hpoint     = 0,
        .timer_sel  = LEDC_HS_TIMER
    }
};

int ch;
esp_err_t err;

void ledc_init(void) {
    ledc_timer_config(&ledc_timer);
    // Set LED Controller with previously prepared configuration
    for (ch = 0; ch < LEDC_CH_NUM; ch++) {
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

void ledc_control(uint32_t light_duty) {
    ESP_LOGI(LEDC_TAG, "LEDC fade update to duty = %d\n", light_duty);
    for (ch = 0; ch < LEDC_CH_NUM; ch++) {
        err = ledc_set_fade_with_time(ledc_channel[ch].speed_mode,
                ledc_channel[ch].channel, light_duty, LEDC_FADE_TIME);
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