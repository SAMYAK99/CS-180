#nature.txt exists in the same directory/folder where this program is placed
file=open("nature.txt","r")
str=""
str1=""
lines=file.readlines()
for line in lines:
if "a" in line:
str+=line
else:
str1+=line
file.close()
newfile=open("new nature.txt","w")
newfile.write(str)
newfile.close()
file=open("nature.txt","w")
file.write(str1)
file.close()