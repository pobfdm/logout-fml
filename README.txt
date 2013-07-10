
/* LOGOUT by Fabio Di Matteo - fadimatteo@gmail.com - www.freemedialab.org
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */

How to  compile and install:

	cd logout
	qmake 		(or qmake-qt4, or qmake-qt5 )
	make
	make install

to uninstall:

	make uninstall


Notes:

Customize the commands:
If you want customize the commands you can edit ~/.config/logout/settings.ini

Windows users:
Windows users can find the executable in the folder win32/bin/logout.exe

Shutdown and reboot on Unix with sudo widtout password:
You can add add your user to adm group and then add these lines to your /etc/sudoers :
	%adm	ALL= NOPASSWD: /sbin/halt
	%adm	ALL= NOPASSWD: /sbin/reboot

