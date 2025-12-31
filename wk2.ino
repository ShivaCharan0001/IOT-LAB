// Pin definitions
const int smokeSensorPin = A0;   // MQ-2 sensor connected to A0 for analog readings
const int buzzerPin = 8;         // Buzzer connected to digital pin 8
const int ledPin = 13;            // LED connected to digital pin 7 (optional)

int smokeThreshold = 300;        // Threshold value for smoke detection (adjustable)

void setup() {
  // Initialize Serial Monitor for debugging
  Serial.begin(9600);

  // Set up the buzzer and LED as output
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
  // No need to set pinMode for analog input (A0)
}

void loop() {
  // Read the value from the MQ-2 sensor (analog pin A0)
  int smokeValue = analogRead(smokeSensorPin);

  // Print the sensor value to Serial Monitor for debugging
  Serial.print("Smoke Sensor Value: ");
  Serial.println(smokeValue);

  // Check if the sensor value is above the threshold (indicating smoke)
  if (smokeValue > smokeThreshold) {
    // Smoke detected - Turn on buzzer and LED
    digitalWrite(buzzerPin, HIGH);  // Activate the buzzer
    digitalWrite(ledPin, HIGH);     // Turn on the LED (optional)
    Serial.println("Smoke Detected! Buzzer and LED On.");
  } else {
    // No smoke detected - Turn off buzzer and LED
    digitalWrite(buzzerPin, LOW);   // Deactivate the buzzer
    digitalWrite(ledPin, LOW);      // Turn off the LED
    Serial.println("No Smoke Detected. Buzzer and LED Off.");
  }

  // Wait for 1 second before reading the sensor again
  delay(1000);
}

