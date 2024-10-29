# Smart Alarm with Morning Challenge and Water Spray

This smart alarm project ensures you're fully awake and ready to start the day. Place your phone in a secure compartment the night before, and when the alarm goes off in the morning, it won’t stop until you solve a math challenge on the keypad. An ultrasonic sensor detects when you're in front of the alarm, activating a water spray to ensure you’re paying attention.

## How It Works

- **Ultrasonic Sensor**: Detects when you are in front of the alarm in the morning. Only then does it activate a pump to spray water, adding an extra wake-up effect.
- **Keypad Challenge**: The alarm displays a randomized math problem on the LCD. You must enter the correct answer using the keypad to stop the alarm and unlock the phone compartment.
- **Servo-Controlled Lock**: The compartment remains locked until you enter the correct answer. When you do, the servo unlocks the compartment, allowing access to your phone.

## Emergency Backup Access

For those worried about the alarm being too stubborn, there’s a backdoor for emergency access. This door is secured with 10 screws, so if you try to avoid solving the math problem by unscrewing it, you'll be wide awake by the time you’re finished!

## Components

1. **Arduino Board** (e.g., Arduino Uno or Nano): Manages system logic and timing.
2. **Ultrasonic Sensor**: Detects if you're in front of the alarm to trigger the water spray.
3. **LCD Display**: Shows the math challenge and countdowns.
4. **Keypad**: Enables you to input answers to stop the alarm.
5. **Servo Motor**: Controls the lock mechanism of the phone compartment.
6. **Pump**: Activated by the ultrasonic sensor to spray water for an extra wake-up push.

## How to Use

1. Place your phone in the compartment before bed. The compartment is securely locked by the servo.
2. In the morning, when the alarm goes off, stand in front of the alarm to activate the water spray (if you’re brave enough).
3. Solve the math challenge displayed on the LCD by entering the correct answer on the keypad. If correct, the alarm stops and the compartment unlocks.
4. **Emergency Access**: If all else fails, you can access the backdoor secured by 10 screws. But be warned, by the time you unscrew them all, you’ll definitely be awake!

## Benefits of the Smart Alarm

- **Effective Wake-Up**: With a water spray and a math challenge, there’s no chance of oversleeping.
- **Secure Phone Storage**: Motivates you to get out of bed to access your phone.
- **Backup Access**: The 10-screw backdoor ensures you can access your phone if needed, though it’s intentionally time-consuming to discourage cheating.

This Smart Alarm is designed to make waking up more engaging, challenging, and foolproof. Start your day alert and energized, with no chance of oversleeping!
