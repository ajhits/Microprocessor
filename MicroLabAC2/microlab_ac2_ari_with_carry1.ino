//Aritmetic with carry operation

//selection
int value_A1 = 2;
int value_A2 = 3;
int value_A3 = 4;
int value_A4 = 5;

//A inputs
int InputA[4] = {A0,A1,A2,A3};

//B inputs
int InputB[4] = {0,0,1,1};

//2's
int value1[4] = {0,0,0,1};
int value2[4] = {0,0,0,1};

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
    
    //Aritmetic with carry operation
    //F = A
    R4 = digitalRead(A3);
	R3 = digitalRead(A2);
    R2 = digitalRead(A1);
    R1 = digitalRead(A0);
    
    //9,8,7,6 = 0000
    
    digitalWrite(6, R4);
    digitalWrite(7, R3);
    digitalWrite(8, R2);
    digitalWrite(9, R1);
    digitalWrite(10, LOW);
    
    Serial.println("1 selection" );
    
  }
  
  //LLLH
  else if (digitalRead(value_A1) == 0 & 
      digitalRead(value_A2) == 0 &
      digitalRead(value_A3) == 0 &
      digitalRead(value_A4) == 1)
  {
	// w/ carry
    // F = A + B
    
    R4 = digitalRead(A3)|| InputB[0];
	R3 = digitalRead(A2)|| InputB[1];
    R2 = digitalRead(A1)|| InputB[2];
    R1 = digitalRead(A0)|| InputB[3];
    
    digitalWrite(6, R4);
    digitalWrite(7, R3);
    digitalWrite(8, R2);
    digitalWrite(9, R1);
    digitalWrite(10, LOW);
    
    Serial.println("2 selection");
  }
  
    
  //LLHL
  else if (digitalRead(value_A1) == 0 & 
      digitalRead(value_A2) == 0 &
      digitalRead(value_A3) == 1 &
      digitalRead(value_A4) == 0)
  {
    // w/ carry
    // F = A + B'
    
    R4 = digitalRead(A3)|| !InputB[0];
	R3 = digitalRead(A2)|| !InputB[1];
    R2 = digitalRead(A1)|| !InputB[2];
    R1 = digitalRead(A0)|| !InputB[3];
    
    digitalWrite(6, R4);
    digitalWrite(7, R3);
    digitalWrite(8, R2);
    digitalWrite(9, R1);
    digitalWrite(10, LOW);
    
    Serial.println("3 selection");
  }
  
    
  //LLHH
  else if (digitalRead(value_A1) == 0 & 
      digitalRead(value_A2) == 0 &
      digitalRead(value_A3) == 1 &
      digitalRead(value_A4) == 1)
  {
   // F = MINUS 1 (2's Complement)
    
    R4 = (!value1[0]);
    R3 = (!value1[1]);
    R2 = (!value1[2]);
    R1 = (!value1[3]);
 	
    int s1 = R4 ^ value2[0] ^ Cin;
    int s2 = R3 ^ value2[1] ^ Cin;
    int s3 = R2 ^ value2[2] ^ Cin;
    int s4 = R1 ^ value2[3] ^ Cin;
      
    digitalWrite(6, s4);
    digitalWrite(7, s3);
    digitalWrite(8, s2);
    digitalWrite(9, s1);
    digitalWrite(10, LOW);
      
      
    Serial.println("4 selection");
  }
    
  //LHLL
  else if (digitalRead(value_A1) == 0 & 
      digitalRead(value_A2) == 1 &
      digitalRead(value_A3) == 0 &
      digitalRead(value_A4) == 0)
  {
    
    // F = A PLUS AB'
    // A = 1111
    // B = 0011
    // F = 0011 C=1
     
    //AB'
    int ab3 =  digitalRead(A3) & !InputB[3];
    int ab2 =  digitalRead(A2) & !InputB[2];
    int ab1 =  digitalRead(A1) & !InputB[1];
    int ab0 =  digitalRead(A0) & !InputB[0];
    
    Serial.print(ab0);
	Serial.print(ab1);
    Serial.print(ab2);
    Serial.println(ab3);
    
   int Cin = 0;
    
    
   int s1 = digitalRead(A3) ^ ab3 ^ Cin; // 0
   Cin = digitalRead(A3) ^ ab3 & Cin | digitalRead(A3)& ab3 ; // 1

   int s2 = digitalRead(A2) ^ ab2 ^ Cin; // 0
   Cin = digitalRead(A2) ^ ab2 & Cin | digitalRead(A2)& ab2 ; // 1

   int s3 = digitalRead(A1) ^ ab1 ^ Cin;
   Cin = (digitalRead(A1) ^ ab1) & Cin | digitalRead(A1)& ab1;

   int s4 = digitalRead(A0) ^ ab0 ^ Cin;
   Cin = (digitalRead(A0) ^ ab0) & Cin | digitalRead(A0)& ab0 ;
    
 
    
    digitalWrite(10, Cin);
    digitalWrite(6, s4);
    digitalWrite(7, s3);
    digitalWrite(8, s2);
    digitalWrite(9, s1);    
    
    Serial.println("5 selection");
  }
    
  //LHLH
  else if (digitalRead(value_A1) == 0 & 
      digitalRead(value_A2) == 1 &
      digitalRead(value_A3) == 0 &
      digitalRead(value_A4) == 1)
  {
    int Cins = 0;
    
    //A = 1011
    //F = 10011
    
    //okay narin to
    
    //A+B
    int s1 = digitalRead(A3) | InputB[3];
    int s2 = digitalRead(A2) | InputB[2];
    int s3 = digitalRead(A1) | InputB[1];
    int s4 = digitalRead(A0) | InputB[0];
    
    //AB'
    int s5 = digitalRead(A3) & (!InputB[3]); //0
    int s6 = digitalRead(A2) & (!InputB[2]); //0
    int s7 = digitalRead(A1) & (!InputB[1]); //1
    int s8 = digitalRead(A0) & (!InputB[0]); //1
    
    //(A+B) PLUS (AB')
    //s4 s3 s2 s1 = (A+B)
    //s8 s7 s6 s5 = (AB')
    
    //r1
  	int r1 = s1 ^ s5 ^ Cins; // 0
 
  	//Carry
  	Cins = 
    	(s1 ^ s5) & Cins | 
    	s1 & s5; // 0
    
    
   // Serial.print("Carry sa r1:  ");
   // Serial.println(Cins);
 
    //r2
  	int r2 = s2 ^ s6 ^ Cins; // 0
  	//Carry
  	Cins = 
    	(s2 ^ s6) & Cins | 
    	s2 & s6; // 1
 
    //r3
  	int r3 = s3 ^ s7 ^ Cins; // 0
 
  	//Carry
  	Cins = 
    	(s3 ^ s7) & Cins | 
    	s3 & s7; // 1
  
    //r4
  	int r4 = s4 ^ s8 ^ Cins; // 0
 
  	//Carry
  	Cins = 
    	(s4 ^ s8) & Cins | 
    	s4 & s8; // 1   
    
    //Cin r4 r3 r2 r1
    digitalWrite(10,Cins);
    digitalWrite(9,r4);
    digitalWrite(8,r3);
    digitalWrite(7,r2);
    digitalWrite(6,r1);
    
    Serial.println("6 selection");
    
    Serial.println(Cins);
    Serial.print(r4);
    Serial.println(r3);
    Serial.print(r2);
    Serial.println(r1);
  }
    
    //LHHL F=A MINUS B MINUS 1 2's ->Franz


  else if (digitalRead(value_A1) == 0 & 
      digitalRead(value_A2) == 1 &
      digitalRead(value_A3) == 1 &
      digitalRead(value_A4) == 0)
  {
    
 //LHHL F=A MINUS B MINUS 1   (2's complement process)

    int Cout=0;// =Carry0
    int Bin=1;
   int Cinb=0; // = Carry1
  int Cinc=0; // =Carry2
  int fCout=0; // final carry
  
  
  
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
  
   
    int s1 = b1 ^ value1[3] ^ Cinb;
    //Carry
  Cinb =( b1 ^ value1[3]) & Cinb | 
     b1 & value1[3] ; 
  
   int s2 = b2^ value1[2] ^ Cinb;
    //Carry
  Cinb =( b2^ value1[2]) & Cinb | 
     b2& value1[2] ; 
  
   int s3 = b3^ value1[1] ^ Cinb;
    //Carry
  Cinb =( b3^ value1[1]) & Cinb | 
     b3& value1[1] ; 
  
 int s4 = b4^ value1[0] ^ Cinb;
    //Carry
  Cinb =( b4^ value1[0]) & Cinb | 
     b4 & value1[0] ; 
  
  
   
    
     
    // A=1100 + B 2's comp =1101 = 1 1001
  
  //A0 A1 A2 A3 = 1100 -> A
 // S4 S3 S2 S1 = 1101 -> 2'S COMPLEMENT OF B
  
  
  
  int C1 =  digitalRead(A3) ^ (s1) ^ Cout; 
  
  //Carry
  Cout =( digitalRead(A3) ^ s1) & Cout | 
     digitalRead(A3) & s1 ; 
  
  int C2 = digitalRead(A2) ^ (s2) ^ Cout; 
  
  //Carry
  Cout =( digitalRead(A2) ^ s2) & Cout | 
     digitalRead(A2) & s2 ;
  
  int C3 =  digitalRead(A1) ^ (s3) ^ Cout; 
  
  //Carry
  Cout =( digitalRead(A1) ^ s3) & Cout | 
     digitalRead(A1) & s3 ; 
  
 int C4 = digitalRead(A0) ^ (s4) ^ Cout; 
  
  //Carry
  Cout =(digitalRead(A0) ^ s4) & Cout | 
     digitalRead(A0) & s4 ; 

  
    // MINUS 1 =0001
   
   //1 = 0 0 0 1 
    //invert C = 0 0 0 1
    int D1= (!value1[3]);
    int D2= (!value1[2]);
    int D3= (!value1[1]);
    int D4= (!value1[0]);
    
  
   
  
    int s5 = D1 ^ value1[3] ^ Cinc;
    //Carry
  Cinc =( D1 ^ value1[3]) & Cinc | 
     D1 & value1[3] ; 
  
   int s6 = D2^ value1[2] ^ Cinc;
    //Carry
  Cinc =( D2^ value1[2]) & Cinc | 
     D2& value1[2] ; 
  
   int s7 = D3^ value1[1] ^ Cinc;
    //Carry
  Cinc =( D3^ value1[1]) & Cinc | 
     D3& value1[1] ; 
  
    
 int s8 = D4^ value1[0] ^ Cinc;
    //Carry
  Cinc =( D4^ value1[0]) & Cinc | 
     D4 & value1[0] ; 
  
  
 //C4 C3 C2 C1 = 1 1001 -> Answer from A + B 2's
 // S5 S6 S7 S8 = 1111 -> 2'S COMPLEMENT OF 1=0001
  
   
  
  int f1 =  C1 ^ s8 ^ fCout; 
  
  //Carry
  fCout =( C1 ^ s8) & fCout | 
     C1 & s8 ; 
  
  int f2 = C2 ^ s7 ^ fCout; 
  
  //Carry
  fCout =( C2 ^ s7) & fCout | 
     C2 & s7 ;
  
  int f3 =  C3 ^ s6^ fCout; 
  
  //Carry
  fCout =( C3 ^ s6) & fCout | 
     C3 & s6 ; 
  
 int f4 = C4 ^ s5 ^ fCout; 
  
  //Carry
  fCout = (C4 ^ s5) & fCout | 
     C4 & s5 ; 
    
    
    
   
    Serial.println(fCout);
    Serial.println(f4);
    Serial.println(f3);
    Serial.println(f2);
    Serial.println(f1);
    
    digitalWrite(9,f4);
    digitalWrite(8,f3);
    digitalWrite(7,f2);
    digitalWrite(6,f1);
    
 
    Serial.println("7 selection");
  }
  
  //LHHH F=AB’ MINUS 1 ->Franz
  else if (digitalRead(value_A1) == 0 & 
      digitalRead(value_A2) == 1 &
      digitalRead(value_A3) == 1 &
      digitalRead(value_A4) == 1)
  {
    int Cout = 0;
    int Cinc = 0;
    int fCout=0; // final carry
    
     //B = 0 0 1 1 
    //invert B = 1 1 0 0
    int b1= (!InputB[3]);
    int b2= (!InputB[2]);
    int b3= (!InputB[1]);
    int b4= (!InputB[0]);
      
    //    b4 b3 b2 b1 
    //B'= 1   1  0  0
    //A = 1   1  1  1
    //    A0  A1 A2 A3
  
  int s1 = digitalRead(A3) & (b1); 
  int s2 = digitalRead(A2) & (b2); 
  int s3 = digitalRead(A1) & (b3); 
  int s4 = digitalRead(A0) & (b4); 
  
   //1 = 0 0 0 1 
    //invert C = 0 0 0 1
    int D1= (!value1[3]);
    int D2= (!value1[2]);
    int D3= (!value1[1]);
    int D4= (!value1[0]);
    
       
  
    int s5 = D1 ^ value1[3] ^ Cinc;
    //Carry
  Cinc =( D1 ^ value1[3]) & Cinc |  D1 & value1[3] ; 
  
   int s6 = D2^ value1[2] ^ Cinc;
    //Carry
  Cinc =( D2^ value1[2]) & Cinc | D2& value1[2] ; 
  
   int s7 = D3^ value1[1] ^ Cinc;
    //Carry
  Cinc =( D3^ value1[1]) & Cinc | D3& value1[1] ; 
  
    
 int s8 = D4^ value1[0] ^ Cinc;
    //Carry
  Cinc =( D4^ value1[0]) & Cinc | D4 & value1[0] ; 
    
    //S4 S3 S2 S1
    //S8 S7 S6 S5
    
   int f1 =  s1 ^ s8 ^ fCout; 
  
  //Carry
  fCout =( s1 ^ s8) & fCout | 
     s1 & s8 ; 
  
  int f2 = s2 ^ s7 ^ fCout; 
  
  //Carry
  fCout =( s2 ^ s7) & fCout | 
     s2 & s7 ;
  
  int f3 =  s3 ^ s6^ fCout; 
  
  //Carry
  fCout =( s3 ^ s6) & fCout | 
     s3 & s6 ; 
  
 int f4 = s4 ^ s5 ^ fCout; 
  
  //Carry
  fCout = (s4 ^ s5) & fCout | 
     s4 & s5 ; 
  
     Serial.println(f4);
     Serial.println(f3);
       Serial.println(f2);
       Serial.println(f1);
    
     digitalWrite(9,f4);
    digitalWrite(8,f3);
    digitalWrite(7,f2);
    digitalWrite(6,f1);

    Serial.println("8 selection");
  }
    
 //HLLL F=A PLUS AB 
  else if (digitalRead(value_A1) == 1 & 
      digitalRead(value_A2) == 0 &
      digitalRead(value_A3) == 0 &
      digitalRead(value_A4) == 0)
  {
    int fCout = 0;
    
    //AB
  int s1 = digitalRead(A3) & (InputB[3]); 
  int s2 = digitalRead(A2) & (InputB[2]); 
  int s3 = digitalRead(A1) & (InputB[1]); 
  int s4 = digitalRead(A0) & (InputB[0]); 
  
    
    
    //A PLUS AB 
   int f1 =  digitalRead(A3) ^ s1 ^ fCout; 
  //Carry
  fCout =( digitalRead(A3) ^ s1) & fCout | 
     digitalRead(A3) & s1 ; 
  
    int f2 =  digitalRead(A2) ^ s2 ^ fCout; 
  //Carry
  fCout =( digitalRead(A2) ^ s2) & fCout | 
    digitalRead(A2) & s2 ; 
  
    int f3 =  digitalRead(A1) ^ s3 ^ fCout; 
  //Carry
  fCout =( digitalRead(A1) ^ s3) & fCout | 
     digitalRead(A1) & s3 ; 
  
    int f4 =  digitalRead(A0) ^ s4 ^ fCout; 
  //Carry
  fCout =( digitalRead(A0) ^ s4) & fCout | 
     digitalRead(A0) & s4 ; 
  
      
     Serial.println(f4);
     Serial.println(f3);
     Serial.println(f2);
     Serial.println(f1);
    
    digitalWrite(9,f4);
    digitalWrite(8,f3);
    digitalWrite(7,f2);
    digitalWrite(6,f1);

    
    Serial.println("9 selection");
  }   
  
  //HLLH //A PLUS B 
  else if (digitalRead(value_A1) == 1 & 
      digitalRead(value_A2) == 0 &
      digitalRead(value_A3) == 0 &
      digitalRead(value_A4) == 1)
  {
    
    int fCout=0;
    
       //A PLUS B 
   int f1 =  digitalRead(A3) ^ InputB[3] ^ fCout; 
  //Carry
  fCout =( digitalRead(A3) ^ InputB[3]) & fCout | 
     digitalRead(A3) & InputB[3] ; 
  
    int f2 =  digitalRead(A2) ^ InputB[2] ^ fCout; 
  //Carry
  fCout =( digitalRead(A2) ^ InputB[2]) & fCout | 
    digitalRead(A2) & InputB[2] ; 
  
    int f3 =  digitalRead(A1) ^ InputB[1] ^ fCout; 
  //Carry
  fCout =( digitalRead(A1) ^ InputB[1]) & fCout | 
     digitalRead(A1) & InputB[1] ; 
  
    int f4 =  digitalRead(A0) ^ InputB[0] ^ fCout; 
  //Carry
  fCout =( digitalRead(A0) ^ InputB[0]) & fCout | 
     digitalRead(A0) & InputB[0] ; 
    
    Serial.println(fCout);
    Serial.println(f4);
     Serial.println(f3);
     Serial.println(f2);
     Serial.println(f1);
    
     digitalWrite(10,fCout);
    digitalWrite(9,f4);
    digitalWrite(8,f3);
    digitalWrite(7,f2);
    digitalWrite(6,f1);
    
    
    Serial.println("10 selection");
  }
  
    
  //HLHL // F=(A+B’) PLUS AB -> Cumpa
  else if (digitalRead(value_A1) == 1& 
      digitalRead(value_A2) == 0 &
      digitalRead(value_A3) == 1 &
      digitalRead(value_A4) == 0)
  {
       int Cins = 0;
    
    //A = 0001
    //F = 0001 c=1
    
    
    //A+B’
    int s1 = digitalRead(A3) | !InputB[3]; //1
    int s2 = digitalRead(A2) | !InputB[2]; //1
    int s3 = digitalRead(A1) | !InputB[1]; //0
    int s4 = digitalRead(A0)|| !InputB[0]; //1
    
    //AB
    int s5 = digitalRead(A3) & InputB[3]; //0
    int s6 = digitalRead(A2) & InputB[2]; //0
    int s7 = digitalRead(A1) & InputB[1]; //0
    int s8 = digitalRead(A0) & InputB[0]; //1
    
    //(A+B’) PLUS (AB)
    //s4 s3 s2 s1 = (A+B’)
    //s8 s7 s6 s5 = (AB)
    
    //r1
  	int r1 = s1 ^ s5 ^ Cins; // 0
 
  	//Carry
  	Cins = 
    	(s1 ^ s5) & Cins | 
    	s1 & s5; // 0
    
    
 
    //r2
  	int r2 = s2 ^ s6 ^ Cins; // 0
 
  	//Carry
  	Cins = 
    	(s2 ^ s6) & Cins | 
    	s2 & s6; // 1
 
  
    //r3
  	int r3 = s3 ^ s7 ^ Cins; // 0
 
  	//Carry
  	Cins = 
    	(s3 ^ s7) & Cins | 
    	s3 & s7; // 1
  
    //r4
  	int r4 = s4 ^ s8 ^ Cins; // 0
 
  	//Carry
  	Cins = 
    	(s4 ^ s8) & Cins | 
    	s4 & s8; // 1   
    

   
    //Cin r4 r3 r2 r1
    digitalWrite(10,Cins);
    digitalWrite(9,r4);
    digitalWrite(8,r3);
    digitalWrite(7,r2);
    digitalWrite(6,r1);

    Serial.println(Cins);
    Serial.println(r4);
    Serial.println(r3);
    Serial.println(r2);
    Serial.println(r1);
    
    Serial.println("11 selection");
      
  }
//HLHH //AB MINUS 1
  else if (digitalRead(value_A1) == 1 & 
      digitalRead(value_A2) == 0 &
      digitalRead(value_A3) == 1 &
      digitalRead(value_A4) == 1)
  {
     int Cout = 0;
    int Cinc = 0;
    int fCout=0; // final carry
    
  
    //    b4 b3 b2 b1 
    //B'= 1   1  0  0
    //A = 1   1  1  1
    //    A0  A1 A2 A3
  
  int s1 = digitalRead(A3) & InputB[3]; 
  int s2 = digitalRead(A2) & InputB[2]; 
  int s3 = digitalRead(A1) & InputB[1]; 
  int s4 = digitalRead(A0) & InputB[0]; 
  
   //1 = 0 0 0 1 
    //invert C = 0 0 0 1
    int D1= (!value1[3]);
    int D2= (!value1[2]);
    int D3= (!value1[1]);
    int D4= (!value1[0]);
    
       
  
    int s5 = D1 ^ value1[3] ^ Cinc;
    //Carry
  Cinc =( D1 ^ value1[3]) & Cinc |  D1 & value1[3] ; 
  
   int s6 = D2^ value1[2] ^ Cinc;
    //Carry
  Cinc =( D2^ value1[2]) & Cinc | D2& value1[2] ; 
  
   int s7 = D3^ value1[1] ^ Cinc;
    //Carry
  Cinc =( D3^ value1[1]) & Cinc | D3& value1[1] ; 
  
    
 int s8 = D4^ value1[0] ^ Cinc;
    //Carry
  Cinc =( D4^ value1[0]) & Cinc | D4 & value1[0] ; 
    
    //S4 S3 S2 S1
    //S8 S7 S6 S5
    
   int f1 =  s1 ^ s8 ^ fCout; 
  
  //Carry
  fCout =( s1 ^ s8) & fCout | 
     s1 & s8 ; 
  
  int f2 = s2 ^ s7 ^ fCout; 
  
  //Carry
  fCout =( s2 ^ s7) & fCout | 
     s2 & s7 ;
  
  int f3 =  s3 ^ s6^ fCout; 
  
  //Carry
  fCout =( s3 ^ s6) & fCout | 
     s3 & s6 ; 
  
 int f4 = s4 ^ s5 ^ fCout; 
  
  //Carry
  fCout = (s4 ^ s5) & fCout | 
     s4 & s5 ; 
    
       
     Serial.println(f4);
     Serial.println(f3);
       Serial.println(f2);
       Serial.println(f1);
    
     digitalWrite(9,f4);
    digitalWrite(8,f3);
    digitalWrite(7,f2);
    digitalWrite(6,f1);

    
    Serial.println("12 selection");
  } 
  
  //HHLL
  else if (digitalRead(value_A1) == 1 & 
      digitalRead(value_A2) == 1 &
      digitalRead(value_A3) == 0 &
      digitalRead(value_A4) == 0)
  {
    //HHLL
    //F= A PLUS A
    //A = 0001
    //F = 0010

    
    //A PLUS A
    
 	//S1 
    int s1 = digitalRead(A3) ^ digitalRead(A3) ^ Cin; // 0
  
  	//Carry
  	Cin = digitalRead(A3) ^ digitalRead(A3) & Cin | 
      digitalRead(A3)& digitalRead(A3) ; // 1
    
    //S2 
    int s2 = digitalRead(A2) ^ digitalRead(A2) ^ Cin; // 0
  
  	//Carry
  	Cin = digitalRead(A2) ^ digitalRead(A2) & Cin | 
      digitalRead(A2)& digitalRead(A2);  
  
     //S3 
    int s3 = digitalRead(A1) ^ digitalRead(A1) ^ Cin; // 0
  
  	//Carry
  	Cin = digitalRead(A1) ^ digitalRead(A1) & Cin | 
      digitalRead(A1)& digitalRead(A1);    
      
     //S4 
    int s4 = digitalRead(A0) ^ digitalRead(A0) ^ Cin; // 0
  
  	//Carry
  	Cin = digitalRead(A0) ^ digitalRead(A0) & Cin | 
      digitalRead(A0)& digitalRead(A0);
    
  digitalWrite(10,Cin);
  digitalWrite(9,s4);
  digitalWrite(8,s3);
  digitalWrite(7,s2);
  digitalWrite(6,s1);
    
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
  
  //HHHL louise
  else if (digitalRead(value_A1) == 1 & 
      digitalRead(value_A2) == 1 &
      digitalRead(value_A3) == 1 &
      digitalRead(value_A4) == 0)
  {
    int Cins = 0;
    //invertedB
    int IB3 = !InputB[3];
    int IB2 = !InputB[2];
    int IB1 = !InputB[1];
    int IB0 = !InputB[0];
    
   //AorB
    
    int A3s = digitalRead(A3) | IB3; 
    int A2s = digitalRead(A2) | IB2;
    int A1s = digitalRead(A1) | IB1;
    int A0s = digitalRead(A0) | IB0;
    
    //Arithmetic
    // A0s A1s A2s A3s
    
     //S1 
  int s1 = A3s ^ digitalRead(A3) ^ Cins; // 0
  
  //Carry
  Cins = 
    A3s ^ digitalRead(A3) & Cins | 
    A3s & digitalRead(A3); // 1
 
  //s2
  int s2 = A2s ^ digitalRead(A2) ^ Cins; // 0
  //Carry
  Cins = 
    A2s ^ digitalRead(A2) & Cins | 
    A2s & digitalRead(A2) ; // 1
 
  
  //s3
  int s3 = A1s ^ digitalRead(A3) ^ Cins;
  //Carry
  Cins = 
    A1s ^ digitalRead(A1) & Cins | 
    A1s & digitalRead(A1) ;
  
  //s4
  int s4 = A0s ^ digitalRead(A0) ^ Cins;
  //Carry
  Cins = 
    A0s ^ digitalRead(A0) & Cins | 
    A0s & digitalRead(A0) ;
    
    digitalWrite(10,Cins);
    digitalWrite(9,s4);
    digitalWrite(8,s3);
    digitalWrite(7,s2);
    digitalWrite(6,s1);
    
    Serial.println("15 selection");
    Serial.print(A1);
    Serial.print(A2);
    Serial.print(A3);
    Serial.print(A4);
  }  
/////////////////////last session ni louise  
  //HHHH F=A MINUS 1
  else 
  {
    //nandito si Franz nagcocode
    
     int Cout = 0;
    int Cinc = 0;
    int fCout=0; // final carry
    
 
   //1 = 0 0 0 1 
    //invert C = 0 0 0 1
    int D1= (!value1[3]);
    int D2= (!value1[2]);
    int D3= (!value1[1]);
    int D4= (!value1[0]);
    
       
  
    int s5 = D1 ^ value1[3] ^ Cinc;
    //Carry
  Cinc =( D1 ^ value1[3]) & Cinc |  D1 & value1[3] ; 
  
   int s6 = D2^ value1[2] ^ Cinc;
    //Carry
  Cinc =( D2^ value1[2]) & Cinc | D2& value1[2] ; 
  
   int s7 = D3^ value1[1] ^ Cinc;
    //Carry
  Cinc =( D3^ value1[1]) & Cinc | D3& value1[1] ; 
  
    
 int s8 = D4^ value1[0] ^ Cinc;
    //Carry
  Cinc =( D4^ value1[0]) & Cinc | D4 & value1[0] ; 
    
    //S4 S3 S2 S1
    //S8 S7 S6 S5
    
   int f1 =  digitalRead(A3) ^ s8 ^ fCout; 
  
  //Carry
  fCout =( digitalRead(A3) ^ s8) & fCout | 
     digitalRead(A3) & s8 ; 
  
  int f2 = digitalRead(A2) ^ s7 ^ fCout; 
  
  //Carry
  fCout =( digitalRead(A2) ^ s7) & fCout | 
     digitalRead(A2) & s7 ;
  
  int f3 =  digitalRead(A1) ^ s6^ fCout; 
  
  //Carry
  fCout =( digitalRead(A1) ^ s6) & fCout | 
     digitalRead(A1) & s6 ; 
  
 int f4 = digitalRead(A0) ^ s5 ^ fCout; 
  
  //Carry
  fCout = (digitalRead(A0) ^ s5) & fCout | 
     digitalRead(A0) & s5 ; 
    
     
     Serial.println(f4);
     Serial.println(f3);
       Serial.println(f2);
       Serial.println(f1);
    
   
     digitalWrite(9,f4);
    digitalWrite(8,f3);
    digitalWrite(7,f2);
    digitalWrite(6,f1);

    
    
    Serial.println("16 selection");
  }    
}

//main function
void loop(){
  
  
  delay(200);
  	seletion();
  delay(200); 
  

  
}

