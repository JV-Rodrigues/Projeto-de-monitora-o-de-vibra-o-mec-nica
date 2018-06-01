//Programação do Acelerômetro MPU6050

//Inclusão da Biblioteca Wire, que permite a cominicação entre o sensor e o microcontrolador por meio da interface 12C.
#include<Wire.h>

//Endereço do MPU6050
const int MPU=0x68;

//Variáveis de Armazenamento
int Acx,Acy,Acz;

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
Wire.begin();
Wire.beginTransmission(MPU);
Wire.write(0x6B);

//Iniciar o MPU6050
Wire.write(0);
Wire.endTransmission(true);
}

void loop() {
  // put your main code here, to run repeatedly:

Wire.beginTransmission(MPU);
Wire.write(0x3B);  
Wire.endTransmission(false);
  
//Solicitação dos dados do sensor
Wire.requestFrom(MPU,14,true);  

//Armazenamento dos valores dos sensores nas variáveis correspondentes
Acx=Wire.read()<<8|Wire.read();      
Acy=Wire.read()<<8|Wire.read(); 
Acz=Wire.read()<<8|Wire.read(); 

//Mostra os valores na serial
Serial.print("Acel. X = "); Serial.print(Acx);
Serial.print(" | Y = "); Serial.print(Acy);
Serial.print(" | Z = "); Serial.print(Acz);

//Aguarda 300 ms e reinicia o processo
  delay(300);
  
}
