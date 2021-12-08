#IMPORT RELEVANT LIBRARIES
import os

def Find_Data(dsid):
		
	# DATASET AND DERIVATION TO BE CHECKED
	Derivation="recon.AOD"
	Dataset="mc16_13TeV."+str(dsid)+".*."+Derivation+".e*_s*_r*"

	# CREATE A TEMPORARY FILE THAT STORES ALL THE MATCHES WITH THE RELEVANT DATASET AND DERIVATION
	if("recon" not in Derivation):
		os.system("rucio ls "+Dataset+" | grep CONTAINER | grep p4097 | cut -c 2-160 > temp.txt")
	else :
		os.system("rucio ls "+Dataset+" | grep CONTAINER > temp.txt")
	with open("temp.txt","r") as file:
		for line in file:
			spaces=line.count(" ")
			file_with_just_string=open('temp_corrected.txt','a')
			file_with_just_string.write(line[1:len(line)-spaces-len("|CONTAINER|")+3]+"\n")
			file_with_just_string.close()

	os.system("rm temp.txt")

	# OPEN TEMPORARY FILE TO CHECK IF IT HAS A GOOD FORMAT TO BE A CANDIDATE
	with open("temp_corrected.txt","r") as file:

		# LOOP OVER ALL CONTAINERS AND EXTRACT THE AMI TAG
		for line in file:
			pos=0 # VARIABLE TO STORE THE POSITION OF THE BEGINING OF THE AMI TAGS
			for chain in line:
				if chain==Derivation[0]:
					if line[pos:pos+len(Derivation)]==Derivation:
						break
				pos+=1
			pos=pos+len(Derivation)+1
			tag=line[pos:] #FINAL TAG
	
			# FLAG TO DECIDE IF FILE IS WRITTEN AT THE END
			write=True
			#CHECK DATA BELONGS TO 2018,2017,2016,2015
			if(not(("10724" in tag) or ("10201" in tag) or ("9364" in tag))):
				write=False
			#CHECK FULL SIM
			if("3126" not in tag):
				write=False
			# LOOP OVER THE TAG LOOKING FOR THE FOLLOWING FORMAT : e*_s*_r*_p*
			
			if write:
				#COUNTERS FOR EACH TYPE OF TAG
				e=0
				s=0
				r=0
				p=0
				for i in tag:
					if i=="e":
						e+=1
					if i=="s":
						s+=1
					if i=="r":
						r+=1
					if i=="p":
						p+=1
					if (e>1 or s>1 or r>1 or p>1):
						write=False
						break #IF ONE TAG SPECIFIER IS DUPLICATED EXIT THE LOOP AND DISCARD FILE FOR WRITE
		
			# WRITE TO A FILE CALLED samples.txt
			if write:
				final_file = open('samples.txt', 'a')
				final_file.write(line)
				final_file.close()

	#ERASE TEMPORARY FILE USED FOR MATCHES IN RUCIO
	os.system("rm temp_corrected.txt")

DSID_list=[361106,361107,361108]

for DSID in DSID_list:
	Find_Data(DSID)
