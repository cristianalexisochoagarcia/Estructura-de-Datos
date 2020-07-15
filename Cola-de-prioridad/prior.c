void enqueue(PriorityQueue *q, int val){
	if((*q) == NUL){
	(*q) = (PriorityQueue)malloc(sizeof(struct Nodo)); 
	(*q) -> value=val;
	(*q) -> post = NULL;
	}else{
	PriorityQueue prev = NULL;
	PriorityQueue fs = (*q);
	while((*q) != NULL && (*q)->value<val){
		prev = (*q);
		(*q) = (*q) -> post;
	}
	if ((*q) == NULL){
	(*q) = (PriorityQueue)malloc(sizeof(struct Nodo));
	(*q) -> value = val;
	(*q) ->post = NULL;
	prev -> post = (*q);
	(*q) = fst;
	}else if((*q)->value >= val){	// Elemento al principio de la cola
	if (prev == NULL){	//	Comprobamos que el primer elemnto es mayor que el dado
	prev = (PriorityQueue)malloc(sizeof(struct Nodo));
	prev -> value = val;
	prev -> post = (*q);
	(*q) = fst;
	}	
}
