## Exemplo ADC  
  
Realiza conversões analógico-digitais nos canais 0 (PA0) e 1 (PA1) do ADC1, utilizando DMA e base de tempo por timer.  
O timer TIM3 está configurado para geração de evento quando totaliza a contagem, e este evento inicia o conjunto de conversões A/D.  
As leituras são convertidas para tensão e enviadas pela serial periodicamente.  
O estado do LED1 (PB6) é alternado toda vez que um conjunto de conversões é finalizado.  
Além disso, o exemplo alterna o estado do LED2 (PB1) quando a tensão no canal 1 do ADC é maior que 1.5V.  

Foram configurados os seguintes periféricos:  
- GPIO:
	- PB6 - Output (LED1);
	- PB7 - Output (LED2)
- TIMER:
	- TIM3 - Geração de evento a cada 100 ms  
- USART:
	- PA9 - USART1 TX;
	- PA10 - USART1 RX
- ADC (12 bits, gatilho por evento do TIM3, DMA): 
	- PA0 - Canal 0;
	- PA1 - Canal 1
- Clock do sistema: interno 48 MHz  
  
## Software  
  
STM32CubeIDE Version: 1.13.0