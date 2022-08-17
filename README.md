# esat-shell
###### secondary shell for raspberry pi for use in the esat project
.. that no one needed

**fu c++**

stupid types took me 2 hours to meddle with

```
/* system commands:
format: os <command>

 shell will execute any command that is entered in the <command> field, and will look for following words to execute:

 example:

 os git push origin master

will execute the command "git push origin master" not the command "git"
 */

/* testing commands:
format: test <command>

    shell will execute any testing function that is needed to be tested.

    if there are no following commands (ex: "test"), the shell will execute all testing functions

    if there are following commands (ex: "test motor"), the shell will execute the testing function that is specified
*/

/* source commands:

format: src <command>

 although git commands may be used the os class, the src class is more specific to the esat project's source code.

 similar to the os class, the src class will look for subcommands to execute.

 the difference being that the shell will pass through the commands to the os, and src will format the commands to be executed.

 ex: "src pull@latest" will execute the respective command with git, with arguments such as repo locations hardcoded.
 */

/* help commands:
format: help <command>

    shell will display the help text for the command that is specified.

    if there are no following commands (ex: "help"), the shell will display the help text for all commands.

    if there are following commands (ex: "help motor"), the shell will display the help text for the command that is specified.

    if the command is not registered by the shell, the shell will default to returning the help text by the os.

    ex: "help git" will display the help text for the git command, if it is not a registered command by the shell.
*/
```
