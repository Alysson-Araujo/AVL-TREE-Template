/* 
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Aluno: Alysson Alexandre de Oliveira Araújo               |
Matricula: 474084                                         |
Turma: Estrutura de dados avançada 2020.1                 |
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
#include <iostream>
#ifndef AVL_H
#define AVL_H


template<typename Tkey, typename Tvalue>
struct Node
{
    Tkey key;
    Tvalue value;
    int height;
    Node<Tkey,Tvalue> *left;
    Node<Tkey,Tvalue> *right;
};


template<typename Tkey, typename Tvalue>
class avl
{
private:
    Node<Tkey,Tvalue>* root;
    //Cria um novo nó que será incluido na Árvore AVL.
    Node<Tkey,Tvalue>* create_node(Tkey key, Tvalue value);

    // Vai calcular o fator de balanceamento da árvore.
    int balancing_factor(Node<Tkey,Tvalue> *no);

    // Essa função fica responsável em fazer todas as rotações possíveis na árvore avl para que ela se mantenha 
    // regulada
    Node<Tkey,Tvalue>* avl_balance(Node<Tkey,Tvalue> *no, Tkey key);

    // ######################################### Rotações e max #########################################

    Node<Tkey,Tvalue> *rightRotation(Node<Tkey,Tvalue> *no);

    Node<Tkey,Tvalue> *leftRotation(Node<Tkey,Tvalue> *no);

    Node<Tkey,Tvalue>* leftRight(Node<Tkey,Tvalue>* no);

    Node<Tkey,Tvalue>* rightLeft(Node<Tkey,Tvalue>* no);

    int max (int a, int b);

    // ##################################################################################################

    // Verfica se a árvore está vazia.
    bool avl_empty(Node<Tkey,Tvalue>* no);


public:
    avl(Tkey key,Tvalue value);
    ~avl();
    // Faz a inserção de um nó na árvore AVL, onde nesse nó tera uma chave um valor do tipo string
    Node<Tkey,Tvalue>* avl_insert(Node<Tkey,Tvalue> *no,Tkey key, Tvalue value);

    //deletará todos os nós presente na arvore, passando a arvore a partir da sua raiz.
    Node<Tkey,Tvalue>* avl_delete(Node<Tkey,Tvalue> *no);

    // impressão da arvore no estilo de pré ordem.
    void avl_pre_ordem(Node<Tkey,Tvalue> *no);

    // Impressão da árvore no estilo de ordem simétrica.
    void avl_in_ordem(Node<Tkey,Tvalue> *no); 

    // Impressão da árvore no estilo de pós-ordem.
    void avl_pos_ordem(Node<Tkey,Tvalue> *no);

    // irá pegar a chave de um nó e retornará o seu valor correspondente.
    // RValue = Return Value
    Tvalue get_key_RValue(Node<Tkey,Tvalue> *no, Tkey key);

    // Calcula a altura que a Árvore possui.
    int avl_height(Node<Tkey,Tvalue> *no);

    Node<Tkey,Tvalue>* get_root();
};

template<typename Tkey, typename Tvalue>
avl<Tkey,Tvalue>::avl(Tkey key, Tvalue value){
    Node<Tkey,Tvalue> *node = new Node<Tkey,Tvalue>;
    node->key = key;
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    root = node;
}

template<typename Tkey, typename Tvalue>
avl<Tkey,Tvalue>::~avl(){
    Node<Tkey,Tvalue>* node = avl_delete(get_root());
    root = node;
}


//cria a árvore
//Node<Tkey,Tvalue>* avl_create();




template<typename Tkey, typename Tvalue>
Node<Tkey,Tvalue>* avl<Tkey,Tvalue>::create_node(Tkey key, Tvalue value){  
    Node<Tkey,Tvalue> *node = new Node<Tkey,Tvalue>;
    node->key = key;
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}


template<typename Tkey, typename Tvalue>
Node<Tkey,Tvalue>* avl<Tkey,Tvalue>::avl_insert(Node<Tkey,Tvalue> *no, Tkey key, Tvalue value){
    /**
     * Caso base: na primeira verificação, se o no == nullptr retornar true, significa que estamos na raiz e
     * ela está vazia, logo iremos colocar os valores nela.
     * 
     * Se for na segunda ou posteriores verificações, significa que iremos adicionar uma nova folha com os 
     * valores passados nos parâmetros da função.
     */
    if(no == nullptr){
        return create_node(key, value);
    }
    // Vereficará se o valor da key passada é maior que a chave do nó atual 
        if(key < no->key){
            no->left = avl_insert(no->left, key, value);
            //Será verificado se é preciso fazer alguma rotação para deixar balanceada. 
            no = avl_balance(no, key);
        }
        // Vereficará se o valor da key passada é menor que a chave do nó atual 
        if(key > no->key){
            no->right = avl_insert(no->right, key, value);
            //Será verificado se é preciso fazer alguma rotação para deixar balanceada.
            no = avl_balance(no, key);
            // quando a key já está presente na árvore.
        }
    // Vai corrigir a altura da árvore
    no->height = 1 + max(avl_height(no->left), avl_height(no->right));

    return no;
}


// ######################################### Rotações e max #########################################

// Faz uma rotação a direita
template<typename Tkey, typename Tvalue>
Node<Tkey,Tvalue>* avl<Tkey,Tvalue>::rightRotation(Node<Tkey,Tvalue> *no){
        Node<Tkey,Tvalue>* aux;
        aux = no->left;
        no->left = aux->right;
        aux->right = no;
        
        // ###### atualzará as alturas dos nós ######
        no->height = max(avl_height(no->left), avl_height(no->right)) + 1;
        aux->height = max(avl_height(aux->left), avl_height(aux->right)) + 1;
        // ###### ############################ ######

        return aux;
    }

// faz uma rotação a esquerda
template<typename Tkey, typename Tvalue>
Node<Tkey,Tvalue>* avl<Tkey,Tvalue>::leftRotation(Node<Tkey,Tvalue> *no){
        Node<Tkey,Tvalue>* aux;
        aux= no->right;
        no->right = aux->left;
        aux->left = no;
        // ###### atualzará as alturas dos nós ######
        no->height = max(avl_height(no->left), avl_height(no->right)) + 1;
        aux->height = max(avl_height(aux->left), avl_height(aux->right)) + 1;
        // ###### ############################ ######

        return aux;
    }

//rotação dupla a direita
template<typename Tkey, typename Tvalue>
Node<Tkey,Tvalue>* avl<Tkey,Tvalue>::leftRight(Node<Tkey,Tvalue>* no){
        no->left = leftRotation(no->left);
        return rightRotation(no);
    }

//Rotação dupla a esquerda.
template<typename Tkey, typename Tvalue>
Node<Tkey,Tvalue>* avl<Tkey,Tvalue>::rightLeft(Node<Tkey,Tvalue>* no){
    no->right = rightRotation(no->right);
    return leftRotation(no);
}
template<typename Tkey, typename Tvalue>
int avl<Tkey,Tvalue>::max(int a, int b){
    if(a>b) return a;
    return b;
}

// ##################################################################################################



//Função que vai receber um nó e uma chave e vai retornar seu valor.
template<typename Tkey, typename Tvalue>
Tvalue avl<Tkey,Tvalue>::get_key_RValue(Node<Tkey,Tvalue> *no, Tkey key){
    if(no==nullptr){
        return "Chave não encontrada";
    }
    // fará a busca para o lado esquerdo da árvore caso a chave desejada seja menor do que a chave do no
    if(key < no->key){
        return get_key_RValue(no->left, key);
    }
    // fará a busca para o lado direito da árvore caso a chave desejada seja menor do que a chave do no
    else if(key > no->key){
        return get_key_RValue(no->right, key);
    }
    
    //Significa que foi encontrada a raiz com a key passada no parâmetro e retornará o seu valor guardado.
    std:: cout << "chave encontrada, seu valor é: ";
    return no->value;
}


// Fator de balanceamento, onde o seu resultado é fazer subtração da altura do nó direito com a altura do nó
// esquerdo.  
// O fator de balanceamento tem que ser somente -1, 0 ou 1. 
template<typename Tkey, typename Tvalue>
int avl<Tkey,Tvalue>::balancing_factor (Node<Tkey,Tvalue> *node) {
    if(node == nullptr ){
        return 0;
    }
    return avl_height (node -> right) - avl_height (node ->left);
}


// Essa função fica responsável em fazer todas as rotações possíveis na árvore avl para que ela se mantenha 
// regulada
// O fator de balanceamento tem que ser somente -1, 0 ou 1. 
template<typename Tkey, typename Tvalue>
Node<Tkey,Tvalue>* avl<Tkey,Tvalue>::avl_balance(Node<Tkey,Tvalue> *no, Tkey key){
    // Rotação a direita. 
    // suponha que existe um nó desbalanceado b que tem um filho esquerdo x e o x tem  um filho esquerdo y, 
    // deixando o fator de balanceamento de b ser igual a -2. Para fazer o balanceamento, será preciso:
    /* faz uma rotação a direita no b
                            b                 x
                           /                 / \
                          x       =>        y   b
                         /
                        y
    
    */
    if(balancing_factor(no) < -1 && key < no->left->key)
        return rightRotation(no);
    
    // rotação dupla a direita
    // suponha que existe um nó desbalanceado b que tem um filho esquerdo x e o x tem um filho direito y, 
    // deixando o fator de balanceamento de b ser igual a -2. Para fazer o balanceamento, será preciso:
    /* faz uma rotação a esquerda no x e uma rotação a direita no b

                            b                 b                    y
                           /                 /                    / \
                          x       =>        y          =>        x   b
                           \               /                        
                            y             x
    
    */
    
    else if(balancing_factor(no) < -1 && key > no->left->key)
        return leftRight(no);

    // Rotação a esquerda. 
     
    // suponha que existe um nó desbalanceado b que tem um filho direito x e o x tem um filho direito y, 
    // deixando o fator de balanceamento de b ser igual a 2. Para fazer o balanceamento, será preciso:
    /* faz uma rotação a esquerda no b
                            b                 x
                             \               / \
                              x       =>    b   y
                               \
                                y
    
    */
    else if(balancing_factor(no) > 1 && key > no->right->key )
        return leftRotation(no);
    
    // Rotação dupla a esquerda
    
    // suponha que existe um nó desbalanceado b que tem um filho direito x e o x tem um filho esquerdo y, 
    // deixando o fator de balanceamento de b ser igual a 2. Para fazer o balanceamento, será preciso:
    /* fazer uma rotação a direita no x e uma rotação a esquerda no b

                        b                 b                     y
                         \                 \                   / \
                          x       =>        y         =>      b   x
                         /                   \                   
                        y                     x
    
    */
    else if(balancing_factor(no) > 1 && key < no->right->key)
        return rightLeft(no);       

    return no;
}

// retorna a altura atual da árvore.
template<typename Tkey, typename Tvalue>
int avl<Tkey,Tvalue>::avl_height(Node<Tkey,Tvalue> *node) {
    if(node == nullptr){ 
        return 0;
    }
    else{ 
        return node->height;
    }
}



template<typename Tkey, typename Tvalue>
void avl<Tkey,Tvalue>::avl_pre_ordem(Node<Tkey,Tvalue> *no){
    if(no != nullptr){
        std::cout << "Chave " << no->key << ", " << "Valor "<< no->value << std::endl;
        avl_pre_ordem(no->left);
        avl_pre_ordem(no->right);
    }
}

template<typename Tkey, typename Tvalue>
void avl<Tkey,Tvalue>::avl_pos_ordem(Node<Tkey,Tvalue> *no){
    if (no != nullptr) {
        avl_pos_ordem(no ->left);
        avl_pos_ordem(no ->right);
        std::cout << "Chave " << no->key << ", " << "Valor "<< no->value << std::endl;
    }
}

template<typename Tkey, typename Tvalue>
void avl<Tkey,Tvalue>::avl_in_ordem(Node<Tkey,Tvalue> *no){
    if (no != nullptr) {
        avl_in_ordem(no ->left);
        std::cout << "Chave " << no->key << ", " << "Valor "<< no->value << std::endl;
        avl_in_ordem(no ->right);
    }
}


//Irá pecorrer toda a árvore, deletando todos os nós.
template<typename Tkey, typename Tvalue>
Node<Tkey,Tvalue>* avl<Tkey,Tvalue>::avl_delete(Node<Tkey,Tvalue>* no){
    if(no!=nullptr){
        no->left = avl_delete(no->left);
        no->right = avl_delete(no->right);
        std::cout << "excluindo o nó com chave " << no->key << " e com valor de " << no->value << std::endl;
        delete no;
    }
    return nullptr;
}

//Fará a verificação para sabe se a árvore é vazia
template<typename Tkey, typename Tvalue>
bool avl<Tkey,Tvalue>::avl_empty(Node<Tkey,Tvalue>* no){
    if(no== nullptr){
        return true;
    }
    else 
        return false;
}
template<typename Tkey,typename Tvalue>
Node<Tkey,Tvalue>* avl<Tkey,Tvalue>::get_root(){ return root;}

#endif
