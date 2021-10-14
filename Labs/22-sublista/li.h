


/**
 * criou-se cada nó sendo um struct node com um int chamado data 
 * e um apontador next também para um struct node 
**/ 
struct node { 
    int data;
    struct node* next;  

};
typedef struct node node;


/**
 * criou-se cada lista como um head que aponta para um node e 
 * qualquer outra informação sobre a lista pode ser alocada aqui
**/
struct list {
    
    node* head; 
    int size;

};
typedef struct list list;



/**
 * Função para criar uma lista vazia 
 * aqui foi criada uma variável que aponta para uma struct list e 
 * foi alocado o espaço necessário para um list.
 * Alem disso o head da lista foi apontado para NULL e seu tamanho 
 * foi colocado com zero.
**/
list* l_alloc();




/**
 * Função que apaga todos os nodes de uma lista e libera toda a memória dela 
**/
void l_free(list* L);



/**
 * Função para colocar valores no início da lista 
 * foi criado um node p, adicionado uma data, então seu valor de apontador apontou 
 * para onde a head aponta e por fim a head apontou para p,
 * colocando p no inicio da lista.
**/
int l_insert_head(list* L, int data);




/**
 * Função que insere um valor ao fim da lista
 * recebe um apontado para lista que será modificada e um valor para 
 * ser adicionado a lista.
 * Foi criado um apontador p para node que recebe um valor data e aponta para NULL;
 * criou-se um apontador q para head; q caminha na lista até 
 * que o próximo apontador aponte para NULL, quando isso acontece q aponta para o último node
 * da lista; 
 * como q aponta para o último node fazemos o próximo apontador apontar para p, assim o node que p
 * aponta é colocado no fim da lista.
**/
int l_insert_tail(list* L, int data);




/**
 * Função que recebe um intervalo de uma lista e devolve uma sublista com os valores 
 * da lista original nesse intervalor (inclusive intervalos decrescentes)
 * é alocado memória para a nova lista B; depois criamos um novo apontador para a lista original L;
 * esse pontador percorera os nodes de L até encontrar NULL; e enquanto percorre incrementa o valor 
 * de um contador i;
 * a cada valor de i vamos testar se ele esta dentro do intervalo desejado; se estiver e o intervalo for crescente 
 * então adicionamos o valor da posição atual de L em B no tail da lista (assim fica na mesma ordem que em L);
 * se estiver, mas o intervalo for decrescente, então adicionamos o valor da posição atual de L em B no head 
 * (assim fica na ordem contrária de L).
 * ***** nesse caso a lista original L não será mais útil, logo iremos apaga-la da memória usando a função l_free(), ficarem então apenas com a sublista B.
**/
list* l_sublist(list* L, int inicio, int fim);




int l_insert_sub(list* L,list* B, int posicao);




/**
 * Função para printar todos os datas da lista head to tail
**/
void l_print(list* L);