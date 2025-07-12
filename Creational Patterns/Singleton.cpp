#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <memory>
class Singleton{
    private :
    std::string val;
    static std::unique_ptr<Singleton> singleton;
    static std::mutex mutex;
    Singleton(const std::string & s){
        val=s;
    }
     public:
    ~Singleton(){}
   
    Singleton(const Singleton & other)=delete;
    Singleton& operator =(const Singleton & other)=delete;
    static Singleton *GetInstance (const std::string & s);
    std::string value(){
        return val; 
    }
};
Singleton *Singleton::GetInstance (const std::string & s){
    std::lock_guard<std::mutex> lg(mutex);
    if (singleton==nullptr){
        singleton =std::unique_ptr<Singleton>(new Singleton(s)); 
    }
    return singleton.get();
}
void Value1(){
    Singleton* singleton=Singleton::GetInstance("value1");
    std::cout<<singleton->value()<<'\n';
}
void Value2(){
    Singleton* singleton=Singleton::GetInstance("value2");
    std::cout<<singleton->value()<<'\n';
}
std::unique_ptr<Singleton> Singleton::singleton (nullptr);
std::mutex Singleton::mutex;
int main(){
    std::thread t1(Value1);
    std::thread t2(Value2);
    //if we see the same value twice the code worked good , if not it didn't work good
    t1.join();
    t2.join();
}