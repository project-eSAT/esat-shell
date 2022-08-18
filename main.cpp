// secondary shell for raspberry pi

// for use in the esat project

// while in the main shell, you can type in classifiers and commands to run them
// there are 4 classifiers:
// 1. system commands (os)
// 2. testing commands (test)
// 3. source commands (src)
// 4. help commands (help)

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

#include <iostream>
#include <map>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

using namespace std;
// global variable string cmd
string cmd;

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
        if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
            result += buffer.data();
    }
    return result;
}

// map of commands that are built into the shell
map<string, string> builtin = {
        {"os", "execute system level commands. 'format is os <command>'. ex: 'os sudo apt install python3', commands will pass through and return the output of the command"},
        {"test", "execute testing commands. 'format is test <command>'. ex: 'test motor', will execute testing scripts in python in the test folder"},
        {"src", "execute source commands. 'format is src <command>'. ex: 'src pull observations@latest', will execute the respective command with git, with arguments hardcoded"},
        {"help", "display help text. 'format is help <command>'. ex: 'help ipconfig', will display the help text for any given command, and will return the help message from the os if the command is not registered by the shell"}

};

string os (string cmd) {
    printf("%s\n", exec(cmd.c_str()).c_str());
}

string test (string cmd) {
    string test_command = "cd test && python3 " + cmd+".py";
    printf("%s\n", exec(test_command.c_str()).c_str());
}

string help (string cmd) {
// if cmd can be found in the map, display the help text for the command
    if (builtin.find(cmd) != builtin.end()) {
        cout << builtin[cmd] << endl;
    }
    else {
        string help_command = "help " + cmd;
        printf("%s\n", exec(help_command.c_str()).c_str());
    }
}

string src (string cmd) {
//    placeholder
    string src_command = "git help " + cmd;
    printf("%s\n", exec(src_command.c_str()).c_str());
}

void shell() {
    cout << "welcome to the secondary shell that was never needed \n"
            "type in commands with classifiers and commands to run them. \n"
            "ex: os sudo apt install python3 \n"
            "ex: test motor \n"
            "ex: src pull observations@latest \n"
            "ex: help ipconfig \n"
         << endl;

    cin >> cmd;

// formatter for commands
/* check for classifiers, which are always the first word, and anything else is to be stored as cmd  */
// break cmd into two parts, classifier and command
    string classifier = cmd.substr(0, cmd.find(" "));
// cmd is anything after the classifier
    string cmd = cmd.substr(cmd.find(" ") + 1);

    if (classifier == "os") {
        os(cmd);
    } else if (classifier == "test") {
        test(cmd);
    } else if (classifier == "src") {
        src(cmd);
    } else if (classifier == "help") {
        help(cmd);
    } else {
        help(cmd);
    }
}





int main() {
    shell();
    return 0;
}
