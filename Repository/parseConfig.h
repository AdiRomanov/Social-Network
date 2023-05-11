// see https://rapidjson.org/index.html

#include "../rapidjson/filereadstream.h"
#include "../rapidjson/document.h"
#include "../rapidjson/stringbuffer.h"
#include "../rapidjson/prettywriter.h"
#include <cstring>

#include "RepositoryFileTXT.h"
#include "RepositoryFileCSV.h"
#include "../Domain/User.h"
#include <iostream>
using namespace rapidjson;

/*Determina extensia fisierului folosit si creeaza o variabila
 * repository de tipul necesar*/
void readConfigFile(char* configFileName, RepositoryFile<User>* &repoUser){
    FILE* fp = fopen(configFileName, "rb");
    char readBuffer[65536];
    FileReadStream is(fp, readBuffer, sizeof(readBuffer));

    Document d;
    d.ParseStream(is);

    //std::cout << d["fileType"].GetString() << endl;
    int val = d["no"].GetInt();

   /* if (strcmp(d["fileType"].GetString(), "TXT") == 0) {
        repoUser = new RepositoryFileTXT<User>(d["userFileName"].GetString());
    } else {*/
        if (strcmp(d["fileType"].GetString(), "CSV") == 0) {
            repoUser = new RepositoryFileCSV<User>(d["userFileName"].GetString());
        } else {
            //...
        //}
    }

    fclose(fp);
}