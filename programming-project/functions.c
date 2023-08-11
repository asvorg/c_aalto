//function to read the input
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char command;
    char **arguments;
    int num_arguments;
} Command;

void parse_command(const char *input, Command *cmd) {
    cmd->num_arguments = 0;
    cmd->arguments = NULL;

    // Find the command character
    cmd->command = input[0];

    // Find the start of the arguments
    const char *args_start = strchr(input, ' ');
    if (args_start == NULL) {
        return; // No arguments found
    }

    // Count the number of arguments
    const char *arg = args_start + 1;
    while (*arg != '\0') {
        if (*arg == ' ') {
            cmd->num_arguments++;
        }
        arg++;
    }
    cmd->num_arguments++; // Count the last argument

    // Allocate memory for the arguments
    cmd->arguments = (char **)malloc(cmd->num_arguments * sizeof(char *));
    if (cmd->arguments == NULL) {
        return; // Memory allocation error
    }

    // Copy the arguments into allocated memory
    char *arg_copy = strdup(args_start + 1); // Skip the first space
    if (arg_copy == NULL) {
        free(cmd->arguments);
        cmd->arguments = NULL;
        return; // Memory allocation error
    }

    char *token = strtok(arg_copy, " ");
    int i = 0;
    while (token != NULL) {
        cmd->arguments[i] = strdup(token);
        if (cmd->arguments[i] == NULL) {
            // Memory allocation error
            for (int j = 0; j < i; j++) {
                free(cmd->arguments[j]);
            }
            free(cmd->arguments);
            cmd->arguments = NULL;
            return;
        }
        i++;
        token = strtok(NULL, " ");
    }

    free(arg_copy);
}

//check if the input is valid
int check_input(const char *input) {
    if (input == NULL) {
        return 0;
    }

    // Check if the command is valid
    if (input[0] != 'a' && input[0] != 'd' && input[0] != 'f' && input[0] != 'p' && input[0] != 'r' && input[0] != 's' && input[0] != 't' && input[0] != 'u' && input[0] != 'x') {
        return 0;
    }

    // Check if the arguments are valid
    const char *args_start = strchr(input, ' ');
    if (args_start == NULL) {
        return 0; // No arguments found
    }

    const char *arg = args_start + 1;
    while (*arg != '\0') {
        if (*arg != ' ' && *arg != '0' && *arg != '1') {
            return 0;
        }
        arg++;
    }

    return 1;
}