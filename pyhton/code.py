from pymouse import PyMouse
from pykeyboard import PyKeyboard
import serial
k = PyKeyboard();
ser = serial.Serial('/dev/ttyUSB2', 115200, timeout=1)
items = []

while True:
	readq = ser.readline();
	if (readq == 'UP\n'):
		if 'w' not in items:
			k.press_key('w')
			items.append('w')
				
	if (readq == 'DOWN\n'):
		k.press_key('s')
                if 's' not in items:
 	               items.append('s')
        if (readq == 'LEFT\n'):
                k.press_key('a')
                if 'a' not in items:
                       items.append('a')
        if (readq == 'RIGHT\n'):
                k.press_key('d')
                if 'd' not in items:
                       items.append('d')
        if (readq == 'A\n'):
                k.press_key('z')
                if 'z' not in items:
                       items.append('z')
        if (readq == 'B\n'):
                k.press_key('x')
                if 'x' not in items:
                       items.append('x')
        if (readq == 'C\n'):
                k.press_key('c')
                if 'c' not in items:
                       items.append('c')
        if (readq == 'START\n'):
                k.press_key('p')
                if 'p' not in items:
                       items.append('p')


	if (readq == 'STOP\n'):
		for item in items:
    			k.release_key(item)
			items.remove(item)
ser.close() 
