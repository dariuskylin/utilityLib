#print '%s is number %d!' % ('Python',1)

logfile = open('mylog.txt','a')
print >> logfile, 'Fatal error:invalid input!'
logfile.close()

import sys
print >> sys.stderr, 'Fatal error:invalid input!'
