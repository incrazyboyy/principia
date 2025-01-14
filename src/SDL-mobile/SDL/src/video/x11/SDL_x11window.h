/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2012 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/
#include "SDL_config.h"

#ifndef _SDL_x11window_h
#define _SDL_x11window_h

typedef struct
{
    SDL_Window *window;
    Window xwindow;
    Visual *visual;
    Colormap colormap;
#ifndef NO_SHARED_MEMORY
    /* MIT shared memory extension information */
    SDL_bool use_mitshm;
    XShmSegmentInfo shminfo;
#endif
    XImage *ximage;
    GC gc;
    XIC ic;
    SDL_bool created;
    struct SDL_VideoData *videodata;
} SDL_WindowData;

extern int X11_CreateWindow(_THIS, SDL_Window * window);
extern int X11_CreateWindowFrom(_THIS, SDL_Window * window, const void *data);
extern char *X11_GetWindowTitle(_THIS, Window xwindow);
extern void X11_SetWindowTitle(_THIS, SDL_Window * window);
extern void X11_SetWindowIcon(_THIS, SDL_Window * window, SDL_Surface * icon);
extern void X11_SetWindowPosition(_THIS, SDL_Window * window);
extern void X11_SetWindowSize(_THIS, SDL_Window * window);
extern void X11_ShowWindow(_THIS, SDL_Window * window);
extern void X11_HideWindow(_THIS, SDL_Window * window);
extern void X11_RaiseWindow(_THIS, SDL_Window * window);
extern void X11_MaximizeWindow(_THIS, SDL_Window * window);
extern void X11_MinimizeWindow(_THIS, SDL_Window * window);
extern void X11_RestoreWindow(_THIS, SDL_Window * window);
extern void X11_SetWindowBordered(_THIS, SDL_Window * window, SDL_bool bordered);
extern void X11_SetWindowFullscreen(_THIS, SDL_Window * window, SDL_VideoDisplay * display, SDL_bool fullscreen);
extern int X11_SetWindowGammaRamp(_THIS, SDL_Window * window, const Uint16 * ramp);
extern void X11_SetWindowGrab(_THIS, SDL_Window * window);
extern void X11_DestroyWindow(_THIS, SDL_Window * window);
extern SDL_bool X11_GetWindowWMInfo(_THIS, SDL_Window * window,
                                    struct SDL_SysWMinfo *info);

#endif /* _SDL_x11window_h */

/* vi: set ts=4 sw=4 expandtab: */
