import string

#Opens the log file
MyFile = open("../Logs/playerMovement.log")
lineCounter = 0

#Reads in every line of the file
for line in MyFile:
    for word in line.split():
            #Checks if the integer is within the bouds
            #If not, it throws a check of 0
            #If all good it throws a check of 1
            lineCounter = lineCounter + 1
            if int(word) > 5 or int(word) < 0:
                check = 0
                break
            else:
                check = 1
                break

if check == 1:
    print "Player Stayed within bounds"
else:
    print "There was an error and the player left the bounds on move: ", lineCounter


MyFile.close()
