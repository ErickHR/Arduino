import serial, time
#impot pymysql
arduino = serial.Serial("COM3", 9600)
time.sleep(2)

"""coneccion = pymysql.connect(
host='localhost',
user='root',
password='Erickrivas',
db='bdarduino'
).connection

coneccion.cursor = coneccion.connection.cursor()
 
print("conexxcion establecida")
"""
        
while True :
    datos = arduino.readline();
    print(datos)
    time.sleep(4)
    """try:
        self.cursor.execute('insert into mq_135(mq_135) value("{}")'.format(datos))
        self.connection.commit()
    except Exception as e:
        raise"""
    

arduino.close()
