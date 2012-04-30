#include <iostream>

#include "Level.h"

int main (int argc, char * const argv[]) {
	if (argc == 1) {
		printf("Please provide arguments, use --help to view documentation.\n");
		return 0;
	} else {
		if (strcmp(argv[1], "--help") == 0) {
			printf("Display help docs here\n");
		} else {
			
		}
	}
    return 0;
}
