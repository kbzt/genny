# genny

minimal password generator for the command line that writes to stdout

## usage & examples

~~~
usage: genny [args] [value]

  -h    show this help and exit.
  -n    disable numbers (0-9)
  -a    disable alphas (A-Z, a-z)
  -s    disable special characters (!#$%&*@^)
  -l    specify a length (default: 14)

examples:
  genny -al 22
  genny -l 30 -a -s
~~~

as of now genny is only supported on gnu/linux.

## build & run

~~~sh
git clone https://github.com/kbzt/genny.git
cd genny
make
./genny
~~~

- glibc [>=2.35-5]
- clang [>=13.0.1] OR gcc [>=12.1.0]

note: versions are just kept for tracking, will likely work with versions packaged by most linux distributions :)

## install & remove

to install genny to your system after building:
~~~sh
sudo make install
~~~

to remove genny from your system after installing:
~~~sh
sudo make uninstall
~~~
