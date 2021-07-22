def chooseFlask(requirements, flaskTypes, markings):
    waste, perTypeLosses = [], []
    # for each flask type
    for ftype in range(flaskTypes):
        print("\n----- Flask type ", ftype, "-----")
        # get the capacities
        caps = [capacity for fnum, capacity in markings if fnum == ftype]

        # for each requirement
        for req in requirements:
            print("Capacity: ", caps, ", Req: ", req)
            # calculate the extra -- (capacity - req) for each flask in type ftype
            loss = [cap - req for cap in caps]
            # find the smallest positive extra val, and append that to the waste for this flask type
            if len([l for l in loss if l >= 0]):
                # if the flask type can satisfy this order, add the flask type and waste value
                waste.append([ftype, min([l for l in loss if l >= 0])])
                print("Waste: ", waste)
            else:
                # if the flask type cannot satisfy this order, then remove the flask type from the waste list
                waste = [item for item in waste if item[0] != ftype]
                print("Waste removed: ", waste)
                break

    print("Final waste calculations: ", waste)
    validFlasks = [ftype for ftype in list(set(item[0] for item in waste))]
    print("Valid Flasks: ", validFlasks)
    perTypeLosses = [[ftype, sum([item[1] for item in waste if item[0] == ftype])] for ftype in validFlasks]
    print("Per Type Losses: ", perTypeLosses)
    idx = [loss for fnum, loss in perTypeLosses].index(min([loss for fnum, loss in perTypeLosses]))
    return perTypeLosses[idx][0]

#requirements = [4,6,6,7]
#flaskTypes = 3
#markings = [[0, 3], [0, 5], [0, 7], [1, 6], [1, 8], [1, 9], [2, 3], [2, 5], [2, 6]]

#requirements = [96, 86, 105, 110]
#flaskTypes = 5
#markings = [[0,55],[1,1],[1,3],[1,4],[1,46],[2,1],[2,1],[2,42],[2,42],[2,81],[3,13],[3,15],[3,36],[4,1],[4,1],[4,9],[4,11],[4,185]]

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

print(chooseFlask(requirements, flaskTypes, markings)