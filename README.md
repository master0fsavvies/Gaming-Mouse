A personal project of mine.

The idea was to add simulated recoil to a mouse. I ripped open a cheap wireless mouse and used the space reserved for batteries to store two solenoids.
Then I made the mouse powered off of the arduino's 3.3V pin, meaning all the system needs is a powersource, a wired usb, and a wireless usb port.
Then I shoved an RGB light inside to get that magic gaming mouse feel. This project was to help me learn more about transistors.

HOW IT WORKS

The arduino has a button on top of the mouse click button, which makes it feel a little sticky and clicky, but works just fine. Alternatively, you could use my seperate python script
to listen for mouseclicks through the computer to avoid a physical button on the mouse. When it picks up either, the solenoid fires, single fire or autofire.
Meanwhile, the RGB light will cycle through a vibin little rainbow cycle, and when the mouse is held down random colors will pop out to emphasize action.
