#include <iostream>
#include "Mystring.hpp"
#include <vector>
using namespace std;


int fin;
int main() {
    cout<<boolalpha;
    cout<<"=================Practice with classes and overloading operators================="<<endl;
    Mystring empty;
    Mystring jorge {"Jorge"};
    Mystring copy{jorge};
    
    empty.display();
    jorge.display();
    copy.display();

    Mystring a {"Hello,"};
    Mystring b;
    
    b = a;
    
    b.display();
    
    b = {"love u <3"};
    b.display();
  

    Mystring c {"Mercurio, Venus, Tierra, Marte"};
    c.display();
    
    cout<<"\n--------loop1--------\n";  
    vector<Mystring> planetas {"Mercurio","Venus","Tierra","Marte"};
    for (const Mystring &s: planetas)
        s.display();

     
//Modyfing the printed data of the objects acording to their first letter
    cout<<"\n--------loop2--------\n";  
    for(Mystring &s: planetas) {
    if (s.get_str()[0]=='M'){
        Mystring temp {"Sol"};
        temp.display();
        continue;
        }
    s.display();
    }

    


    cout<<"\n------------------Testing tolower overloading op------------------"<<endl;

    Mystring obj1 {"FERRARI"};
    Mystring obj2;
    Mystring obj3  {" is a brand of cars"};
    Mystring obj4 {obj3};
    Mystring obj5 {"Hello, my name is"};
    Mystring obj6 {" Lucas Johnson. "};
    
    obj2.display();
    obj2 = obj1;
    obj2.display();
    
    obj2 = -obj2;
    obj2.display();
    obj2 = (obj2+obj3);
    obj2.display();
    obj2 = (obj2+Mystring {", but i think they're pretty expensive"});
    obj2.display();
    
    cout<<"------------------------------------------------------------------\n";
    cout<<"It is "<<(obj2==obj3)<<" that: \n\n"; 
    (obj2.display());
    cout<<"\n and: \n\n";
    obj3.display();
    cout<<"\n are equal Mystring objects\n\n";
    
    cout<<"---------------------------Sum operators-----------------------\n";
    obj5.display();
    obj5+=obj6;
    obj5.display();
    obj5+=obj1+=obj2;
    obj5.display();
    
    cout<<"\n\n------------------Multiplication operator------------------\n";
    obj2.display();
    obj2 = obj2*2;
    obj2.display();

    
 cin>>fin;
return 0;    
    
}
