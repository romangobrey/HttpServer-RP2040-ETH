#include <Arduino.h>
#include "HttpServer.h"

HttpResponse exampleHandler(String input);

HttpServer httpServer;

void setup()
{
  UCHAR serverIp[4] = {192, 168, 1, 2};
  UCHAR gateway[4] = {192, 168, 1, 1};
  UCHAR subnetMask[4] = {255, 255, 255, 0};

  httpServer.init(serverIp, gateway, subnetMask);
}

void loop()
{
  httpServer.handleRequest(&exampleHandler);
}

HttpResponse exampleHandler(String input)
{
  HttpResponse response;
  response.code = 200;
  response.body = "This is an example response";
  return response;
}