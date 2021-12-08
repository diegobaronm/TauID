#!/bin/bash
rm -rf MC/out/NOMINAL
rm -rf DATA/out/NOMINAL
mkdir MC/out/NOMINAL
mkdir DATA/out/NOMINAL
cp MC/Analysis.h DATA/Analysis.h

python3 Compiler.py DATA

python3 lister.py DATA

cd DATA

parallel -j $1 --progress -a samples.txt python3 RunAnalysis.py ::: no ::: NOMINAL

cd ..

python3 Compiler.py MC

python3 lister.py MC

cd MC

parallel -j $1 --progress -a samples.txt python3 RunAnalysis.py ::: no ::: NOMINAL

cd ..

hadd MC/out/Signal_Sherpa.root MC/out/NOMINAL/Ztautau_sherpa*.root
hadd MC/out/Signal_PoPy.root MC/out/NOMINAL/Ztautau_201*.root
hadd MC/out/Zmumu.root MC/out/NOMINAL/Zmumu_201*.root
hadd MC/out/VV.root MC/out/NOMINAL/llll*.root MC/out/NOMINAL/lllv*.root MC/out/NOMINAL/llvv*.root MC/out/NOMINAL/lvvv*.root MC/out/NOMINAL/ZqqZvv*.root MC/out/NOMINAL/ZqqZll*.root MC/out/NOMINAL/WqqZvv*.root MC/out/NOMINAL/WqqZll*.root MC/out/NOMINAL/WlvZqq*.root
hadd MC/out/Wjets.root MC/out/NOMINAL/Wplusenu*.root MC/out/NOMINAL/Wminusenu*.root MC/out/NOMINAL/Wplusmunu*.root MC/out/NOMINAL/Wminusmunu*.root MC/out/NOMINAL/Wplustaunu*.root MC/out/NOMINAL/Wminustaunu*.root
hadd MC/out/singletop.root MC/out/NOMINAL/st_schan_top*.root MC/out/NOMINAL/st_schan_atop*.root MC/out/NOMINAL/st_tchan_top*.root MC/out/NOMINAL/st_tchan_atop*.root MC/out/NOMINAL/st_wt_top*.root MC/out/NOMINAL/st_wt_atop*.root
hadd MC/out/ttbar.root MC/out/NOMINAL/ttbar_201*.root
hadd DATA/out/data.root DATA/out/NOMINAL/data_201*.root
