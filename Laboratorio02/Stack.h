#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "List.h"
#include "Cell.h"
using namespace std;

template <typename D, typename P>
class Stack : public List<D, P> {
    public:
        Stack(){
            first=last=nullptr;
            n=0;
        }


        void insert(D d) {
            P newest = new Cell<D>(new D(d),nullptr);
            if(getSize()==0)
            {
                this->first=this->last=newest;
            }
            else
            {
                this->last->next = newest;
                this->last = newest;
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
                    temp=temp->next;
                }
                cout<<"-------------------------------------------------------"<<endl;
            cout<<"-------------------------------------------------------"<<endl;
            }
            else
            {
                cout<<"La pila esta vacia"<<endl;
            }
        }

        P next(P k) {

        }

        P prev(P k) { //anterior

        }

        D get(P k){

        }

        void emptyList() {
           while(first)
            {
               remove(*(first->data));
            }
        }

            int n; //num. elementos
            P first; //
            P last; //ultimo
};


#endif /* STACK_H */
