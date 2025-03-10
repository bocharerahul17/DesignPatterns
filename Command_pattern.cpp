/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

struct Character {
    int x;
    int y;
    std::string name;
    Character(std::string _name):name{_name} {}
    void move(int _x, int _y) {
        x= _x;
        y = _y;
    }
    
};

class Command {
    public:
     virtual ~Command() {}
     virtual void execute(Character& c)= 0;
     virtual void undo(Character& c) =0;
     
};

class Move : public Command {
    public:
     void execute(Character& c) {
     int random_x = rand()%4;
     int random_y = rand()%4;
     
     x= random_x;
     y = random_y;
     
     c.move(random_x, random_y);
         std::cout << "moved " <<c.name<<x<< ", "<<y<< std::endl;
     }
     void undo(Character& c) {
         c.move(-x, -y);
          std::cout << "undo " <<c.name<<-x<< ", "<<-y<< std::endl;
     }

    
    private:
     int x;
     int y;
     
};
 

int main()
{
    srand(time(NULL));
    Character mike("mike");
    std::vector<Command*> Command_queue;
    
    Move *m1 = new Move;
    Command_queue.push_back(m1);
    
    Move *m2 = new Move;
    Command_queue.push_back(m2);
    
    Move *m3 = new Move;
    Command_queue.push_back(m3);
    
    Move *m4 = new Move;
    Command_queue.push_back(m4);
    
    for(uint8_t i =0 ; i<Command_queue.size(); i++) {
        Command_queue[i]->execute(mike);
    }
    
    for(uint8_t i =Command_queue.size()-1 ; i>-1; i--) {
        Command_queue[i]->undo(mike);
    }
    
  
    return 0;
}