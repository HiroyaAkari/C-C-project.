#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <direct.h> 

#define MAX_INPUT 1024
#define MAX_ARGS 64

void print_prompt() {
    printf("rika: ");
    fflush(stdout);
}

char* read_input() {
    char* input = malloc(MAX_INPUT);
    if (!input) {
        perror("malloc failed");
        exit(1);
    }
    
    if (fgets(input, MAX_INPUT, stdin) == NULL) {
        free(input);
        return NULL;
    }
    
    input[strcspn(input, "\n")] = 0;
    return input;
}

int parse_input(char* input, char** args) {
    int i = 0;
    char* token = strtok(input, " \t");
    
    while (token != NULL && i < MAX_ARGS - 1) {
        args[i] = token;
        token = strtok(NULL, " \t");
        i++;
    }
    args[i] = NULL;
    return i;
}

void build_cmd_line(char** args, char* cmd_line) {
    cmd_line[0] = '\0';
    for (int i = 0; args[i] != NULL; i++) {
        if (i > 0) strcat(cmd_line, " ");
        strcat(cmd_line, args[i]);
    }
}

int handle_builtin(char** args, int arg_count) {
    if (args[0] == NULL) return 1;
    
    if (strcmp(args[0], "exit") == 0 || strcmp(args[0], "quit") == 0) {
        printf("Goodbye!\n");
        exit(0);
    }
    
    if (strcmp(args[0], "cd") == 0) {
        if (arg_count < 2) {
            fprintf(stderr, "cd: missing argument\n");
        } else {
            if (_chdir(args[1]) != 0) {
                perror("cd failed");
            }
        }
        return 1;
    }
    
    if (strcmp(args[0], "help") == 0) {
        printf("rika Commands:\n");
        printf("  cd <dir>  - Change directory\n");
        printf("  exit      - Exit shell\n");
        printf("  help      - Show this help\n");
        printf("  <cmd>     - Execute any command (dir, echo, cls, etc.)\n");
        return 1;
    }
    
    return 0;
}

void execute_command(char** args) {
    char cmd_line[MAX_INPUT];
    build_cmd_line(args, cmd_line);
    
    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    
    if (!CreateProcess(NULL, cmd_line, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        fprintf(stderr, "Command not found: %s\n", args[0]);
        return;
    }
    
 
    WaitForSingleObject(pi.hProcess, INFINITE);
    
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

int main() {
    char* input;
    char* args[MAX_ARGS];
    int arg_count;
    
    printf("=== Rika Shell (Windows) ===\n");
    printf("Type 'help' for commands, 'exit' to quit\n\n");
    
    while (1) {
        print_prompt();
        input = read_input();
        
        if (input == NULL) {
            printf("\n");
            break;
        }
        
        if (strlen(input) == 0) {
            free(input);
            continue;
        }
        
        arg_count = parse_input(input, args);
        
        if (!handle_builtin(args, arg_count)) {
            execute_command(args);
        }
        
        free(input);
    }
    
    return 0;
}