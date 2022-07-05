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

typedef void(*uni_cb)(struct window*, int unichar);
/* assumed 32-bit unsigned int */
void set_unicode_cb(struct window*, uni_cb cb);

struct key;

typedef void(*key_cb)(window_t*, struct key*);
void set_key_cb(window_t*, key_cb);

int key_keycode(struct key*);
int key_action(struct key*);
int key_flags(struct key*);

const char* key_to_str(struct key*);

struct mouse;

typedef void(*mse_cb)(struct window*, struct mouse*);

void set_mouse_cb_pos(struct window*, mse_cb);
void set_mouse_cb_enter(struct window*, mse_cb);
void set_mouse_cb_button(struct window*, mse_cb);

void mouse_pos(struct mouse* mouse, double*);
int mouse_entered(struct mouse* mouse);
int mouse_button(struct mouse* mouse);
int mouse_action(struct mouse* mouse);
int mouse_flags(struct mouse* mouse);

#endif /* _H_WINDOW_H */
