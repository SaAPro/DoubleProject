import socket
import subprocess
from curtsies import Input

PORT = 6001                     # Reserve a port for your service.
HOST = '130.251.13.118'         # Set IP adress    # '130.251.13.110'

s = socket.socket()             # Create a socket object
s.bind((HOST, PORT))            # Bind to the port
s.listen(5)                     # Now wait for client connection.

available_commands = ["u", "b", "1", "2", "3", "4", "a", "t", "e", "+", "-", "00", "n", "i", "o", "q", "h"]
help_menu = """\
    --------------------------------
    HELP MENU
    --------------------------------
    arrow keys:  move Double (press one key at a time)
    1:  Set the tag location to "laboratorium"
    2:  Set the tag location to "corridor"
    3:  Set the tag location to "graal_laboratory"
    4:  Set the tag location to "corridor" "stairs"
    a:  acquire training set
    t:  train the model
    e:  take and evaluate the picture with the current trained model
    
    u:  unblock Double
    b:  block Double
    +:  raise pole
    -:  lower pole
    00: stop pole
    
    Esc:  quit
    --------------------------------
    """

print('Server listening...')
print("Waiting for the app to be run on Double's iPad...")
conn, addr = s.accept()         # Establish connection with client.
print('Connected to Double!')   # , addr)
print(help_menu)

ESC = "\x1b"
SPACE_BAR = " "
ARROW_DOWN = "KEY_DOWN"
ARROW_UP = "KEY_UP"
ARROW_LEFT = "KEY_LEFT"
ARROW_RIGHT = "KEY_RIGHT"

with Input(keynames='curses') as input_generator:
    for key in input_generator:
        print(key)
        conn.send(key.encode('utf-8'))
        conn.close()
        if key == ESC:
            break
        conn, addr = s.accept()

##    elif command.lower() == "h":
##        print(help_menu)

print('Application terminated.')

