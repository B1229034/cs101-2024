#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class myString {
private:
    string m_str;
public:
    myString(string s) {
        m_str = s; 
    }
    void show() {
        cout << m_str << endl;
    }
};



class ReadClass {
private:
    string* classNames;
    int classCount;
    int capacity;

    void addClassName(const string& className) {
        if (classCount == capacity) {
            int newCapacity = capacity == 0 ? 1 : capacity * 2;
            string* newClassNames = new string[newCapacity];
            for (int i = 0; i < classCount; ++i) {
                newClassNames[i] = classNames[i];
            }
            delete[] classNames;
            classNames = newClassNames;
            capacity = newCapacity;
        }
        classNames[classCount++] = className;
    }

    void extractClassNames(const string& content) {
        size_t pos = 0;
        while ((pos = content.find("class ", pos)) != string::npos) {
            pos += 6; 
            while (pos < content.size() && isspace(content[pos])) {
                ++pos; 
            }
            size_t start = pos;
            while (pos < content.size() && (isalnum(content[pos]) || content[pos] == '_')) {
                ++pos; 
            }
            if (start < pos) {
                addClassName(content.substr(start, pos - start));
            }
        }
    }

public:
    ReadClass() : classNames(nullptr), classCount(0), capacity(0) {}

    ~ReadClass() {
        delete[] classNames;
    }

    void readFile(const string& filename) {
        ifstream in(filename);
        if (!in.is_open()) {
            cerr << "Error opening file: " << filename << endl;
            return;
        }

        string line;
        string fileContent;
        while (getline(in, line)) {
            fileContent += line + '\n';
        }
        in.close();

        extractClassNames(fileContent);
    }

    void showClass() const {
        cout << classCount << " class" << (classCount != 1 ? "es" : "") << " in main.cpp" << endl;
        for (int i = 0; i < classCount; ++i) {
            cout << "class " << classNames[i] << endl;
        }
    }
};

int main() {
    ReadClass rfile;
    rfile.readFile("main.cpp");
    rfile.showClass();
    return 0;
}
