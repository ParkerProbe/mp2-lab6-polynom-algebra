#ifndef EQ_EXCEPTION_H_
#define EQ_EXCEPTION_H_

#include <string>

#define MAX_COMMENT_LEN 256

enum error_code
{
    k_NO_ERROR,
    k_NEGATIVE_VALUE,
    k_OVERFLOW,
    k_OUT_OF_MEMORY,
    k_NOT_FOUND,
    k_EMPTY,
    k_INCORRECT_INDEX,
    k_WRONG_OPERATION_PLACEMENT,
    k_WRONG_BRACKETS_QUANTITY
};

class EqException
{
private:
    void operator=(const EqException& other) = delete;

    // code of error
    error_code error;
    const std::string k_set_comment[9] = { "NO ERROR", "NEGATIVE VALUE", "OVERFLOW", "OUT OF MEMORY", "NOT FOUND", "EMPTY", "INCORRECT_INDEX", "WRONG OPERATION PLACEMENT", "WRONG BRACKETS QUANTITY" };

public:
    // create exception using error_code::<something>
    EqException(error_code error_)
        : error(error_)
    {}
    EqException()
        : error(k_NO_ERROR)
    {}
    ~EqException() = default;

    inline const std::string& get_comment() const
    {
        return k_set_comment[error];
    }

    inline int get_error() const
    {
        return error;
    }

};


#endif // EQ_EXCEPTION_H