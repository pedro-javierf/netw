<p align="center">
  <img src="https://s3.postimg.org/ojpw5x7c3/netw.png">
  <br><br>
  <b>High level cross-platform network wrapper</b><br>
</p>
##License
netw is published under the [GNU GPL 3.0 License](https://github.com/pedro-javierf/netw/blob/master/LICENSE) 

##About
netw is a modern and lightweight C wrapper which provides developers with cross-platform networking code; this means, you can have portable networking capabilities without having to learn specific system socket APIs.

##Features
- [x] Winsock2 TCP 
- [ ] Winsock2 UDP 
- [x] Linux TCP
- [ ] Linux UDP 
- [x] Linux cross-compilers support (supports any system that relies on Linux syntax/cross-libs)

##Usage
on your C/C++ program, include the following header:<br>
`#include netw.h`<br>
now you can call all the netw functions.

##Todo
netw is my own open source wrapper and is still in an early state of development. It is intended to bring cross-platform support in a really easy way, therefore; It hasn't been tested within huge projects and performance hasn't been tested neither. Things planned for the future:<br>
-Improve linux development <br>
-Support raw sockets (Linux mainly)<br>
-Improve stability and performance<br>

##Notes
-netw will automatically detect your compiler/OS at build time<br>
-if builds are done in windows platforms, you must call `initWinsock()` before using netw to initialize the WinSock32, it returns 0 if successful. You must also call ´stopWinsock()´ at the end of your program or when you won't use netw anymore in your code.
