 GPIO_InitTypeDef GPIO_InitStruct = {0};
/* MCU Configuration----------------------------------------------------------*/
/* Reset of all peripherals, Initializes the Flash interface and the Systick. */ 
 HAL_Init();
 /* Configure the system clock */ 
 SystemClock_Config();

 /* GPIOA and GPIOC Configuration----------------------------------------------*/
 /* GPIO Ports Clock Enable */ 
 __HAL_RCC_GPIOC_CLK_ENABLE(); 
 __HAL_RCC_GPIOA_CLK_ENABLE();

 /*Configure GPIO pin : PC13 */
 GPIO_InitStruct.Pin = GPIO_PIN_12 | GPIO_PIN_13; 
 GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
 GPIO_InitStruct.Pull = GPIO_PULLDOWN;
 HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

 /*Configure GPIO pin : PA5 */
 GPIO_InitStruct.Pin = GPIO_PIN_5;
 GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; 
 GPIO_InitStruct.Pull = GPIO_NOPULL;
 GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW; 
 HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

 /* Configure GPIO pin Output Level */
 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);

 /* EXTI interrupt init*/
 HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

 while (1);
 }

 void EXTI15_10_IRQHandler(void) {
 HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_12); 
 HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13); 
 }

 void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) { 
 if(GPIO_Pin == GPIO_PIN_13)
 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, SET); 
 else if(GPIO_Pin == GPIO_PIN_12)
 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, RESET); 
 }
