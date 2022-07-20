#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char* argv[])
{
	FILE* fp1 = fopen(argv[1], "r");
	FILE* fp2 = fopen(argv[2], "r");
	
	uint32_t buffer1[1] = { 0, };
	uint32_t buffer2[1] = { 0, };
	
	fread(buffer1, 1, 4, fp1);
	fread(buffer2, 1, 4, fp2);
	
	uint32_t num1 = htonl(*buffer1);
	uint32_t num2 = htonl(*buffer2);
	uint32_t sum = num1 + num2;
	
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, htonl(*buffer1), num2, htonl(*buffer2), sum, htonl(*buffer1) + htonl(*buffer2));
	
	fclose(fp1);
	fclose(fp2);
	
	return 0;
}

