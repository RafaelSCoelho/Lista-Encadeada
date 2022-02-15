#include "Cabeçalho.h"

int main()
{
    TipoLista lista;
    FLVazia(&lista);
    TipoCelula celula;
    int op = 1, code;
    static char conf, o, y[MAX];
    do {
        system("cls");
        printf("\n|-|-------------------------------------------------------|-|");
        printf("\n|-|-------------------------------------------------------|-|");
        printf("\n|-|[1]--Compra de produtos                                |-|");
        printf("\n|-|-------------------------------------------------------|-|");
        printf("\n|-|[2]--Venda de podutos                                  |-|");
        printf("\n|-|-------------------------------------------------------|-|");
        printf("\n|-|[3]--Lista de produtos                                 |-|");
        printf("\n|-|-------------------------------------------------------|-|");
        printf("\n|-|[4]--Consultar estoque de produtos                     |-|");
        printf("\n|-|-------------------------------------------------------|-|");
        printf("\n|-|[5]--Sair                                              |-|");
        printf("\n|-|-------------------------------------------------------|-|");
        printf("\n|-|-------------------------------------------------------|-|");
        printf("\n|-|Opcao: ");
        o = (toupper(_getche()));

        switch (o) {

        case '1':
            do {
                printf("\n|-|");
                printf("\n|-|-------------------------------------------------------|-|\n");
                printf("|-|\n");
                printf("|-|Compra de Produtos\n");
                printf("|-|\n");
                printf("|-|Digite o Codigo: ");
                scanf_s("%d", &celula.item.codigo);
                if (avisoC(celula, &lista) == 1) {
                    printf("|-|\n");
                    printf("|-|Aperte ENTER para voltar ao menu.");
                    fflush(stdin);
                    scanf_s("%c", &conf, 1);
                    break;
                }
                printf("|-|\n");
                printf("|-|Descricao do Produto: ");
                scanf_s("%s", celula.item.nome, (unsigned)_countof(celula.item.nome));
                printf("|-|\n");
                printf("|-|Quantidade do Produto: ");
                scanf_s("%d", &celula.item.quantidade);
                printf("|-|\n");
                printf("|-|Preco R$: ");
                scanf_s("%f", &celula.item.preco);
                Compra(celula, &lista);
                printf("|-|\n");
                printf("|-|Cadastrar mais um produto? (s/n)");
                fflush(stdin);
                scanf_s("%c", &conf, 1);
                while (conf != 's' && conf != 'n') {
                    printf("|-|\n");
                    printf("|-|Opcao invalida!\n");
                    printf("|-|\n");
                exitop1:
                    printf("|-|Cadastrar mais um produto? (s/n)");
                    fflush(stdin);
                    scanf_s("%c", &conf, 1);
                }
            } while (conf != 'n');
            break;

        case '2':
            fflush(stdin);
            printf("\n|-|");
            printf("\n|-|-------------------------------------------------------|-|\n");
            printf("|-|\n");
            printf("|-|Venda de Produtos\n");
            printf("|-|\n");
            printf("|-|Digite o Codigo: ");
            scanf_s("%d", &code);
            venda(code, &lista);
            printf("\n|-|\n");
            printf("|-|Aperte ENTER para voltar ao menu.");
            fflush(stdin);
            scanf_s("%c", &conf, 1);
            break;

        case '3':
            fflush(stdin);
            printf("\n|-|");
            printf("\n|-|-------------------------------------------------------|-|\n");
            printf("|-|\n");
            printf("|-|Lista de Produtos\n");
            Imprime(lista);
            printf("|-|\n");
            printf("|-|Aperte ENTER para voltar ao menu.");
            fflush(stdin);
            scanf_s("%c", &conf, 1);
            break;

        case '4':
            fflush(stdin);
            printf("\n|-|");
            printf("\n|-|-------------------------------------------------------|-|\n");
            printf("|-|\n");
            printf("|-|Estoque da Empresa\n");
            printf("|-|\n");
            printf("|-|Digite o Codigo: ");
            scanf_s("%d", &code);
            estoque(code, &lista);
            printf("|-|\n");
            printf("|-|Aperte ENTER para voltar ao menu.");
            fflush(stdin);
            scanf_s("%c", &conf, 1);

            break;

        case '5':
            fflush(stdin);
            printf("\n|-|");
            printf("\n|-|-------------------------------------------------------|-|\n");
            printf("|-|\n");
            printf("|-| Saindo do programa...\n");

            break;

        default:
            printf("\n|-|");
            printf("\n|-|-------------------------------------------------------|-|\n");
            printf("|-|\n");
            printf("|-| Opcao invalida\n");
            printf("|-|\n");
            printf("|-|Aperte ENTER para voltar ao menu.");
            fflush(stdin);
            scanf_s("%c", &conf, 1);
            break;
        }
    } while (o != '5');

    return 0;
}


