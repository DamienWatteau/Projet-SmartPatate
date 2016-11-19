#define SET(x,y) (x |=(1<<y))                                  //-Bit set/clear macros
#define CLR(x,y) (x &= (~(1<<y)))                              // |
#define CHK(x,y) (x & (1<<y))                                  // |
#define TOG(x,y) (x^=(1<<y))                                   //-+

#define N 160                                                  //How many frequencies
#include "pitches.h"
#include "note.h"

float results[N];                                              //-Filtered result buffer
float freq[N];                                                 //-Filtered result buffer
int sizeOfArray = N;
 
float peakVoltage = 0;
float peakFreq = 0;

int speaker = 11;

void setup()
{
 
  
  TCCR1A=0b10000010;                                           //-Set up frequency generator
  TCCR1B=0b00011001;                                           //-+
  ICR1=110;
  OCR1A=55;
 
  pinMode(9,OUTPUT);                                           //-Signal generator pin
  pinMode(8,OUTPUT);                                           //-Sync (test) pin
  pinMode(3,OUTPUT);                                           //touché
  pinMode(4,OUTPUT); 
  
  Serial.begin(9600);
 
  for(int i=0;i<N;i++)                                         //-Preset results
    results[i]=0;                                              //-+
}
 
void loop()
{
  Serial.println("coucou!");
  unsigned int d;
 
  int counter = 0;
  peakVoltage = 0;
  peakFreq = 0;
  
  for(unsigned int d=0;d<N;d++)
  {
  
 
    int v=analogRead(0);                                      //-Read response signal
    CLR(TCCR1B,0);                                            //-Stop generator
    TCNT1=0;                                                  //-Reload new frequency
    ICR1=d;                                                   // |
    OCR1A=d/2;                                                //-+
    SET(TCCR1B,0);                                            //-Restart generator
 
    results[d]=results[d]*0.5+(float)(v)*0.5;                 //Filter results
  
    freq[d] = d;
 
                                                              //  -> detection du pic maximum
    if(results[d] > peakVoltage)
    {
      peakVoltage = results[d];
      peakFreq = d;
    }
 
  }
 
 
  TOG(PORTB,0);                                               //-Toggle pin 8 after each sweep (good for scope)


  Serial.print("peakfreq = ");
  Serial.println(peakFreq);
  
  if(peakFreq < 60)
  {
    digitalWrite(4, LOW);                                    //rien
  }
  
  else
  {
    if(peakFreq > 90 && peakFreq < 120)                      //un doigt
    {   
      digitalWrite(4, LOW);
      
     //tone(pin, note, duration)
      tone(3,LA3,Q); 
      delay(1+Q); //delay duration should always be 1 ms more than the note in order to separate them.
      tone(3,LA3,Q);
      delay(1+Q);
      tone(3,LA3,Q);
      delay(1+Q);
      tone(3,F3,E+S);
      delay(1+E+S);
      tone(3,C4,S);
      delay(1+S);
    
      tone(3,LA3,Q);
      delay(1+Q);
      tone(3,F3,E+S);
      delay(1+E+S);
      tone(3,C4,S);
      delay(1+S);
      tone(3,LA3,H);
      delay(1+H);
    
      tone(3,E4,Q); 
      delay(1+Q); 
      tone(3,E4,Q);
      delay(1+Q);
      tone(3,E4,Q);
      delay(1+Q);
      tone(3,F4,E+S);
      delay(1+E+S);
      tone(3,C4,S);
      delay(1+S);
    
      tone(3,Ab3,Q);
      delay(1+Q);
      tone(3,F3,E+S);
      delay(1+E+S);
      tone(3,C4,S);
      delay(1+S);
      tone(3,LA3,H);
      delay(1+H);
    
      tone(3,LA4,Q);
      delay(1+Q);
      tone(3,LA3,E+S);
      delay(1+E+S);
      tone(3,LA3,S);
      delay(1+S);
      tone(3,LA4,Q);
      delay(1+Q);
      tone(3,Ab4,E+S);
      delay(1+E+S);
      tone(3,G4,S);
      delay(1+S);
    
      tone(3,Gb4,S);
      delay(1+S);
      tone(3,E4,S);
      delay(1+S);
      tone(3,F4,E);
      delay(1+E);
      delay(1+E);//PAUSE
      tone(3,Bb3,E);
      delay(1+E);
      tone(3,Eb4,Q);
      delay(1+Q);
      tone(3,D4,E+S);
      delay(1+E+S);
      tone(3,Db4,S);
      delay(1+S);
    
      tone(3,C4,S);
      delay(1+S);
      tone(3,B3,S);
      delay(1+S);
      tone(3,C4,E);
      delay(1+E);
      delay(1+E);//PAUSE QUASI FINE RIGA
      tone(3,F3,E);
      delay(1+E);
      tone(3,Ab3,Q);
      delay(1+Q);
      tone(3,F3,E+S);
      delay(1+E+S);
      tone(3,LA3,S);
      delay(1+S);
    
      tone(3,C4,Q);
      delay(1+Q);
      tone(3,LA3,E+S);
      delay(1+E+S);
      tone(3,C4,S);
      delay(1+S);
      tone(3,E4,H);
      delay(1+H);
    
      tone(3,LA4,Q);
      delay(1+Q);
      tone(3,LA3,E+S);
      delay(1+E+S);
      tone(3,LA3,S);
      delay(1+S);
      tone(3,LA4,Q);
      delay(1+Q);
      tone(3,Ab4,E+S);
      delay(1+E+S);
      tone(3,G4,S);
      delay(1+S);
    
      tone(3,Gb4,S);
      delay(1+S);
      tone(3,E4,S);
      delay(1+S);
      tone(3,F4,E);
      delay(1+E);
      delay(1+E);//PAUSE
      tone(3,Bb3,E);
      delay(1+E);
      tone(3,Eb4,Q);
      delay(1+Q);
      tone(3,D4,E+S);
      delay(1+E+S);
      tone(3,Db4,S);
      delay(1+S);
    
      tone(3,C4,S);
      delay(1+S);
      tone(3,B3,S);
      delay(1+S);
      tone(3,C4,E);
      delay(1+E);
      delay(1+E);//PAUSE QUASI FINE RIGA
      tone(3,F3,E);
      delay(1+E);
      tone(3,Ab3,Q);
      delay(1+Q);
      tone(3,F3,E+S);
      delay(1+E+S);
      tone(3,C4,S);
      delay(1+S);
    
      tone(3,LA3,Q);
      delay(1+Q);
      tone(3,F3,E+S);
      delay(1+E+S);
      tone(3,C4,S);
      delay(1+S);
      tone(3,LA3,H);
      delay(1+H);
    
      delay(2*H);         
    }

    else{                        //pleine main
      
      digitalWrite(4, HIGH);
                       
    }
  }
}
