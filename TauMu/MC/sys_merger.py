import os
import sys

samples_dir=sys.argv[1]

os.chdir(samples_dir)

for d in os.listdir():
	if d!="out":
		os.system("hadd out/Signal_Sherpa"+d+".root "+d+"/Ztautau_sherpa*_sys_*"+d+".root")
		os.system("hadd out/Signal_PoPy"+d+".root "+d+"/Ztautau_201*_sys_*"+d+".root")
		os.system("hadd out/Zmumu"+d+".root "+d+"/Zmumu_201*_sys_*"+d+".root")
		os.system("hadd out/VV"+d+".root "+d+"/llll*_sys_*"+d+".root "+d+"/lllv*_sys_*"+d+".root "+d+"/llvv*_sys_*"+d+".root "+d+"/lvvv*_sys_*"+d+".root "+d+"/ZqqZvv*_sys_*"+d+".root "+d+"/ZqqZll*_sys_*"+d+".root "+d+"/WqqZvv*_sys_*"+d+".root "+d+"/WqqZll*_sys_*"+d+".root "+d+"/WlvZqq*_sys_*"+d+".root")
