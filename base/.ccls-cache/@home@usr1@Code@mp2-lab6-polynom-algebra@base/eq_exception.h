#ifndef EQ_EXCEPTION_H
#define EQ_EXCEPTION_H

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
    test
  } error;

  EqException(error_code _error, const std::string _comment = "") :
    comment(_comment), error(_error)
  {}
  ~EqException()= default;

  const std::string& GetComment() const
  {
    return comment;
  }

  inline int GetError() const
  {
    return error;
  }
};


#endif // EQ_EXCEPTION_H
