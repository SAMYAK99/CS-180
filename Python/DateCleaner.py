import pyperclip
import re

dateRegex = re.compile(r'''(
    (\d{1,4})     #for day / year
    (\s|\.|\||-|\\|/) #for seprator   
    (\d{1,2})       #for months
    (\s|\.|\||-|\\|/) #for seprator 
    (\d{1,4})         #for Date /year
)''',re.VERBOSE)

text = str(pyperclip.paste())

matched = []
for groups in dateRegex.findall(text):
    if len(groups[1]) > 2:
        Date = '-'.join([groups[5],groups[3],groups[1]])
    else:
        Date = '-'.join([groups[1],groups[3],groups[5]])
    matched.append(Date)

if len(matched) > 0:
    print('\n'.join(matched))
else:
    print('No match found')
