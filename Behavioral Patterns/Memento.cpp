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
    std::string print(){
        return state;
    }
};
class Caretaker{
    std::vector<Memento*> memento;
    Originator* originator;
    public:
    Caretaker(Originator* o):originator(o){}
    ~Caretaker(){
        for (Memento *m:memento ){
            delete m;
        }
    }
    void backup(){
        memento.push_back(originator->Save());
    }
    void undo(){
        if(memento.size()){
            Memento* m=memento.back();
            memento.pop_back();
            std::cout<<"we are gonna restore Originator to : "<<m->getstate()<<std::endl;
            originator->Restore(m);
        }
        else{std::cout<<"no saves exists\n";}
    }
    void print(){
        for (Memento *m:memento ){
           std::cout<<m->getstate()<<"\n";
        }
    }

};
void ClientCode(){
    Originator o("some value");
    Caretaker c(&o);
    c.backup();
    o.Change("other value");
    c.backup();
    o.Change("other other value");
    c.print();
    c.undo();
    std::cout<<o.print()<<"decode"<<std::endl;
    c.print();
}
int main(){
    ClientCode();
    return 0;
}