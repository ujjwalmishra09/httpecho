# This is a feature file describing what this replay http server must do.
# You need to implement this replay server in C++ using sockets without
# using any http library for it. For your test you should be able to send
# data to server and server will send back a response with the data string
# reversed. This feature file should be running green once everything is
# in place. Once done, please send a pull request to this repository. Add
# a readme.md file providing how to run your code and tests. You are free
# to add more tests as per your wish. :) Enjoy !!! .

Feature: Reverse Replay Http Server should send back reversed data

 Scenario: simple data
   Given Reverse Replay Server is Running
   When we send "Hello World!"
   Then we should receive back "!dlroW olleH"
