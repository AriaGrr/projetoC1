#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Cria uma nova tarefa e adiciona na lista
int criarTarefa(ListaDeTarefas *lt) {
    if (lt->qtd < 100) {
        printf("Criar tarefa:\n");

        // Limpando o buffer do teclado antes de ler a categoria
        while (getchar() != '\n');

        wprintf(L"Digite a categoria (até 100 caracteres): ");
        fgetws(lt->tarefas[lt->qtd].categoria, sizeof(lt->tarefas[lt->qtd].categoria), stdin);

        // Limpando o buffer do teclado antes de ler a descrição
        while (getchar() != '\n');

        wprintf(L"Digite a descrição (até 300 caracteres): ");
        fgetws(lt->tarefas[lt->qtd].descricao, sizeof(lt->tarefas[lt->qtd].descricao), stdin);

        printf("Digite a prioridade (de 1 a 10): ");
        scanf("%d", &lt->tarefas[lt->qtd].prioridade);

        lt->qtd++;
        return 0;
    } else {
        wprintf(L"Lista de tarefas está cheia.\n");
        return 1;
    }
}

// Deleta uma tarefa da lista
int deletarTarefa(ListaDeTarefas *lt) {
    if (lt->qtd > 0) {
        printf("Deletar tarefa:\n");
        int pos;

        wprintf(L"Digite a posição da tarefa (1 a 100): ");
        scanf("%d", &pos);
        pos--;

        if (pos >= 0 && pos < lt->qtd) {
            for (int i = pos; i < lt->qtd - 1; i++) {
                lt->tarefas[i] = lt->tarefas[i + 1];
            }

            lt->qtd--;
            return 0;
        } else {
            wprintf(L"Posição invalida.\n");
            return 1;
        }
    } else {
        printf("Lista de tarefas vazia.\n");
        return 1;
    }
}

// Mostra a lista de tarefas e retorna 0 se a lista não estiver vazia
int listarTarefa(ListaDeTarefas lt) {
    printf("Lista de tarefas\n");
    printf("Quantidade de tarefas: %d\n", lt.qtd);
    printf("\n");
    
    if (lt.qtd == 0) {
        wprintf(L"A lista de tarefas está vazia.\n");
        return 1; 
    }

    for (int i = 0; i < lt.qtd; i++) {
        printf("Tarefa %d\n", i + 1);
        wprintf(L"Categoria: %s", lt.tarefas[i].categoria);
        wprintf(L"Descrição: %ls", lt.tarefas[i].descricao);
        printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
        printf("\n");
    }

    return 0; 
}

// Mostra o menu
void printMenu(){
    setlocale(LC_ALL, "Portuguese");
    printf("Menu\n");
    printf("1 - Criar tarefa\n");
    printf("2 - Deletar tarefa\n");
    printf("3 - Listar tarefas\n");
    printf("0 - Sair\n");
    wprintf(L"Digite a opção desejada: ");
}

// Salva a lista de tarefas em um arquivo
// fwrite
int salvarLista(ListaDeTarefas lt, char nome[]) {
    FILE *arquivo;
    arquivo = fopen(nome, "wb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    for (int i = 0; i < lt.qtd; i++) {
        fwrite(&lt.tarefas[i], sizeof(Tarefa), 1, arquivo);
    }

    fclose(arquivo);
    return 0;
}

// Carrega a lista de tarefas de um arquivo
// fread
int carregarLista(ListaDeTarefas *lt, char nome[]) {
    FILE *arquivo;
    arquivo = fopen(nome, "rb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    lt->qtd = 0; // Inicialize o contador de tarefas carregadas

    while (fread(&lt->tarefas[lt->qtd], sizeof(Tarefa), 1, arquivo) == 1) {
        lt->qtd++;
    }

    fclose(arquivo);
    return 0;
}
