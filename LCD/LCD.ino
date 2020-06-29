
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  //lcd.print("hello, world!");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  // print the number of seconds since reset:
  lcd.print("Tem. AC Fan Lig.");
   lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print("34.5");

  lcd.setCursor(5, 1);
  // print the number of seconds since reset:
  lcd.print("ON");

  lcd.setCursor(8, 1);
  // print the number of seconds since reset:
  lcd.print("ON");

  lcd.setCursor(12, 1);
  // print the number of seconds since reset:
  lcd.print("ON");
}
