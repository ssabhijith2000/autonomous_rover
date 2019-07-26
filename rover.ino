#define T1 2   //T implies trigger pin
#define T2 3
#define T3 4
#define T4 5
#define E1 6   //E implies echo pin
#define E2 7
#define E3 8
#define E4 9
#define MLF1 A0  //motor pins
#define MLF2 A1
#define MRF1 A2
#define MRF2 A3
#define MLB1 A4
#define MLB2 A5
#define MRB1 A6
#define MRB2 A7
long duration_1,duration_2,duration_3,duration_4;
int distance_l,distance_r,distance_f,distance_b;

void setup()
{
    pinMode(T1, OUTPUT);
    pinMode(T2, OUTPUT);
    pinMode(T3, OUTPUT);
    pinMode(T4, OUTPUT);
    pinMode(E1, INPUT);
    pinMode(E2, INPUT);
    pinMode(E3, INPUT);
    pinMode(E4, INPUT);
    pinMode(MLF1, OUTPUT);
    pinMode(MLF2, OUTPUT);
    pinMode(MRF1, OUTPUT);
    pinMode(MRF2, OUTPUT);
    pinMode(MLB1, OUTPUT);
    pinMode(MLB2, OUTPUT);
    pinMode(MRB1, OUTPUT);
    pinMode(MRB2, OUTPUT);
    Serial.begin(9600);
}


void loop()
{
    leftdetection();
    rightdetection();
    backdetection();
    frontdetection();
    if(distance_b>50 && distance_f>50 && distance_l>50 && distance_r>50)
    {
        forward();
    }
    delay(1000);
}

void leftdetection()
{
     digitalWrite(T1, LOW);
     delayMicroseconds(2);
     digitalWrite(T1, HIGH);
     delayMicroseconds(10);
     digitalWrite(T1, LOW);
     duration_1 = pulseIn(E1, HIGH);
     distance_l = duration_1 * 0.0340 / 2;
     if(distance_l<50)
     {
         Serial.println("right");
         right();
     }
}

void rightdetection()
{
     digitalWrite(T2, LOW);
     delayMicroseconds(2);
     digitalWrite(T2, HIGH);
     delayMicroseconds(10);
     digitalWrite(T2, LOW);
     duration_2 = pulseIn(E2, HIGH);
     distance_r = duration_2 * 0.0340 / 2;
     if(distance_r<50)
     {
         Serial.println("left");
         left();
     }
}

void frontdetection()
{
     digitalWrite(T3, LOW);
     delayMicroseconds(2);
     digitalWrite(T3, HIGH);
     delayMicroseconds(10);
     digitalWrite(T3, LOW);
     duration_3 = pulseIn(E3, HIGH);
     distance_f = duration_3 * 0.0340 / 2;
     if(distance_f<50)
     {
         Serial.println("backward");
         backward();
     }
 }

void backdetection()
{
     digitalWrite(T4, LOW);
     delayMicroseconds(2);
     digitalWrite(T4, HIGH);
     delayMicroseconds(10);
     digitalWrite(T4, LOW);
     duration_4 = pulseIn(E4, HIGH);
     distance_b = duration_4 * 0.0340 / 2;
     if(distance_b<50)
     {
         Serial.println("forward");
         forward();
     }
}

void backward()
{analogWrite(MLF1, 200);
 analogWrite(MLF2, 0);
 analogWrite(MRF1, 200);
 analogWrite(MRF2, 0);
 analogWrite(MLB1, 200);
 analogWrite(MLB2, 0);
 analogWrite(MRB1, 200);
 analogWrite(MRB2, 0);
}

void left()
{ analogWrite(MLF1, 200);
 analogWrite(MLF2, 0);
 analogWrite(MRF1, 0);
 analogWrite(MRF2, 200);
 analogWrite(MLB1, 200);
 analogWrite(MLB2, 0);
 analogWrite(MRB1, 0);
 analogWrite(MRB2, 200);
}

void right()
{analogWrite(MLF1, 0);
 analogWrite(MLF2, 200);
 analogWrite(MRF1, 200);
 analogWrite(MRF2, 0);
 analogWrite(MLB1, 0);
 analogWrite(MLB2, 200);
 analogWrite(MRB1, 200);
 analogWrite(MRB2, 0);
}

void forward()
{analogWrite(MLF1, 0);
 analogWrite(MLF2, 200);
 analogWrite(MRF1, 0);
 analogWrite(MRF2, 200);
 analogWrite(MLB1, 0);
 analogWrite(MLB2, 200);
 analogWrite(MRB1, 0);
 analogWrite(MRB2, 200);
}
