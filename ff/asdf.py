from turtle import down, up
import pycm import *

console(BLE)

ir1 = OLLO(1, const.OLLO_IR)
ir2 = OLLO(2, const.OLLO_IR)
dms = OLLO(3, const.OLLO_DMS)

while True:
    i1 = ir1.read()
    i2 = ir2.read()
    print("ir1", i1, "ir2", i2)
    delay(500)
