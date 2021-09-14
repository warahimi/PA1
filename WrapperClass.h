#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include "LinkedList.h"
#include<fstream>
#include<cstdlib>
#include "Question.h"
#include "Profile.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class WrapperClass
{
public:
    WrapperClass();
    void runGame();
private:
    std::fstream commandsFile;
    std::fstream profilesFile;
    int numberOfProfiles = 0;
    std::string playerName;
    LinkedList<std::string, std::string> list;
    Profile profiles[50]; //this is a poor design decision, because the size is fixed
    void loadFiles();
    void menu();
    void performUserSelection(int option);
    void gameRules();
    void playGame();
    void generateRandomCommand(LinkedList<int,std::string> &trackList);
    void loadPreviousGame();
    void addCommand();
    void removeCommand();
    void writeChangesToFiles();
};
