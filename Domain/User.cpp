//
// Created by roman on 5/14/2022.
//
#include <sstream>
#include <vector>
#include "../Checking/MyException.h"
#include "User.h"

/*Constructori si deconstructor*/
User::User() {
    this->id = 0;
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = 0;
}

User::User(int id, string firstName, string lastName, string email, int age) {
    this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
}

User::User(const User &user) {
    this->id = user.id;
    this->firstName = user.firstName;
    this->lastName = user.lastName;
    this->email = user.email;
    this->age = user.age;
}

User::~User() {
    this->id = 1;
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = 0;
}

/*Getteri si setteri*/
int User::getId() {
    return this->id;
}

string User::getFirstName() {
    return this->firstName;
}

string User::getLastName() {
    return this->lastName;
}

string User::getEmail() {
    return this->email;
}

int User::getAge() {
    return this->age;
}

void User::setId(int newId) {
    this->id = newId;
}

void User::setFirstName(string newFirstName) {
    this->firstName = newFirstName;
}

void User::setLastName(string newLastName) {
    this->lastName = newLastName;
}

void User::setEmail(string newEmail) {
    this->email = newEmail;
}

void User::setAge(int newAge) {
    this->age = newAge;
}

/*Supraincarcarea operatorilor = , == , << */
User& User::operator=(const User &user) {
    if (this != &user)
    {
        this->id = user.id;
        this->firstName = user.firstName;
        this->lastName = user.lastName;
        this->email = user.email;
        this->age = user.age;
    }
    return * this;
}

bool User::operator==(const User &user) {
    if(this->firstName == user.firstName and this->lastName == user.lastName and
        this->email == user.email and this->age == user.age and this->id == user.id)
            {return true;}
    return false;
}

ostream &operator<<(ostream &out, const User &user) {
    out << "Id:" << user.id << std::endl << "First Name: " << user.firstName << std::endl <<
    "Last Name: " << user.lastName << std::endl <<
    "Email: " << user.email << std::endl <<
    "Age: " << user.age << std::endl << std::endl;

    return out;
}
/*Returneaza un string format din argumentele obiectului printr-un separator dat*/
string User::toStringDelimiter(char sep) {
        return to_string(this->id) + sep + this->firstName + sep + this->lastName + sep + this->email + sep + to_string(this->age);
}

User::User(string args, char sep) {
    this->loadFromString(args, sep);
}

/*Imparte un string in argumentele necesare obiectului*/
void User::loadFromString(string args, char sep) {
    vector<string> elements;
    stringstream ss (args);
    string item;
    while (getline (ss, item, sep)) {
        elements.push_back (item);
    }

    if (elements.size() == 5){

        stringstream c(elements[0]);
        c >> this->id;
        this->firstName = elements[1];
        this->lastName = elements[2];
        this->email = elements[3];
        stringstream i(elements[4]);
        i >> this->age;

    }
    else{
        throw MyException("Invalid number of arguments!");
    }
}


