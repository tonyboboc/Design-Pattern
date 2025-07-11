#include <iostream>
#include <string>
class Transport{
    public:
    virtual ~Transport()= default;
    virtual std::string transporting()const = 0;

};
class Car :public Transport{
    public:
 ~Car()= default;
std::string transporting() const override{
    return"Land transporting";
}
};
class Boat:public Transport{
    public:
 ~Boat()= default;
std::string transporting() const override{
    return"Sea transporting";
}
};
class Logistics{
    public:
    virtual ~Logistics()= default;
    virtual Transport* FactoryMethod() const =0;
    void dostuff(){
        Transport* t=this->FactoryMethod();
        std::cout<<"The client chose : "<<t->transporting();
        delete t;
    }
};
class CarLogistics:public Logistics{
public:
~CarLogistics()= default;
Transport * FactoryMethod() const{
    return new Car();
}
};
class BoatLogistics : public Logistics{
public:

    ~BoatLogistics()= default;
    Transport * FactoryMethod() const{
    return new Boat();
}
};
int main(){
    Logistics* p;
    p=new CarLogistics;
    p->dostuff();
    delete p;
    std::cout<<'\n';
    p=new BoatLogistics;
    
    p->dostuff();
    delete p;
    return 0;
}