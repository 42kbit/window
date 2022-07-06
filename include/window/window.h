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

void wait_events(window_t*);
void poll_events(window_t*);

typedef void(*gen_cb)(struct window*);
/* assumed 32-bit unsigned int */

void set_unicode_cb(struct window*, gen_cb);
void set_keyboard_key_cb(struct window*, gen_cb);
void set_mouse_pos_cb(struct window*, gen_cb);
void set_mouse_enter_cb(struct window*, gen_cb);
void set_mouse_button_cb(struct window*, gen_cb);

int key_keycode(struct window*);
int key_action(struct window*);
int key_flags(struct window*);
const char* key_to_str(struct window*);

void mouse_pos(struct window*, double*);
int mouse_entered(struct window*);
int mouse_button(struct window*);
int mouse_action(struct window*);
int mouse_flags(struct window*);

#endif /* _H_WINDOW_H */
