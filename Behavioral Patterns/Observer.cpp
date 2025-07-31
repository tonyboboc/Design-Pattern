#include <list>
#include <string>
#include <iostream>
class BaseObserver{
    public:
virtual  ~BaseObserver()=default;
virtual void Update(const std::string & msg)=0;
};
class BaseSubject{
public:
    virtual ~BaseSubject()=default;
    virtual void attach(BaseObserver* obs)=0;
    virtual void remove(BaseObserver* obs)=0;
    virtual void Notify()=0;
};
class Subject:public BaseSubject{
    private:
    std::list<BaseObserver*> observers;
    std::string message;
    public:
    ~Subject(){
        std::cout<<"Deletion of subject\n";
    }
    void attach(BaseObserver* obs)override{
        observers.push_back(obs);
    }
    void remove(BaseObserver* obs)override{
        observers.remove(obs);
    }
    void Notify()override{
        std::list<BaseObserver*>::iterator it=observers.begin();
        while(it!=observers.end()){
            (*it)->Update(message);
            ++it;
        }

    }
    void CreateMessage(const std::string &msg){
        message=msg;
        Notify();
    }
};
class Observer:public BaseObserver{
    private:
    std::string message;
    int number;
    static int snumber;
    Subject * subject;
    public:
    Observer(Subject & sub):subject(&sub){
        sub.attach(this);
        std::cout<<"I am Observer : "<<++snumber<<std::endl;
        number=snumber;
    }
    ~Observer(){
        std::cout<<"Goodbye , "<<number<<std::endl;
    }
    void Update(const std::string & msg)override{
        message=msg;
        std::cout<<"Observer "<<number<<" this message is avalible "<<message<<std::endl;
    }
    void changesubject(Subject &sub){
        if(subject){
            subject->remove(this);
        }
        subject=&sub;
        sub.attach(this);
    
    }
    void RemoveFromList(){
        if(subject){
        subject->remove(this);
        subject=nullptr;
        }
    }
};
void ClientCode(){
    Subject s1,s2;
    Observer* o1=new Observer(s1);
    Observer* o2=new Observer(s1);
    s1.CreateMessage("A new product is available at store s1");
    o2->changesubject(s2);
    s2.CreateMessage("o2 moved 2 store s2");
    delete o1;
    delete o2;

}
int Observer::snumber = 0;
int main(){
    ClientCode();
    return 0;
}
