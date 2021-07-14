#include "rsh.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
int rsh_cd(char ** args);
char *buildin[] = {
	"cd",
	"exit"
};
int rsh_cd(char ** args) {
	if (args[1] == NULL) {
		fprintf(stderr, "rsh : expected argument to \"cd\"\n");
	} 
	else {
		if (chdir(args[1]) != 0) {
			perror("rsh");
		}
	}
	return 1;
}
int rsh_exit() {
	return 0;
}
int rsh_do(char ** args) {
	pid_t pid, wpid;
	int stat;
	pid = fork();
	if (pid == 0) { // we are child
		if (execvp(args[0], args) == -1) {
			perror("rsh");
		}
		exit(1);
	}
	else if (pid < 0) {
		perror("rsh");
	}
	else {
		do {
			wpid = waitpid(pid, &stat, WUNTRACED);
		} while(!WIFEXITED(stat) && !WIFSIGNALED(stat));
	}
	return 1;
}
#define TOK_DELIM " \t\r\n\a"
char ** rsh_split_line(char *line)
{
	int BUFSIZE = 64;
	  int bufsize = BUFSIZE, position = 0;
	  char **tok = malloc(bufsize * sizeof(char*));
	  char *token;
	
  	if (!tok) {
    	fprintf(stderr, "rsh : alloc error");
    	exit(1);
  	}
  	token = strtok(line, TOK_DELIM);
  	while (token != NULL) {
    	tok[position] = token;
    	position++;
	
    	if (position >= bufsize) {
      		bufsize += BUFSIZE;
      		tok = realloc(tok, bufsize * sizeof(char*));
      		if (!tok) {
        		fprintf(stderr, "lsh: allocation error\n");
        		exit(EXIT_FAILURE);
      		}
    	}
    token = strtok(NULL, TOK_DELIM);
  }
  tok[position] = NULL;
  return tok;
}
char * rsh_read_line() {
	int BUFSIZE = 1024;
	int pos = 0;
	char * buf = calloc(1, BUFSIZE);
	int c;
	if (!buf) {
		fprintf(stderr,"rsh : alloc error");
		exit(1);
	}
	while (1) {
		c = getchar();
		if (c == EOF || c == '\n' || c == '#') {
			buf[pos] = '\0';
			return buf;
		}
		else {
			buf[pos] = c;
		}
		pos++;
		if (pos-- >= BUFSIZE) {
			BUFSIZE += BUFSIZE;
			buf = realloc(buf, BUFSIZE);
			if (!buf) {
				fprintf(stderr, "rsh : alloc error");
				exit(1);
			}
		}	
	}
}
int (*builtin_func[]) (char **) = {
	&rsh_cd,
	&rsh_exit
};
int rsh_exe(char ** args) {
	int i;
	if (args[0] == NULL) {
		return 1;
	}
	for (i = 0; i < 2; i++) {
		if (strcmp(args[0], buildin[i]) == 0) {
			return (*builtin_func[i])(args);
		}
	}
	return rsh_do(args);
}
void rsh_main_loop() {
	char * line;
	char ** args;
	int stat = 1;
	do {
		printf(">>> ");
		line = rsh_read_line();
		args = rsh_split_line(line);
		stat = rsh_exe(args);
		free(line);
		free(args);
	} while (stat);
}
int main() {	
	rsh_main_loop();
	return 0;
}
