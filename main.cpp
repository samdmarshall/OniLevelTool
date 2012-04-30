#include "headers.h"

#include "Level.h"

int main (int argc, char * const argv[]) {
	if (argc == 1) {
		printf("Please provide arguments, use --help to view documentation.\n");
		return 0;
	} else {
		if (strcmp(argv[1], "--help") == 0) {
			printf("Display help docs here\n");
		} else {
			OniLevel *level = new OniLevel;
			bool status = level->Load(argv[1]);
			printf("Success: %s\n", status ? "Yes" : "No");
		}
	}
    return 0;
}
