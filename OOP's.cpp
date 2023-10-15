
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


///////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

class Hero{

private:
    int health;
    char level;

public:
    char *name;
    // Default Constructor
    Hero(){
        cout<<"Default Constructor"<<endl;
        name=new char[100];
    }
    // Parameterised Constructor
    Hero(int health){
        this->health=health;
    }
    Hero(int health,char level){
        this->health=health;
        this->level=level;
    }
    // Copy Constructor
    Hero(Hero& temp){
        char *ch=new char[strlen(temp.name)+1];
        strcpy(ch,temp.name);
        this->name=ch;
        
        this->health=temp.health;
        this->level=temp.level;
    }
    // Destructor
    ~Hero(){
        cout<<"Destructor"<<endl;
    }
    
    void sethealth(int h){
        health=h;
    }
    
    void setlevel(char ch);
    
    int gethealth();
    
    char getlevel(){
        return level;
    }
    void print(){
        cout<<"[ Name: "<<this->name<<" ,";
        cout<<"Health: "<<gethealth()<<" ,";
        cout<<"Level: "<<getlevel()<<" ]"<<endl;
    }
    void setname(char name[]);
};

void Hero::setname(char name[]){
    strcpy(this->name,name);
}

void Hero::setlevel(char ch){
    level=ch;
}

int Hero::gethealth(){
    return health;
}


int main(){
    
    Hero hero1;
    hero1.sethealth(12);
    hero1.setlevel('D');
    char name[4]="xyz";
    hero1.setname(name);
    hero1.print();
    
    Hero hero2(hero1);
    hero2.print();
    hero1.name[0]='G';
    hero1.print();
    hero2.print();
    
    return 0;
}
