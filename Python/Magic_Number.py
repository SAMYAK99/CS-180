'''A magic number is that number whose repeated sum of its digits till we get a single digit is equal to 1.
Take a number as input (num).
Step 2: Calculate the sum of digits of the input number.
Repeat step 2 until we get a single digit.
If the resultant sum is equal to 1 then it is a Magic number else not.
Ex - 12345 - 
Sum = 1 + 2 + 3 + 4 + 5 = 15 = 1 + 5 = 6 (Not a magic Number)
Ex - 1234
Sum = 1 + 2 + 3 + 4 = 10 = 1 + 0 = 1 (Magic Number)'''

def check_magic(number):
    while len(str(number)) > 1:
        sum = 0
        for each in str(number):
            sum += int(each)
        number = sum
    
    if number == 1:
        return "Magic Number"
    return "Not a Magic Number"
    
print(check_magic(int(input("Enter a number:"))))
