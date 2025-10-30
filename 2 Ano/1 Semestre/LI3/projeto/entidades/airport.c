#include "entidades/airport.h"

typedef struct airport_node
{
    char *code;
    char *name;
    char *city;
    char *country;
    double lagitude;
    double longitude;
    char *timezone;
    char *latitude;
    char *longitude;
    char *icao;
    char *type;
    airport_node *next;
    airport_node *prev;
} airport_node;