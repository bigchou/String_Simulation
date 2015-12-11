#include "mystring.h"
#include <string.h>
#include <algorithm>
using namespace std;
// 1. default constructor
String::String():size_(0),capacity_(0){
    str_ = new(nothrow) char[1];
    if(str_)
        str_[0] = '\0';
    else
        cout << "Warning: Memory Allocation Failure" << endl;
}
// 2. copy constructor
String::String(const String &rhs):size_(rhs.size_),capacity_(rhs.capacity_){
    str_ = new(nothrow) char[rhs.capacity_];
    if(str_){
        for(size_t i = 0 ; i < rhs.size_ ; ++i )
            str_[i] = rhs.str_[i];
        str_[rhs.size_] = '\0';
    }else{
        cout << "Warning: Memory Allocation Failure" << endl;
        size_ = capacity_ = 0;
    }
}
// 3. constructor with one parameter with type const char *
String::String(const char *s):size_(strlen(s)),capacity_(size_){
     str_ = new(nothrow) char[size_ + 1];
     if(str_){
        for(size_t i =0; i< size_; ++i)
            str_[i] = s[i];
        str_[size_] = '\0';
     }else{
        cout << "Warning: Memory Allocation Failure" << endl;
        size_ = capacity_ = 0;
     }
}

String::String(char c):size_(1),capacity_(1){
    str_ = new(nothrow) char[2]{c,'\0'};
    if(!str_){
        cout << "Warning: Memory Allocation Failure" << endl;
        size_ = capacity_ = 0;
    }
}
// 8. operator +=
String & String::operator += (const String &rhs){
    if(size_ + rhs.size_ > capacity_){
        char* tmp = new(nothrow) char[size_+rhs.size_+1];
        if(tmp){
            for(size_t i=0;i<size_;++i)
                tmp[i] = str_[i];
            for(size_t i=0;i<rhs.size_;++i)
                tmp[size_+i] = rhs.str_[i];
            delete [] str_;
            str_ = tmp;
            size_ += rhs.size_;
            capacity_ = size_;
            str_[size_] = '\0';
        }else{
            cout << "Warning: Memory Allocation Failure" << endl;
        }
    }else{
        for(size_t i = 0; i < rhs.size_ ; ++i)
            str_[i+size_] = rhs.str_[i];
        size_ += rhs.size_;
        str_[size_] = '\0';
    }
    return *this;
}

String & String::operator += (char c){
    String rhs(c);
    *this += rhs;
    return *this;
}
// 10. operator =
String & String::operator = (String rhs){
    if(this->capacity_ > rhs.size_){
        this->size_ = rhs.size();
        for(size_t i=0 ; i < rhs.size() ; ++i )
            this->str_[i] = rhs.str_[i];
        this->str_[rhs.size_] = '\0';
    }else{
        this->swap(rhs);
    }
    return *this;
}

String & String::operator = (char c){
    char rhs[]{c,'\0'};
    *this = rhs;
    return *this;
}
// 11. swap
void String::swap(String &rhs){
    using std::swap;
    swap(rhs.size_, size_);
    swap(rhs.capacity_,capacity_);
    swap(rhs.str_,str_);
}

// A. relational operators (<, >, <=, >=, ==, !=)
bool operator < (const String &lhs, const String &rhs){
    return strcmp(lhs.str_,rhs.str_)< 0 ? true : false;
}
bool operator > (const String &lhs, const String &rhs){
    return strcmp(lhs.str_,rhs.str_)> 0 ? true : false;
}
bool operator <= (const String &lhs, const String &rhs){
    return lhs>rhs ? false : true;
}
bool operator >= (const String &lhs, const String &rhs){
    return lhs<rhs ? false : true;
}
bool operator == (const String &lhs, const String &rhs){
    return strcmp(lhs.str_,rhs.str_)== 0 ? true : false;
}
bool operator != (const String &lhs, const String &rhs){
    return lhs==rhs ? false : true;
}
// B. operator <<
ostream & operator << (ostream &os, const String &s){
    for(size_t i =0; i < s.size() ; ++i)
        os << s[i];
    return os;
}
// C. operator +
const String operator + (const String &lhs, const String &rhs){
    String tmp(lhs);
    tmp += rhs;
    return tmp;
}
const String operator + (const String &lhs, char rhs){
    String tmp(lhs);
    tmp += rhs;
    return tmp;
}
const String operator + (char lhs, const String &rhs){
    String tmp(lhs);
    tmp += rhs;
    return tmp;
}
// D. extra
istream & operator >> (istream & is, String & s){
    char c;
    while(!isspace(c=is.get()) && c !='\n')
        s+=c;
    if(c!='\n')
        is.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    return is;
}
