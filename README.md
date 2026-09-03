# Sistema de Bolsa Universitaria em C++

Projeto desenvolvido em C++ para simular a análise e concessão de bolsas universitárias com base em critérios acadêmicos e socioeconômicos.

🔵 Sobre o Projeto

O sistema recebe os dados do candidato e verifica automaticamente qual bolsa ele pode receber:

🟢 Bolsa Integral — 100%
🟡 Meia-Bolsa — 50%
🔴 Indeferido — Sem bolsa
📋 Informações analisadas

# O programa solicita:

-Nome e curso
-Renda familiar
-Número de pessoas na residência
-Nota do processo seletivo
-Nota do ENEM
-Média do Ensino Médio
-Existência de deficiência
-Escola pública
-Familiares que já possuem bolsa
-Cálculos
-Renda Per Capita
-Renda Familiar ÷ Número de Pessoas

-Nota Final
-Processo Seletivo × 40%
-ENEM × 30%
-Ensino Médio × 30%

# Regras das bolsas:

🟢 100%	Renda per capita ≤ R$ 800 + Nota ≥ 8,0 + Escola Pública
🟡 50%	Renda per capita ≤ R$ 1.600 + Nota ≥ 6,0
🔴 Sem bolsa	Não atender aos requisitos

Além disso, o sistema verifica familiares que já possuem bolsa e outras condições adicionais.

# Validação:

O programa também impede dados inválidos, como:

Renda negativa;
Número de pessoas menor ou igual a zero;
Notas fora de 0 a 10;
Valores diferentes de 0 ou 1 para respostas de sim/não;
Número negativo de familiares bolsistas.
Tecnologias

1. Clone o projeto
git clone <URL_DO_REPOSITORIO>

2. Compile
g++ main.cpp -o sistema-bolsas

3. Execute
./sistema-bolsas


# Objetivo:

O projeto foi desenvolvido com finalidade acadêmica, colocando em prática conceitos fundamentais de programação em C++ e estruturas de decisão.

# Saídas esperadas:

```text

Bolsa 100%:
===========================================================
Curso: Engenharia de Computação
Nota final: 8.7
Renda per capita: 600
Resultado da bolsa: DEFERIDO - BOLSA INTEGRAL (100%)!
PARABENS, João Silva, estamos felizes em ter voce conosco!
===========================================================

Bolsa 50%:
===========================================================
Curso: Administração
Nota final: 6.5
Renda per capita: 1200
Resultado da bolsa: DEFERIDO - MEIA-BOLSA (50%)!
PARABENS, Maria Souza, estamos felizes em ter voce conosco!
===========================================================

Indeferimento: 
===========================================================
Curso: Direito
Nota final: 4.6
Renda per capita: 2500
Resultado: INDEFERIDO (sem bolsa)!
Motivos do indeferimento:
- Renda per capita acima do limite permitido.
- Nota final abaixo do limite permitido.
- Numero de familiares com bolsa acima do limite permitido.
- Para aluno sem deficiencia e que estudou em escola particular, a nota minima deve ser 7.5.
===========================================================

```
Autor: Marlon Vritzl

Projeto acadêmico — C++
