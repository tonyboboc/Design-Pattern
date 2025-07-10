#include <iostream>
#include <string>
class Console {
    private:
    std::string publisher;
    std::string storage;
    public :
    void setstorage(const std::string & c){
        storage=c;
    }
    void setpublisher(const std::string &c){
        publisher=c;
    }
};