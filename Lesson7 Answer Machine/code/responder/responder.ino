#define player1 2  //the number of the player 1
#define player2 3  //player2 attach to
#define player3 4  //player3 attach to 
#define host    9  //host key attach to
#define buzzerPin 5  //the buzzer attach to    
#define redLED 6  //red LED attach to      
#define yellowLED 7  //yellow LED attach to     
#define blueLED 8  //blue LED attach to 
#define hostLED 10  //host LED attach to

#define uint8 unsigned char
#define uint16 unsigned int

uint8 flag = 0;  //used to indicate the state of host key
uint8 p1State,p2State,p3State,hState = 0;

void setup()
{
  //initialize buzzer,red LED, yellow LED, blue LED and host LED as output
  pinMode(buzzerPin, OUTPUT);     
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);     
  pinMode(blueLED, OUTPUT); 
  pinMode(hostLED, OUTPUT);
  //initialize player1,player2 and player3 as input,combined with pullup
  pinMode(player1, INPUT_PULLUP);
  pinMode(player2, INPUT_PULLUP);
  pinMode(player3, INPUT_PULLUP);    
  pinMode(host, INPUT_PULLUP);
  //turn all the led off
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);  
  digitalWrite(blueLED, LOW); 
  digitalWrite(hostLED, LOW);
}
void loop()
{
  //turn all the led off
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);  
  digitalWrite(blueLED, LOW);  
  digitalWrite(hostLED, LOW);
  //read the state of the host key
  hState = digitalRead(host);
  //when host key pressed
  if(hState == 0)
  {
    if(hState == 0)  //confirm that the host key is pressed
    {
      flag = 1;  //if so,flag is 1
      digitalWrite(hostLED, HIGH);  //turn the host LED on
      delay(200);  
    }
  }
  if(1 == flag)
  {
    //read the state of the button of players
    p1State = digitalRead(player1);  
    p2State = digitalRead(player2);
    p3State = digitalRead(player3);
    //If the player1 press the first
    if(p1State == 0)
    {
      flag = 0;
      digitalWrite(hostLED, LOW);
      Alarm();  //buzzer sound
      digitalWrite(redLED,HIGH);  //turn the red LED on only
      digitalWrite(yellowLED,LOW); 
      digitalWrite(blueLED,LOW); 
      while(digitalRead(host));  //detect the host,if pressed,out of the while loop
    }
    //If the player2 press the first
    if(p2State == 0)
    {
      flag = 0;
      digitalWrite(hostLED, LOW);
      Alarm();
      digitalWrite(redLED,LOW);
      digitalWrite(yellowLED,HIGH); 
      digitalWrite(blueLED,LOW); 
      while(digitalRead(host));
    }
    //If the player3 press the first
    if(p3State == 0)
    {
      flag = 0;
      digitalWrite(hostLED, LOW);
      Alarm();
      digitalWrite(redLED,LOW);
      digitalWrite(yellowLED,LOW); 
      digitalWrite(blueLED,HIGH); 
      while(digitalRead(host));
    }
  }
}
//buzzer sound
void Alarm()         
{
  for(int i=0;i<100;i++){
  digitalWrite(buzzerPin,HIGH); //the buzzer sound
  delay(2);
  digitalWrite(buzzerPin,LOW);  //without sound
  delay(2);                     //when delay time changed,the frequency changed
  }
}
