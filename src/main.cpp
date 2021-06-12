#include <Arduino.h>
#include <Keypad.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

byte rowPins[ROWS] = {9, 7, 8, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad kpd = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
Servo servo;

LiquidCrystal_I2C lcd(0x3F, 16, 2);

const int OPEN_ANGLE = 150;
const int CLOSED_ANGLE = 20;

void setup()
{
  Serial.begin(9600);
  servo.attach(13);
  servo.write(OPEN_ANGLE);

  lcd.init();
  lcd.backlight();

  // log firmware version ardruino
  Serial.println("ardruino door firmware v1.1.1");
}

static void clearLine(byte line)
{
  lcd.setCursor(0, line);
  lcd.print("                ");
  lcd.setCursor(0, line);
  lcd.noBlink();
}

void loop()
{
  char key = kpd.getKey();

  if (key)
  {
    Serial.println(key);
    Serial.flush();
  }

  if (Serial.available() > 0)
  {
    // read the incoming byte:
    char ch = (char)Serial.read();

    switch (ch)
    {
    case '@':
      clearLine(1);
      lcd.setCursor(6, 1);
      lcd.print("....");
      lcd.setCursor(6, 1);
      lcd.blink();
      break;
    case '#':
      lcd.setCursor(6, 1);
      lcd.print("*...");
      lcd.setCursor(7, 1);
      lcd.blink();
      break;
    case '$':
      clearLine(1);
      lcd.setCursor(6, 1);
      lcd.print("**..");
      lcd.setCursor(8, 1);
      lcd.blink();
      break;
    case '%':
      clearLine(1);
      lcd.setCursor(6, 1);
      lcd.print("***.");
      lcd.setCursor(9, 1);
      lcd.blink();
      break;
    case '&':
      clearLine(1);
      lcd.setCursor(6, 1);
      lcd.print("**** #");
      lcd.setCursor(11, 1);
      lcd.blink();
      break;
    case '(':
      servo.write(OPEN_ANGLE);
      break;
    case ')':
      servo.write(CLOSED_ANGLE);
      break;
    case '[':
      clearLine(0);
      break;
    case ']':
      clearLine(1);
      break;
    default:
      if (ch > 31)
      {
        lcd.print(ch);
      }
      break;
    }
  }
}