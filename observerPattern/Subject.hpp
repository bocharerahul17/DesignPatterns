#pragma once
#include<forward_list>
// #include"observer.hpp"
class IObserver;

class ISubject {
    public:
        ISubject();
        virtual ~ISubject();
        
        virtual void AddWatcher(IObserver *Watcher) ;
        virtual void Remove_Watcher(IObserver* Watcher);
        void Notifyall();
    private:
    std::forward_list<IObserver*> mobervers;
        
};


class SomeSubject : public ISubject {
    public:
    
};