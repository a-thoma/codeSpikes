/*
 * @AUTHOR: fudgyone
 * https://github.com/fudgyone
 *
 * Just a shell for funsies. If you can even call it a shell. Very barebones.
 * Takes arguments via fgets into a char buffer, parses them, then passes
 * them on to the OS via system call.
 */

#include <stdio.h>
#include <stdlib.h> // for calloc
#include <string.h> // for strtok
#include <unistd.h> // for...
#include <dirent.h> // for...

int main(int argc, const char *argv[]) {
	
	/*
	 * Front Declarations
	 */

	// We need...
	char *buf = (char*)calloc(256, sizeof(char)); // char buffer to take args
	// char *strbuf[64]; // 2-d char array for strings made of args (size???)

	// for tokens...
	char *token; // pointer to token char
	const char s[2] = " ";

	/*
	 * Actual Code
	 */

	// Prompt the user
	printf("Please enter a command: ");

	// Read in whatever they put in, limit 256 chars
	fgets(buf, 256, stdin);

	/*
	// !!!placeholder!!!
	// print the buffer as one string
	printf("%s\n", buf);
	*/

	// Get the first token, using delimiter s
	token = strtok(buf, s);

	/*
	// !!!placeholder!!!
	// print the buffer, split by tokens (parsing args)
	while(token != NULL) {

		// print the first token
		printf("%s\n", token);

		// set token to NULL with delimiter s
		token = strtok(NULL, s);
	}
	*/

	//

	return 0;
}