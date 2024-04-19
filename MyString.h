# ifndef MYSTRING_H
# define MYSTRING_H

#include <iostream>
class MyString{
    private:
        char* str;
        int len;
        int cap;

    public:
        //constructors
        MyString() : str(new char[1]{'\0'}), len(0), cap(0) {}
        
        MyString(const MyString& string){ //copying from another string
            this->len = string.len;
            this->cap = string.cap;
            this->str = new char[cap+1];
            for(int i = 0; i < cap; i++){
                this->str[i] = string.str[i];
            }
        }
        MyString(const char string[]){ //copying from a c-string (char array)
            len = 0;
            while(string[this->len] != '\0'){
                len++;
            }
            cap = len;
            str = new char[cap+1];

            for(int i = 0; i < len; i++){
                str[i] = string[i];
            }

            str[cap] = '\0';

        }
        
        //functions
        void resize (int n);
        int capacity() const {return cap;}
        int size() const {return len;}
        int length() const {return len;}
        const char* data() const {return str;}
        bool empty() const {return (len==0);}
        const char& front() const {return str[0];}
        const char& at (int pos) const;
        void clear();
        int find (const MyString& substr, int pos = 0) const;

        //operators 
        MyString& operator= (const MyString& rhs);
        MyString MyString::operator+=(const MyString& rhs);
        bool operator==(const MyString& rhs) const;
        friend MyString operator+(const MyString& lhs, const MyString& rhs);
        friend std::ostream& operator<<(std::ostream& os, const MyString& myStr);


        //destructor
        ~MyString(){
            delete[] str;
        }

};









#endif