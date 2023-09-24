enum custom_keycodes
{
    GMAIL_EMAIL = SAFE_RANGE,
    LIVE_EMAIL,
    WORK_EMAIL,
    WORK_EMAIL2,
    DNI,
    PHONE_NUMBER,
    ALT_TAB,
    LSALT_TAB,
    DESKTOP_LEFT,
    DESKTOP_RIGHT,
    DESKTOP_UP,
    SWITCH_TO_MAC,
    SWITCH_TO_WINDOWS,
    SWITCH_TO_LINUX,
    WORD_MODIFIER,
    UNDO,
    CUT,
    COPY,
    PASTE,
    SCREENSHOT,
    ENIE,
    MISSION_CONTROL,
};

enum OS
{
    _MAC,
    _WINDOWS,
    _LINUX,
};

int currentOS = _WINDOWS;
enum layers
{
    _QWERTY,
    _NUMERIC,
    _NAVIGATION,
    _SYMBOLS,
    _FN_KEYS,
    _CONFIG
};

// enum planck_keycodes {
//   PLOVER = SAFE_RANGE,
// };

#define NUM_LAYER LT(_NUMERIC, KC_TAB)
#define NAV_LAYER MO(_NAVIGATION)
#define SYM_LAYER MO(_SYMBOLS)
#define FN_LAYER MO(_FN_KEYS)
#define CONF_LAYER MO(_CONFIG)
#define PLUS_SIGN LSFT(KC_EQL)
#define ASTERISK LSFT(KC_8)
#define BANG LSFT(KC_1)
#define PERCENT LSFT(KC_5)
#define HASHTAG LSFT(KC_3)
#define FIRULITO LSFT(KC_GRV)
#define CARET LSFT(KC_6)
#define AMPERSAND LSFT(KC_7)
#define ARROBA LSFT(KC_2)
#define DOLLAR LSFT(KC_4)
#define PIPE LSFT(KC_BSLS)
#define COMILLA_SIMP KC_QUOT
#define COMILLA_DOBL LSFT(KC_QUOT)
#define AB_PARENT LSFT(KC_9)
#define CE_PARENT LSFT(KC_0)
#define AB_CORCHE KC_LBRC
#define CE_CORCHE KC_RBRC
#define AB_LLAVE LSFT(KC_LBRC)
#define CE_LLAVE LSFT(KC_RBRC)
#define UNDERSCORE LSFT(KC_MINUS)
#define GREATER LSFT(KC_DOT)
#define LESS_THAN LSFT(KC_COMM)

bool     is_alt_tab_active = false; // ADD this near the begining of keymap.c
uint16_t alt_tab_timer     = 0;

void mission_control(void)
{
    switch (currentOS)
    {
    case _WINDOWS:
        register_code(KC_LALT);
        tap_code(KC_SPC);
        unregister_code(KC_LALT);
        break;
    case _MAC:
        register_code(KC_LGUI);
        tap_code(KC_SPC);
        unregister_code(KC_LGUI);
        break;
    case _LINUX:
        tap_code(KC_LGUI);
        tap_code(KC_LGUI);
        break;
    }
}

void previous_desktop(void)
{
    switch (currentOS)
    {
    case _MAC:
        register_code(KC_LCTL);
        tap_code(KC_LEFT);
        unregister_code(KC_LCTL);
        break;
    case _LINUX:
        register_code(KC_LCTL);
        register_code(KC_LALT);
        tap_code(KC_LEFT);
        unregister_code(KC_LCTL);
        unregister_code(KC_LALT);
    case _WINDOWS:
        register_code(KC_LCTL);
        register_code(KC_LGUI);
        tap_code(KC_LEFT);
        unregister_code(KC_LCTL);
        unregister_code(KC_LGUI);
        break;
    }
}

void next_desktop(void)
{
    switch (currentOS)
    {
    case _MAC:
        register_code(KC_LCTL);
        tap_code(KC_RIGHT);
        unregister_code(KC_LCTL);
        break;
    case _LINUX:
        register_code(KC_LCTL);
        register_code(KC_LALT);
        tap_code(KC_RIGHT);
        unregister_code(KC_LCTL);
        unregister_code(KC_LALT);
    case _WINDOWS:
        register_code(KC_LCTL);
        register_code(KC_LGUI);
        tap_code(KC_RIGHT);
        unregister_code(KC_LCTL);
        unregister_code(KC_LGUI);
        break;
    }
}

void show_desktops(void)
{
    if (currentOS == _LINUX)
    {
        tap_code(KC_LGUI);
    }
    else if (currentOS == _WINDOWS)
    {
        register_code(KC_LGUI);
        tap_code(KC_TAB);
        unregister_code(KC_LGUI);
    }
    else if (currentOS == _MAC)
    {
        tap_code(KC_LGUI);
    }
}

void register_alt_tab_modifier(void)
{
    switch (currentOS)
    {
    case _MAC:
        register_code(KC_LGUI);
        break;
    case _WINDOWS:
    case _LINUX:
        register_code(KC_LALT);
        break;
    }
}

void unregister_alt_tab_modifier(void)
{
    switch (currentOS)
    {
    case _MAC:
        unregister_code(KC_LGUI);
        break;
    case _WINDOWS:
    case _LINUX:
        unregister_code(KC_LALT);
        break;
    }
}

void hold_word_modifier(void)
{
    switch (currentOS)
    {
    case _MAC:
        register_code(KC_LALT);
        break;
    case _WINDOWS:
    case _LINUX:
        register_code(KC_LCTL);
        break;
    }
}

void release_word_modifier(void)
{
    switch (currentOS)
    {
    case _MAC:
        unregister_code(KC_LALT);
        break;
    case _WINDOWS:
    case _LINUX:
        unregister_code(KC_LCTL);
        break;
    }
}

void undo(void)
{
    switch (currentOS)
    {
    case _MAC:
        register_code(KC_LGUI);
        tap_code(KC_Z);
        unregister_code(KC_LGUI);
        break;
    case _WINDOWS:
    case _LINUX:
        register_code(KC_LCTL);
        tap_code(KC_Z);
        unregister_code(KC_LCTL);
        break;
    }
}

void cut(void)
{
    switch (currentOS)
    {
    case _MAC:
        register_code(KC_LGUI);
        tap_code(KC_X);
        unregister_code(KC_LGUI);
        break;
    case _WINDOWS:
    case _LINUX:
        register_code(KC_LCTL);
        tap_code(KC_X);
        unregister_code(KC_LCTL);
        break;
    }
}

void copy(void)
{
    switch (currentOS)
    {
    case _MAC:
        register_code(KC_LGUI);
        tap_code(KC_C);
        unregister_code(KC_LGUI);
        break;
    case _WINDOWS:
    case _LINUX:
        register_code(KC_LCTL);
        tap_code(KC_C);
        unregister_code(KC_LCTL);
        break;
    }
}

void paste(void)
{
    switch (currentOS)
    {
    case _MAC:
        register_code(KC_LGUI);
        tap_code(KC_V);
        unregister_code(KC_LGUI);
        break;
    case _WINDOWS:
    case _LINUX:
        register_code(KC_LCTL);
        tap_code(KC_V);
        unregister_code(KC_LCTL);
        break;
    }
}

void screenshot(void)
{
    switch (currentOS)
    {
    case _MAC:
        register_code(KC_LGUI);
        register_code(KC_LSFT);
        tap_code(KC_X);
        unregister_code(KC_LGUI);
        unregister_code(KC_LSFT);
        break;
    case _WINDOWS:
    case _LINUX:
        tap_code(KC_PSCR);
        break;
    }
}

void enie(void)
{
    switch (currentOS)
    {
    case _MAC:
        register_code(KC_LALT);
        tap_code(KC_N);
        unregister_code(KC_LALT);
        tap_code(KC_N);
        break;
    case _WINDOWS:
        register_code(KC_LALT);
        tap_code(KC_KP_0);
        tap_code(KC_KP_2);
        tap_code(KC_KP_4);
        tap_code(KC_KP_1);
        unregister_code(KC_LALT);
        break;
    case _LINUX:
        register_code(KC_LCTL);
        register_code(KC_LSFT);
        tap_code(KC_U);
        unregister_code(KC_LCTL);
        unregister_code(KC_LSFT);
        tap_code(KC_0);
        tap_code(KC_0);
        tap_code(KC_F);
        tap_code(KC_1);
        tap_code(KC_ENT);
        break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {

    case GMAIL_EMAIL:
        if (record->event.pressed)
        {
            SEND_STRING("kenjimartinushiro@gmail.com");
        }
        return false;
        break;
    case LIVE_EMAIL:
        if (record->event.pressed)
        {
            SEND_STRING("kenjiushiro@live.com");
        }
        return false;
        break;
    case WORK_EMAIL:
        if (record->event.pressed)
        {
            SEND_STRING("work@email1.com");
        }
        return false;
        break;
    case WORK_EMAIL2:
        if (record->event.pressed)
        {
            SEND_STRING("work@email2.com");
        }
        return false;
        break;
    case DNI:
        if (record->event.pressed)
        {
            SEND_STRING("38521991");
        }
        return false;
        break;
    case PHONE_NUMBER:
        if (record->event.pressed)
        {
            SEND_STRING("1164484715");
        }
        return false;
        break;
    case ENIE:
        if (record->event.pressed)
        {
            enie();
        }
        return false;
        break;
    case MISSION_CONTROL:
        if (record->event.pressed)
        {
            mission_control();
        }
        return false;
        break;
    case ALT_TAB:
        if (record->event.pressed)
        {
            if (!is_alt_tab_active)
            {
                is_alt_tab_active = true;
                register_alt_tab_modifier();
            }
            alt_tab_timer = timer_read();
            register_code(KC_TAB);
        }
        else
        {
            unregister_code(KC_TAB);
        }
        break;
    case LSALT_TAB:
        if (record->event.pressed)
        {
            if (!is_alt_tab_active)
            {
                is_alt_tab_active = true;
                register_code(KC_LALT);
            }
            alt_tab_timer = timer_read();
            register_code(KC_LSFT);
            register_code(KC_TAB);
            unregister_code(KC_LSFT);
        }
        else
        {
            unregister_code(KC_TAB);
        }
        break;
    case SCREENSHOT:
        if (record->event.pressed)
        {
            screenshot();
            return false;
        }
        break;

    case DESKTOP_LEFT:
        if (record->event.pressed)
        {
            previous_desktop();
        }
        return false;
        break;
    case DESKTOP_RIGHT:
        if (record->event.pressed)
        {
            next_desktop();
        }
        return false;
        break;
    case DESKTOP_UP:
        if (record->event.pressed)
        {
            show_desktops();
        }
        return false;
        break;
    case SWITCH_TO_MAC:
        if (record->event.pressed)
        {
            currentOS = _MAC;
        }
        return false;
        break;
    case SWITCH_TO_WINDOWS:
        if (record->event.pressed)
        {
            currentOS = _WINDOWS;
        }
        return false;
        break;
    case SWITCH_TO_LINUX:
        if (record->event.pressed)
        {
            currentOS = _LINUX;
        }
        return false;
        break;
    case WORD_MODIFIER:
        if (record->event.pressed)
        {
            hold_word_modifier();
        }
        else
        {
            release_word_modifier();
        }
        return false;
        break;
    case UNDO:
        if (record->event.pressed)
        {
            undo();
        }
        return false;
        break;
    case CUT:
        if (record->event.pressed)
        {
            cut();
        }
        return false;
        break;
    case COPY:
        if (record->event.pressed)
        {
            copy();
        }
        return false;
        break;
    case PASTE:
        if (record->event.pressed)
        {
            paste();
        }
        return false;
        break;
    }
    return true;
}
void matrix_scan_user(void)
{ // The very important timer.
    if (is_alt_tab_active)
    {
        if (timer_elapsed(alt_tab_timer) > 500)
        {
            unregister_alt_tab_modifier();
            is_alt_tab_active = false;
        }
    }
}
