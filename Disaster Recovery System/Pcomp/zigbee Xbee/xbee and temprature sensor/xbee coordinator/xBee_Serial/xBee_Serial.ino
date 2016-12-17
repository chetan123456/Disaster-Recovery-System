
//-------EndPoints-------//

//void setup() {
//  // put your setup code here, to run once:
//  Serial.begin(9600);
//  
//
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//  
//  int val = analogRead(A0);
//  
//  Serial.print(2);
//  Serial.print(",");
//  Serial.println(val);
//  delay(1000);
//
//}


//-------Coordinate-------//


#include <SoftwareSerial.h>

SoftwareSerial softSerial(10, 11); // RX, TX

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  softSerial.begin(9600); 
  softSerial.setTimeout(15);

}

int tem = 0;
int res = 0;
int pir;

void loop() {
  // put your main code here, to run repeatedly:
  if(softSerial.available() > 4){
    
     //inByte = readStringUntil('\n');
    
      int endPointNum = softSerial.parseInt();
      if(endPointNum == 0){
        int trash = softSerial.parseInt();
        return;
      }
      
      int inByte = softSerial.parseInt();
      
//      Serial.print(endPointNum);
//      Serial.print(" ");
//      Serial.println(inByte);
      
      if(endPointNum == 1){
        tem = inByte;
      }

      if(endPointNum == 3){
        pir = 1;
      //Serial.print("Motion Detected: ");
      Serial.print(pir);
      Serial.print(",");
      }
      
      else if(endPointNum == 2){
        res = inByte;
      }
      
     // Serial.print("Current Temperature is: ");
      Serial.print(tem);
      Serial.print(",");
      
      //Serial.print("  Resistance is: ");
      Serial.println(res);
      
      
  
  }
  
  delay(10);

}
