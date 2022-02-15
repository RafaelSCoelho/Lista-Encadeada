#pragma once
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

typedef int TipoChave;


typedef struct TipoProduto {
    int codigo;
    char nome[MAX];
    int quantidade;
    float preco;
}TipoProduto;

typedef struct TipoCelula* TipoApontador;

typedef struct TipoCelula {

    TipoProduto item;
    TipoApontador Prox;
} TipoCelula;

TipoCelula cod;

typedef struct {
    TipoApontador Primeiro, Ultimo;
} TipoLista;

//Functions

void FLVazia();
int Vazia();
int avisoC();
void Compra();
void venda();
void estoque();
void Imprime();