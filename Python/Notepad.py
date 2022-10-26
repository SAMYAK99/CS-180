

from tkinter import WORD, BOTH, END, INSERT
from tkinter.filedialog import *
import tkinter as tk

#  Save the current file
def saveFile():
    new_file = asksaveasfile(mode = "w", filetype = [('text file', '.txt')])
    if new_file is None:
        return
    text = str(entry.get(1.0, END))
    new_file.write(text)
    new_file.close()

# open the existing file
def openFile():
    file = askopenfile(mode="r", filetype = [('text file', '*.txt')])
    if file is not None:
        content = file.read()
    entry.insert(INSERT, content)

# clear file
def clearFile():
    entry.delete(1.0, END)

canvas = tk.Tk()

canvas.geometry("400x600")  #set geometry
canvas.title("Notepad")     #set title 
canvas.config(bg = "white")     #set bg color
# canvas.iconbitmap('C:/Users/raman/OneDrive/Pictures/Bluetooth/rv.png')

top = tk.Frame(canvas)
top.pack(padx = 10, anchor = 'nw', pady = 5 )

b1 = tk.Button(canvas, text = "Open", bg = "white", command = openFile)
b1.pack(in_ = top, side = "left")

b2 = tk.Button(canvas, text = "Save", bg = "white", command = saveFile)
b2.pack(in_ = top, side = "left")

b3 = tk.Button(canvas, text = "Clear", bg = "white", command = clearFile)
b3.pack(in_ = top, side = "left")

b4 = tk.Button(canvas, text = "Exit", bg = "white", command = exit)
b4.pack(in_ = top, side = "left")

entry = tk.Text(canvas, wrap = WORD, bg = "#F9DDA4", font =("poppins", 15))
entry.pack(padx = 15, pady = 5, expand = True, fill = BOTH)

canvas.mainloop()
