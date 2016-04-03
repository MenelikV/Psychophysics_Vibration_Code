# MATLAB2ARDUINO
MATLAB for a communication with an arduino
The aim was to monitore a vibration generator with 2 arduino.
* A1 connected to an wave generator / amplfiier (itself connected to the vibration generator) (via its serial port)
* A0 connected via I2C to A1 and connected with Serial port to a computer.

#Protocol 

1. The computer sends parameters to A0
2. Arduino A0 transfer data
3. Data sent to the vibration generator thourgh A1
4. A1 should be able to capture some feedback and send data to A0
(which can forward data coming from A1 to the computer too)

# Goal

The goal of such a circuit was to, thanks to the vibration generators, investigate the conditions in which person is able to distinguish two different vibration waves/
