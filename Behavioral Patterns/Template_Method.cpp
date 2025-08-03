#include <iostream>
#include <string>
class Base_Document{
    public:
    void Export_Document(){
        format_type();
        load_document();
        save();
    }
    protected:
    virtual void save(){
        std::cout<<"normal type of save\n";
    }
    void load_document(){
        std::cout<<"showing the document\n";
    }

    virtual void format_type()const =0;
};
class Document1:public Base_Document{
    protected:
    void format_type()const override{
        std::cout<<"format type 1\n";
    }
};
class Document2:public Base_Document{
    protected:
    void format_type()const override{
        std::cout<<"format type 2\n";
    }
    void save() override{
        std::cout<<"different type of save\n";
    }
};
void ClientCode(){
    Document1 d1;
    Document2 d2;
    d1.Export_Document();
    d2.Export_Document();
}
int main(){
    ClientCode();
    return 0;
}