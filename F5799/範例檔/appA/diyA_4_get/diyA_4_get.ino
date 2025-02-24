// 使用Webduino程式庫建立微網站

#include <SPI.h>
#include <Ethernet.h>
#include <WebServer.h>
#include <Streaming.h>

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

P(FORM) =
  "<form method=\"GET\" action=\"gt\">"
  "訊息：<input name=\"msg\" type=\"text\"><br>"
  "燈光：<input name=\"light\" type=\"radio\" value=\"ON\"> 開"
  "<input name=\"light\" type=\"radio\" value=\"OFF\" checked> 關"
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


void getCmd(WebServer &server, WebServer::ConnectionType type, char *url_tail, bool tail_complete)
{
  URLPARAM_RESULT rc;
  char name[16];
  char value[16];

  server.httpSuccess();

  if (type == WebServer::GET)
  server.printP(htmlHead);
  {
    while (strlen(url_tail))
    {
      rc = server.nextURLparam(&url_tail, name, 16, value, 16);
      if (rc != URLPARAM_EOS)
      {
        server << "<p>參數" << name << "的值是" << value << "</p>";
      }
    }
  }
  server.printP(htmlFoot);
}

void formCmd(WebServer &server, WebServer::ConnectionType type, char *, bool)
{
  server.httpSuccess();

  if (type != WebServer::HEAD)
  {
    server.printP(htmlHead);
    server.printP(FORM);
    server.printP(htmlFoot);
  }
}

void setup()
{
  Ethernet.begin(mac, ip, gateway, subnet);
  webserver.setDefaultCommand(&defaultCmd);     // 處理「首頁」請求
  webserver.addCommand("form.html", &formCmd);  // 處理「表單處理頁面」請求
  webserver.addCommand("gt", &getCmd);          // 處理GET請求
  webserver.begin();
}

void loop()
{
  webserver.processConnection();
}
