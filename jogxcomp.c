/* TRABALHO OFICIAL - CHOMP 022 - PARTE 2

INTEGRANTES DO GRUPO 13:
Larisse Ferreira Alzeri - 12703080
Luis Roberto Piva - 13687727
Nina Cunha Pinheiro - 13686500

*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Primeiras informacoes do jogo para o(s) jogador(es), comum aos dois modos do jogo
void info_jogo() {

    int z; //variavel tutorial

    printf("\n Bem-vindos ao jogo Chomp do Grupo 13, pense bem e boa sorte!\n\n"); //começando o jogo

    do {
        printf(" Antes de tudo temos informacoes aos jogadores. Preparamos um tutorial deste jogo. Caso seja necessario digite 1, senao, digite 2: ");
        scanf("%d", &z);
    } while ((z != 1) && (z != 2)); //loop do tutorial

    if(z == 1) { //TUTORIAAAAAALLLLL, ninguem gosta, mas eh necessario
        printf("\n Okay, vamos ao TUTORIAL. O Chomp eh um jogo de tabuleiro 8x10 feito de chocolate, com um dos quadradinhos no canto inferior esquerdo, marcado pela letra (P) e de coordenadas (7,0), representando o pedaco de chocolate com pimenta (A pimenta pode ser muito traicoiera, dizem por ai!). Dois jogadores alternam suas jogadas. Em cada jogada, um jogador escolhe um pedaco de chocolate representado pelo caracter (#), dada por coordenadas do tabuleiro (linha, coluna), tal eh removido (comido) do tabuleiro, juntamente com os que estao acima e a direita dele (somos gulosinhos). A remocao desses quadradinhos eh imediata, alias esta na barriga de alguem. Porem, o jogador que escolher o pedaco de chocolate com pimenta perde o jogo. Logo, o objetivo do jogo eh fazer seu adversario escolher tal pedaco. Mas fique tranquilo, tudo isso fica muito mais simples e facil na pratica. Confia. Vamos la galera muheres!!!\n\n");
    }
    else {
        printf("\n Okay, okay! Seu chocolate em risco. Vamos la galera mulheres!!!\n\n");
    }

    return;
}

//-----------------------------------------------------------------------
//função usada para imprimir o tabuleiro base original
void Imprimir(char Chomp[9][11]) {

	int i, j; //contadores para estruturar a matriz(linhas)/(colunas)
	int l; //contador usado para deixar as linhas e as colunas identificaveis para as jogadas

    printf("\n~~~~~Que a forca esteja com voces~~~~~\n\n"); //referenciazinha a Star Wars pro programa ficar mais descontraido
	printf("\n-------Chomp 13-------\n");


    for(i = 0; i < 9; i++) { //dar valores as casas do tabuleiro

        printf("\n"); //pular de linha para a matriz ficar corretamente posicionada

        for(j = 0; j < 11; j++) {

            Chomp[i][j] = '#'; //igualando igual a # as casas do tabuleiro que poderao ser escolhidas sem danos imediatos, # parece um pedacinho de chocolate

            //colocando os numeros nas colunas e linhas da matriz para deixar as jogadas localizaveis
            for(l =0; l < 11; l++) { //OBS.: Otimizamos nosso for do ultimo jogo porque quebrava nosso novo codigo com char
                Chomp[0][l] = l -1 + '0'; //numerando as linhas
                Chomp[l][0] = Chomp[0][l]; //numerando as colunas
            }

            Chomp[8][1] = 'P'; //igualando esta casa a P(imenta), a qual causa perda imediata
            Chomp[0][0] = 'C'; //C(homp)

            printf("%c ", Chomp[i][j]);
        }

    }

    printf("\n\n Cuidado para nao acertar a casa com a letra (P) (coordenada 7 0)! Lembre-se: PERDA IMEDIATA!!!");

	return;
}

//----------------------------------------------------------------
//vai dar um tempo ate a resposta do computador pra pessoa ver o que esta acontecendo
void espera(float tempo) {

    clock_t limite, agora;

    // Calcula o horario atual
    agora  = clock();

    // Calcula o horario limite como o atual + tempo segundos
    limite = agora + tempo*CLOCKS_PER_SEC;

    // Verifica quando o horario chega no horario limite
    while (limite > agora) {
        agora  = clock();
    }

    return;
}

//--------------------------------------------------------------------------
//funcao que reestrutura o tabuleiro e o devolve para que possamos usar depois
char Rec_Chocolate(int x, int y, char Chomp[9][11]) {

    int i, j; //contadores basicos

	printf("\n-------Chomp 13-------\n");

    //este for vai comer (' ') as casas acima da linha, impossibilitando-as de serem comidas de novo, alias o chocolate ja esta na barriga de alguem
    for(i = x; i >= 1; i = i - 1) {
        for(j = y; j < 11; j++) {
            Chomp[i][j] = ' ';
        }
    }

    //reconstruindo o chocolate a cada jogada
    for(i = 0; i < 9; i = i + 1) {

        printf("\n"); //pular de linha para o chocolate ficar corretamente posicionado

        for(j = 0; j < 11; j = j + 1) {
            printf(" %c", Chomp[i][j]); //imprimindo o chocolate para continuar o jogo
        }
    }

    return(Chomp[9][11]);
}

//--------------------------------------------------------------------------
//funcao principal, nosso querido CHOMP
int main() {

    char Chomp[9][11]; //matriz base para a estruturacao do jogo (o nosso chocolatee)
    int x, y; //contadores usados como COORDENADAS para construir as jogadas dos jogadores
    int escolha; //variavel que decide qual modo do jogo sera jogado
    int m; //variavel que controla quem joga
    int d, e, i; //dois parametros(d,e) para usar nas jogados do computador/contador usado nas jogadas do Computador

    char Jogador1[30] = {"Jarvis"}, Jogador2[30]; //armazenando nomes para os jogadores, humanizando-os haha Jarvis eh uma referencia a Iron Man

    m = 0; //usada na contagem de jogadas, determina quem joga
    x = 0; //coordenada das linhas
    y = 0; //coordenada das colunas

    info_jogo(); //funcao com as informacoes cruciais do jogo

    do {
        printf(" Alem do tutorial, preparamos duas modalidades deste jogo para voce jogar: \n    1. JOGADOR VS JOGADOR: Voce contra um adversario!!!\n    2. JOGADOR VS COMPUTADOR: Voce contra nosso Jarvis!!!\n\n Qual desses modos voce gostaria de jogar? (Digite o numero correspondente):");
        scanf("%d", &escolha);
    } while ((escolha != 1) && (escolha != 2)); //loop do modo que vai ser jogado

    system("clear");

    if (escolha == 1) {
        printf(" A modalidade escolhida foi JOGADOR VS JOGADOR. Para anotar, nesta modalidade o Jogador 1 sempre comeca o jogo.\n\n Jogador 1 digite um nome de usuario para te identificar (Lembre-se nome de usuario em jogos nao tem espacos!!!):\n\n ");
        scanf("%s", Jogador1); //lendo o nome do primeiro usuario, se for Jogador VS Jogador, "Jarvis" é substituido, senao ele fica
    }
    else{
        printf(" A modalidade escolhida foi JOGADOR VS COMPUTADOR. Para anotar, nesta modalidade Jarvis sempre comeca o jogo.\n\n ");
    }

    printf("\n Agora, digite, por favor, seu nome de usuario, Jogador 2 (Lembre-se nome de usuario em jogos nao tem espacos!!!):\n\n ");
	scanf("%s", Jogador2);

    system("clear"); //limpa a tela com as nuances anteriores do jogo

    Imprimir(Chomp); //funcao que imprime a matriz inicial

 //--------------------------------IF------------------------------------------------//
 //------------------------------APENAS----------------------------------------------//
 //----------------------------JOG VS JOG--------------------------------------------//
    if(escolha == 1) {

        //Chomp[x][y] eh a casa escolhida
        while(Chomp[x+1][y+1] != Chomp[8][1]) { //enquanto a jogada dos jogadores for diferente da casa da pimenta

            //quem comeca sempre eh o Jogador 1, depois muda a cada jogada com o valor de m
            if((m % 2) == 0) {
                printf("\n\n %s, digite o pedaco de chocolate que deseja comer (Lembre-se: primeiro a coordenada da linha e depois a da coluna): ", Jogador1);
            }
            else {
                printf("\n\n %s, digite o pedaco de chocolate que deseja comer (Lembre-se: primeiro a coordenada da linha e depois a da coluna):", Jogador2);
            }

            scanf("%d %d", &x, &y); //lendo as coordenadas dadas pelo usuario

            while (((x > 7) || (x < 0)) || ((y > 9) || (y < 0)) || ((Chomp[x+1][y+1]) == ' ')) { //caso o usuario queira pregar uma peca no programa ahhahah
                printf(" Oops! Valores de coordenada invalidos! Reveja-os, por favor!!!\n");
                scanf("%d %d", &x, &y);
            } //loop das coordenadas

            system("clear"); //deixar apenas o tabuleiro atualizado

            Rec_Chocolate(x+1, y+1, Chomp); //reconstroi o chocolate com a jogada dada

            m++; //mudando quem joga
        }

        if(m % 2 == 0) { //verificando o ganhador e dando a mensagem
            printf("\n\n %s, voce venceu!!!\n Sinto muito %s! Sugerimos que voce chupe um limão para aliviar a ardencia da pimenta.\n\n", Jogador1, Jogador2); //avisando que o jogador 1 venceu pois a ultima rodada foi feita pelo jogador 2
        }
        else {
            printf("\n\n %s, voce venceu!!!\n Sinto muito %s! Sugerimos que voce chupe um limão para aliviar a ardencia da pimenta.\n\n", Jogador2, Jogador1); //avisando que o jogador 2 venceu pois a ultima rodada foi feita pelo jogador 1
        }

    }

 //----------------------------------IF-------------------------------------------------//
 //--------------------------------APENAS-----------------------------------------------//
 //-----------------------------JOG VS JARVIS-------------------------------------------//

    if(escolha == 2) {

        printf("\n\n Um momento, Jarvis esta pensando na melhor estrategia dele...\n\n");
        espera(3); //dando um tempinho para a pessoa ver o que esta acontecendo

        system("clear");

        Rec_Chocolate(7, 2, Chomp); //jogada inicial do computador, estrategia ganhadora
        m++;//mudando quem joga

        while(Chomp[x+1][y+1] != Chomp[8][1]) { //enquanto a jogada dos jogadores for diferente da casa da pimenta

            if((m % 2) != 0) { //jogada do jogador

                printf("\n\n %s, digite o pedaco de chocolate que deseja comer (Lembre-se: primeiro a coordenada da linha e depois a da coluna):", Jogador2);
                scanf("%d %d", &x, &y);

                while (((x > 7) || (x < 0)) || ((y > 9) || (y < 0)) || ((Chomp[x+1][y+1]) == ' ')) { //caso o usuario queira pregar uma peca no programa ahhahah
                    printf(" Oops! Valores de coordenada invalidos! Reveja-os, por favor!!!\n");
                    scanf("%d %d", &x, &y);
                }

                system("clear");

                Rec_Chocolate(x+1, y+1, Chomp);
                m++;
            }

            else { //jogada do computador, vulgo Jarvis

                //zerar sempre para cada jogada
                d = 0; //variavel usada para contar quantas casas disponiveis tem na coluna 0
                e = 0; //variavel usada para contar quantas casas disponiveis tem na linha

                printf("\n\n Um momento, agora eh a vez do nosso Jarvis fazer uma jogada...\n\n");
                espera(1);

                for(i = 1; i < 8; i++) { // for usado para contar quantas casas ainda ha disponiveis na coluna 0, ou para o programa na coluna 1
                    if(Chomp[i][1] == '#') {
                        d++;
                    }
                }

                for(i = 2; i < 10; i++) { // for usado para contar quantas casas ainda ha disponiveis na linha 7, ou para o programa na linha 8
                    if (Chomp[8][i] == '#') {
                        e++;
                    }
                }

                //a nossa estrategia eh comparar a quantidade de casas disponiveis com os for anteriores e decidir como prosseguir, tentando sempre deixar um numero par de casas disponiveis e um numero simetrico entre eles
                //espelhar o jogo
                if(d < e) { //caso em que na coluna 0 tem menos casas disponiveis que na linha 7
                    e = d;
                    espera(1);
                    system("clear");
                    Rec_Chocolate(8, e + 2, Chomp); // vamos nivelar o jogo
                    m++;
                }

                else if(d > e) { //caso em que na linha 7 tenha menos casas disponiveis que na coluna 0
                    d = e;
                    espera(1);
                    system("clear");
                    Rec_Chocolate(7 - d, 1, Chomp); // nivelar o jogo
                    m++;
                }

                else { // esse for eh especial, eh a unica maneira do jogador ganhar, por isso tentamos contornar a jogada

                    if(x == 7 && y == 8) { //jogando nessa casa, essa unica casa, o jogador usa a nossa estrategia, mas em beneficio proprio
                        espera(1);
                        system("clear");
                        Rec_Chocolate(4, 1, Chomp);
                        m++;
                    }

                    if(d == e && x == 7 && y == 4) { //jogamos nessas seguintes casas pois foi o meio escolhido de contornar a situacao, caso o jogador nao tenha notado
                        espera(1);
                        system("clear");
                        Rec_Chocolate(8, 3, Chomp);
                        m++;
                    }

                    if(d == e && x == 5 && y == 0) {
                        espera(1);
                        system("clear");
                        Rec_Chocolate(8, 2, Chomp);
                        m++;
                    }

                    //movimento final caso seja necessario, cunhado por nos como "apocalipse"
                    if(d == 0 && e == 0) {
                        espera(1);
                        system("clear");
                        Rec_Chocolate(8, 1, Chomp);
                        m++;
                    }
                }
            }
        }

        if(m % 2 == 0) { //verificando o ganhador e dando a mensagem
            printf("\n\n %s, voce venceu!!!\n Sinto muito %s! Sugerimos que voce chupe um limão para aliviar a ardencia da pimenta.\n\n", Jogador1, Jogador2); //avisando que o Jarvis venceu pois a ultima rodada foi feita pelo Jojador
        }
        else {
        printf("\n\n %s, voce venceu!!!\n Sinto muito %s! Sugerimos que voce use uma funcao limão eletronico para aliviar a ardencia da pimenta em seu sistema.\n\n", Jogador2, Jogador1); //avisando que o jogador 2 venceu pois a ultima rodada foi feita pelo Jarvis
        }

    }

    return(0);

}
