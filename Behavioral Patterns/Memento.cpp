#include <iostream>
#include <string>
#include <vector>
class Memento{
    public:
    virtual std::string getstate()=0;
};
class ConcreteMemento:public Memento{
    private:
    std::string state;
    public:
    ConcreteMemento(const std::string & state){
        this->state=state;
    }
    std::string getstate()override{
        return state;
    }
};
class Originator{
    std::string state;
    public:
    Originator(const std::string & state){
        this->state=state;
    }
    Memento* Save(){
        return new ConcreteMemento(this->state);
    }
    void  Restore(Memento* save){
        this->state=save->getstate();
        delete save;
    }
    void Change(const std::string s){
        this->state=s;
    }
};
class Caretaker{
    std::vector<Memento*> memento;
    Originator* originator;
    public:
    Caretaker(Originator* o):originator(o){}
    ~Caretaker(){

    }
};