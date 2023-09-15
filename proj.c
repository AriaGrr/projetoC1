#include "proj.h"
#include <stdio.h>


int criarTarefa(ListaDeTarefas *lt){
    printf("Criar tarefa\n");
    char *categoria = lt->tarefas[lt->qtd].categoria;
    return 0;
}

int deletarTarefa(ListaDeTarefas *lt){
    printf("Deletar tarefa\n");
    return 0;
}

int listarTarefa(ListaDeTarefas lt){
    printf("Listar tarefas\n");
    return 0;
}

void printMenu(){
    printf("Menu\n");
    printf("1 - Criar tarefa\n");
    printf("2 - Deletar tarefa\n");
    printf("3 - Listar tarefas\n");
    printf("0 - Sair\n");
    printf("Digite a opcao desejada: ");
}

// fwrite
int salvarLista(ListaDeTarefas lt, char nome[]){
    return 0;
}

// fread
int carregarLista(ListaDeTarefas *lt, char nome[]){
    return 1;
}
