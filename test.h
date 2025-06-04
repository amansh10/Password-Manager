#ifndef TEST_H
#define TEST_H 

#include<iostream>
#include<sqlite3.h>
using namespace std; 

class PasswordNode{
  public:
    string siteName,password,userName; 
    PasswordNode *left; 
    PasswordNode *right; 

    PasswordNode(string sitename, string Password,string UserName){
            siteName=sitename;
             password=Password; 
             userName=UserName; 
             left=right=nullptr; 

    };
    
    }; 

class PasswordManager {
private:
    PasswordNode* root; 

public:
   PasswordManager() { root = nullptr; }

    void insertion(PasswordNode*& root, string sitename, string Password, string UserName);
    PasswordNode *search(PasswordNode* root, string UserName);
    void printSearchDetails(PasswordNode* root, string UserName);
    void printInOrder(PasswordNode* root);
    void loadFromDatabase();
    void menu();
};



#endif