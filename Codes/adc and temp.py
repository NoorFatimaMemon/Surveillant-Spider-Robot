import board
import busio
import time
import adafruit_ads1x15.ads1115 as ADS
from adafruit_ads1x15.analog_in import AnalogIn
import Adafruit_DHT

i2c = busio.I2C(board.SCL, board.SDA)   #Create the I2C bus
ads = ADS.ADS1115(i2c)                  #Create the ADC object using the I2C bus

sensor = Adafruit_DHT.DHT11
DHT11_pin = 17                          #DHT11 = Temp and humidity sensor

mq2 = AnalogIn(ads, ADS.P0)             #Mq2 = Smoke/Methane gas sensor
mq8 = AnalogIn(ads, ADS.P1)             #Mq8 = Hydogen gas sensor
mq9 = AnalogIn(ads, ADS.P2)             #Mq9 = CO sensor


humidity, temperature = Adafruit_DHT.read_retry(sensor, DHT11_pin)
if humidity is not None and temperature is not None:
    print('Temperature={0:0.1f}*C  Humidity={1:0.1f}% \n'.format(temperature, humidity))
else:
    print('Failed to get reading from the sensor. Try again!')

print("The gases in ppm \n {:>5}\t{:>5}".format('MQ-2', 'MQ-8', 'MQ-9'))

count=0

while count < 10:
    print("{:>5}\t{:>5.5f}".format(mq2.voltage, mq8.voltage, mq9.voltage))
    time.sleep(0.5)

    count+=1
