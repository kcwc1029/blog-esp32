// 動手做18-1：監控遠端的溫濕度值

#include <SPI.h>
#include <Ethernet.h>
#include <WebServer.h>
#include <Streaming.h>
#include <DHT.h>

DHT dht(2, DHT11); // 宣告 DHT11 程式物件及接腳

static byte mac[] = {0xF0, 0x7B, 0xCB, 0x4B, 0x7C, 0x9F};
IPAddress ip(192, 168, 1, 25);
IPAddress subnet(255, 255, 255, 0);
IPAddress gateway(192, 168, 1, 1);

WebServer webserver("", 80);

P(htmlHead) =
    "<!doctype html><html>"
    "<head><meta charset=\"utf-8\">"
    "<title>Arduino 溫濕度計</title>"
    "</head><body>";

P(htmlFoot) = "</body></html>";

void defaultCmd(WebServer &server, WebServer::ConnectionType type, char *, bool)
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  server.httpSuccess();

  if (type != WebServer::HEAD) {
    server.printP(htmlHead);

    if (isnan(h) || isnan(t)) {
      server << "<h1>溫濕度計</h1>";
      server << "<p>溫度：" << t << "&deg;C</p>";
      server << "<p>濕度：" << h << "%</p>";
    }
    else{
      server << "<h1>無法讀取溫濕度值</h1>";
    }
    server.printP(htmlFoot);
  }
}

void setup() {
  Ethernet.begin(mac, ip, gateway, subnet);
  webserver.setDefaultCommand(&defaultCmd); // 處理「首頁」請求
  webserver.begin();
}

void loop() {
  webserver.processConnection();
}
