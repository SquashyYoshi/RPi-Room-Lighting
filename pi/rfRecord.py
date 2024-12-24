from datetime import datetime
import matplotlib.pyplot as pyplot
import RPi.GPIO as GPIO
RECEIVED_SIGNAL = [[], []]  #[[time of reading], [signal reading]]
MAX_DURATION = 2

RECEIVE_PIN = 37

if __name__ == '__main__':
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(RECEIVE_PIN, GPIO.IN)
    cumulative_time = 0
    beginning_time = datetime.now()
    print('**Started recording**')
    while cumulative_time < MAX_DURATION:
        thisRun = 0
        for i in range(200):
            thisRun += GPIO.input(RECEIVE_PIN)
        thisVal = round(thisRun / 200)
        time_delta = datetime.now() - beginning_time
        RECEIVED_SIGNAL[0].append(time_delta)
        RECEIVED_SIGNAL[1].append(thisVal)
        cumulative_time = time_delta.seconds
    print ('**Ended recording**')
    print (len(RECEIVED_SIGNAL[0]), 'samples recorded')
    GPIO.cleanup()

    print ('**Processing results**')
    for i in range(len(RECEIVED_SIGNAL[0])):
        RECEIVED_SIGNAL[0][i] = RECEIVED_SIGNAL[0][i].seconds + RECEIVED_SIGNAL[0][i].microseconds/1000000.0
    #basically it makes makes the time is a simple float of seconds it took
    # for signal in RECEIVED_SIGNAL[0]: 
    #     signal = signal.seconds + signal.microseconds/1000000.0

    print ('**Plotting results**')
    pyplot.plot(RECEIVED_SIGNAL[0], RECEIVED_SIGNAL[1])
    pyplot.axis([0, MAX_DURATION, -1, 2])
    pyplot.show()