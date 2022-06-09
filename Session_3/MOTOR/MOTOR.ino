const int in1 = 11;
const int in2 = 10;
const int in3 = 9;
const int in4 = 8;
int anan;
const int e1 = 5;
const int e2 = 6;

void setup() {
  setPwmFrequency(e1,1);
  setPwmFrequency(e2,1);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);  
  pinMode(e1, OUTPUT);
  pinMode(e2, OUTPUT);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  Serial.begin(115200);
  //delay(250);
}

void loop() {
  anan = analogRead(0) >> 2;
  Serial.println(anan);
  if(anan > 127)
  {
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    analogWrite(e1,(anan - 127)<<1);
    analogWrite(e2,(anan - 127)<<1);
  }
  else
  {
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    analogWrite(e1,(127-anan)<<1);
    analogWrite(e2,(127-anan)<<1);
  }
  //analogWrite(e1,anan);
  //analogWrite(e2,127 - anan);
}

void setPwmFrequency(int pin, int divisor) {
  byte mode;
  if(pin == 5 || pin == 6 || pin == 9 || pin == 10) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 64: mode = 0x03; break;
      case 256: mode = 0x04; break;
      case 1024: mode = 0x05; break;
      default: return;
    }
    if(pin == 5 || pin == 6) {
      TCCR0B = TCCR0B & 0b11111000 | mode;
    } else {
      TCCR1B = TCCR1B & 0b11111000 | mode;
    }
  } else if(pin == 3 || pin == 11) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 32: mode = 0x03; break;
      case 64: mode = 0x04; break;
      case 128: mode = 0x05; break;
      case 256: mode = 0x06; break;
      case 1024: mode = 0x07; break;
      default: return;
    }
    TCCR2B = TCCR2B & 0b11111000 | mode;
  }
}
