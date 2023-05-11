//
// Created by roman on 5/21/2022.
//

#ifndef PROIECTSDA_VALIDATORUSER_H
#define PROIECTSDA_VALIDATORUSER_H
#include <string>
#include "../Domain/User.h"

using namespace std;


class UserValidator{
private:
    int nrErrors;
    string message;
public:
    UserValidator(){
        this->nrErrors = 0;
        this->message = "";
    }
    int validate(User& user){

        if(user.getId() < 1)
        {
            this->nrErrors++;
            this->message += "Invalid id! ";
        }

        if(user.getFirstName() == "")
        {
            this->nrErrors++;
            this->message += "Invalid first name! ";
        }

        if(user.getLastName() == "")
        {
            this->nrErrors++;
            this->message += "Invalid last name! ";
        }

        if(user.getAge() < 1)
        {
            this->nrErrors++;
            this->message += "Invalid age! ";
        }

        if(user.getEmail() == "")
        {
            this->nrErrors++;
            this->message += "Invalid email! ";
        }
        return this->nrErrors;
    }

    string toString(){
        return this->message;
    }
};

#endif //PROIECTSDA_VALIDATORUSER_H
