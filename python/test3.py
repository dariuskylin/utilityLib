class FooClass(object):
    """my very first class: FooClass"""
    version = 0.1 #class (data)attribute
    def __init__(self,nm='John Doe'):
        """constructor"""
        self.name = nm #class instance (data)attribute
        print 'Created a class instance for ',nm
    def showname(self):
        """display instance attribute and class name"""
        print 'Your name is',self.name
        print 'My name is',self.__class__.__name__
    def showver(self):
        """display class(static) attribute"""
        print self.version  #references FooClass.version
    def addMe2Me(self,x):   #does not use self
        """apply + operation to argument"""
        return (x+x)
