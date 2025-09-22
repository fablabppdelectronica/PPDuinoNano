#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define ODI
#ifdef ODI
  String wifiSsid = "ODIWAN";
  String wifiPassword = "Fablab@12345";
#endif
#ifdef CODIGO
  String wifiSsid = "SSID";
  String wifiPassword = "password";
#endif

bool wifiConnect = false;
bool stateWifi = false;

WiFiClient espClient;
PubSubClient mqttClient(espClient);
String mqttId = "ESP8266Client-"+ String(random(0xffff), HEX);
String mqttServer = "test.mosquitto.org";
int mqttPort = 1883;
String mqttUser = "ugordillo";
String mqttPassword = "12345678";
bool mqttTls = false;
bool mqttConnect = false;
//bool mqttCheck = false;

bool modeMqtt = false;    // Para ejecutar Read o Write por MQTT
bool stateMqtt = false;   // Para habilitar ejecucion de comando con MQTT

char mqttServerArray[50];
char messageArray[50];
char topicArray[50];

char inChar;
String inString = "",inTopic = "",inMessage = "";

// ***************************************
// FUNCIONES DE CONEXION WIFI
// ***************************************
// Funcion para conectar a red Wifi
bool connectWifi() {
  // Iniciar la conexion a red Wifi
  Serial.print("Connecting to " + wifiSsid + " ");
  WiFi.mode(WIFI_STA);
  WiFi.begin(wifiSsid, wifiPassword);
  // Tiempo para establecer conexion  
  delay(500);    
  byte intentos=0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    intentos++;
    if (intentos>40){  break;  }
  }
  // Evaluar estado para devolución de conexión
  if (WiFi.status() != WL_CONNECTED) {
    Serial.print(" ");
    Serial.print("NoIP");
    return false;
  }
  else {
    Serial.print(" ");
    Serial.print(WiFi.localIP());
    return true;
  }
}
// ***************************************
// Funcion para desconectar a red Wifi
bool disconnectWifi() {
  // Iniciar la desconexion a red Wifi
  Serial.print("Disconnecting from " + wifiSsid + " ");
  WiFi.disconnect();
  // Tiempo para establecer desconexion
  delay(500);    
  // Evaluar estado para devolución de conexión
  if (WiFi.status() != WL_CONNECTED) {  return true;  } // WiFi desconectado
  else {                                return false; } // WiFi conectado
}
// ***************************************
// Funcion para resetear conexion a red Wifi
bool resetWifi() {
  // Iniciar la desconexion a red Wifi
  if (disconnectWifi()){
    Serial.print(">OK>");
    wifiConnect = false;
    if (connectWifi()){   return true;    }
    else{                 return false;   }
  }
  else{
    Serial.println(">ERROR");
    wifiConnect = true;
    return false;
  }
}
// ***************************************
// Funcion para estado de red Wifi
bool statusWifi() {
  // Evaluar estado para devolución de conexión
  if (WiFi.status() != WL_CONNECTED) {  return false; } // WiFi desconectado
  else {                                return true;  } // WiFi conectado
}

// ***************************************
// FUNCIONES DE COMUNICACION MQTT
// ***************************************
// Funcion para recibir suscripciones
void mqttCallback(char* topic, byte* payload, unsigned int length) {
  String topico = String((char*)topic);
  String mensaje = (String((char*)payload)).substring(0,length);
  Serial.print(topico);
  Serial.print('<');
  Serial.println(mensaje);
}
// ***************************************
// Funcion para configurar MQTT
void mqttSetup(){
  mqttServer.toCharArray( mqttServerArray, 100 );
  mqttClient.setServer(mqttServerArray, mqttPort);
  mqttClient.setCallback(mqttCallback);
}
// ***************************************
// Funcion para conectar a broker MQTT
bool mqttConnectGo() {
  // Loop until we're reconnected
  while (!mqttClient.connected()) {
    Serial.print("Connecting to " + mqttServer + " ...");
    // Attempt to connect
    if (mqttClient.connect(mqttId.c_str())) {
      Serial.print("Connected");
      // Once connected, publish an announcement...
      mqttClient.publish("Codigo", "Hello, I am ESP8266");
    } else {
      Serial.print(".");
      delay(5000);
    }
  }
  return mqttClient.connected();
}
// ***************************************
// Funcion para desconectar de broker MQTT
bool mqttDisconnectGo(){
  mqttClient.disconnect();
  if (mqttClient.connected()){
    return false;
  }
  else {
    return true;
  }
}
// ***************************************
// Funcion para leer estado de MQTT
bool mqttStatus(){
  if (mqttClient.connected()){
    return true;
  }
  else {
    return false;
  }
}
// ***************************************
// Funcion para revision de protocolo MQTT
void mqttLoop(){
  mqttClient.loop();
}

// ***************************************
// FUNCIONES DE SETUP DE ESP8288
// ***************************************
// Funcion configurar el ESP8266
void setup() {
  Serial.begin(9600);
  delay(5000);
}

// ***************************************
// FUNCIONES DE BUCLE DE ESP8288
// ***************************************
// Funcion para el algortimo de ESP8266
void loop() {
  // Revision y ejecucion del protocolo MQTT
  if (wifiConnect){
    if (mqttConnect){
      if (!mqttClient.connected()) {
        mqttConnectGo();
      }
      else{   // Ejecutar siempre para las suscripciones
        mqttLoop();
      }
    }
  }
  // -------------------------------------
  // Comando para comunicacion MQTT si esta habilitado
  if (stateMqtt) {
    stateMqtt = false;  // Solo se ejecuta 1 vez
    Serial.print(inTopic);
    // ***********************************
    // -----------------------------------
    // Configurando nombre de Red WIFI
    if (inTopic == "wifi/ssid"){
      // Comando para escritura de nombre de Red Wifi
      if (modeMqtt){  
        // Almacenar nombre de Red Wifi                    
        wifiSsid = inMessage;
        Serial.println(">OK");         
      }
      // Comando para lectura de nombre de Red Wifi
      else{
        if (inMessage == "GET"){
          // Enviar nombre de Red Wifi
          Serial.println("<" + wifiSsid);
        }
        else{
          Serial.println("<ERROR");
        }
      }
    }
    // -----------------------------------
    // Configurando clave de Red WIFI
    else if (inTopic == "wifi/password"){
      // Comando para escritura de clave de Red Wifi
      if (modeMqtt){
        // Almacenar clave de Red Wifi                    
        wifiPassword = inMessage;
        Serial.println(">OK");         
      }
      // Comando para lectura de clave de Red Wifi
      else{
        if (inMessage == "GET"){
          // Enviar clave de Red Wifi
          Serial.print("<" + wifiPassword);
        }
        else{
          Serial.println("<ERROR");
        }
      }
    }
    // -----------------------------------
    // Comando para conexion de Red WIFI      
    else if (inTopic == "wifi/connect"){
      // Comando para control de conexion Red Wifi
      if (modeMqtt){
        // Conectar a Red Wifi configurada
        if (inMessage == "ON"){
          Serial.print(">ON>");
          if (connectWifi()){
            Serial.println(">OK");
            wifiConnect = true;
          }
          else{
            Serial.println(">ERROR");
            wifiConnect = false;
          }
        }
        // Desconectar de Red Wifi actual
        else if (inMessage == "OFF"){
          Serial.print(">OFF>");
          if (disconnectWifi()){
            Serial.println(">OK");
            wifiConnect = false;     
          }
          else{
            Serial.println(">ERROR");
            wifiConnect = true;
          }
        }
        // Resetear conexion de Red Wifi
        else if (inMessage == "RESET"){
          Serial.print(">RESET>");
          wifiConnect = false;
          if (resetWifi()){
            Serial.println(">OK");
            wifiConnect = true;     
          }
          else{
            Serial.println(">ERROR");
            wifiConnect = false;
          }
        }
        else{
          Serial.println(">ERROR");
        } 
      }
      // Comando para lectura de conexion Red Wifi
      else{
        // Leer Red Wifi configurada
        if (inMessage == "GET"){
          if (statusWifi()){
            Serial.println("<Connected to " + wifiSsid);
            wifiConnect = true;     
          }
          else{
            Serial.println("<Disconnected");
            wifiConnect = false;
          }
        }
        else{
          // Comando errado
          Serial.println("<ERROR");
        }
      }        
    }
    // ***********************************
    // -----------------------------------
    // Configurando servidor de connexion MQTT
    else if (inTopic == "mqtt/server"){        // URL o IP del servidor MQTT
      if (modeMqtt){
        mqttServer = inMessage;
        Serial.println(">OK");         
      }
      else{
        if (inMessage == "GET"){
          // Enviar nombre de Red Wifi
          Serial.println("<" + mqttServer);
        }
        else{
          Serial.println("<ERROR");
        }
      }
    }
    // -----------------------------------
    // Configurando puerto de connexion MQTT
    else if (inTopic == "mqtt/port"){     // Puerto de servidor MQTT
      if (modeMqtt){
        mqttPort = inMessage.toInt();
        Serial.println(">OK");         
      }
      else{
        if (inMessage == "GET"){
          // Enviar nombre de Red Wifi
          Serial.println("<" + String(mqttPort));
        }
        else{
          Serial.println("<ERROR");
        }
      }
    }
    // -----------------------------------
    // Configurando identificador de connexion MQTT
    else if (inTopic == "mqtt/id"){       // ID de servidor MQTT
      if (modeMqtt){
        mqttId = inMessage;
        Serial.println(">OK");         
      }
      else{
        if (inMessage == "GET"){
          // Enviar nombre de Red Wifi
          Serial.println("<" + mqttId);
        }
        else{
          Serial.println("<ERROR");
        }
      }        
    }
    // -----------------------------------
    // Configurando usuario de connexion MQTT
    else if (inTopic == "mqtt/user"){     // Usuario para servidor MQTT
      if (modeMqtt){
        mqttUser = inMessage;
        Serial.println(">OK");         
      }
      else{
        if (inMessage == "GET"){
          // Enviar nombre de Red Wifi
          Serial.println("<" + mqttUser);
        }
        else{
          Serial.println("<ERROR");
        }
      }        
    }
    // -----------------------------------
    // Configurando clave de connexion MQTT
    else if (inTopic == "mqtt/password"){ // Clave para servidor MQTT
      if (modeMqtt){
        mqttPassword = inMessage;
        Serial.println(">OK");         
      }
      else{
        if (inMessage == "GET"){
          // Enviar nombre de Red Wifi
          Serial.println("<" + mqttPassword);
        }
        else{
          Serial.println("<ERROR");
        }
      }        
    }
    // -----------------------------------
    // Configurando seguridad de connexion MQTT
    else if (inTopic == "mqtt/tls"){      // Comando para configurar la encriptacion
      if (modeMqtt){
        if (inMessage == "ON"){
          mqttTls = true;
          Serial.println(">OK");
        }
        else if (inMessage == "OFF"){
          mqttTls = false;        
          Serial.println(">OK");
        }
        else{
          Serial.println(">ERROR");
        }   
      }
      else{
        if (inMessage == "GET"){
          // Enviar nombre de Red Wifi
          Serial.print("<");
          if (mqttTls)
            Serial.println("ON");
          else 
            Serial.println("OFF");
        }
        else{
          Serial.println("<ERROR");
        }
      }       
    }
    // -----------------------------------
    // Configurando Identificador de connexion MQTT
    else if (inTopic == "mqtt/connect"){  // Comando para conectar a servidor MQTT
      if (modeMqtt){
        if (inMessage == "ON"){
          Serial.print(">ON>");
          mqttSetup();
          if (mqttConnectGo()){
            Serial.println(">OK");
            mqttConnect = true;
          }
          else{
            Serial.println(">ERROR");
            mqttConnect = false;
          }
        }
        else if (inMessage == "OFF"){
          Serial.print(">OFF>");
          if (mqttDisconnectGo()){
            Serial.println("OK");
            mqttConnect = false;
          }
          else{
            Serial.println("ERROR");
            mqttConnect = true;
          }
        }
        else{
          Serial.println(">ERROR");
        }
      }
      else{
        // Leer conexión MQTT
        if (inMessage == "GET"){
          if (mqttStatus()){
            Serial.println("<Connected to " + mqttServer);
            mqttConnect = true;     
          }
          else{
            Serial.println("<Disconnected");
            mqttConnect = false;
          }
        }
        else{
          // Comando errado
          Serial.println("<ERROR");
        }
      }
    }
    // ***********************************
    // -----------------------------------
    // Realizando acciones de protocolo MQTT
    else{
      if (wifiConnect){
        if (mqttConnect){
          if (modeMqtt){
            inMessage.toCharArray( messageArray, 100 );
            inTopic.toCharArray( topicArray, 100 );
            mqttClient.publish(topicArray, messageArray);
            Serial.print(">");
            Serial.println(inMessage);
          }
          else{
            inTopic.toCharArray( topicArray, 100 );
            mqttClient.subscribe(topicArray);
            Serial.print("<");
            Serial.println(inTopic);
          }
        }
        else{
          Serial.println(">Error, no conectado a broker MQTT");
        }
      }
      else {
        Serial.println(">Error, no conectado a red wifi");
      }
    }
  }
  else{
    // No habilitado comunicación MQTT
    ;
  }
}
void serialEvent() {
  while (Serial.available()) {
    inChar = (char)Serial.read();
    switch (inChar){
      case '\r':
        inMessage = inString;
      break;
      case '\n':
        inString = "";
        stateMqtt = true;
      break;
      case '>':
        inTopic = inString;
        inString = "";
        modeMqtt = true;
      break;
      case '<':
        inTopic = inString;
        inString = "";
        modeMqtt = false;
      break;
      default:
        inString += inChar;
      break;
    }
  }
}
