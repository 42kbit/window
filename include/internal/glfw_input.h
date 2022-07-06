#ifndef _H_GLFW_INPUT_H
#define _H_GLFW_INPUT_H

#include <stdlib.h>
#include <string.h>

struct input{
	int keyboard_keycode;
	int keyboard_action;
	int keyboard_flags;

	double mouse_pos[2];
	int mouse_entered;
	int mouse_button;
	int mouse_action;
	int mouse_flags;

	int unicode_char;
};

static inline struct input* create_input(){
	struct input* mem = (struct input*)malloc(sizeof(struct input));
	if (!mem)
		return NULL;
	memset(mem, 0, sizeof(struct input));
	return mem;
}

static inline void free_input(struct input* i){
	free(i);
}

#endif /* _H_GLFW_INPUT_H */
