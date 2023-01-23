#include "Forth.h"

bool Forth::ReadAndExecute(std::istream & in,std::ostream & out)
{
    std::string inputKeyword;
    getline(in, inputKeyword);
    if (inputKeyword == "exit") { return false; }

    buffer_.clear();
    buffer_.str(inputKeyword);
    buffer_.seekg(0);

    try
    {
        buffer_ >> inputKeyword;
        if (inputKeyword.empty()) { return true; }

        out << "< " << std::flush;

        do
        { forthCommandManager_.Debug(inputKeyword, buffer_, in); }
        while (buffer_ >> inputKeyword);

        {
            std::string temp = buffer_.str();
            buffer_.clear();
            buffer_.str(temp);
            buffer_.seekg(0);
        }

        while (buffer_ >> inputKeyword)
        { forthCommandManager_.Execute(inputKeyword, buffer_, forthStack_, out); }
    }
    catch (std::invalid_argument & e)
    {
        out << " " << e.what() << std::endl;
        return true;
    }
    catch (std::runtime_error & e)
    {
        out << " " << e.what() << std::endl;
        return true;
    }
    catch (std::out_of_range & e)
    {
        out << " Got incorrect number (too big or too small)" << std::endl;
        return true;
    }

    out << " ok" << std::endl;
    return true;
}
