# Iot_timer_relay
Why I made this?
Recently I had an issue with my smartphone. Let me explain, the battery bulged and opened the back cover. I went to mobile repair guy, he said, “It’s because you charge your phone to 100%”. Honestly, everyday I just plug the phone to charging and go to sleep. I thought the makers of my smartphone are smart enough to integrate overcharge protection circuit. Never mind, what can I do as an electronic engineer to solve this issue. I cannot tweak into charger or mobile but the thing I can do is cut-off the mains supply using a relay after fixed time duration. which can be preset for time duration it takes for mobile to charge near to 95%. That’s why, I decided to make this “IoT timer relay”.It will also solve my other problem, like sometimes forgetting to turn off electrical appliances. It takes me maximum 10 min to iron the clothes, so I will set the timer relay for 10 min. 

What it does?
This IoT timer relay is a simple electronic device that will allow us to keep the mains supply turned on for a set time duration. Wherever timed switching is needed this device can be used. In general, this will prevent wastage of electrical energy and also protect our electronic devices. 

How the time is set?
The time duration is set from a webpage served by ESP-01, this doesn’t requires internet. We are using ESP8266 in AP (Access point) mode. In this mode it generates it’s own hotspot. All you need is a smartphone/PC/Laptop, which can connect to hotspot and display webpages with the help of browser. 

Components needed

Sr no
Component name
Quantity
1.
ESP-01  
1
2.
Relay 5V DC
1
3.         
AMS1117-3.3V module
1
4.
5V SMPS/Adapter
1
5.
Switch (push button)
1
6.
Resistor 1K
4
7.
Resistor 4.7K
1
8.
Resistor 56K
1
9.
Capacitor 47uf
1
10.
Capacitor 0.1uf
1
11.
Transistor BC547
1
12.
Diode 1N4007
1
13.
 Led red
1

These all components you need to make the circuit. You can make circuit on breadboard, perf board or directly make PCB. Depends on your fabrication process. I have made it on breadboard. Below given is the circuit diagram.

Circuit diagram - 

![Iot_timer_relay_circuit](https://github.com/user-attachments/assets/c56a4784-02b9-43a3-a00d-e80732448b64)
