#include <Arduino.h>
#include "HttpServer.h"

using namespace Rp2040;

HttpResponse requestHandler(String input);

HttpServer httpServer;

void setup()
{
  // Init HTTP server
  UCHAR serverIp[4] = {192, 168, 1, 2};
  UCHAR gateway[4] = {192, 168, 1, 1};
  UCHAR subnetMask[4] = {255, 255, 255, 0};

  httpServer.init(serverIp, gateway, subnetMask);
}

void loop()
{
  httpServer.handleRequest(&requestHandler);
}

HttpResponse requestHandler(String request)
{
  // Process the request - GET, POST, etc.
  // if (GET) - do GET stuff, etc

  // Set headers
  std::map<String, String> headers;
  headers["Content-Type"] = "text/html";
  headers["Content-Length"] = "0";
  headers["Connection"] = "close";

  // Return response
  HttpResponse response;
  response.code = 200;
  response.codeDescription = "OK";
  response.headers = headers;
  return response;
}
