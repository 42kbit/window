#ifndef _H_WINDOW_H
#define _H_WINDOW_H

struct window;
typedef struct window window_t;
typedef unsigned int win_flags_t;

struct window* create_window(char* name, int w, int h, win_flags_t flags);
void free_window(struct window*);

char* window_name(struct window*);
char* set_window_name(struct window*);
win_flags_t window_flags(struct window*);

#endif /* _H_WINDOW_H */
