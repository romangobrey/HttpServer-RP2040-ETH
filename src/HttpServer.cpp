#include "HttpServer.h"
#include "HttpRequest.h"
#include "HttpParser.h"

using namespace Rp2040;

HttpParser httpParser;

void Rp2040::HttpServer::init(UCHAR serverIp[4], UCHAR gateway[4], UCHAR subnetMask[4], UWORD port, UDOUBLE baudRate)
{
    CH9120_SetMode(TcpServerMode);
    CH9120_SetLocalIp(serverIp);
    CH9120_SetGateway(gateway);
    CH9120_SetSubnetMask(subnetMask);
    CH9120_SetLocalPort(port);
    CH9120_SetBaudRate(baudRate);

    CH9120_Init();

    isInitialized = true;
}

String Rp2040::HttpServer::getRawRequest()
{
    if (UART_ID1.available())
    {
        return UART_ID1.readString();
    }
    return String();
}

void Rp2040::HttpServer::sendResponse(HttpResponse response)
{
    UART_ID1.print(response.toString());
}

void Rp2040::HttpServer::handleRequest(HttpResponse (*callback)(HttpRequest) = nullptr)
{
    if (!Rp2040::HttpServer::isInitialized)
    {
        return; // throw exception?
    }

    String rawRequest = getRawRequest();
    if (rawRequest == NULL || rawRequest == "")
    {
        return;
    }

    if (callback != NULL)
    {
        HttpRequest request = httpParser.GetHttpRequest(rawRequest);
        HttpResponse response = callback(request);
        sendResponse(response);
    }
}
