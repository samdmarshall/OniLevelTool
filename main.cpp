#include "headers.h"

#include "OniTag.h"
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
			bool status = level->LoadPath(argv[1]);
			printf("Load Success: %s\n\n", status ? "Yes" : "No");
			if (status) {
				printf("      Name: %s\n",level->name);
				printf("  Platform: %s\n", ((level->platform-1) ? "Mac/Demo" : "PC"));
				printf("Level Type: %s\n", ((level->type-1) ? "oni" : "dat"));
			}
			level->LoadTags();
			level->ExportAllTags();
		}
	}
    return 0;
}
