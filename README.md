# Sacred

[Sacred](https://esolangs.org/wiki/Sacred) is a joke esoteric programming language that uses only brackets and spaces.

For example, the below writes `Hello World!` to the screen:

```
())( () () () () () () () () ( )) () () () () ( )) () () )) () () () )) () ()
() )) () (( (( (( (( )( ) )) () )) () )) )( )) )) () ( (( ) (( )( ) )) )) (((
)) )( )( )( ((( () () () () () () () ((( ((( () () () ((( )) )) ((( (( )( (((
(( ((( () () () ((( )( )( )( )( )( )( ((( )( )( )( )( )( )( )( )( ((( )) )) ()
((( )) () () (((
```

It was specified by [Conor O'Brien](https://esolangs.org/wiki/User:Conor_O%27Brien) in 2015 but until today had no interpreter or compiler.

The way it works is very similar to the more famous [Brainfuck](https://github.com/DanielJohnBenton/Brainfug) language, but has some additional commands.

## Commands
|Command|Meaning|Brainfuck equivalent|
|---|---|---|
|`())(`|Indicates Sacred [mode 1](https://esolangs.org/wiki/Sacred#Mode_1:_Brainf.2A.2A.2A) (interpret as programming language).|NONE|
|`()()`|Indicates Sacred [mode 2](https://esolangs.org/wiki/Sacred#Mode_2:_Sacred_.3Clanguage.3E) (ASCII encoding/obfuscation of any text e.g. Sacred Scheme). Mode 2 is not implemented in this interpreter but a short JavaScript snippet can be found on Esolangs for this conversion.|NONE|
|`()`|Increments the current byte.|`+`|
|`)(`|Decrements the current byte.|`-`|
|`((`|Go left in the data strip.|`<`|
|`))`|Go right in the data strip.|`>`|
|`(`|Jump past the matching `)` if the byte is zero.|`[`|
|`)`|Jump back to the matching `(` if the byte is non-zero.|`]`|
|`(((`|Outputs the current byte as an ASCII character.|`.`|
|`)))`|Takes a single-character input as an ASCII character.|`,`|
|`((()`|Takes a numeric input.|NONE|
|`()))`|Outputs the byte as a number.|NONE|
|`((()))`|Converts the data strip into characters and evaluates them as if they were code.|NONE|
|`((()()))`|Converts the data strip into characters and evaluates them as if they were code. Places this command at the end of the program to evaluate again the strip ad infinitum.|NONE|

# More examples

## Cat program - integers

A [cat program](https://esolangs.org/wiki/Cat_program) writes its input directly to its output.
This will keep taking integers as input until the user enters 0.

```
())(                                 ; this is a Sacred program - mode 1
()                                   ; set [0] to 1
)) () () () () () () () () () ()     ; set [1] to 10 - newline
((                                   ; return to [0]
(                                    ; loop until [0] is 0
	((() ()))                        ; take integer input and output it
	)) (((                           ; move to [1] to output newline
	((                               ; return to [0] to take next integer
)                                    ; end loop
```

Output:

```
PS D:\code\sacred> .\sacred examples/cat_int.sacred
1
1
-5
-5
1000
1000
0
0
```

## Self-programmer

The following (rather inelegant) program:

```
())( )) () () () () () () () () () () ( )) () () () () )) () () () () )) () () () ()
)) () () () () )) () () () )) () () () () )) () () () () )) () () () )) () () () ()
)) () () () () )) () () () )) () () () () )) () () () () )) () () () )) () () () ()
)) () () () () )) () () () )) () () () () )) () () () () )) () () () )) () () () ()
)) () () () () )) () () () )) () () () () )) () () () () )) () () () )) () () () ()
)) () () () () )) () () () )) () () () () )) () () () () )) () () () )) () () () ()
)) () () () () )) () () () )) () () () () )) () () () () )) () () () )) () () () ()
)) () () () )) () () () () )) () () () () )) () () () )) () () () () )) () () () ()
)) () () () )) () () () () )) () () () () )) () () () )) () () () () )) () () () ()
)) () () () )) () () () () )) () () () () )) () () () )) () () () () )) () () () ()
)) () () () )) () () () () )) () () () () )) () () () )) () () () () )) () () () ()
)) () () () )) () () () () )) () () () () )) () () () )) () () () () )) () () () ()
)) () () () )) () () () () )) () () () () )) () () () )) () () () () )) () () () ()
)) () () () )) () () () () )) () () () () )) () () () )) () () () () )) () () () ()
)) () () () )) () () () () )) () () () () )) () () () )) () () () () )) () () () ()
)) () () () )) () () () () )) () () () () )) () () () )) () () () () )) () () () ()
)) () () () )) () () () () )) () () () () )) () () () )) () () () () )) () () () ()
)) () () () )) () () () () )) () () () () )) () () () )) () () () () )) () () () ()
)) () () () )) () () () () )) () () () () )) () () () )) () () () () )) () () () ()
)) () () () )) () () () () )) () () () () )) () () () )) () () () () )) () () () ()
)) () () () )) () () () () )) () () () () )) () () () )) () () () () )) () () () ()
)) () () () )) () () () () )) () () () )) () () () () )) () () () () )) () () () ))
() () () () )) () () () () )) () () () )) () () () () )) () () () () )) () () () ))
() () () () )) () () () () )) () () () )) () () () () )) () () () () )) () () () ))
() () () () )) () () () () )) () () () )) () () () () )) () () () () )) () () () ))
() () () () )) () () () () )) () () () )) () () () () )) () () () () )) () () () ))
() () () () )) () () () () )) () () () )) () () () () )) () () () () )) () () () ))
() () () () )) () () () () )) () () () )) () () () () )) () () () () )) () () () ))
() () () () )) () () () () )) () () () )) () () () () )) () () () () )) () () () ))
() () () () )) () () () () )) () () () )) () () () () )) () () () () )) () () () ()
)) () () () )) () () () () )) () () () () )) () () () )) () () () () )) () () () ()
)) () () () () )) () () () )) () () () () )) () () () () )) () () () )) () () () ()
)) () () () () )) () () () () )) (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( ((
(( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( ((
(( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( ((
(( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( ((
(( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( ((
(( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( ((
(( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( (( ((
(( (( (( (( (( (( (( )( ) )) )) () )) () )) )) () () )) () )) () )) () () )) )) () 
)) () () )) )) () )) () () )) )) () )) () () )) )) () )) () () )) )) () )) () () ))
)) () )) () () )) )) () )) () () )) )) () )) () () )) )) () )) () () )) )) () )) ()
() )) )) () () )) () )) () )) () () )) )) () )) () () )) )) () )) () () )) )) () ))
() () )) )) () )) () () )) )) () )) () () )) )) () )) () () )) () )) () )) () () ))
)) () )) () () )) )) () )) () () )) )) () )) () () )) )) () )) () () )) )) () )) ()
() )) )) () )) () () )) )) () )) () () )) )) () )) () () )) )) () )) () () )) () ))
() )) () () )) )) () )) () () )) )) () )) () () )) )) () )) () () )) )) () )) () ()
)) () )) () )) () () )) )) )) () () )) )) )) () () )) )) )) () () )) )) )) () () ))
() )) )) () () )) () )) () () )) () )) () )) () () )) () )) )) () () )) () )) )) ()
() )) () )) () )) () () )) )) () )) () () )) )) () )) () () )) )) () )) () () )) ))
() )) () () )) () )) () )) () () )) )) () )) () () )) () )) () )) () () )) )) )) ()
() )) )) )) () () )) )) )) () () )) )) )) () () )) () )) () )) () () )) )) )) )) ()
() )) () )) () )) () () )) )) )) )) () () )) () )) () )) () () ((()))
```

Writes the following program (sans newlines) to memory and then executes it:

```
())( )) () () () () () () () () () ()
(
	)) () () () () () () )) () () () () () () () () () )) () () () () )) (( (( (( (( )(
)
)) )( )( )) () () () () )) () )) (( (( (( (( )) ((( )) ((( )) (((
```

This in turn writes `:^)` to the screen:

```
PS D:\code\sacred> .\sacred examples/selfcodesmiley.sacred
:^)
```

If you replace `((()))` at the end of the program with `((()()))` it will then try to interpret `:^)` as a Sacred program and error out because it sees the bracket as closing an unopened loop:

```
PS D:\code\sacred> .\sacred examples/selfcodesmiley.sacred
:^)Error: Unopened or unclosed loop detected. Commands:
 ) ((()()))
 ```

# Implementation specifics
* Commands are not just delimited by space, but also by tabs and newlines (`\n` and `\t`)
* The memory starts as a single cell with value 0
* Nested loop capable!
* Negative values allowed - memory blocks are signed integers (`signed int`)
* Infinite number of memory blocks allowed
* Enforces against negative pointer locations - must be 0 or above
* Commands `((()))` and `((()()))` cause the memory to be evaluated as a Sacred program with its own memory strip initialised with a single cell with value 0
* In keeping with Brainfuck, numbers in memory are integers only - `((()` will only accept an integer

# Acknowledgements
* [Conor O'Brien](https://esolangs.org/wiki/User:Conor_O%27Brien) - Esolangs
* [Ascii Table](http://www.asciitable.com/)