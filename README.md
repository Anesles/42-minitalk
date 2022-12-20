# **minitalk (Cursus from 42 Porto)**
## **Grade: 115/100**
---
### **Summary:**

In this project I had to develop a server and a client that speaks to the server using UNIX signals. 

#### **Installing and running the project:**
* Clone this repository.
```
git clone git@github.com:Anesles/42-minitalk.git
```
* Run `make`.
```
make
```
* Run the server.
```
./server
```
* Run the client using the PID the server printed out and a string as arguments
```
./client PID "string"
```
---
### **Makefile targets**
* `make` or `make all` - Compiles the program.
* `make clean` - Cleans all object files.
* `make fclean` - Cleans all object files, _client_ and _server_.
* `make re` - Cleans everything (fclean) and recompiles.
## Disclaimer
> At [42School](https://en.wikipedia.org/wiki/42_(school)), almost every project must be written in accordance to the [Norm](./extras/en_norm.pdf), the schools' coding standard. As a result, the implementation of certain parts may appear strange and for sure had room for improvement.# 42-minitalk
