10/22/24

Ok so new sidequest for backing up this thing. I want weekly full system backups stored in cloud storage. I plan to copy the contents of the sd card to the usb stick, then zip everything on the usb stick and upload the .zip to Google Drive.


I HATE MARKDOWN BUT DONT HAVE TIME TO CHANGE FILE FORMAT RN UGHGHGHGHGHGHGH

10/21/24 Side note: I haven't yet updated the files in this project yet, just wanted to add this log

So I've been trying to use rpi-rf and after struggling for HOURS to fix a RunTime error: Failed to add edge detection. Finally I tried updating from rpi-gpio to rpi-lgpio and that fixed the problem. It was cool that I got to dive into the code of rpi-rf to figure out the problem. No offical docs to refer to either. Once I got everything working, I tried to just read rf codes and I was getting no output. Wasn't able to try for long though, will experiment more later.
 
 
 
 
10/6/2024

Turns out the IR LEDs that I wanted to use are not bright enough to shine across my room (10 ft) to the IR sensor on the ceiling. To solve this, I'm going to put an old Arduino board on my desk underneath the IR sensor mounted on the ceiling. I'll connect a 433mhz transmitter/receiver and IR LED to it. I will have the Pi communicate via 433mhz radio to the Arduino, which will send an IR signal up to the sensor as well as a confirmation signal so the Pi knows the signal was delivered.
