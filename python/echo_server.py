from socket import *

myHost = '127.0.0.1'
myPort = 50008

sockobj = socket(AF_INET,SOCK_STREAM)
sockobj.bind((myHost,myPort))
sockobj.listen(5)

while True:
    connection,address = sockobj.accept()
    print('Server connect by',address)
    while True:
        data = connection.recv(1024)
        if not data: break
        print(data)
        connection.send(b'ECHO->' + data)
    connection.close()
