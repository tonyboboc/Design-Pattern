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
        return "nintendo";
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
        return "nintendo";
    }
};
class BaseConsole {
public:
    virtual ~BaseConsole()=default;
    virtual std::string play(){
        return"playing on base console";
    };
    virtual std::string getbrand()const =0;
    virtual std::string plugcontroller(BaseController& con)const=0;
    virtual std::string putgame(Cd& cd)const=0;
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
  std::string plugcontroller(BaseController& con)const override{
    if(!(this->getbrand()==con.getbrand())){
        return "doesn't work , not same brand";
    }
    return "playing on Sony Console with Sony Controller";
  }
  std::string putgame(Cd& cd)const override{
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
  std::string plugcontroller(BaseController& con)const override{
    if(!(this->getbrand()==con.getbrand())){
        return "doesn't work , not same brand";
    }
    return "playing on Xbox Console with Xbox Controller";
  }
  std::string putgame(Cd& cd)const override{
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
  std::string plugcontroller(BaseController& con)const override{
    if(!(this->getbrand()==con.getbrand())){
        return "doesn't work , not same brand";
    }
    return "playing on Nintendo Console with Nintendo Controller";
  }
  std::string putgame(Cd& cd)const override{
    if(!(this->getbrand()==cd.getbrand())){
        return "doesn't work , not same brand";
    }
    return "playing on Nintendo Console with Nintendo Cd";
  }
};
class AbstractFactory {

};