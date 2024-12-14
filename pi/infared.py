from datetime import datetime
import piir
import RPi.GPIO as GPIO
import time
import threading

sendPin = 21 #GPIO
returnPin =  2

remote = piir.Remote('keys.json', sendPin)

def send_data(num):
    num = hex(num)[2:] 
    if len(num) % 2 != 0:
        num = '0' + num
    print("hex: "+num)
    remote.send_data(num)
    print('sent')

def receive_data():
    global data
    data = piir.decode(piir.receive(returnPin))
    
    extracted_data = [int(hex(byte), 16) for byte in data[0]['data']]
    print(f"Extracted data: {extracted_data}")

send_thread = threading.Thread(target=send_data, args=(100,))
receive_thread = threading.Thread(target=receive_data)

send_thread.start()
receive_thread.start()

send_thread.join()
receive_thread.join()
    
    