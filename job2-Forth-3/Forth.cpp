#include "Forth.h"

bool Forth::ReadAndExecute(std::istream & in,std::ostream & out)
{
    std::string inputKeyword;
    getline(in, inputKeyword);
    if (inputKeyword == "exit") { return false; }

    buffer.clear();
    buffer.str(inputKeyword);
    buffer.seekg(0);

    try
    {
        buffer >> inputKeyword;
        if (inputKeyword.empty()) { return true; }

        do
        { ForthCommandManager::Instance().Debug(inputKeyword, buffer, in); }
        while (buffer >> inputKeyword);

        out << "< " << std::flush;

        {
            std::string temp = buffer.str();
            buffer.clear();
            buffer.str(temp);
            buffer.seekg(0);
        }

        while (buffer >> inputKeyword)
        { ForthCommandManager::Instance().Execute(inputKeyword, buffer, forthStack_, out); }
    }
    catch (std::invalid_argument & e)
    {
        out << "< " << e.what() << std::endl;
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
