# arduino-receptor-RF-433MHZ-4-canais-


Programa necessário para o desenvolvimento desse projeto -- IDE Arduino e se quiser alterar o layout da placa,
use o Proteus Design Suite para fazer as mudanças e gerar um novo arquivo GERBER(arquivo necessário
para enviar para a empresa que irá desenvolver a PCI).

A capacidade máxima de armazenamento desse receptor é de + ou - 500 dispositivos entre controles remotos (considere 
cada botão do controle remoto um dispositivo ) e sensores de alarmes (AMBOS COM TECNOLOGIA 'CODE-LEARNING')
 
Após ter montado a placa e gravado o programa no Arduino siga as etapas:

Quando ligar o receptor na tomada, o led ira piscar rapidamente + ou - 8 vezes.

Para iniciar a programação do controle remoto no receptor, obedeça essa sequência:

1- Feche o jumper do canal que deseja programar ao fio negativo da placa.

2- Aperte e solte o push-buttom, O led irá piscar à espera de um sinal do controle remoto ou sensor de alrme, aperte o botão 
do controle remoto ou dispare o sensor de alarme, se o sinal for válido, o led para de piscar e o botão do controle 
remoto ou sensor de alarme estará gravado, SOLTE O FIO DO CANAL QUE ACABOU DE GRAVAR DO FIO NEGATIVO E repita o mesmo procedimento 
para gravar outros dispositivos em outros canais(ou mantenha o fio do canal no negativo, caso queira gravar mais de 
um dispositivo no mesmo canal).
O tempo para programar é de + ou - 13 segundos.

3- Todos os canais podem ser configurados como PULSO ou RETENÇÃO. É recomendado que configure os canais como pulso ou
retenção só depois do termino da gravação dos dispositivos no receptor, pois se esquecer o fio do canal conectado
ao negativo e quiser gravar um outro dispositivo, esse dispositivo será gravado nos dois canais correspondentes aos
fios conectados ao negativo da placa.
Para que o canal funcione como pulso, deixe o fio correspondente ao canal solto (não conectado ao negativo)
Para que o canal funcione como retenção, deixe o fio correspondente ao canal conectado ao fio negativo.

4- Temporização dos Canais 1 e 2.
Obrigatóriamente os canais temporizados devem estar configurados como RETENÇÃO. O potenciometro da esquerda corresponde 
ao canal 1 e o potenciometro da direita, ao canal 2. Para que o canal NÃO seja temporizado, basta zerar o potenciometro
(totalmente anti-horário) e para que o canal seja temporizado, basta ajustar o potenciometro em sentido horário até
encontrar o tempo desejado.
O tempo mínimo é de + ou - 13 segundos e o tempo máximo é de aproximadamente 9 minutos. 
   
5- Para apagar todos dispositivos (reset), mantenha o push-buttom apertado até o led acender, solte o botão, 
o led irá piscar rapidamente e todos os dispositivos gravados serão apagados.   
