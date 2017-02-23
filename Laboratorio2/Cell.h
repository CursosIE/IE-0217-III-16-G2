#ifndef CELL_H
#define CELL_H

template <typename D>
class Cell {
    public:
        Cell* next;
        D* data;
        
        Cell(){
            data= nullptr;
            next=nullptr;
        }
        
        Cell( D* d, Cell* c){
            this->data = d;
            this->next = c;
        }
        
        Cell(const Cell& orig) {
            orig->data = this->data;
            orig->next = this->next;
        }
        
        virtual ~Cell(){
            delete this->data;
        }
        

};

#endif /* CELL_H */

