#include <iostream>
using namespace std;

int main (){

    char nome[50];
    char curso[50];
    int NumeroPessoas, NumeroFamiliaresBolsistas;
    float RendaFamiliar, RendaPerCapita, NotaProcessoSeletivo, NotaEnem, MediaEnsinoMedio, NotaFinal;
    bool Deficiencia, EscolaPublica, CondicaoAdicional = true;

    cout << " ================================================== " << endl;
    cout << " === SISTEMA DE BOLSAS UNIVERSITARIO DA UNIVALI === " << endl;
    cout << " ================================================== " << endl;

    cout << "\nDigite seu nome: " << endl;
    cin.getline(nome, 50);

    cout << "\nDigite o nome da curso que deseja ingressar: " << endl;
    cin.getline(curso, 50);

    cout << "\nCurso escolhido: " << curso << endl;

    cout << "\nDigite a renda familiar: " << endl;
    cin >> RendaFamiliar;

    if(RendaFamiliar < 0){
        cout << "\nRenda familiar invalida. Por favor, insira um valor maior ou igual a zero." << endl;
        return 1;
    }

    cout << "\nDigite o numero de pessoas que moram na residencia: " << endl;
    cin >> NumeroPessoas;

    if(NumeroPessoas <= 0){
        cout << "\nNumero de pessoas invalido. Por favor, insira um valor maior que zero." << endl;
        return 1;
    }

    // Condição para RendaPerCapita:
    RendaPerCapita = RendaFamiliar / NumeroPessoas;
    if(RendaPerCapita < 0){
        cout << "\nRenda per capita invalida. Por favor, insira valores validos." << endl;
        return 1;
    }

    cout << "\nRenda per capita: " << RendaPerCapita << endl;

    cout << "\nDigite a nota do processo seletivo: " << endl;
    cin >> NotaProcessoSeletivo;

    if(NotaProcessoSeletivo < 0 || NotaProcessoSeletivo > 10){
        cout << "\nNota do processo seletivo invalida. Por favor, insira valores validos de 0 a 10." << endl;
        return 1;
    }

    cout << "\nDigite a nota do ENEM: " << endl;
    cin >> NotaEnem;

    if(NotaEnem < 0 || NotaEnem > 10){
        cout << "\nNota do ENEM invalida. Por favor, insira um valor de 0 a 10." << endl;
        return 1;
    }

    cout << "\nDigite a media do ensino medio: " << endl;
    cin >> MediaEnsinoMedio;

    if(MediaEnsinoMedio < 0 || MediaEnsinoMedio > 10){
        cout << "\nMedia do ensino medio invalida. Por favor, insira um valor de 0 a 10." << endl;
        return 1;
    }

    // Condição para NotaFinal:
    NotaFinal = NotaProcessoSeletivo * 0.4 + NotaEnem * 0.3 + MediaEnsinoMedio * 0.3;

    if(NotaFinal < 0 || NotaFinal > 10){
        cout << "\nNota final invalida. Por favor, insira valores validos de 0 a 10." << endl;
        return 1;
    }

    cout << "\nMedia das notas: " << NotaFinal << endl;

    cout << "\nO aluno possui deficiencia? (1 para sim, 0 para nao): " << endl;
    cin >> Deficiencia;

    if(Deficiencia != 0 && Deficiencia != 1) {
        cout << "\nValor invalido. Por favor, insira 1 para sim ou 0 para nao." << endl;
        return 1;
    }

    cout << "\nO aluno estudou em escola publica? (1 para sim, 0 para nao): " << endl;
    cin >> EscolaPublica;

    if(EscolaPublica != 0 && EscolaPublica != 1) {
        cout << "\nValor invalido. Por favor, insira 1 para sim ou 0 para nao." << endl;
        return 1;
    }

    cout << "\nDigite o numero de familiares que ja possuem bolsa: " << endl;
    cin >> NumeroFamiliaresBolsistas;

    if(NumeroFamiliaresBolsistas < 0){
        cout << "\nNumero de familiares com bolsa invalido. Por favor, insira um valor maior ou igual a zero." << endl;
        return 1;
    }

    // Condicao adicional:
    if(Deficiencia == false && EscolaPublica == false && NotaFinal < 7.5) {
        CondicaoAdicional = false;
    }

    // Para bolsa de 100%: ============================================================================
    if(RendaPerCapita <= 800 && NotaFinal >= 8.0 && EscolaPublica == true && 
        NumeroFamiliaresBolsistas == 0 && CondicaoAdicional){  

        cout << "\n========================================" << endl;
        cout << "Curso: " << curso << endl;
        cout << "Nota final: " << NotaFinal << endl;
        cout << "Renda per capita: " << RendaPerCapita << endl;
        cout << "Resultado da bolsa: DEFERIDO - BOLSA INTEGRAL (100%)!" << endl;
        cout << "PARABENS, " << nome << ", estamos felizes em ter voce conosco!" << endl;
        cout << "========================================" << endl;
    }

    // Para bolsa de 50%: =============================================================================
    else if(RendaPerCapita <= 1600 && NotaFinal >= 6.0 && NumeroFamiliaresBolsistas < 2 && CondicaoAdicional){

        cout << "\n========================================" << endl;
        cout << "Curso: " << curso << endl;
        cout << "Nota final: " << NotaFinal << endl;
        cout << "Renda per capita: " << RendaPerCapita << endl;
        cout << "Resultado da bolsa: DEFERIDO - MEIA-BOLSA (50%)!" << endl;
        cout << "PARABENS, " << nome << ", estamos felizes em ter voce conosco!" << endl;
        cout << "========================================" << endl;
    }

    // Caso de indeferimento: ==========================================================================
    else{

        cout << "\n========================================" << endl;
        cout << "Curso: " << curso << endl;
        cout << "Nota final: " << NotaFinal << endl;
        cout << "Renda per capita: " << RendaPerCapita << endl;
        cout << "Resultado: INDEFERIDO (sem bolsa)!" << endl;
        cout << "Motivos do indeferimento:" << endl;

        if(RendaPerCapita > 1600){
            cout << "- Renda per capita acima do limite permitido." << endl;
        }
        if(NotaFinal < 6.0){
            cout << "- Nota final abaixo do limite permitido." << endl;
        }
        if(NumeroFamiliaresBolsistas >= 2){
            cout << "- Numero de familiares com bolsa acima do limite permitido." << endl;
        }
        if(EscolaPublica == false && Deficiencia == false && NotaFinal < 7.5){
            cout << "- Para aluno sem deficiencia e que estudou em escola particular, a nota minima deve ser 7.5." << endl;
        }

        cout << "========================================" << endl;
    }

    return 0;
}