# PSoC5-Pet_Feeder_System
PSoC 5 powered pet feeder system with motion detection and email alert.


This project aims at interfacing the PSoC 5 LP097 with the PIR sensor: HC-SR501, coupled to a stepper motor to open and close the door of the pet feeder system. Additionally, every time the door is opened, an automated email is generated and sent using Python script.

# Interfacing PSoC with Stepper Motor: 
1. A basic interfacing with appropraite turns for the forward and reverse movement to enable opening and closing the door.
2. The design files provides a detailed description as to how the pins were configured for the operation of the stepper motor.
3. A complete port was alloted to the stepper motor, however only 4 bits of the port were used for sending commands for the rotation of the motor.
4. Important things to consider, would be the appropraite delay to be provided for activating the coils of the stepper motor. In this project, since I am using a basic stepper motor, the delay was considered as 10ms. Depending on the type of stepper motor the speed can be adjusted.


# Interfacing the PSoC with PIR Sensor:
1. Interfacing the PIR sensor can be challenging as the PIR sensor can output a HIGH if the configuration is incorrect, or the sensitivity and delay of the sensor is not adjusted accordingly.
2. Adjust the time delay of the PIR sensor, else the output can stay HIGH as long as 5 minutes for a single movement detection. The range for delay is usually between 3 seconds to 5 minutes depending on the manufacturer. The delay is adjusted using a pot attached to the sensor.
3. Connect the VCC and GND to the PSoC and the configure the sensor output as input the PSoC5. 
4. Read the sensor input and trigger the email and motor as required.


# Email alert using Python:
1. Email alerts everytime the motor is turned ON.
2. Install Pyserial for receiving the messages sent via the PSoC UART module. 
