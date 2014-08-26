
const byte pinRed = 8;
const byte pinGreen = 9;
const byte pinBlue = 10;

const byte pinHSync = 4; // 
const byte pinVSync = 5; // frame on/off

void HSync()
{
  digitalWrite(pinHSync, LOW);
  delayMicroseconds(4);
  digitalWrite(pinHSync, HIGH);
}

void VSync()
{
  digitalWrite(pinVSync, LOW);
  delayMicroseconds(64);
  digitalWrite(pinVSync, HIGH);
}

void setPixel(int x, int y)
{
  analogWrite(pinRed, 128);
  analogWrite(pinGreen, 128);
  analogWrite(pinBlue, 128);
  delayMicroseconds(1);
}

void setup()
{
  pinMode(pinRed, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinBlue, OUTPUT);
  analogWrite(pinRed, 128);
  analogWrite(pinGreen, 128);
  analogWrite(pinBlue, 128);
  
  pinMode(pinHSync, OUTPUT);
  pinMode(pinVSync, OUTPUT);
  digitalWrite(pinHSync, HIGH);
  digitalWrite(pinVSync, HIGH);

  setPixel(1, 1);
}

void loop()
{
  VSync(); // 60 Hz -> 16,6 ms
  for (int y=0; y<480; y++) 
  {
    digitalWrite(pinHSync, LOW);
    delayMicroseconds(4);
    digitalWrite(pinHSync, HIGH);
    delayMicroseconds(10);
  }
}

