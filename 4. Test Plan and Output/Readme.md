# Testing Results

# 1. Normal Operation Result

Under normal operation, after the seat 1 control knob is rotated, the TLC59116-Q1 illuminates the
corresponding LEDs, which indicates that the seat is enabled. Additionally, the LCD shows the current
temperature of the load.
As current is supplied to the load, the temperature of the heater card increases. The LMT84-Q1
temperature sensor attached to the heater card outputs a voltage that is inversely proportional to the
temperature of the board. Figure shows this behavior. From this figure, observe that after a period of 30
seconds the temperature sensor voltage decreases by 220 mV, which translates to a temperature
increase of approximately 40°C.

![image](https://user-images.githubusercontent.com/94230294/144419235-31e707a6-4e13-4c57-9c5d-a287fb3dda94.png)


# 2. Open-Load Diagnostics With Switch-Enabled Results

When the switch is enabled, the open-load condition can be detected through the current sense feature of
the TPS1HA08-Q1. If an open-load condition exists, the load current is below the expected value. In this
case, the expected load current per TPS1HA08-Q1 device is 2 A. Figure shows the behavior of the
system when the load card is disconnected while the switch is enabled.

![image](https://user-images.githubusercontent.com/94230294/144419567-f1160a06-a6ed-4ccf-802c-8c9bdef47561.png)


# 3. Open-Load Diagnostics With Switch-Disabled Results

While the TPS1HA08-Q1 switch is disabled (and if DIA_EN(x) is high), an internal comparator detects the
condition of VOUTx. The detection circuitry is only enabled when DIA_EN(x) = HIGH and EN(x) = LOW.
If VOUTx > VOL (typically 3 V), the SNS pin moves to the fault level (6 mA < ISNSFH < 8.6 mA) and the ST pin
asserts low. If VOUTx < VOL, then no fault indication exists.
The fault indication (SNS and ST(x)) only occurs if the SELx pins are selecting the relevant device.
Figure 5 shows the behavior during an open-load event while the switch is disabled. As the figure shows,
when the load is disconnected, SNS rises to ISNFSH and ST is asserted low.

![image](https://user-images.githubusercontent.com/94230294/144419824-6b403d7f-ff94-4141-9235-8f8e1cfe3841.png)
