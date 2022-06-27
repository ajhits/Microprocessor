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
int Cin = 0;

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



//selection
void seletion() {
 
  //LLLL
  if (digitalRead(value_A1) == 0 & 
      digitalRead(value_A2) == 0 &
      digitalRead(value_A3) == 0 &
      digitalRead(value_A4) == 0)
  {
    //R1 R2 R3 R4 = BINARY
    
    
    //Logical Operation
     //F = A'
    R4 = !digitalRead(A3);
	  R3 = !digitalRead(A2);
    R2 = !digitalRead(A1);
    R1 = !digitalRead(A0);
    
    digitalWrite(6, R4);
    digitalWrite(7, R3);
    digitalWrite(8, R2);
    digitalWrite(9, R1);
    
    Serial.println("1 selection" );
  }
  
  //LLLH
  else if (digitalRead(value_A1) == 0 & 
      digitalRead(value_A2) == 0 &
      digitalRead(value_A3) == 0 &
      digitalRead(value_A4) == 1)
  {

    //Logical Operation
    // F (A + B)'
    R4 = digitalRead(A3) || InputB[0];
	  R3 = digitalRead(A2) || InputB[1];
    R2 = digitalRead(A1) || InputB[2];
    R1 = digitalRead(A0) || InputB[3];
    
    //Inverted
    R4 = !InputB[0];
    R3 = !InputB[1];
    R2 = !InputB[2];
    R1 = !InputB[3];
      
    digitalWrite(6, R1);
    digitalWrite(7, R2);
    digitalWrite(8, R3);
    digitalWrite(9, R4);

    Serial.println("2 selection");
  }
  
    
  //LLHL
  else if (digitalRead(value_A1) == 0 & 
      digitalRead(value_A2) == 0 &
      digitalRead(value_A3) == 1 &
      digitalRead(value_A4) == 0)
  {

    //Logical Operation
    // F = A' B
    R4 = !digitalRead(A3); 
    R3 = !digitalRead(A2);
    R2 = !digitalRead(A1);
    R1 = !digitalRead(A0);
      
    R4 = digitalRead(A3) && InputB[0];
	  R3 = digitalRead(A2) && InputB[1];
    R2 = digitalRead(A1) && InputB[2];
    R1 = digitalRead(A0) && InputB[3];
    
    digitalWrite(6, R4);
    digitalWrite(7, R3);
    digitalWrite(8, R2);
    digitalWrite(9, R1);  
    
    Serial.println("3 selection");
  }
  
  //LLHH
  else if (digitalRead(value_A1) == 0 & 
      digitalRead(value_A2) == 0 &
      digitalRead(value_A3) == 1 &
      digitalRead(value_A4) == 1)
  {
    
    Serial.println("4 selection");
  }
    
  //LHLL
  else if (digitalRead(value_A1) == 0 & 
      digitalRead(value_A2) == 1 &
      digitalRead(value_A3) == 0 &
      digitalRead(value_A4) == 0)
  {
    Serial.println("5 selection");
  }
    
  //LHLH
  else if (digitalRead(value_A1) == 0 & 
      digitalRead(value_A2) == 1 &
      digitalRead(value_A3) == 0 &
      digitalRead(value_A4) == 1)
  {
    Serial.println("6 selection");
  }
    
  //LHHL
  else if (digitalRead(value_A1) == 0 & 
      digitalRead(value_A2) == 1 &
      digitalRead(value_A3) == 1 &
      digitalRead(value_A4) == 0)
  {
    Serial.println("7 selection");
  }
    
  //LHHH
  else if (digitalRead(value_A1) == 0 & 
      digitalRead(value_A2) == 1 &
      digitalRead(value_A3) == 1 &
      digitalRead(value_A4) == 1)
  {
    Serial.println("8 selection");
  }
    
  //HLLL
  else if (digitalRead(value_A1) == 1 & 
      digitalRead(value_A2) == 0 &
      digitalRead(value_A3) == 0 &
      digitalRead(value_A4) == 0)
  {
    Serial.println("9 selection");
  }  
  
  //HLLH
  else if (digitalRead(value_A1) == 1 & 
      digitalRead(value_A2) == 0 &
      digitalRead(value_A3) == 0 &
      digitalRead(value_A4) == 1)
  {
    Serial.println("10 selection");
  }
  
    
  //HLHL
  else if (digitalRead(value_A1) == 1 & 
      digitalRead(value_A2) == 0 &
      digitalRead(value_A3) == 1 &
      digitalRead(value_A4) == 0)
  {
    Serial.println("11 selection");
  }  
  
  //HLHH
  else if (digitalRead(value_A1) == 1 & 
      digitalRead(value_A2) == 0 &
      digitalRead(value_A3) == 1 &
      digitalRead(value_A4) == 1)
  {
    Serial.println("12 selection");
  }  
  
  //HHLL
  else if (digitalRead(value_A1) == 1 & 
      digitalRead(value_A2) == 1 &
      digitalRead(value_A3) == 0 &
      digitalRead(value_A4) == 0)
  {
    Serial.println("13 selection");
  }  
  
  //HHLH
  else if (digitalRead(value_A1) == 1 & 
      digitalRead(value_A2) == 1 &
      digitalRead(value_A3) == 0 &
      digitalRead(value_A4) == 1)
  {
    Serial.println("14 selection");
  } 
  
  //HHHL
  else if (digitalRead(value_A1) == 1 & 
      digitalRead(value_A2) == 1 &
      digitalRead(value_A3) == 1 &
      digitalRead(value_A4) == 0)
  {
    Serial.println("15 selection");
  }  
  
  //HHHH
  else 
  {
    Serial.println("16 selection");
  }    
}

//main function
void loop(){
  seletion();
  Serial.println(".......\n");
  
}


