#include "Levenshtein.h"


Levenshtein::Levenshtein(int maxCost, string file, string word) {
    this->maxCost = maxCost;
    this->a1 = new Trie;
    this->word = word;
    a1->create(file);
}


ListWithPointer<string,Cell<string>*>* Levenshtein::LevenshteinRow() 
{
    ListWithPointer<string,Cell<string>*>* results = new ListWithPointer<string,Cell<string>*>();
    ListWithPointer<int,Cell<int>*>* currentRow = new ListWithPointer<int,Cell<int>*>();
    
    for(int i=0; i<word.size()+1;i++)
    {
        currentRow->insert(i);
    }
    
    for(int j=0;j<26;j++)
    {
        if(a1->trieTree->children[j])
        {
            searchRecursive(a1->trieTree->children[j],j+'a',currentRow,results);
        }
    }
    return results;
}

void Levenshtein::searchRecursive(TrieNode* node, char letter, ListWithPointer<int,Cell<int>*>* prevRow, ListWithPointer<string,Cell<string>*>* results)
{
    int columns = word.size()+1;
    ListWithPointer<int,Cell<int>*>* currentRow = new ListWithPointer<int,Cell<int>*>();
    currentRow->insert(prevRow->get(prevRow->first)+1);
    for(int d=1; d<columns;d++)
    {
        int insertCost= currentRow->pos(d-1)+1;
        int deleteCost= prevRow->pos(d)+1;
        int replaceCost;
        if (word[d-1] != letter)
        {
            replaceCost = prevRow->pos(d-1)+1;
        }
        else
        {
            replaceCost= prevRow->pos(d-1);
        }
        currentRow->insert(min(insertCost,deleteCost,replaceCost));
    }
    
    if(currentRow->pos(columns-1)<=maxCost && node->EOW)
    {
        results->insert(node->str);
    }
    
    int min_row = 12;
    for(int k =0;k<currentRow->getSize();k++)
    {
        if(currentRow->pos(k)<min_row)
        {
            min_row=currentRow->pos(k);
        }
    }
    
    if(min_row <= maxCost)
    {
        for(int n=0; n<26;n++)
        {
            if(node->children[n])
            {
                searchRecursive(node->children[n],n +'a',currentRow,results);
            }
        }
    }
    
}

int Levenshtein::min(int a, int b, int c) // 10
{
    if(a<b)
    {
        if(a<c) return a;
        else return c;
    }
    else
    {
        if(b<c) return b;
        else return c;
    }
}


int Levenshtein::Levenshtein_alg(string s1){
	int l_s1= s1.size() +1; //5N+8:  metodo Size (5n+5), declaracion, asignacion, operacion 
	int l_s2=word.size() +1;  //5M+8:  metodo Size (5n+5), declaracion, asignacion, operacion
        int matrix[l_s1][l_s2]; //+1 Declaracion
	int distancia=0; //+1 Declaracion y asignacion
	int costo;  //+1 Declaracion

	matrix[0][0]=0;	//+1 Asignacion
	for(int i=1;i< l_s1; i++){ //+2 Comparacion y operacion
		matrix[i][0]=i; //+1 Asignacion
	}
	//xM
	for(int j=1;j< l_s2; j++){//+2 Comparacion y operacion
		matrix[0][j]=j; //+1 Asignacion
	}

	
	//xN 
 	for(int j = 1; j < l_s2; j++) { //+2 Comparacion y operacion
		//xM
		 for(int i = 1; i < l_s1; i++) { //+2 Comparacion y operacion
			
			if(s1[i-1]==word[j-1]){ //+3 Comparacion, 2 accesos
				costo=0; //+1 Asignacion
			}
			else{ //+1 Comparacion
			       costo=1; //+1 Asignacion
			}
		        matrix[i][j] =min(matrix[i-1][j] +1 , matrix[i][j-1] +1 , matrix[i-1][j-1]+costo); //+10, asignacion(1), metodo min(6), 3 accesos  
			
		}
    	 } 


	distancia= matrix[l_s1-1][l_s2-1]; //+3 Asignacion y 2 accesos
	return distancia;	//+1 retorno
}

bool Levenshtein::inRange(TrieNode* a){
	bool ret=true; //+2 Asignacion y declaracion
	int q= a->numChar; //+2 Asignacion y declaracion
	int dif= q - word.size(); //+3 Asignacion, declaracion y operacion
	if(dif<0){ // +1 comparacion
		dif= -1*dif; //+2 Asignacion y declaracion
	}
	
	if(dif>maxCost&& q>word.size()){  //+3 Comparaciones
		ret=false; //+1 Asignacion
	}
	return ret; //+1 retorno
}

ListWithPointer<string,Cell<string>*>* Levenshtein::LevenshteinMatrix(TrieNode* a){
    
    ListWithPointer<string,Cell<string>*>* results = new ListWithPointer<string,Cell<string>*>();
	if(a!=nullptr && inRange(a)==true ){ //+1 Comparacion
		if(a->EOW==true){ //+18, 3 Comparaciones y metodo in range
			if( Levenshtein_alg(a->str) <= maxCost){	//T(n)=16NxM + 10N + 10M + 30, 2 Comparaciones + Levenshtein_alg 		
			  results->insert( a->str );// complejidad O(p), con p el tamaño de la lista			
				//cout << a->str << " ";
			}
		}
		for(int i=0;i<ALPHABET_SIZE;i++){
			TrieNode* b= a->children[i];
			if(b!=nullptr){
				LevenshteinMatrix(b);
			}
		}
	}	
    return results;
}


Levenshtein::~Levenshtein() {
}

