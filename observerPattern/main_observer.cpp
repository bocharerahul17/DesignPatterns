/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<iostream>
#include"Subject.hpp"
#include"observer.hpp"

int main()
{
    SomeSubject subject;
    Watcher Watcher1(subject, "Watcher1");
    Watcher Watcher2(subject, "Watcher2");
    {
    Watcher Watcher3(subject, "Watcher3");
    }
    
    subject.Notifyall();

    return 0;
}