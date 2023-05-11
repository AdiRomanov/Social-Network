//
// Created by roman on 5/14/2022.
//

#ifndef PROIECTSDA_USER_H
#define PROIECTSDA_USER_H
#include <string>
#include <iostream>

using namespace std;

class User {
private:
    string firstName, lastName, email;
    int id, age;
public:
    User();

    User(const User &user);
    ~User();
    User(string args, char sep);User(int id, string firstName, string lastName, string email, int age);
    void loadFromString(string args, char sep);
    int getId();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    void setId(int newId);
    void setFirstName(string newFirstName);
    void setLastName(string newLastName);
    void setEmail(string newEmail);
    void setAge(int newAge);
    User& operator = (const User &user);
    bool operator == (const User &user);
    friend ostream& operator << (ostream& out, const User &user);
    string toStringDelimiter(char sep);
};


#endif //PROIECTSDA_USER_H
