# https://stackoverflow.com/a/11342486

class Machine:

    # Class Variable counts how many machines have been created.
    # The value is the same for all objects of this class.
    counter = 0

    def __init__(self):

        # Notice: no 'self'.
        Machine.counter += 1

        # Instance variable.
        # Different for every object of the class.
        self.id = Machine.counter

machine1 = Machine()
machine2 = Machine()
machine3 = Machine()

#The value is different for all objects.
print 'machine1.id', machine1.id
print 'machine2.id', machine2.id
print 'machine3.id', machine3.id

#The value is the same for all objects.
print 'machine1.counter', machine1.counter
print 'machine2.counter', machine2.counter
print 'machine3.counter', machine3.counter