import pyttsx3
import webbrowser
import smtplib
import random
import speech_recognition as sr
import wikipedia
import datetime
import os
import sys



engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices') 
engine.setProperty('voices',voices[0].id)

def speak(audio):
    engine.say(audio)
    engine.runAndWait()


def wishme():
    time=int(datetime.datetime.now().hour)
    if time>=0 and time<12:
        speak("good morning sir")
    elif time>=12 and time<18:
        speak("good afternoon sir")
    else: 
        speak("good evening sir")    
    speak( "I am your virtual assistant jarvis . please tell me how may i help you")
  

def takeCommand():
    r=sr.Recognizer()
    with sr.Microphone() as source:
        print("listening.....")
        r.pause_threshold=1
        r.adjust_for_ambient_noise(source, duration=5)
        audio=r.listen(source)

    try:
        print("Recognizing.....")
        stat=r.recognize_google(audio, language="en-in")
        print(f"User said:> {stat}\n")

    except Exception as e:
        #print(e)

        print("Say that again please!!")
        return "None"
    return stat
def sendemail(to,content):
    e_mail=lib.smtplib.SMTP('smtp.gmail.com',587)
    e_mail.ehlo()
    e_mail.starttls()
    e_mail.login('tggv9986@gmail.com', 'mypass')
    e_mail.sendemail('tggv9986@gmail.com',to,content)
    e_mail.close()
if __name__ == "__main__":
    wishme()
    while True:
        stat=takeCommand().lower()

        if 'wikipedia' in stat:
            speak('searching wikipedia')
            stat=stat.replace('wikipedia' , "")
            results=wikipedia.summary(stat, sentences=3)
            speak('According to  wikipedia')
            print(results)
            speak(results)

        elif 'open youtube' in stat:
            speak('okay')
            webbrowser.open('youtube.com')

        elif 'my youtube channel' in stat:
            speak("okay")
            webbrowser.open('youtube.com/c/thegreatgrandvideos')
        
        elif 'google classroom' in stat:
            speak("okay")
            webbrowser.open('https://classroom.google.com/c/NjQzNTUyODU0MTFa')

        elif 'google' in stat:
            speak("okay")
            webbrowser.open('www.google.co.in')

        elif 'play music' in stat:
            musicfile='"E:\\YouTube\\NCS Music & Sound Effect'
            songs=os.listdir(musicfile)
            print(songs)
            os.startfile(os.path.join(musicfile ,songs[0]))

        elif'time' in stat:
            ntime=datetime.datetime().strftime('%H:%M:%S')

        elif"open vs code" in stat:
            vscode='C:\\Users\\ABHISHEK RANJAN\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Visual Studio Code\\Visual Studio Code.lnk'   
            os.startfile(vscode)

        elif'open filmora' in stat:
            filmora="C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\Wondershare\\Filmora9\\Wondershare Filmora9.lnk"
            os.startfile(filmora)

        elif'open zoom' in stat:
            zoomm="C:\\Users\\ABHISHEK RANJAN\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Zoom\\Start Zoom.lnk"
            os.startfile(zoomm) 

        elif 'open droidcam' in stat:
            d_cam="C:\\Users\\ABHISHEK RANJAN\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\DroidCam\\DroidCam Client.lnk"
            os.startfile(d_cam) 

        elif "what's up" in stat or 'how are you' in stat:
            stMsgs = ['Just doing my thing!', 'I am fine!', 'I am nice and full of energy']
            speak(random.choice(stMsgs))  

        elif 'nothing' in stat or 'abort' in stat or 'stop' in stat:
            speak('okay')
            speak('Bye Sir, have a good day.')
            sys.exit()

        elif 'hello' in stat:
            speak('Hello Sir')                       


        elif'email to ashutosh' in stat:
            try:
                speak("what should i mail")
                mes=takeCommand()
                to='ashuranjan567@gmail.com'
                sendemail(to, mes)
            except Exception as e:
                #print(e)
                speak("sorry sir email has not been send i committed a mistake")

          

    
    
    



          





    