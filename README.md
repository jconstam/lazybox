# Lazybox
Lazybox is [Busybox](busybox.com)'s less-portable, less-functional cousin.

Really, this is just a pet project to play around with system programming in C/C++ in Linux.

## Testing
In order to test Lazybox, there are 3 components:

1) CTest - Executes the Lazybox binary and the various symlinks to verify that the commands are executed as expected.

2) Unity - Unit testing for code written in C.

3) Google Test - Unit testing for code written in C++.

## Code Generation
There are several files which are automatically generated as a part of the build process.
TO BE COMPLETED

# Modules
|Command|Description|Difficulty|Status|
|-------|-----------|----------|------|
|[| | | |
|[[| | | |
|acpid|Listen to ACPI events and spawn specific helpers on event arrival|Medium|Not Started|
|addgroup|Add a group or add a user to a group|Easy|Not Started|
|adduser|Add a user|Easy|Not Started|
|adjtimex|Read and optionally set system timebase parameters.|Easy|Not Started|
|ar|Extract or list files from an ar archive.|Easy|Not Started|
|arp|Manipulate ARP cache|Medium|Not Started|
|arping|Send ARP requests/replies|Easy|Not Started|
|ash| | | |
|awk| | | |
|basename|Strip directory path and .suffix from file name.|Easy|Not Started|
|beep|Sound the system beep.|Easy|Not Started|
|blkid|Print UUIDs of all filesystems|Easy|Not Started|
|brctl|Manage Ethernet bridges|Medium|Not Started|
|bunzip2|Uncompress file (or standard input)|Easy|Not Started|
|bzcat|Uncompress to stdout|Easy|Not Started|
|bzip2|Compress file(s) (or standard input) with bzip2 algorithm.|Easy|Not Started|
|cal|Display a calendar|Easy|Not Started|
|cat|Concatenate file(s) and print them to standard out.|Easy|Not Started|
|catv|Concatenate file(s) and print them to standard out.  Display nonprinting characters.|Easy|Not Started|
|chat|Useful for interacting with a modem connected to stdin/stdout. A script consists of one or more "expect-send" pairs of strings, each pair is a pair of arguments.|Hard|Not Started|
|chattr|Change file attributes on an ext2 fs|Medium|Not Started|
|chgrp|Change the group membership of one or more files to a specified group.|Easy|Not Started|
|chmod|Change the mode of one or more files.|Easy|Not Started|
|chown|Change the owner and/or group of one or more file.|Easy|Not Started|
|chpasswd|Change a user's password in /etc/passwd.|Easy|Not Started|
|chpst|Change the process state and run a program.|Medium|Not Started|
|chroot|Run a program with specified root directory.|Easy|Not started|
|chrt|Manipulate real-time attributes of a process.|Easy|Not Started|
|chvt|Change the foreground virtual terminal to /dev/ttyN.|Medium|Not Started|
|cksum|Calculate the CRC32 checksums of one or more files.|Easy|Not Started|
|clear|Clear screen|Easy|Not Started|
|cmp|Compare a file with another file or standard input.|Easy|Not Started|
|comm|Compare a file with another file or standard input.|Easy|Not Started|
|cp|Copies one or more files|Easy|Not Started|
|cpio|Extract or list files from a cpio archive or create a cpio archive.|Easy|Not Started|
|crond| | | |
|crontab| | | |
|cryptpw|Crypt a password.|Easy|Not Started|
|cut|Prints selected fields from each input file to standard output.|Easy|Not Started|
|date|Display time or set time|Easy|In Progress|
|dc|Tiny RPN calculator.|Easy|Not Started|
|dd|Copy a file with converting and formatting.|Medium|Not Started|
|deallocvt|Decallocate unused virtual terminal /dev/ttyN.|Medium|Not Started|
|delgroup|Delete a group or remove a user from a group.|Easy|Not Started|
|deluser|Delete a user from the system.|Easy|Not Started|
|depmod| | | |
|devmem|Read/write from physical address|Medium|Not Started|
|df|Print filesystem usage statistics|Easy|Not Started|
|dhcprelay|Relay DHCP requests between clients and server.|Medium|Not Started|
|diff|Compare files line by line and output the differences between them.|Medium|NotStarted|
|dirname|Strip non-directory suffix from filename.|Easy|Not Started|
|dmesg|Print or control the kernel ring buffer.|Easy|Not Started|
|dnsd|Small static DNS server daemon|Hard|Not Started|
|dnsdomainname| | | |
|dos2unix|Convert file in-place from DOS to Unix format. Can also use standard in/out.|Easy|Not Started|
|dpkg|Install, remove, and manage Debian packages.|Hard|Not Started|
|du|Summarize disk space used for each file and/or directory.|Medium|Not Started|
|dumpkmap|Print a binary keyboard translation table to standard output.|Easy|Not Started|
|dumpleases|Display DHCP leases granted by udhcpd.|Medium|Not Started|
|echo|Print a string|Easy|In Progress|
|ed| | | |
|egrep| | | |
|eject|Eject specified device.|Medium|Not Started|
|env|Print the current environment or run program after setting up the specified environment.|Easy|Not Started|
|envdir|Set various environment variables as specified by files in the specified directory and run program.|Easy|Not Started|
|envuidgid|Set $UID to account's uid and $GID to account's gid and run program.|Easy|Not Started|
|expand|Convert tabs to spaces, write to standard output.|Easy|Not Started|
|expr|Print the value of the specified expression to standard output.|Medium|Not Started|
|fakeidentd|Provide fake ident (auth) service.|Medium|Not Started|
|false|Return an exit code of false (1).|Easy|Not Started|
|fbset|Show and modify frame buffer settings.|Easy|Not Started|
|fbsplash| | | |
|fdflush|Force floppy disk drive to detect disk change.|Medium|Not Started|
|fdformat|Format floppy disk.|Medium|Not Started|
|fdisk|Change partition table.|Hard|Not Started|
|fgrep| | | |
|find|Search for files.|Medium|Not Started|
|findfs|Find a filesystem device based on a label or UUID.|Easy|Not Started|
|flash_lock|Lock part or all of an MTD device.|Medium|Not Started|
|flash_unlock|Unlock an MTD device.|Medium|Not Started|
|fold|Wrap input lines in each file (or standard input), write to standard output.|Easy|Not Started|
|free|Display the amount of free and used system memory.|Easy|Not Started|
|freeramdisk|Free all memory used by the specified ramdisk.|Easy|Not Started|
|fsck|Check and repair filesystems.|Hard|Not Started|
|fsck.minix|Check MINIX filesystem.|Medium|Not Started|
|fsync|Write files' buffered blocks to disk.|Easy|Not Started|
|ftpd|Anonymus FTP server.|Hard|Not Started|
|ftpget|Retrieve a remote file via FTP.|Easy|Not Started|
|ftpput|Store a local file on a remote machine via FTP.|Easy|Not Started|
|fuser|Find processes which use the specified files or ports.|Medium|Not Started|
|getopt| | | |
|getty|Open a tty, prompt for a login name, then invoke /bin/login.|Medium|Not Started|
|grep|Search for a pattern in each file or standard input.|Medium|Not Started|
|gunzip|Uncompress files or standard input.|Easy|Not Started|
|gzip|Compress files or standard input.|Easy|Not Started|
|hd|An alias for "hexdump -C".|Easy|Not Started|
|hdparm| | | |
|head|Print first N lines of each file (or standard input) to standard output.  If more than one file, precede each with a header giving the file name.|Easy|Not Started|
|hexdump|Dispay file(s) or standard input in a user-specified format.|Easy|Not Started|
|hostid|Print out a unique 32-bit identifier for the machine.|Easy|Not Started|
|hostname|Get or set hostname or DNS domain name.|Easy|Not Started|
|httpd|Listen for incoming HTTP requests.|Hard|Not Started|
|hush| | | |
|hwclock|Query or set hardware clock (RTC).|Medium|Not Started|
|id|Print information about a user.|Easy|Not Started|
|ifconfig|Configure a network interface.|Medium|Not Started.|
|ifdown| | | |
|ifenslave|Configure network interfaces for parallel routing.|Medium|Not Started|
|ifplugd|Network interface plug detection daemon.|Hard|Not Started|
|ifup| | | |
|inetd|Listen for network connections and launch programs.|Hard|Not Started|
|init|The parent of all processes.|Hard|Not Started|
|inotifyd|Run a program on filesystem changes.|Medium|Not Started|
|insmod|Load the specified kernel modules into the kernel.|Medium|Not Started|
|install|Copy files and set attributes.|Easy|Not Started|
|ionice|Change I/O scheduling class and priority|Medium|Not Started|
|ip| | | |
|ipaddr| | | |
|ipcalc|Calculate IP network settings from an IP address.|Easy|Not Started|
|ipcrm|Add or remove an object by shmid value.|Medium|Not Started|
|ipcs| | | |
|iplink| | | |
|iproute| | | |
|iprule| | | |
|iptunnel| | | |
|kbd_mode|Report or set the keyboard mode.|Medium|Not Started|
|kill|Send a signal to given PIDs.|Easy|Not Started|
|killall|Send a signal to given processes.|Easy|Not Started|
|killall5|Send a signal to all processes outside the current session.|Easy|Not Started|
|klogd|Kernel logger.|Easy|Not Started|
|last|Show listing of the last users that logged into the system.|Easy|Not Started|
|length|Print a string's length.|Easy|Not Started|
|less|View a file or list of files. Allows for manipulating the files in various ways.|Medium|Not Started|
|linux32| | | |
|linux64| | | |
|linuxrc| | | |
|ln|Create a link to the specified target.|Easy|Not Started|
|loadfont|Load a console font from standard input.|Medium|Not Started|
|loadkmap|Load a binary keyboard translation table from standard input.|Medium|Not Started|
|logger|Write a message to the system log.  Can also log from standard input.|Easy|Not Started|
|login|Begin a new session on the system.|Medium|Not Started|
|logname|Print the name of the current user.|Easy|Not Started|
|logread|Show messages in syslogd's circular buffer.|Easy|Not Started|
|losetup|Associate loop devices.|Medium|Not Started|
|lpd|Print file.|Medium|Not Started|
|lpq| | | |
|lpr| | | |
|ls|List directory contents.|Easy|Not Started|
|lsattr|List file attributes on an ext2 fs.|Medium|Not Started|
|lsmod|List the currently loaded kernel modules.|Easy|Not Started|
|lzmacat|Uncompress to standard out.|Easy|Not Started|
|lzop| | | |
|lzopcat| | | |
|makemime|Create multipart MIME-encoded message from files.|Medium|Not Started|
|man| | | |
|md5sum| | | |
|mdev| | | |
|mesg| | | |
|microcom| | | |
|mkdir| | | |
|mkdosfs| | | |
|mkfifo| | | |
|mkfs.minix| | | |
|mkfs.vfat| | | |
|mknod| | | |
|mkpasswd| | | |
|mkswap| | | |
|mktemp| | | |
|modprobe| | | |
|more| | | |
|mount| | | |
|mountpoint| | | |
|mt| | | |
|mv| | | |
|nameif| | | |
|nc| | | |
|netstat| | | |
|nice| | | |
|nmeter| | | |
|nohup| | | |
|nslookup| | | |
|od| | | |
|openvt| | | |
|passwd| | | |
|patch| | | |
|pgrep| | | |
|pidof| | | |
|ping| | | |
|ping6| | | |
|pipe_progress| | | |
|pivot_root| | | |
|pkill| | | |
|popmaildir| | | |
|printenv| | | |
|printf| | | |
|ps| | | |
|pscan| | | |
|pwd| | | |
|raidautorun| | | |
|rdate| | | |
|rdev| | | |
|readlink| | | |
|readprofile| | | |
|realpath| | | |
|reformime| | | |
|renice| | | |
|reset| | | |
|resize| | | |
|rm| | | |
|rmdir| | | |
|rmmod| | | |
|route| | | |
|rpm| | | |
|rpm2cpio| | | |
|rtcwake| | | |
|run-parts| | | |
|runlevel| | | |
|runsv| | | |
|runsvdir| | | |
|rx| | | |
|script| | | |
|scriptreplay| | | |
|sed| | | |
|sendmail| | | |
|seq| | | |
|setarch| | | |
|setconsole| | | |
|setfont| | | |
|setkeycodes| | | |
|setlogcons| | | |
|setsid| | | |
|setuidgid| | | |
|sh| | | |
|sha1sum| | | |
|sha256sum| | | |
|sha512sum| | | |
|showkey| | | |
|slattach| | | |
|sleep| | | |
|softlimit| | | |
|sort| | | |
|split| | | |
|start-stop-daemon| | | |
|stat| | | |
|strings| | | |
|stty| | | |
|su| | | |
|sulogin| | | |
|sum| | | |
|sv| | | |
|svlogd| | | |
|swapoff| | | |
|swapon| | | |
|switch_root| | | |
|sync| | | |
|sysctl| | | |
|syslogd| | | |
|tac| | | |
|tail| | | |
|tar| | | |
|taskset| | | |
|tcpsvd| | | |
|tee| | | |
|telnet| | | |
|telnetd| | | |
|test| | | |
|tftp| | | |
|tftpd| | | |
|time| | | |
|timeout| | | |
|top| | | |
|touch| | | |
|tr| | | |
|traceroute| | | |
|true| | | |
|tty| | | |
|ttysize| | | |
|udhcpc| | | |
|udhcpd| | | |
|udpsvd| | | |
|umount| | | |
|uname| | | |
|uncompress| | | |
|unexpand| | | |
|uniq| | | |
|unix2dos| | | |
|unlzma| | | |
|unlzop| | | |
|unzip| | | |
|uptime| | | |
|usleep| | | |
|uudecode| | | |
|uuencode| | | |
|vconfig| | | |
|vi| | | |
|vlock| | | |
|volname| | | |
|watch| | | |
|watchdog| | | |
|wc| | | |
|wget| | | |
|which| | | |
|who| | | |
|whoami| | | |
|xargs| | | |
|yes| | | |
|zcat| | | |
|zcip| | | |
