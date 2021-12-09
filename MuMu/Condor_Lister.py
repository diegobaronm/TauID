import os
import sys

def menu(question,options):
    incorrect_answer=True
    while incorrect_answer:
        print(question)
        c=0
        for i in options:
            c+=1
            print(str(c)+")"+" "+i)
        answer=input()
        if int(answer)<=len(options):
            incorrect_answer=False
        else :
            print("Select a correct option!")
    return int(answer)  

def tag_checker(dir,request,avoid):
    os.chdir(dir)
    sys.path.append('backend')
    from dataSets import dataCombos
    samples=[]
    for i in dataCombos:
        include=True
        for j in request:
            if j not in i:
                include=False
                break
        if include :
            for j in avoid:
                if j in i:
                    include=False
                    break
        if include :
            samples=samples+dataCombos[i]
    with open("Input_Condor.txt","w") as file:
        for j in samples:
            file.write(j)
            file.write('\n')
    os.chdir('..')

def sample_file_generator(type_of_ntuples):
    # NOMINAL
    if type_of_ntuples==1 :
        tag_checker("DATA",[],["sys"])
        tag_checker("MC",[],["sys"])
    else if type_of_ntuples==2 :
        tag_checker("MC",["sys"],["jet"])
    else if type_of_ntuples==3 :
        tag_checker("MC",["sys","jet"],[]) 




ntuples_type=menu("Nominal or systematics?",["Nominal","Systematics NO JET","Systematics JET"])
sample_file_generator(ntuples_type)

