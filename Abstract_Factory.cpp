#include <iostream>
#include <string>
class BaseController{
    public:
virtual ~BaseController()=default;
virtual std::string getbrand()const=0;
};
class SonyController :public BaseController{
    public:
~SonyController()=default;
std::string getbrand ()const override{
    return "sony";
}
};
class XboxController :public BaseController{
    public:
    ~XboxController()=default;
    std::string getbrand()const override{
        return "xbox";
    }
};
class NintendoController :public BaseController{
    public:
    ~NintendoController()=default;
    std::string getbrand()const override{
        return "Nintendo";
    }
};
class Cd{
public :
virtual ~Cd()=default;
virtual std::string getbrand()const =0;
};
class SonyCd:public Cd{
    public:
    ~SonyCd()=default;
    std::string getbrand()const override{
        return "sony";
    }
};
class XboxCd:public Cd{
    public :
    ~XboxCd()=default;
    std::string getbrand()const override{
        return "xbox";
    }
};
class NintendoCd:public Cd{
    public:
    ~NintendoCd()=default;
    std::string getbrand()const override{
        return "Nintendo";
    }
};
class BaseConsole {
public:
    virtual ~BaseConsole()=default;
    virtual std::string play(){
        return"playing on base console";
    };
    virtual std::string getbrand()const =0;
    virtual std::string plugcontroller(const BaseController& con)const=0;
    virtual std::string putgame(const Cd& cd)const=0;
};
class SonyConsole:public BaseConsole{
  public :
  ~SonyConsole()=default;
  std::string play() override{
    return"playing on Sony Console";
  } 
  std::string getbrand()const override{
    return "sony";
  } 
  std::string plugcontroller(const BaseController& con)const override{
    if(!(this->getbrand()==con.getbrand())){
        return "doesn't work , not same brand";
    }
    return "playing on Sony Console with Sony Controller";
  }
  std::string putgame(const Cd& cd)const override{
    if(!(this->getbrand()==cd.getbrand())){
        return "doesn't work , not same brand";
    }
    return "playing on Sony Console with Sony Cd";
  }

};
class XboxConsole:public BaseConsole{
    public:
 ~XboxConsole()=default;
 std::string play()override{
return "playing on Xbox Console";
 }std::string getbrand()const override{
    return "xbox";
  } 
  std::string plugcontroller(const BaseController& con)const override{
    if(!(this->getbrand()==con.getbrand())){
        return "doesn't work , not same brand";
    }
    return "playing on Xbox Console with Xbox Controller";
  }
  std::string putgame(const Cd& cd)const override{
    if(!(this->getbrand()==cd.getbrand())){
        return "doesn't work , not same brand";
    }
    return "playing on Xbox Console with Xbox Cd";
  }
};
class NintendoConsole:public BaseConsole{
~NintendoConsole()=default;
 std::string play()override{
return "playing on Nintendo Console";
 }std::string getbrand()const override{
    return "Nintendo";
  } 
  std::string plugcontroller(const BaseController& con)const override{
    if(!(this->getbrand()==con.getbrand())){
        return "doesn't work , not same brand";
    }
    return "playing on Nintendo Console with Nintendo Controller";
  }
  std::string putgame(const Cd& cd)const override{
    if(!(this->getbrand()==cd.getbrand())){
        return "doesn't work , not same brand";
    }
    return "playing on Nintendo Console with Nintendo Cd";
  }
};
class AbstractFactory {
    public:
virtual ~AbstractFactory()=default;
virtual BaseConsole* createConsole()const=0;
virtual BaseController* createController()const=0;
virtual Cd* createGame()const=0;
};
class SonyFactory :public AbstractFactory{
    public:
~SonyFactory()=default;
BaseConsole* createConsole()const override {
    return new SonyConsole();
}
BaseController* createController()const override{
    return new SonyController();
}
Cd* createGame()const override{
    return new SonyCd();
}
};
class XboxFactory :public AbstractFactory{
    public:
~XboxFactory()=default;
BaseConsole* createConsole()const override {
    return new XboxConsole();
}
BaseController* createController()const override{
    return new XboxController();
}
Cd* createGame()const override{
    return new XboxCd();
}
};
class NintendoFactory :public AbstractFactory{
    public:
~NintendoFactory()=default;
BaseConsole* createConsole()const override {
    return new NintendoConsole();
}
BaseController* createController()const override{
    return new NintendoController();
}
Cd* createGame()const override{
    return new NintendoCd();
}
};
void Client(const AbstractFactory & x){
    BaseConsole* cons=x.createConsole();
    BaseController* cont=x.createController();
    Cd* cd=x.createGame();
    std::cout<<cons->plugcontroller(*cont)<<std::endl;
    std::cout<<cons->putgame(*cd)<<std::endl;
    std::cout<<cons->play()<<std::endl;
    delete cons;delete cont;delete cd;
}
int main(){
AbstractFactory* a=new SonyFactory();
Client(*a);
delete a;
a=new NintendoFactory();
Client(*a);
delete a;
a=new XboxFactory();
Client(*a);
delete a;
return 0;
}