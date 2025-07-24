#include<iostream>
#include <string>
class Handler{
public:
    virtual Handler* setnext(Handler * handler)=0;
    virtual std::string handle(int request)=0;
};
class BaseHandler:public Handler{
    private:
    Handler* next;
    public:
    BaseHandler():next(nullptr){}
    Handler* setnext(Handler * handler) override{
        next=handler;
        return handler;
    } 
    std::string handle(int request)override{
        if(next){
            return next->handle(request);
        }
        return {};
    }
};
class Junior:public BaseHandler{
    public:
    std::string handle(int request)override{
        if(request<=1){
            return "junior can take care of this :";
        }
        return BaseHandler::handle(request);
    }
};
class Midlevel:public BaseHandler{
    public:
std::string handle(int request)override{
    if(request<=2){
            return "mid-level can take care of this :";
        }
        return BaseHandler::handle(request);
    
}
};
class Senior:public BaseHandler{
    public:
std::string handle(int request)override{
    if(request<=3){
            return "senior can take care of this :";
        }
        return BaseHandler::handle(request);
}
};
void clientcode(Handler*h){
    int x;
    std::cout<<"what level is your problem ? :";
    std::cin>>x;
    std::string s=h->handle(x);
    if(s.empty()){
        std::cout<<"no one can handle that request";
    }
    std::cout<<s;

}
int main(){
    Handler* h1=new Junior();
    Handler* h2=new Midlevel();
    Handler* h3=new Senior();
    h1->setnext(h2)->setnext(h3);
    clientcode(h1);
}