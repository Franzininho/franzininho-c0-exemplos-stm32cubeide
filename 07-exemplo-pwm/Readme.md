## Exemplo PWM  
  
Realiza acionamento dos LEDs com PWM, alternando gradualmente o brilho.  
O PWM foi conifgurado com frequência 1 kHz e largura de pulso de 0 a 1000.  

Foram configurados os seguintes periféricos:  
- GPIO:
	- PB6 - Timer 1 Canal 3 (LED1)
	- PB7 - Timer 1 Canal 3 (LED1)
- TIMER:
	- TIM1 - Geração de PWM (1 kHz, PW 0 a 1000)
- Clock do sistema: interno 48 MHz  
  
## Software  
  
STM32CubeIDE Version: 1.13.0

## Teste  
  
![Franzininho C0 - Exemplo PWM](./img/board.gif)  
  
![Leitura no osciloscópio](./img/scope.gif)  