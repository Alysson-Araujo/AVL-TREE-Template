/* 
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Aluno: Alysson Alexandre de Oliveira Araújo               |
Matricula: 474084                                         |
Turma: Estrutura de dados avançada 2020.1                 |
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#include <iostream>
#include "avl.h"
using namespace std;


void menu(){
    cout << "\n ----------------------------- \n Implementação da Árvore AVL \n ----------------------------- \n" 
    << "Digite 1 para inserir um elemento na árvore." << "\n"  
    << "Digite 2 para apagar a Árvore por completo." << "\n" 
    << "Digite 3 para fazer o percurso em pre-ordem." << "\n" 
    << "Digite 4 para fazer o percurso em ordem simétrica (percurso em ordem)." << '\n'
    << "Digite 5 para fazer o percurso em pós-ordem." << '\n'
    << "Digite 6 para pesquisar uma chave e retornar o valor associado à chave caso ela exista na árvore." << '\n'
    << "Digite 7 para calcular a altura da árvore." << '\n'
    << "Digite 0 para sair do programa."
    << endl;
}

int main(){

    //Node<int, int>* node;
    //Controlador do while
    bool open = true;
    
    avl<int, int> teste(10, 100);
    teste.avl_in_ordem(teste.get_root());
    teste.avl_insert(teste.get_root(),20,200);
    teste.avl_insert(teste.get_root(),30,300);
    teste.avl_insert(teste.get_root(),40,400);
    teste.avl_insert(teste.get_root(),50,500);
    teste.avl_insert(teste.get_root(),60,200);
    
    // numero para ser usado no switch, selecionando oq quer fazer no programa
    int num;
    /*
    while (open){
        menu();
        cin >> num;
        switch (num)
        {
        case 1:
            cout<< "Digite a chave do nó: ";
            cin >> key;
            cout << "Digite o valor do nó: ";
            cin >> value;
            no = avl_insert(no,key,value);
            break;
        
        case 2:
            no = avl_delete(no);
            if(avl_empty(no)){
                cout << "A Árvore AVL foi deletada com sucesso!" << endl;
            }
            else{
                cout << "Ocorreu algum problema em deletar a Aŕvore AVL." << endl;
                break;
            }
        
        case 3:
            avl_pre_ordem(no);
            break;

        case 4:
            avl_in_ordem(no);
            break;
        
        case 5:
            avl_pos_ordem(no);
            break;
        
        case 6:
            cout << "Digite o valor da key: ";
            cin >> key;
            cout << get_key_RValue(no, key) << endl;
            break;
        
        case 7:
            cout << "A altura da árvore é: " << avl_height(no) << endl;
            break;
        
        case 0:
            open = false;
            break;
        default:
            cout <<"Por favor, digite um dos valores descritos no menu." << endl;
            break;
        }
    }

    avl_delete(no);*/
    return 0;
}