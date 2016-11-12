



#define SENSOR_LIGHT_PIN A0

void setup() {
	Serial.begin(115200);
	
	pinMode(SENSOR_LIGHT_PIN, INPUT);

}

int max = 0;
int min = 1024;

void loop() {
	
	int current = analogRead(SENSOR_LIGHT_PIN);
	if(max<current){
	    max = current;
	}
	if(min>current){
	    min = current;
	}

	Serial.print("Max: ");
	Serial.print(max);
	Serial.print("\tMin: ");
	Serial.print(min);
	Serial.print("\tCurrent: ");
	Serial.println(current);


	while(Serial.available()){
	    if(Serial.read()=='r'){
            max = 0;
            min = 1024;
	    }
	}
}
