import os
import sys

sys.path.append('backend')

from dataSets import dataCombos

samples=[]
for i in dataCombos:
    if("_sys" in i and "_jet" not in i):
         samples+=dataCombos[i]

with open("samples_sys.txt","w") as file:
    for j in samples:
        file.write(j)
        file.write('\n')

