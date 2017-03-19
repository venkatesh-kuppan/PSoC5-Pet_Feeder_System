import time
import serial
import smtplib
TO = 'pet_feeder@gmail.com'
GMAIL_USER = 'pir_sensor@gmail.com'
GMAIL_PASS = 'abcd'
SUBJECT = 'Pet Feeder System Alert!!'
TEXT = 'PIR sensor detected pet movement, Motor will be turned ON'
ser = serial.Serial('COM2', 9600)
def send_email():
	print("Sending Email")
	smtpserver = smtplib.SMTP("smtp.gmail.com",587)
	smtpserver.ehlo()
	smtpserver.starttls()
	smtpserver.ehlo
	smtpserver.login(GMAIL_USER, GMAIL_PASS)
	header = 'To:' + TO + '\n' + 'From: ' + GMAIL_USER
	header = header + '\n' + 'Subject:' + SUBJECT + '\n'
	print header
	msg = header + '\n' + TEXT + ' \n\n'
	smtpserver.sendmail(GMAIL_USER, TO, msg)
	smtpserver.close()

while True:
	message = ser.readline()
	print(message)
	if message[0] == 'P' :
		send_email()
	time.sleep(0.5)
