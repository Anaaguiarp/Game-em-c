#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int sessao = 0, tent=0, opcao;

struct jogador{
    char nome[50];
    int idade;
    int tentativas[20];
    int sessoes[10][20];
    int tentativasS[10];
};

struct jogador j1;

void menuJogo() {
    printf("--------------------- MENU ---------------------\n");
    printf("Digite:\n1- Iniciar novo jogo\n2- Ver historico de sessoes\n3- Ver instrucoes de jogo\n4- Sair\nEscolha a opcao: ");
    scanf("%d", &opcao);
    printf("------------------------------------------------\n");
}

void HistoricoSessoes(){
    if(sessao == 0){
        printf("Nenhuma sessao foi gerada ainda...\n");
        return;
    }

    for (int i = 0; i < sessao; i++) {
        printf("Sessao %d: \n", i + 1);//pra mostrar a sessao correspondente
        for (int j = 0; j < j1.tentativasS[i]; j++) {
            printf("[%d] ", j1.sessoes[i][j]);
        }
        printf("\n\n");
    }
}

void iniciarJogo(){
    int numSecreto, numEscolhido;

    srand(time(NULL));
    numSecreto= rand() % 101;
    printf("Aguarde enquanto o numero secreto esta sendo gerado...\nNumero gerado! Boa sorte!\n");
    /*printf("%d\n", numSecreto); //teste*/

    printf("Informe o seu palpite:\n");

    do{
        scanf("%d", &numEscolhido);
        j1.tentativas[tent]=numEscolhido;
        tent++;

        if(tent>=20){
            printf("Limite de tentativas atingido!\n");
            return;
        }

        if(numEscolhido != numSecreto){
            if(numEscolhido < numSecreto){
            printf("Esta proximo! Um pouco mais!\n");
            }else{
                printf("Esta proximo! Um pouco menos!\n");
            }
            printf("Informe o seu palpite novamente:\n");
        }else{
        printf("PABABENS!! Voce acertou em %d tentativas!\n", tent);
        }
    }while(numEscolhido != numSecreto);

    for (int i = 0; i < tent; i++) {
        j1.sessoes[sessao][i] = j1.tentativas[i];
    }
    j1.tentativasS[sessao] = tent;

    sessao++;
}

void verInstrucoes(){
    printf("Instrucoes:\n . O computador ira gerar um numero entre 1 e 100\n . O usuario devera adivinhar qual o numero\n . O usuario possui 20 tentativas totais para acertar, apos isso, o programa retornara ao menu\n");
}

int main(){

    printf("Informe seu nome:\n");
    scanf("%[^\ns]", j1.nome);
    printf("Informe sua Idade:\n");
    scanf("%d", &j1.idade);

    do{
        menuJogo();
        if(opcao == 1){
            iniciarJogo();
        }else if(opcao == 2){
            HistoricoSessoes();
        }else if(opcao == 3){
            verInstrucoes();
        }else if(opcao == 4){
            printf("Encerrando...\n");
            break;
        }
    }while(opcao != 4);
    
    return 0;
}