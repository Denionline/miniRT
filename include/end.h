#ifndef END_H
# define END_H

enum ERROR_CODE {
	ERR_MALLOC = 42,
	ERR_NOT_ENOUGH_ARGS,
	ERR_OPEN_FILE,
	ERR_INVALID_TUPLE,
	ERR_UNKNOWN_IDENTIFIER,
	ERR_OUT_OF_RANGE,
	ERR_INVALID_CHAR,
};

void	end(t_scene *scene, enum ERROR_CODE status_code);
void	print_error(enum ERROR_CODE error_code);

#endif