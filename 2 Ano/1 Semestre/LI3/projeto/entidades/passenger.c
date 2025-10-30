#include "../includes/entidades/passenger.h"

typedef struct passenger_node {
    char *document_number;
    char *first_name;
    char *last_name;
    char *dob;
    char *nationality;
    char *gender;
    char *email;
    char *phone;
    char *address;
    char *photo;
    struct passenger_node *next;
    struct passenger_node *prev;
} passenger_node;
