#if ARDUINO > 10605
#include <Mouse.h>
#endif  //ARDUINO > 10605
#include <MouseTo.h>


const byte pin = 10; //Initialize P10

void setup() {
  Mouse.begin();
  MouseTo.setScreenResolution(2200, 1080);
  MouseTo.setCorrectionFactor(0.33);
  pinMode(pin, INPUT_PULLUP);
  
}

void loop() {

  //Start program when pin 10 is connected to ground
  while (digitalRead(pin) == LOW) {
    
    //Set home location
    MouseTo.setTarget(0, 0);      
    while (MouseTo.move() == false) {}
    delay(1000);

    //Click low battery prompt if phone is below 5%
    MouseTo.setTarget(900, 1400);      
    while (MouseTo.move() == false) {}
    delay(600);
    Mouse.click();
    delay(600);
    
    //Move and drag to unlock the screen, then move to top left
    MouseTo.setTarget(525, 1700); 
    while (MouseTo.move() == false) {}
    delay(600);
    Mouse.press();
    MouseTo.setTarget(0, 0);
    while (MouseTo.move() == false) {}
    Mouse.release();
    delay(600);

    //Make sure phone is on home screen
    Mouse.click(MOUSE_MIDDLE);
    delay(600);
    
    //Click to open pull down menu
    Mouse.click();
    delay(600);

    //Move and click settings button
    MouseTo.setTarget(975, 70);      
    while (MouseTo.move() == false) {}
    delay(600);
    Mouse.click();
    delay(600);

    //Move in position and scroll up to make sure the page is in the correct orientation
    MouseTo.setTarget(200, 600);      
    while (MouseTo.move() == false) {}
    delay(600);
    Mouse.move(0, 0, -400);
    delay(50);
    Mouse.move(0, 0, -400);
    delay(600);
    
    //Move to Apps setting and click
    MouseTo.setTarget(0, 1720);
    while (MouseTo.move() == false) {}
    delay(600);
    Mouse.click();
    delay(2000);

    //Scroll to settings app and click
    Mouse.move(100, 127, 400);
    delay(50);
    Mouse.move(0, 127, 400);
    delay(50);
    Mouse.move(0, 40, 400);
    delay(50);
    Mouse.move(0, 0, 400);
    delay(600);
    Mouse.click();
    delay(600);
    
    //Move and click on storage option
    MouseTo.setTarget(900, 1400);      
    while (MouseTo.move() == false) {}
    delay(600);
    Mouse.click();
    delay(600);

    //Move and click on clear data
    MouseTo.setTarget(800, 830);      
    while (MouseTo.move() == false) {}
    delay(600);
    Mouse.click();
    delay(600);

    //Move and click dialog that confirms deletion
    MouseTo.setTarget(870, 1250);      
    while (MouseTo.move() == false) {}
    delay(600);
    Mouse.click();
    delay(600);

    //Reset position
    MouseTo.setTarget(0, 0);      
    while (MouseTo.move() == false) {}
    delay(600);
    
    //Make sure phone is on home screen
    Mouse.click(MOUSE_MIDDLE);
    delay(600);

    //Click to open pull down menu
    Mouse.click();
    delay(600);
    
    //Move and click settings button
    MouseTo.setTarget(975, 70);      
    while (MouseTo.move() == false) {}
    delay(600);
    Mouse.click();
    delay(600);

    //Move, scroll, and click on "about phone" setting
    Mouse.move(100, 127, 400);
    delay(50);
    Mouse.move(0, 127, 400);
    delay(50);
    Mouse.move(0, 40, 400);
    delay(50);
    Mouse.move(0, 0, 400);
    delay(600);
    MouseTo.setTarget(530, 1975);      
    while (MouseTo.move() == false) {}
    delay(600);
    Mouse.click();
    delay(600);

    //Scroll, move, and click on build number 10 times.
    Mouse.move(0, 0, 200);
    delay(600);
    MouseTo.setTarget(530, 550);      
    while (MouseTo.move() == false) {}
    delay(600);
    int count = 0;
    while (count < 10){
      Mouse.click();
      delay(100);
      count++;
    }

    //Right click to revert to previous settings menu
    Mouse.click(MOUSE_RIGHT);
    delay(600);

    //Scroll, Move, and click on dev options
    Mouse.move(0, 0, 400);
    delay(50);
    Mouse.move(0, 0, 400);
    delay(600);
    MouseTo.setTarget(500, 2000);      
    while (MouseTo.move() == false) {}
    delay(600);
    Mouse.click();
    delay(600);

    //Toggle Developer options on and off to clear any previous user settings
    MouseTo.setTarget(950, 280);      
    while (MouseTo.move() == false) {}
    delay(600);
    Mouse.click();
    delay(600);
    Mouse.click();
    delay(600);
    MouseTo.setTarget(900, 1325);      
    while (MouseTo.move() == false) {}
    delay(600);
    Mouse.click();
    delay(600);
    
    //Scroll, Move, and click enable USB debugging button
    Mouse.move(0, 0, 200);
    delay(50);
    MouseTo.setTarget(1000, 550);      
    while (MouseTo.move() == false) {}
    delay(600);
    Mouse.click();
    delay(600);
    
    //Click accept on the dialog prompt
    MouseTo.setTarget(900, 1400);      
    while (MouseTo.move() == false) {}
    delay(600);
    Mouse.click();
    delay(600);
    
    //Return to home screen
    Mouse.click(MOUSE_MIDDLE);
    delay(600);

    while(1) {} //only runs the program one time
  }
}
