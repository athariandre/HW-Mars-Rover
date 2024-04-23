# include <iostream>
# include <stdexcept>
# include "MyString.h"

using std::cout, std::endl;


void MyString::resize(int n){ //REMAKE
    int smaller_len = n;
    if(len < smaller_len){
        smaller_len = len;
    }

    char* temp = new char[n+1];
    for(int i = 0; i < smaller_len; i++){
        temp[i] = str[i];
    }
     
    temp[n] = '\0'; //set null-terminator
    len = n;
    cap = n+1;
    delete[] str; //clear old arr memory (to prevent leaks)
    str = temp; //update arr
}

const char& MyString::at (int pos) const{
    if(pos >= len){
        throw std::out_of_range("Attempted access to an out-of-bound index (index " + std::to_string(pos) + " in string of length " + std::to_string(len));
    }
    else{
        return str[pos];
    }
}

void MyString::clear(){ //REMAKE
    delete[] str;
    str = new char[1];
    str[0] = '\0';
    len = 0;
    cap = 1;
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
    resize(rhs.size());

    for(int i = 0; i < rhs.size(); i++){
        str[i] = rhs.at(i);
    }
    
    return *this;
}

MyString operator+=(MyString& lhs, const MyString& rhs){ //remake
    int llen = lhs.len;
    int rlen = rhs.len; 
    lhs.resize(lhs.len+rhs.len); //resize newstr to accomodate for rhs
    int cnt = 0;
    for(int i = llen; i < lhs.size(); i++){
        lhs.str[i] = rhs.str[cnt]; //add rhs
        cnt++;
    }
    lhs.str[lhs.size()] = '\0';
    return lhs;
}

bool operator==(const MyString& lhs, const MyString& rhs){
    int llen = lhs.len;
    int rlen = rhs.len;
    if(llen != rlen){
        return false;
    }
    for(int i = 0; i < lhs.size(); i++){
        if(lhs.at(i) != rhs.at(i)){
            return false;
        }
    }
    return true;
}

MyString operator+(const MyString& lhs, const MyString& rhs){
    MyString newstr; //copy lhs to newstr
    newstr.len = lhs.len + rhs.len;
    newstr.cap = lhs.len + rhs.len + 1;

    for(int i = 0; i < lhs.len; i++){
        newstr.str[i] = lhs.at(i); //add rhs
    }

    int cnt = 0;
    for(int i = lhs.len; i < newstr.len; i++){
        newstr.str[i] = rhs.at(cnt);
        cnt++;
    }

    newstr.str[newstr.len] = '\0';
    return newstr;
}

std::ostream& operator<<(std::ostream& os, const MyString& myStr) { 
    for(int i = 0; i < myStr.len; i++){
        os << myStr.at(i);
    }
    return os;
}