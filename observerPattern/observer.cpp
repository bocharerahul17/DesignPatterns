#include"observer.hpp"
#include<iostream>


        Watcher::Watcher(ISubject &msubject, std::string m_name):subject{msubject}, name{m_name} {
            subject.AddWatcher(this);
        
        }
        Watcher::~Watcher() {
            subject.Remove_Watcher(this);
        }
        
        void Watcher::OnNotify() {
            std::cout <<name<<"-Watcher "<< std::endl;
        }
        