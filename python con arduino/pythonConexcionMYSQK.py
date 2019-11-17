import pymysql

class DataBase:
    def __init__(self):
        self.connection = pymysql.connect(
            host='localhost',
            user='root',
            password='Erickrivas',
            db='bdarduino'
            )
        self.cursor = self.connection.cursor()
    
        print("conexxcion establecida")

    def select_user(self, id):
        sql = 'select * from prueba where id = {id}'.format(id)

        try:
            self.cursor.execute(sql)
            user = self.cursos.fetchone()

            print("id:     ", user[0])
            print("nombre: ", user[1])
            print("edad: ", user[2])

        except Exception as e:
            raise

    def select_all_user(self):
        sql = 'select * from prueba'

        try:
            self.cursor.execute(sql)
            users = self.cursor.fetchall()

            for user in users:
                print("id:     ", user[0])
                print("nombre: ", user[1])
                print("edad: ", user[2])
                print("-------------\n")
        except Exception as e:
            raise
        
    def update_user(self, nombre, edad, id):
        sql = 'update prueba set nombre = "{}", edad = "{}" where id = "{}"'.format(nombre, edad, id)

        try:
            self.cursor.execute(sql)
            self.connection.commit()
        except Exception as e:
            raise

    def insert_user(self, nombre, edad):
        sql = 'insert into prueba(nombre, edad) value("{}", "{}")'.format(nombre, edad)
        try:
            self.cursor.execute(sql)
            self.connection.commit()
        except Exception as e:
            raise
    
    def close_connection(self):
        self.connection.close()
            
database = DataBase()
database.select_all_user()
database.insert_user("anatolia", 70)
database.select_all_user()
database.close_connection()
