
#include<ESP8266WiFi.h>
#include<FirebaseArduino.h>
#define WIFI_SSID "garubin"
#define WIFI_PASS "garuka662"
#define FB_HOST "evsproj-636ac.firebaseio.com"
#define FB_AUTH "TgF6QISwOn7o0YP4zRR1EtZ0wGsUKJBcLrUoSH5n"

void setup() {
	
	//setup code: which will required to run once for initial connection to firebase
	
	Serial.begin(9600);
	pinMode(D1, OUTPUT);
	pinMode(D2, INPUT);
	WiFi.begin(WIFI_SSID,WIFI_PASS);

	Serial.print("Connecting.");

	while(WiFi.status()!=WL_CONNECTED)
	{
		Serial.print(".");
	}

	Serial.println("Connected to:");
	Serial.print(WiFi.localIP());
	Firebase.begin(FB_HOST, FB_AUTH);
}

long.duration,inches,cm;

void loop() {
	
	//Main code which will be repeating continuosly
	
	digitalWrite(D1, LOW);
        delayMicroseconds(2);
	digitalWrite(D1, HIGH);
	delayMicroseconds(5);
	digitalWrite(D1, LOW);
	duration = pulseln(D2, HIGH);
	inches = microsecondsToInches(duration);
	cm = microsecondsToInches(duration);

	Serial.print(inches);
	Serial.print("in, ");
	Serial.print(cm);
	Serial.print("cm");
	Serial.println();

	Firebase.setInt("dust", inches);
	delay(100);

}

long microsecondsToInches(long microseconds){
	
	return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds){

	return microseconds / 29 / 2;
}
