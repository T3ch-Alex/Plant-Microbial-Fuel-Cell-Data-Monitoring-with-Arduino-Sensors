/* Primeiramente incluímos as biblioteca dos dispositivos */
#include <Adafruit_ADS1X15.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
/* Definimos algumas configurações */
#define BME_SCK 18
#define BME_MISO 19
#define BME_MOSI 23
#define BME_CS 5*/
#define SEALEVELPRESSURE_HPA (1013.25)
// DISPOSITIVO ADS1115
/* O código original pode ser obtido no site GitHub, 
criado pelo autor do canal Gadget Reboot (2019) no site 
do YouTube. O código e os pinos foram adaptados para o circuito 
do experimento.
- Iniciamos o dispositivo ADS1115 */
Adafruit_ADS1115 ads; /* Usar este para a versão 16-bit */
//Adafruit_ADS1015 ads; /* Usar este para a versão 12-bit */
// SENSOR BME280
/* Para o sensor BME280, utilizou-se o tutorial do site Last Minute Engineers (2021).
- Iniciamos o dispositivo BME280 */
Adafruit_BME280 bme; // I2C
// SENSOR UV GYML8511
36
/* O código utilizado para este sensor pode ser encontrado no site Cap 
Sistema, 
criado pelo autor Cacpnrj (2021).
- Estabelecemos as variáveis para os pinos do Sensor UV GYML8511. */
int UVOUT = A0; //Output do sensor
int REF_3V3 = A1; //3.3V de alimentação do Arduino
// SENSOR LDR
/* O código para este sensor utilizado foi retirado do site Blog da Robótica, 
da autora Viana (2020).
- Estabelecemos as variáveis para os pinos do sensor LDR.
- Deve-se ajustar o valor do pino para o LDR para não utilizar o mesmo 
pino 
analógico que outros sensores. */
int ldr = A7;//Atribui A7 a variável ldr
int valorldr = 0;//Declara a variável valorldr como inteiro
// SENSOR UMIDADE DO SOLO
/* O código utilizado é do autor Rjloura (2017) publicado no site GitHub. 
- Pinos e variáveis do sensor de umidade do solo.
- Importante escolher um pino analógico que não esteja sendo usado para 
evitar 
conflitos. 
- Em caso de uso do Arduino UNO, deve-se escolher um pino de A2 à A5 
pois, 
já estamos utilizando A0 e A1 para o sensor UV */
int analogPin = A6;
int moisture;
int percentage;
/* Aqui mapeamos conforme queremos medir a umidade do solo, no caso do 
experimento, map_high foi ajustado para umidade do solo encharcado com 
nível de água ligeiramente abaixo do cátodo e map_low para o solo seco */
int map_low = 955;
int map_high = 380;
/* ---------------------------------------------------------------------
*/
void setup(void)
{
Serial.begin(9600);
// PLX-DAQ (Planilha do EXCEL)
/* O programa utilizado é o PLX-DAQ (Parallax, c2021). Já o código 
(adaptado), foi originalmente publicado pelo autor Mytectutor (c2021). 
- O Arduino deve estar conectado ao computador ligado, com a planilha 
PLX-DAQ aberta o tempo todo, pois o programa se comunica pela entrada
USB do computador onde o Arduino está conectado. 
- Ao abrir a planilha, deve-se clicar no botão connect do PLX-DAQ. 
- Vale notar que o programa não pode estar rodando na IDE do Arduino 
ou haverá conflitos entre o programa do Arduino e o PLX-DAQ.
- Aqui o programa limpa os dados anteriores na planilha PLX-DAQ e 
cria novas colunas, registrando os dados em sequência e zera o tempo 
corrido. */
Serial.println("CLEARDATA");
Serial.println("LABEL, Time, Started Time, Date, Intensidade UV(mW/m²), 
Voltagem(mV), Corrente(mA), Luminosidade(lux), Irradiância (W/m²), Umidade do Solo(%), Temperatura(ºC), Pressão(hPa), Umidade do Ar(%)");
37
Serial.println("RESETTIMER");
// SENSOR UV GYML8511
/* Aqui definimos o modo dos pinos do sensor UV */
pinMode(UVOUT, INPUT);
pinMode(REF_3V3, INPUT);
// SENSOR LDR
/* Aqui definimos o modo do pino do sensor LDR */
pinMode(ldr, INPUT);//Define ldr (pino analógico A7) como saída
// DISPOSITIVO ADS1115
/*Aqui definimos o ganho do sensor para leituras de +/- 0.256V, 
na versão 16 bit, utilizamos o valor de 0.0078125mV para cada 1 bit. 
Para a versão 12-bit utilizar 0.125mV.*/
ads.setGain(GAIN_SIXTEEN); // 16x gain +/- 0.256V 1 bit = 
0.125mV 0.0078125mV
if (!ads.begin()) {
while (1);
}
// SENSOR BME
/* Estabelece o endereço do sensor BME */
bool status;
status = bme.begin(0x76); //I2C address can be 0x77 or 0x76 (by default 0x77 set in library)
if (!status) {
while (1);
}
delay(1000);
}
/* ---------------------------------------------------------------------
*/
void loop(void)
{
// SENSOR UV GYML8511
/* Definimos as variáveis para os dados do sensor UV */
int uvLevel = averageAnalogRead(UVOUT);
int refLevel = averageAnalogRead(REF_3V3);
/* Usamos a entrada 3.3V como referência para obtermos um valor mais 
preciso */
float outputVoltage = 3.3 / refLevel * uvLevel;
float uvIntensity = mapfloat(outputVoltage, 0.99, 2.9, 0.0, 15.0);
// DISPOSITIVO ADS1115
int16_t results;
/* Neste multiplicador, colocamos o valor de mV para cada bit que definimos no setup. */
float multiplier = 0.0078125F; // 0,0078125mV para cada 1 bit
/* Faz o sensor ler o valor. */
results = ads.readADC_Differential_0_1();
// SENSOR LDR
/* Lê o valor do sensor ldr e armazena na variável valorldr. */
valorldr=analogRead(ldr);
// SENSOR UMIDADE DO SOLO
38
/* Fazemos a leitura do sensor e guardamos nas variáveis */
moisture = analogRead(analogPin);
percentage = map(moisture, map_low, map_high, 0, 100);
// PLX-DAQ (Planilha do EXCEL)
/* Imprime os dados, o tempo e a data */
Serial.print("DATA, TIME, TIMER, DATE,");
// Aqui em diante imprimimos o resultado de cada variável de cada sensor.
// Cada um separado por uma vírgula.
// SENSOR UV
/* Imprime a medida de intensidade UV em mW/m². */
Serial.print(uvIntensity);
Serial.print(" ,");
// DISPOSITIVO ADS1115 DDP
/* Imprime a medida de ddp em mV */
Serial.print(results * multiplier);
Serial.print(" ,");
// DISPOSITIVO ADS1115 CORRENTE
/* Imprime o cálculo da corrente em mA, dividindo a ddp por 100 ohms 
da resistência externa.*/
Serial.print(((results * multiplier)/100));
Serial.print(" ,");
// SENSOR LDR LUMINOSIDADE
/* Imprime a medida de luminosidade em Lux*/
Serial.print(valorldr);
Serial.print(" ,");
// SENSOR LDR IRRADIÂNCIA
/* Imprime o cálculo da irradiância em W/m², utilizando 
um fator de 0,00833 W/m² para cada 1 lux (MICHAEL et al, 2020).*/
Serial.print(valorldr * 0,00833);
Serial.print(" ,");
// SENSOR UMIDADE DO SOLO
/* Imprime o resultado em porcentagem. */
Serial.print(percentage);
Serial.print(" ,");
// SENSOR BME280
/* Imprimimos o resultado de cada variável do BME280 e separamos por 
uma vírgula */
Serial.print(bme.readTemperature());
Serial.print(" ,");
Serial.print(bme.readPressure() / 100.0F);
Serial.print(" ,");
Serial.print(bme.readHumidity());
Serial.println(" ,");
// TEMPO DE ESPERA DE CADA MEDIÇÃO EM MILLISEGUNDOS
/* Aqui colocamos uma espera de 1 hora para cada medição */
delay(3600000);
}
39
/* ---------------------------------------------------------------------
*/
// SENSOR UV FUNÇÃO
/* Faz uma média de leituras em um determinado pino e
retorna a média. */
int averageAnalogRead(int pinToRead)
{
byte numberOfReadings = 8;
unsigned int runningValue = 0; 
for(int x = 0 ; x < numberOfReadings ; x++)
runningValue += analogRead(pinToRead);
runningValue /= numberOfReadings;
return(runningValue); 
}
// SENSOR UV MAPEAMENTO
/* Mapear o sensor UV é relativamente simples. O Arduino tem um função 
map() integrada, mas não funciona para floats, então fazemos uma função 
mapFloat() simples */
float mapfloat(float x, float in_min, float in_max, float out_min, float
out_max)
{
return (x - in_min) * (out_max - out_min) / (in_max - in_min) +
out_min;
}
