 //leftsonar
const int lefttrigPin = 12;
const int leftechoPin = 13;
long leftduration;
int leftdistance;

/*rightsonar
const int righttrigPin = 0;
const int rightechoPin = 4;
long rightduration;
int rightdistance;*/

//motors
int leftmotorFp   = 1;
int leftmotorRp   = 2;
int leftmotorEnP  = 3;
int lmspeed=50;

int rightmotorFp  = 7;
int rightmotorRp  = 8;
int rightmotorEnP = 6;
int rmspeed=50;

void setup()
{ setleftsonar();
  //setrightsonar();
  setmotors();  }

void loop() 
{  leftdistance  = trigleftsonar (); 
   //rightdistance = trigrightsonar();
   sonarlogic(leftdistance);
  // sonarlogic(leftdistance, rightdistance);
}

int trigleftsonar()
{  digitalWrite(lefttrigPin,  LOW);
   delayMicroseconds(2);
   digitalWrite(lefttrigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(lefttrigPin,  LOW);

   leftduration = pulseIn(leftechoPin, HIGH);
   leftdistance = leftduration*0.034/2;
   return(leftdistance);
}
/*
int trigrightsonar()
{  digitalWrite(righttrigPin,  LOW);
   delayMicroseconds(2);
   digitalWrite(righttrigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(righttrigPin,  LOW);

   rightduration = pulseIn(rightechoPin, HIGH);
   rightdistance = rightduration*0.034/2;
   return(rightdistance);
}*/

void setmotors ()
{ pinMode(leftmotorFp,       OUTPUT);
  pinMode(leftmotorRp,       OUTPUT);
  pinMode(leftmotorEnP ,     OUTPUT);
  analogWrite(leftmotorEnP, lmspeed);

  pinMode(rightmotorFp,       OUTPUT);
  pinMode(rightmotorRp,       OUTPUT);
  pinMode(rightmotorEnP ,     OUTPUT);
  analogWrite(rightmotorEnP, rmspeed);
}

void setleftsonar()
{ pinMode(lefttrigPin, OUTPUT); 
  pinMode(leftechoPin, INPUT);
}
/*
void setrightsonar()
{ pinMode(righttrigPin, OUTPUT); 
  pinMode(rightechoPin, INPUT);
}*/

//void sonarlogic(int leftdistance, int rightdistance)
void sonarlogic(int leftdistance)
{ if (leftdistance<=10)
  {   moveright();    }
 /* else
  {   moveforward();  }
   
  if (rightdistance<=10)
  {   moveleft();    }
  else
  {   moveforward();  }*/
}

 
void moveright()  //move CW
{      digitalWrite(leftmotorFp, HIGH);
       digitalWrite(leftmotorRp,  LOW);
       digitalWrite(rightmotorFp, LOW);
       digitalWrite(rightmotorRp, LOW);       }
/*
void moveleft() //move CCW
{      digitalWrite(leftmotorFp,   LOW);
       digitalWrite(leftmotorRp,   LOW);
       digitalWrite(rightmotorFp, HIGH);
       digitalWrite(rightmotorRp,  LOW);      }*/
/*
void moveforward()  
{      digitalWrite(leftmotorFp,  HIGH);
       digitalWrite(leftmotorRp,   LOW);
       digitalWrite(rightmotorFp, HIGH);
       digitalWrite(rightmotorRp,  LOW);      }*/
