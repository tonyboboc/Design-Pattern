#include <iostream>
#include <string>
class Phone;
class State{
    protected:
    Phone* context;
    public:
    virtual ~State()=default;
    void setcontext(Phone* con){
        context=con;
    }
    virtual void powerb()=0;
    virtual void homeb()=0;

};
class Phone{
private:
State* state;
public:
Phone (State * st): state(nullptr){
    Transition_to(st);
}
void Transition_to(State* st){
    if (state){
        delete state;
    }
    state=st;
    st->setcontext(this);
}
~Phone(){
    delete state;
}
void Request1(){
    state->powerb();
}
void Request2(){
    state->homeb();
}
};
class Off;
class On:public State{
public:
void powerb()override;
void homeb()override{
    std::cout<<"Showing apps\n";
}
};
class Off:public State{
public:
void powerb()override{
    //this is power button
    std::cout<<"Turning Phone on\n";
    context->Transition_to(new On);
}
void homeb()override{
    std::cout<<"Show lockscreen\n";
}
};
void On::powerb(){
    //this is power button
    std::cout<<"Turning Phone off\n";
    context->Transition_to(new Off);
}
void ClientCode(){
    Phone* p=new Phone(new On());
    p->Request2();
    p->Request1();
    p->Request2();
    delete p;
}
int main(){
    ClientCode();
    return 0;
}

