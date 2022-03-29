# genny

minimal password generator for the command line that writes to stdout

## usage & examples

as of now genny is only supported on gnu/linux.

## build & run

~~~
git clone https://github.com/kbzt/genny.git
cd genny
make genny
./genny
~~~

note: make sure your os has an up to date version of glibc, or more specifically the bsd library.

## install & remove

to install genny to your system after building:
~~~
sudo make install
~~~

to remove genny from your system after installing:
~~~
sudo make uninstall
~~~
