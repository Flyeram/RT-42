#ifndef KEYCODE_H
# define KEYCODE_H

# ifdef __linux__

# define KEY_EXIT 65307
# define KEY_ALIASING 49

# define ROTATE_LEFT 97
# define ROTATE_RIGHT 100
# define ROTATE_UP 119
# define ROTATE_DOWN 115
# define ROTATE_FORWARD 116
# define ROTATE_BACK 103

# define MOVE_LEFT 65361
# define MOVE_RIGHT 65363
# define MOVE_UP 65362
# define MOVE_DOWN 65364
# define MOVE_FORWARD 65365
# define MOVE_BACK 65366

# else
# define KEY_EXIT 53
# define KEY_ALIASING 12

# define ROTATE_LEFT 123
# define ROTATE_RIGHT 124
# define ROTATE_UP 125
# define ROTATE_DOWN 126
# define ROTATE_FORWARD 115
# define ROTATE_BACK 119

# define MOVE_LEFT 24
# define MOVE_RIGHT 27
# define MOVE_UP 121
# define MOVE_DOWN 116
# define MOVE_FORWARD 69
# define MOVE_BACK 78

# endif

#endif
