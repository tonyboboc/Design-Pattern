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
};
class XboxConsole:public BaseConsole{

};