//
// Created by roman on 5/20/2022.
//

#include "EventService.h"
/*CRUD, validare de date*/
EventService::EventService(RepositoryFile<Event> *eventRepositoryFile, EventValidator eventValidator) {
    this->eventRepositoryFile = eventRepositoryFile;
    this->eventValidator = eventValidator;
}

void EventService::addEvent(int id, string name, string text) {
    Event event(id, name, text);
    if(this->eventValidator.validate(event) > 0)
        throw(MyException(this->eventValidator.toString()));
    this->eventRepositoryFile->add(event);
}

bool EventService::findEvent(int id, string name, string text) {
    Event event(id, name, text);
    if(this->eventValidator.validate(event) > 0)
        throw(MyException(this->eventValidator.toString()));
    return this->eventRepositoryFile->find(event);
}

void EventService::deleteEvent(int id, string name, string text) {
    Event event(id, name, text);
    if(this->eventValidator.validate(event) > 0)
        throw(MyException(this->eventValidator.toString()));
    this->eventRepositoryFile->del(event);
}

void EventService::updateEvent(int id, string name, string text, int newId, string newName, string newText) {
    Event event(id, name, text);
    Event newEvent(newId, newName, newText);
    if(this->eventValidator.validate(event) > 0)
        throw(MyException(this->eventValidator.toString()));
    if(this->eventValidator.validate(newEvent) > 0)
        throw(MyException(this->eventValidator.toString()));
    this->eventRepositoryFile->update(event, newEvent);
}

/*Returneaza toate evenimentele*/
List<Event> EventService::getAllEvents() {
    return this->eventRepositoryFile->getAll();
}

/*Returneaza numarul de evenimente*/
int EventService::numberOfEvents() {
    return this->eventRepositoryFile->size();
}
