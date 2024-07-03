#include <VirtualWire.h> //Biblioteca para RF433MHz

#define RX   2  //Define módulo rx no pino digital 2
#define LED1 3  //Define led 1 no pino digital 3
#define LED2 4  //Define led 2 no pino digital 4

byte data[VW_MAX_MESSAGE_LEN];        //Variável para armazenar os dados
byte dataLength = VW_MAX_MESSAGE_LEN; //Tamanho máximo dos dados recebidos

void setup() {
  pinMode(LED1, OUTPUT); //Configura led 1 como saída
  pinMode(LED2, OUTPUT); //Configura led 2 como saída
  vw_set_rx_pin(RX);     //Configura pino de dado do módulo tx
  vw_setup(1200);        //Configura baud rate de comunicação - 1200bps
  vw_rx_start();         //Inicia o recebimento de dados
  
  digitalWrite(LED1, LOW); //Inicia led 1 em nível baixo
  digitalWrite(LED2, LOW); //Inicia led 2 em nível baixo 
  Serial.begin(9600);
}

void loop() {
  Serial.println("Teste 1");
  if (vw_get_message(data, &dataLength)) { 
    Serial.println("Teste");
    if (data[0])  Serial.println("Bot 1: 0");
    if (!data[0]) Serial.println("Bot 1: 1");
    if (data[1])  Serial.println("Bot 2: 0");
    if (!data[1]) Serial.println("Bot 2: 1");
  }
}
