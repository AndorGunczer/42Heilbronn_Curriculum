#include "ft_pipex.h"

char	**path_finder(char **envp)
{
	int		i;
	char	*temp;
	char	**paths;

	i = 0;
	while (envp[i] != '\0')
	{
		if (envp[i][0] == 'P' && envp[i][1] == 'A'
			&& envp[i][2] == 'T' && envp[i][3] == 'H')
		{
			temp = ft_substr(envp[i], 5, (ft_strlen(envp[i]) - 5));
			paths = ft_split(temp, ':');
			free(temp);
		}
		i++;
	}
	return (paths);
}

int	parent(int pipes[], char **argv, char **envp)
{
	int				out;
	struct s_pipex	pipex;

	out = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0666);
	wait(0);
	if (check_file(argv[4], 'W') != -1)
	{
		close(pipes[1]);
		dup2(pipes[0], 0);
		dup2(out, 1);
		pipex.cmnd = ft_split(argv[3], ' ');
		pipex.paths = path_finder(envp);
		pipex.i = 0;
		check_command(pipex, ft_split(argv[3], ' '));
		exec_command(&pipex, envp);
		ft_custom_free(pipex.paths, pipex.cmnd, 'D');
	}
	close(out);
	exit(0);
}

int	child(int pipes[], char **argv, char **envp)
{
	int				in;
	struct s_pipex	pipex;

	if (check_file(argv[1], 'R') != -1)
	{
		in = open(argv[1], O_RDONLY);
		close(pipes[0]);
		dup2(pipes[1], 1);
		dup2(in, 0);
		pipex.cmnd = ft_split(argv[2], ' ');
		pipex.paths = path_finder(envp);
		pipex.i = 0;
		check_command(pipex, ft_split(argv[2], ' '));
		exec_command(&pipex, envp);
		ft_custom_free(pipex.paths, pipex.cmnd, 'D');
		close(in);
	}
	exit(0);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		pipes[2];

	if (argc != 5 || pipe(pipes) == -1)
	{
		perror("Error");
		return (0);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (0);
	}
	else if (pid == 0)
		child(pipes, argv, envp);
	else
		parent(pipes, argv, envp);
	return (0);
}
