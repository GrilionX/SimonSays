#ifndef QUEUE_H
#define QUEUE_H

typedef struct nodo{
    char letra;
    struct nodo* next;
}Nodo;

typedef struct {
    Nodo *frente;
    Nodo *final;
}Cola;

Cola* crearCola();
void encolar(Cola* cola, char letra);
char desencolar(Cola* cola);
int estaVacia(Cola* cola);
void liberarCola (Cola* cola);

#endif