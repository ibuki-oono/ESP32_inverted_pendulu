const int PIN_IN1 = 16;
const int PIN_IN2 = 17;
const int ledPin = 26;// PWM


 
void setup(){
  pinMode(PIN_IN1,OUTPUT); 
  pinMode(PIN_IN2,OUTPUT); 
  ledcSetup(0,12800,8); 

  //ピンをチャンネルに接続
  ledcAttachPin(ledPin,0);
}
 
void loop(){
      
    // モーターの回転速度を中間にする
    ledcWrite(0,127);
 
    // 回転
    digitalWrite(PIN_IN1,HIGH);
    digitalWrite(PIN_IN2,LOW);
    delay(5000);
 
    // ブレーキ
    digitalWrite(PIN_IN1,HIGH);
    digitalWrite(PIN_IN2,HIGH);
    
    // 逆回転
    digitalWrite(PIN_IN1,LOW);
    digitalWrite(PIN_IN2,HIGH);    
    delay(5000);
 
    // ブレーキ
    digitalWrite(PIN_IN1,HIGH);
    digitalWrite(PIN_IN2,HIGH);
    delay(2000);
    
    // モーターの回転速度を最大にする
    ledcWrite(0,255);
    
    // 逆回転　
    digitalWrite(PIN_IN1,LOW);
    digitalWrite(PIN_IN2,HIGH);    
    delay(5000);
                
    // ストップ
    digitalWrite(PIN_IN1,LOW);
    digitalWrite(PIN_IN2,LOW);
    delay(2000);
}
