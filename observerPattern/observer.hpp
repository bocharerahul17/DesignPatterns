#pragma once
#include"Subject.hpp"
#include <string>

class IObserver {
    public:
    
    virtual ~IObserver() {}
    virtual void OnNotify() = 0;
   
};

class Watcher:public IObserver {
    public:
        explicit Watcher(ISubject &msubject, int message, std::string m_name);
        ~Watcher() ;
        void OnNotify();
		
    private:
        std::string name;
        int mMessage;
        ISubject &subject;
};