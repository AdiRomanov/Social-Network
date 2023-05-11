//
// Created by roman on 5/20/2022.
//

#include "Event.h"
/*Constructori*/
Event::Event() {
    this->id = 0;
    this->name = "";
    this->text = "";
}

Event::Event(int id, string name, string text) {
    this->id = id;
    this->name = name;
    this->text = text;
}

Event::Event(const Event &event) {
    this->id = event.id;
    this->name = event.name;
    this->text = event.text;
}

Event::Event(string args, char sep) {
    this->loadFromString(args, sep);
}
/*Deconstructor (se distrug automat oricum dar e o practica buna)*/
Event::~Event() {
    this->id = 0;
    this->name = "";
    this->text = "";
}

/*Transforma un string in datele necesare*/
void Event::loadFromString(string args, char sep) {
    vector<string> elements;
    stringstream ss (args);
    string item;
    while (getline (ss, item, sep)) {
        elements.push_back (item);
    }

    if (elements.size() == 3){

        stringstream a(elements[0]);
        a >> this->id;
        this->name = elements[1];
        this->text = elements[2];

    }
    else{
        throw MyException("Invalid number of arguments!");
    }
}
/*Imparte argumentele unui obiect cu un separator dat*/
string Event::toStringDelimiter(char sep) {
    return to_string(this->id) + sep + this->name + sep +this->text;
}
/*getteri , setteri*/
int Event::getId() {
    return this->id;
}

string Event::getName(){
    return this->name;
}

string Event::getText() {
    return this->text;
}

void Event::setId(int newId) {
    this->id = newId;
}

void Event::setName(string newName){
    this->name = newName;
}

void Event::setText(string newText) {
    this->text = newText;
}
/*Supraincarcarea operatoriilor =, ==, <<*/
Event &Event::operator=(const Event &event) {
    if(this != &event)
    {
        this->id = event.id;
        this->name = event.name;
        this->text = event.text;
    }
    return * this;
}

bool Event::operator==(const Event &event) {
    if(this->id == event.id and this->name == event.name and this->text == event.text) return true;
    return false;
}

ostream &operator<<(ostream &out, const Event &event) {
    out << "Id:" << event.id << endl;
    out << "Name:" << event.name << endl;
    out << "Event:" << event.text << endl;
    return out;
}
