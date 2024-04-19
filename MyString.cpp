# include <iostream>
# include <stdexcept>
# include "MyString.h"

using std::cout, std::endl;


void MyString::resize(int n){ //double free occuring here
    if(n < len){
        char* temp = new char[n+1];
        for(int i = 0; i < n; i++){
            temp[i] = str[i];
        }
        temp[n] = '\0'; //set null-terminator
        delete[] str; //clear old arr memory (to prevent leaks)
        str = temp; //update arr
        len = n;
        cap = n+1;
        return;
    }
    else{
        char* temp = new char[n+1];
        for(int i = 0; i < len; i++){
            temp[i] = str[i]; //copy every item to 
        }
        temp[n] = '\0'; //set null-terminator
        delete[] str; //clear old arr memory (to prevent leaks)
        str = temp; //update arr
        len = n;
        cap = n+1;
        return;
    }
}

const char& MyString::at (int pos) const{
    if(pos >= len){
        throw std::invalid_argument("Attempted access to an out-of-bound index (index " + std::to_string(pos) + " in string of length " + std::to_string(len));
    }
    else{
        return str[pos];
    }
}

void MyString::clear(){
    delete[] str;
    str = new char[1];
    str[0] = '\0';
    len = 0;
    cap = 0;
}

int MyString::find (const MyString& substr, int pos) const{
    int search_len = substr.size();
    bool match = false;
    for(int i = pos; i <= (len - search_len); i++){
        match = true;
        for(int j = 0; j < search_len; j++){
            if(str[i+j] != substr.data()[j]){
                match = false;
                break;
            }
        }
        if(match){
            return i;
        }
    }
    return (int)-1;
}

MyString& MyString::operator=(const MyString& rhs){
    str = rhs.str;
    len = rhs.len;
    cap = rhs.cap;
    
    return *this;
}

MyString operator+=(MyString& lhs, const MyString& rhs){
    int llen = lhs.len;
    int rlen = rhs.len;
    MyString newstr = MyString(lhs); //copy lhs to newstr
    newstr.resize(llen+rlen+1); //resize newstr to accomodate for rhs
    int cnt = 0;
    for(int i = llen; i < llen; i++){
        newstr.str[i] = rhs.at(cnt); //add rhs
        cnt++;
    }
    lhs = newstr;
    return lhs;
}

bool MyString::operator==(const MyString& rhs) const{
    int llen = len;
    int rlen = rhs.len;
    if(llen != rlen){
        return false;
    }
    for(int i = 0; i < len; i++){
        if(str[i] != rhs.data()[i]){
            return false;
        }
    }
    return true;
}

MyString operator+(const MyString& lhs, const MyString& rhs){
    int llen = lhs.len;
    int rlen = rhs.len;
    MyString newstr = MyString(lhs); //copy lhs to newstr
    newstr.resize(llen+rlen); //resize newstr to accomodate for rhs
    int cnt = 0;
    for(int i = llen; i < llen; i++){
        newstr.str[i] = rhs.at(cnt); //add rhs
        cnt++;
    }
    return newstr;
}

std::ostream& operator<<(std::ostream& os, const MyString& myStr) { 
    os << myStr.data();
    return os;
}