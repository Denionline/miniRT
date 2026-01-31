#include "head.h"

void	print_error(enum ERROR_CODE error_code)
{
	if (error_code == ERR_MALLOC)
		printf("Malloc error\n");
	else if (error_code == ERR_NOT_ENOUGH_ARGS)
		printf("Invalid numbers of args, try: ./miniRT scenes/default.rt\n");
	else if (error_code == ERR_OPEN_FILE)
		printf("Error to open the scene\n");
	else if (error_code == ERR_INVALID_TUPLE)
		printf("Invalid point or vector\n");
	else if (error_code == ERR_UNKNOWN_IDENTIFIER)
		printf("Unknown identifier on line\n");
	else if (error_code == ERR_OUT_OF_RANGE)
		printf("Some parameter on scene is out of range\n");
	else if (error_code == ERR_INVALID_CHAR)
		printf("There is some invalid character on scene\n");
	else if (error_code == ERR_DUPLICATE)
		printf("There is some unique rule duplicated\n");
	else if (error_code == ERR_MISSING)
		printf("There is some mandatory rule missing\n");
	else
		printf("Unexpected Error\n");
}
