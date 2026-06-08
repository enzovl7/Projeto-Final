#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQUIVO "tarefas.txt"

typedef struct No {
    char tarefa[100];
    struct No *prox;
} No;

No *topo = NULL;

// Adiciona uma tarefa no topo da pilha
void adicionarTarefa(char texto[]) {
    No *novo = malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro de memoria.\n");
        return;
    }

    strcpy(novo->tarefa, texto);
    novo->prox = topo;
    topo = novo;
}

// Lista todas as tarefas
void listarTarefas() {
    No *aux = topo;

    if (aux == NULL) {
        printf("Nenhuma tarefa cadastrada.\n");
        return;
    }

    printf("\n=== Tarefas Cadastradas ===\n");

    while (aux != NULL) {
        printf("- %s\n", aux->tarefa);
        aux = aux->prox;
    }
}

// Conclui a tarefa do topo
void concluirTarefa() {
    No *remover;

    if (topo == NULL) {
        printf("Nao existem tarefas para concluir.\n");
        return;
    }

    remover = topo;
    topo = topo->prox;

    printf("Tarefa concluida: %s\n", remover->tarefa);

    free(remover);
}

// Salva as tarefas no arquivo
void salvarArquivo() {
    FILE *arquivo = fopen(ARQUIVO, "w");
    No *aux = topo;

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    while (aux != NULL) {
        fprintf(arquivo, "%s\n", aux->tarefa);
        aux = aux->prox;
    }

    fclose(arquivo);
}

// Carrega as tarefas do arquivo
void carregarArquivo() {
    FILE *arquivo = fopen(ARQUIVO, "r");
    char texto[100];

    if (arquivo == NULL) {
        return;
    }

    while (fgets(texto, sizeof(texto), arquivo) != NULL) {
        texto[strcspn(texto, "\n")] = '\0';
        adicionarTarefa(texto);
    }

    fclose(arquivo);
}

// Libera a memoria antes de encerrar
void liberarMemoria() {
    No *aux;

    while (topo != NULL) {
        aux = topo;
        topo = topo->prox;
        free(aux);
    }
}

int main() {
    int opcao;
    char texto[100];

    carregarArquivo();

    do {
        printf("\n=== Sistema de Tarefas com Pilha ===\n");
        printf("1 - Adicionar tarefa\n");
        printf("2 - Listar tarefas\n");
        printf("3 - Concluir ultima tarefa adicionada\n");
        printf("4 - Salvar e sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {

            case 1:
                printf("Digite a tarefa: ");
                fgets(texto, sizeof(texto), stdin);
                texto[strcspn(texto, "\n")] = '\0';

                adicionarTarefa(texto);
                printf("Tarefa adicionada com sucesso.\n");
                break;

            case 2:
                listarTarefas();
                break;

            case 3:
                concluirTarefa();
                break;

            case 4:
                salvarArquivo();
                liberarMemoria();
                printf("Dados salvos. Encerrando sistema...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 4);

    return 0;
}