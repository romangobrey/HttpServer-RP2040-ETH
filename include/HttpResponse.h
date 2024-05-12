#include <arduino.h>
#include <map>

class HttpResponse
{
public:
    unsigned short code;
    String codeDescription;
    std::map<String, String> headers;
    String body;
    String toString();
};