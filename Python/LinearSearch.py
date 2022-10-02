def linearSearch(arr,n,x):
    for i in range(0,n):
        if (arr[i]==x):
            return i
    return -1        

if __name__ == "__main__":
    arr=[]
    n=int(input("Enter number of elements in list: "))
    print("Enter",str(n),"elements in the list: ")
    for i in range(n):
        y=input()
        arr.append(y)
    x=input("Enter the Element to search: ")
    res = linearSearch(arr, n, x)  
    if(res == -1):  
        print("*****  Element not found!  *****")  
    else:  
        print("***** Element found at index: ", res, " *****") 
