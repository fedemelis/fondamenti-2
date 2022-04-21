#pragma once

#include "stdlib.h"
#include "stdio.h"
#include "memory.h"

typedef struct {
    unsigned p; // Peso
    unsigned a; // Altezza
    unsigned l; // Limite
} Cartone;

typedef struct {
    unsigned pesotot; // Peso tot
    unsigned altezzatot; // Altezza tot
    int *pila; // pila
    int size;
} Torre;

extern void TorreCartoni(const Cartone* c, size_t n);