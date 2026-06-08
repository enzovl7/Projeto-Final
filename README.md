# Gerenciador de Tarefas com Pilha

## Descrição

Este projeto foi desenvolvido em linguagem C e tem como objetivo gerenciar tarefas utilizando uma estrutura de dados encadeada do tipo Pilha.

O sistema funciona através de um menu interativo no terminal, permitindo que o usuário adicione tarefas, visualize as tarefas cadastradas e conclua tarefas.

Todas as tarefas ficam armazenadas em uma pilha. Dessa forma, a última tarefa adicionada será sempre a primeira tarefa a ser removida quando o usuário escolher a opção de concluir tarefa.

Além disso, o sistema possui persistência em arquivo, ou seja, as tarefas são salvas em um arquivo de texto e permanecem armazenadas mesmo após o encerramento do programa.

Ao iniciar o sistema, o arquivo é lido automaticamente e as tarefas são carregadas para a memória. Ao sair, todas as tarefas são salvas novamente.

## Problema Resolvido

Muitas vezes o usuário precisa manter uma lista simples de atividades para realizar durante o dia.

Este sistema permite cadastrar essas atividades e organizá-las utilizando o conceito de pilha.

A proposta é demonstrar a utilização prática de estruturas de dados encadeadas em um problema simples e fácil de entender.

## Estrutura de Dados Utilizada

O projeto utiliza apenas uma Pilha Encadeada.

Uma pilha é uma estrutura de dados que segue o princípio LIFO (Last In, First Out), que significa "o último que entra é o primeiro que sai".

Exemplo:

1. Estudar Estrutura de Dados
2. Fazer Trabalho de C
3. Revisar para a Prova

Neste caso, a tarefa "Revisar para a Prova" foi a última adicionada e será a primeira a ser concluída.

A pilha foi escolhida porque ela atende perfeitamente ao funcionamento proposto pelo sistema e permite demonstrar o uso de nós encadeados e ponteiros.

## Funcionamento da Estrutura

Cada tarefa é armazenada em um nó.

Cada nó possui:

- A descrição da tarefa.
- Um ponteiro para o próximo nó da pilha.

Estrutura utilizada:

```c
typedef struct No {
    char tarefa[100];
    struct No *prox;
} No;
