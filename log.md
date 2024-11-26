**11/24/2024**  
So my Bluetooth solution will not work because this "kosmoduino" is very strange. It's essentially a weirdly shaped Arduino uno with a Bluetooth chip soldered on. For some background, the "kosmoduino" was a kit for kids to help them learn microcontrollers, but I thought it would be helpful for this project (I already owned it). The kit comes with this game you play using a gamepad (connected via Bluetooth to your phone) you put together. Anyway, I found the code used on the microcontroller/gamepad, and the way the microcontroller communicates with the phone is just with Serial.print statements sent through the Bluetooth chip. I tried using a serial monitor app to pick up the print statements, but it wouldn't detect the Bluetooth device. So, I tried the game and that was able to connect to the microcontroller fine. I tried using the command line (on my Pi) to pair it, but that wouldn't work, but the Pi did detect the microcontroller. My theory for why this isn't working is the Arduino encodes the Bluetooth signal in a custom way. The annoying this is I can't find out how it is encoding unless I have the source code of the ios app. So now I'm back to looking for 433mhz transmitters/receivers that actually work so that the Pi and Arduino can communicate.  
I also got the ultrasonic sensor working through the Arduino, it was pretty simple. I was amazed at how accurate it was (+- 1cm)
<br>
<br>
**11/22/2024**  
I've done some more research and it turns out the HAT won't work. It's only designed to use a certain type of modulation, not OOK modulation. The 433mhz transmitters are terrible and it turns out they were missing part of the built-in antenna. Anyway, now, I'm going to work on setting up the Bluetooth connection between the RPi and the Arduino. I'm also setting up the IR-controlled rgb light strips and the ultrasonic sensor. I can at least make it so my rgb lights come on when I walk into my room, and this will lay the foundation for when I get the 433 mHz working.
<br>
<img src="https://m.media-amazon.com/images/I/71eWTMtqWxL.jpg" alt="lllMissing transmitter coil" width="250" height="350"/>
<br>
<br>
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
<br>
<br>
**10/2/2024  Original README**  
My goal for this project is to unify my room light control
Right now I am using: a remote-controlled ceiling fan, 2 sets of rgb light strips (controlled separately), Christmas lights controlled by plugging in and unplugging the lights

I am using a 2.4ghz tv remote from Amazon to control everything. It has a little dongle that I can plug into my Raspberry Pi 4. The RPi will have a 433mhz transmitter to communicate with the fan and outlet controller. I will also have an infrared transmitter on the RPi with line of sight to the RGB controller. I will use 2 seperate transmitters to control both the RGB controllers. I'm also adding an ultrasonic sensor in front of my door so the lights can automatically turn on and off.

The other interface I will use is a Flask web-app interface to change settings. I will also add a sunrise alarm clock feature with schedules so that I can set different times for different days and I will control this through the web app. I might also try to use javascript to make things more dynamic because I have no idea how to actually use javascript.
