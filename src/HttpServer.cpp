#include "HttpServer.h"
#include "HttpRequest.h"
#include "HttpParser.h"

using namespace Rp2040;

//HttpParser httpParser;

Rp2040::HttpServer::HttpServer(DeviceModel device)
{
    _deviceModel = device;
}

void Rp2040::HttpServer::init(UCHAR serverIp[4], UCHAR gateway[4], UCHAR subnetMask[4], UWORD port, UDOUBLE baudRate)
{
    if(_deviceModel == DeviceModel::Rp2040Eth)
    {
        _ch9120Server.init(serverIp, gateway, subnetMask, port, baudRate);
    }

    if(_deviceModel == DeviceModel::W5500EvbPico)
    {
        _w5500Server.init(serverIp, gateway, subnetMask, port);
    }

    isInitialized = true;
}

void Rp2040::HttpServer::handleRequest(HttpResponse (*callback)(HttpRequest) = nullptr)
{
    if (!Rp2040::HttpServer::isInitialized)
    {
        return; // throw exception?
    }

    if(_deviceModel == DeviceModel::W5500EvbPico)
    {
        _w5500Server.handleRequest(callback);
    }

    if(_deviceModel == DeviceModel::Rp2040Eth)
    {
        _ch9120Server.handleRequest(callback);
    }
}
