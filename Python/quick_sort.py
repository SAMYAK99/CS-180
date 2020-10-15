#python code illustrating quick sort
def qsort(list1,low,high):
    if(low<high):
        p=partition(list1,low,high)

        qsort(list1,low,p-1)
        qsort(list1,p+1,high)

#This function is for partition
def partition(list1,low,high):
    i=low-1
    pivot=list1[high]

    for j in range(low,high):
        if(list1[j]<pivot):
            i+=1
            list1[i],list1[j]=list1[j],list1[i]

    list1[high],list1[i+1]=list1[i+1],list1[high]
    return i+1   
     
if __name__ == "__main__":
    list1=[int(x) for x in input().split()]
    qsort(list1,0,len(list1)-1)
    print(list1)