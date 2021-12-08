#!/bin/bash
cd ..

python3 Compiler.py MC

cd MC

python3 lister_sys.py

if [ "$2" = "NOMINAL" ]
then
	parallel -j $1 --progress -a samples_sys.txt python3 RunAnalysis.py ::: no ::: NOMINAL
fi

if [ "$2" = "SYS" ]
then
    parallel -j $1 --progress -a samples_sys.txt python3 RunAnalysis.py ::: no :::: sys_trees.txt
fi

