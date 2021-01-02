#include <stdio.h>
#include <string.h>

void getTheAnswer()
{
	FILE* input = fopen("input.txt", "r");
	if (input == NULL)
	{
		printf("File not found");
		return;
	}
	FILE* output = fopen("output.txt", "w");
	if (output == NULL)
	{
		return;
	}

	while (!feof(input))
	{
		char string[500] = "0";
		fgets(string, 500, input);
		int i = 0;
		for (; string[i] != ';' && string[i] != '\0'; i++)
		{
		}
		for (; string[i] != '\0'; i++)
		{
			fprintf(output, "%c", string[i]);
		}
	}

	fclose(input);
	fclose(output);
}

int main()
{
	getTheAnswer();

	return 0;
}