#include "entidades/aircraft.h"

typedef struct aircraft_node {
    char *identifier;
    char *manufacturer;
    char *model;
    int year;
    int capacity;
    int range;
    aircraft_node *next;
    aircraft_node *prev;
} aircraft_node;
