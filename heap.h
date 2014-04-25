#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include "HeapADT.h"

using namespace std;

template<typename E> class Heap : public HeapADT<E>
{
private:
    E * content;
    int maxsize;
    int n;

    void heapfy(int pos){
        int i = 0;
        int j = 0;
        for(;j< this->n;j++)
            for(i = 0; i < this->n - 1; i++)
                if(this->content[i] < this->content[i+1]){
                    this->content[i] += this->content[i+1];
                    this->content[i+1] = this->content[i] - this->content[i+1];
                    this->content[i] -= this->content[i+1];
                }
    }

    void expandContent(){
        this->maxsize*=1.5;
        E * aux = new E[this->maxsize];
        for(int i = 0; i < this->n; i++)
            aux[i] = this->content[i];
        this->content = aux;
    }

public:
    Heap(){
        this->content = new E[1000];
        this->maxsize = 1000;
        this->n =0;
    }

    int size() const{
        return this->n;
    }

    bool isLeaf(int pos) const{
        return (pos*2 > this->n);
    }

    int left(int pos) const{
        if(!this->isLeaf(pos))
            return pos*2;
    }

    int righ(int pos) const{
        if(!this->isLeaf(pos))
            return pos*2 + 1;
    }

    int parent(int pos) const{
        if(pos > 1)
            return pos/2;
    }

    void buildMaxHeap(){
        this->heapfy(0);
    }

    void insert(const E& it){
        this->content[n] = it;
        this->n ++;
        if(this->n == this->maxsize)
            this->expandContent();
    }

    E removefirst(){
        E first;
        first = this->content[0];
        E * aux  = new E[this->maxsize];
        for(int i = 1; i < this->n ; i++)
            aux[i-1] = this->content[i];

        this->content = aux;
        this->n --;
        return first;
    }

    E remove(int pos){
        E toRemove;
        toRemove = this->content[pos];
        E * aux = new E[this->maxsize];
        int j = 0;
        for(int i=0; i < this->n ; i++){
            aux[j] = this->content[i];
            if(i!=pos-1)
                j++;
        }

        this->content = aux;
        this->n--;
        return toRemove;

    }

    void printHeap(){
        for(int i=0; i< this->n ; i++)
            cout << " " << this->content[i];
        cout << "\n";
    }
};

#endif // HEAP_H
