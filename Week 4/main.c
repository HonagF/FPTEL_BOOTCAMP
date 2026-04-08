/**
 ***********************************************************************
 * @author: honag
 * @credit: based on the code of GaoKong 
 * @date: 08 - 04 - 2026
 ***********************************************************************
 **/

#include "cmd_line.h"
#include <stdio.h>
#include <string.h>

/*Extra: LED Handler*/
int32_t led_handler(uint8_t* argv){
    if(argv == NULL || *argv == '\0'){
        printf("[LED Handler] No arguments provided.\n");
        return CMD_INVALID_ARG;
    }
    if(strcmp((char*)argv, "on") == 0){
        printf("[LED Handler] LED turned ON.\n");
        return CMD_SUCCESS;
    }
    else if(strcmp((char*)argv, "off") == 0){
        printf("[LED Handler] LED turned OFF.\n");
        return CMD_SUCCESS;
    }
    else {
        printf("[LED Handler] Invalid argument: %s. Use 'on' or 'off'.\n", argv);
        return CMD_INVALID_ARG;
    }
    return CMD_UNKNOWN_ERROR;               // should never reach here, added just in case 
}
/*Help cmd*/
int32_t help_handler(uint8_t* argv){
    printf("   -> [HELP] Available commands:\n");
    printf("    - led [on/off]: Control the LED state.\n");
    printf("    - help:         Show this help message.\n");
    printf("    - exit:         Exit the command line interface.\n");
    return CMD_SUCCESS;
}

cmd_line_t my_cmd_tbl[] = {
    {"led", led_handler},
    {"help", help_handler},
    {NULL, NULL} // End of command table marker
};

int main(){
    char cmd_input[50];

    printf("== COMMAND LINE PARSER TESTER ==\n");
    printf("Type 'help' to see available commands. Type 'exit' to quit.\n");

    while (1){
        printf("Honag CLI >");

        if(fgets(cmd_input, sizeof(cmd_input), stdin) != NULL){
            cmd_input[strcspn(cmd_input, "\r\n")] = '\0'; // Remove trailing newline characters

            if(strcmp(cmd_input, "exit") == 0){
                printf("Exiting CLI.......................................\n");
                printf("Goodbye!\n");
                break;
            }
            if(strlen(cmd_input) == 0){
                continue; // Skip empty input
            }
            uint8_t status = cmd_line_parser(my_cmd_tbl, (uint8_t*)cmd_input);
            switch (status){
                case CMD_SUCCESS:
                    break;
                case CMD_NOT_FOUND:
                    printf("Error: Command not found.\n");
                break;
                case CMD_TOO_LONG: 
                    printf("Error: Command line is too long. Maximum length is %d characters.\n", CMD_LINE_MAX_SIZE);
                    break;
                case CMD_EMPTY:
                    printf("Error: Command line is empty.\n");
                    break;
                case CMD_INVALID_ARG:
                    break;
                case CMD_EXECUTION_ERROR:
                    printf("Error: An error occurred during command execution.\n");
                    break;
                default:
                    printf("Error: An unknown error occurred.\n");
                    break;
        }
    }
}
return 0;
}