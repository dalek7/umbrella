# UDP server example
import socket
import sys

server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
if len(sys.argv) > 1:
	port = int(sys.argv[1])
else:
	port = 12345

server_socket.bind(("", port))

#http://stackoverflow.com/questions/166506/finding-local-ip-addresses-using-pythons-stdlib
print("Internal : ")
print([(s.connect(('8.8.8.8', 80)), s.getsockname()[0], s.close()) for s in [socket.socket(socket.AF_INET, socket.SOCK_DGRAM)]][0][1])

print("UDPServer Waiting for client on port {}...".format(port))
 
while 1:
	data, address = server_socket.recvfrom(256)
	print("( {}:{} ) said {}".format(address[0], address[1], data))
