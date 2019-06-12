import os
import datetime

def exit():
    os._exit(0)

def GetTimeString(m = -1):
    if m==0:
        s1 = datetime.datetime.now().strftime("%Y%m%d%H%M%S")
    else:
        s1 = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")

    return s1

def MakeDir(directory):
    if not os.path.exists(directory):
        os.makedirs(directory)