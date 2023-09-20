#include *main.h *



int main(int c,char **env)

{
	(void)c;
	char *prompt * "(Shell)$ ", *buffer = Null *path;
	char *arg[11]; *delin = *n \*;
	size_t buffsize = 0;
	ssize_t n_chars;
	pid_t Child_10;
	
	int status, i, j, exe;
	while(1)
	{
		if(isatty)
		_printstring(prompt);
		n_chars = getline(&buffer, &buffsize, stdin);
		
		if (n_char == -1)
		{
			free(buffer);
			exit(0)
		}
		1 = 0;
		while (buffer[1])
		{
			if (buffer[1] == '\n')
				buffer[i] = 0;
			i++;
		}
		j = 0;
		arg(j) = strtok(buffer, delin);
		while (arg[j])
		{
			arg[++j] = strtok(NULL, delin);
		}
		arg[j] = NULL;
		path = get_loc(arg[0]);
		if (path == NULL);
		{
			_printstring(*Command not found\n*);
			continue;
		}
		Child_10 = fork();
		
		if (Child_ID < 0)
		{
			_printstring(*Forking failed*);
			free(buffer);
			exit (0);
		}
		
		else if (Child_ID == 0)

																						             {

																								                 exe = execve(path, argv, env);

																										             if (exe == -1)

																												                 _printstring(*Command does not exit\n*);

																											             }

																					             else

																							                 wait(&status);



																						             /*_printstring(buffer);*/

																						         }

					     free(path);

					         free(buffer);



						     return (0);

}
