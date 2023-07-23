## Exemplo Blinky Int  

Pisca o LED1(PB6) duas vezes por segundo, usando interrupção do timer para temporizar as trocas de estado do LED.  

Foram configurados os seguintes periféricos:  

- GPIO:  PB6 - OUTPUT (LED1)  
- TIMER:  Timer 17
- Clock do sistema: interno 48 MHz  
  
Cálculo do timer para gerar a interrupção a cada 0,25s (250ms):  

- Intervalo = Contador * Prescaler / Master Clock  
- Master Clock: 48 MHz = 48.000.000 Hz  
- Prescaler: 48.000  
- Contador: 250  

## Software  
  
STM32CubeIDE Version: 1.13.0
