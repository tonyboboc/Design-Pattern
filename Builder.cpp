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
class Manual{
    private:
    std::string publisher;
    std::string storage;
    public:
    Manual()=default;
    void setstorage(const std::string & c){
        storage=c;
    }
    void setpublisher(const std::string &c){
        publisher=c;
    }
    std::string browsing (){
        return "if you want to browse the games, go to the game library in the console menu";
    }
    std::string play(){
        return "if you wanna play games, put the game discs into the console";
    }
    std::string info(){
        return "this is a console made by "+publisher+" and it has a storage of "+storage+"\n";
    }
    ~Manual()=default;
};
class Builder{
    public:
    virtual ~Builder()=default;
    virtual void producepublisher(const std::string&c)=0;
    virtual void producestorage(const std::string&c)=0;
};
class ManualBuilder:public Builder{
    private:
    Manual* manual;
    public:
    ~ManualBuilder(){
        delete manual;
    }
    ManualBuilder(){
        this->reset();
    }
    void reset(){
        this->manual=new Manual;
    }
    Manual * getprod(){
        Manual * m=manual;
        this->reset();
        return m;
    }
    void producepublisher(const std::string &c) override{
        manual->setpublisher(c);
    }
    void producestorage(const std::string &c)override{
        manual->setstorage(c);
    }
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
    void build(const std::string &c,const std::string& s){
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
    director.build(s1,s2);
    Console* c=conbuilder->getprod();
    std::cout<<c->info();
    delete c;
//Created using only builder 
    conbuilder->producepublisher(s1);
    conbuilder->producestorage(s2);
    c=conbuilder->getprod();
    std::cout<<c->info();
    delete c;
    delete conbuilder;
//Creating Manual using director
    ManualBuilder *  manbuilder=new ManualBuilder(); 
    director.setbuilder(manbuilder);
    director.build(s1,s2);
    Manual * man=manbuilder->getprod();
    std::cout<<man->info();
//Creating Manual using Builder
    delete man;
    manbuilder->producepublisher(s1);   
    manbuilder->producestorage(s2);
    man=manbuilder->getprod();
    std::cout<<man->info();
    delete man ;
    delete manbuilder;
}
//It is easier using a director since we don't need to tell the builder what to build each and every time
int main(){

    Director d;
    clientcode(d);
    return 0;
}