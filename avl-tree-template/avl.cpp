/* 
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Aluno: Alysson Alexandre de Oliveira Araújo               |
Matricula: 474084                                         |
Turma: Estrutura de dados avançada 2020.1                 |
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

//#include <iostream>
//#include "item.h"
//#include "alv.h"
//
//
// 
//struct Node
//{
//    Tkey key;
//    Tvalue value;
//    int height;
//    Node *left;
//    Node *right;
//};
//
//Node* avl_create(){
//    return nullptr;
//}
//
//Node* create_node(Tkey key, Tvalue value){  
//    Node *node = new Node;
//    node->key = key;
//    node->value = value;
//    node->left = nullptr;
//    node->right = nullptr;
//    node->height = 1;
//    return node;
//}
//
//Node* avl_insert(Node *no, Tkey key, Tvalue value){
//    /**
//     * Caso base: na primeira verificação, se o no == nullptr retornar true, significa que estamos na raiz e
//     * ela está vazia, logo iremos colocar os valores nela.
//     * 
//     * Se for na segunda ou posteriores verificações, significa que iremos adicionar uma nova folha com os 
//     * valores passados nos parâmetros da função.
//     */
//    if(no == nullptr){
//        return create_node(key, value);
//    }
//    // Vereficará se o valor da key passada é maior que a chave do nó atual 
//        if(key < no->key){
//            no->left = avl_insert(no->left, key, value);
//            //Será verificado se é preciso fazer alguma rotação para deixar balanceada. 
//            no = avl_balance(no, key);
//        }
//        // Vereficará se o valor da key passada é menor que a chave do nó atual 
//        if(key > no->key){
//            no->right = avl_insert(no->right, key, value);
//            //Será verificado se é preciso fazer alguma rotação para deixar balanceada.
//            no = avl_balance(no, key);
//            // quando a key já está presente na árvore.
//        }
//    // Vai corrigir a altura da árvore
//    no->height = 1 + max(avl_height(no->left), avl_height(no->right));
//
//    return no;
//}
//
//
//// ######################################### Rotações e max #########################################
//
//// Faz uma rotação a direita
//Node *rightRotation(Node *no){
//        Node* aux;
//        aux = no->left;
//        no->left = aux->right;
//        aux->right = no;
//        
//        // ###### atualzará as alturas dos nós ######
//        no->height = max(avl_height(no->left), avl_height(no->right)) + 1;
//        aux->height = max(avl_height(aux->left), avl_height(aux->right)) + 1;
//        // ###### ############################ ######
//
//        return aux;
//    }
//
//// faz uma rotação a esquerda
//Node *leftRotation(Node *no){
//        Node* aux;
//        aux= no->right;
//        no->right = aux->left;
//        aux->left = no;
//        // ###### atualzará as alturas dos nós ######
//        no->height = max(avl_height(no->left), avl_height(no->right)) + 1;
//        aux->height = max(avl_height(aux->left), avl_height(aux->right)) + 1;
//        // ###### ############################ ######
//
//        return aux;
//    }
//
////rotação dupla a direita
//Node* leftRight(Node* no){
//        no->left = leftRotation(no->left);
//        return rightRotation(no);
//    }
//
////Rotação dupla a esquerda.
//Node* rightLeft(Node* no){
//    no->right = rightRotation(no->right);
//    return leftRotation(no);
//}
//
//int max(int a, int b){
//    if(a>b) return a;
//    return b;
//}
//
//// ##################################################################################################
//
//
//
////Função que vai receber um nó e uma chave e vai retornar seu valor.
//Tvalue get_key_RValue(Node *no, Tkey key){
//    if(no==nullptr){
//        return "Chave não encontrada";
//    }
//    // fará a busca para o lado esquerdo da árvore caso a chave desejada seja menor do que a chave do no
//    if(key < no->key){
//        return get_key_RValue(no->left, key);
//    }
//    // fará a busca para o lado direito da árvore caso a chave desejada seja menor do que a chave do no
//    else if(key > no->key){
//        return get_key_RValue(no->right, key);
//    }
//    
//    //Significa que foi encontrada a raiz com a key passada no parâmetro e retornará o seu valor guardado.
//    std:: cout << "chave encontrada, seu valor é: ";
//    return no->value;
//}
//
//
//// Fator de balanceamento, onde o seu resultado é fazer subtração da altura do nó direito com a altura do nó
//// esquerdo.  
//// O fator de balanceamento tem que ser somente -1, 0 ou 1. 
//int balancing_factor (Node *node) {
//    if(node == nullptr ){
//        return 0;
//    }
//    return avl_height (node -> right) - avl_height (node ->left);
//}
//
//
//// Essa função fica responsável em fazer todas as rotações possíveis na árvore ALV para que ela se mantenha 
//// regulada
//// O fator de balanceamento tem que ser somente -1, 0 ou 1. 
//Node* avl_balance(Node *no, Tkey key){
//    // Rotação a direita. 
//    // suponha que existe um nó desbalanceado b que tem um filho esquerdo x e o x tem  um filho esquerdo y, 
//    // deixando o fator de balanceamento de b ser igual a -2. Para fazer o balanceamento, será preciso:
//    /* faz uma rotação a direita no b
//                            b                 x
//                           /                 / \
//                          x       =>        y   b
//                         /
//                        y
//    
//    */
//    if(balancing_factor(no) < -1 && key < no->left->key)
//        return rightRotation(no);
//    
//    // rotação dupla a direita
//    // suponha que existe um nó desbalanceado b que tem um filho esquerdo x e o x tem um filho direito y, 
//    // deixando o fator de balanceamento de b ser igual a -2. Para fazer o balanceamento, será preciso:
//    /* faz uma rotação a esquerda no x e uma rotação a direita no b
//
//                            b                 b                    y
//                           /                 /                    / \
//                          x       =>        y          =>        x   b
//                           \               /                        
//                            y             x
//    
//    */
//    
//    else if(balancing_factor(no) < -1 && key > no->left->key)
//        return leftRight(no);
//
//    // Rotação a esquerda. 
//     
//    // suponha que existe um nó desbalanceado b que tem um filho direito x e o x tem um filho direito y, 
//    // deixando o fator de balanceamento de b ser igual a 2. Para fazer o balanceamento, será preciso:
//    /* faz uma rotação a esquerda no b
//                            b                 x
//                             \               / \
//                              x       =>    b   y
//                               \
//                                y
//    
//    */
//    else if(balancing_factor(no) > 1 && key > no->right->key )
//        return leftRotation(no);
//    
//    // Rotação dupla a esquerda
//    
//    // suponha que existe um nó desbalanceado b que tem um filho direito x e o x tem um filho esquerdo y, 
//    // deixando o fator de balanceamento de b ser igual a 2. Para fazer o balanceamento, será preciso:
//    /* fazer uma rotação a direita no x e uma rotação a esquerda no b
//
//                        b                 b                     y
//                         \                 \                   / \
//                          x       =>        y         =>      b   x
//                         /                   \                   
//                        y                     x
//    
//    */
//    else if(balancing_factor(no) > 1 && key < no->right->key)
//        return rightLeft(no);       
//
//    return no;
//}
//
//// retorna a altura atual da árvore.
//int avl_height(Node *node) {
//    if(node == nullptr){ 
//        return 0;
//    }
//    else{ 
//        return node->height;
//    }
//}
//
//
//
//
//void avl_pre_ordem(Node *no){
//    if(no != nullptr){
//        std::cout << "Chave " << no->key << ", " << "Valor "<< no->value << std::endl;
//        avl_pre_ordem(no->left);
//        avl_pre_ordem(no->right);
//    }
//}
//
//
//void avl_pos_ordem(Node *no){
//    if (no != nullptr) {
//        avl_pos_ordem(no ->left);
//        avl_pos_ordem(no ->right);
//        std::cout << "Chave " << no->key << ", " << "Valor "<< no->value << std::endl;
//    }
//}
//
//void avl_in_ordem(Node *no){
//    if (no != nullptr) {
//        avl_in_ordem(no ->left);
//        std::cout << "Chave " << no->key << ", " << "Valor "<< no->value << std::endl;
//        avl_in_ordem(no ->right);
//    }
//}
//
//
////Irá pecorrer toda a árvore, deletando todos os nós.
//Node* avl_delete(Node* no){
//    if(no!=NULL){
//        no->left = avl_delete(no->left);
//        no->right = avl_delete(no->right);
//        std::cout << "excluindo o nó com chave " << no->key << " e com valor de " << no->value << std::endl;
//        delete no;
//    }
//    return nullptr;
//}
////Fará a verificação para sabe se a árvore é vazia
//bool avl_empty(Node* no){
//    if(no== nullptr){
//        return true;
//    }
//    else 
//        return false;
//}
//