#include <stdlib.h>

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

int length(LInt l) {
    int count = 0; // Inicializa o contador
    while (l != NULL) { // Percorre a lista enquanto não for NULL
        count++; // Incrementa o contador
        l = l->prox; // Avança para o próximo nó
    }
    return count; // Retorna o comprimento da lista
}

void freeL(LInt l) {
    LInt temp;
    while (l != NULL) { // Percorre a lista enquanto não for NULL
        temp = l->prox; // Guarda o próximo nó
        free(l);        // Libera o nó atual
        l = temp;       // Avança para o próximo nó
    }
}

void insertOrd(LInt *l, int x) {
    LInt newNode = malloc(sizeof(struct lligada)); // Cria o novo nó
    if (newNode == NULL) return; // Verifica falha na alocação
    newNode->valor = x;
    newNode->prox = NULL;

    // Caso a lista esteja vazia ou o valor seja menor que o primeiro elemento
    if (*l == NULL || (*l)->valor > x) {
        newNode->prox = *l;
        *l = newNode;
        return;
    }

    // Percorre a lista para encontrar a posição correta
    LInt current = *l;
    while (current->prox != NULL && current->prox->valor < x) {
        current = current->prox;
    }

    // Insere o novo nó na posição correta
    newNode->prox = current->prox;
    current->prox = newNode;
}

void merge(LInt *r, LInt a, LInt b) {
    LInt *last = r; // Ponteiro para o final da lista resultante

    while (a != NULL && b != NULL) {
        if (a->valor < b->valor) {
            *last = a;       // Adiciona o nó de 'a' à lista resultante
            a = a->prox;     // Avança o ponteiro de 'a'
        } else {
            *last = b;       // Adiciona o nó de 'b' à lista resultante
            b = b->prox;     // Avança o ponteiro de 'b'
        }
        last = &((*last)->prox); // Avança o ponteiro final
    }

    // Anexa os nós restantes de 'a' ou 'b'
    *last = (a != NULL) ? a : b;
}

void splitQS(LInt l, int x, LInt *mx, LInt *Mx) {
    *mx = NULL; // Inicializa a lista de menores
    *Mx = NULL; // Inicializa a lista de maiores ou iguais
    LInt *lastMx = mx, *lastMxRest = Mx; // Ponteiros para o final de cada lista

    while (l != NULL) {
        if (l->valor < x) {
            *lastMx = l;         // Adiciona o nó à lista de menores
            lastMx = &((*lastMx)->prox); // Avança o ponteiro final
        } else {
            *lastMxRest = l;     // Adiciona o nó à lista de maiores ou iguais
            lastMxRest = &((*lastMxRest)->prox); // Avança o ponteiro final
        }
        l = l->prox; // Avança para o próximo nó da lista original
    }

    *lastMx = NULL;     // Garante que a lista de menores termine em NULL
    *lastMxRest = NULL; // Garante que a lista de maiores termine em NULL
}

int removeAll(LInt *l, int x) {
    int count = 0; // Contador de elementos removidos
    LInt current = *l, prev = NULL;

    while (current != NULL) {
        if (current->valor == x) {
            LInt temp = current; // Nó a ser removido
            if (prev == NULL) {
                *l = current->prox; // Atualiza o início da lista
            } else {
                prev->prox = current->prox; // Pula o nó atual
            }
            current = current->prox; // Avança para o próximo nó
            free(temp); // Libera a memória do nó removido
            count++; // Incrementa o contador
        } else {
            prev = current; // Atualiza o nó anterior
            current = current->prox; // Avança para o próximo nó
        }
    }

    return count; // Retorna o número de elementos removidos
}

int removeMaiorL(LInt *l) {
    if (*l == NULL) return 0; // Lista vazia, não deveria ocorrer

    LInt current = *l, prev = NULL;
    LInt maxNode = *l, maxPrev = NULL;

    // Encontrar o maior elemento
    while (current != NULL) {
        if (current->valor > maxNode->valor) {
            maxNode = current;
            maxPrev = prev;
        }
        prev = current;
        current = current->prox;
    }

    // Remover o maior elemento
    if (maxPrev == NULL) {
        *l = maxNode->prox; // O maior elemento é o primeiro da lista
    } else {
        maxPrev->prox = maxNode->prox; // Pula o maior elemento
    }

    int maxValue = maxNode->valor; // Armazena o valor do maior elemento
    free(maxNode); // Libera a memória do nó removido

    return maxValue; // Retorna o valor do maior elemento
}

void appendL(LInt *l, int x) {
    // Criar um novo nó
    LInt newNode = (LInt)malloc(sizeof(struct lligada));
    newNode->valor = x;
    newNode->prox = NULL;

    // Verificar se a lista está vazia
    if (*l == NULL) {
        *l = newNode; // Novo nó se torna o primeiro elemento
    } else {
        LInt current = *l;
        // Percorrer até o último nó
        while (current->prox != NULL) {
            current = current->prox;
        }
        current->prox = newNode; // Apontar o último nó para o novo nó
    }
}

LInt cloneRev(LInt l) {
    LInt newList = NULL; // Nova lista inicializada como vazia

    while (l != NULL) {
        // Criar um novo nó
        LInt newNode = (LInt)malloc(sizeof(struct lligada));
        newNode->valor = l->valor;
        newNode->prox = newList; // Inserir no início da nova lista

        newList = newNode; // Atualizar o início da nova lista
        l = l->prox; // Avançar na lista original
    }

    return newList; // Retornar a nova lista
}

int take(int n, LInt *l) {
    if (n <= 0) {
        // Liberar toda a lista se n <= 0
        while (*l != NULL) {
            LInt temp = *l;
            *l = (*l)->prox;
            free(temp);
        }
        return 0;
    }

    LInt current = *l;
    int count = 0;

    // Percorrer até o n-ésimo nó
    while (current != NULL && count < n - 1) {
        current = current->prox;
        count++;
    }

    // Se ainda houver nós após o n-ésimo, liberar o restante
    if (current != NULL && current->prox != NULL) {
        LInt temp = current->prox;
        current->prox = NULL; // Finalizar a lista no n-ésimo nó
        while (temp != NULL) {
            LInt next = temp->prox;
            free(temp);
            temp = next;
        }
    }

    // Retornar o comprimento final da lista
    return (count + 1);
}

int drop(int n, LInt *l) {
    int count = 0;

    // Remover os primeiros n nós
    while (*l != NULL && count < n) {
        LInt temp = *l;       // Nó atual a ser removido
        *l = (*l)->prox;      // Avançar para o próximo nó
        free(temp);           // Liberar o nó atual
        count++;              // Incrementar o contador
    }

    // Retornar o número de elementos removidos
    return count;
}

LInt Nforward(LInt l, int N) {
    if (l == NULL) {
        return NULL; // Lista vazia
    }

    // Avançar N posições na lista circular
    for (int i = 0; i < N; i++) {
        l = l->prox;
    }

    return l; // Retornar o endereço do elemento N posições à frente
}

LInt arrayToList(int v[], int N) {
    if (N == 0) {
        return NULL; // Array vazio, lista vazia
    }

    // Criar o primeiro nó da lista
    LInt head = (LInt)malloc(sizeof(struct lligada));
    head->valor = v[0];
    head->prox = NULL;

    LInt current = head;

    // Criar os nós restantes
    for (int i = 1; i < N; i++) {
        LInt newNode = (LInt)malloc(sizeof(struct lligada));
        newNode->valor = v[i];
        newNode->prox = NULL;

        current->prox = newNode; // Ligar o nó atual ao próximo
        current = newNode;       // Avançar para o próximo nó
    }

    return head; // Retornar o início da lista
}

LInt somasAcL(LInt l) {
    if (l == NULL) {
        return NULL; // Lista original vazia
    }

    // Criar o primeiro nó da nova lista
    LInt newHead = (LInt)malloc(sizeof(struct lligada));
    newHead->valor = l->valor; // Primeiro valor acumulado é o próprio valor
    newHead->prox = NULL;

    LInt currentOriginal = l->prox; // Ponteiro para a lista original
    LInt currentNew = newHead;      // Ponteiro para a nova lista
    int acumulador = newHead->valor; // Inicializar o acumulador com o primeiro valor

    // Percorrer a lista original e construir a nova lista
    while (currentOriginal != NULL) {
        acumulador += currentOriginal->valor; // Atualizar a soma acumulada

        // Criar um novo nó com a soma acumulada
        LInt newNode = (LInt)malloc(sizeof(struct lligada));
        newNode->valor = acumulador;
        newNode->prox = NULL;

        // Ligar o nó atual da nova lista ao novo nó
        currentNew->prox = newNode;
        currentNew = newNode; // Avançar na nova lista

        currentOriginal = currentOriginal->prox; // Avançar na lista original
    }

    return newHead; // Retornar o início da nova lista
}

LInt rotateL(LInt l) {
    if (l == NULL || l->prox == NULL) {
        return l; // Lista vazia ou com apenas um elemento
    }

    LInt head = l;         // Guardar o primeiro nó
    LInt newHead = l->prox; // O segundo nó será o novo início da lista

    // Percorrer até o último nó
    LInt current = l;
    while (current->prox != NULL) {
        current = current->prox;
    }

    current->prox = head; // Apontar o último nó para o primeiro nó
    head->prox = NULL;    // O antigo primeiro nó será o novo último nó

    return newHead; // Retornar o novo início da lista
}

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

int altura(ABin a) {
    if (a == NULL) {
        return 0; // Árvore vazia tem altura 0
    }

    int alturaEsq = altura(a->esq); // Altura da subárvore esquerda
    int alturaDir = altura(a->dir); // Altura da subárvore direita

    return 1 + (alturaEsq > alturaDir ? alturaEsq : alturaDir); // Maior altura + 1
}

ABin cloneAB(ABin a) {
    if (a == NULL) {
        return NULL; // Árvore vazia, nada para clonar
    }

    // Alocar memória para o novo nó
    ABin newNode = (ABin)malloc(sizeof(struct nodo));
    newNode->valor = a->valor; // Copiar o valor do nó atual

    // Clonar recursivamente as subárvores
    newNode->esq = cloneAB(a->esq);
    newNode->dir = cloneAB(a->dir);

    return newNode; // Retornar o novo nó
}

void inorder(ABin a, LInt *l) {
    if (a == NULL) {
        return; // Árvore vazia, nada a fazer
    }

    // Percorrer a subárvore esquerda
    inorder(a->esq, l);

    // Criar um novo nó para a lista ligada
    LInt newNode = (LInt)malloc(sizeof(struct lligada));
    newNode->valor = a->valor;
    newNode->prox = NULL;

    // Adicionar o novo nó ao final da lista
    while (*l != NULL) {
        l = &((*l)->prox);
    }
    *l = newNode;

    // Percorrer a subárvore direita
    inorder(a->dir, l);
}

void preorder(ABin a, LInt *l) {
    if (a == NULL) {
        return; // Árvore vazia, nada a fazer
    }

    // Criar um novo nó para a lista ligada
    LInt newNode = (LInt)malloc(sizeof(struct lligada));
    newNode->valor = a->valor;
    newNode->prox = NULL;

    // Adicionar o novo nó ao final da lista
    while (*l != NULL) {
        l = &((*l)->prox);
    }
    *l = newNode;

    // Percorrer a subárvore esquerda
    preorder(a->esq, l);

    // Percorrer a subárvore direita
    preorder(a->dir, l);
}

void posorder(ABin a, LInt *l) {
    if (a == NULL) {
        return; // Árvore vazia, nada a fazer
    }

    // Percorrer a subárvore esquerda
    posorder(a->esq, l);

    // Percorrer a subárvore direita
    posorder(a->dir, l);

    // Criar um novo nó para a lista ligada
    LInt newNode = (LInt)malloc(sizeof(struct lligada));
    newNode->valor = a->valor;
    newNode->prox = NULL;

    // Adicionar o novo nó ao final da lista
    while (*l != NULL) {
        l = &((*l)->prox);
    }
    *l = newNode;
}

int freeAB(ABin a) {
    if (a == NULL) {
        return 0; // Árvore vazia, nenhum nó para liberar
    }

    // Liberar subárvore esquerda e contar nós
    int leftCount = freeAB(a->esq);

    // Liberar subárvore direita e contar nós
    int rightCount = freeAB(a->dir);

    // Liberar o nó atual
    free(a);

    // Retornar o total de nós libertados
    return 1 + leftCount + rightCount;
}

int pruneAB(ABin *a, int l) {
    if (*a == NULL) {
        return 0; // Árvore vazia, nenhum nó para remover
    }

    if (l < 1) {
        // Remover manualmente toda a árvore
        int count = 0;

        // Liberar subárvore esquerda
        count += pruneAB(&((*a)->esq), 0);

        // Liberar subárvore direita
        count += pruneAB(&((*a)->dir), 0);

        // Liberar o nó atual
        free(*a);
        *a = NULL;

        return count + 1; // Contar o nó atual
    }

    // Recorrer às subárvores
    int leftCount = pruneAB(&((*a)->esq), l - 1);
    int rightCount = pruneAB(&((*a)->dir), l - 1);

    // Retornar o total de nós removidos
    return leftCount + rightCount;
}

int iguaisAB(ABin a, ABin b) {
    if (a == NULL && b == NULL) {
        return 1; // Ambas as árvores são nulas, são iguais
    }

    if (a == NULL || b == NULL) {
        return 0; // Apenas uma das árvores é nula, não são iguais
    }

    if (a->valor != b->valor) {
        return 0; // Valores diferentes, não são iguais
    }

    // Verificar recursivamente as subárvores esquerda e direita
    return iguaisAB(a->esq, b->esq) && iguaisAB(a->dir, b->dir);
}

LInt nivelL(ABin a, int n) {
    if (a == NULL) {
        return NULL; // Árvore vazia, lista vazia
    }

    if (n == 1) {
        // Criar um novo nó da lista com o valor do nó atual
        LInt newNode = malloc(sizeof(struct lligada));
        newNode->valor = a->valor;
        newNode->prox = NULL;
        return newNode;
    }

    // Recorrer às subárvores
    LInt leftList = nivelL(a->esq, n - 1);
    LInt rightList = nivelL(a->dir, n - 1);

    // Concatenar as listas
    LInt current = leftList;
    if (current == NULL) {
        return rightList; // Apenas a lista da direita existe
    }

    while (current->prox != NULL) {
        current = current->prox; // Avançar até o final da lista esquerda
    }
    current->prox = rightList; // Concatenar com a lista da direita

    return leftList;
}

int depthOrd(ABin a, int x) {
    if (a == NULL) {
        return -1; // Árvore vazia, elemento não encontrado
    }

    if (a->valor == x) {
        return 1; // Elemento encontrado no nível atual
    }

    int depth;
    if (x < a->valor) {
        depth = depthOrd(a->esq, x); // Procurar na subárvore esquerda
    } else {
        depth = depthOrd(a->dir, x); // Procurar na subárvore direita
    }

    if (depth == -1) {
        return -1; // Elemento não encontrado
    }

    return depth + 1; // Somar 1 ao nível retornado
}

