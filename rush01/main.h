#ifndef MAIN_H
#define MAIN_H

#include "global.h"

int main(int argc, char **argv);
void init_tableau(Tableau *tab);
int recur(Tableau *p_tab, int ligne, int *p_compteur_answers);
int is_possible(Tableau *p_tab, int ligne);
int is_possible_final(Tableau *p_tab);
void copier_ligne(int ligne, int indice_permut, Tableau *p_tab);
int signatures_are_equal(Signature s1, Signature s2);
int sig_of_permut_sub(Tableau *p_tab, int num, int is_ligne, int from_start);
Signature sig_of_permut(Tableau *p_tab, int num, int is_ligne);

#endif