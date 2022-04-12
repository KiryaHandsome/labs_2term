#ifndef STRINGCLASS_H
#define STRINGCLASS_H



#include <malloc.h>
#include <stdexcept>
#include <iostream>

#if defined(STRINGCLASS_DLL_LIBRARY)
#  define  STRINGCLASS_DLL_EXPORT __declspec(dllexport)
#else
#  define STRINGCLASS_DLL_EXPORT __declspec(dllexport)
#endif

class STRINGCLASS_DLL_EXPORT  String
{
private:
    char* str;
    size_t size;
    size_t capacity;
public:
     String();
     String(const char* str);
     String(const String& other) noexcept;
     String(size_t init_size);
     String(String&& other);
     String& operator = (const String& other);
     String& operator = (char* s);
     char& at(size_t index) const;
     char& operator [] (size_t index) const;
     const char* c_str() const;
     char& back() const;
     size_t lenght() const;
     size_t size_() const;
     size_t capacity_() const;
     bool empty() const;
     void shrink_to_fit();
     void reserve(size_t new_cap);
    //OPERATIONS//
     void clear();
     void push_back(char c);
     void pop_back();
     void insert(size_t pos, const String& StringClass);
     void erase(size_t pos, size_t length);
     String& operator + (const String& s);
     String& operator + (const char* input);
     String& operator += (const String& input);
     String& operator += (const char* input);
    //COMPARE
     bool operator ==(const String& other);
     bool operator !=(const String& other);
    //SEARCH
     size_t find(const char* s);
    //NON-MEMBER FUNCTIONS
     friend std::ostream& operator << (std::ostream& stream, const String& s);
     friend std::istream& operator >> (std::istream& in, String& s);
    //DESTRUCTOR
     ~String();
};

extern "C" STRINGCLASS_DLL_EXPORT String* CreateObject();



#endif // StringClass_H
