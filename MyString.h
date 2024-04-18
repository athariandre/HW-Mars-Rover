# ifndef MYSTRING_H
# define MYSTRING_H

class MyString{
    private:
        char* str;
        size_t len;
        size_t cap;

    public:
        //constructors
        MyString(){ //default constructor
            cap = 0;
            str = new char[1];
            str[0] = '\0';
            len = 0;
        }
        MyString(const MyString& string){ //copying from another string
            len = string.len;
            cap = string.cap;
            str = new char[cap+1];
            for(size_t i = 0; i < cap; i++){
                str[i] = string.str[i];
            }
        }
        MyString(const char string[]){ //copying from a c-string (char array)
            len = 0;
            while(string[this->len] != '\0'){
                len++;
            }
            cap = len;
            str = new char[cap+1];

            for(size_t i = 0; i < len; i++){
                str[i] = string[i];
            }

            str[cap] = '\0';

        }
        
        //functions
        void resize (size_t n);
        size_t capacity() const {return cap;}
        size_t size() const {return len;}
        size_t length() const {return len;}
        const char* data() const {return str;}
        bool empty() const {return (len==0);}
        const char& front() const {return str[0];}
        const char& at (size_t pos) const;
        void clear();
        size_t find (const MyString& substr, size_t pos = 0) const;

        //operators 
        MyString& operator= (const MyString& rhs);
        friend MyString operator+=(MyString& lhs, const MyString& rhs);
        bool operator==(const MyString& rhs) const;
        friend MyString operator+(const MyString& lhs, const MyString& rhs);
        friend std::ostream& operator<<(std::ostream& os, const MyString& myStr);


        //destructor
        ~MyString(){
            delete[] this->str;
        }

};









#endif