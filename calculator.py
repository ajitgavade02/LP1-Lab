#import tkinter
from tkinter import *


root=Tk()

root.title('Grade Calculator')
root.geometry('500x400')
root.configure(bg="white")
# root.resizable(False,False)

def Calculation():
    english=int(englishentry.get())
    skills=int(analytical_skillentry.get())
    general=int(generalentry.get())
    total=(english+skills+general)
    # percentage=int(total/3)
    Label(text=f"{total}",font="arial 15 bold").place(x=250,y=170)
    average = int(total/3)
   
    Label(text=f"{average}",font="arial 15 bold").place(x=250,y=210)

    if(average>40):
        grade="PASS"
    else:
        grade="FAIL"
    
    Label(text=f"{grade}",font="arial 15 bold").place(x=250,y=250)

sub1=Label(root,text="English:",font="arial 10")
sub2=Label(root,text="Analytical Skill:",font="arial 10")
sub3=Label(root,text="General Knowledge:",font="arial 10")
# sub4=Label(root,text="Marathi:",font="arial 10")
# sub5=Label(root,text="Science:",font="arial 10")
total=Label(root,text="Total:",font="arial 10")
avg=Label(root,text="Average:",font="arial 10")
grade=Label(root,text="Grade:",font="arial 10")

sub1.place(x=50,y=20)
sub2.place(x=50,y=70)
sub3.place(x=50,y=120)
total.place(x=50,y=170)
avg.place(x=50,y=210)
grade.place(x=50,y=250)

englishvalue=StringVar()
analytical_skillvalue=StringVar()
generalvalue=StringVar()

englishentry=Entry(root,textvariable=englishvalue,font="arial 15",width=15)

analytical_skillentry=Entry(root,textvariable=analytical_skillvalue,font="arial 15",width=15)

generalentry=Entry(root,textvariable=generalvalue,font="arial 15",width=15)

englishentry.place(x=250,y=20)
analytical_skillentry.place(x=250,y=70)
generalentry.place(x=250,y=120)

Button(text="Calculate",font="arial 15",bg="white",bd=10,command=Calculation).place(x=50,y=300)

Button(text="Exit",font="arial 15",bg="white",bd=10,width=8,command=lambda:exit()).place(x=200,y=300)

root.mainloop()
