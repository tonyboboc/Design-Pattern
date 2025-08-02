#include <iostream>
#include <string>
#include <memory>
class Strategy{
    public:
    virtual ~Strategy()=default;
    virtual std::string Route()const=0;
};
class Context{
    std::unique_ptr<Strategy> strategy;
    public:
    explicit Context(std::unique_ptr<Strategy> &&str = {}):strategy(std::move(str)){
    
    }
    void change_strategy(std::unique_ptr<Strategy> &&str){
        strategy=std::move(str);
    }
    void set_route(){
        if(strategy){
            std::cout<<strategy->Route()<<std::endl;
            std::cout<<"This route was chosen\n";
        }
        else{
            std::cout<<"you did not select on what you want your Route to be (foot or car )\n";
        }
    }
};
class Foot:public Strategy{
    public:
    std::string Route()const override{
        return "Calculating where you want to go on foot";
    }
    ~Foot() { std::cout << "Foot strategy deleted\n"; }
};
class Car:public Strategy{
    public:
    std::string Route()const override{
        return "Calculating where you want to go by car";
    }
    ~Car() { std::cout << "Car strategy deleted\n"; }
};
void ClientCode(){
    Context context(std::make_unique<Foot>());
    std::cout<<"Here is the route by foot : ";
    context.set_route();
    context.change_strategy(std::make_unique<Car>());
    std::cout<<"Here is the route by car : ";
    context.set_route();
   
}
int main(){
    ClientCode();
    return 0;
}