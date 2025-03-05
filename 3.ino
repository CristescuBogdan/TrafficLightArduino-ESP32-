//3
#include "BluetoothSerial.h" //Header File for Serial Bluetooth
BluetoothSerial ESP_BT; //Object for Bluetooth
int incoming;
int LED_PIN = 33; // GPIO ales
int LED_G = 12; // GPIO ales
int x=10;
int y=10;
int z,c=0;
int i;
#define A 18
#define B 19
#define C 17
#define D 16
#define E 5
#define F 21
#define G 4
#define DP 4
#define DIGIT1 22
#define DIGIT2 23
#define MAX_TIME 10
unsigned long timp = millis();
int digitCurent;
#define touchPin 15
 int ledPin = 26;// change with your threshold value
const int threshold=20;// variable for storing the touch pin value
int touchValue;

void setup() {
  Serial.begin(115200);
  delay(1000);
  pinMode (ledPin, OUTPUT);
  pinMode (LED_G, OUTPUT);
 ESP_BT.begin("ESP32_LED_Controlboooo"); //Nume semnal Bluetooth 
 Serial.println("Bluetooth Device is Ready to Pair");
 pinMode (LED_PIN, OUTPUT);//LED-uleste output
 x=10;
 pinMode(A, OUTPUT); //A
pinMode(B, OUTPUT); //B
pinMode(C, OUTPUT); //C
pinMode(D, OUTPUT); //D
pinMode(E, OUTPUT); //E
pinMode(F, OUTPUT); //F
pinMode(G, OUTPUT); //G
pinMode(DP, OUTPUT); //DP
pinMode(DIGIT1, OUTPUT); //DIGIT1
pinMode(DIGIT2, OUTPUT); //DIGIT2
}
void aprindeCifra(byte digitCurent){
if(digitCurent==1){
digitalWrite(DIGIT1,LOW); //DIGIT1
digitalWrite(DIGIT2,HIGH); //DIGIT2
digitalWrite(A,HIGH); //a
digitalWrite(B,LOW); //b
digitalWrite(C,HIGH); //c
digitalWrite(D,HIGH); //d             //S
digitalWrite(E,LOW); //e
digitalWrite(F,HIGH); //f
digitalWrite(G,HIGH); // g
digitalWrite(DP,HIGH); // DP
delay(1000);
digitalWrite(DIGIT1,HIGH); //DIGIT1
digitalWrite(DIGIT2,LOW); //DIGIT2
digitalWrite(A,LOW); //a
digitalWrite(B,LOW); //b
digitalWrite(C,LOW); //c
digitalWrite(D,HIGH); //d           //t
digitalWrite(E,HIGH); //e
digitalWrite(F,HIGH); //f
digitalWrite(G,HIGH); // g
digitalWrite(DP,HIGH); // DP
delay(1000);

}
else{if(digitCurent==2){

  digitalWrite(DIGIT1,LOW); //DIGIT1
digitalWrite(DIGIT2,HIGH); //DIGIT2
digitalWrite(A,HIGH); //a
digitalWrite(B,HIGH); //b
digitalWrite(C,HIGH); //c           //A
digitalWrite(D,LOW); //d
digitalWrite(E,HIGH); //e
digitalWrite(F,HIGH); //f
digitalWrite(G,HIGH); // g
delay(1000);

  digitalWrite(DIGIT1,HIGH); //DIGIT1
digitalWrite(DIGIT2,LOW); //DIGIT2
digitalWrite(A,LOW); //a
digitalWrite(B,LOW); //b
digitalWrite(C,LOW); //c
digitalWrite(D,LOW); //d
digitalWrite(E,HIGH); //e
digitalWrite(F,LOW); //f
digitalWrite(G,HIGH); // g
delay(1000);
  digitalWrite(DIGIT1,LOW); //DIGIT1
digitalWrite(DIGIT2,HIGH); //DIGIT2
digitalWrite(A,LOW); //a
digitalWrite(B,LOW); //b
digitalWrite(C,LOW); //c
digitalWrite(D,HIGH); //d           //t
digitalWrite(E,HIGH); //e
digitalWrite(F,HIGH); //f
digitalWrite(G,HIGH); // g
digitalWrite(DP,HIGH); // DP
delay(1000);}
else{if(digitCurent==3){

  digitalWrite(DIGIT1,LOW); //DIGIT1
digitalWrite(DIGIT2,HIGH); //DIGIT2
digitalWrite(A,LOW); //a
digitalWrite(B,LOW); //b
digitalWrite(C,HIGH); //c           //o
digitalWrite(D,HIGH); //d
digitalWrite(E,HIGH); //e
digitalWrite(F,LOW); //f
digitalWrite(G,HIGH); // g
delay(1000);

  digitalWrite(DIGIT1,HIGH); //DIGIT1
digitalWrite(DIGIT2,LOW); //DIGIT2
digitalWrite(A,HIGH); //a
digitalWrite(B,HIGH); //b
digitalWrite(C,LOW); //c          //P
digitalWrite(D,LOW); //d
digitalWrite(E,HIGH); //e
digitalWrite(F,HIGH); //f
digitalWrite(G,HIGH); // g
delay(1000);
}}
}
}//void aprindecif

void loop() {

touchValue = touchRead (touchPin);
Serial.print (touchValue);
ESP_BT.println("au mai ramas");
ESP_BT.println(x);
if(touchValue<=30 && x!=0)
  {
    
    
    if(millis() - timp >= MAX_TIME*100) {
    // turn LED on
     digitalWrite(LED_PIN, HIGH);
    Serial.println(" - LED on");
    }


x=x-2;
z=x;
timp = millis();
  }
  delay(2000);
if(z<2){
  // turn LED off
  digitalWrite(LED_PIN,LOW);
  Serial.println(" - LED off");
  if (millis() - timp >= MAX_TIME) 
  {
  for(i=0;i<2;i++)
  {
    if(digitCurent==1) {
      digitalWrite(DIGIT1, LOW);
      digitalWrite(DIGIT2, HIGH); //aprinde 1
      aprindeCifra(digitCurent);
      digitCurent=2;
        }
    else {
     digitalWrite(DIGIT1, HIGH);
      digitalWrite(DIGIT2, LOW); //aprinde 2
     aprindeCifra(digitCurent);
     digitCurent=1;
    }
        }

  }
  timp = millis();

}
z+=1;
c+=1;
//app b)
if(c>4 && y!=0 )
  {
    
    
    if(millis() - timp >= MAX_TIME*10) {
       // turn LED on
      digitalWrite(ledPin, HIGH);
      Serial.println(" - LED on");
      }
   
      y=y-1;
 //Serial.println(y);      
      if(y>=7){
            digitalWrite(LED_G,HIGH);
            delay(1000);
            digitalWrite(LED_G, LOW);
            delay(1000);
          }
          if(y<7){
            digitalWrite(LED_G,HIGH);
            delay(500);
            digitalWrite(LED_G, LOW);
            delay(500);
          }
          if(y<4){
            digitalWrite(LED_G,HIGH);
            delay(250);
            digitalWrite(LED_G, LOW);
            delay(250);
          }
      }  
      timp = millis();
      //x=x-1;
      //for(x=x-1;x>=0;x--)
          
        
  delay(10);
  if(y==0){
  // turn LED off
  digitalWrite(ledPin,LOW);
  Serial.println(" - LED off");
  digitalWrite(LED_G,LOW);
  Serial.println(" - LED off");
  if (millis() - timp >= MAX_TIME) 
    {
      if(digitCurent==1) 
        {
        digitalWrite(DIGIT1, LOW);
        digitalWrite(DIGIT2, HIGH); //aprinde 1
        aprindeCifra(digitCurent);
        digitCurent=3;
        }
  else {
      digitalWrite(DIGIT1, HIGH);
      digitalWrite(DIGIT2, LOW); //aprinde 2
      aprindeCifra(digitCurent);
      digitCurent=1;
        }
    }
    timp = millis();
    }



  
}//VOIDLOOP