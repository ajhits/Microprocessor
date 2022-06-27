//Aritmetic without carry operation

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
    
	//LLLL
	//F = A PLUS 1
	//A = 1101
	//F = 1110
    Serial.println(digitalRead(A3));
    
	int Cin = 0;  

  //A0 A1 A2 A3
  //0  0  0  1
 
  //S1 
  int s1 = digitalRead(A3) ^ 1 ^ Cin;

  //Carry
  Cin = (digitalRead(A3) ^ 1) & Cin | digitalRead(A3) & 1; 
 
  //S2 
  int s2 = digitalRead(A2) ^ 0 ^ Cin;

  //Carry
  Cin = (digitalRead(A2) ^ 0) & Cin | digitalRead(A2) & 0; 

     
  //S3 
  int s3 = digitalRead(A1) ^ 0 ^ Cin;

  //Carry
  Cin = (digitalRead(A1) ^ 0) & Cin | digitalRead(A1) & 0;
    
   //S4
  int s4 = digitalRead(A0) ^ 0 ^ Cin;

  //Carry
  Cin = (digitalRead(A0) ^ 0) & Cin | digitalRead(A0) & 0;  
    
    digitalWrite(10, Cin);
    digitalWrite(6, s1);
    digitalWrite(7, s2);
    digitalWrite(8, s3);
    digitalWrite(9, s4);
    
    Serial.println("1 selection" );

    
  }
  
  //LLLH
  else if (digitalRead(value_A1) == 0 & 
      digitalRead(value_A2) == 0 &
      digitalRead(value_A3) == 0 &
      digitalRead(value_A4) == 1)
     
  {
    //LLLH
    //F=(A+B) PLUS 1
	//A = 1110
	//F = 0000

    //(A+B)
    int ab3 = digitalRead(A3) | InputB[3];
    int ab2 = digitalRead(A2) | InputB[2];
    int ab1 = digitalRead(A1) | InputB[1];
    int ab0 = digitalRead(A0) | InputB[0];
    
    Serial.print(ab0);
    Serial.print(ab1);
    Serial.print(ab2);
    Serial.println(ab3);

    //(A+B) PLUS 1
    Cin = 0;
    //S1 
  	int s1 = ab3 ^ 1 ^ Cin;

  	//Carry
  	Cin = (ab3 ^ 1) & Cin | ab3 & 1; 
    
 	//S2 
  	int s2 = ab2 ^ 0 ^ Cin;

  	//Carry
  	Cin = (ab2 ^ 0) & Cin | ab2 & 0;    
    
	//S3 
  	int s3 = ab1 ^ 0 ^ Cin;

  	//Carry
  	Cin = (ab1 ^ 0) & Cin | ab1 & 0;   
    
	//S4 
  	int s4 = ab0 ^ 0 ^ Cin;

  	//Carry
  	Cin = (ab0 ^ 0) & Cin | ab0 & 0;     
    
    
    //OUTPUT LED
    digitalWrite(10, Cin);
    digitalWrite(6, s1);
    digitalWrite(7, s2);
    digitalWrite(8, s3);
    digitalWrite(9, s4);
    
    Serial.println("2 selection");
  }
  
  //LLHL
  else if (digitalRead(value_A1) == 0 & 
      digitalRead(value_A2) == 0 &
      digitalRead(value_A3) == 1 &
      digitalRead(value_A4) == 0)
  {
    //LLHL
    //F = (A+B’) PLUS 1
    //A = 0000
    //F = 1101

    //(A+B’)
    int ab3 = digitalRead(A3) | !InputB[3];
	int ab2 = digitalRead(A2) | !InputB[2];
	int ab1 = digitalRead(A1) | !InputB[1];    
	int ab0 = digitalRead(A0) | !InputB[1];    
    
    //F = (A+B’) PLUS 1
    
    //(A+B) PLUS 1
    Cin = 0;
    //S1 
  	int s1 = ab3 ^ 1 ^ Cin;

  	//Carry
  	Cin = (ab3 ^ 1) & Cin | ab3 & 1; 
    
 	//S2 
  	int s2 = ab2 ^ 0 ^ Cin;

  	//Carry
  	Cin = (ab2 ^ 0) & Cin | ab2 & 0;    
    
	//S3 
  	int s3 = ab1 ^ 0 ^ Cin;

  	//Carry
  	Cin = (ab1 ^ 0) & Cin | ab1 & 0;   
    
	//S4 
  	int s4 = ab0 ^ 0 ^ Cin;

  	//Carry
  	Cin = (ab0 ^ 0) & Cin | ab0 & 0;      
    
    digitalWrite(10, Cin);
    digitalWrite(6, s1);
    digitalWrite(7, s2);
    digitalWrite(8, s3);
    digitalWrite(9, s4);
    
    Serial.println("3 selection");
  }
    
  //LLHH
  else if (digitalRead(value_A1) == 0 & 
      digitalRead(value_A2) == 0 &
      digitalRead(value_A3) == 1 &
      digitalRead(value_A4) == 1)
  {

   //LLHH
   //F = ZERO
   //A = 1101
   //0000

    digitalWrite(10, 0);
    digitalWrite(6, 0);
    digitalWrite(7, 0);
    digitalWrite(8, 0);
    digitalWrite(9, 0);
    
    
    Serial.println("4 selection");
  }
    
  //LHLL
  else if (digitalRead(value_A1) == 0 & 
      digitalRead(value_A2) == 1 &
      digitalRead(value_A3) == 0 &
      digitalRead(value_A4) == 0)
  {
    
	//LHLL
	//F = A PLUS AB’ PLUS 1
    //A = 0000
    //F = 0001
    
    //AB’
    int ab3 = digitalRead(A3) & !InputB[3];
	int ab2 = digitalRead(A2) & !InputB[2];
	int ab1 = digitalRead(A1) & !InputB[1];    
	int ab0 = digitalRead(A0) & !InputB[1];
    

    
    //A PLUS AB’

    Cin = 0;
    
    //S1 
  	int s1 = digitalRead(A3) ^ ab3 ^ Cin;

  	//Carry
  	Cin = (digitalRead(A3) ^ ab3) & Cin | digitalRead(A3) & ab3; 
    
    //S2
  	int s2 = digitalRead(A2) ^ ab2 ^ Cin;

  	//Carry
  	Cin = (digitalRead(A2) ^ ab2) & Cin | digitalRead(A2) & ab2; 
    
    //S3
  	int s3 = digitalRead(A1) ^ ab1 ^ Cin;

  	//Carry
  	Cin = (digitalRead(A1) ^ ab1) & Cin | digitalRead(A1) & ab1;
   
        
    //S4
  	int s4 = digitalRead(A0) ^ ab0 ^ Cin;

  	//Carry
  	Cin = (digitalRead(A0) ^ ab0) & Cin | digitalRead(A0) & ab0; 
    

    
    //A PLUS AB’ PLUS 1
    
     //S1 
  	int sS1 = s1 ^ 1 ^ Cin;

  	//Carry
  	Cin = (s1 ^ 1) & Cin | s1 & 1;
    
    //S2 
  	int sS2 = s2 ^ 0 ^ Cin;

  	//Carry
  	Cin = (s2 ^ 0) & Cin | s2 & 0;
  
   //S3
  	int sS3 = s3 ^ 0 ^ Cin;

  	//Carry
  	Cin = (s3 ^ 0) & Cin | s3 & 0;  
    
   //S4
  	int sS4 = s4 ^ 0 ^ Cin;

  	//Carry
  	Cin = (s4 ^ 0) & Cin | s4 & 0;     
    
	//OUTPUT THE LED
    digitalWrite(10,Cin);
    digitalWrite(9,sS4);
    digitalWrite(8,sS3);
    digitalWrite(7,sS2);
    digitalWrite(6,sS1);    
       
    Serial.println("5 selection");
  }
    
  //LHLH
  else if (digitalRead(value_A1) == 0 & 
      digitalRead(value_A2) == 1 &
      digitalRead(value_A3) == 0 &
      digitalRead(value_A4) == 1)
  {
   
      int carry = 0;
	//LHLH
    //F = (A+B) PLUS AB' PLUS 1
    //A = 0001
    //F = 0100

  //(A+B)
    int AorB3 = digitalRead(A3) | InputB[3];
    int AorB2 = digitalRead(A2) | InputB[2];    
    int AorB1 = digitalRead(A1) | InputB[1];
    int AorB0 = digitalRead(A0) | InputB[0];  
    //AorB0, AorB1, AorB2, AorB3

    
  //AB'
    int AandB3 = digitalRead(A3) | InputB[3];
    int AandB2 = digitalRead(A2) | InputB[2];    
    int AandB1 = digitalRead(A1) | InputB[1];
    int AandB0 = digitalRead(A0) | InputB[0];  
    
    //AandB0, AandB1, AandB2, AandB3


  //(A+B) PLUS AB'     
    int S1 = AorB3 ^ AandB3 ^ carry; 
  //Carry
    carry = (AorB3 ^ AandB3) & carry | AorB3 & digitalRead(A3); 

    int S2 = AorB2 ^ AandB2 ^ carry;
  //Carry
    carry = (AorB2 ^ AandB2) & carry | AorB2 & digitalRead(A2); 

    int S3 = AorB1 ^ AandB1 ^ carry; 
  //Carry
    carry = (AorB1 ^ AandB1) & carry | AorB1 & digitalRead(A1); 

    int S4 = AorB0 ^ AandB0 ^ carry; 
  //Carry
    carry = (AorB0 ^ AandB0) & carry | AorB0 & digitalRead(A0); 

  

  //(A+B) PLUS AB' PLUS 1
  int R1 = S1 ^ 0 ^ carry; 
  //Carry
  carry = (R1 ^ 0) & carry | R1 & 0; 

  int R2 = S2 ^ 0 ^ carry; 
  //Carry
  carry = (R2 ^ 0) & carry | R2 & 0; 

  int R3 = S3 ^ 0 ^ carry; 
  //Carry
  carry = (R3 ^ 0) & carry | R3 & 0; 

  int R4 = S4 ^ 0 ^ carry; 
  //Carry
  carry = (R4 ^ 0) & carry | R4 & 0; 


 //OUTPUT THE LED
    digitalWrite(9,R1);
    digitalWrite(8,R2);
    digitalWrite(7,R3);
    digitalWrite(6,R4);
    
    
    Serial.println("6 selection");
  }
    
  //LHHL
  else if (digitalRead(value_A1) == 0 & 
      digitalRead(value_A2) == 1 &
      digitalRead(value_A3) == 1 &
      digitalRead(value_A4) == 0)
  {
    
    //LHHL 
    //F = A MINUS B (2's complement process)
    //A = 0100
    //F = 0001

    int Cout = 0;// =Carry0
    int Bin = 1;
	int Cinb = 0; // = Carry1
  	int Cinc = 0; // =Carry2
  	int fCout = 0; // final carry
  
  
    //B = 0 0 1 1 
    //invert B = 1 1 0 0
    int b1= (!InputB[3]);
    int b2= (!InputB[2]);
    int b3= (!InputB[1]);
    int b4= (!InputB[0]);
      
    
    //B1 B2 B3 B4 
    // 1  1  0  0
    //value1 = 0 0 0 1
    //[3][2][1][0]
    // 0  0  0  1
  
   
   int s1 = b1 ^ 0 ^ Cinb;
    //Carry
  Cinb =( b1 ^ 0) & Cinb | b1 & 0 ; 
  
   int s2 = b2 ^ 0 ^ Cinb;
    //Carry
  Cinb =( b2 ^ 0) & Cinb | b2& 0 ; 
  
   int s3 = b3 ^ 0 ^ Cinb;
    //Carry
  Cinb =( b3 ^ 0) & Cinb | b3& 0 ; 
  
   int s4 = b4 ^ 1 ^ Cinb;
    //Carry
  Cinb =( b4 ^ 1) & Cinb | b4 & 1 ; 
  
    
 // A=1100 + B 2's comp =1101 = 1 1001
 //A0 A1 A2 A3 = 1100 -> A
 // S4 S3 S2 S1 = 1101 -> 2'S COMPLEMENT OF B
  
  int C1 =  digitalRead(A3) ^ (s1) ^ Cout; 
  //Carry
  Cout =( digitalRead(A3) ^ s1) & Cout | digitalRead(A3) & s1 ; 
  
  int C2 = digitalRead(A2) ^ (s2) ^ Cout; 
  //Carry
  Cout =( digitalRead(A2) ^ s2) & Cout | digitalRead(A2) & s2 ;
  
  int C3 =  digitalRead(A1) ^ (s3) ^ Cout; 
  //Carry
  Cout =( digitalRead(A1) ^ s3) & Cout | digitalRead(A1) & s3 ; 
  
 int C4 = digitalRead(A0) ^ (s4) ^ Cout; 
  //Carry
  Cout =(digitalRead(A0) ^ s4) & Cout | digitalRead(A0) & s4 ; 

    
    digitalWrite(9,C1);
    digitalWrite(8,C2);
    digitalWrite(7,C3);
    digitalWrite(6,C4);
    
    Serial.println("7 selection");
  }
    
  //LHHH
  else if (digitalRead(value_A1) == 0 & 
      digitalRead(value_A2) == 1 &
      digitalRead(value_A3) == 1 &
      digitalRead(value_A4) == 1)
  {
    //LHHH
    //F = AB'  
    //A = 0001
    //F = 0000
    
    int carry = 0;
    
  //AB'
    int ab3 = digitalRead(A3) & !InputB[3];
    int ab2 = digitalRead(A2) & !InputB[2];
    int ab1 = digitalRead(A1) & !InputB[1];    
    int ab0 = digitalRead(A0) & !InputB[0];
  // ab3, ab2, ab1, ab0

  //OUTPUT THE LED
    digitalWrite(10,carry);
    digitalWrite(9,ab3);
    digitalWrite(8,ab2);
    digitalWrite(7,ab1);
    digitalWrite(6,ab0);
    
    
    
    Serial.println("8 selection");
  }
    
  //HLLL
  else if (digitalRead(value_A1) == 1 & 
      digitalRead(value_A2) == 0 &
      digitalRead(value_A3) == 0 &
      digitalRead(value_A4) == 0)
  {
    
    //HLLL
    //F = A PLUS AB PLUS 1   
    //A = 0000
    //F = 0001
    
    int carry = 0;
    
  //AB
    int ab3 = digitalRead(A3) & InputB[3];
    int ab2 = digitalRead(A2) & InputB[2];
    int ab1 = digitalRead(A1) & InputB[1];    
    int ab0 = digitalRead(A0) & InputB[0];
  // ab3, ab2, ab1, ab0


  //A PLUS AB  
	Cin = 0;
  //S1 
  	int s1 = digitalRead(A3) ^ ab3 ^ Cin;
  	Cin = (digitalRead(A3) ^ ab3) & Cin | digitalRead(A3) & ab3; 
  //S2
  	int s2 = digitalRead(A2) ^ ab2 ^ Cin;
  	Cin = (digitalRead(A2) ^ ab2) & Cin | digitalRead(A2) & ab2; 
  //S3
  	int s3 = digitalRead(A1) ^ ab1 ^ Cin;
  	Cin = (digitalRead(A1) ^ ab1) & Cin | digitalRead(A1) & ab1;   
  //S4
  	int s4 = digitalRead(A0) ^ ab0 ^ Cin;
  	Cin = (digitalRead(A0) ^ ab0) & Cin | digitalRead(A0) & ab0; 


  //F = A PLUS AB PLUS 1
  //S1 
  	int sS1 = s1 ^ 1 ^ Cin;
  	Cin = (s1 ^ 1) & Cin | s1 & 1;
  //S2 
  	int sS2 = s2 ^ 0 ^ Cin;
  	Cin = (s2 ^ 0) & Cin | s2 & 0;
  //S3
  	int sS3 = s3 ^ 0 ^ Cin;
  	Cin = (s3 ^ 0) & Cin | s3 & 0;  
  //S4
  	int sS4 = s4 ^ 0 ^ Cin;
  	Cin = (s4 ^ 0) & Cin | s4 & 0;   
  
    
  //OUTPUT THE LED
    digitalWrite(10,Cin);
    digitalWrite(9,sS4);
    digitalWrite(8,sS3);
    digitalWrite(7,sS2);
    digitalWrite(6,sS1); 
    
    Serial.println("9 selection");
  }  
  
  //HLLH
  else if (digitalRead(value_A1) == 1 & 
      digitalRead(value_A2) == 0 &
      digitalRead(value_A3) == 0 &
      digitalRead(value_A4) == 1)
  {
       //HLLH
    //F = A PLUS B PLUS 1   
    //A = 0001
    //F = 0101
    
    int carry = 0;
    
  //A PLUS B
    int ab3 = digitalRead(A3) & InputB[3];
    int ab2 = digitalRead(A2) & InputB[2];
    int ab1 = digitalRead(A1) & InputB[1];    
    int ab0 = digitalRead(A0) & InputB[0];
  // ab3, ab2, ab1, ab0


  //A PLUS B  
	Cin = 0;
  //S1 
  	int s1 = digitalRead(A3) ^ InputB[3] ^ Cin;
  	Cin = (digitalRead(A3) ^ InputB[3]) & Cin | digitalRead(A3) & InputB[3]; 
  //S2
  	int s2 = digitalRead(A2) ^ InputB[2] ^ Cin;
  	Cin = (digitalRead(A2) ^ InputB[2]) & Cin | digitalRead(A2) & InputB[2]; 
  //S3
  	int s3 = digitalRead(A1) ^  InputB[1] ^ Cin;
  	Cin = (digitalRead(A1) ^ InputB[1] ) & Cin | digitalRead(A1) & InputB[1] ;   
  //S4
  	int s4 = digitalRead(A0) ^ InputB[0]  ^ Cin;
  	Cin = (digitalRead(A0) ^ InputB[0]) & Cin | digitalRead(A0) & InputB[0]; 



  //F = A PLUS B PLUS 1   
  //S1 
  	int sS1 = s1 ^ 1 ^ Cin;
  	Cin = (s1 ^ 1) & Cin | s1 & 1;
  //S2 
  	int sS2 = s2 ^ 0 ^ Cin;
  	Cin = (s2 ^ 0) & Cin | s2 & 0;
  //S3
  	int sS3 = s3 ^ 0 ^ Cin;
  	Cin = (s3 ^ 0) & Cin | s3 & 0;  
  //S4
  	int sS4 = s4 ^ 0 ^ Cin;
  	Cin = (s4 ^ 0) & Cin | s4 & 0;   
  
  //OUTPUT THE LED
    digitalWrite(10,Cin);
    digitalWrite(9,sS4);
    digitalWrite(8,sS3);
    digitalWrite(7,sS2);
    digitalWrite(6,sS1); 
    
    
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
     // Logical Operation
    // F = AB
    // A = 1111
    // F = 0011
    R4 = digitalRead(A0) & InputB[0];
	R3 = digitalRead(A1) & InputB[1];
    R2 = digitalRead(A2) & InputB[2];
    R1 = digitalRead(A3) & InputB[3];
    
    digitalWrite(6, R1);
    digitalWrite(7, R2);
    digitalWrite(8, R3);
    digitalWrite(9, R4);
    Serial.println("12 selection");
  }  
  
  
  //HHLL
  else if (digitalRead(value_A1) == 1 & 
      digitalRead(value_A2) == 1 &
      digitalRead(value_A3) == 0 &
      digitalRead(value_A4) == 0)
  {  
   int carry = 0;
	//HHLL
    //F= A PLUS A PLUS 1
    //A = 0011
    //F = 0111

  
  //A PLUS A
  
  //S1 
  int s1 = digitalRead(A3) ^ digitalRead(A3) ^ carry; 
  
  //Carry
  carry = 
   (digitalRead(A3) ^ digitalRead(A3)) & carry | 
    digitalRead(A3)& digitalRead(A3); 
    
  //S2 
  int s2 = digitalRead(A2) ^ digitalRead(A2) ^ carry; 
  
  //Carry
  carry = 
    (digitalRead(A2) ^ digitalRead(A2)) & carry | 
    digitalRead(A2)& digitalRead(A2);    
 
   //S3 
  int s3 = digitalRead(A1) ^ digitalRead(A1) ^ carry; 
  
  //Carry
  carry = 
    (digitalRead(A1) ^ digitalRead(A1)) & carry | 
    digitalRead(A1)& digitalRead(A1);   
  
   //S3 
  int s4 = digitalRead(A0) ^ digitalRead(A0) ^ carry; 
  
  //Carry
  carry = 
    (digitalRead(A0) ^ digitalRead(A0)) & carry | 
    digitalRead(A0)& digitalRead(A0);   
    
    //S1 S2 S3 S4
 
   
  //A PLUS 1
  
  //S1 
  int sS1 = s1 ^ 1 ^ carry; 
  //Carry
  carry = (s1 ^ 1) & carry | s1 & 1; 
    
  //S2 
  int sS2 = s2 ^ 0 ^ carry; 
  
  //Carry
  carry = (s2 ^ 0) & carry | s2 & 0;    
 
   //S3 
  int sS3 = s3 ^ 0 ^ carry; 
  
  //Carry
  carry = (s3 ^ 0) & carry | s3 & 0;   
  
   //S3 
  int sS4 = (s4 ^ 0) ^ carry; 
  
  //Carry
  carry = (s4 ^ 0) & carry | s4 & 0;    
    
    
 //OUTPUT THE LED
    digitalWrite(10,carry);
    digitalWrite(9,sS4);
    digitalWrite(8,sS3);
    digitalWrite(7,sS2);
    digitalWrite(6,sS1);
    
    
    Serial.println("13 selection");
  }  
  
  
  
  //HHLH
  else if (digitalRead(value_A1) == 1 & 
      digitalRead(value_A2) == 1 &
      digitalRead(value_A3) == 0 &
      digitalRead(value_A4) == 1)
  {
    
     int Cins = 0;
    //invertedB
    
    //A+B
    int A3s = digitalRead(A3) | InputB[3]; 
    int A2s = digitalRead(A2) | InputB[2];
    int A1s = digitalRead(A1) | InputB[1];
    int A0s = digitalRead(A0) | InputB[0];
  
   //A+B' PLUS A
    
   //S1 
  int s1 = A3s ^ digitalRead(A3) ^ Cins; // 0  
  //Carry
  Cins = 
    A3s ^ digitalRead(A3) & Cins | 
    A3s & digitalRead(A3); // 1
    
   int s2 = A2s ^ digitalRead(A2) ^ Cins; // 0  
  //Carry
  Cins = 
    A2s ^ digitalRead(A2) & Cins | 
    A2s & digitalRead(A2); // 1

	int s3 = A1s ^ digitalRead(A1) ^ Cins; // 0  
  //Carry
  Cins = 
    A1s ^ digitalRead(A1) & Cins | 
    A1s & digitalRead(A1); // 1

 int s4 = A0s ^ digitalRead(A0) ^ Cins; // 0  
  //Carry
  Cins = 
    A0s ^ digitalRead(A0) & Cins | 
    A0s & digitalRead(A0); // 1
    
 //A+B' PLUS A PLUS 1  
  //A0 A1 A2 A3
  //0  0  0  1
 
  //sS1 
  int sS1 = s1 ^ 1 ^ Cin;
  //Carry
  Cin = (s1 ^ 1) & Cin | s1 & 1;
    
  //sS2 
  int sS2 = s2 ^ 0 ^ Cin;
  //Carry
  Cin = (s2 ^ 0) & Cin | s2 & 0;
    
  //sS3  
  int sS3 = s3 ^ 0 ^ Cin;
  //Carry
  Cin = (s3 ^ 0) & Cin | s3 & 0;
    
   //sS4  
  int sS4 = s4 ^ 0 ^ Cin;
  //Carry
  Cin = (s4 ^ 0) & Cin | s4 & 0;
       
 //OUTPUT THE LED
    digitalWrite(9,sS4);
    digitalWrite(8,sS3);
    digitalWrite(7,sS2);
    digitalWrite(6,sS1);
    
    Serial.println("14 selection");
  } 
  
  
  
//HHHL///////////////////////////////////////////
  //F=(A+B’) PLUS A PLUS 1
else if (digitalRead(value_A1) == 1 & 
      digitalRead(value_A2) == 1 &
      digitalRead(value_A3) == 1 &
      digitalRead(value_A4) == 0)
  {
  
     int Cins = 0;
    //invertedB
    
    //A+B
    int A3s = digitalRead(A3) | !InputB[3]; 
    int A2s = digitalRead(A2) | !InputB[2];
    int A1s = digitalRead(A1) | !InputB[1];
    int A0s = digitalRead(A0) | !InputB[0];
  
   //A+B' PLUS A
    
   //S1 
  int s1 = A3s ^ digitalRead(A3) ^ Cins; // 0  
  //Carry
  Cins = 
    A3s ^ digitalRead(A3) & Cins | 
    A3s & digitalRead(A3); // 1
    
   int s2 = A2s ^ digitalRead(A2) ^ Cins; // 0  
  //Carry
  Cins = 
    A2s ^ digitalRead(A2) & Cins | 
    A2s & digitalRead(A2); // 1

	int s3 = A1s ^ digitalRead(A1) ^ Cins; // 0  
  //Carry
  Cins = 
    A1s ^ digitalRead(A1) & Cins | 
    A1s & digitalRead(A1); // 1

 int s4 = A0s ^ digitalRead(A0) ^ Cins; // 0  
  //Carry
  Cins = 
    A0s ^ digitalRead(A0) & Cins | 
    A0s & digitalRead(A0); // 1
    
 //A+B' PLUS A PLUS 1  
  //A0 A1 A2 A3
  //0  0  0  1
 
  //sS1 
  int sS1 = s1 ^ 1 ^ Cin;
  //Carry
  Cin = (s1 ^ 1) & Cin | s1 & 1;
    
  //sS2 
  int sS2 = s2 ^ 0 ^ Cin;
  //Carry
  Cin = (s2 ^ 0) & Cin | s2 & 0;
    
  //sS3  
  int sS3 = s3 ^ 0 ^ Cin;
  //Carry
  Cin = (s3 ^ 0) & Cin | s3 & 0;
    
   //sS4  
  int sS4 = s4 ^ 0 ^ Cin;
  //Carry
  Cin = (s4 ^ 0) & Cin | s4 & 0;
       
 //OUTPUT THE LED
    digitalWrite(9,sS4);
    digitalWrite(8,sS3);
    digitalWrite(7,sS2);
    digitalWrite(6,sS1);
    
    Serial.println("15 selection");

  }
  
  //HHHH
  else 
  {
   	digitalWrite(9,digitalRead(A3));
    digitalWrite(8,digitalRead(A2));
    digitalWrite(7,digitalRead(A1));
    digitalWrite(6,digitalRead(A0));
    

    Serial.print(A1);
    Serial.print(A2);
    Serial.print(A3);
    Serial.print(A4);
    
    Serial.println("16 selection");
  }    
}

//main function
void loop(){
  delay(200);
  seletion();
  Serial.println(".......\n");
  
}

