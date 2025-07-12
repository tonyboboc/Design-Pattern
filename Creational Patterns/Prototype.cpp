#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>
enum class type{
    Warrior,
    Mage
};
class Character{
    protected :
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
    virtual std::string info()const=0;
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
    std::string info()const override{
        return "Warrior with stats : "+std::to_string(health)+" "+name+" "+std::to_string(stamina)+" "+std::to_string(walkspeed)+" "+weapon;
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
    std::string info()const override{
        return "Warrior with stats : "+std::to_string(health)+" "+name+" "+std::to_string(stamina)+" "+std::to_string(walkspeed)+" "+spell;
    }
};
class CharacterFactory{
    std::unordered_map<type,std::unique_ptr<Character>> characters;
    public:
        CharacterFactory(){
            characters[type::Warrior]= std::make_unique<Warrior>("basic weapon","Warrior",100,120,50);
            characters[type::Mage]=std::make_unique<Mage>("basic spell","Mage",85,100,75);
        }
        ~CharacterFactory()=default;//Because we used smart pointers
        std::unique_ptr<Character> createcharacter(type Type){
            return (characters[Type]->Clone());
        }
};
void Client (CharacterFactory & factory){
    std::cout<<"what character type do you want ? mage(0) or warrior(1) ?";
    int x;
    std::cin>>x;
    std::unique_ptr<Character> character;
    if(x==0){
        character=factory.createcharacter(type::Mage);
        std::cout<<character->info();
    }
    else{
        character=factory.createcharacter(type::Warrior);
        std::cout<<character->info();
    }
    //no need for deletion since we use smart pointers

}
int main(){
    CharacterFactory factory;
    Client(factory);
    return 0;
}