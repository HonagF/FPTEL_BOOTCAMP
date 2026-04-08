/**
 ***********************************************************************
 * @author: honag
 * @credit: based on the code of GaoKong 
 * @date: 08 - 04 - 2026
 ***********************************************************************
 **/

 #ifndef __CMD_LINE_H__
 #define __CMD_LINE_H__

 #ifdef __cplusplus
 extern "C" {
    #endif

    #include <stdint.h>

    #define CMD_LINE_MAX_SIZE 12

    #define CMD_TBL_NOT_FOUND 0     //Command not found in the command table
    #define CMD_SUCCESS 1           //Successfully executed the command
    #define CMD_NOT_FOUND 2         //Command found but not recognized
    #define CMD_TOO_LONG 3          //Command line is too long
    #define CMD_EMPTY 4             //Command line is empty
    #define CMD_INVALID_ARG 5       //Invalid argument provided to the command
    #define CMD_EXECUTION_ERROR 6    //Error occurred during command execution
    #define CMD_UNKNOWN_ERROR 7      //An unknown error occurred

    typedef int32_t (*p_cmd_func)(uint8_t* argv); // Command function pointer type, takes a pointer to the command arguments and returns an int32_t status code

    typedef struct {
        const char* cmd_name;     // Command name
        p_cmd_func cmd_func;      // Command function pointer
    } cmd_line_t;

    extern uint8_t cmd_line_parser(cmd_line_t* cmd_tbl, uint8_t* cmd); // Parses the command line and executes the corresponding command function
    #ifdef __cplusplus
}
#endif

#endif /* __CMD_LINE_H__ */
