//
// Created by roman on 5/18/2022.
//

#include "Message.h"
#include <vector>
#include <sstream>
/*Constructori si deconstructor*/
Message::Message() {
    this->id = 0;
    this->idSender = 0;
    this->idReceiver = 0;
    this->text = "";
}

Message::Message(int id, int idSender, int idReceiver, string text) {
    this->id = id;
    this->idSender = idSender;
    this->idReceiver = idReceiver;
    this->text = text;
}

Message::Message(const Message &message) {
    this->id = message.id;
    this->idSender = message.idSender;
    this->idReceiver = message.idReceiver;
    this->text = message.text;
}

Message::~Message() {
    this->id = 0;
    this->idSender = 0;
    this->idReceiver = 0;
    this->text = "";
}

Message::Message(string args, char sep) {
    this->loadFromString(args, sep);
}
/*Separa stringul in argumentele obiectului*/
void Message::loadFromString(string args, char sep) {
    vector<string> elements;
    stringstream ss (args);
    string item;
    while (getline (ss, item, sep)) {
        elements.push_back (item);
    }

    if (elements.size() == 4){

        stringstream c(elements[0]);
        c >> this->id;
        stringstream d(elements[1]);
        d >> this->idSender;
        stringstream e(elements[2]);
        e >> this->idReceiver;
        this->text = elements[3];

    }
    else{
        throw MyException("Invalid number of arguments!");
    }
}
/*Creeaza un string cu argumentele obiectului sperata print-un separator dat*/
string Message::toStringDelimiter(char sep) {
    return to_string(this->id) + sep + to_string(this->idSender) + sep + to_string(this->idReceiver) + sep + this->text;
}

/*Getteri si setteri*/
int Message::getId() {
    return this->id;
}

int Message::getIdSender() {
    return this->idSender;
}

int Message::getIdReceiver() {
    return this->idReceiver;
}

string Message::getText() {
    return this->text;
}

void Message::setId(int newId) {
    this->id = newId;
}

void Message::setIdSender(int newIdSender) {
    this->idSender = newIdSender;
}

void Message::setIdReceiver(int newIdReceiver) {
    this->idReceiver = newIdReceiver;
}

void Message::setText(string newText) {
    this->text = newText;
}

/*Supraincarcarea operatorilor = , <= , == , <<*/
Message& Message::operator=(Message message) {
    if (this != &message)
    {
        this->id = message.id;
        this->idSender = message.idSender;
        this->idReceiver = message.idReceiver;
        this->text = message.text;
    }
    return * this;
}

bool Message::operator<=(Message &message1){
    if (this->id <= message1.id) return true;
    else return false;
}

bool Message::operator==(Message &message) {
    if(this->id == message.id and this->idSender == message.idSender and this->idReceiver == message.idReceiver
    and this->text == message.text)
        return true;
    return false;
}

ostream &operator<<(ostream &out, const Message &message) {
    out << "Id:" << message.id << " IdSender:" << message.idSender << " IdReveiver:" << message.idReceiver << " Text:" << message.text << endl;
    return out;
}

