/**
 ***********************************************************************
 * @author: honag
 * @credit: based on the code of GaoKong 
 * @date: 08 - 04 - 2026
 ***********************************************************************
 **/

#include "cmd_line.h"
#include <string.h>
#include <stddef.h>

uint8_t cmd_line_parser(cmd_line_t* cmd_tbl, uint8_t* cmd){
    char cmd_buf[CMD_LINE_MAX_SIZE + 1]; // Buffer to hold the command line, +1 for null terminator
    uint8_t* p_cmd = cmd;                   // Pointer to traverse the command line
    uint8_t cmd_i = 0;                      // Index for the command buffer
    uint8_t i_check = 0;                    // Index for checking the command table

    if(cmd_tbl == NULL){
        return CMD_TBL_NOT_FOUND;           // Command table not found
    }
    if (cmd == NULL || *cmd == '\0' || *cmd == '\r' || *cmd == '\n') {
        return CMD_EMPTY;                    // Command line is empty
    }
    /*Parse the cmd line to extract command name*/
    while (*p_cmd != '\0'){
        if (*p_cmd == '\r' || *p_cmd == '\n' || *p_cmd == ' '){
            break;
        }

        cmd_buf[cmd_i++] = *p_cmd++;        // Copy the command character to the buffer
        
        if(cmd_i >= CMD_LINE_MAX_SIZE){
            return CMD_TOO_LONG;            // Command line is too long
        }
    }
    cmd_buf[cmd_i] = '\0';
    /*Extract arg*/
    while (*p_cmd == ' '){
        p_cmd++;                            // Skip spaces to find the start of arguments
    }
    uint8_t* argv = p_cmd;                  // Pointer to the arg
    int len = strlen((char*)argv);
    if (len > 0 && (argv[len - 1] == '\r' || argv[len - 1] == '\n')){
        argv[len - 1] = '\0';              // Remove trailing newline characters from arguments
        len --;
    }
    /*Lookup and execute*/
    while (cmd_tbl[i_check].cmd_name != NULL){
        if(strcmp(cmd_tbl[i_check].cmd_name, cmd_buf) == 0){
            if(cmd_tbl[i_check].cmd_func != NULL){
                uint32_t func_status = cmd_tbl[i_check].cmd_func(argv); // Execute the command function with the arg
                return (uint8_t)func_status; // Return the status code from the command fucntion
            } else {
                return CMD_EXECUTION_ERROR;
            }
        }
        i_check++;
    }
    return CMD_NOT_FOUND;                    // Command not found in the command table
}