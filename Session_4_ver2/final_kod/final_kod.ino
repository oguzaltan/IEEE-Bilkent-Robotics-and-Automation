#include<SoftwareSerial.h>

SoftwareSerial bt_iletisim(12, 13); //RX ve TX

int sol_on = 11;
int sol_arka = 10;
int sol_hiz = 6; // wait  

int sag_on = 9;
int sag_arka = 8;
int sag_hiz = 5;

int motorlar_hiz = 255;
byte son_islem;

void setup()
{
  pinMode(sol_on, OUTPUT);
  pinMode(sag_on, OUTPUT);
  pinMode(sol_arka, OUTPUT);
  pinMode(sag_arka, OUTPUT);
  pinMode(sol_hiz, OUTPUT);
  pinMode(sag_hiz, OUTPUT);

  Serial.begin(9600);
  bt_iletisim.begin(9600);
}

void loop()
{
  if (bt_iletisim.available())
  {
    char data = bt_iletisim.read();
    Serial.println(data);

    if (data == '1')
    {
      dur();
      delay(10);
      ileri();
      son_islem = 1;
    }
    else if (data == '2')
    {
      dur();
      delay(10);
      geri();
      son_islem = 2;
    }
    else if (data == '3')
    {
      dur();
      delay(10);
      sol();
      son_islem = 3;
    }
    else if (data == '4')
    {
      dur();
      delay(10);
      sag();
      son_islem = 4;
    }
    else if (data == '6')
    {
      dur();
    }
    else if (data == '0')
    {
      motorlar_hiz = motorlar_hiz + 25;
      if (motorlar_hiz > 255)
      {
        motorlar_hiz = 255;
      }
      Serial.print("motorlar hiz= ");
      Serial.println(motorlar_hiz);
      son_isleme_devam_et();
    }
    else if (data == '5')
    {
      motorlar_hiz = motorlar_hiz - 25;
      if (motorlar_hiz < 0)
      {
        motorlar_hiz = 0;
      }
      Serial.print("motorlar hiz= ");
      Serial.println(motorlar_hiz);
      son_isleme_devam_et();
    }
  }
}
void ileri()
{
  digitalWrite(sol_on, 1);
  digitalWrite(sag_on, 1);
  digitalWrite(sol_arka, 0);
  digitalWrite(sag_arka, 0);
  analogWrite(sol_hiz, motorlar_hiz);
  analogWrite(sag_hiz, motorlar_hiz);
}

void geri()
{
  digitalWrite(sol_on, 0);
  digitalWrite(sag_on, 0);
  digitalWrite(sol_arka, 1);
  digitalWrite(sag_arka, 1);
  analogWrite(sol_hiz, motorlar_hiz);
  analogWrite(sag_hiz, motorlar_hiz);
}

void sol()
{
  digitalWrite(sol_on, 1);
  digitalWrite(sag_on, 0);
  digitalWrite(sol_arka, 0);
  digitalWrite(sag_arka, 1);
  analogWrite(sol_hiz, motorlar_hiz);
  analogWrite(sag_hiz, motorlar_hiz);
}

void sag()
{
  digitalWrite(sol_on, 0);
  digitalWrite(sag_on, 1);
  digitalWrite(sol_arka, 1);
  digitalWrite(sag_arka, 0);
  analogWrite(sol_hiz, motorlar_hiz);
  analogWrite(sag_hiz, motorlar_hiz);
}
void dur()
{
  digitalWrite(sol_on, 0);
  digitalWrite(sag_on, 0);
  digitalWrite(sol_arka, 0);
  digitalWrite(sag_arka, 0);
  analogWrite(sol_hiz, 0);
  analogWrite(sag_hiz, 0);
}

void son_isleme_devam_et()
{
  if (son_islem == 1)
  {
    ileri();
  }
  else if (son_islem == 2)
  {
    geri();
  }
  else if (son_islem == 3)
  {
    sol();
  }
  else if (son_islem == 4)
  {
    sag();
  }
}
