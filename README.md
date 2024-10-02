Last updated 10/2/24

My goal for this project is to unify my room light control
Right now I am using: a remote-controlled ceiling fan, 2 sets of rgb light strips (controlled separately), Christmas lights controlled by plugging in and unplugging the lights

I am using a 2.4ghz tv remote from Amazon to control everything. It has a little dongle that I can plug into my Raspberry Pi 4. The RPi will have a 433mhz transmitter to communicate with the fan and outlet controller. I will also have an infrared transmitter on the RPi with line of sight to the RGB controller. I will use 2 seperate transmitters to control both the RGB controllers. I'm also adding an ultrasonic sensor in front of my door so the lights can automatically turn on and off.

The other interface I will use is a Flask web-app interface to change settings. I will also add a sunrise alarm clock feature with schedules so that I can set different times for different days and I will control this through the web app. I might also try to use javascript to make things more dynamic because I have no idea how to actually use javascript.

Supplies:

Raspberry pi 4 – 2gb RAM
 [Adafruit]([url](https://www.adafruit.com/product/4292))-$45   [The Pi Hut]([url](https://thepihut.com/products/raspberry-pi-4-model-b?variant=20064052674622))-$47.93
  
Amzn [2.4ghz remote]([url](https://www.amazon.com/gp/product/B0C7RLYNNC/ref=ox_sc_act_title_3?smid=A3C4FT8K0XHSEP&th=1)) - $12.88

Amzn [IR Transmitters/Receivers]([url](https://www.amazon.com/Digital-Receiver-Transmitter-Electronic-Building/dp/B08X2MFS6S/ref=sr_1_2?dib=eyJ2IjoiMSJ9.aJOx9fQwnkAVp8ySr3ecbRU6Ax5kxsufhF76TwJK6SlmaxP38SJRiJ509bwu4LzsaOviqB3oYKXr_xXIvYpDpis5e4TdI0SAdQPuWcQhBplSyEedqbVpERAMn3UzFhvUsonx3EokVB6XcBfyNUZ2-jGNPosOntRLPvVxT6qkdCudoB6ijmhQX2OZrqb94rvKEQKyygj2_9SAoh4sk1kGhLW5er_gAzuRIf0yTlpIgVM.5ygud8gTDVuMW2BaCBhto6AsO0aTqztflo2E7ofZCn0&dib_tag=se&keywords=raspberry%2Bpi%2Bir%2Breceiver&qid=1727442141&sr=8-2&th=1)) - $8.99

Amzn [433 mhz  + jumper cables]([url](https://www.amazon.com/gp/product/B0BDFK55YN/ref=ox_sc_act_title_1?smid=A1YZW40LYQY3L1&psc=1)) controlling fan, outlet - $6.99

Adafruit [Ultrasonic sensor]([url](https://www.adafruit.com/product/3942)) detect people entering/exiting - $3.95

Amzn [hopefully 434mhz outlet controller]([url](https://www.amazon.com/gp/product/B0CZL49XRC/ref=ox_sc_act_title_4?smid=A1LP08NKVFAI79&psc=1)) - $11.99
