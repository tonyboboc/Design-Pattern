#include <iostream>
#include <string>
class Console {
    private:
    std::string publisher;
    std::string storage;
    public :
    Console()=default;
    void setstorage(const std::string & c){
        storage=c;
    }
    void setpublisher(const std::string &c){
        publisher=c;
    }
    std::string browsing (){
        return "browsing store";
    }
    std::string play(){
        return "playing some game";
    }
    std::string info(){
        return publisher + " "+storage +"\n";
    }
    ~Console()=default;
};
class Builder{
    public:
    virtual ~Builder()=default;
    virtual void producepublisher(const std::string&c)=0;
    virtual void producestorage(const std::string&c)=0;
};
class ConsoleBuilder:public Builder{
    private:
    Console* console;
    public:
    ConsoleBuilder(){
        this->reset();
    }
    ~ConsoleBuilder(){
        delete console;
    };
    void producepublisher(const std::string&c)override{
        console->setpublisher(c);
    }
    void producestorage(const std::string &c)override{
        console->setstorage(c);
    }
    Console* getprod(){
        Console * console1=console;
        this->reset();
        return console1;
    }
    void reset(){
        
        console=new Console;
    }

};

class Director{
    private :
    Builder * builder;
    public:
    void setbuilder (Builder * builder){
        this->builder=builder;
    }
    void buildconsole(const std::string &c,const std::string& s){
        builder->producepublisher(c);
        builder->producestorage(s);
    }
};
void clientcode(Director & director){
//created using director
   
    ConsoleBuilder *conbuilder=new ConsoleBuilder();
    director.setbuilder(conbuilder);
    std::string s1,s2;
    std::cout<<"what brand do you want the console :";
    std::cin>>s1;
    std::cout<<"how much space in it : ";
    std::cin>>s2;
    director.buildconsole(s1,s2);
    Console* c=conbuilder->getprod();
    std::cout<<c->info();
    delete c;
//Created using only builder (it is easier to use director if you have another builder class (ex another for a console manual))
    conbuilder->producepublisher(s1);
    conbuilder->producestorage(s2);
    c=conbuilder->getprod();
    std::cout<<c->info();
    delete c;
    delete conbuilder;
}
int main(){

    Director d;
    clientcode(d);
    return 0;
}