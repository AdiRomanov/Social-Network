
#ifndef PROIECTSDA_REPOSITORYFILE_H
#define PROIECTSDA_REPOSITORYFILE_H
#include <string>
#include <fstream>
#include "../Checking/MyException.h"
#include "../Domain/List.h"

using namespace std;

/*Clasa de baza ce utilizeaza lista definita ca TAD1
 Acesta este un repository generic*/
template <class T>
class RepositoryFile{
protected:
    string filename;
    List<T> elements;
public:
    RepositoryFile() = default;
    explicit RepositoryFile(const string& filename);
    virtual void saveToFile() = 0;
    virtual void loadFromFile() = 0;
    ~RepositoryFile() = default;
    void add(T& elem);
    void del(T& elem);
    bool find(T& elem);
    void update(T& elem, T& newElem);
    List<T> getAll();
    int size();

};

template<class T>
RepositoryFile<T>::RepositoryFile(const string &filename) {
    this->filename = filename;
}

/*Adauga un element in lista si apoi o salveaza in fisier*/
template<class T>
void RepositoryFile<T>::add(T &elem) {
    this->elements.push_back(elem);
    this->saveToFile();
}

/*Verifica daca un element dat se afla in lista*/
template<class T>
bool RepositoryFile<T>::find(T &elem) {
    for(int i=0; i<this->elements.size(); i++) {
        if (elements[i] == elem) {
            return true;
        }
    }
    throw MyException("Searched entity was not found!");
}

/*Sterge un element din lista daca acesta exista*/
template<class T>
void RepositoryFile<T>::del(T &elem) {
    bool check = false;
    for(int i=0; i<this->elements.size(); i++) {
        if (elements[i] == elem) {
             this->elements.erase(elem);
             check = true;
        }
    }
    if(!check)
        throw MyException("Searched entity was not found!");
    this->saveToFile();
}

/*Actualizeaza un element din lista*/
template<class T>
void RepositoryFile<T>::update(T &elem, T &newElem) {
    bool check = false;
    for(int i=0; i<this->elements.size(); i++) {
        if (elements[i] == elem) {
            this->elements.update(elem, newElem);
            check = true;
        }
    }
    if(!check)
        throw MyException("Searched entity was not found!");
    this->saveToFile();
}

/*Returneaza toate elementele listei*/
template<class T>
List<T> RepositoryFile<T>::getAll() {
    return this->elements;
}

/*Returneaza numarul de elemente al listei*/
template<class T>
int RepositoryFile<T>::size() {
    return this->elements.size();
}


#endif //PROIECTSDA_REPOSITORYFILE_H
