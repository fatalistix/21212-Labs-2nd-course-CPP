#include "Forth.h"

std::stringstream & operator>>(std::stringstream & in, Forth & f)
{
    std::string command;
    f.output_.clear();
    while (in >> command)
    {
        f.output_ += ForthCommandManager::Instance().DoCommand(command, f.forthStack_, f.forthStatus_);
    }
    return in;
}

std::string & operator<<(std::string & out, Forth & f)
{
    out = f.output_;
    switch (f.forthStatus_)
    {
        case F_OK:
        {
            out += " ok";
            break;
        }
        case F_UNKNOWN:
        {
            f.forthStatus_ = F_OK;
            out += " ?";
            break;
        }
        case F_EXCEPTION:
        {
            f.forthStatus_ = F_OK;
            break;
        }
    }
    return out;
}
