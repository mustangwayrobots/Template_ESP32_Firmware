/**
 * ==============================================================================
 * Template_ESP32_Firmware.ino - starter sketch for a new club firmware project
 * ==============================================================================
 * FIRST THING TO DO in a new repo made from this template:
 *   Rename this file so it matches your repo name EXACTLY (capital letters too).
 *   Repo "Sumo_Bot"  ->  this file must be "Sumo_Bot.ino".
 *   The automatic GitHub build looks for the .ino named after its folder.
 *
 * Board in Arduino IDE: Tools > Board > esp32 > MakerGO ESP32 C3 SuperMini
 * (same core version as CORE_VERSION in .github/workflows/build.yml)
 *
 * What it does: blinks the status LED and prints to the Serial Monitor
 * (115200 baud), so you can check the board and the Flash page work.
 * Replace it with your own project code.
 */

// --- Board choice: change HARDWARE_V1 below if you add more board versions ---
// (A build that passes -DHARDWARE_Vx, like the GitHub flasher build, overrides this.)
#if !defined(HARDWARE_V1) && !defined(HARDWARE_V2)
  #define HARDWARE_V1
#endif

#include "HardwareConfig.h"

const unsigned long BLINK_MS = 500;

void setLed(bool on) {
#if defined(STATUS_LED_ACTIVE_LOW)
  digitalWrite(STATUS_LED, on ? LOW : HIGH);
#else
  digitalWrite(STATUS_LED, on ? HIGH : LOW);
#endif
}

void setup() {
  Serial.begin(115200);
  pinMode(STATUS_LED, OUTPUT);
  setLed(false);
  delay(500);
  Serial.println();
  Serial.println("Mustang Way Robots - template firmware");
  Serial.print("Board: ");
  Serial.println(BOARD_VERSION_STR);
}

void loop() {
  static bool ledOn = false;
  static unsigned long last = 0;

  if (millis() - last >= BLINK_MS) {
    last = millis();
    ledOn = !ledOn;
    setLed(ledOn);
    Serial.println(ledOn ? "LED on" : "LED off");
  }
}
