import serial, time
from Coneccion import ConneccionMySql

arduino = serial.Serial("COM3", 9600)
time.sleep(2)

datos = ConneccionMySql()

try:
    while True:
        mq_135 = arduino.readline()
        mq_2 = arduino.readline()
        datos.insertando(mq_135, mq_2)
        print("insertando....")
        time.sleep(60)
except:
    print("a ocurrido un error")

datos.cerrandoConeccion()
arduino.close()




