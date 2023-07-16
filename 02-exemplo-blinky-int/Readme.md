## Exemplo Blinky Int

Esse é um exemplo básico para um projeto com a placa Franzininho C0- Foram configurados os seguintes periféricos:
GPIO: 	PB6 - OUTPUT (LED1)
TIMER: 	Timer 17

Clock do sistema: interno 48 MHz

Aplicação exemplo:

Pisca o LED1 duas vezes por segundo, usando interrupção para temporizar as trocas de estado do LED

Cálculo do timer para gerar a interrupção a cada 0,25s (250ms):

Intervalo = Contador * Prescaler / Master Clock
Master Clock: 48 MHz = 48.000.000 Hz
Prescaler: 	48.000
Contador: 	   250


## Software

STM32CubeIDE Version: 1.13.0