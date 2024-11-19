README för Arduino-projekt
Översikt
Detta projekt kombinerar funktioner för realtidsklocka (RTC), temperaturmätning, en servomotor och en OLED-skärm för att skapa ett interaktivt system. Systemet visar aktuell tid, temperatur och antal knapptryckningar på OLED-skärmen. Dessutom styrs en servomotor baserat på temperaturvärdet.

Funktioner:
Realtidsklocka (RTC):

Använder DS3231-modulen för att hämta och visa aktuell tid.
Temperaturövervakning:

Läser av temperatur med hjälp av en termistor och omvandlar detta till Celsius.
OLED-display:

Visar tid, temperatur och antal knapptryckningar.
Knappinteraktion:

Räknar antalet knapptryckningar och visar detta på OLED-skärmen.
Servomotorstyrning:

Justerar servomotorns position baserat på avläst temperatur.
Krav
Hårdvara:
Arduino (exempelvis Uno)
DS3231 RTC-modul
OLED-skärm (SSD1306)
Servomotor
Termistor
Motstånd (10 kΩ)
Tryckknapp
Kopplingskablar
Bibliotek:
Installera följande bibliotek via Arduino IDE:

RTClib
U8glib
Servo
Kopplingsschema
RTC-modul:

SDA → A4 (Arduino Uno)
SCL → A5 (Arduino Uno)
VCC → 5V
GND → GND
OLED-skärm:

SDA → A4
SCL → A5
VCC → 5V
GND → GND
Servomotor:

Signal → Pin 9
VCC → 5V
GND → GND
Tryckknapp:

Ena benet till Pin 3, andra till GND.
Termistor:

Ena benet till 5V via ett 10 kΩ motstånd och till A0.
Andra benet till GND.
Funktioner i koden
setup()
Initierar seriell kommunikation, RTC-modulen, OLED-skärmen och servomotorn.
Ställer in knappen och andra nödvändiga pinnar.
loop()
Läser tid och temperatur.
Skriver ut tid och temperatur på OLED-skärmen.
Hanterar knapptryckningar och räknar antalet.
Justerar servomotorns position baserat på temperaturen.
getTime()
Hämtar och returnerar den aktuella tiden i formatet HH:MM:SS.
getTemp()
Läser av temperaturen från termistorn och omvandlar den till Celsius.
oledWrite(time, temp)
Skriver tid, temperatur och antal knapptryckningar till OLED-skärmen.
servoWrite(temp)
Justerar servomotorns position baserat på temperaturen.
Användning
Ladda upp koden till din Arduino via Arduino IDE.
Se till att alla komponenter är korrekt anslutna.
Starta projektet. OLED-skärmen visar aktuell tid, temperatur och knapptryckningar. Servomotorn rör sig baserat på temperaturen.
Författare
Hugo Mattsson
