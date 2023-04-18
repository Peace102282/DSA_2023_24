#include<stdio.h>
#include<Stdlib.h>
#include<string.h>
void read_lines(char lines[10][100], int *num_lines) {
    char line[100];
    while (*num_lines < 10) {
        fgets(line, 100, stdin);
        if (line[0] == '\n') {
            break;
        }
        strncpy(lines[*num_lines], line, 100);
        (*num_lines)++;
    }
}
int Length(char *strings)
{
    int i;
    for(i=0;strings[i]!='\0';++i);

    return i;
}
void find_longest_line(char lines[10][100], int num_lines) {
    int longestLength = 0;
    char *longestLine = NULL;
    for (int i = 0; i < num_lines; i++) {
        int length = Length(lines[i]);
        if (length > longestLength) {
            longestLength = length;
            longestLine = lines[i];
        }
    }
    if (longestLine != NULL) {
        printf("Longest line: %s", longestLine);
    } else {
        printf("No lines read\n");
    }
}
int main(){
 char lines[10][100];
    int num_lines = 0;

    // Read lines from user input
    printf("Enter up to %d lines of text, or an empty line to stop:\n", 10);
    read_lines(lines, &num_lines);
      find_longest_line(lines, num_lines);

}
