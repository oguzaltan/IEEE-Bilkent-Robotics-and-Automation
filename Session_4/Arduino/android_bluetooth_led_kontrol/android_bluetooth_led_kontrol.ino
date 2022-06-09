int gelenVeri;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0){
    gelenVeri=Serial.read();
  }
  if(gelenVeri==0)
    digitalWrite(13, LOW);
  if(gelenVeri==1)
    digitalWrite(13, HIGH);    
}
