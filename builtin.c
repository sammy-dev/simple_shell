#include "shell.h"

/**
 * 
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
	int exitchecker;

	if (info->argv[1])  
	{
		exitchecker = _erratoi(info->argv[1]);
		if (exitchecker == -1)
		{
			info->status = 2;
			print_error(info, "Illegal numbers taken: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _mycd(info_t *info)
{
	char *k, *dir_p, buffer_mem[1024];
	int chdir_rett;

	k = getcwd(buffer_mem, 1024);
	if (!k)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir_p = _getenv(info, "HOME=");
		if (!dir_p)
			chdir_rett = /* TODO: what should this be? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_rett = chdir(dir_p);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(k);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_rett = /* TODO: what should this be? */
			chdir((dir_p = _getenv(info, "OLDPWD=")) ? dir_p : "/");
	}
	else
		chdir_rett = chdir(info->argv[1]);
	if (chdir_rett == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer_mem, 1024));
	}
	return (0);
}

/**
 * _myhelp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **argument_arrays;

	argument_arrays = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*argument_arrays); /* temp att_unused workaround */
	return (0);
}
