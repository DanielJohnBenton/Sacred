# Sacred

[Sacred](https://esolangs.org/wiki/Sacred) is an esoteric programming language that uses only brackets and spaces.

For example, the below writes `Hello World!` to the screen:

```
())( () () () () () () () () ( )) () () () () ( )) () () )) () () () )) () ()
() )) () (( (( (( (( )( ) )) () )) () )) )( )) )) () ( (( ) (( )( ) )) )) (((
)) )( )( )( ((( () () () () () () () ((( ((( () () () ((( )) )) ((( (( )( (((
(( ((( () () () ((( )( )( )( )( )( )( ((( )( )( )( )( )( )( )( )( ((( )) )) ()
((( )) () () (((
```

It was specified by [Conor O'Brien](https://esolangs.org/wiki/User:Conor_O%27Brien) in 2015 but until today had no interpreter or compiler.

## Commands
|Command|Meaning|Brainfuck equivalent|
|---|---|---|
|`())(`|Indicates Sacred [mode 1](https://esolangs.org/wiki/Sacred#Mode_1:_Brainf.2A.2A.2A) (interpret as programming language.|NONE|
|`()()`|Indicates Sacred [mode 2](https://esolangs.org/wiki/Sacred#Mode_2:_Sacred_.3Clanguage.3E) (ASCII encoding/obfuscation of any text e.g. Sacred Scheme).|NONE|
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

# Examples

## Hello World

```
())( () () () () () () () () ( )) () () () () ( )) () () )) () () () )) () () () )) () (( (( (( (( )( ) )) () )) () )) )( )) )) () ( (( ) (( )( ) )) )) ((( )) )( )( )( ((( () () () () () () () ((( ((( () () () ((( )) )) ((( (( )( ((( (( ((( () () () ((( )( )( )( )( )( )( ((( )( )( )( )( )( )( )( )( ((( )) )) () ((( )) () () (((
```

Output: `Hello World!`

The way it works is very similar to the more famous [Brainfuck](https://github.com/DanielJohnBenton/Brainfug) language, but has some additional commands.

# Implementation specifics
* Commands are not just delimited by space, but also by tabs and newlines (`\n` and `\t`)
* The memory starts as a single cell with value 0
* Nested loop capable!
* Negative values allowed - memory blocks are signed integers (`signed int`)
* Infinite number of memory blocks allowed
* Enforces against negative pointer locations - must be 0 or above
* Commands `((()))` and `((()()))` cause the memory to be evaluated as a Sacred program with its own memory strip initialised with a single cell with value 0
* In keeping with Brainfuck, numbers in memory are integers only - `((()` will only accept an integer