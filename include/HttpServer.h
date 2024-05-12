#include "CH9120.h"
#include "HttpResponse.h"

class HttpServer
{
private:
    bool isInitialized;

    String getRequest();
    void sendResponse(HttpResponse response);

public:
    HttpServer();
    ~HttpServer();

    void init(UCHAR serverIp[4], UCHAR gateway[4], UCHAR subnetMask[4], UWORD port = 80, UDOUBLE baudRate = 115200);
    void handleRequest(HttpResponse (*callback)(String));
};
