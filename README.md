# httpecho

## Code structure

There are 2 server and 1 client application code. These codes are for Linux with [GNU gcc compiler](https://help.ubuntu.com/community/InstallingCompilers).

server.c - This is created to interact with any browser like (Chrome, Firefox etc).

server1.c - This works with client application created by client.c .

client.c - This works as a client application after compilation.


## Compilation

These codes are for Linux platform.

To compile the code type following commands in terminal.

$ cc -o server server.c

$ cc -o server1 server1.c

$ cc -o client client.c


## Uses guide or Tests

After compilation there two executable files - server and server1


#### To test the first executable (server) - server works well with web-browser

Open terminal and run first executable.

$ ./server 2500 

Now if you want to test it from same computer then open web-browser chrome or firefox and type following kyewords in url bar.

[http://localhost:2500/?string=ujjwal mishra](http://localhost:2500/?string=ujjwal mishra)


then you will get response - arhsim lawjju

you can try another.

[http://localhost:2500/?string=hello world!](http://localhost:2500/?string=hello world!)

you can put any string after "http://localhost:2500/?string=" like http GET request You will get reverse of the string.

now if you want to test it on another device which have any browser and connected with same network then follow below instructions.

run command $ ifconfig

you will get assigned Ip of your system. put this ip in the place of localhost. Example Given below.

Ex - your system ip is 192.168.43.9. Then open your browser on device and put follwing query like given below

[http://192.168.43.9:2500/?string=ujjwal mishra](http://192.168.43.9:2500/?string=ujjwal mishra)

(Note : This will work if device on which browser is running and computer are in same network)

#### To test second executable (server1) - server1 works well with client

Open terminal and run second executable.

$ ./server1 2500

Open another terminal and run client executable.

$ ./client localhost 2500
 
client will ask you to put any string and server1 will receive ,reverse and send you.

you can run the client on any device having same network.

#### Notes
You can use any port no.

You can use 127.0.0.1 at place of localhost.
