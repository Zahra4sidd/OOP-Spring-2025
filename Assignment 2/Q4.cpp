#include <iostream>
#include <string>
using namespace std;

int generateHash(const string& password) {
    int hash = 5381;
    for (char c : password) {
        hash = hash * 33 + c;
    }
    return hash;
}

class User {
protected:
    string name;
    string id;
    string* permissions;
    int permissionCount;
    string email;
    int hashedPassword;

public:
    User(string n, string i, string e, string p) : 
        name(n), id(i), email(e) {
        hashedPassword = generateHash(p);
        permissions = nullptr;
        permissionCount = 0;
    }

    bool authenticate(string password) {
        return generateHash(password) == hashedPassword;
    }

    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Email: " << email << endl;
        cout << "Permissions: ";
        for (int i = 0; i < permissionCount; i++) {
            cout << permissions[i] << " ";
        }
        cout << endl;
    }

    bool hasPermission(string action) {
        for (int i = 0; i < permissionCount; i++) {
            if (permissions[i] == action) {
                return true;
            }
        }
        return false;
    }

    virtual void accessLab() {
        if (hasPermission("full_lab_access")) {
            cout << name << " has full access to the lab." << endl;
        } else {
            cout << name << " does not have lab access." << endl;
        }
    }

    void addPermission(string perm) {
        string* newPerms = new string[permissionCount + 1];
        for (int i = 0; i < permissionCount; i++) {
            newPerms[i] = permissions[i];
        }
        newPerms[permissionCount] = perm;
        delete[] permissions;
        permissions = newPerms;
        permissionCount++;
    }

    string getName() { return name; }

    ~User() {
        if (permissions != nullptr) {
            delete[] permissions;
        }
    }
};

class Student : public User {
protected:
    int* assignments;
    int assignmentCount;

public:
    Student(string n, string i, string e, string p) : User(n, i, e, p) {
        assignments = nullptr;
        assignmentCount = 0;
        addPermission("submit_assignment");
    }

    void display() override {
        cout << "STUDENT DETAILS:" << endl;
        User::display();
        cout << "Assignments: ";
        for (int i = 0; i < assignmentCount; i++) {
            cout << "Assignment " << i+1 << ": " 
                 << (assignments[i] ? "Submitted" : "Pending") << " | ";
        }
        cout << endl;
    }

    void addAssignment() {
        int* newAssignments = new int[assignmentCount + 1];
        for (int i = 0; i < assignmentCount; i++) {
            newAssignments[i] = assignments[i];
        }
        newAssignments[assignmentCount] = 0;
        delete[] assignments;
        assignments = newAssignments;
        assignmentCount++;
    }

    void submitAssignment(int index) {
        if (index >= 0 && index < assignmentCount) {
            assignments[index] = 1;
            cout << name << " submitted assignment " << index+1 << endl;
        } else {
            cout << "Invalid assignment index." << endl;
        }
    }

    ~Student() {
        if (assignments != nullptr) {
            delete[] assignments;
        }
    }
};

class TA : public Student {
protected:
    Student** students;
    int studentCount;
    string* projects;
    int projectCount;

public:
    TA(string n, string i, string e, string p) : Student(n, i, e, p) {
        students = nullptr;
        studentCount = 0;
        projects = nullptr;
        projectCount = 0;
        addPermission("view_projects");
        addPermission("manage_students");
    }

    void display() override {
        cout << "TEACHING ASSISTANT DETAILS:" << endl;
        User::display();
        cout << "Managing " << studentCount << " students" << endl;
        cout << "Projects: ";
        for (int i = 0; i < projectCount; i++) {
            cout << projects[i] << " | ";
        }
        cout << endl;
    }

    bool addStudent(Student* student) {
        if (studentCount >= 10) {
            cout << "Cannot add more students. TA limit reached." << endl;
            return false;
        }

        Student** newStudents = new Student*[studentCount + 1];
        for (int i = 0; i < studentCount; i++) {
            newStudents[i] = students[i];
        }
        newStudents[studentCount] = student;
        delete[] students;
        students = newStudents;
        studentCount++;
        return true;
    }

    bool addProject(string project) {
        if (projectCount >= 2) {
            cout << "Cannot add more projects. TA project limit reached." << endl;
            return false;
        }

        string* newProjects = new string[projectCount + 1];
        for (int i = 0; i < projectCount; i++) {
            newProjects[i] = projects[i];
        }
        newProjects[projectCount] = project;
        delete[] projects;
        projects = newProjects;
        projectCount++;
        return true;
    }

    ~TA() {
        if (students != nullptr) {
            delete[] students;
        }
        if (projects != nullptr) {
            delete[] projects;
        }
    }
};

class Professor : public User {
protected:
    TA** tas;
    int taCount;

public:
    Professor(string n, string i, string e, string p) : User(n, i, e, p) {
        tas = nullptr;
        taCount = 0;
        addPermission("assign_projects");
        addPermission("full_lab_access");
    }

    void display() override {
        cout << "PROFESSOR DETAILS:" << endl;
        User::display();
        cout << "Working with " << taCount << " TAs" << endl;
    }

    void assignProject(TA* ta, string project) {
        if (ta->addProject(project)) {
            cout << "Assigned project '" << project << "' to TA " << ta->getName() << endl;
        } else {
            cout << "Failed to assign project to TA " << ta->getName() << endl;
        }
    }

    void addTA(TA* ta) {
        TA** newTAs = new TA*[taCount + 1];
        for (int i = 0; i < taCount; i++) {
            newTAs[i] = tas[i];
        }
        newTAs[taCount] = ta;
        delete[] tas;
        tas = newTAs;
        taCount++;
    }

    ~Professor() {
        if (tas != nullptr) {
            delete[] tas;
        }
    }
};

void authenticateAndPerformAction(User* user, string action, string password) {
    if (user->authenticate(password)) {
        if (user->hasPermission(action)) {
            cout << "Authentication successful. Performing action: " << action << endl;
            if (action == "submit_assignment") {
                Student* s = dynamic_cast<Student*>(user);
                if (s) {
                    s->submitAssignment(0);
                }
            } else if (action == "view_projects") {
                cout << "Viewing projects..." << endl;
            } else if (action == "assign_projects") {
                cout << "Assigning projects..." << endl;
            } else if (action == "full_lab_access") {
                user->accessLab();
            }
        } else {
            cout << "User doesn't have permission for this action." << endl;
        }
    } else {
        cout << "Authentication failed. Incorrect password." << endl;
    }
}

int main() {
    Student student1("Alice", "S001", "alice@uni.edu", "student123");
    student1.addAssignment();
    student1.addAssignment();

    TA ta1("Bob", "T001", "bob@uni.edu", "ta123");
    
    Professor prof1("Dr. Smith", "P001", "smith@uni.edu", "prof123");

    ta1.addStudent(&student1);

    prof1.addTA(&ta1);
    prof1.assignProject(&ta1, "AI Research");
    prof1.assignProject(&ta1, "Database Optimization");

    cout << "\nDisplaying User Information" << endl;
    student1.display();
    cout << endl;
    ta1.display();
    cout << endl;
    prof1.display();

    cout << "\nTesting Authentication" << endl;
    authenticateAndPerformAction(&student1, "submit_assignment", "student123");
    authenticateAndPerformAction(&ta1, "manage_students", "ta123");
    authenticateAndPerformAction(&prof1, "assign_projects", "prof123");
    authenticateAndPerformAction(&prof1, "full_lab_access", "prof123");

    cout << "\nTesting Failed Authentication" << endl;
    authenticateAndPerformAction(&student1, "submit_assignment", "wrongpass");

    cout << "\nTesting Unauthorized Action" << endl;
    authenticateAndPerformAction(&student1, "assign_projects", "student123");

    return 0;
}
