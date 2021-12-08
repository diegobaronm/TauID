import os
import sys

sys.path.append('backend')

from dataSets import dataCombos

samples=[]
for i in dataCombos:
    if(("_sys_jet") in i):
         samples.append(i)

with open("samples_sys_jet.txt","w") as file:
    for j in samples:
        file.write(j)
        file.write('\n')

