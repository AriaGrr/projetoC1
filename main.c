#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
// Grupo ->
// Nome: Marjorie Luize Martins Costa
// RA: 242230845
// Nome: Antonio Roth Gorham
// RA: 241230788

int main(){

    int cod;
    char arquivo[] = "tarefas";
    ListaDeTarefas lt;

    cod = carregarLista(&lt, arquivo);
    if (cod == 1) {
        lt.qtd = 0;
    }
    int opcao;
    do{    
        printMenu();
        scanf("%d", &opcao);
        printf("%d\n", opcao);
        if(opcao == 0){
            printf("Saindo...\n");
        }
        else if (opcao == 1){
            criarTarefa(&lt);
            // Limpar o terminal
            system("clear");
        } else if (opcao == 2){
            deletarTarefa(&lt);
            system("clear");
        } else if (opcao == 3){
            system("clear");
            listarTarefa(lt);
            
            printf("Pressione Enter para voltar ao menu...");
            getchar(); // Captura o Enter
            getchar(); // Aguarda o próximo Enter

            system("clear");
        } else {
            printf("Opção não existe!\n");
        }
    } while (opcao != 0);

    cod = salvarLista(lt, arquivo);
    if (cod != 0){
        printf("Erro ao salvar tarefas!\n");
    }
    return 0;
}
