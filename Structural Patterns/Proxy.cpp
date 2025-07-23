#include <string>
#include <iostream>
#include <memory>
class BasePost{
    public:
    virtual std::string Post()const=0;
};
class RealPost:public BasePost{
    public:
    std::string Post()const override{
        return "Posting on social media\n";
    }
};
class Proxy:public BasePost{
    private:
    std::unique_ptr <RealPost>post;
    bool logged=false;
    bool islogged()const{
        return logged;
    }
    public:
    Proxy( const RealPost & x){
        post=std::make_unique<RealPost>(x);
    }
    void loggin(){
        std::cout<<"pass and username/email\n";
        logged=true;
    }
    std::string Post()const override{
        if(this->islogged()){
           return post->Post(); 
        }
        else{
            return "you are not logged, log in \n";
        }
    }
   
};
void ClientCode(BasePost & base){
    std::cout<<base.Post();
}
int main(){
RealPost r;
Proxy p(r);
p.loggin();
ClientCode(p);
}
