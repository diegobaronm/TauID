#IMPORTING RELEVANT LIBRARIES
import os
import subprocess

# COUNTER FOR NUMBER OF CONTAINERS WITH LESS THAN 1M EVENTS
c=0

# OPENING FILE WITH SAMPLES TO CHECK
with open("samples.txt","r") as file:

    # CHECKING EACH SAMPLE
    for line in file:
        output=subprocess.check_output("rucio list-files "+line,shell=True) #LIST FILES WITH RUCIO
        info=output.split('\n')[-4:-1] #EXTRACT METADATA ON A LIST
        n_events=float((info[2]).split(':')[1]) #GET NUMBER OF EVENTS

        # CHECK IF CONTAINER HAS LESS THAN 1M EVENTS
        if n_events<1000000:
            c+=1

        # WRITE INFORMATION OF EACH CONTAINER TO A FILE
        info_file=open("info.txt","a")
        info_file.write(line)
        for x in info:
            info_file.write(x+'\n')
        info_file.write('-'*150+'\n')
        info_file.close()

# PRINT A WARNING MESSAGE WITH NUMBER OF CONTAINERS WITH LESS THAN 1M EVENTS
if c==0:
    print("All containers have more than 1M Events")
else :
    print("WARNING!")
    print("There are "+str(c)+" containers with less than 1M Events")
