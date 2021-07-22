def countAnagramPhrases(words, phrases):
    # for each word in words
    # calculate the ascii value for the word and add it as a tuple to the words list
    words = [[word, sum([ord(c) for c in word])] for word in words]
    print(words)
    
    ret = []
    for phrase in phrases:
        psplit = phrase.split()
        psplit = [[word, sum([ord(c) for c in word])] for word in psplit]
        print("Phrase split: ",psplit)
        # find a word in the words list that has the same ascii score but is not the same word
        retval = 1
        for pword in psplit:
#             xx = [word for word in words if (word[1] == pword[1]) and (word[0] != pword[0])]
            xx = [word for word in words if (word[1] == pword[1]) and (word[0] != pword[0]) and (len(word[0]) == len(pword[0]) and sorted(word[0]) == sorted(pword[0]))]
            print("XX: ",xx)
#             yy = [w for w in xx]
            retval = retval * (len([word for word in words if (word[1] == pword[1]) and (word[0] != pword[0]) and (len(word[0]) == len(pword[0]) and sorted(word[0]) == sorted(pword[0]))]) + 1)
            print(retval)
        ret.append(retval)
    return ret

# reading the inputs to the function
words, phrases = [], []
with open("ii.txt",'r') as file:
    nWords = int(file.readline().strip())
    for _ in range(nWords):
        words.append(file.readline().strip())
    nPhrases = int(file.readline().strip())
    for _ in range(nPhrases):
        phrases.append(file.readline().strip())

print("Words: ", words,"\nPhrases: ", phrases)

print(countAnagramPhrases(words, phrases))
