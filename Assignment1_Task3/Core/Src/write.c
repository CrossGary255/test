#include "main.h"
#include "tim.h"
#include "gpio.h"

volatile uint32_t g_ms;

int main(void)
{
  SystemClock_Config();
  MX_GPIO_Init();
  MX_TIM2_Init();

  HAL_TIM_Base_Start_IT(&htim2);

  while (1)
  {
    
  }
}
  


//4

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if(GPIO_Pin!=KEY_Pin)return;

    uint32_t now=g_ms;

    static uint32_t pre=0;

    if(now-pre>20){
      HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
      
    }
    pre=now;
    return;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
    if(htim->Instance==TIM2){
      g_ms++;
    }
}
