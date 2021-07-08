hottest
=======

"hottest" is a C program that uses the libsensors(3) library to
display the highest temperature it can find.

I use it in combination with i3blocks(1) to get an idea of how my
computer is doing without overwhelming me with details.

Installation
------------

You will need the libsensors(3) library. I find that on Debian 9 I can
install it with

    # apt install libsensors4-dev

With that installed, run

     $ make

in the project directory. You should now have a "hottest" binary.

Credit
------

A big chunk of code is based on a snippet posted on Stack Overflow [1]
by user Mat [2] licensed under CC BY-SA 3.0. As that is a viral license,
this project is also licensed under the terms of CC BY-SA 3.0.

[1] https://stackoverflow.com/a/8565176
[2] https://stackoverflow.com/users/635608/mat
[3] https://creativecommons.org/licenses/by-sa/3.0/
