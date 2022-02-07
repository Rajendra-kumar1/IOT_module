const int LED1=22;
const int LED2=15;
void setup() {
  // put your setup code here, to run once:
pinMode(LED1,OUTPUT);
Serial.begin(115200);

pinMode(LED2,OUTPUT);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LED1,HIGH);
Serial.println("LED1 0n\n");
delay(500);

digitalWrite(LED1,LOW);
Serial.println("LED1 off\n");
delay(1000);

digitalWrite(LED2,HIGH);
Serial.println("LED2 0n\n");
delay(2000);

digitalWrite(LED2,LOW);
Serial.println("LED2 off\n");
delay(3000);
}

