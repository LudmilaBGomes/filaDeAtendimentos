#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 5

typedef struct {
    int fila[MAX_SIZE];
    int ini;
    int fim;
    int tam;
    
} tFilaCirc; 

typedef struct {
    int guiche;
    int senha;
    char tipo;
} atendimento;

typedef struct {
    atendimento regAtend[2000];
    int tam;
} tRegistroAtendimento;

typedef struct {
    char tipo;
    int senha;
} evento;

typedef struct {
    int numGuiche;
    bool livre;
    
} estruturaGuiche;




void iniciaFila(tFilaCirc *);
int filaVazia(tFilaCirc *);
int filaCheia(tFilaCirc *);
int tamFila(tFilaCirc *);
void insereFila(tFilaCirc *, int);
int retiraFila(tFilaCirc *);
void controleEvento(evento *, tFilaCirc *, tFilaCirc *, atendimento *, tRegistroAtendimento *);
void imprimeRegistro(tRegistroAtendimento *);
void iniciaAtendimento(tRegistroAtendimento *);



int main() {
  
  tFilaCirc filaNormal;
  tFilaCirc filaPrioridade;
  estruturaGuiche estGuiche;
  atendimento atendi;
  tRegistroAtendimento regiAtend;
  evento e;
 
 iniciaFila(&filaPrioridade);
 iniciaFila(&filaNormal);
iniciaAtendimento(&regiAtend);

 controleEvento(&e, &filaPrioridade, &filaNormal, &atendi, &regiAtend);
 printf("REGISTRO DE ATENDIMENTO\n");
 imprimeRegistro(&regiAtend);
    
};



void iniciaFila(tFilaCirc *fila) {
    fila->ini = 0;
    fila->fim = -1;
    fila->tam = 0;
}

int filaVazia(tFilaCirc *fila) {
    return(fila->tam == 0);
}

int filaCheia(tFilaCirc *fila) {
    return(fila->tam == MAX_SIZE);
}

int tamFila(tFilaCirc *fila) {
    return(fila->tam);
}

void insereFila(tFilaCirc *fila, int valor) {
    if(filaCheia(fila) == 1) {
        printf("Fila cheia! Não é possível inserir"); }
        else {
            fila->fim = (fila->fim +1) % MAX_SIZE;
            fila->fila[fila->fim] = valor;
            fila->tam++;
        }
    }


int retiraFila(tFilaCirc *fila) {
    int valor;
    if(filaVazia(fila) == 1) {
        printf("Fila vazia! Não é possível remover");
    } else { 
        valor = fila->fila[fila->ini];
        fila->ini = (fila->ini + 1) % MAX_SIZE;
        fila->tam--;
        return(valor);
        
    }
}

void iniciaAtendimento(tRegistroAtendimento *regisAtend) {
    regisAtend->tam = 0;
}

void preencheRegistro(atendimento *atendi, tRegistroAtendimento *regisAtend) {
    regisAtend->regAtend[regisAtend->tam].guiche = atendi->guiche;
    regisAtend->regAtend[regisAtend->tam].senha = atendi->senha;
    regisAtend->regAtend[regisAtend->tam].tipo = atendi->tipo;
    regisAtend->tam++;
}

void imprimeRegistro(tRegistroAtendimento *regisAtend) {
    
    for(int i = 0; i < regisAtend->tam; i++) {
    printf("%d %d %c\n", regisAtend->regAtend[i].guiche, regisAtend->regAtend[i].senha, 
    regisAtend->regAtend[i].tipo); 
    }
}

void controleEvento(evento *event, tFilaCirc *filaP, tFilaCirc *filaN, atendimento *atend, tRegistroAtendimento *regisAtend) {
    printf("Informe o tipo de evento e senha, use apenas a inicial maiúscula do nome. \n P: Prioridade \n N: Normal \n G: Guichê\n");
    while(event->tipo != 'F') {
        printf("Evento e senha: EX: P 1 ");
        scanf(" %c %d", &event->tipo, &event->senha); 
        
        if(event->tipo == 'P'){
            
            if(filaCheia(filaP) == 1) {
                printf("Por favor, aguarde! Fila cheia.");
            } else {
                insereFila(filaP, event->senha);
            }
            
        } else if(event->tipo == 'N') {
            if(filaCheia(filaN) == 1){
                printf("Por favor, aguarde! Fila cheia."); 
            } else {
                insereFila(filaN, event->senha);
            }
        } else if(event->tipo == 'G') {
             
             switch(event->senha) {
                    int senhaFilaN, senhaFilaP;
                    case 1:
                    if(filaP->tam == 0) {
                        senhaFilaN = retiraFila(filaN);
                        atend->senha = senhaFilaN;
                        atend->guiche = event->senha;
                        atend->tipo = 'N';
                        preencheRegistro(atend, regisAtend);
                        } else {
                            senhaFilaP = retiraFila(filaP);
                            atend->senha = senhaFilaP;
                            atend->guiche = event->senha;
                            atend->tipo = 'P';
                            preencheRegistro(atend, regisAtend);
                        }
                
                        break;
                    case 2:
                        senhaFilaN = retiraFila(filaN);
                        atend->senha = senhaFilaN;
                        atend->guiche = event->senha;
                        atend->tipo = 'N';
                        preencheRegistro(atend, regisAtend);
                        break;
                    case 3:
                        senhaFilaN = retiraFila(filaN);
                        atend->senha = senhaFilaN;
                        atend->guiche = event->senha;
                        atend->tipo = 'N';
                        preencheRegistro(atend, regisAtend);
                        break;
                    case 4:
                        senhaFilaN = retiraFila(filaN);
                        atend->senha = senhaFilaN;
                        atend->guiche = event->senha;
                        atend->tipo = 'N';
                        preencheRegistro(atend, regisAtend);
                        break;
                    default:
                    printf("Guichê não encontrado!");
        
}

            
        }
    
    };
}

  





