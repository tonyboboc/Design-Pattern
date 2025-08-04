#include <iostream>
#include <string>
class Console;
class Pc;
class BaseVisitor{
    public:
    void VisitConsole(const Console* console);
    void VisitPC(const Pc* pc);
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
    void ConsoleStuff(){
        std::cout<<"Doing stuff you can only do on console (play games from  ps+)";
    }
};
class Pc:public Component{
public:
    void Accept(BaseVisitor * visitor)const{
        visitor->VisitPC(this);
    }
    void PcStuff(){
        std::cout<<"Doing stuff you can only do on pc (pay taxes)";
    }
};