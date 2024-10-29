# Smart Alarm with Secure Wake-Up Challenge

This is a smart alarm project designed to help even the heaviest sleepers wake up. The night before, you place your phone in a secure compartment controlled by a servo. When the alarm goes off in the morning, it won’t stop ringing until you solve a randomized math challenge on the keypad, which unlocks the compartment.

## How It Works

- **Ultrasonic Sensor**: Detects when an object (your phone) is placed in the compartment.
- **Keypad Challenge**: In the morning, the alarm activates and displays a randomized math challenge on the LCD. You must enter the correct answer using the keypad to stop the alarm and unlock the compartment.
- **Servo-Controlled Lock**: The compartment remains locked until the correct answer is entered, after which the servo unlocks it.

## Emergency Backup Access

For those who might worry about tech mishaps, there’s an emergency backdoor to access your phone. This door is securely fastened with 10 screws, so if you try to “cheat” by unscrewing it instead of solving the math problem, you’ll certainly be wide awake by the time you’re done!

## Components

1. **Arduino Board** (e.g., Arduino Uno or Nano): Manages all system logic.
2. **Ultrasonic Sensor**: Detects if the phone is inside the compartment.
3. **LCD Display**: Displays the math challenge and status messages.
4. **Keypad**: Allows user input to solve the math problem.
5. **Servo Motor**: Locks/unlocks the compartment based on user input.
6. **Pump (optional)**: Adds an extra “wake-up effect” when the alarm is triggered.

## How to Use

1. Place your phone in the compartment at night. The ultrasonic sensor will confirm that it’s inside.
2. In the morning, when the alarm goes off, you’ll see a countdown and the math challenge displayed on the LCD.
3. Solve the math challenge on the keypad to stop the alarm and unlock the compartment.
4. If necessary, use the backdoor with screws for emergency access—but be warned, there are 10 screws, so you’ll definitely be awake by the time you’re finished!

## Project Benefits

- **Fun Wake-Up Experience**: Adds a challenge to your wake-up routine, ensuring you're fully alert.
- **Secure Phone Storage**: Keeps your phone locked away, adding an extra layer of motivation to get out of bed.
- **Emergency Access**: The backdoor ensures access if needed, though it’s designed to make “cheating” harder.

With this Smart Alarm, you'll have a challenging yet fun start to your day. Say goodbye to oversleeping!

