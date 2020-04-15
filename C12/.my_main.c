

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "ex00/ft_list.h"
t_list	*ft_create_elem(void *data);
void	ft_list_push_front(t_list **begin_list, void *data);
int		ft_list_size(t_list *begin_list);
t_list	*ft_list_last(t_list *begin_list);
void	ft_list_push_back(t_list **begin_list, void *data);
t_list	*ft_list_push_strs(int size, char **strs);
t_list	*ft_list_at(t_list *begin_list, unsigned int nbr);
void	ft_list_reverse(t_list **begin_list);
void	ft_list_foreach(t_list *begin_list, void (*f)(void *));
void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
							void *data_ref, int (*cmp)());
t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());
void	ft_list_remove_if(t_list **begin_list, void *data_ref,
						int (*cmp)(), void (*free_fct)(void *));
void	ft_list_merge(t_list **begin_list1, t_list *begin_list2);
void	ft_list_sort(t_list **begin_list, int (*cmp)());
void	ft_list_reverse_fun(t_list *begin_list);
void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)());
void	ft_sorted_list_merge(t_list **begin_list1,
							t_list *begin_list2, int (*cmp)());

void afficher_liste(t_list *elt)
{
	printf("\ndebut\n");
	while (elt != 0)
	{
		printf("%d\n", (*(int*)(elt->data)));
		elt = elt->next;
	}
	printf("fin\n\n");
}

void afficher_liste2(t_list *elt)
{
	printf("\ndebut\n");
	while (elt != 0)
	{
		printf("%s\n", (char*)(elt->data));
		elt = elt->next;
	}
	printf("fin\n\n");
}

void my_free(void *a)
{
	free(a);
}

void double_entier(void *p)
{
	(*(int*)(p)) *= 2;
}

int plus_grand(void *pa, void *pb) {
	return (*(int*)pa >= *(int*)pb);
}

int soustraction(void *pa, void *pb) {
	return (*(int*)pa - *(int*)pb);
}

int is_multiple_of(void *pa, void *pb)
{
	return (*(int*)pa % *(int*)pb == 0);
}

t_list *create_list(int n)
{
	int *p;
	t_list *old_elt = NULL;
	t_list *elt;
	for (int i = 0; i < n; i++) {
		p = malloc(sizeof(int));
		*p = n - 1 - i;
		elt = ft_create_elem(p);
		elt->next = old_elt;
		old_elt = elt;
	}
	return (elt);
}

int main(){
	t_list *elt = create_list(10);
	afficher_liste(elt);
	
	// ex01
	// int b = 4;
	// ft_list_push_front(&elt, &b);
	// afficher_liste(elt);

	// ex02
	// int c = ft_list_size(elt);
	// printf("taille = %d\n", c);
	
	// ex03
	// t_list *elt2 = ft_list_last(elt);
	// printf("dernier element = %d\n", (*(int*)(elt2->data)));

	// ex04
	// int b = 4;
	// ft_list_push_back(&elt, &b);
	// afficher_liste(elt);

	// ex05
	// char *strs[3] = {"coucou", "toto", "toutou"};
	// t_list *elt2 = ft_list_push_strs(3, strs);
	// afficher_liste2(elt2);

	// ex06
	// ft_list_clear(elt, &my_free);
	// afficher_liste(elt);

	// ex07
	// int b = 5;
	// t_list *elt2 = ft_list_at(elt, b);
	// printf("list[%i] = %d\n", b, (*(int*)(elt2->data)));

	// ex08
	// ft_list_reverse(&elt);
	// afficher_liste(elt);

	// ex09
	// ft_list_foreach(elt, double_entier);
	// afficher_liste(elt);
	
	// ex10
	// int b = 5;
	// ft_list_foreach_if(elt, double_entier, &b, plus_grand);
	// afficher_liste(elt);

	// ex11
	// int b = 5;
	// t_list *elt2 = ft_list_at(elt, 5);
	// t_list *elt3 = ft_list_find(elt, &b, soustraction);
	// printf("adresse 1 = %p\n", elt2);
 	// printf("adresse 2 = %p\n", elt3);

	// ex12
	// int b = 3;
	// ft_list_remove_if(&elt, &b, is_multiple_of, my_free);
	// afficher_liste(elt);

	// ex13
	// t_list *elt2 = create_list(5);
	// ft_list_merge(&elt, elt2);
	// afficher_liste(elt);
	
	// ex14
	// t_list *elt2 = create_list(5);
	// ft_list_merge(&elt, elt2);
	// afficher_liste(elt);
	// ft_list_sort(&elt, soustraction);
	// afficher_liste(elt);

	// ex15
	// ft_list_reverse_fun(elt);
	// afficher_liste(elt);

	// ex16
	// ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)());
	
	// ex17

	return 0;
}

