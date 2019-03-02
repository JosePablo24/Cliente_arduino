#include <ESP8266WiFi.h>

const char* ssid     = "Marlene";
const char* password = "9612499002";

const char* host = "157.230.187.198";
const int httpPort1=6000;
const int httpPort2=7000;
const int httpPort3=8000;

WiFiClient client;

void setup() {
  Serial.begin(9600);
  delay(10);
  Serial.println('hola');
  WiFi.begin(ssid, password);
while(WiFi.status() != WL_CONNECTED){
  delay(500);
  Serial.print(":");
  } 
   while(!client.connect(host, httpPort1)){
    Serial.println("Conexion fallida");    
    }
    Serial.println("conexion de alguien exitosa");  
     while(client.connected()){
      client.print("hola \n"); 
              String req = client.readStringUntil('r');
                Serial.println("servidor 1 -> " + req);                      
      //delay(5);
          }           
 
}

void loop() {
  // put your main code here, to run repeatedly:
  while(!client.connected()){
    Serial.println("desconectado");
    delay(0.5);    
        if(client.connect(host, httpPort1)){
              Serial.println(" -------- Conexion exitosa al servidor 1 -------- ");
             while(client.connected()){
              client.print("hola \n");
              String req = client.readStringUntil('r');
                Serial.println("servidor 1 -> " + req);                      
              delay(10);
            }
        }
        if(client.connect(host, httpPort2)){
          Serial.println(" -------- Conexion exitosa al servidor 2 -------- ");                      
            while(client.connected()){
              client.print("hola \n");
              String req = client.readStringUntil('r');
                Serial.println("servidor 2 ->" + req);                        
                delay(10);
                }                         
          }
          if(client.connect(host, httpPort3)){
              Serial.println(" -------- Conexion exitosa al servidor 3 -------- ");            
              while(client.connected()){
                client.print("hola \n");
                String req = client.readStringUntil('r');
                Serial.println("servidor 3 ->" + req);                        
                delay(10);
                }
            }                
        }                                             
    }
