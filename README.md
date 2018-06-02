# HackFX

HackFX is a project to put life back into a dumped JB Lighting Licon FX fader board and make a MIDI controller out of it.  

We had a Licon FX fader board where the interface with all faders and knobs were totally fine. The only problem was that the controller was missing. So we made our own. The controller outputs a standard USB MIDI signal which you can use for various things. In our example we use it in combination with the DMXControl software on a PC to generate DMX signals.  

Use Arduino Mega 2560

Install SimpleKalmanFilter library -> https://github.com/denyssene/SimpleKalmanFilter  
Install MIDI Library by Forty Seven Effects -> https://github.com/FortySevenEffects/arduino_midi_library

Install https://github.com/ddiakopoulos/hiduino binary on ATmega16u2
