#ifndef EQ_EXCEPTION_H_
#define EQ_EXCEPTION_H_

#include <string>

#define MAX_COMMENT_LEN 256

class EqException
{
private:
    void operator=(const EqException& other) = delete;

public:
    std::string comment;
    
    enum error_code
    {
        TEST
    } error;

    EqException(error_code error_, const std::string comment_ = "")
        : comment(comment_), error(error_)
    {}
    ~EqException()= default;

    const std::string& get_comment() const
    {
        return comment;
    }

    inline int get_error() const
    {
        return error;
    }
};


#endif // EQ_EXCEPTION_H
