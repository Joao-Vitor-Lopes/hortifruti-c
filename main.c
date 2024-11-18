#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Definindo função para exibir a lista de produtos

void exibirFrutas() {
    FILE *file = fopen("frutas.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo frutas.txt.\n");
        return;
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), file)) {
        printf("%s", linha);
    }
    fclose(file);
}

void exibirLegumes() {
    FILE *file = fopen("legumes.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo legumes.txt.\n");
        return;
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), file)) {
        printf("%s", linha);
    }
    fclose(file);
}

void exibirVerduras() {
    FILE *file = fopen("verduras.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo verduras.txt.\n");
        return;
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), file)) {
        printf("%s", linha);
    }
    fclose(file);
}

void exibirErvasTemperos() {
    FILE *file = fopen("ervas_temperos.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo ervas_temperos.txt.\n");
        return;
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), file)) {
        printf("%s", linha);
    }
    fclose(file);
}

void exibirTuberculosRaizes() {
    FILE *file = fopen("tuberculos_raizes.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo tuberculos_raizes.txt.\n");
        return;
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), file)) {
        printf("%s", linha);
    }
    fclose(file);
}

void exibirOutrosProdutos() {
    FILE *file = fopen("outros_produtos.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo outros_produtos.txt.\n");
        return;
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), file)) {
        printf("%s", linha);
    }
    fclose(file);
}
typedef struct {
    char nome[50];
    float preco;
} Produto;

void carregarProdutos(const char *nomeArquivo, Produto produtos[], int *quantidade) {
    FILE *file = fopen(nomeArquivo, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nomeArquivo);
        return;
    }

    *quantidade = 0;
    while (fscanf(file, "%s %f", produtos[*quantidade].nome, &produtos[*quantidade].preco) == 2) {
        (*quantidade)++;
    }
    fclose(file);
}

float buscarPrecoProduto(const Produto produtos[], int quantidade, const char *nomeProduto) {
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(produtos[i].nome, nomeProduto) == 0) {
            return produtos[i].preco;
        }
    }
    return -1.0; // Retorna -1 se o produto não for encontrado
}

int main() {
    setlocale(LC_ALL, "portuguese");
    int opcao, repeat=1, pagamento;
    float totalc, totalpr, peso, quant;
    Produto produtos[100];
    int quantidadeProdutos;
    char nomeProduto[50];

    printf("Olá, bem-vindo ao hortifruti Hortmix!\n\n");
    printf("Deseja continuar e fazer uma compra conosco?\nNúmero 1 para continuar\nQualquer outro número para sair\n");
    int i;
    scanf("%d", &i);

    system("cls");
    while (repeat == 1){
        if (i == 1) {
        system("cls");
        printf("\nO que deseja comprar?\n");
        printf("\n=== Menu ===\n\n");
        printf("1. Frutas\n");
        printf("2. Legumes\n");
        printf("3. Verduras\n");
        printf("4. Ervas e Temperos\n");
        printf("5. Tubérculos e Raízes\n");
        printf("6. Outros Produtos Naturais\n");
        printf("\n0. Sair\n\n");
        scanf("%d", &opcao);

        const char *nomeArquivo;
        switch (opcao) {
            case 1:
                system("cls");
                printf("\n=== Frutas ===\n\n");
                exibirFrutas();
                printf("\nEssa é a tabela por kg dos produtos\n\n");
                nomeArquivo = "frutas.txt";
                break;
            case 2:
                 system("cls");
                printf("\n=== Legumes ===\n\n");
                exibirLegumes();
                printf("\nEssa é a tabela por kg dos produtos\n\n");
                nomeArquivo = "legumes.txt";
                break;
            case 3:
                 system("cls");
                printf("\n=== Verduras ===\n\n");
                exibirVerduras();
                printf("\nEssa é a tabela por quantidade dos produtos\n\n");
                nomeArquivo = "verduras.txt";
                break;
            case 4:
                 system("cls");
                printf("\n=== Ervas e Temperos ===\n\n");
                exibirErvasTemperos();
                printf("\nApenas o tomilho é calculado por kg\n\n");
                nomeArquivo = "ervas_temperos.txt";
                break;
            case 5:
                 system("cls");
                printf("\n=== Tubérculos e Raízes ===\n\n");
                exibirTuberculosRaizes();
                printf("\nEssa é a tabela por kg dos produtos\n\n");
                nomeArquivo = "tuberculos_raizes.txt";
                break;
            case 6:
                 system("cls");
                printf("\n=== Outros Produtos ===\n\n");
                exibirOutrosProdutos();
                printf("\nEssa é a tabela por kg dos produtos\n\n");
                nomeArquivo = "outros_produtos.txt";
                break;
            case 0:
                printf("Saindo do programa...\n");
                return 0;
            default:
                printf("Opção inválida.\n");
                return 0;
        }

        carregarProdutos(nomeArquivo, produtos, &quantidadeProdutos);

        printf("\n\nDigite o nome do item desejado ou (0) para voltar: ");
        scanf(" %[^\n]", nomeProduto);

        float preco = buscarPrecoProduto(produtos, quantidadeProdutos, nomeProduto);
        if (preco == -1.0) {
            printf("Produto não encontrado.\n");
        } else {
            printf("Preço encontrado: %.2f R$\n", preco);

            printf("Kg ou quantidade desejada: ");
            scanf("%f", &quant);



            totalc = preco * quant;
            totalpr = totalc + totalpr;

            printf("\nTotal para %s: %.2f R$ e %.1f kg (ou quantidade)", nomeProduto, totalc, quant);

            printf("Deseja continuar a compra?\n Digite 1 para continuar ou qualquer outro número para finalizar: ");
            scanf("%d", &repeat);
        }
         } else {
        printf("Obrigado e volte sempre!\n");
        return 0;
    }

    }
    system("cls");
    printf("Total da compra: %.2f\n", totalpr);
   printf("\nQual a forma de pagamento?\n");
        printf("1. Débito\n");
        printf("2. Crédito\n");
        printf("3. Dinheiro\n");
        printf("4. Pix (QRCODE)\n");
        printf("0. Sair\n");
        scanf("%d", &pagamento);
        switch (pagamento) {
            case 1:
                system("cls");
                printf("Forma de pagamento selecionada: Débito");
                printf("\nProcessando pagamento...\n\n");
                printf("\nPagamento aprovado! (%.2f)\n\nVolte Sempre :\)\n\n===Hortifruti Hortmix===\n\n", totalpr);
                break;
            case 2:
                 system("cls");
                printf("Forma de pagamento selecionada: Crédito");
                printf("\nProcessando pagamento...\n\n");
                printf("\nPagamento aprovado! (%.2f)\n\nVolte Sempre :\)\n\n===Hortifruti Hortmix===\n\n", totalpr);
                break;
            case 3:
                 system("cls");
                printf("Forma de pagamento selecionada: Dinheiro");
                printf("\nProcessando pagamento...\n\n");
                printf("\nPagamento aprovado! (%.2f)\n\nVolte Sempre :\)\n\n===Hortifruti Hortmix===\n\n", totalpr);
                break;
            case 4:
                 system("cls");
                printf("Forma de pagamento selecionada: Pix");
                printf("\nProcessando pagamento...\n\n");
                printf("\nPagamento aprovado! (%.2f)\n\nVolte Sempre :\)\n\n===Hortifruti Hortmix===\n\n",totalpr);
                break;
            case 0:
                printf("Saindo do programa...\n");
                return 0;

                }


    return 0;
}
