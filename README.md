# Trabalho Final - Jogo Chomp

## Sobre o Projeto

Este repositório contém o trabalho final da disciplina **SME0230 - Introdução à Programação de Computadores**, ministrada no primeiro semestre de 2022 pelas professoras Marina Andretta e Franklina Toledo. [cite: 1, 2, 3]

O objetivo do projeto foi desenvolver o jogo "Chomp" em Linguagem C. [cite: 6, 27]

### O Jogo Chomp

[cite_start]Chomp é um jogo para dois jogadores que se passa em um tabuleiro retangular, que no contexto deste trabalho, representa uma barra de chocolate de dimensões 8x10. [cite: 18, 20] [cite_start]O quadrado no canto inferior esquerdo é considerado "envenenado" (com pimenta). [cite: 18]

As regras são as seguintes:
1.  [cite_start]Dois jogadores alternam turnos (Jogador 1 e Jogador 2). [cite: 20] [cite_start]O Jogador 1 sempre inicia a partida. [cite: 32]
2.  [cite_start]A cada turno, o jogador escolhe um dos quadrados (um pedaço do chocolate). [cite: 21]
3.  [cite_start]Ao escolher um quadrado, ele é "comido" (removido do tabuleiro), juntamente com todos os quadrados que estão acima e à direita dele. [cite: 21]
4.  [cite_start]O jogador que for forçado a comer o quadrado envenenado (o do canto inferior esquerdo) perde o jogo. [cite: 25]

## Funcionalidades Implementadas

[cite_start]O programa foi desenvolvido em Linguagem C e implementa as seguintes funcionalidades: [cite: 27]

* [cite_start]**Menu Inicial**: Permite ao usuário escolher entre duas versões do jogo: [cite: 29]
    1.  [cite_start]Jogador (humano) vs. Jogador (humano) [cite: 27]
    2.  [cite_start]Jogador (humano) vs. Computador [cite: 27]
* [cite_start]**Tabuleiro**: Representação de um tabuleiro 8x10, que é atualizado e exibido na tela após cada jogada. [cite: 18, 35]
* **Validação de Jogadas**: O programa verifica se a jogada inserida pelo usuário é válida. [cite_start]Caso não seja, uma mensagem de erro é exibida e o jogador pode tentar novamente. [cite: 33, 34]
* [cite_start]**Controle de Turnos**: O sistema informa de quem é a vez de jogar e alterna os turnos corretamente. [cite: 31, 38]
* [cite_start]**Condição de Fim de Jogo**: Ao final de cada jogada, o programa verifica se a partida terminou e exibe uma mensagem indicando o resultado. [cite: 36, 37]

## Estrutura do Projeto

[cite_start]Conforme as diretrizes do trabalho, todo o código foi implementado em um único arquivo-fonte `.c`. [cite: 14] [cite_start]Foram seguidas as boas práticas de programação, como indentação e uso de comentários para facilitar a legibilidade, e foram evitados recursos como o comando `goto` e variáveis globais. [cite: 40, 44, 50]

## Como Compilar e Executar

1.  **Clone o repositório:**
    ```bash
    git clone [https://github.com/seu-usuario/seu-repositorio.git](https://github.com/seu-usuario/seu-repositorio.git)
    ```
2.  **Navegue até o diretório do projeto:**
    ```bash
    cd seu-repositorio
    ```
3.  **Compile o programa usando um compilador C (como o GCC):**
    ```bash
    gcc -o chomp nome_do_arquivo.c -lm
    ```
4.  **Execute o jogo:**
    ```bash
    ./chomp
    ```

## Autores

* [Seu Nome Completo] - N° USP: [Seu Número USP]
* [Nome do Integrante 2] - N° USP: [Número USP do Integrante 2]
* [Nome do Integrante 3] - N° USP: [Número USP do Integrante 3]

## Agradecimentos

[cite_start]Agradecimentos às professoras **Marina Andretta** e **Franklina Toledo** e aos monitores **Ana Alice Zulian** e **Bruno da Freiria Mischiate Borges** pela orientação durante a disciplina. [cite: 3, 4, 5]
