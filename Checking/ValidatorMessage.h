#pragma once
#include <string>
#include "../Domain/Message.h"

using namespace std;


class MessageValidator{
private:
    int nrErrors;
    string message;
public:
    MessageValidator(){
        this->nrErrors = 0;
        this->message = "";
    }
    int validate(Message& user){

        if(user.getId() < 1)
        {
            this->nrErrors++;
            this->message += "Invalid id! ";
        }

        if(user.getIdSender() < 1)
        {
            this->nrErrors++;
            this->message += "Invalid sender id! ";
        }

        if(user.getIdReceiver() < 1)
        {
            this->nrErrors++;
            this->message += "Invalid receiver id! ";
        }

        if(user.getText() == "")
        {
            this->nrErrors++;
            this->message += "Invalid text! ";
        }


        return this->nrErrors;
    }

    string toString(){
        return this->message;
    }
};