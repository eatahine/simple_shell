#include "shell.h"
/**
 ** new_cd - Changes the current working directory .
 ** if no parameter is passed it will change directory to HOME.
 * * @vars: A string representing the input from the user.
 */
void new_cd(vars_t *vars)
{
	int index;

	if (vars->array_tokens[1] == NULL)
	{
	index = find_env_index(*vars, "HOME");
	chdir((vars->env[index]) + 5);
	}
	else if (_strcmpr(vars->array_tokens[1], "-") == 0)
	print_str(vars->array_tokens[1], 0);
	else
	chdir(vars->array_tokens[1]);
}

/**
 ** print_cd_1 - Prints error when cd argument in invalid
 **              i.e. cd -asd22
 ** @vars: vars parameter to include
 * * Return: Always return void and print a messaje as shown below.
 */
void print_cd_1(vars_t *vars)
{
	print_str("-bash: cd: ", 1);
	print_str(vars->array_tokens[1], 1);
	print_str(": invalid option", 0);
	print_str("cd: usage: cd [-] [--]", 0);
}

/**
 ** print_cd_2 - Prints error message when cd argument doesn'n exist.
 **              i.e. cd das7d32
 ** @vars: vars parameter to include
 ** Return: Always return void and print a messaje as shown below.
 */
void print_cd_2(vars_t *vars)
{
	print_str("-bash: cd: ", 1);
	print_str(vars->array_tokens[1], 1);
	print_str(": Not a directory", 0);
}
