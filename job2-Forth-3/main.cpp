#include "Streams/CurrentStreams.h"
#include "Forth.h"

int main()
{
    inputStream.exceptions(std::ios::badbit | std::ios::failbit);
    try
    {
        while (true)
        {
            outputStream << "> " << std::flush;

            if (!ForthInterpreter::Instance().ReadAndExecute(inputStream, outputStream))
            {
                break;
            }
        }
    }
    catch (std::istream::failure &)
    {
        outputStream << "< Error reading from stream/file" << std::endl;
        return 0;
    }
    catch (std::ostream::failure &)
    {
        outputStream << "< Error writing to stream/file" << std::endl;
        return 0;
    }

    outputStream << "< Exited without errors" << std::endl;
    return 0;
}

