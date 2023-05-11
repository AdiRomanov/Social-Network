#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <string>

using namespace std;

class MyException{
private:
    string message;
public:
    explicit MyException(string message) : message(message){
    }
    string getMessage(){
        return message;
    }
};
#endif