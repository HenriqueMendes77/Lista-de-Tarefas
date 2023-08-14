#include <stdio.h>
#include <string.h>

#define limite 20

//Variaveis da lista de tarefas
typedef struct{
    char item[100];
    int check;
} Tarefa;

//Função para adicionar tarefas
void add(Tarefa lista[], int *contador){
    while(*contador < limite){
        printf("\n-------------------------------------------------");
        printf("\nDigite '0' e pressione enter para salvar a lista.");
        printf("\nA lista suporta 20 itens no máximo.");
        printf("\n-------------------------------------------------\n");
        printf(">> ");
        char texto[100];
        scanf(" %[^\n]", texto);
        if (strcmp(texto, "0") == 0) {
            break;
        }
        if (*contador < limite) {
            strcpy(lista[*contador].item, texto);
            lista[*contador].check = 0;
            (*contador)++;
        } else {
            printf("Limite de tarefas atingido!\n");
        }
    }
}

//Função para mostrar a lista na tela
void exibir(Tarefa lista[], int contador){
    printf("\nLista de Tarefas:\n");
    for (int i = 0; i < contador; i++) {
        printf("%d. [%s] - %s\n", i + 1, lista[i].check ? "X" : " ", lista[i].item);
    }
}

//Função para marcar uma tarefa como concluída
void marcar(Tarefa lista[], int contador){
    int n;
    printf("Número da tarefa: ");
    scanf("%i", &n);
    if (n >= 1 && n <= contador) {
        lista[n-1].check = 1;
        printf("Tarefa concluída!\n");
    } else {
        printf("Número de tarefa inválido!\n");
    }
}

//Função para excluir tarefas
void excluir(Tarefa lista[], int *contador){
    int n;
    printf("Número da tarefa: ");
    scanf("%i", &n);
    if (n >= 1 && n <= *contador) {
        for (int i = n - 1; i < *contador - 1; i++) {
            lista[i] = lista[i + 1];
        }
        (*contador)--;
        printf("Tarefa excluida!\n");
    } else {
        printf("Número de tarefa inválido!\n");
    }
}

//Menu do programa
void menu(){
    printf("\n-------------------- MENU --------------------");
    printf("\n1 - Adicionar Tarefa");
    printf("\n2 - Mostrar Lista");
    printf("\n3 - Concluir Tarefa");
    printf("\n4 - Excluir Tarefa");
    printf("\n0 - Sair");
    printf("\n------------------------------------------------");
}

int main() {
    Tarefa lista[limite];
    int conta_tarefa = 0;
    int op;

    while(1){
        menu();
        printf("\nEscolha uma opção: ");
        scanf("%i", &op);

        switch(op){
            case 1:
                add(lista, &conta_tarefa);
                break;

            case 2:
                exibir(lista, conta_tarefa);
                break;

            case 3:
                marcar(lista, conta_tarefa);
                break;
            
            case 4:
                excluir(lista, &conta_tarefa);
                break;
            
            case 0:
                printf("\nSaindo...");
                return 0;
                break;

            default:
                printf("\nOpção inválida");
                break;
        }
    }

    return 0;
}
