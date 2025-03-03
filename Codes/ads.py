import board
import busio
import time
import adafruit_ads1x15.ads1115 as ADS
from adafruit_ads1x15.analog_in import AnalogIn
i2c = busio.I2C(board.SCL, board.SDA)
#time.sleep(1)
ads = ADS.ADS1115(i2c)
time.sleep(1)
chan1 = AnalogIn(ads, ADS.P0)
chan2 = AnalogIn(ads, ADS.P1)
chan3 = AnalogIn(ads, ADS.P2)
#time.sleep(1)
while(1):
    print(chan1.voltage)  #MQ2
    #time.sleep(.2)
   # print(chan2.voltage)  #MQ8
    #time.sleep(10)
   #print(chan3.voltage)  #MQ9
    time.sleep(.5)