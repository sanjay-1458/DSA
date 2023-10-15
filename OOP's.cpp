
#include <iostream>
using namespace std;

class Student{

private:
    int _id;
    
public:
    string name;
    
    void setid(int id){
        _id=id;
    }
    int getid(){
        return _id;
    }
    void printname();
    Student(){
        cout<<"Default Constructor called"<<endl;
    }
    Student(int x);
    ~Student(){
        cout<<"Destructor called"<<endl;
    }
};

Student::Student(int x){
    cout<<"Parameterized Constructor called"<<endl;
}

void Student::printname(){
    cout<<name<<endl;
}

int main()
{
    Student s,k(33);
    s.setid(21);
    s.name="xyz";
    cout<<s.getid()<<endl;
    s.printname();

    return 0;
}



