# ESPAsyncWebServer using in other class


Le code proposé ici montre comment il est possible d’utiliser l’excellent bibliothèque "ESPAsyncWebServer" à l’intérieur d’une classe.

Cette classe est nommée "WebHandler" pour l’exemple. Elle se décompose en un fichier d’entête  "WebHandler.h" et un fichier source "WebHandler.cpp".

Une instance de classe est créée dans le fichier principal "ESP32_Async_Web_Server.ino" et nommée "webHandler". Le constructeur de la classe se limite à la création de deux pointeurs :

<code>
WebHandler() {
  _server = nullptr;
  _ws = nullptr;
}
</code>
<p>&nbsp;</p>
La méthode "void WebHandler::init(int webPort)" appelée dans le "setup" du fichier principal affecte à ces deux pointeur des instances des classes "AsyncWebServer" et "AsyncWebSocket" et initialise ces instances.

<p>&nbsp;</p>
<code>
void WebHandler::init(int webPort)
 { <p>&nbsp;</p>
  _server = new AsyncWebServer(webPort);<p>&nbsp;</p>
  _ws = new AsyncWebSocket("/ws");
  <code>

