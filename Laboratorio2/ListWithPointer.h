#ifndef LISTWITHPOINTER_H
#define LISTWITHPOINTER_H

#include <iostream>
#include "List.h"
#include "Cell.h"
using namespace std;

template <typename D, typename P>
class ListWithPointer : public List<D, P> {
    public:
        ListWithPointer(){
            this->first = this->last = nullptr;
            this->n=0;
        }
        
        
        void insert(D d) { 
            P c = new Cell<D>(new D(d), nullptr);
            if(this->getSize()==0)
            {
                this->first = this->last = c;
            }
            
            else
            {
                
                this->last->next = c;
                this->last = c;
            }
            this->n++;
            
        }
        
        void remove(D d) { 
            if(first)
            {
                P temp= find(d);
                if(temp)
                {
                    if(temp==first)
                    {
                        first=next(temp);
                    }
                    
                    else{
                        P temp2 = prev(temp);
                        temp2->next = next(temp);
                        if(temp==last)
                        {
                            last = temp2;
                        }
                    }
                    this->n--;
                    delete temp;
                }
            }     
        }
        
        P find(D d) 
        { 
            P temp = first;
            if(first){
                for(int i=0;i<this->getSize();i++)
                {
                    if(get(temp)==d)
                    {
                        return temp;
                    }
                    else
                    {
                        temp=next(temp);
                    }
                }
            }
            cout<<"El valor " << d <<" no esta en la lista"<<endl;
                return nullptr;
        }
        
        D get(P k) { //obtener
            return *(k->data);
        }
        
        void assign(P k, D d) {
            *(k->data) = d;
        }
        
        void sort() { 
            for(int i=0;i<getSize();i++){
                 P temp = first;
                for(int j =0; j<getSize()-1;j++)
                {
                    if(temp && next(temp) && *(temp->data)>*(next(temp)->data))
                    {
                        D newtemp=*(temp->data);
                        *(temp->data)=*(next(temp)->data);
                        *(next(temp)->data)=newtemp;
                    }
                    temp=next(temp);
                }
            }
        }
        
        int getSize() { //tamaño
            return this->n;
        }
        
        void printList() { 
            P temp = first;
            if(first){
                for(int i=0; i<this->getSize(); i++)
                {
                    cout<<get(temp)<<endl;
                    temp=next(temp);
                }
                cout<<"------------------------------------------------------------"<<endl;
                cout<<"------------------------------------------------------------"<<endl;
            }
            else
            {
                cout<<"La lista se encuentra vacia"<<endl;
            }
        }
        
        P next(P k) { //siguiente
                return k->next;
        }
        
        P prev(P k) { //anterior
            if(k != first){
                P temp = first;
                for(int i=0; i < this->getSize(); i++)
                {
                        if(k == next(temp))
                        {
                            int a = get(temp);
                            return temp;
                        }
                        else
                        {
                            temp = next(temp);
                        }
                }
            }
            return nullptr;
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
#endif /* LISTWITHPOINTER_H */

