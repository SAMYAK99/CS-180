from datetime import date
today = date.today()

bYear= input("enter year of birth")
bMonth=input("enter month of birth")
bDate=input("enter date of birth")
name=input("enter name of the birthday legend")
age = today.year - int(bYear)
if (today.month == int(bMonth) and today.day == int(bDate)):
        print(f"Happy Birthday {name}")
        print(f"its your {age} birthday")
else:
        print(f"the coming birthday will be your {age + 1} birthday")