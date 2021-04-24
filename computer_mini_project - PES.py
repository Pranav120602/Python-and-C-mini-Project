#MYMAP FUNCTION
from tkinter import *
import os

def mymap(myfunction, mylist):
    output = []
    for element in mylist:
        output.append(myfunction(element))
    return output


def menudriven():
    print("WELCOME TO PROJECT ")
    print("We have 3 sub questions, click on any of the options below :) ")
    print("Click 1 for Question a ")
    print("Click 2 for Question b ")
    print("Click 3 for Question c ")
    print("click 4 for all o/p to appear")
    print("Click 0 to exit the program ")
menudriven()
op = int(input("Enter a option :"))
while op !=0:
    if op ==1:
        print("QUESTION a :")
        n =int(input("How many strings you want to enter :"))
        l=[]
        for i in range(n):
            input1 = input("Enter string: ")
            l.append(input1)
        print("Your list is :",l)

        def func1(l):
            return(l,len(l))
        list1 = mymap(func1,l)
        root = Tk()
        myFrame = Frame(root).place(x=50, y=100)
        for i in list1:
            Label(myFrame, text =i).pack() 
        root.mainloop()


    elif op==2:
        print("QUESTION b :")
        
        l = ['phy unit 2.pdf','file1.txt','file2.txt']
        list2 = mymap(lambda x: (x,os.path.getsize(x)),l)
        
        print("Your list is: ",l)
        root = Tk()
        myFrame = Frame(root).place(x=50, y=100)
        for i in list2:
            Label(myFrame, text =i).pack()
        root.mainloop()


        
    elif op == 3:
        print("QUESTION c :")

        a =int(input("How many strings you want to enter :"))
        n3=[]
        for i in range(a):
            input1 = input("Enter string: ")
            n3.append(input1)
        print("Your list is :",n3)

        def func3(n3):
            return(n3[::-1])
        

        list3 = list(mymap(func3,n3))
        root = Tk()
        myFrame = Frame(root).place(x=50, y=100)
        for i in list3:
            Label(myFrame, text =i).pack() 
        root.mainloop()

    elif op ==4:
        print("QUESTION a :")
        n =int(input("How many strings you want to enter :"))
        l=[]
        for i in range(n):
            input1 = input("Enter string: ")
            l.append(input1)
        print("Your list is :",l)

        def func1(l):
            return(l,len(l))
        list1 = mymap(func1,l)
       
        print("QUESTION b :")
        
        l = ['phy unit 2.pdf','file1.txt','file2.txt']
        list2 = mymap(lambda x: (x,os.path.getsize(x)),l)
        
        print("Your list is: ",l)
        
        print("QUESTION c :")

        a =int(input("How many strings you want to enter :"))
        n3=[]
        for i in range(a):
            input1 = input("Enter string: ")
            n3.append(input1)
        print("Your list is :",n3)

        def func3(n3):
            return(n3[::-1])
        

        list3 = list(mymap(func3,n3))
        

        
        win = Tk()
        myFrame = Frame(win).place(x=500, y=100)
        for i in list1:
            Label(myFrame, text = i,).pack()
       
        
        
    
        for j in list2:
            Label(myFrame, text = j).pack()
        for k in list3:
            Label(myFrame, text = k).pack()
        
        win.mainloop()
            
            
            
        
        
        



        
    else:
        print("Sorry, invalid option")
    print()
    menudriven()
    op = int(input("Enter a option :"))

print()
print("THANK YOU !!")



