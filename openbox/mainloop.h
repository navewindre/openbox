#ifndef __ob__mainloop_h
#define __ob__mainloop_h

#include <X11/Xlib.h>
#include <glib.h>

typedef struct _ObMainLoop ObMainLoop;

ObMainLoop *ob_main_loop_new(Display *display);
void        ob_main_loop_destroy(ObMainLoop *loop);

typedef void (*ObMainLoopXHandler) (const XEvent *e, gpointer data);

void ob_main_loop_x_add(ObMainLoop *loop,
                        ObMainLoopXHandler handler,
                        gpointer data,
                        GDestroyNotify notify);
void ob_main_loop_x_remove(ObMainLoop *loop,
                           ObMainLoopXHandler handler);

typedef void (*ObMainLoopFdHandler) (gint fd, gpointer data);

void ob_main_loop_fd_add(ObMainLoop *loop,
                         gint fd,
                         ObMainLoopFdHandler handler,
                         gpointer data,
                         GDestroyNotify notify);
void ob_main_loop_fd_remove(ObMainLoop *loop,
                            gint fd);

typedef void (*ObMainLoopSignalHandler) (gint signal, gpointer data);

void ob_main_loop_signal_add(ObMainLoop *loop,
                             gint signal,
                             ObMainLoopSignalHandler handler,
                             gpointer data,
                             GDestroyNotify notify);
void ob_main_loop_signal_remove(ObMainLoop *loop,
                                ObMainLoopSignalHandler handler);

void ob_main_loop_timeout_add(ObMainLoop *loop,
                              gulong microseconds,
                              GSourceFunc handler,
                              gpointer data,
                              GDestroyNotify notify);
void ob_main_loop_timeout_remove(ObMainLoop *loop,
                                 GSourceFunc handler);

void ob_main_loop_run(ObMainLoop *loop);
void ob_main_loop_exit(ObMainLoop *loop);

#endif