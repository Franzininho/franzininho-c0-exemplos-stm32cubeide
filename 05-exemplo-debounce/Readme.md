## Exemplo Debounce  
  
Alterna o estado do LED2(PB1) quando o botão estiver pressionado. Além disso, pisca brevemente o LED1(PB6) e envia uma mensagem pela UART quando uma borda de subida ou descida é detectada.  
Este exemplo utiliza interrupção externa para detecção do botão e interrupção de timer para geração de base de tempo para algoritmo de debounce (periódico, sem travamento).    

Foram configurados os seguintes periféricos:  
- GPIO:
	- PA8 - Interrupção externa, pull up interno (Botão);  
	- PB6 - Output (LED1);
	- PB7 - Output (LED2)
- TIMER:
	- TIM17 - Interrupção a cada 1ms  
- USART:
	- PA9 - USART1 TX;
	- PA10 - USART1 RX
- Clock do sistema: interno 48 MHz  
  
## Software  
  
STM32CubeIDE Version: 1.13.0

## Teste  
  
![Franzininho C0 - Exemplo ADC](./img/board.gif)  
  
![Leituras no console via UART](./img/console.jpg)  