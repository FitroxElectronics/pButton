#include "pButton.h"

Button::Button(int pin, bool activeHigh)
{
    buttonPin = pin;
    buttonState = activeHigh ? HIGH : LOW;
    lastButtonState = activeHigh ? HIGH : LOW;
    lastDebounceTime = 0;
    clickInterval = 50;       // Adjust as needed
    longClickDuration = 1000; // Adjust as needed
    lastClickTime = 0;
    doubleClickFlag = false;
    tripleClickFlag = false;
    activeHigh = activeHigh;

    clickCallback = nullptr;
    longClickCallback = nullptr;
    doubleClickCallback = nullptr;
    tripleClickCallback = nullptr;

    if (activeHigh)
    {
        pinMode(buttonPin, INPUT_PULLUP);
    }
    else
    {
        pinMode(buttonPin, INPUT);
    }
}

void Button::update()
{
    int reading = digitalRead(buttonPin);

    if (reading != lastButtonState)
    {
        lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > clickInterval)
    {
        if (reading != buttonState)
        {
            buttonState = reading;

            if ((activeHigh && buttonState == LOW) || (!activeHigh && buttonState == HIGH))
            {
                // Button pressed
                if (millis() - lastClickTime > longClickDuration)
                {
                    // Long click
                    if (longClickCallback != nullptr)
                    {
                        longClickCallback();
                    }
                    tripleClickFlag = false;
                }
            }
            else
            {
                // Button released
                if (millis() - lastClickTime < clickInterval)
                {
                    // Double click
                    if (doubleClickFlag && doubleClickCallback != nullptr)
                    {
                        doubleClickCallback();
                        tripleClickFlag = false;
                    }
                    else
                    {
                        doubleClickFlag = true;
                    }
                }
                else
                {
                    // Single click
                    if (clickCallback != nullptr)
                    {
                        clickCallback();
                    }
                    doubleClickFlag = false;

                    // Triple click
                    if (tripleClickFlag && tripleClickCallback != nullptr)
                    {
                        tripleClickCallback();
                    }
                    else
                    {
                        tripleClickFlag = true;
                    }
                }
                lastClickTime = millis();
            }
        }
    }

    lastButtonState = reading;
}

void Button::onClick(void (*callback)())
{
    clickCallback = callback;
}

void Button::onLongClick(void (*callback)())
{
    longClickCallback = callback;
}

void Button::onDoubleClick(void (*callback)())
{
    doubleClickCallback = callback;
}

void Button::onTripleClick(void (*callback)())
{
    tripleClickCallback = callback;
}