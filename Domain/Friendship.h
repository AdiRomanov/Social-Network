//
// Created by roman on 5/20/2022.
//

#ifndef PROIECTSDA_FRIENDSHIP_H
#define PROIECTSDA_FRIENDSHIP_H
#include <string>
#include <iostream>

using namespace std;

class Friendship {
private:
    int id, idUser1, idUser2;
    bool areFriends;
public:
    Friendship();
    Friendship(int id, int idUser1, int idUser2, bool areFriends);
    Friendship(const Friendship& friendship);
    Friendship(string args, char sep);
    ~Friendship();
    int getId();
    int getIdUser1();
    int getIdUser2();
    bool getAreFriends();
    void setId(int newId);
    void setIdUser1(int newIdUser1);
    void setIdUser2(int newIdUser2);
    void setAreFriends(bool newAreFirends);
    void loadFromString(string args, char sep);
    string toStringDelimiter(char sep);
    Friendship& operator = (const Friendship& friendship);
    bool operator == (const Friendship& friendship);
    bool operator <= (const Friendship& friendship);
    bool operator < (const Friendship& friendship);
    bool operator > (const Friendship& friendship);
    friend ostream& operator << (ostream& out, Friendship& friendship);
};


#endif //PROIECTSDA_FRIENDSHIP_H
