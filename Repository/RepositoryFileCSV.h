#ifndef PROIECTSDA_REPOSITORYFILECSV_H
#define PROIECTSDA_REPOSITORYFILECSV_H
#include "RepositoryFile.h"

/*Repository ce mosteneste din clasa de baza RepositoryFile
    Acesta este utilizat pentu fisierele cu extensia CSV*/
template <class T>
class RepositoryFileCSV : public RepositoryFile<T>
{

public:
    RepositoryFileCSV() = default;
    explicit RepositoryFileCSV(string filename);
    void saveToFile();
    void loadFromFile();
    ~RepositoryFileCSV() = default;
};


template<class T>
RepositoryFileCSV<T>::RepositoryFileCSV(string filename):RepositoryFile<T>(filename){
    this->loadFromFile();
}

/*Salveaza elementele intr-un fisier cu extensia CSV*/
template<class T>
void RepositoryFileCSV<T>::saveToFile()
{

    ofstream f(this->filename);
    for(int i=0; i<this->elements.size(); i++){
        f << this->elements[i].toStringDelimiter(',') << endl;
    }
    f.close();
}

/*Preia elemnte dintr-un fisier CSV*/
template<class T>
void RepositoryFileCSV<T>::loadFromFile()
{
    string line;
    ifstream f(this->filename);
    while (std::getline(f, line)) {
        T ob(line, ',');
        this->elements.push_back(ob);
    }

}

#endif //PROIECTSDA_REPOSITORYFILECSV_H
