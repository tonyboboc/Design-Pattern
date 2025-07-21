#include <iostream>
#include <string>
class roomclean{
    public:
    ~roomclean()=default;
    std::string operation(){
        return "cleaning room";
    }
};
class give{
    public:
    ~give()=default;
    std::string operation(){
        return "give keys to client";
    }
};
class Facade{
    private:
    give* receptionist;
    roomclean* roomattendant;
    public:
    Facade(){
        receptionist=new give();
        roomattendant=new roomclean();
    }
    ~Facade(){
        delete receptionist;
        delete roomattendant;
    }
    void givekeys()const {
        std::cout<<roomattendant->operation()<<std::endl;
        std::cout<<receptionist->operation()<<std::endl;
    }
};
void clientcode(const Facade & f){
    f.givekeys();
}
int main(){
    Facade* f;
    clientcode(*f);
}