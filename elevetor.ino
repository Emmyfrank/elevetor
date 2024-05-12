#define UP_BUTTON_PIN D2
#define DOWN_BUTTON_PIN D3

int motor1Pin1 = 12; 
int motor1Pin2 = 14; 
int enable1Pin = 13; 

// Setting minimum duty cycle
int dutyCycle = 60; //60

int prev_button_state = LOW;  // The previous state from the input pin
int button_state;     // The current reading from the input pin
int prev_down_button_state = LOW;  // The previous state from the input pin
int down_button_state;     // The current reading from the input pin

void setup() {
  // Initialize the Serial to communicate with the Serial Monitor.
  // Serial.begin(9600);
  // Configure the ESP8266 pin as a pull-up input: HIGH when the button is open, LOW when pressed.
  pinMode(UP_BUTTON_PIN, INPUT_PULLUP);
  pinMode(DOWN_BUTTON_PIN, INPUT_PULLUP);

  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  // read the state of the switch/button:
  button_state = digitalRead(UP_BUTTON_PIN);
  down_button_state = digitalRead(DOWN_BUTTON_PIN);

  //Apply power to spin at maximum speed
  digitalWrite(enable1Pin, HIGH);

  if (prev_button_state == HIGH && button_state == LOW){
    moveUpward();
  } else if (prev_down_button_state == HIGH && down_button_state == LOW){
     moveDownward();
  }else if (prev_button_state == LOW && button_state == HIGH)
    Serial.println("The button is released");

  // save the the last state
  prev_button_state = button_state;
  prev_down_button_state = down_button_state;
}

void moveUpward(){
  Serial.println("The button is pressed");
    // Move the DC motor forward at maximum speed
    Serial.println("Moving Forward");
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    delay(170);

    // Stop the DC motor
    Serial.println("Motor stopped");
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    delay(1000);
}

void moveDownward(){
  // Move DC motor backwards at maximum speed
    Serial.println("Moving Backwards");
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW); 
    delay(170);

    // Stop the DC motor
    Serial.println("Motor stopped");
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor1Pin1, LOW);
    delay(1000);
}