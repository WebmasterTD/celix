/*
 * test.c
 *
 *  Created on: Jul 31, 2011
 *      Author: alexander
 */
#include <stdio.h>
#include <stdlib.h>

#include "hessian_2.0_out.h"
#include "hessian_2.0_in.h"

int main(int argc, char **argv) {
	hessian_out_t out = malloc(sizeof(*out));

//	hessian_writeDouble(out, 12.25);
//	hessian_writeUTCDate(out, 894621091000l);
//	hessian_writeLong(out, 1324123l);
//	hessian_writeString(out, "hello");
	unsigned char b[22];
	int i = 0;
	b[i++] = 'a';b[i++] = 'b';b[i++] = 'c';b[i++] = 'd';b[i++] = 'e';b[i++] = 'f';b[i++] = 'g';b[i++] = 'h';b[i++] = 'i';b[i++] = 'j';b[i++] = 'k';
	b[i++] = 'l';b[i++] = 'm';b[i++] = 'n';b[i++] = 'o';b[i++] = 'p';b[i++] = 'q';b[i++] = 'r';b[i++] = 's';b[i++] = 't';b[i++] = 'u';b[i++] = 'v';

	hessian_writeBytes(out, b, 22);
//	hessian_writeListBegin(out, 1, "string");
//	hessian_writeString(out, "test");
//	hessian_writeListEnd(out);

	//4832798725635008448

	double d = 81273459184.123;
	char *langeString = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz"
			"abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";

//	printf("Stringl: %d\n", strlen(langeString));

//	hessian_writeString(out, langeString);


	for (i = 0; i < out->offset; i++) {
		printf("%X ", out->buffer[i]);
	}
	printf("\n");


	FILE *fp = fopen("mybinfile.ttt", "wb");

	//the string length + 1 for the null terminator
	fwrite(out->buffer, sizeof(char), out->offset, fp);

	fclose(fp);

	out->offset = 0;
	unsigned char *rb = NULL;
	int read;
	rb = NULL;
	hessian_readNBytes(out, 0, 10, &rb, &read);
	printf("Read: %s\n", rb);
	char ch;
	hessian_readByte(out, &ch);
	printf("Read: %c\n", ch);
	hessian_readByte(out, &ch);
		printf("Read: %c\n", ch);
		hessian_readByte(out, &ch);
			printf("Read: %c\n", ch);
			hessian_readByte(out, &ch);
				printf("Read: %c\n", ch);
				rb = NULL;
					hessian_readNBytes(out, 0, 10, &rb, &read);
					printf("Read: %s\n", rb);
	printf("Read: %d\n", read);
}

