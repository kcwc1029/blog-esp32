// 使用Webduino程式庫建立微網站

#include <SPI.h>
#include <Ethernet.h>
#include <WebServer.h>
#include <Streaming.h>

const byte LED_PIN = 8;

static byte mac[] = {0xF0, 0x7B, 0xCB, 0x4B, 0x7C, 0x9F};
IPAddress ip(192, 168, 1, 25);
IPAddress subnet(255, 255, 255, 0);
IPAddress gateway(192, 168, 1, 1);

WebServer webserver("", 80);

P(htmlHead) =
    "<!doctype html><html>"
    "<head><meta charset=\"utf-8\">"
    "<title>Arduino 微網站</title>"
    "</head><body>";

P(homePage) = "這是微網站的首頁。";

P(htmlFoot) = "</body></html>";

P(formHead) = "<form method=\"post\" action=\"sw\">";

P(formOFF) =
    "燈光：<input name=\"light\" type=\"radio\" value=\"ON\"> 開"
    "<input name=\"light\" type=\"radio\" value=\"OFF\" checked> 關";

P(formON) =
    "燈光：<input name=\"light\" type=\"radio\" value=\"ON\" checked> 開"
    "<input name=\"light\" type=\"radio\" value=\"OFF\"> 關";

P(formFoot) =
    "<br><br><input type=\"submit\" name=\"button\" value=\"送出\">"
    "</form>";

void defaultCmd(WebServer &server, WebServer::ConnectionType type, char *, bool)
{
  server.httpSuccess();

  if (type != WebServer::HEAD)
  {
    server.printP(htmlHead);
    server.printP(homePage);
    server.printP(htmlFoot);
  }
}

void postCmd(WebServer &server, WebServer::ConnectionType type, char *, bool)
{
  char name[16], value[16];
  bool lightStatus = false; // 燈光狀態
  server.httpSuccess();

  if (type == WebServer::POST)
  {
    while (server.readPOSTparam(name, 16, value, 16))
    {
      if (strcmp(name, "light") == 0)
      {
        server << "<p>燈光已經";
        if (strcmp(value, "ON") == 0)
        {
          server << "打開。</p>";
          digitalWrite(LED_PIN, HIGH);
          lightStatus = true;
        }
        else
        {
          server << "關閉。</p>";
          digitalWrite(LED_PIN, LOW);
        }
      }
    }
    server.printP(formHead);
    if (lightStatus)
    {
      server.printP(formON);
    }
    else
    {
      server.printP(formOFF);
    }
    server.printP(formFoot);
    server.printP(htmlFoot);
  }
}

void formCmd(WebServer &server, WebServer::ConnectionType type, char *, bool)
{
  server.httpSuccess();

  if (type != WebServer::HEAD)
  {
    server.printP(htmlHead);
    server.printP(formHead);
    server.printP(formHead);
    server.printP(formFoot);
    server.printP(htmlFoot);
  }
}

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  Ethernet.begin(mac, ip, gateway, subnet);
  webserver.setDefaultCommand(&defaultCmd);     // 處理「首頁」請求
  webserver.addCommand("form.html", &formCmd);  // 處理「表單處理頁面」請求
  webserver.addCommand("sw", &postCmd);         // 處理「sw表單處理頁面」請求
  webserver.begin();
}

void loop()
{
  webserver.processConnection();
}
