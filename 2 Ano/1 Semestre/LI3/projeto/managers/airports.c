#include "managers/airports.h"
#include "entidades/airport.h"

typedef struct airports
{
    int size;
    airport_node *top;
    airport_node *bottom;
} airports;