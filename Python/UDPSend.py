import socket
from pynput.keyboard import Key, Listener
#UDP_IP = "192.168.1.200"
#UDP_PORT = 10003

UDP_IP = "127.0.0.1"
UDP_PORT = 10003
MESSAGE = "Hello, World!"

def on_press(key):
    #print(key)
    #print('{0}'.format(key))
    if key== Key.up:
        print("Up !")
        send("w", UDP_IP, UDP_PORT)
    elif key== Key.down:
        print("Down !")
        send("s", UDP_IP, UDP_PORT)
    elif key== Key.left:
        print("Left !")
        send("a", UDP_IP, UDP_PORT)
    elif key== Key.right:
        print("Right !")
        send("d", UDP_IP, UDP_PORT)


def on_release(key):
    # print('{0} release'.format(key))
    if key == Key.esc:
        # Stop listener
        return False


def send(data, port=10000, addr='127.0.0.1'):
    """send(data[, port[, addr]]) - multicasts a UDP datagram."""
    # Create the socket

    #print("UDP target IP:", UDP_IP)
    #print("UDP target port:", UDP_PORT)
    print("Sending message: {}".format(data))

    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)  # UDP
    sock.sendto(bytes(data, "utf-8"), (UDP_IP, UDP_PORT))

# Collect events until released
with Listener(
        on_press=on_press,
        on_release=on_release) as listener:
    listener.join()