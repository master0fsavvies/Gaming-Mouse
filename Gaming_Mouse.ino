const int solenoid = 2;
const int rateButton = 6;
const int leftMouse = 5;
const int boxButton = 9;
const int redPin = 10;
const int greenPin = 11;
const int bluePin = 12;
int currentState = 2;
int totalStates = 2;
int rateState = 1;
int totalRateStates = 3;
boolean canFire = true;
int r = 255;
int g = 0;
int b = 0;
int randomR = 0;
int randomG = 0;
int randomB = 0;
int timeOn = 20;
int timeOff = 40;

void setup() {
  pinMode(solenoid, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(leftMouse, INPUT_PULLUP);
  pinMode(boxButton, INPUT_PULLUP);
  pinMode(rateButton, INPUT_PULLUP);
  digitalWrite(solenoid, LOW);
  Serial.begin(9600);
  randomSeed(analogRead(0));
  ledOn();
}

void loop() {
  read();
  if(digitalRead(leftMouse) == HIGH){
    if(currentState == 1){
      recoil();
    }
    if(currentState == 2 && canFire){
      recoil();
      canFire = false;
    }
  }
  else{
    canFire = true;
    ledCycle();
    delay(5);
  }
}

void recoil(){
  digitalWrite(solenoid, HIGH);
  randomRGB();
  delay(timeOn);
  digitalWrite(solenoid, LOW);
  delay(timeOff);
}

void read(){
  if(digitalRead(boxButton) == LOW){
    currentState = (currentState % totalStates) + 1;
    if(currentState == 1){
      analogWrite(redPin, 255);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 0);
    }
    else if(currentState == 2){
      analogWrite(redPin, 0);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 255);
    }
    delay(1000);
  }
  if(digitalRead(rateButton) == LOW){
    rateState = (rateState % totalRateStates) + 1;
    if(rateState == 1){
      analogWrite(redPin, 255);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 0);
      timeOn = 20;
      timeOff = 40;
    }
    else if(rateState == 2){
      analogWrite(redPin, 0);
      analogWrite(greenPin, 255);
      analogWrite(bluePin, 0);
      timeOn = 20;
      timeOff = 30;
    }
    else if(rateState == 3){
      analogWrite(redPin, 0);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 255);
      timeOn = 40;
      timeOff = 40;
    }
    delay(1000);
  }
}

void ledOn(){
   analogWrite(redPin, r);
   analogWrite(greenPin, g);
   analogWrite(bluePin, b);
}

void ledOff(){
   analogWrite(redPin, 0);
   analogWrite(greenPin, 0);
   analogWrite(bluePin, 0);
}

void ledCycle(){
  if (r == 255 && g < 255) {
      g++;
  } else if (g == 255 && r > 0) {
      r--;
  } else if (g == 255 && b < 255) {
      b++;
  } else if (b == 255 && g > 0) {
      g--;
  } else if (b == 255 && r < 255) {
      r++;
  } else if (r == 255 && b > 0) {
      b--;
  }
  ledOn();
}

void randomRGB(){
  randomR = random(256);
  randomG = random(256);
  randomB = random(256);
  analogWrite(redPin, randomR);
  analogWrite(greenPin, randomG);
  analogWrite(bluePin, randomB);
}
