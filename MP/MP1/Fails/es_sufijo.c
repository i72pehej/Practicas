#include <stdio.h>
#include <math.h>
#include <string.h>

/*
char *strtstr(const char *c_grande, const char *c_peque){

}
*/

int main(int argc, char const *argv[])
{
	const char c_grande[20]="TutorialsPoint";
	const char c_peque[10]="Point";
	char *res;

	res=strtstr(c_grande, c_peque);

	printf("El sufijo es: %s\n", res);

	return 0;
}
