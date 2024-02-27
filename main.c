#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
      
      if (argc != 3) {
        fprintf(stderr, "%s <fisier_input> <fisier_output>\n", argv[0]);
        return 1;
    }

    FILE *fisier_input, *fisier_output;
    int nr_elemente_sir;
    int sir_numere[60];
    char nume_operatie[10];
    int nr_clauze = 0;

    fisier_input = fopen(argv[1], "r");
    fisier_output = fopen(argv[2], "w");

    if (fisier_input == NULL || fisier_output == NULL) {
        fprintf(fisier_output, "Fisierul nu s-a putut deschide.\n");
        return 1;
    }

    // citesc primele doua valori
    int valoare1, valoare2;
    fscanf(fisier_input, "%d %d", &valoare1, &valoare2);

    while (fscanf(fisier_input, "%s", nume_operatie) == 1) {

        nr_elemente_sir = 0;
        // citesc sirul de numere
        while (nr_elemente_sir < 60 && fscanf(fisier_input, "%d", &sir_numere[nr_elemente_sir]) == 1) {
            nr_elemente_sir++;
        }

        // verific tipul de operatie si cresc numarul de clauze
        if (strcmp(nume_operatie, "NOT") == 0) {
            for (int i = 0; i < nr_elemente_sir; i++) {
            }
              nr_clauze++;
     
            for (int i = 0; i < nr_elemente_sir; i++) {
            }
             nr_clauze++;
        } else if (strcmp(nume_operatie, "OR") == 0) {
            for (int i = 0; i < nr_elemente_sir - 1; i++) {
            }
            nr_clauze++;
            for (int i = 0; i < nr_elemente_sir - 1; i++) {
                nr_clauze++;
            }
        } else if (strcmp(nume_operatie, "AND") == 0) {
            for (int i = 0; i < nr_elemente_sir - 1; i++) {
            }
            nr_clauze++;
            for (int i = 0; i < nr_elemente_sir - 1; i++) {
                nr_clauze++;
            }
        }
    }
    
    nr_clauze++;

    fclose(fisier_input);
    fisier_input = fopen(argv[1], "r");

    fprintf(fisier_output, "p cnf %d %d\n", valoare2, nr_clauze);

    // parcurg din nou fisierul pentru a afisa rezultatele
    // pentru fiecare operatie aplic fiecare caz din formula transformarii CNF
    while (fscanf(fisier_input, "%s", nume_operatie) == 1) {
        nr_elemente_sir = 0;
        while (nr_elemente_sir < 60 && fscanf(fisier_input, "%d", &sir_numere[nr_elemente_sir]) == 1) {
            nr_elemente_sir++;
        }

        if (strcmp(nume_operatie, "NOT") == 0) {
            for (int i = 0; i < nr_elemente_sir; i++) {
                if (sir_numere[i] >= 0) {
                    fprintf(fisier_output, "-%d ", sir_numere[i]);
                } else {
                    fprintf(fisier_output, "%d ", abs(sir_numere[i]));
                }
            }
            fprintf(fisier_output, "0");
            fprintf(fisier_output, "\n");
            for (int i = 0; i < nr_elemente_sir; i++) {
                fprintf(fisier_output, "%d ", sir_numere[i]);
            }
            fprintf(fisier_output, "0\n");
        } else if (strcmp(nume_operatie, "OR") == 0) {
            for (int i = 0; i < nr_elemente_sir - 1; i++) {
                fprintf(fisier_output, "%d ", sir_numere[i]);
            }
            if (sir_numere[nr_elemente_sir - 1] >= 0) {
                fprintf(fisier_output, "-%d 0\n", sir_numere[nr_elemente_sir - 1]);
            } else {
                fprintf(fisier_output, "%d 0\n", abs(sir_numere[nr_elemente_sir - 1]));
            }
            for (int i = 0; i < nr_elemente_sir - 1; i++) {
                if (sir_numere[i] >= 0) {
                    fprintf(fisier_output, "-%d %d 0\n", sir_numere[i], sir_numere[nr_elemente_sir - 1]);
                } else {
                    fprintf(fisier_output, "%d %d 0\n", abs(sir_numere[i]), sir_numere[nr_elemente_sir - 1]);
                }
            }
        } else if (strcmp(nume_operatie, "AND") == 0) {
            for (int i = 0; i < nr_elemente_sir - 1; i++) {
                if (sir_numere[i] >= 0) {
                    fprintf(fisier_output, "-%d ", sir_numere[i]);
                } else {
                    fprintf(fisier_output, "%d ", abs(sir_numere[i]));
                }
            }
            fprintf(fisier_output, "%d 0\n", sir_numere[nr_elemente_sir - 1]);

            for (int i = 0; i < nr_elemente_sir - 1; i++) {
                if (sir_numere[nr_elemente_sir - 1] >= 0) {
                    fprintf(fisier_output, "%d -%d 0\n", sir_numere[i], sir_numere[nr_elemente_sir - 1]);
                } else {
                    fprintf(fisier_output, "%d %d 0\n", abs(sir_numere[i]), sir_numere[nr_elemente_sir - 1]);
                }
            }
        }
    }
    
    fprintf(fisier_output, "%d 0\n", valoare2);

    fclose(fisier_input);
    fclose(fisier_output);

    return 0;
}
