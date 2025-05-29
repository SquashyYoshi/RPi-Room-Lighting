import RPi.GPIO as GPIO
import time

RX_PIN = 37
TX_PIN = 40

def main():
    GPIO.setmode(GPIO.BOARD)
    print('Recording...')
    sample = record()
    print("waiting")
    time.sleep(1)
    print('Playing...')
    play(sample)

    # GPIO.cleanup()
    # GPIO.setmode(GPIO.BOARD)
    # GPIO.setup(TX_PIN, GPIO.OUT, initial=GPIO.LOW)
    # GPIO.cleanup()


def record():
    GPIO.setup(RX_PIN, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)

    sample = read_timings(RX_PIN)
    print('Recorded', len(sample), 'bit transitions')
    return sample

def play(sample):
    GPIO.setup(TX_PIN, GPIO.OUT, initial=GPIO.HIGH)
    for i, (timing, level) in enumerate(sample):
        if i != 0:
            # Busy-sleep (gives a better time granularity than
            # sleep() but at the cost of busy looping)
            now = time.time()
            while now + timing > time.time():
                pass
        GPIO.output(TX_PIN, level)
    
def read_timings(rx_pin):
    capture = []
    while True:
        start = time.time()
        if GPIO.wait_for_edge(rx_pin, GPIO.BOTH, timeout=200):
            capture.append((time.time() - start, GPIO.input(rx_pin)))

        # elif len(capture) < 5:  # Any pattern is likely larger than 5 bits
        #     capture = []
        else:
            capture.append((time.time() - start + 0.1, GPIO.HIGH))
            #up for 200ms
            capture.append((time.time() - start + 0.3, GPIO.LOW))
            #back down
            return capture
        
main()
