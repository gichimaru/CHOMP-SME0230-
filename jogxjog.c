/* TRABALHO OFICIAL - CHOMP 022 - PARTE 1

INTEGRANTES DO GRUPO 13:
Larisse Ferreira Alzeri - 12703080
Luis Roberto Piva - 13687727
Nina Cunha Pinheiro - 13686500
*/

#include <stdio.h>

int main(){

    int matriz[9][11]; //matriz base para a estruturacao do jogo
    char Jogador1[20], Jogador2[20];//armazenando nomes para os jogadores, humanizando-os haha
    int i, j, k, l; //contadores usados para construir a matriz do jogo
    int a, b, m, n; //contadores usados para construir as jogadas dos jogadores
    int z;//variavel usada para saber se o usuario quer um tutorial do jogo

    n = 1;//n comeca po 1 pois ele inicializa os comandos a seguir

    while (n == 1) {// para repetir o jogo enquanto o usuário quiser

        m = 0; //usada na contagem de jogadas, determina quem joga
        a = 0; //usadas nas coordenadas das jogadas(linhas)
        b = 0; //usada nas coordenadas das jogadas(colunas)

        printf("\n Bem-vindos ao jogo Chomp do Grupo 13, pense bem e boa sorte!\n\n");//começando o jogo (muitos \n(ina))

        printf(" Antes de comecar para valer, porem, temos duas coisas a apresentar e/ou perguntar aos jogadores.\n Em primeiro lugar, para facilitar a identificacao, Jogador 1 digite um nome de usuario para te identificar (Lembre-se nome de usuario em jogos nao tem espacos!!!:\n\n");
        scanf("%s", Jogador1);//lendo o nome do primeiro usuario

        printf("\n Agora sua vez de nos fornecer um nome, Jogador 2:\n\n");
        scanf("%s", Jogador2);//lendo o nome do segundo

        printf("\n Em segundo, %s, %s, preparamos um tutorial deste jogo, descrevendo como ele funciona. Caso voces precisem digite 1. Se voces ja sabem jogar, digite qualquer numero: ", Jogador1, Jogador2);//vendo se os usuarios precisam de um tutorial, antes do jogo
        scanf("%d", &z);

        if(z == 1) { //TUTORIAAAAAALLLLL, ninguem gosta, mas eh necessario
            printf("\n Okay, vamos la. O Chomp eh um jogo de tabuleiro 8x10 feito de chocolate, com um dos quadradinhos no canto inferior esquerdo marcado pelo numero 2, de coordenadas (8,1), o qual representa o pedaco de chocolate com pimenta.(A pimenta pode ser muito traicoiera, dizem por ai.) Dois jogadores alternam suas jogadas. Em cada jogada, um jogador escolhe um quadrado com o valor 0, dada por coordenadas do tabuleiro(linha, coluna), e este quadrado eh removido do tabuleiro, juntamente com os que estao acima e a direita dele. A remocao desses quadradinhos eh representado pelo numero 1. Porem, o jogador que escolher o pedaco de chocolate com pimenta perde o jogo. Logo, o objetivo do jogo eh fazer seu adversario escolher tal pedaco. Tudo isso fica muito mais simples e facil na pratica. \n\nEntao vamos la galera mulheres.\n\n");
        }
        else{
            printf("\n Okay, okay! Vamos direto entao.\n");
        }

        //colocando os numeros nas colunas e linhas da matriz
        for(i = 0; i < 9; i++) { //dar valores as casas do tabuleiro

            printf("\n"); //pular de linha para a matriz ficar corretamente posicionada

            for(j = 0; j < 11; j++) {

                matriz[i][j] = 0; //igualando igual a zero as casas do tabuleiro que poderao ser escolhidas sem danos imediatos
                matriz[8][1] = 2; //igualando esta casa a 2, para a casa com a pimenta, a qual causa perda imediata

                //for usado para dar numeros a primeira coluna da matriz, para tornar as jogadas localizaveis
                for(l = 0; l < 1; l++) { //coluna 0
                    for(k = 0;k < 9; k++) {
                        matriz[k][l] = k; //numero da linha
                    }
                }

                //for usado para dar numeros a primeira linha da matriz, para tornar as jogadas localizaveis
                for(k = 0; k < 1; k++) { //linha 0
                    for(l = 0; l < 11; l++) {
                        matriz[k][l] = l; //numero da coluna
                    }
                }
                printf(" %d", matriz[i][j]); //imprimindo a matriz para o jogo
            }
        }
        printf("\n\n Cuidado para nao acertar a casa com valor 2 (coordenada 8 1)! Lembre-se: PERDA IMEDIATA!!!"); //avisando ao usuario que a casa com a pimenta resulta em perda imediata

        //matriz[a][b] para a construcao das jogadas
        while(matriz[a][b] != matriz[8][1]) { //enquanto a jogada dos jogadores for diferente da casa da pimenta

            //quem comeca sempre eh o Jogador 1, depois muda a cada jogada com o valor de m
            if(m % 2 == 0) {
                printf("\n\n %s, digite o pedaco que deseja remover (Lembre-se: primeiro a coordenada da linha e depois a da coluna): ", Jogador1);
            }
            else {
                printf("\n\n %s, digite o pedaco que deseja remover (Lembre-se: primeiro a coordenada da linha e depois a da coluna):", Jogador2);
            }

            scanf("%d %d", &a, &b); //lendo as coordenadas dadas pelo usuario

            while (((a > 8) || (a <= 0)) || ((b > 10) || (b <= 0)) || ((matriz[a][b]) == 1)) { //caso o usuario queria pregar uma peca no programa ahhahah
                printf(" Oops! Valores de coordenada invalidos! Reveja-os, por favor!!!\n");
                scanf("%d %d", &a, &b);
            }

            for(i = a; i >= 1; i = i - 1) { //este for vai transformar as casas acima da linha indicada em 1, impossibilitando-as de serem escolhidas depois
                for(j = b; j < 11; j++) { //este for vai transformar as casa a direita da coluna indicada em 1, impossibilitando-as de serem escolhidas depois
                    matriz[i][j] = 1; //igualando as matrizes a 1 para marcar que ali ja foi excluido
                }
            }

            //reconstruindo a matriz a cada jogada
            for(i = 0; i < 9; i = i + 1) {
                printf("\n"); //pular de linha para a matriz ficar corretamente posicionada
                for(j = 0; j < 11; j = j + 1) {
                printf(" %d", matriz[i][j]); //imprimindo a matriz para continuar o jogo
                }
            }
            m = m + 1; //mudar a vez dos jogadores e verificar a condicao do while
        }

        if(m % 2 == 0) {
            printf("\n\n %s, voce venceu!!!\n Sinto muito %s, mas nao foi desta vez!\n\n", Jogador1, Jogador2); //avisando que o jogador 1 venceu pois a ultima rodada foi feita pelo jogador 2
        }
        else {
            printf("\n\n %s, voce venceu!!!\n Sinto muito %s, mas nao foi desta vez!\n\n", Jogador2, Jogador1); //avisando que o jogador 2 venceu pois a ultima rodada foi feita pelo jogador 1
        }
        n = 0;
        printf(" Jogadores, aceitam jogar de novo? (Digite 1 para SIM e qualquer outra tecla para Nao):");//repeticao do código vem daqui
        scanf("%d", &n);
        printf("\n\n"); //deixar os jogos separados
    }

    return(0);
}
