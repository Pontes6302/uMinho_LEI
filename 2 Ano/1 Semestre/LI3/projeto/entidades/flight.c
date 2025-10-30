#include "../includes/entidades/flight.h"

typedef struct flight_node
{
    int flight_id;
    char *departure;
    char *actual_departure;
    char *arrival;
    char *actual_arrival;
    char *gate;
    char *status;
    char *origin;
    char *destination;
    char *aircraft;
    char *airline;
    char *tracking_url;
    flight_node *next;
    flight_node *prev;
} flight_node;