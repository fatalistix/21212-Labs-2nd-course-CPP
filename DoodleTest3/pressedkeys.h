#pragma once

#include "SingletonHolder.h"

#ifdef linux

#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>

class Server
{
public:
    bool LeftPressed();
    bool RightPressed();
private:
    Server();
    ~Server();

    Server(const Server &)=delete;
    Server & operator=(const Server &)=delete;

    friend SingletonHolder <Server>;

    Display * display_X;
    char keys_return_X[32];
    const KeyCode KEY_LEFT_KC_X;
    const KeyCode KEY_RIGHT_KC_X;

    bool key_is_pressed(KeyCode kc, Display * dpy, char * pressed);
};

#endif

typedef SingletonHolder <Server> KeysServer;


