# include <iostream>
# include "MyString.h"

using std::cout, std::endl;


void MyString::resize(size_t n){
    if(n < len){
        char* temp = new char[n+1];
        for(size_t i = 0; i < n; i++){
            temp[i] = str[i];
        }
        temp[n] = '\0'; //set null-terminator
        delete[] str; //clear old arr memory (to prevent leaks)
        str = temp; //update arr
        delete[] temp; //delete temp arr
        temp = nullptr; //prevent hanging pointer (not neccessarily needed, temp "despawns" after function definition left)
        return;
    }
    else{
        char* temp = new char[n+1];
        for(size_t i = 0; i < len; i++){
            temp[i] = str[i]; //copy every item to 
        }
        temp[n] = '\0'; //set null-terminator
        delete[] str; //clear old arr memory (to prevent leaks)
        str = temp; //update arr
        delete[] temp; //delete temp arr
        temp = nullptr; //prevent hanging pointer (not necessarily needed, temp "despawns" after function definition left)
        return;
    }
}

const char& MyString::at (size_t pos) const{
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

size_t MyString::find (const MyString& substr, size_t pos) const{
    size_t search_len = substr.size();
    bool match = false;
    for(size_t i = pos; i <= (len - search_len); i++){
        match = true;
        for(size_t j = 0; j < search_len; j++){
            if(str[i+j] != substr.data()[j]){
                match = false;
                break;
            }
        }
        if(match){
            return i;
        }
    }
    return (size_t)-1;
}

MyString& MyString::operator=(const MyString& rhs){
    str = rhs.str;
    len = rhs.len;
    cap = rhs.cap;
    
    return *this;
}

MyString operator+=(MyString& lhs, const MyString& rhs){
    size_t llen = lhs.len;
    size_t rlen = rhs.len;
    MyString newstr = MyString(lhs); //copy lhs to newstr
    newstr.resize(llen+rlen); //resize newstr to accomodate for rhs
    size_t cnt = 0;
    for(int i = llen; i < llen; i++){
        newstr.str[i] = rhs.at(cnt); //add rhs
        cnt++;
    }
    lhs = newstr;
    return lhs;
}

bool MyString::operator==(const MyString& rhs) const{
    size_t llen = len;
    size_t rlen = rhs.len;
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
    size_t llen = lhs.len;
    size_t rlen = rhs.len;
    MyString newstr = MyString(lhs); //copy lhs to newstr
    newstr.resize(llen+rlen); //resize newstr to accomodate for rhs
    size_t cnt = 0;
    for(int i = llen; i < llen; i++){
        newstr.str[i] = rhs.at(cnt); //add rhs
        cnt++;
    }
    return newstr;
}

