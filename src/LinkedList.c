#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "eServicios.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* linkedList = NULL;

    linkedList = (LinkedList*) malloc(sizeof(LinkedList));

    if(linkedList != NULL){

    	linkedList->pFirstNode = NULL;
    	linkedList->size = 0;
    }

    return linkedList;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL){

    	returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */

static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;
	int linkedlistLen = ll_len(this);//obtiene el len de la linkedList

	if(this != NULL){
			//verifica que nodeIndex este dentro del size de la linkedlist.
			if(nodeIndex >= 0 && nodeIndex < linkedlistLen){

				for(int i = 0;i <= nodeIndex ;i++){

					if(i == 0){
						pNode = this->pFirstNode;
					}
					else{
						pNode = pNode->pNextNode;
					}
				}
			}
	}

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* aux;

    //Verificamos que la lista no sea nula.
    if(this != NULL){

    	int len = ll_len(this);

    	//verificamos que el indice este dentro del len de la lista.
    	if(nodeIndex >= 0){

    		//creamos el nodo.
    		Node* pNode= (Node*)malloc(sizeof(Node));

    		//verificamos que haya podido obtener memoria para el nodo.
    		if(pNode != NULL){
    			//Colocamos el elemento dentro del nuevo nodo.
    			pNode->pElement = pElement;

    			//vemos si el index es 0.
    			if(nodeIndex == 0){
    				//colocamos el nuevo nodo al princio de la lista.
    				pNode->pNextNode = this->pFirstNode;
    				this->pFirstNode = pNode;
    				this->size++;//aumentamos el size de la lista.
    				returnAux = 0;
    			}
    			else{

    				//si el nodeindex esta dentro del len de la lista.
    				if(nodeIndex<len){

    					//obtenemos el nodo en ese indice.
    					aux=getNode(this,nodeIndex);
    					pNode->pNextNode = aux;
    					this->size++;//aumentamos el size de la lista.
    					returnAux=0;
    				}else if(nodeIndex == len){//si el node index es igual al len.

    					aux=getNode(this,nodeIndex-1);
    					pNode->pNextNode= NULL;
    					this->size++;
    					returnAux = 0;
    				}
    				aux->pNextNode = pNode;
    			}

    		}
    	}
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len = ll_len(this);

    if(this != NULL){

    	if(addNode(this,len,pElement) == 0){

    		returnAux = 0;
    	}

    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    int len = ll_len(this);
    Node* pNode;

    if(this !=NULL){

    	if(index>=0 && index<len){

    		pNode = getNode(this,index);
    		returnAux = pNode->pElement;
    	}
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    int len = ll_len(this);
    Node* pNode;

    //verificamos que la lista no sea nula.
    if(this != NULL){

    	//verificamos que el index este dentro del len de la lista.
    	if(index >= 0 && index<len){
    		pNode=getNode(this,index); //obtenemos el nodo a modificar.

    		if(pNode !=NULL){//modificamos el nodo.
    			pNode->pElement = pElement;
    			returnAux = 0;
    		}
    	}

    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
	  int returnAux = -1;
	  int len = ll_len(this);
	  Node* nodoAnt;
	  Node* nodeRemove;

	  //verificamos que la lista no sea nula.
	  if(this != NULL){
		  	 //verificamos que el index este dentro del len de la lista.
			if(index>=0 && index<len){

				nodeRemove=getNode(this,index); //obtenemos el nodo a eliminar.

				if(nodeRemove!=NULL){

					if(index==0){ //si el primer nodo de la lista lo cambiamos directo de la lista.
						this->pFirstNode=nodeRemove->pNextNode;
					}
					else{
						//obtenemos el nodo anterior.
						nodoAnt=getNode(this,index-1);
						if(nodoAnt!=NULL){
							//intencambiamos los punteros.
							nodoAnt->pNextNode=nodeRemove->pNextNode;
						}
					}
					this->size--;//disminuimos la lista.
					free(nodeRemove);//borramos el nodo de memoria.
					returnAux =0;
				}
			}
	  }
	    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len = ll_len(this);

    //verificamos que la lista no sea nula.
    if(this !=NULL){

    	//recorremos todos los elementos de la linked list y los eliminamos.
    	for(int i = 0;i<len;i++){
    		ll_remove(this,i);
    	}

    	len = ll_len(this);
    	//verificamos que todos los nodos ya no existan.
    	if(len == 0){
    		returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    //verificamos que la lista no sea nula.
    if(this != NULL){

    	//eliminamos todo su contenido.
    	if(ll_clear(this) == 0){
    		free(this);//borramos la linkedlist de memoria.
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len = ll_len(this);
    void* element;

    if(this != NULL){ //verificar que la lista no sea nula.

    	for(int i = 0;i < len;i++){ //recoremos la lista y obtenemos los elementos.

    		element = ll_get(this,i);

    		if(element == pElement){ //comparamos el elemento actual de la lista con el pasado con parametro.

    			returnAux = i;
    			break;
    		}
    	}

    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL){ //verificamos que la lista no sea nula.

    	if(this->pFirstNode == NULL){//verificamos si tiene un nodo la lista.
    		returnAux = 1;
    	}
    	else{
    		returnAux = 0;
    	}

    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int len = ll_len(this);

    //verificamos que la lista no esa nula.
    if(this != NULL){

    	if(index>= 0 && index <=len){//verificamos que el index este dentro de la lista.

    		if(addNode(this,index,pElement) == 0){//verificamos si el nodo se agrego correctamente.

    			returnAux = 0;
    		}
    	}
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int len = ll_len(this);

    if(this !=NULL){ //verificamos que la lista no sea nula.

    	if(index>= 0 && index <= len){ //verificamos que el index este dentro del len de la lista.

    		returnAux =ll_get(this,index); //obtenemos el puntero.
    		ll_remove(this,index);//borramos el elemento.

    	}
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this !=NULL){ //verificamos que la lista no sea nula.

    	if(ll_indexOf(this,pElement) != -1){ //verificamos si el elemento se encuentra en la lista.

    		returnAux = 1;//si lo encuentra.
    	}
    	else{
    		returnAux = 0;//si no lo encuentra.
    	}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int lenLinked2 = ll_len(this2);
    int contadorElementos = 0;
    void* element;

    if(this!= NULL && this2 != NULL){ //verifica que la lista no sea nula.

    	for(int i =0; i < lenLinked2 ;i++){ //recorre la segunda lista.

    		element = ll_get(this2,i); //obtiene un elemento.

    		if(ll_contains(this,element) == 1){ //verifica que este dentro de la primera lista.
    			contadorElementos++; // si esta dentro la cuenta.
    		}
    	}

    	if(contadorElementos == lenLinked2){ //si los elementos contados coincinden con el len de la lista.

    		returnAux = 1; //contiene todo los elementos.
    	}
    	else{
    		returnAux = 0; // no contiene todo los elementos.
    	}
    }


    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int len = ll_len(this);
    void* element;

    if(this !=NULL){//Verificamos que la lista no sea nula.

    	if(from >=0 &&  to>from && to <= len){ //verificamos que los parametros sean correctos.

    		cloneArray = ll_newLinkedList();//creamos una nueva linkedList.

    		if(cloneArray !=NULL){//verificamos que se haya creado correctamente.

    			//colocamos los parametros en el for.
    			for(int i = from; i < to; i++){

    				element = ll_get(this,i);//obtenemos el elemento del indice de la lista.

    				ll_add(cloneArray,element);//colocamos el elemento en la nueva lista.
    			}
    		}
    	}

    }


    return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int len = ll_len(this);

    if(this != NULL){//verificamos que la lista no sea nula.
    	cloneArray = ll_subList(this,0,len);//clonamos la lista.
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int len = ll_len(this);
    void* elemento1;
    void* elemento2;

    if(this != NULL){//Verificamos si la lista no es nula.

    	if(pFunc != NULL){//verificar que el puntero a funcion no sea nulo.

    		if(order == 0 || order == 1){ //verificar que el orden es 1 o 0.

    			for(int i = 0;i < len; i++){

    				for(int x =i+1;x < len; x++){

    					elemento1 = ll_get(this,i);
    					elemento2 = ll_get(this,x);

    					if(order == 1){

    						if(pFunc(elemento1,elemento2)>0){
    							ll_set(this,i,elemento2);
    							ll_set(this,x,elemento1);
    						}
						}
						else{

							if(pFunc(elemento1,elemento2)<0){
							     ll_set(this,i,elemento2);
							    ll_set(this,x,elemento1);
							   }
						}
    				}
    			}
    			returnAux = 0;
    		}

    	}

    }

    return returnAux;

}

LinkedList* ll_map(LinkedList* this ,void*(pFunc)(void* element)){

	int largoLista = ll_len(this); //obtenemos el largo de la lista.

	//verificamos que la lista o la funcion no sean null.
	if(this != NULL && pFunc != NULL){

		//recorremos la lista.
		for(int i=0;i<largoLista;i++){

			//aplicamos la funcion.
			pFunc(ll_get(this,i));

		}

	}

	return this;
}

LinkedList* ll_filter (LinkedList* this,int tipoElejido ,int (*pFunc) (void* element,int tipo)){

	//variables.
	LinkedList* listaFiltrada = NULL;
	int LargoLista = ll_len(this);
	void* Elemento = NULL;

	//verificamos que la lista o la funcion no sean null.
	if(this != NULL && pFunc != NULL){

		//inicializamos la linkedlist
		listaFiltrada = ll_newLinkedList();

		if(listaFiltrada != NULL){

			//recorremos la lista pasada por parametros.
			for(int i = 0;i < LargoLista;i++){
				
				//obtemos un elemento.
				Elemento = ll_get(this,i);
				
				//verificamos que cumpla con el filtro pasado por parametro.
				if(pFunc(Elemento,tipoElejido) == 1){
					ll_add(listaFiltrada,Elemento); //se agrega a la nueva lista.
				}
			}
		} 
	}

	return listaFiltrada;
}
