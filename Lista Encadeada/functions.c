#include "Cabeçalho.h"

/* ========================================================================= */

void FLVazia(TipoLista* Lista)
{
    Lista->Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
}

int Vazia(TipoLista Lista)
{
    return (Lista.Primeiro == Lista.Ultimo);
}

void Compra(TipoCelula celula, TipoLista* Lista)
{
    TipoApontador q;
    int i;
    Lista->Ultimo->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->item.codigo = celula.item.codigo;
    for (i = 0; i < MAX; i++) {
        Lista->Ultimo->item.nome[i] = celula.item.nome[i];
    }
    Lista->Ultimo->item.quantidade = celula.item.quantidade;
    Lista->Ultimo->item.preco = celula.item.preco;
    Lista->Ultimo->Prox = NULL;
}


int avisoC(TipoCelula celula, TipoLista* Lista) {
    TipoApontador Aux;

    Aux = Lista->Primeiro->Prox;
    while (Aux != NULL) {

        if (celula.item.codigo == Aux->item.codigo) {
            printf("|-|\n");
            printf("|-|Erro: Codigo ja cadastrado.\n");
            return 1;
        }
        Aux = Aux->Prox;
    }
}

void venda(int code, TipoLista* Lista)
{
    TipoApontador Aux;
    int quant = 0, x = 0;
    float soma, preco = 0;

    if (Vazia(*Lista))
    {
        printf("|-|\n");
        printf("|-|Erro: Lista vazia\n");
        return;
    }

    Aux = Lista->Primeiro->Prox;

    while (Aux != NULL) {
        if (Aux->item.codigo == code) {
            printf("|-|\n");
            printf("|-|Produto: %s\n", Aux->item.nome);
            printf("|-|\n");
            printf("|-|Preco: R$%.2f\n", Aux->item.preco);
            preco = Aux->item.preco;
            printf("|-|\n");
            printf("|-|Quantidade: ");
            (scanf_s("%d", &x));
            if (x > Aux->item.quantidade) {
                printf("|-|\n");
                printf("|-|Erro: Estoque insuficiente. Quantidade disponivel: %d", Aux->item.quantidade);
                return;
            }
            Aux->item.quantidade = Aux->item.quantidade - x;
        }
        if (Aux == Lista->Ultimo && Aux->item.codigo != code) {
            printf("|-|\n");
            printf("|-|Erro: Codigo nao cadastrado.\n");
            return;
        }
        Aux = Aux->Prox;
    }
    soma = x * preco;
    printf("|-|\n");
    printf("|-|Total da compra: R$%.2f\n", soma);
}


void estoque(int code, TipoLista* Lista)
{
    TipoApontador Aux;
    Aux = Lista->Primeiro;

    while (Aux != NULL) {
        if (Aux->item.codigo == code) {
            printf("|-|\n");
            printf("|-|Codigo: %d |Descricao: %s |Quantidade: %d | Preco: R$%.2f | \n", Aux->item.codigo, Aux->item.nome, Aux->item.quantidade, Aux->item.preco);
            return;
        }
        if (Aux == Lista->Ultimo && Aux->item.codigo != code) {
            printf("|-|\n");
            printf("|-|Erro: Codigo nao cadastrado.\n");
            return;
        }
        Aux = Aux->Prox;
    }
}

void Imprime(TipoLista Lista)
{
    TipoApontador Aux;
    Aux = Lista.Primeiro->Prox;
    if (Aux == NULL) {
        printf("|-|\n");
        printf("|-|Estoque vazio.\n");
    }
    while (Aux != NULL) {
        printf("|-|\n");
        printf("|-|Codigo: %d |Descricao: %s |Quantidade: %d | Preco: R$%.2f |\n", Aux->item.codigo, Aux->item.nome, Aux->item.quantidade, Aux->item.preco);
        Aux = Aux->Prox;
    }
}