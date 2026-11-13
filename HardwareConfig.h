/**
 * ==============================================================================
 * HardwareConfig.h - pin layout for each board version
 * ==============================================================================
 * The board is chosen at the top of the main .ino file (one line to edit).
 * A build that passes -DHARDWARE_Vx (like the GitHub flasher build) overrides it.
 *
 * The GitHub build makes one firmware for EVERY HARDWARE_Vx it finds in the
 * #if / #elif lines below, and students pick their version on the Flash page.
 * Only one board? Keep just the HARDWARE_V1 block (and delete HARDWARE_V2).
 * Adding a board: copy a block, give it the next number, and change the pins.
 * Also add the new name to the "#if !defined(...)" line in the main .ino file.
 *
 * Status LED type, one per board:
 *   STATUS_LED_ACTIVE_LOW  plain LED, ON when the pin is LOW (SuperMini)
 *   (leave it out for an LED that is ON when the pin is HIGH)
 */
#pragma once

#if defined(HARDWARE_V1)
  #define BOARD_VERSION_STR "ESP32-C3 SuperMini - V1"
  #define STATUS_LED        8     // blue onboard LED on the ESP32-C3 SuperMini
  #define STATUS_LED_ACTIVE_LOW
  // Add your project's pins here, for example:
  // #define MOTOR_A_PIN    1

#elif defined(HARDWARE_V2)
  #define BOARD_VERSION_STR "Custom PCB - V2 (example, edit or delete)"
  #define STATUS_LED        8
  #define STATUS_LED_ACTIVE_LOW

#else
  #error "No board chosen. Set the board line at the top of the main .ino file."
#endif
