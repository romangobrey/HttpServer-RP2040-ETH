#include "CH9120.h"
#include "CH9120Server.h"
#include "DeviceModel.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "W5500Server.h"

namespace Rp2040
{
    class HttpServer
    {
    private:
        bool isInitialized;
        DeviceModel _deviceModel;
        CH9120Server _ch9120Server;
        W5500Server _w5500Server;

    public:
        HttpServer(DeviceModel device);
        void init(UCHAR serverIp[4], UCHAR gateway[4], UCHAR subnetMask[4], UWORD port = 80, UDOUBLE baudRate = 115200);
        void handleRequest(HttpResponse (*callback)(HttpRequest));
    };
}
