#!/bin/bash

count=1
while [ $count -le 100 ]
do
	echo 1 > /sys/class/leds/led0/brightness
	sleep 0.1
	echo 0 > /sys/class/leds/led0/brightness
	sleep 0.1
	echo 1 > /sys/class/leds/led1/brightness
	sleep 0.1
	echo 0 > /sys/class/leds/led1/brightness
	sleep 0.1
	((count++))
done
