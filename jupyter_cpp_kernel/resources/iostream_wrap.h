#ifndef IOSTREAM_WRAP_H
#define IOSTREAM_WRAP_H

#include <iostream>
#include <sstream>
#include <string>
#include "stdio_wrap.h"

class cin_wrapper : public std::istringstream {
    public:
        cin_wrapper() : std::istringstream("") {

        };
        template <typename T> cin_wrapper& operator>>(T& val) {
            char doRequest = checkInputRequest();
            if (doRequest) {
#ifdef BUFFERED_OUTPUT
                flush_all_output();
#endif
                std::cout << "<inputRequest>";
                fflush(stdout);
                /* read everything from stdin into buffer */
                readIntoBuffer();
            }

            str(std::string(inputBuff));
            seekg(0);

            std::istringstream::operator>>(val);

            const long length = strlen(inputBuff);
            long index = tellg();
            long a = 0;
            /* +1 to include \0 */
            for(; index < length + 1; ++a, ++index) {
                inputBuff[a] = inputBuff[index];
            }
            
            return *this;
        }
};

namespace std {
    static cin_wrapper cin_wrap;
}

#define cin cin_wrap

#endif /* IOSTREAM_WRAP_H */