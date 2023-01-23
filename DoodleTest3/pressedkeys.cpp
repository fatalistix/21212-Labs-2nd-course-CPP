#include "pressedkeys.h"

#ifdef linux

Server::Server()
    : display_X(XOpenDisplay(":0"))
    , KEY_LEFT_KC_X(XKeysymToKeycode(display_X, XK_Left))
    , KEY_RIGHT_KC_X(XKeysymToKeycode(display_X, XK_Right))
{}

Server::~Server()
{
    XCloseDisplay(display_X);
}

bool Server::key_is_pressed(KeyCode kc, Display * dpy, char * pressed)
{
    XQueryKeymap(dpy, pressed);
    return !!(pressed[kc >> 3] & (1 << (kc & 7)));
}

bool Server::LeftPressed()
{
    return key_is_pressed(KEY_LEFT_KC_X, display_X, keys_return_X);
}

bool Server::RightPressed()
{
    return key_is_pressed(KEY_RIGHT_KC_X, display_X, keys_return_X);
}


#endif
