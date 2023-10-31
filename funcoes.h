#include <stdio.h>

typedef struct {
    int prioridade;
    char categoria[100];
    char descricao[300];
} Tarefa;

typedef struct {
    Tarefa tarefas[100];
    int qtd;
} ListaDeTarefas;

int criarTarefa(ListaDeTarefas *lt);
int deletarTarefa(ListaDeTarefas *lt);
int listarTarefa(ListaDeTarefas lt);

void printMenu();
// fwrite
int salvarLista(ListaDeTarefas lt, char nome[]);
// fread
int carregarLista(ListaDeTarefas *lt, char nome[]);

