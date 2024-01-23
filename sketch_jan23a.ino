
#include <IRremote.h>
#define IR_RECEIVE_PIN 2

#define LED1 8
#define LED2 9
#define LED3 10
#define LED4 11


// int RECV_PIN = 11;
// IRrecv irrecv(RECV_PIN);
// decode_results results;

void setup()
{
  Serial.begin(9600);
  // IrReceiver.enableIRIn(); // Start the receiver
  IrReceiver.begin(IR_RECEIVE_PIN, DISABLE_LED_FEEDBACK);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

}

void loop()
{
  if (IrReceiver.decode())
    {
    //  Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
     
    String ir_code = String(IrReceiver.decodedIRData.command, HEX);

    Serial.println(ir_code);

    if(ir_code == "1")
      digitalWrite(LED1, HIGH);
    else if(ir_code == "0")
      digitalWrite(LED1, LOW);

    if(ir_code == "2")
      digitalWrite(LED2, HIGH);
    else if(ir_code == "7")
      digitalWrite(LED2, LOW);
    
    if(ir_code == "3")
      digitalWrite(LED3, HIGH);
    else if(ir_code == "6")
      digitalWrite(LED3, LOW);

    if(ir_code == "4")
      digitalWrite(LED4, HIGH);
    else if(ir_code == "8")
      digitalWrite(LED4, LOW);



     IrReceiver.resume(); // Receive the next value
    }
}