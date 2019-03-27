const int control_pin = 10;

void setup() {
  Serial1.begin(9600);
  pinMode(control_pin, INPUT_PULLUP);
}

void loop() {
  while(digitalRead(control_pin) == LOW)
  {
   // send_raw_HID_output((uint8_t)0x41);
    Serial1.write((uint8_t)0xFD); // byte 1 indicates HID raw report
    Serial1.write((uint8_t)0x09); // byte 2 legnth of report 
    Serial1.write((uint8_t)0x01); // byte 3 type of report, 0x01 indicates keyboard
    Serial1.write((uint8_t)0x00); // byte 4 modifier
    Serial1.write((uint8_t)0x00); // byte 5 unused
    Serial1.write((uint8_t)0x4F); // byte 6 scan code 1 = right arrow press
    Serial1.write((uint8_t)0x00);
    Serial1.write((uint8_t)0x00);
    Serial1.write((uint8_t)0x00);
    Serial1.write((uint8_t)0x00);
    Serial1.write((uint8_t)0x00);
    delay(200);
    Serial1.write((uint8_t)0xFD); // byte 1 indicates HID raw report
    Serial1.write((uint8_t)0x09); // byte 2 legnth of report 
    Serial1.write((uint8_t)0x01); // byte 3 type of report, 0x01 indicates keyboard
    Serial1.write((uint8_t)0x00); // byte 4 modifier
    Serial1.write((uint8_t)0x00); // byte 5 unused
    Serial1.write((uint8_t)0x00); // byte 6 scan code 1 = right arrow release
    Serial1.write((uint8_t)0x00);
    Serial1.write((uint8_t)0x00);
    Serial1.write((uint8_t)0x00);
    Serial1.write((uint8_t)0x00);
    Serial1.write((uint8_t)0x00);//extra bytes th

    Serial1.write((uint8_t)0xFD); // byte 1 indicates HID raw report
    Serial1.write((uint8_t)0x09); // byte 2 legnth of report 
    Serial1.write((uint8_t)0x01); // byte 3 type of report, 0x01 indicates keyboard
    Serial1.write((uint8_t)0x00); // byte 4 modifier
    Serial1.write((uint8_t)0x00); // byte 5 unused
    Serial1.write((uint8_t)0x4F); // byte 6 scan code 1 = right arrow press
    Serial1.write((uint8_t)0x00);
    Serial1.write((uint8_t)0x00);
    Serial1.write((uint8_t)0x00);
    Serial1.write((uint8_t)0x00);
    Serial1.write((uint8_t)0x00);
    delay(200);
    Serial1.write((uint8_t)0xFD); // byte 1 indicates HID raw report
    Serial1.write((uint8_t)0x09); // byte 2 legnth of report 
    Serial1.write((uint8_t)0x01); // byte 3 type of report, 0x01 indicates keyboard
    Serial1.write((uint8_t)0x00); // byte 4 modifier
    Serial1.write((uint8_t)0x00); // byte 5 unused
    Serial1.write((uint8_t)0x00); // byte 6 scan code 1 = right arrow release
    Serial1.write((uint8_t)0x00);
    Serial1.write((uint8_t)0x00);
    Serial1.write((uint8_t)0x00);
    Serial1.write((uint8_t)0x00);
    Serial1.write((uint8_t)0x00);//extra bytes th

    Serial1.write((uint8_t)0xFD); // byte 1 indicates HID raw report
    Serial1.write((uint8_t)0x09); // byte 2 legnth of report 
    Serial1.write((uint8_t)0x01); // byte 3 type of report, 0x01 indicates keyboard
    Serial1.write((uint8_t)0x00); // byte 4 modifier
    Serial1.write((uint8_t)0x00); // byte 5 unused
    Serial1.write((uint8_t)0x28); // byte 6 scan code 1 = enter key press
    Serial1.write((uint8_t)0x00);
    Serial1.write((uint8_t)0x00);
    Serial1.write((uint8_t)0x00);
    Serial1.write((uint8_t)0x00);
    Serial1.write((uint8_t)0x00);
    delay(200);
    Serial1.write((uint8_t)0xFD); // byte 1 indicates HID raw report
    Serial1.write((uint8_t)0x09); // byte 2 legnth of report 
    Serial1.write((uint8_t)0x01); // byte 3 type of report, 0x01 indicates keyboard
    Serial1.write((uint8_t)0x00); // byte 4 modifier
    Serial1.write((uint8_t)0x00); // byte 5 unused
    Serial1.write((uint8_t)0x00); // byte 6 scan code 1 = enter key release
    Serial1.write((uint8_t)0x00);
    Serial1.write((uint8_t)0x00);
    Serial1.write((uint8_t)0x00);
    Serial1.write((uint8_t)0x00);
    Serial1.write((uint8_t)0x00);//extra bytes th
    delay(100);
  }
  
}

void send_raw_HID_output(uint8_t input)
{
  Serial1.write((uint8_t)0xFD); // byte 1 indicates HID raw report
  Serial1.write((uint8_t)0x09); // byte 2 legnth of report 
  Serial1.write((uint8_t)0x01); // byte 3 type of report, 0x01 indicates keyboard
  Serial1.write((uint8_t)0x00); // byte 4 modifier
  Serial1.write((uint8_t)0x00); // byte 5 unused
  Serial1.write(input); // byte 6 scan code 1 = press input
  Serial1.write((uint8_t)0x00);
  Serial1.write((uint8_t)0x00);
  Serial1.write((uint8_t)0x00);
  Serial1.write((uint8_t)0x00);
  Serial1.write((uint8_t)0x00); //extra bytes that could be used to send more key presses

  Serial1.write((uint8_t)0xFD); // byte 1 indicates HID raw report
  Serial1.write((uint8_t)0x09); // byte 2 legnth of report 
  Serial1.write((uint8_t)0x01); // byte 3 type of report, 0x01 indicates keyboard
  Serial1.write((uint8_t)0x00); // byte 4 modifier
  Serial1.write((uint8_t)0x00); // byte 5 unused
  Serial1.write((uint8_t)0x00); // byte 6 scan code 1 = release
  Serial1.write((uint8_t)0x00);
  Serial1.write((uint8_t)0x00);
  Serial1.write((uint8_t)0x00);
  Serial1.write((uint8_t)0x00);
  Serial1.write((uint8_t)0x00); //extra bytes that could be used to send more key presses
  
}
