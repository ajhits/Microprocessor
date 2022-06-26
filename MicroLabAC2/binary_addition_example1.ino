//selection
int value_A1 = 2;
int value_A2 = 3;
int value_A3 = 4;
int value_A4 = 5;

//A inputs
int InputA[4] = {A0,A1,A2,A3};

//B inputs
int InputB[4] = {0,0,1,1};

//Output LED
int R1 = 0;
int R2 = 0;
int R3 = 0;
int R4 = 0;


void setup()
{
  Serial.begin(9600);
  
//LED Output  
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  
//For selection  
  pinMode(value_A1, INPUT_PULLUP);
  pinMode(value_A2, INPUT_PULLUP);
  pinMode(value_A3, INPUT_PULLUP);
  pinMode(value_A4, INPUT_PULLUP);
  
// for Input A  
  for (int i = 0; i<4; i++){
    pinMode(InputA[i], INPUT_PULLUP);
  }
  
  Serial.println("loading.......\n");
}


//main function
void loop(){
  
delay(200);
 int Cin = 0; //Carry
  
  //A = 1110
  //B = 0011
  //F = 10001  
  
  //men men
  //tama sakin
 
  //S1 
  int s1 = digitalRead(A3) ^ InputB[3] ^ Cin; // 0
  
  //Carry
  Cin = 
    digitalRead(A3) ^ InputB[3] & Cin | 
    digitalRead(A3)& InputB[3] ; // 1
  
  //s2
  int s2 = digitalRead(A2) ^ InputB[2] ^ Cin; // 0
  //Carry
  Cin = 
    digitalRead(A2) ^ InputB[2] & Cin | 
    digitalRead(A2)& InputB[2] ; // 1
 
  
  //s3
  int s3 = digitalRead(A1) ^ InputB[1] ^ Cin;
  //Carry
  Cin = 
    digitalRead(A1) ^ InputB[1] & Cin | 
    digitalRead(A1)& InputB[1] ;
  
  //s4
  int s4 = digitalRead(InputA[0]) ^ InputB[0] ^ Cin;
  //Carry
  Cin = 
    digitalRead(A0) ^ InputB[0] & Cin | 
    digitalRead(A0)& InputB[0] ;
  
  
  
 
  digitalWrite(10,Cin);
  digitalWrite(9,s4);
  digitalWrite(8,s3);
  digitalWrite(7,s2);
  digitalWrite(6,s1);
  
  delay(200);
  Serial.println(".......\n");
  
}


 
  

  






























