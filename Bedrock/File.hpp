/*++
Copyright (c) 2019 Bedrock Studios. All Right Reserved.
Licensed under the GNU Public Generic License v3.

Module:
- "File.hpp"

Created:
- 29/06/2019

Summary:
- Contains the file-handling operations and functions,
  for the Bedrock language and translator.

Authors:
- Auron
--*/

#ifndef FILE_HPP
#define FILE_HPP

#include <fstream>          // C++ standard file operations.
#include "Directory.hpp"    // Bedrock directory-handler.

namespace Bedrock
{
    class File {
    private:
        string m_Path;
        string m_Name;
    public:
        File(Directory *, string);
        virtual ~File(void);
        bool FindFile(void) const;
        void SetFile(string);
        string GetFile(void) const throw();
    };

    // Creates a target file object, with the given directory's path and file name...
    File::File(Directory *dir, string name) : m_Path(dir->GetDirectory()), m_Name(name) {

    }

    // Destroys the calling object...
    File::~File(void) {
        delete this;
    }

    // Tries to find the calling object's complete path...
    bool File::FindFile(void) const {
        if (FILE *file = fopen((this->m_Path + this->m_Name).c_str(), "r")) {
            fclose(file);
            return true;
        }
        else {
            return false;
        }
    }

    // Change the calling object's name... (changing the path is done with the Directory class)
    void File::SetFile(string name) {
        this->m_Name = name;
    }

    // Returns the calling object's complete path.
    string File::GetFile(void) const throw() {
        if (this->FindFile()) {
            return (this->m_Path + this->m_Name);
        }
        else {
            throw -1;
        }
    }
} // namespace Bedrock

#endif // FILE_HPP
