#include <string>
#include <iostream>
#include <vector>
class Electronicdevice{
    std::string name;
    public:
    Electronicdevice(std::string s): name(s){}
    void turnoff(){
        std::cout<<"turning off : "<<name<<std::endl;
    }
    void turnon(){
        std::cout<<"turning on : "<<name<<std::endl;
    }
};
class Command{
    public:
    virtual void execute()=0;
};
class TurnOnCommand:public Command{
    private:
    Electronicdevice* e;
    public:
    TurnOnCommand(Electronicdevice* e){
        this->e=e;
    }
    void execute()override{
        e->turnon();
    }
};
class TurnOffCommand:public Command{
    private:
    Electronicdevice*e;
    public:
    TurnOffCommand(Electronicdevice* e){
        this->e=e;
    }
    void execute ()override{
        e->turnoff();
    }
};
class Remote{
    private:
    std::vector<Command*> commands;
    public:
    void addCommand(Command * c){
        commands.push_back(c);
    }
    void dostuff(int i){
        if(i>=0&&i<commands.size()){
            commands[i]->execute();
        }
    }
};
int main(){
    Electronicdevice tv("tv");
    Electronicdevice radio("radio");
    TurnOnCommand turnOnTV(&tv);
    TurnOffCommand turnOffTV(&tv);
    TurnOnCommand turnOnRadio(&radio);
    TurnOffCommand turnOffRadio(&radio);
    Remote remote;
     remote.addCommand(&turnOnTV); 
    remote.addCommand(&turnOffTV);
    remote.addCommand(&turnOnRadio);
    remote.addCommand(&turnOffRadio);
    remote.dostuff(0); 
    remote.dostuff(1);
    remote.dostuff(2);
    remote.dostuff(3);
    
    return 0;
}