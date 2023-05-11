//
// Created by roman on 5/21/2022.
//

#ifndef PROIECTSDA_VALIDATOREVENT_H
#define PROIECTSDA_VALIDATOREVENT_H
#include <string>
#include "../Domain/Event.h"

using namespace std;

class EventValidator{
private:
    int nrErrors;
    string message;
public:
    EventValidator(){
        this->nrErrors = 0;
        this->message = "";
    }
    int validate(Event& event){

        if(event.getId() < 1){
            this->nrErrors++;
            this->message += "Invalid id! ";
        }

        if(event.getName() == "")
        {
            this->nrErrors++;
            this->message += "Invalid name! ";
        }

        if(event.getText() == ""){
            this->nrErrors++;
            this->message += "Invalid text! ";
        }

        return this->nrErrors;
    }

    string toString(){
        return this->message;
    }
};


#endif //PROIECTSDA_VALIDATOREVENT_H
