#include "HttpServer.h"
#include "Custom.h"

using namespace Rp2040;
using namespace MyCustomHandlers;

void CustomHandler::handle(HttpRequest &request)
{
    Serial.println("CustomHandlers::CustomHandler::handle!!!!!");
}