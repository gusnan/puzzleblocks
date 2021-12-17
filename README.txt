

Program.cpp:

You cannot delete the mouse bitmap before calling Mouse::doneMouse(), that
will give you a hard-debugged SIGABRT 

"corrupted double-linked list"

With debug information pointing into the Nvidia drivers.
