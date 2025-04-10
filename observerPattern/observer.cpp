#include"observer.hpp"
#include<iostream>


        Watcher::Watcher(ISubject &msubject, int message, std::string m_name):
            subject{msubject},mMessage{message}, name{m_name} {
            subject.AddWatcher(mMessage, this);
        
        }
        Watcher::~Watcher() {
            subject.Remove_Watcher(mMessage ,this);
        }
        
        void Watcher::OnNotify() {
            std::cout <<name<<"-Watcher "<< std::endl;
        }
        