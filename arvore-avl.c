#include <stdlib.h>
#include <stdio.h>

typedef struct no {
    struct no* pai;
    struct no* esquerda;
    struct no* direita;
    int valor;
} No;

typedef struct arvore {
    struct no* raiz;
} Arvore;

void balanceamento(Arvore*, No*);
int altura(No*);
int fb(No*);
No* rsd(Arvore*, No*);
No* rse(Arvore*, No*);
No* rdd(Arvore*, No*);
No* rde(Arvore*, No*);


// váriavel para contagem das operações de balanceamento
int contador = 0;


Arvore* criar() {
    Arvore *arvore = malloc(sizeof(Arvore));
    arvore->raiz = NULL;

    return arvore;
}

int vazia(Arvore* arvore) {
    return arvore->raiz == NULL;
}

No* adicionarNo(No* no, int valor) {

    /////////
    contador++;

    if (valor > no->valor) {
        if (no->direita == NULL) {
            //printf("Adicionando %d dir %d\n",valor, no->valor);
            No* novo = malloc(sizeof(No));
            novo->valor = valor;
            novo->pai = no;
            novo->direita = NULL;
            novo->esquerda = NULL;

            no->direita = novo;

            return novo;
        } else {
            return adicionarNo(no->direita, valor);
        }
    } else {
        if (no->esquerda == NULL) {
            //printf("Adicionando %d esq %d\n",valor, no->valor);
            No* novo = malloc(sizeof(No));
			novo->valor = valor;
            novo->pai = no;
            novo->direita = NULL;
            novo->esquerda = NULL;

            no->esquerda = novo;

            return novo;
        } else {
            return adicionarNo(no->esquerda, valor);
        }
    }
}

No* adicionar(Arvore* arvore, int valor) {
    if (arvore->raiz == NULL) {
        //printf("Adicionando %d\n",valor);
        No* novo = malloc(sizeof(No));
        novo->valor = valor;
        novo->pai = NULL;
        novo->direita = NULL;
        novo->esquerda = NULL;

        arvore->raiz = novo;

        /////////
        contador++;

        return novo;
    } else {
        No* no = adicionarNo(arvore->raiz, valor);
        balanceamento(arvore, no);

        return no;
    }
}

void balanceamento(Arvore* arvore, No* no) {
    while (no != NULL) {
        int fator = fb(no);

        if (fator > 1) { //árvore mais pesada para esquerda
            //rotação para a direita
            if (fb(no->esquerda) > 0) {
                //printf("RSD(%d)\n",no->valor);
                rsd(arvore, no); //rotação simples a direita, pois o FB do filho tem sinal igual
            } else {
                //printf("RDD(%d)\n",no->valor);
                rdd(arvore, no); //rotação dupla a direita, pois o FB do filho tem sinal diferente
            }
        } else if (fator < -1) { //árvore mais pesada para a direita
            //rotação para a esquerda
            if (fb(no->direita) < 0) {
                //printf("RSE(%d)\n",no->valor);
                rse(arvore, no); //rotação simples a esquerda, pois o FB do filho tem sinal igual
            } else {
                //printf("RDE(%d)\n",no->valor);
                rde(arvore, no); //rotação dupla a esquerda, pois o FB do filho tem sinal diferente
            }
        }

        no = no->pai;
    }
}

int altura(No* no){

    /////////
    //contador++;

    int esquerda = 0,direita = 0;

    if (no->esquerda != NULL) {
        esquerda = altura(no->esquerda) + 1;
    }

    if (no->direita != NULL) {
        direita = altura(no->direita) + 1;
    }

    return esquerda > direita ? esquerda : direita; //max(esquerda,direita)
}

int fb(No* no) {

    /////////
    contador++;

    int esquerda = 0,direita = 0;

    if (no->esquerda != NULL) {
        esquerda = altura(no->esquerda) + 1;
    }

    if (no->direita != NULL) {
        direita = altura(no->direita) + 1;
    }

    return esquerda - direita;
}

No* rse(Arvore* arvore, No* no) {

    /////////
    contador++;

    No* pai = no->pai;
    No* direita = no->direita;

    no->direita = direita->esquerda;
    no->pai = direita;

    direita->esquerda = no;
    direita->pai = pai;

    if (no->direita != NULL)
        no->direita->pai = no;

    if (pai == NULL) {
        arvore->raiz = direita;
    } else {
        if (pai->esquerda == no) {
            pai->esquerda = direita;
        } else {
            pai->direita = direita;
        }
    }

    return direita;
}

No* rsd(Arvore* arvore, No* no) {

    /////////
    contador++;

    No* pai = no->pai;
    No* esquerda = no->esquerda;

    no->esquerda = esquerda->direita;
    no->pai = esquerda;

    esquerda->direita = no;
    esquerda->pai = pai;

    if (no->esquerda != NULL)
        no->esquerda->pai = no;

    if (pai == NULL) {
        arvore->raiz = esquerda;
    } else {
        if (pai->esquerda == no) {
            pai->esquerda = esquerda;
        } else {
            pai->direita = esquerda;
        }
    }

    return esquerda;
}

No* rde(Arvore* arvore, No* no) {

    no->direita = rsd(arvore, no->direita);
    return rse(arvore, no);
}

No* rdd(Arvore* arvore, No* no) {

    no->esquerda = rse(arvore, no->esquerda);
    return rsd(arvore, no);
}


// imprime endereços para verificar encadeamento
void imprimeInorder(No* no) {
    if (no!=NULL){
        imprimeInorder(no->esquerda);
        printf("Valor %d    & %x\n",no->valor, no);
        //printf("   esq %x    v %d\n",no->esquerda,no->esquerda == NULL ? 0 : no->esquerda->valor);
        //printf("   dir %x    v %d\n\n",no->direita,no->direita == NULL ? 0 : no->direita->valor);
        imprimeInorder(no->direita);
    }
}
//


int main() {


    /*  Versão 1
    int random[] = {35, 5, 84, 43, 82, 54, 55, 45, 60, 3, 93, 20, 74, 81, 49, 15, 61, 37, 34, 100,
                  39,16, 44, 33, 46, 4, 59, 92, 87, 19, 95, 53, 47, 48, 6, 72, 98, 31, 67, 50, 97,
                  2, 71, 62, 94, 13, 65, 27, 79, 23, 51, 73, 25, 11, 21, 63, 10, 56, 80, 42, 9,
                  17, 52, 64, 12, 78, 57, 99, 89, 36, 68, 38, 77, 70, 76, 40, 28, 24, 58, 29, 90,
                  75, 8, 69, 26, 30, 83, 86, 18, 41, 32, 85, 96, 14, 66, 88, 91, 1, 22, 7}; // usei shuffle do python pra desordenar as chaves de 1-100
    //*/


    /* Versão 2
    Arvore* a = criar();

    FILE* arquivo = fopen("ChavesDesordenadas.txt","r");
    int random[1001]={};
    if(arquivo!=NULL)
        for(int i=0;i<1000;i++){
            fscanf(arquivo,"%d",&random[i]);
            //printf("valor lido: %d\n",random[i]);
        }

    for(int i = 1; i <= 1000; i++){

        // pro ordenado crescente (pior caso)
        //adicionar(a, i);

        // pro ordenado decrescente (pior caso) (deu os mesmos valores do crescente)
        //adicionar(a, 1001-i);

        // pro desordenado (caso médio)
        //adicionar(a, random[i-1]);

        if(i%100==0)
            printf("// %d -> %d\n", i, contador);

    }
    //*/


    //* Versão 3
    Arvore** a = calloc(10, sizeof(Arvore*));

    char nomeArquivo[] = "Chaves0.txt";
    int chave;
    float medias[10] = {};

    FILE* arquivo = NULL;

    for(int i = 0; i < 10; i++){
        nomeArquivo[6] = 48 + i;  // valor da tabela ascii para caracteres 0-9
        arquivo = fopen(nomeArquivo,"r");

        printf("Conjunto %d\n", i);
        a[i] = criar();
        contador = 0;
        int k = 0;

        for(int j = 1; j <= 1000; j++){

            fscanf(arquivo,"%d",&chave);

            // pro ordenado crescente (pior caso)
            //adicionar(a[i], j);

            // pro desordenado (caso médio)
            adicionar(a[i], chave);

            if(j%100==0){
                printf("// %d -> %d\n", j, contador);

                medias[k++] += contador;
            }
        }

        printf("\n");

        fclose(arquivo);
    }

    printf("Medias:\n");
    int k = 0;
    for(int i = 100; i <=1000; i+=100){
        medias[k] /= 10.0;
        printf("// %d -> %f\n", i, medias[k++]);
    }

    //*/


    // Dados da Versão 2
    // 10 conjuntos com as chaves ordenadas
    // 100 -> 12564
    // 200 -> 46759
    // 300 -> 100194
    // 400 -> 178446
    // 500 -> 265374
    // 600 -> 387237
    // 700 -> 533907
    // 800 -> 693405
    // 900 -> 856107
    // 1000 -> 1035357
    // sem contabilizar altura
    // 100 -> 1525
    // 200 -> 3466
    // 300 -> 5551
    // 400 -> 7751
    // 500 -> 9951
    // 600 -> 12324
    // 700 -> 14724
    // 800 -> 17124
    // 900 -> 19524
    // 1000 -> 21924

    // 10 conjuntos de chaves desordenadas
    // 100 -> 11403
    // 200 -> 44436
    // 300 -> 98304
    // 400 -> 174856
    // 500 -> 269737
    // 600 -> 385512
    // 700 -> 520411
    // 800 -> 680291
    // 900 -> 856271
    // 1000 -> 1054489
    // sem contabilizar altura
    // 100 -> 1305
    // 200 -> 3037
    // 300 -> 4980
    // 400 -> 6963
    // 500 -> 9049
    // 600 -> 11236
    // 700 -> 13389
    // 800 -> 15640
    // 900 -> 17873
    // 1000 -> 20150

    // 10 conjuntos de médias de 10 ordenações (validade estatística)
    // 100 -> 1341.000000
    // 200 -> 3089.199951
    // 300 -> 5006.700195
    // 400 -> 6998.700195
    // 500 -> 9057.700195
    // 600 -> 11186.000000
    // 700 -> 13361.200195
    // 800 -> 15576.000000
    // 900 -> 17834.000000
    // 1000 -> 20128.000000



    // imprimeInorder(a->raiz);

    //printf("\nOPERACOES: %d\n\n",contador);
    //printf("r %x  v %d\n",a->raiz, a->raiz->valor);

}
