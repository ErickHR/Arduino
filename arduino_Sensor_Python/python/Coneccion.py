import pymysql

class ConneccionMySql:
    def __init__(self):
        self.connection = pymysql.connect(
            host='localhost',
            user='root',
            password='Erickrivas',
            db='bdarduino'
            )
        self.cursor = self.connection.cursor()
    
        print("coneccion establecida")

    def insertando(self, mq_135, mq_2):
        sql = 'insert into sensor(mq_135, mq_2) value("{}", "{}")'.format(mq_135, mq_2)
        try:
            self.cursor.execute(sql)
            self.connection.commit()
        except Exception as e:
            raise
    
    def cerrandoConeccion(self):
        self.connection.close()
