    #MIRAAAAAAAAAAAAAAAAAAAAA SOY GABO
import time
import board
import adafruit_tcs34725

# Initialize the color sensor
i2c = board.I2C()
color_sensor = adafruit_tcs34725.TCS34725(i2c)

# Main loop
while True:
    # Read RGB values from the color sensor
    r, g, b, _ = color_sensor.color_rgb_bytes

    # Print the RGB values
    print("Red: {}, Green: {}, Blue: {}".format(r, g, b))

    # Wait for a short delay before reading again
    time.sleep(0.5)