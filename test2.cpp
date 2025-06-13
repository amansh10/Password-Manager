#include<iostream>
#include<sqlite3.h>

#include"test.h"
// just checking for github 
using namespace std; 

void PasswordManager::insertion(PasswordNode*& root,string sitename, string Password,string userName){
    
    PasswordNode* newNode=new PasswordNode(sitename,Password,userName);
    if(root==nullptr){
        root=newNode;

  return;
    }
  
  else if (userName.compare(root->userName) > 0){
    insertion(root->right,sitename,Password,userName);

  }

   else if (userName.compare(root->userName) < 0){
    insertion(root->left,sitename,Password,userName);
    
  }


        sqlite3 *db; 
    char *errMsg=nullptr;
    int rc=sqlite3_open("password-manager.db", &db);

    string sql="CREATE TABLE IF NOT EXISTS password ("
    "SNO INTEGER PRIMARY KEY AUTOINCREMENT,"
    "SiteName TEXT NOT NULL,"
    "UserName TEXT NOT NULL,"
    "Password TEXT NOT NULL);";

    rc=sqlite3_exec(db,sql.c_str(),nullptr,0,&errMsg);


    string sql_insertion = "INSERT INTO password (SiteName, UserName, Password) VALUES ('" 
                        + sitename + "', '" + userName + "', '" + Password + "');";

    rc=sqlite3_exec(db,sql_insertion.c_str(),nullptr,0,&errMsg);



sqlite3_close(db);

}

PasswordNode* PasswordManager::search(PasswordNode *root, string userName){
   
    PasswordNode *result=root;
    if(result==nullptr){
         sqlite3 *db; 
    sqlite3_open("password-manager.db", &db);

    char *errMsg=nullptr;
   // string sql_search="SELECT SiteName, UserName, Password FROM password WHERE UserName=''"+userName+"';";
    string sql_search = "SELECT SiteName, UserName, Password FROM password WHERE UserName='" + userName + "';";


           auto callback = [](void* unused, int argc, char** argv, char** colNames) -> int {
        for (int i = 0; i < argc; ++i) {
            cout << colNames[i] << ": " << (argv[i] ? argv[i] : "NULL") << "  "; 
            
        };
         cout << endl;
    return 0;
    };

    int rc=sqlite3_exec(db,sql_search.c_str(),callback,0,&errMsg);
    sqlite3_close(db);
    return nullptr;
    }

    if(result->userName==userName){
        return result;
     

    }
    else if(userName.compare(result->userName)>0){
        return search(result->right,userName);

    }

    else if(userName.compare(result->userName)<0){
        return search(result->left,userName);

    }
    return nullptr;
  
    

};
void PasswordManager::printSearchDetails(PasswordNode *root, string userName){
    PasswordNode* Details=search(root,userName);
    if(Details==nullptr){
        cout<<"There is no such data! "<<endl;
        return;
    }
    cout<<"The name of the site is "<<Details->siteName<<endl;
    cout<<"The password of the site is "<<Details->password<<endl;
    cout<<"The username associated with site is "<<Details->userName<<endl;

    cout<<" "<<endl; 


};

void PasswordManager::printInOrder(PasswordNode *root) {

    if(root==nullptr){
        return;
    }

    else{
    printInOrder(root->left);
    cout<<"The name of the site is "<<root->siteName<<endl;
    cout<<"The password of the site is "<<root->password<<endl;
    cout<<"The username associated with site is "<<root->userName<<endl;
    cout<<" "<<endl;
    printInOrder(root->right);

    };


};

void PasswordManager::loadFromDatabase() {
    sqlite3* db;
    sqlite3_open("password-manager.db", &db);
    string sql = "SELECT SiteName, UserName, Password FROM password;";
    
    auto callback = [](void* data, int argc, char** argv, char** colNames) -> int {
        PasswordManager* pm = static_cast<PasswordManager*>(data);
        string site = argv[0];
        string user = argv[1];
        string pass = argv[2];
        pm->insertion(pm->root, site, pass, user);  
        return 0;
    };

    char* errMsg = nullptr;
    sqlite3_exec(db, sql.c_str(), callback, this, &errMsg);
    sqlite3_close(db);
}





void PasswordManager::menu(){
loadFromDatabase();
    int option; 
    while(option!=4){
    cout<<"Welcome To Password Manager"<<endl;
    cout<<"1. Add New Password "<<endl;
    cout<<"2. Search Password "<<endl;
    cout<<"3. Print InOrder"<<endl;
    cout<<"4.Exit "<<endl;

    cin>>option;


    if(option==1){
   
        string sitename;
        string password; 
        string username;
        
        cout<<"What is the sitename? "<<endl;
        cin>>sitename;

        cout<<"What is username? "<<endl;
        cin>>username;

        cout<<"What is password? "<<endl;
        cin>>password;

        insertion(this->root,sitename,password,username);

        
    }

    else if(option==2){

         
        string userName;

       cout<<"What is the userName? "<<endl;
        cin>>userName;

       PasswordNode* result=search(this->root,userName);
        if(result!=nullptr){
        printSearchDetails(this->root,userName);
        };
        
        
    }
    else if(option==3){
            printInOrder(this->root);

    }
    else if(option==4){

        break;
    }

    };
    
    


};


 

