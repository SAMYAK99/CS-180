list=[87,24,90,66,480,340,13,99,44,96]
print("List has the items: ",list)
searchitem=int(input("Enter a number to search for: "))
found=False
for i in range(len(list)):
    if list[i]==searchitem:
        found=True
        print(searchitem,'is present in the list at index',i)
        break
if found==False:
    print(searchitem,'is not present in the list!')
