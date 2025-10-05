
```markdown
# 🧩 LexicalAnalyser (C Project)

## 📘 Overview
**LexicalAnalyser** is a C program that performs **lexical analysis** on C source code.  
It reads a `.c` file, classifies its components into tokens (keywords, identifiers, constants, operators, delimiters, etc.), and reports **basic syntax errors** such as:
- Missing semicolons
- Missing or unmatched quotes
- Unclosed braces `{}`, parentheses `()`, and brackets `[]`

This project demonstrates the **first phase of compiler design**, helping users understand how compilers scan and validate source code.

---

## 🚀 Features
- 🔹 Token classification for C language elements  
- 🔹 Detection of common syntax and lexical errors  
- 🔹 Supports input from `.c` source files  
- 🔹 Modular implementation with headers and source files  
- 🔹 Ideal for compiler design learning and educational projects  

---

## 🧩 Project Structure

```

📂 LexicalAnalyser
│
├── main.c            # Entry point; handles input and output operations
├── analyse.c         # Contains tokenization and error-detection logic
├── analyse.h         # Function prototypes and constants
├── types.h           # User-defined enums and typedefs
├── sample.c          # Example input C file
├── Makefile          # For compiling the project easily
└── README.md         # Project documentation

````

---

## ⚙️ How It Works
1. The program reads the source `.c` file line by line.  
2. Each token (word, operator, or symbol) is analyzed and classified.  
3. It keeps track of opened and closed symbols like `{}`, `()`, and `[]`.  
4. Reports syntax errors such as:
   - Missing semicolons
   - Unmatched quotes or braces
5. Displays a clean, categorized output of all identified tokens and errors.

---

## 🧪 Example Usage

### **Input**
`sample.c`
```c
#include <stdio.h>

int main() {
    printf("Hello World!")
    return 0;
}
````

### **Output**

```
Keyword: int
Identifier: main
Special Symbol: (
Special Symbol: )
Special Symbol: {
Function: printf
String Literal: "Hello World!"
Error: Missing semicolon at line 4
Keyword: return
Constant: 0
Special Symbol: ;
Special Symbol: }
```

---

## 🛠️ Compilation

Use the provided **Makefile** to build the project:

```bash
make
```

This generates an executable named `lexical`.

Run the program with:

```bash
./lexical sample.c
```

Clean build files:

```bash
make clean
```

---

## 📚 Concepts Used

* File handling in C
* Tokenization and string manipulation
* Character classification using `ctype.h`
* Stack-based error checking for braces and parentheses
* Modular programming and structured design

---

## 🧠 Educational Value

This project demonstrates how the **lexical analysis phase** of a compiler works internally — converting raw code into meaningful tokens before syntax and semantic analysis.

---

## ✨ Author

**SriSanthosh**
💻 *C Programmer & Compiler Design Enthusiast*
📧 srisanthosh4711@gmail.com
🌐 [https://github.com/srisanthosh-babu]

---


## 💬 Contributing

Contributions, suggestions, and improvements are welcome!
Feel free to fork this repository and submit a pull request.

---

> 🧠 *“Lexical analysis is where understanding code truly begins.”*

```


