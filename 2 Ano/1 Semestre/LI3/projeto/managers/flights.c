#include "managers/flights.h"
#include "entidades/flight.h"

typedef struct flights {
    int size;
    flight_node *top;
    flight_node *bottom;
} flights;