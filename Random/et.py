x = int(raw_input("Please enter an integer:"))
root = 0
pwr = 0
while (pwr < 6):
    pwr += 1
    print 'hey'
    while (root ** pwr < abs(x)):
     root+=1
     if(root ** pwr == abs(x)):
      print (root,pwr)

raw_input("Press any key to continue")
