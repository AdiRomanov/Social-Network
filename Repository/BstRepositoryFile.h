//
// Created by roman on 5/18/2022.
//

#ifndef PROIECTSDA_BSTREPOSITORYFILE_H
#define PROIECTSDA_BSTREPOSITORYFILE_H
#include "../Domain/BST.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


/*Repository generic pentru folosirea arborelui binar de cautare*/
template <class T>
class BstRepositoryFile{
private:
    string filename;
    BST<T>* root;
public:
    BstRepositoryFile();
    explicit BstRepositoryFile(const string& filename);
    void saveToFile();
    void loadFromFile();
    ~BstRepositoryFile();
    void add(T& elem);
    bool find(T& elem);
    void update(T& elem, T& newElem);
    void del(T& elem);
    vector<T> getAll();
};

template<class T>
BstRepositoryFile<T>::BstRepositoryFile() {

}

template<class T>
BstRepositoryFile<T>::BstRepositoryFile(const string &filename) {
    this->filename = filename;

    this->loadFromFile();
}


/*Salveaza toate nodurile intr-un container de tip vector, dupa le insereaza intr-un fisier dat*/
template<class T>
void BstRepositoryFile<T>::saveToFile()
{

    ofstream f(this->filename);

    vector<T> nodesData;
    nodesData.clear();
    root->inOrder(nodesData, root);
    //cout << nodesData.size() << endl;
    //cout << root->numberOfNodes() << endl;
    for(auto item: nodesData)
    {
        f << item.toStringDelimiter(',') << endl;
    }

    f.close();
}


/*Incarca in memorie toate obiectele dintr-un fisier dat*/
template<class T>
void BstRepositoryFile<T>::loadFromFile()
{
    bool ok = true;
    string line;
    ifstream f(this->filename);
    while (std::getline(f, line)) {
        T ob(line, ',');
        if(ok) {root = new BST<T>(ob); ok = false;}
        else root->Insert(ob);
    }

}

/*Adauga un element, pe urma este salvat in fisierul dat*/
template<class T>
void BstRepositoryFile<T>::add(T &elem) {
    root->Insert(elem);

    this->saveToFile();
}

/*Verifica daca un obiect dat se afla in arbore*/
template<class T>
bool BstRepositoryFile<T>::find(T &elem) {
    if(root->Search(elem)) return true;
    else return false;
}

template<class T>
BstRepositoryFile<T>::~BstRepositoryFile() {
    delete root;
}

/*Actualizeaza un element din arbore, daca acesta exista*/
template<class T>
void BstRepositoryFile<T>::update(T &elem, T &newElem) {
    root->Update(elem, newElem);

    this->saveToFile();
}

/*Stocheaza toate obiectele din noduri si pe urma le returneaza*/
template<class T>
vector<T> BstRepositoryFile<T>::getAll() {
    vector<T> nodesData;
    nodesData.clear();

    root->inOrder(nodesData, root);
    return nodesData;
}

/*Sterge un element din arbore*/
template<class T>
void BstRepositoryFile<T>::del(T &elem) {
    root->Delete(root,elem);
    saveToFile();
}


#endif //PROIECTSDA_BSTREPOSITORYFILE_H
