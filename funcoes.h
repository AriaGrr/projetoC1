#include <stdio.h>

typedef struct {
    int prioridade;
    // Mudei o char para wchar_t, para que o programa aceite caracteres especiais
    wchar_t categoria[100];
    wchar_t descricao[300];
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

