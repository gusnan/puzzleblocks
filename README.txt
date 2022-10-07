


BUILDING
========

This requires the libraries

Gusgame (https://github.com/gusnan/gusgame)

GusGui (https://github.com/gusnan/gusgui)

Allegro5 (https://github.com/liballeg/allegro5)


Program.cpp:

You cannot delete the mouse bitmap before calling Mouse::doneMouse(), that
will give you a hard-debugged SIGABRT and

"corrupted double-linked list"

in my case With debug information pointing into the Nvidia drivers.


CPPCHECK
========

For cppcheck, use the command

cppcheck --enable=all --suppressions-list=../cppcheck-suppressions.txt --check-config -I/usr/include/lua5.3 -I/home/gusnan/kod/puzzle/puzzle/src -I/usr/local/include -I/usr/include/ -I/usr/include/c++/10/ -I/usr/include/x86_64-linux-gnu/c++/10/ ../src

(not mentioned in the cppcheck-suppressions.txt file, since it cannot be done
with comments and ruins the syntax, and makes the suppresions file not usable).

