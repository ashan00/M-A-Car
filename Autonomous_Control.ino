int STBY = 3;
int ENA = 5;
int ENB = 6;
int AIN1= 7;
int BIN1 = 8;
int Left =145;
int Right = 147;

void setup() {
  Serial.begin(9600);//open serial and set the baudrate
pinMode(STBY, OUTPUT);
pinMode(ENA, OUTPUT);
pinMode(ENB, OUTPUT);
pinMode(AIN1, OUTPUT);
pinMode(BIN1, OUTPUT);
digitalWrite(STBY, HIGH);
}

void forward(){ 
  analogWrite(ENA, Right);
  analogWrite(ENB, Left);
  digitalWrite(AIN1,HIGH); 
  digitalWrite(BIN1,HIGH);  

  Serial.println("Forward");//send message to serial monitor
}

void back(){
  analogWrite(ENA, Right);
  analogWrite(ENB, Left);
  digitalWrite(AIN1,LOW);
  digitalWrite(BIN1,LOW);

  Serial.println("Back");
}

void left(){
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
  digitalWrite(AIN1, HIGH);
 digitalWrite(BIN1, LOW);
  delay(282);
 digitalWrite(ENA, LOW);
 digitalWrite(ENB, LOW);
  Serial.println("Left");
}

void right(){
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
  digitalWrite(AIN1, LOW);
 digitalWrite(BIN1, HIGH);
 delay(282);
 digitalWrite(ENA, LOW);
 digitalWrite(ENB, LOW);
  Serial.println("Right");
}


void stoped(){
  digitalWrite(STBY, LOW);
  Serial.println("stoped");
}

void paused(){
    analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}


//the loop will take following sequence of actions: f,r,f,l,f,s
void loop() {
  forward();  
  delay(2075);
  paused();
  delay(500);
  right();
  delay(500);
  forward();
  delay(2075);
   paused();
  delay(500);
  left();
  delay(500);
   forward();
  delay(2100);
  stoped();
}
