//
// Created by roman on 5/18/2022.
//

#ifndef PROIECTSDA_MESSAGE_H
#define PROIECTSDA_MESSAGE_H
#include <string>
#include "../Checking/MyException.h"

using namespace std;

class Message {
private:
    int id, idSender, idReceiver;
    string text;
public:
    Message();
    Message(int id, int idSender, int idReceiver, string text);
    Message(const Message& message);
    ~Message();
    Message(string args, char sep);
    int getId();
    int getIdSender();
    int getIdReceiver();
    string getText();
    void setId(int newId);
    void setIdSender(int newIdSender);
    void setIdReceiver(int newIdReceiver);
    void setText(string newText);
    Message& operator = (Message message);
    bool operator <= (Message &message);
    bool operator == (Message &message);
    friend ostream& operator << (ostream& out, const Message &message);
    void loadFromString(string args, char sep);
    string toStringDelimiter(char sep);
};


#endif //PROIECTSDA_MESSAGE_H
