

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include "NodeT.h"
#include "ListaConArreglo.h"

using namespace std;

template <typename Data>
class BinarySearchTree {
public:

    BinarySearchTree() {
	nodes=0;
	}

    BinarySearchTree(NodeT<Data>* r) {
        this->root = r;
	nodes=0;
    }

    BinarySearchTree(Data* d) {
        this->root = new NodeT<Data>(nullptr, nullptr, d, nullptr);
	nodes=0;
    }

    BinarySearchTree(const BinarySearchTree& orig) {
    }

    virtual ~BinarySearchTree() {
    }

    void insert(Data* d) {
        if (this->root == nullptr) {
            root = new NodeT<Data>(nullptr, nullptr, d, nullptr);
        } else {
            NodeT<Data>* t = root;
            bool end = 0;
            while (!end) {
                if (*d < *(t->d)) {
                    if (t->l == nullptr) {
                        t->l = new NodeT<Data>(nullptr, nullptr, d, t);
                        end = 1;
                    } else {
                        if (t->l != nullptr) {
                            t = t->l;
                        }
                    }
                } else {
                    if (t->r == nullptr) {
                        t->r = new NodeT<Data>(nullptr, nullptr, d, t);
                        end = 1;
                    } else {
                        if (t->r != nullptr) {
                            t = t->r;
                        }
                    }
                }
            }
        }
	nodes++;
    }

    void removing(NodeT<Data>* n) {
        if (n && n->l == n->r && n->r == nullptr) // es hoja?
        {
            delete n; // =)
        } else {
            NodeT<Data>* t = replacementFor(n);
            if (t) {
                *(n->d) = *(t->d);
                removing(t);
            }
        }
    }

    void remove(Data* d) {
        removing(find(d));
    }

    Data * get(NodeT<Data>* n) {
    }

    void set(NodeT<Data>* n, Data * d) {
    }

    NodeT<Data>* finding(Data* d, NodeT<Data>* n) {
        if (n && *(n->d) == *d) {

            return n;
        } else {
            if (n && *(n->d) > *d) {
                return finding(d, n->l);
            } else {
                if (n) {
                    return finding(d, n->r);
                } else {
                    return nullptr;
                }
            }
        }
	if(nodes!=0){
		nodes--;
	}
    }

    NodeT<Data>* find(Data* d) {
        return finding(d, this->root);
    }



    void printTree() {
        this->preOrder(root);
    }
	/*! Ve si el nodo actual está vacío.
        Recorre de manera recursiva el subarbol izquierdo.
        Imprime el valor del nodo actual.
        Recorre de manera recursiva el subarbol derecho.
        \param n nodo actual*/

    void inOrder(NodeT<Data>* n) {
       if (n) {
	    inOrder(n->l);
            cout << *(n->d) << endl;
	    inOrder(n->r);
         }
    }

    NodeT<Data>* replacementFor(NodeT<Data>* n) {
        if (n) {
            if (n->l) {
                return maxLesser(n);
            } else {
                if (n->r) {
                    return minGreater(n);
                }
            }
        }
        return nullptr;
    }

    NodeT<Data>* minGreater(NodeT<Data>* n) {
        NodeT<Data>* t = n->r;
        while (t->l) {
            t = t->l;
        }
        return t;
    }

    NodeT<Data>* maxLesser(NodeT<Data>* n) {

        NodeT<Data>* t = n->l;

        while (t->r) {
            t = t->r;
        }
        return t;
    }
 /*! postOrder recorre el árbol para imprimirlo de la siguiente forma:
        1- Recorre el subarbol a su derecha de manera recursiva.
        2- Recorre el subarbol a su izquierda de manera recursiva.
        3- Imprime el contenido del nodo en el que se encuentra.
        \param n nodo actual
    */
    void postOrder(NodeT<Data>* n) {
	if (n) {
	    postOrder(n->l);
            postOrder(n->r);
            cout << *(n->d) << endl;

        }
    }
   /*! preOrder recorre al árbol para imprimir de la siguiente forma:
    * 1-Imprime el contenido del nodo en el que se encuentra.
    * 2-Se llama de manera recursiva para recorrer el subarbol izquierdo;
    * 3-Se llama de manera recursiva para recorrer el subarbol derecho
    \param n nodo actual*/

    void preOrder(NodeT<Data>* n) {
	 if (n) {
            cout << *(n->d) << endl;
            preOrder(n->l);
            preOrder(n->r);
        }
    }

/*!Para todos los nodos del arbol donde n es root, agrega a la lista con arreglo llamada lista
*el valor de sus datos. Por la menera de recorrer el arbol notese que la lista queda ordenada
*en orden ascendente.
*/
    void listNodes(NodeT<Data>* n, ListaConArreglo<Data,int>* lista){
	if (n) {
	    listNodes(n->l, lista);
            lista->insert(*(n->d));
	    listNodes(n->r, lista);
         }

    }
	/*! Dado un arbol y dos listas, ambas con elementos o solamente menores o solamente mayores al root del
*arbol, de manera estrategica y recursiva se agregan los nodos al arbol para que este quede balanceado.
*/
   void InsertBalanced(BinarySearchTree<Data>* bst, ListaConArreglo<Data,int>* lista, ListaConArreglo<Data,int>* lista2){
		if(lista2->n != 0){
			bst->insert(new Data(lista2->get( lista2->n/2 )));
			bst->insert(new Data(lista->get(lista->n/2)));

			ListaConArreglo< Data , int >* less1 = new ListaConArreglo< Data , int >();
			ListaConArreglo< Data , int >* more1 = new ListaConArreglo< Data , int >();
			ListaConArreglo< Data , int >* less2 = new ListaConArreglo< Data , int >();
			ListaConArreglo< Data , int >* more2 = new ListaConArreglo< Data , int >();



			for(int i=0;i<lista->n/2; i++){
				less1->insert(lista->get(i) );
			}

			for(int i=lista->n/2+1;i<lista->n; i++){
				more1->insert(lista->get(i) );
			}

			for(int i=0;i<lista2->n/2; i++){
				less2->insert(lista2->get(i) );
			}

			for(int i=lista2->n/2 +1;i<lista2->n; i++){
				more2->insert(lista2->get(i) );
			}
		InsertBalanced(bst, less2, more2);
		InsertBalanced(bst, less1, more1);
		}
}

   void printTree(BinarySearchTree<Data> bst) {
        this->postOrder(bst.root);
    }
/*! Retorna un arbol balanceado
*/
    BinarySearchTree balance() {
	if(nodes>=3){
	    	ListaConArreglo< Data , int >* lista = new ListaConArreglo< Data , int >();
		listNodes(this->root, lista);
		lista->printList();
		BinarySearchTree<Data>* bst2 = new BinarySearchTree<Data>(new Data( lista->get(nodes/2)));
		printTree(bst2->root);
		ListaConArreglo< Data , int >* less = new ListaConArreglo< Data , int >();
		ListaConArreglo< Data , int >* more = new ListaConArreglo< Data , int >();
		for(int i=0;i<nodes/2; i++){
			less->insert(lista->get(i) );
		}

		for(int i=nodes/2 +1 ;i<nodes; i++){
			more->insert(lista->get(i) );
		}

		InsertBalanced(bst2,  less, more);

		cout <<" D: " <<endl;
		printTree(bst2->root);

		return *bst2;


	}

	else{
		cout << "El arbol se encuentra balanceado"<<endl;
	}

	}



    NodeT<Data>* root;
    int level, nodes;
};

#endif /* BINARYSEARCHTREE_H */
