#include <iostream>
#include <string>
//Implemetation
class color{
    public:
    virtual ~color()=default;
    virtual std::string color_is()const=0;
};
class red:public color{
    std::string s="red";
    public:
    ~red()=default;
    std::string color_is()const override{
        return s;
    }
};
class blue :public color{
 std::string s="blue";
    public:
    ~blue()=default;
    std::string color_is()const override{
        return s;
    }
};
class shape{
    protected:
    color* s;
    public:
    shape(color* s){this->s=s;}
    virtual ~shape()=default;
    virtual std::string all_is()const{
        return "normal shape of color "+ s->color_is()+'\n';
    };
};
class square:public shape{
    std::string c="square";
    public:
    square(color *s):shape(s){}
    std::string all_is()const override{
        return "this shape is "+ c +" of color "+s->color_is()+'\n';
    }
};
class circle:public shape{
    std::string c="circle";
    public:
    circle(color *s):shape(s){}
    std::string all_is()const override{
        return "this shape is "+ c +" of color "+s->color_is()+'\n';
    }
};
int main(){
    color* c=new blue();
    shape* s =new shape(c);
    //even a normal base shape has a color
    std::cout<<s->all_is();
    delete s;
    s=new circle(c);
    std::cout<<s->all_is();
    delete s;
    delete c;
    c= new red();
    s=new square(c);
    std::cout<<s->all_is();
    delete s;
    delete c;
    return 0;
}