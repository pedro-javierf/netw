<p align="center">
  <img src="https://s3.postimg.org/ojpw5x7c3/netw.png">
  <br><br>
  <b>High level cross-platform network wrapper</b><br>
</p>
##License
netw is published under the [GNU GPL 3.0 License](https://github.com/pedro-javierf/netw/blob/master/LICENSE) 

##About
netw is modern C and C++ lib, that provides the developer with cross-platform networking code; this means, you can have portable networking capabilities without having to learn specific system APIs.

##Features
- [x] Winsock2 TCP 
- [ ] Winsock2 UDP 
- [x] Linux TCP
- [ ] Linux UDP 
- [ ] Linux cross-compilers support

##Usage
on your C/C++ program, include the following header:<br>
`#include netw.h`<br>
now you can call all the netw functions.

##Todo
netw is an open source wrapper and is still in an early state of development. At the moment, it hasn't been tested within huge projects and performance hasn't been tested neither. Things planned for the future:<br>
-Improve linux development speed<br>
-Support raw sockets<br>
-Wrapping other socket calls (send, recv, etc...)<br>
-Improve stability and performance<br>

##Notes
-netw will automatically detect your compiler/OS at build time<br>
-if build are done in windows platforms, you must call `initWinsock()` before using netw, returns 0 if successful. You must also call ´stopWinsock()´ at the end of your program or when you won't use netw anymore in your code.