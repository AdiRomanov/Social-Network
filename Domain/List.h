//
// Created by roman on 5/14/2022.
//

#ifndef PROIECTSDA_LIST_H
#define PROIECTSDA_LIST_H
#include <iostream>

/*Tad 1*/
template <typename T>
class List
{
private:
    T* lst;
    int capacity;
    int dim;
public:
    /*Constructor initializeaza functia cu un slot*/
    List()
    {
        lst = new T[1];
        capacity = 1;
        dim = 0;
    }
    T begin(){
        return lst[0];
    }

    T end(){
        return lst[dim];
    }

    /*Introduce un element generic in lista*/
    void push_back(T &data)
    {
        if (dim == capacity) {
            T* temp = new T[2 * capacity];

            for (int i = 0; i < capacity; i++) {
                temp[i] = lst[i];
            }

            delete[] lst;
            capacity *= 2;
            lst = temp;
        }

        lst[dim] = data;
        dim++;
    }

    void insert(T data, int index)
    {
        if (index == capacity)
            push(data);
        else
            lst[index] = data;
    }

    T get(int index)
    {
        if (index < dim)
            return lst[index];
    }

    void pop() { dim--; }

    int size() { return dim; }

    int getCapacity() { return capacity; }

    void print()
    {
        for (int i = 0; i < dim; i++) {
            std::cout << lst[i] << " ";
        }
        std::cout << std::endl;
    }

    /*Sterge un element din lista*/
    void erase(T elem)
    {   int i;
        for(i=0; i < dim; i++)
            if(lst[i] == elem)
                break;
        if(i < dim)
        {
            dim--;
            for(int j = i; j < dim; j++)
                lst[j] = lst[j+1];
        }
    }

    /*Returneaza elementul de pe pozitia data a listei*/
    T operator[](int index) {
        return lst[index];
    }

    /*Modifica un element al functiei*/
    int update(T elem, T newElem) {
        int i;
        for(i=0; i < dim; i++)
            if(lst[i] == elem)
                break;
        if (lst[i] == elem) {
            lst[i] = newElem;
            return  1;
        }
        return  0;
    }
};


#endif //PROIECTSDA_LIST_H
