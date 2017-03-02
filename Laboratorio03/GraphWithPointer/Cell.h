#ifndef CELL_H
#define CELL_H

template <typename D>
/*!
 Plantilla de la clase Celda
 */
class Cell {
    public:
        //! Puntero que apunta a la celda siguiente.
        Cell* next;
        
        //! Puntero que apunta al dato almacenado en la celda.
        D* data;
        
        /*! Constructor de la clase celda, sus atributos inician en nulo*/
        Cell(){
            data= nullptr;
            next=nullptr;
        }
        
        /*! Constructor de la clase celda, asigna a data y next, los valores recibidos como atributos
         \param d puntero de tipo D
         \param c puntero de tipo Cell*/
        
        Cell( D* d, Cell* c){
            this->data = d;
            this->next = c;
        }
        
        /*Constructor por copia.
         \param orig objeto de tipo Cell*/
        
        Cell(const Cell& orig) {
            orig->data = this->data;
            orig->next = this->next;
        }
        
        /*Destructor de la clase celda, elimina el puntero data.*/
        virtual ~Cell(){
            delete this->data;
        }
        
        
};

#endif /* CELL_H */

