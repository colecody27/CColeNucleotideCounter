/*
 ============================================================================
 Name        : CColeNucleotideCounter.c
 Author      : Cody Cole
 Version     :
 Copyright   : 26 August 20
 Description : Program to count nucleotide
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0); //Turns off output buffering
	char iFileName[30];
	char oFileName[30];
	FILE *ifPtr;
	FILE *ofPtr;

	//Prompt user for input filename and open file for reading
	puts("Please enter input filename");
	scanf("%s", iFileName);
	if (fopen(iFileName, "r") == NULL) {
		puts("File name does not exist \nProgram exit");
		return (-1);
	} else {
		ifPtr = fopen(iFileName, "r");
		//Prompt to user for output filename
		puts("Please enter output filename");
		scanf("%s", oFileName);
		if (fopen(oFileName, "w") == NULL) {
			puts("File name does not exist \nProgram exit");
			return (-1);
		} else {
			ofPtr = fopen(oFileName, "w");
			int aCount = 0, cCount = 0, gCount = 0, tCount = 0;
			int newLine = 0;
			//While not end of file
			while (!feof(ifPtr)) {
				char letter;
				//fscanf(ifPtr, "%c", &letter);
				letter = fgetc(ifPtr);
				switch (letter) {
				case 'A':
					aCount++;
					break;
				case 'C':
					cCount++;
					break;
				case 'G':
					gCount++;
					break;
				case 'T':
					tCount++;
					break;
				case '\n': //Might not read as char
					newLine++;
					break;
				default:
					break;
				}
				if (newLine) { //If the character is a newline
					//Write count to file
					fprintf(ofPtr, "%d %d %d %d \n", aCount, cCount, gCount,
							tCount);
					//reset counts, including newline
					//printf("%d %d %d %d\n", aCount, cCount, gCount, tCount);
					aCount = 0, cCount = 0, gCount = 0, tCount = 0, newLine = 0;
				}
			}
			//Reset file pointer
			rewind(ifPtr);
			//Close files
			fclose(ifPtr);
			fclose(ofPtr);
			puts("Complete");
		}
	}

	return EXIT_SUCCESS;
}
