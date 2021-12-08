import sys

histos=[]
with open("sys_variables.txt","r") as file:
	histos=file.readlines()

for i in range(len(histos)):
    histos[i]=histos[i].rstrip('\n')

def book():
	for prongs in ["1","3"]:
		for stage in ["cuts_","cuts_tpt_"]:
			for i in histos:
				print('h_tm'+prongs+'p_'+stage+i+' = new TH1F("tau_matched_'+prongs+'p_'+stage+i+'","Systematic related yield",2,0,2);')
			print("\n")
		print("\n")

def write():
        for prongs in ["1","3"]:
                for stage in ["cuts_","cuts_tpt_"]:
                        for i in histos:
                                print('h_tm'+prongs+'p_'+stage+i+'->Write();')
                        print("\n")
                print("\n")

def define():
        for prongs in ["1","3"]:
                for stage in ["cuts_","cuts_tpt_"]:
                        for i in histos:
                                print('TH1F* h_tm'+prongs+'p_'+stage+i+';')
                        print("\n")
                print("\n")

def fill():
	for prongs in ["1","3"]:
		for stage in ["cuts_","cuts_tpt_"]:
			for i in histos:
				print('h_tm'+prongs+'p_'+stage+i+'->Fill(tau_0_truth_isHadTau,weight*'+i+'/RELSYS);')
			print("\n")
		print("\n")

if sys.argv[1]=="book":
	book()
elif sys.argv[1]=="write":
	write()
elif sys.argv[1]=="define":
	define()
elif sys.argv[1]=="fill":
	fill()
else :
	print("Incorrect argument! TRY AGAIN!")
