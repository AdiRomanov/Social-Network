#ifndef PROIECTSDA_REPOSITORYFILETXT_H
#define PROIECTSDA_REPOSITORYFILETXT_H
#include "RepositoryFile.h"

/*NU este folosit in proiect*/
template <class T> class
RepositoryFileTXT : public RepositoryFile<T>
{
public:
    RepositoryFileTXT() = default;
    explicit RepositoryFileTXT(string filename);
    void saveToFile();
    void loadFromFile();
    ~RepositoryFileTXT() = default;
};


template<class T>
RepositoryFileTXT<T>::RepositoryFileTXT(string filename):RepositoryFile<T>(filename){
    this->loadFromFile();
}

template<class T>
void RepositoryFileTXT<T>::saveToFile()
{

    ofstream f(this->filename);
    for (T crt : this->elements) {
        f << crt.toStringDelimiter(' ') << endl;
    }
    f.close();
}

template<class T>
void RepositoryFileTXT<T>::loadFromFile()
{
    string line;
    ifstream f(this->filename);
    while (std::getline(f, line)) {
        try{
            T ob(line, ' ');
            this->elements.push_back(ob);
        }
        catch(exception &ex){
            // cout << "some pb: " + ex.what() << endl;

            throw ex;
        }
    }

}
#endif //PROIECTSDA_REPOSITORYFILETXT_H
