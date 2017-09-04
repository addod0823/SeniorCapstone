import serial
import signal


ser = serial.Serial(port='/dev/tty.usbmodem1421', baudrate=9600, bytesize=serial.EIGHTBITS, parity=serial.PARITY_NONE, timeout=2)
signal.signal(signal.SIGINT, lambda x,y: sys.exit(0))

file = open("/Users/derrickaddo/Desktop/Capstone/x_y.txt","w+")
try:
    ser.isOpen()
    print("Getting data from arduino...")
except:
    print("Error")
    exit()

if(ser.isOpen()):
    try:
        while(1):
            file.write(ser.read())
    except Exception:
        print("")
else:
     print("Cannot open serial port")
