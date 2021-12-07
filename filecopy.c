//Kopiert eine Datei mit 2 Streams

#include<stdio.h>
#include<stdlib.h>

int main(void) {
    FILE *quelle, *ziel;
    int c;
    char name_q[255], name_z[255];

    printf("Name der Quelledatei: ");
    scanf("%s", &name_q);

    quelle = fopen(name_q, "rb");
    if(quelle == NULL) {
        printf("Konnte %s nicht öffnen!", name_q);
        return EXIT_FAILURE;
    }
    else {
        printf("Name der Zieldatei: ");
        scanf("%s", &name_z);

        ziel = fopen(name_z, "w+b");
        if(ziel == NULL) {
            printf("Konnte Zieldatei nicht erzeugen!\n");
            return EXIT_FAILURE;
        }
        else {
            while ((c = getc(quelle)) != EOF) {
                putc(c, ziel);
            }
        }
    }

    return EXIT_SUCCESS;
}