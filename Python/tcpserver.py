#!/usr/bin/python                                                                                                                                                                                                                                                    
# http://stackoverflow.com/questions/8404704/non-blocking-python-sockets
import socket
import select

server = socket.socket( socket.AF_INET, socket.SOCK_STREAM )
server.bind( ('localhost', 10000) )
server.listen( 5 )

toread = [server]

running = 1

# we will shut down when all clients disconenct                                                                                                                                                                                                                      
while running:

    rready,wready,err = select.select( toread, [], [] )
    for s in rready:
        if s == server:
            # accepting the socket, which the OS passes off to another                                                                                                                                                                                               
            # socket so we can go back to selecting.  We'll append this                                                                                                                                                                                              
            # new socket to the read list we select on next pass                                                                                                                                                                                                     

            client, address = server.accept()
	    print "Connected: %s" % (address,)
            toread.append( client )  # select on this socket next time                                                                                                                                                                                               
        else:
            # Not the server's socket, so we'll read                                                                                                                                                                                                                 
            data = s.recv( 64 )
            if data:
                print "Received %s" % ( data  )
		s.send(data) 
            else:
                print "Client disconnected"
                s.close()

                # remove socket so we don't watch an invalid 
                # descriptor, decrement client count                                                                                                                                                                      
                toread.remove( s )
                running = len(toread) - 1

# clean up                                                                                                                                                                                                                                                           
server.close()