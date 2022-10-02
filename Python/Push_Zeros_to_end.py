from sys import stdin 
def pushZerosAtEnd(arr, n) :
    nonZero = 0 
    for i in range(n):
        if arr[i] != 0 :
            temp = arr[i] 
            arr[i] = arr[nonZero] 
            arr[nonZero] = temp 
            nonZero += 1 

def takeInput() :
    n = int(input())
    if n == 0:
        return list(), 0 
    arr = list(map(int, input().rstrip().split())) 
    return arr, n
def printList(arr, n) :
    for i in range(n) : 
        print(arr[i], end = " ") 
    print()
    
t = int(input())
while t > 0 : 
    arr, n = takeInput() 
    pushZerosAtEnd(arr, n)
    printList(arr, n)
    
    t -= 1
