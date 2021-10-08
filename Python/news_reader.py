import requests
import json
from time import sleep


def speak(str):
    from win32com.client import Dispatch

    speak = Dispatch("SAPI.SpVoice")
    speak.Speak(str)


print("\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~")
print("\t\t\t\t\t\t ||  NEWS READER  ||")
print("\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~")
print("\tHello! Welcome to the news reader app.\n")

req = requests.get(
    "https://newsapi.org/v2/top-headlines?country=in&apiKey=<your_api_key>"
)
dict = json.loads(req.text)

speak("Hello! Welcome to the news reader app")
speak("Here are the news for today.")
print("News for today are : ")

arts = dict["articles"]
for i in arts:
    print("The Headline is - " + str(i["title"]))
    speak("The Headline is - " + str(i["title"]))

    print("Story - " + str(i["description"]))
    speak(i["description"])

    print("Checkout the link for detail : " + str(i["url"]))
    sleep(7)
    speak("Moving to the next news...")
    print("\n\nMoving to the next news...\n")

speak("\n\nThanks for listening the new, have a nice day.")
