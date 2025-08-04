#include <iostream>
#include <string>
class Console;
class Pc;
class BaseVisitor{
    void VisitConsole(const Console* console);
    void VisitPC(const Pc* pc);
};
class Component{
    public:
    virtual ~Component()=default;
    virtual void Accept(BaseVisitor *visitor) const = 0;
};
