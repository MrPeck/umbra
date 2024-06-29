#!/usr/bin/python

import socket
import struct

PORT = 1337
FILE_PATH = '/home/ppeck/Desktop/Stuff/Cyber/Projects/rootkit/test'

server_sock = socket.socket()
server_sock.bind(('', PORT))
server_sock.listen(1)
client_sock, client_address = server_sock.accept()

client_sock.send()


client_sock.recv(1)


server_sock.close()
client_sock.close()
