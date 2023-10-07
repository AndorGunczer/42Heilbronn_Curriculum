#include "ft_pipex.h"

int	check_file(char *filename, char R_o_W)
{
	if (R_o_W == 'W')
	{
		if (access(filename, W_OK) == -1)
		{
			ft_putstr_fd("permission denied ", 2);
			ft_putendl_fd(filename, 2);
			return (-1);
		}
	}
	else if (R_o_W == 'R')
	{
		if (access(filename, F_OK) == -1)
		{
			ft_putstr_fd("no such file or directory: ", 2);
			ft_putendl_fd(filename, 2);
			return (-1);
		}
		else if (access(filename, R_OK) == -1)
		{
			ft_putstr_fd("permission denied ", 2);
			ft_putendl_fd(filename, 2);
			return (-1);
		}
	}
	return (0);
}

void	exec_command(struct s_pipex *pipex, char **envp)
{
	while (pipex->paths[pipex->i] != 0)
	{
		pipex->temp = ft_strjoin(pipex->paths[pipex->i], "/");
		pipex->full_path = ft_strjoin(pipex->temp, pipex->cmnd[0]);
		if (access(pipex->full_path, F_OK) != -1)
		{
			execve(pipex->full_path, pipex->cmnd, envp);
			ft_custom_free(&pipex->full_path, &pipex->temp, 'S');
			return ;
		}
		ft_custom_free(&pipex->full_path, &pipex->temp, 'S');
		(pipex->i)++;
	}
}

int	check_command(struct s_pipex pipex, char **cmnd)
{
	while (pipex.paths[pipex.i] != 0)
	{
		pipex.temp = ft_strjoin(pipex.paths[pipex.i], "/");
		pipex.full_path = ft_strjoin(pipex.temp, cmnd[0]);
		if (access(pipex.full_path, F_OK) != -1)
		{
			ft_custom_free(&pipex.full_path, &pipex.temp, 'S');
			return (0);
		}
		ft_custom_free(&pipex.full_path, &pipex.temp, 'S');
		(pipex.i)++;
	}
	ft_putstr_fd("Command not found: ", 2);
	ft_putendl_fd(cmnd[0], 2);
	return (-1);
}
