**11/19/2024**  
Ok so I've been very busy, but with the time I've had, I've been struggling to use these 433mhz transmitters/receivers. So far, I haven't been able to get the transmitter to work and the receiver only works if I have the remote touching it. I tried to make makeshift antennas using jumper wires bent around the antenna hole, but it didn't seem to help. My new plan is to buy a 433mhz transceiver HAT to communicate with the fan/outlet and use Bluetooth to talk to the Arduino on the other side of the room. I got the Arduino many moons ago in this discontinued kit for kids (Kosmo Duino I think), but I believe it is just a branded version of an Arduino Uno and I know for a fact it has Bluetooth.  
<br>
<br>
**10/21/24**  
Side note: I haven't yet updated the files in this project yet, just wanted to add this log
So I've been trying to use rpi-rf and after struggling for HOURS to fix a RunTime error: Failed to add edge detection. Finally I tried updating from rpi-gpio to rpi-lgpio and that fixed the problem. It was cool that I got to dive into the code of rpi-rf to figure out the problem. No offical docs to refer to either. Once I got everything working, I tried to just read rf codes and I was getting no output. Wasn't able to try for long though, will experiment more later.
<br>
<br>
**10/6/2024**  
Turns out the IR LEDs that I wanted to use are not bright enough to shine across my room (10 ft) to the IR sensor on the ceiling. To solve this, I'm going to put an old Arduino board on my desk underneath the IR sensor mounted on the ceiling. I'll connect a 433mhz transmitter/receiver and IR LED to it. I will have the Pi communicate via 433mhz radio to the Arduino, which will send an IR signal up to the sensor as well as a confirmation signal so the Pi knows the signal was delivered.
