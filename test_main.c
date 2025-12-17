#include <stdio.h>
#include <stdlib.h>
#include "printlib.h"
#include <string.h>

void comp_c(char *arr_c, int size){
	int i = 0;
	while (i < size){
		if (i == 0)
			printf("comparing between ft_printf and printf for %%c:\n");
		ft_printf("ft_printf()'s result: %c || ", arr_c[i]);
		printf("printf()'s expected result: %c\n", arr_c[i]);
		i++;
	}
}

void comp_s(char **arr_s, int size){
	int i = 0;
	while (i < size){
		if (i == 0)
			printf("comparing between ft_printf and printf for %%s:\n");
		ft_printf("ft_printf()'s result: %s || ", arr_s[i]);
		printf("printf()'s expected result: %s\n", arr_s[i]);
		i++;
	}
}

void comp_uidhex(int *arr_num, int size){
	int i = 0;
	while (i < size){
		if (i == 0)
			printf("comparing between ft_printf and printf for number conversions:\n");
		if (i >= 0 && i <= 5){
			ft_printf("ft_printf()'s result: %d // %i|| ", arr_num[i], arr_num[i]);
			printf("printf()'s expected result: %d // %i\n", arr_num[i], arr_num[i]);
		}
		else if (i > 5 && i != 9){
			ft_printf("ft_printf()'s result: %x // %X|| ", arr_num[i], arr_num[i]);
			printf("printf()'s expected result: %x // %X\n", arr_num[i], arr_num[i]);
		}
		else if (i == 9){	
			ft_printf("ft_printf()'s result: %u || ", arr_num[i]);
			printf("printf()'s expected result: %u\n", arr_num[i]);
		}
		i++;
	}
}

void comp_ptr(void **arr_ptr, int size){
	int i = 0;
	while (i < size){
		if (i == 0)
			printf("comparing between ft_printf and printf for %%p:\n");
		ft_printf("ft_printf()'s result: %p || ", arr_ptr[i]);
		printf("printf()'s expected result: %p\n", arr_ptr[i]);
		i++;
	}
}

int main(){
	/* Testing out %c cases, notably: '\0' and any ascii char in addition to the constant string *format */
	char test_c[5] = "a1B-\0";
	comp_c(test_c, 5);

	/* Testing out %s cases, notably an empty string, a NULL pointer, and a random string in addition to *format. */
	char *test_s1 = "";
	char *test_s2 = "1Nvi5-IbL3  ";
	char **test_s = (char **)calloc(3, sizeof(char *));
	for (int i = 0; i < 2; i++){
		test_s[i] = calloc(20, sizeof(char));
		i++;
	}
	test_s[0] = test_s1;
	test_s[1] = test_s2;

	/*Note that we do not assign test[2] because it's already been initialized as NULL by calloc which should output (null).*/

	comp_s(test_s, 3);

	/* Testing out %u, %d, %i, %x and %X cases, notably INT_MIN for %i and %d and some hexadecimal numbers which we'll be comparing to %x and %X*/

	int test_uidhex[10] = {1337, 0x1337, -42, -2147483648, 0x42, 0x41235, 4919, 66, 41235, 2147483648};
	comp_uidhex(test_uidhex, 10);

	/* And lastly testing out %p cases, notably NULL*/
	void **test_p = (void **)calloc(4, sizeof(void *));
	void *test_p1;
	void *test_p2;
	void *test_p3;
	test_p[0] = test_p1; test_p[1] = test_p2; test_p[2] = test_p3;
	comp_ptr(test_p, 4);
}
