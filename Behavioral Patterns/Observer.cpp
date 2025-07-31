#include <list>
#include <string>
#include <iostream>
class BaseObserver{
    public:
virtual  ~BaseObserver()=default;
virtual void Update(const std::string & message)=0;
};
class BaseSubject{
public:
    virtual ~BaseSubject()=default;
    virtual void attach(BaseObserver* obs)=0;
    virtual void remove(BaseObserver* obs)=0;
    virtual void Notify()=0;
};