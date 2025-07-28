#include <iostream>
#include <vector>

template <typename U>
class   Iterator{
    public:
    typedef typename U::container::iterator iter_type;
    Iterator (U* p_data,bool reverse=false):m_pdata(p_data){
        m_it=m_pdata->m_data.begin();
    }
    void First(){
        m_it=m_pdata->m_data.begin();
    }
    bool IsDone(){
        return (m_it==m_pdata->m_data.end());
    }
    void next(){
        m_it++;
    }
    iter_type Current(){
        return m_it;
    }
    private:
    U * m_pdata;
    iter_type m_it;
};
template <class T>
class Container{
friend class Iterator<Container>;
public:
using container=std::vector<T>;
void add (T a){
    m_data.push_back(a);
}
Iterator<Container>* CreateIterator(){
    return new Iterator<Container>(this);
}
private: 
std::vector<T> m_data;
};
class Data{
    public:
    Data(int a):m_data(a){}
    void set_data(int a ){
        m_data=a;
    }
    int data(){
        return m_data;
    }
    private:
    int m_data;
};
void clientCode(){
    Container<int> cont;
    cont.add(5);
    cont.add(7);
    cont.add(9);
    Iterator<Container<int>>*it=cont.CreateIterator();
    for (it->First(); !it->IsDone(); it->next()) {
    std::cout << *it->Current() << std::endl;
  }
  delete it;
  Container<Data> cont1;
  Data a(10),b(20),c(30);
  cont1.add(a);cont1.add(b);cont1.add(c);
  Iterator<Container<Data>>*it1=cont1.CreateIterator();
  for (it1->First(); !it1->IsDone(); it1->next()) {
    std::cout << it1->Current()->data() << std::endl;
  }
  delete it1;
}
int main(){
    clientCode();
    return 0;
}