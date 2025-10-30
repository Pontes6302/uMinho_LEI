#include "managers/passengers.h"
#include "entidades/passenger.h"

typedef struct passengers {
    int size;
    passenger_node *top;
    passenger_node *bottom;
} passengers;