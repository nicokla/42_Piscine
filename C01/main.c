#include "ex00/ft_ft.h"
#include "ex01/ft_ultimate_ft.h"
#include "ex02/ft_swap.h"
#include "ex03/ft_div_mod.h"
#include "ex04/ft_ultimate_div_mod.h"
#include "ex05/ft_putstr.h"
#include "ex06/ft_strlen.h"
#include "ex07/ft_rev_int_tab.h"
#include "ex08/ft_sort_int_tab.h"

#include <stdio.h>


int main(){

	// ex00
	/*int a = 4;
	ft_ft(&a);
	printf("%d\n", a);
*/

	// ex01
	/* int a;
	int *p1 = &a;
	int **p2 = &p1;
	int ***p3 = &p2;
	int ****p4 = &p3;
	int *****p5 = &p4;
	int ******p6 = &p5;
	int *******p7 = &p6;
	int ********p8 = &p7;
	int *********p9 = &p8;
	ft_ultimate_ft(p9);
	printf("%d", *********p9); // a == *********p9
*/ 

    // ex02
	/* int a=3, b=5;
	 ft_swap(&a, &b);
	 printf("%d %d\n", a, b);
	*/

	// ex03
	/*int a=16, b=3;
	int div, mod;
	ft_div_mod(a, b, &div, &mod);
	printf("%d %d\n", div, mod);
*/

	/*ex04
	int a=16, b=3;
	ft_ultimate_div_mod(&a,&b);
	printf("%d %d\n",a,b);
	*/

	//ex05
	//ft_putstr("coucou");

	// ex06
	// printf("%d",ft_strlen("coucou"));

	// ex07
	/*int tableau[4] = {2, 3, 4, 5};
	ft_rev_int_tab(tableau, 4);
	for(int i=0; i<4; i++){
		printf("%d",tableau[i]);
	}
	*/

	// ex08
	/*int tableau[4] = {4, 3, 2, 5};
	ft_sort_int_tab(tableau, 4);
	for(int i=0; i<4; i++)
	{
		printf("%d",tableau[i]);
	}*/

	
	return 0;
}





