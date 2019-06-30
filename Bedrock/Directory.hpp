/*++
Copyright (c) 2019 Bedrock Foundation. All Right Reserved.
Licensed under the GNU Public Generic License v3.

Module:
- "Directory.hpp"

Created:
- 29/06/2019

Summary:
- Contains the directory-handling operations and functions,
  for the Bedrock language and translator.

Authors:
- Auron
--*/

#ifndef DIRECTORY_HPP
#define DIRECTORY_HPP

#include <sys/types.h>          // C++ "DIR" data type.
#include <dirent.h>             // Disk directory operations.
#include <string>               // C++ standard string class.
#include <cstring>              // C standard string operations.

using std::string;

namespace Bedrock
{
    class Directory {
    private:
        string m_Path;
    public:
        Directory(string);
        virtual ~Directory(void);
        bool FindDirectory(void) const;
        void SetDirectory(string);
        string GetDirectory(void) const throw();
    };

    // Creates a directory object, with the given path...
    Directory::Directory(string path): m_Path(path) {

    }

    // Destroys the directory object...
    Directory::~Directory(void) {
        delete this;
    }

    // Attempts to find the calling object's path...
    bool Directory::FindDirectory(void) const {
        DIR *dir = opendir(this->m_Path.c_str());
        if (dir) {
            closedir(dir);
            return true;
        }
        else {
            return false;
        }
    }

    // Allows the program to change the calling object's path...
    void Directory::SetDirectory(string path) {
        this->m_Path = path;
    }

    // Returns the calling object's path...
    string Directory::GetDirectory(void) const throw() {
        if (this->FindDirectory()) {
            return this->m_Path;
        }
        else {
            throw -1;
        }
    }
} // namespace Bedrock

#endif // DIRECTORY_HPP
