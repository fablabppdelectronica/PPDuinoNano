# MÓDULO EDUCATIVO: PPDuino Nano
## Presentación
Los módulos educativos son una herramienta invaluable para los estudiantes, que les permite aprender de forma tangible y efectiva los conocimientos de cada Unidad Didáctica.

El presente proyecto es una iniciativa innovadora que busca desarrollar un **módulo educativo de codigo abierto** que permitirá realizar los laboratorios de multiples unidades d

idáctica, que lo puedan fabricar los docentes o estudiantes y que permita trabajar con:
- Electrónica Analógica
- Electrónica Digital
- Electrónica Potencia
- Programación Embebida
- Redes
- Telecomunicaciones, entre otras.

El proyecto esta desarrollado por los docentes y estudiantes del Programa de Electronica Industrial.
## Proyecto PPDuino
Para esta primera etapa e inspirados por dispositivos PLCs como el S7-1200 y Logo de Siemens, el objetivo es disenar y fabricar un módulo educativo tipo PLC.

Se trabajara en 3 areas:
- Diseño Electronico.
- Diseño 2D y 3D.
- Programación.

Mostramos el bosquejo proyectado. 
<div><p style = 'text-align:center;'><img src="/files/img/0.jpg" alt="JuveYell" width="300px"></p></div>
Para conseguir el Producto Mínimo Viable, se siguieron la secuencia que se muestra en la imagen:
<div><p style = 'text-align:center;'><img src="/files/img/All.png" alt="JuveYell" width="700px"></p></div>

## Diseño Electrónico
### Tarjeta de procesador
Para el desarrollo de la tarjeta del procesador, se trabajo con la tarjeta Arduino Nano por su gran comunidad, facilidad de adquisión local y costo accesible.

#### Lista de componentes
<table><tr><th>Reference</th><td>Value</td><td>Footprint</td><td>Qty</td></tr><tr><th>A1</th><td>Arduino Nano</td><td>Module:Arduino_Nano</td><td>1</td></tr><tr><th>C1</th><td>100uF</td><td>Capacitor_THT:CP_Radial_D5.0mm_P2.50mm</td><td>1</td></tr><tr><th>C2</th><td>10uF</td><td>Capacitor_THT:CP_Radial_D5.0mm_P2.50mm</td><td>1</td></tr><tr><th>J1</th><td>PWR_IN</td><td>Borneras:TerminalBlock_Altech_AK300-2_P5.00mm</td><td>1</td></tr><tr><th>J2</th><td>Conn_01x12</td><td>Connector_PinSocket_2.54mm:PinSocket_1x12_P2.54mm_Horizontal</td><td>1</td></tr><tr><th>J11</th><td>INPUTS</td><td>Connector_PinSocket_2.54mm:PinSocket_1x10_P2.54mm_Vertical</td><td>1</td></tr><tr><th>J12</th><td>OUTPUTS</td><td>Connector_PinHeader_2.54mm:PinHeader_1x10_P2.54mm_Vertical</td><td>1</td></tr><tr><th>U1</th><td>L7805</td><td>Package_TO_SOT_THT:TO-220-3_Horizontal_TabDown</td><td>1</td></tr><tr><th>U6</th><td>+5V</td><td>Codigo_lib:Mini 560 Pro</td><td>1</td></tr></table>

#### Esquematico de procesador
<div><p style = 'text-align:center;'><img src="/PPDuino_Nano_Electronic\V0.2\Procesador\PPDuino Nano Procesador SCH.png" alt="JuveYell" width="700px"></p></div>

### Entradas
### Tarjeta de entradas
Para el desarrollo de la tarjeta de entradas se diseño para proporcionar:
* 4 entradas digitales desde +5V a +24V (dependera del voltaje de alimentación)
* 2 entradas analogicas de 0V a +5V epcon la tarjeta Arduino Nano por su gran comunidad, facilidad de adquisión local y costo accesible.

#### Lista de componentes
<table><tr><th>Reference</th><td>Value</td><td>Footprint</td><td>Qty</td></tr><tr><th>D1</th><td>DI0</td><td>LED_THT:LED_D3.0mm_IRBlack</td><td>1</td></tr><tr><th>D2</th><td>DI1</td><td>LED_THT:LED_D3.0mm_IRBlack</td><td>1</td></tr><tr><th>D3</th><td>DI2</td><td>LED_THT:LED_D3.0mm_IRBlack</td><td>1</td></tr><tr><th>D4,D5</th><td>DI3</td><td>LED_THT:LED_D3.0mm_IRBlack</td><td>2</td></tr><tr><th>D6,D7</th><td>Z5.1V</td><td>Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal</td><td>2</td></tr><tr><th>J2</th><td>DI</td><td>Borneras:TerminalBlock_Altech_AK300-4_P5.00mm</td><td>1</td></tr><tr><th>J3</th><td>AI</td><td>Borneras:TerminalBlock_Altech_AK300-4_P5.00mm</td><td>1</td></tr><tr><th>J10</th><td>PWR_OUT</td><td>Borneras:TerminalBlock_Altech_AK300-2_P5.00mm</td><td>1</td></tr><tr><th>J11</th><td>INPUTS</td><td>Connector_PinHeader_2.54mm:PinHeader_1x10_P2.54mm_Vertical</td><td>1</td></tr><tr><th>Q1,Q2,Q3,Q4</th><td>BC548</td><td>Package_TO_SOT_THT:TO-92L_Inline_Wide</td><td>4</td></tr><tr><th>R1,R2,R3,R4,R5,<br>R6,R7,R8,R9,R10,<br>R11,R12,R14,<br>R15,R16,R17</th><td>2.2k</td><td>Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal</td><td>16</td></tr><tr><th>R13</th><td>1k</td><td>Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal</td><td>1</td></tr></table>

#### Esquematico de entradas
<div><p style = 'text-align:center;'><img src="/PPDuino_Nano_Electronic\V0.2/Entradas/PPDuino Nano Entradas SCH.png" alt="JuveYell" width="700px"></p></div>

### Salidas
### Tarjeta de salidas
Para el desarrollo de la tarjeta del procesador, se tabajo con la tarjeta Arduino Nano por su gran comunidad, facilidad de adquisión local y costo accesible.

#### Lista de componentes
<table><tr><th>Reference</th><td>Value</td><td>Footprint</td><td>Qty</td></tr><tr><th>D5,J14</th><td>RLY0</td><td>Borneras:TerminalBlock_Altech_AK300-2_P5.00mm,LED_THT:LED_D3.0mm_IRBlack</td><td>2</td></tr><tr><th>D6,D8</th><td>1N4148</td><td>Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal</td><td>2</td></tr><tr><th>D7,J7</th><td>RLY1</td><td>Borneras:TerminalBlock_Altech_AK300-2_P5.00mm,LED_THT:LED_D3.0mm_IRBlack</td><td>2</td></tr><tr><th>D9</th><td>DI3</td><td>LED_THT:LED_D3.0mm_IRBlack</td><td>1</td></tr><tr><th>D10</th><td>DI2</td><td>LED_THT:LED_D3.0mm_IRBlack</td><td>1</td></tr><tr><th>D11</th><td>DI1</td><td>LED_THT:LED_D3.0mm_IRBlack</td><td>1</td></tr><tr><th>D12</th><td>DI0</td><td>LED_THT:LED_D3.0mm_IRBlack</td><td>1</td></tr><tr><th>J6</th><td>SEL0</td><td>Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical</td><td>1</td></tr><tr><th>J8</th><td>PWM</td><td>Borneras:TerminalBlock_Altech_AK300-4_P5.00mm</td><td>1</td></tr><tr><th>J9</th><td>PWR_OUT</td><td>Borneras:TerminalBlock_Altech_AK300-2_P5.00mm</td><td>1</td></tr><tr><th>J12</th><td>OUTPUTS</td><td>Connector_PinHeader_2.54mm:PinHeader_1x10_P2.54mm_Vertical</td><td>1</td></tr><tr><th>J13</th><td>SEL1</td><td>Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical</td><td>1</td></tr><tr><th>K1,K2</th><td>~</td><td>Codigo_lib:Relay</td><td>2</td></tr><tr><th>Q1,Q2</th><td>BC548</td><td>Package_TO_SOT_THT:TO-92L_Inline_Wide</td><td>2</td></tr><tr><th>R13,R14,R15,<br>R16,R17,R18,<br>R19,R20</th><td>330</td><td>Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal</td><td>8</td></tr><tr><th>U5</th><td>L293D</td><td>Package_DIP:DIP-16_W7.62mm_LongPads</td><td>1</td></tr></table>

#### Esquematico de salidas
<div><p style = 'text-align:center;'><img src="/PPDuino_Nano_Electronic\V0.2/Salidas/PPDuino Nano Salidas SCH.png" alt="JuveYell" width="700px"></p></div>

## Fabricacion
### Impresión 3D
<div><p style = 'text-align:center;'><img src="/PPDuino_Nano_3D_Design/Impresion3D1.png" alt="JuveYell" width="700px"></p></div>

<div><p style = 'text-align:center;'><img src="/PPDuino_Nano_3D_Design/Impresion3D2.jpeg" alt="JuveYell" width="500px"></p></div>

<div><p style = 'text-align:center;'><img src="/PPDuino_Nano_3D_Design/Impresion3D3.jpeg" alt="JuveYell" width="500px"></p></div>

### Fabricacion de PCB
<div><p style = 'text-align:center;'><img src="/PPDuino_Nano_Electronic/PCB1.jpeg" alt="JuveYell" width="500px"></p></div>

## Programación
### Programación con Arduino IDE (C++)

Descarguemos el software para programar el Arduino Nano en [Descargar Arduino IDE](https://www.arduino.cc/en/software/)

Reconoscamos las herramientas de Arduino IDE
<div><p style = 'text-align:center;'><img src="/PPDuino_Nano_Programming\C++\1_Parpadeo/0.png" alt="JuveYell" width="700px"></p></div>

Seleccionar en BOARDS: Arduino Nano
Seleccionar en PORTS: COMx (Dependera del puerto asignado desde su computadora)
<div><p style = 'text-align:center;'><img src="/PPDuino_Nano_Programming\C++\1_Parpadeo/1.png" alt="JuveYell" width="700px"></p></div>

<div><p style = 'text-align:center;'><img src="/PPDuino_Nano_Programming\C++\1_Parpadeo/2.png" alt="JuveYell" width="700px"></p></div>

### Programación con OpenPLC IDE (Ladder)

Descarguemos el software OpenPLC para programar el Arduino Nano en [Descargar OpenPLC](https://autonomylogic.com/)

Reconoscamos las herramientas de OpenPLC
<div><p style = 'text-align:center;'><img src="/PPDuino_Nano_Programming\Ladder\1_Parpadeo/0.png" alt="JuveYell" width="700px"></p></div>

<div><p style = 'text-align:center;'><img src="/PPDuino_Nano_Programming\Ladder\1_Parpadeo/1.png" alt="JuveYell" width="700px"></p></div>

<div><p style = 'text-align:center;'><img src="/PPDuino_Nano_Programming\Ladder\1_Parpadeo/2.png" alt="JuveYell" width="700px"></p></div>

<div><p style = 'text-align:center;'><img src="/PPDuino_Nano_Programming\Ladder\1_Parpadeo/3.png" alt="JuveYell" width="700px"></p></div>

<div><p style = 'text-align:center;'><img src="/PPDuino_Nano_Programming\Ladder\1_Parpadeo/4.png" alt="JuveYell" width="700px"></p></div>

### Programación con Fab Blocks (Bloques)

Descarguemos el software Fab Blocks IDE para programar el Arduino Nano en [Descargar Fab Blocks IDE](https://github.com/codigospace/Fab-Blocks-IDE/releases)

Reconoscamos las herramientas de Fab Blocks IDE
<div><p style = 'text-align:center;'><img src="/PPDuino_Nano_Programming\Blockly\1_Parpadeo/0.png" alt="JuveYell" width="700px"></p></div>

<div><p style = 'text-align:center;'><img src="/PPDuino_Nano_Programming\Blockly\1_Parpadeo/1.png" alt="JuveYell" width="700px"></p></div>

<div><p style = 'text-align:center;'><img src="/PPDuino_Nano_Programming\Blockly\1_Parpadeo/2.png" alt="JuveYell" width="700px"></p></div>

<div><p style = 'text-align:center;'><img src="/PPDuino_Nano_Programming\Blockly\1_Parpadeo/3.png" alt="JuveYell" width="700px"></p></div>

# NOSOTROS
## IESTP Pedro P. Díaz
Somos el Instituto Superior Pedro P. Díaz de la cuidad de Arequipa en Perú, formamos profesionales que aportan desarrollo a la comunidad, región y pais.
Estamos ubicados en Arequipa, una cuidad cálida, rodeada de 3 volcanes, con una zona céntrica de arquitectura barroca construida de sillar, una piedra volcánica blanca, razon para denominarla "La Cuidad Blanca".
La instalación del instituto esta ubicada en Av. Pizarro 130 de Jose Luis Bustamante y Rivero.
## Programa de Electrónica Industrial
Somos el Programa de Electrónica Industrial del IESTP Pedro P. Diaz.
## Fab Lab PPD Electronica
Somos el laboratorio de fabricación digital del programa de Electrónica Industrial, que empodera a la comunidad educativa con capacitaciones y equipamiento para que fabriquen casi cualquier cosas.