#include "Data.h"
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
    }

    int** fillMatrix(int size, int** a){
	for (int i = 0; i < size; i++) {
      	  for (int j = 0; j < size; j++) {
		a[i][j]=-1;
		
	  }
	}
	return a;
    }


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

    void addEdge(string id1, string id2, int weight){
	int a=getPos(id1);
	int b=getPos(id2);
        if(a!=-1 && b!=-1 && pm[a][b]==-1){
		pm[a][b]=weight;
	}
     }

    void removeEdge(int id1, int id2){
	int a=getPos(id1);
	int b=getPos(id2); 
	if(a!=-1 && b!=-1){
		pm[a][b]=-1;
	} 

    }

 
   void printMatrix(){
	cout << "Matriz de Adyacencia" << endl;
	for (int i = 0; i < Nodes; i++) {
      	  for (int j = 0; j < Nodes; j++) {
         	  cout << pm[i][j] << "  ";  
       	 }
	cout << endl;
    }
  }

  void printNodes(){
	for (int i = 0; i < Nodes; i++) {
	     cout<< NodeIdentifier[i] << "(" << (NodesList[i]).data << ") ";
	}	 	
	cout << endl;

}

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

int DirectPath_1(string id1, string id2){
	int a=getPos(id1);
	int b=getPos(id2);
	int ret=-1;
	if(a!=-1 && b!=-1){
		ret=pm[a][b];
	}
	return ret;
}

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

int isPath(string s){
	int is=1;
	int size= Size(s);
	for(int i=0;i<size-1;i++){
		char* a= new char(s[i]);
		char* b= new char(s[i+1]);
		string s1= string(a);
		string s2= string(b);
		if(DirectPath_1(s1,s2)==-1){
			is=0;
			i=size;		
		}
		
	}
	return is;

}
int factorial(int i){
	if(i==0){
		return 1;	
	}
	else{
		int res= i*factorial(i-1);
		return res;
	}

}


int IsOnList(string id,string* list, int list_len){
	int varRet=0;
	for(int i=0;i<list_len; i++){
		if(id== list[i]){
			varRet=1;
		}
	}
	return varRet;
}
//Nodes>size>1
string genPaths(int size, string id1, string id2){

	int MidleElements;
	bool rep;
	if(id1==id2){
		MidleElements=Nodes-1;
		rep=true;
	}
	else{
		MidleElements=Nodes-2;
		rep=false;
	}

	int a=getPos(id1);
	int b=getPos(id2);
	int* c;
	c= new int[Nodes];
	for(int j=0;j<Nodes; j++){
		if(j!=a && j!=b){
			c[j]=0;
		}
		else{
			c[j]=-1;
		}
	}
	for(int j=0;j<Nodes; j++){
		if(c[j]!=-1){
			c[j]=1;
			j=Nodes;
		}

	}

	int* d;
	d= new int[Nodes];
	d=c;

	for(int j=0; j<Nodes; j++){
		cout << c[j] << " ";
	}
	cout << endl;
		
	string res=id1;


 
	/*for(int j=0;j<size-2;j++){
		
		int k=0;
		for(int i=0;i<Nodes;i++){
			if(c[i]==1){
				string tmp=NodeIdentifier[i];
				if(k==0){
					res+=tmp;
					k=1;	
				}
			}
		}
		for(int i=0;i<Nodes;i++){	
			if(i==Nodes-1 && c[i]==1){
				c[i]=0;
				if(c[0]!=-1){
					c[0]=1;
				}
				else{
					if(c[1]!=-1){
						c[1]=1;
					}				
					else{
						c[2]=1;
					}				
				}
				
			}
			if(i==Nodes-2 && c[i]==1){
				c[i]=0;
				if(c[Nodes-1]!=-1){
					c[Nodes-1]=1;
				}
				else{
					if(c[0]!=-1){
						c[0]=1;
					}				
					else{
						c[1]=1;
					}				
				}
			}
			if(i!=Nodes-1 && i!=Nodes-2 && c[i]==1){
				c[i]=0;
				if(c[i+1]!=-1){
					c[i+1]=1;
				}
				else{
					if(c[i+2]!=-1){
						c[i+2]=1;
					}
					else{
						c[i+3]=1;

					}
				}
			}
			
			for(int j=0; j<Nodes; j++){
			cout << c[j] << " ";
			}
			cout << endl;
		}
	}
	res+=id2;*/


	
  return res;


}


string Path (string id1, string id2){
	int a1= IsOnList(id1, NodeIdentifier, Nodes);
	int a2= IsOnList(id2, NodeIdentifier, Nodes);
	if(a1==1 && a2==1){
		string ret="";
	
		return ret;
	}
	else{
	return "EL NODO SOLICITADO NO EXISTE";
	}
}




/*
bool DirectPath_2(string id1, string id2){
	int tmp=0;
	bool res;	
	tmp= DirectPath_1(id1, id2);
	if(tmp==-1){
		res=false;
	}
	else{
		res==true;
	}
	return res;

}

int IsOnList(string id,string* list, int list_len){
	int varRet=0;
	for(int i=0;i<list_len; i++){
		if(id== list[i]){
			varRet=1;
		}
	}
	return varRet;
}

int HavePaths(string id,string* list, int list_len){
	int have=0;
	for(int i=0;i<Nodes; i++){
		string id2=NodeIdentifier[i];
	
		if( DirectPath_1(id,id2)!=-1    &&  IsOnList(id2, list, list_len)==0 ){
	        		have=1;
		}
	}
	return have;
}

int a=0;
int IndirectPath_1(int dist, string id1, string id2,   string* cancel, int cancel_len){
		
		if(cancel_len!=0){
	       		cancel_len++;
			string* s1;
				s1= new string[cancel_len];
			if(cancel_len!=1){	
				for(int i=0; i<cancel_len-1; i++){
					s1[i]=cancel[i];
			}
			}
			s1[cancel_len-1]=id1;
			cancel=s1;
		}
		


		if(DirectPath_2(id1,id2) == true){
			dist= dist+DirectPath_1(id1,id2);
			a=1;
			return dist;
		}
		else{ 
			//for(int i=0;i<cancel_len;i++){
			//cout << cancel[i] << endl;
			//}
		
				if(HavePaths( id1, cancel,  cancel_len)==1 && a==0){
					cout << "Hay caminos" <<endl;
					for(int i=0; i<Nodes; i++){
					   string temp=NodeIdentifier[i];
					   if(IsOnList(temp, cancel, cancel_len)==false){
					     cout<<temp<<endl;
					      int rec=IndirectPath_1( dist+DirectPath_1(id1,temp),temp,id2,cancel,cancel_len);
					    else{
					    }

					  }
					}



				}
				else{ 
					cout << "No hay caminos" <<endl;
					a=1;
					return -1;
				}
		}
		cout << "a= " << a <<endl;


}

int IndirectPath_Main(string id1, string id2){
	a=0;
	string* NodeIdentifierUsed;
	NodeIdentifierUsed= new string[0];
	int cancel_len=0;
	int dist=0;
	int ret= IndirectPath_1(dist, id1, id2, NodeIdentifierUsed, cancel_len);
	return ret;
}*/


};



#endif /* GRAPHWITHARRAY_H */
