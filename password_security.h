#ifndef PASSWORD_SECURITY_H
#define PASSWORD_SECURITY_H

#include <string>

bool hashPassword(const std::string& password,
                  std::string& storedHash);

bool verifyPassword(const std::string& password,
                    const std::string& storedHash);

#endif
