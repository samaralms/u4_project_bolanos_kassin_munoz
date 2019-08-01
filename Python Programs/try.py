#!/usr/bin/env python
import serial
import keyboard, click


serial_port = serial.Serial("/dev/rfcomm4", baudrate = 115200)

while True:
 key = click.getchar()
 #archivo = open("prueba.txt","w")
 if keyboard.is_pressed('down') == True or keyboard.is_pressed('up') == True or keyboard.is_pressed('left') == True or keyboard.is_pressed('right') == True or keyboard.is_pressed('+') == True or keyboard.is_pressed('p') == True or keyboard.is_pressed('w') == True or keyboard.is_pressed('g') == True or keyboard.is_pressed('s') == True or keyboard.is_pressed('a') == True:

	#if keyboard.is_pressed('up'):
	if key =='\x1b[A':
		print('Up')
		estandar = 'uu'
		serial_port.write(estandar)

	#elif keyboard.is_pressed('down'):
	elif key =='\x1b[B':
		print('Down')
		estandar = 'dd'
		serial_port.write(estandar)

	#elif keyboard.is_pressed('right'):
	elif key =='\x1b[C':
		print('Right')
		estandar = 'rr'
		serial_port.write(estandar)

	#elif keyboard.is_pressed('left'):
	elif key =='\x1b[D':
		print('Left')
		estandar = 'll'
		serial_port.write(estandar)

	elif keyboard.is_pressed('a'):
		print('Spin Left')
		estandar = 'aa'
		serial_port.write(estandar)

	elif keyboard.is_pressed('s'):
		print('Spin Right')
		estandar = 'ss'
		serial_port.write(estandar)

	elif keyboard.is_pressed('w'):
		print('Controller')
		estandar = 'ww'
		serial_port.write(estandar)

	elif keyboard.is_pressed('g'):
		print('Autonomous')
		estandar = 'gg'
		serial_port.write(estandar)

	elif keyboard.is_pressed('p'):
		print('stop')
		estandar = 'ss'
		serial_port.write(estandar)

	else:
		print('Uknonwn command')
		estandar = 'Uknonwn command'
		serial_port.write(estandar)


	#archivo.write(str((estandar)))
 	print(estandar)

 else :
	print('Stop')
	estandar = 'ss'
	print(estandar)
	#archivo.write(str((estandar)))
