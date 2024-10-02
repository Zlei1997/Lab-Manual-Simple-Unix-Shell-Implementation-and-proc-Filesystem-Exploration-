#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024

void execute_command(char *cmd) {
    char *args[MAX_CMD_LEN / 2 + 1];
    char *token;
    int arg_count = 0;

    // Split the command into arguments
    token = strtok(cmd, " \t\r\n");
    while (token != NULL) {
        args[arg_count++] = token;
        token = strtok(NULL, " \t\r\n");
    }
    args[arg_count] = NULL;

    if (arg_count == 0) {
        return;  // Empty command
    }

    // Built-in command: exit
    if (strcmp(args[0], "exit") == 0) {
        int status = 0;
        if (arg_count > 1) {
            status = atoi(args[1]);
        }
        exit(status);
    }

    // Fork a child process to execute the command
    pid_t pid = fork();
    if (pid == 0) {  // Child process
        if (execvp(args[0], args) == -1) {
            perror("Error executing command");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {  // Forking error
        perror("Error forking");
    } else {  // Parent process
        wait(NULL);  // Wait for the child process to complete
    }
}

void proc_command(char *filename) {
    char path[MAX_CMD_LEN];
    snprintf(path, sizeof(path), "/proc/%s", filename);

    FILE *file = fopen(path, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

void execute_command(char *cmd) {
    // Existing code...

    if (strcmp(args[0], "proc") == 0) {
        if (arg_count > 1) {
            proc_command(args[1]);
        } else {
            printf("Usage: proc <filename>\n");
        }
        return;
    }

    // Existing code...
}

int main() {
    char cmd[MAX_CMD_LEN];

    while (1) {
        printf("simple_shell> ");
        if (fgets(cmd, sizeof(cmd), stdin) == NULL) {
            break;
        }

        execute_command(cmd);
    }

    return 0;
}
