#ifndef END_H
# define END_H

enum ERROR_CODE {
	ERR_MALLOC = 42,
	ERR_OPEN_FILE = 43,
	ERR_NOT_ENOUGH_ARGS,
	ERR_INVALID_TUPLE,
	ERR_OUT_OF_RANGE,
	ERR_INVALID_CHAR,
	ERR_UNKNOWN_IDENTIFIER = 53,
};

void	end(t_scene *scene, int status_code, char *description, int to_free);
void	print_error(enum ERROR_CODE error_code, char *description);

#endif