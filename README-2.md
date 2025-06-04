
# 🔐 Password Manager using C++ and SQLite

This project is a simple **Password Manager** developed using **C++** and **SQLite3**. It provides a command-line interface (CLI) to store, search, and view saved passwords for different websites. All data is persistently stored using an SQLite database, and a Binary Search Tree (BST) is used to organize in-memory data efficiently.

---

## 📂 Project Structure

```
📁 PasswordManager/
├── test.h            # Header file containing class declarations
├── function.cpp      # Main logic for class methods and SQLite operations
└── main.cpp          # Entry point of the application
```

---

## 🧠 Features

- ✅ Add new password credentials (Site name, Username, Password)
- 🔍 Search password details by username
- 🌳 View all stored passwords in **in-order BST traversal**
- 💾 All data is stored persistently in an SQLite3 database (`password-manager.db`)
- 🌱 On startup, previously saved data is automatically loaded into the BST

---

## 🛠 Technologies Used

- **C++**
- **SQLite3**
- **Binary Search Tree (BST)** for organizing data
- **Command-Line Interface (CLI)**

---

## 🚀 How to Run

### 1. Install Dependencies

Ensure you have:

- A C++ compiler (e.g., `g++`)
- SQLite3 installed (`sudo apt install libsqlite3-dev` on Linux)

### 2. Compile the Project

```bash
g++ main.cpp function.cpp -o PasswordManager -lsqlite3
```

### 3. Run the Application

```bash
./PasswordManager
```

---

## 📸 CLI Preview

```
Welcome To Password Manager
1. Add New Password
2. Search Password
3. Print InOrder
4. Exit
```

---

## 🧪 Example Use Case

### Add a new site:
```
Sitename: github
Username: john123
Password: mySecurePass
```

### Search by username:
```
Input: john123
Output: 
Site: github
Username: john123
Password: mySecurePass
```

### Print all stored credentials:
- Displays records sorted by username (BST in-order)

---

## 📈 Future Improvements

- 🔒 Encrypt stored passwords
- ✏️ Support editing and deleting entries
- 🧪 Add unit testing
- 🌐 GUI version using Qt or Web technologies
- 🔑 Master password authentication

---

## 👨‍💻 Author

- Developed by **Sapta Rangi** during summer break to build better software design habits with multi-file C++ projects and deeper use of data structures like BST.

---

## 📝 License

This project is licensed under the MIT License. Feel free to use, modify, or distribute it.

