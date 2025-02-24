// 動手做A-1：建立微型網站伺服器，動態IP

#include <SPI.h>
#include <Ethernet.h>

String HTML =
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/html\r\n"
    "\r\n"
    "<html><head><meta charset=\"utf-8\"></head>"
    "<body><h1>Arduino物聯網應用</h1></body></html>"
    "\r\n";

byte mac[] = {0xF0, 0x7B, 0xCB, 0x4B, 0x7C, 0x9F};

EthernetServer server(80);

void setup()
{
  Serial.begin(9600);

  Ethernet.begin(mac);
  IPAddress ip = Ethernet.localIP();
  server.begin();

  Serial.print("My IP address: ");
  Serial.print(ip);
}

void loop()
{
  EthernetClient client = server.available();

  if (client)
  {
    while (client.connected())
    {
      if (client.available())
      {
        client.print(HTML);
        break;
      }
    }

    delay(1);
    client.stop();
  }
}
