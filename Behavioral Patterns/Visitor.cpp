#include <iostream>
#include <string>
class Console;
class Pc;
class BaseVisitor{
    void VisitConsole(const Console* console);
    void VisitPC(const Pc* pc);
};
