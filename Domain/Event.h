//
// Created by roman on 5/20/2022.
//

#ifndef PROIECTSDA_EVENT_H
#define PROIECTSDA_EVENT_H
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include "../Checking/MyException.h"

using namespace std;

class Event {
private:
    int id;
    string name, text;
public:
    Event();
    Event(int id, string name, string text);
    Event(const Event& event);
    Event(string args, char sep);
    ~Event();
    void loadFromString(string args, char sep);
    string toStringDelimiter(char sep);
    int getId();
    string getName();
    string getText();
    void setId(int newId);
    void setName(string newName);
    void setText(string newText);
    Event& operator = (const Event& event);
    bool operator == (const Event& event);
    friend ostream& operator << (ostream& out, const Event& event);
};


#endif //PROIECTSDA_EVENT_H
