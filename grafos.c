

#include <stdio.h>


void ligar(int matrizadj[50][50],int cidade1,int cidade2);
void desligar(int matrizadj[50][50],int cidade1,int cidade2);
int tem_caminho(int a,int b,int qtdestradas,int matrizadj[50][50]);
int adjacente(int a,int b,int matrizadj[50][50]);


int main()
{
    const int n = 50;
    int i,j;
    int matrizadj[n][n];
    int cidade1 = 1,cidade2;
    int qtdestradas;
    int a,b;
    //Digitar o caminho que deseja procurar, no caso de a ate b.
    printf("Digite o destino [a-b]:  ");
    scanf("%d %d",&a,&b);
    //Digitar a quantidade de estradas que voce deseja saber se esse caminho tem.
    printf("Digite a quantidade de estradas: ");
    scanf("%d",&qtdestradas);
    //Inicializar a matriz, colocando todos os valores como 0.
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            matrizadj[i][j] = 0;
        }
    }
    // Faz um while que liga as cidades que vc deseja, transformando o valor da matriz que recebe o indice i e j em 1
    printf("Digite as cidades que estão ligadas: ");
    int contador = 0;
    while(cidade1!=0){
        scanf("%d",&cidade1);
        if(cidade1==0){
            break;
        }
        scanf("%d",&cidade2);

        ligar(matrizadj,cidade1,cidade2);
    
    }
    if(tem_caminho(a,b,qtdestradas,matrizadj)){
        printf("Tem caminho com %d estradas",qtdestradas);
    }
    else{
        printf("Não tem caminho com %d estradas",qtdestradas);
    }

}

void ligar(int matrizadj[50][50],int cidade1,int cidade2){
    matrizadj[cidade1][cidade2] = 1;
}

void desligar(int matrizadj[50][50],int cidade1,int cidade2){
    matrizadj[cidade1][cidade2] = 0;
}
//Observa se a matriz na posicao a,b é adjacente ou seja, possui um arco que liga ambas/ o valor na matriz[a][b] = 1;
int adjacente(int a,int b,int matrizadj[50][50]){
    if(matrizadj[a][b] == 1){
        return 1;
    }
    return 0;
}

int tem_caminho(int a,int b,int qtdestradas,int matrizadj[50][50]){
    int c;
    //Se a quantidade de estradas que voce deseja do caminho que voce deseja achar for 1, voce faz so uma verificacao e verifica se
    // pra chegar em tal destino, existe apenas uma estrada,vendo se esses pontos são adjacentes.
    if(qtdestradas == 1){
        return adjacente(a,b,matrizadj);
    }
    //Se nao, vc verifica se existe um caminho da cidade 1 para outra cidade de forma que leve ao seu destino, lembrando que tem que cumprir
    // o requisito de achar para determinado x estradas.
    else{
    //Verifica se existe um caminho de a ate c, se tiver, chama a função tem_caminho de novo, so que com qtdestradas-1 e verifica se tem de c ate b.
        for(c = 0;c<50;c++){
            if(adjacente(a,c,matrizadj) == 1 && tem_caminho(c,b,qtdestradas-1,matrizadj) == 1){
                return 1;
            }
        }
        return 0;
    }
}

