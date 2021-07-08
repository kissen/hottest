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
