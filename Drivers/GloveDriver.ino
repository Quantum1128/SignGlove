const float VCC = 5.0; 
const float R_S = 47000.0; 
const int TOTAL = A0;
int vL;

class finger{
  public: 
    int ADC12; 
    int inPin; 

    float getR(){
      int adcT = analogRead(this->inPin-1);
      float Vd; 

      this->ADC12 = analogRead(this->inPin); 
      
      if(this->inPin == A1) Vd = VCC - (analogRead(A0) * (5.0 / 1023.0)); 
      
      else Vd = vL - (adcT * (5.0 / 1023.0));  
      
      float Rt = (((VCC / (VCC - (analogRead(A0) * (5.0 / 1023.0))) - 1) * R_S));

      float vdr = (analogRead(this->inPin - 1) * (5.0/1023.0) - analogRead(this->inPin) * (5.0/1023.0)); 

      float Ro = (vdr / (analogRead(A0) * (5.0/1023.0))) * Rt;

      Serial.println(String(Ro));

      return Ro; 
    }
};

finger indexF; 
finger middleF; 
finger ringF;

void setup() {
  indexF.inPin = A1;
  middleF.inPin = A2; 
  ringF.inPin = A3; 
  pinMode(TOTAL, INPUT); 
  pinMode(indexF.inPin, INPUT); 
  pinMode(middleF.inPin, INPUT); 
  pinMode(ringF.inPin, INPUT); 
  Serial.begin(9600);
}

void loop() {
  float r1 = indexF.getR(), r2 = middleF.getR(), r3 = ringF.getR();;
  delay(1000);
}
