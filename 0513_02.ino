byte seven_seg_digits[10][7]={{0,0,0,0,0,0,1},
{1,0,0,1,1,1,1},
{0,0,1,0,0,1,0},
{0,0,0,0,1,1,0},
{1,0,0,1,1,0,0},
{0,1,0,0,1,0,0},
{0,1,0,0,0,0,0},
{0,0,0,1,1,1,1},
{0,0,0,0,0,0,0},
{0,0,0,1,1,0,0}
};


byte pin_numbers[7]={2,3,4,5,6,7,8};
const int buttonPin=12;
int present_buttonState=0; int pre_buttonState=0;
int buttonState=1;
int num=0;
void setup() {
  Serial.begin(9600);
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
    pinMode(7,OUTPUT);
    pinMode(8,OUTPUT);
digitalWrite(9,0);
digitalWrite(buttonPin,HIGH);
pinMode(buttonPin,INPUT);
}

void sevenSegWrite(byte digit){
  byte pin=2;
  for(byte seg=0;seg<7;seg++){
    digitalWrite(pin_numbers[seg],seven_seg_digits[digit][seg]);
    pin++;
  }
}
void loop() {
  present_buttonState=digitalRead(buttonPin);
  Serial.println(present_buttonState);
  if(pre_buttonState==0 && present_buttonState==1){
    num++;
    if(num>9){
      num=0;
    }
    pre_buttonState=1;
  }

  if(pre_buttonState==1 && present_buttonState==0) pre_buttonState=0;
  sevenSegWrite(num);
}
