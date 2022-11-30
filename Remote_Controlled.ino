#include <IRremote.h>
int IRpin = 9;
IRrecv IR(IRpin);
decode_results cmd;
int STBY = 3;
int ENA = 5;
int ENB = 6;
int AIN1= 7;
int BIN1 = 8;
int left;
int right;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
IR.enableIRIn(); 
IR.blink13(true);
pinMode(STBY, OUTPUT);
pinMode(ENA, OUTPUT);
pinMode(ENB, OUTPUT);
pinMode(AIN1, OUTPUT);
pinMode(BIN1, OUTPUT);
digitalWrite(STBY, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:

  left = 145;
  right = 150;
 
while (IR.decode(&cmd)==0){
}
delay(500);
IR.resume();
if (cmd.value ==0xFFC23D){ //foreward - goes forward
  analogWrite(ENA, right);
  analogWrite(ENB, left);
  digitalWrite(AIN1, HIGH);
 digitalWrite(BIN1, HIGH);
 delay(500);
cmd.value == 0;
Serial.println(cmd.value, HEX);
}

IR.resume();
if (cmd.value ==0xFF22DD){ //reverse- goes reverse
  analogWrite(ENA, right);
  analogWrite(ENB, left);
  digitalWrite(AIN1, LOW);
 digitalWrite(BIN1, LOW);
 delay(500);
cmd.value == 0;
Serial.println(cmd.value, HEX);
}

IR.resume();
if (cmd.value ==0xFFA25D){ //power- turns off car
  digitalWrite(ENA, LOW);
 digitalWrite(ENB, LOW);
  digitalWrite(AIN1, LOW);
 digitalWrite(BIN1, LOW);
 delay(500);
cmd.value == 0;
Serial.println(cmd.value, HEX);
}

IR.resume();
if (cmd.value ==0xFF629D){ //vol+ - turns left
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
  digitalWrite(AIN1, HIGH);
 digitalWrite(BIN1, LOW);
  delay(282);
 digitalWrite(ENA, LOW);
 digitalWrite(ENB, LOW);
 delay(500);
cmd.value == 0;
Serial.println(cmd.value, HEX);
}


IR.resume();
if (cmd.value ==0xFFA857){ //vol- turns right
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
  digitalWrite(AIN1, LOW);
 digitalWrite(BIN1, HIGH);
 delay(282);
 digitalWrite(ENA, LOW);
 digitalWrite(ENB, LOW);
 delay(500);
cmd.value == 0;
Serial.println(cmd.value, HEX);
}

IR.resume();
if (cmd.value ==0xFF6897){ //vol+ - turns left slightly
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
  digitalWrite(AIN1, HIGH);
 digitalWrite(BIN1, LOW);
  delay(50);
 digitalWrite(ENA, LOW);
 digitalWrite(ENB, LOW);
 delay(500);
cmd.value == 0;
Serial.println(cmd.value, HEX);
}

IR.resume();
if (cmd.value ==0xFF30CF){ //vol+ - turns right slightly
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
  digitalWrite(AIN1, LOW);
 digitalWrite(BIN1, HIGH);
  delay(50);
 digitalWrite(ENA, LOW);
 digitalWrite(ENB, LOW);
 delay(500);
cmd.value == 0;
Serial.println(cmd.value, HEX);
}
}
