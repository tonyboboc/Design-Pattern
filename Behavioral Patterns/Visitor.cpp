#include <iostream>
#include <string>
class Console;
class Pc;
class BaseVisitor{
    public:
    virtual void VisitConsole(const Console* console)const=0;
    virtual void VisitPc(const Pc* pc)const=0;
};
class Component{
    public:
    virtual ~Component()=default;
    virtual void Accept(BaseVisitor *visitor) const = 0;
};
class Console:public Component{
    public:
    void Accept(BaseVisitor * visitor)const{
        visitor->VisitConsole(this);
    }
    std::string ConsoleStuff()const {
        return"Doing stuff you can only do on console (play games from  ps+)";
    }
};
class Pc:public Component{
public:
    void Accept(BaseVisitor * visitor)const{
        visitor->VisitPc(this);
    }
    std::string PcStuff()const {
        return"Doing stuff you can only do on pc (pay taxes)";
    }
};
class ConcreteVisitor:public BaseVisitor{
    public:
    void VisitConsole(const Console* console)const override{
        std::cout<<console->ConsoleStuff()<<std::endl;
    }
    void VisitPc(const Pc* pc )const override{
        std::cout<<pc->PcStuff()<<std::endl;
    }
};
void ClientCode(){
    ConcreteVisitor visitor;
    Component * pc=new Pc();
    Component* console=new Console();
    pc->Accept(&visitor);
    console->Accept(&visitor);
 }
 int main(){
    ClientCode();
    return 0;
 }