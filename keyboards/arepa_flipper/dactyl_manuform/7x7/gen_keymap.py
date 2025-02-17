def generate_qmk_keymap(rows, cols):
    keymap = []

    # Define keys for the _QWERTY layer
    layer_qwerty = []
    for row in range(rows):
        row_keys = []
        for col in range(cols):
            key = f"KC_{chr(65 + (row * cols + col) % 26)}"  # Sample key assignments like 'KC_A', 'KC_B'
            row_keys.append(key)
        layer_qwerty.append(row_keys)

    # Define keys for the _LOWER layer
    layer_lower = []
    for row in range(rows):
        row_keys = []
        for col in range(cols):
            key = f"KC_LALT"  # Sample key assignments like 'KC_LALT' for lower layer
            row_keys.append(key)
        layer_lower.append(row_keys)

    # Define keys for the _RAISE layer
    layer_raise = []
    for row in range(rows):
        row_keys = []
        for col in range(cols):
            key = f"KC_RALT"  # Sample key assignments like 'KC_RALT' for raise layer
            row_keys.append(key)
        layer_raise.append(row_keys)

    # Creating the full keymap in QMK format
    keymap_code = """
#include QMK_KEYBOARD_H

enum custom_layer {
    _QWERTY,
    _LOWER,
    _RAISE,
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
"""
    for row in range(rows):
        keymap_code += "        "
        for col in range(cols):
            keymap_code += f"{layer_qwerty[row][col]}, "
        keymap_code = keymap_code.rstrip(", ") + "\n"
    keymap_code += """
    ),
    [_LOWER] = LAYOUT(
"""
    for row in range(rows):
        keymap_code += "        "
        for col in range(cols):
            keymap_code += f"{layer_lower[row][col]}, "
        keymap_code = keymap_code.rstrip(", ") + "\n"
    keymap_code += """
    ),
    [_RAISE] = LAYOUT(
"""
    for row in range(rows):
        keymap_code += "        "
        for col in range(cols):
            keymap_code += f"{layer_raise[row][col]}, "
        keymap_code = keymap_code.rstrip(", ") + "\n"
    keymap_code += """
    )
};
"""

    return keymap_code


# Write to file
def save_keymap_to_file():
    rows, cols = 7, 7  # 7x7 layout
    keymap_code = generate_qmk_keymap(rows, cols)

    # Saving to keymap.c
    with open("keymap.c", "w") as f:
        f.write(keymap_code)

    print("Generated keymap.c for 7x7 layout!")

# Run the function to generate and save the keymap
save_keymap_to_file()

