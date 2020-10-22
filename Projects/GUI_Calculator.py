from tkinter import *
root = Tk()


def handleClick(btnVal):
    exp = strVar.get()
    if btnVal == '=':
        exp = str(eval(exp))
    elif btnVal == 'C':
        exp = ''
    else:
        exp += str(btnVal)
    strVar.set(exp)


strVar = StringVar()
strVar.set('')

Label(root, textvariable=strVar).grid(row=0, column=0, columnspan=3)

Button(root, text='C', command=lambda : handleClick('C'), width=5,
       height=2).grid(row=0, column=3)

Button(root, text='7', command=lambda : handleClick('7'), width=5,
       height=2).grid(row=1, column=0)

Button(root, text='8', command=lambda : handleClick('8'), width=5,
       height=2).grid(row=1, column=1)

Button(root, text='9', command=lambda : handleClick('9'), width=5,
       height=2).grid(row=1, column=2)

Button(root, text='/', command=lambda : handleClick('/'), width=5,
       height=2).grid(row=1, column=3)

Button(root, text='4', command=lambda : handleClick('4'), width=5,
       height=2).grid(row=2, column=0)

Button(root, text='5', command=lambda : handleClick('5'), width=5,
       height=2).grid(row=2, column=1)

Button(root, text='6', command=lambda : handleClick('6'), width=5,
       height=2).grid(row=2, column=2)

Button(root, text='*', command=lambda : handleClick('*'), width=5,
       height=2).grid(row=2, column=3)

Button(root, text='1', command=lambda : handleClick('1'), width=5,
       height=2).grid(row=3, column=0)

Button(root, text='2', command=lambda : handleClick('2'), width=5,
       height=2).grid(row=3, column=1)

Button(root, text='3', command=lambda : handleClick('3'), width=5,
       height=2).grid(row=3, column=2)

Button(root, text='-', command=lambda : handleClick('-'), width=5,
       height=2).grid(row=3, column=3)

Button(root, text='.', command=lambda : handleClick('.'), width=5,
       height=2).grid(row=4, column=0)

Button(root, text='0', command=lambda : handleClick('0'), width=5,
       height=2).grid(row=4, column=1)

Button(root, text='=', command=lambda : handleClick('='), width=5,
       height=2).grid(row=4, column=2)

Button(root, text='+', command=lambda : handleClick('+'), width=5,
       height=2).grid(row=4, column=3)

root.mainloop()
