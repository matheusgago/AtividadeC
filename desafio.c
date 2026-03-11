#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // Biblioteca



int main() {
    setlocale(LC_ALL, "");
    int tipoVeiculo, cobertura, idade, eixos = 0;
    float valorBase = 0, adicionalCategoria = 0, adicionalIdade = 0, taxaCobertura = 0, valorTotal = 0;

    printf("--- Sistema de Cálculo de Seguro ---\n\n");


    printf("Selecione o tipo de veículo:\n");
    printf("1 - Passeio\n2 - Carga Pesada\n3 - Caminhonete\n4 - Motocicleta (até 999cc)\n5 - Motocicleta (1000cc ou mais)\n");
    printf("Opção: ");
    scanf("%d", &tipoVeiculo);


    if (tipoVeiculo >= 4){
    valorBase = 1200.00; //motos

    if (tipoVeiculo == 4) adicionalCategoria = valorBase * 0.80; //80%
    else adicionalCategoria = valorBase * 0.90; //90%
    } else {
    valorBase = 1000.00; //demais
    if (tipoVeiculo == 1) adicionalCategoria = valorBase * 0.10; //10%
    else if (tipoVeiculo == 2) adicionalCategoria = valorBase * 0.20; //20%
    else adicionalCategoria = valorBase * 0.33; //33%
}


    printf("\nDigite a idade do condutor principal: ");
    scanf("%d", &idade);

    if (tipoVeiculo == 2 || tipoVeiculo == 3) {
    printf("Digite o número de eixos do veículo: ");
    scanf("%d", &eixos);
}


    if (idade < 25) adicionalIdade = valorBase * 0.15;
    else if (idade >= 25 && idade <= 29) adicionalIdade = valorBase * 0.10;
    else adicionalIdade = valorBase * 0.05;


    printf("\nSelecione o tipo de cobertura:\n");
    printf("1 - Seguro Básico\n2 - Seguro Parcial\n3 - Seguro Completo\n");
    printf("Opção: ");
    scanf("%d", &cobertura);


    switch (cobertura) {
    case 1: // Básico
    if (tipoVeiculo == 1) taxaCobertura = 2.00;
    else if (tipoVeiculo == 2 || tipoVeiculo == 3) taxaCobertura = (valorBase * 0.03) * eixos;
    else if (tipoVeiculo == 4) taxaCobertura = -5.00;
    else taxaCobertura = 10.00;
    break;
    case 2: // Parcial
    if (tipoVeiculo == 1) taxaCobertura = 2.00;
    else if (tipoVeiculo == 2 || tipoVeiculo == 3) taxaCobertura = (valorBase * 0.05) * eixos;
    else if (tipoVeiculo == 4) taxaCobertura = 15.00;
    else taxaCobertura = 20.00;
    break;
    case 3: // Completo
    if (tipoVeiculo == 1) taxaCobertura = 10.00;
    else if (tipoVeiculo == 2 || tipoVeiculo == 3) taxaCobertura = (valorBase * 0.10) * eixos;
    else if (tipoVeiculo == 4) taxaCobertura = 80.00;
    else taxaCobertura = 100.00;
    break;
}


valorTotal = valorBase + adicionalCategoria + adicionalIdade + taxaCobertura;


    printf("\n================================");
    printf("\n RELATÓRIO DO SEGURO ");
    printf("\n================================");
    printf("\nValor Base: R$ %.2f", valorBase);
    printf("\nAdicional por Categoria: R$ %.2f", adicionalCategoria);
    printf("\nAdicional por Idade: R$ %.2f", adicionalIdade);
    printf("\nTaxa de Cobertura: R$ %.2f", taxaCobertura);
    printf("\n--------------------------------");
    printf("\nVALOR TOTAL FINAL: R$ %.2f", valorTotal);
    printf("\n================================\n");


    return 0;
}
