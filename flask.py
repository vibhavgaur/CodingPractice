def chooseFlask(requirements, flaskTypes, markings):
    print("Flask chosen")


requirements, flaskTypes, markings = [], [], []
with open('output005.txt','r') as file:
    numRequirements = int(file.readline().strip())
    for _ in range(numRequirements):
        requirements.append(file.readline().strip())
    
    flaskTypes = int(file.readline().strip())
    
    totalMarks = int(file.readline().strip())
    markings_colsize = int(file.readline().strip())
    for _ in range(totalMarks-1):
        marking = file.readline().strip()
        marking = list(map(int, marking.rsplit(" ")))
        markings.append(marking)

chooseFlask(requirements, flaskTypes, markings)
