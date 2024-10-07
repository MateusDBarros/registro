#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a estrutura dos registros, armazenando as informações
struct Registro {
    char nome[50];
    char profissao[50];
    int idade;
};

int MAX = 100;
int contador = 0;

// Função para adicionar registros
void adicionar(struct Registro pessoas[], int *numPessoas) {
    if (contador < MAX) {
        // Entrada de dados do usuário
        printf("Digite o nome do cliente: ");
        scanf("%s", pessoas[*numPessoas].nome);
        printf("Digite a profissao de %s: ", pessoas[*numPessoas].nome);
        scanf("%s", pessoas[*numPessoas].profissao);
        printf("Qual a idade de %s: ", pessoas[*numPessoas].nome);
        scanf("%d", &pessoas[*numPessoas].idade);
        printf("\n");
        contador++;
        (*numPessoas)++;  // Incrementa o número de registros
    } else {
        printf("Limite de Registros atingido!\n");
    }
}

// Função para visualizar todos os registros
void vizualizar(struct Registro pessoas[], int numPessoas) {
    // Cabeçalho da tabela
    printf("| %-20s | %-20s | %-5s |\n", "Nome", "Profissao", "Idade");
    printf("|----------------------|----------------------|-------|\n");
    
    // Impressão dos registros
    for (int i = 0; i < numPessoas; i++) {
        printf("| %-20s | %-20s | %-5d |\n", pessoas[i].nome, pessoas[i].profissao, pessoas[i].idade);
        printf("|----------------------|----------------------|-------|\n");
    }
    printf("\n");
}

// Função para editar um registro existente
void editar(struct Registro pessoas[], int numPessoas) {
    char nome[25];
    printf("Qual pessoa gostaria de editar o registro? ");
    scanf("%s", nome);

    // Pesquisa e edição do registro
    for (int i = 0; i < numPessoas; i++) {
        if (strcmp(nome, pessoas[i].nome) == 0) {
            printf("Digite o nome da pessoa: ");
            scanf("%s", pessoas[i].nome);
            printf("Digite a profissao de %s: ", pessoas[i].nome);
            scanf("%s", pessoas[i].profissao);
            printf("Qual a idade de %s: ", pessoas[i].nome);
            scanf("%d", &pessoas[i].idade);
            printf("Usuario editado com sucesso\n");
            return;
        }
    }
    printf("Pessoa nao encontrada!\n");
}

// Função para excluir um registro
void excluir(struct Registro pessoas[], int *numPessoas) {
    char nome[25];
    printf("Qual pessoa gostaria de apagar o registro? ");
    scanf("%s", nome);

    // Pesquisa e exclusão do registro
    for (int i = 0; i < *numPessoas; i++) {
        if (strcmp(pessoas[i].nome, nome) == 0) {
            for (int j = i; j < *numPessoas - 1; j++) {
                pessoas[j] = pessoas[j + 1];
            }
            (*numPessoas)--;  // Decrementa o número de registros
            contador--;
            printf("Registro removido!\n");
            return;
        }
    }
    printf("Usuario nao encontrado!\n");
}

// Função principal
int main(void) {
    struct Registro pessoas[100];
    int numPessoas = 0;
    int escolha;

    printf("O que Gostaria de fazer hoje?\n");

    // Loop de opções do menu
    do {
        printf("Selecione as opcoes abaixo\n");
        printf("1. Adicionar novo registro\n");
        printf("2. Vizualizar todos os registros\n");
        printf("3. Editar um registro\n");
        printf("4. Excluir um registro\n");
        printf("5. Sair\n");
        scanf("%d", &escolha);
        printf("------------------------------------\n");
        printf("\n");

        // Escolha das opções do menu
        switch (escolha) {
            case 1:
                adicionar(pessoas, &numPessoas);
                break;
            case 2:
                vizualizar(pessoas, numPessoas);
                break;
            case 3:
                editar(pessoas, numPessoas);
                break;
            case 4:
                excluir(pessoas, &numPessoas);
                break;
            case 5:
                printf("Fim do programa...\n");
                printf("------------------------------------\n");
                break;
            default:
                printf("Selecao invalida, por favor entre uma das opcoes oferecidas!\n");
                printf("------------------------------------\n");
                break;
        }
    } while (escolha != 5);  // Continua até o usuário escolher sair

    return 0;
}
