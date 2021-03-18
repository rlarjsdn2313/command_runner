#include <stdio.h>
#include <string.h>

#define LINE_BUF 10240
#define BIG_BUF 40960

void run_command(char* command, char* buf) {
	FILE *fp = NULL;
	char line[LINE_BUF];
	
	if ((fp = popen(command, "r")) == NULL){
		return;
	}
		
	while (fgets(line, LINE_BUF, fp) != NULL) {
		strcat(buf, line);
	}
			
	pclose(fp);	
}

int main() {
	char buf[BIG_BUF];
	run_command("ls", buf);
	
	printf("%s", buf);
		
	return 1;
}