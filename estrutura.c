// ESTRUTURA �RVORE RUBRO-NEGRA

enum coloracao { Vermelho, Preto };
typedef enum coloracao Cor;
typedef struct no {
 struct no* pai;
 struct no* esquerda;
 struct no* direita;
 Cor cor; //cor do n� (Vermelho ou Preto)
 int valor;
} No;
