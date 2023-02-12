#include "Mystring.hpp"
#include <cstring>
#include <iostream>
//We need to create the constructors necesarry for the class
//First, no-args constructor
Mystring::Mystring()
:str{nullptr} {
    str = new char[1];
    *str = '\0';
    }
//Then, an overloaded constructor for objects initialized with some string
Mystring::Mystring(const char *s)
    :str{nullptr} {
    if(s==nullptr){
        str = new char [1];
        *str='\0';
    }else {
    str = new char[std::strlen(s)+1]; 
    //Here we can use "s", because c style strings are just arrays of characters 
    // and thus we can modify them by providing the adress (puta, como me ocstó entender eso)
    std::strcpy(str, s);
    }
}

Mystring::Mystring (const Mystring &source)
    : str{nullptr} {
        str = new char[std::strlen(source.str)+1];
        std::strcpy(str, source.str);

        }


Mystring::~Mystring() {
    delete [] str;
    }
    void Mystring::display() const { //Don't forget that here you dont need to put smcn
    std::cout<<str<<" : "<<get_lenght()<<"\n";
    }
    
    int Mystring::get_lenght() const {return std::strlen(str); } 
    //Well, i supose we can implement this method without expecting any variable since all methods
    //in a class can access to the members of the class, 所以 we can just aslk for "strlen(str)"
    
    const char * Mystring::get_str() const { return str;}
    
    //Here goes the implementation of the overloading of assignment operator method
        Mystring &Mystring::operator=(const Mystring &rhs) {
        std::cout<<"                                                     copy constructor used\n";
        //I still dont fully understand the purpose of adding a reference operator there,
            //later on, if we use this operator with a rhs containing a c style string, it will sill work
            //thats pretty confusing
            
//Well, my best theory right now is that, if you create a 'Mystring' object and then try to assign it whatever
//you put on the right side, the class will suppose "Well, that rhs value must be of the same type as the lhs
//one", so it creates a new object given the constructors you provide. So, it creates an object with a member
//equal to that c style string, and then assign that object data to the lhs object.
        //std::cout<<"Using the overloaded copy assignment\n";
        if (this == &rhs)
            return *this;
        
        delete [] this->str;
        str = new char[std::strlen(rhs.str)+1];
        std::strcpy(str, rhs.str);
        return *this;
            }
  
     
Mystring &Mystring::operator=(Mystring &&rhs){
    std::cout<<"                                                     move constructor used\n";
    if (this == &rhs){
        return *this;
    }else {
        
    delete [] str;
    str = rhs.str;
    rhs.str = {nullptr};
    return *this;
    }
}
    //Here i will implement the overloading of the minus operator, to convert mystring objects to lowercase
    
Mystring Mystring::operator-() const {
    std::cout<<"                                                     tolower operator being used"<<std::endl;
    char *temp = new char [std::strlen(str)+1];
    temp = std::strcpy(temp, str);
    for (size_t i{0}; i<std::strlen(temp); i++) {
        temp[i] = std::tolower(temp[i]);
        }
    Mystring sapy {temp};
    delete [] temp;
    return sapy;
        
}
        
    //Now, the implementation of the concatenation method
Mystring Mystring::operator+(const Mystring &rhs) const {
    char *sapy = new char [std::strlen(str)+std::strlen(rhs.str)+1];
    std::strcpy(sapy, str);
    std::strcat(sapy, rhs.str);
    Mystring temp {sapy};
    delete [] sapy;
    return temp;
    
}
    

    //Implementation of "==" operator
    
bool Mystring::operator==(const Mystring &rhs) const {
    std::cout<<"                                                     ''=='' operator used\n";
    if(std::strcmp(str , rhs.str) == 0){
        return true;        
    }else {
    return false;    
    }
}         
            
    //Here we will implement the method for the ovrldng of the "+=" for the class

Mystring Mystring::operator+=(const Mystring &rhs) {
    std::cout<<"                                                     Using the ''+-'' concatenator\n";
    char *buff = new char [std::strlen(str)+std::strlen(rhs.str)+1];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    *this = Mystring {buff};
    delete [] buff;
    return *this;
}

Mystring Mystring::operator*(const int &n) {
    char *buff = new char [((std::strlen(str)+1)*n)];
    std::strcpy(buff, "");
    for (int i{0}; i<n; i++) 
        std::strcat(buff,str);
    Mystring temp {buff};
    delete [] buff;
    return temp;
        
        
    
    }
    
    
    
