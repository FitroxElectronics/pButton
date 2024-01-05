#ifndef pButton_h
#define pButton_h

#include <Arduino.h>

class Button
{
public:
    Button(int pin, bool activeHigh = true);

    void update();

    // Callbacks for different button events
    void onClick(void (*callback)());
    void onLongClick(void (*callback)());
    void onDoubleClick(void (*callback)());
    void onTripleClick(void (*callback)());

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