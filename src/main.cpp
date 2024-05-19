#include <Arduino.h>
#include "HttpServer.h"
#include "HttpParser.h"

using namespace Rp2040;

HttpResponse handleRequest(HttpRequest request);

HttpServer httpServer;

void setup()
{
  // Init HTTP server
  UCHAR serverIp[4] = {192, 168, 1, 170};
  UCHAR gateway[4] = {192, 168, 1, 1};
  UCHAR subnetMask[4] = {255, 255, 255, 0};

  httpServer.init(serverIp, gateway, subnetMask);
}

void loop()
{
  httpServer.handleRequest(&handleRequest);
}

HttpResponse handleRequest(HttpRequest request)
{
  String method = HttpParser::GetRawMethodType(request.methodType);

  // Set response
  HttpResponse response;
  response.code = 200;
  response.codeDescription = "OK";
  response.body = "Request with type '" + ((String)method) + "' has been received";

  // Set headers
  std::map<String, String> headers;
  headers["Content-Type"] = "text/html";
  headers["Connection"] = "close";
  headers["Content-Length"] = response.body.length();

  response.headers = headers;
  return response;
}
