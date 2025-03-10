/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<string>
#include <memory>


class IGameObject {
    public:
        virtual ~IGameObject() {}
        virtual void update() = 0;
        virtual void render() = 0;
    
    
}; 

class Plane : public IGameObject {
    
    public:
        Plane() {};
        void update() {}
        void render() {}
};

class Boat : public IGameObject {
    
    public:
        Boat() {};
        void update() {}
        void render() {}
};

enum class objtype {PLANE, BOAT};

class factorygameobj {
    private:
         factorygameobj() {}
         ~factorygameobj() {}
         
      
         
    public:
    
    static int s_plane;
    static int s_boat;
    static std::shared_ptr<IGameObject> createobj(objtype type) {
    
    if(objtype::PLANE ==type ){
        s_plane++;
        return std::make_shared<Plane>();
        
    }
    else if(objtype::BOAT== type) {
        s_boat++;
        return std::make_shared<Boat>();
        
        
    }
    return nullptr;
    }
    
    static void printobj() {
        
        std::cout<<"splane"<<s_plane<<std::endl;
        std::cout<<"sboat"<<s_boat<<std::endl;
    }
    
  
    
};

int factorygameobj::s_plane =0;
int factorygameobj::s_boat= 0;


int main()
{
    // std::shared_ptr<IGameObject> myobj = MakeObj(objtype::PLANE);
    // std::shared_ptr<IGameObject> myobj2 = MakeObj(objtype::BOAT);


   std::shared_ptr<IGameObject> myobj = factorygameobj::createobj(objtype::BOAT);
   std::shared_ptr<IGameObject> myobj2 = factorygameobj::createobj(objtype::BOAT);
   std::shared_ptr<IGameObject> myobj3 = factorygameobj::createobj(objtype::PLANE);
   
   factorygameobj::printobj();
    return 0;
}