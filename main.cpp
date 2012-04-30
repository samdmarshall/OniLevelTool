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
			printf("Success: %s\n", status ? "Yes" : "No");
			
			for (int32_t i = 0; i < level->header->instance_count; i++) {
				OniTag *tag = new OniTag;
				tag->LoadFrom(&level->instance_descriptors[i], level->data_table, level->names_table);
				delete tag;
			}
		}
	}
    return 0;
}
