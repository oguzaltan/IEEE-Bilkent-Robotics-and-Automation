//Sırasıyla yanıp sönen ledler

int a_led = 9; //9. pin'i aled olarak tanımladık.
int b_led = 10; //10. pin'i bled olarak tanımladık.
int c_led = 11; //11. pin'i cled olarak tanımladık.
int d_led = 12; //12. pin'i dled olarak tanımladık.

void setup() {
pinMode (a_led, OUTPUT); //9. pin'i çıkış olarak tanımladık.
pinMode (b_led, OUTPUT); //10. pin'i çıkış olarak tanımladık.
pinMode (c_led, OUTPUT); //11. pin'i çıkış olarak tanımladık.
pinMode (d_led, OUTPUT); //12. pin'i çıkış olarak tanımladık.
}

void loop() {
digitalWrite (a_led, HIGH); //aled'e enerji verdik.
delay (100); //0.1s boyunca yanmasını sağladık
digitalWrite (a_led, LOW); //aled'in enerjisini kestik.
delay (100); //0.1s boyunca yanmasını sağladık
digitalWrite (b_led, HIGH); //bled'e enerji verdik.
delay (100); //0.1s boyunca yanmasını sağladık
digitalWrite (b_led, LOW); //bled'in enerjisini kestik.
delay (100); //0.1s boyunca yanmasını sağladık
digitalWrite (c_led, HIGH); // cled'e enerji verdik.
delay (100); //0.1s boyunca yanmasını sağladık
digitalWrite (c_led, LOW); //cled'in enerjisini kestik.
delay (100); //0.1s boyunca yanmasını sağladık
digitalWrite (d_led, HIGH); // dled'e enerji verdik.
delay (100); //0.1s boyunca yanmasını sağladık
digitalWrite (d_led, LOW); //dled'in enerjisini kestik.
delay (100); //0.1s boyunca yanmasını sağladık
}
