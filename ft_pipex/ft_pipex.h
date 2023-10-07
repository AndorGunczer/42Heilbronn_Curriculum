#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdarg.h>

struct s_pipex {
	int		i;
	char	**cmnd;
	char	**paths;
	char	*full_path;
	char	*temp;
};

int		main(int argc, char **argv, char **envp);

int		child(int end[], char **argv, char **envp);
int		parent(int end[], char **argv, char **envp);

int		check_file(char *filename, char R_o_W);
int		check_command(struct s_pipex pipex, char **cmnd);
void	exec_command(struct s_pipex *pipex, char **envp);

void	ft_single_free(char **string);
void	ft_double_free(char	**string);
void	ft_custom_free(char **str1, char **str2, char SD);

#endif
