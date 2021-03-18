import time
from time import sleep
#Nea Programming Project
#function - word+root
def obtvalue(filename):
    tdD = []
    odD = []
    f = open(filename, 'r')
    for line in f:
        line = line.replace("\r","").replace("\n","") # this feature will print out the cvs files content.
        
        if len(line) < 1:
            continue
        odD = line.split(",")
        print(odD)
        tdD.append(odD)
    f.close()
    print()
    print()
    print()
    print(tdD)
    print()
    print()
    return tdD
 
    LPL = 1
    BOH = 2
    
def airportde():
     
    UKA = input("Please enter your 3 digit code for the UK airport ")
    if UKA == "LPL" or UKA == "BOH":
        print("Correct")
    else:
        print("Incorrect")

    r1 = []

    filename = "Airports.txt"
    r1 = obtvalue(filename)

    print("Destination!!!")
    ITA = input("Please enter your 3 digit code for the International airport ")
    for x in range(5):
        if r1[x][0] == ITA:
            print(r1[x][1])


def menu(): #fuction to be recalled.
    print("Enter airport details - A")
    sleep(0.5)
    print("Enter flight details - B")
    sleep(0.5)
    print("enter price plan and calculate profit - C")
    sleep(0.5)
    print("clear data - D")
    sleep(0.5)
    print("quit - E")
    menc = input("pick: ") #user input to pick from the main menu
    if menc == "A":
        print("You have chosen to Enter Airport Details")
        airportde()
    elif menc == "B":
        print("You have chosen Enter flight details")
        flightde()
    elif menc== "C":
        print("you have chosen Enter price plan and calculate profit")
        pricepln()
    elif menc == "D":
        print("you have chosen clear data")
    elif menc == "E":
        print("you have chosen to quit")
        exit()
    else:
        menu()


menu()

    
