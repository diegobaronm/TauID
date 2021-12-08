#!/bin/bash
# py Unifiyer.py First_Directory Second_Directory Combinated_Directory

regions=('CR_OS/' 'SR_SS/' 'SR_OS/' 'CR_SS/')

mkdir $3
for h in ${regions[@]}
do
    mkdir $3$h
done

for i in ${regions[@]}
do
    dir=$1$i
    b=$(ls $dir)
    for j in $b
    do
        if [ ${j:(-4)} = 'root' ];then
            hadd $3$i$j $1$i$j $2$i$j
        fi
    done
done

