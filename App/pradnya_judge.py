import sys
import os
from sandbox import *


def sand(argv):
	program_path = argv[0]
	input_path = argv[1]
	o_p = argv[2]
	timelimit = int(argv[3])

    #f_wr = os.open("stdout.txt",os.O_TRUNC|os.O_RDWR|os.O_CREAT)
    #s = Sandbox(program_path, owner="nobody", stdin=open(input_path, "r"), stdout=f_wr)
    
	cookbook = {
        'args': program_path,               # targeted program
        'owner':"nobody",
        'stdin': open(input_path, "r"),             # input to targeted program
        'stdout': open(o_p,"w"),           # output from targeted program
        #'stderr': sys.stderr,           # error from targeted program
        'quota': dict(wallclock=30000,  # 30 sec
                      cpu=timelimit,			#1sec
                      memory = 8388608*250, #  16 MB
                      disk = 1048576)}    # 1 MB

	s = Sandbox(**cookbook)
	s.run()
	print s.result
    #output = os.fdopen(f_wr)
    #output.seek(0)
    #verdict = {'stdout' : output.read() , 'verdict' : s.result}
	return s.result
    
    
if __name__ == "__main__":
	sand(sys.argv[1:])
