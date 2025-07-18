#include <iostream>
#include <string>
#include <list>
#include <algorithm>
class FilesystemItem{
    protected:
    FilesystemItem* parent;

    public:
     FilesystemItem():parent(nullptr){}
    virtual ~FilesystemItem(){};
    void setparent(FilesystemItem * parent){
        this->parent=parent;
    }
    FilesystemItem * getparent(){
        return parent;
    }
    virtual void add (FilesystemItem* child){}
    virtual void remove(FilesystemItem* child){}
    virtual bool isFolder()const{
        return false;
    }
    
    virtual std::string Operation()const =0;
};
class File : public FilesystemItem{
    std::string name;
public:
    File(std::string s):FilesystemItem(){
        name=s;
    }
    std::string Operation() const override{
        return name;
    }   
};
class Folder:public FilesystemItem{
    std::string name;
    std::list<FilesystemItem *> children;
    public :
    Folder(std::string s):FilesystemItem(){
        name=s;
    }
    void add(FilesystemItem * child) override{
        children.push_back(child);
        child->setparent(this);
    }
    void remove(FilesystemItem* child)override{
        children.remove(child);
        child->setparent(nullptr);
    }
    std::string Operation()const override{
        std::string result;
        for(const FilesystemItem* f : children){
            if(f==children.back()){
                result +=f->Operation();
            }
            else{
                result +=f->Operation()+ '+';
            }
        }
        return name +"( "+result +" )";
    }
    ~Folder(){
        for(const FilesystemItem* c:children){
            delete c;
        }
    }
};
void Clientcode(FilesystemItem* f){
    std::cout<<f->Operation();
}
int main(){
    FilesystemItem* folder=new Folder("Main Folder");
    FilesystemItem* file1=new File("file1");
    FilesystemItem* file2=new File("file2");
    FilesystemItem* file3=new File("file3");
    folder->add(file1);
    FilesystemItem* subfolder=new Folder("Sub Folder");
    folder->add(subfolder);
    subfolder->add(file2);
    subfolder->add(file3);
    Clientcode(folder);
    delete folder;

    return 0;
}