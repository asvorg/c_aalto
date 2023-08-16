#include "project.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

struct Command {
    char command;
    char arg1[1000];
    char arg2[1000];
    char arg3[1000];
    char arg4[1000];
    
};

struct Data {
    char name[1000];
    int num_gold;
    int num_silver;
    int num_bronze;
};

#define MAX_DATA 1000


struct Command get_command() {
    char command[1];
    char arg1[1000];
    char arg2[1000];
    char arg3[1000];
    char arg4[1000];

    struct Command cmd;
    printf("Enter command: ");
    scanf(" %c", command);
    
    if (command[0] == 'M') {
        scanf("%s %s %s", arg2, arg3, arg4);
        int num_medals[3];
        sscanf(arg2, "%d", &num_medals[0]);
        sscanf(arg3, "%d", &num_medals[1]);
        sscanf(arg4, "%d", &num_medals[2]);
        cmd.command = 'M';
        sprintf(cmd.arg2, "%d %d %d", num_medals[0], num_medals[1], num_medals[2]);
        return cmd;
    }
    
    // Consume the rest of the line using fgets
    fgets(arg1, sizeof(arg1), stdin);
    sscanf(arg1, "%s %s", arg1, arg2);
    
    cmd.command = command[0];
    strcpy(cmd.arg1, arg1);
    strcpy(cmd.arg2, arg2);
    
    return cmd;
}


void initialize_database(struct Data database[], int *num_data) {
    *num_data = 0; 
}


void add_country(struct Data database[], int *num_data, char *country) {
    // check if country already exists
    for (int i = 0; i < *num_data; i++) {
        if (strcmp(database[i].name, country) == 0) {
            printf("Country already exists\n");
            return;
        }
    }
    
    // add country
    if (*num_data < MAX_DATA) {
        strcpy(database[*num_data].name, country);
        database[*num_data].num_gold = 0;
        database[*num_data].num_silver = 0;
        database[*num_data].num_bronze = 0;
        (*num_data)++;
        printf("Country '%s' added to the database.\n", country);
    } else {
        printf("Database is full, cannot add more countries.\n");
    }
}

void add_medals(struct Data database[], int num_data, char *name, int num_gold, int num_silver, int num_bronze) {
    int boolFound = 0;

    for (int i = 0; i < num_data; i++) {
        if (strcmp(database[i].name, name) == 0) {
            boolFound = 1;
        
            database[i].num_gold += num_gold;
            database[i].num_silver += num_silver;
            database[i].num_bronze += num_bronze;

            
            printf("Medals added to %s:\n", name);
            printf("Gold: %d\n", database[i].num_gold);
            printf("Silver: %d\n", database[i].num_silver);
            printf("Bronze: %d\n", database[i].num_bronze);
        }
    }
    
    if (boolFound == 0) {
        printf("Nation '%s' not found in the database.\n", name);
    }
}

void print_database(struct Data database[], int num_data){
    for (int i = 0; i < num_data; i++) {
        printf("%s %d %d %d\n", database[i].name, database[i].num_gold, database[i].num_silver, database[i].num_bronze);
    }
}

void write_to_file(struct Data database[], int num_data, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    for (int i = 0; i < num_data; i++) {
        fprintf(fp, "%s %d %d %d\n", database[i].name, database[i].num_gold, database[i].num_silver, database[i].num_bronze);
    }
    
    fclose(fp);
}
void load_from_file(struct Data database[], int *num_data, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    *num_data = 0;
    while (fscanf(fp, "%s %d %d %d", database[*num_data].name, &database[*num_data].num_gold, &database[*num_data].num_silver, &database[*num_data].num_bronze) != EOF) {
        //replace the current database with the one in the file
        (*num_data)++;

    }
    
    fclose(fp);
}


int main(void) {
    struct Data database[MAX_DATA];
    int num_data;
    initialize_database(database, &num_data);

    while (1) {
        struct Command cmd = get_command();
        if (cmd.command == 'Q') {
            break;
        } 
        if (cmd.command == 'A') {
            add_country(database, &num_data, cmd.arg1);
        }
        if (cmd.command == 'M') {
            int num_medals[3];
            sscanf(cmd.arg2, "%d %d %d", &num_medals[0], &num_medals[1], &num_medals[2]);
            add_medals(database, num_data, cmd.arg1, num_medals[0], num_medals[1], num_medals[2]);
        }
        if (cmd.command == 'L') {
            print_database(database, num_data);
        }
        if (cmd.command == 'W') {
            write_to_file(database, num_data, cmd.arg1);
        }
        if (cmd.command == 'O') {
            load_from_file(database, &num_data, cmd.arg1);
        }
    }
}