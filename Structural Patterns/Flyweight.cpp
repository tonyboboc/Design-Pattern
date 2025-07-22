#include <iostream>
#include <string>
#include <unordered_map>
class SharedState{
std::string texture;
public:
SharedState(const std::string & texture){
    this->texture=texture;
}
std::string getTexture() const{
    return texture;
}
};
class UniqueState{
    std::string name;
    public:
    UniqueState(const std::string & name){
        this->name=name;
    }
    std::string getName()const{
        return name;
    }
};
class Flyweight{
    private:
    SharedState * sharedstate;
    public:
    Flyweight(const SharedState * shared_state):sharedstate(new SharedState(*shared_state)){}
    Flyweight(const Flyweight & other):sharedstate(new SharedState(*other.sharedstate)){}
    ~Flyweight(){delete sharedstate;}
    void Operation(const UniqueState & unique)const {
        std::cout<<unique.getName()<<" has a texture of : "<<sharedstate->getTexture();
    }
};
class FlyweightFactory{
private:
std::unordered_map<std::string,Flyweight> flyweights;
std::string GetKey(const SharedState& s){
    return s.getTexture();
}
public:
FlyweightFactory(std::initializer_list<SharedState> share_states){
    for (const SharedState &ss : share_states)
        {
            this->flyweights.insert(std::make_pair<std::string, Flyweight>(this->GetKey(ss), Flyweight(&ss)));
        }
}
Flyweight getFlyweight(const SharedState & sharedstate){
    std::string key=this->GetKey(sharedstate);
    if(flyweights.find(key)==flyweights.end()){
        std::cout<<"we don't have this texture \n";
        flyweights.insert(std::make_pair(key,Flyweight(&sharedstate)));
    }
    else{
        std::cout<<"we already have this texture\n";
    }
    return this->flyweights.at(key);

}
void List()const{
    for(std::pair<std::string ,Flyweight>pair:this->flyweights){
        std::cout<<pair.first<<" ";
    }
}
};
int main(){
    FlyweightFactory *factory=new FlyweightFactory({{"tree"},{"car"}});
    factory->List();
   const Flyweight & flyweight=factory->getFlyweight({"tree"});
  flyweight.Operation({"Tree1"});
  delete factory;
}

