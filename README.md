
![Logo] (share/logout/logout.png)
# Logout-fml #
Logout-fml is a simple utility to perform scheduled tasks. It runs on Gnu/Linux and Windows

[**Download**](http://www.freemedialab.org/listing/logout-fml/)

## Screenshots ##
![Main window](http://www.freemedialab.org/wiki/lib/exe/fetch.php?w=280&tok=0bf4ad&media=progetti:logout:logout0-linux.png)
![Server/client](http://www.freemedialab.org/wiki/lib/exe/fetch.php?cache=&w=794&h=667&tok=162eb9&media=progetti:logout:clients0.jpg)

## How Install ##
How to  compile and install:

	cd logout
	qmake 		(or qmake-qt4, or qmake-qt5 )
	make
	make install

to uninstall:

`make uninstall`
  
## Notes ##
  
  -Customize the commands:
If you want customize the commands you can edit ~/.config/logout/settings.ini

-Windows users:
Windows users can find the executable in the folder win32/bin/logout.exe

-Shutdown and reboot on Unix with sudo without password:
You can add add your user to adm group and then add these lines to your /etc/sudoers :

	%adm	ALL= NOPASSWD: /sbin/halt
	%adm	ALL= NOPASSWD: /sbin/reboot

-Server mode:
The server accepts tcp packets in the following format:
		password:command:message
You can also send packets with netcat using the following format:
		echo "secret:reboot:Reboot the computer..."| nc 192.168.1.2 1234
