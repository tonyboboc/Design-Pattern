#include <iostream>
#include <string>
class Foccacia{
    public:
    virtual ~Foccacia()=default;
    virtual std::string operation()const=0;
    virtual int cost()const=0;
};
class Pizza:public Foccacia{
    public:
    ~Pizza()=default;
    std::string operation()const override{
        return "pizza";
    }
    int cost ()const override  {
        return 20;
    }
};
class BaseDecorator:public Foccacia{
    protected:
    Foccacia* pizza;
    public:
    BaseDecorator(Foccacia* pizza): pizza(pizza){}
    std::string operation()const override{
        return pizza->operation();
    }
    int cost()const override{
        return pizza->cost();
    }
};
class addcheese:public BaseDecorator{
    public:
    addcheese(Foccacia* pizza):BaseDecorator(pizza){}
    std::string operation()const override{
        return BaseDecorator::operation()+ " with cheese ";
    }
    int cost()const override{
        return BaseDecorator::cost()+5;
    }
};
class addpeperoni :public BaseDecorator{
    public:
addpeperoni(Foccacia* pizza):BaseDecorator(pizza){}
    std::string operation()const override{
        return BaseDecorator::operation()+ " with peperoni ";
    }
    int cost()const override{
        return BaseDecorator::cost()+10;
    }
};
int main(){
    Foccacia * pizza=new Pizza();
    Foccacia* topping1=new addcheese(pizza);
    Foccacia* topping2=new addpeperoni(topping1);
    std::cout<<topping2->operation()<<' ';
    std::cout<<topping2->cost()<<std::endl;
    std::cout<<topping1->operation()<<' ';
    std::cout<<topping1->cost()<<std::endl;
    delete pizza ;
    delete topping1;
    delete topping2;
}