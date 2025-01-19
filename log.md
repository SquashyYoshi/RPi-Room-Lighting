**1/19/2025**  
I swear everything in this project wants me to fail. For example, I had the Pi receiving rf signals from the Arduino, and now it doesn't work. I've tried reverting the code and I can't get it to work right now. The name of the port changed and I still don't know why ( /dev/ttyACM0 to /dev/ttyACM1 ??? ). The serial monitor extension I was using to send commands to the arduino stopped loading for a while. There's just been so many things seemingly outside of my control that stopped working. As I'm writing this, the markdown preview also doesn't work like wth. That being said, I have managed for the Pi to send signals to the Arduino and that works fine. Once I get the communication figured out, the rest of the project should be much easier.
<br>
<br>
**1/18/2025**  
So I've been very busy, doing a lot of stuff over the break, and it's been hard to get back into this project. From what it seems, my fan doesn't use any sort of set protocol that it sends signals on, which makes it hard to sniff them (can't use preexisting software). I'm going to focus on getting the Arduino and the Pi to communicate over 433mhz today. Longer term, my plan is to just hook up my rgb light strips (which used infared) to my system and ignore the fan. I may try communicating with the fan again later, I have a few ideas.  
<br>
_Ideas for communicating with fan:_  
    - Smart light bulb in fan (doesn't help control actual fan and might need a smart hub)  
    - Motors to physically push buttons on the remote (would be slower/loud)  
<br>
<br>
**12/24/2024**  
I have been stuggling trying to get the right rf signals to communicate with my fan. I honestly believe I can do it, but it sucks not making actual, mesurable progress on this project. I'm going to shift my focus to the other aspects of this project for now, and pretend I'm not going to control the fan at all.  
<br>
_What I need to do:_  
    - Use 433mhz to connect Pi with Arduino  
    - Configure Pi to be able to send IR signals to RGB controller  
    - Implement ultrasonic sensor to automatically turn on/off RGB lights  
<br>
<br>
**12/14/2024**  
_I finally uploaded my code!_  
So I've been trying to sniff my remote's radio signals using an arduino (so I can get a live plot from the receiver) and I learned that by averaging out 100 signal reads, I could filter out most noise. Then I made it so everything from the receiver would be recorded for a few seconds, then played back through a transmitter. Unfortunately, this added a lot of complexity to my program and introduced a ton of noise to the receiver. Now my plan is to get readings from the arduino using the code that didn't produce noise and screenshot the graph. I will then manually write down each signal. I only have a few buttons on my remote to record, so this solution should work and hopefully not take forever. I've also tried things like RPi-rf sniffer but they also seem to suffer from too much noise. I have hope that my dumb method of recording manually will work. This is supposed to be my CS50 final project, so I really hope I can get it done before the end of the year.  
Another funny thing that happened was I accidentally took down my security system when I was messing around. Basically, I had this Pi program that would repeatedly send out the signal 1234 every second. I ran this a few times throughout my testing to make sure the transmitter and receiver were hooked up right. Every time I ran this program though, I got an alert on my phone saying my security was down. I guess the sensors (like door open, motion, glass break) operated on 433mhz. I only had issues with the security system though, when I had an antenna connected to the transmitter.  
One last thing I noticed was calling GPIO.cleanup() actually made my transmitter make enough noise to jam my fan, as in the remote wouldn't work. This would happen when no program was running on the Pi. If the last program ran called GPIO.cleanup() on my transmitter, my fan would be jammed. So the solution was to remove GPIO.cleanup() and I haven't had issues since.
<br>
<br>
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
