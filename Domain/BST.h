//
// Created by roman on 5/18/2022.
//

#ifndef PROIECTSDA_BST_H
#define PROIECTSDA_BST_H

#include <cstddef>
#include <vector>

using namespace std;
/*
 O clasa ce reprezinta un arbore binar de cautare cu date generice
 */
template <class T>
class BST {
private:
    T data;
public:
    BST* left;
    BST* right;
    BST() = default;
    BST(T data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    ~BST(){
        delete left;
        delete right;
    }

/*    BST* GetNewNode(T data){
        BST* newNode = NULL;
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }*/

/*Functia de insertie: parcurge arborele si creeaza un nod nou in locatia potrivita*/
    BST* Insert(BST* root, T data){
        if(root == NULL){
            root = new BST<T>(data);
        }
        else if(data <= root->data) {
            root->left = Insert(root->left, data);
        }
        else {
            root->right = Insert(root->right, data);
        }
        return root;
    }

    /*A doua functie de insert: pentru usurarea codului*/
    void Insert(T data){
        Insert(this, data);
    }

    /*Parcurge arborele in cautarea unui nod dat*/
    bool Search(BST* root, T data){
        if(root == NULL) return false;
        else if(root->data == data) return true;
        else if(data <= root->data) return Search(root->left, data);
        else return Search(root->right, data);
    }
    /*Usurarea codului*/
    bool Search(T data){
        return Search(this, data);
    }

    /*Parcurge arborele in ordine crescatoare si retine datele intr-un container*/
    void inOrder(vector<T> &nodesData, BST* node){
        if(node != NULL)
        {
            inOrder(nodesData, node->left);
            nodesData.push_back(node->data);
            inOrder(nodesData, node->right);
        }
    }

    /*Functie recursiva pentru a determina numarul de noduri*/
    void countNodes(BST* node, int& numberOfNodes){

        if(node != NULL)
        {
            countNodes( node->left, numberOfNodes);

            countNodes(node->right, numberOfNodes);
            numberOfNodes++;
        }
    }
    int numberOfNodes(){
        int number = 0;
        countNodes(this, number);
        return number;
    }

    /*Modifica un nod din arbore*/
    bool Update(BST* root, T data, T newData){
        if(root == NULL) return false;
        else if(root->data == data) {root->data = newData; return true;}
        else if(data <= root->data) return Update(root->left, data, newData);
        else return Update(root->right, data, newData);
    }
    /*Usurarea codului*/
    bool Update(T data, T newData){
        return Update(this, data, newData);
    }

    /*Sterge un nod din arbore pastrand proprietatiile unui arbore binar*/
    BST* Delete(BST* root, T data){
        BST* delPtr = root;

        if(root == NULL)
            return NULL;
        if(data < root->data)
            root->left = Delete(root->left, data);
        else if(data > root->data)
            root->right = Delete(root->right, data);
        else if(root->left == NULL and root->right == NULL)
        {
            delete delPtr;
            return NULL;
        }
        else if(root->left == NULL and root->right != NULL)
        {
            BST* temp;

            temp = root->right;
            delPtr->right = NULL;
            delete delPtr;
            return temp;
        }
        else if(root->left != NULL and root->right == NULL){
            BST* temp;

            temp = root->left;
            delPtr->left = NULL;
            delete delPtr;
            return temp;
        }
        else if(root->left != NULL and root->right != NULL)
        {
            BST* temp = root->left;
            while(temp->left != NULL)
                temp = temp->left;
            root->data = temp->data;
            root->right = Delete(root->right, root->data);
            return root;
        }
    }

};

#endif //PROIECTSDA_BST_H
