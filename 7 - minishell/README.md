# minishell 

<img src="logo.jpg" alt="logo"/><br/>

------------

❗**The structure of the code may look strange, this is caused by the coding rules of School 21 (no more than 25 lines for a func etc.)**

------------

### Mini UNIX command interpreter.


The goal of the project is to create a mini version of the real shell and give a deeper understanding of terminal commands and process creation.

This two-person project was done with *@Hmiso*.


Please see <a href="./subject.pdf">subject.pdf</a> for getting the assignments.

------------
#### Build and Run:
```
> make
> ./minishell
```
#### Implemented features:
* ```pipes```, ```semicolons```, ```enviroment variables```, ```$?```, redirections: ```>``` ```>>``` ```<```
* Builtins: ```cd```, ```pwd```, ```echo```, ```export```, ```unset```, ```env```, ```exit```
* Signals: ```Ctrl-C```, ```Ctrl-\```, ```Ctrl-D```
* Commands work with absolute and relative paths.

#### Crazy Stuff:

You can find some crazy cases in *cases.txt* which are working correctly like in real bash.<br/>
To test them just open two windows: with my minishell and real bash and compare behaviour.

#### Sources:
- [Write a Shell in C - Brennan.io](https://brennan.io/2015/01/16/write-a-shell-in-c/)