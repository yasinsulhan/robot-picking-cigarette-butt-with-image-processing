String command;
int time = 100;
unsigned long previousMillis_left = 0;        // will store last time LED was updated
unsigned long previousMillis_middle = 0;
unsigned long previousMillis_right = 0;

unsigned long previousMillis_left_line = 0;
unsigned long previousMillis_middle_line = 0;
unsigned long previousMillis_right_line = 0;

//right range sensor is defined
int Echo1 = A0;
int Trig1 = A1;

//left range sensor is defined
int Echo2 = A5;
int Trig2 = A4;

//midddle range sensor is defined
int Echo3 = A3;
int Trig3 = A2;


//line sensors channel are defined
int kanal1 =  12;   // right
int kanal3 = 8;     // middle
int kanal4 = 13;    // left

// Motor driver pins are defined.
#define MotorR1 7
#define MotorR2 6
#define MotorRE 9  
#define MotorL1 5
#define MotorL2 4
#define MotorLE 3

const int ledPin = 2; // haberlesme denemek icin led takildi.

int ABS = 80;     // motor speed is defined
int ABS2 = 80;

// distance between sensors and obstacle is defined
int Left_Distance = 0, Right_Distance = 0, Middle_Distance = 0;


// line sensors state
int kanal_durum1;     // right sensor state
int kanal_durum3;     // middle sensor state
int kanal_durum4;     // left sensor state


// Go forward function
void _mForward()
{
  digitalWrite(MotorR1, HIGH);
  digitalWrite(MotorR2, LOW);
 
  digitalWrite(MotorL1, HIGH);
  digitalWrite(MotorL2, LOW);
  analogWrite(MotorRE, ABS);
  analogWrite(MotorLE, ABS2);
  //Serial.print("ROBOT_MOVING_FARWARD");
}

// Go bacward function
void _mBack()
{
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, HIGH);
 
  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, HIGH);
  analogWrite(MotorRE, 100);
  analogWrite(MotorLE, 100);
  //Serial.print("ROBOT_MOVING_BACKWARD");
}

// Turn left function
void _mleft()
{
  digitalWrite(MotorR1, HIGH);
  digitalWrite(MotorR2, LOW);
 
  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, HIGH);
  analogWrite(MotorRE, ABS);
  analogWrite(MotorLE, ABS);
  //Serial.print("ROBOT_MOVING_LEFTWARD");
}

// Turn right function
void _mright(){
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, HIGH);
 
  digitalWrite(MotorL1, HIGH);
  digitalWrite(MotorL2, LOW);
  analogWrite(MotorRE, ABS);
  analogWrite(MotorLE, ABS);
  //Serial.print("ROBOT_MOVING_RIGHTWARD");
}

// Stop function
void _mStop(){
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, LOW);
 
  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, LOW);
  analogWrite(MotorRE, LOW);
  analogWrite(MotorLE, LOW);
  //Serial.print("ROBOT_STOP");
}

//Left Ultrasonic distance measurement function
int Left_Distance_test()
{
  digitalWrite(Trig2, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig2, HIGH);
  delayMicroseconds(20);
  digitalWrite(Trig2, LOW);
  float Fdistance = pulseIn(Echo2, HIGH);
 
  Fdistance = Fdistance / 29 / 2;
  return (int)Fdistance;
  //delayMicroseconds(40);
}

//Middle Ultrasonic distance measurement function
int Middle_Distance_test(){
  digitalWrite(Trig3, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig3, HIGH);
  delayMicroseconds(20);
  digitalWrite(Trig3, LOW);
  float Fdistance = pulseIn(Echo3, HIGH);
 
  Fdistance = Fdistance / 29 / 2;
  return (int)Fdistance;
  //delayMicroseconds(40);
}

//Right Ultrasonic distance measurement function
int Right_Distance_test(){
  digitalWrite(Trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig1, HIGH);
  delayMicroseconds(20);
  digitalWrite(Trig1, LOW);
  float Fdistance = pulseIn(Echo1, HIGH);

  Fdistance = Fdistance / 29 / 2;
  return (int)Fdistance;
  //delayMicroseconds(40);
}


//middle line sensor state is returned
int middle_line_sensor_test()
{
  int kanal_durum = digitalRead(kanal3);
  //Serial.print("Middle channel = ");
  //Serial.println(kanal_durum);
  //Serial.println("____________________________________");
  return int(kanal_durum);
}

//right line sensor state is returned
int right_line_sensor_test()
{
  int kanal_durum = digitalRead(kanal1);
  //Serial.print("Right Channel = ");
  //Serial.println(kanal_durum);
  //Serial.println("____________________________________");
  return int(kanal_durum);
}

//left line sensor state is returned
int left_line_sensor_test()
{
  int kanal_durum = digitalRead(kanal4);
  //Serial.print("Left channel = ");
  //Serial.println(kanal_durum);
  //Serial.println("____________________________________");
  return int(kanal_durum);
}
void setup() {
 
  // Serial comminication starts
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

  // In range sensors, echo is input and trig is output
  pinMode(Echo1, INPUT);
  pinMode(Trig1, OUTPUT);
  pinMode(Echo2, INPUT);
  pinMode(Trig2, OUTPUT);
  pinMode(Echo3, INPUT);
  pinMode(Trig3, OUTPUT);

  // Line sensors channel is defined as input
  pinMode(kanal1, INPUT);
  pinMode(kanal3, INPUT);
  pinMode(kanal4, INPUT);

  // Motors is defined as output
  pinMode(MotorL1, OUTPUT);
  pinMode(MotorL2, OUTPUT);
  pinMode(MotorLE, OUTPUT);
  pinMode(MotorR1, OUTPUT);
  pinMode(MotorR2, OUTPUT);
  pinMode(MotorRE, OUTPUT);

  _mStop();
}

// Main Code
void loop() {

  unsigned long currentMillis = millis();

 
 
  // sensor channel states are taken
/*  
  Left_Distance = Left_Distance_test();
  Middle_Distance = Middle_Distance_test();
  Right_Distance = Right_Distance_test();
*/    

  // distances between obstacles are taken
  if(currentMillis - previousMillis_left >= time)
  {  
      Left_Distance = Left_Distance_test();
      //delay(10);
      previousMillis_left = currentMillis;
  }

  if(currentMillis - previousMillis_middle >= time)
  {  
      Middle_Distance = Middle_Distance_test();
      //delay(10);
      previousMillis_middle = currentMillis;
  }

  if(currentMillis - previousMillis_right >= time)
  {  
      Right_Distance = Right_Distance_test();
      //delay(10);
      previousMillis_right = currentMillis;
  }


  if(currentMillis - previousMillis_left_line >= time)
  {  
      kanal_durum4 = left_line_sensor_test();
      //delay(10);
      previousMillis_left_line = currentMillis;
  }

  if(currentMillis - previousMillis_middle_line >= time)
  {  
      kanal_durum3 = middle_line_sensor_test();
      //delay(10);
      previousMillis_middle_line = currentMillis;
  }

  if(currentMillis - previousMillis_right_line >= time)
  {  
      kanal_durum1 = right_line_sensor_test();
      //delay(10);
      previousMillis_right_line = currentMillis;
  }
 
  //serial comminication led control (robot arms will be added in here.)
  if(Serial.available() > 0)
  {
    message = Serial.readStringUntil('\n');
    //Serial.println(message);

    if(message == "Hello from RPI")
    {
        Serial.println("OK!");
        digitalWrite(ledPin,HIGH);   
    }

    if(message != "Hello from RPI")
    {
        digitalWrite(ledPin, LOW);
    }
    
  }


 
  //if middle distance sensor work
  if(Middle_Distance <= 20)
  {
    if(Right_Distance > Left_Distance) // and it is nearest to the left obstacle
    {
      if((Right_Distance <= 20) && (Left_Distance <= 20)) // also each left and right sensors are closer
      {
        // stop and go backward it is dead end.
        _mStop();
        delay(250);

        _mBack();
        delay(250);

      }
     
      else  // if robot is not much closer to the right obstacle.
      {
        // turn right
        _mright();
        delay(250);

      }
    }

   
    else if(Right_Distance < Left_Distance)  // if the robot is closer to the right obstacle.
    {
        if((Right_Distance <= 20) && (Left_Distance <= 20)) // also the robot is closer to each right and left obstacle.
        {  
          // stop and go backward it is dead end.
          _mStop();
          delay(200);

          _mBack();
          delay(250);
        }
        else
        {
          // if the robot is not closer to the left obstacle, turn left.
          _mleft();
          delay(250);
         
        }
    }
    }
   
    /*bundan sonrası artık çok zor değil çünkü orta sensorun algılamadığı şeyi, kesinlikle sağ ya da sol sensorden sadece birisi algılar*/
    //after upper code, the remained one is very simple because only left or right sensors detect the obstacle. And line channels perceive black line.


    else if(kanal_durum1 == 1 && kanal_durum4 == 1)
    {
      _mBack();
      delay(300);
     
    }

    else if(kanal_durum1 == 1 && kanal_durum4 == 1 && kanal_durum3 == 1)
    {
      _mBack();
      delay(300);
     
    }

   
   
    // if middle channel line sensor perceives black line, stop,go back and turn left
    else if(kanal_durum3 == 1)
    {
      //_mStop();
      //delay(300);
      _mBack();
      delay(300);
      _mleft();
      delay(300);
     
    }

    // if right channel line sensor perceives black line, turn left.
    else if(kanal_durum1 == 1)
    {
      //_mStop();
      //delay(300);
      _mleft();
      delay(200);

    }

    // if left channel line sensor perceives black line, turn right.
    else if(kanal_durum4 == 1)
    {
      //_mStop();
      //delay(300);
 
      _mright();
      delay(300);
    }

    // if the right sensor perceives the obstacle first, turn left.
    else if(Right_Distance <= 15)
    {
      _mleft();
      delay(250);
    }

    // if the left sensor perceives the obstacle first, turn right.
    else if(Left_Distance <= 15)
    {
      _mright();
      delay(250);

    }

   
    // if there is no obstacle, go forward.
    else{
      _mForward();
    }
}
