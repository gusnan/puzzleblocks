

Program.cpp:

You cannot delete the mouse bitmap before calling Mouse::doneMouse(), that
will give you a hard-debugged SIGABRT and

"corrupted double-linked list"

in my case With debug information pointing into the Nvidia drivers.
