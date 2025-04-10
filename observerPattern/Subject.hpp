#pragma once
#include<forward_list>
#include<map>
// #include"observer.hpp"
class IObserver;

class ISubject {
    public:
        ISubject();
        virtual ~ISubject();
        
        virtual void AddWatcher(int message, IObserver *Watcher) ;
        virtual void Remove_Watcher(int message, IObserver* Watcher);
        void Notifyall();
        void Notify(int message);
    private:
    typedef std::forward_list<IObserver*> ObserversList;
    typedef std::map<int, ObserversList> ObserversMap;
    
    ObserversMap mobservers;
        
};


class SomeSubject : public ISubject {
    public:
    
    enum messagetype{PLAYSOUND, HANDLEPHYSICS, LOG};
    
};