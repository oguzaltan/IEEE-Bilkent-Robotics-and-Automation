//Devrenin Tamamı
#include <LiquidCrystal.h> //LCD Kütüphanesi
LiquidCrystal LCD(11,10,9,2,3,4,5); 
  
#define trigPin 13 //Sensörün Echo pini Arduinonun 13. pinine bağlanır
#define echoPin 12 //Sensorün Trig pini Arduinonun 12. pinine bağlanır
#define buzzer 7 // Eğer engel belirli bir mesafedeyse buzzer çalışır
  
void setup()
{
 pinMode(trigPin, OUTPUT); //13. yani trigpini çıkış olarak ayarlıyoruz
 pinMode(echoPin, INPUT); //12. yani echoPini giriş olarak ayarlıyoruz
 pinMode(buzzer, OUTPUT); //7. pini buzzera bağlıyoruz
  
 LCD.begin(16,2); 
 LCD.setCursor(0,0); 
 LCD.print("Kastamonu"); //İlk satırda görünecek mesajı yazıyoruz
}
  
void loop() {
 long duration, distance;
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = (duration/2) / 29.1; //Ölçüm fonksiyonu

 if (distance <= 30 && distance >= 20)
 {
  digitalWrite(buzzer, HIGH);
 }
 else
 {
  digitalWrite(buzzer, LOW);
 }
  
LCD.setCursor(0,1); 
 LCD.print(" "); //Ekranı temizlemek için boşluk yazdırıyoruz.
 LCD.setCursor(0,1); 
 LCD.print("Mesafe ");
 LCD.setCursor(7,1); 
 LCD.print(distance); //Ölçülen mesafeyi yazdırıyoruz
 LCD.print(" cm"); //Ölçü birimini yazdırıyoruz
 delay(250);
}
