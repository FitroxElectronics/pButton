#ifndef pButton_h
#define pButton_h

#include <Arduino.h>

class pButton
{
public:
    pButton(int pin, bool activeHigh = true);

    void update();

    // Callbacks for different button events
    void click(void (*callback)());
    void longClick(void (*callback)());
    void doubleClick(void (*callback)());
    void tripleClick(void (*callback)());

private:
    int buttonPin;
    bool buttonState;
    bool lastButtonState;
    unsigned long lastDebounceTime;
    unsigned long clickInterval;
    unsigned long longClickDuration;
    unsigned long lastClickTime;
    bool doubleClickFlag;
    bool tripleClickFlag;
    bool activeHigh;

    void (*clickCallback)();
    void (*longClickCallback)();
    void (*doubleClickCallback)();
    void (*tripleClickCallback)();
};

#endif