myList=['alfia','anjaleena','abhinav','abhijith','adithya']

print(myList)
print(myList[0])

#length of the list
length=len(myList)

if(length>0):
    print("List is not empty")
else:
    print("List is empty")
    
    
# Accessing elements in a list using a for loop
for i in myList:
    if(i=='alfia'):
        print("Found")

# sorting the list
myList.sort()

print(myList)

#while loop implementation
i=length-1
while(i>=0):
    print(myList[i])
    i=i-1