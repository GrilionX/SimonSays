#include <stdio.h>
#include <stdlib.h>
#include "queueUser.h"

Cola* crearCola(){
    Cola* nuevaCola = (Cola*)malloc(sizeof(Cola));
    if (nuevaCola == NULL){
        return NULL;
    }
    nuevaCola->frente = NULL;
    nuevaCola->final = NULL;
    return nuevaCola;
}

int estaVacia(Cola* cola){
    return cola->frente == NULL;
}

void encolar(Cola* cola, char letra){
    Nodo* nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    if (nuevoNodo == NULL){
        return;
    }
    nuevoNodo->letra = letra;
    nuevoNodo->next = NULL;
    if (cola->final == NULL){
        cola->frente = nuevoNodo;
    }else{
        cola->final->next = nuevoNodo;
    }
    cola->final = nuevoNodo;
}

char desencolar(Cola* cola){
    if (cola -> frente == NULL){
        return '\0';
    }
    Nodo* nodoTemp = cola->frente;
    char letra = nodoTemp -> next;
    if(cola->frente == NULL){
        cola->final=NULL;
    }
    free(nodoTemp);
    return letra;
}

void liberarCola(Cola* cola){
    while (!estaVacia(cola)){
        desencolar(cola);
    }
    free (cola);
}