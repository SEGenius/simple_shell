#include "shell.h"

/**
 * _getenv - gets an environment varying
 * @name: name of the environment variable.
 * @env: environment
 * Return: the value of the variable scoured.
*/
char *_getenv(const char *name, char **env)
{
		char *gewill = NULL;
			int i;

			if (env == NULL)
			return (NULL);

			for (i = 0; env[i]; i++)
			{

				getwill = strtok(env[i], "=");

				if (strcmp(getwill, name) == 0)
				{
					return (strtok(NULL, "\n"));
				}
			}

			return (NULL);
}
