
#include <iostream>
#include <fstream>
#include <string>

void inserting_file(std::fstream& nf,  char fname[],  char str[]) {

    nf.open(fname, std::ios::out);
    if (nf.is_open()){
        nf << str;
        //inserting text
       nf.close();
    }
   
}
void printfile(std::fstream& newfile, char fname[]) {
    newfile.open(fname, std::ios::in);
    std::string tp;
    if (newfile.is_open()){
        while (getline(newfile, tp)) {            
            std::cout << tp << std::endl;         
        }
        newfile.close();
    }
}
//capitalizes the first and last letters of each word
std::string capitalizes_letters(std::fstream& newfile, char fname[]) {
    newfile.open(fname, std::ios::in);
    std::string tp;
    if (newfile.is_open()) {

        while (getline(newfile, tp)) { 

            int length = tp.length();
            for (int i = 0; i < length; i++) {

                if (i == 0 || i == (length - 1)) {
                    tp[i] = toupper(tp[i]);
                }
                else if (tp[i] == ' ') {
                    tp[i - 1] = toupper(tp[i - 1]);
                    tp[i + 1] = toupper(tp[i + 1]);
                }
            }
            newfile.close();
            return tp;
        }

    }
}
int main()
{
    std::fstream newfile;
    char str[]="namespaces are used to organize code into logical groups and to prevent name \
 collisions that can occur especially when your code base includes multiple libraries.\n";
    char fname[] = "SomeWords.txt";

    inserting_file(newfile, fname,  str);

    printfile(newfile, fname);

    std::cout << "\n\n String after capitalizing first and last letter of each word :\n";
    std::cout << "_______________________________________________________ \n\n";

    std::cout << capitalizes_letters(newfile, fname);
    std::cout << "\n";

    
    return 0;
}

