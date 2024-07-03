#include <VirtualWire.h> //Biblioteca para RF433MHz

#define TX  2  //Define módulo tx no pino digital 2
#define BT1 3  //Define botão 1 no pino digital 3
#define BT2 4  //Define botão 2 no pino digital 4
#define pinPot A0

byte tx_buffer[3]; //Buffer de messagem  


void setup() {
  pinMode(BT1, INPUT_PULLUP); //Configura botão 1 como entrada
  pinMode(BT2, INPUT_PULLUP); //Configura botão 2 como entrada
  vw_set_tx_pin(TX);   //Configura pino de dado do módulo tx
  vw_setup(4000);      //Configura baud rate de comunicação - 1200bps

  Serial.begin(9600);
}

void loop() {

  int pot = analogRead(A0);
  int saidaMotor = pot / 4;

  
  tx_buffer[0] = saidaMotor;
  
  if (digitalRead(BT1) == 0) {
    tx_buffer[1] = 0;  //Transmite o valor com endereço 0     
    //while(!digitalRead(BT1)); //Fica preso até soltar o botão 1
    //delay(10);                //Atraso 10ms - Debource
  }
  else{
    tx_buffer[1] = 1;
  }
  if (digitalRead(BT2) == 0) {
    tx_buffer[2] = 0;  //Transmite o valor com endereço 1     
    //while(!digitalRead(BT2)); //Fica preso até soltar o botão 2
    //delay(10);                //Atraso 10ms - Debource
  }
  else{
    tx_buffer[2] = 1;
  }
  //Transmite os dados
  vw_send(tx_buffer, 3);
  vw_wait_tx();
  
  Serial.println(tx_buffer[0]);
  Serial.println(tx_buffer[1]);
  Serial.println(tx_buffer[2]);

  //delay(2000);
}
