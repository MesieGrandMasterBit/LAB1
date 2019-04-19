#include <stdio.h>
#include <stdlib.h>

void recognition(char* string)
{
	int j = 0;
	int circ = 0;
	int tri = 0;
	int error = 0;
	char circle[6] = {'c', 'i', 'r', 'c', 'l', 'e'};
	char triangle[8] ={'t', 'r', 'i', 'a', 'n', 'g', 'l', 'e'};

	while(string[j] != '('){
		if(string[j] == circle[j]){
			circ = 1;
		}
			else {
				error = 1;
			}
		if(string[j] == triangle[j]){
			tri = 1;
		}
			else {
				error = 1;
			}
				j++;
		}
		if(circ == 1)
			printf("Cirle\n");
		if(tri == 1)
			printf("Triangle\n");
		if(error == 1)
			printf("Error\n");
		}

void output_geometry(char *string_two, double p, double s, int i)
{
	FILE *geom;
	geom = fopen("geometry_output.txt", "a");

	fprintf(geom, "%d. ", i);
	fputs(string_two, geom);
	fprintf(geom, "\n\tperimeter = %.4f\n", p);
	fprintf(geom, "\tarea = %.4f\n", s);
	fprintf(geom, "\tintersects: \n\n");

	fclose(geom);

}

int main()
{
	int n = 50;
	int p = 0;
	int s = 0;
	int i = 0;
	char *string = NULL;
	char *string_c = NULL;
	int *string_i = NULL;
	string =(char*) calloc(n, sizeof(char));
	string_i =(int*) calloc(n, sizeof(int));
	string_c =(char*) calloc(n, sizeof(char));

	FILE *geom;

	geom = fopen("geometry_input.txt", "r");
	while(feof(geom) == 0) {
		int j = 0;
		fgets(string_c, 50, geom);
		//fgets(string_i, 50, geom);
		++i;
	while(string_c[j] != '\n') {
		string[j] = string_c[j];
		++j;
	}
	//recognition(string, &p, &s);
	output_geometry(string, p, s, i);

	}

	fclose(geom);

	//printf("%d\t%d", p, s);
return 0;
}
