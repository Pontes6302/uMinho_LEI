int contavogais(char *s){
    int c = 0;
    for (int i=0; s[i] != '\0'; i++)
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            c++;
    return c;
}

int retiraVogaisRep (char *s){
    for (int i = 0; s[i]; i++){
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
            for (int j = i; s[j]; j++)
                s[j] = s[j+1];
            i--;
        }
    }
}

int duplicaVogais (char *s){
    int j;
    char res[strlen(s)];
    for (int i = 0; s[i]; i++){
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
            res[j] = s[i];
            j++;
        }
    }
    for (int i = 0; s[i]; i++)
        res[i+j] = s[i];
    return j;
}

int ordenado (int v[], int N){
    for (int i = 0; i < N-1; i++)
        if (v[i] > v[i+1])
            return 0;
    return 1;
}

void merge (int a[], int na, int b[], int nb, int r[]){
    int i = 0, j = 0, k = 0;
    while (i < na && j < nb){
        if (a[i] < b[j])
            r[k++] = a[i++];
        else
            r[k++] = b[j++];
    }
    while (i < na)
        r[k++] = a[i++];
    while (j < nb)
        r[k++] = b[j++];
}

int partition (int v[], int N, int x){
    int size = sizeof(v)/sizeof(v[0]) - 1;
    int res = 0;
    for (int i = 0; 1; i++){
        if (v[i] >= x){
            for (int j = size; j > i; j--)
                if (v[j] < x){
                    int temp = v[i];
                    v[i] = v[j];
                    v[j] = temp;
                    res++;
                    break;
                }
                else if (j == i)
                    return res;
        }
    }
    return res;
}
