#include <EEPROM.h>

enum RequestType { READ, WRITE, UNKNOWN };

class Request {
  public:
    RequestType type;
    String address;
  	String value;

    Request(RequestType type, String address, String value) {
      this->type = type;
      this->address = address;
      this->value = value;
    }
};

const String readCommand = "read";
const String writeCommand = "write";
const char inputDelimiter = ' ';

void handleInput(String input);
RequestType recongnizeType(String input);
Request parseInput(char delimiter, String input);

void setup() {
  Serial.begin(9600); // Subscribe to Serial Monitor input
}

void loop() {
  if (Serial.available() > 0) handleInput(Serial.readString()); // Read input when it is available
}

void handleInput(String input) {
  Request request = parseInput(inputDelimiter, input);

  if (request.type == READ && request.address != "") { // Handle read request
    Serial.println(EEPROM.read(request.address.toInt()));
  } else if (request.type == WRITE && request.address != "" && request.value != "") { // Handle write request
    EEPROM.write(request.address.toInt(), request.value.toInt());
  }
}

Request parseInput(char delimiter, String input) {
  int max = 3;
  String components[max] = {""};

  int currentComponent = 0;
  int start = -1;
  int end = -1;

  for (int i = 0; i < input.length(); i++) {
    if (currentComponent == max) break;

    if (input[i] == delimiter && start != -1 && end != -1) {
      components[currentComponent] = input.substring(start, end + 1);
      currentComponent += 1;
      start = -1;
      end = -1;
    } else if (input[i] != delimiter) {
      if (start == -1) start = i;
      end = i;
    }
  }

  if (start != -1 && end != -1 && currentComponent < max) {
    components[currentComponent] = input.substring(start, end + 1); // Cover cases when input does not end with a space
  }

  return Request(recongnizeType(components[0]), components[1], components[2]);
}

RequestType recongnizeType(String input) {
  return input == readCommand ? READ : input == writeCommand ? WRITE : UNKNOWN;
}