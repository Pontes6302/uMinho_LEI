#include "../includes/entidades/reservation.h"
#include <stdbool.h>

typedef struct reservation_node {
    int reservation_id;
    char *flight_ids;
    char *document_number;
    char *seat;
    double price;
    bool extra_luggage;
    bool priority_boarding;
    char *qr_code;
    struct reservation_node *next;
    struct reservation_node *prev;
} reservation_node;

