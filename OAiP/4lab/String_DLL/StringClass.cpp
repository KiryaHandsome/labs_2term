#include "StringClass.h"


//namespace my {
//void* memcpy(void* s1, const void* s2, size_t n)
//{
//    char* dest = (char*)s1;
//    const char* src = (const char*)s2;
//    for (size_t i = 0; i < n; ++i)
//    {
//        *(dest + i) = *(src + i);
//    }
//    return dest;
//}

//void* memmove(void* s1, const void* s2, size_t n)
//{
//    char* dest = (char*)s1;
//    const char* src = (const char*)s2;

//    char* buffer = (char*)malloc(sizeof(char) * n);//
//    if (buffer != nullptr)
//    {
//        for (size_t i = 0; i < n; ++i)
//        {
//            *(buffer + i) = *(src + i);
//        }

//        for (size_t i = 0; i < n; ++i)
//        {
//            *(dest + i) = *(buffer + i);
//        }
//        free(buffer);
//        return dest;
//    }
//    return nullptr;
//}

//size_t strlen(const char* s)
//{
//    size_t length = 0;
//    while (*s++) ++length;
//    return ++length;
//}

//char* strcpy(char* s1, const char* s2)
//{
//    char* tmp = s1;
//    while (*s1++ = *s2++);
//    return tmp;
//}

//char* strncpy(char* s1, const char* s2, size_t n)
//{
//    char* tmp = s1;
//    for (size_t i = 0; i < n; ++i)
//    {
//        *s1++ = *s2++;
//    }
//    return tmp;
//}

//char* strcat(char* s1, const char* s2)
//{
//    size_t i, j;
//    for (i = 0; s1[i] != '\0'; i++) {}

//    for (j = 0; s2[j] != '\0'; j++)
//    {
//        s1[i + j] = s2[j];
//    }
//    s1[i + j] = '\0';
//    return s1;
//}

//char* strncat(char* s1, const char* s2, size_t n)
//{

//    char* dest = s1;
//    while (*dest != '\0') dest++;
//    while (n--)
//    {
//        if (!(*dest++ = *s2++))
//        {
//            return s1;
//        }
//    }
//    *dest = '\0';
//    return s1;
//}

//int memcmp(const void* s1, const void* s2, size_t n)
//{
//    unsigned char* p = (unsigned char*)s1;
//    unsigned char* q = (unsigned char*)s2;
//    int charCompareStatus = 0;
//    if (s1 == s2)
//    {
//        return charCompareStatus;
//    }
//    while (n > 0)
//    {
//        if (*p != *q)
//        {
//            charCompareStatus = (*p > *q) ? 1 : -1;
//            break;
//        }
//        n--;
//        p++;
//        q++;
//    }
//    return charCompareStatus;
//}

//int strcmp(const char* s1, const char* s2)
//{
//    while (*s1 && (*s1 == *s2))
//    {
//        s1++;
//        s2++;
//    }
//    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
//}

//int strncmp(const char* s1, const char* s2, size_t n)
//{
//    while (n && *s1 && (*s1 == *s2))
//    {
//        ++s1;
//        ++s2;
//        --n;
//    }
//    if (n == 0)
//    {
//        return 0;
//    }
//    else
//    {
//        return (*(unsigned char*)s1 - *(unsigned char*)s2);
//    }
//}

//size_t strxfrm(char* s1, const char* s2, size_t n)
//{
//    size_t n2 = strlen(s2);
//    if (n > n2)
//    {
//        strcpy(s1, s2);
//    }
//    return n2;
//}

//char* strtok(char* s1, char* s2)
//{
//    auto is_delim = [](char c, char* delim)
//    {
//        while (*delim != '\0')
//        {
//            if (c == *delim)
//                return 1;
//            delim++;
//        }
//        return 0;
//    };

//    static char* backup_StringClass;
//    if (!s1)
//    {
//        s1 = backup_StringClass;
//    }
//    if (!s1)
//    {
//        return nullptr;
//    }
//    while (true)
//    {
//        if (is_delim(*s1, s2))
//        {
//            s1++;
//            continue;
//        }
//        if (*s1 == '\0')
//        {
//            return nullptr;
//        }
//        break;
//    }
//    char* ret = s1;
//    while (true)
//    {
//        if (*s1 == '\0')
//        {
//            backup_StringClass = s1;
//            return ret;
//        }
//        if (is_delim(*s1, s2))
//        {
//            *s1 = '\0';
//            backup_StringClass = s1 + 1;
//            return ret;
//        }
//        s1++;
//    }
//}

//void* memset(void* s, int c, size_t n)
//{
//    unsigned char* p = (unsigned char*)s;
//    while (n--)
//    {
//        *p++ = (unsigned char)c;
//    }
//    return s;
//}
//}

//CONSTRUCTORS
 String::String() : size(0), capacity(0)
{
    str = new char[1];
    str[0] = '\0';
}

 String::String(const char* str)
{
    size = strlen(str);
    capacity = size;

    this->str = new char[size + 1];
    for (size_t i = 0; i < size; i++)
    {
        this->str[i] = str[i];
    }

    this->str[size] = '\0';
}

 String::String(const String& other) noexcept
{
    size = other.size;
    capacity = other.capacity;

    str = new char[capacity];
    for (size_t i = 0; i < size; i++)
    {
        str[i] = other.str[i];
    }

    str[size] = '\0';
}

 String::String(size_t init_size)
{
    str = new char[init_size];

    size = init_size;
    capacity = init_size;

    str[size - 1] = '\0';
}

 String::String(String&& other)
{
    size = other.size;
    capacity = other.capacity;
    str = other.str;
    other.str = nullptr;
}

//ASSIGNING
 String& String::operator = (const String& other)
{
    if (capacity < other.capacity)
    {
        clear();
        str = new char[other.capacity];
        capacity = other.capacity;
    }

    size = other.size;

    for (size_t i = 0; i < size; i++)
    {
        str[i] = other.str[i];
    }

    str[size] = '\0';

    return *this;
}

 String& String::operator = (char* s)
{
    size_t s_size = strlen(s);

    if (capacity < s_size)
    {
        clear();
        str = new char[s_size];
        capacity = s_size;
    }

    size = s_size;

    for (size_t i = 0; i < size; i++)
    {
        str[i] = s[i];
    }

    str[size] = '\0';

    return *this;
}

//ELEMENT ACCESS
 char& String::operator [] (size_t index) const
{
    return str[index];
}

 char& String::at(size_t index) const
{
    if (index >= size)
        throw std::out_of_range("Out of range");
    return str[index];
}

 const char* String::c_str() const
{
    return str;
}

 char& String::back() const
{
    return str[size - 1];
}

//CAPACITY
 size_t String::lenght() const
{
    return size;
}

 size_t String::size_() const
{
    return size;
}

 size_t String::capacity_() const
{
    return capacity;
}

 bool String::empty() const
{
    return size;
}

 void String::shrink_to_fit()
{
    if (size == capacity)
        return;
    reserve(size + 1);
}

 void String::reserve(size_t new_cap)
{
    if (new_cap > capacity)
    {
        char* new_str = new char[new_cap];
        for (size_t i = 0; i < size; ++i)
        {
            new_str[i] = str[i];
        }
        new_str[size] = '\0';
        clear();
        str = new_str;
        size = strlen(new_str);
        capacity = new_cap - 1;
    }
}

//OPERATIONS
 void String::clear()
{
    delete[] str;
    str = nullptr;
    size = 0;
    capacity = 0;
}

 void String::push_back(char c)
{
    if (size == capacity) {
        reserve(capacity * 2);
    }
    str[size++] = c;
    str[size] = '\0';
}

 void String::pop_back()
{
    str[--size] = '\0';
}

 void String::insert(size_t pos, const String& String)
{
    size_t new_size = size + String.size_();
    auto new_str = new char[new_size + 1];
    for (size_t i = 0, l = 0; i < new_size; ++i)
    {
        if (i != pos)
        {
            new_str[i] = str[l];
            ++l;
        }
        else
        {
            size_t j = 0;
            for (; j < String.size_(); ++j)
            {
                new_str[i + j] = String[j];
            }
            i += j - 2;
        }
    }
    clear();
    str = new_str;
    size = new_size;
    capacity = new_size;
}


 void String::erase(size_t pos, size_t length)
{
    size_t new_size = size - length;
    auto new_str = new char[new_size];
    for (size_t i = 0, l = 0; i < size; ++i) {
        if (i < pos || i > pos + length)
        {
            new_str[l] = str[i];
            ++l;
        }
    }
    clear();
    str = new_str;
    size = new_size;
    capacity = new_size;
}

 String& String::operator + (const String& s)
{
    for (size_t i = 0; i < s.size_(); i++)
    {
        this->push_back(s[i]);
    }
    return *this;
}

 String& String::operator + (const char* input)
{
    size_t len = strlen(input);
    for (size_t i = 0; i < len - 1; i++)
    {
        this->push_back(input[i]);
    }
    return *this;
}

 String& String::operator += (const String& input)
{
    for (size_t i = 0; i < input.size_(); i++)
    {
        this->push_back(input[i]);
    }
    return *this;
}

 String& String::operator += (const char* input)
{
    size_t len = strlen(input);
    for (size_t i = 0; i < len; i++)
    {
        this->push_back(input[i]);
    }
    return *this;
}

//COMPARE
 bool String::operator ==(const String& other)
{
    if (size != other.size)
    {
        return false;
    }
    for (size_t i = 0; i < size; i++)
    {
        if (str[i] != other.str[i])
        {
            return false;
        }
    }
    return true;
}

 bool String::operator !=(const String& other)
{
    return !(this->operator==(other));
}



//SEARCH
 size_t String::find(const char* s)
{
    for (int i = 0; i < size; i++) {
        bool found = true;
        for (int j = 0; j < strlen(s); j++) {
            if (str[i + j] != s[j])
                found = false;
        }

        if (found)
            return i;
    }
    return std::string::npos;

}

//NON-MEMBER FUNCTIONS
std::ostream& operator << (std::ostream& stream, const String& s)
{
    stream << s.str;
    return stream;
}

std::istream& operator >> (std::istream& in, String& s)
{
    s.clear();
    char temp_symb;
    for (int i = 0; ; i++)
    {
        temp_symb = getchar();
        if (temp_symb == '\n')
        {
            break;
        }
        else
        {
            s.push_back(temp_symb);
        }
    }
    return in;
}

//DESTRUCTOR
 String::~String()
{
    clear();
}



extern "C" STRINGCLASS_DLL_EXPORT String* CreateObject()
{
    return new String;
}
