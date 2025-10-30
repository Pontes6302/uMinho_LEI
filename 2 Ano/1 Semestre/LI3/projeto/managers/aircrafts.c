#include "managers/aircrafts.h"
#include "entidades/aircraft.h"

typedef struct aircrafts {
    int size;
    aircraft_node *top;
    aircraft_node *bottom;
} aircrafts;