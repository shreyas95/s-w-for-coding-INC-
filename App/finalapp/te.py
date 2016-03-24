import sys
import os
from sandbox import *
'''
1 ------------>    Output within time
2 ------------>    fork()
3 ------------>    Excess Memory
4
5 ------------>    Time limit exceeded
6 ------------>    Segmentation fault

''' 

result = 0
 
def sand(program_path, input_path):

    f_wr = os.open("stdout.txt",os.O_TRUNC|os.O_RDWR|os.O_CREAT)
    #s = Sandbox(program_path, owner="nobody", stdin=open(input_path, "r"), stdout=f_wr)
    
    cookbook = {
        'args': program_path,               # targeted program
        'owner':"nobody",
        'stdin': open(input_path, "r"),             # input to targeted program
        'stdout': f_wr,           # output from targeted program
        #'stderr': sys.stderr,           # error from targeted program
        'quota': dict(wallclock=30000,  # 30 sec
                      cpu=2000,			#2sec
                      memory = 8388608*2, #  16 MB
                      disk = 1048576)}    # 1 MB

    s = Sandbox(**cookbook)
    s.run()
    output = os.fdopen(f_wr)
    output.seek(0)
    verdict = {'stdout' : output.read() , 'verdict' : s.result}
    
    return verdict
    
'''
os.system("g++ -o test1 test1.c")
a = sand("./test1","./input.txt")
result = a['verdict']

print result

if result == 1:
	print "Output within time"
elif result == 2:
	print "Fork found"
elif result == 3:
	print "Memory limit exceeded"
elif result == 5:
	print "Time limit exceeded"
elif result == 6:
	print "Segmentation fault"
'''	


