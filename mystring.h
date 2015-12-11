#ifndef MYSTRING_HHH
#define MYSTRING_HHH
#include <iostream>
class String{
friend  bool operator < (const String &lhs, const String &rhs);
friend  bool operator > (const String &lhs, const String &rhs);
friend  bool operator == (const String &lhs, const String &rhs);
public:
// 0. extra
size_t capacity() const {return capacity_;}
// 1. default constructor
String();
// 2. copy constructor
String(const String &rhs);
// 3. constructor with one parameter with type const char *
String(const char *s);
String(char c);
// 4. destructor
~String(){delete [] str_;}
// 5. size()
size_t size()const{return size_ ; }
// 6. c_str()
const char* c_str() const { return str_;}
// 7. operator []
const char & operator [] (std::size_t i) const { return str_[i];}
char & operator [] (std::size_t i){return const_cast<char &>(static_cast<const String &>(*this)[i]);}
// 8. operator +=
String & operator += (const String &rhs);
String & operator += (char c);
// 9. clear()
void clear(){size_ = 0;str_[0] = '\0';}
// 10. operator =
String & operator = (String rhs);
String & operator = (char c);
// 11. swap
void swap(String &rhs);

private:
    std::size_t size_ = 0, capacity_ = 0;
    char *str_ = nullptr;
};
// A. relational operators (<, >, <=, >=, ==, !=)
 bool operator < (const String &lhs, const String &rhs);
 bool operator > (const String &lhs, const String &rhs);
 bool operator <= (const String &lhs, const String &rhs);
 bool operator >= (const String &lhs, const String &rhs);
 bool operator == (const String &lhs, const String &rhs);
 bool operator != (const String &lhs, const String &rhs);
// B. operator <<
std::ostream & operator << (std::ostream &os, const String &s);
// C. operator +
const String operator + (const String &lhs, const String &rhs);
const String operator + (const String &lhs, char rhs);
const String operator + (char lhs, const String &rhs);
// D. extra
std::istream & operator >> (std::istream &is, String &s);
#endif // MYSTRING_HHH
