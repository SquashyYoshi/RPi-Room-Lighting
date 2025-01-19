import rpi_rf
import RPi.GPIO as GPIO
import time
import threading


def main():
    #start()
    re = rpi_rf.RFDevice(10, rx_tolerance=0) #gpio pin number
    tr = rpi_rf.RFDevice(2)
    re.enable_rx()
    print("rX enabled")
    tr.enable_tx()
    print("tX enabled")
    try:
        inThread = threading.Thread(target=usrSend)
        inThread.daemon = True
        inThread.start()
        while True:
            if re.rx_code:
                print(f"received {re.rx_code}")
                re.rx_code = None
            time.sleep(0.2)
    except KeyboardInterrupt:
        print()


def usrSend():
    while True:
        val = int(input())
        tr.tx_code(val)
        time.sleep(0.2)
def start():
    global re, tr
    re = rpi_rf.RFDevice(10, rx_tolerance=0) #gpio pin number
    tr = rpi_rf.RFDevice(2)
    re.enable_rx()
    print("rX enabled")
    tr.enable_tx()
    print("tX enabled")
main()

# print("uhhh there was something")
# print("Received code: {}".format(re.rx_code))
# print("Protocol: {}".format(re.rx_proto))
# print("Bitlength: {}".format(re.rx_bitlength))
# print("Pulselength: {}".format(re.rx_pulselength))
# print()