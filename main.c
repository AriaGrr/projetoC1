#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcoes.h"

#ifdef _WIN32 // Verifica se é Windows
    #define CLEAR_SCREEN "cls"
    #define PAUSE "pause"
#else
    #define CLEAR_SCREEN "clear"
    #define PAUSE "read -p 'Pressione Enter para continuar...' -n1 -s"
#endif

int main (){
    setlocale(LC_ALL, "Portuguese");

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
            system(CLEAR_SCREEN);
        } else if (opcao == 2){
            deletarTarefa(&lt);
            system(CLEAR_SCREEN);
        } else if (opcao == 3){
            system(CLEAR_SCREEN);
            listarTarefa(lt);
            
            printf("Pressione Enter para voltar ao menu...");
            getchar(); // Captura o Enter
            getchar(); // Aguarda o próximo Enter

            system(CLEAR_SCREEN);
        } else {
            wprintf(L"Opção não existe!\n");
        }
    } while (opcao != 0);

    cod = salvarLista(lt, arquivo);
    if (cod != 0){
        printf("Erro ao salvar tarefas!\n");
    }
    return 0;
}
