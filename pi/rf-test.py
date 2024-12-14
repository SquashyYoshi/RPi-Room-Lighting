import rpi_rf
import RPi.GPIO as GPIO
import time

def main():
    re = rpi_rf.RFDevice(26, rx_tolerance=0) #gpio pin number
    tr = rpi_rf.RFDevice(21) 
    re.enable_rx()
    print("rX enabled")
    tr.enable_tx()
    print("tX enabled")
    try:
        while True:
            tr.tx_code(1234)
            if re.rx_code:
                print("uhhh there was something")
                print("Received code: {}".format(re.rx_code))
                print("Protocol: {}".format(re.rx_proto))
                print("Bitlength: {}".format(re.rx_bitlength))
                print("Pulselength: {}".format(re.rx_pulselength))
                print()
                re.rx_code = None
            time.sleep(0.1)  # Add a small delay to avoid busy-waiting
    except KeyboardInterrupt:
        print()

main()