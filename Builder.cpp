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
    ~Console()=default;
};
class Manual{
    private :
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
    std::string read(){
        return"reading manual";
    }
    std::string play(){
        return "if you want to play a game ,put the cd into the console";
    }
    ~Manual()=default;
};
class Builder{
    public:
    virtual ~Builder()=default;
    virtual void settingpublisher(const std::string&c);
    virtual void settingstorage(const std::string&c);
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
    void settingpublisher(const std::string&c)override{
        console->setpublisher(c);
    }
    void settingstorage(const std::string &c)override{
        console->setstorage(c);
    }
    Console* getprod(){
        Console * console1=console;
        this->reset();
        return console1;
    }
    void reset(){
        delete console;
        console=new Console;
    }

};
class ManualBuilder:public Builder{
    private :
    Manual* manual;
    public:
    ~ManualBuilder(){delete manual;}
    ManualBuilder(){
        this->reset();
    }
    void reset(){
        delete manual;
        manual =new Manual;
    }
    void settingpublisher(const std::string & c)override{
        manual->setpublisher(c);
    }
    void settingstorage(const std::string &c)override{
        manual->setstorage(c);
    }
    Manual * getproduct(){
        Manual* manual1=manual;
        delete manual;
        return manual1;
    }
};
class Director{
    private :
    Builder *builder;
    public:
    
};