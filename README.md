# Trabalho Final - Jogo Chomp

Este repositório contém o trabalho final da disciplina **SME0230 - Introdução à Programação de Computadores**, ministrada no primeiro semestre de 2022 pelas professoras Marina Andretta e Franklina Toledo.

O objetivo do projeto foi desenvolver o jogo "Chomp" em Linguagem C.

### O Jogo Chomp

Chomp é um jogo para dois jogadores que se passa em um tabuleiro retangular, que no contexto deste trabalho, representa uma barra de chocolate de dimensões 8x10. O quadrado no canto inferior esquerdo é considerado "envenenado" (com pimenta).

As regras são as seguintes:
1. Dois jogadores alternam turnos (Jogador 1 e Jogador 2). O Jogador 1 sempre inicia a partida.
2. A cada turno, o jogador escolhe um dos quadrados (um pedaço do chocolate).
3. Ao escolher um quadrado, ele é "comido" (removido do tabuleiro), juntamente com todos os quadrados que estão acima e à direita dele.
4. O jogador que for forçado a comer o quadrado envenenado (o do canto inferior esquerdo) perde o jogo.

## Funcionalidades Implementadas

O programa foi desenvolvido em Linguagem C e implementa as seguintes funcionalidades

* **Menu Inicial**: Permite ao usuário escolher entre duas versões do jogo:
    1.  Jogador (humano) vs. Jogador (humano)
    2.  Jogador (humano) vs. Computador
* **Tabuleiro**: Representação de um tabuleiro 8x10, que é atualizado e exibido na tela após cada jogada.
* **Validação de Jogadas**: O programa verifica se a jogada inserida pelo usuário é válida. Caso não seja, uma mensagem de erro é exibida e o jogador pode tentar novamente.
* **Controle de Turnos**: O sistema informa de quem é a vez de jogar e alterna os turnos corretamente.
* **Condição de Fim de Jogo**: Ao final de cada jogada, o programa verifica se a partida terminou e exibe uma mensagem indicando o resultado.

## Estrutura do Projeto

Conforme as diretrizes do trabalho, todo o código foi implementado em um único arquivo-fonte `.c`. Foram seguidas as boas práticas de programação, como indentação e uso de comentários para facilitar a legibilidade, e foram evitados recursos como o comando `goto` e variáveis globais.

## Autores

* Luís Roberto Piva - N° USP: 13687727
* [Nome do Integrante 2] - N° USP: [Número USP do Integrante 2]
