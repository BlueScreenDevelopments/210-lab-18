#include <iostream>
#include <string>

using namespace std;

struct Node {
    double rating;
    string comments;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

void addNodeToHead(double rating, string comments) {
    Node* newNode = new Node;
    newNode->rating = rating;
    newNode->comments = comments;
    newNode->next = head;
    head = newNode;
    if (tail == nullptr) {
        tail = newNode;
    }
}

void addNodeToTail(double rating, string comments) {
    Node* newNode = new Node;
    newNode->rating = rating;
    newNode->comments = comments;
    newNode->next = nullptr;
    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

void printReviews() {
    Node* temp = head;
    int count = 1;
    double sum = 0.0;
    cout << "    ";
    while (temp != nullptr) {
        cout << "> Review #" << count << ": " << temp->rating << ": " << temp->comments << endl;
        sum += temp->rating;
        temp = temp->next;
        count++;
    }
    if (count > 1) {
        cout << "    > Average: " << sum / (count - 1) << endl;
    }
}

int main() {
    int choice;
    cout << "Which linked list method should we use?" << endl;
    cout << "    [1] New nodes are added at the head of the linked list" << endl;
    cout << "    [2] New nodes are added at the tail of the linked list" << endl;
    cout << "Choice: ";
    cin >> choice;

    bool addMore = true;
    while (addMore) {
        double rating;
        string comments;
        cout << "Enter review rating 0-5: ";
        cin >> rating;
        cout << "Enter review comments: ";
        cin.ignore();
        getline(cin, comments);
        if (choice == 1) {
            addNodeToHead(rating, comments);
        }
        else {
            addNodeToTail(rating, comments);
        }
        char response;
        cout << "Enter another review? Y/N: ";
        cin >> response;
        cout << endl;
        if (response == 'n' || response == 'N') {
            addMore = false;
        }
    }

    cout << "Outputting all reviews:" << endl;
    printReviews();

    return 0;
}