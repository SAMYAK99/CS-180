list1=[]
def push(list1,num):
    list1.append(num)
    return list1
def pop(list1):
    list1.pop()
    return list1
def top(list1):
    return list1[len(list1)-1]
def displayList(list1):
    for i in range(len(list1)):
        print(list1[i],end=' ')
    print()
def options(n):
    if(n==1):
        num=int(input("Enter the number you want to insert:\n"))
        push(list1,num)
        main()
    elif(n==2):
        pop(list1)
        main()
    elif(n==3):
        print(top(list1))
        main()
    elif(n==4):
        displayList(list1)
        main()
    else:
        exit()
def main():
    print("*******MENU*******")
    print("1.Push")
    print("2.Pop")
    print("3.Top")
    print("4.DisplayList")
    print('5.Exit')
    n=int(input("Enter the option:\n"))
    options(n)
main()