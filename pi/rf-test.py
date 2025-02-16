import rpi_rf
import RPi.GPIO as GPIO
import time
import threading
from datetime import datetime, timedelta


def main():
    global re
    global tr
    global canReceive 
    canReceive = True
    re = rpi_rf.RFDevice(10) #gpio pin number rx_tolerance=0 (might add that parameter back)
    tr = rpi_rf.RFDevice(2)
    re.enable_rx()
    print("rX enabled")
    tr.enable_tx()
    print("tX enabled")

    try:
        usrSend()
        # txThread = threading.Thread(target=usrSend)
        # txThread.daemon = True
        # txThread.start()
        # while True:
        #     if canReceive and re.rx_code:
        #         print(f"received {re.rx_code}")
        #         re.rx_code = None
        #     time.sleep(0.2)
    except KeyboardInterrupt:
        print()


def usrSend():
    while True:
        val = int(input())
        checkSum = int(val/2 + 8)
        success = False
        canReceive = False
        tr.tx_code(val)
        print(f"Should hear {checkSum}...")
        startTime = datetime.now()
        while(datetime.now() < startTime + timedelta(seconds=3)):
            if re.rx_code == checkSum:
                print("Checksum received")
                success = True
                re.rx_code = None
            time.sleep(0.1)
        if not success:
            print("Checksum not received after 3 seconds ;(")
        canReceive = True


main()

# print("uhhh there was something")
# print("Received code: {}".format(re.rx_code))
# print("Protocol: {}".format(re.rx_proto))
# print("Bitlength: {}".format(re.rx_bitlength))
# print("Pulselength: {}".format(re.rx_pulselength))
# print()