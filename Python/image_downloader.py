import requests
from bs4 import BeautifulSoup
from random import seed
from random import randint
import pandas as pd
excel_file = 'Products2.xlsx'
movies = pd.read_excel(excel_file)
df = pd.DataFrame(movies)
for i in df.index:
    query = df['Product'][i]
    URL = "https://www.google.co.in/search?q=%s&source=lnms&tbm=isch" % query
    page = requests.get(URL)

    soup = BeautifulSoup(page.content, 'html.parser')
    imgclass = soup.find_all("img", {"class": "t0fcAb"})
    for a in imgclass:
        response = requests.get(a['src'])
        file = open(query+".png", "wb")
        file.write(response.content)
        file.close()
        break 
    break

