//
// Created by roman on 5/20/2022.
//

#include "Friendship.h"
#include "../Checking/MyException.h"
#include <vector>
#include <sstream>
/*Constructori*/
Friendship::Friendship() {
    this->id = 0;
    this->idUser1 = 0;
    this->idUser2 = 0;
    this->areFriends = false;
}

Friendship::Friendship(int id, int idUser1, int idUser2, bool areFriends) {
    this->id = id;
    this->idUser1= idUser1;
    this->idUser2 = idUser2;
    this->areFriends = areFriends;
}

Friendship::Friendship(const Friendship &friendship) {
    this->id = friendship.id;
    this->idUser1 = friendship.idUser1;
    this->idUser2 = friendship.idUser2;
    this->areFriends = friendship.areFriends;
}

Friendship::Friendship(string args, char sep) {
    this->loadFromString(args, sep);
}
/*Deconstructor (se distrug automat oricum dar e o practica buna)*/
Friendship::~Friendship() {
    this->id = 0;
    this->idUser1 = 0;
    this->idUser2 = 0;
    this->areFriends = false;
}
/*Getteri , Setteri*/
int Friendship::getId() {
    return this->id;
}

int Friendship::getIdUser1() {
    return this->idUser1;
}

int Friendship::getIdUser2() {
    return this->idUser2;
}

bool Friendship::getAreFriends() {
    return this->areFriends;
}

void Friendship::setId(int newId) {
    this->id = newId;
}

void Friendship::setIdUser1(int newIdUser1) {
    this->idUser1 = newIdUser1;
}

void Friendship::setIdUser2(int newIdUser2) {
    this->idUser2 = newIdUser2;
}

void Friendship::setAreFriends(bool newAreFirends) {
    this->areFriends = newAreFirends;
}
/*Transforma un string in argumentele necesare obiectului*/
void Friendship::loadFromString(string args, char sep) {
    vector<string> elements;
    stringstream ss (args);
    string item;
    while (getline (ss, item, sep)) {
        elements.push_back (item);
    }

    if (elements.size() == 4){

        stringstream a(elements[0]);
        a >> this->id;
        stringstream b(elements[1]);
        b >> this->idUser1;
        stringstream c(elements[2]);
        c >> this->idUser2;
        stringstream d(elements[3]);
        d >> this->areFriends;


    }
    else{
        throw MyException("Invalid number of arguments!");
    }
}

/*Delimiteaza argumentele obiectului printr-un separator dat*/
string Friendship::toStringDelimiter(char sep) {
    return to_string(this->id) + sep + to_string(this->idUser1) + sep + to_string(this->idUser2) + sep + to_string(this->areFriends);
}

/*Supraincarcare operatori = , ==, << , <= , < , >*/
Friendship &Friendship::operator=(const Friendship &friendship) {
    if(this != &friendship)
    {
        this->id = friendship.id;
        this->idUser1 = friendship.idUser1;
        this->idUser2 = friendship.idUser2;
        this->areFriends = friendship.areFriends;
    }
    return * this;
}

bool Friendship::operator==(const Friendship &friendship) {
    if(this->id == friendship.id and this->idUser1 == friendship.idUser1 and
    this->idUser2 == friendship.idUser2 and this->areFriends == friendship.areFriends)
        return true;
    return false;
}

ostream &operator<<(ostream &out, Friendship &friendship) {
    out << "Id:" << friendship.id << endl;
    out << "IdUser1:" << friendship.idUser1 << endl;
    out << "IdUser2:" << friendship.idUser2 << endl;
    out << "AreFriends:" << friendship.areFriends << endl;

    return out;
}

bool Friendship::operator<=(const Friendship &friendship) {
    if(this->id <= friendship.id) return true;
    else return false;
}

bool Friendship::operator<(const Friendship &friendship) {
    if(this->id < friendship.id) return true;
    else return false;
}

bool Friendship::operator>(const Friendship &friendship) {
    if(this->id > friendship.id) return true;
    else return false;
}
