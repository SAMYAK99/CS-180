#This program converts roman numerals to decimal integers
# using python dictonaries  


x ={"I":1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000}
value = input("Enter a roman numberal: ")
value = value.upper()
total= int
total=0
try:
    for i in range(len(value)):
        if i+1<len(value):
            if( x[value[i]]>=x[value[i+1]]):    #if second value is greater then we add
                total+=x[value[i]]
        elif i+1==len(value):
            total+=x[value[i]]
        else:
            total-=x[value[i]]      #if second value is small we substract

except:
    print("Your input was wrong")

print(total)   