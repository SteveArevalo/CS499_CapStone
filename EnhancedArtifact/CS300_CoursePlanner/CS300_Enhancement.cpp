//============================================================================
// Name        : ProjectTwo_AVL.cpp
// Author      : Steve Arevalo
// Version     : 2.0
// Description : Enhanced program using an AVL Tree for efficient storage,
//               searching, printing, and deletion of course information.
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to hold course information
struct Course {
    string courseNumber;
    string courseName;
    vector<string> prerequisites;
};

// AVL Node structure
struct Node {
    Course course;
    Node* left;
    Node* right;
    int height;

    Node(Course c) : course(c), left(nullptr), right(nullptr), height(1) {}
};

// Get node height
int getHeight(Node* node) {
    return node ? node->height : 0;
}

// Calculate balance factor
int getBalance(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// Right rotation (LL Case)
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    // Return new root
    return x;
}

// Left rotation (RR Case)
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Rotate
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

// Insert a course into AVL Tree
Node* insertNode(Node* root, Course course) {
    if (!root) return new Node(course);

    if (course.courseNumber < root->course.courseNumber)
        root->left = insertNode(root->left, course);
    else if (course.courseNumber > root->course.courseNumber)
        root->right = insertNode(root->right, course);
    else
        return root; // Duplicate not allowed

    // Update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Check balance
    int balance = getBalance(root);

    // Case 1: Left-Left
    if (balance > 1 && course.courseNumber < root->left->course.courseNumber)
        return rotateRight(root);

    // Case 2: Right-Right
    if (balance < -1 && course.courseNumber > root->right->course.courseNumber)
        return rotateLeft(root);

    // Case 3: Left-Right
    if (balance > 1 && course.courseNumber > root->left->course.courseNumber) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Case 4: Right-Left
    if (balance < -1 && course.courseNumber < root->right->course.courseNumber) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// Find min node (used for deletion)
Node* findMin(Node* node) {
    while (node->left)
        node = node->left;
    return node;
}

// Delete a course from AVL Tree
Node* deleteNode(Node* root, string courseNumber) {
    if (!root) return root;

    if (courseNumber < root->course.courseNumber)
        root->left = deleteNode(root->left, courseNumber);

    else if (courseNumber > root->course.courseNumber)
        root->right = deleteNode(root->right, courseNumber);

    else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;

            if (!temp) { // No child
                temp = root;
                root = nullptr;
            } else { // One child
                *root = *temp;
            }
            delete temp;
        } else {
            Node* temp = findMin(root->right);
            root->course = temp->course;
            root->right = deleteNode(root->right, temp->course.courseNumber);
        }
    }

    if (!root) return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    // Rebalance cases
    if (balance > 1 && getBalance(root->left) >= 0)
        return rotateRight(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return rotateLeft(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// In-order traversal (sorted list)
void printCourseList(Node* root) {
    if (!root) return;
    printCourseList(root->left);
    cout << root->course.courseNumber << ", " << root->course.courseName << endl;
    printCourseList(root->right);
}

// Search for a course
Node* findCourse(Node* root, const string& courseNumber) {
    if (!root) return nullptr;
    if (root->course.courseNumber == courseNumber) return root;

    if (courseNumber < root->course.courseNumber)
        return findCourse(root->left, courseNumber);
    else
        return findCourse(root->right, courseNumber);
}

// Print detailed course info
void printCourseInfo(Node* courseNode) {
    if (!courseNode) {
        cout << "Course not found." << endl;
        return;
    }

    cout << courseNode->course.courseNumber << ", "
         << courseNode->course.courseName << endl;

    if (!courseNode->course.prerequisites.empty()) {
        cout << "Prerequisites: ";
        for (size_t i = 0; i < courseNode->course.prerequisites.size(); ++i) {
            cout << courseNode->course.prerequisites[i];
            if (i < courseNode->course.prerequisites.size() - 1)
                cout << ", ";
        }
        cout << endl;
    } else {
        cout << "Prerequisites: None" << endl;
    }
}

// Load CSV into AVL
Node* loadCourses(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return nullptr;
    }

    Node* root = nullptr;
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string courseNumber, courseName, prereq;
        vector<string> prereqs;

        getline(ss, courseNumber, ',');
        getline(ss, courseName, ',');

        while (getline(ss, prereq, ','))
            prereqs.push_back(prereq);

        Course course;
        course.courseNumber = courseNumber;
        course.courseName = courseName;
        course.prerequisites = prereqs;

        root = insertNode(root, course);
    }

    return root;
}

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Load Data Structure\n";
    cout << "2. Print Course List\n";
    cout << "3. Print Course\n";
    cout << "4. Delete Course\n";
    cout << "9. Exit\n";
    cout << "Enter choice: ";
}

int main() {
    Node* root = nullptr;
    string filename;
    bool dataLoaded = false;

    while (true) {
        displayMenu();
        int choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            cout << "Enter filename: ";
            getline(cin, filename);
            root = loadCourses(filename);

            if (root) {
                dataLoaded = true;
                cout << "Data loaded successfully.\n";
            }
        }

        else if (choice == 2) {
            if (!dataLoaded)
                cout << "Load data first.\n";
            else
                printCourseList(root);
        }

        else if (choice == 3) {
            if (!dataLoaded)
                cout << "Load data first.\n";
            else {
                string courseNum;
                cout << "Enter course number: ";
                getline(cin, courseNum);
                printCourseInfo(findCourse(root, courseNum));
            }
        }

        else if (choice == 4) {
            if (!dataLoaded)
                cout << "Load data first.\n";
            else {
                string courseNum;
                cout << "Enter course number to delete: ";
                getline(cin, courseNum);
                root = deleteNode(root, courseNum);
                cout << "Course deleted (if it existed).\n";
            }
        }

        else if (choice == 9) {
            cout << "Goodbye!" << endl;
            break;
        }

        else {
            cout << "Invalid option." << endl;
        }
    }

    return 0;
}
