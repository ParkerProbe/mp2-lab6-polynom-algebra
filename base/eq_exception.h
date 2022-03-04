#ifndef EQ_EXCEPTION_H_
#define EQ_EXCEPTION_H_

#include <string>

#define MAX_COMMENT_LEN 256

class EqException
{
private:
    void operator=(const EqException& other) = delete;

public:
    std::string comment_;
    
    enum error_code
    {
        TEST
    } error_;

    EqException(error_code error, const std::string comment = "")
        : comment_(comment), error_(error)
    {}
    ~EqException()= default;

    const std::string& get_comment() const
    {
        return comment_;
    }

    inline int get_error() const
    {
        return error_;
    }
};


#endif // EQ_EXCEPTION_H
