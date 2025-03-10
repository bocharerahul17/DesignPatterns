Inheritance
Polymorphism
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include<memory>

using namespace std;


class Logger {
    
    public:
    static Logger& GetloggerMethod() {
        static Logger* s_logger = new Logger;
        // static std::unique_ptr<Logger> s_logger = std::make_unique<Logger>();
        return *s_logger;
    }
    
    void printlogger() {
        std::cout << "accessing the logger" << std::endl;
        for(auto &e:m_messages) {
            cout<<e<<endl;
        }
    }
    
    void addmessages(std::string s) {
        m_messages.push_back(s);
        
        
    }
    
    private:
    Logger() {
        cout<<"logger is created"<<endl;
        
        
    }
    
    ~Logger() {
        cout<<"Releasing the logger"<<endl;
        
    }
    
    std::vector<std::string> m_messages;
    
    
};


int main()
{
    Logger::GetloggerMethod().addmessages("Hello from 2");
    Logger::GetloggerMethod().addmessages("Hello from 2");
    Logger::GetloggerMethod().addmessages("Hello from 3");
    Logger::GetloggerMethod().printlogger();
    return 0;
}