#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "List.h"
#include "Cell.h"
using namespace std;

template <typename D, typename P>
class Queue : public List<D, P> {
    public:
        Queue(){
            first=last=nullptr;
            n=0;
        }
        
        
        void insert(D d) {
            P new = new Cell<D>(d,nullptr);
            if(getSize()==0)
            {
                this->first=this->last=new;
            }
            else
            {
                this->last->next = new;
                this->last = new;
            }
           
            n++;
        }
        
        void remove(D d) { 
            
            P temp = first;
            if(getSize()>1){
                first = first->next;
            }
            else
            {
                first=last=nullptr;
            }
            delete temp;
            n--;
        }
        
        P find(D d) 
        { 
            
        }
        
        void assign(P k, D d) {

        }
        
        void sort() { 
            
        }
        
        int getSize() { //tamaño
            return n;
        }
        
        void printList() { 
            if(first)
            {
                P temp = first;
                for(int i =0; i<this->getSize(); i++)
                {
                    cout<<*(temp->data)<<endl;
                }
            }
        }
        
        P next(P k) { 
            
        }
        
        P prev(P k) { //anterior
            
        }
        
        void emptyList() {
            P temp = first->next;
            delete first;
            first=temp->next;
        }
        
        
            int n; //num. elementos
            P first; //
            P last; //ultimo
};


#endif /* QUEUE_H */

