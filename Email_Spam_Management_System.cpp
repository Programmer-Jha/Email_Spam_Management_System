#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>
#include <ctime>
using namespace std;

class Email
{
    public:
    int id;
    string subject;
    string body;
    time_t timestamp;

    Email(int i, string s, string b)
    {
        id = i;
        subject = s;
        body = b;
        timestamp = time(0);
    }
};

unordered_set<string> spamKeywords = {"win", "free", "money", "prize", "lottery", "offer", "rummy_circle", "cash_prizes", "unsubscribe"};

bool isSpam(Email email)
{
    for (const string &word : spamKeywords)
    {
        if (email.body.find(word) != string::npos)
        {
            return true;
        }
    }
    return false;
}

queue<Email> inbox;
queue<Email> spamBox;
int emailcounter = 1;

void insertEmail(Email email)
{
    if (isSpam(email))
    {
        cout << "Email identified as spam: " << email.subject << endl;
        spamBox.push(email);
    }
    else
    {
        cout << "Email identified as non-spam: " << email.subject << endl;
        inbox.push(email);
    }
}

void displayEmails(queue<Email> &emails)
{
    queue<Email> temp = emails;
    while (!temp.empty())
    {
        Email email = temp.front();
        cout<<"ID: "<<email.id<<endl;
        cout<<"Subject: "<<email.subject<<endl;
        cout<<"Body: "<<email.body<<endl;
        cout<<"Received: "<<ctime(&email.timestamp);
        cout<<"--------------------------------------------------------"<<endl;
        temp.pop();
    }
}

void displayInbox()
{
    if (inbox.empty())
    {
        cout << "Inbox is empty." << endl;
    }
    else
    {
        cout << endl << "------------ Inbox Emails ------------" << endl;
        displayEmails(inbox);
    }
}

void displaySpamBox()
{
    if (spamBox.empty())
    {
        cout << "No Spam Emails." << endl;
    }
    else
    {
        cout << endl << "----------- Spam Emails -----------" << endl;
        displayEmails(spamBox);
    }
}

void displayAllEmails()
{
    if (inbox.empty() && spamBox.empty())
    {
        cout << "No emails in the system." << endl;
        return;
    }
    cout << endl << "---------- All Emails ----------" << endl;
    if (!inbox.empty())
    {
        cout << "\n--- Inbox Emails ---" << endl;
        displayEmails(inbox);
    }
    if (!spamBox.empty())
    {
        cout << "\n--- Spam Emails ---" << endl;
        displayEmails(spamBox);
    }
}

void addEmailFromUser()
{
    string subject, body;
    cout << "Enter the subject of the email: ";  
    getline(cin, subject);
    cout << "Enter the body of the email: ";
    getline(cin, body);

    Email email(emailcounter++, subject, body);
    insertEmail(email);
}

void deleteEmail(queue<Email> &emails, int id) {
    queue<Email> temp;
    bool found = false;

    while (!emails.empty()) {
        Email email = emails.front();
        emails.pop();

        if (email.id == id) {
            found = true;
            cout << "Email with ID " << id << " has been deleted." << endl;
        } else {
            temp.push(email);
        }
    }

    emails = temp;

    if (!found) {
        cout << "Email with ID " << id << " not found." << endl;
    }
}

void deleteEmailById() {
    int id;
    char confirm;
        
    cout << "Enter the ID of the email to delete: ";
    cin >> id;

    cout << "Are you sure you want to delete the email with ID " << id << "? (y/n): ";
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y') {
        deleteEmail(inbox, id);
        deleteEmail(spamBox, id);
    } else {
        cout << "Deletion cancelled." << endl;
    }
}

int main()
{
    int choice;
    do
    {
        cout << "\nEmail Spam Management System\n";
        cout << "1. Add an Email\n";
        cout << "2. Display Inbox\n";
        cout << "3. Display Spam Box\n";
        cout << "4. Display All Emails\n";
        cout << "5. Delete an Email\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            addEmailFromUser();
            break;
        case 2:
            displayInbox();
            break;
        case 3:
            displaySpamBox();
            break;
        case 4:
            displayAllEmails();
            break;
        case 5:
            deleteEmailById();
            break;
        case 6:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

// Test Cases / User Inputs for the Program

// TEST CASE: 1     
// Enter the subject of the email: LinkedIn Premium Alert
// Enter the body of the email: Hello User, you are informed that your linkedin premium is going to be expired tomorrow so that an auto charge will be deducted from your bank account to continue and allow your all premium features.

// TEST CASE: 2
// Enter the subject of the email: Win Cash Prizes
// Enter the body of the email: Hey Gamers, you got a free voucher of INR 5000

// TEST CASE: 3
// Enter the subject of the email: Project Development Update
// Enter the body of the email: Hey Teammates, this mail is to inform you all that we had successfully completed our project name "Email Spam Management System".

// TEST CASE: 4
// Enter the subject of the email: Rummy Circle
// Enter the body of the email: Hey Gamers, you got a free voucher of INR 10000 login to rummycircle.com to claim the reward.

// TEST CASE: 5
// Enter the subject of the email: Meeting Update
// Enter the subject of the email: Hello Everyone, all the employees of our company are to be informed that the meeting for the changing strategy of our company's work model is to be fixed by our Chairman Sir on 23rd of this month, so kindly be present there!!!.