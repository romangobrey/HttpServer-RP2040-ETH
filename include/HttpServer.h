#include "CH9120.h"
#include "HttpRequest.h"
#include "HttpResponse.h"

namespace Rp2040
{
    class IHttpHandler
    {
    public:
        virtual HttpResponse handle(const HttpRequest &request) = 0;
    };

    class HttpServer
    {
    public:
        void handleRequest(IHttpHandler *handler);
        void handleRequest(HttpResponse (*callback)(HttpRequest));
        void init(UCHAR serverIp[4], UCHAR gateway[4], UCHAR subnetMask[4], UWORD port = 80, UDOUBLE baudRate = 115200);

    private:
        bool isInitialized;
        String getRawRequest();
        void sendResponse(HttpResponse response);
    };
}
