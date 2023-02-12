#ifndef MYSTRING_HPP
#define MYSTRING_HPP

class Mystring
{
private:
    char *str;
public:
    Mystring();
    Mystring(const char *s);    
    Mystring(const Mystring &source);
    ~Mystring();
    void display() const;
    int get_lenght() const;
    const char * get_str() const;
    
    //Here we will initialize a new method by which we will overload the assiignment operator (=)
    Mystring &operator=(const Mystring &rhs);
    //Down there there is a method initialization for move assginment (overloading '=')
    Mystring &operator=(Mystring &&rhs);
    //Now we gotta initialize a method to overload the '-' assignment, to return a lowercase version
    //of any mystring object given to it
    Mystring operator-() const;
    
    //Now, i want to create an operator for concatenating mystring objects and one to compare them
    Mystring operator+(const Mystring &rhs) const;
    
    bool operator==(const Mystring &rhs) const;
    
    Mystring operator+=(const Mystring &rhs);
    
    Mystring operator*(const int &n);
    
    



};

#endif // MYSTRING_HPP
