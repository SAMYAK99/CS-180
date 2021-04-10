from tkinter import *
import pygame
import os
from time import strftime
window = Tk()
pygame.mixer.init()
n=0
def start_stop():
	global n
	n=n+1
	if n == 1:
		song_name=songs_listbox.get()
		pygame.mixer.music.load(song_name)
		pygame.mixer.music.play(0)
	elif (n%2)==0:
		pygame.mixer.music.pause()
	elif (n%2)!=0:
		pygame.mixer.music.unpause()
l1=Label(window,text="Prathima Music Player", font="times 18")
l1.grid(row=1, column=1)
b2=Button(window,text='o', command=start_stop)
b2.grid(row=4, column=1)
songs_list=os.listdir()
songs_listbox=StringVar(window)
songs_listbox.set("Select Songs")
menu=OptionMenu(window, songs_listbox, *songs_list)
menu.grid(row=4, column=4)
window.mainloop()