#include"Subject.hpp"
#include"observer.hpp"


         ISubject::~ISubject(){}
         ISubject::ISubject(){}
         
        
     void ISubject::AddWatcher(IObserver *Watcher) {
            mobervers.push_front(Watcher);
        
    }
    
         void ISubject::Remove_Watcher(IObserver* Watcher) {
            mobervers.remove(Watcher);
        
    }
        void ISubject::Notifyall() {
            for(auto &o: mobervers) {
                o->OnNotify();
            }
        }