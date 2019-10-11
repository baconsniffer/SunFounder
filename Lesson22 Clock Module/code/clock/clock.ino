#include <stdio.h>
#include <string.h>
#include <DS1302.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

uint8_t CE_PIN   = 5;  //RST pin attach to
uint8_t IO_PIN   = 6;  //
uint8_t SCLK_PIN = 7;

char buf[50];
char day[10];
/* Serial data cache */
String comdata = "";
int numdata[7] ={0}, j = 0, mark = 0;
/* Create a DS1302 object */
DS1302 rtc(CE_PIN, IO_PIN, SCLK_PIN);


void print_time()
{
    int i;
    /* Get current time from DS1302 */
    Time t = rtc.time();
    /* Convert week from number to name */
    memset(day, 0, sizeof(day));
    switch (t.day)
    {
    case 1: strcpy(day, "Sun"); break;
    case 2: strcpy(day, "Mon"); break;
    case 3: strcpy(day, "Tue"); break;
    case 4: strcpy(day, "Wed"); break;
    case 5: strcpy(day, "Thu"); break;
    case 6: strcpy(day, "Fri"); break;
    case 7: strcpy(day, "Sat"); break;
    }
    /* Format the date code into a buf waiting output */
    snprintf(buf, sizeof(buf), "%s %04d-%02d-%02d %02d:%02d:%02d", day, t.yr, t.mon, t.date, t.hr, t.min, t.sec);
    /* Output date to serial port */
    Serial.println(buf); buf[0] = 0;
    ;snprintf(buf, sizeof(buf), "%04d-%02d-%02d", t.yr, t.mon, t.date);
    lcd.setCursor(0,0);
    lcd.print(t.yr%100);
    Serial.print("--->"); Serial.print(t.yr%100); Serial.println("<---");
    lcd.print("-");
    lcd.print(t.mon/10);
    lcd.print(t.mon%10);
    lcd.print("-");
    lcd.print(t.date/10);
    lcd.print(t.date%10);
    lcd.print(" ");
    lcd.print(day);
//    lcd.print(buf);
    
    lcd.setCursor(4,1);
    lcd.print(t.hr);
    lcd.print(":");
    lcd.print(t.min/10);
    lcd.print(t.min%10);
    lcd.print(":");
    lcd.print(t.sec/10);
    lcd.print(t.sec%10);
}


void setup()
{
    Serial.begin(9600);
    rtc.write_protect(false);
    rtc.halt(false);
    lcd.init();  //initialize the lcd
  lcd.backlight();  //open the backlight 
}

void loop()
{

    /* When the serial port has data, splicing data into variables comdata */
    while (Serial.available() > 0)
    {
        comdata += char(Serial.read());
        delay(2);
        mark = 1;
    }
    /* Separate the comdata string by comma, and the result of the decomposition becomes a number converted to a numdata[] array. */
    if(mark == 1)
    {
        Serial.print("You inputed : ");
        Serial.println(comdata);
        for(int i = 0; i < comdata.length() ; i++)
        {
            if(comdata[i] == ',' || comdata[i] == 0x10 || comdata[i] == 0x13)
            {
                j++;
            }
            else
            {
                numdata[j] = numdata[j] * 10 + (comdata[i] - '0');
            }
        }
        /* Convert the converted numdata into a time format and write it to the DS1302 */
        Time t(numdata[0], numdata[1], numdata[2], numdata[3], numdata[4], numdata[5], numdata[6]);
        rtc.time(t);
        mark = 0;j=0;
        /* Empty the comdata variable to wait for the next input */
        comdata = String("");
        /* Empty numdata */
        for(int i = 0; i < 7 ; i++) numdata[i]=0;
    }
    
    /* Print current time */
    print_time();
    delay(1000);
}
