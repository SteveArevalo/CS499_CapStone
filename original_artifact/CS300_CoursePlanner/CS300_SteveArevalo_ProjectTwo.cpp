//============================================================================
// Name        : ProjectTwo.cpp
// Author      : Steve Arevalo
// Version     : 1.0
// Description : Program to load, store, and search course information 
//               using a Binary Search Tree.
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
    string courseNumber;              // Course identifier
    string courseName;                // Full course title 
    vector<string> prerequisites;     // List of prerequisite courses
};

// Node structure for the Binary Search Tree
struct Node {
    Course course;  // Course data stored in this node
    Node* left;     // Pointer to left child
    Node* right;    // Pointer to right child

    // Constructor to initialize a node with a course
    Node(Course c) : course(c), left(nullptr), right(nullptr) {}
};

// Function to insert a course into the BST
Node* insert(Node* root, Course course) {
    // If tree is empty, create new node
    if (!root) return new Node(course);

    // Compare course numbers to maintain BST ordering
    if (course.courseNumber < root->course.courseNumber) {
        root->left = insert(root->left, course);   // Insert into left subtree
    } else {
        root->right = insert(root->right, course); // Insert into right subtree
    }
    return root;
}

// Function to perform in order traversal of BST
// Prints courses in alphanumeric order
void printCourseList(Node* root) {
    if (!root) return;
    printCourseList(root->left);  // Visit left subtree
    cout << root->course.courseNumber << ", " << root->course.courseName << endl;
    printCourseList(root->right); // Visit right subtree
}

// Function to search for a course in the BST by course number
Node* findCourse(Node* root, const string& courseNumber) {
    if (!root) return nullptr;  // Not found
    if (root->course.courseNumber == courseNumber) return root; // Match found

    // Search left or right subtree depending on comparison
    if (courseNumber < root->course.courseNumber) {
        return findCourse(root->left, courseNumber);
    } else {
        return findCourse(root->right, courseNumber);
    }
}

// Function to print detailed information about a course
void printCourseInfo(Node* courseNode) {
    if (!courseNode) {
        cout << "Course not found." << endl;
        return;
    }

    // Print course number and name
    cout << courseNode->course.courseNumber << ", " << courseNode->course.courseName << endl;

    // Print prerequisites if any
    if (!courseNode->course.prerequisites.empty()) {
        cout << "Prerequisites: ";
        for (size_t i = 0; i < courseNode->course.prerequisites.size(); ++i) {
            cout << courseNode->course.prerequisites[i];
            if (i < courseNode->course.prerequisites.size() - 1) cout << ", ";
        }
        cout << endl;
    } else {
        cout << "Prerequisites: None" << endl;
    }
}

// Function to load courses from a CSV file into a BST
Node* loadCourses(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open file." << endl;
        return nullptr;
    }

    Node* root = nullptr;
    string line;

    // Read file line by line
    while (getline(file, line)) {
        stringstream ss(line);
        string courseNumber, courseName, prereq;
        vector<string> prereqs;

        // First two values: course number and course name
        getline(ss, courseNumber, ',');
        getline(ss, courseName, ',');

        // Remaining values: prerequisites
        while (getline(ss, prereq, ',')) {
            prereqs.push_back(prereq);
        }

        // Create a Course object
        Course course;
        course.courseNumber = courseNumber;
        course.courseName = courseName;
        course.prerequisites = prereqs;

        // Insert course into BST
        root = insert(root, course);
    }

    file.close();
    return root;
}

// Function to display the main menu
void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Load Data Structure\n";
    cout << "2. Print Course List\n";
    cout << "3. Print Course\n";
    cout << "9. Exit\n";
    cout << "Enter choice: ";
}

// Main function
int main() {
    Node* root = nullptr;    // Root of BST
    string filename;         // File name for CSV input
    bool dataLoaded = false; // Tracks if data has been loaded

    while (true) {
        displayMenu();
        int choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        if (choice == 1) {
            // Load courses from a CSV file
            cout << "Enter file name: ";
            getline(cin, filename);
            root = loadCourses(filename);
            if (root) {
                dataLoaded = true;
                cout << "Data loaded successfully.\n";
            }
        }
        else if (choice == 2) {
            // Print sorted list of courses
            if (!dataLoaded) {
                cout << "Error: Please load the data first.\n";
            } else {
                printCourseList(root);
            }
        }
        else if (choice == 3) {
            // Find and print course information
            if (!dataLoaded) {
                cout << "Error: Please load the data first.\n";
            } else {
                string courseNum;
                cout << "Enter course number: ";
                getline(cin, courseNum);
                Node* found = findCourse(root, courseNum);
                printCourseInfo(found);
            }
        }
        else if (choice == 9) {
            // Exit program
            cout << "Goodbye!\n";
            break;
        }
        else {
            // Handle invalid menu choices
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
