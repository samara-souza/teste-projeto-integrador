#include <VirtualWire.h> //Biblioteca para RF433MHz

#define TX  2  //Define módulo tx no pino digital 2
#define BT1 3  //Define botão 1 no pino digital 3
#define BT2 4  //Define botão 2 no pino digital 4

byte tx_buffer[2]; //Buffer de messagem  
int Status_1 = 0;  
int Status_2 = 0;

void setup() {
  pinMode(BT1, INPUT_PULLUP); //Configura botão 1 como entrada
  pinMode(BT2, INPUT_PULLUP); //Configura botão 2 como entrada
  vw_set_tx_pin(TX);   //Configura pino de dado do módulo tx
  vw_setup(1200);      //Configura baud rate de comunicação - 1200bps

  Serial.begin(9600);
}

void loop() {
  if (!digitalRead(BT1)) {    //Botão 1 pressionado?
                              //Sim..
    Status_1 = !Status_1;     //Inverte o estado 1
    tx_buffer[0] = 0;  //Transmite o valor com endereço 0     
    //while(!digitalRead(BT1)); //Fica preso até soltar o botão 1
    //delay(10);                //Atraso 10ms - Debource
  }
  else{
    tx_buffer[0] = 1;  //Transmite o valor com endereço 0     
  }
  if (!digitalRead(BT2)) {    //Botão 2 pressionado?
                              //Sim..
    Status_2 = !Status_2;     //Inverte o estado 2
    tx_buffer[1] = 0;  //Transmite o valor com endereço 1     
    //while(!digitalRead(BT2)); //Fica preso até soltar o botão 2
    //delay(10);                //Atraso 10ms - Debource
  }
  else{
    tx_buffer[1] = 1;  //Transmite o valor com endereço 0     
  }
  //Transmite os dados
  vw_send(tx_buffer, 2);
  //vw_wait_tx();

  Serial.println(tx_buffer[0]);
  Serial.println(tx_buffer[1]);
}
