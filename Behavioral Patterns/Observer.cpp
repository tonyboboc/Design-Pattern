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
    Observer(Subject & sub)subject(sub){
        sub.attach(this);
        std::cout<<"I am Observer : "<<++snumber<<std::endl;
        number=snumber;
    }
    ~Observer(){
        Std::cout<<"Goodbye , "<<number<<std::endl;
    }
    void Update(const std::string & msg){
        message=msg;
        std::cout<<"Observer "<<number<<" this message is avalible "<<message<<std::endl;
    }
    void RemoveFromList(){
        
    }
};
