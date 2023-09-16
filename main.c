#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"



int main (){
    int cod;
    char arquivo[] = "tarefas";
    ListaDeTarefas lt;

    cod = carregarLista(&lt, arquivo);
    if (cod == 1)
        lt.qtd = 0;

    int opcao;
    do{
        printMenu();
        scanf("%d", &opcao);
        printf("%d\n", opcao);
        if(opcao == 0)
        ;
        else if (opcao == 1){
            criarTarefa(&lt);
        } else if (opcao == 2){
            deletarTarefa(&lt);
        } else if (opcao == 3){
            listarTarefa(lt);
        } else {
            printf("Opcao não existe!\n");
        }
    } while (opcao != 0);

    cod = salvarLista(lt, arquivo);
    if (cod != 0){
        printf("Erro ao salvar tarefas!\n");
    }
    return 0;
}