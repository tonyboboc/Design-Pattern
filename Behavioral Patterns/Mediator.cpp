#include <iostream>
class BaseComponent;
class Mediator{
    public:
    virtual void notify(BaseComponent* sender, std::string event)=0;
};
class BaseComponent{
protected :
Mediator* mediator;
public:
BaseComponent (Mediator* medi=nullptr):mediator(medi){}
void setMediator(Mediator* medi){
    mediator=medi;
}
};
class PlayerA:public BaseComponent{
    public:
    void DoA(){
        std::cout<<"doing A\n";
        mediator->notify(this,"B");
    }
};
class PlayerB:public BaseComponent{
    public:
    void DoB(){
        std::cout<<"doing B\n";
        mediator->notify(this,"C");
    }
};
class PlayerC:public BaseComponent{
    public:
    void DoC(){
        std::cout<<"doing C\n";
        mediator->notify(this,"A");
    }
};
class Chat:public Mediator{
    private:
    PlayerA *p1;
    PlayerB *p2;
    PlayerC *p3;
    public:
    Chat(PlayerA* pa,PlayerB* pb,PlayerC* pc):p1(pa),p2(pb),p3(pc){
        p1->setMediator(this);
        p2->setMediator(this);
        p3->setMediator(this);
    }
    void notify(BaseComponent *sender, std::string event)  override {
        if(event=="B"){
            p2->DoB();
        }
        if(event=="C"){
            p3->DoC();
        }
        if(event=="A"){
        }
    }
};
void ClientCode(){
    PlayerA* a=new PlayerA();
    PlayerB* b=new PlayerB();
    PlayerC* c=new PlayerC();
    Chat* chat=new Chat(a,b,c);
    //Normal operation trigers Mediator
    a->DoA();
        std::cout<<std::endl;
    b->DoB();
        std::cout<<std::endl;
    c->DoC();
        std::cout<<std::endl;
    delete a;
    delete b;
    delete c;
    delete chat;
}
int main(){
    ClientCode();
    return 0;
}