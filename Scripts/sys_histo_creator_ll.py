import sys

histos=[]
with open("sys_variables.txt","r") as file:
	histos=file.readlines()

for i in range(len(histos)):
    histos[i]=histos[i].rstrip('\n')

def book():
	for stage in ["cuts_","cuts_ptl_"]:
		for i in histos:
			print('h_yield_sys_'+stage+i+' = new TH1F("yield_sys_'+stage+i+'","Systematic related yield",40,0,40);')
		print("\n")
	print("\n")

def write():
	for stage in ["cuts_","cuts_ptl_"]:
			for i in histos:
					print('h_yield_sys_'+stage+i+'->Write();')
			print("\n")
	print("\n")

def define():
	for stage in ["cuts_","cuts_ptl_"]:
			for i in histos:
					print('TH1F* h_yield_sys_'+stage+i+';')
			print("\n")
	print("\n")

def fill():
	for stage in ["cuts_","cuts_ptl_"]:
		for i in histos:
			print('h_yield_sys_'+stage+i+'->Fill(r_lpt_tpt,weight*'+i+'/RELSYS);')
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
