#include "Data.h"
#include <string.h>
#include <string>
#ifndef GRAPHWITHARRAY_H
#define GRAPHWITHARRAY_H

using namespace std;


template <typename D>
//D es  Data<int>
class GraphWithArray {
public:

    int Nodes;
    D* NodesList;
    string* NodeIdentifier;
    int** pm;
 /*!Se pretende tratar un grafo mediante una matriz
*de adyacencias.
*/
    GraphWithArray() {
	Nodes=0;
		
	NodesList= new D[Nodes];

	NodeIdentifier= new string[Nodes];	

	pm = new int* [Nodes];
	for (int i = 0; i < Nodes; i++) {
	     pm[i] = new int[Nodes];
	}  

    }

    virtual ~GraphWithArray() {

	for (int i = 0; i < Nodes; i++) {
	    delete pm[i]; 
	}  
	delete pm;

    }

/*!El metodo fillMatrix es util solamente para matrices cuadradas de 
*dimension size. La recorre y pone el valor de -1 en todas sus casillas.
*/
    int** fillMatrix(int size, int** a){
	for (int i = 0; i < size; i++) {
      	  for (int j = 0; j < size; j++) {
		a[i][j]=-1;
		
	  }
	}
	return a;
    }

/*!Metodo útil para agregar un nodo a la matriz. 
*A este nodo le corresponde un identificador de tipo string.
*Esto implica agregar una fila y una columna.
*Las cuales van a tener valores de -1 en sus casillas
*dado que al crearse son nodos aislados
*/


    void addNode(D d, string id){
	D* NodesList2;
        NodesList2= new D[Nodes+1];
	for (int i = 0; i < Nodes; i++) {
	     NodesList2[i] =NodesList[i];
	}	 
        NodesList2[Nodes]= d;   	


	string* NodeIdentifier2;
	NodeIdentifier2= new string[Nodes+1];
	for (int i = 0; i < Nodes; i++) {
	     NodeIdentifier2[i] = NodeIdentifier[i];
	}	 
        NodeIdentifier2[Nodes]= id; 

        

	int** pm2;   
    	pm2 = new int* [Nodes+1];
	for (int i = 0; i < Nodes+1; i++) {
	     pm2[i] = new int[Nodes+1];
	}
        pm2=fillMatrix(Nodes+1, pm2);
	for (int k = 0; k < Nodes; k++) {
      	  for (int j = 0; j < Nodes; j++) {
		pm2[k][j]=pm[k][j];
	  }
	}
	NodesList=NodesList2;
	NodeIdentifier=NodeIdentifier2;
	pm=pm2;
        Nodes++;
    }

/*!Metodo util para eliminar nodos del grafo
*Se elimina la fila y columna correspondiente a 
*ese nodo.
*Ademas se debe eliminar al nodo de la lista de nodos
*/
    void removeNode(string id){
    	if(Nodes!=0 && getPos(id)!=-1){
		int posDel=getPos(id);

		D* NodesList2;
	        NodesList2= new D[Nodes-1];
		for (int i = 0; i < posDel ; i++) {
		     NodesList2[i] =NodesList[i];
		}
		for (int i = posDel; i < Nodes-1 ; i++) {
		     NodesList2[i] =NodesList[i+1];
		}	


		string* NodeIdentifier2;
	        NodeIdentifier2= new string[Nodes-1];
		for (int i = 0; i < posDel ; i++) {
		     NodeIdentifier2[i] =NodeIdentifier[i];
		}
		for (int i = posDel; i < Nodes-1 ; i++) {
		     NodeIdentifier2[i] =NodeIdentifier[i+1];
		}

		
		int** pm2;   
    		pm2 = new int* [Nodes-1];
		for (int i = 0; i < Nodes-1; i++) {
		     pm2[i] = new int[Nodes-1];
		}
			 
		for(int k = 0; k < Nodes-1; k++) {
      	 		for (int j = 0; j < Nodes-1; j++) {
				if(k<posDel && j<posDel){
					pm2[k][j]=pm[k][j];
				}
				if(k>=posDel && j<posDel){
					pm2[k][j]=pm[k+1][j];
				}
				if(k<posDel && j>=posDel){
					pm2[k][j]=pm[k][j+1];
				}
				if(k>=posDel && j>=posDel){
					pm2[k][j]=pm[k+1][j+1];
				}	  	
			}
		}
	 
	NodesList=NodesList2;
	NodeIdentifier=NodeIdentifier2;
	pm=pm2;
	Nodes--;
	}

    }

 /*!Metodo util para agregar una arista entre los nodos
* id1 e id2 (en esa direccion), cuyo peso es de weight. 
*/ 

    void addEdge(string id1, string id2, int weight){
	int a=getPos(id1);
	int b=getPos(id2);
        if(a!=-1 && b!=-1 && pm[a][b]==-1){
		pm[a][b]=weight;
	}
     }

 /*!Metodo util para eliminar una arista entre los nodos
* id1 e id2 (en esa direccion). 
*/ 

    void removeEdge(string id1, string id2){
	int a=getPos(id1);
	int b=getPos(id2); 
	if(a!=-1 && b!=-1){
		pm[a][b]=-1;
	} 

    }

 /*!Imprime la matriz de adyacencia correspondiente
*al arbol
*/
   void printMatrix(){
	cout << "Matriz de Adyacencia" << endl;
	for (int i = 0; i < Nodes; i++) {
      	  for (int j = 0; j < Nodes; j++) {
         	  cout << pm[i][j] << "     "; 
		  if(pm[i][j]!=-1){
			cout << " ";
		}
		 if(pm[i][j]<10){
			cout << " ";
		}
       	 } 
	cout << endl;
    }
  }
/*!Permite imprimir los nodos del grafo
*/
  void printNodes(){
	for (int i = 0; i < Nodes; i++) {
	     cout<< NodeIdentifier[i] << "(" << (NodesList[i]).data << ") ";
	}	 	
	cout << endl;

}

/*!Dado un identificador id, retorna la posicion en la lista de identificadores.
*en caso de que el identificador no corresponda a ningun nodo retorna -1
*/
int getPos(string id){
	bool found=false;
	int timesFinding=0;
	int resul=-1;	
	while(!found){
		if(NodeIdentifier[timesFinding]==id){
			resul=timesFinding;
			found= true;
		}
		timesFinding++;
		if (timesFinding ==Nodes){
			found= true;
		}
	}
	return resul;
}
/*! retorna el peso de una arista entre los nodos id1 e id2.
*si alguno de los dos nodos o esta arista nombrada no existen
*retorna -1.
*/
int DirectPath_1(string id1, string id2){
	int a=getPos(id1);
	int b=getPos(id2);
	int ret=-1;
	if(a!=-1 && b!=-1){
		ret=pm[a][b];
	}
	return ret;
}


/*! para una lista de enteros, retorna el menor diferente de -1
*o retorna -1 en caso de que tal elemento no exista.
*/
int pos_menor(int* n){
if(n){
	int menor=-1;
	int inter=-1;
	for(int i=1;i< Nodes-2; i++){
		if(menor==-1 && n[i]!=-1){
			menor=n[i];
			inter=i;
		}
		if(n[i]<menor && n[i]!=-1){
			menor=n[i];
			inter=i;
			}
	}
	return inter;
}

}

/*!dado un nodo A, una lista de identificadores n2 y
*una lista de enteros n(que representa la validez de esos nodos)
*el metodo retorna el identificador del nodo cuya distancia al nodo
*con identificador A es la menor, con respecto a los demas nodos VALIDOS.
*/
string Lesser(string A, int* n, string* n2){
string inter= "empty";
int* dist;
dist=new int[Nodes-2]; 
for(int i=0;i<Nodes-2;i++){
 dist[i]=-1;
}

for(int i=0;i<Nodes-2;i++){
	int a= n[i];
	string b=n2[i];
	int k= -1;
	
	if(A!=b && a!=-1){
	   k= DirectPath_1(A, b);
	}
	dist[i]=k;
}

int g= pos_menor(dist);
if(g!=-1){
	inter=n2[g];
}	
	return inter; 

}
/*!Metodo para conocer la cantidad de caracteres de
*un string.
*/
int Size(string s1){
	int size=0;
	bool out= false;
	while(!out){
		if(s1[size]!= '\0'){
			size++;
		}
		else{
			out=true;
		}
	}	
	return size;
}
/*!Una vez dado un trayecto de nodos por recorrer,
*representado en un string, se calcula y retorna la 
*distancia que implica recorrer tal camino.
*/
int tamTray(string s){
	int org=0;
	for(int i=0; i< Size(s)-1; i++){
		char a= s[i];
		char b= s[i+1];
		string c;
		string d;
		c=a;
		d=b;
		int t=DirectPath_1(c,d);
		if(t != -1){
			org+=t;
		}
 	}
	return org;	
}
/*!retorna cual es la menor distancia entre dos nodos
*recorriendo a todos los demas.
*/
int* dijkstra(string A, string B){

int a=getPos(A);
int b=getPos(B);

string* n;
n= new string[Nodes];
for(int i=0;i<Nodes;i++){
 n[i]=NodeIdentifier[i];

}


if(n[Nodes-1]!=B){
  string temp=n[b];
  n[b]=n[Nodes-1];
  n[Nodes-1]=temp;
}

if(n[Nodes-2]!=A){
  string temp=n[a];
  n[a]=n[Nodes-2];
  n[Nodes-2]=temp;
}

string* p;
p=new string[Nodes-2]; 
for(int i=0;i<Nodes-2;i++){
 p[i]=n[i];
}

int* m;
m=new int[Nodes-2]; 
for(int i=0;i<Nodes-2;i++){
 m[i]=0;

}


string temp=A;
string guardar=A;

for(int j=0; j<Nodes-2; j++){
	string q=Lesser(temp, m, p);	
	temp=q;
	if(q!="empty"){
		int c= getPos(q);
		m[c]=-1;
		guardar+=q;
	}
}
guardar+=B;
int tam= tamTray(guardar);
//delete n;
//delete m;
//delete p;
int* z= new int(tam);
return z;
}

/*!retorna una matriz para cada campo [i][j] donde se asigna
* la menor distancia para ir del nodo i al nodo j pasando por todos 
*los demas.
*/
int** floyd(){

 int** r;
 r = new int* [Nodes];
 for (int i = 0; i < Nodes; i++) {
     r[i] = new int[Nodes];
 }  

for(int i=0;i<Nodes;i++){
	for(int n=0; n<Nodes; i++){
		string s=NodeIdentifier[n];
		string d=NodeIdentifier[i];
		r[n][i]= *(dijkstra(s,d) );
	}
}

return r;
}

};



#endif /* GRAPHWITHARRAY_H */
