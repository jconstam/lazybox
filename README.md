R Lazybox
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
|chat| | | |
|chattr| | | |
|chgrp| | | |
|chmod| | | |
|chown| | | |
|chpasswd| | | |
|chpst| | | |
|chroot| | | |
|chrt| | | |
|chvt| | | |
|cksum| | | |
|clear| | | |
|cmp| | | |
|comm| | | |
|cp| | | |
|cpio| | | |
|crond| | | |
|crontab| | | |
|cryptpw| | | |
|cut| | | |
|date| | | |
|dc| | | |
|dd| | | |
|deallocvt| | | |
|delgroup| | | |
|deluser| | | |
|depmod| | | |
|devmem| | | |
|df| | | |
|dhcprelay| | | |
|diff| | | |
|dirname| | | |
|dmesg| | | |
|dnsd| | | |
|dnsdomainname| | | |
|dos2unix| | | |
|dpkg| | | |
|du| | | |
|dumpkmap| | | |
|dumpleases| | | |
|echo|Print a string|Easy|In-Progress|
|ed| | | |
|egrep| | | |
|eject| | | |
|env| | | |
|envdir| | | |
|envuidgid| | | |
|expand| | | |
|expr| | | |
|fakeidentd| | | |
|false| | | |
|fbset| | | |
|fbsplash| | | |
|fdflush| | | |
|fdformat| | | |
|fdisk| | | |
|fgrep| | | |
|find| | | |
|findfs| | | |
|flash_lock| | | |
|flash_unlock| | | |
|fold| | | |
|free| | | |
|freeramdisk| | | |
|fsck| | | |
|fsck.minix| | | |
|fsync| | | |
|ftpd| | | |
|ftpget| | | |
|ftpput| | | |
|fuser| | | |
|getopt| | | |
|getty| | | |
|grep| | | |
|gunzip| | | |
|gzip| | | |
|hd| | | |
|hdparm| | | |
|head| | | |
|hexdump| | | |
|hostid| | | |
|hostname| | | |
|httpd| | | |
|hush| | | |
|hwclock| | | |
|id| | | |
|ifconfig| | | |
|ifdown| | | |
|ifenslave| | | |
|ifplugd| | | |
|ifup| | | |
|inetd| | | |
|init| | | |
|inotifyd| | | |
|insmod| | | |
|install| | | |
|ionice| | | |
|ip| | | |
|ipaddr| | | |
|ipcalc| | | |
|ipcrm| | | |
|ipcs| | | |
|iplink| | | |
|iproute| | | |
|iprule| | | |
|iptunnel| | | |
|kbd_mode| | | |
|kill| | | |
|killall| | | |
|killall5| | | |
|klogd| | | |
|last| | | |
|length| | | |
|less| | | |
|linux32| | | |
|linux64| | | |
|linuxrc| | | |
|ln| | | |
|loadfont| | | |
|loadkmap| | | |
|logger| | | |
|login| | | |
|logname| | | |
|logread| | | |
|losetup| | | |
|lpd| | | |
|lpq| | | |
|lpr| | | |
|ls| | | |
|lsattr| | | |
|lsmod| | | |
|lzmacat| | | |
|lzop| | | |
|lzopcat| | | |
|makemime| | | |
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
