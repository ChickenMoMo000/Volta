#define RELAY1 33
#define RELAY2 32
#define RELAY3 35
#define RELAY4 34

// Define ESP32 pins connected to the L298N driver for each motor
// Motor 1
#define IN1_1 15
#define IN2_1 2
#define IN3_1 0
#define IN4_1 4
// Motor 2
#define IN1_2 16
#define IN2_2 17
#define IN3_2 5
#define IN4_2 18
// Motor 3

// Define delay time for stepping speed (smaller delay = faster rotation)
int delayTime = 2; // Adjust this for speed control

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(115200);
  
  // Set relay pins as OUTPUT
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);
  
  // Turn on all relays
  digitalWrite(RELAY1, LOW); // Assuming active LOW relays
  digitalWrite(RELAY2, LOW);
  digitalWrite(RELAY3, LOW);
  digitalWrite(RELAY4, LOW);
  
  Serial.println("All relays are ON!");
  
  // Set pin modes for all motor control pins
  // Motor 1
  pinMode(IN1_1, OUTPUT);
  pinMode(IN2_1, OUTPUT);
  pinMode(IN3_1, OUTPUT);
  pinMode(IN4_1, OUTPUT);
  // Motor 2
  pinMode(IN1_2, OUTPUT);
  pinMode(IN2_2, OUTPUT);
  pinMode(IN3_2, OUTPUT);
  pinMode(IN4_2, OUTPUT);
  // Motor 3
 
}

// Function to step forward for a motor
void stepForward(int IN1, int IN2, int IN3, int IN4) {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  delay(delayTime);

  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  delay(delayTime);

  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  delay(delayTime);

  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  delay(delayTime);
}

// Function to step backward for a motor
void stepBackward(int IN1, int IN2, int IN3, int IN4) {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  delay(delayTime);

  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  delay(delayTime);

  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  delay(delayTime);

  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  delay(delayTime);
}

void loop() {
  // Rotate all motors forward for 200 steps
  for (int i = 0; i < 500; i++) {
    stepForward(IN1_1, IN2_1, IN3_1, IN4_1);
    stepForward(IN1_2, IN2_2, IN3_2, IN4_2); 
  }
  delay(1000); // Pause before changing direction

  // Rotate all motors backward for 200 steps
  for (int i = 0; i < 500; i++) {
    stepBackward(IN1_1, IN2_1, IN3_1, IN4_1);
    stepBackward(IN1_2, IN2_2, IN3_2, IN4_2);
  }
  delay(1000); // Pause before repeating
}