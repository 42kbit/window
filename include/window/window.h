#ifndef _H_WINDOW_H
#define _H_WINDOW_H

struct monitor;
typedef struct monitor monitor_t;

struct window;
typedef struct window window_t;

int init_window_lib(void);
void free_window_lib(void);

monitor_t* create_monitor(void);
void free_monitor(monitor_t*);
window_t* create_window(
		char* name,
		int w, 
		int h, 
		monitor_t* monitor
		);
void make_cur_context(window_t* win);
void free_window(struct window*);

int is_open(window_t* win);

char* get_window_title(struct window*);
void set_window_title(struct window*, char* new_name);

void poll_events(window_t*);
void swap_buffers(window_t* win);

int vsync_get();
void vsync_set(int);

/* inputs here */

void poll_events(window_t*);

typedef void(*gen_cb)(window_t*);
void set_key_cb(window_t*, gen_cb);
void set_mouse_cb(window_t*, gen_cb);

struct key;
int key_keycode(struct key*);
int key_scancode(struct key*);
int key_press_type(struct key*);
int key_flags(struct key*);

#endif /* _H_WINDOW_H */
