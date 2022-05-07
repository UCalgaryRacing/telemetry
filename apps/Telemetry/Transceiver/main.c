

COMPONENT_INIT {
  // Initialize the CAN bus

  // Start the receiver thread

  // If we want to start telemetry on power on
  // Request the sensors
  // Write the sensor data to flash
  // Request a new session from the server
  // With the request returned udp port - We want to start a udp socket
  // Activate the transmission system
  // When there is a request to stop, we shut the transmission and reading system down
  // Wait for a new message to start

  // Ways to start:
  // - Switch on the car
  // - Start on power
  // - Start via TCP message

  // When reading the data, use a mutex
}