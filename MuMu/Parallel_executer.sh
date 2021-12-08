#!/bin/bash
# REMOVE WHAT IS IN out_previous AND FILL IT WITH out CONTENTS
rm -rf MC/out/NOMINAL
mkdir MC/out/NOMINAL
rm -rf DATA/out/NOMINAL
mkdir DATA/out/NOMINAL
cp MC/Analysis.h DATA/Analysis.h

python3 Compiler.py DATA

python3 lister.py DATA

cd DATA

parallel -j 9 --progress -a samples.txt python3 RunAnalysis.py ::: no ::: NOMINAL

cd ..

python3 Compiler.py MC

python3 lister.py MC

cd MC

parallel -j 9 --progress -a samples.txt python3 RunAnalysis.py ::: no ::: NOMINAL

cd ..

hadd MC/out/Signal_Sherpa.root MC/out/NOMINAL/Zmumu_sherpa*.root
hadd MC/out/Ztautau_PoPy.root MC/out/NOMINAL/Ztautau_*.root
hadd MC/out/Signal_PoPy.root MC/out/NOMINAL/Zmumu_201*.root
hadd MC/out/VV.root MC/out/NOMINAL/llll_*.root MC/out/NOMINAL/lllv_*.root MC/out/NOMINAL/llvv_*.root MC/out/NOMINAL/lvvv_*.root MC/out/NOMINAL/ZqqZvv_*.root MC/out/NOMINAL/ZqqZll_*.root MC/out/NOMINAL/WqqZvv_*.root MC/out/NOMINAL/WqqZll_*.root MC/out/NOMINAL/WlvZqq_*.root
hadd MC/out/Wjets.root MC/out/NOMINAL/Wplusenu_*.root MC/out/NOMINAL/Wminusenu_*.root MC/out/NOMINAL/Wplusmunu_*.root MC/out/NOMINAL/Wminusmunu_*.root MC/out/NOMINAL/Wplustaunu_*.root MC/out/NOMINAL/Wminustaunu_*.root
hadd MC/out/singletop.root MC/out/NOMINAL/st_schan_top_*.root MC/out/NOMINAL/st_schan_atop_*.root MC/out/NOMINAL/st_tchan_top_*.root MC/out/NOMINAL/st_tchan_atop_*.root MC/out/NOMINAL/st_wt_top_*.root MC/out/NOMINAL/st_wt_atop_*.root
hadd MC/out/ttbar.root MC/out/NOMINAL/ttbar_*.root
hadd DATA/out/data.root DATA/out/NOMINAL/data_*.root