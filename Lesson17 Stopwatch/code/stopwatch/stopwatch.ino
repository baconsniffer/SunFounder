/*
 * 秒计时器
 * 使用定时器1定时0.1秒溢出，设置计数值count，每0.1秒加1，再设置变量n，当
 * count加到10，即1秒，n加1，也即n便是n秒
 * 计时到10000秒归零
*/

#include <TimerOne.h>
int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;
int p = 9;

int d4 = 10;
int d3 = 11;
int d2 = 12;
int d1 = 13;
//设置变量
long n = 0;
int x = 100;
int del = 5;
int val = 1111;
int count = 0;

void setup()
{
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(p, OUTPUT);
  Timer1.initialize(100000); // set a timer of length 100000 microseconds (or 0.1 sec - or 10Hz => the led will blink 5 times, 5 cycles of on-and-off, per second)
  Timer1.attachInterrupt( add ); // attach the service routine here
}
/***************************************/	 
void loop()
{
  int i,j;
  clearLEDs();
  pickDigit(0);
  pickNumber((n/1000));
  delay(del);
 
  clearLEDs();
  pickDigit(1);
  pickNumber((n%1000)/100);
  delay(del);
 
  clearLEDs();
  pickDigit(2);
  //dispDec(3);
  pickNumber(n%100/10);
  delay(del);
 
  clearLEDs();
  pickDigit(3);
  pickNumber(n%10);
  delay(del);
}
/**************************************/	 
void pickDigit(int x)  
{
  digitalWrite(d1, HIGH);
  digitalWrite(d2, HIGH);
  digitalWrite(d3, HIGH);
  digitalWrite(d4, HIGH);
 
  switch(x)
  {
    case 0: 
    digitalWrite(d1, LOW); 
    break;
    case 1: 
    digitalWrite(d2, LOW); 
    break;
    case 2: 
    digitalWrite(d3, LOW); 
    break;
  default: 
    digitalWrite(d4, LOW); 
    break;
  }
}
	 
void pickNumber(int x)
{
  switch(x)
  {
    default: 
    zero(); 
    break;
    case 1: 
    one(); 
    break;
    case 2: 
    two(); 
    break;
    case 3: 
    three(); 
    break;
    case 4: 
    four(); 
    break;
  case 5: 
    five(); 
    break;
  case 6: 
    six(); 
    break;
  case 7: 
    seven(); 
    break;
  case 8: 
    eight(); 
    break;
  case 9: 
    nine(); 
    break;
  }
}
	 
void dispDec(int x)  //开启小数点
{
  digitalWrite(p, HIGH);
}
	 
void clearLEDs()  //清屏
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(p, LOW);
}
	 
void zero()  //定义数字0时阴极那些管脚开关
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}
	 
void one()  //定义数字1时阴极那些管脚开关
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}
	 
void two()  //定义数字2时阴极那些管脚开关
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}

void three()  //定义数字3时阴极那些管脚开关
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}
	 
void four()  //定义数字4时阴极那些管脚开关
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}
 
void five()  //定义数字5时阴极那些管脚开关
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}
	 
void six()  //定义数字6时阴极那些管脚开关
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}
	 
void seven()  //定义数字7时阴极那些管脚开关
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}
 
void eight()  //定义数字8时阴极那些管脚开关
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}
	 
void nine()  //定义数字9时阴极那些管脚开关
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}
/*******************************************/
void add()
{
    // Toggle LED
    count ++;
    if(count == 10)
    {
      count = 0;
      n ++;
      if(n == 10000)
      {
        n = 0;
      }
    }
}
