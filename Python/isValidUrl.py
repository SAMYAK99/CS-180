import pyperclip
import re


urlRegex = re.compile('''(
    http(s)?://[a-zA-Z0-9._-]+(\.[a-zA-Z0-9]+)
)''', re.VERBOSE)

text = str(pyperclip.paste())

matches = []
for groups in urlRegex.findall(text):
    matches.append(groups[0])

if len(matches) > 0:
    pyperclip.copy('\n'.join(matches))
    print('Matches copied to clipboard')
    print('\n'.join(matches))
else:
    print('No matches found!')
