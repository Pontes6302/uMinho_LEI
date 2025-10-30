#include "managers/reservations.h"
#include "entidades/reservation.h"

typedef struct reservations {
    int size;
    reservation_node *top;
    reservation_node *bottom;
} reservations;