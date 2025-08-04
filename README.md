# 📧 Email Spam Management System

The **Email Spam Management System** is a console-based C++ project designed to simulate the process of identifying and filtering spam emails using basic keyword matching techniques. This project demonstrates a simplified version of spam detection logic without the use of complex algorithms or machine learning.

---

## 👨‍💻 Author
**Aniket Kumar Jha**  
Topic - Email Spam Management System

---

## 📝 Description

This system takes a number of email messages as input and analyzes them to determine whether they are spam or not. It uses a basic keyword-matching algorithm to identify common spam-related terms like:
free, win, winner, money, urgent, click, offer

If a message contains any of these keywords (case-insensitive), it's categorized as **Spam**; otherwise, it goes to the **Inbox**.

---

## 💡 Features

- Simple keyword-based spam filtering
- Case-insensitive message analysis
- Categorizes messages into Inbox and Spam Box
- Easy to understand and beginner-friendly

---

## 🛠️ Tech Stack

- **Language:** C++
- **Compiler:** g++ or any C++-compatible IDE
- **Libraries Used:** iostream, string, vector, algorithm

---

## 🚀 How to Run

1. Clone or download the repository.

2. Compile the code:
   ```bash
   g++ email_spam_management.cpp -o spam_filter
3. 
If a message contains any of these keywords (case-insensitive), it's categorized as **Spam**; otherwise, it goes to the **Inbox**.

---

## 💡 Features

- Simple keyword-based spam filtering
- Case-insensitive message analysis
- Categorizes messages into Inbox and Spam Box
- Easy to understand and beginner-friendly

---

## 🛠️ Tech Stack

- **Language:** C++
- **Compiler:** g++ or any C++-compatible IDE
- **Libraries Used:** iostream, string, vector, algorithm

---

## 🚀 How to Run

1. Clone or download the repository.

2. Compile the code:
   ```bash
   g++ email_spam_management.cpp -o spam_filter
3. Run the Program
    ./spam_filter

Follow on-screen prompts to input email messages and see the classification result.

📌 Future Enhancements
1. Add custom keyword input from the user
2. Save output to file or database
3. Integrate with GUI using Qt or other C++ frameworks
4. Extend logic using machine learning (with Python/C++)