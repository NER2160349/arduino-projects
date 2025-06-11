//www.elegoo.com
//2023.05.05

#include "IRremote.h"
#include <LiquidCrystal.h>

int receiver = 6; // Signal Pin of IR receiver to Arduino Digital Pin 11
int redLED = 13; //Pin connected to red LED

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);     // create instance of 'irrecv'
//variable uses to store the last decodedRawData
uint32_t last_decodedRawData = 0;
/*-----( Function )-----*/
String translateIR() // takes action based on IR code received
{
  // Check if it is a repeat IR code 
  if (irrecv.decodedIRData.flags)
  {
    //set the current decodedRawData to the last decodedRawData 
    irrecv.decodedIRData.decodedRawData = last_decodedRawData;
    return("REPEAT!");
  } else
  {
    //output the IR code on the serial monitor
    //Serial.print("IR code:0x");
    //Serial.println(irrecv.decodedIRData.decodedRawData, HEX);
  }
  //map the IR code to the remote key
  switch (irrecv.decodedIRData.decodedRawData)
  {
    case 0xBA45FF00: return("POWER"); Serial.println("Power"); break;
    case 0xB847FF00: return("FUNC/STOP"); break;
    case 0xB946FF00: return("VOL+"); break;
    case 0xBB44FF00: return("FAST BACK");    break;
    case 0xBF40FF00: return("PAUSE");    break;
    case 0xBC43FF00: return("FAST FORWARD");   break;
    case 0xF807FF00: return("DOWN");    break;
    case 0xEA15FF00: return("VOL-");    break;
    case 0xF609FF00: return("UP");    break;
    case 0xE619FF00: return("EQ");    break;
    case 0xF20DFF00: return("ST/REPT");    break;
    case 0xE916FF00: return("0");    break;
    case 0xF30CFF00: return("1");    break;
    case 0xE718FF00: return("2");    break;
    case 0xA15EFF00: return("3");    break;
    case 0xF708FF00: return("4");    break;
    case 0xE31CFF00: return("5");    break;
    case 0xA55AFF00: return("6");    break;
    case 0xBD42FF00: return("7");    break;
    case 0xAD52FF00: return("8");    break;
    case 0xB54AFF00: return("9");    break;
    default:
      return(" Choose again   ");
  }// End Case
  //store the last decodedRawData
  last_decodedRawData = irrecv.decodedIRData.decodedRawData;
  delay(500); // Do not get immediate repeat
} //END translateIR

void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  lcd.begin(16, 2);
  lcd.print("Click \"Power\"");
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode");
  irrecv.enableIRIn(); // Start the receiver
  pinMode(redLED, OUTPUT);

}/*--(end setup )---*/


void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  lcd.clear();
  if (irrecv.decode()) // have we received an IR signal?
  {
    digitalWrite(redLED, HIGH);
    translateIR();
    String command = translateIR();
    lcd.print(command);
    delay(4000);
    digitalWrite(redLED, LOW);
    irrecv.resume(); // receive the next value
  }
}/* --(end main loop )-- */
