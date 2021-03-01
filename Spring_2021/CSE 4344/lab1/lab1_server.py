'''
Aamir Mazumdar 1001523593
CSE 4344 - 001
Lab 1
'''



from socket import *
import threading
from _thread import *
import os.path
from os import path


IP = 'localhost'
PORT = 8080
BUFFER_SIZE = 1024
FORMAT = 'utf-8'

print_lock = threading.Lock()

def client_thread(clientSocket):
    while True:
        data = clientSocket.recv(1024) #retrive the data from the client

        if len(data) < 1: break        #breaks if the client does not have any data
        buffer = data.decode()         #decodes the byte string into a string

        filename = buffer.split()[1]   #storing element 1 of the request from the client.
                                       #the split function split it by whitespace.
        
        #301 Portion of the Lab
        if filename[1:] == "freecookies.html":
            #Send response message for 301
            header = "HTTP/1.1 301 Moved Permanently \r\n"
            header += "Location: http://localhost:8080/index.html"
            header += "\r\n"
            header += "<html><body>301 Moved Permanently. No more free cookies</body></html>\r\n\r\n" 

            #sending the error message to the client
            clientSocket.send(header.encode(FORMAT))
            break 

        #checks if the file exists else shows the 404 error message.
        elif path.exists(filename[1:]):
            f = open(filename[1:], "rb") # opens the file name in the form of a byte string
            
            outputdata = f.read() #reading the contents of the file
            f.close
            header = "HTTP/1.1 200 OK \r\n"
            header += "\r\n"
            temp = header.encode(FORMAT) #converted the HTTP response into a byte string
            final = temp + outputdata #concatenated the two byte strins in order to send to the client socket.
            clientSocket.send(final)
            break
        
        else:
            #Send response message for file not found
            header = "HTTP/1.1 404 Not Found \r\n"
            header += "\r\n"
            header += "<html><body>404 Not Found</body></html>\r\n\r\n" 

            #sending the error message to the client
            clientSocket.send(header.encode(FORMAT)) 
            break
    print_lock.release() #releasing the thread
    clientSocket.close() #closing the client socket's connection





def main():
    serverSocket = socket(AF_INET, SOCK_STREAM)  # Establishes the welcoming socket
    serverSocket.bind((IP, PORT))

    #puts the socket to listen for a connection
    serverSocket.listen(1)
    while True:
        clientSocket, address = serverSocket.accept()

        #the lock acquired by the client. explanation was from here:
        #https://www.geeksforgeeks.org/socket-programming-multi-threading-python/
        print_lock.acquire() 
        print(f"Connected to {address}.")

        #starts a new thread
        start_new_thread(client_thread, (clientSocket,))

if __name__ == '__main__':
    main()

