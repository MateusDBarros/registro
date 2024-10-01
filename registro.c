#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define a estrutura dos registros, armazenando as informações
struct Registro {
    char nome[50];
    char profissao[50];
    int idade;
    int id;
};

//Criando as funçoes utilizadas
void adicionar(struct Registro pessoas[], int *numPessoas);
void vizualizar(struct Registro pessoas[], int *numPessoas);
void editar(struct Registro pessoas[], int numPessoas);
void excluir();

int main(void)
{   
    printf("O que Gostaria de fazer hoje?\n");
    
    printf("Selecione as opcoes abaixo\n");
    printf("1. Adicionar novo registro\n");
    printf("2. Vizualizar todos os registros\n");
    printf("3. Editar um registro\n");
    printf("4. Excluir um registro\n");
    printf("5. Sair\n");

    struct Registro pessoas[100];
    int numPessoas = 0;
    int escolha = scanf("%d");

    switch (escolha)
    {
    case 1:
        adicionar(pessoas, numPessoas);
        break;
    case 2:
        vizualizar(pessoas,numPessoas);
        break;
    case 3:
        editar(pessoas, numPessoas);
        break;
    case 4:
        excluir(pessoas, numPessoas);
        break;
    
    default:
    {
        printf("Selecao invalida, por favor entre uma das opcoes oferecidas!");
        return main();
        break;
    }

}
}
void exibir(struct Registro c)

{
    printf("Nome: %s\n", c.nome);
    printf("Profissao: %s\n", c.profissao);
    printf("Idade: %d\n", c.idade);
}

//Pegando as informações para adicionar na struct
void adicionar(struct Registro pessoas[], int *numPessoas)
{
    printf("Digite o nome do cliente: ");
    scanf("%s", pessoas[*numPessoas].nome);

    printf("Digite a profissao de %s: ", pessoas[*numPessoas].nome);
    scanf("%s", pessoas[*numPessoas].profissao);

    printf("Qual a idade de %s: ", pessoas[*numPessoas].nome);
    scanf("%s", pessoas[*numPessoas].idade);

    printf("Insira a ID de %s: ", pessoas[*numPessoas].nome);
    scanf("%s", pessoas[*numPessoas].id);
}

//Exibir as informações
void vizualizar(struct Registro pessoas[], int *numPessoas)
{
    for (int i = 0; i < numPessoas; i++)
    {
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Profissao: %s\n", pessoas[i].profissao);
        printf("Idade: %d\n", pessoas[i].idade);
        printf("ID: %d\n", pessoas[i].id);
        printf("\n");
    }
    
    char retorno = ' ';
    
    
    do {
        printf("Aperte a tecla 'v' para voltar ao menu anterior: ");
        scanf("%c", retorno);
        if (strcmp('v', retorno) == 0) return main();
    }
    while (strcmp('v', retorno) != 0);
}

//Edita os as informações
void editar(struct Registro pessoas[], int numPessoas)
{ 
    char nome[25];
    printf("Qual pessoa gostaria de editar o registro? ");
    scanf("%s", nome);

    for (int i = 0; i < numPessoas; i++)
    {
        if(strcmp(nome, pessoas[i].nome) == 0)
        {
            printf("Digite o nome da pessoa: ");
            scanf("%s", pessoas[i].nome);

            printf("Digite a profissao de %s: ", pessoas[i].nome);
            scanf("%s", pessoas[i].profissao);

            printf("Qual a idade de %s: ", pessoas[i].nome);
            scanf("%s", pessoas[i].idade);

            printf("Insira a ID de %s: ", pessoas[i].nome);
            scanf("%s", pessoas[i].id);
            return;
        } 
    }
    printf("Pessoa nao encontrada!");
    
}
//Exluir um registro da struct
void excluir(struct Registro pessoas[], int numPessoas)
{
    char nome[25];
    printf("Qual pessoa gostaria de apagar o registro? ");
    scanf("%s", nome);

    for (int i = 0; i < numPessoas; i++)
    {
        if (strcmp(pessoas[i].nome, nome) == 0)
        {
            pessoas[i] = pessoas[i + 1];
        }

    }
    printf("Usuario nao encontrado!");
    main();
}
