  int led = 10; // Burada ledimizi bağlayacağımız yeri seçerek pine isim veriyoruz. Ben 10 nolu çıkışı seçtim.
  
  void setup()  //Bu kısımda kullanacağımız pinleri ve giriş mi çıkış mı olacağını ayarlıyoruz.
  {
    
  pinMode (led, OUTPUT);
  }
  
  void loop() // Bu kısımda döngü kodunu giriyoruz.
  {
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);
  delay(500);
  // döngü, kod bitince tekrar başa döner.
  }
