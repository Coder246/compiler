#include <iostream>
#include <fstream>
#include "Lexer.h"
#include "Token.h"

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::ifstream;
using std::ostringstream;

string readFileIntoString(const string &path) {
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    return string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
}


int main(int argc, char **argv) {
    if (argc == 1) {
        std::cout << "ERROR: No input file give" << std::endl;
        return -1;
    } else {
        std::cout << "PROG: " << argv[1] << std::endl;
        string filename(argv[1]);
        string file_contents;

        file_contents = readFileIntoString(filename);
        //cout << file_contents << endl;


        Lexer lexer;
        lexer.lex(file_contents);


    }

    return 0;
}
