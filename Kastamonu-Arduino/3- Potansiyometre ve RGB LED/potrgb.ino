#define YESIL 10
#define MAVI 11
#define KIRMIZI 9

void setup() {

  pinMode(YESIL, OUTPUT);
  pinMode(MAVI, OUTPUT);
  pinMode(KIRMIZI, OUTPUT);

}
const int potK = A0;
const int potY = A1;
const int potM = A2;

int KIRMIZIDeger;
int MAVIDeger;
int YESILDeger;

void loop() {

    KIRMIZIDeger = analogRead(potK);
    YESILDeger = analogRead(potY);
    MAVIDeger = analogRead(potM);
    analogWrite( KIRMIZI, 255 - KIRMIZIDeger );
    analogWrite( YESIL,255 - YESILDeger );
    analogWrite( MAVI, 255 - MAVIDeger );
}

