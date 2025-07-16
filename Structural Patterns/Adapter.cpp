#include <iostream>
#include <string>
#include <algorithm>
class Target {
    public:
    virtual ~Target()=default;
    virtual std::string normalbehaviour ()const {
        return "this is the way a function a normal class would override (the classes that inherit from Target)";
    }
};
class Adaptee{
    public:
    ~Adaptee()=default;
    std::string weird(){
        return "retpada na sdeen ssalc siht";
    }
};
class Adapter :public Target{
    Adaptee * var;
public:
Adapter (Adaptee & adaptee){
    var=&adaptee;
}
virtual ~Adapter()=default;
std::string normalbehaviour()const override{
    std::string reverse=var->weird();
    std::reverse(reverse.begin(),reverse.end());
    return reverse;
}
};
void clientcode(Target * target){
    //this class is used by all classes and the adapter
    std::cout<<target->normalbehaviour();
}
int main(){
    Adaptee a;
    Adapter adapter(a);
    clientcode(&adapter);
    return 0;

}