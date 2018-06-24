int soundSensor=2;
int Relay=4;
boolean RelayStatus=false;
long CurrentClap=0;
long LastClap=0;
//time between claps
long LowerTimeInterval=200;
long UpperTimeInterval=800;
long LastRelayChange=0;

void setup() {
 pinMode(soundSensor,INPUT);
 pinMode(Relay,OUTPUT);
 Serial.begin(9600);
}

void loop() {

  int SensorData=digitalRead(soundSensor); 
  if(SensorData==0){
    CurrentClap=millis();
    Serial.println("Sound Detected ");
    Serial.println(millis());
    if(CurrentClap-LastClap>LowerTimeInterval && CurrentClap-LastClap<UpperTimeInterval && CurrentClap-LastRelayChange>1000){
    
      if(RelayStatus==false){
          RelayStatus=true;
          digitalWrite(Relay,HIGH);
      }
      else{
          RelayStatus=false;
          digitalWrite(Relay,LOW);
      }
      LastRelayChange=millis();
    } 
    LastClap=CurrentClap;
    
  }
}
    
