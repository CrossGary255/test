#include "main.h"
#include "tim.h"
#include "gpio.h"

volatile uint32_t g_ms = 0; 



int main(void)
{
  SystemClock_Config();
  MX_GPIO_Init();
  MX_TIM2_Init();
  while (1)
  {
    uint32_t pre = 0;
    if(g_ms-pre>=250){
        pre+=250;
        HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
    }
  }
  
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
    if(htim->Instance==TIM2){
      g_ms++;
    }