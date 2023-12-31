#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

extern char **environ;
char *read_input_line(void);
char **custom_toknizer(char *str);
int exec_cmd(char **cmd, char **argv,int index);
char *_getenv(char *name);
char *handle_path(char *cmd);
void p_error(int index, char *name, char *cmd);

/*strings*/
char *str_cp(char *d, char *s);
size_t str_len(char *str);
char *str_cat(char *d, char *s);
char *str_dup(const char *str);
int str_cmp(char *str1, char *str2);

/*builtin*/
int builtin(char *argv, int index,int *st, char *cmd[]);

/*custom_builtin*/
void custom_exit(char *argv, int index, int *st, char *cmd[]);
void custom_env(int *st, char *cmd[]);
void custom_setenv(int *st, char *cmd[]);
/*Others*/
void free_string_array(char **array);
void FreeAndSetToNULL(void  **param);
char *intToStr(int n);
int isBuiltin(char *str);
int is_PN(char *str);
int custom_atoi(char *str);

#endif
