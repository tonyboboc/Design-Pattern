#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>
enum class type{
    Warrior,
    Mage
};
class Character{
    private :
    int health;
    std::string name;
    int stamina;
    int walkspeed;
    public:
    Character(int health,const std::string & name,int stamina,int walkspeed){
        this->health=health;
        this->name=name;
        this->stamina=stamina;
        this->walkspeed=walkspeed;
    }
    virtual std::unique_ptr<Character> Clone()const =0;
    virtual int return_helth()const{
        return this->health;
    }
    void change_name(const std::string & name){
        this->name=name;
    }
    virtual void changeatt(const std::string & c)=0;
    virtual std::string return_name()const {
        return this->name;
    }
};
class Warrior:public Character{
    private:
    std::string weapon;
    public :
    Warrior(const std::string & weapon,const std::string & name ,int health,int stamina,int walkspeed):
    Character(health,name,stamina,walkspeed){
        this->weapon=weapon;
    }
    void changeatt(const std::string &c)override{
        this->weapon=c;
    } 
    std::unique_ptr<Character> Clone()const override{
        return std::make_unique<Warrior>(*this);
    }
};
class Mage :public Character{
    private:
    std::string spell;
    public:
    Mage(const std::string & spell,const std::string & name ,int health,int stamina,int walkspeed):
    Character(health,name,stamina,walkspeed){
        this->spell=spell;
    }
    void changeatt(const std::string & c)override{
        spell=c;
    }
    std::unique_ptr<Character> Clone()const override{
        return std::make_unique<Mage>(*this);
    }
};