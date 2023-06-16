#include <stdio.h>
#include <stdlib.h>
#define maxTam 30
#include <locale.h>



typedef struct dataNas
{
    int dia;
    int ano;
    char mes[10];
} dataNas;

typedef struct funcionarios
{
    char nome[maxTam];
    int idade;
    char sexo;
    char cpf[12];
    char cargo[maxTam];
    dataNas dataNascimento;
    double salario;
    int codigo;
} funcionarios;

int main()
{
    setlocale(LC_ALL, ""); 
    funcionarios Funcionarios;

    printf("Olá, peço que digite algumas informações\nDigite seu nome: ");
    scanf("%s", Funcionarios.nome);

    printf("Idade: ");
    scanf("%d", &Funcionarios.idade);

    printf("Sexo: ");
    scanf(" %c", &Funcionarios.sexo);

    printf("CPF: ");
    scanf("%s", Funcionarios.cpf);

    printf("Cargo: ");
    scanf("%s", Funcionarios.cargo);

    printf("Data de Nascimento: ");
    printf("Dia: ");
    scanf("%d", &Funcionarios.dataNascimento.dia);
    printf("Mês: ");
    scanf("%s", Funcionarios.dataNascimento.mes);
    printf("Ano: ");
    scanf("%d", &Funcionarios.dataNascimento.ano);

    printf("Salario: ");
    scanf("%lf", &Funcionarios.salario);

    printf("Codigo do Setor: ");
    scanf("%d", &Funcionarios.codigo);

    printf("\n---------------------------------------\nCONFIRA SUAS INFORMAÇÕES:\nNome: %s\nIdade: %d\nSexo: %c\nCPF: %s\nCargo: %s\nData de nascimento: %d/%s/%d\n", Funcionarios.nome, Funcionarios.idade, Funcionarios.sexo, Funcionarios.cpf, Funcionarios.cargo, Funcionarios.dataNascimento.dia, Funcionarios.dataNascimento.mes, Funcionarios.dataNascimento.ano);

    return 0;
}