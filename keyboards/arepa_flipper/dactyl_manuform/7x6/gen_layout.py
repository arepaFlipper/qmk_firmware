import json

key_labels = [
    "KC_ESC" , "KC_RPRN" , "KC_F1"  , "KC_F2" , "KC_F3" , "KC_F4" , "KC_F5" , "KC_F6"  ,  "KC_F7" , "KC_F8"  , "KC_F9" , "KC_F10" , "KC_F11"   , "KC_F12" ,
    "KC_VOLU", "KC_GRV"  , "KC_1"   , "KC_2"  , "KC_3"  , "KC_4"  , "KC_5"  ,  "KC_6"  , "KC_7"   , "KC_8"   , "KC_9"  , "KC_0"   , "KC_MINS"  , "KC_EQL",
    "KC_VOLD", "KC_TAB"  , "KC_Q"   , "KC_W"  , "KC_E"  , "KC_R"  , "KC_T"  ,  "KC_Y"  , "KC_U"   , "KC_I"   , "KC_O"  , "KC_P"   , "KC_LBRC"  , "KC_RBRC",
    "KC_BRIU", "KC_LSFT" , "KC_A"   , "KC_S"  , "KC_D"  , "KC_F"  , "KC_G"  ,  "KC_H"  , "KC_J"   , "KC_K"   , "KC_L"  , "KC_SCLN", "KC_QUOT"  , "KC_BSLS",
    "LSFT(KC_BSLS)", "KC_LCTL" , "KC_Z"   , "KC_X"  , "KC_C"  , "KC_V"  , "KC_B"  ,  "KC_N"  , "KC_M"   , "KC_COMM", "KC_DOT", "KC_SLSH", "KC_LCTL"  , "_______",
    "KC_LGUI", "KC_LCTL" , "KC_LALT"   , "LSFT(KC_COMM)"  , "LSFT(KC_DOT)"  , "MO(RAISE)"  , "KC_LSFT"  ,  "MO(LOWER)", "MO(NUM)"  , "LSFT(KC_LBRC)"   , "LSFT(KC_LBRC)", "KC_RALT", "KC_SLSH", "LSFT(KC_B)",
    "_______","_______","_______",    "KC_LCTL", "KC_ENT", "KC_LALT", "KC_BSPC", "KC_DEL", "KC_RALT", "KC_ENT", "KC_RCTL","_______","_______","_______"
]

def generate_qmk_layout(rows, cols):
    # Generate the layout for a 7x7 keyboard matrix, skipping out-of-bound coordinates
    omit_coords = {(6, 0), (6, 1), (6, 2), (6, 11), (6, 12), (6, 13)}

    layout = []
    for row in range(rows):
        for col in range(cols):
            if (row, col) not in omit_coords:
                layout.append({
                    "matrix": [row, col],
                    "x": col,
                    "y": row,
                })
    return layout

# Define the number of rows and columns globally (7x7 matrix)
rows, cols = 7, 7

# Create the keyboard.json structure
keyboard_json = {
    "keyboard_name": "Dactyl Manuform 7x7",
    "manufacturer": "arepa_flipper",
    "maintainer": "qmk",
    "usb": {
        "vid": "0xFEED",
        "pid": "0xCAFE",
        "device_version": "1.0.0"
    },
    "features": {
        "bootmagic": True,
        "command": True,
        "console": False,
        "extrakey": True,
        "mousekey": True,
        "nkro": False
    },
    "qmk": {
        "locking": {
            "enabled": True,
            "resync": True
        }
    },
    "matrix_pins": {
        "cols": ["GP22", "GP21", "GP20", "GP19", "GP18", "GP17", "GP16"],  # Example pinout for 7 columns
        "rows": ["GP15", "GP14", "GP13", "GP12", "GP11", "GP10", "GP9"]     # Example pinout for 7 rows
    },
    "diode_direction": "COL2ROW",
    "processor": "RP2040",
    "bootloader": "rp2040",
    "layouts": {
        "LAYOUT": {
            "layout": generate_qmk_layout(rows, cols)
        }
    }
}

# Save the JSON to a file
output_file = "keyboard.json"
with open(output_file, "w") as f:
    json.dump(keyboard_json, f, indent=4)

print(f"Generated {output_file} for QMK!")

