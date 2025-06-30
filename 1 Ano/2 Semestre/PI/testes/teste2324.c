#include <stdlib.h>
#include <stdio.h>

void rodaEsq(int a[], int N, int r) {
    // Array auxiliar para armazenar os primeiros r elementos
    int temp[r];
    
    // Copiar os primeiros r elementos para o array auxiliar
    for (int i = 0; i < r; i++) {
        temp[i] = a[i];
    }

    // Deslocar os elementos restantes para a esquerda
    for (int i = 0; i < N - r; i++) {
        a[i] = a[i + r];
    }

    // Copiar os elementos do array auxiliar para o final do array
    for (int i = 0; i < r; i++) {
        a[N - r + i] = temp[i];
    }
}

typedef struct lint_nodo {
    int valor;
    struct lint_nodo *prox;
} *LInt;

int delete(int n, LInt *l) {
    if (*l == NULL) {
        return 1; // Lista vazia, erro
    }
    if (n == 0) {
        // Remover o primeiro elemento
        LInt temp = *l;
        *l = (*l)->prox;
        free(temp);
        return 0; // Sucesso
    }
    LInt current = *l;
    for (int i = 0; i < n - 1; i++) {
        if (current == NULL || current->prox == NULL) {
            return 1; // Índice fora dos limites, erro
        }
        current = current->prox;
    }
    // Remover o n-ésimo elemento
    LInt temp = current->prox;
    if (temp == NULL) {
        return 1; // Índice fora dos limites, erro
    }
    current->prox = temp->prox;
    free(temp);
    return 0; // Sucesso
}

int maxCresc(LInt l) {
    if (l == NULL) return 0; // Lista vazia, comprimento é 0
    int currentLength = 1, maxLength = 1;
    while (l->prox != NULL) {
        if (l->valor < l->prox->valor) {
            currentLength++; // Sequência crescente continua
        } else {
            if (currentLength > maxLength) {
                maxLength = currentLength; // Atualizar comprimento máximo
            }
            currentLength = 1; // Reiniciar comprimento atual
        }
        l = l->prox; // Avançar para o próximo nó
    }

    // Garantir que a última sequência seja considerada
    if (currentLength > maxLength) {
        maxLength = currentLength;
    }

    return maxLength;
}

typedef struct abin_nodo {
    int valor;
    struct abin_nodo *esq, *dir;
} *ABin;

ABin folhaEsq(ABin a) {
    if (a == NULL) return NULL; // Árvore vazia

    if (a->esq == NULL && a->dir == NULL) {
        return a; // Nó atual é uma folha
    }

    ABin folha = folhaEsq(a->esq); // Procurar na subárvore esquerda
    if (folha != NULL) {
        return folha; // Retornar a folha encontrada na esquerda
    }

    return folhaEsq(a->dir); // Procurar na subárvore direita
}

// Função auxiliar para verificar correspondência de parênteses
int corresponde(char abertura, char fechamento) {
    return (abertura == '(' && fechamento == ')') ||
           (abertura == '[' && fechamento == ']') ||
           (abertura == '{' && fechamento == '}');
}

// Função para verificar se os parênteses estão corretos
int parentesisOk(char exp[]) {
    char pilha[100];
    int topo = -1;

    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        // Empilhar parênteses de abertura
        if (c == '(' || c == '[' || c == '{') {
            if (topo == 100 - 1) return 0; // Pilha cheia
            pilha[++topo] = c;
        }
        // Verificar parênteses de fechamento
        else if (c == ')' || c == ']' || c == '}') {
            if (topo == -1 || !corresponde(pilha[topo], c)) {
                return 0; // Pilha vazia ou parêntese não corresponde
            }
            topo--; // Desempilhar
        }
    }

    // Verificar se a pilha está vazia no final
    return topo == -1;
}