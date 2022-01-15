#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	FILE *p1;
	p1 = fopen("data12.txt", "r");
	char c;
	int tlines = 0;
	int a = 0;
	if (p1 == NULL){
		printf("Could not open file");
		return 1;
	}
	while (1){
		c = fgetc(p1);
		if (c == EOF){
			break;
		}
		a++;
		if (c == '\n'){
			tlines++;
		}
	}
	rewind(p1);
	char *stixoi;
	stixoi = (char*) calloc(a, sizeof(char));
	printf("\n");
	int b = 0;
	while (1){
		c = fgetc(p1);
		if (c == EOF){
			break;
		}
		if (b <= a){
			stixoi[b] = c;
			b++;
		}
	}
	fclose(p1);
	
	int endlineind = 0;
	
	int s = -1;
	while (s == -1 || s > a ){
		printf("What line to print? It should be smaller than or equal to %i and bigger than zero! Dont numerize like a computer.\n", tlines+1);
		scanf(" %i", &s);
	}
	b = 0;
	s -= 1;
	while (b <= a){
		if (stixoi[b] == '\n'){
			endlineind++;
		}
		else if (s == endlineind){
			printf("%c", stixoi[b]);
		}
		b++;
	}
	
	
	return 0;
}