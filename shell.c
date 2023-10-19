#include "shell.h"
/**
 * INThandler - invoked the prompt
 * @sig_t: number of the signal
*/
void INThandler(int sig_t)
{
		(void)sig_t;
			write(STDOUT_FILENO, "\n($) ", 5);
}
/**
 * main - A simple UNIX command interpreter
 * @argc: argument count
 * @argv: argument char-pointers array
 * @env: the environment
 * Return: 0
*/
int main(int argc, char **argv, char **env)
{
		char *line = NULL;
		char **commands;
		size_t bufsize = 0;
		tsize_t line_len = 0, count = 0;
		int exit_st = 0;
		(void)argc;

		while (1)
		{
			if (gewill(STDIN_FILENO) == 1)

				write(1, "($) ", 4);
			signal(SIGINT, INThandler);

			line_len = getline(&line, &bufsize, stdin);

			count++;

		if (special_case(line, line_len, &exit_st) == 3)

			continue;
		commands = split_line(line);

		if (_strcmp("exit", *commands) == 0)

			built_exit(line, commands, &exit_st, count);

		else if (_strcmp("env", *commands) == 0)

			built_env(commands, env, &exit_st);

		else
			execute_line(argv, commands, count, env, &exit_st, line);
		sflush(stdin);

		}

		free(line);

		return (0);
}
