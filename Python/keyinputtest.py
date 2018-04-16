from pynput.keyboard import Key, Listener

def on_press(key):
    #print('{0}'.format(key))
    if key== Key.up:
        print("Up !")
    elif key== Key.down:
        print("Down !")
    elif key== Key.left:
        print("Left !")
    elif key== Key.right:
        print("Right !")


def on_release(key):
    # print('{0} release'.format(key))
    if key == Key.esc:
        # Stop listener
        return False

# Collect events until released
with Listener(
        on_press=on_press,
        on_release=on_release) as listener:
    listener.join()