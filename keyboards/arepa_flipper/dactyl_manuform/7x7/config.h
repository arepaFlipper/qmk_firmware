#pragma once

// WS2812 RGB LED strip input and number of LEDs
/* RGB light config
    36 LEDs for notifications using 144/m led strip
    30 LEDs around the bottom of the board using 60/m led strip
    43 LEDs pointing up, in a grid
*/
//#define RGBLED_SPLIT { 36, 36 }

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_DRIVER SIOD0
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1
#define SERIAL_PIO_USE_PIO0 // use state machine 0 for serial split
#define SPLIT_USB_DETECT
#define WAIT_FOR_USB

//#define SPLIT_TRANSPORT_MIRROR // if this one is enabled the led modes dont sync // This mirrors the master side matrix to the slave side for features that react or require knowledge of master side key presses on the slave side. The purpose of this feature is to support cosmetic use of key events (e.g. RGB reacting to keypresses).
#define SPLIT_LAYER_STATE_ENABLE // This enables syncing of the layer state between both halves of the split keyboard. The main purpose of this feature is to enable support for use of things like OLED display of the currently active layer.
#define SPLIT_MODS_ENABLE // This enables transmitting modifier state (normal, weak and oneshot) to the non primary side of the split keyboard. The purpose of this feature is to support cosmetic use of modifer state (e.g. displaying status on an OLED screen).
#define SPLIT_ACTIVITY_ENABLE // This synchronizes the activity timestamps between sides of the split keyboard, allowing for activity timeouts to occur.

// #define MASTER_LEFT
#define MASTER_RIGHT
