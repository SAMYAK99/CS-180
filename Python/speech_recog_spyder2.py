import pyttsx3
import speech_recognition as sr
import datetime
import wikipedia
import webbrowser
import os
import smtplib
from gtts import gTTS
import playsound

print('initialising the virtual ai')+
engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
engine.setProperty('voice' , voices[1].id)
def speak(text):
    tts = gTTS(text = text , lang = "en")
    filename = "voice3.mp3"
    tts.save(filename)
    playsound.(filename)
    os.remove(filename)


def speak(text):
    engine.say(text)
    engine.runAndWait()
    
    
# speak('hi bhubesh welcome hey you are looking beautiful!')
    

master = "bhubesh"

def wishme():
    hour = datetime.datetime.now().hour
    print(hour)
    
    if hour>=0 and hour <12:
        speak("Good Morning" + master)
    elif hour>=12 and hour <18:
        speak("Good Afternoon" + master)
        
    else:
        speak("Good evening" + master)
    
    
def takeCommand():
    r  = sr.Recognizer()
    with sr.Microphone() as source:
        print(" Listening.." )
        audio = r.listen(source)
        
    try:
        print("Recognizing...")
        query = r.recognize_google(audio , language = 'en-in')
        print(f"user said { query}\n")
    except  sr.UnknownValueError:
            print('sorry , i am uanble recognise the audio')
    except sr.RequestError:
            print('Sorry , My speech is Down')
            query = None
        
    return query
        
    speak(' I am pyrobo. How may I help you ')
    
speak("initializing python...")    
wishme()
query = takeCommand()


# logic for executing the tasks as per the query


if 'wikipedia ' in query.lower():
    speak('searching wikipedia...')
    query = query.replace('wikipedia' , '')
    results = wikipedia.summary(query, sentences = 2)
    speak(results)
    print(results)
    
elif 'open youtube' in query.lower():
    # webbrowser.open("youtube.com")
    url = "youtube.com"
    chrome_path = 'C:/Program Files (x86)/Google/Chrome/Application/chrome.exe %s'
    webbrowser.get(chrome_path).open(url)
    speak("openin youtube")
    print("opening youtube")
     
if "open google" in query.lower():
    url = "google.com"\
    chrome_path = 'C:/Program Files (x86)/Google/Chrome/Application/chrome.exe %s'
    webbrowser.get(chrome_path).open(url)
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
