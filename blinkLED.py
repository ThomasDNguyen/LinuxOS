'''CREDITS:
Student Name:   Nguyen Duy Thanh
Student Number: e1601122
School: 	VAASA University of Applied Sciences (VAMK), Vaasa, Finland
-------------------------------------------------------------------------------'''

#This is a Python program to blink the onboard leds of the RPi 3 Model B

'''P.S: If you want to enforce your knowledge on the programming language C++ make sure to visit my github page: ... . Also, feel free
to leave any comments/suggestions and if you wish to use this code for your own project(s) please be sure to include the credits.
Thank you and have a nice day :D '''

#To compile .py program: python3 *file_name*


import time

#This is the function to blink the ACT led (the green one) of the RPi 3 Model B
def led0():
	#1st argument is to open file "brightness" at location "/sys/class/leds/led0" and the 2nd one is to  set the mode of the file to write
	f=open("/sys/class/leds/led0/brightness","w")
	#Write "1" to file "brightness"
	f.write("1")
	#Close the file (to make the changes take effect ofc)
	f.close()
	#Put the program to sleep
	time.sleep(.1)
	#From here on out it's basically the same principle
	f=open("/sys/class/leds/led0/brightness","w")
	f.write("0")
	f.close()
	time.sleep(.1)

#This is the function to blink the PWR led (the red one) of the RPi 3 Model B
def led1():
	f=open("/sys/class/leds/led1/brightness","w")
	f.write("1")
	f.close()
	time.sleep(.1)
	f=open("/sys/class/leds/led1/brightness","w")
	f.write("0")
	f.close()
	time.sleep(.1)

#This is the main() function where it calls the 2 functions led0() and led1()
def main():
	count=1
	while count <= 100:
		led0()
		led1()
		count+=1
	time.sleep(.1)

#Executing the main() function
if __name__== "__main__":
	main()
