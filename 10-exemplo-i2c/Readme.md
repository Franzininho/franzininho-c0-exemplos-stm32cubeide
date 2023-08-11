## Exemplo I2C 
  
Realiza leitura de temperatura e umidade relativa com o sensor HTU21D.
O PWM foi conifgurado com frequência 1 kHz e largura de pulso de 0 a 1000.  

Foram configurados os seguintes periféricos:  
- GPIO:
	- PB6 - Output (LED1);
	- PB7 - I2C1 SCL;
	- PC14 - I2C1 SDA
- I2C:
	- I2C1 - 400 kHz
- USART1:
	- PA9 - TX;
	- PA10 - RX 
- Clock do sistema: interno 48 MHz  
  
## Software  
  
STM32CubeIDE Version: 1.13.0

## Teste  
  
![Franzininho C0 - Exemplo I2C](./img/board.jpg)  
  
![Envio de dados pela UART](./img/console.png)  
  
![Falha na comunicação com o sensor](./img/console_error.png)  