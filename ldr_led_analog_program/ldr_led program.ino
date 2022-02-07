const int ldr=14;
const int led=21;
int val;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(ldr,INPUT);
pinMode(led,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
val=analogRead(ldr);
Serial.println(val);
if(val>=1500)
{
  digitalWrite(led,1);
delay(1000);
}
else
{
digitalWrite(led,0);
delay(1000);  
}
}
