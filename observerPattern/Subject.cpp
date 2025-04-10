#include"Subject.hpp"
#include"observer.hpp"
#include <iostream>



         ISubject::~ISubject(){}
         ISubject::ISubject(){}
         
        
     void ISubject::AddWatcher(int message, IObserver *Observer) {
         
         auto it = mobservers.find(message);
         if(it == mobservers.end()) {
             mobservers[message] = ObserversList();
         }
        
         mobservers[message].push_front(Observer);

    }
    
         void ISubject::Remove_Watcher(int message, IObserver* Observer) {
            auto it = mobservers.find(message);
            if(it!= mobservers.end()) {
                ObserversList& list = mobservers[message];
                     list.remove(Observer);
            }
            
    }
        void ISubject::Notifyall() {
            
            for(ObserversMap::iterator it =mobservers.begin(); 
                        it!=mobservers.end(); 
                        it++)
                        { 
                            for( auto &o :mobservers[it->first]) {
                            o->OnNotify();
                        } 
                
            }
          
        }
        
        void ISubject::Notify(int message) {
            for (auto &o:mobservers[message]) {
                o->OnNotify();
            }
        }